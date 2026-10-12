"""Original PC GIT ticks, timer callbacks, reset walks, loop counting and node activation."""
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

# DAG scheduling with arbitrary file order, branching/joins and all non-loop predicates.
for case in range(300):
    size=rng.randint(1,18);order=list(range(size));rng.shuffle(order);nodes=[node(kind=rng.choice([1,2]),condition=rng.choice([0,1,2,3,5]),threshold=rng.randrange(4),flags=rng.choice([0,1,2,0x802,0xc01])) for _ in range(size)]
    for a in range(size):
        for b in range(a+1,size):
            if rng.random()<.12:
                u,v=order[a],order[b];nodes[u]['children'].append(v);nodes[v]['parents'].append(u)
    generation=rng.randrange(256);build(nodes,generation);model=copy.deepcopy(nodes)
    for frame in range(4):
        generation=model_tick(model,generation);n.call(0x59f740,[FLOW]);check('dag-tick',snapshot(nodes),expected_snapshot(model),dict(case=case,frame=frame))

# Real timer callbacks through the actual gizmo registry and the actual GIT scheduler.
timerTrace=[]
for duration in [0.,.05,.25,1.,2.]:
    nodes=[node(0,children=[1],flags=0x4001,duration=duration),node(1,parents=[0],children=[2]),node(2,parents=[1],name='marker')]
    build(nodes);model=copy.deepcopy(nodes);generation=0;trace=[]
    for frame in range(10):
        delta=f32(.25 if frame else 0.)
        for g in model:
            if g['kind']==0 and g['remaining']>=0:g['remaining']=f32(g['remaining']-delta)
        n.call(0x5b0400,[WORLD,0,bits(delta)]);generation=model_tick(model,generation);n.call(0x59f740,[FLOW]);got=snapshot(nodes);check('timer-gizmo-graph-tick',got,expected_snapshot(model),dict(duration=duration,frame=frame));trace.append(dict(frame=frame,remaining=got[0]['remaining'],timerActivationComplete=bool(got[0]['flags']&2),sinkComplete=bool(got[2]['flags']&2)))
    if duration==1.:timerTrace=trace

# A persistent Timer -> Action -> Loop cycle, including actual native graph initialization.
loopTraces=[]
for duration in [.1,.25,1.,2.]:
    nodes=[node(0,parents=[2],children=[1],flags=0x4000,duration=duration),node(2,parents=[0],children=[2]),node(1,parents=[1],children=[0],condition=4)]
    build(nodes);n.call(0x59f4e0,[FLOW,0]);initial=snapshot(nodes)
    check('loop-initializer-active-flags',[g['flags'] for g in initial],[0x4000,0,0xc01],duration);check('loop-initializer-return-input-count',n.unpack('<B',NODES+2*32+1)[0],1,duration)
    for i,g in enumerate(nodes):g.update(initial[i]);g['skip']=n.unpack('<B',NODES+i*32+1)[0]
    model=copy.deepcopy(nodes);state={'resetGeneration':n.unpack('<B',0x956434)[0]};generation=0;trace=[]
    for frame in range(270):
        delta=f32(.125 if frame else 0)
        for g in model:
            if g['kind']==0 and g['remaining']>=0:g['remaining']=f32(g['remaining']-delta)
        n.call(0x5b0400,[WORLD,0,bits(delta)]);generation=model_tick(model,generation,state);n.call(0x59f740,[FLOW]);got=snapshot(nodes)
        check('persistent-loop-timer-graph',got,expected_snapshot(model),dict(duration=duration,frame=frame));check('persistent-loop-reset-generation',n.unpack('<B',0x956434)[0],state['resetGeneration'])
        if frame<20 or frame>252:trace.append(dict(frame=frame,generation=generation,remaining=got[0]['remaining'],flags=[g['flags'] for g in got],resetGeneration=state['resetGeneration']))
    loopTraces.append(dict(duration=duration,trace=trace))

# TurnOnFlowBox is tested inside actual linked action lists, including named duplicate targets.
for case,actions in enumerate([[['name=door']], [['name=DOOR','FALSE']], [['name=door','FALSE'],['name=door']], [['FALSE','name=door']], [['name=missing']], [['name=door','TRUE']], [['name=door','FALSE','TRUE']]]):
    nodes=[node(2,flags=1),node(2,flags=0x800,name='Door'),node(2,flags=2,name='door'),node(2,flags=0x400,name='other')];nodes[0]['actions']=actions;build(nodes);model=copy.deepcopy(nodes)
    generation=model_tick(model,0);n.call(0x59f740,[FLOW]);check('turn-on-flowbox-linked-action',snapshot(nodes),expected_snapshot(model),dict(case=case,actions=actions))

# Reset traversal visits descendants once per generation, stops at the owning Loop,
# and calls the original timer deactivation callback unless node flag0x1000 suppresses it.
for case in range(200):
    size=rng.randint(2,18);nodes=[node(1,condition=4)]+[node(0 if rng.random()<.5 else 2,flags=0x4000|(0x1000 if rng.random()<.3 else 0),duration=f32(rng.uniform(.1,4))) for _ in range(size-1)]
    for g in nodes:g['resetStamp']=rng.randrange(256)
    for i,g in enumerate(nodes):g['children']=rng.sample(range(size),rng.randrange(min(size,4)))
    for g in nodes:
        if g['kind']==0:g['remaining']=-1.;g['timerFlags']=1
    start=rng.randrange(1,size);generation=rng.randrange(256);build(nodes);model=copy.deepcopy(nodes)
    def reset(i):
        g=model[i]
        if i==0 or g['resetStamp']==generation:return
        g['resetStamp']=generation
        if g['kind']==0 and not g['flags']&0x1000:g['remaining']=g['duration'];g['timerFlags']&=~1
        for j in g['children']:reset(j)
    reset(start);n.call(0x59da60,[FLOW,NODES,NODES+32*start,generation]);check('loop-descendant-reset',snapshot(nodes),expected_snapshot(model),dict(case=case,start=start,generation=generation))

# Loop cycle-input count: actual recursive helper returns number of reachable return edges.
for case in range(200):
    size=rng.randint(2,20);nodes=[node() for _ in range(size)]
    for i,g in enumerate(nodes):g['children']=rng.sample(range(size),rng.randrange(min(size,4)))
    generation=rng.randrange(1,256);build(nodes);model=copy.deepcopy(nodes)
    def walk(i,total):
        if i==0:model[0]['resetStamp']=(model[0]['resetStamp']-1)&255;return total+1
        for j in model[i]['children']:
            if model[j]['resetStamp']!=generation:model[j]['resetStamp']=generation;total=walk(j,total)
        return total
    want=0
    for j in model[0]['children']:want=walk(j,want)
    got=n.call(0x59da30,[generation],regs={UC_X86_REG_EDI:NODES});check('loop-return-edge-count',got,want,case);check('loop-count-visit-marks',snapshot(nodes),expected_snapshot(model),case)

# Monitored condition output recomputes the predicate, temporarily sets0x400, then restores it.
for complete,monitor,prior400 in itertools.product([False,True],repeat=3):
    for states in itertools.product([False,True],repeat=3):
        for code in [0,1,2,3,4,5]:
            nodes=[node(1,parents=[1,2,3],condition=code,threshold=2,skip=1,flags=(2 if complete else 0)|(0x200 if monitor else 0)|(0x400 if prior400 else 0))]+[node(2,flags=2 if v else 0) for v in states]
            build(nodes);before=snapshot(nodes);total=sum(states);predicates=[all(states),any(states),not any(states),total>=2,total>=2,total==2];want=int(predicates[code]) if monitor else int(complete)
            check('monitored-condition-output',n.call(0x59ddd0,[FLOW,NODES]),want,dict(code=code,states=states,monitor=monitor,prior400=prior400));check('monitor-restores-transient-flag',snapshot(nodes),before)

# Parent cleanup releases pending effects only when every child crosses its barrier.
cleanupFlags=[0,1,2,3,0x40,0x42,0x43,0x80,0x82,0x83,0x100,0x102,0x140,0x142,0x143,0x180,0x182,0x183]
for a,b,deactivate,reverse,recursive in itertools.product(cleanupFlags,cleanupFlags,[False,True],[False,True],[False,True]):
    parentFlags=0x120|(0x10 if deactivate else 0)|(8 if reverse else 0)|(0x40 if recursive else 0)
    nodes=[node(0,children=[1,2],flags=parentFlags,duration=1.5),node(2,parents=[0],flags=a),node(2,parents=[0],flags=b)]
    nodes[0]['remaining']=-.5;nodes[0]['timerFlags']=1;build(nodes);model=copy.deepcopy(nodes)
    def released(flags,current):return bool(flags&2) and not bool(flags&0x100) if flags&0xc0 else not bool(flags&1) or current
    release=released(a,True) and released(b,False)
    if release:
        model[0]['flags']&=~0x20
        if recursive:model[0]['flags']&=~0x100
        if deactivate and not reverse:model[0]['remaining']=1.5;model[0]['timerFlags']&=~1
    n.call(0x59de40,[FLOW,NODES+32]);check('parent-cleanup-child-barriers',snapshot(nodes),expected_snapshot(model),dict(a=a,b=b,deactivate=deactivate,reverse=reverse,recursive=recursive))

# Timer boundary and randomized activation fields: original x86 includes remaining==0.
timerScalar=D+0x48000;timerHandle=timerScalar+0x80;n.pack('<I',timerHandle,timerScalar)
for remaining,delta,enabled in itertools.product([-1.,0.,.01,.1,1.],[0.,.01,.25,2.],[False,True]):
    n.pack('<I',WORLD+0x50f8,timerScalar);n.pack('<I',WORLD+0x50fc,1);n.pack('<f',timerScalar,remaining);n.pack('<B',timerScalar+10,int(enabled));n.call(0x5b0400,[WORLD,0,bits(delta)])
    want=f32(f32(remaining)-f32(delta)) if remaining>=0 else f32(remaining);check('timer-countdown-boundary',n.unpack('<f',timerScalar)[0],want);check('timer-output-enabled-and-expired',n.call(0x5b0470,[timerHandle]),int(enabled and want<=0))
for seed in [0,1,0xffff,0x8000]+[rng.randrange(65536) for _ in range(200)]:
    for activate in [0,1]:
        state=(seed*0x24cd+1)&0xffff;n.pack('<I',0x80253c,seed);n.pack('<f',timerScalar+4,3.25);n.pack('<B',timerScalar+10,0x82);n.call(0x5b04b0,[timerHandle,activate])
        check('random-timer-lcg',n.unpack('<I',0x80253c)[0],state);check('random-timer-duration',n.unpack('<f',timerScalar)[0],f32(state/65535*3.25),tol=1e-6);check('timer-activation-preserves-flags',n.unpack('<B',timerScalar+10)[0],0x82|activate)

# Complete 16-bit QRAND state space for equal 25/25/25/25 GizRandom weights.
randomObj=timerScalar;randomHandle=timerHandle;n.pack('<I',randomHandle,randomObj);n.pack('<I',randomObj+0x10,4);n.pack('<4i',randomObj+0x14,25,25,25,25)
distribution={};noneSeeds=[];reciprocal=Fraction.from_float(n.unpack('<d',0x751700)[0])
for seed in range(65536):
    n.pack('<I',0x80253c,seed);n.pack('<B',randomObj+0x38,0x80);n.call(0x5b00b0,[randomHandle,1]);state=(seed*0x24cd+1)&0xffff;draw=1+int(state*reciprocal*100);wanted=(draw-1)//25 if draw<=100 else 0xffffffff;got=n.unpack('<I',randomObj+0x34)[0]
    check('gizrandom-full-state-selection',got,wanted,dict(seed=seed,state=state,draw=draw));check('gizrandom-full-state-rng',n.unpack('<I',0x80253c)[0],state);distribution[str(got)]=distribution.get(str(got),0)+1
    if got==0xffffffff:noneSeeds.append(dict(seed=seed,updatedState=state,draw=draw))
for weights in [[0,100],[50,50],[10,20,30],[100,100],[-1,101],[1,1,98]]:
    n.pack('<I',randomObj+0x10,len(weights));n.pack('<'+'i'*len(weights),randomObj+0x14,*weights)
    for seed in range(0,65536,257):
        n.pack('<I',0x80253c,seed);n.call(0x5b00b0,[randomHandle,1]);state=(seed*0x24cd+1)&0xffff;draw=1+int(state*reciprocal*100);low=0;want=0xffffffff
        for i,weight in enumerate(weights):
            if low<=draw<=low+weight:want=i;break
            low+=weight
        check('gizrandom-weighted-range',n.unpack('<I',randomObj+0x34)[0],want,dict(weights=weights,seed=seed,draw=draw))
    chosen=n.unpack('<I',randomObj+0x34)[0];state=n.unpack('<I',0x80253c)[0];n.call(0x5b00b0,[randomHandle,0]);check('gizrandom-deactivate-retains-choice',n.unpack('<I',randomObj+0x34)[0],chosen);check('gizrandom-deactivate-retains-rng',n.unpack('<I',0x80253c)[0],state);check('gizrandom-deactivate-clears-enabled',n.unpack('<B',randomObj+0x38)[0]&1,0)

report=dict(binarySha256=n.sha256,method='Original PC GIT tick/process/output/action/reset routines and real GizTimer/GizRandom callbacks execute on synthetic graphs, with an independent graph/timer model. Actual registered function pointers retained; no replacement callbacks, OS API or game launch.',checks=sum(counts.values()),categories=counts,mismatches=len(errors),errors=errors[:50],timerTrace=timerTrace,loopTraces=loopTraces,gizRandomDistribution=distribution,gizRandomNoOutputCases=noneSeeds,functions=['0x59f740','0x59e090','0x59f8d0','0x59e030','0x59db00','0x59ddd0','0x59da60','0x59da30','0x59d9d0','0x59de40','0x464760','0x55a250','0x55a1b0','0x5b0670','0x5b0400','0x5b0470','0x5b04b0','0x5b00b0','0x54fa60'],contracts={'tick':'Flow+0xc generation is an 8-bit increment, including wrap to zero. Nodes are scanned in array order. Active bit0 or monitor bit0x100 enters processing if node generation differs. Successful activation sets0x802 and clears bit0, then recursively activates children. Condition parents may revisit an already stamped child.','timer':'Gizmo activation finishes immediately, but output remains false until enabled flag bit0 and remaining<=0. Update subtracts delta when remaining>=0; it does not clamp negative results. Activate/deactivate both reset duration, with randomized reset when flag bit1 is set.','loopReset':'Recursive0x59da60 stamps byte+9, stops at owning Loop and previously visited generation. It deactivates descendant gizmos unless nodeflag0x1000 is set; it does not clear node completion flags. A fresh reset generation is used for each immediate Loop child.','parentCleanup':'Pending flag0x20 releases when all children cross their state barrier: ordinary children may be inactive or the current child; children with flags0xc0 require completion and no0x100. Flag0x10 deactivates associated gizmos if flag8 is absent; flag0x40 clears0x100 and recursively releases parents. Reverse callback behavior itself remains unverified.', 'cycleCount':'0x59da30 uses custom EDI root and returns reachable root-return edge count for loop startup threshold adjustment.','monitor':'Condition output with flag0x200 recomputes its kind process with temporary flag0x400, then restores the prior flag0x400 value. Without monitor it returns completion bit1.','TurnOnFlowBox':'Case-insensitive matching of all node names. name= chooses target; FALSE disables active bit0. TRUE does not undo FALSE within a call. Other flags/completion remain unchanged. Linked actions run in order.','GizRandom':'16-bit QRAND is state=(state*0x24cd+1)&65535. Draw=1+floor(updatedState*C*100), where C is the exact binary64 reciprocal at0x751700, evaluated by x87 before truncation. Its slight rounding below1/65535 keeps the top draw at100. Select the first inclusive cumulative interval. All65536 states give exactly16384 choices per output for25/25/25/25 weights.'},limits=['Graph DAG scheduling model covers action/condition nodes and timer callbacks, not every gizmo or arbitrary cyclic scheduler graph.','A Timer/Action/Loop cycle, including actual initialization, was checked for270 frames at each of four durations, including generation wrap. Other real puzzle topologies and non-timer gizmos remain unverified.','Reset/monitor side effects on real non-timer gizmos remain unverified.','Synthetic runtime records were constructed from native layouts; no original GIT text-loader emulation or full level simulation is implied.'])
(native.BASE/'reports/gameplay-git-runtime-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['checks','categories','mismatches','errors','gizRandomDistribution','gizRandomNoOutputCases']},indent=2));assert not errors
