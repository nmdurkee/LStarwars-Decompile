"""Full51d7b0 caller, finite static graph fixtures; two explicit world services."""
import importlib.util,struct,json,random,itertools,copy,math,gzip
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');rt=load('route','gameplay-path-routing-verify.py');bd=load('bind','gameplay-path-binding-verify.py');tg=load('target','gameplay-path-targeting-verify.py');co=load('corner','gameplay-path-corners-verify.py');cr=co.corr;an=co.ang;W=co.W;n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=D+0x90000;P=A+0x2c8;REF=D+0x92000;QUERY=D+0x94000;PATH=D;NODES=rt.NODES;EDGES=rt.CNX;CTX=0x12345678;CALLBACK=n.STOP+0x100
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
rt.n=n;bd.CON=EDGES;tg.PATH=PATH;tg.EDGES=EDGES
events=[];options={};executed=set();seenHelpers={}
def ret(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);mu.reg_write(UC_X86_REG_EAX,value&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==CALLBACK:
  events.append(['special',*n.unpack('<III',sp+4)])
  if 'callbackFlags' in options:n.pack('<I',P+0x1e8,options['callbackFlags'])
  ret(mu,options.get('callbackReturn',0))
 elif address==0x51d5e0:events.append(['transition',*n.unpack('<II',sp+4)]);ret(mu,0)
for a in [CALLBACK,0x51d5e0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=0x51d7b0,end=0x51e8b2)
for a in [0x51d750,0x51b1f0,0x51a890,0x51b890,0x51b7f0,0x51be90,0x51c430,0x51c150]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:seenHelpers.__setitem__(hex(p),seenHelpers.get(hex(p),0)+1),begin=a,end=a)
def eid(i):return EDGES+i*0x24 if i>=0 else 0
def eptr(identity):return (identity-EDGES)//0x24 if identity else -1
def pos(node):return [r.fl(r.u(node,4+j*4)) for j in range(3)]
def floats(b,at):return [r.fl(r.u(b,at+j*4)) for j in range(3)]
def storevec(b,at,v):
 for j,value in enumerate(v):r.put(b,at+j*4,r.bits(value))
def setup(o):
 global options,events
 options=o;events=[]
 q=dict(nodes=[dict(adj=[0],member=3,boundary=0),dict(adj=[0,1],member=3,boundary=0),dict(adj=[1,2],member=3,boundary=0),dict(adj=[2],member=3,boundary=0)],edges=[dict(a=0,b=1,mask=3,distance=10.),dict(a=1,b=2,mask=3,distance=10.),dict(a=2,b=3,mask=3,distance=10.)],base=[[255,0,0,0],[0,255,1,1],[0,0,255,1],[0,0,0,255]],groups=[])
 for j in range(2):q['groups'].append(dict(count=4,map=[0,1,2,3],exits=[],matrix=copy.deepcopy(q['base'])))
 if 'base' in o:q['base']=o['base']
 for i,p in enumerate(q['nodes']):p['member']=o.get('members',[3]*4)[i];p['boundary']=o.get('boundaries',[0]*4)[i]
 for i,e in enumerate(q['edges']):
  e['mask']=o.get('masks',[3]*3)[i];e['distance']=r.f(o.get('distances',[10]*3)[i])
  if o.get('reversed',[False]*3)[i]:e['a'],e['b']=e['b'],e['a']
 rt.resetcache(q,{});rt.materialize(q);rt.loadcache(q);n.write(A,bytes(0x5000));n.write(0x29899a0,r.SINE_BYTES);n.pack('<I',0x9238fc,CALLBACK if o.get('callback') else 0);n.pack('<B',PATH+0x78,7);positions=[[r.f(x) for x in p] for p in o.get('positions',[[0,0,0],[0,0,10],[10,0,10],[10,0,20],[100,0,100]])];nodes=[]
 for i,p in enumerate(positions):
  node=bytearray(n.read(NODES+i*0x5c,0x5c));storevec(node,4,p);r.put(node,0x10,r.bits(r.f(o.get('radii',[2]*5)[i])));height=o.get('heights',[[x[1]-2,x[1]+2] for x in positions])[i];r.put(node,0x18,r.bits(r.f(height[0])));r.put(node,0x20,r.bits(r.f(height[1])));r.put(node,0x2a,o.get('dynamic',[0]*5)[i],1);nodes.append(node);n.write(NODES+i*0x5c,node)
 edges=[]
 for i in range(3):
  edge=bytearray(n.read(eid(i),0x24));r.put(edge,0,o.get('requirements',[[0,0]]*3)[i][0]);r.put(edge,4,o.get('requirements',[[0,0]]*3)[i][1]);r.put(edge,0x12,o.get('angles',[0,16384,0])[i]+(32768 if o.get('reversed',[False]*3)[i] else 0),2);r.put(edge,0x1c,r.bits(r.f(o.get('lengths',[10]*3)[i])));edge[0x17]=3;edges.append(edge);n.write(eid(i),edge)
 actor=r.pattern(0x10d8,1);reference=r.pattern(0x10d8,1);position=[r.f(v) for v in o.get('position',[0,0,2])];target=[r.f(v) for v in o.get('target',[10,0,18])];query=[r.f(v) for v in o.get('query',position)];storevec(reference,0x5c,position);r.put(reference,0x27e,o.get('attachmentSlot',65535),2);r.put(reference,0xac,r.bits(r.f(o.get('bodyRadius',.5))));r.put(actor,0x2c8+0xd0,REF);r.put(actor,0x2c8+0x158,PATH);r.put(actor,0x2c8+0x15c,eid(o.get('current',0)));r.put(actor,0x2c8+0x1cc,0 if o.get('newTarget') else PATH);r.put(actor,0x2c8+0x1d0,eid(o.get('targetEdge',2)));r.put(actor,0x2c8+0x190,0);r.put(actor,0x2c8+0x194,0);r.put(actor,0x2c8+0x17c,0)
 for off,value,size in [(0x160,o.get('direction',0),1),(0x166,o.get('stateFlags',5),2),(0x13c,o.get('route',255),1),(0x13d,o.get('cursor',0),1),(0x13a,o.get('membership',3),2),(0x142,0,1),(0x143,255,1),(0x1f4,o.get('permission',0xffffffff),4),(0x1e8,o.get('flags',0),4),(0x1ec,o.get('targetFlags',0),4)]:r.put(actor,0x2c8+off,value,size)
 for off,value in [(0x168,o.get('progress',.2)),(0x1dc,o.get('targetProgress',.8)),(0x1c0,o.get('acceptedRadius',0)),(0x1c4,o.get('targetRadius',0))]:r.put(actor,0x2c8+off,r.bits(r.f(value)))
 storevec(actor,0x2c8+0x1b4,target);storevec(actor,0x2c8+0x14c,query);n.write(A,actor);n.write(REF,reference);n.pack('<3f',QUERY,*query)
 n.pack('<B',PATH+0x10,o.get('pointCount',4));n.write(PATH+0x18,bytes([255]*32));g=dict(count=o.get('pointCount',4),candidateCount=0,points=[dict(position=positions[i],radius=r.fl(r.u(nodes[i],0x10)),edges=q['nodes'][i]['adj'] if i<4 else []) for i in range(5)],edges=[[e['a'],e['b']] for e in q['edges']]);return dict(actor=actor,reference=reference,nodes=nodes,edges=edges,q=q,g=g)
def model(before,o,transition=None,special=None):
 z=copy.deepcopy(before);a=z['actor'];ref=z['reference'];nodes=z['nodes'];edges=z['edges'];q=z['q'];ev=[];pa=0x2c8
 get=lambda off:r.u(a,pa+off);f=lambda off:r.fl(get(off));setv=lambda off,v:r.put(a,pa+off,v);setf=lambda off,v:setv(off,r.bits(v));byte=lambda off:a[pa+off]
 def flag(mask):setv(0x1e8,get(0x1e8)|mask)
 def out(v,radius=0):storevec(a,pa+0x104,v);setf(0x110,radius)
 def contains(edge,query,previous,margin,stamp=0):
  state=dict(nodes=nodes,edge=edges[edge],seen=bytearray([255]*32),query=query,hit=bytearray(32),marker=7);state,inside,_=cr.model(state,dict(route=byte(0x13c),margin=margin,stampMode=stamp,previous=list(edges[previous][0x10:0x12]),noHit=True));edges[edge][:]=state['edge'];return bool(inside)
 def bind(edge,direction):bd.bind(a,dict(edges=edges,points=[pos(p) for p in nodes],count=2),eid(edge),direction,*[floats(ref,0x5c)[i] for i in [0,2]])
 def nextedge(direction):
  current=eptr(get(0x15c));dest=get(0x17c);dest=(dest-NODES)//0x5c if dest else None
  if current<0:return -1,direction
  return rt.next_edge(q,edges[current][0x11 if byte(0x160)==0 else 0x10],dest,byte(0x13c),direction,[])
 def ensure():
  image,status=tg.model(z['g'],{},a,floats(a,pa+0x1b4),'ensure');a[:]=image;return status
 saved={off:get(off) for off in [0x1b4,0x1b8,0x1bc,0x1c0,0x1c4,0x1cc,0x1d0,0x1d4,0x1d8,0x1dc,0x1e0]};status=ensure()
 if status<0:out(floats(ref,0x5c));return z,ev
 old=eptr(get(0x15c));target=eptr(get(0x1d0));delta=[(W(x)-W(y)).store() for x,y in zip(floats(a,pa+0x1b4),floats(ref,0x5c))];distance=tg.distance(floats(a,pa+0x1b4),floats(ref,0x5c));radius=f(0x1c4)
 attached=struct.unpack_from('<h',ref,0x27e)[0]!=-1;dynamic=old>=0 and all(nodes[ix][0x2a]!=0 for ix in edges[old][0x10:0x12]);arrival=(not attached or dynamic) and radius!=0 and -.5<delta[1]<.5 and (W(radius)*W(radius)-W(distance)).exact[0]>0
 if arrival and status==0:out(floats(ref,0x5c));return z,ev
 if arrival and status!=0 and byte(0x1ec)&4:
  for off,value in saved.items():setv(off,value)
  ev.append(['transition',CTX,P])
  if transition is not None:transition(z,o)
  ensure();old=eptr(get(0x15c));target=eptr(get(0x1d0))
 if old<0 or target<0:out(floats(ref,0x5c));return z,ev
 lastold=old;direction=0
 if get(0x15c)!=get(0x1d0):
  if contains(target,floats(a,pa+0x14c),eptr(get(0x15c)),r.fl(r.u(ref,0xac))):direction=int(edges[target][0x10] not in edges[eptr(get(0x15c))][0x10:0x12]);bind(target,direction)
  if get(0x15c)!=get(0x1d0):
   direction=byte(0x160);best=rt.MAX;progress=max(0.,min(1.,f(0x168)));costs=[abs((W(r.fl(r.u(edges[old],0x18)))*W(progress)).store()),abs((W(r.fl(r.u(edges[old],0x18)))*(W(1)-W(progress))).store())];aCost=(W(f(0x1dc))*W(r.fl(r.u(edges[target],0x18)))).store();bCost=((W(1)-W(f(0x1dc)))*W(r.fl(r.u(edges[target],0x18)))).store();destination=edges[target][0x10];visited=0
   if byte(0x13c)!=255:flag(0x100000)
   for retry in range(256):
    aCost=abs(aCost);bCost=abs(bCost);route=byte(0x13c);mask=(1<<route) if route<16 else 0
    if route!=255 and not r.h(edges[target],0x14)&mask:
     for end in [0,1]:
      node=nodes[edges[target][0x10+end]]
      if (~r.h(node,0x5a))&r.h(node,0x58)&mask:
       if end==0:aCost=rt.MAX
       else:bCost=rt.MAX
    for proposed,departure,blockedIndex in [(byte(0x160),int(byte(0x160)==0),byte(0x160)),(int(byte(0x160)==0),byte(0x160),int(byte(0x160)==0))]:
     if r.u(edges[old],blockedIndex*4)&0x40000000:continue
     for end,cost in [(0,aCost),(1,bCost)]:
      candidate=rt.MAX
      if cost!=rt.MAX and costs[departure]!=rt.MAX:
       d=rt.distance(q,edges[old][0x10+departure],edges[target][0x10+end],route,0,[])
       if d!=rt.MAX:candidate=(W(costs[departure])+W(cost)+W(d)).store()
      if candidate<best:best=candidate;direction=proposed;destination=edges[target][0x10+end];setv(0x1e8,get(0x1e8)&~0x100000)
    if not get(0x1e8)&0x100000:break
    if route!=255:visited|=1<<(route&31)
    bd.select(a,dict(count=2,edges=edges))
    if visited&(1<<(byte(0x13c)&31)):return z,ev
    aCost=(W(f(0x1dc))*W(r.fl(r.u(edges[target],0x18)))).store();bCost=((W(1)-W(f(0x1dc)))*W(r.fl(r.u(edges[target],0x18)))).store()
   else:raise RuntimeError('model route retry')
   setv(0x17c,NODES+destination*0x5c);bind(old,direction);previous=-1;next,direction=nextedge(direction)
   if next<0:
    required=(r.u(edges[target],0)|r.u(edges[target],4))&0xdfffffff
    if not required&0xd8000000 and (not required or get(0x1f4)&required) and contains(target,floats(a,pa+0x14c),eptr(get(0x15c)),r.fl(r.u(ref,0xac))):bind(target,0)
   else:
    for _ in range(32):
     if next==previous or not contains(next,floats(a,pa+0x14c),eptr(get(0x15c)),r.fl(r.u(ref,0xac))) or old==target:break
     previous=next;bind(next,direction);old=next
     if eptr(get(0x15c))!=next or byte(0x160)!=direction:break
     next,direction=nextedge(direction)
     if next<0:break
    else:raise RuntimeError('model traversal loop')
 if o.get('callback'):
  if old!=target:flag(0x20000000)
  ev.append(['special',P,REF,QUERY])
  if special is not None:callbackResult=special(z,o,ev)
  else:
   if 'callbackFlags' in o:setv(0x1e8,o['callbackFlags'])
   callbackResult=o.get('callbackReturn',0)
  if callbackResult:flag(0x40080000);return z,ev
 current=eptr(get(0x15c));direction=byte(0x160);required=r.u(edges[current],direction*4)
 if required&0xd8000000:out(pos(nodes[edges[current][0x10+direction]]));flag(0x400000);setv(0x1f8,required);return z,ev
 lastold=current
 if current==target and (byte(0x13c)==255 or r.h(edges[target],0x14)&((1<<byte(0x13c)) if byte(0x13c)<16 else 0)):
  if not byte(0x166)&1 or f(0x1c4)==0:out(floats(a,pa+0x1b4),f(0x1c0));return z,ev
  if (W(f(0x1c4))*W(f(0x1c4))-W(distance)).exact[0]>0:
   if status==0:out(floats(ref,0x5c));return z,ev
   if byte(0x1ec)&4:
    for off,value in saved.items():setv(off,value)
    ev.append(['transition',CTX,P])
    if transition is not None:transition(z,o)
    ensure()
  length=r.f(math.sqrt(distance));scale=(W(f(0x1c4))/W(length)).store();scaled=[(W(v)*W(scale)).store() for v in delta];point=floats(a,pa+0x1b4);point[0]=(W(point[0])-W(scaled[0])).store();point[2]=(W(point[2])-W(scaled[2])).store();out(point,f(0x1c0) if f(0x1c4)<=f(0x1c0) else 0);return z,ev
 common=None;direction=0
 for i,j in [(0,0),(0,1),(1,0),(1,1)]:
  if edges[current][0x10+i]==edges[target][0x10+j]:common=edges[current][0x10+i];direction=j;break
 next=target
 if common is None or (byte(0x13c)!=255 and not (r.h(edges[target],0x14)|r.h(nodes[common],0x5a))&((1<<byte(0x13c)) if byte(0x13c)<16 else 0)):next,direction=nextedge(direction)
 def fallback():
  p=pos(nodes[edges[eptr(get(0x15c))][0x10+int(byte(0x160)==0)]]);out(floats(ref,0x5c) if tg.distance(p,floats(ref,0x5c))<1 else p);flag(0x400000)
 if next<0:fallback();return z,ev
 required=r.u(edges[next],direction*4)
 if required&0xdfffffff:
  if required&0xd8000000:out(floats(ref,0x5c));flag(0x400000);setv(0x1f8,required);return z,ev
  if not get(0x1f4)&required:flag(0x600000);setv(0x1f8,required);fallback();return z,ev
  setv(0x1ec,get(0x1ec)|1)
 point=floats(a,pa+0x1b4) if next==target else pos(nodes[edges[next][0x10+direction]])
 if next!=target:flag(0x80000)
 if contains(lastold,point,eptr(get(0x15c)),r.fl(r.u(ref,0xac))):out(point);return z,ev
 #The real51c430 uses param3's radius but packet storage belongs to owner.
 if get(0x190)==eid(lastold) and get(0x194)==eid(next):valid=bool(get(0x1e8)&0x60)
 else:
  setv(0x190,eid(lastold));setv(0x194,eid(next));setv(0x1e8,get(0x1e8)&~0x60);edgeA,edgeB=edges[lastold],edges[next];aa=struct.unpack_from('<h',edgeA,0x12)[0];ab=struct.unpack_from('<h',edgeB,0x12)[0];a0,a1=edgeA[0x10:0x12];b0,b1=edgeB[0x10:0x12];shared=None
  if a0==b0:shared,outerA,outerB,aa,ab=a0,a1,b1,co.wrap(aa+32768),co.wrap(ab+32768)
  elif a0==b1:shared,outerA,outerB,aa=a0,a1,b0,co.wrap(aa+32768)
  elif a1==b0:shared,outerA,outerB,ab=a1,a0,b1,co.wrap(ab+32768)
  elif a1==b1:shared,outerA,outerB=a1,a0,b0
  if shared is not None and not contains(lastold,pos(nodes[outerB]),lastold,0,1):
   for edgeA,edgeB,first,second,headA,headB,offset,mask in [(edgeA,edgeB,outerA,outerB,aa,ab,0x198,0x20),(edgeB,edgeA,outerB,outerA,ab,aa,0x1a4,0x40)]:
    valid,value=co.construct(nodes,edgeA,edgeB,shared,first,second,headA,headB,r.fl(r.u(ref,0xac)),bytes(a[pa+offset:pa+offset+12]));a[pa+offset:pa+offset+12]=value
    if valid:flag(mask)
  valid=bool(get(0x1e8)&0x60)
 if not valid:point=pos(nodes[edges[next][0x10+direction]])
 else:
  for offset,mask,negative in [(0x1a4,0x40,True),(0x198,0x20,False)]:
   if not get(0x1e8)&mask:continue
   corner=floats(a,pa+offset);d1=[(W(x)-W(y)).store() for x,y in zip(corner,floats(ref,0x5c))];d2=[(W(x)-W(y)).store() for x,y in zip(point,floats(ref,0x5c))];difference=co.wrap(an.direction(d2[0],d2[2])-an.direction(d1[0],d1[2]))
   if (difference<0 if negative else difference>0):point=corner;flag(0x80000);break
 out(point);return z,ev
cases=[];errors=[]
def snapshot(z):return dict(actor=n.read(A,len(z['actor'])),reference=n.read(REF,len(z['reference'])),nodes=[n.read(NODES+i*0x5c,0x5c) for i in range(5)],edges=[n.read(eid(i),0x24) for i in range(3)])
def summary(before,after,ev):return dict(actor=r.changes(before['actor'],after['actor']),reference=r.changes(before['reference'],after['reference']),nodes=[r.changes(a,b) for a,b in zip(before['nodes'],after['nodes'])],edges=[r.changes(a,b) for a,b in zip(before['edges'],after['edges'])],events=ev)
def run(o):
 before=setup(o);expected,ev=model(before,o)
 for i,p in enumerate(expected['q']['nodes']):
  c=p['cache'];r.put(expected['nodes'][i],0x2e,c[0],1);r.put(expected['nodes'][i],0x2f,c[1],1);r.put(expected['nodes'][i],0x38,r.bits(c[2]));r.put(expected['nodes'][i],0x3c,r.bits(c[3]))
 n.call(0x51d7b0,[CTX,P,REF,QUERY],count=500000);got=summary(before,snapshot(before),events);want=summary(before,expected,ev);cases.append(dict(options=o,native=got))
 if got!=want:errors.append(dict(options=o,got=got,want=want))
def main():
 for current,target,position in itertools.product(range(3),range(3),[[0,0,2],[0,0,10],[5,0,10],[10,0,15],[20,0,20]]):run(dict(current=current,targetEdge=target,position=position))
 for reverse,current,target in itertools.product(itertools.product([False,True],repeat=3),range(3),range(3)):run(dict(reversed=list(reverse),current=current,targetEdge=target))
 for req,edge,direction in itertools.product([1,0x20000000,0x8000000,0x80000000],[1,2],[0,1]):
  requirements=[[0,0] for _ in range(3)];requirements[edge][direction]=req;run(dict(requirements=requirements,permission=0));run(dict(requirements=requirements))
 run(dict(base=[[255]*4]*4,position=[0,0,9.5]));run(dict(positions=[[0,0,i*10] for i in range(5)],angles=[0,0,0],target=[0,0,25],targetEdge=1))
 for boundaries in [[0,0,1,0],[0,1,1,0]]:run(dict(current=0,targetEdge=1,route=0,masks=[1,2,1],boundaries=boundaries))
 for masks,bound in itertools.product([[1,2,2],[1,2,1],[2,1,1]],[[0]*4,[3]*4]):run(dict(route=0,masks=masks,boundaries=bound))
 for count,current,slot,dynamic in itertools.product([0,4],[-1,0],[0,65535],[[0]*5,[1]*5,[1,0,1,0,0]]):
  if count and current<0 and slot!=65535:continue #Original dereferences null edge before later null guard.
  run(dict(pointCount=count,current=current,attachmentSlot=slot,dynamic=dynamic,newTarget=True))
 for radius in [.1,.3,.7,1.1,1.3,2.3,3.3]:run(dict(current=0,targetEdge=0,position=[0,0,0],target=[r.f(radius),0,0],targetRadius=r.f(radius)))
 for target,new,stateFlags,radius,position,flags in itertools.product([0,2],[False,True],[0,1,4,5],[0,1,3],[[10,0,18],[10,0,17.5],[10,.5,18],[0,0,2]],[0,4]):run(dict(targetEdge=target,newTarget=new,stateFlags=stateFlags,targetRadius=radius,position=position,targetFlags=flags))
 for callback,ret,flags,current,target in itertools.product([False,True],[0,1,0xffffffff],[0,0x1234,0x20000000],range(3),range(3)):run(dict(callback=callback,callbackReturn=ret,callbackFlags=flags,current=current,targetEdge=target))
 for requirement,current,target,permission,direction in itertools.product([1,0x20000000,0x40000000,0x8000000,0x10000000,0x80000000],range(3),range(3),[0,0xffffffff],[0,1]):run(dict(requirements=[[requirement,requirement]]*3,current=current,targetEdge=target,permission=permission,direction=direction))
 for route,masks,members,boundaries in itertools.product([0,1,255],[[0]*3,[1]*3,[2]*3,[3]*3],[[3]*4,[1,1,2,2]],[[0]*4,[3]*4]):run(dict(route=route,masks=masks,members=members,boundaries=boundaries))
 rng=random.Random(0x51d7b0)
 for i in range(512):run(dict(current=rng.randrange(3),targetEdge=rng.randrange(3),position=[r.f(rng.uniform(-2,12)),r.f(rng.uniform(-1,1)),r.f(rng.uniform(-2,22))],target=[r.f(rng.uniform(-2,12)),r.f(rng.uniform(-1,1)),r.f(rng.uniform(-2,22))],progress=r.f(rng.uniform(-1,2)),targetProgress=r.f(rng.uniform(-1,2)),targetRadius=r.f(rng.uniform(0,3)),acceptedRadius=r.f(rng.uniform(0,3)),direction=rng.randrange(2),route=rng.choice([0,1,255]),newTarget=bool(rng.randrange(2)),targetFlags=rng.choice([0,4])))
 authored=0
 for file in sorted((BASE/'reports/gameplay-navigation/data').rglob('*.json.gz')):
  doc=json.loads(gzip.decompress(file.read_bytes()))
  for path in doc['paths']:
   chain=None
   for e0 in path['connections']:
    p0,p1=e0['to'],e0['from']
    if p0==p1:continue
    for i1 in path['points'][p1]['connectionIndices']:
     e1=path['connections'][i1];p2=e1['from'] if e1['to']==p1 else e1['to']
     if p2 in [p0,p1]:continue
     for i2 in path['points'][p2]['connectionIndices']:
      e2=path['connections'][i2];p3=e2['from'] if e2['to']==p2 else e2['to']
      if p3 in [p0,p1,p2]:continue
      points=[path['points'][i] for i in [p0,p1,p2,p3]];edges=[e0,e1,e2];radii=[p['xzSize'] for p in points];lengths=[e['distanceCandidates'][1] for e in edges]
      if not all(math.isfinite(v) and v>0 for v in lengths) or any(abs(radii[i+1]-radii[i])>lengths[i] for i in range(3)):continue
      chain=(points,edges,[p0,p1,p2,p3],radii,lengths);break
     if chain:break
    if chain:break
   if chain:
    points,edges,indices,radii,lengths=chain;positions=[p['position'] for p in points];reversedEdges=[e['to']!=indices[i] for i,e in enumerate(edges)];base=dict(positions=positions+[positions[-1]],radii=radii+[radii[-1]],heights=[[p['semantics']['minWorldY'],p['semantics']['maxWorldY']] for p in points]+[[points[-1]['semantics']['minWorldY'],points[-1]['semantics']['maxWorldY']]],lengths=lengths,distances=[e['distanceCandidates'][0] for e in edges],angles=[e['unknownShorts'][0]-(32768 if reversedEdges[i] else 0) for i,e in enumerate(edges)],masks=[e['unknownShorts'][1] for e in edges],reversed=reversedEdges,requirements=[[e['toFlags'],e['fromFlags']] for e in edges],position=[r.f((a+b)*.5) for a,b in zip(positions[0],positions[1])],target=positions[-1],authored=dict(file=doc['source'],sha256=doc['sha256'],path=path['index'],nodes=indices,connectionOffsets=[e['offset'] for e in edges],qualification='Original point/edge geometry and flags, synthetic four-node route tables and caller state.'))
    for direction in [0,1]:run(dict(base,direction=direction))
    authored+=1
   if authored>=32:break
  if authored>=32:break
 assembly=json.loads((BASE/'reports/gameplay-path-steering-assembly.json').read_text());missing=[]
 for row in assembly['instructions']:
  row['executed']=int(row['address'],16) in executed
  if not row['executed']:missing.append(row['address'])
 (BASE/'reports/gameplay-path-steering-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');report=dict(binarySha256=n.sha256,checks=len(cases),mismatches=len(errors),examples=errors[:5],authoredGeometryChains=authored,authoredGeometryCases=authored*2,helperCalls=seenHelpers,instructionCoverage=dict(total=len(assembly['instructions']),executed=len(executed),missing=missing));(BASE/'reports/gameplay-path-steering-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-steering-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
