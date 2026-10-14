"""Original5B9E90 raw uint32 states, global/local zero distinction and unaligned pointer."""
import importlib.util,json,struct,random,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;LOCAL=D+0x100;GLOBAL=0x8066c0;cases=[];errors=[];checks=0
for seed,state in itertools.product([0,1,0x7fffffff,0x80000000,0xffffffff,0x075bd924,0x075bd925]+[random.Random(i).getrandbits(32)for i in range(256)],[0,LOCAL,LOCAL+1,GLOBAL,0xdead0000]):
 n.write(LOCAL,bytes([0xcd])*16);n.write(GLOBAL,bytes([0xef])*16);p=state if state else GLOBAL
 if p!=0xdead0000:n.pack('<I',p,seed)
 initial=[dict(address=p,bytes=n.read(p,16).hex())for p in[LOCAL,GLOBAL]];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 def rd(p):return sum(shadow[p+i]<<(i*8)for i in range(4))
 def wd(p,v):
  for i in range(4):shadow[p+i]=(v>>(i*8))&255
 mf=False;want=0
 try:
  if state and not rd(p):wd(p,1)
  x=rd(p)^0x075bd924;signed=x if x<0x80000000 else x-0x100000000;q=abs(signed)//0x1f31d*(-1 if signed<0 else 1);value=(x*0x41a7-q*0x7fffffff)&0xffffffff;wd(p,value)
  if value&0x80000000:wd(p,(value+0x7fffffff)&0xffffffff)
  want=rd(p)^0x075bd924;wd(p,want)
 except KeyError:mf=True
 model=[dict(address=r['address'],bytes=bytes(shadow[r['address']+i]for i in range(16)).hex())for r in initial];nf=False;got=0
 try:got=n.call(0x5b9e90,[state])
 except RuntimeError:nf=True
 native=[dict(address=r['address'],bytes=n.read(r['address'],16).hex())for r in initial]
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,seed=seed,state=state,native=a,model=b))
 cases.append(dict(inputs=dict(state=state),seed=seed,initial=initial,fault=nf,returnValue=0 if nf else got,final=native))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,refinements=['5B9E90'],ports=[])
(nm.BASE/'reports/script-phase150-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase150-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
