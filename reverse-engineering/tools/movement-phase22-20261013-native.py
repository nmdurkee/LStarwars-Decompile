"""Original pod heading and Z-vector rotation, finite prepared inputs, no computational adapters."""
import importlib.util,struct,json,gzip,itertools,base64,random
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
p21=Path(__file__).with_name('movement-phase21-20261013-native.py').read_text();exec(p21[:p21.index('for k,angle in itertools.product')])
POD=MATRIX;DIR=INPUT;angles=list(n.unpack('<513H',0x8066c8));r=random.Random(20261023);vectors=[];errors=[];groups={}
def short(x):return((int(x)+32768)&65535)-32768
def angle(x,z):
 if x==0:return short(32768 if z<0 else 0)
 if z==0:return short(49152 if x<0 else 16384)
 a,b=abs(x),abs(z);inv=b<a;num,den=(b,a)if inv else(a,b);idx=int(quant(quant(Fraction(num)*512,64)/Fraction(den),64));q=16384-angles[idx]if inv else angles[idx];return short(q+32768 if x<0 and z<0 else -q if x<0 else 32768-q if z<0 else q)
def vy(v,a):
 s,c=X.fl(table[(a>>1)&32767]),X.fl(table[((a+16384)>>1)&32767]);x,y,z=map(X.fl,v);return[(s*z+c*x).flstore(),v[1],(z*c-x*s).flstore()]
def vx(v,a):
 s,c=X.fl(table[(a>>1)&32767]),X.fl(table[((a+16384)>>1)&32767]);x,y,z=map(X.fl,v);return[v[0],(c*y-s*z).flstore(),(s*y+c*z).flstore()]
def heading(c,img):
 def fl(p):return struct.unpack_from('<f',img,p-D)[0]
 def vec(p):return[fl(p+j*4)for j in range(3)]
 def put(p,v):struct.pack_into('<3f',img,p-D,*v)
 def transform(v):
  rows=[list(map(X.fl,vec(POD+j*16)))for j in range(3)];v=list(map(X.fl,v));return[(row[1]*v[1]+row[0]*v[0]+row[2]*v[2]).flstore()if j==0 else(row[0]*v[0]+row[1]*v[1]+row[2]*v[2]).flstore()for j,row in enumerate(rows)]
 def rotate(k,a):model(k,dict(angle=a),img)
 source=c.get('source',DIR);v=transform(vec(source));yaw=angle(v[0],v[2]);struct.pack_into('<i',img,POD-D+0x74,yaw);v=vy(v,-yaw);pitch=angle(v[1],v[2]);struct.pack_into('<i',img,POD-D+0x70,pitch);rotate('y',yaw);rotate('x',-pitch)
 if c.get('mode',0):rotate('z',512);return
 fresh=vec(source);rawyaw=angle(fresh[0],fresh[2]);flat=vy(fresh,-rawyaw);rawpitch=angle(flat[1],flat[2]);a=short(int(fl(POD+0x5c)))+16384;s,co=X.fl(table[(a>>1)&32767]),X.fl(table[((a+16384)>>1)&32767]);roll=[co.flstore(),s.flstore(),0];roll=vy(vx(roll,-rawpitch),rawyaw);roll=transform(roll);bank=angle(roll[0],roll[1]);delta=Fraction(c.get('delta',f32(1/60)));high=quant(delta*24000,64);low=quant(delta*-24000,64)
 if bank>high:bank=short(int(high))
 if bank<low:bank=short(int(low))
 factor=c.get('factor',1);bf=0 if factor>2 else ((X.fl(2)-X.fl(factor))*X.fl(bank)).flstore()if factor>1 else float(bank);rotate('z',-short(int(bf)))
def zvec(c,img):
 source=c.get('source',DIR);out=c.get('output',OUT);a=c.get('angle',12345);s,co=X.fl(table[(a>>1)&32767]),X.fl(table[((a+16384)>>1)&32767]);fl=lambda p:struct.unpack_from('<f',img,p-D)[0];x=X.fl(fl(source));struct.pack_into('<f',img,out-D,(co*x-s*X.fl(fl(source+4))).flstore());struct.pack_into('<f',img,out-D+4,(x*s+co*X.fl(fl(source+4))).flstore());img[out-D+8:out-D+12]=img[source-D+8:source-D+12]
def run22(k,c,group):
 before=setup(c);struct.pack_into('<f',before,POD-D+0x5c,c.get('curve',1234.5));n.write(D,before);delta=c.get('delta',f32(1/60));n.pack('<f',0x925018,delta);expected=bytearray(before);(heading if k=='heading'else zvec)(c,expected)
 if k=='heading':n.call(0x4d94f0,[c.get('source',DIR),bits(c.get('factor',1)),c.get('mode',0)],regs={m.UC_X86_REG_ESI:POD})
 else:n.call(0x5b3690,[c.get('output',OUT),c.get('source',DIR),c.get('angle',12345)])
 after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected:errors.append(dict(kind=k,input=c,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(kind=k,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode()))
for mode,factor,delta in itertools.product([0,1,-1],[-1,0,1,1.5,2,2.5],[-.125,0,f32(1/60),.125,1,2]):run22('heading',dict(mode=mode,factor=factor,delta=delta),'mode-factor-ordered-clamp-grid')
for j in range(512):run22('heading',dict(matrix=[[f32(r.uniform(-4,4))for j in range(3)]for row in range(3)],vector=[f32(r.uniform(-8,8))for j in range(3)],curve=f32(r.uniform(-1e6,1e6)),factor=f32(r.uniform(-1,3)),delta=f32(r.uniform(-.125,.25)),mode=0 if j%3 else 1),'finite-nonorthogonal-heading-bank')
for source,mode in itertools.product([POD,POD+4,POD+16,POD+32],[0,1]):run22('heading',dict(source=source,mode=mode),'direction-alias-fresh-matrix-reads')
for vector in [[0,0,0],[0,0,1],[0,0,-1],[1,0,0],[-1,0,0],[0,1,0],[0,-1,0],[-0.,-0.,-0.]]:run22('heading',dict(vector=vector,matrix=[[1,0,0],[0,1,0],[0,0,1]],curve=0),'axis-zero-direction')
for source,out,a in itertools.product([DIR,POD,POD+4],[OUT,DIR-4,DIR,DIR+4,DIR+8,POD,POD+4],[-2147483648,-65537,-1,0,1,16384,32768,65535,2147483647]):run22('z',dict(source=source,output=out,angle=a),'z-vector-shifted-alias-full-angle')
for seq in range(16):
 c=dict(matrix=[[f32(r.uniform(-2,2))for j in range(3)]for row in range(3)],vector=[f32(r.uniform(-4,4))for j in range(3)],curve=f32(r.uniform(-65536,65536)),factor=[0,1,1.5,2.5][seq%4],delta=[f32(1/60),-.125,0,.125][seq%4],mode=seq%2)
 before=setup(c);struct.pack_into('<f',before,POD-D+0x5c,c['curve']);n.write(D,before);n.pack('<f',0x925018,c['delta'])
 for step in range(8):
  before=bytearray(n.read(D,SIZE));expected=bytearray(before);heading(c,expected);n.call(0x4d94f0,[DIR,bits(c['factor']),c['mode']],regs={m.UC_X86_REG_ESI:POD});after=n.read(D,SIZE);groups['repeated-heading-updates']=groups.get('repeated-heading-updates',0)+1
  if after!=expected:errors.append(dict(kind='heading',input=c,sequence=seq,step=step,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
  vectors.append(dict(kind='heading',input=dict(c,sequence=seq,step=step),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode()))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],nativeAdapters=0,limits=['Finite used matrix/vector/curve/factor/delta inputs and representable conversions; exact supplied sine and original 513-word angle table.','All native heading, direction, vector and matrix math executes without computational adapters. Source scratch is disjoint caller-owned storage outside retained image.','Whole CreatePod command and actor creation remain pending.'])
(m.BASE/'reports/movement-phase22-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase22-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(table=[bits(v)for v in table],angles=angles,vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
for start,end in [(0x4d94f0,0x4d970b),(0x5b3690,0x5b3703)]:
 ins=[]
 for i in cs.disasm(n.read(start,end-start),start):
  ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
 functions.append(dict(address=hex(start),size=sum(len(bytes.fromhex(i['bytes']))for i in ins),instructions=ins))
(m.BASE/'reports/movement-phase22-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2)+'\n')
print(json.dumps(dict(cases=len(vectors),checks=len(vectors),mismatches=len(errors),errors=errors[:5])))
