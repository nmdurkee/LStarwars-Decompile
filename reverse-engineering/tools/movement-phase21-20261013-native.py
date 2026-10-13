"""Original pod matrix rotations/transform, runtime sine input, aliased outputs."""
import importlib.util,struct,json,gzip,itertools,base64,random
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;MATRIX=D+0x1000;INPUT=D+0x2000;OUT=D+0x3000;SIZE=0x10000;SIN=0x29899a0;table=list(struct.unpack('<32768f',(m.BASE/'references/native-animation-sine-table.f32').read_bytes()));n.write(SIN,struct.pack('<32768f',*table));vectors=[];errors=[];groups={};r=random.Random(20261022)
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
p4=Path(__file__).with_name('movement-phase4-20261013-native.py').read_text();exec(p4[p4.index('def quant('):p4.index('def readstr(')])
FUNCS={'x':0x5b4dd0,'y':0x5b5060,'z':0x5b5240,'transform':0x5b3470}
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);rows=c.get('matrix',[[1.25,-2.5,3.75],[4.125,5.25,-6.5],[-7.125,8.25,9.5]]);unused=c.get('unused',[0x7f800001,0xff800003,0x80000000,0x7fc00001,0xdeadbeef,1,0xffffffff]);raw=[]
 for j in range(3):raw.extend([bits(v)for v in rows[j]]+[unused[j]])
 raw.extend(unused[3:7]);n.pack('<16I',MATRIX,*raw);source=c.get('source',INPUT);n.pack('<3f',source,*c.get('vector',[2.125,-1.25,3.375]));return bytearray(n.read(D,SIZE))
def model(k,c,image):
 def fl(p):return val(struct.unpack_from('<I',image,p-D)[0])
 def vec(p):return[fl(p+j*4)for j in range(3)]
 def put(p,v):
  for j,x in enumerate(v):struct.pack_into('<f',image,p-D+j*4,x)
 if k=='transform':
  v=list(map(X.fl,vec(c.get('source',INPUT))));rows=[list(map(X.fl,vec(MATRIX+j*16)))for j in range(3)];out=[]
  for j,row in enumerate(rows):out.append((row[1]*v[1]+row[0]*v[0]+row[2]*v[2]).flstore()if j==0 else(row[0]*v[0]+row[1]*v[1]+row[2]*v[2]).flstore())
  put(c.get('output',OUT),out);return
 angle=c.get('angle',12345);s=X.fl(table[(angle>>1)&32767]);co=X.fl(table[((angle+0x4000)>>1)&32767]);first,second={'x':(1,2),'y':(0,2),'z':(0,1)}[k];a=list(map(X.fl,vec(MATRIX+first*16)));b=list(map(X.fl,vec(MATRIX+second*16)));minus=k=='y';aa=[(co*x-s*y if minus else co*x+s*y).flstore()for x,y in zip(a,b)];bb=[(co*y+s*x if minus else co*y-s*x).flstore()for x,y in zip(a,b)];put(MATRIX+first*16,aa);put(MATRIX+second*16,bb)
def run(k,c,group):
 before=setup(c);expected=bytearray(before);model(k,c,expected);n.call(FUNCS[k],[c.get('output',OUT),c.get('source',INPUT),MATRIX]if k=='transform'else[MATRIX,c.get('angle',12345)]);after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected:errors.append(dict(kind=k,input=c,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(kind=k,input=dict(c),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode()))
for k,angle in itertools.product(['x','y','z'],[-2147483648,-65537,-65536,-32769,-1,0,1,2,32767,32768,65535,65536,65537,2147483647]):run(k,dict(angle=angle),'signed-fullwidth-angle-wrap')
for j in range(512):
 c=dict(matrix=[[f32(r.uniform(-1e4,1e4))for v in range(3)]for row in range(3)],vector=[f32(r.uniform(-1e4,1e4))for v in range(3)],angle=r.randrange(-2147483648,2147483648))
 for k in FUNCS:run(k,c,'finite-three-row-x87-rounding')
for source,output in itertools.product([INPUT,MATRIX,MATRIX+4,MATRIX+16,MATRIX+32],[OUT,INPUT-4,INPUT,INPUT+4,INPUT+8,MATRIX-4,MATRIX,MATRIX+4,MATRIX+16,MATRIX+32]):run('transform',dict(source=source,output=output),'all-prefetched-output-source-matrix-aliases')
for k,angle,negative in itertools.product(['x','y','z'],[0,16384,32768,49152],[False,True]):run(k,dict(angle=angle,matrix=[[val(0x80000000 if negative else 0)]*3 for j in range(3)]),'signedzero-matrix-trig-quadrants')
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],nativeAdapters=0,limits=['Finite used3x3/vector inputs andfinite arithmetic outputs; preserved unusedmatrixW/translation words includeallIEEEclasses andrawbit patterns because originals neverread them.','Supplied exact32768word runtime sine table, originalproducer remains external. AllsignedInt32angles supportactual index wrapping.','No heading/fullCreatePod commandcredit; heading/curve/spawncomposition remains next.'])
(m.BASE/'reports/movement-phase21-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase21-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(table=[bits(v)for v in table],vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=len(vectors),mismatches=len(errors),errors=errors[:5])))
