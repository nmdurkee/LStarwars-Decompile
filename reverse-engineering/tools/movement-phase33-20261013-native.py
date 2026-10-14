"""Original projectile math with unchanged computational children; no game execution."""
from pathlib import Path
import json,struct,gzip,base64,itertools,random,math
p=Path(__file__).with_name('movement-phase22-20261013-native.py');q={'__file__':str(p)};exec(compile(p.read_text().split('for mode,factor,delta in itertools.product')[0],str(p),'exec'),q)
n=q['n'];m=q['m'];X=q['X'];quant=q['quant'];f32=q['f32'];bits=q['bits'];D=n.DATA;SIZE=0x20000;A=D+0x1000;B=D+0x2000;V=D+0x3000;O=D+0x4000;H=D+0x5000;SCENE=D+0x6000;LEGACY=D+0x7000;MODERN=D+0x8000;HEADER=D+0x9000;TABLE=D+0xa000;RECORD=D+0xb000;FRET=D+0x1f000;STUB=n.STOP+0x100;vectors=[];errors=[];calls={}
from unicorn import UC_HOOK_CODE
def hook(mu,a,size,user):
 if a in[0x49f630,0x5b4500,0x5b3c50,0x5d02e0,0x5b3800,0x5b3860,0x5bec80,0x5bed80,0x5be2d0,0x5c0240]:calls[hex(a)]=calls.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,hook)
def div(a,b):return X(quant(a.v/b.v,64),a.neg!=b.neg)
def sub(a,b):return(X.fl(a)-X.fl(b)).flstore()
def length(v):
 x,y,z=map(X.fl,v);return f32(math.sqrt((x*x+y*y+z*z).flstore()))
def setup(c):
 n.write(D,bytes([0xa5])*SIZE)
 for p,v in[(A,c.get('origin',[1.,2.,3.])),(B,c.get('target',[20.,5.,50.])),(V,c.get('velocity',[1.,0.,-2.]))]:n.pack('<3f',p,*v)
 n.pack('<f',0x925018,c.get('delta',f32(1/60)));n.pack('<3I',H,SCENE,LEGACY if c.get('legacy',True)else 0,MODERN if c.get('modern',True)else 0);n.pack('<I',LEGACY+0x40,HEADER);n.pack('<h',HEADER+0x40,c.get('index',3));n.pack('<I',SCENE+0x18,TABLE);n.pack('<I',TABLE+c.get('index',3)*4,RECORD);n.pack('<f',RECORD+0x14,c.get('scale',2.5));n.pack('<4f',MODERN+0xa0,*c.get('sphere',[2.,3.,4.,1.]));calls.clear();return bytearray(n.read(D,SIZE))
def oracle(kind,c,img):
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def f(p):return struct.unpack_from('<f',img,p-D)[0]
 def pf(p,v):struct.pack_into('<f',img,p-D,v)
 out=c.get('output',O)
 if kind=='matrix':
  for j in range(3):put(out+0x30+j*4,u(A+j*4))
  for j in[0x2c,0x24,0x20,0x1c,0x18,0x10,0xc,8,4]:put(out+j,0)
  for j in[0x3c,0x28,0x14,0]:put(out+j,0x3f800000)
 elif kind=='distance':
  if out:
   pf(out,sub(f(A),f(B)));pf(out+4,sub(f(A+4),f(B+4)));z=sub(f(A+8),f(B+8));pf(out+8,z);y=f(out+4);x=f(out)
  else:x,y,z=[sub(f(A+j*4),f(B+j*4))for j in range(3)]
  x,y,z=map(X.fl,[x,y,z]);pf(FRET,(x*x+y*y+z*z).flstore())
 elif kind=='sprite':
  legacy=u(H+4)
  if legacy:
   header=u(legacy+0x40);index=struct.unpack_from('<h',img,header-D+0x40)[0];table=u(u(H)+0x18);v=f(u(table+index*4)+0x14)
  else:
   modern=u(H+8);v=(X.fl(length([f(modern+0xa0+j*4)for j in range(3)]))+X.fl(f(modern+0xac))).flstore()
  pf(FRET,v)
 else:
  predicted=[f(B+j*4)for j in range(3)];speed=f32(c.get('speed',12.));gravity=f32(c.get('gravity',-9.8));delta=f32(c.get('delta',f32(1/60)))
  for _ in range(3):
   d=[sub(predicted[0],f(A)),predicted[1],sub(predicted[2],f(A+8))];time=div(X.fl(length(d)),X.fl(speed)).flstore();predicted=[(X.fl(f(B+j*4))+X.fl(time)*X.fl(f(V+j*4))).flstore()for j in range(3)]
  x,z=sub(predicted[0],f(A)),sub(predicted[2],f(A+8));time=div(X.fl(length([x,0.,z])),X.fl(speed)).flstore();height=sub(predicted[1],f(A+4));y=(div(X.fl(height),X.fl(time)+X.fl(delta))-X.fl(gravity)*X.fl(.5)*X.fl(time)).flstore();a=q['angle'](x,z)&65535;vx=(X.fl(q['table'][a>>1])*X.fl(speed)).flstore();vz=(X.fl(speed)*X.fl(q['table'][((a+0x4000)>>1)&32767])).flstore();pf(out,vx);pf(out+4,y);pf(out+8,vz)
def floatcall(address,args):
 code=b''.join(b'\x68'+struct.pack('<I',v&0xffffffff)for v in reversed(args));calladdr=STUB+len(code);code+=b'\xe8'+struct.pack('<i',address-calladdr-5)+b'\x83\xc4'+bytes([len(args)*4])+b'\xd9\x1d'+struct.pack('<I',FRET)+b'\xc3';n.write(STUB,code);n.mu.ctl_remove_cache(STUB,STUB+len(code));n.call(STUB)
def run(kind,c):
 before=setup(c);expected=bytearray(before);oracle(kind,c,expected);out=c.get('output',O)
 if kind=='matrix':n.call(0x5b4500,[out,A])
 elif kind=='distance':floatcall(0x5b3c50,[A,B,out])
 elif kind=='sprite':floatcall(0x5d02e0,[H])
 else:n.call(0x49f630,[out,A,B,V,bits(c.get('speed',12.)),bits(c.get('gravity',-9.8))])
 after=n.read(D,SIZE)
 if after!=expected:errors.append(dict(kind=kind,input=c,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12]))
 vectors.append(dict(kind=kind,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),deltaBits=n.unpack('<I',0x925018)[0],nativeEntryCounts=dict(calls)))
for offset in range(-80,81,4):run('matrix',dict(output=A+offset))
for index,legacy,modern in itertools.product([-256,-1,0,1,3,255],[False,True],[False,True]):
 if not legacy and not modern:continue
 run('sprite',dict(index=index,legacy=legacy,modern=modern))
for out in[0,O,A-4,A,A+4,A+8,B-4,B,B+4,B+8]:run('distance',dict(output=out))
r=random.Random(33)
for j in range(256):
 c=dict(origin=[f32(r.uniform(-500,500))for _ in range(3)],target=[f32(r.uniform(-500,500))for _ in range(3)],velocity=[f32(r.uniform(-5,5))for _ in range(3)],speed=f32(r.uniform(1,50))*(-1 if j%4==0 else 1),gravity=f32(r.uniform(-20,20)),delta=f32(r.uniform(-.25,.25)))
 run('aim',c);run('distance',dict(c,output=[0,O,A-4,A,A+4,B,B+4][j%7]));run('sprite',dict(legacy=j%2==0,index=j%511-255,scale=f32(r.uniform(-20,20)),sphere=[f32(r.uniform(-20,20))for _ in range(4)]))
for speed,gravity,delta in itertools.product([-12.,1.,12.],[-9.8,0.,9.8],[-.125,0.,f32(1/60),.25]):run('aim',dict(speed=speed,gravity=f32(gravity),delta=delta))
for out in[O,A-4,A,A+4,A+8,B-4,B,B+4,B+8,V-4,V,V+4]:run('aim',dict(output=out))
for axis in[[0.,0.,1.],[1.,0.,0.],[0.,0.,-1.],[-1.,0.,0.],[0.,1.,0.],[-0.,-0.,-0.]]:run('aim',dict(origin=[0.,0.,0.],target=axis,velocity=[0.,0.,0.],delta=.125))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=len(vectors),mismatches=len(errors),errors=errors[:10],nativeAdapters=0);(m.BASE/'reports/movement-phase33-20261013-draft-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:3])))
if errors:raise SystemExit('Projectile math mismatch; no sealed fixtures')
report.update(status='Original projectile math direct comparisons passed; managed replay pending',limits=['Finite consumed vectors/scalars and finite representable intermediate stores; nonzero speed and nonzero vertical denominator, valid complete raw pointer backing.','Exact original sine and 513-word angle tables. Legacy signed16 index with valid readable prefix, nullable optional difference output, forward translation/input aliases and projectile output/input aliases included.','No computational adapters. Float-return capture is an isolated x86 transfer stub. Signaling NaN arithmetic/load behavior excluded. Managed/game execution not performed.']);(m.BASE/'reports/movement-phase33-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase33-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(sineTable='reverse-engineering/references/native-animation-sine-table.f32',angles=q['angles'],vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
for a,b in[(0x49f630,0x49f779),(0x5b4500,0x5b4544),(0x5b3c50,0x5b3cec),(0x5d02e0,0x5d0325)]:functions.append(dict(address=hex(a),size=b-a,instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/movement-phase33-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2)+'\n')
