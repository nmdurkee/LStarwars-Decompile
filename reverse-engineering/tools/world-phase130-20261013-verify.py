import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x751000,0x200,0),(0x297cb3c,4,0),(0x297c1b0,0x20,0),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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


MODULE=0x10300000;PROC=MODULE+0x100;INIT=MODULE+0x200;BASIC=MODULE+0x300;ALT=MODULE+0x400;n.mu.mem_map(MODULE,0x1000)
for a in [MODULE,PROC,INIT,BASIC,ALT]:n.write(a,b'\xc3')
P=D+0x1000;ERR=D+0xf000;trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['decoded'] if a==0x6f01bc else case['encoded'] if a==0x6f0145 else case['module'] if a==MODULE else case['procedure'] if a in [PROC,ALT] else ERR if a==0x6ead5f else case['endpoint']
def invalid(im):
 p=service(im,0x6ead5f,[]);im.W(p,22);service(im,0x6e9fc2,[0]*5);return 22
def platform(im,output):
 if not output or not im.W(0x297c1b4):return invalid(im)
 im.W(output,im.W(0x297c1b4));return 0
def fallback(im,p,spin):service(im,im.W(0x7510d0),[p]);return 1
def apply(im,c):
 if c['entry']=='platform':return platform(im,c['args'][0])
 if c['entry']=='fallback':return fallback(im,*c['args'])
 target=service(im,0x6f01bc,[im.W(0x297cb3c)])
 if not target:
  value=im.W(0x297c1b4)
  if not value:invalid(im);service(im,0x6e9e8e,[0]*5)
  if value!=1:
   module=service(im,im.W(0x751154),[0x77ef2c])
   if module:target=service(im,im.W(0x7511b0),[module,0x77ef04])
  if not target:target=0x6fd023
  im.W(0x297cb3c,service(im,0x6f0145,[target]))
 return fallback(im,*c['args']) if target==0x6fd023 else service(im,target,c['args'])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6fd033,0x6fd023,0x6ebe42,0x6f0954,0x6f0999]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [MODULE,PROC,INIT,BASIC,ALT,0x6f01bc,0x6f0145,0x6ead5f,0x6e9fc2,0x6e9e8e]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a==0x6ead5f else 5 if a in [0x6e9fc2,0x6e9e8e] else 2 if a in [PROC,ALT,INIT] else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);cleanup=4+count*4 if a in [MODULE,PROC,INIT,BASIC,ALT] else 4;uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013130);cases=[]
def seed(entry='initialize',decoded=0,platform=2,module=1,procedure=INIT):return dict(entry=entry,args=[P,4000] if entry!='platform' else [P],decoded=decoded,module=module,procedure=procedure,encoded=0x13579bdf,endpoint=0xfedcba98,writes=[word(0x751154,MODULE),word(0x7511b0,PROC),word(0x7510d0,BASIC),word(0x297cb3c,0x12345678),word(0x297c1b4,platform),word(0,0xffffffff)])
for decoded in [0,INIT,0x6fd023]:
 for plat in [0,1,2,0xffffffff]:
  for module in [0,1]:
   for proc in [0,INIT]:cases.append(seed(decoded=decoded,platform=plat,module=module,procedure=proc))
for i in range(256):
 c=seed(decoded=rng.choice([0,INIT,0x6fd023]),platform=rng.choice([0,1,2,rng.getrandbits(32)]),module=rng.choice([0,1]),procedure=rng.choice([0,INIT]));c.update(encoded=rng.getrandbits(32),endpoint=rng.getrandbits(32));c['args']=[rng.getrandbits(32),rng.getrandbits(32)];cases.append(c)
for address in [0x6f01bc,0x6f0145,MODULE,PROC,0x6ead5f,0x6e9fc2,0x6e9e8e]:
 for at,value in [(0x297cb3c,0),(0x297c1b4,1),(0x7511b0,ALT),(0x7510d0,BASIC),(ERR,0xffffffff)]:
  c=seed(platform=0);c['serviceWrites']={hex(address):[word(at,value)]};cases.append(c)
for output in [0,P,0x297c1b4,0x297cb3c]:
 for plat in [0,1,2,0xffffffff]:
  c=seed('platform',platform=plat);c['args']=[output];cases.append(c)
for i in range(64):
 c=seed('fallback');c['args']=[rng.getrandbits(32),rng.getrandbits(32)];c['endpoint']=rng.getrandbits(32);cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call({'initialize':0x6fd033,'fallback':0x6fd023,'platform':0x6ebe42}[c['entry']],c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=dict(initialize=hashlib.sha256(n.read(0x6fd033,59)+n.read(0x6fd071,72)+n.read(0x6fd0e8,16)).hexdigest(),fallback=hashlib.sha256(n.read(0x6fd023,16)).hexdigest(),platform=hashlib.sha256(n.read(0x6ebe42,55)).hexdigest()),domain='normal no-exception prepared resolver/IAT cells; original platform getter private output as value; cached resolved target survives encoder mutation; invalid parameter/Watson children returning suspension only',nativeAdapters=['DecodePointer/EncodePointer children','module/procedure and critical-section Win32 endpoints','errno/invalid parameter and Watson returning projection'],syntheticExcluded=0,exceptionPathsRecovered=False,reaEvidenceIds=["ev_2d929b02d0ec95a2d7911e0278d90dedd71f935ac8e6ca8facc11eee70cd0e6b","ev_ddadd08e2ca7001983d7d7c6e9276c36b0f662984d178cfade00aa8f13df0631","ev_e97da604485491a123b55a80bcc26f6f4cb397f15885748f86e1e939bd187972"],seconds=round(time.time()-start,3))
(B/'reports/world-phase130-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase130-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
