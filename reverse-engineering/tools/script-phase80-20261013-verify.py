"""Original LZ2K getters and chunk loader with real memory file read/copy children."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
HEADER=DATA;PACKED=0x88ab50;PARENT=D+0x7000;RECORD=D+0x7100;GL=0x917840;ACTIVE=0x91ce60;MAGIC=0x75ea44;MASK=0x800540
segments += [(PACKED,2048),(PARENT,32),(RECORD,48),(GL,16),(ACTIVE,4),(MAGIC,5),(MASK,4)]
def initialize80(payload,plain,mask,position,size,low,high):
 n.write(TABLE,bytes(400));n.write(DATA,bytes(4096));n.write(OUT,bytes([0xa5])*8192);n.write(PACKED,bytes([0xa7])*2048);n.write(PARENT,bytes(32));n.write(RECORD,bytes(48));n.write(GL,bytes(16));n.pack('<I',ACTIVE,RECORD);n.write(MAGIC,b'LZ2K\0');n.pack('<I',MASK,mask);n.write(DATA+position,b'LZ2K'+struct.pack('<II',plain,payload)+bytes((i*37+11)&255 for i in range(payload)));n.pack('<5I',TABLE,DATA,DATA+size-1,DATA+position,0,1);n.pack('<I',PARENT,0x400);n.pack('<II',PARENT+8,0xdeadbeef,0x12345678);n.pack('<II',RECORD+16,low,high);n.pack('<I',GL+4,PARENT)
def field80(p,offset):
 if bytes(rb(p+i)for i in range(4))!=bytes(rb(MAGIC+i)for i in range(4)):return 0
 value=rd(p+offset)&rd(MASK)
 return value if offset==4 else ((value+12)&0xffffffff if value else 0)
def chunk80(header):
 parent=rd(GL+4);assert read71(rd(parent),header,12)==12;wd(GL+12,field80(header,4));wd(GL,(field80(header,8)-12)&0xffffffff);read71(rd(rd(GL+4)),PACKED,rd(GL));delta=(rd(GL)+12)&0xffffffff;low=rd(rd(ACTIVE)+16);high=rd(rd(ACTIVE)+20);s=(low+delta)&0xffffffff;record=rd(ACTIVE);wd(record+16,s);wd(record+20,(high+(0xffffffff if delta&0x80000000 else 0)+(1 if s<low else 0))&0xffffffff);low=rd(record+16);high=rd(rd(ACTIVE)+20);parent=rd(GL+4);wd(parent+8,low);wd(parent+12,high);return parent
def execute80(c):
 global shadow,checks
 initialize80(c.get('payload',17) if c['method']=='Chunk' else 17,c.get('plain',17),c.get('mask',0xffffffff),c.get('position',0),c.get('size',2048),c.get('low',17),c.get('high',0))
 method=c['method']
 if method!='Chunk':
  n.write(HEADER,c.get('signature','4c5a324b') and bytes.fromhex(c.get('signature','4c5a324b')));n.pack('<II',HEADER+4,c['plain'],c['payload'])
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 if method=='Chunk':
  # Compiler private stack local is intentionally outside captured state.
  local=D+0xa000
  for i in range(12):shadow[local+i]=0
  want=chunk80(local);actual=n.call(0x4f6760,[],count=5000000);inputs={}
 else:
  want=field80(HEADER,4 if method=='Plain'else 8);actual=n.call(0x4f5e30 if method=='Plain'else 0x4f5eb0,[HEADER]);inputs=dict(header=HEADER)
 final=snap();model=snap(True)
 for group,a,b in [('return',actual,want),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else [x for x,y in zip(a,b)if x!=y][:1],model=b if group=='return'else [y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual,final=final))
for method,signature,mask,value in itertools.product(['Plain','Block'],['4c5a324b','4c5a324a','00000000','6c5a324b'],[0,0xffffffff,0x7fffffff,0xffffff],[0,1,17,1024,0x7fffffff,0x80000000,0xfffffff4,0xffffffff]):execute80(dict(method=method,signature=signature,mask=mask,plain=value,payload=value))
for payload,plain,low,high,position,short in itertools.product([1,17,1024],[1,17,4096],[0,17,0xfffffff8],[0,1,0xffffffff],[0,7],[False,True]):execute80(dict(method='Chunk',payload=payload,plain=plain,low=low,high=high,position=position,size=position+12+(payload//2 if short else payload)))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=3,ports=[],closure='Original4f6760→4fb550/4fb4f0/6e6d90 plus both original header getters and original cookie checks; no adapters')
(nm.BASE/'reports/script-phase80-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase80-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
