"""Original byte substring and complete normalized directory/flat container lookup; no adapters."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase90-20261013-verify.py').read_text().split('\nfor path,preserve')[0])
TREE=D+0x7000;DIRNAMES=D+0x7200;NEEDLE=D+0x7600;LOCAL=D+0xa000;SEPARATOR=0x75a204;segments +=[(TREE,64),(DIRNAMES,128),(NEEDLE,128),(SEPARATOR,4)];cases=[];checks=0;errors=[]
def substring91(text,needle):
 if not rb(text):return 0
 candidate=text
 while rb(candidate):
  offset=0
  while rb(needle+offset):
   c=rb(candidate+offset)
   if not c or c!=rb(needle+offset):break
   offset+=1
  if not rb(needle+offset):return candidate
  candidate+=1
 return 0

def compare91(a,b):
 if not a:return-1
 if not b:return 1
 offset=0
 while True:
  x=rb(a+offset);y=rb(b+offset);x=(x-32)&255 if 97<=x<=122 or x>=224 else x;y=(y-32)&255 if 97<=y<=122 or y>=224 else y
  if x!=y:return 1 if (x if x<128 else x-256)>(y if y<128 else y-256)else-1
  if not x:return 0
  offset+=1

def find91(container,path):
 source=path+4 if rb(path)==64 else path;i=0
 while rb(source+i):wb(LOCAL+i,rb(source+i));i+=1
 wb(LOCAL+i,0);normalize90(0,LOCAL);tree=rd(container+16)
 if not tree:return flat90(container,LOCAL)
 node=signed16(rw(tree));component=LOCAL;delimiter=substring91(component,SEPARATOR)
 if delimiter:wb(delimiter,0)
 while True:
  tree=rd(container+16);row=tree+node*8
  if compare91(rd(row+4),component)==0:
   if not delimiter:
    value=signed16(rw(rd(container+16)+node*8));return 0xffffffff if value>0 else(-value)&0xffffffff
   node=signed16(rw(row));component=delimiter+1;delimiter=substring91(component,SEPARATOR)
   if delimiter:wb(delimiter,0)
  else:node=signed16(rw(row+2))
  if not node:return 0xffffffff

def execute91(c):
 global shadow,checks
 for p,z in segments:n.write(p,bytes(z))
 method=c['method'];payload=bytes.fromhex(c['path'])+b'\0';n.write(PATH,payload);n.write(SEPARATOR,b'\\\0\0\0');n.pack('<I',FLAG,c.get('preserve',0))
 if method=='Substring':n.write(NEEDLE,bytes.fromhex(c['needle'])+b'\0');inputs=dict(text=PATH,needle=NEEDLE)
 else:
  inputs=dict(container=CON,path=PATH);n.pack('<I',CON+4,4);n.pack('<I',CON+28,HASHES);n.pack('<I',CON+32,1);n.pack('<I',CON+40,NAMES);query=payload[:-1][4:]if payload[:1]==b'@'else payload[:-1];query=bytes(92 if b in[47,92]else b-32 if not c.get('preserve')and 97<=b<=122 else b for b in query);n.write(NAMES,query+b'\0');word=NAMES+len(query)+1;word+=word&1;n.pack('<h',word,c.get('value',-7));h=0x811c9dc5
  for b in query:h=((h^(b if b<128 else(b-256)&0xffffffff))*0x199933)&0xffffffff
  for i in range(4):n.pack('<I',HASHES+i*4,h if c.get('hashHit')and i==3 else(h+i+1)&0xffffffff)
  if c.get('tree'):
   n.pack('<I',CON+16,TREE);n.pack('<h',TREE,1)
   for i,(name,child,sibling)in enumerate([(b'ROOT',2,4),(b'FILE.DAT',c.get('leaf',-7),3),(b'ALT.DAT',-9,0),(b'OTHER',-3,0)],1):p=DIRNAMES+(i-1)*24;n.write(p,name+b'\0');n.pack('<hhI',TREE+i*8,child,sibling,p)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(256):shadow[LOCAL+i]=0
 if method=='Substring':want=substring91(PATH,NEEDLE);address=0x4f20a0;args=[PATH,NEEDLE]
 else:want=find91(CON,PATH);address=0x4f9aa0;args=[CON,PATH]
 model=snap(True);actual=n.call(address,args,count=2000000);final=snap()
 for group,a,b in [('return',actual,want),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group=='return'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual,final=final))
for text,needle in itertools.product([b'',b'abcabc',b'ROOT\\FILE',b'\xffa\xe0',b'a'],[b'',b'a',b'abc',b'bc',b'\\',b'abcdef',b'\xe0']):execute91(dict(method='Substring',path=text.hex(),needle=needle.hex()))
paths=[b'root/file.dat',b'ROOT\\ALT.DAT',b'ROOT',b'OTHER',b'root/missing',b'MISSING',b'@RAWroot/file.dat',b'ROOT//FILE.DAT',b'',b'root/FILE.dat/extra']
for path,tree,preserve,hit,leaf in itertools.product(paths,[False,True],[0,1],[False,True],[-7,0,-32768]):
 if tree and path.endswith(b'/extra') and leaf<0:continue #A terminal leaf is not a prepared directory.
 execute91(dict(method='Find',path=path.hex(),tree=tree,preserve=preserve,hashHit=hit,leaf=leaf))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=2,ports=[],closure='Whole4f9aa0→original4efdf0/4f76f0/4f20a0/4f8b10/cookie with real private path/tree; original4f20a0 standalone, no adapters')
(nm.BASE/'reports/script-phase91-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase91-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
