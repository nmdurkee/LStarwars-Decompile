"""Original camera render-cache and concrete viewport offset/extent producers."""
import importlib.util,struct,json,gzip,random,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase6-20261013-renderer'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x=load('wide','animation-x87.py');n=nx.NativeX86();W=x.wide;A=x.add;M=x.mul;D=x.div;S=x.store
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
def sign(v):return v<0 or v==0 and math.copysign(1,v)<0
def product(a,b):
 out=S(M(W(a),W(b)));return -0. if out==0 and sign(a)!=sign(b) else out
def quotient(a,b):
 out=S(D(W(a),W(b)));return -0. if out==0 and sign(a)!=sign(b) else out
unit=n.unpack('<d',0x751a68)[0];widthDiv=n.unpack('<d',0x75c068)[0];heightDiv=n.unpack('<d',0x75c060)[0]
checks=0;errors=[];rng=random.Random(0x5fcc80);offsetCases=[];extentCases=[];cacheCases=[]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<30:errors.append({'label':label,'native':a,'expected':e})
def setup(c):
 for a,vals in [(0x973900,c['screen']),(0x80e694,c['source']),(0x963e10,c['rectangle']),(0x80202c,c['origin'])]:n.pack('<'+'i'*len(vals),a,*vals)
def offsets(c):
 out=[]
 for i in range(2):
  screen,source=c['screen'][i],c['source'][i];ratio=quotient(f32(screen),f32(source)) if screen and source else 0.
  delta=S(A(M(W(c['rectangle'][i]),W(unit)),(-A(W(c['origin'][i]),W(-(screen>>1)))[0],A(W(c['origin'][i]),W(-(screen>>1)))[1])))
  out.append(quotient(delta,ratio) if delta and ratio else 0.)
 return out
def extents(c):return [quotient(S(M(W(c['rectangle'][i+2]),W(unit))),quotient(c['screen'][i],c['source'][i])) for i in range(2)]
# Extents differ from the expression above: no intermediate float spills.
def extents(c):
 out=[]
 for i in range(2):
  numerator=M(W(c['rectangle'][i+2]),W(unit));denominator=D(W(c['screen'][i]),W(c['source'][i]));v=S(D(numerator,denominator));out.append(-0. if v==0 and (c['screen'][i]<0)!=(c['source'][i]<0) else v)
 return out
edge=[0,1,-1,2,-2,3,-3,720,1280,16777217,-16777217,2147483647,-2147483648]
def case(i,nonzero):
 screen=[rng.choice(edge) if i<512 else rng.randint(-2147483648,2147483647) for _ in range(2)];source=[rng.choice(edge) if i<512 else rng.randint(-2147483648,2147483647) for _ in range(2)]
 if nonzero:screen=[v or 1 for v in screen];source=[v or -1 for v in source]
 return {'screen':screen,'source':source,'rectangle':[rng.choice(edge) if i<512 else rng.randint(-2147483648,2147483647) for _ in range(4)],'origin':[rng.choice(edge) if i<512 else rng.randint(-2147483648,2147483647) for _ in range(2)]}
for i in range(2048):
 c=case(i,False);setup(c);p=n.DATA;n.pack('<4I',p,0x12345678,0xaaaaaaaa,0xbbbbbbbb,0x87654321);n.call(0x5dad10,[p+4,p+8]);actual=list(n.unpack('<2I',p+4));expected=[word(v)for v in offsets(c)];ck(actual,expected,'offset '+str(i));ck(list(n.unpack('<2I',p))[0],0x12345678,'offset guard first');ck(n.unpack('<I',p+12)[0],0x87654321,'offset guard last');c['nativeWords']=actual;offsetCases.append(c)
for i in range(2048):
 c=case(i,True);setup(c);p=n.DATA;n.pack('<4I',p,0x12345678,0xaaaaaaaa,0xbbbbbbbb,0x87654321);n.call(0x5daef0,[p+4,p+8]);actual=list(n.unpack('<2I',p+4));ck(actual,[word(v)for v in extents(c)],'extent '+str(i));ck(n.unpack('<I',p)[0],0x12345678,'extent guard first');ck(n.unpack('<I',p+12)[0],0x87654321,'extent guard last');c['nativeWords']=actual;extentCases.append(c)
for i in range(1024):
 c=case(i,True);setup(c);view=[rng.getrandbits(32)for _ in range(16)];projection=[word(rng.choice([-0.,0.,1.,-1.,f32(rng.uniform(-100,100))]))for _ in range(16)];before=bytes(rng.getrandbits(8)for _ in range(0x84));counter=rng.getrandbits(32);short=rng.getrandbits(16);n.pack('<16I',0x80b708,*view);n.pack('<16I',0x80b748,*projection);n.write(0x9869b0,before);n.pack('<I',0x9868c0,counter);n.pack('<H',0x9868cc,short);result=n.call(0x5fcc80);after=n.read(0x9869b0,0x84);expected=bytearray(before);struct.pack_into('<I',expected,0,0);struct.pack_into('<16I',expected,4,*view);struct.pack_into('<5I',expected,0x44,*[projection[j]for j in(0,5,10,11,14)])
 ov,ev=offsets(c),extents(c);values=[]
 for source in(ov,ev):
  for axis in range(2):
   factor=D(W(c['screen'][axis]),W(widthDiv if axis==0 else heightDiv));v=S(M(W(source[axis]),factor));values.append(-0. if v==0 and sign(source[axis])!=(c['screen'][axis]<0) else v)
 struct.pack_into('<4I',expected,0x74,*[word(v)for v in values]);ck(after.hex(),expected.hex(),'cache image '+str(i));ck(n.unpack('<I',0x9868c0)[0],(counter+1)&0xffffffff,'counter32 '+str(i));ck(n.unpack('<H',0x9868cc)[0],(short+1)&0xffff,'counter16 '+str(i));ck(result,1,'cache return '+str(i));c.update(viewWords=view,projectionWords=projection,beforeHex=before.hex(),counter=counter,shortCounter=short,nativeHex=after.hex(),nativeCounter=n.unpack('<I',0x9868c0)[0],nativeShortCounter=n.unpack('<H',0x9868cc)[0],nativeResult=result);cacheCases.append(c)
# Capture the real camera producer -> render-cache call, retaining its actual
# consumed view/projection words. This does not assert a complete camera oracle.
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
cameraEvents=[]
def matrixAdapter(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret,out,left,right=n.unpack('<4I',sp);a=n.unpack('<16f',left);b=n.unpack('<16f',right);values=[]
 for i in range(4):
  for j in range(4):
   total=0.
   for k in range(4):total+=float(a[i*4+k])*b[k*4+j]
   values.append(f32(total))
 n.pack('<16f',out,*values);mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+16);mu.reg_write(UC_X86_REG_EIP,ret)
def cacheEntry(mu,address,size,_):cameraEvents.append({'viewWords':list(n.unpack('<16I',0x80b708)),'projectionWords':list(n.unpack('<16I',0x80b748)),'beforeHex':n.read(0x9869b0,0x84).hex(),'counter':n.unpack('<I',0x9868c0)[0],'shortCounter':n.unpack('<H',0x9868cc)[0]})
n.mu.hook_add(UC_HOOK_CODE,matrixAdapter,begin=0x715718,end=0x715718);n.mu.hook_add(UC_HOOK_CODE,cacheEntry,begin=0x5fcc80,end=0x5fcc80);n.mu.ctl_remove_cache(0x5fcc80,0x5fcd56)
prior=json.loads(gzip.decompress((R/'scene-phase5-20261013-native-fixtures.json.gz').read_bytes()));priorCases=prior['cameraCases']
for i in range(128):
 sample=priorCases[i];c={'screen':[720+i%5,520+i%7],'source':[600,420],'rectangle':[i*7-300,i*5-240,11520,8320],'origin':[i%17-8,i%19-9]};setup(c);before=bytes(rng.getrandbits(8)for _ in range(0x84));counter=rng.getrandbits(32);short=rng.getrandbits(16);n.write(0x9869b0,before);n.pack('<I',0x9868c0,counter);n.pack('<H',0x9868cc,short)
 for name,address in [('projection',0x80b748),('symmetricCache',0x80b8c8),('asymmetricCache',0x97ba90)]:n.pack('<16I',address,*sample['before']['matrixWords'][name])
 n.pack('<16f',0x971620,*[1. if j%5==0 else 0. for j in range(16)]);n.pack('<I',0x973944,0);n.pack('<I',0x973950,0);n.pack('<I',0x973954,0);cameraWords=sample['cameraWords'];n.pack('<30I',n.DATA+0x4000,*cameraWords);cameraEvents.clear();n.call(0x5ed540,[n.DATA+0x4000,1]);ck(len(cameraEvents),1,'actual camera render-cache calls '+str(i));
 if not cameraEvents:raise RuntimeError('Missing actual cache callback')
 actual=cameraEvents[0];counterAtCameraEntry=counter;counter=actual['counter'];short=actual['shortCounter'];before=bytes.fromhex(actual['beforeHex']);view,projection=actual['viewWords'],actual['projectionWords'];after=n.read(0x9869b0,0x84);expected=bytearray(before);struct.pack_into('<I',expected,0,0);struct.pack_into('<16I',expected,4,*view);struct.pack_into('<5I',expected,0x44,*[projection[j]for j in(0,5,10,11,14)]);values=[]
 for source in(offsets(c),extents(c)):
  for axis in range(2):
   v=S(M(W(source[axis]),D(W(c['screen'][axis]),W(widthDiv if axis==0 else heightDiv))));values.append(-0. if v==0 and sign(source[axis])!=(c['screen'][axis]<0) else v)
 struct.pack_into('<4I',expected,0x74,*[word(v)for v in values]);ck(after.hex(),expected.hex(),'actual camera callback image '+str(i));ck(n.unpack('<I',0x9868c0)[0],(counter+1)&0xffffffff,'actual camera counter32 '+str(i));ck(n.unpack('<H',0x9868cc)[0],(short+1)&0xffff,'actual camera counter16 '+str(i));c.update(viewWords=view,projectionWords=projection,beforeHex=before.hex(),counter=counter,shortCounter=short,nativeHex=after.hex(),nativeCounter=n.unpack('<I',0x9868c0)[0],nativeShortCounter=n.unpack('<H',0x9868cc)[0],nativeResult=1,cameraWords=cameraWords,cameraReuseArgument=1,counterAtCameraEntry=counterAtCameraEntry);cacheCases.append(c)
fixture={'unit':unit,'widthDiv':widthDiv,'heightDiv':heightDiv,'offsetCases':offsetCases,'extentCases':extentCases,'cacheCases':cacheCases};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));report={'schema':'original-render-cache-native-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'offsetCases':len(offsetCases),'extentCases':len(extentCases),'cacheCases':len(cacheCases),'directCacheCases':1024,'actualCameraCallbackCases':128,'retainedPortableReplayCases':5248},'constants':{'unit':unit,'widthDiv':widthDiv,'heightDiv':heightDiv},'adapters':{'cameraCompositionOnly':'0x715718 imported D3DX uses declared sequential binary64 / float32 matrix policy for 128 actual producer captures; direct cache/offset/extent routines have no adapters.'},'limits':['Original cache/offset/extent routines and actual getter/helper chains execute unchanged. Direct cases have no adapters; actual camera composition alone adapts imported D3DX.','Offset accepts all signed Int32 input and applies native zero-ratio/offset branches. Extents and cache require nonzero screen/source dimensions for finite arithmetic.','View matrix is raw words including nonfinite bits; sampled projection values are finite and preserve signed zero. Nonfinite x87 load/store behavior is not claimed.','Full 0x84-byte cache image retains untouched gaps; counters wrap at 32 and 16 bits. Runtime globals provided from caller; authored-world binding not asserted.','Native/Python exact own-state comparison passed; managed replay pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
