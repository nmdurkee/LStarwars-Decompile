"""Shared bounded GIT native fixture construction; importing performs no tests."""
import importlib.util,json,struct,random,itertools,math,copy
from fractions import Fraction
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn.x86_const import UC_X86_REG_EDI
n=native.NativeX86();D=n.DATA;FLOW=D;NODES=D+0x100;POOL=D+0x10000;WORLD=D+0x30000;TIMERS=D+0x40000;HANDLES=D+0x41000;REG=D+0x42000;REGTYPE=REG+0x100;SYS=REG+0x400;SYSTYPES=SYS+0x100
errors=[];counts={};rng=random.Random(0x59f740);nextPool=POOL
def f32(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def check(kind,got,want,detail=None,tol=0):
    counts[kind]=counts.get(kind,0)+1
    equal=got==want
    if tol:equal=math.isclose(got,want,rel_tol=tol,abs_tol=tol)
    if not equal:errors.append(dict(kind=kind,got=got,want=want,detail=detail))
def alloc(size):
    global nextPool
    p=nextPool;nextPool+=(size+3)&~3;return p
def string(s):p=alloc(len(s)+1);n.write(p,s.encode('latin1')+b'\0');return p
def node(kind=2,parents=None,children=None,flags=0,name='',condition=0,threshold=0,skip=0,duration=1):return dict(kind=kind,parents=parents or [],children=children or [],flags=flags,name=name,condition=condition,threshold=threshold,skip=skip,stamp=0,resetStamp=0,duration=f32(duration),remaining=f32(duration),timerFlags=0,actions=[])
def build(nodes,generation=0,resetGeneration=0):
    global nextPool
    n.write(D,bytes(0x50000));nextPool=POOL;n.pack('<3IB',FLOW,SYS,len(nodes),NODES,generation);n.pack('<I',0x93b268,REG);n.pack('<3I',REG,1,0,REGTYPE);n.pack('<I',SYS,SYSTYPES);n.pack('<I',0x93b2a4,0);n.pack('<B',0x956434,resetGeneration)
    registration=n.call(0x5b0670,[0])
    # PC ADDGIZMOTYPE fields are copied to the runtime callback slots used by 0x55a1b0/55a250.
    for runtime,registered in [(0x44,0x24),(0x48,0x28),(0x54,0x34)]:n.pack('<I',REGTYPE+runtime,n.unpack('<I',registration+registered)[0])
    timerCount=0
    for i,g in enumerate(nodes):
        p=NODES+i*32;n.pack('<4B',p,len(g['parents']),g['skip'],len(g['children']),g['kind']);n.pack('<BBH',p+8,g['stamp'],g['resetStamp'],g['flags'])
        if g['name']:n.pack('<I',p+28,string(g['name']))
        for off,key in [(16,'parents'),(20,'children')]:
            a=alloc(4*len(g[key]))
            for j,k in enumerate(g[key]):n.pack('<I',a+4*j,NODES+32*k)
            n.pack('<I',p+off,a)
        a=alloc(len(g['parents']));n.pack('<I',p+24,a)
        if g['kind']==1:
            cond=alloc(4);n.pack('<BB',cond,g['condition'],g['threshold']);n.pack('<I',p+12,cond)
        elif g['kind']==0:
            ti=timerCount;timerCount+=1;g['timerIndex']=ti;t=TIMERS+ti*28;h=HANDLES+ti*8;n.pack('<ffHB',t,g['remaining'],g['duration'],0,g['timerFlags']);n.write(t+12,('T'+str(i)).encode()+b'\0');n.pack('<I',h,t);n.pack('<B',h+6,0)
            data=alloc(12);ref=alloc(8);refs=alloc(4);n.pack('<II',ref,h,t+12);n.pack('<I',refs,ref);n.pack('<3I',data,1,0,refs);n.pack('<I',p+12,data)
        else:
            previous=0
            for action in g['actions']:
                a=alloc(16);args=alloc(4*len(action));definition=alloc(8);n.pack('<2I',definition,0,0x464760)
                for j,s in enumerate(action):n.pack('<I',args+4*j,string(s))
                n.pack('<4I',a,0,args,len(action),definition)
                if previous:n.pack('<I',previous,a)
                else:n.pack('<I',p+12,a)
                previous=a
    n.pack('<I',WORLD+0x50f8,TIMERS);n.pack('<I',WORLD+0x50fc,timerCount);n.pack('<I',SYSTYPES+4,timerCount);n.pack('<I',SYSTYPES+12,HANDLES)
def snapshot(nodes):
    out=[]
    for i,g in enumerate(nodes):
        p=NODES+i*32;stamp,reset,flags=n.unpack('<BBH',p+8);row=dict(flags=flags,stamp=stamp,resetStamp=reset)
        if g['kind']==0:
            t=TIMERS+g['timerIndex']*28;row.update(remaining=n.unpack('<f',t)[0],timerFlags=n.unpack('<B',t+10)[0])
        out.append(row)
    return out
def expected_snapshot(nodes):return[{**dict(flags=g['flags'],stamp=g['stamp'],resetStamp=g['resetStamp']),**(dict(remaining=g['remaining'],timerFlags=g['timerFlags']) if g['kind']==0 else {})} for g in nodes]
def model_output(nodes,i):
    g=nodes[i]
    if g['kind']==0:return bool(g['timerFlags']&1) and g['remaining']<=0
    return bool(g['flags']&2)
def model_tick(nodes,generation,state=None):
    state=state if state is not None else {'resetGeneration':0}
    generation=(generation+1)&255
    def reset(owner,i,stamp):
        g=nodes[i]
        if i==owner or g['resetStamp']==stamp:return
        g['resetStamp']=stamp
        if g['kind']==0 and not g['flags']&0x1000:g['remaining']=g['duration'];g['timerFlags']&=~1
        for child in g['children']:reset(owner,child,stamp)
    def process(i,depth=0):
        if depth>100:raise RuntimeError('Model cycle exceeds bounded depth')
        g=nodes[i]
        if not g['flags']&1:return
        outs=[model_output(nodes,p) for p in g['parents']]
        if g['kind']==1:
            code=g['condition'];total=sum(outs);threshold=g['threshold']
            success=[all(outs),any(outs),not any(outs),total>=threshold if outs else threshold==0,total>=len(outs)-(g['skip'] if g['flags']&0x400 else 0),total==threshold][code]
        else:success=all(outs)
        if not success:return
        if g['kind']==1 and g['condition']==4:
            for child in g['children']:
                state['resetGeneration']=(state['resetGeneration']+1)&255;reset(i,child,state['resetGeneration'])
        if g['kind']==0:g['remaining']=g['duration'];g['timerFlags']|=1
        for action in g['actions']:
            target=None;active=True
            for token in action:
                k=token.lower().find('name=')
                if k>=0:target=token[k+5:]
                elif token.lower()=='false':active=False
            if target is not None:
                for other in nodes:
                    if other['name'].lower()==target.lower():other['flags']=(other['flags']&~1)|int(active)
        if g['flags']&0x400 and g['flags']&0x800:g['flags']&=~0x400
        g['flags']=(g['flags']&~1)|0x802
        for j in g['children']:
            child=nodes[j];child['flags']|=1
            if child['stamp']!=generation or g['kind']==1:
                child['stamp']=generation;process(j,depth+1)
    for i,g in enumerate(nodes):
        if g['stamp']!=generation and (g['flags']&1 or g['flags']&0x100):process(i)
        g['stamp']=generation
    return generation

