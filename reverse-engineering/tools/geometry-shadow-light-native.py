"""Original light setup, look-at/orthographic helpers and extraction composition."""
import ast,json,struct,gzip,hashlib,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
p=B/'tools/geometry-shadow-extraction-native.py';tree=ast.parse(p.read_text());body=[]
for node in tree.body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='cases'for t in node.targets):break
 body.append(node)
e={'__file__':str(p)};exec(compile(ast.Module(body=body,type_ignores=[]),str(p),'exec'),e);n=e['n'];v=e['v'];x=e['x'];W=x.wide;add=x.add;mul=x.mul;div=x.div;store=e['store'];f32=e['f32'];D=n.DATA;SIZE=e['SIZE'];CTX=e['CTX'];CAM=e['CAM'];CUTS=e['CUTS'];PROJECTION=e['PROJECTION'];VIEW=e['VIEW'];EYE=D+0x200;TARGET=D+0x220;UP=D+0x240;OUT=D+0x280
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
calls=[]
for address in [0x5b7390,0x5952c0,0x5c6c10,0x5b79d0,0x595360,0x5b3b30,0x5e8950]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(a),begin=address,end=address)
def lookat(eye,target,up):
 forward=v['normal']([f32(target[j]-eye[j])for j in range(3)]);right=v['normal'](v['cross'](up,forward));vertical=v['normal'](v['cross'](forward,right));out=[0.]*16
 for i in range(3):out[i*4:i*4+3]=[right[i],vertical[i],forward[i]]
 for j,axis in enumerate([right,vertical,forward]):out[12+j]=store(add(add(mul(W(-eye[0]),W(axis[0])),mul(W(-eye[1]),W(axis[1]))),mul(W(-eye[2]),W(axis[2]))),(-eye[0]*axis[0]-eye[1]*axis[1])-eye[2]*axis[2])
 out[15]=1.;return out,forward
def orthographic(values):
 out=[0.]*16
 for axis in range(3):
  low,high=values[axis*2:axis*2+2];out[axis*5]=store(div(W(2),add(W(high),W(-low))),2/(high-low));out[12+axis]=store(div(add(W(low),W(high)),add(W(low),W(-high))),(low+high)/(low-high))
 out[15]=1.;return out
cases=[];counts=collections.Counter()
def execute(kind,index,eye,target,up,params,camera=None,cuts=None):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));pack=lambda b,p,values:struct.pack_into('<'+'f'*len(values),b,p-D,*values);pack(before,EYE,eye);pack(before,TARGET,target);pack(before,UP,up);expected=bytearray(before);matrix,forward=lookat(eye,target,up);ortho=orthographic(params);unknown=[];nativeArgs=[]
 if kind=='lookat':pack(expected,OUT,matrix);nativeArgs=[(0x5b7390,[OUT,EYE,TARGET,UP],{})]
 elif kind=='orthographic':pack(expected,OUT,ortho);nativeArgs=[(0x5b79d0,[OUT]+[struct.unpack('<I',struct.pack('<f',q))[0]for q in params],{})]
 else:
  if kind in ['setup','wrapper','chain']:
   pack(expected,CTX+0x760,eye+[1.]);pack(expected,CTX+0x770,forward+[1.]);pack(expected,CTX+0x780,matrix);nativeArgs.append((0x5c6c10,[CTX,EYE,TARGET,UP],{})if kind=='wrapper'else(0x5952c0,[EYE,TARGET,UP],{UC_X86_REG_ECX:CTX}))
  if kind in ['projection','chain']:
   pack(expected,CTX+0x7c0,ortho);struct.pack_into('<I',expected,CTX+0x800-D,0);nativeArgs.append((0x595360,[struct.unpack('<I',struct.pack('<f',q))[0]for q in params],{UC_X86_REG_ECX:CTX}))
  if kind=='chain':
   pack(before,CAM,camera);pack(before,CUTS,cuts);pack(expected,CAM,camera);pack(expected,CUTS,cuts);expected,unknown,_=e['model'](expected,len(cuts));nativeArgs.append((0x5e8950,[CAM,CUTS,len(cuts)],{UC_X86_REG_ECX:CTX}))
 n.write(D,before);n.write(n.STACK,struct.pack('<I',0x12345678)*16384);n.pack('<I',0x29a9c48,index&1);calls.clear()
 for address,args,regs in nativeArgs:n.call(address,args,regs,count=1000000)
 actual=bytearray(n.read(D,SIZE))
 if kind=='chain':actual[PROJECTION-D:PROJECTION-D+64]=n.read(e['NATIVE_PROJECTION'],64);actual[VIEW-D:VIEW-D+64]=n.read(e['NATIVE_VIEW'],64)
 raw=bytes(actual)
 for p in unknown:actual[p:p+4]=before[p:p+4]
 if actual!=expected:raise AssertionError(dict(kind=kind,index=index,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:30],actual=raw.hex(),expected=expected.hex()))
 counts['cases']+=1;counts[kind]+=1;counts['persistentBytes']+=SIZE;cases.append(dict(kind=kind,index=index,before=bytes(before).hex(),parameters=params,cutCount=len(cuts)if cuts is not None else 0,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeContextBytes=raw[CTX-D:CTX-D+0x830].hex(),nativeMatrixBytes=raw[OUT-D:OUT-D+64].hex(),nativeCalls=calls.copy(),undefinedWordOffsets=unknown,nativeUndefinedWords=[struct.unpack_from('<I',raw,p)[0]for p in unknown]))
rng=random.Random(0x5952c0);cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';authored=json.loads((B/cp).read_text());matrices=[r['matrix']for r in authored['cameras']['cameras']]
for i in range(512):
 eye=[f32(rng.uniform(-1000,1000))for _ in range(3)];target=[f32(rng.uniform(-1000,1000))for _ in range(3)];up=[[0.,1.,0.],[0.,0.,1.],[1.,0.,0.],[0.,-1.,0.]][i%4]
 if i%11==0:target=eye.copy()
 if i%13==0:eye=[0.,-0.,0.];target=up.copy()
 params=[f32(q)for q in [-rng.uniform(.01,100),rng.uniform(.01,100),-rng.uniform(.01,100),rng.uniform(.01,100),-rng.uniform(.01,100),rng.uniform(.01,100)]]
 if i%7==0:params=[-1.,1.,-100.,100.,0.,1.]
 for kind in ['lookat','orthographic','setup','wrapper','projection']:execute(kind,i,eye,target,up,params)
 if i<256:execute('chain',i,eye,target,up,params,matrices[i%6]+[1.,1.3333333730697632,.1,1000.],[.1,10.,100.][:2+i%2])
fp=R/'geometry-shadow-light-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,eye=EYE,target=TARGET,up=UP,output=OUT,context=CTX,camera=CAM,cuts=CUTS,projection=PROJECTION,view=VIEW,cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(v['ns']['TABLE']).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-light-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Actual5b7390/5952c0/5c6c10/5b79d0/595360 plus original normalization execute unchanged.256 sequential original setup+orthographic+extraction chains also execute.','Finite disjoint inputs/outputs, nonzero orthographic denominator and bounded extraction domain. Degenerate eye=target/parallelup supported with original zero-normal behavior.','Normalization arithmetic uses stricter private wide support; existing gameplay5b3b30 native map is not duplicated.','Six authored CU2 camera matrices only in composed extraction; light source/target/up and projection extents are controlled. Upstream596a30 player/light-selection math, registration/consumer chain andGPU remain separate.','Only proven extraction padding normalized in256 chaincases; raw native padding words retained. Managed runtime equality remains pending.']);(R/'geometry-shadow-light-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))

