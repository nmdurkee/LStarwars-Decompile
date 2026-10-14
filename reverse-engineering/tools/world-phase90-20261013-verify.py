import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x90000,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

MANAGER=D+0x6000;OUTPUT=D+0x1000;RES1=D+0x2000;RES2=D+0x2100;TABLE=D+0x3000;PROGRAM=D+0x85000;TARGET=0x10300000
n.mu.mem_map(TARGET,0x1000);n.write(TARGET,b'\xc3');trace=[];case={}
def service(im,address,args):
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case.get('resetResult',0x12345678)
def clear(im,p):
 a=im.W(p+0x4cc)
 if a:target=im.W(im.W(a)+8);service(im,target,[a]);im.W(p+0x4cc,0)
 a=im.W(p+0x4d0)
 if a:target=im.W(im.W(a)+8);service(im,target,[a]);im.W(p+0x4d0,0)
 im.W(p,0xffffffff)
def select(im,manager,out):
 cursor=S(im.W(manager+0x79184));selected=S(U(cursor+1));found=False
 if selected<400:
  while selected<400:
   if S(im.W(U(manager+selected*0x4d8+8)))<=0:found=True;break
   selected+=1
 if not found:
  selected=0
  if cursor>0:
   while selected<cursor:
    if S(im.W(U(manager+selected*0x4d8+8)))<=0:found=True;break
    selected+=1
 if not found:return 0
 p=U(manager+selected*0x4d8+4);im.W(manager+0x79184,selected);clear(im,p);im.W(out,selected);return p
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
entries={}
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x7414c0,0x744010,0x7422d0,0x743930]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=TARGET:return
 sp=uc.reg_read(UC_X86_REG_ESP);rv=service(ni,a,list(n.unpack('<I',sp+4)));uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+(8 if a==TARGET else 4))
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(entry=0x7414c0,cursor=-1,free=0,ref=0):
 c=dict(entry=entry,manager=MANAGER,output=OUTPUT,program=PROGRAM,writes=[word(RES1,TABLE),word(RES2,TABLE),word(TABLE+8,TARGET),word(OUTPUT,0xdeadbeef)])
 if entry==0x7414c0:
  for i in range(-4,416):c['writes'] += [word(MANAGER+i*0x4d8+8,1)]
  if free is not None:c['writes'] += [word(MANAGER+free*0x4d8+8,ref)]
  c['writes'] += [word(MANAGER+0x79184,cursor)]
 return c
cases=[]
for cursor in [-4,-1,0,1,398,399,400,401,409]:
 for free in [-3,-1,0,1,2,31,397,398,399,400,408,None]:
  for ref in [0,0xffffffff,0x80000000]:cases.append(seed(cursor=cursor,free=free,ref=ref))
for a in [0,RES1]:
 for b in [0,RES2]:
  c=seed(0x744010);c['writes'] += [word(PROGRAM+0x4cc,a),word(PROGRAM+0x4d0,b)];cases.append(c)
for cursor in [-1,0,398,399]:
 c=seed(cursor=cursor,free=2);p=MANAGER+2*0x4d8+4;c['writes'] += [word(p+0x4cc,RES1)];c['serviceWrites']={hex(TARGET):[word(p+0x4d0,RES2),word(MANAGER+0x79184,123),word(p+4,0)]};cases.append(c)
for output in [MANAGER+0x79184,RES1,PROGRAM+4,MANAGER+4]:
 c=seed(cursor=-1,free=0);c['output']=output;cases.append(c)
for entry in [0x7422d0,0x743930]:
 for offset in range(4):c=seed(entry);c['program']=PROGRAM+offset;cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 if c['entry']==0x7414c0:pred=select(im,c['manager'],c['output'])
 elif c['entry']==0x744010:clear(im,c['program']);pred=None
 else:im.W(c['program'],0xffffffff);pred=c['program']
 expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(c['entry'],[c['output']],regs={UC_X86_REG_ECX:c['manager']}) if c['entry']==0x7414c0 else n.call(c['entry'],[c['program']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();checks+=2+(pred is not None)
 if actual!=im.hash() or pred is not None and rv!=pred or trace!=expectedTrace:errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash(),nativeResult=rv,modelResult=pred,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=pred,trace=trace);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['COMvtable+8 resource release'],seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase90-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase90-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
