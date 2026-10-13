"""Original5f0f00 LOD/material branches with explicit downstream boundaries."""
import importlib.util,json,struct,gzip,hashlib,itertools,math
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
handle=BASE;header=BASE+0x100;owner=BASE+0x300;special=BASE+0x500;matrix=BASE+0x600;distances=BASE+0x700;models=BASE+0x1000;items=BASE+0x2000;mt=BASE+0x3000;flags=BASE+0x3200;mbits=BASE+0x3300;overrides=BASE+0x3400;materials=[BASE+0x4000+i*0x400 for i in range(6)];records=[BASE+0x6000+i*0x100 for i in range(6)];events=[];merges=[];errors=[];cases=[];sources=[];counts={'lod':0,'material':0,'mergeBoundary':0}
def skip(mu,retValue=0):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);mu.reg_write(UC_X86_REG_EAX,retValue)
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x5e0530:
  material,index=n.unpack('<2I',sp+4);events.append([materials.index(material),index]);skip(mu)
 elif address==0x5e5020:merges.append(list(n.unpack('<2I',sp+4)));skip(mu,materials[5])
 else:skip(mu)
for address in[0x5fd220,0x607590,0x5e0530,0x5e5020]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def setup(thresholds,position,forced=0):
 n.write(BASE,bytes(0x10000));n.pack('<3I',handle,header,0,special);n.pack('<I',header+0x110,owner);n.pack('<I',special+0xb0,models);n.pack('<I',special+0xbc,distances);n.pack('<I',owner+8,items);n.pack('<I',owner+0x48,flags);n.pack('<I',owner+0x50,mt);n.pack('<2I',owner+0x58,mbits,mbits+16);n.pack('<'+'f'*len(thresholds),distances,*thresholds)
 for i in range(len(thresholds)):
  pair=BASE+0x800+i*8;n.pack('<3I',models+i*12,1,pair,pair+4);n.pack('<2I',pair,0,3+i)
 n.pack('<16f',matrix,1,0,0,0,0,1,0,0,0,0,1,0,*position,1)
 for i,material in enumerate(materials):n.pack('<I',mt+i*4,material);n.pack('<I',material+0x3c,records[i]);n.pack('<2I',records[i],owner,i);n.pack('<I',material+0x1f0,7)
 for address,value in[(0x806ccc,1),(0x966384,0),(0x9738ec,forced),(0x9738f0,0),(0x9738f4,0),(0x9738a8,0),(0x9715a0,0),(0x2974d1c,0)]:n.pack('<I',address,value&0xffffffff)
 n.pack('<3f',0x973718,0,0,0);events.clear();merges.clear()
def lod(thresholds,distance,forced):
 i=0
 if thresholds[0]!=0:
  if forced==0:
   while distance<thresholds[i]:i+=1
  else:
   while thresholds[i]!=0 and i!=forced:i+=1
 return i
def runlod(thresholds,position,forced,label):
 setup(thresholds,position,forced);n.call(0x5f0f00,args=[handle,matrix,0x11111111,0,0]);distance=f32(sum(float(v)*v for v in position));expected=lod(thresholds,distance,forced);native=events[0][1]-3 if len(events)==1 else None
 if native!=expected and len(errors)<20:errors.append({'kind':'lod','label':label,'native':events,'expected':expected})
 cases.append({'kind':'lod','label':label,'thresholds':thresholds,'distanceWord':bits(distance),'forced':forced,'nativeIndex':native});counts['lod']+=1
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 row=index[sr['source']];raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/row['report']).read_text());chosen=data['specialObjects'][::max(1,len(data['specialObjects'])//8)][:8];recordsUsed=[]
 for spec in chosen:
  field=spec['address']+0xbc;relative=struct.unpack_from('<i',raw,field)[0]
  if not relative:continue
  p=field+relative;thresholds=[]
  for i in range(64):
   value=struct.unpack_from('<f',raw,p+i*4)[0]
   if not math.isfinite(value):raise ValueError('Nonfinite LOD threshold')
   thresholds.append(value)
   if value==0:break
  else:raise ValueError('Unterminated bounded authored LOD array')
  recordsUsed.append({'index':spec['index'],'thresholds':thresholds})
  for distance in[0.,1.,100.,10000.]:
   for forced in[0,1,-1]:runlod(thresholds,[math.sqrt(distance),0.,0.],forced,[sr['source'],spec['index'],distance,forced])
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'specials':recordsUsed})
 if errors:break
for thresholds in[[0.],[100.,25.,0.],[1.,f32(1-2**-24),0.],[2.,1.,1.,0.]]:
 for x in[0.,f32(1-2**-24),1.,f32(1+2**-23),5.,10.,100.]:
  for forced in[0,1,2,3,-1,2147483647]:runlod(thresholds,[x,0.,0.],forced,['boundary',thresholds,x,forced])
# Override precedence and linked-material gates. Clone is an explicit boundary;
# its synthetic return is a normal sixth material with independent chain/gates.
for tag,tablePresent,tableEntry,globalEntry,sameLayout,mode in itertools.product([0,7],[False,True],[False,True],[False,True],[False,True],[0,1,2]):
 setup([0.],[0.,0.,0.]);n.write(materials[0]+0x9a,bytes([tag]));n.pack('<I',overrides+tag*4,materials[2]if tableEntry else 0);n.pack('<I',0x9738f4,overrides if tablePresent else 0);n.pack('<I',0x9738f0,materials[1]if globalEntry else 0);n.pack('<I',0x2974d1c,mode)
 for i in[1,2]:n.pack('<I',materials[i]+0x1f0,7 if sameLayout else 8)
 for i in[0,1,2,5]:n.pack('<I',materials[i]+0x30,materials[3]);n.write(materials[i]+248,bytes([[0,0,0],[255,0,0],[1,0,0],[0,1,0]][[0,1,2,5].index(i)]))
 n.pack('<I',materials[3]+0x30,materials[4]);n.write(materials[3]+248,bytes([255,255,255]));n.write(materials[4]+248,bytes([0,0,0]));n.call(0x5f0f00,args=[handle,matrix,0,0,0]);replacement=(1 if globalEntry else 0)if not tablePresent or tag==0 else(2 if tableEntry else 0);selected=5 if replacement and not sameLayout else replacement;chain=[selected,3,4];gates={0:[0,0,0],1:[255,0,0],2:[1,0,0],3:[255,255,255],4:[0,0,0],5:[0,1,0]};expected=[i for i in chain if(gates[i][0]==255 or sum(gates[i])==0)if mode==1]if mode==1 else[i for i in chain if gates[i][0]!=255];actual=[row[0]for row in events];expectedMerge=bool(replacement and not sameLayout)
 if actual!=expected or bool(merges)!=expectedMerge:
  if len(errors)<20:errors.append({'kind':'material','input':[tag,tablePresent,tableEntry,globalEntry,sameLayout,mode],'native':actual,'expected':expected,'merge':merges})
 cases.append({'kind':'material','tag':tag,'tablePresent':tablePresent,'tableEntry':tableEntry,'globalEntry':globalEntry,'sameLayout':sameLayout,'mode':mode,'nativeSelected':actual,'nativeMerged':bool(merges)});counts['material']+=1;counts['mergeBoundary']+=len(merges)
fp=R/'geometry-dynamic-selection-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-selection-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'bounds':['Only LOD/material-selection branches from5f0f00: visibleoverride1,zero shadow count,no fade or matrix-sway. Original center/transform/distance helpers run unchanged.','Three output boundaries5fd220/607590/5e0530 recorded or skipped; shader/packet side effects unclaimed by this slice.','Material clone5e5020 records arguments then returns controlled material5; clone allocation/cache behavior is not reconstructed.','Authored threshold arrays combined with controlled one-part-per-LOD models so selected index is observable. Distances use a single nonzero coordinate, avoiding an inferred general distance arithmetic model.','No managed executable or GPU launched.']};(R/'geometry-dynamic-selection-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

