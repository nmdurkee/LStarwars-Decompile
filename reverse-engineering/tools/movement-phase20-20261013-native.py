"""Original pod normalized/distance curves with exact spilled float arithmetic andaliases."""
import importlib.util,struct,json,gzip,itertools,base64,random,math
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;CURVE=D+0x1000;OUT=D+0x3000;SIZE=0x10000;vectors=[];errors=[];groups={}
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
p4=Path(__file__).with_name('movement-phase4-20261013-native.py').read_text();exec(p4[p4.index('def quant('):p4.index('def readstr(')])
def add(a,b):return(X.fl(a)+X.fl(b)).flstore()
def sub(a,b):return(X.fl(a)-X.fl(b)).flstore()
def mul(a,b):return(X.fl(a)*X.fl(b)).flstore()
def normal(v):
 x,y,z=map(X.fl,v);square=(x*x+y*y+z*z).flstore();length=f32(math.sqrt(square));recip=0. if length<=0 else f32(float(quant(Fraction(1)/Fraction(float(length)),24)));return[mul(recip,x)for x in v]
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);count=c.get('count',4);points=c.get('points',[[f32(j*1.125),f32(j*j*.375),f32(j*-2.5),f32(.125+j*.25)]for j in range(count+2)])
 for j,pt in enumerate(points):n.pack('<4f',CURVE+j*16,*pt)
 n.pack('<I',CURVE+0x400,count);n.pack('<2f',CURVE+0x404,.25,-.5);n.pack('<f',CURVE+0x410,c.get('length',count*10.));
 for j in range(count):n.pack('<f',CURVE+0x414+j*4,c.get('cumulative',[(v+1)*10. for v in range(count)])[j])
 return bytearray(n.read(D,SIZE))
def normalized(image,out,u):
 def fl(p):return val(struct.unpack_from('<I',image,p-D)[0])
 def vec(p):return[fl(p+j*4)for j in range(3)]
 def ghost(p,q):
  a,b=vec(p),vec(q);unit=normal([sub(x,y)for x,y in zip(a,b)]);return[add(x,mul(y,10.))for x,y in zip(a,unit)]
 count=struct.unpack_from('<i',image,CURVE-D+0x400)[0];scaled=mul(count-1,u);old=int(scaled);fraction=sub(scaled,old);index=old
 if index<=0:before=ghost(CURVE,CURVE+16);index=0
 else:
  if index>count-1:index=count
  before=vec(CURVE+index*16-16)
 current=CURVE+index*16;p,q=vec(current),vec(current+16);after=vec(CURVE+(index+2)*16)if index<count-2 else ghost(CURVE+(count-1)*16,CURVE+(count-2)*16)
 square=X.fl(fraction)*X.fl(fraction);sq=square.flstore();cube=(square*X.fl(fraction)).flstore();twice=[];linear=[];quadratic=[];cubic=[]
 for j in range(3):
  twice.append(add(p[j],p[j]));linear.append(mul(sub(q[j],before[j]),fraction));quadratic.append(mul(sub(add(sub(add(before[j],before[j]),mul(p[j],5.)),mul(q[j],4.)),after[j]),sq));cubic.append(mul(add(sub(mul(sub(p[j],q[j]),3.),before[j]),after[j]),cube))
 for j in range(3):struct.pack_into('<f',image,out-D+j*4,mul(add(add(add(linear[j],twice[j]),quadratic[j]),cubic[j]),.5))
 pw,qw=fl(current+12),fl(current+28);w=((X.fl(qw)-X.fl(pw))*X.fl(fraction)+X.fl(pw)).flstore();struct.pack_into('<f',image,out-D+12,w)
def model(k,c,image,out,param):
 if k=='distance':
  length=val(struct.unpack_from('<I',image,CURVE-D+0x410)[0]);count=struct.unpack_from('<i',image,CURVE-D+0x400)[0]
  if param>=length:param=1.
  else:
   for j in range(count):
    end=val(struct.unpack_from('<I',image,CURVE-D+0x414+j*4)[0])
    if param<end:
     previous=0. if j==0 else val(struct.unpack_from('<I',image,CURVE-D+0x410+j*4)[0]);num=X.fl(param)-X.fl(previous);den=X.fl(end)-X.fl(previous);ratio=X(quant(num.v/den.v,64),num.neg!=den.neg).flstore();value=X.fl(ratio)+X(j);param=X(quant(value.v/Fraction(count),64),value.neg).flstore();break
 normalized(image,out,param)

def run(k,c,param,out=OUT,group='synthetic'):
 before=setup(c);expected=bytearray(before);model(k,c,expected,out,param);n.call(0x40eff0 if k=='normalized'else 0x40f450,[CURVE,out,bits(param)],count=500000);after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected:errors.append(dict(kind=k,input=c,parameterBits=bits(param),output=out,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(kind=k,input=dict(c),parameterBits=bits(param),output=out,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode()))
for count,param in itertools.product([2,3,4,8,16,63,64],[-2.,-.125,0.,.125,.5,.875,1.,1.125,2.]):run('normalized',dict(count=count),param,group='count-boundaries-segment-clamp')
for count,distance in itertools.product([2,3,4,8,16],[ -10.,0.,5.,10.,15.,20.,50.,100.,200.]):run('distance',dict(count=count),distance,group='distance-cumulative-boundary-remap')
r=random.Random(20261021)
for j in range(512):
 count=r.randrange(2,17);points=[[f32(r.uniform(-1e4,1e4))for v in range(4)]for i in range(count+2)];c=dict(count=count,points=points);run('normalized',c,f32(r.uniform(-.5,1.5)),group='normalized-cubic-store-rounding');run('distance',c,f32(r.uniform(-10.,count*10.+10.)),group='distance-store-rounding')
for parameter,point,offset in itertools.product([0.,.25,.75,1.,1.25],[0,1,2,3],[-4,0,4,8,12]):run('normalized',{},parameter,CURVE+point*16+offset,group='output-input-shifted-alias-W-late-read')
for count in[2,4,8]:
 points=[[0.,0.,0.,float(j)]for j in range(count+2)]
 for parameter in[-0.,0.,.125,.5,1.,1.25]:run('normalized',dict(count=count,points=points),parameter,group='zero-endpoint-norm-signedzero')
for param in[5.,15.,25.,35.]:run('distance',dict(count=4,length=100.,cumulative=[2.,4.,6.,8.]),param,group='no-cumulative-match-preserves-distance-as-parameter')
# Direct normalization validates the refined finite vector projection in place or separate.
for j in range(256):
 count=4;c=dict(count=count);before=setup(c);expected=bytearray(before);v=[f32(r.uniform(-1e5,1e5))for v in range(3)]if j else[-0.,0.,0.];source=CURVE;output=source if j%2 else OUT;n.pack('<3f',source,*v);before=bytearray(n.read(D,SIZE));expected=bytearray(before);unit=normal(v)
 for k,x in enumerate(unit):struct.pack_into('<f',expected,output-D+k*4,x)
 n.call(0x5b3b30,[output,source]);after=n.read(D,SIZE)
 if after!=expected:errors.append(dict(kind='normalize',vectorBits=[bits(x)for x in v],output=output,diff=[[hex(k),after[k],expected[k]]for k in range(SIZE)if after[k]!=expected[k]][:16]))
 vectors.append(dict(kind='normalize',input=c,parameterBits=0,output=output,source=source,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode()));groups['direct-finite-normalization-inplace-separate']=groups.get('direct-finite-normalization-inplace-separate',0)+1
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],nativeAdapters=0,limits=['Finite prepared2..64point backing includingrawnext/header records,finite derivatives andnormalizations; bounded representableFTOL scaledparameters.','Allnumeric resolver-free evaluation,FTOL,normalize/sqrt originals execute. Entire65536byte memoryimage retained, includingaliased XYZ stores andlateW reads.','No authoredCreatePod commandcredit orlivecurveproducer/heading/spawn claim. Existing5b3b30 onlyrefinednumeric projection withno newentrycount.'])
(m.BASE/'reports/movement-phase20-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase20-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=len(vectors),mismatches=len(errors),errors=errors[:5])))
