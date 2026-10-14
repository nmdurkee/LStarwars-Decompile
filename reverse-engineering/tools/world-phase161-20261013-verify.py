import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;PUBLICREGIONS=[(D,0x10000,167),(0x297cb44,24,0),(0x297c1b4,16,0),(0x751000,0x300,0)];REGIONS=PUBLICREGIONS+[(0x1000dfdc,32,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

Image.hash=lambda im:hashlib.sha256(b''.join(im.read(a,z) for a,z,f in PUBLICREGIONS)).hexdigest()
BASE=0x10300000;LOAD=BASE;PROC=BASE+0x100;BOX=BASE+0x200;ACTIVE=BASE+0x300;POPUP=BASE+0x400;INFO=BASE+0x500;STATION=BASE+0x600;n.mu.mem_map(BASE,0x1000)
for a in [LOAD,PROC,BOX,ACTIVE,POPUP,INFO,STATION]:n.write(a,b'\xc3')
COOKIE=0x55aa55aa;trace=[];case={};counts={};entries={}
def service(im,address,args):
 trace.append([address,args]);key=hex(address);index=counts.get(key,0);counts[key]=index+1
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 if address in [0x6f01bc,0x6f0145]:return args[0]^case['cookie']
 if address==LOAD:return case['module']
 if address==PROC:return case['procedures'].get(hex(args[1]),0)
 if address==ACTIVE:return case['activeWindow']
 if address==POPUP:return case['popupWindow']
 if address==STATION:return case['station']
 if address==INFO:
  if case['infoResult']:im.W(args[2]+8,case['infoFlags']);im.W(args[4],12)
  return case['infoResult']
 if address==0x6ead5f:return case['errnoPointer']
 return case['endpoint']
def invalid(im):
 im.W(service(im,0x6ead5f,[]),22);service(im,0x6e9fc2,[0]*5);return 22
def platform(im,p):
 value=im.W(0x297c1b4)
 if not value:return invalid(im)
 im.W(p,value);return 0
def major(im,p):
 if not im.W(0x297c1b4):return invalid(im)
 im.W(p,im.W(0x297c1c0));return 0
def watson(im):service(im,0x6e9e8e,[0]*5)
def encode(im,p):return service(im,0x6f0145,[p])
def decode(im,p):return service(im,0x6f01bc,[p])
def apply(im,c):
 if c.get('nullOnly'):return encode(im,0)
 text,caption,flags=c['args'];frame=c['frame'];encodedNull=encode(im,0);owner=0;im.W(frame-12,0);im.W(frame-16,0)
 if not im.W(0x297cb44):
  module=service(im,im.W(0x75106c),[0x7807c4])
  if not module:return 0
  procedure=im.W(0x7511b0);target=service(im,procedure,[module,0x7807b8])
  if not target:return 0
  im.W(0x297cb44,encode(im,target));im.W(0x297cb48,encode(im,service(im,procedure,[module,0x7807a8])));im.W(0x297cb4c,encode(im,service(im,procedure,[module,0x780794])))
  if platform(im,frame-12):watson(im)
  if im.W(frame-12)==2:
   info=encode(im,service(im,procedure,[module,0x780778]));im.W(0x297cb54,info)
   if info:im.W(0x297cb50,encode(im,service(im,procedure,[module,0x780760])))
 active=True;stationEncoded=im.W(0x297cb50)
 if stationEncoded!=encodedNull and im.W(0x297cb54)!=encodedNull:
  stationTarget=decode(im,stationEncoded);infoTarget=decode(im,im.W(0x297cb54))
  if stationTarget and infoTarget:
   station=service(im,stationTarget,[]);visible=False
   if station:
    result=service(im,infoTarget,[station,1,frame-32,12,frame-20]);visible=bool(result and im.B(frame-24)&1)
   if not visible:
    if major(im,frame-16):watson(im)
    flags|=0x200000 if im.W(frame-16)>=4 else 0x40000;active=False
 if active:
  target=im.W(0x297cb48)
  if target!=encodedNull:
   target=decode(im,target)
   if target:
    owner=service(im,target,[])
    if owner:
     target=im.W(0x297cb4c)
     if target!=encodedNull:
      target=decode(im,target)
      if target:owner=service(im,target,[owner])
 message=decode(im,im.W(0x297cb44));return service(im,message,[owner,text,caption,flags]) if message else 0
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address in [0x701fe9,0x6f01b3,0x6ebe42,0x6ebef1]:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [LOAD,PROC,BOX,ACTIVE,POPUP,INFO,STATION,0x6f01bc,0x6f0145,0x6ead5f,0x6e9fc2,0x6e9e8e]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if address in [ACTIVE,STATION,0x6ead5f] else 1 if address in [LOAD,POPUP,0x6f01bc,0x6f0145] else 2 if address==PROC else 4 if address==BOX else 5;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];value=service(ni,address,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4+(count*4 if address in [LOAD,PROC,BOX,ACTIVE,POPUP,INFO,STATION] else 0));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013161);cases=[]
def seed():return dict(args=[D+0x1000,D+0x2000,0x12010],frame=0x1000dffc,cookie=COOKIE,module=1,activeWindow=0xabc,popupWindow=0xdef,station=0x123,infoResult=1,infoFlags=1,errnoPointer=D+0x100,endpoint=0xfedcba98,procedures={'0x7807b8':BOX,'0x7807a8':ACTIVE,'0x780794':POPUP,'0x780778':INFO,'0x780760':STATION},writes=[word(0x75106c,LOAD),word(0x7511b0,PROC),word(0x297c1b4,2),word(0x297c1c0,6)])
for i in range(512):
 c=seed();c.update(cookie=COOKIE if i&1 else 0,module=0 if i%13==0 else 1,activeWindow=rng.choice([0,0xabc]),popupWindow=rng.choice([0,0xdef]),station=rng.choice([0,0x123]),infoResult=i%3!=0,infoFlags=rng.getrandbits(32));c['args'][2]=rng.getrandbits(32);c['writes'] += [word(at,c['cookie']) for at in [0x297cb48,0x297cb4c,0x297cb50,0x297cb54]]
 for name in list(c['procedures']):
  if rng.randrange(4)==0:c['procedures'][name]=0
 c['writes'] += [word(0x297c1b4,rng.choice([0,1,2,3])),word(0x297c1c0,rng.choice([0,3,4,6,0xffffffff]))]
 if i%3==0:
  for at,target in [(0x297cb44,BOX),(0x297cb48,ACTIVE),(0x297cb4c,POPUP),(0x297cb50,STATION),(0x297cb54,INFO)]:c['writes'].append(word(at,(target if rng.randrange(3) else 0)^c['cookie']))
 cases.append(c)
for cookie in [0,COOKIE,0xffffffff]:
 c=seed();c.update(nullOnly=True,cookie=cookie,args=[]);cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 result=n.call(0x6f01b3 if c.get('nullOnly') else 0x701fe9,c['args'],count=300000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in PUBLICREGIONS)).hexdigest()
 if result!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=result,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(result=result,trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase161-20261013-ptl-runtime-message-box.cs').read_bytes()).hexdigest(),originalBodySpan=dict(address='0x701fe9',length=445,sha256=hashlib.sha256(n.read(0x701fe9,445)).hexdigest()),encodedNullBodySha256=hashlib.sha256(n.read(0x6f01b3,9)).hexdigest(),ghidraOwnedBytes=439,returningWatsonGapBytes=6,domain='full message-box own dispatch and encoded-null helper, cached import targets/global publication, coherent startup encoded-null optional fields, encoded-null sentinel comparisons, station visibility and major-version flags, active window/popup selection, actual platform/major getters; private frame is a supplied value projection excluded from public image hash and stack alias claims',nativeAdapters=['pointer codec children','Win32 LoadLibrary/GetProc/MessageBox/window/station information value endpoints','errno pointer and returning invalid/Watson dispatcher'],reaEvidenceIds=['ev_e2a8e838aaf454f8e64c6683e60caeedcbd604e951ba17001bff233ec6ce1432','ev_5dbcb236aad5b73f55760e57a1c5c9fb12c899e7f76cf32d272c0bd7de1fd903','ev_e97da604485491a123b55a80bcc26f6f4cb397f15885748f86e1e939bd187972','ev_e9f058f21c20dcafd36307d441261cd849d9208cb374202d959fba027a14cce7'],managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase161-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase161-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],hashRegions=[dict(address=a,length=z,fill=f) for a,z,f in PUBLICREGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
