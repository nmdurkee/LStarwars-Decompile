"""51c150 side intersection and51c430 cached corner production."""
import importlib.util,struct,json,random,itertools,copy
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');ar=load('arcsine','gameplay-path-arcsine-verify.py');cm=load('cornermath','gameplay-path-corner-math-verify.py');corr=load('corridor','gameplay-path-corridor-verify.py');ang=load('angle','gameplay-path-angle-verify.py');n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=D;P=A+0x2c8;PATH=D+0x2000;NODES=D+0x4000;EDGES=D+0x6000;OUT=D+0x9000;CTX=0x12345678
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDI
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
W=cm.W
def sub(a,b):return (W(a)-W(b)).store()
def pos(p):return [r.fl(r.u(p,4+4*i)) for i in range(3)]
def rotation(v,angle):
 s=r.SINE[(angle>>1)&32767];c=r.SINE[((angle+16384)>>1)&32767];return [r.products(v[2],s,v[0],c),v[1],r.products(v[2],c,-v[0],s)]
def add(a,b):return [r.add(x,y) for x,y in zip(a,b)]
def wrap(x):return ((x+32768)&65535)-32768
def construct(nodes,a,b,common,first,second,angleA,angleB,bodyRadius,output):
 margin=W(bodyRadius)+W(r.f(.05));radii=[max(0.,(W(r.fl(r.u(nodes[i],0x10)))-margin).store()) for i in [first,common,second]];ra,rc,rb=radii;la=r.fl(r.u(a,0x1c));lb=r.fl(r.u(b,0x1c));angle0=wrap(angleA+wrap(ar.model(((W(rc)-W(ra))/W(la)).store())));angle1=wrap(angleB-wrap(ar.model(((W(rc)-W(rb))/W(lb)).store())))
 startA=add(rotation([ra,0.,0.],angle0),pos(nodes[first]));endA=add(rotation([ra,0.,la],angle0),pos(nodes[first]));startB=add(rotation([-rb,0.,0.],angle1),pos(nodes[second]));endB=add(rotation([-rb,0.,lb],angle1),pos(nodes[second]));da=[sub(x,y) for x,y in zip(endA,startA)];db=[sub(x,y) for x,y in zip(endB,startB)];result,u,v=cm.model(startA,da,startB,db);u,v=r.fl(u),r.fl(v)
 if not result or u<0 or v<0 or u>1 or v>1:return 0,output
 startA[1]=(W(pos(nodes[common])[1])*W(u)+(W(1)-W(u))*W(pos(nodes[first])[1])).store();scaled=[r.mul(x,u) for x in da];value=add(startA,scaled);return 1,struct.pack('<3I',*[r.bits(x) for x in value])
def setup(o):
 n.write(D,bytes(0xa000));n.write(0x29899a0,r.SINE_BYTES);actor=r.pattern(0x10d8,1);r.put(actor,0xac,r.bits(r.f(o.get('bodyRadius',.5))));r.put(actor,0x2c8+0x158,PATH);r.put(actor,0x2c8+0x13c,o.get('route',255),1);r.put(actor,0x2c8+0x190,EDGES if o.get('sameCache') else 0);r.put(actor,0x2c8+0x194,EDGES+0x24 if o.get('sameCache') else 0);r.put(actor,0x2c8+0x1e8,o.get('flags',0x1000));n.write(A,actor);n.pack('<I',PATH+0x7c,NODES);n.pack('<B',PATH+0x78,o.get('pathMarker',7));positions=o.get('positions',[[0,0,0],[0,0,-10],[10,0,0],[20,0,0]]);nodes=[]
 for i,p in enumerate(positions):
  node=bytearray(0x5c)
  for j,v in enumerate(p):r.put(node,4+j*4,r.bits(r.f(v)))
  r.put(node,0x10,r.bits(r.f(o.get('radii',[2,2,2,2])[i])));r.put(node,0x18,r.bits(r.f(p[1]-2)));r.put(node,0x20,r.bits(r.f(p[1]+2)));r.put(node,0x5a,o.get('boundaries',[0]*4)[i],2);nodes.append(node);n.write(NODES+i*0x5c,node)
 edges=[]
 for i,ends in enumerate(o.get('endpoints',[[1,0],[2,0]])):
  edge=bytearray(0x24);edge[0x10:0x12]=bytes(ends);length=r.f(o.get('lengths',[10,10])[i]);heading=o.get('edgeAngles',[0,49152])[i];r.put(edge,0x12,heading,2);r.put(edge,0x14,o.get('masks',[1,1])[i],2);edge[0x17]=o.get('edgeMarkers',[3,3])[i];r.put(edge,0x1c,r.bits(length));edges.append(edge);n.write(EDGES+i*0x24,edge)
 output=bytes((i*17+3)&255 for i in range(12));n.write(OUT,output);return dict(actor=actor,nodes=nodes,edges=edges,output=output)
def cachemodel(before,o):
 z=copy.deepcopy(before);actor=z['actor'];a,b=z['edges'];flags=r.u(actor,0x2c8+0x1e8)
 if o.get('sameCache'):return z,int(bool(flags&0x60))
 r.put(actor,0x2c8+0x1e8,flags&~0x60);r.put(actor,0x2c8+0x190,EDGES);r.put(actor,0x2c8+0x194,EDGES+0x24);a0,a1=a[0x10:0x12];b0,b1=b[0x10:0x12];aa=struct.unpack_from('<h',a,0x12)[0];ab=struct.unpack_from('<h',b,0x12)[0]
 if a0==b0:common,first,second,aa,ab=a0,a1,b1,wrap(aa+32768),wrap(ab+32768)
 elif a0==b1:common,first,second,aa=a0,a1,b0,wrap(aa+32768)
 elif a1==b0:common,first,second,ab=a1,a0,b1,wrap(ab+32768)
 elif a1==b1:common,first,second=a1,a0,b0
 else:return z,0
 state=dict(nodes=z['nodes'],edge=a,seen=bytearray(32),query=pos(z['nodes'][second]),hit=bytearray(32),marker=o.get('pathMarker',7));out,inside,events=corr.model(state,dict(stampMode=1,route=o.get('route',255),previous=[a0,a1],noHit=True));a[:]=out['edge']
 if inside:return z,0
 result,point=construct(z['nodes'],a,b,common,first,second,aa,ab,r.f(o.get('bodyRadius',.5)),bytes(actor[0x2c8+0x198:0x2c8+0x1a4]));actor[0x2c8+0x198:0x2c8+0x1a4]=point;r.put(actor,0x2c8+0x1e8,r.u(actor,0x2c8+0x1e8)|(result<<5));result,point=construct(z['nodes'],b,a,common,second,first,ab,aa,r.f(o.get('bodyRadius',.5)),bytes(actor[0x2c8+0x1a4:0x2c8+0x1b0]));actor[0x2c8+0x1a4:0x2c8+0x1b0]=point;r.put(actor,0x2c8+0x1e8,r.u(actor,0x2c8+0x1e8)|(result<<6));return z,int(bool(r.u(actor,0x2c8+0x1e8)&0x60))
cases=[];errors=[];counts={};executed=set();ranges=[(0x51c150,0x51c430),(0x51c430,0x51c6a0)]
for a,end in ranges:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=end-1)
def run(o,kind='construct'):
 before=setup(o)
 if kind=='construct':
  aa,ab=o.get('angles',[0,-16384]);result,output=construct(before['nodes'],*before['edges'],0,1,2,aa,ab,r.f(o.get('bodyRadius',.5)),before['output']);value=n.call(0x51c150,[EDGES+0x24,aa,ab,NODES,NODES+2*0x5c,OUT],{UC_X86_REG_EAX:A,UC_X86_REG_ECX:EDGES,UC_X86_REG_EDI:NODES+0x5c});got=[value,n.read(OUT,12).hex()];want=[result,output.hex()]
 else:
  expected,result=cachemodel(before,o);value=n.call(0x51c430,[CTX,P,A,EDGES,EDGES+0x24]);got=dict(result=value,actor=r.changes(before['actor'],n.read(A,len(before['actor']))),edges=[r.changes(e,n.read(EDGES+i*0x24,0x24)) for i,e in enumerate(before['edges'])]);want=dict(result=result,actor=r.changes(before['actor'],expected['actor']),edges=[r.changes(e,v) for e,v in zip(before['edges'],expected['edges'])])
 cases.append(dict(kind=kind,options=o,native=got));counts[kind]=counts.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 for radius,body,angle in itertools.product([0,.25,1,2,4],[0,.5,2,5],[0,8192,16384,32768,49152,65535]):run(dict(radii=[radius]*4,bodyRadius=body,angles=[0,angle]))
 for a,b in itertools.product([[0,1],[1,0]],[[0,2],[2,0]]):
  for same,flags,marker in itertools.product([False,True],[0,0x20,0x40,0x60,0xffffffff],[3,7]):run(dict(endpoints=[a,b],edgeAngles=[32768 if a[0]==0 else 0,16384 if b[0]==0 else 49152],sameCache=same,flags=flags,edgeMarkers=[marker,3]),'cache')
 for endpoints in [[[0,1],[2,3]],[[0,1],[0,1]],[[1,0],[1,0]]]:run(dict(endpoints=endpoints),'cache')
 for route,mask,bound in itertools.product([0,1,15,16,255],[0,1,2,0x8000],[0,1,2,0x8000]):run(dict(route=route,masks=[mask,1],boundaries=[bound]*4),'cache')
 rng=random.Random(0x51c150)
 for i in range(2048):
  o=dict(radii=[r.f(rng.uniform(0,4)) for _ in range(4)],bodyRadius=r.f(rng.uniform(0,3)),angles=[rng.randrange(65536),rng.randrange(65536)],lengths=[r.f(rng.uniform(8,30)),r.f(rng.uniform(8,30))],positions=[[r.f(rng.uniform(-20,20)) for _ in range(3)] for _ in range(4)]);run(o)
  if i<512:run(o,'cache')
 assembly=[]
 for a,end in ranges:
  ins=[]
  for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  assembly.append(dict(address=hex(a),endExclusive=hex(int(ins[-1]['address'],16)+len(bytes.fromhex(ins[-1]['bytes']))),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],instructionCoverage=dict(total=sum(len(s['instructions']) for s in assembly),executed=sum(i['executed'] for s in assembly for i in s['instructions']),missing=[i['address'] for s in assembly for i in s['instructions'] if not i['executed']]))
 (BASE/'reports/gameplay-path-corners-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-corners-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-corners-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
