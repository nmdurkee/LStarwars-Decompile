"""Original memory-file→LZ2K headers/payload→full codec→compressed dispatcher composition."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase84-20261013-verify.py').read_text().split('\nfor entries,countBits')[0])
COMP=0x297dc60;PARENT=D+0xd000;PACKED=0x88ab50;DECODED=0x8cf598;AVAILABLE=0x90fba4;OFFSET=0x8cf390;GL=0x917840;ACTIVE=0x91ce60;MAGIC=0x75ea44;MASK=0x800540;LOCAL=D+0xf000
segments=common+[(SYM,8192),(SMALL,512),(SLEN,510),(PLEN,24),(LEFT,4096),(RIGHT,4096),(INDEX,4),(RING,8192),(OUT,17000),(DATA,4096),(TABLE,400),(COMP,48),(PARENT,32),(PACKED,1024),(DECODED,17000),(AVAILABLE,4),(OFFSET,4),(GL,16),(ACTIVE,4),(MAGIC,5),(MASK,4)];cases=[];checks=0;errors=[]
def load85():
 parent=rd(GL+4);assert read71(rd(parent),LOCAL,12)==12;assert bytes(rb(LOCAL+i)for i in range(4))==b'LZ2K';plain=rd(LOCAL+4)&rd(MASK);payload=rd(LOCAL+8)&rd(MASK);assert payload;wd(GL+12,plain);wd(GL,payload);read71(rd(rd(GL+4)),PACKED,payload);delta=(rd(GL)+12)&0xffffffff;low=rd(rd(ACTIVE)+16);high=rd(rd(ACTIVE)+20);sumLow=(low+delta)&0xffffffff;record=rd(ACTIVE);wd(record+16,sumLow);wd(record+20,(high+(-1 if delta&0x80000000 else 0)+(sumLow<low))&0xffffffff);low=rd(record+16);high=rd(rd(ACTIVE)+20);parent=rd(GL+4);wd(parent+8,low);wd(parent+12,high)
def read85(out,count):
 if not count:return 0
 available=rd(AVAILABLE);total=0
 while count:
  if not available:
   load85();packed=rd(GL);plain=rd(GL+12)
   if packed==plain:
    for i in range(packed):wb(DECODED+i,rb(PACKED+i))
   else:wrapper81(PACKED,DECODED,packed,plain)
   available=rd(GL+12);wd(OFFSET,0)
  copied=min(signed(count),signed(available));assert copied>=0
  source=DECODED+rd(OFFSET)
  for i in range(copied):wb(out+i,rb(source+i))
  wd(OFFSET,(rd(OFFSET)+copied)&0xffffffff);total+=copied;available-=copied;count-=copied;out+=copied;wd(AVAILABLE,available)
 return total

def encoded85(symbol,category):
 return stream(bitstring(65535,16)+bitstring(0,5)+bitstring(0,5)+bitstring(0,9)+bitstring(symbol,9)+bitstring(0,4)+bitstring(category,4))+bytes(16)
def execute85(c):
 global shadow,checks,config,events
 config=c
 for p,z in segments:n.write(p,bytes(z))
 n.write(RING,bytes((i*19+23)&255 for i in range(8192)));n.write(DECODED,bytes((i*17+29)&255 for i in range(17000)));n.write(OUT,bytes([0xa5])*17000);n.write(MAGIC,b'LZ2K\0');n.pack('<I',MASK,0xffffffff);n.pack('<I',GATE,1)
 raw=bytes((i*31+37)&255 for i in range(17));packed=encoded85(c['symbol'],c['category']);plan=[(raw,17),(packed,4096),(encoded85((c['symbol']+1)%510,c['category']),8193)]if c['rawFirst']else[(packed,4096),(raw,17),(packed,8193)];blob=bytes(c['position'])+b''.join(b'LZ2K'+struct.pack('<II',plain,len(payload))+payload for payload,plain in plan);n.write(DATA,blob);n.pack('<5I',TABLE,DATA,DATA+len(blob)-1,DATA+c['position'],0,1);n.pack('<I',COMP,PARENT-48);n.pack('<III',COMP+0x20,0,1,2);n.pack('<II',COMP+0x10,c['low'],c['high']);n.pack('<I',PARENT,0x400);n.pack('<I',GL+4,PARENT);n.pack('<I',ACTIVE,COMP);n.pack('<I',AVAILABLE,c['cached']);n.pack('<I',OFFSET,5)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(12):shadow[LOCAL+i]=0
 events=[];want=[]
 for count in c['requests']:want.append(read85(OUT,count))
 model=snap(True);actual=[]
 for count in c['requests']:actual.append(n.call(0x4fb550,[0x800,OUT,count],count=15000000))
 final=snap()
 for group,a,b in [('returns',actual,want),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='returns'else [x for x,y in zip(a,b)if x!=y][:1],model=b if group=='returns'else [y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(handle=0x800,destination=OUT,requests=c['requests']),initial=initial,returnValues=actual,final=final))
for symbol,category,wanted,rawFirst in itertools.product([17,256,509],[0,13],[0,1,17,31,257,8192,8193],[False,True]):execute85(dict(symbol=symbol,category=category,requests=[wanted,111],rawFirst=rawFirst,cached=7 if len(cases)&1 else 0,position=7 if len(cases)&2 else 0,low=0xfffffff8 if len(cases)&4 else 17,high=0xffffffff if len(cases)&8 else 0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=0,ports=[],closure='Actual4fb550→4faf60→4f6760→header getters/actual4fb550/4fb4f0→4faea0→all codec children, no adapters')
(nm.BASE/'reports/script-phase85-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase85-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
