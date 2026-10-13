"""Original FOV integer-conversion slice and recursion guard/cycle boundaries."""
import importlib.util,json,struct,hashlib,itertools,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
def module(name,path):
 s=importlib.util.spec_from_file_location(name,P/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('nx','native-x86.py');model=module('portal_model','geometry-portal-runtime-model.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
errors=[];angleOnly=False;angleResult=None;entries=[];counts={'angleConversion':0,'recursionGuards':0,'syntheticGraphs':0,'loaderDepthInitialization':0};cases=[];angleCases=[]
def hook(mu,address,size,_):
 global angleResult
 if address==0x5d9a9a and angleOnly:
  angleResult=n.unpack('<q',mu.reg_read(UC_X86_REG_ESP)+0x14)[0];mu.reg_write(UC_X86_REG_EIP,n.STOP)
 elif address==0x5ee940:
  v=n.unpack('<6I',mu.reg_read(UC_X86_REG_ESP));entries.append([(v[3]&65535)-(65536 if v[3]&32768 else 0),(v[4]&65535)-(65536 if v[4]&32768 else 0),v[5]])
for a in [0x5d9a9a,0x5ee940]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
scale=n.unpack('<d',0x755d18)[0];values=[0.,-0.,1.,-1.]
for desired in [0.,1.,-1.,.5,-.5,2**31-1,-2**31,2**31,-2**31-1]:
 value=model.f32(desired/scale);bits=struct.unpack('<I',struct.pack('<f',value))[0]
 for delta in [-1,0,1]:
  raw=(bits+delta)&0xffffffff;v=struct.unpack('<f',struct.pack('<I',raw))[0]
  if math.isfinite(v):values.append(v)
angleOnly=True
for half in values:
 n.pack('<f',n.STACK+0xe000+0x30,half);n.call(0x5d9a76);wide=model.x87.mul(model.x87.wide(half),model.x87.wide(scale));m,e=wide;expected=(abs(m)<<e if e>=0 else abs(m)>>-e)*(-1 if m<0 else 1);counts['angleConversion']+=1
 row={'halfFov':half,'nativeInt64':angleResult,'portableInt32Domain':-2**31<=expected<2**31};angleCases.append(row)
 if angleResult!=expected:errors.append({'angle':row,'expected':expected})
angleOnly=False
uv=json.loads((R/'geometry-uv-programs.json').read_text());sineBytes=(B/uv['sineTable']['file']).read_bytes();sine=list(struct.unpack('<32768f',sineBytes));n.write(0x29899a0,sineBytes)
base=n.DATA;scene=base;display=base+0x1000;rooms=base+0x2000;portals=base+0x3000;storage=base+0x5000;bounds=base+0x10000;flags=base+0x20000;overrides=base+0x21000;camera=base+0x22000;scratch=base+0x23000;arena=base+0x80000
identity=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.];eye=[0.,0.,1.,0.];initial=model.rectangle_volume([-1.]*3,[1.]*3,-2,identity,1.,.75,sine,scale,eye)
def setup(edges,depthLimit):
 count=max([v for p in edges for v in p]+[0])+1;data={'bounds':[{'center':[0.,0.,2.],'extent':[.1,.1,.1]}for i in range(count)],'portalData':{'rooms':[{'instanceIndices':[i],'portalIndices':[],'flags':0x20,'priority':0}for i in range(count)],'portals':[]}}
 for i,(a,b)in enumerate(edges):
  p={'plane':[0.,0.,1.,-1.],'vertices':[[-1.,-1.,1.],[1.,-1.,1.],[1.,1.,1.],[-1.,1.,1.]],'frontRoom':a,'backRoom':b,'activeFlags':1};data['portalData']['portals'].append(p);data['portalData']['rooms'][a]['portalIndices'].append(i)
  if b!=a:data['portalData']['rooms'][b]['portalIndices'].append(i)
 n.write(scene,b'\0'*0x25000);n.pack('<I',scene+0x110,display);n.pack('<II',scene+0x74,count,rooms);n.pack('<I',scene+0x70,portals);n.pack('<I',scene+0xfc,bounds);n.pack('<i',scene+0xe4,depthLimit);n.pack('<I',display+0x74,0x4000);n.pack('<I',display+0x48,flags);n.pack('<I',display+0x88,overrides);n.write(flags,bytes([9])*count)
 cursor=storage
 for i,r in enumerate(data['portalData']['rooms']):
  address=rooms+24*i;n.pack('<I',address,cursor);n.pack('<h',cursor,i);cursor+=4;n.pack('<h',address+12,1);n.pack('<I',address+8,cursor);n.write(address+15,bytes([len(r['portalIndices'])]));n.pack('<I',address+16,0x20)
  for pi in r['portalIndices']:n.pack('<h',cursor,pi);cursor+=2
  cursor=(cursor+3)&~3;n.pack('<4f4f',bounds+32*i,0.,0.,2.,0.,.1,.1,.1,0.)
 for i,p in enumerate(data['portalData']['portals']):
  n.pack('<4fIhhh',portals+32*i,*p['plane'],cursor,4,p['frontRoom'],p['backRoom']);n.pack('<I',portals+32*i+28,1)
  for v in p['vertices']:n.pack('<3f',cursor,*v);cursor+=12
 n.pack('<16f',camera,*identity);n.pack('<2f',camera+64,1.,.75);n.pack('<I',0x96e564,camera);n.pack('<16f',0x95fb78,*identity);n.pack('<16f',0x80b888,*identity);n.pack('<3f',0x971894,0.,0.,0.);n.pack('<4f',0x963f78,*eye);n.pack('<h',0x971abc,0);n.pack('<I',0x97398c,0);n.pack('<I',0x96d9c0,arena);n.pack('<I',0x966388,arena+0x10000);n.pack('<I',0x963e00,scene+0x9c);n.pack('<I',0x963f98,scene+0xdc);n.pack('<3f',scratch,-1.,-1.,-1.);n.pack('<3f',scratch+16,1.,1.,1.);ptr=n.call(0x5d9a00,[scratch,scratch+16,0xfffffffe]);n.write(0x280a2f0,bytes(625));return data,ptr
def check(edges,depthLimit,startDepth,path,previous,kind):
 data,ptr=setup(edges,depthLimit);expected=model.traverse(data,0,initial,identity,1.,.75,sine,scale,identity,eye,depthLimit,[9]*len(data['bounds']),bytes(625),bytes(625),active=[1]*len(edges),startDepth=startDepth,previous=previous,path=path);n.pack('<16h',0x963f54,*path);entries.clear();n.call(0x5ee940,[scene,ptr,0,previous,startDepth],count=1000000);count=n.unpack('<I',scene+0xdc)[0];actual={'bits':n.read(0x280a2f0,625).hex(),'flags':[n.unpack('<I',rooms+24*i+16)[0]for i in range(len(data['bounds']))],'path':list(n.unpack('<16h',0x963f54)),'entries':list(entries),'volumes':count};want={'bits':bytes(expected['bits']).hex(),'flags':expected['roomFlags'],'path':expected['path'],'entries':expected['entries'],'volumes':len(expected['volumes'])};counts[kind]+=1;row={'edges':edges,'depthLimit':depthLimit,'startDepth':startDepth,'path':path,'previous':previous,'native':actual};cases.append(row)
 if actual!=want and len(errors)<30:errors.append({'case':row,'expected':want})
for depth in [0,1,2,3,15,16,17]:
 for location in sorted(set([-1,0,max(0,depth-2),min(15,max(0,depth-1))])):
  path=[-1]*16
  if location>=0:path[location]=0
  check([],0,depth,path,-1,'recursionGuards')
for edges,depth,previous in itertools.product([[(0,0)],[(0,1)],[(0,1),(1,2),(2,0)],[(0,1),(0,1)],[(0,1),(1,1),(1,2)]],[0,1,2,4,15],[-1,0,1]):check(edges,depth,0,[-1]*16,previous,'syntheticGraphs')
loaderDepthCases=[]
for row in [r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']if r['rooms']]:
 n.write(scene,b'\0'*0x2000);n.pack('<I',scene+0x1d0,scene+0x1000);n.pack('<I',scene+0x6c,row['portals']);n.pack('<I',scene+0xe4,0xabababab)
 n.pack('<H',0x986e88,0);n.pack('<H',0x986e90,0);n.pack('<I',0x986e8c,scratch);n.pack('<I',0x986e94,scratch+16);n.pack('<I',scene+0x1000+4,scratch+32);n.pack('<I',scene+0x1000+12,scratch+48)
 n.call(0x602550,[scene],count=1000000);actual=n.unpack('<I',scene+0xe4)[0];counts['loaderDepthInitialization']+=1;loaderDepthCases.append({'source':row['source'],'portalCount':row['portals'],'nativeDepth':actual})
 if actual!=row['portals']:errors.append({'loaderDepth':loaderDepthCases[-1]})
report={'schema':'original-portal-runtime-boundaries-v1','binarySHA256':n.sha256,'passed':not errors,'counts':counts,'errors':errors,'angleScale':scale,'angleCases':angleCases,'cases':cases,'scope':['Original FOV instruction slice0x5d9a76..0x5d9a9a executes unchanged until its result is read; only then execution stops at the explicit slice endpoint.','Full original recursive helper and its callees execute unchanged for guard/graph cases.','Depth16/17 direct-call fixtures cover the native guard; normal portable entry begins atdepth0.','Synthetic self-links,triangular cycles,duplicate links,previous-room exclusion and depth caps are distinguished from authored geometry.'],'limits':['Portable phase conversion excludes out-of-Int32 results even though native slice writesInt64.','Compiled C# conversion and traversal execution remain pending.']}
report['loaderDepthCases']=loaderDepthCases;report['scope'].append('Original602550 load finalizer and5d9130 setter execute with empty buffer/material arrays and all60 authored portal counts; depth becomes portal count. No GPU/resource-allocation branch is entered.')
(R/'geometry-portal-runtime-boundaries.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n');print(json.dumps({k:report[k]for k in ['passed','counts','errors']},indent=2))
if errors:raise SystemExit(1)
