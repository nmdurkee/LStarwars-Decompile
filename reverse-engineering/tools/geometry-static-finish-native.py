"""Original alpha/material command patchers and bounded finish orchestration."""
import importlib.util,json,struct,hashlib,gzip,itertools,random
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
BASE=0x11000000;SIZE=0x2000000;n.mu.mem_map(BASE,SIZE);cursor=BASE;scene=n.DATA;errors=[];cases=[];sources=[];counts={'authoredAlpha':0,'authoredMaterial':0,'materialBoundary':0,'finish':0,'alphaMatrixWords':0,'commandBytes':0};digest=hashlib.sha256();hooks={};calls=[];callRows=[]
def alloc(size):
 global cursor
 a=(cursor+15)&~15;cursor=a+size
 if cursor>BASE+SIZE:raise ValueError('Fixture arena exhausted')
 n.write(a,bytes(size));return a
def hook(mu,address,size,_):
 calls.append([hex(address),mu.reg_read(UC_X86_REG_ESI)])
 if address in hooks:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];hooks[address]();mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for a in [0x5f0d70,0x4ffaa0,0x4ffac0,0x5de440,0x603920,0x5df910,0x5df880,0x5e0bd0,0x5e0d00]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def compare(a,e,where):
 digest.update(str((a,e)).encode())
 if a!=e and len(errors)<30:errors.append({'context':where,'native':a,'expected':e})
def clamp_word(word):
 f=struct.unpack('<f',struct.pack('<I',word))[0]
 return 0 if f<0 else 0x3f800000 if f>1 else word
def material_model(before,current,previous,records,materials,mode,present=True):
 out=bytearray(before)
 if not present or not materials or materials[0]is None:return out
 for i,record in enumerate(records):
  if current[i>>3]==previous[i>>3]:continue
  active=bool(current[i>>3]&(1<<(i&7)));gate=materials[record['material']]
  if gate is not None:active=active and(gate[0]!=255 if mode!=1 else gate[0]==255 or sum(gate)==0)
  out[record['item']*16+1]=0 if active else 1
 return out
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};schedule=json.loads((R/'geometry-scene-scheduling-native-validation.json').read_text());alphaWords=[0xbf800000,0x80000000,0,0x3e800000,0x3f800000,0x40000000,0x7fc12345,0x7f800000,0xff800000]
for sr in schedule['sources']:
 row=index[sr['source']];data=json.loads((B/row['report']).read_text());raw=(B/'extracted'/row['source']).read_bytes();render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];a=render['address'];cursor=BASE;n.write(scene,bytes(0x200));u=lambda q:struct.unpack_from('<I',raw,q)[0]
 def ptr(q):
  d=struct.unpack_from('<i',raw,q)[0];return q+d if d else 0
 commandCount=u(a+4);start=ptr(a+8);baseItems=raw[start:start+commandCount*16];items=alloc(len(baseItems));defs=alloc(len(data['models'])*12);itemCounts=alloc(len(data['models'])*2);alpha=alloc(len(data['models'])*4);matrixAddresses={};matrixBefore={};clipItems=[]
 for i,m in enumerate(data['models']):
  count=render['clipItemCounts'][i];cp=ptr(m['address']+8);indices=[u(cp+j*4)for j in range(count)];clipItems.append(indices);nativeIndices=alloc(count*4);n.pack('<I',defs+i*12+8,nativeIndices);n.pack('<H',itemCounts+i*2,count)
  for j,ix in enumerate(indices):
   if not 1<=ix<commandCount:raise ValueError('Invalid command predecessor')
   n.pack('<I',nativeIndices+j*4,ix);resource=ptr(start+(ix-1)*16+4)
   if baseItems[ix*16]==0x82 and resource not in matrixAddresses:matrixAddresses[resource]=alloc(64);matrixBefore[resource]=raw[resource:resource+64]
 n.pack('<I',scene+8,items);n.pack('<I',scene+0x10,len(clipItems));n.pack('<I',scene+0x14,defs);n.pack('<I',scene+0x18,itemCounts)
 for alphaPresent in [False,True]:
  for pattern in [0,1]:
   before=bytearray(baseItems)
   for ix in range(commandCount):before[ix*16+1]=[0,1,3,255][(ix+pattern)%4]
   n.write(items,before);n.pack('<I',scene+0x68,alpha if alphaPresent else 0);values=[alphaWords[(i+pattern)%len(alphaWords)]for i in range(len(clipItems))];n.pack('<'+'I'*len(values),alpha,*values);expected={p:bytearray(v)for p,v in matrixBefore.items()}
   for resource,address in matrixAddresses.items():n.write(address,matrixBefore[resource])
   for ci,indices in enumerate(clipItems):
    for ix in indices:
     if before[ix*16]!=0x82:continue
     resource=ptr(start+(ix-1)*16+4);n.pack('<I',items+(ix-1)*16+4,matrixAddresses[resource])
     if alphaPresent and before[ix*16+1]:struct.pack_into('<I',expected[resource],60,clamp_word(values[ci]))
   nativeBefore=n.read(items,len(before));n.call(0x5df880,regs={UC_X86_REG_ESI:scene},count=4000000);compare(n.read(items,len(before)),nativeBefore,[row['source'],'alphaItemsUnchanged',alphaPresent,pattern]);counts['authoredAlpha']+=1;counts['commandBytes']+=len(before)
   observed=[]
   for resource,address in matrixAddresses.items():
    actual=n.read(address,64);compare(actual,bytes(expected[resource]),[row['source'],'matrix',resource,alphaPresent,pattern]);observed.append([resource,struct.unpack_from('<I',actual,60)[0]]);counts['alphaMatrixWords']+=16
   cases.append({'kind':'alpha','source':row['source'],'alphaPresent':alphaPresent,'pattern':pattern,'nativeMatrixAlphaWords':observed})
 count=u(a+0x4c);materialTable=ptr(a+0x50);recordTable=ptr(a+0x54);materials=[];records=[];table=alloc(count*4);recordPointers=alloc(count*4);bitCount=(count+7)//8;bits=[alloc(bitCount),alloc(bitCount)]
 for i in range(count):
  material=ptr(materialTable+i*4);gate=list(raw[material+248:material+251])if material else None;materials.append(gate);mp=alloc(708)if material else 0
  if mp:n.write(mp+248,bytes(gate))
  n.pack('<I',table+i*4,mp);record=ptr(recordTable+i*4);target=ptr(record+12);item=(target-start)//16
  if target!=start+item*16 or not 0<=item<commandCount:raise ValueError('Material target is not a command')
  mi=u(record+4);records.append({'material':mi,'item':item});rp=alloc(68);n.pack('<I',recordPointers+i*4,rp);n.pack('<I',rp+4,mi);n.pack('<I',rp+12,items+item*16)
 n.pack('<I',scene+0x4c,count);n.pack('<I',scene+0x50,table);n.pack('<I',scene+0x54,recordPointers);n.pack('<2I',scene+0x58,*bits)
 for parity,mode,equal in itertools.product([0,1],[0,1,2],[False,True]):
  current=bytes((i*57+0xa5)&255 for i in range(bitCount));previous=current if equal else bytes((b^0x5a)if i%2==0 else b for i,b in enumerate(current));n.write(bits[parity],current);n.write(bits[1-parity],previous);n.write(items,baseItems);n.pack('<I',scene+0x74,parity<<15);n.pack('<I',0x2974d1c,mode);n.call(0x5e0bd0,regs={UC_X86_REG_ESI:scene},count=1000000);expected=material_model(baseItems,current,previous,records,materials,mode);actual=n.read(items,len(baseItems));compare(actual,bytes(expected),[row['source'],'materials',parity,mode,equal]);counts['authoredMaterial']+=1;counts['commandBytes']+=len(actual);cases.append({'kind':'material','source':row['source'],'parity':parity,'mode':mode,'equal':equal,'nativeItemSHA256':hashlib.sha256(actual).hexdigest()})
 sources.append({'source':row['source'],'sha256':row['sha256'],'commands':commandCount,'clips':len(clipItems),'materials':count,'matrixTargets':len(matrixAddresses)});print('finish sources',len(sources),'errors',len(errors),flush=True)
 if errors:break

# Synthetic gate triples include all distinct special-mode outcomes plus null
#material entries/first-entry early gate and partial final bytes.
boundary=[];rng=random.Random(0x5e0bd0)
for count,present,firstPresent,mode,parity,equal in itertools.product([0,1,7,8,9,17],[False,True],[False,True],[0,1,2],[0,1],[False,True]):
 cursor=BASE;n.write(scene,bytes(0x200));items=alloc(max(16,count*16));before=bytes([0xcc])*max(16,count*16);n.write(items,before);table=alloc(max(4,count*4));recordPointers=alloc(max(4,count*4));bits=[alloc(max(1,(count+7)//8)),alloc(max(1,(count+7)//8))];materials=[];records=[];palette=[None,[0,0,0],[255,0,0],[1,0,0],[0,255,0],[255,255,255]]
 for i in range(count):
  gate=([0,0,0]if firstPresent else None)if i==0 else palette[i%len(palette)];materials.append(gate);mp=alloc(256)if gate is not None else 0
  if mp:n.write(mp+248,bytes(gate))
  n.pack('<I',table+i*4,mp);rp=alloc(68);n.pack('<I',recordPointers+i*4,rp);n.pack('<I',rp+4,i);n.pack('<I',rp+12,items+i*16);records.append({'material':i,'item':i})
 current=bytes(rng.randrange(256)for _ in range((count+7)//8));previous=current if equal else bytes(b^255 for b in current);n.write(bits[parity],current);n.write(bits[1-parity],previous);n.pack('<I',scene+0x4c,count);n.pack('<I',scene+0x50,table if present else 0);n.pack('<I',scene+0x54,recordPointers);n.pack('<2I',scene+0x58,*bits);n.pack('<I',scene+0x74,parity<<15);n.pack('<I',0x2974d1c,mode);n.call(0x5e0bd0,regs={UC_X86_REG_ESI:scene});expected=material_model(before,current,previous,records,materials,mode,present);actual=n.read(items,len(before));compare(actual,bytes(expected),['boundary',count,present,firstPresent,mode,parity,equal]);counts['materialBoundary']+=1;boundary.append({'count':count,'present':present,'firstPresent':firstPresent,'mode':mode,'parity':parity,'current':current.hex(),'previous':previous.hex(),'nativeItems':actual.hex()})

# Finish orchestration retains real clip/alpha/material patchers. Dynamic list
#flush and sorted packet finalization are explicit observed boundaries here.
finish=[];hooks[0x5de440]=lambda:None;hooks[0x5e0d00]=lambda:None
for registeredCount,pattern in itertools.product([0,1,2,7,256],range(4)):
 n.write(0x973dbc,bytes(0x94));n.pack('<I',0x973fa4,0);n.pack('<I',0x9739b8,registeredCount);records=[]
 for i in range(registeredCount):
  address=n.DATA+0x10000+i*0x200;n.write(address,bytes(0x100));flags=[0,2,4,6][(i+pattern)%4];n.pack('<I',address+0x74,flags);n.pack('<I',0x9739bc+i*4,address);records.append([address,flags])
 stats=[(0xface0000+i*37+pattern)&0xffffffff for i in range(24)];n.pack('<24I',0x973ed4,*stats);n.write(0x973f34,bytes(96));calls.clear();n.call(0x5f0d70,count=2000000);sequence=[(a,s)for a,s in calls];expectedAddresses=['0x5f0d70','0x4ffaa0','0x5de440','0x603920','0x5e0bd0']
 for address,flags in records:
  if flags&4:expectedAddresses+=['0x5df910','0x5df880']
  if flags&6:expectedAddresses+=['0x5e0bd0']
 expectedAddresses+=['0x5e0d00','0x4ffac0'];compare([a for a,s in sequence],expectedAddresses,['finishOrder',registeredCount,pattern]);compare(list(n.unpack('<24I',0x973f34)),stats,['finishStats',registeredCount,pattern]);patched=[(a,s)for a,s in sequence if a in['0x5df910','0x5df880','0x5e0bd0']];expectedRows=[('0x5e0bd0',0x973dbc)]
 for address,flags in records:
  if flags&4:expectedRows +=[('0x5df910',address),('0x5df880',address)]
  if flags&6:expectedRows +=[('0x5e0bd0',address)]
 compare(patched,expectedRows,['finishOwners',registeredCount,pattern]);counts['finish']+=1;finish.append({'registeredCount':registeredCount,'pattern':pattern,'nativeCalls':[a for a,s in sequence],'nativeStats':stats})
report={'schema':'original-static-finish-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'resultSHA256':digest.hexdigest(),'fixtureFile':'geometry-static-finish-fixtures.json.gz','boundaries':{'0x5de440':'Finish-orchestration tests only: recorded no-op boundary for pending dynamic-list updates.','0x5e0d00':'Finish-orchestration tests only: recorded no-op boundary for sorted packet finalization.','0x4ffaa0/0x4ffac0':'Original instructions run with lock handle0, selecting normal no-lock branches.'},'limits':['Alpha and material helper tests run unmodified original instructions with actual authored command/clip/material maps.','NaN and signed-zero alpha words retained; native clamp carries unordered NaN, despite decompiler inequality wording.','Material+f8/f9/fa bytes are named raw gate bytes; broader semantic meaning remains unidentified.','Finish dispatch proved with empty per-scene helper tables and exact register ownership; populated helpers separately exercised on authored data.','Compiled C# execution remains pending; no GPU or full sorted-packet completion claim.']}
(R/'geometry-static-finish-native-validation.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(R/report['fixtureFile'],'wt',encoding='utf8')as f:json.dump({'authored':cases,'materialBoundaries':boundary,'finish':finish},f,separators=(',',':'))
print(json.dumps({k:report[k]for k in ['passed','counts','errors']},indent=2))
if errors:raise SystemExit(1)
