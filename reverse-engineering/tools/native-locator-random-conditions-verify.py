import importlib.util,json,struct,random,math
from pathlib import Path
s=importlib.util.spec_from_file_location('distance',Path(__file__).with_name('native-distance-rounding-verify.py'));d=importlib.util.module_from_spec(s);s.loader.exec_module(d);v=d.v;n=v.n;B=v.B;D=n.DATA
SYS=D;CRE=D+0x1000;REF=D+0x2000;PACK=D+0x3000;LOC=D+0x4000;NAME=D+0x5000;OUT=D+0x6000
rows=[];errors=[];groups={};memory=0
names=['Alpha','Beta','alpha','Origin'];points=[[1.,2.,3.],[-2.,4.,1.],[90.,80.,70.],[0.,0.,0.]]
def capture(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',OUT)[0]
def distance(a,b):
 diff=[d.store(v.F(x)-v.F(y)) for x,y in zip(a,b)];square=d.store(v.add(v.add(v.mul(diff[0],diff[0]),v.mul(diff[1],diff[1])),v.mul(diff[2],diff[2])));return v.bits(v.f(math.sqrt(square)))
def setup(o):
 n.write(D,bytes(0x7000));n.pack('<II',SYS+0x24,len(names),LOC)
 for i,(name,pos) in enumerate(zip(names,points)):n.write(LOC+i*0x3c,name.encode()+b'\0');n.pack('<3f',LOC+i*0x3c+0x10,*pos)
 n.pack('<I',CRE+0xd0,REF if o.get('reference',True) else 0);n.pack('<I',REF,0);n.pack('<3f',CRE+0x14c,*o.get('position',[0.,0.,0.]));n.pack('<3f',REF+0x5c,999.,998.,997.);n.pack('<I',PACK+0xa4,0 if o.get('selected',0)<0 else LOC+o.get('selected',0)*0x3c)
def run(kind,o,source=None):
 global memory
 setup(o);expected=n.read(D,0x6000)
 if kind=='bind':
  name=o['name']
  if name is not None:n.write(NAME,name.encode()+b'\0')
  expected=n.read(D,0x6000);ptr=n.call(0x52d070,[SYS if o.get('system',True) else 0,NAME if name is not None else 0]);got=-1 if ptr==0 else (ptr-LOC)//0x3c;want=next((i for i,x in enumerate(names) if x.lower()==name.split('\0')[0].lower()),-1) if name is not None and o.get('system',True) else -1
 elif kind=='range':
  bound=o.get('bound',-1);selected=o.get('selected',0);target=bound if bound>=0 else selected
  got=capture(0x514a00,[SYS,PACK,CRE if o.get('creature',True) else 0,0,0 if bound<0 else LOC+bound*0x3c]);want=distance(o.get('position',[0.,0.,0.]),points[target]) if o.get('creature',True) and o.get('reference',True) and target>=0 else 0x7f7fffff
 elif kind=='distance':
  n.pack('<3f',NAME,*o['a']);n.pack('<3f',NAME+0x10,*o['b']);expected=bytearray(n.read(D,0x6000));diff=[d.store(v.F(x)-v.F(y)) for x,y in zip(o['a'],o['b'])];struct.pack_into('<3f',expected,NAME+0x20-D,*diff)
  got=capture(0x5becc0,[NAME,NAME+0x10,NAME+0x20]);want=distance(o['a'],o['b'])
 else:
  n.pack('<I',0x95e5d4,o['seed']);got=dict(value=capture(0x5149a0,[]),state=n.unpack('<I',0x95e5d4)[0]);seed=(o['seed']*0x19660d+0x3c6ef35f)&0xffffffff;want=dict(value=v.bits((seed&0x7fffff)/8388608.),state=seed)
 memory+=1;bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x6000)!=expected:bad.append('collateral write')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 rows.append(dict(kind=kind,options=o,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses={x['name']:x['uses'] for x in ledger['rows'] if x['name'] in ['LocatorRange','Random']}
 for name in [None,'','Alpha','ALPHA','beta','missing','Origin','alpha\0later']:
  for system in [False,True]:run('bind',dict(name=name,system=system))
 for bound in [-1,0,1,3]:
  for selected in [-1,0,1,3]:
   for creature in [False,True]:
    for reference in [False,True]:
     for position in [[0.,0.,0.],[1.,2.,3.],[-2.,4.,1.],[1.,2**-12,2**-27]]:run('range',dict(bound=bound,selected=selected,creature=creature,reference=reference,position=position))
 rng=random.Random(514900)
 for i in range(768):run('distance',dict(a=[v.f(rng.uniform(-10000,10000)) for _ in range(3)],b=[v.f(rng.uniform(-10000,10000)) for _ in range(3)]))
 for seed in [0,1,0x7fffffff,0x80000000,0xffffffff]+[i*1048573 for i in range(4096)]:run('random',dict(seed=seed&0xffffffff))
 for use in uses['LocatorRange']:run('range',dict(bound=-1,selected=0,position=[v.f(rng.uniform(-3,3)) for _ in range(3)]),use)
 for use in uses['Random']:run('random',dict(seed=rng.randrange(2**32)),use)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,authoredUses={k:len(x) for k,x in uses.items()},examples=errors[:8],method='Original initializer, locator lookup, range condition, distance/sqrt and Random tail thunk execute unchanged. Exact float32 return and shared RNG state, input-region write checks; no behavior substitutions.',limits=['Finite coordinates and finite squared-distance result; original nonnull scratch length helper. Bound locator identity and controller position supplied.','Condition comparison/connective scheduling remains the existing separate scheduler contract. Authored rows retain their source but are not whole-script execution.','Prepared managed replay pending.'])
 (B/'reports/native-locator-random-conditions-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-locator-random-conditions-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,names=names,points=points,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
