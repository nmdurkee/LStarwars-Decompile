import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REGIONS=[(D,0x1000,167),(0x29a9c48,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];N=rot['N'];F=rot['F'];bits=rot['bits'];word=rot['word'];Image=rot['Image']
def sub(a,b):return a+N(-b.v,not b.neg)
def clamp(a):return N(1) if a.v>1 else N(-1) if a.v< -1 else a
def inverse(input,selector):
 x=N.word(input);squared=sub(N(1),x*x).store()
 if not math.isfinite(F(squared)):raise ValueError('nonfinite square-root helper input')
 root=bits(0 if F(squared)<0 else math.sqrt(F(squared)));absolute=input&0x7fffffff;minimum=root if F(absolute)>F(root) else absolute;large=N(3.402820018375656e38);direction=sub(N.word(absolute),N(0.7071067690849304))*large;branch=clamp(direction).store();sign=clamp(large*x).store();signedBranch=N.word(sign)*N.word(branch);a=N.word(minimum)*signedBranch;a2=a*a;a3=a2*a;a4=a2*a2;baseline=(signedBranch+N.word(sign)).store();result=N(-1)*a+N.word(baseline)*N(0.785398006439209);result=result+(a*N(-0.16666699945926666))*a2;result=result+(N(-0.07500000298023224)*a2)*a3;result=result+(a3*N(-0.04464289918541908))*a4;result=result+(a4*N(-0.03038189932703972))*(a2*a3);value=(result*N(10430.400390625)).v
 if selector:value=rot['quant'](value,53)
 q=abs(value.numerator)//value.denominator*(-1 if value<0 else 1);return q&0xffffffff if -2147483648<=q<=2147483647 else 0x80000000
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x64fe20,0x5c0240,0x6e9530,0x6e6b90]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,bits(0.5),bits(-0.5),bits(0.7071067690849304)-1,bits(0.7071067690849304),bits(0.7071067690849304)+1,bits(-0.7071067690849304)-1,bits(-0.7071067690849304),bits(-0.7071067690849304)+1,bits(1)-1,bits(1),bits(1)+1,bits(-1)-1,bits(-1),bits(-1)+1,bits(2),bits(-2),bits(1e10),bits(-1e10),0x5f7fffff,0xdf7fffff]
cases=[];rng=random.Random(2026101344)
for selector in [0,1]:
 for input in choices:cases.append(dict(input=input,selector=selector,writes=[word(0x29a9c48,selector)]))
 for i in range(512):
  input=rng.randint(0,0x5f7fffff)|(rng.randrange(2)<<31);cases.append(dict(input=input,selector=selector,writes=[word(0x29a9c48,selector)]))
 for i in range(257):input=bits(i/128-1);cases.append(dict(input=input,selector=selector,writes=[word(0x29a9c48,selector)]))
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 try:result=inverse(c['input'],c['selector'])
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 im=Image(c)
 for a,z,_ in REGIONS:n.write(a,im.read(a,z))
 actualResult=n.call(0x64fe20,[c['input']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actualResult!=result or actual!=im.hash():errors.append(dict(case=i,input=hex(c['input']),selector=c['selector'],actualResult=actualResult,modelResult=result,actual=actual,model=im.hash()));break
 c['expected']=dict(result=actualResult,sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase44-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase44-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
