import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x2962080,4,0),(0x2854ce8,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
import math
P=D+0x1000;Q=D+0x2000;PROBE=D+0xfff0;SHIM=0x10300000
# Observation-only wrapper: push the supplied point, execute original6585a0 unmodified, spill returned ST0 once.
n.mu.mem_map(SHIM,0x1000);code=bytes.fromhex('ff742404e8')+struct.pack('<i',0x6585a0-(SHIM+9))+bytes.fromhex('83c404d91d')+struct.pack('<I',PROBE)+b'\xc3';n.write(SHIM,code)
def apply(im,c):
 if c['entry']==0x5ffd40:im.W(0x2854ce8,c['value']);return
 if c['entry']==0x5b4c90:
  cached=N.word(c['value'])
  for i in range(3):im.W(c['point']+i*4,(N.word(im.W(c['point']+i*4))*cached).store())
  return
 reference=im.W(0x2962080)
 if not reference:result=0
 else:
  delta=[]
  for i in range(3):a=N.word(im.W(c['point']+i*4));b=N.word(im.W(reference+i*4));w=(a+N(-b.v,not b.neg)).store();delta.append(N.word(w))
  x,y,z=delta;squared=(x*x+y*y+z*z).store()
  if not math.isfinite(F(squared)):raise ValueError('nonfinite consumed distance square')
  result=bits(math.sqrt(F(squared)))
 im.W(PROBE,result)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x5ffd40,0x5b4c90,0x6585a0,0x5becc0,0x5c0240]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(entry=0x6585a0,value=0x3f000000):return dict(entry=entry,value=value,point=P,writes=[patch(P,struct.pack('<3f',1.25,-2.5,-0.0)),patch(Q,struct.pack('<3f',-.5,3.75,-0.0)),word(0x2962080,Q)])
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,bits(1),bits(-1),bits(.5),bits(-.125),bits(10000),0x7f7fffff,0xff7fffff]
cases=[]
for scale in choices:
 for value in choices:
  c=seed(0x5b4c90,scale);c['writes'].append(patch(P,struct.pack('<3I',value,value,value)));cases.append(c)
for a in [0,0x80000000,bits(1),bits(-1),bits(1e18),bits(-1e18),1,0x80000001]:
 for b in [0,0x80000000,bits(1),bits(-1),bits(1e18),bits(-1e18),1,0x80000001]:
  c=seed();c['writes'] += [patch(P,struct.pack('<3I',a,a,a)),patch(Q,struct.pack('<3I',b,b,b))];cases.append(c)
for point in [0,P,P+1,Q,0xffffffff]:c=seed();c['point']=point;c['writes'].append(word(0x2962080,0));cases.append(c)
for shift in range(-12,13):c=seed();c['writes'].append(word(0x2962080,P+shift));cases.append(c)
rng=random.Random(2026101367)
for i in range(256):
 c=seed();c['writes'] += [patch(P,struct.pack('<3f',*[rng.uniform(-10000,10000) for j in range(3)])),patch(Q,struct.pack('<3f',*[rng.uniform(-10000,10000) for j in range(3)]))];cases.append(c)
for value in [0,1,0xffffffff,0x7f800001]+[rng.getrandbits(32) for i in range(256)]:cases.append(seed(0x5ffd40,value))
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:apply(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(SHIM,[c['point']]) if c['entry']==0x6585a0 else n.call(c['entry'],[c['value']] if c['entry']==0x5ffd40 else [c['point'],c['value']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or c["entry"]==0x6585a0 and n.unpack("<I",PROBE)[0]!=im.W(PROBE):errors.append(dict(case=i,native=actual,model=im.hash(),nativeDistance=hex(n.unpack('<I',PROBE)[0]),modelDistance=hex(im.W(PROBE))));break
 c['expected']=dict(sha256=actual,result=im.W(PROBE) if c['entry']==0x6585a0 else None);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=sum(2 if c['entry']==0x6585a0 else 1 for c in rows),mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase67-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase67-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],probe=PROBE,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
