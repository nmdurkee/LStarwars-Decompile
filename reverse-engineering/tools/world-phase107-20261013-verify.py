import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x80000,167),(0x2854ce0,0x200,0),(0x2854b80,0x40,0),(0x280d3c0,0x40,0),(0x297bea0,4,0),(0x97f978,0x200,0),(0x987500,16,0),(0x9736e0,4,0),(0x96d9c0,20,167),(0x9715a0,20,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

import math
def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());selected=ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef) and x.name not in ['seed','observe','model']],type_ignores=[]);env=dict(globals(),__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env
screen=model(108);point=model(36);affine=model(102);refill=model(110)
TARGET=0x10300000;RELEASE_TARGET=TARGET+0x100;n.mu.mem_map(TARGET,0x1000);n.write(TARGET,b'\xc3');n.write(RELEASE_TARGET,b'\xc3')
trace=[];case={};counts={}
def service(im,address,args):
 trace.append([address,args]);key=hex(address);index=counts.get(key,0);counts[key]=index+1
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 sequence=case.get('sequenceWrites',{}).get(key,[])
 if index<len(sequence):
  for p in sequence[index]:im.write(p['address'],base64.b64decode(p['data']))
 if address==TARGET:
  if case['allocateWrites']:im.W(args[3],case['buffer'])
  return case['allocatorResult']
 if address==RELEASE_TARGET:return case['releaseResult']
 return 0
refill.update(service=service,TARGET=TARGET,RELEASE_TARGET=RELEASE_TARGET)
def refillInvoke(im,address,args):
 if address==0x6e5bc0:return service(im,im.W(im.W(args[0])+0x30),args)
 return service(im,address,args)
refill['service']=refillInvoke
assert n.read(0x76a7f0,8).hex()=='000000a0703dee3f'
GRAVITY=N(struct.unpack('<d',n.read(0x76a7f0,8))[0]);dot=affine['dot']
def blend(im,frame,field,fraction,complement):return (N.word(im.W(frame+field+40))*fraction+N.word(im.W(frame+field))*complement).store()
def xyz(im,p,v):
 for i,w in enumerate(v):im.W(p+i*4,w)
def emit(im,c):
 descriptor,chunk,material,time,matrix,flags,first,second,life,minimumDepth=c['args'];pending=0
 if im.B(material+0x99)==0x97:u0=0;u1=bits(1);v1=bits(1);v0=0
 else:u0=im.W(descriptor+0x28);u1=im.W(descriptor+0x30);v0=im.W(descriptor+0x2c);v1=im.W(descriptor+0x34)
 for slot in range(32):
  record=chunk+0x3c+slot*32;elapsed=N.word((N.word(time)-N.word(im.W(record-16))).store());product=elapsed*N.word(im.W(record));frameIndex=screen['qwordLow'](product)
  assert frameIndex==screen['sourceQwordLow'](product)
  if frameIndex>=63:continue
  fractionWord=(product-N(frameIndex)).store();frame=descriptor+0x4c+frameIndex*40
  position=[(N.word(im.W(record-12))*elapsed+N.word(im.W(record-28))).store(),(N.word(im.W(record-8))*elapsed+N.word(im.W(record-24))+N.word(im.W(descriptor+0x10))*elapsed*elapsed*GRAVITY).store(),(elapsed*N.word(im.W(record-4))+N.word(im.W(record-20))).store()]
  projected=[dot(*position,im.W(matrix+col*4),im.W(matrix+col*4+16),im.W(matrix+col*4+32),False,0) for col in range(3)]
  for col in range(3):im.W(0x97f9a8+col*4,(N.word(im.W(matrix+col*4+48))+N.word(projected[col])).store())
  if flags in [6,7]:screen['apply'](im,dict(point=0x97f9a8))
  distance=(N.word(im.W(0x987504))*N.word(im.W(0x97f9ac))+N.word(im.W(0x987500))*N.word(im.W(0x97f9a8))+N.word(im.W(0x987508))*N.word(im.W(0x97f9b0))+N.word(im.W(0x98750c))).store()
  if F(minimumDepth)>F(distance):continue
  if U(im.W(0x2854cf4)+pending+6)>im.W(0x2854cfc):
   old=im.W(0x2854d04);im.W(old+12,U(im.W(old+12)+pending));im.W(0x2854d0c,U(im.W(0x2854d0c)+pending));pending=0
   if not refill['apply'](im):return
   root=im.W(0x9736e0);cursor=im.W(root);oldCommand=im.W(0x2854d04);im.W(root,U(cursor+15)&0xfffffff0);commandMaterial=im.W(oldCommand+16);root=im.W(0x9736e0);command=im.W(root);typ=im.B(0x2854cf0);im.W(command+16,commandMaterial);count=im.W(0x2854cec);im.B(command,typ);offset=im.W(0x2854cf4);im.W(command+4,count);im.W(command+8,offset);im.W(command+12,pending);im.W(root,U(im.W(root)+20));im.W(0x2854d04,command);service(im,0x607cb0,[command])
  fraction=N.word(fractionWord);complement=N(1)-fraction;vertices=[[0]*3 for i in range(4)]
  for col in range(3):
   vertices[0][col]=blend(im,frame,col*4,fraction,complement);vertices[2][col]=blend(im,frame,24+col*4,fraction,complement);vertices[1][col]=blend(im,frame,12+col*4,fraction,complement);vertices[3][col]=(N.word(vertices[2][col])-N.word(vertices[1][col])+N.word(vertices[0][col])).store()
  for vertex in range(4):vertices[vertex]=point['transformwords'](im,vertices[vertex],0x97f978)
  color=im.W(frame+36);basePointer=im.W(0x2854d00);byteOffset=U((im.W(0x2854cf4)+pending)*24)
  xyz(im,U(basePointer+byteOffset),vertices[0]);im.W(im.W(0x2854d00)+byteOffset+12,color);basePointer=im.W(0x2854d00);im.W(basePointer+byteOffset+16,u0);im.W(basePointer+byteOffset+20,v1);xyz(im,basePointer+byteOffset+24,vertices[1]);im.W(im.W(0x2854d00)+byteOffset+36,color);basePointer=im.W(0x2854d00);im.W(basePointer+byteOffset+40,u1);im.W(basePointer+byteOffset+44,v1);basePointer=im.W(0x2854d00);xyz(im,basePointer+byteOffset+48,vertices[2]);im.W(im.W(0x2854d00)+byteOffset+60,color);basePointer=im.W(0x2854d00);im.W(basePointer+byteOffset+64,u1);im.W(basePointer+byteOffset+68,v0);basePointer=im.W(0x2854d00);xyz(im,basePointer+byteOffset+72,vertices[0]);im.W(im.W(0x2854d00)+byteOffset+84,color);basePointer=im.W(0x2854d00);im.W(basePointer+byteOffset+88,u0);im.W(basePointer+byteOffset+92,v1);basePointer=im.W(0x2854d00);xyz(im,basePointer+byteOffset+96,vertices[2]);im.W(im.W(0x2854d00)+byteOffset+108,color);basePointer=im.W(0x2854d00);im.W(basePointer+byteOffset+112,u1);im.W(basePointer+byteOffset+116,v0);basePointer=im.W(0x2854d00);xyz(im,basePointer+byteOffset+120,vertices[3]);im.W(im.W(0x2854d00)+byteOffset+132,color);basePointer=im.W(0x2854d00);im.W(basePointer+byteOffset+136,u0);im.W(basePointer+byteOffset+140,v0);pending+=6
  if any(not math.isfinite(F(w)) for vertex in vertices for w in vertex):raise ValueError('nonfinite emitted vertex outside prepared domain')
 finalCommand=im.W(0x2854d04);im.W(finalCommand+12,U(im.W(finalCommand+12)+pending));im.W(0x2854cf4,U(im.W(0x2854cf4)+pending));im.W(0x2854d0c,U(im.W(0x2854d0c)+pending))
DESC=D+0x1000;MATERIAL=D+0x3000;CHUNK=D+0x4000;MATRIX=D+0x6000;COMMAND=D+0x8000;CURSOR=D+0x9000;ARENA=D+0xa000;ALLOC=D+0xb000;VTABLE=D+0xc000;BUFFER=D+0x20000;IDENTITY=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];rng=random.Random(20261013107);cases=[]
def seed(active=1,flags=0,index=.5,tag=0,cap=192,mode=1,current=0):
 c=dict(args=[DESC,CHUNK,MATERIAL,bits(1),MATRIX,flags,0,0,bits(1),bits(0)],buffer=BUFFER,allocatorResult=0x80004005,releaseResult=0,allocateWrites=True,writes=[patch(DESC,bytes(0x1000)),patch(CHUNK,bytes(0x500)),patch(MATERIAL,bytes(0x300)),byte(MATERIAL+0x99,tag),patch(MATRIX,struct.pack('<16f',*IDENTITY)),patch(0x97f978,struct.pack('<16f',*IDENTITY)),patch(0x987500,struct.pack('<4f',0,0,1,100)),patch(0x96d9c4,struct.pack('<3f',-10,-10,-10)),patch(0x9715a4,struct.pack('<3f',20,20,20)),word(DESC+0x10,bits(-.5)),patch(DESC+0x28,struct.pack('<4f',.125,.25,.75,.875)),word(0x2854cec,mode),word(0x2854cf0,current),word(0x2854cf4,0),word(0x2854cf8,8192),word(0x2854cfc,cap),word(0x2854d00,BUFFER),word(0x2854d04,COMMAND),word(0x2854d0c,0),patch(COMMAND,bytes(20)),word(COMMAND+16,MATERIAL),word(0x9736e0,CURSOR),word(CURSOR,ARENA),word(ALLOC,VTABLE),word(VTABLE+0x2c,TARGET),word(VTABLE+0x30,RELEASE_TARGET)])
 for j in range(8):c['writes'] += [word(0x280d3cc+j*4,ALLOC),word(0x2854b8c+j*4,BUFFER+j*0x8000)]
 for j in range(64):c['writes'] += [patch(DESC+0x4c+j*40,struct.pack('<9fI',-1-j*.01,-1,0,1+j*.01,-1,0,1+j*.01,1,0,0xaabbccdd))]
 for j in range(32):c['writes'] += [patch(CHUNK+0x20+j*32,struct.pack('<8f',1,2,3,0 if j<active else 10000,.1,.2,.3,index if j<active else 1))]
 return c
for active in [0,1,2,32]:
 for flags in [0,6,7]:
  for index in [-1,-.5,0,.5,1,62.5,63,64]:
   for tag in [0,0x97]:cases.append(seed(active,flags,index,tag))
for active in [1,2,32]:
 for cap in [0,6,12,192]:
  for mode in [0,1]:
   for current in [0,3,7]:cases.append(seed(active,0,.5,0,cap,mode,current))
for i in range(256):
 c=seed(rng.choice([1,2,4]),rng.choice([0,6,7]),rng.uniform(-.9,62.9));c['writes'] += [patch(MATRIX,struct.pack('<16f',*[rng.uniform(-2,2) for j in range(16)])),patch(0x97f978,struct.pack('<16f',*[rng.uniform(-2,2) for j in range(16)]))];cases.append(c)
for threshold in [bits(-1000),bits(0),bits(100),bits(1000),0x7fc00001,0x7f800000,0xff800000]:
 c=seed(2);c['args'][9]=threshold;cases.append(c)
for key in [hex(TARGET),hex(RELEASE_TARGET),'0x607cb0','0x5f7490']:
 for field in [0x2854cf4,0x2854d0c,0x2854cec,0x2854cf0,0x2854cfc]:
  c=seed(2,0,.5,0,0,0 if key==hex(RELEASE_TARGET) or key==hex(TARGET) else 1,7 if key=='0x5f7490' else 0);c['serviceWrites']={key:[word(field,0)]};cases.append(c)
# Qword conversion overflows still produce low DWORD0; negative subunit frames extrapolate.
for elapsed,frequency in [(2**31,2**32),(-2**31,2**32),(.5,-1)]:
 c=seed();c['args'][3]=bits(elapsed);c['writes'] += [word(DESC+0x10,0),patch(CHUNK+0x20,struct.pack('<8f',1,2,3,0,0,0,0,frequency))];cases.append(c)
for pointer in [0x97f978,0x97f9a8]:
 c=seed();c['args'][4]=pointer;c['writes'] += [patch(pointer,struct.pack('<16f',*IDENTITY))];cases.append(c)
# Explicit emission aliases validate the live buffer pointer and later particle reads.
for bufferPointer in [0x97f978,0x97f9a8,MATRIX,DESC+0x4c]:
 c=seed(2);c['writes'].append(word(0x2854d00,bufferPointer));cases.append(c)
c=seed();c['writes'] += [word(0x2854d00,0x2854cf4),word(DESC+0x4c+36,0x2854cf4),word(DESC+0x28,COMMAND)];cases.append(c)
c=seed(2,0,.5,0,0);c['serviceWrites']={'0x607cb0':[word(DESC+0x28,bits(.5)),word(CHUNK+0x20+32+12,bits(10000))]};cases.append(c)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
ni=NI()
def observe(uc,a,z,user):
 if a in [0x60b5d0,0x5ffee0,0x6e6b90,0x5ffc80,0x6e5bc0,0x6e5b90,0x5b30a0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [TARGET,RELEASE_TARGET,0x607cb0,0x5f7490]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<5I' if a==TARGET else '<I',sp+4)) if a!=0x5f7490 else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+(24 if a==TARGET else 8 if a==RELEASE_TARGET else 4))
n.mu.hook_add(UC_HOOK_CODE,observe)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c)
 try:emit(im,c)
 except (ValueError,OverflowError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x60b5d0,c['args'],count=3000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:
  errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace,diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for a,z,_ in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:12]));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=hashlib.sha256(n.read(0x60b5d0,1360)).hexdigest(),binarySha256=n.sha256,gravityConstantBits=n.read(0x76a7f0,8).hex(),pointHelperRawBytesSha256=hashlib.sha256(n.read(0x5b30a0,108)).hexdigest(),pointHelperDuplicateCredit=0,domain='prepared finite32-particle motion/interpolation/modifier results, qword-low frame gating, raw color words, ordered global vertex stores and buffer rollover; quietNaN/infinite depth comparison thresholds',reaEvidenceIds=["ev_b98861102fe1e1fd114abb1617f0565887ae93def79dbbd21b492665ffc48e40","ev_ea12938c741b07211cb0503153ac8a906c4d3565365d8e839dad57149b292cd2","ev_1b04e019bde4a542c42c8a92707c2ae9615554ed2f5c12a599c1d972487654fe","ev_ac4e4ea5b4b8277625a0a0d12c775cd990c634f25a1ec3325cd3d350da27adff","ev_729dab12d8f13c6accce2bdeaf046e4f85e7307ba1e4a06d8369ab6b99d259e5","ev_49937f1207f83d5926d57f0c9dfe8930d301c41d65297ccc38417913b24d6b75"],nativeAdapters=['allocatorvtable+2c/+30 value/mutation ports','5f7490 fatal service','607cb0 command link initially explicit'],syntheticExcluded=len(excluded),excluded=excluded,seconds=round(time.time()-start,3))
(B/'reports/world-phase107-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase107-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
