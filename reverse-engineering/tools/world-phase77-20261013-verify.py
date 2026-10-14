import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167),(0x9736e0,64,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

P=D+0x1000;M=D+0x2000;O=D+0x3000;ROOT=D+0x4000;MASK=D+0x5000;C=D+0x7000;ALLOC=D+0x8000;PREV=D+0xa000;GEO=D+0xb000
trunc8=lambda i:i//8 if i>=0 else -((-i)//8)
def apply(im,c):
 p=c['packet'];material=im.W(p+0x10);owner=im.W(material+0x3c);root=im.W(owner);im.W(root+0x74,im.W(root+0x74)|2);index=S(im.W(owner+4));root=im.W(owner);bank=(im.W(root+0x74)>>15)&1;mask=U(im.W(root+0x58+bank*4)+trunc8(index));rem=index-trunc8(index)*8;im.B(mask,im.B(mask)|((1<<(rem&31))&255));trace=[[0x607590,[owner,0x9868a0]]]
 for p in c.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 cursor=im.W(0x9736e0);im.W(cursor,(im.W(cursor)+15)&0xfffffff0);cursor=im.W(0x9736e0);command=im.W(cursor);prev=im.W(owner+0x14);im.W(prev+4,command);im.W(owner+0x24,im.W(cursor));im.W(cursor,im.W(cursor)+16);im.B(im.W(cursor),0x8d);im.B(im.W(cursor)+1,1);geometry=im.W(owner+0x18);command=im.W(cursor);im.W(command+4,U(geometry+16));im.W(owner+0x14,im.W(cursor));im.W(cursor,im.W(cursor)+16);im.B(im.W(owner+0x24),0xa7);im.B(im.W(owner+0x24)+1,3);im.W(im.W(owner+0x24)+4,c['packet']);im.W(owner+0x24,U(im.W(owner+0x24)+16));return trace
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={};trace=[];current={}
def observe(uc,a,z,user):
 if a==0x607cb0:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=0x607590:return
 sp=uc.reg_read(UC_X86_REG_ESP);trace.append([a,list(n.unpack('<2I',sp+4))])
 for p in current.get('mutations',[]):n.write(p['address'],base64.b64decode(p['data']))
 uc.reg_write(UC_X86_REG_EAX,0xdeadbeef);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(index=0,bank=0,offset=0):return dict(packet=P,writes=[word(P+0x10,M),word(M+0x3c,O),word(O,ROOT),word(O+4,index),word(ROOT+0x74,bank<<15),word(ROOT+0x58,U(MASK-trunc8(S(U(index))))),word(ROOT+0x5c,U(MASK+0x1000-trunc8(S(U(index))))),word(0x9736e0,C),word(C,ALLOC+offset),word(O+0x14,PREV),word(O+0x18,GEO),word(O+0x24,0)])
cases=[];rng=random.Random(2026101377)
for index in list(range(-32,258))+[-2147483648,2147483647,-257,0x80000007]:
 for bank in [0,1]:cases.append(seed(index,bank,rng.randrange(16)))
for offset in range(16):
 for field,value in [(0x14,PREV+0x100),(0x18,GEO+0x100),(0x24,ALLOC+0x100)]:
  c=seed(offset,offset&1,offset);c['mutations']=[word(O+field,value)];cases.append(c)
for offset in range(16):
 c=seed(7,0,offset);c['writes'] += [word(C+4,ALLOC+0x100+offset)];c['mutations']=[word(0x9736e0,C+4)];cases.append(c)
# Cached owner survives material root changes inside preparation.
for offset in range(16):
 c=seed(7,0,offset);c['mutations']=[word(M+0x3c,O+0x100)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expectedTrace=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 current=c;trace=[];n.call(0x607cb0,[c['packet']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entryCounts=entries,binarySha256=n.sha256,nativeAdapters=['607590 owner preparation mutable image port'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase77-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase77-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
