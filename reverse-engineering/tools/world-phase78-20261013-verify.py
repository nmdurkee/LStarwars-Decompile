import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,0),(0x9736e0,8,0),(0x9736e8,120,0),(0x80b708,48,0),(0x97f978,64,167),(0x987500,16,167),(0x2854ce0,0x80,0),(0x2974d1c,4,0),(0x280d3cc,64,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

CHUNK=D+0x1000;DESC=D+0x2000;MAT=D+0x3000;OWNER=D+0x4000;ROOT=D+0x5000;MASK=D+0x6000;CURSOR=D+0x7000;ARENA=D+0x8000;PREV=D+0xc000;GEO=D+0xd000;MATRIX=D+0xe000
ctx=dict(P=CHUNK,quiet=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w,rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64,math=__import__('math'),trunc8=lambda i:i//8 if i>=0 else -((-i)//8))
def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());selected=ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]);env=dict(ctx,__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env
matrices=model(76);link=model(77);trace=[];case={}
def service(im,address,args):
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return 0
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def submit(im,c):
 chunk,descriptor,material,time,matrix,flags,first,second,life,color=c['args']
 if not descriptor:im.W(0x2854d08,0);return
 if not material or im.B(material+0x99)==0x97 and S(im.W(0x2974d1c))<2:return
 if descriptor!=im.W(0x2854d08):
  b=im.W(material+0x40)
  if b&0x30000!=0x20000 or not b&0x40000:
   im.W(material+0x40,(b&0xfffeffff)|0x60000);service(im,0x601030,[material]);im.H(material+0x2c0,(im.H(material+0x2c0)+1)&65535)
  modifier=im.W(0x2854ce8)
  if not modifier:matrices['apply'](im,dict(entry=0x5edd70,destination=0x97f978))
  else:
   for i in range(16):im.W(0x97f978+i*4,im.W(modifier+i*4))
  cam=[im.W(0x9736e8+i*4) for i in range(30)]
  for i in range(3):im.W(0x987500+i*4,cam[8+i])
  value=N.word(cam[8])*N.word(cam[12])+N.word(cam[9])*N.word(cam[13]);value=value+N.word(cam[10])*N.word(cam[14]);im.W(0x98750c,value.store()^0x80000000);im.W(descriptor+0x14,time)
  root=im.W(0x9736e0);im.W(root,(im.W(root)+15)&0xfffffff0);root=im.W(0x9736e0);cmd=im.W(root);im.W(root,cmd+0x14);count=im.W(0x2854cec);typ=im.W(0x2854cf0);im.W(cmd+4,count);value=im.W(0x2854cf4);im.B(cmd,typ&255);im.W(cmd+8,value);im.W(cmd+0x10,material);im.W(cmd+0x0c,0);im.W(0x2854d04,cmd)
  if not im.W(0x2854d00):entry=im.W(U(0x280d3cc+typ*4));size=im.W(0x2854cf8);service(im,0x6e5b90,[0,size,0x2854d00,0x2000,entry]);cmd=im.W(0x2854d04)
  owner=im.W(im.W(cmd+0x10)+0x3c);calls=link['apply'](im,dict(packet=cmd,mutations=case.get('serviceWrites',{}).get('0x607590',[])));trace.extend(calls);im.W(0x2854d08,descriptor)
 current=chunk;live=chunk
 for i in range(257):
  tag=S8(im.B(current));next=im.W(current+4)
  if tag==0x52:service(im,0x60b5d0,[descriptor,live,material,time,matrix,flags,first,second,life,color]);break
  if tag==0x4e and next:service(im,0x60b5d0,[descriptor,live,material,time,matrix,flags,first,second,life,color]);current=next;live=next
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
def observe(uc,a,z,user):
 if a in [0x60c410,0x5d60c0,0x5edd70,0x5e4b00,0x607cb0]:entries[hex(a)]=entries.get(hex(a),0)+1
 counts={0x601030:1,0x607590:2,0x6e5b90:5,0x60b5d0:10}
 if a not in counts:return
 sp=uc.reg_read(UC_X86_REG_ESP);service(ni,a,list(n.unpack('<%dI'%counts[a],sp+4)));uc.reg_write(UC_X86_REG_EAX,0xdeadbeef);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():
 c=dict(args=[CHUNK,DESC,MAT,bits(10),MATRIX,0,bits(.25),bits(.75),bits(1),bits(.5)],writes=[byte(CHUNK,0x52),word(CHUNK+4,0),word(MAT+0x3c,OWNER),word(MAT+0x40,0),half(MAT+0x2c0,0),word(OWNER,ROOT),word(OWNER+4,7),word(ROOT+0x58,MASK),word(ROOT+0x5c,MASK+0x100),word(OWNER+0x14,PREV),word(OWNER+0x18,GEO),word(0x9736e0,CURSOR),word(CURSOR,ARENA),word(0x2854d08,0),word(0x2854d00,1),word(0x2854ce8,0),word(0x2854cec,2),word(0x2854cf0,3),word(0x2854cf4,4),word(0x2854cf8,5),word(0x280d3cc+12,6),patch(0x9736e8,struct.pack('<30f',*[i*.125 for i in range(30)])),patch(0x80b708,struct.pack('<12f',1,0,0,0,0,1,0,0,0,0,1,0)),patch(MATRIX,struct.pack('<16f',1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1))]);return c
cases=[]
for tag in [0,0x4e,0x52,0xff]:
 for cached in [False,True]:
  for flags in [0,0x20000,0x40000,0x60000,0x70000,0xffffffff]:
   for modifier in [0,MATRIX]:
    c=seed();c['writes'] += [byte(CHUNK,tag),word(0x2854d08,DESC if cached else 0),word(MAT+0x40,flags),word(0x2854ce8,modifier)];cases.append(c)
for descriptor,material in [(0,0),(0,MAT),(DESC,0)]:c=seed();c['args'][1:3]=[descriptor,material];c['args'][0]=0xffffffff;cases.append(c)
for count in [0,1,2,0xffffffff]:c=seed();c['writes'] += [byte(MAT+0x99,0x97),word(0x2974d1c,count)];cases.append(c)
for offset in range(16):c=seed();c['writes'] += [word(CURSOR,ARENA+offset),half(MAT+0x2c0,65535)];cases.append(c)
for length in [1,2,16,255,256,257,258]:
 for terminal in [0,0x52]:
  c=seed()
  for i in range(length):c['writes'] += [byte(CHUNK+i*16,0x4e if i<length-1 else terminal),word(CHUNK+i*16+4,CHUNK+(i+1)*16 if i<length-1 else 0)]
  # Long chains use a dedicated nonoverlapping block.
  shift=D+0x10000-CHUNK;c['args'][0]+=shift;c['writes']=c['writes'][:len(seed()['writes'])]+[dict(address=p['address']+shift,data=p['data']) for p in c['writes'][len(seed()['writes']):]];cases.append(c)
for address,mutations in [(0x601030,[word(0x2854ce8,MATRIX),half(MAT+0x2c0,65535)]),(0x607590,[word(CURSOR,ARENA+0x100)]),(0x6e5b90,[word(0x2854d00,123)]),(0x60b5d0,[word(0x2854d08,0)])]:
 c=seed();c['serviceWrites']={hex(address):mutations}
 if address==0x6e5b90:c['writes'] += [word(0x2854d00,0)]
 cases.append(c)
rng=random.Random(2026101378)
for i in range(128):
 c=seed();c['args'][3]=bits(rng.uniform(-1000,1000));c['args'][6:10]=[bits(rng.uniform(-100,100)) for j in range(4)];c['writes'] += [patch(0x9736e8,struct.pack('<30f',*[rng.uniform(-100,100) for j in range(30)])),word(CURSOR,ARENA+rng.randrange(16)),word(MAT+0x40,rng.getrandbits(32))];cases.append(c)
c=seed();c['writes'] += [word(CURSOR,0x2854cf0)];cases.append(c)
# Cached next survives GPU callback changing the current packet.
c=seed();c['writes'] += [byte(CHUNK,0x4e),word(CHUNK+4,CHUNK)];c['serviceWrites']={'0x60b5d0':[byte(CHUNK,0x52),word(CHUNK+4,0)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);submit(im,c);predictedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x60c410,c['args'],count=10000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=predictedTrace:
  errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace[:4],modelTrace=predictedTrace[:4]));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['601030 material refresh','607590 owner preparation','6e5b90 arena allocation','60b5d0 GPU child submission'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase78-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase78-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
