import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x750f00,0x300,0),(0x82a000,0xa00,167),(0,4,0),(0x297c1b0,0x20,0),(0x777fc0,8,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

if not any(begin<=0<=end for begin,end,_ in n.mu.mem_regions()):n.mu.mem_map(0,0x1000)
MODULE=0x10300000;PROC_A=MODULE+0x100;PROC_B=MODULE+0x200;ATOMIC=MODULE+0x300
n.mu.mem_map(MODULE,0x1000)
for a in [MODULE,PROC_A,PROC_B,ATOMIC]:n.write(a,b'\xc3')
trace=[];case={};counts={}
def service(im,address,args):
 key=hex(address);index=counts.get(key,0);counts[key]=index+1;trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 sequence=case.get('sequenceWrites',{}).get(key,[])
 if index<len(sequence):
  for p in sequence[index]:im.write(p['address'],base64.b64decode(p['data']))
 if address==MODULE:return case['module']
 if address==0x6ead5f:return D+0xf000
 if address in [PROC_A,PROC_B]:return case['encode'] if args[1]==0x777fc8 else case['decode']
 if address==ATOMIC:im.W(args[0],U(im.W(args[0])+1));return im.W(args[0])
 if address==0x6f179a:return case['unlockResult']
 return 0
# The thunk returns the unlock endpoint's EAX unchanged.
def unlock(im):return service(im,0x6f179a,[12])
def apply(im,c):
 if c['entry']=='unlock':return unlock(im)
 record,locale=c['args'];module=service(im,im.W(0x751154),[0x777fd8]);im.W(record+0x5c,0x829b78);im.W(record+0x14,1)
 if module and capability(im,dict(entry='supported',args=[])):
  proc=im.W(0x7511b0);im.W(record+0x1f8,service(im,proc,[module,0x777fc8]));im.W(record+0x1fc,service(im,proc,[module,0x777fe8]))
 im.W(record+0x70,1);im.B(record+0xc8,0x43);im.B(record+0x14b,0x43);im.W(record+0x68,0x82a070);service(im,im.W(0x7511cc),[0x82a070]);service(im,0x6f188a,[12]);im.W(record+0x6c,locale)
 if not locale:im.W(record+0x6c,im.W(0x82a678))
 addrefs(im,dict(args=[im.W(record+0x6c)]));return unlock(im)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
ni=NI();entries={}
def observe(uc,a,z,user):
 if a in [0x6f02d6,0x6f038c,0x6f0954,0x6f0999,0x6f00d9,0x6ebef1,0x6f4bc0,0x6facb1]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [MODULE,PROC_A,PROC_B,ATOMIC,0x6f188a,0x6f179a,0x6ead5f,0x6e9fc2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=2 if a in [PROC_A,PROC_B] else 0 if a==0x6ead5f else 5 if a==0x6e9fc2 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);cleanup=4+count*4 if a in [MODULE,PROC_A,PROC_B,ATOMIC] else 4;uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
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
def capability(im,c):
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
def addrefs(im,c):
 locale=c['args'][0];target=im.W(0x7511cc);service(im,target,[locale])
 for offset in [0xb0,0xb8,0xb4,0xc0]:
  p=im.W(locale+offset)
  if p:service(im,target,[p])
 row=locale+0x50
 for i in range(6):
  if im.W(row-8)!=0x82a598:
   p=im.W(row)
   if p:service(im,target,[p])
  if im.W(row-4):
   p=im.W(row+4)
   if p:service(im,target,[p])
  row+=16
 return service(im,target,[U(im.W(locale+0xd4)+0xb4)])

P=D+0x1000;L=D+0x3000;MOD=D+0x9000;rng=random.Random(20261013125);cases=[]
def seed(locale=0,version=5,hastext=False):
 writes=[patch(P,bytes([167])*0x214),word(0x751154,MODULE),word(0x7511b0,PROC_A),word(0x7511cc,ATOMIC),word(0x82a070,0xffffffff),word(0x82a678,L),word(0,0xffffffff),word(0x297c1b4,1),word(0x297c1c0,version),patch(0x777fc0,b'.text\0\0\0'),word(MOD+0x3c,0x100),half(MOD+0x106,2),half(MOD+0x114,0x80),patch(MOD+0x198,b'.text\0\0\0' if hastext else b'.data\0\0\0'),patch(MOD+0x1c0,b'.rsrc\0\0\0')]
 for loc in [L,L+0x1000]:
  writes+=[patch(loc,bytes(0x100)),word(loc+0xd4,D+0x6000)]
  for off in [0xb0,0xb8,0xb4,0xc0]:writes.append(word(loc+off,D+0x6000+off))
  for j in range(6):
   row=loc+0x50+16*j;writes.extend([word(row-8,0),word(row-4,1),word(row,D+0x7000+8*j),word(row+4,D+0x7004+8*j)])
 return dict(entry='initialize',args=[P,locale],module=MOD,encode=0x11223344,decode=0x55667788,unlockResult=0xfedcba98,writes=writes)
for locale in [0,L,L+0x1000]:
 for version in [0,5,6,0x7fffffff,0x80000000,0xffffffff]:
  for hastext in [False,True]:
   for valid in [0,1]:
    c=seed(locale,version,hastext);c['writes']+=[word(0x297c1b4,valid)];cases.append(c)
for i in range(256):
 c=seed(rng.choice([0,L,L+0x1000]),rng.choice([0,5,6,0xffffffff]),bool(i%3));c.update(encode=rng.getrandbits(32),decode=rng.getrandbits(32),unlockResult=rng.getrandbits(32));cases.append(c)
for address in [MODULE,PROC_A,ATOMIC,0x6f188a,0x6f179a]:
 for at,value in [(0x7511b0,PROC_B),(0x82a678,L+0x1000),(P+0x6c,L+0x1000),(0x297c1c0,6),(L+0xb8,0),(0x7511cc,ATOMIC),(0x82a070,0xfffffffe)]:
  c=seed();c['serviceWrites']={hex(address):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f02d6,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,domain='actual initializer, version PE section search, major getter, strcmp and locale addref in prepared readable default/explicit locale and no-exception execution; normal original SEH frame',nativeAdapters=['Win32 module/procedure/interlocked endpoints','CRT lock/unlock and errno/invalid parameter children'],syntheticExcluded=0,additionalAddressCredit=0,reaEvidenceIds=["ev_365edae6c7939dd54baff510ba42db7d317e3c4d7745f2b9f60d06853cf4e5a8","ev_e9f058f21c20dcafd36307d441261cd849d9208cb374202d959fba027a14cce7","ev_5d4bee0a2286043f5a857755f65ca9ec72c77de9c737b4d28c14fff0e4112915","ev_90edd229cd47a87af512037bb1326feb076c2c8678ae42d3b08530e79237e9dc"],seconds=round(time.time()-start,3))
(B/'reports/world-phase125-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase125-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
