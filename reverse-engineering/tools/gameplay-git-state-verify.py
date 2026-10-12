"""Original PC saved graph bit planes and real NuSpecial visibility/reversal callbacks."""
import importlib.util,json,struct,random,itertools
from pathlib import Path
p=Path(__file__).with_name('gameplay-git-fixture.py');spec=importlib.util.spec_from_file_location('fixture',p);f=importlib.util.module_from_spec(spec);spec.loader.exec_module(f)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
n=f.n;D=f.D;check=f.check;counts=f.counts;errors=f.errors;rng=random.Random(0x59f4e0);SAVED=D+0x49000
portable=[]
def save_model(flags):
    out=[0]*81;out[0]=1
    for i,flag in enumerate(flags):
        for plane,mask in enumerate([1,0x100,2,0x20,0x400]):
            if flag&mask:out[1+16*plane+(i>>5)]|=1<<(i&31)
    return out
def restore_model(flags,words):
    return [(flag&~0x423)|sum(mask if words[offset+(i>>5)]&(1<<(i&31)) else 0 for offset,mask in [(1,1),(0x21,2),(0x31,0x20),(0x41,0x400)]) for i,flag in enumerate(flags)]
for case,size in enumerate([0,1,31,32,33,255,256,511,512]+[rng.randrange(1,513) for _ in range(55)]):
    flags=[rng.randrange(65536) for _ in range(size)];nodes=[f.node(2,flags=v) for v in flags];f.build(nodes,217)
    for i in range(size):n.pack('<BB',f.NODES+i*32+8,199,178)
    n.write(SAVED,b'\xa5'*0x180);n.call(0x59f3b0,[f.FLOW,SAVED]);words=list(n.unpack('<81I',SAVED));check('saved-bitplanes',words,save_model(flags),dict(case=case,size=size));check('save-tail-preserved',n.read(SAVED+0x144,0x3c),b'\xa5'*0x3c)
    initial=[rng.randrange(65536) for _ in flags]
    for i,v in enumerate(initial):n.pack('<H',f.NODES+i*32+10,v)
    n.call(0x59f4e0,[f.FLOW,SAVED]);want=restore_model(initial,words);got=[n.unpack('<H',f.NODES+i*32+10)[0] for i in range(size)]
    check('restored-selected-flags',got,want,dict(case=case,size=size));check('restore-generation-cleared',n.unpack('<B',f.FLOW+12)[0],0)
    check('restore-node-tick-stamps',[n.unpack('<B',f.NODES+i*32+8)[0] for i in range(size)],[0]*size);check('restore-nonloop-reset-stamps',[n.unpack('<B',f.NODES+i*32+9)[0] for i in range(size)],[178]*size)
    portable.append(dict(op='save',flags=flags,words=words,initial=initial,restored=got))
# Explicit independence of the stored monitor plane and the initial runtime monitor flag.
for original,initial in itertools.product([0,0x100],[0,0x100]):
    f.build([f.node(2,flags=original)]);n.call(0x59f3b0,[f.FLOW,SAVED]);n.pack('<H',f.NODES+10,initial);n.call(0x59f4e0,[f.FLOW,SAVED]);check('monitor-plane-not-restored',n.unpack('<H',f.NODES+10)[0]&0x100,initial)
# A restored Loop recomputes return-input count, while restoring its 0x400 flag independently.
for savedflags in range(16):
    nodes=[f.node(2,parents=[1],children=[1]),f.node(1,parents=[0],children=[0],condition=4,skip=99,flags=0x100)]
    f.build(nodes);flags=[0,sum(mask for i,mask in enumerate([1,2,0x20,0x400]) if savedflags&(1<<i))];n.pack('<81I',SAVED,*save_model(flags));n.call(0x59f4e0,[f.FLOW,SAVED]);check('restored-loop-input-count',n.unpack('<B',f.NODES+33)[0],1);check('restored-loop-flags',n.unpack('<H',f.NODES+42)[0],flags[1]|0x100)

OBJ=D+0x50000;HANDLE=OBJ+0x100;ANIM=OBJ+0x200;ITEM=OBJ+0x300;CONTROL=OBJ+0x400;STATIC=OBJ+0x500;BOUND=OBJ+0x600;SCENE=OBJ+0x700
trace=[];callback_args={0x5ae450:2,0x5ae4a0:3,0x5ae520:2,0x5a1030:3,0x5a1170:1,0x5cfc00:2}
def observe(mu,address,size,data):
    if address in callback_args:
        sp=mu.reg_read(UC_X86_REG_ESP);trace.append(dict(address=hex(address),args=list(n.unpack('<'+'I'*callback_args[address],sp+4))))
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x5a0000,end=0x5d0000)
def special_setup(flags=2,visible=True,animstate=1,speed=.75,frame=.5):
    f.build([f.node(0,flags=0x4000)]);n.write(OBJ,bytes(0x800));registration=n.call(0x5ae8e0,[0])
    for runtime,registered in [(0x44,0x24),(0x48,0x28),(0x54,0x34),(0x58,0x38),(0x5c,0x3c)]:n.pack('<I',f.REGTYPE+runtime,n.unpack('<I',registration+registered)[0])
    n.pack('<I',HANDLE,OBJ);n.pack('<I',OBJ+0x20,ANIM);n.pack('<B',OBJ+0x24,flags);n.pack('<H',ANIM+10,4);n.pack('<I',ANIM+12,animstate);n.pack('<I',ANIM+24,ITEM)
    n.pack('<4I',ITEM,0,SCENE,STATIC,0);n.pack('<I',ITEM+16,CONTROL);n.pack('<2f',ITEM+24,0.,1.);n.pack('<f',CONTROL+0x40,speed);n.pack('<f',CONTROL+0x4c,frame);n.pack('<I',CONTROL+0x50,1);n.pack('<I',STATIC+0x40,BOUND);n.pack('<I',STATIC+0x48,0x200 if visible else 0);n.pack('<I',BOUND+0x44,int(visible));trace.clear()
def special_snapshot():return dict(flags=n.unpack('<B',OBJ+0x24)[0],animFlags=n.unpack('<H',ANIM+10)[0],speed=n.unpack('<f',CONTROL+0x40)[0],frame=n.unpack('<f',CONTROL+0x4c)[0],playing=n.unpack('<I',CONTROL+0x50)[0]&1,visible=bool(n.unpack('<I',STATIC+0x48)[0]&0x200),boundsVisible=bool(n.unpack('<I',BOUND+0x44)[0]&1))
physical=[]
for priorReverse,priorVisible,reverse,withVisibility in itertools.product([False,True],repeat=4):
    special_setup(2|int(priorReverse),priorVisible);before=special_snapshot();n.call(0x55b0e0,[f.SYS,HANDLE,int(reverse),int(withVisibility),1]);got=special_snapshot();want=dict(before)
    changed=priorReverse!=reverse
    if changed:
        want['flags']=(want['flags']&~1)|int(reverse);want['speed']=-1. if reverse else 1.
        if withVisibility:
            want['visible']=want['boundsVisible']=not reverse
            if reverse:want['flags']&=~2;want['animFlags']|=2;want['playing']=0
    check('nuspecial-reversal-physical-state',got,want);expected=[0x5ae4a0]
    if changed:
        expected += [0x5ae4a0,0x5a1030]
        if withVisibility:
            if reverse:expected += [0x5ae450,0x5a1170]
            expected += [0x5ae520,0x5cfc00]
    check('nuspecial-query-mutate-visibility-order',[int(t['address'],16) for t in trace],expected)
    physical.append(dict(priorReverse=priorReverse,priorVisible=priorVisible,reverse=reverse,withVisibility=withVisibility,after=got,trace=list(trace)))
for visible in [False,True]:
    special_setup();n.call(0x55a2b0,[f.SYS,HANDLE,int(visible),1]);got=special_snapshot();check('direct-special-visibility',got['visible'],visible);check('direct-special-bounds-visibility',got['boundsVisible'],visible);check('hide-deactivates-special',got['flags']&2,2 if visible else 0);check('hide-stops-animation',got['playing'],int(visible))
for a,b,priorReverse,priorVisible,withVisibility in itertools.product([False,True],repeat=5):
    special_setup(2|int(priorReverse),priorVisible)
    # Replace the timer reference in an actual graph node with the real NuSpecial handle.
    data=n.unpack('<I',f.NODES+12)[0];refs=n.unpack('<I',data+8)[0];ref=n.unpack('<I',refs)[0];n.pack('<I',ref,HANDLE)
    parents=f.alloc(8);n.pack('<2I',parents,f.NODES+32,f.NODES+64);n.pack('<B',f.NODES,2);n.pack('<I',f.NODES+16,parents);n.pack('<H',f.NODES+10,0x100|(0x80 if withVisibility else 0));n.pack('<B',f.NODES+35,2);n.pack('<B',f.NODES+67,2);n.pack('<H',f.NODES+42,2 if a else 0);n.pack('<H',f.NODES+74,2 if b else 0)
    n.call(0x59e090,[f.FLOW,f.NODES,1]);got=special_snapshot();reverse=not(a and b);check('monitored-gizmo-reversal',got['flags']&1,int(reverse));check('monitored-gizmo-conditional-visibility',got['visible'],not reverse if withVisibility and priorReverse!=reverse else priorVisible)

# The monitor path reuses parent-output-index[0], rather than advancing for parent 1.
monitorOutputCases=[]
for selected0,selected1,index0,index1 in itertools.product([0,1],repeat=4):
    special_setup(2,True);n.pack('<I',f.REG,2)
    randomRegistration=n.call(0x5b0250,[1]);n.pack('<I',f.REGTYPE+0x9c+0x48,n.unpack('<I',randomRegistration+0x28)[0])
    data=n.unpack('<I',f.NODES+12)[0];refs=n.unpack('<I',data+8)[0];ref=n.unpack('<I',refs)[0];n.pack('<I',ref,HANDLE)
    parents=f.alloc(8);n.pack('<2I',parents,f.NODES+32,f.NODES+64);outputs=f.alloc(2);n.pack('<2B',outputs,index0,index1);n.pack('<B',f.NODES,2);n.pack('<I',f.NODES+16,parents);n.pack('<I',f.NODES+24,outputs);n.pack('<H',f.NODES+10,0x100)
    for i,selected in enumerate([selected0,selected1]):
        obj=OBJ+0x1000+i*0x100;handle=obj+0x80;n.pack('<I',handle,obj);n.pack('<B',handle+6,1);n.pack('<I',obj+0x34,selected);n.pack('<B',obj+0x38,1)
        p=f.NODES+(i+1)*32;n.pack('<B',p+3,0);n.pack('<H',p+10,0x4000);d=f.alloc(12);ref=f.alloc(8);refs=f.alloc(4);n.pack('<II',ref,handle,0);n.pack('<I',refs,ref);n.pack('<3I',d,1,0,refs);n.pack('<I',p+12,d)
    n.call(0x59e090,[f.FLOW,f.NODES,1]);reverse=not(selected0==index0 and selected1==index0);got=n.unpack('<B',OBJ+0x24)[0]&1
    check('monitor-reuses-first-output-index',got,int(reverse),dict(selected0=selected0,selected1=selected1,index0=index0,index1=index1));monitorOutputCases.append([selected0,selected1,index0,index1,got])

report=dict(binarySha256=n.sha256,method='Unmodified original PC functions, synthetic graph/save buffers and a real NuSpecial animation-object callback path. Code hooks observe callback arguments only; no callback or engine function is replaced.',checks=sum(counts.values()),categories=counts,mismatches=len(errors),errors=errors[:20],portableFixtures=portable,physicalCases=physical,monitorOutputCases=monitorOutputCases,functions=['0x59f3b0','0x59f4e0','0x55b0e0','0x55a250','0x55a2b0','0x5ae8e0','0x5ae450','0x5ae4a0','0x5ae520','0x5a1030','0x5a1170','0x5a15e0','0x5cfc00','0x59e090','0x59df70','0x5b0070'],limits=['Saved-state tests use at most the 512 nodes representable by each 16-word bit plane; larger counts are not treated as safe native input.','Physical fixtures exercise NuSpecial with one static scene instance and animation control; other gizmo types, skinned-instance visibility and renderer/collision refresh remain outside this suite.','Native loader name rebinding is invoked only on empty/previously bound synthetic lists; shipped text loading and editor Collapse flattening remain open.'])
(f.native.BASE/'reports/gameplay-git-state-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['checks','categories','mismatches','errors']},indent=2));assert not errors
