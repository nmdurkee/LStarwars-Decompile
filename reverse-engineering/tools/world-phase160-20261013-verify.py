import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x829ac0,184,0),(0x297c190,4,0),(0x829580,4,0),(0x297c550,0x314,0),(0x751000,0x300,0),(0x778000,0x1000,0),(0x76aa40,32,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

TABLEDATA=n.read(0x829ac0,184);STRINGS=n.read(0x778000,0x1000);BANNERSTRING=n.read(0x76aa40,32);GETSTD=0x10300000;FILENAME=GETSTD+0x100;WRITE=GETSTD+0x200;n.mu.mem_map(GETSTD,0x1000)
for a in [GETSTD,FILENAME,WRITE]:n.write(a,b'\xc3')
trace=[];case={};counts={};entries={}
def string(im,p):
 out=bytearray()
 while im.B(p):out.append(im.B(p));p=U(p+1)
 return bytes(out)
def service(im,address,args):
 if address in [0x6f8503,0x702217,0x7021a6]:return secure['apply'](im,dict(entry=address,args=args))
 trace.append([address,args]);key=hex(address);index=counts.get(key,0);counts[key]=index+1
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 if address==GETSTD:return case['handle']
 if address==FILENAME:
  if case['filenameResult']:im.write(args[1],case['filename'].encode()+bytes([0]))
  return case['filenameResult']
 if address in [0x6f8503,0x702217,0x7021a6]:
  values=case['copyResults'] if address==0x6f8503 else case['truncateResults'] if address==0x702217 else case['appendResults'];result=values[min(index,len(values)-1)]
  if not result:
   content=string(im,args[2]);out=args[0]
   if address==0x702217:content=content[:args[3]]
   if address==0x7021a6:out+=len(string(im,out))
   im.write(out,content+bytes([0]))
  return result
 return case['endpoint']
def length(im,p):
 while im.B(p):p=U(p+1)
 return p
def strlen(im,p):return U(length(im,p)-p)
def watson(im):service(im,0x6e9e8e,[0]*5)
def apply(im,c):
 code=c['args'][0];index=0
 while index<23 and im.W(0x829ac0+index*8)!=code:index+=1
 if index==23:return
 if im.W(0x297c190)==1 or (im.W(0x297c190)==0 and im.W(0x829580)==1):
  handle=service(im,im.W(0x7511dc),[0xfffffff4])
  if handle in [0,0xffffffff]:return
  z=strlen(im,im.W(0x829ac4+index*8));service(im,im.W(0x7510e8),[handle,im.W(0x829ac4+index*8),z,c['writtenPointer'],0]);return
 if code==252:return
 buffer=0x297c550;path=0x297c569
 if service(im,0x6f8503,[buffer,0x314,0x7785c8]):watson(im)
 im.B(0x297c66d,0)
 if not service(im,im.W(0x751150),[0,path,0x104]) and service(im,0x6f8503,[path,0x2fb,0x7785b0]):watson(im)
 if U(strlen(im,path)+1)>60:
  tail=U(strlen(im,path)+path-59)
  if service(im,0x702217,[tail,U(0x297c864-tail),0x7785ac,3]):watson(im)
 if service(im,0x7021a6,[buffer,0x314,0x7785a8]):watson(im)
 if service(im,0x7021a6,[buffer,0x314,im.W(0x829ac4+index*8)]):watson(im)
 service(im,0x701fe9,[buffer,0x778580,0x12010])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def B(self,a,v=None):
  if v is None:return n.read(U(a),1)[0]
  n.write(U(a),bytes([v&255]))
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address in [0x6f09f8,0x7022ca,0x6edd80,0x6f8503,0x702217,0x7021a6]:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [GETSTD,FILENAME,WRITE,0x701fe9,0x6e9e8e]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=1 if address==GETSTD else 4 if address==0x702217 else 5 if address in [WRITE,0x6e9e8e] else 3;args=list(n.unpack('<'+'I'*count,sp+4));value=service(ni,address,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4+(count*4 if address in [GETSTD,FILENAME,WRITE] else 0));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
secure=dict(__file__=str(B/'tools/world-phase159-20261013-verify.py'),U=U,S=S,service=service);module=ast.parse((B/'tools/world-phase159-20261013-verify.py').read_text());exec(compile(ast.Module(body=[x for x in module.body if isinstance(x,ast.FunctionDef) and x.name in ['error','apply']],type_ignores=[]),'secure159','exec'),secure)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013160);cases=[]
def seed(code,mode=0,app=0):return dict(args=[code],writtenPointer=0x1000dffc,handle=0xabcdef01,filename='C:/game/LEGOStarWarsSaga.exe',filenameResult=26,copyResults=[0],truncateResults=[0],appendResults=[0],endpoint=0xfedcba98,writes=[patch(0x829ac0,TABLEDATA),patch(0x778000,STRINGS),patch(0x76aa40,BANNERSTRING),word(0x297c190,mode),word(0x829580,app),word(0x7511dc,GETSTD),word(0x751150,FILENAME),word(0x7510e8,WRITE)])
for i in range(384):
 c=seed(struct.unpack_from('<I',TABLEDATA,(i%23)*8)[0] if i%7 else rng.getrandbits(32),rng.choice([0,1,2,3,0xffffffff]),rng.choice([0,1,2]));c.update(handle=rng.choice([0,0xffffffff,rng.getrandbits(32)]),filename='C:/'+('a'*rng.choice([0,26,55,56,57,58,59,60,100,200,256])),filenameResult=0 if i%11==0 else 1);cases.append(c)
for index in [0,22]:
 c=seed(struct.unpack_from('<I',TABLEDATA,index*8)[0],1,0);c['serviceWrites']={hex(GETSTD):[word(0x829ac4+index*8,D+0x100),patch(D+0x100,b'changed message\0')]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 n.call(0x6f09f8,c['args'],count=300000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase160-20261013-ptl-runtime-diagnostic-secure-cpu.cs').read_bytes()).hexdigest(),originalBodySpan=dict(address='0x6f09f8',length=416,sha256=hashlib.sha256(n.read(0x6f09f8,416)).hexdigest()),ghidraOwnedBytes=399,returningWatsonGapBytes=17,domain='complete diagnostic writer own control flow with actual mode and strlen; fixed readable 23-row table, missing keys, console/GUI modes, invalid handles, filename fallback and truncation boundaries, callback mutations; actual secure-string children and Watson returning projection; private WriteFile out-cell supplied explicitly, incidental EAX excluded',nativeAdapters=['Win32 GetStdHandle/GetModuleFileNameA/WriteFile','701fe9 message box wrapper','returning Watson suspension'],reaEvidenceIds=['ev_d34f1071673b0e70cedfdefe8452ed397ec865b42c335ccfb262739d8040faa5','ev_e26950b0c8afdccd768980e787198755d2ec263bc292df590cc4db23b5fe133a','ev_320838c3d0c8e4a9104d89d09cfff86b1cde26a00e0ae3899dc1cf5e0a5360d9'],additionalAddressCredit=0,syntheticExcluded=6,syntheticExcludedReason='prior fake secure-string failure callbacks removed; no equivalence credit',managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase160-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase160-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
