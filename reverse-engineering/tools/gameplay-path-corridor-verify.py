"""Bounded original corridor51b1f0; attached-point refresh is mutable service."""
import importlib.util,json,struct,copy,itertools,random,gzip,math
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');arc=load('arc','gameplay-path-arcsine-verify.py');w=r.wide;n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;PATH=D;NODES=D+0x1000;EDGE=D+0x3000;PREV=EDGE+0x24;QUERY=D+0x4000;HIT=D+0x5000;CTX=0x12345678
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
options={};events=[];cases=[];errors=[];executed=set()
W=w.wide;A=w.add;M=w.mul;V=w.div;S=w.store
def neg(a):return (-a[0],a[1])
def sub(a,b):return A(a,neg(b))
def cmp(a,b):return sub(a,b)[0]
def b(v):return r.bits(v)
def f(v):return r.f(v)
def sf(a,b):return r.fl((r.bits(a)&~r.bits(b))&0x80000000) if a==0 and b==0 else S(sub(W(a),W(b)))
def rotation(x,z,angle):
 sin=r.SINE[(angle>>1)&32767];cos=r.SINE[((angle+16384)>>1)&32767];return r.products(z,sin,x,cos),r.products(z,cos,-x,sin)
def distance(query,p,stored):
 dx=sf(query[0],p[0]);dz=sf(query[2],p[2]);value=A(M(W(dx),W(dx)),M(W(dz),W(dz)));return W(S(value)) if stored else value
def effect(z,index,o):
 for e in o.get('effects',[]):
  if e.get('trigger',0)!=index:continue
  if e['target']=='node':r.put(z['nodes'][e['index']],e['offset'],e['value'],e.get('size',4))
  elif e['target']=='edge':r.put(z['edge'],e['offset'],e['value'],e.get('size',4))
  elif e['target']=='seen':z['seen'][e['index']]=e['value']
def hook(mu,addr,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);context,path,point=n.unpack('<III',sp+4);index=(point-NODES)//0x5c;events.append(['refresh',context,index]);z=dict(nodes=[bytearray(n.read(NODES+i*0x5c,0x5c)) for i in range(4)],edge=bytearray(n.read(EDGE,0x24)),seen=bytearray(n.read(PATH+0x18,32)));effect(z,index,options)
 for i,p in enumerate(z['nodes']):n.write(NODES+i*0x5c,p)
 n.write(EDGE,z['edge']);n.write(PATH+0x18,z['seen']);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_EAX,0)
n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x51af40,end=0x51af40);n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=0x51b1f0,end=0x51b7eb)
def setup(o):
 global options,events
 options=o;events=[];n.write(D,bytes(0x6000));n.write(0x29899a0,r.SINE_BYTES);n.pack('<I',PATH+0x7c,NODES);n.pack('<B',PATH+0x78,o.get('pathMarker',7));seen=bytearray(o.get('seen',[0]*32));n.write(PATH+0x18,seen)
 nodes=[]
 for i in range(4):
  p=bytearray(0x5c);position=o.get('positions',[[0,0,0],[0,0,10],[5,0,0],[5,0,10]])[i];radius=o.get('radii',[2,2,2,2])[i];height=o.get('heights',[[-1,1]]*4)[i]
  for j,v in enumerate(position):r.put(p,4+j*4,b(f(v)))
  for at,value in [(0x10,radius),(0x18,height[0]),(0x20,height[1])]:r.put(p,at,b(f(value)))
  p[0x2a]=o.get('dynamic',[0]*4)[i];r.put(p,0x5a,o.get('boundaries',[0]*4)[i],2);nodes.append(p);n.write(NODES+i*0x5c,p)
 edge=bytearray(0x24);edge[0x10:0x12]=bytes(o.get('endpoints',[0,1]));r.put(edge,0x12,o.get('angle',0),2);r.put(edge,0x14,o.get('mask',1),2);edge[0x17]=o.get('edgeMarker',3);r.put(edge,0x1c,b(f(o.get('length',10))));n.write(EDGE,edge);n.pack('<BB',PREV+0x10,*o.get('previous',[0,2]));query=[f(v) for v in o.get('query',[0,0,5])];n.pack('<3f',QUERY,*query)
 if 'queryWords' in o:query=[r.fl(v) for v in o['queryWords']];n.pack('<3I',QUERY,*o['queryWords'])
 hit=bytearray((i*17+3)&255 for i in range(0x20));n.write(HIT,hit);return dict(nodes=nodes,edge=edge,seen=seen,hit=hit,query=query,marker=o.get('pathMarker',7))
def model(z,o):
 z=copy.deepcopy(z);e=z['edge'];ev=[];mode=o.get('stampMode',0);route=o.get('route',255);margin=f(o.get('margin',0));query=z['query'];endpoint0=e[0x10];endpoint1=e[0x11]
 if mode:
  if e[0x17]==z['marker']:return z,0,ev
  e[0x17]=z['marker']
 mask=1<<(route&255) if (route&255)<16 else 0
 if route!=255 and not o.get('noPrevious') and not r.h(e,0x14)&mask:
  previous=o.get('previous',[0,2]);common=next((v for v in previous if v in [endpoint0,endpoint1]),None)
  if common is None or not r.h(z['nodes'][common],0x5a)&mask:return z,0,ev
 p0=z['nodes'][endpoint0];p1=z['nodes'][endpoint1];threshold=A(W(margin),W(r.fl(b(.05))));small0=cmp(W(r.fl(r.u(p0,0x10))),threshold)<=0;small1=cmp(W(r.fl(r.u(p1,0x10))),threshold)<=0
 rad0=r.fl(r.u(p0,0x10)) if small0 else sf(r.fl(r.u(p0,0x10)),margin);rad1=r.fl(r.u(p1,0x10)) if small1 else sf(r.fl(r.u(p1,0x10)),margin)
 def refresh(bitindex,p,identityindex):
  if p[0x2a] and not z['seen'][bitindex>>3]&(1<<(bitindex&7)):ev.append(['refresh',CTX,identityindex]);effect(z,identityindex,o)
 refresh(endpoint0,p0,endpoint0);refresh(e[0x11],p1,endpoint1)
 pos=lambda p:[r.fl(r.u(p,4+j*4)) for j in range(3)]
 lo=lambda p:r.fl(r.u(p,0x18));hi=lambda p:r.fl(r.u(p,0x20));length=r.fl(r.u(e,0x1c));angle=struct.unpack_from('<h',e,0x12)[0];localx,localz=rotation(sf(query[0],pos(p0)[0]),sf(query[2],pos(p0)[2]),-angle);diff=sub(W(rad1),W(rad0));inside=False
 if abs(S(diff))<=length:
  if (abs(localx)>rad0 and abs(localx)>rad1) or localz< -rad0 or cmp(W(localz),A(W(length),W(rad1)))>0:return z,0,ev
  theta=arc.model(S(V(diff,W(length))));theta=((theta+32768)&65535)-32768;tx,tz=rotation(abs(localx),localz,-theta)
  if tz<0:inside=lo(p0)<=query[1]<=hi(p0) and cmp(distance(query,pos(p0),False),M(W(rad0),W(rad0)))<=0
  elif S(M(W(r.SINE[((theta+16384)>>1)&32767]),W(length)))<tz:inside=lo(p1)<=query[1]<=hi(p1) and cmp(distance(query,pos(p1),False),M(W(rad1),W(rad1)))<=0
  else:
   if rad0>localz:lower,upper=lo(p0),hi(p0)
   elif cmp(W(localz),sub(W(length),W(rad1)))>0:lower,upper=lo(p1),hi(p1)
   else:
    t=S(V(sub(W(localz),W(rad0)),sub(W(length),A(W(rad0),W(rad1)))));one=sub(W(1),W(t));lower=S(A(M(W(lo(p1)),W(t)),M(W(lo(p0)),one)));upper=S(A(M(W(hi(p1)),W(t)),M(W(hi(p0)),one)))
   inside=lower<=query[1]<=upper and tx<rad0
 else:
  point,radius=(p1,rad1) if rad0<rad1 else (p0,rad0);inside=lo(point)<=query[1]<=hi(point) and cmp(distance(query,pos(point),True),M(W(radius),W(radius)))<=0
 if inside and not o.get('noHit'):
  hit=z['hit'];r.put(hit,4,EDGE);hit[8]=0;r.put(hit,0xe,(r.h(hit,0xe)&~8)|(8 if small0 or small1 else 0)|1,2);ratio=r.fl((b(localz)^b(length))&0x80000000) if localz==0 else S(V(W(localz),W(length)));r.put(hit,0x10,b(ratio));r.put(hit,0x14,b(localx))
 return z,int(inside),ev
def summary(before,after,events):return dict(nodes=[r.changes(a,b) for a,b in zip(before['nodes'],after['nodes'])],edge=r.changes(before['edge'],after['edge']),hit=r.changes(before['hit'],after['hit']),seen=list(after['seen']),events=events)
def run(o,source=None):
 before=setup(o);expected,result,ev=model(before,o);args=[CTX,QUERY,PATH,EDGE,o.get('unused5',1),0 if o.get('noPrevious') else PREV,o.get('route',255),o.get('unused8',17),0 if o.get('noHit') else HIT,b(f(o.get('margin',0))),o.get('stampMode',0)];value=n.call(0x51b1f0,args);after=dict(nodes=[n.read(NODES+i*0x5c,0x5c) for i in range(4)],edge=n.read(EDGE,0x24),hit=n.read(HIT,0x20),seen=n.read(PATH+0x18,32));got=dict(result=value,state=summary(before,after,events));want=dict(result=result,state=summary(before,expected,ev))
 if got!=want:errors.append(dict(options=o,got=got,want=want))
 cases.append(dict(options=o,native=got,source=source))
def main():
 for x,y,z in itertools.product([-3,-2,-1,0,1,2,3],[-2,-1,0,1,2],[-3,-2,-1,0,1,2,5,8,9,10,11,12,13]):run(dict(query=[x,y,z]))
 for ra,rb,margin,query in itertools.product([.25,1,2,6],[.25,1,3,20],[-1,0,.25,2],[[0,0,-1],[.5,0,5],[1,0,9],[0,1,11]]):run(dict(radii=[ra,rb,2,2],margin=margin,query=query))
 for route,mask,bound,previous in itertools.product([0,1,15,16,31,32,63,64,255,256,511],[0,1,2,0x8000],[0,1,2,0x8000],[[0,2],[2,1],[2,3]]):run(dict(route=route,mask=mask,boundaries=[bound]*4,previous=previous))
 for mode,path,edge in itertools.product([0,1,0x80000000],[0,7,255],[0,7,255]):run(dict(stampMode=mode,pathMarker=path,edgeMarker=edge))
 for dynamic,seen in itertools.product([[0,0,0,0],[1,0,0,0],[0,1,0,0],[1,1,0,0]],[[0]*32,[255]*32]):run(dict(dynamic=dynamic,seen=seen))
 for effect in [dict(trigger=0,target='node',index=0,offset=0x10,value=b(40)),dict(trigger=0,target='node',index=0,offset=4,value=b(5)),dict(trigger=1,target='node',index=1,offset=0x20,value=b(-5)),dict(trigger=0,target='edge',offset=0x1c,value=b(5))]:run(dict(dynamic=[1,1,0,0],effects=[effect]))
 for seen in [0,2,4,6]:run(dict(dynamic=[1,1,1,0],seen=[seen]+[0]*31,effects=[dict(trigger=0,target='edge',offset=0x11,size=1,value=2),dict(trigger=1,target='node',index=1,offset=0x20,value=b(-5))]))
 for seen in [2,255]:run(dict(dynamic=[1,1,0,0],effects=[dict(trigger=0,target='seen',index=0,value=seen)]))
 for nullhit,noprev,angle in itertools.product([False,True],[False,True],[0,1,16384,32768,49152,65535]):run(dict(noHit=nullhit,noPrevious=noprev,angle=angle))
 for x,z,angle in itertools.product([0,0x80000000],[0,0x80000000],[0,1,16384,32768,49152,65535]):run(dict(queryWords=[x,0,z],angle=angle))
 rng=random.Random(0x51b1f0)
 for _ in range(2048):
  angle=rng.randrange(65536);length=f(rng.uniform(.125,40));r0=f(rng.uniform(.05,5));r1=f(rng.uniform(.05,5));p0=[f(rng.uniform(-100,100)),0,f(rng.uniform(-100,100))];dx,dz=rotation(0,length,angle);p1=[f(p0[0]+dx),0,f(p0[2]+dz)];localx=f(rng.uniform(-5,5));localz=f(rng.uniform(-5,length+5));dx,dz=rotation(localx,localz,angle);query=[f(p0[0]+dx),f(rng.uniform(-3,3)),f(p0[2]+dz)]
  run(dict(angle=angle,length=length,radii=[r0,r1,2,2],positions=[p0,p1,[5,0,0],[5,0,10]],query=query,heights=[[-2,.75],[-.25,2],[-1,1],[-1,1]],margin=f(rng.uniform(0,.5)),noHit=bool(rng.randrange(2))))
 sampled=0;excluded_zero_length=0
 for file in sorted((BASE/'reports/gameplay-navigation/data').rglob('*.json.gz')):
  doc=json.loads(gzip.decompress(file.read_bytes()))
  for path in doc['paths']:
   for index in sorted(set([0,len(path['connections'])//2,len(path['connections'])-1])):
    if index<0 or index>=len(path['connections']):continue
    edge=path['connections'][index];length=edge['distanceCandidates'][1]
    if length<=0:excluded_zero_length+=1;continue
    pa,pb=[path['points'][edge[k]] for k in ['to','from']];p0,p1=pa['position'],pb['position'];mid=[f((a+b)*.5) for a,b in zip(p0,p1)];height=[[(p['semantics']['minWorldY']),(p['semantics']['maxWorldY'])] for p in [pa,pb]]
    base=dict(angle=edge['unknownShorts'][0],length=length,radii=[pa['xzSize'],pb['xzSize'],2,2],positions=[p0,p1,[5,0,0],[5,0,10]],heights=height+[[-1,1],[-1,1]],mask=edge['unknownShorts'][1]);source=dict(file=doc['source'],path=path['index'],connection=index,offset=edge['offset']);sampled+=1
    for query in [p0,p1,mid,[mid[0],f(max(height[0][1],height[1][1])+1),mid[2]]]:run(dict(base,query=query),source)
 assembly=json.loads((BASE/'reports/gameplay-path-corridor-assembly.json').read_text());missing=[]
 for i in assembly['instructions']:
  i['executed']=int(i['address'],16) in executed
  if not i['executed']:missing.append(i['address'])
 (BASE/'reports/gameplay-path-corridor-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8')
 report=dict(binarySha256=n.sha256,checks=len(cases),mismatches=len(errors),examples=errors[:5],sampledAuthoredConnections=sampled,excludedNonpositiveLengthConnections=excluded_zero_length,instructionCoverage=dict(total=len(assembly['instructions']),executed=len(executed),missing=missing))
 (BASE/'reports/gameplay-path-corridor-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-corridor-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
