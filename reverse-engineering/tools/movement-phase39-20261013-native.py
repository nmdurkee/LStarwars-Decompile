"""Original cleanup64ac90 composed with actual effect callback4d9710."""
from pathlib import Path
import json,gzip,base64,itertools,struct
p=Path(__file__).with_name('movement-phase38-20261013-native.py');q={'__file__':str(p)};exec(compile(p.read_text().split('for flags,ef,emitter,link,callback,sound,reason in itertools.product')[0],str(p),'exec'),q)
n=q['n'];m=q['m'];D=q['D'];SIZE=q['SIZE'];P=q['P'];SLOT=q['SLOT'];SCR=q['SCR'];W=D+0x9000;W2=D+0x9200;events=q['events'];counts=q['counts'];vectors=[];errors=[];current={}
def effect_mutation(c,port,put,st):
 mode=c.get('effectMode',0)
 if port=='particle':
  if mode in[1,4]:st['sound']=0x1234ffff
  if mode in[2,4]:put(P+0x1f4,0);put(P+0x1fc,0x80000000);put(P+0x30,0x3f400000);st['world']=W2
 if port=='sound'and mode in[3,4]:put(P+0x1f4,0x1234ffff);put(P+0x1fc,0x7fc12345);put(P+0x34,0x41200000);st['particle']=-1
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
def effect_hook(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x4d9710:
  counts['callbackBody']=counts.get('callbackBody',0)+1;events.append(q['event']('callback',list(n.unpack('<2I',sp+4)),n.read,a));return
 if a not in[0x62c560,0x64b370]:return
 port='particle'if a==0x62c560 else'sound';args=list(n.unpack('<3I',sp+4));which=1 if port=='particle'else 0;args[which]=struct.unpack('<i',struct.pack('<I',args[which]))[0];pos=args[2 if port=='particle'else 1];events.append(dict(port=port,args=args,position=n.read(pos,12).hex()));st=dict(particle=n.unpack('<h',0x882406)[0],sound=n.unpack('<i',0x882408)[0],world=n.unpack('<I',0x802c54)[0]);effect_mutation(current,port,lambda p,v:n.pack('<I',p,v),st);n.pack('<h',0x882406,st['particle']);n.pack('<i',0x882408,st['sound']);n.pack('<I',0x802c54,st['world']);mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,effect_hook)
def run(c):
 global current
 current=c;q['current']=dict(c,mode=c.get('linkMode',0));n.write(D,bytes([0xa5])*SIZE);n.pack('<I',P+0x144,c.get('flags',1));n.pack('<I',P+0x108,0x20000);n.pack('<I',P+0x1d8,7);n.pack('<I',P+0x1dc,c.get('slot',SLOT));n.pack('<I',SLOT,0x89abcdef);n.pack('<I',q['SLOT2'],0x12345678);n.pack('<I',P+0x1c0,0x4d9710 if c.get('callback',True)else 0);n.pack('<I',P+0x1f4,c.get('sound',17)&0xffffffff);n.pack('<I',P+0x1fc,0x3f800000);n.pack('<3I',P+0x30,0x7f812345,0x80000000,0xffffffff);n.pack('<I',W+0x134,0x11223344);n.pack('<I',W2+0x134,0xaabbccdd);before=n.read(D,SIZE);st=dict(particle=c.get('particle',0),sound=c.get('effectSound',0),world=W);n.pack('<h',0x882406,st['particle']);n.pack('<i',0x882408,st['sound']);n.pack('<I',0x802c54,W);expected=bytearray(before)+bytearray(0x100000-SIZE);expected_events=[];expected_counts={'body':1};events.clear();counts.clear();reason=c.get('reason',0)
 def u(p):return struct.unpack_from('<I',expected,p-D)[0]
 def put(p,v):struct.pack_into('<I',expected,p-D,v&0xffffffff)
 def read(p,length):return bytes(expected[p-D:p-D+length])
 def publish(port,args,address=0):expected_events.append(q['event'](port,args,read,address));q['mutation'](dict(c,mode=c.get('linkMode',0)),port,put)
 def effect(port,args):
  position=args[2 if port=='particle'else 1];expected_events.append(dict(port=port,args=args,position=read(position,12).hex()));effect_mutation(c,port,put,st)
 flags=u(P+0x144)
 if flags&1:
  put(P+0x144,flags&0xfffffffe);publish('emitter',[u(P+0x1d8)]);link=u(P+0x1dc)
  if link:publish('link',[u(link)]);put(u(P+0x1dc),0xffffffff)
  if u(P+0x1c0):
   expected_counts['callbackBody']=1;expected_events.append(q['event']('callback',[P,reason&0xffffffff],read,0x4d9710));particle=st['particle']
   if particle!=-1:effect('particle',[u(st['world']+0x134),particle,P+0x30])
   sound=st['sound']
   if sound!=-1:effect('sound',[sound,P+0x30,1])
  if reason!=6 and u(P+0x1f4)!=0xffffffff:put(SCR,0xffffffff);publish('audio',[SCR,u(P+0x1f4),P+0x30,0,0,1,u(P+0x1fc)]);put(SCR,0x24681357)
 n.call(0x64ac90,[P,reason&0xffffffff]);after=n.read(D,SIZE);actual_state=dict(particle=n.unpack('<h',0x882406)[0],sound=n.unpack('<i',0x882408)[0],world=n.unpack('<I',0x802c54)[0]);bad=[]
 if after!=expected[:SIZE]:bad.append('image')
 if events!=expected_events:bad.append('events')
 if actual_state!=st:bad.append('globals')
 if counts!=expected_counts:bad.append('bodyCounts')
 if bad:errors.append(dict(input=c,bad=bad,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],events=events,expectedEvents=expected_events))
 vectors.append(dict(input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),events=list(events),afterState=actual_state,nativeEntryCounts=dict(counts)))
for flags,particle,sound,reason,object_sound,mode in itertools.product([0,1],[-1,0,32767],[-1,0,65535,0x1234ffff],[0,6,7],[-1,17],[0,1,2,3,4]):run(dict(flags=flags,particle=particle,effectSound=sound,reason=reason,sound=object_sound,effectMode=mode))
for slot,link_mode,callback,mode in itertools.product([SLOT,P+0x144,P+0x1f4,P+0x1fc],[0,1],[False,True],[0,4]):run(dict(slot=slot,linkMode=link_mode,callback=callback,effectMode=mode))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=4*len(vectors),mismatches=len(errors),errors=errors[:5],actualBodies=['64ac90','4d9710'],ports=['684400','635750','62c560','64b370','690490']);(m.BASE/'reports/movement-phase39-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:2])))
if errors:raise SystemExit('Cleanup effect composition mismatch; no paired fixture')
with gzip.open(m.BASE/'reports/movement-phase39-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
