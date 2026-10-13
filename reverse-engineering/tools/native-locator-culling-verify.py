import importlib.util,json,random,struct,base64
from fractions import Fraction as F
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
rows=[];errors=[];groups={};memory=0
I=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.]
PLANES=[1.,-1.,0.,0.,0.,0.,1.,-1.,1.,1.,1.,1.,0.,0.,0.,0.]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def wide(v):
 if not v:return v
 sign=-1 if v<0 else 1;v=abs(v);num,den=v.numerator,v.denominator;shift=max(0,num.bit_length()-64)
 if shift:
  q,r=divmod(num,1<<shift);half=1<<(shift-1)
  if r>half or r==half and q&1:q+=1
  num=q<<shift
 return sign*F(num,den)
def add(a,b):return wide(F(a)+F(b))
def mul(a,b):return wide(F(a)*F(b))
def transform(matrix,point,count=3):
 out=[]
 for c in range(count):
  x=add(add(add(mul(matrix[c],point[0]),mul(matrix[4+c],point[1])),mul(matrix[8+c],point[2])),matrix[12+c]);value=f(float(x))
  if value==0:
   approx=((matrix[c]*point[0]+matrix[4+c]*point[1])+matrix[8+c]*point[2])+matrix[12+c]
   if struct.unpack('<Q',struct.pack('<d',approx))[0]>>63:value=-0.
  out.append(value)
 return out

def outside(v):
 point=v['point']
 if v['object'] is not None:point=transform(v['object'],point)
 point=transform(v['view'],point)
 if add(v['radius'],add(point[2],-v['near']))<0 or add(v['radius'],add(v['far'],-point[2]))<0:return 1
 return int(any(x<-v['radius'] for x in transform(v['planes'],point,4)))

def run(v,kind):
 global memory
 n.write(D,bytes(0x400));n.pack('<3f',D,*v['point']);n.pack('<16f',D+0x40,*v['planes']);n.pack('<16f',0x80b708,*v['view']);n.pack('<16f',0x80b988,*v['planes']);n.pack('<2f',0x973730,v['near'],v['far'])
 if v['object'] is not None:n.pack('<16f',D+0x100,*v['object'])
 regions=[(D,0x400),(0x80b708,64),(0x80b988,64),(0x973730,8)];expected=[bytearray(n.read(p,z)) for p,z in regions]
 if kind=='outside':got=n.call(0x5d6620,[D,bits(v['radius']),D+0x100 if v['object'] is not None else 0]);want=outside(v)
 else:
  dest=D if v.get('alias',False) else D+0x200;n.call(0x5b3ec0,[dest,D,D+0x40]);got=list(n.unpack('<4I',dest));want=[bits(x) for x in transform(v['planes'],v['point'],4)];struct.pack_into('<4I',expected[0],dest-D,*want)
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 for i,(p,z) in enumerate(regions):
  memory+=1
  if n.read(p,z)!=expected[i]:bad.append(dict(region=i))
 if bad:errors.append(dict(kind=kind,values=v,bad=bad))
 rows.append(dict(kind=kind,values=v,native=got));groups[kind]=groups.get(kind,0)+1

def value(**kw):
 v=dict(point=[0.,0.,2.],view=I[:],planes=PLANES[:],object=None,radius=0.,near=1.,far=10.);v.update(kw);return v

def main():
 for x in [-5.,-2.,-1.,0.,1.,2.,5.]:
  for y in [-3.,0.,3.]:
   for z in [-1.,0.,1.,2.,10.,11.]:
    for radius in [-1.,0.,1.,3.]:run(value(point=[x,y,z],radius=radius),'outside')
 for z in [1.-2**-24,1.,1.+2**-23,10.-2**-20,10.,10.+2**-20]:
  for radius in [0.,2**-149,2**-24,2**-20]:run(value(point=[0.,0.,f(z)],radius=radius),'outside')
 rng=random.Random(5_6620)
 for i in range(768):
  matrix=[f(rng.uniform(-4,4)) for _ in range(16)];point=[f(rng.uniform(-20,20)) for _ in range(3)]
  run(value(point=point,planes=matrix,alias=bool(i%2)),'planes')
  v=value(point=point,view=[f(rng.uniform(-2,2)) for _ in range(16)],planes=matrix,object=I[:] if i%3==0 else [f(rng.uniform(-2,2)) for _ in range(16)] if i%3==1 else None,radius=f(rng.uniform(-2,20)),near=-1000.,far=1000.)
  run(v,'outside')
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,examples=errors[:8],method='Original sphere culling, affine point transform and four-plane transform execute unchanged; finite x87 reference arithmetic, exact plane output bits, complete input/global-region collateral-write checks.',limits=['Finite coordinates/matrices/radius/near/far with finite float32 transform outputs. View and plane matrix preparation are supplied records.','Portable transforms return new arrays; native point/output alias is covered, partial matrix/output overlap is excluded.','Managed replay compiled only; no game launch and no command-use credit.'])
 (B/'reports/native-locator-culling-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-locator-culling-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
