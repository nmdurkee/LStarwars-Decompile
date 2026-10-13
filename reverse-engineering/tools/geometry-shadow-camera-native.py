"""Original rigid camera inverse and degree-FOV perspective matrix helpers."""
import ast,json,struct,gzip,hashlib,math,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';source=B/'tools/geometry-shadow-frustum-native.py';tree=ast.parse(source.read_text());prefix=[]
for node in tree.body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='portals'for t in node.targets):break
 prefix.append(node)
ns={'__file__':str(source)};exec(compile(ast.Module(body=prefix,type_ignores=[]),str(source),'exec'),ns);n=ns['n'];x=ns['x'];W=x.wide;mul=x.mul;add=x.add;div=x.div;store=ns['store'];f32=ns['f32'];sine=ns['sine'];D=n.DATA;SIZE=512;SRC=D+0x80;OUT=D+0x100
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX
angleScale=n.unpack('<d',0x7578a0)[0];assert angleScale==182.04444885253906;angles=[]
for address in [0x5b7687,0x5b76a2]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:angles.append(mu.reg_read(UC_X86_REG_EAX)),begin=address,end=address)
def truncate(value):
 sig,exp=value;return (-1 if sig<0 else 1)*(abs(sig)<<exp if exp>=0 else abs(sig)>>-exp)
def inverse(matrix):
 result=[0.]*16
 for i in range(3):
  for j in range(3):result[i*4+j]=matrix[j*4+i]
 translation=[-v for v in matrix[12:15]]
 for j in range(3):
  p=[result[j],result[j+4],result[j+8]];result[j+12]=store(add(add(mul(W(translation[0]),W(p[0])),mul(W(translation[1]),W(p[1]))),mul(W(translation[2]),W(p[2]))),(translation[0]*p[0]+translation[1]*p[1])+translation[2]*p[2])
 result[15]=1.;return result
def perspective(fov,aspect,near,far):
 half=mul(W(fov),W(.5));a=truncate(mul(half,W(angleScale)));b=truncate(mul(half,W(-angleScale)));sy=sine[(a>>1)&32767];cy=sine[((0x4000-b)>>1)&32767];tangent=store(div(W(sy),W(cy)),sy/cy);denom=add(W(far),W(-near));result=[0.]*16
 result[0]=store(div(W(1),mul(W(tangent),W(aspect))),1/(tangent*aspect));result[5]=store(div(W(1),W(tangent)),1/tangent);result[10]=store(div(W(far),denom),far/(far-near));result[11]=1.;result[14]=store(div(mul(W(-far),W(near)),denom),(-far*near)/(far-near));return result,[a&0xffffffff,b&0xffffffff]
cases=[];counts=collections.Counter()
def execute(kind,index,matrix=None,parameters=None,inplace=False,sse=False,source=None):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));output=SRC if inplace else OUT;wantedAngles=[]
 if kind=='inverse':struct.pack_into('<16f',before,SRC-D,*matrix);result=inverse(matrix);args=[output,SRC];address=0x5b5a40
 else:result,wantedAngles=perspective(*parameters);args=[OUT]+[struct.unpack('<I',struct.pack('<f',v))[0]for v in parameters];address=0x5b7670
 expected=bytearray(before);struct.pack_into('<16f',expected,output-D,*result);n.write(D,before);n.pack('<I',0x29a9c48,int(sse));angles.clear();n.call(address,args,count=10000);actual=n.read(D,SIZE)
 if actual!=expected or angles!=wantedAngles:raise AssertionError(dict(kind=kind,index=index,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:20],actual=actual.hex(),expected=expected.hex(),angles=angles,wantedAngles=wantedAngles))
 counts['cases']+=1;counts[kind]+=1;counts['floatWords']+=16;counts['inplace']+=inplace;cases.append(dict(kind=kind,index=index,before=bytes(before).hex(),parameters=parameters,inplace=inplace,sse=sse,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeMatrixBytes=actual[output-D:output-D+64].hex(),nativeAngles=wantedAngles,source=source))
cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';camera=json.loads((B/cp).read_text());matrices=[r['matrix']for r in camera['cameras']['cameras']]
for i,m in enumerate(matrices):
 for inplace in [False,True]:execute('inverse',i,matrix=m,inplace=inplace,source=dict(cameraFile=cp,cameraIndex=i))
rng=random.Random(0x5b5a40)
for i in range(1024):
 m=[f32(rng.uniform(-100,100))for j in range(16)]
 if i%7==0:m=[[-0.,0.,1.,-1.][(i+j)%4]for j in range(16)]
 for inplace in [False,True]:execute('inverse',1000+i,matrix=m,inplace=inplace)
for i in range(2048):
 fov=f32(rng.uniform(1,170)*(1 if i%2==0 else-1));aspect=f32([1.,.75,1.3333333,-1.][i%4]);near=f32([0.,.1,1.,10.,-1.][i//4%5]);far=f32([100.,1000.,-100.,.01][i//20%4]);execute('perspective',i,parameters=[fov,aspect,near,far],sse=bool(i&1))
fp=R/'geometry-shadow-camera-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,source=SRC,output=OUT,cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(ns['TABLE']).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-camera-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Actual original5b5a40/5b7670 instructions execute unchanged, including original CRT conversion helpers for both policy modes.','Rigid inverse algorithm transposes3x3 and transforms negated translation; all finite source matrices execute, but it is only mathematically an inverse for orthonormal affine bases. In-place and disjoint outputs verified.','Projection FOV is degrees; bounded absoluteFOV1..170, nonzero aspect/tangent/cosine andfar!=near, finite stored outputs. Original sine table used, two truncations are retained.','Source includes six raw authoredCU2matrices plus synthetic data; projection parameters are controlled. Partial memory overlap and nonfinite/overflow domains excluded.','C# compilation/equality remain separate; outer5e8950 andGPU output are not covered here.']);(R/'geometry-shadow-camera-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
