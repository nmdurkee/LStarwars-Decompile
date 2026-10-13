"""Real light/plane producers -> original registry -> original box visibility."""
import ast,json,struct,gzip,hashlib,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';p=B/'tools/geometry-shadow-light-native.py';tree=ast.parse(p.read_text());body=[]
for node in tree.body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='cases'for t in node.targets):break
 body.append(node)
l={'__file__':str(p)};exec(compile(ast.Module(body=body,type_ignores=[]),str(p),'exec'),l);e=l['e'];n=l['n'];x=l['x'];W=x.wide;add=x.add;mul=x.mul;f32=l['f32'];D=n.DATA;SIZE=0x6000;EYE=l['EYE'];TARGET=l['TARGET'];UP=l['UP'];CAM=l['CAM'];CUTS=l['CUTS'];LOW=D+0x300;HIGH=D+0x320;PROJECTION=l['PROJECTION'];VIEW=l['VIEW'];STATE=D+0x1800;CONTEXTS=[D+0x2000+i*0x900 for i in range(4)]
from unicorn.x86_const import UC_X86_REG_ECX
def distance(p,q):
 dot=x.store(add(add(mul(W(p[0]),W(q[0])),mul(W(p[1]),W(q[1]))),mul(W(p[2]),W(q[2]))));return x.store(add(W(dot),W(q[3])))
def box(planes,low,high):return all(any(distance([high[j]if pick[j]else low[j]for j in range(3)],plane)>0 for pick in [(0,0,0),(0,1,0),(1,1,0),(1,0,0),(0,0,1),(0,1,1),(1,1,1),(1,0,1)])for plane in planes)
def mask(image,ctx,low,high):
 count=struct.unpack_from('<i',image,ctx+0x710-D)[0];result=0
 for i in range(count):
  at=ctx+i*0x380;pc=struct.unpack_from('<I',image,at+0x260-D)[0];planes=[struct.unpack_from('<4f',image,at+0x1a0+j*16-D)for j in range(pc)]
  if box(planes,low,high):result|=1<<i
 return result
cases=[];counts=collections.Counter();results=collections.Counter()
def execute(index,low,high,origin,camera):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));pack=lambda b,p,values:struct.pack_into('<'+'f'*len(values),b,p-D,*values);word=lambda b,p,value:struct.pack_into('<I',b,p-D,value&0xffffffff);readword=lambda b,p:struct.unpack_from('<I',b,p-D)[0];pack(before,LOW,low);pack(before,HIGH,high);pack(before,CAM,camera);initialPointers=[0xa0+i*16 for i in range(4)];initialMasks=[0xdead0000+i for i in range(4)];word(before,STATE,0);word(before,STATE+4,0);struct.pack_into('<4I',before,STATE+0x10-D,*initialPointers);struct.pack_into('<4I',before,STATE+0x20-D,*initialMasks);specs=[]
 for j,ctx in enumerate(CONTEXTS):
  enabled=(index>>j)&1;word(before,ctx+0x808,enabled);word(before,ctx+0x824,0);specs.append(dict(context=ctx,eye=[float(j*10+1),float(j*5+20),float(j*3-30)],target=[0.,0.,0.],up=[0.,1.,0.],extents=[-100.,100.,-100.,100.,.1,1000.],cuts=[.1,30.,100.][:2+(index+j)%2]))
 expected=bytearray(before);n.write(D,before);n.pack('<I',0x966384,0);n.pack('<I',0x9715a0,0);n.pack('<4I',0x96d9d0,*initialPointers);n.pack('<4I',0x96e550,*initialMasks);n.pack('<I',0x29a9c48,index&1);n.write(n.STACK,struct.pack('<I',0x12345678)*16384);unknown=[];registered=[];masks=initialMasks.copy();steps=[]
 def compare(stage,ret=None,wanted=None):
  raw=bytearray(n.read(D,SIZE));raw[PROJECTION-D:PROJECTION-D+64]=n.read(e['NATIVE_PROJECTION'],64);raw[VIEW-D:VIEW-D+64]=n.read(e['NATIVE_VIEW'],64);word(raw,STATE,n.unpack('<I',0x966384)[0]);word(raw,STATE+4,n.unpack('<I',0x9715a0)[0]);raw[STATE+0x10-D:STATE+0x20-D]=n.read(0x96d9d0,16);raw[STATE+0x20-D:STATE+0x30-D]=n.read(0x96e550,16);padding=[readword(raw,p+D)for p in unknown]
  for p in unknown:raw[p:p+4]=before[p:p+4]
  if raw!=expected or ret!=wanted:raise AssertionError(dict(index=index,stage=stage,ret=ret,wanted=wanted,offsets=[i for i,(a,b)in enumerate(zip(raw,expected))if a!=b][:20]))
  steps.append(dict(stage=stage,nativeSHA256=hashlib.sha256(raw).hexdigest(),nativeReturn=ret,nativePadding=padding));counts['comparisons']+=1;counts['persistentBytes']+=SIZE
 for spec in specs:
  ctx=spec['context'];eye=spec['eye'];target=spec['target'];up=spec['up'];cuts=spec['cuts'];params=spec['extents']
  for p,values in [(EYE,eye),(TARGET,target),(UP,up),(CUTS,cuts)]:pack(expected,p,values);n.pack('<'+'f'*len(values),p,*values)
  matrix,forward=l['lookat'](eye,target,up);pack(expected,ctx+0x760,eye+[1.]);pack(expected,ctx+0x770,forward+[1.]);pack(expected,ctx+0x780,matrix);pack(expected,ctx+0x7c0,l['orthographic'](params));word(expected,ctx+0x800,0);e['CTX']=ctx;expected,padding,_=e['model'](expected,len(cuts));unknown.extend(padding)
  n.call(0x5952c0,[EYE,TARGET,UP],{UC_X86_REG_ECX:ctx});n.call(0x595360,[struct.unpack('<I',struct.pack('<f',q))[0]for q in params],{UC_X86_REG_ECX:ctx});n.call(0x5e8950,[CAM,CUTS,len(cuts)],{UC_X86_REG_ECX:ctx},count=1000000);n.call(0x5d0560,[ctx]);
  if readword(expected,ctx+0x808):word(expected,ctx+0x824,1);word(expected,STATE+0x10+len(registered)*4,ctx);registered.append(ctx);word(expected,STATE,len(registered));word(expected,STATE+4,0)
  compare('prepare-'+str(len(steps)))
 for k,refresh in enumerate([1,0,-1]):
  endpoints=(low,high)if k<2 else(high,low)
  if refresh:
   masks[:len(registered)]=[mask(expected,ctx,*endpoints)for ctx in registered];struct.pack_into('<4I',expected,STATE+0x20-D,*masks);word(expected,STATE+4,1)
  wanted=int(any(0<value<0x80000000 for value in masks[:len(registered)]));ret=n.call(0x5ea6a0,[0xdead1111 if k==1 else(LOW if k==0 else HIGH),0xdead2222 if k==1 else(HIGH if k==0 else LOW),refresh&0xffffffff],count=1000000);compare('evaluate-'+str(k),ret,wanted);results[wanted]+=1
 n.call(0x5d05b0)
 for ctx in registered:word(expected,ctx+0x824,0)
 word(expected,STATE,0);word(expected,STATE+4,0);compare('reset');counts['cases']+=1;counts['contextsProduced']+=4;counts['volumesProduced']+=6;cases.append(dict(index=index,before=bytes(before).hex(),source=origin,specifications=specs,steps=steps,undefinedWordOffsets=unknown))
cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';authored=json.loads((B/cp).read_text());matrices=[r['matrix']for r in authored['cameras']['cameras']];portals=json.loads((R/'geometry-portal-predicate-fixtures.json').read_text())['portals']
for i,p in enumerate(portals):
 low=[min(v[j]for v in p['vertices'])for j in range(3)];high=[max(v[j]for v in p['vertices'])for j in range(3)];execute(i,low,high,dict(source=p['source'],portal=p['index']),matrices[i%6]+[1.,1.3333333730697632,.1,1000.])
fp=R/'geometry-shadow-visibility-chain-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,eye=EYE,target=TARGET,up=UP,camera=CAM,cuts=CUTS,low=LOW,high=HIGH,state=STATE,projection=PROJECTION,view=VIEW,cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(l['v']['ns']['TABLE']).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-visibility-chain-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),visibilityResults=dict(results),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Sequential original light setup5952c0,orthographic595360,extraction5e8950,registration5d0560,evaluation5ea6a0 andreset5d05b0 all execute actual nested code with no computational replacements.','All326 authored portal vertex bounds are probes, not claimed runtime object boxes. Six authored CU2 camera transforms, controlled fourlight contexts; all16 enabled-context masks exercised.','Eachscenario captures four preparation states, refreshed evaluation, cached evaluation with invalidendpoint pointers proving no read, reversed-endpoint refreshed evaluation, andreset preserving slots/masks.','Only proven farW/positionW padding normalized; every original padding word retained at each comparison. Registryglobals are mirrored explicitly into fixture image.','Supporting composition adds no native address credit. It does not claim the original full-frame call sequence or actual shadow packets/GPU output. Managed runtime equality pending.']);(R/'geometry-shadow-visibility-chain-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
