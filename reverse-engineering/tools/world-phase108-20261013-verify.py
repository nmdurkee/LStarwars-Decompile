import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x96d9c0,20,167),(0x9715a0,20,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

def qwordLow(v):
 integer=int(v.v)
 return U(integer) if -9223372036854775808<=integer<=9223372036854775807 else 0
# Exact model of the portable high-word/16-bit decomposition; assert it agrees with mathematical qword truncation.
def sourceQwordLow(v):
 high=int(rot['quant'](v.v/4294967296,64))
 if not -2147483648<=high<=2147483647:return 0
 remain=rot['quant'](v.v-rot['quant'](high*4294967296,64),64)
 if high==-2147483648 and remain<0:return 0
 shortHigh=int(rot['quant'](remain/65536,64));shortRemain=rot['quant'](remain-rot['quant'](shortHigh*65536,64),64)
 assert -2147483648<=shortHigh<=2147483647 and -2147483648<=int(shortRemain)<=2147483647
 return U(shortHigh*65536+int(shortRemain))
def divide(a,b):return N(rot['quant'](a.v/b.v,64),a.neg!=b.neg)
def apply(im,c):
 point=c['point'];origin=N.word(im.W(0x96d9c4));period=N.word(im.W(0x9715a4));normalized=[divide(N.word(im.W(point))-origin,period).store()]
 for i in [1,2]:normalized.append(divide(N.word(im.W(point+i*4))-N.word(im.W(0x96d9c4+i*4)),N.word(im.W(0x9715a4+i*4))).store())
 wrapped=[]
 for word in normalized:
  if not __import__('math').isfinite(F(word)):raise ValueError('nonfinite normalized result outside prepared domain')
  value=N.word(word);biased=value+N(65536);rounded=qwordLow(biased);assert rounded==sourceQwordLow(biased);shift=S(U(rounded-65536));wrapped.append((value-N(shift)).store())
 im.W(point,(N.word(wrapped[0])*period+origin).store())
 for i in [1,2]:im.W(point+i*4,(N.word(im.W(0x9715a4+i*4))*N.word(wrapped[i])+N.word(im.W(0x96d9c4+i*4))).store())
P=D+0x1000;rng=random.Random(20261013108);cases=[]
def seed(point=P,values=(1,2,3),origin=(0,0,0),period=(1,1,1)):return dict(point=point,writes=[patch(point,struct.pack('<3f',*values)),patch(0x96d9c4,struct.pack('<3f',*origin)),patch(0x9715a4,struct.pack('<3f',*period))])
for i in range(768):cases.append(seed(values=[rng.uniform(-100000,100000) for j in range(3)],origin=[rng.uniform(-10,10) for j in range(3)],period=[rng.choice([-1,1])*rng.uniform(.001,16) for j in range(3)]))
for sampleWord in [0,0x80000000,1,0x80000001,0x007fffff,0x807fffff,bits(.5),bits(-.5),bits(65536),bits(-65536),0x3f7fffff,0xbf7fffff,0x4f000000,0xcf000000,0x4f800000,0xcf800000,0x5f000000,0xdf000000,0x5effffff,0xdeffffff,0x7f7fffff,0xff7fffff]:
 c=seed();c['writes'].append(patch(P,struct.pack('<3I',sampleWord,sampleWord,sampleWord)));cases.append(c)
for exponent in range(-60,-25):
 for sign in [-1,1]:cases.append(seed(values=[sign*2.0**exponent]*3))
for base in [0x96d9c4,0x9715a4]:
 for shift in [-4,0,4]:
  # Prepared region must contain full aliased XYZ input/output.
  c=seed(point=base+shift,values=(2,3,4),origin=(.25,.5,.75),period=(1,2,3));cases.append(c)
for mask in range(64):
 c=seed();c['writes'] += [patch(P,struct.pack('<3I',*[0x80000000 if mask&(1<<i) else 0 for i in range(3)])),patch(0x96d9c4,struct.pack('<3I',*[0x80000000 if mask&(1<<(i+3)) else 0 for i in range(3)]))];cases.append(c)
for zero in [0,0x80000000]:
 c=seed();c['writes'].append(word(0x9715a4,zero));cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:apply(im,c)
 except (ValueError,OverflowError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason='nonzero finite periods and finite normalized intermediates required: '+str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x5ffee0,[c['point']],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativePoint=list(n.unpack('<3I',c['point'])),modelPoint=[im.W(c['point']+i*4) for i in range(3)]));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entry='0x5ffee0',originalBytesSha256=hashlib.sha256(n.read(0x5ffee0,231)).hexdigest(),binarySha256=n.sha256,domain='finite nonzero periods and normalized/stored arithmetic; original biased qword conversion including low DWORD wrap/overflow; cached X and fresh Y/Z output globals; exact point/global aliases',reaEvidenceIds=["ev_1b04e019bde4a542c42c8a92707c2ae9615554ed2f5c12a599c1d972487654fe"],nativeAdapters=[],syntheticExcluded=len(excluded),excluded=excluded,seconds=round(time.time()-start,3))
(B/'reports/world-phase108-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase108-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
