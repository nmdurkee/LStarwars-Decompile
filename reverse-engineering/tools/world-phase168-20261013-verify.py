import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297c1b4,16,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

trace=[];case={};entries={}
def service(im,address,args):
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['errnoPointer'] if address==0x6ead5f else case['endpoint']

def apply(im,c):
 output=c['args'][0]
 if not output or not im.W(0x297c1b4):
  im.W(service(im,0x6ead5f,[]),22);service(im,0x6e9fc2,[0]*5);return 22
 im.W(output,im.W(0x297c1b8 if c['entry']==0x6ebe79 else 0x297c1bc));return 0
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address in [0x6ebe79,0x6ebeb5]:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [0x6ead5f,0x6e9fc2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if address==0x6ead5f else 5;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];value=service(ni,address,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013168);cases=[]
for entry in [0x6ebe79,0x6ebeb5]:
 for i in range(768):
  output=rng.choice([0,D+0x200,0x297c1b4,0x297c1b8,0x297c1bc,0x297c1c0]);c=dict(entry=entry,args=[output],errnoPointer=rng.choice([D+0x100,0x297c1b4,0x297c1b8,0x297c1bc]),endpoint=rng.getrandbits(32),writes=[word(0x297c1b4,rng.choice([0,1,2,0xffffffff])),word(0x297c1b8,rng.getrandbits(32)),word(0x297c1bc,rng.getrandbits(32)),word(0x297c1c0,rng.getrandbits(32)),word(D+0x100,0xabcdef01)])
  if i%3==0:c['serviceWrites']={'0x6ead5f':[word(0x297c1b4,2)],'0x6e9fc2':[word(D+0x108,0x12345678)]}
  cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 result=n.call(c['entry'],c['args'],count=100000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if result!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=result,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(result=result,trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase168-20261013-ptl-runtime-version-fields.cs').read_bytes()).hexdigest(),originalBodies=[dict(address=hex(a),length=60,sha256=hashlib.sha256(n.read(a,60)).hexdigest()) for a in [0x6ebe79,0x6ebeb5]],domain='raw complete minor/build field getters with null-output and version-valid validation; readable raw output/errno aliases to each version global, cached errno pointer and callback mutations; invalid dispatcher returning projection',nativeAdapters=['6ead5f errno pointer','6e9fc2 returning invalid dispatcher'],reaEvidenceIds=[],rawBodyEvidence='focused REA FunctionManager requests2276/2277 did not expose raw getter entries; exact original PE bytes and native entry execution supply the evidence, no live manager classification claimed',managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase168-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase168-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
