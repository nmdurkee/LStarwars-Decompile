"""Original4effb0 provider enumeration with actual4eff30 getter and recovered release RET callbacks; no adapters."""
from pathlib import Path
import importlib.util,json,struct,itertools,hashlib
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
D=n.DATA;COUNT=0x297e064;FILTER=0x297e080;PROVIDERS=0x29803e0;FILTERCOUNT=0x29838d0;STATUS=0x91eea4;OUTPUT=D+0x40;segments=[(COUNT,4),(FILTER,0x2340),(PROVIDERS,0x2340),(FILTERCOUNT,4),(STATUS,4),(D,0x100)];shadow={};cases=[];checks=0;errors=[]
def snapshot(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rd(p):return sum(shadow[p+i]<<(i*8)for i in range(4))
def wd(p,v):
 for i in range(4):shadow[p+i]=(v>>(i*8))&255
def signed(v):return v if v<0x80000000 else v-0x100000000
def status103(callback,provider):
 if callback==0x4eff30:return rd(STATUS)
 if callback in[0x4ef790,0x4ef7b0,0x512850,0x512860,0x512870]:return callback
 raise ValueError('Prepared actual status callback required')
def enumerate103():
 index=0;chosen=0;out=FILTER
 if signed(rd(COUNT))>0:
  while True:
   provider=PROVIDERS+index*0x234;value=status103(rd(provider+0x230),provider)
   if not value&2:
    chosen+=1
    for word in range(0x8d):wd(out+word*4,rd(provider+word*4))
    out+=0x234
   index+=1
   if index>=signed(rd(COUNT)):break
 wd(OUTPUT,FILTER);wd(FILTERCOUNT,chosen);return chosen
for count,flags,pattern in itertools.product([-2,-1,0,1,2,4,16],[0,1,2,3,0x100,0x102,0xffffffff],['getter','ret','alternate','paired']):
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.pack('<I',COUNT,count&0xffffffff);n.pack('<I',STATUS,flags)
 for row in range(16):
  provider=PROVIDERS+row*0x234;n.write(provider,bytes((row*37+i*11+flags)&255 for i in range(0x234)));getter=pattern=='getter'or pattern=='alternate'and row%2==0 or pattern=='paired'and row%4<2;n.pack('<I',provider+0x230,0x4eff30 if getter else[0x4ef790,0x4ef7b0,0x512850,0x512860,0x512870][row%5])
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};wanted=enumerate103();model=snapshot(True);actual=n.call(0x4effb0,[OUTPUT],count=1000000);final=snapshot()
 for group,a,b in [('return',actual,wanted),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=dict(count=count,flags=flags,pattern=pattern),native=a if group!='images'else'diff',model=b if group!='images'else'diff'))
 cases.append(dict(context=dict(count=count,flags=flags,pattern=pattern),inputs=dict(output=OUTPUT),initial=initial,final=final,returnValue=actual))
leafCases=[]
for flags in[0,1,2,3,0x80000000,0xffffffff]:
 n.pack('<I',STATUS,flags);initial=snapshot();actual=n.call(0x4eff30,[0xdeadbeef],count=10);final=snapshot();checks+=2
 if actual!=flags or initial!=final:errors.append(dict(group='getter',flags=flags,actual=actual))
 leafCases.append(dict(flags=flags,returnValue=actual))
report=dict(binarySha256=n.sha256,nativeCases=len(cases)+len(leafCases),enumerationCases=len(cases),getterCases=len(leafCases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=2,ports=[],closure='Actual4effb0 provider callback/fullrecord copy→actual4eff30 getter and102release RET bodies; no hooks')
(nm.BASE/'reports/script-phase103-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase103-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,leafCases=leafCases),separators=(',',':')));print(json.dumps(report))
