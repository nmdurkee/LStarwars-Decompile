"""Run original opponent helper bodies, with all numeric/vector callees unchanged."""
import importlib.util,json,struct,itertools,math,random
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
n=a.n;BASE=a.BASE;D=a.D;V=D+0x60000;OUT=V+64
s=importlib.util.spec_from_file_location('wide',Path(__file__).with_name('animation-x87.py'));wide=importlib.util.module_from_spec(s);s.loader.exec_module(wide)
checks={};errors=[];vectors=[]
def f(v):return a.f(v)
def sub(x,y):return [f(a-b) for a,b in zip(x,y)]
def sq(d):return wide.dot3_plus_constant(*d,*d,0)
def sphere(origin,direction,center,radius,old):
 d=sub(center,origin);dot=wide.dot3_plus_constant(d[1],d[0],d[2],direction[1],direction[0],direction[2],0)
 if dot<0:return dict(result=0,output=a.bits(old))
 residual=f(wide.dot3_plus_constant(d[2],d[0],d[1],d[2],d[0],d[1],0)-f(dot*dot))
 return dict(result=int(residual<=radius),output=a.bits(residual if residual<=radius else old))
def check(kind,data,got,want):
 checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,data=data,got=got,want=want))
 vectors.append(dict(kind=kind,data=data,native=got))
def floatcall(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',OUT)[0]
def assigned(own,flags,index,target,players):
 n.pack('<I',a.actor(0)+0xef4,flags);n.pack('<B',a.actor(0)+0x1084,index)
 for i,p in enumerate(players):n.pack('<I',0x93d7f0+i*4,a.actor(p))
 got=n.call(0x43d410,[a.actor(0) if own else 0,a.actor(target)])
 want=int(own and (not flags&0x2000 or (index!=255 and players[index]==target)))
 check('assignment',dict(own=own,flags=flags,index=index,target=target,players=players),got,want)
def band(row,entries,assigned,threshold,step,base):
 n.pack('<I',a.actor(0)+0x3ac,a.actor(1));n.pack('<b',a.actor(1)+0x280,row)
 n.pack('<iff',0x7f671c,threshold,step,base);n.write(0x876858,bytes(9*17*8+8))
 if 0<=row<=8:
  for i,p in enumerate(entries):n.pack('<I',0x876858+(row*17+i)*8,a.actor(p))
 for i,x in enumerate(assigned):n.pack('<B',a.actor(i)+0x1084,x)
 wanted=.75
 if 0<=row<=8:
  wanted=base;unassigned=ring=0
  for p in entries[:17]:
   if p<0:break
   if p==0:wanted=wide.store(wide.add(wide.mul(wide.wide(ring),wide.wide(step)),wide.wide(base)));break
   if assigned[p]==255:unassigned+=1
   if unassigned>=threshold:ring+=1;unassigned=0
 got=floatcall(0x43d450,[a.actor(0)]);check('band',dict(row=row,entries=entries,assigned=assigned,threshold=threshold,step=step,base=base),got,a.bits(wanted))
def ray(origin,direction,center,radius,output=True):
 origin=list(map(f,origin));direction=list(map(f,direction));center=list(map(f,center));radius=f(radius);old=123.25
 for ptr,v in [(V,origin),(V+16,direction),(V+32,center)]:n.pack('<3f',ptr,*v)
 n.pack('<f',OUT,old);result=n.call(0x551730,[V,V+16,V+32,a.bits(radius),OUT if output else 0]);got=dict(result=result,output=n.unpack('<I',OUT)[0]);want=sphere(origin,direction,center,radius,old)
 if not output:want['output']=a.bits(old)
 check('raySphere',dict(origin=origin,direction=direction,center=center,radius=radius,output=output),got,want)
def obstruct(origins,radii,flags,active,players):
 origins=[list(map(f,v)) for v in origins];radii=list(map(f,radii))
 for i in range(8):n.pack('<3f',a.actor(i)+0x80,*origins[i]);n.pack('<f',a.actor(i)+0x1dc,radii[i]);n.pack('<II',a.actor(i)+0x1f8,flags if i==0 else 0,active[i])
 for i,p in enumerate(players):n.pack('<I',0x93d7f0+i*4,a.actor(p))
 got=n.call(0x440150,[a.actor(0),a.actor(1)]);want=0
 if not flags&5:
  delta=sub(origins[1],origins[0]);distance=sq(delta);length=f(math.sqrt(distance));scale=f(1/length) if length else 0;direction=[f(d*scale) for d in delta]
  for p in players:
   if p<0 or p in [0,1] or active[p]&0x1001!=0x1001:continue
   if sq(sub(origins[0],origins[p]))>=distance:continue
   radius=f(radii[p]+.125)
   if sphere(origins[0],direction,origins[p],f(radius*radius),0)['result']:want=1;break
 check('obstruction',dict(origins=origins,radii=radii,flags=flags,active=active,players=players),got,want)
def main():
 for own,flags,index,target,players in itertools.product([False,True],[0,0x2000,0xffffffff],[0,1,7,255],[-1,0,1,2,7],[[0,1,2,3,4,5,6,7],[-1]*8,[1]*8]):assigned(own,flags,index,target,players)
 for row,pos,threshold,variant in itertools.product([-128,-1,0,1,8,9,127],[-1,0,1,8,16,17],[-1,0,1,2,32],[0,1]):
  entries=[2+i%6 for i in range(18)]
  if pos>=0:entries[pos]=0
  assignments=[255]*8 if variant==0 else [0,255,1,255,2,255,3,255]
  band(row,entries,assignments,threshold,.75 if variant==0 else f(-.2),1.25)
 band(0,[2,-1,0]+[-1]*15,[255]*8,1,.75,.75)
 band(0,[2,0]+[-1]*16,[255]*8,1,f(1+2**-23),2**-24+2**-47)
 for point in itertools.permutations([1.,2**-12,2**-27]):
  for direction in [[0.,0.,0.],list(point)]:ray([0,0,0],direction,list(point),1.)
 for center,radius,direction,output in itertools.product([[0,0,0],[0,0,1],[0,0,-1],[1,0,1],[0,1,1],[1,1,1],[.5,0,1]],[-1,0,.249999985,.25,.25000003,1,2],[[0,0,1],[0,0,0],[0,0,2],[1,0,0]],[True,False]):ray([0,0,0],direction,center,radius,output)
 rng=random.Random(0x551730)
 for i in range(512):
  origin=[f(rng.uniform(-100,100)) for _ in range(3)];center=[f(rng.uniform(-100,100)) for _ in range(3)];direction=[f(rng.uniform(-2,2)) for _ in range(3)];ray(origin,direction,center,rng.uniform(-1,40000))
 origins=[[0,0,0],[0,0,10]]+[[0,0,5] for _ in range(6)]
 for xyz,radius,flags,active,slot in itertools.product([[0,0,-1],[0,0,0],[0,0,5],[0,0,10],[0,0,11],[1,0,5],[.625,0,5],[.62500006,0,5]],[-.5,0,.5,1],[0,1,4,0x400],[0,1,0x1000,0x1001],[0,7]):
  origins[2]=xyz;players=[-1]*8;players[slot]=2;act=[0x1001]*8;act[2]=active;obstruct(origins,[radius]*8,flags,act,players)
 for i in range(256):
  origins=[[rng.uniform(-3,3) for _ in range(3)] for _ in range(8)];obstruct(origins,[rng.uniform(0,2) for _ in range(8)],0,[0x1001]*8,list(range(8)))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:10],method='Original 0x43d410,0x43d450,0x551730,0x440150 and numeric/vector callees run unchanged. Independent Python projection compared per case; no callbacks substituted in these helper calls.',limits=['Finite float32 inputs, valid eight-slot player assignment or255, supplied table/actor attachments.','Table generation and permission-mask producer are not included.','No managed execution; C# comparison awaits permitted execution.'])
 (BASE/'reports/gameplay-opponent-targeting-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-opponent-targeting-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 dis=Cs(CS_ARCH_X86,CS_MODE_32)
 assembly={hex(start):[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in dis.disasm(n.read(start,size),start)] for start,size in [(0x43d410,0x3d),(0x43d450,0xae),(0x551730,0xcd),(0x440150,0x138)]}
 (BASE/'reports/gameplay-opponent-targeting-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=assembly),indent=2),encoding='utf8')
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
