"""Capture original-PC outputs for independent compiled C# differential validation."""
import importlib.util,json,random,copy,struct,base64
from pathlib import Path
p=Path(__file__).with_name('gameplay-git-fixture.py');s=importlib.util.spec_from_file_location('fixture',p);f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;rng=random.Random(0x592025);graphs=[]
def capture(nodes,frames=5,initialize=False,delta=.125,generation=0):
    initial=copy.deepcopy(nodes);f.build(nodes,generation)
    if initialize:n.call(0x59f4e0,[f.FLOW,0])
    entry=dict(nodes=initial,initialize=initialize,generation=generation,initialState=f.snapshot(nodes),initialResetGeneration=n.unpack('<B',0x956434)[0],frames=[])
    for frame in range(frames):
        dt=f.f32(0 if frame==0 else delta);n.call(0x5b0400,[f.WORLD,0,f.bits(dt)]);n.call(0x59f740,[f.FLOW]);entry['frames'].append(dict(delta=dt,state=f.snapshot(nodes),generation=n.unpack('<B',f.FLOW+12)[0],resetGeneration=n.unpack('<B',0x956434)[0]))
    graphs.append(entry)
for case in range(160):
    size=rng.randint(1,18);order=list(range(size));rng.shuffle(order);nodes=[f.node(rng.choice([1,2]),condition=rng.choice([0,1,2,3,5]),threshold=rng.randrange(4),flags=rng.choice([0,1,2,0x802,0xc01])) for _ in range(size)]
    for a in range(size):
        for b in range(a+1,size):
            if rng.random()<.12:u,v=order[a],order[b];nodes[u]['children'].append(v);nodes[v]['parents'].append(u)
    capture(nodes,generation=rng.randrange(256))
for duration in [.1,.25,1.,2.]:
    capture([f.node(0,parents=[2],children=[1],flags=0x4000,duration=duration),f.node(2,parents=[0],children=[2]),f.node(1,parents=[1],children=[0],condition=4)],frames=270,initialize=True)
for flags in [0x4001,0x4011,0x4009,0x4041,0x4081,0x4051,0x4091,0x40c1,0x5011]:
    capture([f.node(0,children=[1],flags=flags,duration=.25),f.node(2,parents=[0],children=[2]),f.node(2,parents=[1])],frames=12)
for actions in [[['name=door']],[['name=DOOR','FALSE']],[['name=door','FALSE'],['name=door']],[['FALSE','name=door']],[['name=missing']],[['name=door','TRUE']],[['name=door','FALSE','TRUE']]]:
    nodes=[f.node(2,flags=1),f.node(2,flags=0x800,name='Door'),f.node(2,flags=2,name='door'),f.node(2,flags=0x400,name='other')];nodes[0]['actions']=actions;capture(nodes,frames=3)
# All initial seeds: capture exact native selected output and exact random timer float bits.
obj=f.D+0x50000;handle=obj+0x100;n.pack('<I',handle,obj);n.pack('<I',obj+0x10,4);n.pack('<4i',obj+0x14,25,25,25,25);selected=bytearray()
for seed in range(65536):
    n.pack('<I',0x80253c,seed);n.call(0x5b00b0,[handle,1]);selected.append(n.unpack('<I',obj+0x34)[0])
randomTimers=[]
for duration in [.05,.1,.2,.33333334,1.,3.25,15.,100.,123.4567]:
    duration=f.f32(duration);n.pack('<f',obj+4,duration);n.pack('<B',obj+10,2)
    for seed in list(range(0,65536,53))+[65535,65534,13107,26214,39321,52428]:
        n.pack('<I',0x80253c,seed);n.call(0x5b04b0,[handle,1]);randomTimers.append([seed,f.bits(duration),n.unpack('<I',obj)[0],n.unpack('<I',0x80253c)[0]])
state=json.loads((f.native.BASE/'reports/gameplay-git-state-tests.json').read_text())
report=dict(binarySha256=n.sha256,graphs=graphs,equalRandomSelections=base64.b64encode(selected).decode(),randomTimers=randomTimers,savedStates=state['portableFixtures'],physicalCases=state['physicalCases'],monitorOutputCases=state['monitorOutputCases'],scope='Expected outputs captured from original PC code; compiled C# core is not used to generate expectations.')
out=f.native.BASE/'reports/gameplay-portable-fixtures.json';out.write_text(json.dumps(report,separators=(',',':')));print(json.dumps(dict(graphs=len(graphs),graphFrames=sum(len(g['frames']) for g in graphs),randomSeeds=len(selected),randomTimers=len(randomTimers),savedStates=len(state['portableFixtures']),physicalCases=len(state['physicalCases']),bytes=out.stat().st_size)))
