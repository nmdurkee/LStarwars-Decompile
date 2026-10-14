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

CONTEXT=n.STACK+0xdfec;ARGS=n.STACK+0xe004;LOCALEINFO=D+0x1000;MBCS=D+0x1200;CTABLE=D+0x1400

def construct158(instance,locale):
 wr(instance+12,0,1)
 if locale:wr(instance,rd(locale));wr(instance+4,rd(locale+4));return
 thread=port(0x6f040c,True);wr(instance+8,thread);wr(instance,rd(thread+0x6c));wr(instance+4,rd(thread+0x68))
 if rd(instance)!=rd(0x82a678)and not rd(thread+0x70)&rd(0x82a594):wr(instance,port(0x6fae25,True))
 if rd(instance+4)!=rd(0x82a498)and not rd(rd(instance+8)+0x70)&rd(0x82a594):wr(instance+4,port(0x6fa67a,True))
 thread=rd(instance+8)
 if not shadow[thread+0x70]&2:wr(thread+0x70,rd(thread+0x70)|2);wr(instance+12,1,1)

def execute158(c):
 global config,shadow,segments,events,checks
 config=dict(c);config['newLocale']=LOCALEINFO;config['newMultibyte']=MBCS;n.write(D,bytes(0x2000));n.write(CONTEXT,bytes([0xcd])*16);n.pack('<2I',LOCALE,LOCALEINFO,MBCS);n.pack('<I',LOCALEINFO+0xc8,CTABLE);n.pack('<I',MBCS+0xc8,CTABLE)
 for i in range(256):n.pack('<H',CTABLE+i*2,c.get('tableWord',0x8000 if i>=128 else 0x1234))
 n.pack('<3I',THREAD+0x68,MBCS,LOCALEINFO,c.get('threadFlags',0));n.pack('<I',0x82a678,0 if c.get('refresh')else LOCALEINFO);n.pack('<I',0x82a498,0 if c.get('refresh')else MBCS);n.pack('<I',0x82a594,c.get('mask',1));locale=c.get('locale',LOCALE);character=c.get('character',255)&0xffffffff;n.pack('<2I',ARGS,character,locale)
 if locale in[CONTEXT,CONTEXT+4]:n.pack('<3I',CONTEXT,LOCALEINFO,MBCS,LOCALEINFO)
 segments=[(D,0x2000),(CONTEXT,16),(ARGS,8),(0x82a678,4),(0x82a498,4),(0x82a594,4)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];mf=False;want=0
 try:
  construct158(CONTEXT,rd(ARGS+4));table=rd(rd(CONTEXT)+0xc8);p=table+shadow[ARGS]*2;want=(shadow[p]|shadow[p+1]<<8)&0x8000
  if shadow[CONTEXT+12]:thread=rd(CONTEXT+8);wr(thread+0x70,rd(thread+0x70)&0xfffffffd)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(0x6fc0ee,[character,locale])
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(characterSlot=ARGS,localeSlot=ARGS+4,context=CONTEXT),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for character,locale in itertools.product(range(256),[0,LOCALE]):execute158(dict(character=character,locale=locale))
for character,locale,flags,word in itertools.product([-1,256,0x80000080],[0,LOCALE],[0,2,0x80000000],[0,0xffff,0x8001]):execute158(dict(character=character,locale=locale,threadFlags=flags,tableWord=word))
for c in[dict(locale=0,refresh=True),dict(locale=CONTEXT),dict(locale=CONTEXT+4),dict(locale=0,patches={'0x6f040c':[[ARGS,4,0],[THREAD+0x70,4,2]]}),dict(locale=0,refresh=True,patches={'0x6fae25':[[ARGS,4,128]]}),dict(locale=0,thread=0),dict(locale=0xdead0000)]:execute158(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=['6F040C thread getter','6FAE25 locale refresh','6FA67A multibyte refresh'],closure='actual6FC0EE→actual6EB53D constructor, wordclassification andthreadbitcleanup')
(nm.BASE/'reports/script-phase158-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase158-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
