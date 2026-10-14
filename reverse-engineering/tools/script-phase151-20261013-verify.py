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
exec(Path(__file__).with_name('script-phase124-20261013-verify.py').read_text().split('\ndef execute124(')[0])
# New native instance excludes all scheduler/row adapters from imported fixture scaffolding.
n=nm.NativeX86();n.write(TABLE,table);CB=n.STOP+0x900;VALUE=n.STOP+0xa00;n.write(CB,b'\xd9\x05'+struct.pack('<I',VALUE)+b'\xc3');n.mu.hook_add(UC_HOOK_CODE,hook127)
FORM=D+0x1000;FORM2=D+0x1400;OWNER=D+0x3000;OWNER2=D+0x3400;OWNER3=D+0x3800;ACTOR=D+0x4000;TARGET=D+0x4500;TARGETREF=D+0x3200;OWNREF=OWNER;PATH=D+0x5000;EDGE=D+0x6000;NEXTEDGE=D+0x6100;OWNEREDGE=D+0x6200;NODES=D+0x7000;ROUTES=D+0x8000;ROUTEROWS=D+0x9000;CONNECTIONS=D+0xa000;NODEA=D+0xb000;NODEB=D+0xb100;SYS=D+0xc000;P=D+0xc200;ARGS=D+0xd000;RESULT=D+0x500
from unicorn.x86_const import UC_X86_REG_ESI

def dispatch_game(form,callback):
 previous=0;blocked=False;reverse=bool(rd(form+0x50)&4)
 if callback and rd(form+0x50)&8:
  index=rb(form+6)-1 if reverse else 0
  while index>=0 if reverse else index<rb(form+6):
   row=form+0x54+index*0x34
   if rb(row+0x2d):
    value=follow_row(form,row,previous,rd(form))if callback==0x51cbc0 else random_row(form,row,previous,rd(form))
    if value:break
    if rb(row+0x30)&2:blocked=True
    previous=row
   index+=-1 if reverse else 1
 wd(form+0x50,(rd(form+0x50)&~0x10)|(0x10 if blocked else 0))
def schedule(callback,model):dispatch_game(rd(ACTOR+0x144),callback)
def node146(method,first):
 away=method=='Away'
 if not rd(ACTOR+0xd0)or not rd(ACTOR+0x158)or not rd(ACTOR+0x15c):return 1
 if first:
  if method=='Random':wd(0x95e5d4,(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff)
  node=NODES+0x5c;wd(P+0x6c,node)
  if not rb(node+0x28):return 1
  path=rd(ACTOR+0x158);index=(node-rd(path+0x7c))//0x5c
  if not away:wd(P+0x84,path)
  edge=rd(rd(node+0x34));wd(P+0x88,edge);wd(P+0x94,0 if rb(edge+0x10)==index else bits(1.));flags=rb(P+0x92)|rb(P+0x93)<<8;shadow[P+0x92]=(flags|1)&255;shadow[P+0x93]=flags>>8;wd(P+0x98,0);shadow[P+0x8c]=0;set124(ACTOR,node+4,0,P+0x84,2 if away else 1,rd(ACTOR+0x180));return 0
 selected=rd(P+0x6c)
 if selected:
  x=add(fl(rd(ACTOR+0x14c)),-fl(rd(selected+4)));z=add(fl(rd(ACTOR+0x154)),-fl(rd(selected+12)));distance=w.store(w.add(w.add(w.mul(w.wide(x),w.wide(x)),w.wide(0.)),w.mul(w.wide(z),w.wide(z))))
  if not away:set124(ACTOR,selected+4,0,P+0x84,1,rd(ACTOR+0x180))
  if fl(rd(selected+0x14))<=distance:
   if away:set124(ACTOR,selected+4,0,P+0x84,2,rd(ACTOR+0x180))
   return 0
 return 1

def opponent147(c):
 if c.get('nullActor'):return 1
 if c.get('first',1):
  for i in range(max(0,c.get('count',len(c.get('tokens',[]))))):
   token=rd(ARGS+i*4)
   if rd(0x9238b0):
    value={b'RUN':0,b'WALK':1,b'TIPTOE':2}.get(bytes(map(foldbyte,byte_text(token))))
    if value is not None:shadow[ACTOR+0x13f]=value;continue
   if eq(token,0x758218):shadow[P+0x68]=rb(P+0x68)|2
   elif eq(token,0x758208):shadow[P+0x68]=rb(P+0x68)|1
   else:wd(ACTOR+0x180,expression122(ACTOR,P,rd(ARGS+i*4)))
 target=rd(ACTOR+0xe4)
 if target and rd(target+4):intent124(rd(ACTOR+0xd0),target,rb(P+0x68),rd(ACTOR+0x180))
 return 0

def draw148():
 seed=(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff;wd(0x95e5d4,seed);return(seed&0x7fffff)/8388608

def path148(c):
 if c.get('nullActor'):return 1
 reference=rd(ACTOR+0xd0)
 if not reference or not rd(reference):return 1
 if not rd(ACTOR+0x158)or not rd(ACTOR+0x15c):return 0
 if c.get('first',1):
  wd(ACTOR+0x188,0);minimum=maximum=0.
  for i in range(max(0,c.get('count',len(c.get('tokens',[]))))):
   token=rd(ARGS+i*4)
   if rd(0x9238b0):
    value={b'RUN':0,b'WALK':1,b'TIPTOE':2}.get(bytes(map(foldbyte,byte_text(token))))
    if value is not None:shadow[ACTOR+0x13f]=value;continue
   at=substring(token,0x7581bc)
   if at:minimum=fl(expression122(ACTOR,P,at+8))
   else:
    at=substring(rd(ARGS+i*4),0x7581b4)
    if at:maximum=fl(expression122(ACTOR,P,at+8))
    else:wd(P+0x9c,expression122(ACTOR,P,rd(ARGS+i*4)))
  if minimum<maximum:
   draw=draw148();first=w.mul(w.add(w.wide(1.),w.wide(-draw)),w.wide(minimum));spill=math.ldexp(float(first[0]),first[1]);second=draw148();wd(P+0x9c,bits(w.store(w.add(w.mul(w.wide(second),w.wide(maximum)),w.wide(spill)))))
 formation=rd(ACTOR+0x144)
 if not formation or not rb(formation+0x50)&8:wd(ACTOR+0x1c0,0);wd(ACTOR+0x1c4,rd(ACTOR+0x180));wd(ACTOR+0x1e8,(rd(ACTOR+0x1e8)&0xfffffffc)|4)
 else:
  if rd(formation)==rd(ACTOR+0xd0):dispatch_game(formation,0x51c6a0)
  formation124(ACTOR)
 wait=fl(rd(P+0x9c))
 if wait>0:
  wait=add(wait,-fl(bits(c.get('delta',.1))));wd(P+0x9c,bits(wait))
  if wait<=0:return 1
 return 0

def go149(c):
 if c.get('nullActor'):return 1
 if not rd(ACTOR+0xd0)or not rd(ACTOR+0x158)or not rd(ACTOR+0x15c)or not rd(rd(ACTOR+0xd0)+0x1f8)&0x400 or rb(ACTOR+0x138)==255:return 1
 system=0 if c.get('nullSystem')else SYS;record=rd(system+0x18)+rb(ACTOR+0x138)*0xa4;point=origin(system,ACTOR)if rd(0x923908)else 0
 if not point:point=record+0x20
 if c.get('first',1):
  wd(ACTOR+0x180,bits(.2));minimum=maximum=0.
  for i in range(max(0,c.get('count',len(c.get('tokens',[]))))):
   token=rd(ARGS+i*4)
   if rd(0x9238b0):
    value={b'RUN':0,b'WALK':1,b'TIPTOE':2}.get(bytes(map(foldbyte,byte_text(token))))
    if value is not None:shadow[ACTOR+0x13f]=value;continue
   at=substring(token,0x760be4)
   if at:wd(P+0x9c,expression122(ACTOR,P,at+9))
   else:
    at=substring(rd(ARGS+i*4),0x7581bc)
    if at:minimum=fl(expression122(ACTOR,P,at+8))
    else:
     at=substring(rd(ARGS+i*4),0x7581b4)
     if at:maximum=fl(expression122(ACTOR,P,at+8))
     elif eq(rd(ARGS+i*4),0x760bd4):shadow[P+0x69]=1
     else:
      at=substring(rd(ARGS+i*4),0x757994);wd(ACTOR+0x180,expression122(ACTOR,P,at+10 if at else rd(ARGS+i*4)))
  if fl(rd(P+0x9c))==0:
   value=fl(bits(.01))if maximum<=minimum else w.store(w.add(w.mul(w.wide(draw148()),w.add(w.wide(maximum),w.wide(-minimum))),w.wide(minimum)));wd(P+0x9c,bits(value))
  set124(ACTOR,point,0,record+0x30,1,rd(ACTOR+0x180));wd(P+0x78,0);wd(P+0x7c,0);wd(P+0x80,bits(1.));rot=rotate(vec(P+0x78),rd(record+0x2c))
  for i,value in enumerate(rot):wd(P+0x78+i*4,bits(value))
  for i in range(3):wd(P+0x78+i*4,bits(add(fl(rd(P+0x78+i*4)),fl(rd(point+i*4)))))
  return 0
 set124(ACTOR,point,0,record+0x30,1,rd(ACTOR+0x180));delta=[add(fl(rd(ACTOR+0x14c+i*4)),-fl(rd(point+i*4)))for i in range(3)]
 if rb(P+0x69):delta[1]=0.
 distance=w.store(w.add(w.add(w.mul(w.wide(delta[0]),w.wide(delta[0])),w.mul(w.wide(delta[1]),w.wide(delta[1]))),w.mul(w.wide(delta[2]),w.wide(delta[2]))));basis=add(fl(rd(0x801c6c)),fl(rd(ACTOR+0x180)));dt=fl(bits(c.get('delta',.1)));threshold=w.store(w.add(w.mul(w.wide(dt),w.wide(fl(rd(rd(ACTOR+0xd0)+0x22c)))),w.wide(basis)));square=w.mul(w.wide(threshold),w.wide(threshold));square=math.ldexp(float(square[0]),square[1])
 if distance<square:
  wd(ACTOR+0x1e4,P+0x78);wait=fl(rd(P+0x9c))
  if wait<=0:return 1
  wait=add(wait,-dt);wd(P+0x9c,bits(wait))
  if wait<0:wd(P+0x9c,0)
 return 0

LOCATORS=D+0x18000;CHARACTER=D+0x17000;DONE=n.STOP+0xb00
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP

def formatter151(format,a,b,argc,model):
 read=lambda p:byte_text(p)if model else native_text151(p)
 if argc==2 and format==0x7577d4:result=read(a)+b'_'+str(b if b<0x80000000 else b-0x100000000).encode()
 elif argc==2 and format==0x7577cc:result=read(a)+b'_'+(read(b)if b else b'(null)')
 else:
  raw=read(format)
  if b'%'in raw.replace(b'%%',b''):raise ValueError('Unprepared variadic format')
  result=raw.replace(b'%%',b'%')
 if len(result)>63:raise ValueError('Prepared64byte output domain')
 events.append(dict(service='sprintf',format=format,first=a,second=b,arguments=argc,bytes=list(result)))
 return result

def native_text151(p):
 value=[]
 while n.read(p,1)[0]:value.append(n.read(p,1)[0]);p+=1
 return bytes(value)
def completion151(callback,owner,point,model):
 events.append(dict(callback=callback,args=[owner,point]));return config.get('completeResult',0)
def port151(mu,address,size,data):
 if address==0x6e69ef:
  sp=mu.reg_read(UC_X86_REG_ESP);out,format=n.unpack('<2I',sp+4);argc=2 if format in[0x7577d4,0x7577cc]else 0;a,b=n.unpack('<2I',sp+12)if argc else(0,0);value=formatter151(format,a,b,argc,False);n.write(out,value+b'\0');ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,len(value));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==DONE:
  sp=mu.reg_read(UC_X86_REG_ESP);owner,point=n.unpack('<2I',sp+4);value=completion151(address,owner,point,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,port151)
def drawint151():
 state=rd(0x8066c0);x=state^0x075bd924;signed=x if x<0x80000000 else x-0x100000000;q=abs(signed)//0x1f31d*(-1 if signed<0 else 1);value=(x*0x41a7-q*0x7fffffff)&0xffffffff
 if value&0x80000000:value=(value+0x7fffffff)&0xffffffff
 value^=0x075bd924;wd(0x8066c0,value);return value

def lookup151(system,value):
 key=bytes(map(foldbyte,value));i=0
 if not system:return 0
 while i<(rd(system+0x24)if rd(system+0x24)<0x80000000 else rd(system+0x24)-0x100000000):
  row=rd(system+0x28)+i*0x3c
  if bytes(map(foldbyte,byte_text(row)))==key:return rd(system+0x28)+i*0x3c
  i+=1
 return 0

def go151(c):
 if c.get('nullActor'):return 1
 if not rd(ACTOR+0xd0)or not rd(rd(ACTOR+0xd0))or not rd(ACTOR+0x158)or not rd(ACTOR+0x15c):return 1
 if c.get('first',1):
  shadow[P+0x68]=0;wd(P+0x6c,rd(P+0xa4));personal=indexed=False;randomCount=0;minimum=maximum=0.;i=0;count=c.get('count',len(c.get('tokens',[])))
  while i<count:
   token=rd(ARGS+i*4)
   if rd(0x9238b0):
    value={b'RUN':0,b'WALK':1,b'TIPTOE':2}.get(bytes(map(foldbyte,byte_text(token))))
    if value is not None:shadow[ACTOR+0x13f]=value;i+=1;continue
   if substring(rd(ARGS+i*4),0x75782c)or substring(rd(ARGS+i*4),0x75850c):
    i+=1
    if i<count:
     owner=rd(ACTOR+0xd0);name=rd(ARGS+i*4);format=name;a=b=argc=0;index=rb(owner+0x280);index=index if index<128 else index-256
     if indexed and index!=-1:format=0x7577d4;a=name;b=index&0xffffffff;argc=2
     elif personal and rd(owner+0x54):format=0x7577cc;a=name;b=rd(rd(owner+0x54)+0xc);argc=2
     elif randomCount:
      value=drawint151();value=value if value<0x80000000 else value-0x100000000;q=abs(value)//abs(randomCount)*(-1 if(value<0)!=(randomCount<0)else 1);remainder=value-q*randomCount;format=0x7577d4;a=name;b=remainder&0xffffffff;argc=2
     name=formatter151(format,a,b,argc,True);wd(P+0x6c,lookup151(0 if c.get('nullSystem')else SYS,name))
    if substring(rd(ARGS+(i-1)*4),0x75850c):
     selected=rd(P+0x6c)
     if selected:
      owner=rd(ACTOR+0xd0)
      for j in range(3):wd(owner+0x5c+j*4,rd(selected+0x10+j*4))
     return 1
   elif substring(rd(ARGS+i*4),0x7577f4):personal=True
   elif substring(rd(ARGS+i*4),0x7577ec):indexed=True
   else:
    handled=False
    for key,skip,kind in[(0x757824,7,'random'),(0x760be4,9,'wait'),(0x7581bc,8,'minimum'),(0x7581b4,8,'maximum'),(0x757994,10,'goal')]:
     at=substring(rd(ARGS+i*4),key)
     if not at:continue
     value=expression122(ACTOR,P,at+skip)
     if kind=='random':v=int(fl(value))&0xffffffff;randomCount=v if v<0x80000000 else v-0x100000000
     elif kind=='wait':wd(P+0x9c,value)
     elif kind=='minimum':minimum=fl(value)
     elif kind=='maximum':maximum=fl(value)
     else:wd(ACTOR+0x180,value)
     handled=True;break
    if not handled:
     for key,flag in[(0x760c24,1),(0x760bd4,2),(0x760c14,4),(0x760c08,8),(0x760bf0,16)]:
      if eq(rd(ARGS+i*4),key):shadow[P+0x68]=rb(P+0x68)|flag;handled=True;break
     if not handled:wd(ACTOR+0x180,expression122(ACTOR,P,rd(ARGS+i*4)))
   i+=1
  if fl(rd(P+0x9c))==0:wd(P+0x9c,bits(fl(bits(.01))if maximum<=minimum else w.store(w.add(w.mul(w.wide(draw148()),w.add(w.wide(maximum),w.wide(-minimum))),w.wide(minimum)))))
  chosen=rd(P+0x6c)
  if not chosen:return 1
  point=chosen+0x10;set124(ACTOR,point,0,chosen+0x20,7 if rb(P+0x68)&8 else 1,rd(ACTOR+0x180));wd(P+0x78,0);wd(P+0x7c,0);wd(P+0x80,bits(1.));rot=rotate(vec(P+0x78),rd(chosen+0x1c))
  for i,value in enumerate(rot):wd(P+0x78+i*4,bits(value))
  for i in range(3):wd(P+0x78+i*4,bits(add(fl(rd(P+0x78+i*4)),fl(rd(point+i*4)))))
  return 0
 chosen=rd(P+0x6c)
 if not chosen:return 1
 point=chosen+0x10;set124(ACTOR,point,0,chosen+0x20,7 if rb(P+0x68)&8 else 1,rd(ACTOR+0x180))
 if rb(P+0x68)&4 and rd(ACTOR+0xe4):wd(ACTOR+0x1e4,rd(ACTOR+0xe4)+0x5c)
 if rb(P+0x68)&1 and not rb(rd(ACTOR+0xd0)+0x281):return 0
 delta=[add(fl(rd(ACTOR+0x14c+i*4)),-fl(rd(point+i*4)))for i in range(3)]
 if rb(P+0x68)&2:delta[1]=0.
 distance=w.store(w.add(w.add(w.mul(w.wide(delta[0]),w.wide(delta[0])),w.mul(w.wide(delta[1]),w.wide(delta[1]))),w.mul(w.wide(delta[2]),w.wide(delta[2]))));reference=rd(ACTOR+0xd0);basis=add(fl(rd(ACTOR+0x180)),fl(rd(0x801c6c)));dt=fl(bits(c.get('delta',.1)));threshold=w.store(w.add(w.mul(w.wide(dt),w.wide(fl(rd(reference+0x22c)))),w.wide(basis)));square=w.mul(w.wide(threshold),w.wide(threshold));square=math.ldexp(float(square[0]),square[1])
 if distance>=square:
  if rd(ACTOR+0x1e8)&0x400000 and rb(P+0x68)&16 and rd(0x9238b8)and completion151(rd(0x9238b8),reference,point,True):return 1
  return 0
 if not rb(P+0x68)&4 or not rd(ACTOR+0xe4):wd(ACTOR+0x1e4,P+0x78)
 wait=fl(rd(P+0x9c))
 if wait<=0:return 1
 wait=add(wait,-dt);wd(P+0x9c,0 if wait<0 else bits(wait));return 0

def execute151(method,c):
 global config,shadow,segments,checks,events,ordinal
 config=c;n.write(D,bytes(0xe000));n.pack('<I',SYS+0x138c,TARGETREF);n.pack('<I',OWNREF+4,ACTOR);n.pack('<I',TARGETREF+4,TARGET);n.pack('<I',ACTOR+0xd0,OWNREF);n.pack('<I',ACTOR+0x144,FORM);n.write(ACTOR+0x149,bytes([1,c.get('actorRow',1)]));n.pack('<I',ACTOR+0x180,bits(c.get('goal',2.)));n.pack('<I',ACTOR+0x158,PATH);n.pack('<I',ACTOR+0x15c,NODEA);n.pack('<I',TARGET+0x158,PATH);n.pack('<I',TARGET+0x15c,NODEB);n.write(TARGET+0x166,b'\1');n.pack('<f',TARGET+0x120,5.);n.pack('<3f',TARGET+0x14c,10.,20.,30.);n.pack('<3f',TARGET+0x170,7.,8.,9.);n.write(NODEA+0x10,b'\0');n.write(NODEB+0x10,b'\1');n.write(P+0x68,bytes([c.get('packetFlags',0)]));n.pack('<I',0x9238b0,0);n.pack('<I',0x9238c0,0);n.pack('<I',0x9238c4,CB if c.get('callback')else 0);n.pack('<I',0x95e5d4,c.get('seed',123456789));n.write(0x92224c,bytes(0x18))
 for i,p in enumerate([OWNER,OWNER2,OWNER3]):n.pack('<I',p,1);n.pack('<I',p+4,ACTOR);n.pack('<f',p+0x60,5.+i);n.pack('<I',p+0x1fc,0x1001);n.write(p+0x28b,b'\0')
 n.pack('<I',ACTOR+0x84,PATH);n.pack('<I',ACTOR+0x88,OWNEREDGE);n.pack('<f',ACTOR+0x94,.25);n.write(ACTOR+0x13c,bytes([c.get('category',255)]));n.pack('<I',PATH+0x7c,NODES);n.pack('<I',PATH+0x84,ROUTES)
 for i,p in enumerate([EDGE,NEXTEDGE,OWNEREDGE]):n.pack('<2I',p,0,0);n.write(p+0x10,bytes([0 if i==0 else 1,1 if i==0 else 2]));n.pack('<h',p+0x12,0x4000 if i==1 else 0);n.pack('<H',p+0x14,1)
 for i,pos in enumerate([[0.,0.,0.],[10.,0.,0.],[10.,0.,10.]]):node=NODES+i*0x5c;n.pack('<3f',node+4,*pos);n.pack('<f',node+0x10,10.);n.pack('<f',node+0x14,1.);n.write(node+0x28,bytes([c.get('capacity',3)]));n.pack('<I',node+0x34,CONNECTIONS+i*0x100);n.pack('<H',node+0x5a,0);n.pack('<3I',CONNECTIONS+i*0x100,EDGE,NEXTEDGE,OWNEREDGE);n.pack('<I',ROUTES+i*4,ROUTEROWS+i*0x100);n.write(ROUTEROWS+i*0x100,bytes([c.get('routeValue',0)])*256)
 for form in[FORM,FORM2]:
  n.pack('<I',form,OWNER if c.get('owner',True)else OWNER2);n.pack('<h',form+4,c.get('cap',1024));n.write(form+6,bytes([3,3]));n.pack('<3I',form+0xc,OWNER,OWNER2,OWNER3);n.pack('<I',form+0x50,c.get('formFlags',8));n.pack('<f',form+0x124,c.get('width',2.));n.pack('<f',form+0x128,3. if form==FORM else 7.)
  for i in range(3):
   row=form+0x54+i*0x34;n.pack('<I',row,PATH);n.pack('<I',row+4,EDGE);n.write(row+8,bytes([c.get('orientation',0)]));n.pack('<f',row+0x10,.5);n.pack('<3f',row+0x18,*(c.get('position',[5.+i,0.,0.])));n.pack('<I',row+0x24,0);n.pack('<I',row+0x28,NEXTEDGE if c.get('existingNext')else 0);n.write(row+0x2d,bytes([c.get('active',[1,1,1])[i]]));n.pack('<I',row+0x30,c.get('rowFlags',0))
 n.write(PATH+0x10,b'\x03');n.pack('<I',P+0x6c,NODES+0x5c);n.pack('<6I',P+0x84,PATH,EDGE,0,0,bits(.5),0);n.pack('<I',ARGS,D+0xd820);n.write(D+0xd820,b'beta\0');n.pack('<3f',ACTOR+0x14c,*c.get('actorPosition',[1.,2.,3.]))
 for i,name in enumerate([b'alpha',b'beta',b'gamma']):n.pack('<I',NODES+i*0x5c,D+0xd800+i*0x20);n.write(D+0xd800+i*0x20,name+b'\0')
 n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else TARGETREF);n.pack('<I',TARGETREF+4,0 if c.get('nullTarget')else TARGET);n.pack('<I',0x9238b0,0x43c0c0 if c.get('movement',True)else 0)
 for i,t in enumerate(c.get('tokens',[])):n.pack('<I',ARGS+i*4,D+0xe000+i*0x100);n.write(D+0xe000+i*0x100,t.encode('latin1')+b'\0')
 n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else OWNREF);n.pack('<I',OWNREF,0 if c.get('nullControllerObject')else 1);n.pack('<I',ACTOR+0x158,0 if c.get('noPath')else PATH);n.pack('<I',ACTOR+0x15c,0 if c.get('noNode')else NODEA);n.pack('<I',ACTOR+0x188,0xabcdef01);n.pack('<f',P+0x9c,c.get('wait',.25));n.pack('<I',ACTOR+0x1e8,c.get('actorFlags',0xabcdef07))
 spawn=D+0x10000;n.write(spawn,bytes(0x300));n.pack('<I',SYS+0x18,spawn);n.write(ACTOR+0x138,bytes([c.get('selector',0)]));n.pack('<I',OWNREF+0x1f8,0 if c.get('noSpawnFlag')else 0x400);n.pack('<f',OWNREF+0x22c,c.get('speed',1.));n.pack('<I',0x923908,0x43c3a0 if c.get('originCallback',True)else 0);n.write(P+0x69,bytes([c.get('xz',0)]))
 for i in range(3):r=spawn+i*0xa4;n.pack('<3f',r+0x20,*c.get('originPosition',[10.,0.,10.]));n.pack('<I',r+0x2c,c.get('heading',0));n.pack('<6I',r+0x30,PATH,EDGE,0,0,bits(.5),0);n.pack('<f',r+0x5c,3.);n.pack('<f',r+0x60,4.)
 n.write(LOCATORS,bytes(0x800));names=['beta','beta_0','beta_1','beta_2','beta_3','beta_4','beta_5','beta_hero','beta_-128','beta_127','beta%','missing']
 for i,name in enumerate(names):r=LOCATORS+i*0x3c;n.write(r,name.encode()+b'\0');n.pack('<3f',r+0x10,*c.get('locatorPosition',[10.,0.,10.]));n.pack('<I',r+0x1c,c.get('heading',0));n.pack('<6I',r+0x20,PATH,EDGE,0,0,bits(.5),0)
 n.pack('<I',SYS+0x24,len(names));n.pack('<I',SYS+0x28,LOCATORS);n.pack('<I',P+0x6c,0 if c.get('noSelected')else LOCATORS);n.pack('<I',P+0xa4,0 if c.get('noSelected')else LOCATORS);n.pack('<I',OWNREF+0x54,0 if c.get('noCharacter')else CHARACTER);n.pack('<I',CHARACTER+0xc,CHARACTER+0x40);n.write(CHARACTER+0x40,b'hero\0');n.write(OWNREF+0x280,bytes([c.get('personalIndex',1)&255,c.get('ground',1)&255]));n.pack('<I',0x8066c0,c.get('integerSeed',1));n.pack('<I',0x9238b8,DONE if c.get('completeCallback')else 0);n.write(P+0x68,bytes([c.get('packetFlags',0)]))
 raw=[(LOCATORS,0x800),(CHARACTER,0x100),(0x8066c0,4),(0x9238b8,4),(0x7577cc,0x68),(0x75850c,16),(0x760bf0,0x48),(spawn,0x300),(0x923908,4),(0x801c6c,4),(0x760bd4,32),(0x757994,16),(0x7581b4,16),(0x758208,32),(0x755d34,24),(D+0xe000,0x1000),(D+0xd800,0x100),(P,0x200),(FORM,0x200),(FORM2,0x200),(OWNER,0x300),(OWNER2,0x300),(OWNER3,0x300),(TARGETREF,0x100),(ACTOR,0x300),(TARGET,0x300),(PATH,0x100),(EDGE,0x300),(NODES,0x200),(ROUTES,0x400),(ROUTEROWS,0x300),(CONNECTIONS,0x300),(NODEA,0x200),(SYS,0x1400),(ARGS,0x100),(RESULT,4),(0x9238b0,4),(0x9238c0,4),(0x9238c4,4),(0x92224c,0x18),(0x95e5d4,4)]
 merged=[]
 for p,z in sorted(raw):
  if merged and p<=merged[-1][0]+merged[-1][1]:merged[-1][1]=max(merged[-1][1],p+z-merged[-1][0])
  else:merged.append([p,z])
 segments=[tuple(x)for x in merged];initial=snap();shadow=dict(fixed);shadow.update({r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))});callback=0x51c6a0 if c.get('random')else 0x51cbc0;mode=4 if c.get('random')else 1;events=[];ordinal=0;mfault=False;want=0
 try:
  want=go151(c)
 except(KeyError,ZeroDivisionError):mfault=True
 wd(RESULT,want if not mfault else 0);model=snap(True);me=events.copy();events=[];ordinal=0;nfault=False;got=0
 try:
  got=n.call(0x536700,[0 if c.get('nullSystem')else SYS,P,0 if c.get('nullActor')else ACTOR,ARGS,c.get('count',len(c.get('tokens',[])))&0xffffffff,c.get('first',1),bits(c.get('delta',.1))],count=4000000)
 except RuntimeError:nfault=True
 n.pack('<I',RESULT,got if not nfault else 0);native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(formation=FORM,callback=callback,system=0 if c.get('nullSystem')else SYS,packet=P,actor=0 if c.get('nullActor')else ACTOR,args=ARGS,point=TARGET+0x14c,words=TARGET+0x158,mode=mode,result=RESULT,first=c.get('first',1),count=c.get('count',len(c.get('tokens',[]))),address=0x536700,delta=bits(c.get('delta',.1))),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
for first,flags,tokens in itertools.product([0,1],[0,8,12],[[],['RUN','WALK','TIPTOE'],['name','beta'],['name','missing'],['indexed','name','beta'],['personal','name','beta'],['random=6','name','beta'],['teleport','beta'],['on_ground'],['xz_rangecheck'],['face_opponent'],['ignore_path'],['must_reach_destination'],['waittime=.1'],['mintime=1','maxtime=3'],['goalrange=5']]):execute151('Locator',dict(first=first,formFlags=flags,tokens=tokens))
for c in[dict(nullActor=True),dict(noController=True),dict(nullControllerObject=True),dict(noPath=True),dict(noNode=True),dict(nullSystem=True,tokens=['name','beta']),dict(count=-1),dict(tokens=['name']),dict(tokens=['teleport']),dict(noSelected=True),dict(noSelected=True,first=0),dict(tokens=['indexed','personal','name','beta'],personalIndex=-1),dict(tokens=['indexed','name','beta'],personalIndex=-128),dict(tokens=['random=-3','name','beta']),dict(tokens=['name','beta%%']),dict(first=0,packetFlags=1,ground=0),dict(first=0,packetFlags=2,actorPosition=[10.,99.,10.],wait=0.),dict(first=0,packetFlags=4,actorPosition=[10.,0.,10.],wait=0.),dict(first=0,packetFlags=16,actorFlags=0x400000,completeCallback=True,completeResult=1),dict(first=0,packetFlags=16,actorFlags=0x400000,completeCallback=True,completeResult=0),dict(callback=True,routeValue=255,patches={'1':[[ACTOR+0x144,4,FORM2]]}),dict(first=0,actorPosition=[10.,0.,10.],wait=.1,delta=.1),dict(first=0,actorPosition=[10.,0.,10.],wait=.1,delta=.2)]:execute151('Locator',c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,refinements=['536700'],ports=['CRT sprintf6E69EF qualifiedname formatter','optional9238B8 special-completion callback','optional9238C4 movement-step callback'],closure='actual536700→real lookup/expression/integer+fractionRNG/intent/formation/math/cookie-normal-return; sprintf explicit',sharedTableSha256=nm.hashlib.sha256(table).hexdigest(),sharedTableUnchanged=n.read(TABLE,len(table))==table)
(nm.BASE/'reports/script-phase151-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase151-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,shared=shared,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
