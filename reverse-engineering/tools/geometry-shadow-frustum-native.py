"""Original camera frustum corners/far-plane and three-point plane math."""
import importlib.util,json,struct,gzip,hashlib,base64,math,random,collections,ast
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def mod(name,p):
 s=importlib.util.spec_from_file_location(name,B/p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=mod('nx','tools/native-x86.py');x=mod('wide','tools/animation-x87.py');n=nx.NativeX86();D=n.DATA;SIZE=1024;CAM=D+0x100;OUT=D+0x200;PLANE=D+0x300;POINTS=D+0x100;TABLE=(B/'references/native-animation-sine-table.f32').read_bytes();sine=struct.unpack('<32768f',TABLE);n.write(0x29899a0,TABLE);cases=[];counts=collections.Counter();calls=[];angles=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESI,UC_X86_REG_EDI
for address in [0x5c8030,0x5c7fa0,0x5c19d0,0x5b30a0,0x5b3920,0x5b3b30,0x5c0240]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(a),begin=address,end=address)
n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:angles.append(mu.reg_read(UC_X86_REG_EAX)),begin=0x5c805b,end=0x5c805b)
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];W=x.wide;mul=x.mul;add=x.add;div=x.div
def store(v,approx):
 out=x.store(v);return math.copysign(0.,approx)if out==0 and approx==0 else out
def plane(a,b,c):
 left=[f32(b[i]-a[i])for i in range(3)];right=[f32(c[i]-a[i])for i in range(3)];cross=[]
 for i,j in [(1,2),(2,0),(0,1)]:cross.append(store(add(mul(W(left[i]),W(right[j])),mul(W(-left[j]),W(right[i]))),left[i]*right[j]-left[j]*right[i]))
 squared=x.store(add(add(mul(W(cross[1]),W(cross[1])),mul(W(cross[0]),W(cross[0]))),mul(W(cross[2]),W(cross[2]))));length=f32(math.sqrt(squared));inverse=x.store(div(W(1),W(length)))if length>0 else 0.;normal=[store(mul(W(v),W(inverse)),v*inverse)for v in cross];constant=store(add(add(mul(W(normal[1]),W(a[1])),mul(W(normal[0]),W(a[0]))),mul(W(normal[2]),W(a[2]))),(normal[1]*a[1]+normal[0]*a[0])+normal[2]*a[2]);return normal+[-constant]
def point(p,m):
 result=[]
 for i in range(3):result.append(store(add(add(add(mul(W(p[0]),W(m[i])),mul(W(p[1]),W(m[i+4]))),mul(W(p[2]),W(m[i+8]))),W(m[i+12])),((p[0]*m[i]+p[1]*m[i+4])+p[2]*m[i+8])+m[i+12]))
 return result
def frustum(matrix,fov,aspect,near,far):
 phase=f32(fov*.5);angle=math.trunc(phase*10430.3779296875)&0xffffffff;sy=sine[angle>>1&32767];cy=sine[((angle+0x4000)&0xffffffff)>>1&32767]
 if cy==0 or near==0 or aspect==0:raise ValueError('Nonzero frustum denominator required')
 yy=store(div(mul(W(sy),W(near)),W(cy)),sy*near/cy);xx=store(div(W(yy),W(aspect)),yy/aspect);ratio=store(div(W(far),W(near)),far/near);local=[[-xx,-yy,near],[-xx,yy,near],[xx,yy,near],[xx,-yy,near]];local+=[[store(mul(W(v),W(ratio)),v*ratio)for v in p]for p in local];points=[point(p,matrix)for p in local];return points,plane(*points[4:7]),angle
def execute(kind,index,points=None,matrix=None,params=None,sse=False,poison=0,source=None):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));expected=bytearray(before);pack=lambda b,p,v:struct.pack_into('<'+'f'*len(v),b,p-D,*v)
 if kind=='plane':
  for i,p in enumerate(points):pack(before,POINTS+i*16,p)
  expected[:]=before;pack(expected,PLANE,plane(*points));args=[];regs={UC_X86_REG_ESI:POINTS,UC_X86_REG_ECX:POINTS+16,UC_X86_REG_EAX:POINTS+32,UC_X86_REG_EDI:PLANE};address=0x5c7fa0;angle=None
 else:
  pack(before,CAM,matrix+params);expected[:]=before;vv,pp,angle=frustum(matrix,*params)
  for i,p in enumerate(vv):pack(expected,OUT+i*16,p+([1.]if i<4 else[]))
  pack(expected,PLANE,pp);args=[CAM,OUT,PLANE];regs={};address=0x5c8030
 n.write(D,before);n.write(n.STACK,struct.pack('<I',poison)*16384);n.pack('<I',0x29a9c48,int(sse));calls.clear();angles.clear();n.call(address,args,regs,count=100000);actual=bytearray(n.read(D,SIZE));raw=bytes(actual)
 if kind=='frustum':
  for i in range(4,8):actual[OUT-D+i*16+12:OUT-D+i*16+16]=expected[OUT-D+i*16+12:OUT-D+i*16+16]
 if actual!=expected or angle is not None and angles!=[angle]:raise AssertionError(dict(kind=kind,index=index,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:30],actual=raw.hex(),expected=expected.hex(),angles=angles,expectedAngle=angle))
 counts['cases']+=1;counts[kind]+=1;counts['floatWords']+=4 if kind=='plane' else 32;cases.append(dict(kind=kind,index=index,before=bytes(before).hex(),points=points,matrix=matrix,params=params,sse=sse,stackPoison=poison,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeOutputBytes=raw[OUT-D:OUT-D+128].hex()if kind=='frustum'else raw[PLANE-D:PLANE-D+16].hex(),nativePlaneBytes=raw[PLANE-D:PLANE-D+16].hex(),nativeCalls=calls.copy(),nativeAngle=angle,source=source));return raw
portals=json.loads((R/'geometry-portal-predicate-fixtures.json').read_text())['portals']
for i,p in enumerate(portals):
 vv=p['vertices']
 for winding in [vv[:3],list(reversed(vv[:3]))]:execute('plane',i,points=winding,source=dict(source=p['source'],portal=p['index']))
rng=random.Random(0x5c7fa0)
for i in range(512):
 p=[[f32(rng.uniform(-10000,10000))for _ in range(3)]for k in range(3)]
 if i%5==0:p[1]=p[0].copy()
 if i%7==0:p=[[0.,-0.,0.],[-0.,0.,0.],[0.,0.,-0.]]
 execute('plane',1000+i,points=p)
cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';camera=json.loads((B/cp).read_text());identity=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.];matrices=[identity]+[r['matrix']for r in camera['cameras']['cameras']]
for i in range(1024):
 params=[f32([0.,-0.,.1,1.,1.5,2.,3.,-1.][i%8]),f32([1.,.75,1.3333333,-1.][i%4]),f32([.1,1.,10.,-1.][i//4%4]),f32([0.,1.,100.,1000.][i//16%4])]
 execute('frustum',i,matrix=matrices[i%len(matrices)],params=params,sse=bool(i&1),poison=[0,0x3f800000,0xdeadbeef][i%3],source=dict(cameraFile=cp,cameraIndex=(i%len(matrices))-1))
audit=[]
for poison in [0,0x12345678,0xdeadbeef]:
 raw=execute('frustum',2000+len(audit),matrix=identity,params=[1.,1.,1.,100.],poison=poison);audit.append(dict(stackPoison=poison,farW=[struct.unpack_from('<I',raw,OUT-D+i*16+12)[0]for i in range(4,8)]))
assert all(r['farW']==[r['stackPoison']]*4 for r in audit)
fp=R/'geometry-shadow-frustum-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,camera=CAM,output=OUT,plane=PLANE,points=POINTS,cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(TABLE).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-frustum-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),paddingAudit=audit,limits=['Original5c7fa0 plane and5c8030 corner/far-plane math plus real5b3920/5b3b30/5c0240/CRT conversion/5c19d0/5b30a0 run unchanged. No computational substitutions.','All326 authored portal first triangles in both windings and512 synthetic/degenerate planes; identity plus six authored CU2 camera transforms, controlled finite FOV/aspect/near/far parameters.','All meaningful XYZ, planeXYZW and nearW words compare bit-exact. Four far-cornerW words are proven uninitialized stack padding: three poison patterns propagate exactly, native bytes retained. Portable projection preserves caller padding rather than fabricating a defined value.','Finite inputs and intermediate outputs, nonzero aspect/near/sampledcosine, disjoint inputs/outputs; FOVrange-1..3 and both CRT conversion policies. No broad out-of-range trig conversion or partial alias claim.','Full outer5e8950 light-volume extraction, GPU outputs and compiled managed equality remain separate.']);(R/'geometry-shadow-frustum-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
