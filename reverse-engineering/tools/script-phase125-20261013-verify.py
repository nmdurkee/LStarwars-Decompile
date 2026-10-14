"""Original registered43c3a0 and three real origin predicates; no native adapters."""
import importlib.util,json,struct,itertools,random,math
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
s=importlib.util.spec_from_file_location('w',Path(__file__).with_name('animation-x87.py'));w=importlib.util.module_from_spec(s);s.loader.exec_module(w)
D=n.DATA;SYS=D+0x1000;ACTOR=D+0x3000;REF=D+0x4000;BASE=D+0x10000;OUT=D+0x5000;TABLE=0x29899a0
checks=0;errors=[];cases=[];shadow={};segments=[]
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(b):return struct.unpack('<f',struct.pack('<I',b))[0]
def rb(p):return shadow[p]
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):shadow[p+i]=(v>>(i*8))&255
def product(a,b):return fl((bits(a)^bits(b))&0x80000000)if a==0 or b==0 else w.store(w.mul(w.wide(a),w.wide(b)))
def add(a,b):return fl(bits(a)&bits(b)&0x80000000)if a==0 and b==0 else w.store(w.add(w.wide(a),w.wide(b)))
def products(a,b,c,d):return fl((bits(a)^bits(b))&(bits(c)^bits(d))&0x80000000)if(a==0 or b==0)and(c==0 or d==0)else w.store(w.add(w.mul(w.wide(a),w.wide(b)),w.mul(w.wide(c),w.wide(d))))
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def origin(system,actor):
 if not system or not actor:return 0
 selector=rb(actor+0x138)
 if selector==255:return 0
 if not rb(actor+0x1ec)&8:
  record=(rd(system+0x18)+selector*0xa4)&0xffffffff;column=rb(actor+0x149);x=product((column+1)//2,fl(rd(record+0x5c)))
  if column&1:x=fl(bits(x)^0x80000000)
  z=product(rb(actor+0x14a),fl(rd(record+0x60)^0x80000000));angle=rd(record+0x2c);ci=((angle+0x4000)>>1)&0x7fff;si=(angle>>1)&0x7fff;c=fl(rd(TABLE+ci*4));s=fl(rd(TABLE+si*4));rx=products(s,z,c,x);rz=products(c,z,fl(bits(s)^0x80000000),x)
  for i,value in enumerate([rx,0.,rz]):wd(actor+0xf8+i*4,bits(add(value,fl(rd(record+0x20+i*4)))))
  wd(actor+0x1ec,rd(actor+0x1ec)|8)
 return(actor+0xf8)&0xffffffff

def distance(a,b):
 delta=[add(fl(rd(a+i*4)),-fl(rd(b+i*4)))for i in range(3)]
 return bits(math.sqrt(w.dot3_plus_constant(*delta,*delta,0.)))
def evaluate(address,system,actor):
 if address==0x43c3a0:return origin(system,actor)
 fallback=0 if address==0x515360 else rd(0x75ecf0)
 if not actor or address==0x5153c0 and not rd(actor+0xe4)or address==0x515450 and(not system or not rd(system+0x138c)):return fallback
 selected=origin(system,actor)
 if not selected:
  if not system:return fallback
  selector=rb(actor+0x138)
  if selector==255:return fallback
  selected=rd(system+0x18)+selector*0xa4+0x20
 p=actor+0x14c if address==0x515360 else rd(actor+0xe4)+0x5c if address==0x5153c0 else rd(system+0x138c)+0x5c
 return distance(p,selected)
A=D+0x100;B=D+0x200;POINT=D+0x300;CLOSEST=D+0x400;RESULT=D+0x500

def dot125(a,b):
 if all(x==0 or y==0 for x,y in zip(a,b)):return add(add(product(a[0],b[0]),product(a[1],b[1])),product(a[2],b[2]))
 return w.store(w.add(w.add(w.mul(w.wide(a[0]),w.wide(b[0])),w.mul(w.wide(a[1]),w.wide(b[1]))),w.mul(w.wide(a[2]),w.wide(b[2]))))
def vec125(p):return[fl(rd(p+i*4))for i in range(3)]
def line125(first,second,point,closest):
 a=vec125(first);b=vec125(second);normal=[add(y,-x)for x,y in zip(a,b)];square=dot125(normal,normal);length=fl(bits(math.sqrt(square)));inverse=w.store(w.div(w.wide(1.),w.wide(length)));normal=[product(v,inverse)for v in normal];query=vec125(point);offset=[add(y,-x)for x,y in zip(vec125(first),query)];projection=dot125(offset,normal);position=[add(fl(rd(first+i*4)),product(v,projection))for i,v in enumerate(normal)];difference=[add(x,-y)for x,y in zip(position,vec125(point))];result=bits(dot125(difference,difference))
 if closest:
  for i,v in enumerate(position):wd(closest+i*4,bits(v))
 return result

def execute125(address,c):
 global shadow,segments,checks
 n.write(D,bytes(0x1000));n.pack('<3f',A,*c['first']);n.pack('<3f',B,*c['second']);n.pack('<3f',POINT,*c['point']);closest=0 if address==0x5bfc30 or c.get('nullOutput')else c.get('closest',CLOSEST);segments=[(D,0x1000)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};want=line125(A,B,POINT,closest);wd(RESULT,want);model=snap(True);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(address,[A,B,POINT]if address==0x5bfc30 else[A,B,POINT,closest],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0];native=snap()
 for group,a,b in [('return',got,want),('images',native,model)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(first=A,second=B,point=POINT,closest=closest,result=RESULT),initial=initial,returnValue=got,final=native))
lines=[([0.,0.,0.],[1.,0.,0.]),([0.,0.,0.],[0.,1.,0.]),([0.,0.,0.],[0.,0.,1.]),([0.,0.,0.],[3.,4.,0.]),([1.,2.,3.],[-1.,-2.,-3.]),([-100.,2.,3.],[5.,-8.,9.]),([-0.,0.,-0.],[1.,-0.,0.])]
points=[[0.,0.,0.],[1.,2.,3.],[-1.,-2.,-3.],[100.,-100.,20.],[.25,-.5,2.**-20]]
for address,(a,b),point,out in itertools.product([0x5bfae0,0x5bfc30],lines,points,[0,CLOSEST,A,A+4,B,POINT,POINT+4]):execute125(address,dict(first=a,second=b,point=point,closest=out,nullOutput=out==0))
rng=random.Random(0x5bfae0125)
for i in range(120):execute125(0x5bfae0 if i%2 else 0x5bfc30,dict(first=[rng.uniform(-10000,10000)for _ in range(3)],second=[rng.uniform(-10000,10000)for _ in range(3)],point=[rng.uniform(-10000,10000)for _ in range(3)],closest=[A,B,POINT,CLOSEST][i%4]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=2,ports=[],closure='actual5BFAE0/5BFC30→5C0240/6E9530float-spilled sqrt→5B3C50 squared math')
(nm.BASE/'reports/script-phase125-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase125-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
