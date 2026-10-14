"""Original locale-update thiscall constructor, explicit thread/locale/multibyte children."""
import importlib.util,json,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
D=n.DATA;OBJ=D+0x100;LOCALE=D+0x200;THREAD=D+0x300;OTHER=D+0x500;shadow={};segments=[];events=[];config={};cases=[];errors=[];checks=0
rd=lambda p:sum(shadow[p+i]<<(i*8)for i in range(4))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def port(address,model):
 events.append(dict(callback=address,args=[]));write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(8*z))-1)).to_bytes(z,'little'))
 for p,z,v in config.get('patches',{}).get(hex(address),[]):write(p,v,z)
 return config.get({0x6f040c:'thread',0x6fae25:'newLocale',0x6fa67a:'newMultibyte'}[address],{0x6f040c:THREAD,0x6fae25:0xabcdef01,0x6fa67a:0x12345678}[address])
def hook(mu,address,size,data):
 if address not in[0x6f040c,0x6fae25,0x6fa67a]:return
 sp=mu.reg_read(UC_X86_REG_ESP);value=port(address,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def execute(c):
 global config,shadow,segments,events,checks
 config=c;n.write(D,bytes([0xcd])*0x800);n.pack('<2I',LOCALE,0x11112222,0x33334444)
 for p in[THREAD,OTHER]:n.pack('<3I',p+0x68,c.get('multibyte',0x33334444),c.get('localeValue',0x11112222),c.get('threadFlags',0))
 n.pack('<I',0x82a678,c.get('globalLocale',0x11112222));n.pack('<I',0x82a498,c.get('globalMultibyte',0x33334444));n.pack('<I',0x82a594,c.get('mask',1));instance=c.get('instance',OBJ);locale=c.get('locale',0);segments=[(D,0x800),(0x82a678,4),(0x82a498,4),(0x82a594,4)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];mf=False;want=instance
 try:
  wr(instance+12,0,1)
  if locale:wr(instance,rd(locale));wr(instance+4,rd(locale+4))
  else:
   thread=port(0x6f040c,True);wr(instance+8,thread);wr(instance,rd(thread+0x6c));wr(instance+4,rd(thread+0x68))
   if rd(instance)!=rd(0x82a678)and not rd(thread+0x70)&rd(0x82a594):wr(instance,port(0x6fae25,True))
   if rd(instance+4)!=rd(0x82a498)and not rd(rd(instance+8)+0x70)&rd(0x82a594):wr(instance+4,port(0x6fa67a,True))
   thread=rd(instance+8)
   if not shadow[thread+0x70]&2:wr(thread+0x70,rd(thread+0x70)|2);wr(instance+12,1,1)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(0x6eb53d,[locale],regs={UC_X86_REG_ECX:instance})
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(instance=instance,locale=locale),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for locale,globalLocale,globalMB,flags,mask in itertools.product([0,LOCALE],[0x11112222,0],[0x33334444,0],[0,1,2,3,0x80000000],[0,1,2,0x80000000]):execute(dict(locale=locale,globalLocale=globalLocale,globalMultibyte=globalMB,threadFlags=flags,mask=mask))
for c in[dict(locale=OBJ),dict(locale=OBJ+4),dict(instance=LOCALE,locale=LOCALE),dict(instance=LOCALE+4,locale=LOCALE),dict(instance=THREAD+0x60),dict(instance=THREAD+0x68),dict(instance=0),dict(locale=0xdead0000),dict(thread=0),dict(globalLocale=0,patches={'0x6fae25':[[OBJ+8,4,OTHER],[OTHER+0x70,4,0x80000002],[0x82a594,4,0x80000000]]}),dict(globalLocale=0,globalMultibyte=0,patches={'0x6fa67a':[[OBJ+8,4,OTHER],[OBJ+12,1,7]]})]:execute(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=['6F040C thread getter','6FAE25 locale refresh','6FA67A multibyte refresh'])
(nm.BASE/'reports/script-phase154-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase154-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
