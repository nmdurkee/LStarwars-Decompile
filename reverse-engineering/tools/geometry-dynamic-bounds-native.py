"""Scalar original transformed dynamic AABB clipping with authored geometry."""
import importlib.util,json,struct,hashlib,gzip,math
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def module(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
nx=module('nx',B/'tools/native-x86.py');x87=module('x87',B/'tools/animation-x87.py');n=nx.NativeX86()
import numpy as np
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
BASE=n.DATA;IDENTITY=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.]
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
errors=[];cases=[];sources=[];counts={'box':0,'affineAlias':0,'packedPoints':0,'floatWords':0,'signedZeroDifferences':0};classes={0:0,1:0,2:0};pointOutputs=[]
def observe(mu,address,size,_):
 pointOutputs.append(n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0])
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x603f10,end=0x603f10)
def dot(x,y,z,a,b,c,translation=None):
 exact=x87.add(x87.add(x87.mul(x87.wide(x),x87.wide(a)),x87.mul(x87.wide(y),x87.wide(b))),x87.mul(x87.wide(z),x87.wide(c)));approx=(float(x)*a+float(y)*b)+float(z)*c
 if translation is not None:exact=x87.add(exact,x87.wide(translation));approx+=translation
 value=x87.store(exact)
 # PlaybackWide/rational zeros have no sign. Ordered IEEE zero operations
 # retain that sign; never replace a nonzero exact result with approximation.
 return approx if value==0 and approx==0 else value
def mul(left,right):
 out=IDENTITY[:]
 for row in range(4):
  for col in range(3):out[row*4+col]=dot(*left[row*4:row*4+3],right[col],right[4+col],right[8+col],right[12+col]if row==3 else None)
 return out
def points(packed,matrix):return[dot(*packed[i:i+3],matrix[c],matrix[c+4],matrix[c+8],matrix[c+12])for i in range(0,len(packed),3)for c in range(3)]
def comparewords(actual,expected,label):
 counts['floatWords']+=len(actual)
 for i,(a,e)in enumerate(zip(actual,expected)):
  if bits(a)==bits(e):continue
  if a==0 and e==0:counts['signedZeroDifferences']+=1
  if len(errors)<30:errors.append({'context':label,'slot':i,'native':a,'model':e,'nativeWord':bits(a),'modelWord':bits(e)})
def classify(minimum,maximum,matrix,view,near,far,override,requested,sx,sy,enabled):
 if not enabled:return 1,None,None,None
 combined=view[:]if matrix is None else mul(matrix,view);limit=requested if requested!=0 else override if override!=0 else far
 xyz=[]
 for mask in[0,7,4,3,2,6,1,5]:xyz.extend(maximum[c]if mask&(1<<c)else minimum[c]for c in range(3))
 transformed=points(xyz,combined);codes=[]
 for i in range(8):
  x,y,z=transformed[i*3:i*3+3];code=0
  if z<near:code|=32
  if limit<z:code|=16
  if x<-float(z)*sx:code|=1
  if float(z)*sx<x:code|=2
  if y<-float(z)*sy:code|=8
  if float(z)*sy<y:code|=4
  codes.append(code)
 allcode=63;anycode=0
 for code in codes:allcode&=code;anycode|=code
 return 0 if allcode else 2 if anycode else 1,combined,transformed,[limit]*4
def runbox(minimum,maximum,matrix,view,params,label,sentinel=False):
 near,far,override,requested,sx,sy,enabled=params;pointOutputs.clear();n.pack('<3f',BASE,*minimum);n.pack('<3f',BASE+16,*maximum);n.pack('<16f',BASE+64,*(matrix or IDENTITY));n.pack('<16f',0x80b708,*view);n.pack('<2f',0x973730,near,far);n.pack('<f',0x97374c,override);n.pack('<f',0x966378,sx);n.pack('<f',0x97313c,sy);n.pack('<I',0x80e85c,enabled);n.pack('<I',0x297c0d0,0);beforeMatrix=[f32(i*.25-2)for i in range(16)];beforeFar=[-3.,-2.,-1.,0.];n.pack('<16f',0x280c480,*beforeMatrix);n.pack('<4f',0x80e8f0,*beforeFar)
 expected,combined,transformed,replicated=classify(minimum,maximum,matrix,view,*params);pointer=0x806680 if sentinel else BASE+64 if matrix is not None else 0;actual=n.call(0x6042e0,args=[BASE,BASE+16,pointer,bits(requested),0]);observedMatrix=list(n.unpack('<16f',0x280c480));observedFar=list(n.unpack('<4f',0x80e8f0));observedPoints=list(n.unpack('<24f',pointOutputs[0]))if pointOutputs else None
 if actual!=expected and len(errors)<30:errors.append({'context':label,'nativeClass':actual,'modelClass':expected})
 comparewords(observedMatrix,combined if enabled else beforeMatrix,[label,'matrix']);comparewords(observedFar,replicated if enabled else beforeFar,[label,'far'])
 if enabled:comparewords(observedPoints,transformed,[label,'corners'])
 counts['box']+=1;classes[actual]=classes.get(actual,0)+1;cases.append({'kind':'box','label':label,'minimum':minimum,'maximum':maximum,'matrix':matrix,'view':view,'params':params,'sentinel':sentinel,'beforeMatrix':beforeMatrix,'beforeFar':beforeFar,'nativeClass':actual,'nativeMatrix':observedMatrix,'nativeMatrixWords':list(n.unpack('<16I',0x280c480)),'nativeFar':observedFar,'nativePoints':observedPoints})
cameraPath='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';camera=json.loads((B/cameraPath).read_text());views=[IDENTITY]
for ci in[0,5]:views.append(np.linalg.inv(np.array(camera['cameras']['cameras'][ci]['matrix']).reshape(4,4)).astype(np.float32).flatten().tolist())
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 row=index[sr['source']];raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/row['report']).read_text());specials=data['specialObjects'];indices=sorted(set(int(i*(len(specials)-1)/7)for i in range(8)))if specials else[]
 for ix in indices:
  p=specials[ix]['address'];matrix=list(struct.unpack_from('<16f',raw,p+64));minimum=list(struct.unpack_from('<3f',raw,p+0x80));maximum=list(struct.unpack_from('<3f',raw,p+0x90))
  if not all(math.isfinite(v)for v in matrix+minimum+maximum):raise ValueError('Nonfinite authored transform or bounds')
  for vi,view in enumerate(views):
   for requested,override in[(0.,0.),(0.,100.),(5.,100.)]:runbox(minimum,maximum,matrix,view,[f32(.1),1000.,override,requested,1.,.75,1],[sr['source'],ix,vi,requested,override])
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'specialIndices':indices})
 if(si+1)%10==0:print('box sources',si+1,'errors',len(errors),flush=True)
 if errors:break
for center in [[0.,0.,5.],[5.,0.,5.],[f32(5+2**-20),0.,5.],[0.,f32(5*.75),5.],[0.,0.,f32(.1)],[0.,0.,10.],[0.,0.,-1.]]:
 for extent in[0.,.1,1.]:
  minimum=[f32(v-extent)for v in center];maximum=[f32(v+extent)for v in center]
  for requested,enabled,sentinel in[(0.,1,False),(5.,1,False),(0.,0,False),(0.,1,True)]:runbox(minimum,maximum,None,IDENTITY,[f32(.1),10.,0.,requested,1.,.75,enabled],['boundary',center,extent,requested,enabled,sentinel],sentinel)
# Alias-safe affine product path and loop/remainder packed-point dimensions.
for i in range(32):
 left=[f32(((j*19+i*7)%31-15)*.03125)for j in range(16)];right=views[i%3];expected=mul(left,right)
 for alias in[0,1,2]:
  n.pack('<16f',BASE,*left);n.pack('<16f',BASE+64,*right);out=[BASE+128,BASE,BASE+64][alias];n.call(0x5b5430,args=[out,BASE,BASE+64]);actual=list(n.unpack('<16f',out));comparewords(actual,expected,['affine',i,alias]);counts['affineAlias']+=1;cases.append({'kind':'affine','left':left,'right':right,'alias':alias,'native':actual,'nativeWords':list(n.unpack('<16I',out))})
for count in[0,1,2,3,4,5,7,8,9,15,16,17]:
 packed=[f32((i%13-6)*.125)for i in range(count*3)];matrix=views[count%3];n.pack('<16f',BASE,*matrix);n.write(BASE+128,struct.pack('<'+'f'*len(packed),*packed));n.write(BASE+1024,bytes(256));n.call(0x603f10,args=[BASE+1024,BASE+128,BASE,count]);actual=list(n.unpack('<'+'f'*(count*3),BASE+1024));comparewords(actual,points(packed,matrix),['points',count]);counts['packedPoints']+=1;cases.append({'kind':'points','matrix':matrix,'packed':packed,'native':actual,'nativeWords':list(n.unpack('<'+'I'*(count*3),BASE+1024))})
for mask in range(128):
 packed=[-0. if mask&(1<<i)else 0. for i in range(3)];matrix=IDENTITY[:]
 for row in range(3):
  for col in range(3):matrix[row*4+col]=-1. if mask&(1<<(row+3))else 1.
 for col in range(3):matrix[12+col]=-0. if mask&64 else 0.
 n.pack('<16f',BASE,*matrix);n.pack('<3f',BASE+128,*packed);n.call(0x603f10,args=[BASE+1024,BASE+128,BASE,1]);actual=list(n.unpack('<3f',BASE+1024));comparewords(actual,points(packed,matrix),['zeroPoints',mask]);counts['packedPoints']+=1;cases.append({'kind':'points','matrix':matrix,'packed':packed,'native':actual,'nativeWords':list(n.unpack('<3I',BASE+1024))})
 if mask<64:
  left=IDENTITY[:]
  for row in range(4):left[row*4:row*4+3]=packed
  n.pack('<16f',BASE,*left);n.pack('<16f',BASE+64,*matrix);n.call(0x5b5430,args=[BASE+128,BASE,BASE+64]);actual=list(n.unpack('<16f',BASE+128));comparewords(actual,mul(left,matrix),['zeroAffine',mask]);counts['affineAlias']+=1;cases.append({'kind':'affine','left':left,'right':matrix,'alias':0,'native':actual,'nativeWords':list(n.unpack('<16I',BASE+128))})
fp=R/'geometry-dynamic-bounds-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-bounds-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'classes':classes,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'cameraPreparation':{'file':cameraPath,'sha256':hashlib.sha256((B/cameraPath).read_bytes()).hexdigest(),'indices':[0,5],'method':'Float32 NumPy inverse of authored CU2 world transforms; camera production/inversion is fixture preparation, not native runtime reconstruction.'},'bounds':['Original scalar branch6042e0, original affine product5b5430 and original packed point transform603f10 execute unchanged; hook captures local corner buffer address only.','Finite transformed bounds, matrices and products. Scalar branch selected with runtime297c0d0=0; SIMD604110 and nonzero unsupported fifth argument excluded.','Classification and every stored float word compare exactly, including signed zero. Ordered zero tracking corrects the earlier168 sign differences;192 targeted sign cases added.','No managed executable or GPU launched.']};(R/'geometry-dynamic-bounds-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','classes','errors','fixtureBytes']}));raise SystemExit(bool(errors))

