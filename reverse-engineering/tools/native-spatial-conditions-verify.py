import importlib.util,json,struct,random,math
from pathlib import Path
s=importlib.util.spec_from_file_location('ranges',Path(__file__).with_name('native-locator-random-conditions-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q)
d=q.d;v=q.v;n=q.n;B=q.B;D=n.DATA
SYS=q.SYS;CRE=q.CRE;REF=q.REF;PACK=q.PACK;LOC=q.LOC;NAME=q.NAME;OUT=q.OUT;P0=D+0x7000;P1=D+0x8000
rows=[];errors=[];groups={};memory=0
addresses={'bind':0x52d090,'current':0x514bb0,'onpath':0x514b20,'rangeXZ':0x514a50,'player':0x514c30,'nearest':0x514c80,'distanceXZ':0x5bed80}
def square(a,b,xz=False):
 dif=[d.store(v.F(x)-v.F(y)) for x,y in zip(a,b)]
 if xz:dif[1]=0.
 return d.store(v.add(v.add(v.mul(dif[0],dif[0]),v.mul(dif[1],dif[1])),v.mul(dif[2],dif[2])))
def result_distance(a,b,xz=False):return v.bits(v.f(math.sqrt(square(a,b,xz))))
def setup(o):
 q.setup(o);n.write(P0,bytes(0x2000));n.pack('<I',SYS+0x138c,P0 if o.get('player0',True) else 0);n.pack('<I',SYS+0x1390,P1 if o.get('player1',True) else 0)
 n.pack('<3f',REF+0x5c,*o.get('actor',[9.,8.,7.]));n.pack('<3f',P0+0x5c,*o.get('p0',[1.,2.,3.]));n.pack('<3f',P1+0x5c,*o.get('p1',[-2.,4.,1.]));n.pack('<B',CRE+0x166,o.get('nodeFlags',0))
def run(kind,o,source=None):
 global memory
 setup(o);before=bytearray(n.read(D,0x6000));players=n.read(P0,0x2000);args=[]
 selected=o.get('selected',0);bound=o.get('bound',-1);creature=CRE if o.get('creature',True) else 0;system=SYS if o.get('system',True) else 0
 if kind=='bind':
  name=o['name']
  if name is not None:n.write(NAME,name.encode()+b'\0')
  before=bytearray(n.read(D,0x6000));ptr=n.call(addresses[kind],[system,NAME if name is not None else 0]);got=-1 if ptr==0 else (ptr-LOC)//0x3c;want=next((i for i,x in enumerate(q.names) if x.lower()==name.split('\0')[0].lower()),-1) if name is not None and system else -1
 elif kind=='distanceXZ':
  n.pack('<3f',NAME,*o['a']);n.pack('<3f',NAME+0x10,*o['b']);before=bytearray(n.read(D,0x6000));scratch=NAME+0x20 if o.get('scratch',True) else 0
  if scratch:struct.pack_into('<3f',before,NAME+0x20-D,d.store(v.F(o['a'][0])-v.F(o['b'][0])),0.,d.store(v.F(o['a'][2])-v.F(o['b'][2])))
  got=q.capture(addresses[kind],[NAME,NAME+0x10,scratch]);want=result_distance(o['a'],o['b'],True)
 else:
  args=[system,PACK,creature,0,0 if bound<0 else LOC+bound*0x3c];got=q.capture(addresses[kind],args)
  if kind=='current':want=v.bits(1. if bound>=0 and selected==bound else 0.)
  elif kind=='onpath':want=v.bits(1. if creature and o.get('nodeFlags',0)&1 else 0.)
  elif kind=='rangeXZ':
   target=bound if bound>=0 else selected;want=result_distance(o.get('position',[0.,0.,0.]),q.points[target],True) if creature and o.get('reference',True) and target>=0 else 0x7f7fffff
  elif not creature or not o.get('reference',True) or not system:want=0x7f7fffff
  elif kind=='player':want=result_distance(o.get('p0',[1.,2.,3.]),o.get('actor',[9.,8.,7.])) if o.get('player0',True) else 0x7f7fffff
  else:
   best=struct.unpack('<f',struct.pack('<I',0x7f7fffff))[0]
   if o.get('player0',True):best=square(o.get('p0',[1.,2.,3.]),o.get('actor',[9.,8.,7.]))
   if o.get('player1',True):best=min(best,square(o.get('p1',[-2.,4.,1.]),o.get('actor',[9.,8.,7.])))
   want=0x7f7fffff if v.bits(best)==0x7f7fffff else v.bits(v.f(math.sqrt(best)))
 memory+=2;bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x6000)!=before:bad.append('input region changed')
 if n.read(P0,0x2000)!=players:bad.append('players changed')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 rows.append(dict(kind=kind,options=o,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());kinds={'LocatorRangeXZ':'rangeXZ','CurrentLocatorIs':'current','OnPath':'onpath','PlayerRange':'player','NearestPlayerRange':'nearest'};uses={x['name']:x['uses'] for x in ledger['rows'] if x['name'] in kinds}
 for name in [None,'','Alpha','ALPHA','beta','missing','Origin','alpha\0later']:
  for system in [False,True]:run('bind',dict(name=name,system=system))
 for bound in [-1,0,1,2,3]:
  for selected in [-1,0,1,2,3]:
   for creature in [False,True]:run('current',dict(bound=bound,selected=selected,creature=creature))
 for flags in range(256):
  for creature in [False,True]:run('onpath',dict(nodeFlags=flags,creature=creature,reference=False))
 rng=random.Random(514880)
 for kind in ['rangeXZ','player','nearest']:
  for mask in range(32):
   for i in range(24):
    o=dict(system=bool(mask&1),creature=bool(mask&2),reference=bool(mask&4),player0=bool(mask&8),player1=bool(mask&16),bound=rng.choice([-1,0,1,2,3]),selected=rng.choice([-1,0,1,2,3]))
    for key in ['position','actor','p0','p1']:o[key]=[v.f(rng.uniform(-1000,1000)) for j in range(3)]
    run(kind,o)
 for i in range(1024):
  a=[v.f(rng.uniform(-1.e6,1.e6)) for j in range(3)];b=[v.f(rng.uniform(-1.e6,1.e6)) for j in range(3)]
  for scratch in [False,True]:run('distanceXZ',dict(a=a,b=b,scratch=scratch))
 for a,b in [([0.,0.,0.],[0.,0.,0.]),([1.,2**-12,2**-27],[0.,0.,0.]),([2**-74,999.,2**-74],[0.,0.,0.]),([1.e18,1.e18,1.e18],[0.,0.,0.])]:
  a=list(map(v.f,a));b=list(map(v.f,b))
  for scratch in [False,True]:run('distanceXZ',dict(a=a,b=b,scratch=scratch))
  run('nearest',dict(actor=b,p0=a,p1=a));run('player',dict(actor=b,p0=a))
 for name,authored in uses.items():
  for source in authored:
   for scenario in range(3):run(kinds[name],dict(selected=scenario,bound=scenario if name=='CurrentLocatorIs' else -1,nodeFlags=scenario,player0=scenario!=1,player1=scenario!=2),source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,authoredUses={k:len(x) for k,x in uses.items()},examples=errors[:8],method='Original condition bodies, current-locator initializer, named lookup, squared-distance and sqrt routines execute unchanged. Exact float32 outputs and full input/player regions compared. No behavior replacements.',limits=['Finite coordinates and finite squared-distance sums; readable packet and player/controller records. Runtime ownership and loader binding remain host-supplied.','The XZ distance helper maps its float32 return projection; scratch/null original paths are checked, but portable API uses value vectors rather than aliased raw memory.','Authored condition rows are reference cases, not whole-script execution. Managed replay remains pending.'])
 (B/'reports/native-spatial-conditions-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-spatial-conditions-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,names=q.names,points=q.points,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
