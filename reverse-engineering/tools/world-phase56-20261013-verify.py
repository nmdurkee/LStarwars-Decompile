import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;OUT=D+0x2000;SIZE=D+0x1000;REGIONS=[(D,0x5000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];word=rot['word'];patch=rot['patch'];Image=rot['Image'];case={};trace=[]
def service(im,a,args):
 trace.append([a,args])
 for x in case.get('serviceWrites',[]):im.write(x['address'],base64.b64decode(x['data']))
 return 0xdeadbeef
def apply(im,c):
 dest=c['destination'];size=c['sizePointer']
 if c['entry']==0x683530:
  a=c['args'];service(im,0x682b10,[a[0],a[1],a[0],a[1],a[2],a[3],32,a[4],a[5]]);return 0
 if c['entry']==0x5ffe80:aligned=U(dest+15)&0xfffffff0;im.W(size,0xa4c);return aligned
 im.write(dest,bytes([0x52]));im.W(dest+4,0);im.W(dest+0x14,0);im.W(dest+0x18,0);im.W(dest+0x1c,0);im.W(dest+0x20,0)
 for i in range(32):
  at=dest+0x20+i*32
  for field,bits in [(0,0x3f800000),(4,0x40000000),(8,0x40400000),(16,0x40800000),(20,0x40a00000),(24,0x40c00000),(12,0xbf800000),(28,0x43000000)]:im.W(at+field,bits)
 im.W(dest+0x420,0);im.W(size,0x424);return dest
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
entries={}
def observe(uc,a,z,user):
 if a in [0x5ffdc0,0x5ffe70,0x5ffe80,0x683530]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=0x682b10:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];args=list(n.unpack('<9I',sp+4));value=service(NI(),a,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(entry=0x5ffdc0,destination=OUT,sizePointer=SIZE):return dict(entry=entry,destination=destination,sizePointer=sizePointer,args=[0,1,2,3,4,5],writes=[])
cases=[]
for entry in [0x5ffdc0,0x5ffe70]:
 for shift in range(-8,0x428):cases.append(seed(entry,sizePointer=OUT+shift))
 for shift in range(32):cases.append(seed(entry,destination=OUT+shift))
for cursor in list(range(32))+[0xffffffff,0xfffffff0,0xfffffff1,0x7fffffff,0x80000000,0x12345678]:cases.append(seed(0x5ffe80,destination=cursor))
rng=random.Random(2026101356)
for i in range(256):cases.append(seed(0x5ffe80,destination=rng.getrandbits(32),sizePointer=OUT+rng.randrange(0x420)))
for i in range(128):
 c=seed(0x683530);c['args']=[rng.getrandbits(32) for j in range(6)];c['serviceWrites']=[word(OUT+rng.randrange(0x420),rng.getrandbits(32))];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 actualReturn=n.call(c['entry'],c['args'] if c['entry']==0x683530 else [c['destination'],c['sizePointer']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if c['entry']==0x683530:actualReturn=0
 if actual!=im.hash() or actualReturn!=expected or trace!=modelTrace:errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash(),nativeReturn=actualReturn,modelReturn=expected,nativeTrace=trace,modelTrace=modelTrace));break
 c['expected']=dict(result=actualReturn,sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['0x682b10 mutable pool setup service'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase56-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase56-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
