import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x751100,0x100,0),(0x297c1b0,0x20,0),(0x777fc0,8,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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


MODULE=0x10300000;n.mu.mem_map(MODULE,0x1000);n.write(MODULE,b'\xc3');P=D+0x1000;L=D+0x2000;R=D+0x3000;ERR=D+0x8000
trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['module'] if a==MODULE else ERR if a==0x6ead5f else 0
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def invalid(im):
 error=service(im,0x6ead5f,[]);im.W(error,22);service(im,0x6e9fc2,[0]*5);return 22
def compare(im,left,right):
 if left&1:
  a=im.B(left);b=im.B(right);left+=1;right+=1
  if a!=b:return 0xffffffff if a<b else 1
  if not a:return 0
 if left&2:
  pair=im.H(left);left+=2
  for i in range(2):
   a=(pair>>(8*i))&255;b=im.B(right+i)
   if a!=b:return 0xffffffff if a<b else 1
   if not a:return 0
  right+=2
 while True:
  value=im.W(left)
  for i in range(4):
   a=(value>>(8*i))&255;b=im.B(right+i)
   if a!=b:return 0xffffffff if a<b else 1
   if not a:return 0
  left+=4;right+=4
def apply(im,c):
 if c['entry']=='compare':return compare(im,*c['args'])
 if c['entry']=='major':
  out=c['args'][0]
  if not out or not im.W(0x297c1b4):return invalid(im)
  im.W(out,im.W(0x297c1c0));return 0
 major=im.W(0x297c1c0) if im.W(0x297c1b4) else 0
 if not im.W(0x297c1b4):invalid(im)
 if S(major)>5:return 1
 module=service(im,im.W(0x751154),[0]);header=U(module+im.W(module+0x3c));section=U(header+0x18+im.H(header+0x14));index=0
 if not im.H(header+6):return 1
 while True:
  if compare(im,0x777fc0,section)==0:return 0
  index+=1;section=U(section+40)
  if index>=im.H(header+6):return 1
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
def observe(uc,a,z,user):
 if a in [0x6f00d9,0x6ebef1,0x6f4bc0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [MODULE,0x6ead5f,0x6e9fc2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=1 if a==MODULE else 5 if a==0x6e9fc2 else 0;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(4 if a==MODULE else 0))
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013123);cases=[]
def seed(entry='supported',args=[]):return dict(entry=entry,args=args,module=P,writes=[word(0x751154,MODULE),word(0x297c1b4,1),word(0x297c1c0,5),patch(0x777fc0,b'.text\0\0\0'),word(P+0x3c,0x100),half(P+0x106,3),half(P+0x114,0x80),patch(P+0x198,b'.data\0\0\0'),patch(P+0x1c0,b'.text\0\0\0'),patch(P+0x1e8,b'.rsrc\0\0\0')])
for valid in [0,1,0xffffffff]:
 for major in [0,1,5,6,0x7fffffff,0x80000000,0xffffffff]:
  for count in [0,1,2,3]:
   c=seed();c['writes']+=[word(0x297c1b4,valid),word(0x297c1c0,major),half(P+0x106,count)];cases.append(c)
for out in [0,L,0x297c1b4,0x297c1c0]:
 for valid in [0,1]:
  c=seed('major',[out]);c['writes']+=[word(0x297c1b4,valid)];cases.append(c)
for a in [0x6ead5f,0x6e9fc2,MODULE]:
 for at,value in [(0x297c1b4,1),(0x297c1c0,6),(P+0x106,0),(P+0x114,0x90)]:
  c=seed();c['writes']+=[word(0x297c1b4,0)];c['serviceWrites']={hex(a):[word(at,value)]};cases.append(c)
for i in range(768):
 length=rng.randrange(0,80);a=bytes(rng.randrange(1,256) for _ in range(length));b=bytearray(a)
 if i%3 and length:b[rng.randrange(length)]=rng.randrange(1,256)
 if i%7==0:b.extend(b'x')
 left=L+(i%4);right=R+((i//4)%4);c=seed('compare',[left,right]);c['writes']+=[patch(left,a+b'\0'+bytes(8)),patch(right,bytes(b)+b'\0'+bytes(8))];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call({'supported':0x6f00d9,'major':0x6ebef1,'compare':0x6f4bc0}[c['entry']],c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=dict(capability=hashlib.sha256(n.read(0x6f00d9,108)).hexdigest(),major=hashlib.sha256(n.read(0x6ebef1,60)).hexdigest(),compare=hashlib.sha256(n.read(0x6f4bc0,67)+n.read(0x6f4c04,68)).hexdigest()),binarySha256=n.sha256,domain='readable finite PE section headers and padded NUL terminated byte strings; private stack output represented as a value; invalid parameter handler returning projection',nativeAdapters=['GetModuleHandleA','errno and invalid parameter children'],syntheticExcluded=0,reaEvidenceIds=["ev_365edae6c7939dd54baff510ba42db7d317e3c4d7745f2b9f60d06853cf4e5a8","ev_e9f058f21c20dcafd36307d441261cd849d9208cb374202d959fba027a14cce7","ev_5d4bee0a2286043f5a857755f65ca9ec72c77de9c737b4d28c14fff0e4112915"],seconds=round(time.time()-start,3))
(B/'reports/world-phase123-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase123-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
