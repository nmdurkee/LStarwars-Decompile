import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x90000,167),(0x297cc6c,4,0),(0x297ae20,4,0),(0x29765c8,0x658,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

M=D+0x1000;P1=D+0x2000;P2=D+0x3000;OLD=D+0x4000
PREP=0x10300000;COMPILE=PREP+0x100;IENTER=PREP+0x400;IEXIT=PREP+0x500;VTABLE=D+0x9000;firstProgram=0
n.mu.mem_map(PREP,0x1000)
for a in [PREP,COMPILE,IENTER,IEXIT]:n.write(a,b'\xc3')
n.write(0x7510b8,struct.pack('<I',IENTER));n.write(0x7510b4,struct.pack('<I',IEXIT))
trace=[];case={};counts={}
def service(im,address,args):
 key=hex(address);index=counts.get(key,0);counts[key]=index+1;trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 seq=case.get('sequenceWrites',{}).get(key,[])
 if index<len(seq):
  for p in seq[index]:im.write(p['address'],base64.b64decode(p['data']))
 if address==0x744b70:return U(0x12340000+args[2])
 if address==COMPILE:
  global firstProgram
  program=args[11];slot=args[12];im.W(program,slot);im.W(program+4,0);im.W(program+8,U(0x12340000+args[3]))
  if index==0:firstProgram=program
  elif case.get('mutateFirst',False):im.H(firstProgram,111)
  return 1
 if address in [PREP,0x7510b8,0x7510b4]:return 0
 values=case['responses'].get(key,[0]);return values[min(index,len(values)-1)]
def channel(im,at):
 f=F(im.W(at));t=f*255
 if not __import__('math').isfinite(t):return 0
 value=int(t);return value&255 if -2147483648<=value<2147483648 else 0
ctx=dict(rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64)
p=Path(__file__).with_name('world-phase86-20261013-verify.py');tree=ast.parse(p.read_text());node=next(x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name=='invoke');exec(compile(ast.Module(body=[node],type_ignores=[]),str(p),'exec'),ctx);leafService=service;ctx['port']=leafService
def loader(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);tree=ast.parse(p.read_text());selected=ast.Module(body=[x for x in tree.body if isinstance(x,ast.FunctionDef)],type_ignores=[]);env=dict(ctx,__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env
shaderKey=loader(89);slot=loader(90);slot['service']=leafService
p=Path(__file__).with_name('world-phase90-20261013-verify.py');ts=p.read_text();tt=ast.parse(ts);body=ast.get_source_segment(ts,next(x for x in tt.body if isinstance(x,ast.FunctionDef) and x.name=='select'));body=body.replace('if not found:return 0','if not found:return (0,None)').replace('im.W(out,selected);return p','return (p,selected)');exec(compile(body,str(p),'exec'),slot)
def factory(im,args):
 manager,runtime,material,mode,fourth,fifth=args;target=im.W(im.W(manager)+8);leafService(im,target,[manager,runtime,material]);key=shaderKey['values'](im,dict(args=[0,runtime,material,mode,fourth]));token=leafService(im,0x744b70,key+[int((fifth&255)!=0)])
 for i in range(400):
  if im.W(manager+i*0x4d8+12)!=token:continue
  p=U(manager+i*0x4d8+4)
  if p:im.W(p+4,U(im.W(p+4)+1));return p
  break
 p,index=slot['select'](im,manager,0);index=runtime if not p else index;target=im.W(im.W(manager)+4);rv=leafService(im,target,[manager]+key+[fifth,p,U(index)])
 if not rv&255:return 0
 im.W(p+4,U(im.W(p+4)+1));return p
# Platformwrapper import is guarded bytoken1..12.
def platform(im,address,args):
 token=args[0]
 if U(token-1)<=11:leafService(im,0x7510b8 if address==0x4ffaa0 else 0x7510b4,[0x91ef70+token*24])
 return 0
closed=[0x741620,0x7415b0,0x741770,0x741790,0x6e27d0,0x6e27f0,0x6df300,0x6df310]
def service(im,address,args):
 if address==0x7416a0:return factory(im,args)
 if address in [0x4ffaa0,0x4ffac0]:return platform(im,address,args)
 return ctx['invoke'](im,address,args) if address in closed else leafService(im,address,args)
ctx['port']=service
def refresh(im,c):
 m=c['material'];service(im,0x6df300,[]);count=S16(im.H(m+0x74))
 if count>0:
  im.W(m+0xb8,count)
  if im.B(m+0x15c)==0:im.B(m+0x15c,1)
  b=im.W(m+0x1f0)
  if b&0x3800==0:im.W(m+0x1f0,(b&0xffffcfff)|0x800)
 if im.W(m+0x44)&0x800000 and not im.W(m+0x3c):im.W(m+0x1f0,im.W(m+0x1f0)|0x40000)
 old=S16(im.H(m+0x1f4))
 if old>0:p=service(im,0x741620,[old]);service(im,0x7415b0,[p])
 old=S16(im.H(m+0x1f6))
 if old>0:p=service(im,0x741620,[old]);service(im,0x7415b0,[p])
 if im.W(m+0x44)&0x800000 and not im.W(m+0x3c):p=service(im,0x741770,[m+0xb4,m]);im.H(m+0x1f4,im.H(p))
 else:
  mode=service(im,0x6e27d0,[0x29765c8]);a=service(im,0x741790,[m+0xb4,m,mode]);mode=service(im,0x6e27f0,[0x29765c8]);b=service(im,0x741790,[m+0xb4,m,mode]);im.H(m+0x1f4,im.H(a));im.H(m+0x1f6,im.H(b))
 declaration=service(im,0x7418c0,[im.W(m+0x1f0)]);color=im.H(m+0x74)==0;im.W(m+0x2bc,declaration)
 if color:blue=channel(im,m+0x5c);green=channel(im,m+0x58);red=channel(im,m+0x54);im.W(m+0xc8,0xff000000|(blue<<16)|(green<<8)|red)
 service(im,0x6df310,[])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
entries={}
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.write(a,struct.pack('<I',U(v)))
 def H(self,a,v=None):
  if v is None:return n.unpack('<H',a)[0]
  n.write(a,struct.pack('<H',v&65535))
ni=NI()
def observe(uc,a,z,user):
 if a in [0x601030,0x741620,0x7415b0,0x741770,0x741790,0x6e27d0,0x6e27f0,0x6df300,0x6df310,0x4ffaa0,0x4ffac0,0x7416a0,0x744320,0x7414c0,0x744010,0x7422d0,0x743930]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [PREP,COMPILE,IENTER,IEXIT,0x744b70,0x7418c0]:return
 sp=uc.reg_read(UC_X86_REG_ESP)
 if a==PREP:args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<2I',sp+4));cleanup=12;logical=a
 elif a==COMPILE:p,fifth,program,index=n.unpack('<4I',sp+4);args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<9I',p))+[fifth,program,index];cleanup=20;logical=a
 elif a in [IENTER,IEXIT]:args=list(n.unpack('<I',sp+4));cleanup=8;logical=0x7510b8 if a==IENTER else 0x7510b4
 elif a==0x7418c0:args=list(n.unpack('<I',sp+4));cleanup=4;logical=a
 else:out,p,flag=n.unpack('<3I',sp+4);args=list(n.unpack('<9I',p))+[flag];cleanup=4;logical=a
 rv=leafService(ni,logical,args)
 if a==0x744b70:n.write(out,struct.pack('<I',rv))
 uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():return dict(material=M,responses={'0x741620':[OLD],'0x741770':[P1],'0x741790':[P1,P2],'0x6e27d0':[16],'0x6e27f0':[1],'0x7418c0':[0x12345678]},writes=[patch(M,bytes(0x300)),half(P1,10),half(P2,20),half(M+0x1f4,1),half(M+0x1f6,2),patch(M+0x54,struct.pack('<3f',.25,.5,.75))])
cases=[];rng=random.Random(2026101385)
for count in [0,1,2,32767,32768,65535]:
 for flag in [0,0x800000]:
  for linked in [0,P1]:
   for bits0 in [0,0x800,0x1000,0x2000,0x3800,0xffffffff]:
    c=seed();c['writes'] += [half(M+0x74,count),word(M+0x44,flag),word(M+0x3c,linked),word(M+0x1f0,bits0)];cases.append(c)
for index in [0,1,400,401,32767,32768,65535]:
 for other in [0,1,32768]:
  c=seed();c['writes'] += [half(M+0x1f4,index),half(M+0x1f6,other)];cases.append(c)
for color in [0,0x80000000,1,0x80000001,0x7f7fffff,0xff7fffff,0x7f800000,0xff800000,0x7fc00001,bits(.5),bits(1),bits(-1),bits(16777216),bits(-16777216)]:
 c=seed();c['writes'] += [patch(M+0x54,struct.pack('<3I',color,color,color))];cases.append(c)
for i in range(256):
 c=seed();c['writes'] += [patch(M+0x54,struct.pack('<3f',*[rng.uniform(-100000,100000) for j in range(3)]))];cases.append(c)
c=seed();c['sequenceWrites']={'0x741790':[[],[half(P1,111)]]};cases.append(c)
c=seed();c['serviceWrites']={'0x7415b0':[half(M+0x1f6,65535)]};cases.append(c)
c=seed();c['serviceWrites']={'0x6df300':[word(M+0x44,0x800000),half(M+0x74,7)]};cases.append(c)
c=seed();c['writes'] += [half(M+0x74,1)];c['serviceWrites']={'0x7418c0':[half(M+0x74,0),patch(M+0x54,struct.pack('<3f',.1,.2,.3))]};cases.append(c)
# First index output overlaps the second returned program WORD; secondread follows firstwrite.
c=seed();c['responses']['0x741790']=[P1,M+0x1f4];cases.append(c)
PROGRAMS=D+0x10000
prepared=[];excludedOld=[]
for c in cases:
 initial=Image(c)
 if any(400<S16(initial.H(c['material']+f))<=32767 for f in [0x1f4,0x1f6]):excludedOld.append(dict(case=cases.index(c),reason='positiveoldprogramindex>400 maps0and subsequent originalrelease addressesunreadable4; outsidepreparedreadable domain'));continue
 c['writes'] += [word(0x297cc6c,PROGRAMS),word(0x297ae20,0),byte(0x29765c8+0x654,0x20)]
 c['responses']['0x7416a0']=c['responses'].get('0x741790',[P1,P2])
 for field in ['serviceWrites','sequenceWrites']:
  if field in c:
   for old,new in [('0x741790','0x7416a0'),('0x6df300','0x4ffaa0'),('0x6df310','0x4ffac0')]:
    if old in c[field]:c[field][new]=c[field].pop(old)
   for old in ['0x741620','0x7415b0','0x741770','0x6e27d0','0x6e27f0']:c[field].pop(old,None)
 prepared.append(c)
cases=prepared
rot['common']=[word(PROGRAMS,VTABLE),word(VTABLE+8,PREP),word(VTABLE+4,COMPILE),word(PROGRAMS+0x79184,0xffffffff)]
for i in range(400):rot['common'] += [word(PROGRAMS+i*0x4d8+8,0),word(PROGRAMS+i*0x4d8+12,0xffffffff),word(PROGRAMS+i*0x4d8+4+0x4cc,0),word(PROGRAMS+i*0x4d8+4+0x4d0,0)]
for c in cases:
 for field in ['serviceWrites','sequenceWrites']:
  if field in c:
   if '0x7416a0' in c[field]:
    # Returned-pointer fixture from87 is replacedby actualphysicalcache-slot allocation; no oldarbitrarypointercredit.
    if field=='sequenceWrites':c['mutateFirst']=True
    c[field].pop('0x7416a0',None)
   for old,new in [('0x4ffaa0','0x7510b8'),('0x4ffac0','0x7510b4')]:
    if old in c[field]:c[field][new]=c[field].pop(old);c['writes'] += [word(0x297ae20,1)]
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};firstProgram=0;im=Image(c);refresh(im,c);expectedTrace=trace[:];trace=[];counts={};firstProgram=0;initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x601030,[c['material']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified raw refinement' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['IATcriticalsectionimports onlegalnonzerotoken','manager vtable+8 prepare/+4 compile','744b70 readonlyprivatekey tokenresolver','7418c0 declaration'],seconds=round(time.time()-start,3),syntheticExcluded=len(excludedOld),excluded=excludedOld)
(B/'reports/world-phase92-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase92-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
