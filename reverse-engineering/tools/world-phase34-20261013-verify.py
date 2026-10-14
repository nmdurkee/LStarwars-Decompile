import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;A=D+0x1000;C=D+0x2000;OUT=D+0x3000;PROBE=D+0x5000;SHIM=0x10300000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];Image=rot['Image']
# Post-return observer only: original64fde0 code executes unchanged and returns ST0; the shim spills it once to a retained probe.
n.mu.mem_map(SHIM,0x1000);code=bytes.fromhex('ff742408ff742408e8')+struct.pack('<i',0x64fde0-(SHIM+13))+bytes.fromhex('83c408d91d')+struct.pack('<I',PROBE)+b'\xc3';n.write(SHIM,code)
def divide(a,b):
 if not(a&0x7fffffff) or not(b&0x7fffffff):return 0
 x,y=N.word(a),N.word(b);return N(rot['quant'](x.v/y.v,64),x.neg!=y.neg).store()
def scaled(im,c):
 s=N.word(c['scale'])
 for i in range(3):
  dw=im.W(c['delta']+i*4);bw=im.W(c['basis']+i*4)
  if not math.isfinite(F(dw)) or not math.isfinite(F(bw)):raise ValueError('nonfinite consumed after alias propagation')
  im.W(c['destination']+i*4,(N.word(dw)*s+N.word(bw)).store())
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x64fde0,0x5b3860]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind):return dict(kind=kind,a=bits(1),b=bits(2),scale=bits(0.5),basis=A,delta=C,destination=OUT,writes=[patch(A,struct.pack('<3f',1.25,-2.5,-0.0)),patch(C,struct.pack('<3f',0.5,3.75,-0.0))])
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(1),bits(-1),bits(0.125),bits(-3.75),bits(1024)]
cases=[]
for a in choices:
 for b in choices:c=seed('divide');c.update(a=a,b=b);cases.append(c)
for a,b in [(0,0x7f800000),(0x80000000,0x7fc12345),(0x7fc12345,0),(0xff800000,0x80000000)]:c=seed('divide');c.update(a=a,b=b);cases.append(c)
rng=random.Random(2026101334)
for i in range(512):
 c=seed('divide');c.update(a=rng.choice(choices),b=rng.choice(choices));cases.append(c)
for i in range(512):
 c=seed('scaled');c['scale']=rng.choice(choices);c['writes'] += [patch(A,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)])),patch(C,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)]))];cases.append(c)
for basis,delta in [(A,C),(A,A),(C,A),(C,C)]:
 for anchor in [basis,delta]:
  for shift in [-12,-8,-4,-3,-2,-1,0,1,2,3,4,8,12]:
   c=seed('scaled');c.update(basis=basis,delta=delta,destination=anchor+shift);cases.append(c)
for scale in choices:
 c=seed('scaled');c['scale']=scale;c['destination']=A+4;cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:
  if c['kind']=='divide':result=divide(c['a'],c['b']);im.W(PROBE,result)
  else:scaled(im,c);result=None
 except ValueError as e:excluded.append(dict(case=i,reason=str(e)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 if c['kind']=='divide':n.call(SHIM,[c['a'],c['b']]);actualResult=n.unpack('<I',PROBE)[0]
 else:n.call(0x5b3860,[c['destination'],c['basis'],c['delta'],c['scale']]);actualResult=None
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or actualResult!=result:errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash(),actualResult=actualResult,modelResult=result));break
 c['expected']=dict(sha256=actual,result=actualResult);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded,returnObservationShim='post-returnFSTPf32, not a child adapter')
(B/'reports/world-phase34-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase34-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],probe=PROBE,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
