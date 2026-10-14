import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x2854ce0,0x80,0),(0x2854b80,0x40,0),(0x280d3c0,0x40,0),(0x297bea0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

ALLOC=D+0x1000;VTABLE=D+0x2000;BUFFER=D+0x3000;TARGET=0x10300000
n.mu.mem_map(TARGET,0x1000);n.write(TARGET,b'\xc3');trace=[];case={};RELEASE_TARGET=TARGET+0x100;n.write(RELEASE_TARGET,b'\xc3')
def service(im,address,args):
 if address==0x6e5bc0:return service(im,im.W(im.W(args[0])+0x30),args)
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 if address==RELEASE_TARGET:return case['releaseResult']
 if address==TARGET:
  if case['allocateWrites']:im.W(args[3],case['buffer'])
  return case['result']
 return 0
alloc=model=None
# Original6e5b90 executes; its portable raw wrapper supplies only the dynamic allocator endpoint.
def allocate(im,args):
 first,second,output,flags,allocator=args;target=im.W(im.W(allocator)+0x2c);value=service(im,target,[allocator,first,second,output,flags]);im.W(0x297bea0,value);return value
def apply(im):
 mode=im.W(0x2854cec)
 if mode==0 and im.W(0x2854d00):service(im,0x6e5bc0,[im.W(U(0x280d3cc+im.W(0x2854cf0)*4))]);mode=im.W(0x2854cec)
 nxt=U(im.W(0x2854cf0)+1)
 if mode:
  if nxt>=8:service(im,0x5f7490,[]);return 0
  nxt&=7
 elif nxt>=4:mode=1;nxt=0;im.W(0x2854cec,1)
 else:nxt&=3
 im.W(0x2854cf0,nxt);im.W(0x2854cf4,0)
 if mode:im.W(0x2854d00,im.W(0x2854b8c+nxt*4));return 1
 selected=im.W(0x280d3cc+nxt*4);size=im.W(0x2854cf8);allocate(im,[0,size,0x2854d00,0x2000,selected]);return 1
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.write(a,struct.pack('<I',U(v)))
ni=NI();entries={}
def observe(uc,a,z,user):
 if a in [0x5ffc80,0x6e5b90,0x6e5bc0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [RELEASE_TARGET,0x5f7490,TARGET]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<5I' if a==TARGET else '<I',sp+4)) if a!=0x5f7490 else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+(24 if a==TARGET else 8 if a==RELEASE_TARGET else 4))
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(mode=0,current=0,live=BUFFER):
 c=dict(buffer=BUFFER,result=0,allocateWrites=True,writes=[word(0x2854cec,mode),word(0x2854cf0,current),word(0x2854cf4,77),word(0x2854cf8,8192),word(0x2854d00,live),word(ALLOC,VTABLE),word(VTABLE+0x2c,TARGET)])
 for i in range(-3,10):c['writes'] += [word(0x280d3cc+i*4,ALLOC),word(0x2854b8c+i*4,BUFFER+i*0x100)]
 return c
cases=[];rng=random.Random(20261013109)
for mode in [0,1,2,0xffffffff]:
 for current in [0,1,2,3,4,5,6,7,8,9,0xfffffffe,0xffffffff]:
  for live in [0,BUFFER]:cases.append(seed(mode,current,live))
for i in range(256):
 c=seed(rng.choice([0,1]),rng.randrange(8),rng.choice([0,BUFFER]));c['result']=rng.getrandbits(32);c['allocateWrites']=bool(i%2);c['writes'] += [word(0x2854cf8,rng.getrandbits(32))];cases.append(c)
for address in [0x6e5bc0,TARGET,0x5f7490]:
 for field in [0x2854cec,0x2854cf0,0x2854cf4,0x2854cf8,0x2854d00,0x297bea0]:
  for value in [0,1,3,7,0xffffffff]:
   c=seed(1,7) if address==0x5f7490 else seed(0,0);c['serviceWrites']={hex(address):[word(field,value)]};cases.append(c)
for c in cases:
 c['releaseResult']=0xdeadbeef;c['entry']='refill';c['writes'].append(word(VTABLE+0x30,RELEASE_TARGET))
 if '0x6e5bc0' in c.get('serviceWrites',{}):c['serviceWrites'][hex(RELEASE_TARGET)]=c['serviceWrites'].pop('0x6e5bc0')
for value in [0,1,0xffffffff,0x80000000,0x7fffffff,0xdeadbeef]:
 for at in [ALLOC,VTABLE+0x30,0x2854cec,0x297bea0]:
  c=seed();c.update(entry='release',releaseResult=value);c['writes'].append(word(VTABLE+0x30,RELEASE_TARGET));c['serviceWrites']={hex(RELEASE_TARGET):[word(at,0x12345678)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=service(im,0x6e5bc0,[ALLOC]) if c['entry']=='release' else apply(im);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6e5bc0,[ALLOC]) if c['entry']=='release' else n.call(0x5ffc80,count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or rv!=expected or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=dict(refill=hashlib.sha256(n.read(0x5ffc80,185)).hexdigest(),release=hashlib.sha256(n.read(0x6e5bc0,13)).hexdigest()),binarySha256=n.sha256,domain='prepared bank tables including unsigned index wrapping; callback writes followed by original cached/live reads',reaEvidenceIds=["ev_ac4e4ea5b4b8277625a0a0d12c775cd990c634f25a1ec3325cd3d350da27adff","ev_729dab12d8f13c6accce2bdeaf046e4f85e7307ba1e4a06d8369ab6b99d259e5"],nativeAdapters=['5f7490 fatal reporting service','allocatorvtable+2c value/mutation port'],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase110-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase110-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
