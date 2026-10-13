"""51d1f0 subset nearest point and51d5e0 neighboring-path selection."""
import importlib.util,struct,json,random,itertools,copy
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
t=load('target','gameplay-path-targeting-verify.py');r=load('reinit','gameplay-reinitialization-verify.py');n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=D;P=A+0x2c8;REF=D+0x2000;EDGE=D+0x3000;PATHS=D+0x4000;NODES=D+0x10000;CAND=D+0x20000;GROUPS=D+0x30000;LIST=D+0x32000;SYSTEM=D+0x40000;CONTEXT=D+0x41000;MASKS=D+0x42000;QUERY=D+0x50000;OUT=D+0x50010
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EDI
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
def pathid(i):return PATHS+i*0x100 if i>=0 else 0
def points(o):return [[[r.f(v) for v in p] for p in graph] for graph in o.get('points',[[[i*10,0,0],[i*10,0,10],[i*10+2,0,5]] for i in range(4)])]
def candidates(o):return o.get('candidates',[[0,1]]*4)
def setup(o):
 n.write(D,bytes(0x51000));image=r.pattern(0x10d8,1);r.put(image,0x2c8+0x158,pathid(0));r.put(image,0x2c8+0x15c,EDGE);r.put(image,0x2c8+0x1cc,pathid(o.get('target',3)));r.put(image,0x2c8+0xd0,REF);r.put(image,0x2c8+0x130,o.get('memberLow',1));r.put(image,0x2c8+0x134,o.get('memberHigh',0));query=[r.f(v) for v in o.get('query',[1,0,1])]
 for j,v in enumerate(query):r.put(image,0x2c8+0x1b4+j*4,r.bits(v))
 n.write(A,image);n.pack('<3f',REF+0x5c,*[r.f(v) for v in o.get('position',[0,0,5])]);n.pack('<BB',EDGE+0x10,*o.get('endpoints',[0,1]));n.pack('<I',CONTEXT+0x10,SYSTEM);n.pack('<I',SYSTEM+0xc,GROUPS);n.pack('<3f',QUERY,*query);n.pack('<II',OUT,o.get('outPoint',0x12345678),o.get('outDistanceWord',0x42c80000));pp=points(o);cc=candidates(o)
 for i in range(4):
  node=NODES+i*0x1000;row=CAND+i*0x1000;path=pathid(i);n.pack('<B',path+0x7a,len(cc[i]));n.pack('<I',path+0x7c,node);n.pack('<I',path+0x8c,row);n.pack('<B',path+0x14,3);n.pack('<I',path+0x88,MASKS+i*0x100)
  for j,mask in enumerate([1,2,0x100000000]):n.pack('<Q',MASKS+i*0x100+0x28*j+0x18,mask)
  for j,p in enumerate(pp[i]):n.pack('<3f',node+j*0x5c+4,*p);n.pack('<f',node+j*0x5c+0x14,r.f(o.get('scores',[0,0,0])[j] if i==0 else 0));n.pack('<B',node+j*0x5c+0x30,o.get('links',[0,1,255])[j] if i==0 else 0)
  for j,point in enumerate(cc[i]):n.pack('<BBh',row+j*4,point,0xa5,o.get('groupIndices',[0,1])[j%2])
 for k,group in o.get('groups',{'0':[1,2],'1':[2,1]}).items():
  ix=int(k);ptr=LIST+(ix+8)*0x100;n.pack('<BI',GROUPS+ix*8,len(group),0);n.pack('<I',GROUPS+ix*8+4,ptr)
  for j,i in enumerate(group):n.pack('<I',ptr+j*4,pathid(i))
 return image,pp,cc,query
def nearest(pp,cc,query,outPoint,outDistance):
 best=r.fl(0x7f7fffff);chosen=None
 for point in cc:
  distance=t.distance(pp[point],query)
  if distance<best:chosen=point;best=distance
 return (0,outPoint,outDistance) if chosen is None else (1,chosen,r.bits(best))
def bind(image,identity):
 if r.u(image,0x2c8+0x158)==identity:return
 for at in [0x15c,0x160,0x164,0x168,0x16c,0x17c]:r.put(image,0x2c8+at,0)
 for at,value,size in [(0x158,identity,4),(0x161,255,1),(0x13a,0,2),(0x124,65535,2),(0x13c,255,1),(0x13d,0,1)]:r.put(image,0x2c8+at,value,size)
 member=r.u(image,0x2c8+0x130)|(r.u(image,0x2c8+0x134)<<32);mask=sum(1<<j for j,value in enumerate([1,2,0x100000000]) if value&member);r.put(image,0x2c8+0x13a,mask,2)
def model(image,pp,cc,query,o):
 image=bytearray(image);ends=o.get('endpoints',[0,1]);position=[r.f(v) for v in o.get('position',[0,0,5])];scores=[r.f(v) for v in o.get('scores',[0,0,0])];a,b=[r.f(t.distance(position,pp[0][i])-scores[i]) for i in ends];selected=ends[1] if b<=a else ends[0];link=o.get('links',[0,1,255])[selected]
 if link>=len(cc[0]):return 0,image,None
 gi=o.get('groupIndices',[0,1])[link%2];group=o.get('groups',{'0':[1,2],'1':[2,1]}).get(str(gi),[]);target=o.get('target',3)
 if target in group:bind(image,pathid(target));return 1,image,target
 best=r.fl(0x7f7fffff);distanceWord=r.bits(a);outPoint=0;chosen=None
 for i in group:
  _,outPoint,distanceWord=nearest(pp[i],cc[i],query,outPoint,distanceWord);distance=r.fl(distanceWord)
  if distance<best:best=distance;chosen=i
 if chosen is None:return 0,image,None
 bind(image,pathid(chosen));return 1,image,chosen
cases=[];errors=[];counts={};executed=set();ranges=[(0x51d1f0,0x51d284),(0x51d5e0,0x51d74f)]
for a,end in ranges:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=end-1)
def run(o,kind='transition'):
 before,pp,cc,query=setup(o)
 if kind=='nearest':
  i=o.get('path',1);want=nearest(pp[i],cc[i],query,o.get('outPoint',0x12345678),o.get('outDistanceWord',0x42c80000));value=n.call(0x51d1f0,[QUERY,OUT,OUT+4],{UC_X86_REG_EDI:pathid(i)});got=[value,*n.unpack('<II',OUT)];want=list(want)
 else:
  result,after,selected=model(before,pp,cc,query,o);value=n.call(0x51d5e0,[CONTEXT,P]);got=dict(result=value,changes=r.changes(before,n.read(A,len(before))));want=dict(result=result,changes=r.changes(before,after))
 counts[kind]=counts.get(kind,0)+1;cases.append(dict(kind=kind,options=o,native=got))
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 for count,query in itertools.product([0,1,2,3,7,254,255],[[0,0,0],[10,0,5],[1,2,3]]):run(dict(candidates=[[0,1],[i%3 for i in range(count)],[0,1],[0,1]],query=query),'nearest')
 for target,position,links,group in itertools.product([-1,0,1,2,3],[[0,0,0],[0,0,5],[0,0,10]],[[0,1,255],[255,255,255],[0,0,255]],[[],[1],[1,2],[2,1],[0,1,2]]):run(dict(target=target,position=position,links=links,groups={'0':group,'1':group}))
 for c1,c2,group,score in itertools.product([[],[0],[0,1]], [[],[0],[0,1]],[[1,2],[2,1]],[-100,0,100]):run(dict(candidates=[[0,1],c1,c2,[0,1]],groups={'0':group,'1':group},scores=[score,0,0]))
 for gi in [-1,0,1]:run(dict(groupIndices=[gi,gi],groups={str(gi):[1,2]}))
 for member in [0,1,2,3,0xffffffff]:run(dict(memberLow=member,memberHigh=member))
 rng=random.Random(0x51d5e0)
 for i in range(2048):
  o=dict(points=[[[r.f(rng.uniform(-100,100)) for _ in range(3)] for _ in range(3)] for _ in range(4)],position=[r.f(rng.uniform(-100,100)) for _ in range(3)],query=[r.f(rng.uniform(-100,100)) for _ in range(3)],scores=[r.f(rng.uniform(-100,100)) for _ in range(3)],candidates=[[0,1]]+[[rng.randrange(3) for _ in range(rng.randrange(4))] for _ in range(3)],groups={'0':[1,2,3],'1':[3,2,1]},target=-1,memberLow=rng.randrange(4),memberHigh=rng.randrange(2));run(o);run(o,'nearest')
 assembly=[]
 for a,end in ranges:
  ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a)];assembly.append(dict(address=hex(a),endExclusive=hex(end),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],instructionCoverage=dict(total=sum(len(s['instructions']) for s in assembly),executed=len(executed),missing=[i['address'] for s in assembly for i in s['instructions'] if not i['executed']]))
 (BASE/'reports/gameplay-path-transition-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-transition-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-transition-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
