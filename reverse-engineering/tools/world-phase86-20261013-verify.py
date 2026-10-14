import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297cc6c,4,0),(0x297ae20,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

RECEIVER=D+0x1000;PROGRAM=D+0x3000;trace=[];case={}
def port(im,address,args):
 trace.append([address,args])
 for p in case.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['result']
def invoke(im,address,args):
 if address==0x741620:return U(im.W(0x297cc6c)+args[0]*0x4d8+4) if args[0]<=400 else 0
 if address==0x7415b0:im.W(args[0]+4,U(im.W(args[0]+4)-1));return args[0]
 if address in [0x6e27d0,0x6e27f0]:return (16 if address==0x6e27d0 else 1) if im.B(args[0]+0x654)&32 else 0
 if address in [0x741770,0x741790]:return port(im,0x7416a0,[im.W(0x297cc6c),args[0],args[1],args[2] if address==0x741790 else 0,0,0])
 port(im,0x4ffaa0 if address==0x6df300 else 0x4ffac0,[im.W(0x297ae20)]);return None
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
entries={}
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x741620,0x7415b0,0x6e27d0,0x6e27f0,0x741770,0x741790,0x6df300,0x6df310]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x7416a0,0x4ffaa0,0x4ffac0]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<5I',sp+4)) if a==0x7416a0 else list(n.unpack('<I',sp+4));rv=port(ni,a,args);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+(24 if a==0x7416a0 else 4))
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e,args):return dict(entry=e,args=args,result=0x12345678,writes=[word(0x297cc6c,0xabcdef01),word(0x297ae20,0x12345678)])
cases=[];rng=random.Random(2026101386)
for manager in [0,0xfffffff0,0x10100000]:
 for index in list(range(402))+[0x7fffffff,0x80000000,0xffffffff]:
  c=seed(0x741620,[index]);c['writes'] += [word(0x297cc6c,manager)];cases.append(c)
for e in [0x6e27d0,0x6e27f0]:
 for flags in range(256):c=seed(e,[RECEIVER]);c['writes'] += [byte(RECEIVER+0x654,flags)];cases.append(c)
for value in [0,1,0xffffffff,0x80000000]+[rng.getrandbits(32) for i in range(128)]:c=seed(0x7415b0,[PROGRAM]);c['writes'] += [word(PROGRAM+4,value)];cases.append(c)
for e in [0x741770,0x741790,0x6df300,0x6df310]:
 for i in range(128):
  c=seed(e,[rng.getrandbits(32),rng.getrandbits(32)]+([rng.getrandbits(32)] if e==0x741790 else []) if e in [0x741770,0x741790] else []);c['result']=rng.getrandbits(32);c['mutations']=[word(0x297cc6c,rng.getrandbits(32)),word(0x297ae20,rng.getrandbits(32))];cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);pred=invoke(im,c['entry'],c['args']);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(c['entry'],regs={UC_X86_REG_ECX:c['args'][0]}) if c['entry'] in [0x6e27d0,0x6e27f0] else n.call(c['entry'],c['args']);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();checks+=2+(pred is not None)
 if actual!=im.hash() or pred is not None and pred!=rv or trace!=expectedTrace:errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash(),nativeResult=rv,modelResult=pred,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(result=pred,sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['7416a0 thiscallfactory with fivecallee-cleanedargs','4ffaa0/4ffac0 lockchild'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase86-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase86-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
