"""Original projectile effect callback; effect/sound publication are explicit lifecycle ports."""
from pathlib import Path
import importlib.util,struct,json,gzip,base64,itertools
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);n=m.NativeX86();D=n.DATA;SIZE=0x10000;P=D+0x2000;W=D+0x4000;W2=D+0x5000;vectors=[];errors=[];events=[];current={};calls={}
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
def mutate(c,port,put,state):
 mode=c.get('mode',0)
 if port=='particle':
  if mode in[1,4]:state['sound']=c.get('nextSound',-1)
  if mode in[2,4]:state['world']=W2;state['particle']=-1;put(P+0x30,0x41200000)
 if port=='sound'and mode in[3,4]:state['sound']=0x1234ffff;put(P+0x34,0x80000000)
def hook(mu,a,size,user):
 if a==0x4d9710:calls['body']=calls.get('body',0)+1
 if a not in[0x62c560,0x64b370]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<3I',sp+4));port='particle'if a==0x62c560 else'sound';args[1 if port=='particle'else 0]=struct.unpack('<i',struct.pack('<I',args[1 if port=='particle'else 0]))[0];pos=args[2 if port=='particle'else 1];events.append(dict(port=port,args=args,position=n.read(pos,12).hex()));state=dict(particle=n.unpack('<h',0x882406)[0],sound=n.unpack('<i',0x882408)[0],world=n.unpack('<I',0x802c54)[0]);mutate(current,port,lambda p,v:n.pack('<I',p,v),state);n.pack('<h',0x882406,state['particle']);n.pack('<i',0x882408,state['sound']);n.pack('<I',0x802c54,state['world']);mu.reg_write(UC_X86_REG_EAX,0x76543210);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def run(c):
 global current
 current=c;n.write(D,bytes([0xa5])*SIZE);n.pack('<I',W+0x134,c.get('system',0x11223344));n.pack('<I',W2+0x134,0xaabbccdd);n.pack('<3I',P+0x30,*c.get('positionWords',[0x3f800000,0x7f812345,0x80000000]));state=dict(particle=c.get('particle',-1),sound=c.get('sound',-1),world=0 if c.get('nullWorld')else W);n.pack('<h',0x882406,state['particle']);n.pack('<i',0x882408,state['sound']);n.pack('<I',0x802c54,state['world']);before=n.read(D,SIZE);expected=bytearray(before);expected_events=[];events.clear();calls.clear()
 def put(p,v):struct.pack_into('<I',expected,p-D,v&0xffffffff)
 def publish(port,args):
  pos=args[2 if port=='particle'else 1];expected_events.append(dict(port=port,args=args,position=bytes(expected[pos-D:pos-D+12]).hex()));mutate(c,port,put,state)
 particle=state['particle']
 if particle!=-1:publish('particle',[struct.unpack_from('<I',expected,state['world']-D+0x134)[0],particle,P+0x30])
 sound=state['sound']
 if sound!=-1:publish('sound',[sound,P+0x30,1])
 n.call(0x4d9710,[P]);after=n.read(D,SIZE);actual_state=dict(particle=n.unpack('<h',0x882406)[0],sound=n.unpack('<i',0x882408)[0],world=n.unpack('<I',0x802c54)[0]);bad=[]
 if after!=expected:bad.append('image')
 if events!=expected_events:bad.append('events')
 if actual_state!=state:bad.append('globals')
 if bad:errors.append(dict(input=c,bad=bad,events=events,expectedEvents=expected_events))
 vectors.append(dict(input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),events=list(events),afterState=actual_state,nativeEntryCounts=dict(calls)))
for particle,sound in itertools.product([-32768,-257,-256,-128,-2,-1,0,1,127,128,255,256,32767],[-2147483648,-65537,-257,-2,-1,0,1,255,65535,65536,0x1234ffff,2147483647]):run(dict(particle=particle,sound=sound))
for j in range(256):run(dict(particle=j-256,sound=0x12340000+j))
for mode,next_sound,particle in itertools.product([0,1,2,3,4],[-1,0,65535,0x1234ffff],[-1,0,32767]):run(dict(mode=mode,nextSound=next_sound,particle=particle,sound=17))
for sound in[-1,0,65535,0x1234ffff]:run(dict(particle=-1,sound=sound,nullWorld=True))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),mismatches=len(errors),errors=errors[:5],ports=['62c560','64b370']);(m.BASE/'reports/movement-phase35-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:3])))
if errors:raise SystemExit('Callback mismatch; no sealed fixtures')
with gzip.open(m.BASE/'reports/movement-phase35-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);(m.BASE/'reports/movement-phase35-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=[dict(address='0x4d9710',size=0x48,instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x4d9710,0x48),0x4d9710)])]),indent=2)+'\n')
