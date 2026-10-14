import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297cc70,0x808,167),(0x2974d1c,4,0),(0x29765cc,4,0),(0x297bea0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))

QUERY=D+0x1000;TABLE=D+0x2000;FLAG=D+0x3000;DEVICE=D+0x4000;VTABLE=D+0x5000;ELEMENTS=D+0x6000;OUTPUT=D+0x7000;BYTES=D+0x8000;TARGET=0x10300000;CACHE=0x297cc78
n.mu.mem_map(TARGET,0x1000);n.write(TARGET,b'\xc3');trace=[];case={}
def find(im,query,table,count):
 low=table;high=U(table+count*8-8)
 if low<=high:
  while low<=high:
   slots=S(U(high-low))>>3;half=slots//2 if slots>=0 else -((-slots)//2);middle=U(low+half*8);v=im.W(middle)
   if v<query:low=U(middle+8)
   elif v<=query:return middle,True
   else:high=U(middle-8)
 return low,False
def search(im,c):
 low=c['table'];high=U(low+c['count']*8-8)
 if low<=high:p,found=find(im,im.W(c['query']),low,c['count'])
 else:p,found=low,False
 im.B(c['flag'],int(found));return p
def move(im,d,s,z):
 if d<s:
  delta=U(s-d);p=d
  for i in range(z):value=im.B(U(delta+p));im.B(p,value);p=U(p+1)
  return p
 se=U(s+z);de=U(d+z)
 for i in range(z):se=U(se-1);de=U(de-1);im.B(de,im.B(se))
 return 0
def layout(im,f):
 data=bytearray();offset=12;cap=S(im.W(0x2974d1c))
 def add(stream,off,typ,usage,index):data.extend(struct.pack('<HHBBBB',stream,off&65535,typ,0,usage,index))
 def vector(kind,usage,index,two=False):
  nonlocal offset
  if kind==1:add(0,offset,1 if two else 2,usage,index);offset+=8 if two else 12
  elif kind==2:add(0,offset,4 if cap<2 else 5 if usage==2 else 8,usage,index);offset+=4
 add(0,0,2,0,0);vector(2 if f&0x880008 else (f>>2)&1,3,0);vector(2 if f&0x1000020 else (f>>4)&1,6,0);vector(2 if f&0x2000080 else (f>>6)&1,6,1)
 if f&0x100:add(0,offset,4,10,0);offset+=4
 if f&0x600:add(0,offset,4,10,1);offset+=4
 tex=(f>>11)&7;half=bool(f&0x8000000);small,large=(15,16) if half else (1,3);one,two=(4,8) if half else (8,16)
 if tex==1:add(0,offset,small,5,0);offset+=one
 elif tex==2:add(0,offset,large,5,0);offset+=two
 elif tex==3:add(0,offset,large,5,0);add(0,offset+two,small,5,1);offset+=two+one
 elif tex==4:add(0,offset,large,5,0);offset+=two;add(0,offset,large,5,1);offset+=two
 vector(2 if f&0x8000 else (f>>14)&1,1,0,True);vector(2 if f&0x20000 else (f>>16)&1,2,0)
 if f&0x4000000:add(0,offset,4 if cap<2 else 8,5,6);add(0,offset+4,4,5,7)
 if f&0x400000:add(1,0,2,0,1)
 add(255,0,17,0,0);return bytes(data)
def port(im,target,device,elementPointer,output,data):
 trace.append([target,[device,elementPointer,output],base64.b64encode(data).decode()])
 if case['writeHandle']:im.W(output,case['handle'])
 for p in case.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['status']
def device(im,ptr,out,data):
 d=im.W(0x29765cc);target=im.W(im.W(d)+0x158);rv=port(im,target,d,ptr,out,data);im.W(0x297bea0,rv);return rv
def resolve(im,c):
 f=c['flags'];count=im.W(0x297cc70);entry,found=find(im,f,CACHE,count)
 if found:return im.W(entry+4)
 position=S(U(entry-CACHE))>>3;move(im,U(entry+8),entry,U((count-position)*8));im.W(0x297cc70,U(im.W(0x297cc70)+1));elements=layout(im,f);im.W(entry,f);device(im,0,entry+4,elements);return im.W(entry+4)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.write(a,struct.pack('<I',U(v)))
ni=NI()
def elementsAt(p):
 data=bytearray()
 for i in range(32):
  b=n.read(p+i*8,8);data.extend(b)
  if struct.unpack_from('<H',b)[0]==255:return bytes(data)
 raise ValueError('declaration no bounded terminator')
def observe(uc,a,z,user):
 if a in [0x741860,0x7418c0,0x4ef660,0x6e4850]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=TARGET:return
 sp=uc.reg_read(UC_X86_REG_ESP);dev,ptr,out=n.unpack('<3I',sp+4);data=elementsAt(ptr);publicPointer=ptr if D<=ptr<D+0x10000 else 0;rv=port(ni,a,dev,publicPointer,out,data);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+16)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e=0x7418c0):return dict(entry=e,flags=0,query=QUERY,table=TABLE,count=0,flag=FLAG,destination=BYTES,source=BYTES+0x100,length=16,elements=ELEMENTS,output=OUTPUT,status=0,handle=0xaabbccdd,writeHandle=True,writes=[word(0x297cc70,0),word(0x29765cc,DEVICE),word(DEVICE,VTABLE),word(VTABLE+0x158,TARGET),word(QUERY,0),patch(ELEMENTS,struct.pack('<HHBBBBHHBBBB',0,0,2,0,0,0,255,0,17,0,0,0)),patch(BYTES,bytes(range(256))*8)])
cases=[];rng=random.Random(2026101398)
for cap in [-1,0,1,2,3,0x7fffffff]:
 for flags in [0,0xffffffff]+[1<<i for i in range(32)]:
  c=seed();c['flags']=flags;c['writes'] += [word(0x2974d1c,cap)];cases.append(c)
for tex in range(8):
 for half in [0,0x8000000]:
  for cap in [0,2]:
   for other in [0,0x88003c,0x30000,0x4000100,0x400000]:
    c=seed();c['flags']=(tex<<11)|half|other;c['writes'] += [word(0x2974d1c,cap)];cases.append(c)
for i in range(512):c=seed();c['flags']=rng.getrandbits(32);c['writes'] += [word(0x2974d1c,rng.getrandbits(32))];cases.append(c)
for keys in [[],[0],[1,3,5],[0,1,0x7fffffff,0x80000000,0xffffffff]]:
 for query in [0,1,2,3,4,5,0x7fffffff,0x80000000,0xffffffff]:
  for wrote in [False,True]:
   c=seed();c['flags']=query;c['writeHandle']=wrote;c['status']=0x80004005 if not wrote else 0;c['writes'] += [word(0x297cc70,len(keys))]+[patch(CACHE+i*8,struct.pack('<2I',k,100+i)) for i,k in enumerate(keys)];cases.append(c)
for count in [0,1,3,0xffffffff,0x80000000,0x20000001]:
 for query in [0,1,2,3,0xffffffff]:
  c=seed(0x741860);c['count']=count;c['writes'] += [word(QUERY,query),patch(TABLE,struct.pack('<6I',0,100,2,101,0xffffffff,102))];
  if count in [0,0xffffffff,0x80000000]:c['query']=0xffffffff
  cases.append(c)
for flag in [QUERY,TABLE,TABLE+4]:c=seed(0x741860);c.update(count=1,flag=flag);c['writes'] += [word(QUERY,7),word(TABLE,7)];cases.append(c)
for shift in range(-32,33):
 for length in [0,1,2,3,4,7,8,16,32,64]:
  c=seed(0x4ef660);c.update(destination=BYTES+128+shift,source=BYTES+128,length=length);cases.append(c)
for output in [OUTPUT,0x297bea0,VTABLE+0x158]:
 for status in [0,1,0x80004005,0xffffffff]:c=seed(0x6e4850);c.update(output=output,status=status);cases.append(c)
c=seed();c['mutations']=[word(0x297cc70,123),word(0x297bea0,0xdeadbeef)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);e=c['entry']
 if e==0x7418c0:pred=resolve(im,c);args=[c['flags']]
 elif e==0x741860:pred=search(im,c);args=[c['query'],c['table'],c['count'],c['flag']]
 elif e==0x4ef660:pred=move(im,c['destination'],c['source'],c['length']);args=[c['destination'],c['source'],c['length']]
 else:pred=device(im,c['elements'],c['output'],im.read(c['elements'],16));args=[c['elements'],c['output']]
 expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(e,args,count=10000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=pred or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,entry=hex(e),native=actual,model=im.hash(),nativeResult=rv,modelResult=pred,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['devicevtable+158 CreateVertexDeclaration value/mutation port'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase98-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase98-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
