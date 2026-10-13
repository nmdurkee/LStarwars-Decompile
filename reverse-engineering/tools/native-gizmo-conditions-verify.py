import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
WORLD=D;GLOBAL=D+0x3000;TYPES=D+0x3100;REG=D+0x4000;BUCKETS=D+0x4100;RECORDS=D+0x4800;OBJECTS=D+0x5000;ANIMS=D+0xb000;TEXT=D+0xc000;SERVICE=D+0x19000;OUT=D+0x1a000
ADDR={'bindAny':0x443a00,'bindBlowup':0x441630,'GizmoOutput0':0x443a30,'GizmoOutput1':0x443a70,'GizmoOutput2':0x443ab0,'BlowupBlownup':0x441660}
rows=[];errors=[];groups={};events=[];current={};memory=0
names=[['alpha','beta','Alpha',None],['gamma','ALPHA','delta',''],['a','b','c','d'],['delta','omega','zeta','eta'],['edge','Alpha','last',None]]
def record(t,i):return RECORDS+t*0x100+i*8
def identity(p):return None if not p else [(p-RECORDS)//0x100,((p-RECORDS)%0x100)//8]
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);args=n.unpack('<3I',sp+4)
 if address==0x558770:events.append(['name',identity(args[0])])
 else:
  events.append(['output',identity(args[0]),args[1],args[2]])
  if address==SERVICE:
   mu.reg_write(UC_X86_REG_EAX,current['value']);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for address in [0x558770,0x558780,SERVICE]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def options(o):
 p=dict(typeCount=4,types=True,registry=True,accessors=[True,True,True,False,True],outputs=[True,True,False,True,True],blowupType=1,value=0x80000001,mode='service',state=2,proximity=3,bound=[0,0]);p.update(o);return p
def setup(o,name):
 current.clear();current.update(o);events.clear();n.write(D,bytes(0x1b000));n.write(SERVICE,b'\xc3');n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ac8,REG if o['registry'] else 0);n.pack('<i',0x802f54,o['blowupType']);n.pack('<I',0x93b268,GLOBAL if o['types'] else 0);n.pack('<iII',GLOBAL,o['typeCount'],0,TYPES);n.pack('<I',REG,BUCKETS)
 for typ in range(5):
  n.pack('<II',TYPES+typ*0x9c+0x44,0x558770 if o['accessors'][typ] else 0,(0x558780 if o['mode']=='obstacle' else SERVICE) if o['outputs'][typ] else 0);n.pack('<i',BUCKETS+typ*20+4,4);n.pack('<I',BUCKETS+typ*20+12,record(typ,0))
  for i,namevalue in enumerate(names[typ]):
   rec=record(typ,i);obj=OBJECTS+typ*0x1000+i*0x100;anim=ANIMS+typ*0x100+i*0x20;n.pack('<I',rec,obj if namevalue is not None else 0);n.pack('<B',rec+6,typ)
   if namevalue is not None:n.write(obj,namevalue.encode()+b'\0');n.pack('<I',obj+0x34,anim);n.pack('<II',obj+0x94,3,o['proximity']);n.pack('<i',anim+0xc,o['state'])
 if name is not None:n.write(TEXT,name.encode()+b'\0')
def model(kind,o,name):
 ev=[]
 if kind.startswith('bind'):
  if name is None or not o['types'] or not o['registry']:return dict(result=None,events=ev)
  typ=-1 if kind=='bindAny' else o['blowupType'];indices=range(max(0,o['typeCount'])) if typ<0 or typ>o['typeCount'] else [typ]
  for typ in indices:
   if not o['accessors'][typ]:continue
   for i,candidate in enumerate(names[typ]):
    ev.append(['name',[typ,i]])
    if candidate is not None and candidate.lower()==name.split('\0')[0].lower():return dict(result=[typ,i],events=ev)
  return dict(result=None,events=ev)
 bound=o['bound'];value=0;index={'GizmoOutput0':0,'GizmoOutput1':1,'GizmoOutput2':2,'BlowupBlownup':0}[kind]
 if bound is not None and o['types'] and o['registry'] and bound[0]<o['typeCount'] and o['outputs'][bound[0]]:
  ev.append(['output',bound,index,1])
  if o['mode']=='service':value=o['value']
  elif names[bound[0]][bound[1]] is not None:value=int(o['state']==2) if index==0 else int(o['state']!=0) if index==1 else int(o['proximity']!=0)
 return dict(result=bits(float(bool(value)) if kind=='BlowupBlownup' else float(value)),events=ev)
def run(kind,inputs=None,name=None,source=None):
 global memory
 o=options(inputs or {});setup(o,name);before=n.read(D,0x1a000)
 if kind.startswith('bind'):result=identity(n.call(ADDR[kind],[0,TEXT if name is not None else 0,0]))
 else:
  bound=o['bound'];n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(ADDR[kind],[0,0,0,0,0 if bound is None else record(*bound)]);n.mu.emu_start(n.STOP,n.STOP+6);result=n.unpack('<I',OUT)[0]
 got=dict(result=result,events=events.copy());want=model(kind,o,name);bad=[];memory+=1
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x1a000)!=before:bad.append('input memory changed')
 if bad:errors.append(dict(kind=kind,options=o,name=name,bad=bad))
 rows.append(dict(kind=kind,options=o,name=name,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses={r['name']:r['uses'] for r in ledger['rows'] if r['name'] in ADDR}
 for kind in ['bindAny','bindBlowup']:
  for name in [None,'','alpha','ALPHA','beta','gamma','omega','edge','missing','alpha\0ignored']:
   for typ in [-1,0,1,3,4,7]:
    for gate in ['normal','types','registry']:
     o=dict(blowupType=typ)
     if gate!='normal':o[gate]=False
     run(kind,o,name)
 for kind in ['GizmoOutput0','GizmoOutput1','GizmoOutput2','BlowupBlownup']:
  for bound in [None,[0,0],[0,3],[1,1],[2,0],[3,0],[4,0]]:
   for count in [-1,0,1,3,4,5]:
    for value in [0,1,2,0x7fffff,0xffffff,0x1000001,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]:run(kind,dict(bound=bound,typeCount=count,value=value))
  for state in [-1,0,1,2,3,4]:
   for proximity in [0,1,0xffffffff]:
    for bound in [[0,0],[0,3],[1,1]]:run(kind,dict(mode='obstacle',state=state,proximity=proximity,bound=bound))
  for types,registry in itertools.product([False,True],repeat=2):run(kind,dict(types=types,registry=registry))
 for kind,authored in uses.items():
  for source in authored:
   for mode in ['service','obstacle']:run(kind,dict(mode=mode),source=source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:6],method='Original condition wrappers,55a020 name lookup,558770 name accessor and55a1b0 output dispatcher execute unchanged. Output tests include both a declared arbitrary-uint callback service and actual558780 obstacle callbacks. Compare float32 conversion, callback order and complete input memory.',limits=['Existing bounded SceneryRegistry and SceneryNameBindings projections; prepared current-world/type arrays with valid extra index==count slot where tested.','Generic output callbacks remain physical-type services. Actual obstacle output is covered; BlowupBlownup wrapper verification does not claim the blowup simulation/output producer is recovered.','Finite valid ASCII name buffers and bounded type counts; managed replay pending.'])
 (B/'reports/native-gizmo-conditions-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-gizmo-conditions-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,names=names,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
