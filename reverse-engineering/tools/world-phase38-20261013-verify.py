import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;P=D+0x1000;R=D+0x3000;CTX=D+0x5000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];Image=rot['Image']
case={};trace=[]
def tls(im):
 trace.append([0x6f040c,[]])
 if case.get('mutateLifetime'):im.W(case['record']+0xa4,bits(-3.75))
 return case['context']
def rand(im):
 context=tls(im);s=U(im.W(context+20)*214013+2531011);im.W(context+20,s);return (s>>16)&32767
def attr(im,c):
 entry=c['entry'];p=c['particle'];r=c['record']
 if entry==0x6e8e1e:return rand(im)
 factors={0x654950:2,0x654970:5.400000095367432,0x6549c0:4,0x6549e0:16}
 if entry in factors:
  k=N(factors[entry]);im.W(p+16,(N.word(im.W(p))*k).store())
  if entry==0x654970:im.W(p+20,(N.word(im.W(p+4))*k).store())
  im.W(p+24,(k*N.word(im.W(p+8))).store());return None
 if entry==0x6549a0:im.W(p+16,im.W(p)^0x80000000);im.W(p+24,im.W(p+8)^0x80000000);return None
 k=N(0.6000000238418579);product=N.word(im.W(p))*k;im.W(p+16,(N.word(im.W(p+16))+N(-product.v,not product.neg)).store());product=N.word(im.W(p+8))*k;im.W(p+24,(N.word(im.W(p+24))+N(-product.v,not product.neg)).store());y=N.word(im.W(p+4));z=N.word(im.W(p+8));x=N.word(im.W(p));squared=(z*z+x*x).store()
 if not math.isfinite(F(squared)):raise ValueError('nonfinite consumed root input')
 root=bits(math.sqrt(F(squared)));product=N.word(root)*N(0.4000000059604645);im.W(p+4,(y+N(-product.v,not product.neg)).store());random=rand(im);value=N(random)*N.word(im.W(r+0xa4));value=N(rot['quant'](value.v/1503238528,64),value.neg);value=value+N.word(im.W(r+0xa4));life=im.W(r+0xa4)
 if not life&0x7fffffff:im.W(p+28,(life&0x80000000)|0x7f800000)
 else:im.W(p+28,N(rot['quant'](64/value.v,64),value.neg).store())
 return None
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={};nativeTrace=[]
class NativeImage:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00,0x6e8e1e,0x5c0240,0x6e9530]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=0x6f040c:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];start=len(trace);value=tls(NI);nativeTrace.extend(trace[start:]);del trace[start:];uc.reg_write(UC_X86_REG_EAX,value);uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(entry):return dict(entry=entry,particle=P,record=R,context=CTX,writes=[patch(P,struct.pack('<8f',1.25,-2.5,-0.0,10,0.5,0.25,-0.0,1)),word(R+0xa4,bits(5)),word(CTX+20,0x12345678)])
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,bits(1),bits(-1),bits(0.125),bits(-3.75),bits(1024),bits(-100000)]
cases=[];rng=random.Random(2026101338)
for entry in [0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00]:
 for i in range(128):
  c=seed(entry);c['writes'] += [patch(P,struct.pack('<8I',*[rng.choice(choices) for _ in range(8)]))];cases.append(c)
for state in [0,1,0xffffffff,0x80000000,0x7fffffff,0x12345678,0x007fffff]:
 for life in [0,0x80000000,1,0x80000001,bits(0.5),bits(-3.75),0x7f7fffff,0xff7fffff]:
  c=seed(0x654a00);c['writes'] += [word(CTX+20,state),word(R+0xa4,life)];cases.append(c)
for i in range(256):c=seed(0x6e8e1e);c['writes'] += [word(CTX+20,rng.getrandbits(32))];cases.append(c)
for offset in [0,4,8,12,16,20,24,28]:
 c=seed(0x654a00);c['record']=P+offset-0xa4;cases.append(c)
for offset in [0,4,8,12,16,20,24,28]:
 c=seed(0x654a00);c['context']=P+offset-20;cases.append(c)
c=seed(0x654a00);c['mutateLifetime']=True;cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 try:result=attr(im,c)
 except (ValueError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=trace[:];trace=[];nativeTrace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:actualResult=n.call(c['entry'],[] if c['entry']==0x6e8e1e else [D+0x6000,c['record'],c['particle']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or nativeTrace!=modelTrace or (result is not None and actualResult!=result):
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=nativeTrace,modelTrace=modelTrace,actualResult=actualResult,modelResult=result))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=nativeTrace,result=actualResult if result is not None else None);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2+sum(c['entry']==0x6e8e1e for c in rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['0x6f040c TLS-context pointer acquisition'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase38-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase38-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
