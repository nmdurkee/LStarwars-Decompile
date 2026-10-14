"""Original projectile cleanup CPU ordering with explicit lifecycle services."""
from pathlib import Path
import importlib.util,struct,json,gzip,base64,itertools
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);n=m.NativeX86();D=n.DATA;SIZE=0x10000;P=D+0x2000;SLOT=D+0x8000;SLOT2=D+0x8010;SLOT3=D+0x8020;SCR=D+0xf0000;CB=n.STOP+0x400;CB2=n.STOP+0x500;vectors=[];errors=[];events=[];current={};counts={}
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
ports={0x684400:('emitter',1),0x635750:('link',1),CB:('callback',2),CB2:('callback',2),0x690490:('audio',7)}
def mutation(c,port,put):
 mode=c.get('mode',0)
 if port=='emitter'and mode==4:put(P+0x1dc,SLOT2);put(P+0x1c0,CB2);put(P+0x1f4,19)
 if port=='link'and mode in[1,4]:put(P+0x1dc,SLOT3 if mode==4 else SLOT2)
 if port=='callback':
  if mode==2:put(P+0x1f4,0xffffffff)
  if mode in[3,4]:put(P+0x1f4,0x1234ffff);put(P+0x1fc,0x7fc12345);put(P+0x30,0x41200000)
def event(port,args,read,callback=0):
 result=dict(port=port,args=list(args))
 if port=='callback':result['address']=callback;result['args'][1]=struct.unpack('<i',struct.pack('<I',args[1]))[0]
 if port=='audio':result['outputBefore']=struct.unpack('<I',read(args[0],4))[0];result['position']=read(args[2],12).hex();result['args'][0]=0;result['args'][1]=struct.unpack('<i',struct.pack('<I',args[1]))[0]
 return result
def hook(mu,a,size,user):
 if a==0x64ac90:counts['body']=counts.get('body',0)+1
 if a not in ports:return
 port,cnt=ports[a];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*cnt,sp+4));events.append(event(port,args,n.read,a));mutation(current,port,lambda p,v:n.pack('<I',p,v));
 if port=='audio':n.pack('<I',args[0],0x24681357)
 mu.reg_write(UC_X86_REG_EAX,0x76543210);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def run(c):
 global current
 current=c;n.write(D,bytes([0xa5])*SIZE);n.pack('<I',P+0x144,c.get('flags',1));n.pack('<I',P+0x108,c.get('emitterFlags',0x20000));n.pack('<I',P+0x1d8,7 if c.get('emitter',True)else 0);slot=c.get('slot',SLOT);n.pack('<I',P+0x1dc,slot if c.get('link',True)else 0);n.pack('<I',SLOT,0x89abcdef);n.pack('<I',SLOT2,0x12345678);n.pack('<I',SLOT3,0x13572468);n.pack('<I',P+0x1c0,CB if c.get('callback',True)else 0);n.pack('<I',P+0x1f4,c.get('sound',17)&0xffffffff);n.pack('<I',P+0x1fc,c.get('gain',0x3f800000));n.pack('<3I',P+0x30,0x7f812345,0x80000000,0xffffffff);before=n.read(D,SIZE);expected=bytearray(before)+bytearray(0x100000-SIZE);expected_events=[];events.clear();counts.clear();reason=c.get('reason',0)
 def u(p):return struct.unpack_from('<I',expected,p-D)[0]
 def put(p,v):struct.pack_into('<I',expected,p-D,v&0xffffffff)
 def read(p,length):return bytes(expected[p-D:p-D+length])
 def publish(port,args,address=0):expected_events.append(event(port,args,read,address));mutation(c,port,put)
 flags=u(P+0x144)
 if flags&1:
  put(P+0x144,flags&0xfffffffe)
  if u(P+0x108)&0x20000 and u(P+0x1d8):publish('emitter',[u(P+0x1d8)])
  link=u(P+0x1dc)
  if link:publish('link',[u(link)]);put(u(P+0x1dc),0xffffffff)
  callback=u(P+0x1c0)
  if callback:publish('callback',[P,reason&0xffffffff],callback)
  if reason!=6 and u(P+0x1f4)!=0xffffffff:
   put(SCR,0xffffffff);publish('audio',[SCR,u(P+0x1f4),P+0x30,0,0,1,u(P+0x1fc)]);put(SCR,0x24681357)
 n.call(0x64ac90,[P,reason&0xffffffff]);after=n.read(D,SIZE);bad=[]
 if after!=expected[:SIZE]:bad.append('image')
 if events!=expected_events:bad.append('events')
 if counts!={'body':1}:bad.append('bodyCount')
 if bad:errors.append(dict(input=c,bad=bad,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],events=events,expectedEvents=expected_events))
 vectors.append(dict(input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),events=list(events),nativeEntryCounts=dict(counts)))
for flags,ef,emitter,link,callback,sound,reason in itertools.product([0,1,0x21,0x80000001],[0,0x20000,0xffffffff],[False,True],[False,True],[False,True],[-1,0,65535,0x1234ffff],[-1,0,6,7]):run(dict(flags=flags,emitterFlags=ef,emitter=emitter,link=link,callback=callback,sound=sound,reason=reason))
for mode,reason,sound in itertools.product([1,2,3,4],[-1,6,7],[-1,17]):run(dict(mode=mode,reason=reason,sound=sound))
for gain in[0,0x80000000,0x3f800000,0x7f800000,0x7fc12345,0xffffffff]:run(dict(gain=gain))
for slot,callback in itertools.product([P+0x144,P+0x1d8,P+0x1dc,P+0x1f4,P+0x1fc],[False,True]):run(dict(slot=slot,callback=callback))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),mismatches=len(errors),errors=errors[:5],ports=['684400','635750','indirect callback','690490']);(m.BASE/'reports/movement-phase38-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:3])))
if errors:raise SystemExit('Cleanup mismatch; no paired fixture')
with gzip.open(m.BASE/'reports/movement-phase38-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);(m.BASE/'reports/movement-phase38-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=[dict(address='0x64ac90',size=0xaf,instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x64ac90,0xaf),0x64ac90)])]),indent=2)+'\n')
