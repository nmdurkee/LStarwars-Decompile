"""Original51af40 moving attachment refresh and scene-reference getters."""
import importlib.util,json,struct,copy,itertools,random,math
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');ang=load('ang','gameplay-path-angle-verify.py');corr=load('corr','gameplay-path-corridor-verify.py');n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;PATH=D;NODES=D+0x1000;EDGES=D+0x3000;LIST=D+0x4000;NORMAL=D+0x8000;INSTANCE=D+0x9000;DISPLAY=D+0xa000;ANIM=D+0xb000;CALLBACK=D+0xe000;CTX=0x12345678
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
w=r.wide;W=w.wide;A=w.add;M=w.mul;S=w.store
def b(v):return r.bits(v)
def f(v):return r.f(v)
def add(a,b):return r.fl(r.bits(a)&r.bits(b)&0x80000000) if a==0 and b==0 else S(A(W(a),W(b)))
def sub(a,b):return r.fl(r.bits(a)&~r.bits(b)&0x80000000) if a==0 and b==0 else S(A(W(a),W(-b)))
def transform(matrix,point):
 out=[]
 for c in range(3):
  value=M(W(matrix[c]),W(point[0]));approx=matrix[c]*point[0]
  for j in [1,2]:value=A(value,M(W(matrix[4*j+c]),W(point[j])));approx+=matrix[4*j+c]*point[j]
  value=A(value,W(matrix[12+c]));approx+=matrix[12+c];stored=S(value);out.append(r.fl(0x80000000 if math.copysign(1,approx)<0 else 0) if stored==0 else stored)
 return out
IDENTITY=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
def matrix(o):return [f(v) for v in o.get('matrix',IDENTITY[:12]+[10,0,0,1])]
def repair(z,o):
 p=z['nodes'][o.get('node',0)]
 if o.get('repair'):
  r.put(p,0x40,1);r.put(p,0x44,NORMAL);r.put(p,0x48,0)
 for e in o.get('effects',[]):r.put(p,e['offset'],e['value'],e.get('size',4))
events=[];options={};executed=set()
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);context,ref=n.unpack('<II',sp+4);events.append(['resolve',context,(ref-0x40-NODES)//0x5c]);z=dict(nodes=[bytearray(n.read(NODES+i*0x5c,0x5c)) for i in range(4)]);repair(z,options)
 for i,p in enumerate(z['nodes']):n.write(NODES+i*0x5c,p)
 mu.reg_write(UC_X86_REG_EAX,int(options.get('resolve',False)));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,callback,begin=CALLBACK,end=CALLBACK)
ranges=[(0x51af40,0x51b1eb),(0x5cfd60,0x5cfd90),(0x5d0330,0x5d0365),(0x5d0420,0x5d044b)]
for a,end in ranges:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=end-1)
def setup(o):
 global options,events
 options=o;events=[];n.write(D,bytes(0xc000));n.pack('<I',PATH+0x7c,NODES);seen=bytearray(o.get('seen',[0]*32));n.write(PATH+0x18,seen);idx=o.get('node',0);m=matrix(o);fallback=[f(v) for v in o.get('fallback',IDENTITY)];kind=o.get('kind','normal');animated=o.get('animated',0);anim=ANIM if animated==1 else 0xffffffff if animated==-1 else 0
 normalAnimated=o.get('normalAnimated',animated);displayAnimated=o.get('displayAnimated',animated);displayAnim=ANIM if displayAnimated==1 else 0xffffffff if displayAnimated==-1 else 0
 n.pack('<I',NORMAL+0x40,INSTANCE);n.pack('<16f',INSTANCE,*fallback);n.pack('<II',INSTANCE+0x44,o.get('normalFlags',o.get('visible',1)),ANIM if normalAnimated==1 else 0);n.pack('<16f',DISPLAY+0x40,*fallback);n.pack('<II',DISPLAY+0xb8,o.get('displayFlags',o.get('visible',1)<<1),0);n.pack('<I',DISPLAY+0xc4,displayAnim);n.pack('<16f',ANIM,*m);n.pack('<f',ANIM+0x40,f(o.get('speed',1)));n.pack('<I',ANIM+0x50,o.get('animationFlags',1))
 if animated!=1:n.pack('<16f',INSTANCE,*m);n.pack('<16f',DISPLAY+0x40,*m)
 nodeRecords=[];edges=[];endpoints=o.get('edges',[[0,1],[2,0],[1,2]])
 for i,ends in enumerate(endpoints):
  edge=bytearray(0x24);r.put(edge,0,o.get('edgeFlags0',0x55));r.put(edge,4,o.get('edgeFlags1',0xaa));edge[0x10:0x12]=bytes(ends);r.put(edge,0x12,1234,2);r.put(edge,0x1c,b(99));r.put(edge,0x20,b(f(o.get('extra',1))));edges.append(edge);n.write(EDGES+i*0x24,edge)
 for i in range(4):
  p=bytearray(0x5c);pos=o.get('positions',[[0,0,0],[0,0,10],[5,0,0],[5,0,10]])[i];local=[f(v) for v in o.get('local',[1,2,3])]
  if i==idx and o.get('samePosition'):pos=transform(m,local)
  for j,v in enumerate(pos):r.put(p,4+4*j,b(f(v)))
  r.put(p,0x10,b(f(o.get('radii',[2]*4)[i])));r.put(p,0x18,b(-999));r.put(p,0x20,b(999));r.put(p,0x1c,b(f(o.get('lowOffset',-1))));r.put(p,0x24,b(f(o.get('highOffset',1))));p[0x2a]=o.get('dynamic',1) if i==idx else 0;p[0x2b]=o.get('flags',0) if i==idx else o.get('otherFlags',0);adj=[j for j,e in enumerate(endpoints) if i in e];p[0x28]=len(adj);r.put(p,0x34,LIST+i*0x100)
  for j,e in enumerate(adj):n.pack('<I',LIST+i*0x100+j*4,EDGES+e*0x24)
  if i==idx:
   r.put(p,0x40,int(o.get('scene',True)));r.put(p,0x44,NORMAL if kind in ['normal','both'] else 0);r.put(p,0x48,DISPLAY if kind in ['display','both'] else 0)
   for j,v in enumerate(local):r.put(p,0x4c+4*j,b(v))
  nodeRecords.append(p);n.write(NODES+i*0x5c,p)
 n.pack('<I',0x9238d8,CALLBACK if o.get('callback') else 0);return dict(nodes=nodeRecords,edges=edges,seen=seen)
def reference(p,o):
 if r.u(p,0x44):return dict(visible=bool(r.u(p,0x40) and o.get('normalFlags',o.get('visible',1))&1),matrix=ANIM if o.get('normalAnimated',o.get('animated',0))==1 else INSTANCE,animation=ANIM if o.get('normalAnimated',o.get('animated',0))==1 else 0)
 if r.u(p,0x48):return dict(visible=bool(r.u(p,0x40) and o.get('displayFlags',o.get('visible',1)<<1)&2),matrix=ANIM if o.get('displayAnimated',o.get('animated',0))==1 else DISPLAY+0x40,animation=ANIM if o.get('displayAnimated',o.get('animated',0))==1 else 0)
 return dict(visible=False,matrix=0,animation=0)
def model(z,o):
 z=copy.deepcopy(z);idx=o.get('node',0);p=z['nodes'][idx];ev=[]
 if not p[0x2a] or z['seen'][idx>>3]&(1<<(idx&7)):return z,ev
 z['seen'][idx>>3]|=1<<(idx&7);adj=[i for i,e in enumerate(z['edges']) if idx in e[0x10:0x12]]
 if p[0x2b]&4:
  if not reference(p,o)['visible']:return z,ev
  p[0x2b]&=~4
  for i in adj:
   e=z['edges'][i];other=e[0x11] if e[0x10]==idx else e[0x10]
   if not z['nodes'][other][0x2b]&4:r.put(e,0,r.u(e,0)&~0x10000000);r.put(e,4,r.u(e,4)&~0x10000000)
 elif not reference(p,o)['visible']:
  if o.get('callback'):ev.append(['resolve',CTX,idx]);repair(z,o)
  if not o.get('callback') or not o.get('resolve'):
   p[0x2b]|=4
   for i in adj:e=z['edges'][i];r.put(e,0,r.u(e,0)|0x10000000);r.put(e,4,r.u(e,4)|0x10000000)
   return z,ev
 old=[r.fl(r.u(p,4+4*j)) for j in range(3)];local=[r.fl(r.u(p,0x4c+4*j)) for j in range(3)];new=transform(matrix(o),local)
 for j,v in enumerate(new):r.put(p,4+4*j,b(v))
 r.put(p,0x18,b(add(r.fl(r.u(p,0x1c)),new[1])));r.put(p,0x20,b(add(r.fl(r.u(p,0x24)),new[1])))
 for i in adj:
  e=z['edges'][i];other=e[0x11] if e[0x10]==idx else e[0x10];q=z['nodes'][other];first=z['nodes'][e[0x11]];second=z['nodes'][e[0x10]];dx=sub(r.fl(r.u(first,4)),r.fl(r.u(second,4)));dz=sub(r.fl(r.u(first,12)),r.fl(r.u(second,12)));length=f(math.sqrt(S(A(A(M(W(dx),W(dx)),W(0)),M(W(dz),W(dz))))));r.put(e,0x1c,b(length));r.put(e,0x12,ang.heading(dx,dz),2);extra=r.fl(r.u(e,0x20))
  if extra!=0:
   limit=A(A(W(r.fl(r.u(p,0x10))),W(extra)),W(r.fl(r.u(q,0x10))));mask=0x08000000
   for offset in [0,4]:r.put(e,offset,r.u(e,offset)|mask if A(W(length),(-limit[0],limit[1]))[0]>0 else r.u(e,offset)&~mask)
 moved=old!=new or reference(p,o)['animation'] and o.get('animationFlags',1)&1 and f(o.get('speed',1))!=0;p[0x2b]=(p[0x2b]|2) if moved else (p[0x2b]&~2)
 return z,ev
def summary(before,after,ev):return dict(nodes=[r.changes(a,b) for a,b in zip(before['nodes'],after['nodes'])],edges=[r.changes(a,b) for a,b in zip(before['edges'],after['edges'])],seen=list(after['seen']),events=ev)
cases=[];errors=[];counts={}
def run(o,kind='refresh'):
 before=setup(o);idx=o.get('node',0);ref=NODES+idx*0x5c+0x40
 if kind=='reference':
  got=dict(visible=bool(n.call(0x5cfd60,[ref])),matrix=n.call(0x5d0330,[ref]),animation=n.call(0x5d0420,[ref]));want=reference(before['nodes'][idx],o)
 elif kind=='corridor':
  query=[f(v) for v in o.get('query',[11,2,3])];hit=bytearray((i*17+3)&255 for i in range(32));state=dict(nodes=before['nodes'],edge=before['edges'][0],seen=before['seen'],hit=hit,query=query,marker=0);extra=copy.deepcopy(before['edges'][1:]);resolveEvents=[]
  originalEffect=corr.effect
  def composedEffect(z,point,unused):
   changed,ev=model(dict(nodes=z['nodes'],edges=[z['edge']]+extra,seen=z['seen']),dict(o,node=point));resolveEvents.extend(ev)
   for a,b in zip(z['nodes'],changed['nodes']):a[:]=b
   z['seen'][:]=changed['seen'];z['edge'][:]=changed['edges'][0]
   for a,b in zip(extra,changed['edges'][1:]):a[:]=b
  corr.effect=composedEffect
  try:expected,result,ignored=corr.model(state,dict(noPrevious=True,margin=o.get('margin',0)))
  finally:corr.effect=originalEffect
  n.write(0x29899a0,r.SINE_BYTES);n.pack('<3f',D+0xc000,*query);n.write(D+0xc100,hit);value=n.call(0x51b1f0,[CTX,D+0xc000,PATH,EDGES,1,0,255,0,D+0xc100,b(f(o.get('margin',0))),0]);after=dict(nodes=[n.read(NODES+i*0x5c,0x5c) for i in range(4)],edges=[n.read(EDGES+i*0x24,0x24) for i in range(len(before['edges']))],seen=n.read(PATH+0x18,32));got=dict(result=value,state=summary(before,after,events),hit=r.changes(hit,n.read(D+0xc100,32)));want=dict(result=result,state=summary(before,dict(nodes=expected['nodes'],edges=[expected['edge']]+extra,seen=expected['seen']),resolveEvents),hit=r.changes(hit,expected['hit']))
 else:
  expected,ev=model(before,o);n.call(0x51af40,[CTX,PATH,NODES+idx*0x5c]);after=dict(nodes=[n.read(NODES+i*0x5c,0x5c) for i in range(4)],edges=[n.read(EDGES+i*0x24,0x24) for i in range(len(before['edges']))],seen=n.read(PATH+0x18,32));got=summary(before,after,events);want=summary(before,expected,ev)
 cases.append(dict(kind=kind,options=o,native=got));counts[kind]=counts.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 for kind,scene,visible,animated in itertools.product(['none','normal','display','both'],[False,True],[0,1,2,3],[0,1,-1]):run(dict(kind=kind,scene=scene,visible=visible,animated=animated),'reference')
 for nf,df,na,da in itertools.product([0,1,2,3],[0,1,2,3],[0,1],[0,1,-1]):run(dict(kind='both',normalFlags=nf,displayFlags=df,normalAnimated=na,displayAnimated=da),'reference')
 for idx,dynamic,seen,flags,visible,animated in itertools.product(range(4),[0,1],[[0]*32,[255]*32],[0,2,4,6],[0,1],[0,1]):run(dict(node=idx,dynamic=dynamic,seen=seen,flags=flags,visible=visible,animated=animated))
 for kind,flags,visible,other,extra in itertools.product(['normal','display','both'],[0,4],[0,1],[0,4],[-1,0,1,20]):run(dict(kind=kind,flags=flags,visible=visible,otherFlags=other,extra=extra,edgeFlags0=0x18000055,edgeFlags1=0x180000aa))
 for animated,flags,speed in itertools.product([0,1],[0,1,2,3],[-1,0,1]):run(dict(animated=animated,animationFlags=flags,speed=speed,samePosition=True,flags=2))
 for kind,flags,success in itertools.product(['none','normal','display'],[0,4],[False,True]):
  run(dict(kind=kind,flags=flags,visible=0,callback=True,resolve=success,repair=success,effects=[dict(offset=0x1c,value=b(-7))]))
 for idx in range(4):run(dict(node=idx,edges=[],animated=1))
 for extra in [-10,-4,0,1]:run(dict(positions=[[11,2,3]]*4,extra=extra))
 for idx,flags,visible,animated,margin,query in itertools.product([0,1],[0,4],[0,1],[0,1],[0,.25],[[11,2,3],[11,2,8],[0,0,5],[20,0,0]]):run(dict(node=idx,flags=flags,visible=visible,animated=animated,margin=margin,query=query),'corridor')
 for success in [False,True]:run(dict(kind='none',callback=True,resolve=success,repair=success),'corridor')
 rng=random.Random(0x51af40)
 for i in range(2048):
  m=[f(rng.uniform(-3,3)) for _ in range(16)];m[12:15]=[f(rng.uniform(-50,50)) for _ in range(3)];run(dict(matrix=m,local=[f(rng.uniform(-10,10)) for _ in range(3)],positions=[[f(rng.uniform(-50,50)) for _ in range(3)] for _ in range(4)],kind=['normal','display','both'][i%3],animated=i%2,node=i%4,flags=4 if i%7==0 else 0,otherFlags=4 if i%11==0 else 0,radii=[f(rng.uniform(0,5)) for _ in range(4)],extra=f(rng.uniform(-2,20)),edgeFlags0=rng.randrange(2**32),edgeFlags1=rng.randrange(2**32)))
 assembly=[]
 for a,end in ranges:
  ins=[]
  for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  assembly.append(dict(address=hex(a),endExclusive=hex(int(ins[-1]['address'],16)+len(bytes.fromhex(ins[-1]['bytes']))),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],instructionCoverage=dict(total=sum(len(s['instructions']) for s in assembly),executed=sum(i['executed'] for s in assembly for i in s['instructions']),missing=[i['address'] for s in assembly for i in s['instructions'] if not i['executed']]))
 (BASE/'reports/gameplay-path-refresh-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-refresh-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-refresh-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
