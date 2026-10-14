import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;SRC=D+0x1000;MATRIX=D+0x2000;OUT=D+0x3000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];Image=rot['Image']
def finite(w):
 if not math.isfinite(F(w)):raise ValueError('nonfinite consumed operand')
 return N.word(w)
def scale(im,c):
 factor=finite(c['scale'])
 for i in range(3):im.W(c['destination']+i*4,(finite(im.W(c['source']+i*4))*factor).store())
def transformwords(im,point,m):
 out=[0,0,0];P=lambda a,w:finite(im.W(a))*finite(w)
 for axis in [1,2]:out[axis]=(P(m+axis*4,point[0])+P(m+16+axis*4,point[1])+P(m+32+axis*4,point[2])+finite(im.W(m+48+axis*4))).store()
 out[0]=(P(m+16,point[1])+P(m,point[0])+P(m+32,point[2])+finite(im.W(m+48))).store();return out
def transform(im,c):
 out=transformwords(im,[im.W(c['source']+i*4) for i in range(3)],c['matrix'])
 for i in range(3):im.W(c['destination']+i*4,out[i])
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x5b3830,0x5c11d0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind):return dict(kind=kind,destination=OUT,source=SRC,matrix=MATRIX,scale=bits(0.5),writes=[patch(SRC,struct.pack('<3f',1.25,-2.5,-0.0)),patch(MATRIX,struct.pack('<16f',*[i/8-1 for i in range(16)]))])
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(1),bits(-1),bits(0.125),bits(-3.75),bits(1024)]
cases=[];rng=random.Random(2026101336)
for i in range(512):
 c=seed('scale');c['scale']=rng.choice(choices);c['writes'] += [patch(SRC,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)]))];cases.append(c)
for i in range(512):
 c=seed('transform');c['writes'] += [patch(SRC,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)])),patch(MATRIX,struct.pack('<16I',*[rng.choice(choices) for _ in range(16)]))];cases.append(c)
for kind in ['scale','transform']:
 for anchor in [SRC,MATRIX]:
  for shift in [-12,-8,-4,-3,-2,-1,0,1,2,3,4,8,12,16,32,48,52,56,60]:c=seed(kind);c['destination']=anchor+shift;cases.append(c)
for kind in ['scale','transform']:
 for offset in [-4,0,4,8,12,16,32,48,52]:c=seed(kind);c['source']=MATRIX+offset;cases.append(c)
for scalar in choices:
 c=seed('scale');c['scale']=scalar;c['destination']=SRC+4;cases.append(c)
# Numerically sensitive x87 cancellation and signed-zero cases.
for value in [0,0x80000000,bits(1),bits(-1),0x007fffff,0x00800000]:
 c=seed('transform');c['writes'] += [patch(SRC,struct.pack('<3I',value,value,value)),patch(MATRIX,struct.pack('<16I',*[0x80000000]*16))];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:(scale if c['kind']=='scale' else transform)(im,c)
 except ValueError as e:excluded.append(dict(case=i,reason=str(e)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x5b3830 if c['kind']=='scale' else 0x5c11d0,[c['destination'],c['source'],c['scale'] if c['kind']=='scale' else c['matrix']])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():errors.append(dict(case=i,actual=actual,model=im.hash()));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase36-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase36-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
