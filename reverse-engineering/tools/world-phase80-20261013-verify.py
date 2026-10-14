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

R=D+0x1000;C=D+0x2000;ARENA=D+0x4000;PREV=D+0x8000;GEO=D+0x9000
def apply(im,c):
 r=c['record'];control=im.W(0x9736e0);im.W(control,(im.W(control)+15)&0xfffffff0);control=im.W(0x9736e0);prev=im.W(r+0x14);command=im.W(control);im.W(prev+4,command);im.B(im.W(control),c['type']&255);im.B(im.W(control)+1,3);command=im.W(control);im.W(command+4,c['payload'] if c['payload'] else command+32);im.B(im.W(control)+16,0x8d);im.B(im.W(control)+17,1);geo=im.W(r+0x18);command=im.W(control);im.W(command+20,U(geo+16));im.W(r+0x14,U(im.W(control)+16));im.W(control,U(im.W(control)+32));return control if not c['payload'] else 0
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a==0x6034b0:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(typ=0,payload=0,offset=0):return dict(record=R,type=typ,payload=payload,writes=[word(0x9736e0,C),word(C,ARENA+offset),word(R+0x14,PREV),word(R+0x18,GEO)])
cases=[]
for typ in range(256):
 for payload in [0,GEO]:
  for offset in [0,15]:cases.append(seed(typ,payload,offset))
for offset in range(16):
 for payload in [0,GEO]:
  c=seed(0x1ab,payload,offset);c['writes'] += [word(R+0x14,C-4)];cases.append(c)
for offset in range(16):
 c=seed(0x94,GEO,offset);c['record']=C-0x14;c['writes'] += [word(C+4,GEO)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);pred=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6034b0,[c['record'],c['type'],c['payload']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=pred or actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=pred));break
 c['expected']=dict(result=rv,sha256=actual);rows.append(c)
report=dict(status='sealed qualified raw refinement' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase80-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase80-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
