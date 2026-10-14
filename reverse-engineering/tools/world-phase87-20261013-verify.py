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
trace=[];case={};counts={}
def service(im,address,args):
 key=hex(address);index=counts.get(key,0);counts[key]=index+1;trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 seq=case.get('sequenceWrites',{}).get(key,[])
 if index<len(seq):
  for p in seq[index]:im.write(p['address'],base64.b64decode(p['data']))
 values=case['responses'].get(key,[0]);return values[min(index,len(values)-1)]
def channel(im,at):
 f=F(im.W(at));t=f*255
 if not __import__('math').isfinite(t):return 0
 value=int(t);return value&255 if -2147483648<=value<2147483648 else 0
ctx=dict(rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64)
p=Path(__file__).with_name('world-phase86-20261013-verify.py');tree=ast.parse(p.read_text());node=next(x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name=='invoke');exec(compile(ast.Module(body=[node],type_ignores=[]),str(p),'exec'),ctx);leafService=service;ctx['port']=leafService
closed=[0x741620,0x7415b0,0x741770,0x741790,0x6e27d0,0x6e27f0,0x6df300,0x6df310]
def service(im,address,args):return ctx['invoke'](im,address,args) if address in closed else leafService(im,address,args)
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
ni=NI()
def observe(uc,a,z,user):
 if a in [0x601030,0x741620,0x7415b0,0x741770,0x741790,0x6e27d0,0x6e27f0,0x6df300,0x6df310]:entries[hex(a)]=entries.get(hex(a),0)+1
 arguments={0x4ffaa0:1,0x4ffac0:1,0x7416a0:5,0x7418c0:1}
 if a not in arguments:return
 sp=uc.reg_read(UC_X86_REG_ESP);cnt=arguments[a];args=[uc.reg_read(UC_X86_REG_ECX)] if cnt<0 else list(n.unpack('<%dI'%cnt,sp+4)) if cnt else [];args=([uc.reg_read(UC_X86_REG_ECX)]+args) if a==0x7416a0 else args;rv=leafService(ni,a,args);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+(24 if a==0x7416a0 else 4))
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
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);refresh(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x601030,[c['material']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed qualified raw refinement' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['4ffaa0/4ffac0 platformlock','7416a0 shaderfactory','7418c0 declaration'],seconds=round(time.time()-start,3),syntheticExcluded=len(excludedOld),excluded=excludedOld)
(B/'reports/world-phase87-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase87-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
