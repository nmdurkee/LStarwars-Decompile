"""Actual UTF16 filesystem body/catalog semantics; preserve original byte command/name consumers."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase99-20261013-verify.py').read_text().split('\ntable=json.loads')[0])
s100=Path(__file__).with_name('script-phase100-20261013-verify.py').read_text();exec(s100[s100.index('def byte100'):s100.index('def execute100')]);s48=Path(__file__).with_name('script-phase48-20261013-verify.py').read_text();exec(s48[s48.index('def rw'):s48.index('def execute48')]);s49=Path(__file__).with_name('script-phase49-20261013-verify.py').read_text();exec(s49[s49.index('def next49'):s49.index('def hook49')]);segments=list(dict.fromkeys(segments+[(0x88ab4c,4)]));cases=[];checks=0;errors=[]
oldline101=nextline;oldcount101=next_count

def nextline(model):return next49()if rb(PARSER+0x578)else oldline101(model)
def next_count():
 global P48
 P48=PARSER;return next48()if rb(PARSER+0x578)else oldcount101()
def token(model):next_count()
def dispatch31():
 p=rd(PARSER+0x510)
 if rb(PARSER+0x578):
  name='';i=0
  while rw(p+i*2):
   c=rw(p+i*2);name+=chr(c if c<256 else{0x2019:0x92,0x2013:0x96,0x2018:0x91,0x2026:0x85,0x2122:0x99}.get(c,63));i+=1
 else:name=text(p)
 if not name or name[0]==';':return
 depth=signed(rd(PARSER+0x570))
 if depth>=0:
  for table in[rd(PARSER+0x530+depth*4),rd(PARSER+0x550+depth*4)]:
   if not table:continue
   at=table
   while rd(at):
    if fold(text(rd(at)))==fold(name):command31(rd(at+4),True);return
    at+=8
 fallback=rd(0x91eec4)
 if fallback:command31(fallback,True)

def setup101(c):
 setup99(c);n.write(ROOTNAME,b'root.scp\0');n.pack('<I',0x91eec4,0)
def execute101(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45,PARSER
 config=c;setup101(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,2),(LOCAL,256),(LOCAL97,512)]:
  for i in range(z):shadow[p+i]=0
 if c['method']=='Body':wanted=finalize40(0,FOLDER46,ROOTNAME,TOP,BOTTOM)
 else:load46(0,FOLDER46,TOP,BOTTOM,SYS69);wanted=rd(SYS69+28)
 model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=[];symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 if c['method']=='Body':actual=n.call(0x52c320,[ROOTNAME,TOP,BOTTOM],regs={UC_X86_REG_EAX:FOLDER46,UC_X86_REG_ECX:0},count=24000000)
 else:n.call(0x52c470,[0,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);actual=n.unpack('<I',SYS69+28)[0]
 final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:16],model=b if group!='images'else'compactdiff'))
 scriptName=native_text(n.unpack('<I',actual+8)[0])if actual and n.unpack('<I',actual+8)[0]else'';state=n.unpack('<I',actual+16)[0]if actual else 0;stateNames=[]
 while state:stateNames.append(native_text(n.unpack('<I',state+24)[0]));state=n.unpack('<I',state)[0]
 cases.append(dict(context=c,inputs=dict(archive=0,path=FOLDER46,fileName=ROOTNAME,top=TOP,bottom=BOTTOM,system=SYS69),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()},summary=dict(scriptName=scriptName,stateNames=stateNames)))
def wide101(text,order):return((b'\xff\xfe'if order=='le'else b'\xfe\xff')+text.encode('utf-16'+order)).decode('latin1')
def packed101(token):
 raw=token.encode('latin1');raw+=b'\0'if len(raw)&1 else b'';return raw.decode('utf-16le')
normal='STATE BASE\n}\nSTATE TARGET\n}\n';packed=packed101('STATE')+' '+packed101('BASE')+'\n}\n'+packed101('STATE')+' '+packed101('TARGET')+'\n}\n'
#Observed release diagnostics are RET-only, not application callbacks.
releaseDiagnostics102={0x4ef790,0x4ef7b0,0x512850,0x512860,0x512870}
oldhook102=hook46
def hook46(mu,address,size,data):
 if address in releaseDiagnostics102:return
 return oldhook102(mu,address,size,data)
#Fresh native instance excludes earlier diagnostic adapters; retain only final platform and bounded catalog formatting.
priorNative102=n;n=nm.NativeX86();pe102=struct.unpack_from('<I',n.blob,0x3c)[0];imageSize102=struct.unpack_from('<I',n.blob,pe102+24+56)[0];n.write(0x400000,priorNative102.read(0x400000,(imageSize102+4095)&~4095));n.write(n.STOP,priorNative102.read(priorNative102.STOP,4096))
oldfilehook102=hook94
def releaseFileHook102(mu,address,size,data):
 if address==0x4ef7b0:return
 return oldfilehook102(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,releaseFileHook102);n.mu.hook_add(UC_HOOK_CODE,hook95);n.mu.hook_add(UC_HOOK_CODE,hook99)
class ReleaseEvents102(list):
 def append(self,item):
  if item.get('name')!='Diagnostic':super().append(item)
def execute101(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45,PARSER
 config=c;setup101(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,2),(LOCAL,256),(LOCAL97,512)]:
  for i in range(z):shadow[p+i]=0
 if c['method']=='Body':wanted=finalize40(0,FOLDER46,ROOTNAME,TOP,BOTTOM)
 else:load46(0,FOLDER46,TOP,BOTTOM,SYS69);wanted=rd(SYS69+28)
 model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 if c['method']=='Body':actual=n.call(0x52c320,[ROOTNAME,TOP,BOTTOM],regs={UC_X86_REG_EAX:FOLDER46,UC_X86_REG_ECX:0},count=24000000)
 else:n.call(0x52c470,[0,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);actual=n.unpack('<I',SYS69+28)[0]
 final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:16],model=b if group!='images'else'compactdiff'))
 scriptName=native_text(n.unpack('<I',actual+8)[0])if actual and n.unpack('<I',actual+8)[0]else'';state=n.unpack('<I',actual+16)[0]if actual else 0;stateNames=[]
 while state:stateNames.append(native_text(n.unpack('<I',state+24)[0]));state=n.unpack('<I',state)[0]
 cases.append(dict(context=c,inputs=dict(archive=0,path=FOLDER46,fileName=ROOTNAME,top=TOP,bottom=BOTTOM,system=SYS69),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()},summary=dict(scriptName=scriptName,stateNames=stateNames)))

#Whole loader uses fresh native102 final platform hooks; no loader/read/seek/format adapters.
PATH106=D+0x2b00;TOP106=D+0x2c00;SIZE106=TOP106+4;ALLOC106=D+0xc0000;FMT106=0x10006000;segments=list(dict.fromkeys(segments+[(ALLOC106,0x2000),(0x91ee9c,4),(0x800474,4)]));cases=[];checks=0;errors=[]
def move106(dest,source,count):
 if dest<source:
  for i in range(count):wb(dest+i,rb(source+i))
  return dest+count
 for i in range(count-1,-1,-1):wb(dest+i,rb(source+i))
 return 0
def seek106(handle,position):return publicSeek95(handle,position&0xffffffff,(position>>32)&0xffffffff,0)
def load106(path,top,sizeOut,mode):
 saved=rd(BUFFERFLAG);mode=signed((mode&0xffff)| (0xffff0000 if mode&0x8000 else 0));handle=gameOpen94(path,mode&0xffffffff,0,0)
 if not handle:wd(BUFFERFLAG,saved);return 0
 base=signed(rd(0x91ee9c))
 if base:seek106(handle,base&0xffffffffffffffff)
 reader77(handle,BOMTEMP,8);offset=signed(rd(BOMTEMP));size=rd(BOMTEMP+4)
 if offset<0:offset=-offset*256
 seek106(handle,(base+offset)&0xffffffffffffffff);formatter97(rd(DEFAULT),FMT106,path,256);name=text(FMT106);aligned=(len(name)+16)&0xfffffff0;needed=(size+aligned+0xc0)&0xffffffff
 if not top:publicClose95(handle);wd(BUFFERFLAG,saved);return 0
 archive=rd(top);wd(top,(archive+needed)&0xffffffff)
 if sizeOut:wd(sizeOut,needed)
 filename=archive+0xc0;data=filename+aligned;wb(archive+0xb0,0);wb(archive+0xb1,0);wd(archive+0xb8,filename)
 for i,b in enumerate(name.encode('latin1')+b'\0'):wb(filename+i,b)
 reader77(handle,data,size);version=rd(data);count=rd(data+4);cursor=data+8;wd(archive,version);wd(archive+4,count);wd(archive+8,cursor);cursor+=count*16;directories=rd(cursor);cursor+=4;wd(archive+0xc,directories);wd(archive+0x10,cursor);cursor+=directories*8;nameBytes=rd(cursor);cursor+=4;wd(archive+0x14,nameBytes);wd(archive+0x18,cursor)
 for i in range(max(0,signed(directories))):at=rd(archive+0x10)+i*8+4;wd(at,(rd(at)+cursor)&0xffffffff)
 wd(rd(archive+0x10)+4,0);cursor+=nameBytes
 for off in[0x1c,0x20,0x24,0x28]:wd(archive+off,0)
 if signed(version)<=-2:
  indexes=cursor;wd(archive+0x1c,indexes);indexBytes=count*4;cursor+=indexBytes;named=rd(cursor);cursor+=4;wd(archive+0x20,named);namedBytes=rd(cursor);cursor+=4;wd(archive+0x24,namedBytes);wd(archive+0x28,cursor)
  for i in range(max(0,signed(named))):
   while rb(cursor):cursor+=1
   cursor+=1
   if cursor&1:cursor+=1
   cursor+=2
  destination=rd(archive+0x10);move106(destination,indexes,indexBytes);wd(archive+0x1c,destination);destination+=indexBytes
  if namedBytes:wd(archive+0x28,destination);move106(destination,destination,namedBytes);destination+=namedBytes
  wd(top,destination)
  for off in[0x10,0xc,0x14,0x18]:wd(archive+off,0)
 wd(archive+0x34,0xffffffff);wd(archive+0x38,0);wd(archive+0x3c,0)
 for i in range(7):
  p=archive+0x40+i*16;wd(p,0);wd(p+4,0xffffffff);wd(p+8,0);wd(p+12,0)
 wd(archive+0x30,handle);wb(archive+0xb2,mode);wb(archive+0xb3,mode>>8);wd(archive+0xb4,0);wd(BUFFERFLAG,saved);return archive

def execute106(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45
 config=c;setup99(c);n.write(PATH106,b'archive.dat\0');n.write(ALLOC106,bytes([0xa5])*0x2000);n.pack('<II',TOP106,ALLOC106+c.get('alignment',0),0xa5a5a5a5);n.pack('<I',0x91ee9c,c.get('base',0));n.pack('<I',0x800474,c.get('special',0));n.pack('<I',PROVIDER,c.get('providerType',0));initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,8),(LOCAL,256),(LOCAL97,512),(FMT106,256)]:
  for i in range(z):shadow[p+i]=0
 top=0 if c.get('nullTop')else TOP106;sizeOut=0 if c.get('nullSize')else SIZE106;wanted=load106(PATH106,top,sizeOut,c.get('mode',0));model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99();actual=n.call(0x4fbb40,[PATH106,top,sizeOut,c.get('mode',0)],count=24000000);final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(context=c,inputs=dict(path=PATH106,top=top,sizeOut=sizeOut,mode=c.get('mode',0),formatLocal=FMT106),initial=initial,final=final,returnValue=actual,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()}))
def table106(version,files,dirs,named):
 names=b'\0DIR\0';payload=struct.pack('<II',version&0xffffffff,files)
 for i in range(files):payload+=struct.pack('<4I',0x12340000+i,10+i,0x100+i*16,0x200+i)
 payload+=struct.pack('<I',dirs)
 for i in range(dirs):payload+=struct.pack('<II',i,0 if i==0 else 1)
 payload+=struct.pack('<I',len(names))+names
 if version<=-2:
  payload+=b''.join(struct.pack('<I',i+3)for i in range(files));blob=b''
  for i in range(named):
   blob+=('NAME'+str(i)).encode()+b'\0'
   if (len(payload)+8+len(blob))&1:blob+=b'\0'
   blob+=struct.pack('<H',i)
  payload+=struct.pack('<II',named,len(blob))+blob
 return payload
def file106(table,base,offset):
 actual=base+(offset if offset>=0 else -offset*256);data=bytearray([0x5a])*max(base+8,actual+len(table));data[base:base+8]=struct.pack('<II',offset&0xffffffff,len(table));data[actual:actual+len(table)]=table;return bytes(data).decode('latin1')
ENTRY107=D+0x2d00;ENTRYB107=ENTRY107+32;OUT107=D+0xd0000;segments=list(dict.fromkeys(segments+[(OUT107,512),(0x88ab48,4)]));cases=[];checks=0;errors=[]
parentSeek93=lambda handle,low,high:publicSeek95(handle,low,high,0)
oldPort92_107=port92
def port92(name,args,model):
 if name=='Open':return gameOpen94(*args)
 return oldPort92_107(name,args,model)
oldReader107=reader77
def reader77(handle,destination,count):
 if signed(handle)<0x800:return oldReader107(handle,destination,count)
 record=COMP+(handle-0x800)*48;parent=rd(record)+((rd(record+32)+3)<<4);assert rd(record+40)==0;current=q(record+16)
 if current!=q(parent+8):publicSeek95(rd(parent),current&0xffffffff,current>>32,0);wq(parent+8,q(record+16))
 difference=(q(record+8)+signed(rd(record+24))-q(record+16))&MASK64;chosen=min(signed(count),max(0,signed64(difference)))&0xffffffff
 if not chosen:return 0
 value=oldReader107(rd(parent),destination,chosen)
 if signed(value)>=0:wq(record+16,(q(record+16)+value)&MASK64);wq(parent+8,q(record+16))
 return value

def hash107(text):
 h=0x811c9dc5
 for b in text.encode('latin1'):h=((h^(b if b<128 else b-256))*0x199933)&0xffffffff
 return h
def archive107(number):
 contents=[b'ALPHA1234',bytes((i*17+23)&255 for i in range(37))][:number];names=['A.BIN','B.BIN'][:number];table=struct.pack('<II',0xfffffffe,number)
 for i,payload in enumerate(contents):table+=struct.pack('<4I',16+i,len(payload),len(payload),0)
 table+=struct.pack('<I',1)+struct.pack('<II',0,0)+struct.pack('<I',1)+b'\0'+b''.join(struct.pack('<I',hash107(name))for name in names)+struct.pack('<II',0,0);data=bytearray(file106(table,0,8).encode('latin1'));data+=bytes([0x5a])*max(0,0x1100+37-len(data))
 for i,payload in enumerate(contents):data[0x1000+i*0x100:0x1000+i*0x100+len(payload)]=payload
 return bytes(data).decode('latin1')
def execute107(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45
 config=c;setup99(c);n.write(PATH106,b'archive.dat\0');n.write(ENTRY107,(c.get('prefix','')+'a.bin').encode()+b'\0');n.write(ENTRYB107,(c.get('prefix','')+'b.bin').encode()+b'\0');n.write(ALLOC106,bytes([0xa5])*0x2000);n.write(OUT107,bytes([0xa5])*512);n.write(COMP,bytes(960));n.pack('<II',TOP106,ALLOC106,0xa5a5a5a5);n.pack('<I',0x91ee9c,0);n.pack('<I',0x800474,0);n.pack('<I',0x88ab48,c['lock']);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,8),(LOCAL,256),(LOCAL97,512),(FMT106,256)]:
  for i in range(z):shadow[p+i]=0
 archive=load106(PATH106,TOP106,SIZE106,0);a=gameOpen94(ENTRY107,0,archive,0);handles=[a]
 if c['number']==2:handles.append(gameOpen94(ENTRYB107,0,archive,0))
 wanted=[archive]+handles
 for index,count in c['requests']:wanted.append(reader77(handles[index],OUT107,count))
 model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99();nativeArchive=n.call(0x4fbb40,[PATH106,TOP106,SIZE106,0],count=24000000);nativeHandles=[n.call(0x4fa3f0,[ENTRY107,0,nativeArchive,0],count=4000000)]
 if c['number']==2:nativeHandles.append(n.call(0x4fa3f0,[ENTRYB107,0,nativeArchive,0],count=4000000))
 actual=[nativeArchive]+nativeHandles
 for index,count in c['requests']:actual.append(n.call(0x4fb550,[nativeHandles[index],OUT107,count],count=12000000))
 final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('returns',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(context=c,inputs=dict(path=PATH106,top=TOP106,sizeOut=SIZE106,entryA=ENTRY107,entryB=ENTRYB107,destination=OUT107,formatLocal=FMT106),initial=initial,final=final,returnValues=actual,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()}))

import types
codec108=types.ModuleType('codec108');codec108.__file__=str(Path(__file__).with_name('script-phase84-20261013-verify.py'));exec(Path(codec108.__file__).read_text().split('\nfor entries,countBits')[0],codec108.__dict__)
common=codec108.common
for key108 in['SYM','SMALL','SLEN','PLEN','LEFT','RIGHT','INDEX','RING','GATE']:globals()[key108]=getattr(codec108,key108)
stream=codec108.stream;bitstring=codec108.bitstring
def wrapper81(source,destination,packed,plain):
 codec108.shadow=shadow;return codec108.wrapper81(source,destination,packed,plain)

#Original LZ2K header/payload and all decoder children now read loaded archive's real parent filesystem handle.
PACKED=0x88ab50;DECODED=0x8cf598;AVAILABLE=0x90fba4;OFFSET=0x8cf390;GL=0x917840;ACTIVE=0x91ce60;MAGIC=0x75ea44;MASK=0x800540;LOCAL=0x1000b000;segments=[s for s in segments if s[0]!=OUT107];segments=list(dict.fromkeys(segments+common+[(SYM,8192),(SMALL,512),(SLEN,510),(PLEN,24),(LEFT,4096),(RIGHT,4096),(INDEX,4),(RING,8192),(OUT107,17000),(PACKED,1024),(DECODED,17000),(AVAILABLE,4),(OFFSET,4),(GL,16),(ACTIVE,4),(MAGIC,5),(MASK,4)]));cases=[];checks=0;errors=[]
def load85():
 parent=rd(GL+4);assert reader77(rd(parent),LOCAL,12)==12;assert bytes(rb(LOCAL+i)for i in range(4))==b'LZ2K';plain=rd(LOCAL+4)&rd(MASK);payload=rd(LOCAL+8)&rd(MASK);assert payload;wd(GL+12,plain);wd(GL,payload);reader77(rd(rd(GL+4)),PACKED,payload);delta=(rd(GL)+12)&0xffffffff;low=rd(rd(ACTIVE)+16);high=rd(rd(ACTIVE)+20);sumLow=(low+delta)&0xffffffff;record=rd(ACTIVE);wd(record+16,sumLow);wd(record+20,(high+(-1 if delta&0x80000000 else 0)+(sumLow<low))&0xffffffff);low=rd(record+16);high=rd(rd(ACTIVE)+20);parent=rd(GL+4);wd(parent+8,low);wd(parent+12,high)
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

oldReader108=reader77
def reader77(handle,destination,count):
 if signed(handle)>=0x800:
  record=COMP+(handle-0x800)*48
  if rd(record+40)==2:return read85(destination,count)
 return oldReader108(handle,destination,count)
oldApi108=api76
def api76(name,args,model):
 global BOMTEMP
 if name=='ReadFile'and model and args[1]==LOCAL:
  prior=BOMTEMP;BOMTEMP=LOCAL
  try:return oldApi108(name,args,model)
  finally:BOMTEMP=prior
 return oldApi108(name,args,model)
def archive108(c):
 raw=bytes((i*31+37)&255 for i in range(17));packed=encoded85(c['symbol'],c['category']);plan=[(raw,17),(packed,4096),(encoded85((c['symbol']+1)%510,c['category']),8193)]if c['rawFirst']else[(packed,4096),(raw,17),(packed,8193)];blob=b''.join(b'LZ2K'+struct.pack('<II',plain,len(payload))+payload for payload,plain in plan);table=struct.pack('<II',0xfffffffe,1)+struct.pack('<4I',16,len(blob),12306,2)+struct.pack('<I',1)+struct.pack('<II',0,0)+struct.pack('<I',1)+b'\0'+struct.pack('<I',hash107('A.BIN'))+struct.pack('<II',0,0);data=bytearray(file106(table,0,8).encode('latin1'));data+=bytes([0x5a])*max(0,0x1000+len(blob)-len(data));data[0x1000:0x1000+len(blob)]=blob;return bytes(data).decode('latin1')
def execute108(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45
 config=c;setup99(c);n.write(PATH106,b'archive.dat\0');n.write(ENTRY107,b'a.bin\0');n.write(ALLOC106,bytes([0xa5])*0x2000);n.write(OUT107,bytes([0xa5])*17000);n.write(COMP,bytes(960));n.pack('<II',TOP106,ALLOC106,0xa5a5a5a5);n.pack('<I',0x91ee9c,0);n.pack('<I',0x800474,0);n.pack('<I',0x88ab48,c['lock'])
 for p,z in common+[(SYM,8192),(SMALL,512),(SLEN,510),(PLEN,24),(LEFT,4096),(RIGHT,4096),(INDEX,4),(PACKED,1024),(DECODED,17000),(AVAILABLE,4),(OFFSET,4),(GL,16),(ACTIVE,4)]:n.write(p,bytes(z))
 n.write(RING,bytes((i*19+23)&255 for i in range(8192)));n.write(MAGIC,b'LZ2K\0');n.pack('<I',MASK,0xffffffff);n.pack('<I',GATE,1);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,8),(LOCAL,256),(LOCAL97,512),(FMT106,256)]:
  for i in range(z):shadow[p+i]=0
 archive=load106(PATH106,TOP106,SIZE106,0);handle=gameOpen94(ENTRY107,0,archive,0);wanted=[archive,handle]
 for count in c['requests']:wanted.append(reader77(handle,OUT107,count))
 model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99();nativeArchive=n.call(0x4fbb40,[PATH106,TOP106,SIZE106,0],count=24000000);nativeHandle=n.call(0x4fa3f0,[ENTRY107,0,nativeArchive,0],count=4000000);actual=[nativeArchive,nativeHandle]
 for count in c['requests']:actual.append(n.call(0x4fb550,[nativeHandle,OUT107,count],count=15000000))
 final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('returns',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(context=c,inputs=dict(path=PATH106,top=TOP106,sizeOut=SIZE106,entry=ENTRY107,destination=OUT107,formatLocal=FMT106),initial=initial,final=final,returnValues=actual,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()}))
#Serialize catalog/script compressed streams; all I/O and codec children stay actual.
cases=[];checks=0;errors=[];oldSeek109=publicSeek95;oldClose109=publicClose95;oldPort45_109=port45

def publicSeek95(handle,low,high,origin):
 if 0x800<=handle<0x1000:
  record=COMP+(handle-0x800)*48;parent=rd(record)+((rd(record+32)+3)<<4);offset=low|(high<<32);target=(q(record+16)+offset if origin==1 else q(record+8)+signed(rd(record+24))-offset if origin==2 else q(record+8)+offset)&MASK64;value=publicSeek95(rd(parent),target&0xffffffff,target>>32,0);wq(record+16,value);wd(parent+8,value&0xffffffff);wd(parent+12,rd(record+20));return q(record+16)
 return oldSeek109(handle,low,high,origin)
def publicClose95(handle):
 if 0x800<=handle<0x1000:
  record=COMP+(handle-0x800)*48;wd(rd(record)+(rd(record+32)<<4)+52,0xffffffff);wd(record+36,0);return record
 return oldClose109(handle)
def exists95(path):
 if not path or not rb(path):return 0
 saved=rd(BUFFERFLAG);wd(BUFFERFLAG,0);container=rd(OPTIONS)
 if container:
  index=find91(container,path)
  if signed(index)>=0:wd(BUFFERFLAG,saved);return rd(rd(container+8)+(index<<4)+8)
 handle=gameOpen94(path,0,container,1)
 if handle:publicClose95(handle)
 wd(BUFFERFLAG,saved);return 1 if handle else 0
def port45(name,args,model):
 if name=='Size'and 0x800<=args[0]<0x1000:
  record=COMP+(args[0]-0x800)*48;return rd(record+(28 if rd(record+40)else 24))
 return oldPort45_109(name,args,model)
def archive109(row,kind,bom):
 arg=' 1'if row['name']in['AlwaysTrue','Param']else' missing'if row['words'][2]else'';body='STATE BASE\nCONDITIONS\nIF '+row['name']+arg+' > 0 goto TARGET\n}\n}\nSTATE TARGET\n}\n';texts=['root\n',body];prefix=b'\xef\xbb\xbf'if bom else b'';plain=[prefix+t.encode('latin1')for t in texts];payloads=[b'LZ2K'+struct.pack('<II',len(data)+3,len(data)+3)+data+bytes(3) if kind==2 else data for data in plain];names=['AI\\SCRIPT.TXT','AI\\ROOT.SCP'];table=struct.pack('<II',0xfffffffe,2)
 for i,payload in enumerate(payloads):table+=struct.pack('<4I',16+i,len(payload),len(plain[i]),kind)
 table+=struct.pack('<I',1)+struct.pack('<II',0,0)+struct.pack('<I',1)+b'\0'+b''.join(struct.pack('<I',hash107(name))for name in names)+struct.pack('<II',0,0);data=bytearray(file106(table,0,8).encode('latin1'));data+=bytes([0x5a])*max(0,0x1100+len(payloads[1])-len(data))
 for i,payload in enumerate(payloads):data[0x1000+i*256:0x1000+i*256+len(payload)]=payload
 return bytes(data).decode('latin1')
def execute109(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45
 config=c;setup99(c);n.write(PATH106,b'archive.dat\0');n.write(ALLOC106,bytes([0xa5])*0x2000);n.write(COMP,bytes(960));n.pack('<II',TOP106,ALLOC106,0xa5a5a5a5);n.pack('<I',0x91ee9c,0);n.pack('<I',0x800474,0);n.pack('<I',0x88ab48,1)
 for p,z in common+[(SYM,8192),(SMALL,512),(SLEN,510),(PLEN,24),(LEFT,4096),(RIGHT,4096),(INDEX,4),(PACKED,1024),(DECODED,17000),(AVAILABLE,4),(OFFSET,4),(GL,16),(ACTIVE,4)]:n.write(p,bytes(z))
 n.write(RING,bytes((i*19+23)&255 for i in range(8192)));n.write(MAGIC,b'LZ2K\0');n.pack('<I',MASK,0xffffffff);n.pack('<I',GATE,1);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,8),(LOCAL,256),(LOCAL97,512),(FMT106,256)]:
  for i in range(z):shadow[p+i]=0
 archive=load106(PATH106,TOP106,SIZE106,0);wd(OPTIONS,archive);load46(0,FOLDER46,TOP,BOTTOM,SYS69);bindsystem(SYS69);script=rd(SYS69+28);assert script;idle=rd(script+56);assert idle;bind(PACKET69,script,idle,0);result=evaluate69(0,SYS69,idle+8,ACTOR69,PACKET69);model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99();nativeArchive=n.call(0x4fbb40,[PATH106,TOP106,SIZE106,0],count=24000000);n.pack('<I',OPTIONS,nativeArchive);n.call(0x52c470,[0,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);scriptN=n.unpack('<I',SYS69+28)[0];n.call(0x5143a0,[SYS69],count=6000000);idleN=n.unpack('<I',scriptN+56)[0];n.call(0x514640,[SYS69,ACTOR69,PACKET69,0,0,0,0,scriptN,idleN]);nativeResult=n.call(0x52c880,[SYS69,idleN+8,ACTOR69,PACKET69],regs={UC_X86_REG_EAX:0},count=4000000);final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('returns',[nativeArchive,scriptN,idleN,nativeResult],[archive,script,idle,result]),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(context=c,inputs=dict(path=PATH106,containerTop=TOP106,sizeOut=SIZE106,folder=FOLDER46,top=TOP,bottom=BOTTOM,system=SYS69,actor=ACTOR69,packet=PACKET69,formatLocal=FMT106),initial=initial,final=final,returnValues=[nativeArchive,scriptN,idleN,nativeResult],nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()}))
table109=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates']
for row in table109:
 c=dict(predicate=row['name'],kind=2,bom=True,buffered=7,chunk=17,callback=True,seed=0x12345678);c['files']={'archive.dat':archive109(row,2,True)};execute109(c)
for row,kind,bom,buffered,chunk in itertools.product([r for r in table109 if r['name']in['AlwaysTrue','Param','Timer','Random']], [0,2],[False,True],[0,7],[17,4096]):
 if kind==2 and not bom or not buffered and chunk==17 or kind==2 and bom and buffered==7 and chunk==17:continue
 c=dict(predicate=row['name'],kind=kind,bom=bom,buffered=buffered,chunk=chunk,callback=True,seed=0x12345678);c['files']={'archive.dat':archive109(row,kind,bom)};execute109(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,descriptorRows=len(table109),symbolEvents=sum(e.get('name')=='Symbol'for c in cases for e in c['nativeEvents']),ports=['CreateFile','SetFilePointerEx','ReadFile','CloseHandle','EnterCriticalSection','LeaveCriticalSection'],closure='Actualfilesystem containerloader→container catalog/script files→realparser+allbuiltin init/bind/runtime via107recursiveIO/108type2chunks, finalOSonly')
(nm.BASE/'reports/script-phase109-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase109-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
