import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;OUT1=D+0x1000;OUT2=D+0x2000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];N=rot['N'];F=rot['F'];bits=rot['bits'];word=rot['word'];Image=rot['Image']
def neg(a):return N(-a.v,not a.neg)
def sub(a,b):return a+neg(b)
def div(a,b):return N(rot['quant'](a.v/b.v,64),a.neg!=b.neg)
def values(a,b,c):
 if not a&0x7fffffff:
  if not b&0x7fffffff:return 0,0,0,False
  root=div(neg(N.word(c)),N.word(b)).store();return 1,root,root,True
 A=N.word(a);C=N.word(c);V=N.word(b);product=(N(4)*A)*C;square=V*V;difference=sub(square,product)
 if difference.v<0:return 0,0,0,False
 denominator=A+A
 if not difference.v:root=div(neg(V),denominator).store();return 1,root,root,True
 discriminant=difference.store()
 if not math.isfinite(F(discriminant)):raise ValueError('nonfinite consumed square-root input')
 root=N.word(bits(math.sqrt(F(discriminant))));first=div(sub(neg(V),root),denominator).store();second=div(sub(root,V),denominator).store();return 1,first,second,False
def solve(im,c):
 result,first,second,repeated=values(c['a'],c['b'],c['c'])
 if result:
  if repeated:im.W(c['second'],second);im.W(c['first'],first)
  else:im.W(c['first'],first);im.W(c['second'],second)
 return result
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x653840,0x5c0240,0x6e9530]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(a,b,c):return dict(a=a,b=b,c=c,first=OUT1,second=OUT2,writes=[])
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,bits(1),bits(-1),bits(2),bits(-2),bits(0.125),bits(-3.75),bits(10000)]
cases=[]
for a in choices:
 for b in choices:
  for c in choices:cases.append(seed(a,b,c))
for a,b,c in [(bits(1),bits(2),bits(1)),(bits(1),bits(2),bits(1)-1),(bits(1),bits(2),bits(1)+1),(0,bits(1),bits(-1)),(0,0,bits(1)),(bits(-1),0,bits(1)),(bits(1),0,bits(-1))]:
 for shift in [-4,-3,-2,-1,0,1,2,3,4]:case=seed(a,b,c);case['second']=OUT1+shift;cases.append(case)
rng=random.Random(2026101348)
for i in range(256):cases.append(seed(bits(rng.uniform(-1000,1000)),bits(rng.uniform(-1000,1000)),bits(rng.uniform(-1000,1000))))
for a,b,c in [(0,1,0x7f7fffff),(0,0x80000001,0x7f7fffff),(1,bits(1),bits(-1)),(0x7f7fffff,bits(1),0),(0x7f7fffff,bits(1),bits(-1))]:cases.append(seed(a,b,c))
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:result=solve(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 actualResult=n.call(0x653840,[c['a'],c['b'],c['c'],c['first'],c['second']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actualResult!=result or actual!=im.hash():errors.append(dict(case=i,a=hex(c['a']),b=hex(c['b']),c=hex(c['c']),actualResult=actualResult,modelResult=result,actual=actual,model=im.hash(),nativeFirst=n.read(c['first'],4).hex(),modelFirst=im.read(c['first'],4).hex(),nativeSecond=n.read(c['second'],4).hex(),modelSecond=im.read(c['second'],4).hex()));break
 c['expected']=dict(result=actualResult,sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase48-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase48-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
