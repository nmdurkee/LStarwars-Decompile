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

from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
FORM=D+0x1000;ROW=D+0x2000;PREV=D+0x2100;OWNER=D+0x3000;OWNER2=D+0x3400;OWNER3=D+0x3800;ACTOR=D+0x4000;PATH=D+0x5000;EDGE=D+0x6000;NEXTEDGE=D+0x6100;OWNEREDGE=D+0x6200;NODES=D+0x7000;ROUTES=D+0x8000;ROUTEROWS=D+0x9000;CONNECTIONS=D+0xa000;TABLE=0x29899a0;CB=n.STOP+0x900;VALUE=n.STOP+0xa00;events=[];ordinal=0;config={}
table=struct.pack('<32768f',*[math.sin(i*2*math.pi/32768)for i in range(32768)]);n.write(TABLE,table);shared=[dict(address=TABLE,bytes=table.hex())];fixed={TABLE+i:b for i,b in enumerate(table)};n.write(CB,b'\xd9\x05'+struct.pack('<I',VALUE)+b'\xc3')
def angle(p):return struct.unpack('<h',bytes(rb(p+i)for i in range(2)))[0]
def wrap(v):return(v+0x8000)%0x10000-0x8000
def turn(v,cap):return cap if v>cap else -cap if v< -cap else v
def vec(p):return[fl(rd(p+i*4))for i in range(3)]
def rotate(v,heading):
 sine=fl(rd(TABLE+((heading>>1)&0x7fff)*4));cosine=fl(rd(TABLE+(((heading+0x4000)>>1)&0x7fff)*4));x,y,z=v;return[products(sine,z,cosine,x),y,products(cosine,z,fl(bits(sine)^0x80000000),x)]
def step_port(owner,model):
 global ordinal
 ordinal+=1;events.append(dict(callback=CB,args=[owner]))
 for p,z,v in config.get('patches',{}).get(str(ordinal),[]):
  if model:
   for i in range(z):shadow[p+i]=(v>>(i*8))&255
  else:n.write(p,int(v).to_bytes(z,'little'))
 return config.get('stepBits',bits(1.25))
def hook127(mu,address,size,data):
 if address==CB:
  owner=n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0];n.pack('<I',VALUE,step_port(owner,False))
n.mu.hook_add(UC_HOOK_CODE,hook127)
def nudge(form,row,owner):
 edge=rd(row+4);desired=angle(edge+0x12)
 if rb(row+8):desired=wrap(desired+0x8000)
 heading=rd(row+0x24);heading=wrap(turn(wrap(desired-heading),angle(form+4))+heading);wd(row+0x24,heading&0xffffffff);distance=fl(step_port(owner,True))if rd(0x9238c4)else 0.;delta=rotate([0.,0.,distance],rd(row+0x24))
 for i in range(3):wd(row+0x18+i*4,bits(add(fl(rd(row+0x18+i*4)),delta[i])))
 wd(row+0x1c,rd(owner+0x60));return 0
def reset(form):
 i=0
 while i<rb(form+6):
  row=form+0x54+i*0x34;wd(row+0x28,0);wd(row+0x24,wrap(rd(row+0x24)+0x8000)&0xffffffff);shadow[row+8]=int(rb(row+8)==0);i+=1
 wd(form+0x50,rd(form+0x50)^4);wd(form,0)
 if rd(form+0x50)&4:
  for i in range(rb(form+7)-1,-1,-1):
   entry=rd(form+0xc+i*4)
   if entry and rd(entry+0x1fc)&0x1001==0x1001 and not rb(entry+0x28b):wd(form,rd(form+0xc+i*4));return 1
 else:
  i=0
  while i<rb(form+7):
   entry=rd(form+0xc+i*4)
   if rd(entry)and rd(entry+0x1fc)&0x1001==0x1001 and not rb(entry+0x28b):wd(form,rd(form+0xc+i*4));return 1
   i+=1
 return 1
def line_probe(first,second,probe):
 slot=0xfff00000
 for i,b in enumerate(struct.pack('<3f',*probe)):shadow[slot+i]=b
 result=line125(first,second,slot,0)
 for i in range(12):del shadow[slot+i]
 return fl(result)
def common(form,row,owner):
 lateral=fl(rd(form+0x124))
 if rb(row+0x30)&1:lateral=fl(bits(lateral)^0x80000000)
 side=[lateral,0.,0.];rot=rotate(side,rd(row+0x24));probe=[add(x,y)for x,y in zip(rot,vec(row+0x18))]
 if not rb(row+0x30)&2:
  next=rd(row+0x28);edge=rd(row+4);path=rd(row)
  if next==edge:
   end=rb(edge+(0x11 if not rb(row+8)else 0x10));node=rd(path+0x7c)+end*0x5c;x=add(fl(rd(row+0x18)),-fl(rd(node+4)));z=add(fl(rd(row+0x20)),-fl(rd(node+12)));distance=w.store(w.add(w.add(w.mul(w.wide(x),w.wide(x)),w.wide(0.)),w.mul(w.wide(z),w.wide(z))))
   if distance<fl(rd(node+0x14)):return reset(form)
  else:
   nodes=rd(path+0x7c);distance=line_probe(nodes+rb(next+0x10)*0x5c+4,nodes+rb(next+0x11)*0x5c+4,probe);width=fl(rd(form+0x124))
   if distance<=width*width:wd(row+0x30,rd(row+0x30)|2)
  if not rb(row+0x30)&2:
   if rb(form+0x50)&0x10:return 0
   return nudge(form,row,owner)
 desired=angle(rd(row+0x28)+0x12)
 if rb(row+0x2c):desired=wrap(desired+0x8000)
 old=rd(row+0x24);diff=wrap(desired-old);cap=angle(form+4);step=turn(diff,cap)
 if diff<=cap and diff>= -cap:wd(row+0x30,rd(row+0x30)&0xfffffffd);wd(row+4,rd(row+0x28));shadow[row+8]=rb(row+0x2c);wd(row+0x28,0);step=diff
 heading=wrap(step+old);wd(row+0x24,heading&0xffffffff);delta=rotate(side,heading)
 for i in range(3):wd(row+0x18+i*4,bits(add(probe[i],-delta[i])))
 return 0
def follow_row(form,row,previous,owner):
 edge=rd(row+4)
 if not edge:return 0
 end=rb(edge+(0x11 if not rb(row+8)else 0x10));wanted=end
 if not rd(row+0x28):
  if previous:
   value=rd(previous+4)
   if rd(row+4)==value:value=rd(previous+0x28)
   wd(row+0x28,value)
  else:
   reference=rd(form)
   if reference:
    actor=rd(reference+4);path=rd(row)
    if rd(actor+0x84)==path:
     actorEdge=rd(actor+0x88);wanted=rb(actorEdge+(0x10 if fl(rd(actor+0x94))<=.5 else 0x11));neighbors=rd(rd(path+0x84)+end*4);selection=rb(neighbors+wanted)
     if selection!=255:
      conn=rd(rd(path+0x7c)+end*0x5c+0x34);candidate=rd(conn+selection*4);wd(row+0x28,candidate)
      if rd(candidate+(4 if rb(candidate+0x10)!=end else 0)):wd(row+0x28,0)
  next=rd(row+0x28)
  if next and rd(next+(4 if rb(next+0x10)!=wanted else 0))==0:
   a=angle(rd(row+4)+0x12)
   if rb(row+8):a=wrap(0x8000+a)
   current=rb(rd(row+4)+(0x11 if not rb(row+8)else 0x10));b=angle(next+0x12)
   if current==rb(next+0x10):shadow[row+0x2c]=0
   else:shadow[row+0x2c]=1;b=wrap(0x8000+b)
   diff=wrap(b-a);wd(row+0x30,rd(row+0x30)|1 if diff<0 else rd(row+0x30)&0xfffffffe)
  if not rd(row+0x28):
   progress=fl(rd(row+0x10))
   if progress>1 if not rb(row+8)else progress<0:return 1
   return nudge(form,row,owner)
 return common(form,row,owner)
# Random selection uses the full updated uint32 RNG return, not the fraction or shifted low bits.
def random_row(form,row,previous,owner):
 edge=rd(row+4)
 if not edge:return 0
 end=rb(edge+(0x11 if not rb(row+8)else 0x10));node=rd(rd(row)+0x7c)+end*0x5c
 if not rd(row+0x28):
  if previous:
   value=rd(previous+4)
   if edge==value:value=rd(previous+0x28)
   wd(row+0x28,value)
  else:
   capacity=rb(node+0x28);seed=(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff;wd(0x95e5d4,seed);start=seed%capacity;index=0
   while index<rb(node+0x28):
    capacity=rb(node+0x28);candidate=rd(rd(node+0x34)+((index+start)%capacity)*4);wd(row+0x28,candidate);valid=False
    if candidate!=rd(row+4):
     category=rb(rd(owner+4)+0x13c);bit=1<<category if category<64 else 0;mask=rd(candidate+0x14)&0xffff if category!=255 else 0
     if category==255 or mask&bit or (rd(node+0x58)>>16)&bit:
      reverse=rb(candidate+0x10)!=end;opposite=rb(candidate+(0x10 if reverse else 0x11));target=rd(rd(row)+0x7c)+opposite*0x5c;valid=fl(rd(form+0x124))<fl(rd(target+0x10))and not rd(candidate+(4 if reverse else 0))
    if valid:break
    wd(row+0x28,0);index+=1
   if not rd(row+0x28):wd(row+0x28,rd(row+4))
  next=rd(row+0x28)
  if next and rd(next+(4 if rb(next+0x10)!=end else 0))==0:
   a=angle(rd(row+4)+0x12)
   if rb(row+8):a=wrap(0x8000+a)
   current=rb(rd(row+4)+(0x11 if not rb(row+8)else 0x10));b=angle(next+0x12)
   if current==rb(next+0x10):shadow[row+0x2c]=0
   else:shadow[row+0x2c]=1;b=wrap(0x8000+b)
   diff=wrap(b-a);wd(row+0x30,rd(row+0x30)|1 if diff<0 else rd(row+0x30)&0xfffffffe)
  if not rd(row+0x28):return 0
 return common(form,row,owner)
def execute128(c):
 global config,shadow,segments,checks,events,ordinal
 config=c;n.write(D,bytes(0xc000));n.pack('<I',FORM,0 if c.get('noOwner')else OWNER);n.pack('<h',FORM+4,c.get('cap',1024));n.write(FORM+6,bytes([3,c.get('ownerCount',3)]));n.pack('<3I',FORM+0xc,0 if c.get('nullOwnerEntry')else OWNER,OWNER2,OWNER3);n.pack('<I',FORM+0x50,c.get('formFlags',8));n.pack('<f',FORM+0x124,c.get('width',2.))
 for i in range(3):
  rr=FORM+0x54+i*0x34;n.write(rr+8,bytes([2 if i==2 else 0]));n.pack('<I',rr+0x24,i*0x4000);n.pack('<I',rr+0x28,NEXTEDGE)
 for i,p in enumerate([OWNER,OWNER2,OWNER3]):n.pack('<I',p,0 if c.get('emptyObject')and i==0 else 1);n.pack('<I',p+4,ACTOR);n.pack('<f',p+0x60,5.);n.pack('<I',p+0x1fc,c.get('ownerFlags',0x1001)if i==0 else 0x1001);n.write(p+0x28b,bytes([c.get('ownerTag',0)if i==0 else 0]))
 n.pack('<I',ACTOR+0x84,PATH+0x100 if c.get('ownerPathMismatch')else PATH);n.pack('<I',ACTOR+0x88,OWNEREDGE);n.pack('<f',ACTOR+0x94,c.get('ownerProgress',.25));n.pack('<I',PATH+0x7c,NODES);n.pack('<I',PATH+0x84,ROUTES)
 for i,p in enumerate([EDGE,NEXTEDGE,OWNEREDGE]):n.pack('<2I',p,*c.get('edgeWords',[0,0])if i==1 else[0,0]);n.write(p+0x10,bytes([0 if i==0 else 1,1 if i==0 else 2]));n.pack('<h',p+0x12,c.get('nextAngle',0x4000)if i==1 else 0)
 for i,position in enumerate([[0.,0.,0.],[10.,0.,0.],[10.,0.,10.]]):node=NODES+i*0x5c;n.pack('<3f',node+4,*position);n.pack('<f',node+0x14,c.get('nodeThreshold',1.));n.pack('<I',node+0x34,CONNECTIONS+i*0x100);n.pack('<I',CONNECTIONS+i*0x100,0 if c.get('nullCandidate')else EDGE if c.get('sameCandidate')else NEXTEDGE);n.pack('<I',ROUTES+i*4,ROUTEROWS+i*0x100);n.write(ROUTEROWS+i*0x100,bytes([c.get('routeValue',0)])*256)
 n.pack('<I',ROW,PATH);n.pack('<I',ROW+4,0 if c.get('noEdge')else EDGE);n.write(ROW+8,bytes([c.get('orientation',0)]));n.pack('<f',ROW+0x10,c.get('progress',.5));n.pack('<3f',ROW+0x18,*c.get('position',[5.,0.,0.]));n.pack('<I',ROW+0x24,c.get('heading',0)&0xffffffff);n.pack('<I',ROW+0x28,NEXTEDGE if c.get('existingNext')else EDGE if c.get('existingSame')else 0);n.write(ROW+0x2c,bytes([c.get('nextOrientation',0)]));n.pack('<I',ROW+0x30,c.get('rowFlags',0));n.pack('<I',PREV+4,EDGE if c.get('previousSame')else NEXTEDGE);n.pack('<I',PREV+0x28,NEXTEDGE if c.get('previousNext',True)else 0);n.pack('<I',0x9238c4,CB if c.get('callback')else 0)

 n.pack('<I',0x95e5d4,c.get('seed',123456789));n.write(ACTOR+0x13c,bytes([c.get('category',255)]))
 for i in range(3):
  node=NODES+i*0x5c;n.write(node+0x28,bytes([c.get('capacity',3)]));n.pack('<f',node+0x10,c.get('nodeWidth',10.));n.pack('<H',node+0x5a,c.get('nodeMask',0));n.pack('<3I',CONNECTIONS+i*0x100,*([0 if c.get('nullCandidate')else NEXTEDGE]*3 if c.get('allNext')else[EDGE,NEXTEDGE,OWNEREDGE]))
 for edge in[EDGE,NEXTEDGE,OWNEREDGE]:n.pack('<H',edge+0x14,c.get('edgeMask',1))
 segments=[(FORM,0x250),(ROW,0x34),(PREV,0x34),(OWNER,0x300),(OWNER2,0x300),(OWNER3,0x300),(ACTOR,0x200),(PATH,0x100),(EDGE,0x300),(NODES,0x200),(ROUTES,0x400),(ROUTEROWS,0x300),(CONNECTIONS,0x300),(RESULT,4),(0x9238c4,4),(0x95e5d4,4)];initial=snap();shadow=dict(fixed);shadow.update({r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))});previous=PREV if c.get('previous')else 0;events=[];ordinal=0;mfault=False;want=0
 try:want=random_row(FORM,ROW,previous,OWNER)
 except(KeyError,ZeroDivisionError):mfault=True
 wd(RESULT,want if not mfault else 0);model=snap(True);me=events.copy();events=[];ordinal=0;nfault=False;got=0
 try:got=n.call(0x51c6a0,[FORM,ROW,previous,OWNER],count=4000000)
 except RuntimeError:nfault=True
 n.pack('<I',RESULT,got if not nfault else 0);native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(formation=FORM,row=ROW,previous=previous,owner=OWNER,result=RESULT),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
for orientation,category,capacity,seed in itertools.product([0,1,2],[0,1,15,16,63,64,254,255],[0,1,2,3],[0,1,0xffffffff]):execute128(dict(orientation=orientation,category=category,capacity=capacity,seed=seed))
for category,edgeMask,nodeMask,width in itertools.product([0,1,15,16,255],[0,1,0xffff],[0,1,0xffff],[0.,2.,10.,11.]):execute128(dict(category=category,edgeMask=edgeMask,nodeMask=nodeMask,nodeWidth=width))
for c in[dict(previous=True),dict(previous=True,previousSame=True),dict(previous=True,previousSame=True,previousNext=False),dict(existingNext=True,rowFlags=2),dict(noEdge=True),dict(allNext=True,nullCandidate=True),dict(existingSame=True,position=[10.,0.,0.]),dict(callback=True,category=16,patches={'1':[[ROW+0x24,4,0x4000],[OWNER+0x60,4,bits(7.)]]}),dict(edgeWords=[1,1]),dict(existingNext=True,width=-2.),dict(existingNext=True,cap=-32768)]:execute128(c)
for seed in[0,1,2,0xffffffff,0x80000000,123456789]:
 n.pack('<I',0x95e5d4,seed);initial=[dict(address=0x95e5d4,bytes=n.read(0x95e5d4,4).hex())];want=(seed*0x19660d+0x3c6ef35f)&0xffffffff;got=n.call(0x5b9e30);final=[dict(address=0x95e5d4,bytes=n.read(0x95e5d4,4).hex())];checks+=2
 if got!=want or n.unpack('<I',0x95e5d4)[0]!=want:errors.append(dict(group='RNG',seed=seed,native=got,model=want))
 cases.append(dict(method='RNG',context={},inputs={},initial=initial,fault=False,returnValue=got,final=final,nativeEvents=[]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['optional9238C4 movement-step callback'],closure='actual51C6A0→5B9E30/64-bitshift/angles/rotation/line/XZsquare/sqrt/subtract',sharedTableSha256=nm.hashlib.sha256(table).hexdigest(),sharedTableUnchanged=n.read(TABLE,len(table))==table)
(nm.BASE/'reports/script-phase128-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase128-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,shared=shared,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
