import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x90000,0),(0x854260,8,0),(0x297d690,0x420,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

RUNTIME=D+0x2000;MAT=D+0x3000;VTABLE=D+0x4000;RES1=D+0x5000;RES2=D+0x5100;MANAGER=D+0x6000;PREP=0x10300000;COMPILE=PREP+0x100;RELEASE=PREP+0x200;ALT=PREP+0x300
n.mu.mem_map(PREP,0x1000)
for a in [PREP,COMPILE,RELEASE,ALT]:n.write(a,b'\xc3')
common=[word(MANAGER,VTABLE),word(VTABLE+8,PREP),word(VTABLE+4,COMPILE),word(VTABLE+0x104,ALT),word(VTABLE+0x108,PREP),word(RES1,VTABLE+0x200),word(RES2,VTABLE+0x200),word(VTABLE+0x208,RELEASE),word(RUNTIME+0x13c,0),byte(RUNTIME+0x1ba,0),word(MAT+0x40,0)]
for i in range(400):common += [word(MANAGER+i*0x4d8+8,1),word(MANAGER+i*0x4d8+12,0x11111111),word(MANAGER+i*0x4d8+4+0x4cc,0),word(MANAGER+i*0x4d8+4+0x4d0,0)]
rot['common']=common
ctx=dict(rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64)
def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());selected=ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]);env=dict(ctx,__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env
descriptor=model(95);descriptor['TABLE']=0x297d698;descriptor['pred']=model(94);crc=model(93);crc['TABLE']=0x297d698;key=model(89);slots=model(90);trace=[];case={};tokens=[]
class KeyImage:
 def __init__(self,im,words):self.im=im;self.words=words
 def W(self,a,v=None):
  if 0x10310000<=a<0x10310024:assert v is None;return self.words[(a-0x10310000)//4]
  return self.im.W(a,v)
 def B(self,a,v=None):return self.im.B(a,v)
 def read(self,a,z):return self.im.read(a,z)
 def write(self,a,v):return self.im.write(a,v)
def tokenValue(im,values):
 descriptor['case']=case;descriptor['port']=port;wrapper=KeyImage(im,values[:9]);blob=descriptor['blob'](wrapper,dict(key=0x10310000,force=values[9]));return (descriptor['crcValues'](im,blob,True)<<16)|descriptor['crcValues'](im,blob,False)
# Private out-index retains originalruntime argument when7414c0 returns0: its output pointer aliases that caller arg slot.
p=Path(__file__).with_name('world-phase90-20261013-verify.py');ts=p.read_text();tree=ast.parse(ts);body=ast.get_source_segment(ts,next(x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name=='select'));body=body.replace('if not found:return 0','if not found:return (0,None)').replace('im.W(out,selected);return p','return (p,selected)');exec(compile(body,str(p),'exec'),slots)
def port(im,address,args):
 if address==0x744b70:
  value=tokenValue(im,args);tokens.append(value);return value
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['lookupResult'] if address==0x5e5310 else case['format'] if address==PREP+0x400 else case['compileResult'] if address in [COMPILE,ALT] else 0
slots['service']=port
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def create(im,c):
 runtime,material,mode,fourth,fifth=c['args'];manager=c['manager'];target=im.W(im.W(manager)+8);port(im,target,[manager,runtime,material]);words=key['values'](im,dict(args=[0,runtime,material,mode,fourth]));token=port(im,0x744b70,words+[int((fifth&255)!=0)])
 for i in range(400):
  if im.W(U(manager+i*0x4d8+12))!=token:continue
  hit=U(manager+i*0x4d8+4)
  if hit:im.W(hit+4,U(im.W(hit+4)+1));return hit
  break
 program,index=slots['select'](im,manager,0);index=runtime if not program else index;target=im.W(im.W(manager)+4);rv=port(im,target,[manager]+words+[fifth,program,U(index)])
 if not rv&255:return 0
 im.W(program+4,U(im.W(program+4)+1));return program
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
entries={};failureOutIndices=[]
def observe(uc,a,z,user):
 if a in [0x7416a0,0x744320,0x7414c0,0x744010,0x7422d0,0x743930,0x744b70,0x744600,0x744430,0x7444b0,0x7445b0,0x7462b0,0x7462f0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a==0x7416f1:
  sp=uc.reg_read(UC_X86_REG_ESP);tokens.append(n.unpack('<I',sp+0x44)[0]);return
 if a not in [PREP,COMPILE,RELEASE,ALT,0x5e5310,PREP+0x400]:return
 sp=uc.reg_read(UC_X86_REG_ESP)
 if a==PREP:args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<2I',sp+4));cleanup=12
 elif a in [COMPILE,ALT]:p,fifth,program,index=n.unpack('<4I',sp+4);args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<9I',p))+[fifth,program,index];cleanup=20
 elif a==RELEASE:args=list(n.unpack('<I',sp+4));cleanup=8
 elif a==0x5e5310:args=list(n.unpack('<I',sp+4));cleanup=4
 else:obj,level,out=n.unpack('<3I',sp+4);args=[obj,level];cleanup=16
 rv=port(ni,a,args)
 if a==PREP+0x400:n.write(out,struct.pack('<8I',rv,0,0,0,0,0,0,0));rv=0
 uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():return dict(manager=MANAGER,args=[RUNTIME,MAT,0,0x12345678,0],token=0x22222222,compileResult=1,writes=[word(MANAGER+0x79184,0xffffffff),word(MANAGER+8,0)])
cases=[];rng=random.Random(2026101391)
for hit in range(400):
 c=seed();c['writes'] += [word(MANAGER+hit*0x4d8+12,c['token']),word(MANAGER+hit*0x4d8+8,rng.getrandbits(32))];c['args'][2]=rng.getrandbits(32);c['args'][3]=rng.getrandbits(32);c['args'][4]=rng.getrandbits(32);cases.append(c)
for free in [0,1,2,31,398,399]:
 for result in [0,1,0x100,0x101,0xffff0001,0xffffffff]:
  c=seed();c['compileResult']=result;c['writes'] += [word(MANAGER+8,1),word(MANAGER+free*0x4d8+8,0),word(MANAGER+0x79184,free-1)];cases.append(c)
for mode in range(256):c=seed();c['args'][2]=mode;c['args'][4]=mode;cases.append(c)
for fifth in [0x100,0xffffffff,0x80000000,0x10000001]:c=seed();c['args'][4]=fifth;cases.append(c)
c=seed();c['writes'] += [word(MANAGER+8,1)];c['compileResult']=0;cases.append(c)
for hit in [0,399]:
 c=seed();c['serviceWrites']={'0x744b70':[word(MANAGER+hit*0x4d8+12,c['token'])]};cases.append(c)
c=seed();c['serviceWrites']={hex(PREP):[word(MAT+0x40,2),word(MANAGER,VTABLE+0x100)]};cases.append(c)
c=seed();c['serviceWrites']={hex(COMPILE):[word(MANAGER+8,0xffffffff)]};cases.append(c)
c=seed();c['writes'] += [word(MANAGER+4+0x4cc,RES1)];c['serviceWrites']={hex(RELEASE):[word(MANAGER+4+0x4d0,RES2)]};cases.append(c)
# Replace syntheticresolver-token fixtures with tokens fromactualdescriptor+CRC for preparedcachehits.
common += [word(MAT+0x100,0),word(RUNTIME+0x1b8,0),word(RUNTIME+0x1bc,0)]
rot['common']=common
for i,c in enumerate(cases):
 c['lookupResult']=0;c['format']=0
 if '0x744b70' in c.get('serviceWrites',{}):
  if i<400:raise AssertionError('unexpectedhitfixturemutation')
  c['serviceWrites'].pop('0x744b70')
 if i<400:
  case=c;trace=[];tokens=[];im=Image(c);crc['initialize'](im,0);words=key['values'](im,dict(args=[0]+c['args'][:4]));value=tokenValue(im,words+[int((c['args'][4]&255)!=0)]);c['writes'] += [word(MANAGER+i*0x4d8+12,value)]
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];tokens=[];im=Image(c);crc['initialize'](im,0);pred=create(im,c);expectedTrace=trace[:];expectedTokens=tokens[:];trace=[];tokens=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x7461b0,regs={UC_X86_REG_ECX:0})
 rv=n.call(0x7416a0,c['args'],regs={UC_X86_REG_ECX:c['manager']},count=10000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=pred or actual!=im.hash() or trace!=expectedTrace or tokens!=expectedTokens:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=pred,nativeTrace=trace,modelTrace=expectedTrace,nativeTokens=tokens,modelTokens=expectedTokens));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace,tokens=tokens);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*4,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['manager vtable+8 preparation','manager vtable+4 compilation','COMresource release','5e5310texturelookup/COMformatprojection'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase96-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase96-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=common,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
