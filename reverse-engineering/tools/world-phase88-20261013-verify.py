import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297ae20,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

ENTER=0x10300000;EXIT=ENTER+0x100
n.mu.mem_map(ENTER,0x1000);n.write(ENTER,b'\xc3');n.write(EXIT,b'\xc3');n.write(0x7510b8,struct.pack('<I',ENTER));n.write(0x7510b4,struct.pack('<I',EXIT));trace=[];case={}
def apply(im,c):
 trace=[];token=c['token']
 if U(token-1)<=11:
  trace.append([0x7510b8 if c['entry']==0x4ffaa0 else 0x7510b4,[U(0x91ef70+token*24)]])
  for p in c.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 return trace
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
def observe(uc,a,z,user):
 if a in [0x4ffaa0,0x4ffac0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [ENTER,EXIT]:return
 sp=uc.reg_read(UC_X86_REG_ESP);trace.append([0x7510b8 if a==ENTER else 0x7510b4,list(n.unpack('<I',sp+4))])
 for p in case.get('mutations',[]):n.write(p['address'],base64.b64decode(p['data']))
 uc.reg_write(UC_X86_REG_EAX,0xdeadbeef);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+8)
n.mu.hook_add(UC_HOOK_CODE,observe)
rng=random.Random(2026101388);cases=[]
for e in [0x4ffaa0,0x4ffac0]:
 for token in list(range(32))+[0x7fffffff,0x80000000,0xffffffff]+[rng.getrandbits(32) for i in range(256)]:cases.append(dict(entry=e,token=token,writes=[],mutations=[word(0x297ae20,0xffffffff),word(D+0x1000,token)]))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;im=Image(c);pred=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 trace=[];n.call(c['entry'],[c['token']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=pred:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=pred));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['import7510b8 EnterCriticalSection and7510b4 LeaveCriticalSection onlyvalidtoken1..12'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase88-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase88-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
