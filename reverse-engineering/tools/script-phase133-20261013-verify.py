"""Whole original Win32 write wrapper; final WriteFile only, Boolean/count semantics exact."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
D=n.DATA;SOURCE=D+16;HANDLES=0x8007a0;API=n.STOP+0x100;segments=[(HANDLES,256),(D,256)];shadow={};cases=[];errors=[];checks=0;events=[];config={};n.pack('<I',0x7510e8,API)
def snap(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rd(p):return sum(shadow[p+i]<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):shadow[p+i]=(v>>(8*i))&255

def port133(args,model):
 events.append(dict(name='WriteFile',args=args))
 for p,v in config.get('patches',[]):
  if model:wd(p,v)
  else:n.pack('<I',p,v)
 return config['boolean'],config['written']or 0

def hook133(mu,address,size,data):
 if address!=API:return
 sp=mu.reg_read(UC_X86_REG_ESP);raw,source,count,out,overlapped=n.unpack('<5I',sp+4);boolean,written=port133([raw,source,count,overlapped],False)
 if config['written']is not None:n.pack('<I',out,written)
 mu.reg_write(UC_X86_REG_EAX,boolean);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook133)

def run133(c):
 global config,shadow,events,checks
 config=c
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 n.pack('<I',HANDLES+c['index']*4,c['raw']);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];boolean,written=port133([rd(HANDLES+c['index']*4),SOURCE,c['count'],0],True);wanted=written if boolean else 0;model=snap(True);me=events.copy();events=[];actual=n.call(0x4ff3f0,[c['index'],SOURCE,c['count']],regs={UC_X86_REG_ECX:0xdeadbeef});final=snap();ne=events.copy()
 for group,a,b in[('return',actual,wanted),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method='Write',context=c,inputs=dict(index=c['index'],source=SOURCE,count=c['count']),initial=initial,final=final,returnValue=actual,nativeEvents=ne,observedNativeEcx=n.mu.reg_read(UC_X86_REG_ECX)))
for index,raw,boolean,written,count in itertools.product([0,1,63],[0,0xffffffff,0x12345678],[0,1,0xffffffff,0x80000000],[None,0,1,17,0xffffffff],[0,1,17,128,0xffffffff]):run133(dict(index=index,raw=raw,boolean=boolean,written=written,count=count))
for boolean,written in itertools.product([0,1],[None,17]):run133(dict(index=0,raw=0x12345678,boolean=boolean,written=written,count=128,patches=[[HANDLES,0xabcdef01],[SOURCE,0x11223344]]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=['WriteFile'],closure='Whole4ff3f0 Win32write initializescount0, callsfinalWriteFile andmaskswrittenDWORD withnonzeroBoolean; rawhandle/source/countprefetchedbeforeliveOSpatches')
(nm.BASE/'reports/script-phase133-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase133-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
