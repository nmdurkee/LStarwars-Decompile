import struct,json,gzip,importlib.util,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent
s=importlib.util.spec_from_file_location('x',P/'animation-x87.py');x=importlib.util.module_from_spec(s);s.loader.exec_module(x);W=x.wide;A=x.add;M=x.mul;D=x.div;S=x.store
def sub(a,b):return A(a,(-b[0],b[1]))
def floats(a):return [struct.unpack('<f',struct.pack('<I',v))[0]for v in a]
def words(a):return [struct.unpack('<I',struct.pack('<f',v))[0]for v in a]
def negative(v):return math.copysign(1,v)<0
def multiplyStore(a,b):
 v=S(M(W(a),W(b)));return -0. if v==0 and negative(a)!=negative(b) else v
def divideStore(a,b):
 v=S(D(W(a),W(b)));return -0. if v==0 and negative(a)!=negative(b) else v
def blendStore(axis,k,dir,a):
 v=S(A(M(W(axis),W(k)),M(W(dir),W(a))))
 if v==0 and (axis==0 or k==0) and (dir==0 or a==0) and negative(axis)!=negative(k) and negative(dir)!=negative(a):return -0.
 return v
def dot(a,b,order=(0,1,2)):
 v=[M(W(a[i]),W(b[i]))for i in order];out=S(A(A(v[0],v[1]),v[2]));return -0. if out==0 and all(p[0]==0 for p in v) and all(negative(a[i])!=negative(b[i]) for i in order) else out
def dotWide(a,b):
 v=[M(W(a[i]),W(b[i]))for i in(1,0,2)];return A(A(v[0],v[1]),v[2])
def norm(a):
 q=dot(a,a,(1,0,2));length=struct.unpack('<f',struct.pack('<f',math.sqrt(q)))[0];reciprocal=S(D(W(1),W(length))) if length>0 else 0.;return [multiplyStore(reciprocal,v)for v in a]
def model(c):
 camera=floats(c['cameraWords']);direction=floats(c['nativeDirectionWords']);aim=floats(c['aimWords']);inverse=[dot(direction,camera[i:i+3],(1,0,2) if i==0 else (0,1,2))for i in(0,4,8)];lerp=[S(A(M(sub(W(inverse[i]),W(aim[i])),W(.5)),W(aim[i])))for i in range(3)];trans=[dot(lerp,[camera[i],camera[i+4],camera[i+8]],(1,0,2) if i==0 else (0,1,2))for i in range(3)];t=norm(trans);d=norm(direction);factor=dot([-v for v in camera[8:11]],d,(1,0,2));h=struct.unpack('<f',struct.pack('<f',math.sqrt(S(A(M(W(t[0]),W(t[0])),M(W(t[2]),W(t[2])))))))[0];m=floats(c['identityWords']);X,Y,Z=t
 if h>1.1754943508222875e-38:
  m[0]=divideStore(Z,h);m[1]=0.;m[2]=divideStore(X,h);m[4]=S(D(M(W(X),W(Y)),W(h))) if X and Y else multiplyStore(X,Y);m[5]=h;m[6]=S(D(M(W(-Y),W(Z)),W(h))) if Y and Z else multiplyStore(-Y,Z);m[8]=-X;m[9]=Y;m[10]=Z
 else:m[10]=m[5]=0.;m[9]=Y;m[6]=-Y
 m[12]=m[13]=.5
 if factor<0:
  a=factor
  for _ in range(5):a=S(M(W(a),W(a)))
  k=S(sub(W(1),W(a)))
  for column in(0,1):
   axis=[m[column+i*4]for i in range(3)];positive=dotWide(axis,d)[0]>=0
   for i in range(3):m[column+i*4]=blendStore(axis[i],k,d[i] if positive else -d[i],a)
 return words(m),words([-v for v in inverse])
f=json.loads(gzip.decompress((B/'reports/scene-phase7-20261013-light-native-fixtures.json.gz').read_bytes()));errors=[]
for i,c in enumerate(f['producerCases']):
 m,v=model(c)
 if m!=c['matrixWords'] or v!=c['vectorWords']:errors.append({'case':i,'matrix':[(j,hex(a),hex(b))for j,(a,b)in enumerate(zip(m,c['matrixWords']))if a!=b],'vector':[(j,hex(a),hex(b))for j,(a,b)in enumerate(zip(v,c['vectorWords']))if a!=b]})
print(json.dumps({'cases':len(f['producerCases']),'errors':len(errors),'examples':errors[:12]},indent=2))
