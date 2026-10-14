import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

KEY=D+0x1000;RUNTIME=D+0x2000
def modeFlags(im,k):
 r=im.W(k);flags=im.W(r+0x13c);kind=im.W(k+12);result=(flags>>18)&1;vertex=flags&0x30000;layers=not kind or im.B(r+0x1b4)!=0
 if vertex and not flags&0x400000:result|=2
 if layers:
  count=(flags>>9)&3
  if count>=1:result|=4
  if count>=2:result|=8
  if count>=3:result|=16
 if vertex and flags&0x400000:result|=64
 if flags&0x80000:result|=128
 if flags&0x1000000:result|=256
 if flags&0x2000000:result|=1024
 if not kind and im.W(r+0x1b8)&0x80000000:result|=2048
 if layers and flags&256:result|=4096
 return result
def materialLayer(im,k,layer):
 if layer==0:return 1
 if layer>3:return 0
 r=im.W(k);flags=im.W(r+0x1b8) if layer==3 else im.B(r+0x1b8);return int(bool(flags&(1<<(layer+5))) and im.B(r+0x43+layer)!=255)
def runtimeLayer(im,k,layer):
 if im.W(k+12) and not im.B(im.W(k)+0x1b4):return 0
 if layer>3:return 0
 r=im.W(k);return int(S(im.W(r+4+layer*4))>S(im.W(k+32)))
def baseLayer(im,k,layer):
 if not im.W(k+12):return materialLayer(im,k,layer)
 active=materialLayer(im,k,layer);return int(active and layer==0 and bool(im.B(im.W(k)+0x1b4)&1))
def apply(im,c):return {0x744600:lambda:modeFlags(im,c['key']),0x744430:lambda:materialLayer(im,c['key'],c['layer']),0x7444b0:lambda:runtimeLayer(im,c['key'],c['layer']),0x7445b0:lambda:baseLayer(im,c['key'],c['layer'])}[c['entry']]()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
entries={}
def observe(uc,a,z,user):
 if a in [0x744600,0x744430,0x7444b0,0x7445b0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e):return dict(entry=e,key=KEY,layer=0,writes=[word(KEY,RUNTIME),word(KEY+12,0),word(KEY+32,0),word(RUNTIME+0x13c,0),byte(RUNTIME+0x1b4,0),word(RUNTIME+0x1b8,0),patch(RUNTIME+4,struct.pack('<4I',1,2,3,4)),patch(RUNTIME+0x44,bytes([1,2,3]))])
cases=[];rng=random.Random(2026101394)
flagBits=[8,9,10,16,17,18,19,22,24,25]
for bits0 in range(1<<len(flagBits)):
 flag=sum(1<<flagBits[i] for i in range(len(flagBits)) if bits0&(1<<i))
 for kind in [0,1]:
  for byte0 in [0,1]:
   c=seed(0x744600);c['writes'] += [word(RUNTIME+0x13c,flag),word(KEY+12,kind),byte(RUNTIME+0x1b4,byte0),word(RUNTIME+0x1b8,0x80000000 if bits0&1 else 0)];cases.append(c)
for e in [0x744430,0x7444b0,0x7445b0]:
 for layer in [0,1,2,3,4,0xffffffff]:
  for kind in [0,1]:
   for flags in [0,0x40,0x80,0x100,0x1c0]:
    for byte0 in [0,1,2,255]:
     c=seed(e);c['layer']=layer;c['writes'] += [word(KEY+12,kind),byte(RUNTIME+0x1b4,byte0),word(RUNTIME+0x1b8,flags),patch(RUNTIME+0x44,bytes([byte0,byte0,byte0]))];cases.append(c)
for value in [0,1,0xffffffff,0x80000000,0x7fffffff]:
 for limit in [0,1,0xffffffff,0x80000000,0x7fffffff]:
  for layer in range(4):
   c=seed(0x7444b0);c['layer']=layer;c['writes'] += [word(KEY+32,limit),word(RUNTIME+4+layer*4,value)];cases.append(c)
for key,layer in [(0,0),(0xffffffff,0),(0,4),(0xffffffff,0xffffffff)]:c=seed(0x744430);c['key']=key;c['layer']=layer;cases.append(c)
for i in range(256):
 c=seed(0x744600);c['writes'] += [word(RUNTIME+0x13c,rng.getrandbits(32)),word(KEY+12,rng.getrandbits(32)),word(RUNTIME+0x1b8,rng.getrandbits(32)),byte(RUNTIME+0x1b4,rng.randrange(256))];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);pred=apply(im,c)
 for a,z,_ in REGIONS:n.write(a,im.read(a,z))
 rv=n.call(c['entry'],[] if c['entry']==0x744600 else [c['layer']],regs={UC_X86_REG_ECX:c['key']});rv=rv if c['entry']==0x744600 else rv&255;actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=pred or actual!=im.hash():errors.append(dict(case=i,entry=hex(c['entry']),native=rv,model=pred,nativeImage=actual,modelImage=im.hash()));break
 c['expected']=dict(result=rv,sha256=actual);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase94-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase94-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
