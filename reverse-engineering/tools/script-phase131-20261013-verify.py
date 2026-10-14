"""Whole original prepared/public current-position functions and final Win32 seek only."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_EIP
D=n.DATA;TABLE=0x2983740;COMP=0x297dc60;STREAM=0x8ceb50;HANDLES=0x8007a0;API=n.STOP+0x100;segments=[(TABLE,400),(COMP,960),(STREAM,4096),(HANDLES,256)];shadow={};cases=[];errors=[];checks=0;events=[];ordinal=0;config={};n.pack('<I',0x7510ec,API)
def snap(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rd(p):return sum(shadow[p+i]<<(8*i)for i in range(4))
def signed(v):return v if v<0x80000000 else v-0x100000000

def host(model,args):
 global ordinal
 events.append(dict(name='SetFilePointerEx',args=args));lo,hi,ok=config['plan'][min(ordinal,len(config['plan'])-1)];ordinal+=1;return lo,hi,ok

def hook131(mu,address,size,data):
 if address!=API:return
 sp=mu.reg_read(UC_X86_REG_ESP);raw,lo,hi,out,origin=n.unpack('<5I',sp+4);a,b,ok=host(False,[raw,lo,hi,origin]);n.pack('<2I',out,a,b);mu.reg_write(UC_X86_REG_EAX,ok);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook131)

def prepared131(handle):
 if handle>=0x800:
  p=COMP+(handle-0x800)*48;return ((rd(p+16)|(rd(p+20)<<32))-(rd(p+8)|(rd(p+12)<<32)))&0xffffffffffffffff
 p=TABLE+(handle-0x400)*20;return signed((rd(p+8)-rd(p))&0xffffffff)&0xffffffffffffffff

def public131(handle):
 if signed(handle)>=0x1000:return 0
 if signed(handle)>=0x400:return prepared131(handle)
 p=STREAM+(handle-1)*64
 if rd(p+44):return rd(p+8)|(rd(p+12)<<32)
 while True:
  lo,hi,ok=host(True,[rd(HANDLES+(handle-1)*4),0,0,1]);value=lo|(hi<<32)if ok else 0xffffffffffffffff
  if signed(value>>32)>=0:return value

def run131(c):
 global shadow,checks,events,ordinal,config
 config=c
 for p,z in segments:n.write(p,b'\xa5'*z)
 handle=c['handle'];method=c['method'];kind=c['kind']
 if kind=='Memory':p=TABLE+(handle-0x400)*20;n.pack('<I',p,c['baseLow']);n.pack('<I',p+8,c['currentLow'])
 if kind=='Compressed':p=COMP+(handle-0x800)*48;n.pack('<2I',p+8,c['baseLow'],c['baseHigh']);n.pack('<2I',p+16,c['currentLow'],c['currentHigh'])
 if kind=='Stream':p=STREAM+(handle-1)*64;n.pack('<2I',p+8,c['currentLow'],c['currentHigh']);n.pack('<I',p+44,c['buffered']);n.pack('<I',HANDLES+(handle-1)*4,c['raw'])
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;wanted=prepared131(handle)if method=='Prepared'else public131(handle);model=snap(True);me=events.copy();mo=ordinal;events=[];ordinal=0;actual=n.call(0x4f6c20 if method=='Prepared'else 0x4f6d10,[handle],count=4000000);actual|=n.mu.reg_read(UC_X86_REG_EDX)<<32;final=snap();ne=events.copy()
 for group,a,b in[('return',actual,wanted),('images',final,model),('events',ne,me),('attempts',ordinal,mo)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(handle=handle),initial=initial,final=final,returnValue=actual,nativeEvents=ne,attempts=ordinal))
for method,index,base,current in itertools.product(['Prepared','Public'],[0,3,19],[0,17,0x80000000,0xffffffff],[0,1,0x80000000,0xffffffff]):run131(dict(method=method,kind='Memory',handle=0x400+index,baseLow=base,currentLow=current))
for method,index,base,current,baseHigh,currentHigh in itertools.product(['Prepared','Public'],[0,3,19],[0,17,0xffffffff],[0,0x80000000,0xffffffff],[0,0xffffffff],[0,0xffffffff]):run131(dict(method=method,kind='Compressed',handle=0x800+index,baseLow=base,currentLow=current,baseHigh=baseHigh,currentHigh=currentHigh))
for handle,lo,hi in itertools.product([1,2,64],[0,0x80000000,0xffffffff],[0,0xffffffff]):run131(dict(method='Public',kind='Stream',handle=handle,buffered=7,currentLow=lo,currentHigh=hi,raw=0x12345678))
plans=[[[0,0,1]],[[0x80000000,0,1]],[[0xffffffff,0x7fffffff,1]],[[17,0,0],[19,0,1]],[[0,0xffffffff,1],[0xffffffff,0,1]],[[0,0x80000000,1],[17,0,0],[7,0,1]]]
for handle,plan in itertools.product([1,2,64],plans):run131(dict(method='Public',kind='Stream',handle=handle,buffered=0,currentLow=0xdeadbeef,currentHigh=0x12345678,raw=0x12345678+handle,plan=plan))
for h in[0x1000,0x1007,0x10000,0x7fffffff]:run131(dict(method='Public',kind='Crt',handle=h))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=2,ports=['SetFilePointerEx'],closure='Whole4f6c20 memory/compressed relativeposition and4f6d10 publicposition→actualpreparedchild/CRTseek6dee90/Win32seek4ff430; signedhigh retry, finalOSonly')
(nm.BASE/'reports/script-phase131-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase131-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
