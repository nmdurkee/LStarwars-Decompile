import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x854260,8,0),(0x297d690,0x420,0),(0x97157c,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

KEY=D+0x1000;RUNTIME=D+0x2000;MAT=D+0x3000;TEXTURE=D+0x4000;OBJECT=D+0x5000;VTABLE=D+0x6000;OUT=D+0x8000;TARGET=0x10300000;TABLE=0x297d698
n.mu.mem_map(TARGET,0x1000);n.write(TARGET,b'\xc3');trace=[];case={};captured=[]
ctx=dict(TABLE=TABLE,rot=rot,N=N,U=U,F=F,bits=bits,struct=struct,S=S,S16=S16,S8=S8,base64=base64)
def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);tree=ast.parse(p.read_text());selected=ast.Module(body=[x for x in tree.body if isinstance(x,ast.FunctionDef)],type_ignores=[]);env=dict(ctx,__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env
pred=model(94);crc=model(93);texture=model(114)
def port(im,address,args):
 if address==0x5e5310:return texture['apply'](im,dict(index=args[0]))
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['lookupResult'] if address==0x5e5310 else case['format']
def blob(im,c):
 k=c['key'];cached=im.W(k);b=bytearray(104);b[20]=1
 if not c['force']:b[12:20]=im.read(0x854260,8)
 flags=im.W(cached+0x1b8)&0xfffffe3f if not im.W(k+12) else 0x1000
 struct.pack_into('<I',b,4,flags);struct.pack_into('<I',b,8,flags);struct.pack_into('<I',b,0,pred['modeFlags'](im,k));b[33]=int(im.W(k+16)!=0);b[35]=int(im.W(k+24)!=0);b[34]=int(im.W(k+20)!=0)
 if not im.W(k+12) and im.W(im.W(k)+0x1b8)&3:b[21]=im.B(cached+0xa9)
 if not im.W(k+12) and S(im.W(k+32))<S(im.W(im.W(k)+0x48)):b[22]=im.B(cached+0xaa)
 b[23]=pred['runtimeLayer'](im,k,0)
 for i in range(1,4):
  if pred['runtimeLayer'](im,k,i):b[23+i]=im.B(cached+0xaa+i)
 if not im.W(k+12) and im.W(im.W(k)+0x1b8)&0x6000:b[27]=im.B(cached+0xae)
 for i in range(1,4):
  if pred['baseLayer'](im,k,i):b[27+i]=im.B(cached+0x43+i)
 b[32]=1;b[31]=1;kind=im.W(k+12);r=im.W(k)
 if not kind:
  f=im.W(r+0x1b8)
  if f&1 and S(im.W(r+0x38))>S(im.W(k+32)):b[36]=2
  elif f&2 and S(im.W(r+0x38))>S(im.W(k+32)):b[36]=1
  if im.W(im.W(k)+0x1b8)&0x100000:b[37]=2 if S(im.W(k+32))<S(im.W(im.W(k)+0x34)) else 1
 r=im.W(k);b[38]=int(S(im.W(r+0x1e4))>0);b[39]=int(S(im.W(r+0x1e8))>0)
 if not kind and S(im.W(r))<0:b[40]=(im.W(cached+0x1bc)>>2)&3
 b[41]=int(bool(im.B(cached+0x13c)&12));b[42]=im.B(cached+0xa8)
 if not kind and S(im.W(r))<0:b[43]=1 if not im.W(r)&0x800000 else 2
 b[44]=1;material=im.W(k+4)
 if material and im.W(material+0x100):
  texture=port(im,0x5e5310,[im.W(material+0x100)])
  if texture:
   obj=im.W(texture+0x24)
   if obj:
    target=im.W(im.W(obj)+0x44);fmt=port(im,target,[obj,0])
    if fmt==0x31545844:b[44]=0
 return bytes(b)
def crcValues(im,data,reverse):
 v=65535
 for byte0 in data[::-1] if reverse else data:v=((v<<8)^im.W(TABLE+(((v>>8)^byte0)&255)*4))&65535
 return v
def resolve(im,c):
 b=blob(im,c);high=crcValues(im,b,True)<<16;im.W(c['output'],high);im.W(c['output'],im.W(c['output'])|crcValues(im,b,False));return b
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
entries={}
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x5e5310,0x744b70,0x744600,0x744430,0x7444b0,0x7445b0,0x7462b0,0x7462f0,0x7461b0,0x6e6950,0x6e693a]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a in [0x7462b0,0x7462f0]:
  sp=uc.reg_read(UC_X86_REG_ESP);p,length=n.unpack('<2I',sp+4);assert length==104;captured.append(n.read(p,length));return
 if a not in [TARGET]:return
 sp=uc.reg_read(UC_X86_REG_ESP)
 if a==0x5e5310:args=list(n.unpack('<I',sp+4));cleanup=4
 else:obj,level,out=n.unpack('<3I',sp+4);args=[obj,level];cleanup=16
 rv=port(ni,a,args)
 if a==TARGET:n.write(out,struct.pack('<8I',rv,0,0,0,0,0,0,0));rv=0xffffffff
 uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():return dict(key=KEY,output=OUT,force=0,lookupResult=TEXTURE,format=0x31545844,writes=[patch(KEY,struct.pack('<9I',RUNTIME,MAT,0,0,1,0,1,3,0)),word(MAT+0x100,0),word(TEXTURE+0x24,OBJECT),word(OBJECT,VTABLE),word(VTABLE+0x44,TARGET),word(RUNTIME,0),patch(RUNTIME+4,struct.pack('<4I',1,2,3,4)),word(RUNTIME+0x13c,0),byte(RUNTIME+0x1b4,0),word(RUNTIME+0x1b8,0),word(RUNTIME+0x1bc,0),patch(RUNTIME+0xa8,bytes([1,2,3,4,5,6,7])),patch(RUNTIME+0x44,bytes([1,2,3])),word(RUNTIME+0x48,4),word(RUNTIME+0x34,4),word(RUNTIME+0x38,4)])
cases=[];rng=random.Random(2026101395)
for kind in [0,1,0xffffffff]:
 for force in [0,1,0x80000000]:
  for flags in [0,1,2,3,0x40,0x80,0x100,0x6000,0x100000,0x80000000,0xffffffff]:
   c=seed();c['force']=force;c['writes'] += [word(KEY+12,kind),word(RUNTIME+0x1b8,flags)];cases.append(c)
for i in range(384):
 c=seed();c['force']=rng.getrandbits(32) if i&1 else 0;c['writes'] += [word(KEY+12,rng.choice([0,1,0xffffffff])),patch(KEY+16,struct.pack('<5I',*[rng.choice([0,rng.getrandbits(32)]) for j in range(5)])),word(RUNTIME,rng.getrandbits(32)),word(RUNTIME+0x13c,rng.getrandbits(32)),word(RUNTIME+0x1b8,rng.getrandbits(32)),word(RUNTIME+0x1bc,rng.getrandbits(32)),byte(RUNTIME+0x1b4,rng.randrange(256)),patch(RUNTIME+0x44,bytes([rng.randrange(256) for j in range(3)])),patch(RUNTIME+0xa8,bytes([rng.randrange(256) for j in range(7)])),patch(0x854260,struct.pack('<2I',rng.getrandbits(32),rng.getrandbits(32)))]
 for f in [4,8,12,16,0x34,0x38,0x48,0x1e4,0x1e8]:c['writes'] += [word(RUNTIME+f,rng.getrandbits(32))]
 cases.append(c)
for material in [0,MAT]:
 for texid in [0,1,0xffffffff]:
  for result in [0,TEXTURE]:
   for obj in [0,OBJECT]:
    for fmt in [0,0x31545844,0x35545844,0xffffffff]:
     c=seed();c['lookupResult']=result;c['format']=fmt;c['writes'] += [word(KEY+4,material),word(MAT+0x100,texid),word(TEXTURE+0x24,obj)];cases.append(c)
for output in [KEY,KEY+4,KEY+12,RUNTIME,RUNTIME+0x13c]+[TABLE+i*4 for i in [0,1,2,3,127,255]]:
 c=seed();c['output']=output;cases.append(c)
for address,writes in [(0x5e5310,[word(TEXTURE+0x24,0)]),(TARGET,[word(TABLE,0x12345678),word(RUNTIME,0xffffffff)])]:
 c=seed();c['writes'] += [word(MAT+0x100,1)];c['serviceWrites']={hex(address):writes};cases.append(c)
TEX_TABLE=D+0x7000
removedMutableLookup=[dict(case=i,reason='mutable lookup port replaced by original readonly signed table body; no unchanged-fixture equivalence credit') for i,c in enumerate(cases) if '0x5e5310' in c.get('serviceWrites',{})]
cases=[c for c in cases if '0x5e5310' not in c.get('serviceWrites',{})]
for c in cases:c['writes'] += [word(0x97157c,TEX_TABLE),word(TEX_TABLE,c['lookupResult'])]
for index in [0x40000000,0x40000001,0x7fffffff,0x80000000]:
 c=seed();c['writes'] += [word(MAT+0x100,index),word(0x97157c,TEX_TABLE),word(U(TEX_TABLE+index*4-4),TEXTURE)] if index<0x80000000 else [word(MAT+0x100,index),word(0x97157c,0xffffffff)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);crc['initialize'](im,0);expectedBlob=resolve(im,c);expectedTrace=trace[:];trace=[];captured=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x7461b0,regs={UC_X86_REG_ECX:0});n.call(0x744b70,[c['output'],c['key'],c['force']],count=10000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace or captured!=[expectedBlob,expectedBlob]:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace,nativeBlob=captured[0].hex() if captured else None,modelBlob=expectedBlob.hex()));break
 c['expected']=dict(sha256=actual,trace=trace,descriptor=base64.b64encode(expectedBlob).decode(),token=n.unpack('<I',c['output'])[0]);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['textureCOMvtable+44 level0 format-out projection; HRESULTignored'],seconds=round(time.time()-start,3),supersededMutableLookupFixtures=removedMutableLookup,duplicateAddressCredit=0,reaEvidenceIds=["ev_718a7ee47cba9c24cd0e41201dfe02e64f77cabf97a09efe964e67b3211942fc"],syntheticExcluded=0)
(B/'reports/world-phase115-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase115-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
