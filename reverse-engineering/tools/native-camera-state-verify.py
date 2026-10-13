"""Camera cut helper native state and complete write-set verification; no game launch."""
import importlib.util,struct,json,itertools,random
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');spec=importlib.util.spec_from_file_location('camera_state_native',p);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA;REC=D;OTHER=D+0x100;WORLD=D+0x1000;A=D+0x2000;Z=D+0x2100;G=0x9514b0;SIZE=0x480
from unicorn import UC_HOOK_CODE
calls={}
def observer(mu,a,size,user):calls[hex(a)]=calls.get(hex(a),0)+1
for a in [0x5765b0,0x577790,0x577880]:n.mu.hook_add(UC_HOOK_CODE,observer,begin=a,end=a)
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(i):return struct.unpack('<f',struct.pack('<I',i))[0]
scalar={'progress':0x9514c8,'blendIn':0x9514d8,'borders':0x9514e0,'selected':0x9514e4,'end':0x9514e8,'blendOut':0x9514ec,'positionStorage':0x9514f8,'extra':0x9514fc,'start':0x951914,'flags':0x951918,'elapsed':0x95191c,'followTarget':0x951920,'followCamera':0x951924}
def snap():
 out={k:n.unpack('<I',a)[0]for k,a in scalar.items()};out.update(kind=n.unpack('<H',0x9514f0)[0],vectorBytes=n.unpack('<H',0x9514f2)[0],transitionWord=n.unpack('<H',0x9514dc)[0],transitionByte=n.unpack('<B',0x9514de)[0],borderAmount=n.unpack('<I',0x950760)[0],worldMode=n.unpack('<B',WORLD+0x22c)[0],worldPrevious=n.unpack('<I',WORLD+0x1bc)[0],worldCurrent=n.unpack('<I',WORLD+0x1c0)[0],currentBlend=n.unpack('<I',0x951508 if n.unpack('<I',0x9514b8)[0]==0x9514f0 else REC+0x18)[0],camera=list(n.unpack('<3I',0x9518fc)),target=list(n.unpack('<3I',0x951908)))
 return out
def setup(v):
 n.write(G,bytes([0xa5])*SIZE);n.write(D,bytes([0x5a])*0x3000);n.pack('<I',0x9514b8,(0x9514f0 if v['currentBuiltin']else REC)if v['current']else 0);n.pack('<II',REC+8,v['duration'],0);n.pack('<I',REC+0x18,v['currentBlend']);n.pack('<I',0x8021b4,WORLD);n.pack('<I',0x951288,v['suppressFlags']);n.pack('<I',0x950760,v['borderAmount'])
 for k,a in scalar.items():n.pack('<I',a,v[k])
 if v['currentBuiltin']:n.pack('<I',0x951508,v['currentBlend'])
 for k,a in [('kind',0x9514f0),('vectorBytes',0x9514f2),('transitionWord',0x9514dc)]:n.pack('<H',a,v[k])
 n.pack('<B',0x9514de,v['transitionByte']);n.pack('<B',WORLD+0x22c,v['worldMode']);n.pack('<II',WORLD+0x1bc,v['worldPrevious'],v['worldCurrent']);n.pack('<3I',0x9518fc,*v['camera']);n.pack('<3I',0x951908,*v['target']);n.pack('<3I',A,*v['pointA']);n.pack('<3I',Z,*v['pointZ'])
def base(**kw):
 v=dict(current=True,currentBuiltin=False,duration=bits(3),currentBlend=bits(7),suppressFlags=0,progress=bits(.25),start=bits(22),end=bits(33),blendIn=bits(4),blendOut=bits(5),elapsed=bits(8),flags=0xdeadbeef,borders=3,borderAmount=bits(.25),selected=OTHER,followTarget=A,followCamera=Z,kind=0x1234,vectorBytes=0x5678,positionStorage=0x12345678,extra=0x87654321,transitionWord=0xface,transitionByte=0x7f,worldMode=0x37,worldPrevious=bits(8),worldCurrent=bits(9),camera=[bits(x)for x in [1,2,3]],target=[bits(x)for x in [4,5,6]],pointA=[bits(x)for x in [-11,12,-13]],pointZ=[bits(x)for x in [21,-22,23]])
 v.update(kw);return v
def finish(v,o):
 if v['current']:
  duration=o['positionStorage']if v['currentBuiltin']else v['duration']
  if fl(duration)!=0:
   d=fl(duration)-.5
   if fl(o['progress'])<d:o['progress']=bits(d)
  o['currentBlend']=0
def model(v,op,q):
 o=snap()
 if op=='finish':finish(v,o);return o
 if op=='select'and not q['record']:return o
 if op=='configure':
  o.update(kind=2,vectorBytes=12,positionStorage=0x9518fc,extra=q['extra'])
  if q['camera']:o['camera']=v['pointA'][:]
  if q['target']:o['target']=v['pointZ'][:]
 o.update(start=q['start'],end=q['end'],blendIn=q['blendIn'],blendOut=q['blendOut'],flags=0 if op=='configure'or v['suppressFlags']else q['flags'],elapsed=0,selected=0x9514f0 if op=='configure'else OTHER,transitionWord=0,transitionByte=0,followTarget=0,followCamera=0,borders=q['borders'])
 if q['borders']and fl(q['start'])==0 and fl(q['blendIn'])<=0:o['borderAmount']=bits(1)
 if fl(q['start'])<=0 and fl(q['blendIn'])<=0:o.update(worldMode=255,worldPrevious=v['worldCurrent'])
 finish(v,o)
 if op=='configure':
  if q['target']and q['followTarget']:o['followTarget']=Z
  if q['camera']and q['followCamera']:o['followCamera']=A
 return o
rows=[];errors=[];writes=[]
def run(op,v,q):
 setup(v);before={p:bytearray(n.read(p,z))for p,z in [(G,SIZE),(D,0x3000),(0x950760,4)]};expected=model(v,op,q)
 if op=='finish':n.call(0x5765b0)
 elif op=='select':n.call(0x577790,[OTHER if q['record']else 0,q['start'],q['end'],q['blendIn'],q['blendOut'],q['borders'],q['flags']])
 else:n.call(0x577880,[A if q['camera']else 0,Z if q['target']else 0,q['extra'],q['start'],q['end'],q['blendIn'],q['blendOut'],int(q['followTarget']),int(q['followCamera']),q['borders']])
 actual=snap();i=len(rows)
 if actual!=expected:errors.append(dict(i=i,op=op,actual=actual,expected=expected))
 # Reconstruct the only permitted writes into complete surrounding memory images.
 def put(a,fmt,*x):
  for p,b in before.items():
   if p<=a and a+struct.calcsize(fmt)<=p+len(b):struct.pack_into(fmt,b,a-p,*x);return
  raise AssertionError(hex(a))
 for k,a in scalar.items():put(a,'<I',expected[k])
 for k,a in [('kind',0x9514f0),('vectorBytes',0x9514f2),('transitionWord',0x9514dc)]:put(a,'<H',expected[k])
 put(0x9514de,'<B',expected['transitionByte']);put(0x950760,'<I',expected['borderAmount']);put(WORLD+0x22c,'<B',expected['worldMode']);put(WORLD+0x1bc,'<II',expected['worldPrevious'],expected['worldCurrent']);put(0x951508 if v['currentBuiltin']else REC+0x18,'<I',expected['currentBlend']);put(0x9518fc,'<3I',*expected['camera']);put(0x951908,'<3I',*expected['target'])
 for p,b in before.items():
  a=n.read(p,len(b))
  if a!=b:writes.append(dict(i=i,base=hex(p),offsets=[hex(k)for k in range(len(b))if a[k]!=b[k]][:32]))
 rows.append(dict(operation=op,input=v,arguments=q,expected=actual))
vals=[0,0x80000000,bits(.5),bits(1),bits(-1),bits(3),bits(16777216),bits(-16777216),1,0x80000001,0x7f7fffff,0xff7fffff]
for current,duration,progress in itertools.product([False,True],vals,vals):run('finish',base(current=current,duration=duration,progress=progress),{})
r=random.Random(0x577790)
for i in range(1800):
 a=r.randrange(0x7f800000)|(r.randrange(2)<<31);b=r.randrange(0x7f800000)|(r.randrange(2)<<31);run('finish',base(duration=a,progress=b),{})
for current,record,suppress,start,blend,borders in itertools.product([False,True],[False,True],[0,1,0x80000000],[bits(-1),0,0x80000000,bits(1)],[bits(-1),0,0x80000000,bits(1)],[0,1,0xffffffff]):
 run('select',base(current=current,suppressFlags=suppress),dict(record=record,start=start,end=bits(12),blendIn=blend,blendOut=bits(-2),flags=0x87654321,borders=borders))
for camera,target,ft,fc,current,start,blend,borders in itertools.product([False,True],[False,True],[False,True],[False,True],[False,True],[0,bits(1)],[bits(-1),bits(1)],[0,1]):
 run('configure',base(current=current,pointA=[0x80000000,1,0x7f7fffff],pointZ=[0,0x80000001,0xff7fffff]),dict(camera=camera,target=target,followTarget=ft,followCamera=fc,start=start,end=bits(1e9),blendIn=blend,blendOut=bits(.5),extra=0xaabbccdd,borders=borders))
for op in ['finish','select','configure']:
 for progress,start,blend in itertools.product([bits(-1),bits(-.5),0,bits(1)],[bits(-1),0,bits(1)],[bits(-1),0,bits(1)]):
  run(op,base(currentBuiltin=True,progress=progress),dict(record=True,camera=True,target=True,followTarget=True,followCamera=True,start=start,end=bits(3),blendIn=blend,blendOut=bits(.5),extra=0x12345678,borders=1,flags=0xfedcba98))
report=dict(schema='original-pc-camera-state-v1',binarySha256=n.sha256,cases=len(rows),counts={op:sum(x['operation']==op for x in rows)for op in ['finish','select','configure']},mismatches=len(errors),writeSetMismatches=len(writes),completeMemoryWriteChecks=len(rows)*3,errors=errors[:12],writeErrors=writes[:12],nativeCalls=calls,adapters=[],limits=['Finite float inputs; active built-in record alias and its pointer/duration field overlay are included.','No live camera update, scene selection, or rendering is executed.','Portable managed replay is prepared, not run.'])
(B/'reports/native-camera-state-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-camera-state-vectors.json').write_text(json.dumps(dict(records=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));raise SystemExit(1 if errors or writes else 0)
