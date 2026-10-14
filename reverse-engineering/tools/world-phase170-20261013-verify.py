import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x829a68,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

EXIT=0x10300000;EXIT2=EXIT+0x100;n.mu.mem_map(EXIT,0x1000);n.write(EXIT,b'\xc3');n.write(EXIT2,b'\xc3');trace=[];case={};entries={};terminal=0;nativeMode=False
class Stop(Exception):pass
def service(im,address,args):
 global terminal
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 if address==0x6f01bc:return args[0]^case['cookie']
 if address in [EXIT,EXIT2] and case['terminal']:
  terminal=address
  if not nativeMode:raise Stop()
 return case['endpoint']
def apply(im,c):
 service(im,0x6f0bb8,[]);service(im,0x6f09f8,c['args']);target=service(im,0x6f01bc,[im.W(0x829a68)]);service(im,target,[255])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address==0x6ebd99:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [0x6f0bb8,0x6f09f8,0x6f01bc,EXIT,EXIT2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if address==0x6f0bb8 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];value=service(ni,address,args)
 if terminal:uc.reg_write(UC_X86_REG_EIP,n.STOP);return
 uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013170);cases=[]
for i in range(1024):
 cookie=rng.choice([0,0x55aa55aa,0xffffffff]);c=dict(args=[rng.choice([0,2,16,17,30,255,rng.getrandbits(32)])],cookie=cookie,terminal=bool(i&1),endpoint=rng.getrandbits(32),writes=[word(0x829a68,EXIT^cookie)])
 if i%3==0:c['serviceWrites']={'0x6f0bb8':[word(0x829a68,EXIT2^cookie)],'0x6f09f8':[word(D+0x100,0xabcdef01)]}
 if i%5==0:c.setdefault('serviceWrites',{})['0x6f01bc']=[word(0x829a68,EXIT^cookie),word(D+0x108,0x12345678)]
 cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];terminal=0;nativeMode=False;im=Image(c)
 try:apply(im,c)
 except Stop:pass
 expectedTrace=trace[:];expectedTerminal=terminal;trace=[];terminal=0;nativeMode=True;initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 n.call(0x6ebd99,c['args'],count=100000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace or terminal!=expectedTerminal:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTerminal=terminal,modelTerminal=expectedTerminal,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(terminal=terminal,trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase170-20261013-ptl-runtime-fatal-message.cs').read_bytes()).hexdigest(),originalBodySha256=hashlib.sha256(n.read(0x6ebd99,36)).hexdigest(),domain='complete fatal-message own body, banner then specific message then fresh encoded handler read/decode and cached physical exit target; full signed code bit patterns, public callback mutations, returning or terminal cdecl exit handler projections; void EAX and private caller-stack aliases excluded',nativeAdapters=['banner/writer/decoder value ports','cdecl exit handler returning or terminal suspension'],reaEvidenceIds=['ev_9447d7218f1e90d947224e5957a4c21e6a02852be3490007e43edd8af678f34f'],managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase170-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase170-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
