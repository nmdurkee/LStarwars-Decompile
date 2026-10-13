"""Original incremental nearest point scan, target materialization/status."""
import importlib.util,json,struct,copy,itertools,gzip,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
x=load('native','native-x86.py');wide=load('wide','animation-x87.py');n=x.NativeX86();BASE=x.BASE;D=n.DATA;A=D;P=A+0x2c8;PATH=D+0x2000;NODES=D+0x4000;EDGES=D+0x10000;ADJ=D+0x20000;SUBSET=D+0x30000;QUERY=D+0x31000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESI,UC_X86_REG_EDI
graphs=[];vectors=[];errors=[];groups={};executed=set();entries=[(0x51d310,0x1ec),(0x51d500,0xda),(0x51d750,0x59)]
for start,size in entries:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:executed.add(a),begin=start,end=start+size-1)
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def u(b,p):return struct.unpack_from('<I',b,p)[0]
def put(b,p,v,size=4):b[p:p+size]=(v&((1<<(size*8))-1)).to_bytes(size,'little')
def fl(b,p):return struct.unpack_from('<f',b,p)[0]
def pattern():return bytearray((i*37+11)&255 for i in range(0x10d8))
def changes(a,b):return [[p,u(b,p)] for p in range(0,len(a),4) if a[p:p+4]!=b[p:p+4]]
def distance(a,b):
 d=[f(x-y) for x,y in zip(a,b)];return wide.dot3_plus_constant(*d,*d,0)
def setup(g,o):
 n.write(D,bytes(0x32000));image=pattern();put(image,0x2c8+0x158,PATH);put(image,0x2c8+0x1cc,PATH if o.get('same') else 0);put(image,0x2c8+0x1d0,EDGES if o.get('target') else 0)
 for at,name,default in [(0x142,'cursor',0),(0x143,'selected',255),(0x1ec,'flags',4)]:put(image,0x2c8+at,o.get(name,default),1)
 query=o.get('query',[0.,0.,0.]);query=[f(v) for v in query]
 for j,v in enumerate(query):put(image,0x2c8+0x1b4+j*4,bits(v))
 n.write(A,image);n.pack('<B',PATH+0x10,g['count']);n.pack('<B',PATH+0x7a,g.get('candidateCount',0));n.pack('<I',PATH+0x7c,NODES);n.pack('<I',PATH+0x8c,SUBSET);adj=ADJ
 for i,p in enumerate(g['points']):
  n.pack('<3f',NODES+i*0x5c+4,*p['position']);n.pack('<f',NODES+i*0x5c+0x10,p['radius']);n.pack('<B',NODES+i*0x5c+0x28,len(p['edges']));n.pack('<I',NODES+i*0x5c+0x34,adj)
  for edge in p['edges']:n.pack('<I',adj,EDGES+0x24*edge);adj+=4
 for i,e in enumerate(g['edges']):n.pack('<BB',EDGES+i*0x24+0x10,*e)
 for i,point in enumerate(g.get('candidates',[])):n.pack('<I',SUBSET+i*4,point|0xaabbcc00)
 n.pack('<3f',QUERY,*query);return image,query
def model(g,o,image,query,kind):
 image=bytearray(image)
 def scan():
  best=f(3.4028234663852886e38);subset=g.get('candidateCount',0)>0 and image[0x2c8+0x1ec]&4;limit=g['candidateCount'] if subset else g['count']
  if image[0x2c8+0x143]>=g['count']:image[0x2c8+0x143]=255
  if image[0x2c8+0x142]>=limit:image[0x2c8+0x142]=0
  if image[0x2c8+0x143]<g['count']:best=distance(g['points'][image[0x2c8+0x143]]['position'],query)
  start=image[0x2c8+0x142]
  for _ in range(4):
   cursor=image[0x2c8+0x142]
   if not subset or image[0x2c8+0x143]!=cursor:
    point=g['candidates'][cursor] if subset else cursor;d=distance(g['points'][point]['position'],query)
    if d<best:image[0x2c8+0x143]=point;best=d
   cursor=(cursor+1)&255;image[0x2c8+0x142]=0 if cursor>limit else cursor
   if subset and image[0x2c8+0x142]==start:return
 def materialize():
  selected=image[0x2c8+0x143];point=g['points'][selected]
  if not point['edges']:return 0
  for i,v in enumerate(point['position']):put(image,0x2c8+0x1b4+4*i,bits(v))
  put(image,0x2c8+0x1c0,0);radius=point['radius'];value=1. if radius<=2 else wide.store(wide.add(wide.wide(radius),wide.wide(-1.)));put(image,0x2c8+0x1c4,bits(value))
  for at in range(0x1cc,0x1e1,4):put(image,0x2c8+at,0)
  put(image,0x2c8+0x1cc,PATH);put(image,0x2c8+0x1d0,EDGES+0x24*point['edges'][0]);first=g['edges'][point['edges'][0]][0]==selected;put(image,0x2c8+0x1d4,int(first),1);put(image,0x2c8+0x1dc,bits(0. if first else 1.));return 1
 if kind=='scan':scan();result=None
 elif kind=='materialize':result=materialize()
 elif u(image,0x2c8+0x158)==u(image,0x2c8+0x1cc) and u(image,0x2c8+0x1d0):result=0
 else:
  scan();result=1 if image[0x2c8+0x143]<g['count'] and materialize() else -1
 return image,result
def run(gid,o=None,kind='scan',source=None):
 o=o or {};g=graphs[gid];before,query=setup(g,o);want_image,result=model(g,o,before,query,kind)
 if kind=='scan':value=n.call(0x51d310,[QUERY],{UC_X86_REG_ESI:P,UC_X86_REG_EDI:PATH});value=None
 elif kind=='materialize':value=n.call(0x51d500,[],{UC_X86_REG_ECX:P})
 else:value=n.call(0x51d750,[],{UC_X86_REG_EAX:P});value=value if value<2**31 else value-2**32
 got=dict(result=value,changes=changes(before,n.read(A,len(before))));want=dict(result=result,changes=changes(before,want_image))
 if got!=want:errors.append(dict(graph=gid,options=o,kind=kind,got=got,want=want))
 vectors.append(dict(graph=gid,options=o,kind=kind,native=got,source=source));key='authored' if source else kind;groups[key]=groups.get(key,0)+1
def main():
 for count in [0,1,2,3,4,8,254,255]:
  for subset in [0,1,3,255]:
   g=dict(count=count,candidateCount=subset,candidates=[(i*7+1)%(count+1) for i in range(subset+1)],points=[dict(position=[f(i*.75),f((i%3)*1.25),f((i%5)*-.5)],radius=f(i*.5),edges=[0] if i%3 else []) for i in range(count+1)],edges=[[0,1]])
   gid=len(graphs);graphs.append(g)
   for cursor,selected,flags in itertools.product(sorted(set([0,1,max(0,count-1),count,255])),sorted(set([0,1,max(0,count-1),count,255])),[0,4]):run(gid,dict(cursor=cursor,selected=selected,flags=flags,query=[.5,.25,-.5]))
   for cursor,same,target in itertools.product([0,count,255],[False,True],[False,True]):run(gid,dict(cursor=cursor,same=same,target=target,query=[.5,.25,-.5]),'ensure')
   for selected in sorted(set([0,count//2,count])):run(gid,dict(selected=selected),'materialize')
 # Radius thresholds and exact-distance midpoint which ordinary double loses.
 for radius in [-1e20,-1,0,1,2,f(2-2**-23),f(2+2**-22),3.5,1e20]:
  g=dict(count=2,candidateCount=0,points=[dict(position=[1.,0.,0.],radius=radius,edges=[0]),dict(position=[1.,2**-12,2**-27],radius=radius,edges=[0]),dict(position=[2.,0.,0.],radius=radius,edges=[0])],edges=[[0,1]])
  gid=len(graphs);graphs.append(g)
  for selected in [0,1]:run(gid,dict(selected=selected),'materialize')
  run(gid,dict(selected=1,query=[0.,0.,0.]));run(gid,dict(selected=1),'ensure')
 authored_paths=0
 for file in sorted((BASE/'reports/gameplay-navigation/data').rglob('*.json.gz')):
  doc=json.loads(gzip.decompress(file.read_bytes()))
  for path in doc['paths']:
   if not path['points']:continue
   g=dict(count=len(path['points']),candidateCount=0,points=[dict(position=p['position'],radius=p['xzSize'],edges=p['connectionIndices']) for p in path['points']],edges=[[e['to'],e['from']] for e in path['connections']],source=dict(file=doc['source'],path=path['index']))
   gid=len(graphs);graphs.append(g);authored_paths+=1
   for selected in sorted(set([0,len(g['points'])//2,len(g['points'])-1])):run(gid,dict(selected=selected),'materialize',g['source'])
   if len(g['points'])>=4:run(gid,dict(selected=0,cursor=0,query=g['points'][-1]['position']),'ensure',g['source'])
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[dict(address=hex(start),endExclusive=hex(start+size),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in d.disasm(n.read(start,size),start)]) for start,size in entries]
 report=dict(binarySha256=n.sha256,checks=len(vectors),mismatches=len(errors),groups=groups,examples=errors[:3],authoredPaths=authored_paths,instructionCoverage={p['address']:dict(total=len(p['instructions']),executed=sum(i['executed'] for i in p['instructions']),missing=[i['address'] for i in p['instructions'] if not i['executed']]) for p in functions},method='Original51d310/51d500/51d750 with actual5b3c50 distance arithmetic. Entire0x10d8 actor image compared. Prepared extra backing points/candidate entries preserve index==count behavior; authored scan samples never read unavailable sentinel records. Finite float input domain.')
 (BASE/'reports/gameplay-path-targeting-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-targeting-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,graphs=graphs,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-targeting-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
