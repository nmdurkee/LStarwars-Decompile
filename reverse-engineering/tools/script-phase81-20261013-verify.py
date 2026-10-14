"""Actual bit collector and decoder wrapper; only block-to-ring decoder normalized."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EDI
CURSOR=0x297dc50;DEST=0x297e020;ACC=DEST+4;PACKEDLEFT=0x2982724;PLAINLEFT=0x29838d4;BYTE=0x8cf394;AVAIL=0x90f79c;BLOCKLEFT=0x915fac;MATCHLEFT=0x88ab3c;GATE=0x800544;RING=0x91ce80
common=[(CURSOR,4),(DEST,8),(PACKEDLEFT,4),(PLAINLEFT,4),(BYTE,4),(AVAIL,4),(BLOCKLEFT,4),(MATCHLEFT,4),(GATE,4),(DATA,64)];events=[];ordinal=0;config={}
def bits81(count):
 available=rd(AVAIL);value=rd(BYTE);wd(ACC,(rd(ACC)<<(count&31))&0xffffffff)
 if count>available:
  remaining=rd(PACKEDLEFT);cursor=rd(CURSOR)
  while True:
   count=(count-available)&0xffffffff;value=(value<<(count&31))&0xffffffff;wd(ACC,rd(ACC)|value)
   if remaining:remaining-=1;wd(PACKEDLEFT,remaining);value=rb(cursor);cursor=(cursor+1)&0xffffffff;wd(CURSOR,cursor)
   else:value=0
   available=8
   if count<=8:break
  wd(BYTE,value)
 available=(available-count)&0xffffffff;value>>=available&31;wd(AVAIL,available);wd(ACC,rd(ACC)|value);return value

def block81(ring,count,model):
 global ordinal
 ordinal+=1;events.append(dict(ring=ring,count=count));payload=bytes((ordinal*31+i*17)&255 for i in range(count))
 if model:
  for i,b in enumerate(payload):wb(ring+i,b)
 else:n.write(ring,payload)
 if ordinal==1 and config.get('changeRemaining'):
  value=count+23
  if model:wd(PLAINLEFT,value)
  else:n.pack('<I',PLAINLEFT,value)

def wrapper81(source,destination,packed,plain):
 if not rd(GATE):return 0
 wd(CURSOR,source);wd(DEST,destination);wd(PLAINLEFT,plain);wd(PACKEDLEFT,packed);wd(ACC,0);wd(BYTE,0);wd(AVAIL,0);bits81(32);total=0;wd(BLOCKLEFT,0);wd(MATCHLEFT,0)
 while rd(PLAINLEFT):
  count=min(rd(PLAINLEFT),8192);block81(RING,count,True);out=rd(DEST)
  for i in range(count):wb(out+i,rb(RING+i))
  remaining=rd(PLAINLEFT);wd(DEST,(rd(DEST)+count)&0xffffffff);wd(PLAINLEFT,(remaining-count)&0xffffffff);total=(total+count)&0xffffffff
 return total

def hook81(mu,address,size,data):
 if address!=0x4fa320:return
 sp=mu.reg_read(UC_X86_REG_ESP);block81(mu.reg_read(UC_X86_REG_EDI),n.unpack('<I',sp+4)[0],False);mu.reg_write(UC_X86_REG_EAX,0xdeadbeef);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook81)
def execute81(c):
 global shadow,checks,segments,events,ordinal,config
 config=c;method=c['method'];segments=common+([(RING,8192),(OUT,17000)]if method=='Decode'else[])
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.write(DATA,bytes((i*37+11)&255 for i in range(64)));n.pack('<I',CURSOR,DATA);n.pack('<II',DEST,OUT,c.get('accumulator',0x89abcdef));n.pack('<I',PACKEDLEFT,c['packed']);n.pack('<I',PLAINLEFT,0x12345678);n.pack('<I',BYTE,c.get('byte',0xd3));n.pack('<I',AVAIL,c.get('available',0));n.pack('<I',GATE,c.get('gate',1));initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0
 if method=='Bits':inputs=dict(count=c['count']);want=bits81(c['count']);address=0x4f5d00;args=[c['count']]
 else:inputs=dict(source=DATA,destination=OUT,packed=c['packed'],plain=c['plain']);want=wrapper81(**inputs);address=0x4faea0;args=list(inputs.values())
 model=snap(True);me=events.copy();events=[];ordinal=0;actual=n.call(address,args,count=12000000);final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else [y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual,final=final,nativeEvents=ne))
for count,available,packed in itertools.product(range(33),[0,1,7,8],[0,1,4,16]):execute81(dict(method='Bits',count=count,available=available,packed=packed,accumulator=0x89abcdef,byte=0xd3))
for plain,packed,gate in itertools.product([0,1,17,8191,8192,8193,16384],[0,1,3,4,17],[0,1,0xffffffff]):execute81(dict(method='Decode',plain=plain,packed=packed,gate=gate))
for plain in[1,8192,8193,16384]:execute81(dict(method='Decode',plain=plain,packed=17,changeRemaining=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=2,ports=['blockDecoder4fa320'],closure='Original4f5d00 bit collector and4faea0 wrapper through original collector/memcpy, only block decoder normalized')
(nm.BASE/'reports/script-phase81-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase81-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
