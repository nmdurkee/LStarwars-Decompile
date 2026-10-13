import importlib.util,struct,json,random
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;vectors=[];errors=[]
def si(v):return v if v<0x80000000 else v-0x100000000
def model(v,local):
 if local and v==0:v=1
 x=v^0x075bd924;sv=si(x);q=(abs(sv)//0x1f31d)*(-1 if sv<0 else 1);v=(x*0x41a7-q*0x7fffffff)&0xffffffff
 if si(v)<0:v=(v+0x7fffffff)&0xffffffff
 return v^0x075bd924
r=random.Random(20261013);seeds=[0,1,0x075bd924,0x7fffffff,0x80000000,0xffffffff]+[r.getrandbits(32)for _ in range(10000)]
for local in [False,True]:
 for seed in seeds:
  n.pack('<I',0x8066c0,seed);n.pack('<I',D,seed);wanted=model(seed,local);result=n.call(0x5b9e90,[D if local else 0]);state=n.unpack('<I',D if local else 0x8066c0)[0]
  if result!=wanted or state!=wanted:errors.append({'local':local,'seed':seed,'actual':[result,state],'wanted':wanted})
  vectors.append({'local':local,'seed':seed,'result':result,'state':state})
(m.BASE/'reports/movement-phase6-20261013-rng-tests.json').write_text(json.dumps({'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':2*len(vectors),'mismatches':len(errors),'errors':errors,'method':'Original5b9e90 return and state compared for all32bit input seeds in deterministic selected/random grid. Full original body executes with no adapters.'},indent=2)+'\n')
(m.BASE/'reports/movement-phase6-20261013-rng-fixtures.json').write_text(json.dumps({'vectors':vectors},separators=(',',':'))+'\n')
print(json.dumps({'cases':len(vectors),'mismatches':len(errors),'examples':errors[:5]}))
