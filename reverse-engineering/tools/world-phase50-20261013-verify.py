import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;A=D+0x1000;C=D+0x2000;OUT=D+0x3000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];N=rot['N'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];Image=rot['Image']
def value(w):
 if not math.isfinite(F(w)):raise ValueError('nonfinite operand consumed after sequential alias store')
 return N.word(w)
def subtract(im,c):
 for i in range(3):a=value(im.W(c['first']+i*4));b=value(im.W(c['second']+i*4));im.W(c['destination']+i*4,(a+N(-b.v,not b.neg)).store())
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a==0x5b3800:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():return dict(destination=OUT,first=A,second=C,writes=[patch(A,struct.pack('<3f',1.25,-2.5,-0.0)),patch(C,struct.pack('<3f',0.5,0.25,-0.0))])
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(1),bits(-1),bits(0.125),bits(-3.75),bits(1024)]
cases=[];rng=random.Random(2026101350)
for i in range(512):c=seed();c['writes'] += [patch(A,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)])),patch(C,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)]))];cases.append(c)
for a,b in [(A,C),(A,A),(C,A),(C,C)]:
 for anchor in [a,b]:
  for shift in [-12,-8,-4,-3,-2,-1,0,1,2,3,4,8,12]:c=seed();c.update(first=a,second=b,destination=anchor+shift);cases.append(c)
for a in choices:
 for b in choices:c=seed();c['writes'] += [patch(A,struct.pack('<3I',a,a,a)),patch(C,struct.pack('<3I',b,b,b))];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:subtract(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x5b3800,[c['destination'],c['first'],c['second']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():errors.append(dict(case=i,actual=actual,model=im.hash()));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase50-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase50-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
