import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;OUT=D+0x2000;P=D+0x1000;REGIONS=[(D,0x4000,167),(0x973ff4,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];word=rot['word'];patch=rot['patch'];Image=rot['Image'];trace=[];case={}
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def service(im,a,args):
 trace.append([a,args])
 if a==0x5e4b20:
  for x in case.get('allocateWrites',[]):im.write(x['address'],base64.b64decode(x['data']))
  return case['allocated']
 for x in case.get('finalizeWrites',[]):im.write(x['address'],base64.b64decode(x['data']))
 return 0xdeadbeef
def create(im,c):
 parent=c['parent']
 if not parent:return 0
 result=service(im,0x5e4b20,[1,im.W(0x973ff4),1]);im.W(result+0x54,0x3f800000);prior=im.W(result+0x40);im.W(result+0x58,0x3f800000);im.W(result+0x5c,0x3f800000);im.W(result+0x70,0x3f7fbe77);flags=U(((((c['group']&3)<<10)|(c['channel']&3)|0x200)<<4)|(prior&0xffff2fc0)|(c['variant']&15));im.W(result+0x40,flags)
 if c['option']:im.W(result+0x44,im.W(result+0x44)|4)
 cached=im.W(result+0x44);im.W(result+0x40,(flags&0xfffff5ff)|0x500);im.write(result+0x74,im.read(parent+0x74,2));im.write(result+0x76,im.read(parent+0x76,2));im.W(result+0x44,(cached&0xfffffffd)|1);service(im,0x601030,[result]);im.write(result+0x2c0,struct.pack('<H',(struct.unpack('<H',im.read(result+0x2c0,2))[0]+1)&65535));return result
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
class NI:
 def write(self,a,v):n.write(a,v)
def observe(uc,a,z,user):
 if a not in [0x5e4b20,0x601030]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret,arg=n.unpack('<2I',sp);args=[uc.reg_read(UC_X86_REG_ECX),uc.reg_read(UC_X86_REG_EAX),arg] if a==0x5e4b20 else [arg];value=service(NI(),a,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(parent=P,option=0,variant=0,group=0,channel=0):return dict(parent=parent,option=option,variant=variant,group=group,channel=channel,allocated=OUT,writes=[word(OUT+0x40,0x87654321),word(OUT+0x44,0xfedcba98),half(P+0x74,0x1234),half(P+0x76,0xabcd)])
cases=[seed(0)]
for option in [0,1,0xffffffff]:
 for group in range(4):
  for channel in range(4):
   for variant in [0,1,7,15,16,0xffffffff]:cases.append(seed(option=option,group=group,channel=channel,variant=variant))
for shift in range(-128,129):cases.append(seed(parent=OUT+shift,option=1,variant=13,group=3,channel=2))
rng=random.Random(2026101353)
for i in range(256):
 c=seed(parent=rng.choice([P,OUT,OUT-2,OUT+2,OUT-0x34]),option=rng.getrandbits(32),variant=rng.getrandbits(32),group=rng.getrandbits(32),channel=rng.getrandbits(32));c['writes'] += [word(OUT+0x40,rng.getrandbits(32)),word(OUT+0x44,rng.getrandbits(32))]
 if i%3==0:c['allocateWrites']=[word(P+0x74,rng.getrandbits(32)),word(OUT+0x40,rng.getrandbits(32))]
 if i%5==0:c['finalizeWrites']=[word(OUT+0x44,rng.getrandbits(32)),word(OUT+0x74,rng.getrandbits(32))]
 cases.append(c)
for j,c in enumerate(cases):c['kind']='create';c['writes'].append(word(0x973ff4,0x87650000|j))
for count in [0,1,2,7,600,0xffffffff,0x80000000,0x7fffffff]:
 for typeWord in [0,1,255,256,0xffffffff,0x12345678]:
  c=seed();c.update(kind='allocate',count=count);c['writes'].append(word(0x973ff4,typeWord));cases.append(c)
for counter in [0,1,32767,32768,65534,65535]:
 for mut in [False,True]:
  c=seed();c.update(kind='finalize',material=OUT);c['writes'].append(half(OUT+0x2c0,counter))
  if mut:c['finalizeWrites']=[half(OUT+0x2c0,65535-counter)]
  cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 if c.get('kind')=='allocate':expected=service(im,0x5e4b20,[c['count'],im.W(0x973ff4),1])
 elif c.get('kind')=='finalize':service(im,0x601030,[c['material']]);im.write(c['material']+0x2c0,struct.pack('<H',(struct.unpack('<H',im.read(c['material']+0x2c0,2))[0]+1)&65535));expected=0
 else:expected=create(im,c)
 modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 actualReturn=n.call(0x5e4d40,[c['count']]) if c.get('kind')=='allocate' else n.call(0x5e4b00,[c['material']]) if c.get('kind')=='finalize' else n.call(0x654a90,[c['parent'],c['option'],c['variant'],c['group'],c['channel']]);
 if c.get('kind')=='finalize':actualReturn=0
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or actualReturn!=expected or trace!=modelTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeReturn=actualReturn,modelReturn=expected,nativeTrace=trace,modelTrace=modelTrace));break
 c['expected']=dict(result=actualReturn,sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=sum(2 if c.get('kind')=='finalize' else 3 for c in rows),mismatches=len(errors),errors=errors,binarySha256=n.sha256,nativeAdapters=['0x5e4b20 mutable material pool allocation with raw ECX/EAX','0x601030 mutable material refresh'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase54-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase54-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
