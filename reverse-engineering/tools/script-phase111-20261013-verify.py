"""Actual reversed suffix match, file-type registry lookup, conversion and raw slot/strip entry consumers. No hooks."""
from pathlib import Path
import importlib.util,json,itertools,struct
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX
R=0x90fba8; C=0x88ab38; D=n.DATA; SRC=D+0x400; DST=D+0x800; PAT=D+0x100
segments=[(R,0x600),(C,4),(D,0x1000)];cases=[];errors=[];checks=0;shadow={}
def snap(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rb(p):return shadow[p&0xffffffff]
def wb(p,v):shadow[p&0xffffffff]=v&255
def signed8(v):return v if v<128 else v-256
def fold(v):return (v+32)&255 if 65<=v<=90 or 192<=v<=223 else v
def match(row,end,length):
 i=0
 while rb(row+i):
  end-=1
  if length==0 or rb(row+i)!=fold(rb(end)):return 0
  i+=1;length=(length-1)&0xffffffff
 return 1
def lookup(text,length):
 if length==0:
  while rb(text+length):length+=1
 row=R
 while rb(row):
  if match(row,text+length,length):return row
  row+=16
 return 0
def copy(dst,src):
 length=0
 while rb(src+length):
  wb(dst+length,rb(src+length));length+=1
  if length>1024:raise ValueError('unbounded live copy')
 wb(dst+length,0);return length
def convert(dst,src):
 length=copy(dst,src);row=lookup(src,length)
 if not row:return 0
 if rb(row+14)==4:return 1
 slot=signed8(rb(row+13));other=R
 while rb(other+14)!=4 or signed8(rb(other+13))!=slot:
  other+=16
  if other>=R+0x600:raise ValueError('type4 counterpart required')
 cursor=dst+length+signed8(rb(other+15))-signed8(rb(row+15));wb(cursor,0);i=0
 while rb(other+i):cursor-=1;wb(cursor,rb(other+i));i+=1
 return 1
def strip(dst,src):
 length=copy(dst,src);row=lookup(src,length)
 if not row:return 0xffffffff
 wb(dst+length-signed8(rb(row+15)),0);return signed8(rb(row+13))&0xffffffff
def run(c):
 global shadow,checks
 n.write(R,b'\0'*0x600);n.pack('<I',C,0);n.write(D,b'\xa5'*0x1000)
 if 'rows'in c:
  for i,row in enumerate(c['rows']):
   name=bytes.fromhex(row['name']);n.write(R+16*i,name+b'\0');n.write(R+16*i+13,bytes([row.get('slot',0),row.get('type',0),row.get('length',len(name))]));
 else:n.call(0x4f78b0,[c.get('variant',0)],count=4000000)
 if 'count'in c:n.pack('<I',C,c['count'])
 text=bytes.fromhex(c.get('text',''));n.write(SRC,text+b'\0');src=SRC;dst=DST
 if c.get('alias')=='same':dst=SRC
 if c.get('alias')=='before':dst=SRC-16
 n.write(PAT,bytes.fromhex(c.get('pattern',''))+b'\0');initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};method=c['method'];length=c.get('length',0)
 wanted=match(PAT,SRC+len(text),length)if method=='Match'else lookup(SRC,length)if method=='Lookup'else (signed8(rb(lookup(SRC,length)+13))&0xffffffff if lookup(SRC,length)else 0xffffffff)if method=='Slot'else convert(dst,src)if method=='Convert'else strip(dst,src)
 model=snap(True);address={'Match':0x4f77d0,'Lookup':0x4f7c70,'Slot':0x4f7cd0,'Convert':0x4f7cf0,'Strip':0x4f7d90}[method];regs={UC_X86_REG_ECX:PAT,UC_X86_REG_EAX:length}if method=='Match'else {UC_X86_REG_ECX:SRC,UC_X86_REG_EAX:length}if method=='Lookup'else {};args=[SRC+len(text)]if method=='Match'else []if method=='Lookup'else [SRC,length]if method=='Slot'else[dst,src]
 actual=n.call(address,args,regs=regs,count=4000000);final=snap()
 for group,a,b in [('return',actual,wanted),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group=='return'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(source=src,destination=dst,pattern=PAT,end=SRC+len(text),length=length),initial=initial,final=final,returnValue=actual))
rows=json.loads((nm.BASE/'reports/script-phase104-20261013-initializer-rows.json').read_text())
for variant,row,prefix,upper in itertools.product([0,1],rows,[b'',b'folder/path.object'],[False,True]):
 address=row.get('nameWhenNonzero',row['name'])if variant else row['name'];name=bytearray();i=0
 while n.read(address+i,1)!=b'\0':name+=n.read(address+i,1);i+=1
 text=prefix+(bytes(name).upper()if upper else bytes(name))
 for method in ['Lookup','Slot','Convert','Strip']:run(dict(method=method,text=text.hex(),variant=variant,count=0 if prefix else 63))
for text,pattern,length in itertools.product([b'',b'a',b'XYZ.scp',bytes([0xc0,0xc1,0xde,0xdf]),b'none.unknown'],[b'',b'pcs.',b'a',bytes([0xff,0xfe,0xe1,0xe0]),b'PCS.'],[0,1,2,4,7,20]):run(dict(method='Match',text=text.hex(),pattern=pattern.hex(),length=length))
for method,text,length in itertools.product(['Lookup','Slot'],[b'',b'x.scp',b'none.unknown',b'.txt.TRAILING'],[0,1,4,6,12]):run(dict(method=method,text=text.hex(),length=length))
custom=[dict(name=b'aaa.'.hex(),slot=255,type=1),dict(name=b'bbbb.'.hex(),slot=255,type=4)]
for method,alias,text in itertools.product(['Convert','Strip'],['none','same','before'],[b'prefix.aaa',b'.bbbb',b'unknown']):run(dict(method=method,rows=custom,alias=alias,text=text.hex()))
for method in ['Lookup','Slot','Convert','Strip']:run(dict(method=method,rows=[dict(name=b'x.'.hex(),slot=128,type=4),dict(name=b'x.'.hex(),slot=1,type=4)],text=b'a.X'.hex()))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=3,rawEntryConsumers=['0x4f7cd0','0x4f7d90'],ports=[],closure='Original4f78b0 all63 registry rows→4f7c70→4f77d0; conversion4f7cf0 and raw byte-entry slot/strip callers execute entire bodies with no hooks')
(nm.BASE/'reports/script-phase111-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase111-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
