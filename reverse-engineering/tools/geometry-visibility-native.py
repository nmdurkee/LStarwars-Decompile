"""Native scene visibility/LOD/fade and registration contract checks, with frustum oracle explicit."""
import importlib.util,json,struct,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent
sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI,UC_X86_REG_ECX
n=nx.NativeX86();hooks={};tests=[];calls=[]
def hook(mu,address,size,data):
 if address in hooks:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];argc,action=hooks[address];args=n.unpack('<'+'I'*argc,sp+4)if argc else ()
  result=action(args)if action else 0;mu.reg_write(UC_X86_REG_EAX,result or 0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
def check(name,actual,expected):tests.append({'name':name,'passed':actual==expected,**({}if actual==expected else {'actual':actual,'expected':expected})})
def fade(d,start,end):
 if end<=start:
  if d<=end*end:return 0.
  numerator=f32(math.sqrt(d))-end;denominator=start-end
  if not denominator:return float('nan') if numerator==0 else 1.
  value=f32(numerator/denominator);return 1. if value>1 else value
 if d<=start*start:return 1.
 return max(0.,f32((end-f32(math.sqrt(d)))/(end-start)))

# Scene visibility, LOD, far limit and alpha use original5f5380 with only the
# frustum predicate stubbed. The optional debug occlusion mode is disabled in
# original globals; original5c60a0 and5df7b0/sqrt execute unchanged.
scene=n.DATA;vis=scene+0x100;lod=scene+0x200;far=scene+0x300;bounds=scene+0x400;flags=scene+0x500;fades=scene+0x600;clips=scene+0x800
matbits=[scene+0x1000,scene+0x1100];clipbits=[scene+0x1200,scene+0x1300];cursor=scene+0x1400;alpha=scene+0x8000
n.pack('<I',0x9736e0,cursor);n.pack('<3f',0x973718,0,0,0);n.write(0x80bbe0,b'\0\0')
n.pack('<I',scene+0x10,6);n.pack('<I',scene+0x14,clips);n.pack('<I',scene+0x28,lod);n.pack('<I',scene+0x2c,far);n.pack('<2I',scene+0x30,*clipbits);n.pack('<I',scene+0x44,bounds);n.pack('<I',scene+0x48,flags);n.pack('<2I',scene+0x58,*matbits)
thresholds=[100.,25.,0.,64.,0.,0.];limits=[101.,102.,103.,104.,105.,106.];n.pack('<6f',lod,*thresholds);n.pack('<6f',far,*limits);fadepairs=[(2.,8.),(12.,3.),(4.,4.)];n.pack('<6f',fades,*[v for p in fadepairs for v in p])
for i in range(6):
 ids=scene+0x1800+i*16;n.pack('<2I',ids,i,i+8);n.pack('<3I',clips+i*12,2,ids,0)
for i in range(3):n.pack('<8f',bounds+i*32,0,0,0,0,1,1,1,0)
hooks[0x5d69a0]=(3,lambda a:calls.append(a)or frustumResult)
visibilityCases=0;maxAlphaError=0.
for parity in [0,1]:
 for distance in [0.,2.,4.999,5.,5.001,7.999,8.,8.001,9.999,10.,10.001,20.]:
  for mode in ['all','hidden','tree','portal','portal-bypass','portal-disabled']:
   for frustumResult in [0,1,2]:
    vf=[0x41,0x41,0x41]
    if mode=='hidden':vf[1]=0x40
    if mode=='portal-bypass':vf[0]|=8
    n.write(flags,bytes(vf));n.pack('<I',scene+0x74,parity*0x8000);n.pack('<I',scene+0xc,fades);n.pack('<I',cursor,alpha);n.write(alpha,b'\0'*24)
    n.write(vis,b'\0'*0x30);tree=scene+0x1a00;portal=scene+0x1a10;n.write(tree,b'\2');n.write(portal,b'\4')
    n.pack('<I',vis+0x24,tree if mode in ['tree','portal','portal-bypass','portal-disabled']else 0)
    n.pack('<I',vis+0x18,1 if mode.startswith('portal')else 0);n.pack('<I',vis+0x1c,portal);n.pack('<I',0x80ba58,0 if mode=='portal-disabled'else 1)
    for i in range(3):n.pack('<f',bounds+i*32,distance+i)
    for p in matbits+clipbits:n.write(p,b'\0'*4)
    calls.clear();n.call(0x5f5380,[vis],regs={UC_X86_REG_ESI:scene})
    expectedCalls=[];expectedMat=bytearray(4);expectedClip=bytearray(4);expectedAlpha={};clip=0
    for i in range(3):
     visible=mode not in ['tree','portal','portal-bypass','portal-disabled']or i==1
     if mode.startswith('portal')and mode!='portal-disabled':visible=bool(vf[i]&8)or i==2
     if visible and vf[i]&1:
      d=f32(f32(distance+i)**2)
      while thresholds[clip]!=0 and d<thresholds[clip]:clip+=1
      fc=fadepairs[i][1]if vf[i]&64 and fadepairs[i][0]<fadepairs[i][1]else limits[clip]
      expectedCalls.append((bounds+i*32,bounds+i*32+16,bits(fc)))
      if frustumResult:
       for m in [clip,clip+8]:expectedMat[m>>3]|=1<<(m&7)
       expectedClip[clip>>2]|=frustumResult<<((clip&3)*2);expectedAlpha[clip]=fade(d,*fadepairs[i])
     while thresholds[clip]!=0:clip+=1
     clip+=1
    label='scene-'+str((parity,distance,mode,frustumResult));check(label+'-frustum-inputs',calls,expectedCalls)
    check(label+'-material-bits',n.read(matbits[parity],4).hex(),expectedMat.hex());check(label+'-clip-bits',n.read(clipbits[parity],4).hex(),expectedClip.hex())
    actual=n.unpack('<6f',alpha)
    for k,value in expectedAlpha.items():
     err=abs(actual[k]-value);maxAlphaError=max(maxAlphaError,err);check(label+'-alpha-'+str(k),err<=1e-7,True)
    visibilityCases+=1

# Original clip-state patcher: unchanged32-bit words are deliberately not
# touched, changed words set both each mesh item and its preceding transform.
hooks.clear();items=n.DATA+0x20000;clipdefs=items+0x2000;counts=items+0x3000;cb0=items+0x3100;cb1=items+0x3200
n.pack('<I',scene+8,items);n.pack('<I',scene+0x14,clipdefs);n.pack('<I',scene+0x18,counts);n.pack('<2I',scene+0x30,cb0,cb1)
clipPatchCases=0
for count in [1,4,15,16,17,33]:
 for parity in [0,1]:
  for sameWord in [False,True]:
   n.pack('<I',scene+0x10,count);n.pack('<I',scene+0x74,parity*0x8000);n.write(items,b'\xcc'*(count*32));current=bytearray(((count+15)//16)*4);previous=bytearray(len(current));expected=bytearray(b'\xcc'*(count*32))
   for i in range(count):
    ix=clipdefs+0x800+i*4;n.pack('<I',ix,i*2+1);n.pack('<3I',clipdefs+i*12,0,0,ix);n.pack('<H',counts+i*2,1);current[i>>2]|=(i%4)<<((i&3)*2)
   previous[:]=current if sameWord else bytes([255])*len(current)
   n.write([cb0,cb1][parity],current);n.write([cb0,cb1][1-parity],previous)
   for i in range(count):
    word=i//16*4
    if current[word:word+4]!=previous[word:word+4]:expected[i*32+1]=expected[i*32+17]=3 if i%4 else 0
   n.call(0x5df910,regs={UC_X86_REG_ESI:scene});check('clip-control-'+str((count,parity,sameWord)),n.read(items,count*32).hex(),expected.hex());clipPatchCases+=1

# Original registration inserts equal signed keys before existing entries and
# prepends its UV set; source reset5ddd10 is stubbed to isolate registration.
hooks={a:(0,None)for a in [0x4ffaa0,0x4ffac0,0x5ddd10,0x603980,0x6039b0,0x5c1300]}
n.pack('<I',0x9739b8,0);n.pack('<I',0x973ecc,0);n.pack('<I',0x973ec8,0);n.pack('<I',0x973fa8,0);expectedSort=[];sceneList=[];uvSets=[];registrationCases=0
for ordinal,keys in enumerate([[5,-2,5],[0,100,-50],[5],[0x7ffffff0,-0x7ffffff0]]):
 s=n.DATA+0x40000+ordinal*0x2000;records=s+0x100;aset=s+0x300;bias=[0,1,-1,1][ordinal]
 n.write(s,b'\0'*0x100);n.pack('<2I',s+0x60,len(keys),records);n.pack('<I',s+0x8c,aset);n.pack('<I',s+0x74,0xffffffff);n.pack('<I',s+0x68,0x1234);n.pack('<I',0x973ff4,bias&0xffffffff)
 for i,key in enumerate(keys):n.pack('<i',records+i*36,key)
 n.call(0x5ded80,[s]);sceneList.append(s);uvSets.insert(0,aset)
 for i,key in enumerate(keys):
  key=(key+(bias<<17))&0xffffffff;key=key-0x100000000 if key>=0x80000000 else key;pos=next((j for j,p in enumerate(expectedSort)if key<=p[1]),len(expectedSort));expectedSort.insert(pos,(records+i*36,key))
 actual=[];p=n.unpack('<I',0x973ecc)[0]
 while p:actual.append((p,n.unpack('<i',p)[0]));p=n.unpack('<I',p+8)[0];assert len(actual)<100
 check('register-sort-'+str(ordinal),actual,expectedSort);check('register-order-'+str(ordinal),list(n.unpack('<'+'I'*len(sceneList),0x9739bc)),sceneList)
 check('register-flags-'+str(ordinal),n.unpack('<I',s+0x74)[0],0xffffdfef);check('register-alpha-reset-'+str(ordinal),n.unpack('<I',s+0x68)[0],0);registrationCases+=1
for ordinal in [1,3,0,2]:
 s=n.DATA+0x40000+ordinal*0x2000;n.call(0x5dee40,[s]);sceneList.remove(s);expectedSort=[p for p in expectedSort if not s+0x100<=p[0]<s+0x300];uvSets.remove(s+0x300)
 actual=[];p=n.unpack('<I',0x973ecc)[0]
 while p:actual.append((p,n.unpack('<i',p)[0]));p=n.unpack('<I',p+8)[0];assert len(actual)<100
 actualUv=[];p=n.unpack('<I',0x973fa8)[0]
 while p:actualUv.append(p);p=n.unpack('<I',p+12)[0];assert len(actualUv)<100
 check('unregister-sort-'+str(ordinal),actual,expectedSort);check('unregister-order-'+str(ordinal),list(n.unpack('<'+'I'*len(sceneList),0x9739bc))if sceneList else [],sceneList);check('unregister-uv-chain-'+str(ordinal),actualUv,uvSets);check('unregister-count-'+str(ordinal),n.unpack('<I',0x9739b8)[0],len(sceneList));registrationCases+=1
# Direct float-return wrapper stores original ST0 to float32. Fractional fade
# endpoints and nearest float32 squared-distance boundaries exercise x87
# comparison precision; no square root or division helper is replaced.
hooks.clear();wrapper=n.DATA+0xf0000;out=wrapper+0x200
prefix=bytes.fromhex('ff74240cff74240cff74240c');call=wrapper+len(prefix)
n.write(wrapper,prefix+b'\xe8'+struct.pack('<i',0x5df7b0-(call+5))+bytes.fromhex('83c40cd91d')+struct.pack('<I',out)+b'\xc3')
fadeCases=0;fadeSamples=[]
for start,end in [(0.,1.),(1.,0.),(2.,8.),(12.,3.),(4.,4.),(.1,.3),(.3,.1),(-2.,3.),(-3.,-1.)]:
 start,end=f32(start),f32(end);distances={0.,1.,4.,16.,100.}
 for endpoint in [start,end]:
  sq=f32(endpoint*endpoint);u=bits(sq)
  for raw in [max(0,u-1),u,u+1]:distances.add(struct.unpack('<f',struct.pack('<I',raw))[0])
 for distance in sorted(distances):
  n.call(wrapper,[bits(distance),bits(start),bits(end)]);actual=n.unpack('<f',out)[0];expected=fade(distance,start,end);error=abs(actual-expected);maxAlphaError=max(maxAlphaError,error)
  check('fade-helper-'+str((distance,start,end)),(math.isnan(actual)and math.isnan(expected))or error<=1e-7,True);fadeSamples.append({'input':[distance,start,end],'native':actual if math.isfinite(actual)else str(actual),'nativeFloatBits':hex(bits(actual))});fadeCases+=1
alphaCases=0
for value in [-100.,-1.,-0.,0.,.25,1.,2.,100.,float('nan'),float('inf'),-float('inf')]:
 item=n.DATA+0xe0000;matrix=item+0x100;n.pack('<I',item+4,matrix);n.pack('<I',matrix+0x3c,0xcccccccc)
 n.call(0x603ad0,[item,0,bits(value)]);expected=0. if value<0 else 1. if value>1 else value
 check('alpha-clamp-'+str(value),n.unpack('<I',matrix+0x3c)[0],bits(expected));alphaCases+=1

# Original world-scene wrapper601df0 dereferences GSNH+110, then5f5830 selects
# normal/shadow visibility and emits eligible named specials. Downstream
# visibility and special submission endpoints are deliberately intercepted.
hooks.clear();header=n.DATA+0x90000;sc=header+0x1000;vs=header+0x2000;specials=header+0x3000;vflags=header+0x4000;portalBits=header+0x4100;events=[]
n.pack('<I',header+0x110,sc);n.write(sc,b'\0'*0x100);n.pack('<I',sc+0x78,header);n.pack('<I',sc+0x10,1);n.pack('<I',sc+0x6c,4);n.pack('<I',sc+0x70,specials);n.pack('<I',sc+0x48,vflags)
n.write(vs,b'\0'*0x40);n.pack('<I',vs+0x1c,portalBits);n.write(portalBits,b'\2');n.write(vflags,bytes([8,1,1,1]));n.pack('<I',0x973fcc,0);n.pack('<I',0x973fd0,0);n.pack('<I',0x80ba58,1)
hooks[0x5fd0d0]=(1,None);hooks[0x5f3c80]=(2,lambda a:vs);hooks[0x603960]=(1,None)
hooks[0x5f5380]=(1,lambda a:events.append(['normal',a[0]]));hooks[0x5f0ac0]=(0,lambda a:events.append(['shadow']))
def special_call(a):
 h=n.unpack('<3I',a[0]);events.append(['special',h[0],h[2],a[1],list(a[2:])])
hooks[0x5f0f00]=(5,special_call)
specialCases=0
for shadow in [False,True]:
 for blockedVisibility in [False,True]:
  for portal in [False,True]:
   for suppress in [False,True]:
    for matrixMode in [0,-1,1]:
     n.pack('<I',0x9718dc,1 if shadow else 0);n.pack('<I',vs+0x28,1 if blockedVisibility else 0);n.pack('<I',vs+0x18,1 if portal else 0);n.pack('<I',0x80bab4,1 if portal else 0);n.pack('<I',sc+0x74,0x10000 if suppress else 0)
     for i in range(4):
      p=specials+i*208;n.write(p,b'\0'*208);n.pack('<I',p+0xb8,2 if i!=3 else 0);n.pack('<I',p+0xc0,i);n.pack('<I',p+0xc4,(matrixMode if matrixMode!=1 else p+0x600)&0xffffffff)
     events.clear();n.call(0x601df0,[header]);expected=[]
     if not blockedVisibility:expected.append(['shadow']if shadow else ['normal',vs])
     if not suppress:
      for i in range(2 if portal else 3):
       p=specials+i*208;mp=p+64 if matrixMode in [0,-1]else p+0x600;expected.append(['special',header,p,mp,[0,0,0]])
     check('scene-wrapper-specials-'+str((shadow,blockedVisibility,portal,suppress,matrixMode)),events,expected);check('scene-wrapper-clipped-flag-'+str(specialCases),bool(n.unpack('<I',sc+0x74)[0]&4),True);specialCases+=1
r={'schema':'original-visibility-contracts-v1','binarySHA256':n.sha256,'passed':all(t['passed']for t in tests),'assertions':len(tests),'visibilityCases':visibilityCases,'clipPatchCases':clipPatchCases,'registrationCases':registrationCases,'fadeHelperCases':fadeCases,'alphaClampCases':alphaCases,'specialDispatchCases':specialCases,'maximumFadeError':maxAlphaError,'failures':[t for t in tests if not t['passed']],'tests':tests,'fadeSamples':fadeSamples,'originalFunctions':['0x5f5380','0x5df7b0','0x5c0240','0x5df910','0x5ded80','0x5de060','0x5dee40','0x603ad0','0x601df0','0x5f5830'],'scope':'Scene visibility tree/portal gating, strict squared-distance LOD selection, far-limit override, original fade math, material/clip bit writes, paired item-control patch, registration/signed-sort/UV-chain insertion/removal and scene wrapper/special dispatch. Original CPU instructions with explicit hooks.','hooks':['Frustum oracle5d69a0 returns controlled0/1/2; geometric frustum calculation is not validated here.','Original debug gate5c60a0 runs with debug globals disabled.','Registration reset5ddd10 and platform registration hooks stubbed; registration list logic and sort insertion execute.','Scene-wrapper tests intercept visibility evaluators and special draw endpoints to observe dispatch only.','Mutex and diagnostic output stubbed.'],'limits':['No portal visibility evaluation, shadow-extrusion branch or full special-object draw consumer is emulated.','Compiled C# module remains unexecuted due OS denial; these are independent contract fixtures.']}
(B/'reports/geometry-visibility-native-validation.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k]for k in ['passed','assertions','visibilityCases','clipPatchCases','registrationCases','maximumFadeError','failures']},indent=2))
if not r['passed']:raise SystemExit(1)
