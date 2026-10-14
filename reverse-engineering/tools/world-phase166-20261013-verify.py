import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x751000,0x300,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

BASE=0x10300000;MODULE=BASE;PROC=BASE+0x100;MANAGED=BASE+0x200;EXIT=BASE+0x300;EXIT2=BASE+0x400;MODULE2=BASE+0x500;PROC2=BASE+0x600;n.mu.mem_map(BASE,0x1000)
for a in [MODULE,PROC,MANAGED,EXIT,EXIT2,MODULE2,PROC2]:n.write(a,b'\xc3')
trace=[];case={};terminal=0;nativeMode=False;entries={}
class Stop(Exception):pass
def service(im,address,args):
 global terminal
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 if address in [MODULE,MODULE2]:return case['module']
 if address in [PROC,PROC2]:return case['procedure']
 if address in [EXIT,EXIT2] or (address==MANAGED and case['managedTerminal']):
  terminal=address
  if not nativeMode:raise Stop()
 return case['endpoint']
def bridge(im,code):
 module=service(im,im.W(0x751154),[0x777e30])
 if not module:return
 target=service(im,im.W(0x7511b0),[module,0x777e20])
 if target:service(im,target,[code])
def apply(im,c):
 bridge(im,c['args'][0])
 if c['entry']==0x6ebde3:service(im,im.W(0x7511b4),c['args'])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address in [0x6ebde3,0x6ebdbd]:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [MODULE,PROC,MANAGED,EXIT,EXIT2,MODULE2,PROC2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=2 if address in [PROC,PROC2] else 1;args=list(n.unpack('<'+'I'*count,sp+4));value=service(ni,address,args)
 if terminal:uc.reg_write(UC_X86_REG_EIP,n.STOP);return
 uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4+count*4);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013166);cases=[]
def seed(entry,code,module=1,proc=MANAGED,terminating=False):return dict(entry=entry,args=[code],module=module,procedure=proc,managedTerminal=terminating,endpoint=0xfedcba98,writes=[word(0x751154,MODULE),word(0x7511b0,PROC),word(0x7511b4,EXIT)])
for entry in [0x6ebdbd,0x6ebde3]:
 for i in range(512):
  c=seed(entry,rng.choice([0,1,255,0xffffffff,rng.getrandbits(32)]),rng.choice([0,1,0xffffffff]),rng.choice([0,MANAGED]),bool(i&1))
  if i%3==0:c['serviceWrites']={hex(MODULE):[word(0x7511b0,PROC2)],hex(PROC2):[word(0x7511b4,EXIT2)]}
  if i%5==0:c.setdefault('serviceWrites',{})[hex(MANAGED)]=[word(0x7511b4,EXIT2),word(D+0x100,0xabcdef01)]
  cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];terminal=0;nativeMode=False;im=Image(c)
 try:apply(im,c)
 except Stop:pass
 expectedTrace=trace[:];expectedTerminal=terminal;trace=[];terminal=0;nativeMode=True;initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 n.call(c['entry'],c['args'],count=100000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace or terminal!=expectedTerminal:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTerminal=terminal,modelTerminal=expectedTerminal,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(terminal=terminal,trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase166-20261013-ptl-runtime-exit.cs').read_bytes()).hexdigest(),originalBodies=[dict(address=hex(a),length=z,sha256=hashlib.sha256(n.read(a,z)).hexdigest()) for a,z in [(0x6ebdbd,38),(0x6ebde3,20)]],domain='optional managed-runtime exit resolution then fresh physical ExitProcess IAT reload; present/missing module/procedure, signed bit-pattern exit values, callback IAT/public-memory mutations; native emulation stops at terminating import entry, managed bridge may return or suspend, wrapper INT3 fallback and actual process termination excluded; void incidental EAX and caller-stack alias exposure excluded',nativeAdapters=['GetModuleHandleA/GetProcAddress','managed-runtime exit endpoint','ExitProcess terminal suspension'],reaEvidenceIds=['ev_cbe64c9b61c56b4fc3b6ec3cb08cc6ff66ef84975364c9f7e033f1ddf0f65525','ev_690aaf639c85916f1635974c6dcb25663fdba8aee12b8cb1204e97344593b47d'],managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase166-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase166-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
