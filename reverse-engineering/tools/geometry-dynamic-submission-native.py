"""Unmodified normal5f0f00 through scalar bounds, shader and ordinary packets."""
import ast,importlib.util,json,struct,gzip,hashlib,math
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def mod(name,path):
 s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=mod('nx',B/'tools/native-x86.py');x87=mod('x87',B/'tools/animation-x87.py');n=nx.NativeX86();BASE=n.DATA;SIZE=0x10000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
def funcs(file,names,scope):
 for node in ast.parse((B/'tools'/file).read_text()).body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),file,'exec'),scope)
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
IDENTITY=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.]
ds={'BASE':BASE,'struct':struct};funcs('geometry-dynamic-command-native.py',{'u','w','quiet','alpha','model'},ds);u=ds['u'];w=ds['w']
os={'BASE':BASE,'struct':struct,'u':u,'w':w,'ns':ds};funcs('geometry-ordinary-packets-native.py',{'transpose','matrix','evaluate'},os)
ss={'BASE':BASE,'struct':struct};funcs('geometry-shader-emission-native.py',{'u','w','hh','wh','align','payload','append','emit'},ss)
bs={'x87':x87,'IDENTITY':IDENTITY};funcs('geometry-dynamic-bounds-native.py',{'dot','mul','points','classify'},bs)
control=BASE;handle=BASE+0x100;header=BASE+0x200;owner=BASE+0x400;special=BASE+0x600;matrix=BASE+0x700;threshold=BASE+0x800;models=BASE+0x900;items=BASE+0xd00;table=BASE+0x1000;flags=BASE+0x1100;bitset=BASE+0x1200;overrides=BASE+0x1300;materials=[BASE+0x2000+0x400*i for i in range(6)];records=[BASE+0x4000+0x100*i for i in range(6)];shader=BASE+0x6000;scale=BASE+0x6200;translation=BASE+0x6240;cache=BASE+0x6300;output=BASE+0x6310;combined=BASE+0x6400;farLanes=BASE+0x6440
draws=[];writers=[];calls=[];cases=[];errors=[];sources=[];counts={'cases':0,'authoredSpecials':0,'checkedBytes':0,'draws':0,'ordinary':0,'prefix':0,'bounds':0,'shaderEmissions':0,'earlyReturns':0};classes={}
def observe(mu,address,size,_):
 calls.append(address)
 if address==0x5e0530:
  sp=mu.reg_read(UC_X86_REG_ESP);draws.append(list(n.unpack('<2I',sp+4)))
 if address in[0x5e0200,0x5e02b0]:writers.append(address)
for a in[0x6042e0,0x5fd220,0x607590,0x5e0530,0x5e0200,0x5e02b0,0x603530,0x603580,0x6034b0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def floats(b,p,count):return list(struct.unpack_from('<'+'f'*count,b,p-BASE))
def storefloats(b,p,values):struct.pack_into('<'+'f'*len(values),b,p-BASE,*values)
def setup(minimum,maximum,transform,thresholds,index,visible):
 b=bytearray(SIZE)
 for i in range(0x8000,SIZE):b[i]=(i*37+index*17)&255
 for p,value in[(control,BASE+0x8000+(index&15)),(handle,header),(handle+8,special),(header+0x110,owner),(special+0xb0,models),(special+0xbc,threshold),(special+0xc0,3),(owner+8,items),(owner+0x48,flags),(owner+0x50,table),(owner+0x58,bitset),(owner+0x5c,bitset+16),(owner+0x74,0x8000 if index&1 else 0)]:w(b,p,value)
 storefloats(b,special+0x80,minimum);storefloats(b,special+0x90,maximum);storefloats(b,matrix,transform);storefloats(b,threshold,thresholds)
 for li in range(len(thresholds)):
  pair=BASE+0xb00+li*32
  for p,value in[(models+li*12,2),(models+li*12+4,pair),(models+li*12+8,pair+8),(pair,0),(pair+4,1),(pair+8,4),(pair+12,8)]:w(b,p,value)
 for i,material in enumerate(materials):
  record=records[i];ctx=BASE+0x5000+i*0x200
  for p,value in[(table+i*4,material),(material+0x3c,record),(material+0x1f0,7),(material+0xb4,0x80000000 if(i+index)&1 else 0),(record,owner),(record+4,i),(record+8,ctx),(record+0x14,record+0x80),(record+0x18,record+0x90)]:w(b,p,value)
  gates=[[0,0,0],[0,1,0],[255,0,0],[1,0,0],[0,0,0],[255,255,255]][(i+index)%6];b[material-BASE+248:material-BASE+251]=bytes(gates)
  for j,key in enumerate([0x24,0x2c,0x2e,0x1e,0x32,0x30]):struct.pack_into('<H',b,ctx-BASE+key,((index>>(j%4))&1)^1)
 for p,value in[(materials[0]+0x30,materials[3]),(materials[1]+0x30,materials[4])]:w(b,p,value)
 for ci in[4,8]:b[items-BASE+ci*16]=0x82;w(b,items+ci*16+4,BASE+0x7800+ci*16);b[items-BASE+(ci-2)*16]=[0xb0,0xae,0xaf][index%3];w(b,items+(ci-2)*16+4,0xabc00000+ci)
 b[flags-BASE+3]=0x20 if index&2 else 0;w(b,overrides+7*4,materials[2]if index&4 else 0);b[materials[0]-BASE+0x9a]=7 if index&8 else 0
 w(b,shader+0x20,0xffffffff if index&16 else index);struct.pack_into('<H',b,shader-BASE+0x1e,65535 if index&16 else index)
 for j,key in enumerate([0x24,0x2c,0x2e,0x32,0x30]):struct.pack_into('<H',b,shader-BASE+key,(index>>(j%4))&1)
 w(b,shader+0x16c,index&1);w(b,shader+0x194,0x12345678)
 storefloats(b,combined,[i*.25-2 for i in range(16)]);storefloats(b,farLanes,[-3,-2,-1,0])
 opt={'handle':handle,'matrix':matrix,'forcedVisibility':visible,'forcedLod':[0,1,-1][index%3],'filterMode':index%3,'shadowMask':0xabcdef01,'shadowMetadataDisabled':int(bool(index&32)),'globalOverride':materials[5]if index&64 else 0,'overrideTable':overrides if index&128 else 0,'overrideFirst':index&1,'overrideScalarWord':bits(.25),'uv':[bits(.5),bits(2.),0x80000000,bits(-1.)],'camera':[0.,0.,0.],'view':IDENTITY,'near':f32(.1),'far':1000.,'farOverride':0.,'sx':1.,'sy':.75,'enabled':1}
 return b,opt
def model(before,o):
 b=bytearray(before);result=0;emitted=[];shadow=o['shadowMask'];h=o['handle']
 if not h:return b,result,shadow,emitted
 sp=u(b,h+8);mat=floats(b,o['matrix'],16);minimum=floats(b,sp+0x80,3);maximum=floats(b,sp+0x90,3)
 result=o['forcedVisibility']
 if result==-1:
  result,cm,points,far=bs['classify'](minimum,maximum,mat,o['view'],o['near'],o['far'],o['farOverride'],0.,o['sx'],o['sy'],o['enabled'])
  if o['enabled']:storefloats(b,combined,cm);storefloats(b,farLanes,far)
 if result==0:return b,result,shadow,emitted
 center=[f32(f32(a+c)*.5)for a,c in zip(minimum,maximum)];center=bs['points'](center,mat);diff=[f32(a-c)for a,c in zip(center,o['camera'])];dist=x87.wide(0)
 for d in diff:dist=x87.add(dist,x87.mul(x87.wide(d),x87.wide(d)))
 distance=x87.store(dist);tp=u(b,sp+0xbc);lod=0
 if floats(b,tp,1)[0]!=0:
  if o['forcedLod']==0:
   while distance<floats(b,tp+lod*4,1)[0]:lod+=1
  else:
   while floats(b,tp+lod*4,1)[0]!=0 and lod!=o['forcedLod']:lod+=1
 modelAddress=u(b,sp+0xb0)+lod*12;w(b,cache,0)
 for part in range(u(b,modelAddress)):
  source=u(b,table+u(b,u(b,modelAddress+4)+part*4)*4);tag=b[source-BASE+0x9a];replacement=o['globalOverride']if not o['overrideTable']or tag==0 else u(b,o['overrideTable']+tag*4);material=replacement or source
  while material:
   gate=list(b[material-BASE+248:material-BASE+251]);accepted=(gate[0]==255 or sum(gate)==0)if o['filterMode']==1 else gate[0]!=255
   if accepted:
    record=u(b,material+0x3c);own=u(b,record);mi=u(b,record+4);of=u(b,own+0x74)|2;w(b,own+0x74,of);bp=u(b,own+0x58+((of>>15)&1)*4)+mi//8;b[bp-BASE]|=1<<(mi&7)
    updated,_=ds['model']('override',b,[shader,o['overrideFirst'],0,o['overrideScalarWord'],0,material]);b[:]=updated;b[:],trace=ss['emit'](b,record,shader,control,0,0x12345678)
    ci=u(b,u(b,modelAddress+8)+part*4);cmd=items+ci*16;prefix=bool(u(b,material+0xb4)&0x80000000 and ci>1 and b[cmd-BASE-32]in[0xb0,0xae,0xaf]);meta=int(bool(b[flags-BASE+3]&0x20)and not o['shadowMetadataDisabled']);args=[control,record,cmd,o['matrix'],cache,output,scale,translation,0x3f800000,meta];b[:],ret,trace=os['evaluate']('prefix'if prefix else'ordinary',b,args,o['uv']);emitted.append([material,ci,0x5e02b0 if prefix else 0x5e0200])
   material=u(b,material+0x30)
 b[:],_=ds['model']('override',b,[shader,0,0,0,0,0]);shadow=0;return b,result,shadow,emitted
def run(before,o,label):
 expected,ret,shadow,expectedDraws=model(before,o);n.write(BASE,before);n.write(0x9868a0,before[shader-BASE:shader-BASE+420]);n.write(0x2857230,before[scale-BASE:scale-BASE+64]);n.write(0x28571f0,before[translation-BASE:translation-BASE+64]);n.write(0x280c480,before[combined-BASE:combined-BASE+64]);n.write(0x80e8f0,before[farLanes-BASE:farLanes-BASE+16])
 for p,value in[(0x806ccc,o['forcedVisibility']),(0x966384,0),(0x9738ec,o['forcedLod']),(0x9738f0,o['globalOverride']),(0x9738f4,o['overrideTable']),(0x9738a8,o['shadowMetadataDisabled']),(0x9715a0,o['shadowMask']),(0x2974d1c,o['filterMode']),(0x973890,o['overrideFirst']),(0x973894,0),(0x806b9c,o['overrideScalarWord']),(0x9736e0,control),(0x9738a4,0),(0x297dc00,0x12345678),(0x80e85c,o['enabled']),(0x297c0d0,0)]:n.pack('<I',p,value&0xffffffff)
 n.pack('<4I',0x80e258,*o['uv']);n.pack('<3f',0x973718,*o['camera']);n.pack('<16f',0x80b708,*o['view']);n.pack('<2f',0x973730,o['near'],o['far']);n.pack('<f',0x97374c,o['farOverride']);n.pack('<f',0x966378,o['sx']);n.pack('<f',0x97313c,o['sy']);draws.clear();writers.clear();calls.clear();actualRet=n.call(0x5f0f00,args=[o['handle'],o['matrix'],0xfeedface,0,0],count=500000);actual=bytearray(n.read(BASE,SIZE))
 for dst,src,size in[(shader,0x9868a0,420),(scale,0x2857230,64),(translation,0x28571f0,64),(combined,0x280c480,64),(farLanes,0x80e8f0,16)]:actual[dst-BASE:dst-BASE+size]=n.read(src,size)
 # Native cache/output live on its transient stack; portable scratch adapters
 # occupy this explicit window. Compare every persistent byte outside it.
 actual[cache-BASE:cache-BASE+32]=bytes(32);expected[cache-BASE:cache-BASE+32]=bytes(32)
 actualShadow=n.unpack('<I',0x9715a0)[0];actualDraws=[d+[writer]for d,writer in zip(draws,writers)]
 for field,a,e in[('memory',bytes(actual),bytes(expected)),('return',actualRet,ret&0xffffffff),('shadowMask',actualShadow,shadow),('draws',actualDraws,expectedDraws)]:
  if a!=e and len(errors)<20:errors.append({'label':label,'field':field,'actual':a if field!='memory'else None,'expected':e if field!='memory'else None,'offsets':[i for i,(v,x)in enumerate(zip(a,e))if v!=x][:20]if field=='memory'else None})
 counts['cases']+=1;counts['checkedBytes']+=SIZE-32;counts['draws']+=len(draws);counts['ordinary']+=writers.count(0x5e0200);counts['prefix']+=writers.count(0x5e02b0);counts['bounds']+=calls.count(0x6042e0);counts['shaderEmissions']+=calls.count(0x607590);counts['earlyReturns']+=int(0x5fd220 not in calls);classes[actualRet]=classes.get(actualRet,0)+1;cases.append({'label':label,'before':bytes(before).hex(),'options':o,'nativeReturn':actualRet,'nativeShadowMask':actualShadow,'nativeDraws':actualDraws,'nativeSHA256':hashlib.sha256(actual).hexdigest()})
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/index[sr['source']]['report']).read_text());specials=data['specialObjects'];indices=sorted(set(int(i*(len(specials)-1)/7)for i in range(8)))if specials else[]
 for ii in indices:
  p=specials[ii]['address'];minimum=list(struct.unpack_from('<3f',raw,p+0x80));maximum=list(struct.unpack_from('<3f',raw,p+0x90));mat=list(struct.unpack_from('<16f',raw,p+64));tp=p+0xbc+struct.unpack_from('<i',raw,p+0xbc)[0];thresholds=[]
  for i in range(64):
   thresholds.append(struct.unpack_from('<f',raw,tp+i*4)[0])
   if thresholds[-1]==0:break
  else:raise ValueError('Authored LOD bound')
  if not all(math.isfinite(v)for v in minimum+maximum+mat+thresholds):raise ValueError('Nonfinite authored math')
  for visible in[-1,0,1]:b,o=setup(minimum,maximum,mat,thresholds,si*8+ii,visible);run(b,o,[sr['source'],ii,visible])
  counts['authoredSpecials']+=1
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'specialIndices':indices})
 if(si+1)%10==0:print('normal sources',si+1,'errors',len(errors),flush=True)
 if errors:break
for i in range(128):
 b,o=setup([-1.,-1.,4.],[1.,1.,6.],IDENTITY,[100.,25.,0.],i,[-1,1,2,-2][i%4]);o['camera']=[1.,2**-12,2**-27]if i&4 else[0.,0.,0.]
 if i%16==0:o['handle']=0
 if i%16==1:w(b,models,0);w(b,models+12,0);w(b,models+24,0)
 if i%16==2:o['enabled']=0
 run(b,o,['synthetic',i])
fp=R/'geometry-dynamic-submission-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-submission-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'returnClasses':classes,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['All original caller and nested scalar bounds, center/distance, override, shader, ordinary/prefix writer helpers execute unchanged. Observation hooks only.','Authored local bounds, transforms and LOD thresholds combined with controlled relocated runtime material/control/packet images; not a captured live frame.','Normal zero-shadow, zero-sway, inactive-fade, null skin/morph input path. Same-layout overrides only; clone/cache and billboard excluded.','Every persistent compact-image byte compared; explicit32-byte portable stack-scratch adapter excluded. Native globals shader/scratch/bounds mirrored into compact image after execution.','Finite math; nonnegative bounded material indexes, terminated LOD lists and acyclic material chains. SIMD clipping and GPU backend excluded.','No managed executable or game process launched.']};(R/'geometry-dynamic-submission-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','returnClasses','errors','fixtureBytes']}));raise SystemExit(bool(errors))
