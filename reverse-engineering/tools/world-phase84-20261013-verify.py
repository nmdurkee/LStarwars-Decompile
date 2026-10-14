import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297bea0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

ALLOCATOR=D+0x1000;TABLE=D+0x2000;OUTPUT=D+0x3000;TARGET=0x10300000
n.mu.mem_map(TARGET,0x1000);n.write(TARGET,b'\xc3')
def apply(im,c):
 first,second,out,flags,allocator=c['args'];target=im.W(im.W(allocator)+0x2c);trace=[[target,[allocator,first,second,out,flags]]]
 for p in c.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 im.W(0x297bea0,c['result']);return trace
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={};trace=[];current={}
def observe(uc,a,z,user):
 if a==0x6e5b90:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=TARGET:return
 sp=uc.reg_read(UC_X86_REG_ESP);trace.append([a,list(n.unpack('<5I',sp+4))])
 for p in current.get('mutations',[]):n.write(p['address'],base64.b64decode(p['data']))
 uc.reg_write(UC_X86_REG_EAX,current['result']);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+24)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(result=0):return dict(args=[0,8192,OUTPUT,0x2000,ALLOCATOR],result=result,writes=[word(ALLOCATOR,TABLE),word(TABLE+0x2c,TARGET)])
choices=[0,1,0xffffffff,0x80000000,0x7fffffff,0xdeadbeef];cases=[];rng=random.Random(2026101384)
for field in range(4):
 for value in choices:
  c=seed(value);c['args'][field]=value;cases.append(c)
for i in range(384):
 c=seed(rng.getrandbits(32));c['args'][:4]=[rng.getrandbits(32) for j in range(4)];cases.append(c)
for result in choices:
 for at in [ALLOCATOR,TABLE+0x2c,0x297bea0,OUTPUT]:
  c=seed(result);c['mutations']=[word(at,0x12345678)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 current=c;trace=[];rv=n.call(0x6e5b90,c['args']);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=c['result'] or actual!=im.hash() or trace!=expected:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=c['result'],nativeTrace=trace,modelTrace=expected));break
 c['expected']=dict(result=rv,sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['allocatorvtable+2c stdcall value/mutation port'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase84-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase84-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
