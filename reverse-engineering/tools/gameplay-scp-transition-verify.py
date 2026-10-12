"""Original PC state entry, timed transitions, reference priority and interrupt unwinding."""
import importlib.util,json,struct,itertools
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');s=importlib.util.spec_from_file_location('native',p);native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();D=n.DATA;SYS=D;CREATURE=D+0x1000;PACK=D+0x2000;SCRIPTS=D+0x3000;STATES=D+0x5000;ACTIONS=D+0xa000;CONDS=D+0xc000;REFS=D+0xf000;DEFS=D+0x11000
errors=[];counts={};traces=[]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def check(kind,got,want,detail=None):
    counts[kind]=counts.get(kind,0)+1
    if got!=want:errors.append(dict(kind=kind,got=got,want=want,detail=detail))
def script(i):return SCRIPTS+0x100*i
def state(i,j):return STATES+0x300*i+0x80*j
def ref(i):return REFS+0x80*i
def cond(i):return CONDS+0x40*i
def action(i,j):return ACTIONS+0x100*i+0x20*j
def condition(p,threshold=0,target=0,op=4,flags=0):n.pack('<f',p+8,threshold);n.pack('<BBH',p+12,op,0,flags);n.pack('<I',p+0x1c,DEFS);n.pack('<I',p+0x24,target)
def init():
    n.write(D,bytes(0x12000));n.pack('<B',CREATURE+0x138,0xff);n.pack('<2I',DEFS,0,0x514990);n.pack('<2I',DEFS+0x10,0,0x5159a0);n.pack('<2I',DEFS+0x20,0,0x515890)
    for i in range(6):
        n.pack('<I',script(i)+0x10,state(i,0));n.pack('<I',script(i)+0x38,state(i,0))
        for j in range(4):n.pack('<f',script(i)+0x1c+j*8,10*i+j+.25)
        for j in range(3):
            n.pack('<I',state(i,j),state(i,j+1) if j<2 else 0);n.pack('<I',state(i,j)+0x10,action(i,j));n.pack('<I',action(i,j)+0x10,DEFS+0x10)
        n.pack('<I',state(i,0)+8,cond(i));condition(cond(i),0,state(i,1))
    n.pack('<II',PACK,script(0),script(0));n.pack('<I',PACK+8,state(0,1));n.pack('<I',PACK+12,action(0,1));n.pack('<f',PACK+0x24,.5)
def reference(i,owner,target,scope='script',guard=True):
    n.pack('<I',(script(owner)+0x40) if scope=='script' else (state(owner,1)+0x1c),ref(i));n.pack('<I',ref(i)+0xc,script(target));n.pack('<I',ref(i)+0x14,state(owner,2));n.pack('<I',ref(i)+0x1c,cond(10+i));condition(cond(10+i),0 if guard else 1)
def tick(delta=0):n.call(0x52cc90,[SYS,0,CREATURE,PACK,bits(delta)])
def snapshot():return dict(script=n.unpack('<I',PACK+4)[0],state=n.unpack('<I',PACK+8)[0],action=n.unpack('<I',PACK+12)[0],pending=n.unpack('<I',PACK+16)[0],flags=n.unpack('<I',PACK+0x50)[0],depth=n.unpack('<I',PACK+0x64)[0],timer=n.unpack('<f',PACK+0x24)[0],locals=list(n.unpack('<4f',PACK+0x14)),deadline=n.unpack('<f',PACK+0xb8)[0],deadlineState=n.unpack('<I',PACK+0xbc)[0])

# State entry copies a pending state before action processing; ordinary condition transitions
# at the end of the tick initialize the target action, which first runs on the next tick.
for keep in [False,True]:
    init();n.pack('<I',state(0,1)+8,cond(20));condition(cond(20),.75,state(0,2),flags=2 if keep else 0);n.pack('<H',PACK+0xb2,0x1234);n.pack('<I',action(0,2)+0x10,DEFS+0x20)
    tick(.25);got=snapshot();check('condition-target-state',got['state'],state(0,2));check('target-action-deferred',got['timer'],.75);check('target-action-first-call-flag',got['flags']&1,1);check('condition-preserve-counter',n.unpack('<H',PACK+0xb2)[0],0x1234 if keep else 0)
    tick(.25);check('target-action-next-frame',snapshot()['timer'],0.)
for pending in [False,True]:
    init();n.pack('<I',PACK+8,0 if not pending else state(0,1));n.pack('<I',PACK+12,0);n.pack('<I',PACK+16,state(0,2) if pending else 0);n.pack('<I',state(0,0)+8,0);tick(.1);check('initial-or-pending-state-selection',snapshot()['state'],state(0,2 if pending else 0));check('state-pending-cleared',snapshot()['pending'],0)

# Positive deadline crossing beats normal condition transitions, and does not run target
# actions in the current frame. Zero/negative initial deadlines do not fire.
for duration,delta in itertools.product([-1.,0.,.125,.25,1.],[0.,.125,.5,2.]):
    init();n.pack('<I',state(0,1)+8,cond(20));condition(cond(20),0,state(0,0));n.pack('<f',PACK+0xb8,duration);n.pack('<I',PACK+0xbc,state(0,2));n.pack('<B',PACK+0xb4,0x7f);tick(delta);expired=duration>0 and duration-delta<=0
    check('deadline-versus-state-condition',snapshot()['state'],state(0,2 if expired else 0),dict(duration=duration,delta=delta));check('deadline-reference-clear',snapshot()['deadlineState'],0 if expired else state(0,2));check('deadline-marker-clear',n.unpack('<B',PACK+0xb4)[0],0 if expired else 0x7f)

# Global reference lists precede state-local reference lists; first eligible reference wins.
for globalGuard,localGuard in itertools.product([False,True],repeat=2):
    init();reference(0,0,1,guard=globalGuard);reference(1,0,2,scope='state',guard=localGuard);tick();want=1 if globalGuard else 2 if localGuard else 0
    check('global-before-state-reference',snapshot()['script'],script(want));check('reference-push-count',snapshot()['depth'],int(want!=0));check('reference-enter-target-state',snapshot()['state'],state(want,1));
    if want:check('reference-loads-target-defaults',snapshot()['locals'],[10*want+j+.25 for j in range(4)])
for firstGuard,firstSelfTarget in itertools.product([False,True],repeat=2):
    init();reference(0,0,1,guard=firstGuard);reference(1,0,2);n.pack('<I',script(0)+0x40,ref(0));n.pack('<I',ref(0),ref(1))
    if firstSelfTarget:n.pack('<I',cond(1)+0x24,state(1,0))
    tick();check('reference-first-eligible',snapshot()['script'],script(1 if firstGuard and not firstSelfTarget else 2))

# Nested interrupts are pushed one per frame, capped at four; binding clears timed-state fields.
init()
for i in range(5):reference(i,i,i+1)
for depth in range(1,6):
    n.pack('<f',PACK+0xb8,5.);n.pack('<I',PACK+0xbc,state(0,0));tick(.125);got=snapshot();expected=min(depth,4);check('nested-reference-depth-cap',got['depth'],expected);check('nested-reference-current-script',got['script'],script(expected));check('reference-binding-deadline-reset',got['deadline'],0. if depth<=4 else 4.875);traces.append(dict(stage='push',frame=depth,**got))

# Every active reference guard is checked oldest first; an invalid guard discards that
# frame and all younger interrupt frames, then enters the recorded return state.
for depth in range(1,5):
    for failed in range(depth):
        init()
        for i in range(depth):reference(i,i,i+1,guard=i!=failed);n.pack('<I',PACK+0x54+4*i,ref(i))
        n.pack('<I',PACK+0x64,depth);n.pack('<I',PACK+4,script(depth));n.pack('<I',PACK+8,state(depth,1));n.pack('<I',PACK+12,action(depth,1));tick();got=snapshot()
        check('invalid-guard-truncates-stack',got['depth'],failed,dict(depth=depth,failed=failed));check('invalid-guard-resumes-owner-script',got['script'],script(failed));check('invalid-guard-enters-return-state',got['state'],state(failed,2));check('invalid-guard-reloads-owner-defaults',got['locals'],[10*failed+j+.25 for j in range(4)]);traces.append(dict(stage='guard-unwind',initialDepth=depth,failed=failed,**got))

# Reaching the referenced script's idle state pops one frame on the next scheduler tick.
for depth in range(1,5):
    init()
    for i in range(depth):reference(i,i,i+1);n.pack('<I',PACK+0x54+4*i,ref(i))
    n.pack('<I',cond(depth)+0x24,state(depth,0));n.pack('<I',PACK+0x64,depth);n.pack('<I',PACK+4,script(depth));n.pack('<I',PACK+8,state(depth,0));n.pack('<I',PACK+12,action(depth,0));tick();got=snapshot();check('idle-reference-pops-one',got['depth'],depth-1);check('idle-reference-resumes-owner',got['script'],script(depth-1));check('idle-reference-return-state',got['state'],state(depth-1,2));traces.append(dict(stage='idle-return',initialDepth=depth,**got))

# Binding's four parameter overrides use config mask bits 1..4 (values 2,4,8,16).
CONFIG=D+0x11500
for mask in range(32):
    init();n.pack('<I',CONFIG+0x48,mask);n.pack('<4f',CONFIG+100,100.,101.,102.,103.);n.call(0x514640,[SYS,CREATURE,PACK,CONFIG,0,0,0,script(1),state(1,1)])
    check('script-parameter-override-mask',snapshot()['locals'],[100.+j if mask&(2<<j) else 10.+j+.25 for j in range(4)],mask)
for failed in [0,1]:
    init();reference(0,0,1,guard=failed!=0);reference(1,1,2,guard=failed!=1);n.pack('<2I',PACK+0x54,ref(0),ref(1));n.pack('<I',PACK+0x64,2);n.pack('<I',PACK+4,script(2));n.pack('<I',PACK+8,state(2,1));n.pack('<I',PACK+12,action(2,1));n.pack('<I',SYS+0x18,CONFIG);n.pack('<B',CREATURE+0x138,0);n.pack('<I',CONFIG+0x48,0x1e);n.pack('<4f',CONFIG+100,100.,101.,102.,103.);tick()
    check('base-unwind-uses-character-parameters',snapshot()['locals'],[100.+j if failed==0 else 10.+j+.25 for j in range(4)],failed)

def args(tokens):
    ptr=D+0x11800;strings=ptr+0x80
    for i,t in enumerate(tokens):b=t.encode()+b'\0';n.pack('<I',ptr+i*4,strings);n.write(strings,b);strings+=len(b)
    return ptr
def idle(tokens,first,delta):return n.call(0x5159a0,[SYS,PACK,CREATURE,args(tokens),len(tokens),first,bits(delta)])
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
for frames in [-5,0,1,2,254,255,256,1000,1.9]:
    init();n.pack('<I',PACK+0x9c,0);n.pack('<B',PACK+0x68,0);got=idle(['frames='+str(frames)],1,.5);want=max(0,min(255,int(frames)));check('idle-frame-entry-waits',got,0);check('idle-frame-clamp',n.unpack('<B',PACK+0x68)[0],want,frames)
    for frame in range(1,max(3,want+1)):
        got=idle([],0,.5);expected=1 if want!=0 and frame==want else 0;check('idle-frame-countdown',got,expected,dict(frames=frames,call=frame))
for duration,delta in itertools.product([-1.,0.,.1,.25,1.],[0.,.125,.25,.5]):
    init();n.pack('<I',PACK+0x9c,0);n.pack('<B',PACK+0x68,0);check('idle-seconds-entry-waits',idle([str(duration)],1,delta),0);remaining=f32(duration);check('idle-seconds-entry-no-subtract',n.unpack('<f',PACK+0x9c)[0],remaining)
    for frame in range(8):
        expired=remaining>0 and f32(remaining-f32(delta))<=0
        if remaining>0:remaining=max(0.,f32(remaining-f32(delta)))
        check('idle-seconds-countdown',idle([],0,delta),int(expired));check('idle-seconds-remaining',n.unpack('<f',PACK+0x9c)[0],remaining)
def rand(seed):return (seed*0x19660d+0x3c6ef35f)&0xffffffff
def random_float(seed):return (seed&0x7fffff)/(1<<23)
randomCommandCases=[]
for seed,lo,hi in itertools.product([0,1,2,0xffffffff,0x12345678],[-2,0,1,5],[0,3,5]):
    init();n.pack('<I',0x95e5d4,seed);n.pack('<I',PACK+0x9c,0);n.pack('<B',PACK+0x68,0);idle(['mintime='+str(lo),'maxtime='+str(hi)],1,.25);advanced=lo<hi;nextseed=rand(seed) if advanced else seed;want=f32(random_float(nextseed)*(hi-lo)+lo) if advanced else 0.
    check('idle-random-duration',n.unpack('<f',PACK+0x9c)[0],want);check('idle-random-state',n.unpack('<I',0x95e5d4)[0],nextseed)
    init();n.pack('<I',0x95e5d4,seed);tokens=['mintime='+str(lo),'maxtime='+str(hi)];n.call(0x515890,[SYS,PACK,CREATURE,args(tokens),2,1]);r1=rand(seed);r2=rand(r1);advanced=lo!=0 or hi!=0;want=f32((1-random_float(r1))*lo+random_float(r2)*hi) if advanced else 0.
    check('reset-timer-two-independent-draws',n.unpack('<f',PACK+0x24)[0],want);check('reset-timer-random-state',n.unpack('<I',0x95e5d4)[0],r2 if advanced else seed)
    if seed==1:randomCommandCases.append(dict(seed=seed,min=lo,max=hi,result=want))
for value in [-5.,0.,.25,2.5]:
    init();tokens=['time='+str(value)];n.call(0x515890,[SYS,PACK,CREATURE,args(tokens),1,1]);check('reset-timer-explicit-time',n.unpack('<f',PACK+0x24)[0],value)

# SetState uses a named lookup, queues pending state and returns zero. Entry is next tick.
for keep,target,conditionOverride in itertools.product([False,True],['Resume','rEsUmE','Missing'],[False,True]):
    init()
    for i,name in enumerate(['Base','Running','Resume']):
        ptr=D+0x11700+i*0x20;n.write(ptr,name.encode()+b'\0');n.pack('<I',state(0,i)+0x18,ptr)
    tokens=[target]+(['KeepBlockedMessages'] if keep else []);n.pack('<I',action(0,1)+8,args(tokens));n.pack('<I',action(0,1)+12,len(tokens));n.pack('<I',DEFS+0x34,0x5157d0);n.pack('<I',action(0,1)+0x10,DEFS+0x30);n.pack('<I',action(0,2)+0x10,DEFS+0x20);n.pack('<I',PACK+0x50,1);n.pack('<H',PACK+0xb2,0x1234)
    if conditionOverride:n.pack('<I',state(0,1)+8,cond(20));condition(cond(20),0,state(0,0))
    tick(.25);valid=target!='Missing';check('setstate-defers-current-state',snapshot()['state'],state(0,0 if conditionOverride else 1));check('setstate-pending-target',snapshot()['pending'],state(0,2) if valid and not conditionOverride else 0);check('setstate-first-tick-no-target-actions',snapshot()['timer'],.75)
    if not conditionOverride:
        tick(.25);check('setstate-next-tick-entry',snapshot()['state'],state(0,2 if valid else 1));check('setstate-next-tick-action',snapshot()['timer'],0. if valid else 1.);check('setstate-keep-blocked-messages',n.unpack('<H',PACK+0xb2)[0],0x1234 if keep or not valid else 0)

report=dict(binarySha256=n.sha256,method='Unmodified original PC 0x52cc90/0x52caf0/0x514640/0x5145a0 with actual Timer, Idle, ResetTimer, SetState and linked-list/name lookup routines. Synthetic scripts, state records, reference guards and creature context; no replaced callbacks or game launch.',checks=sum(counts.values()),categories=counts,mismatches=len(errors),errors=errors[:40],traces=traces,randomCommandCases=randomCommandCases,functions=['0x52cc90','0x52caf0','0x514640','0x5145a0','0x514550','0x52c880','0x514990','0x515890','0x5159a0','0x5b9dd0','0x5157d0','0x512fc0'],limits=['Reference fixtures use explicit target/return pointers, while SetState uses actual native case-insensitive name lookup; source script text loading remains separate.','Mask-based character parameter overrides are verified on synthetic configuration records; their connection to every authored configuration directive is not established here.','Interrupt callbacks with arbitrary gameplay side effects, dynamic condition operands and all action command implementations remain open.','Idle and ResetTimer scalar/time/frame/random variants use bounded ordinary numeric tokens; arbitrary expression evaluation, malformed arguments and all floating-point bit patterns are not covered.'])
(native.BASE/'reports/gameplay-scp-transition-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['checks','categories','mismatches','errors']},indent=2));assert not errors
