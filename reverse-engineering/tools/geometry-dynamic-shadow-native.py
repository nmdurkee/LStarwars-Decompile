"""Original full5f0f00 normal/shadow scheduling with actual visibility/writers."""
import ast,json,gzip,struct,hashlib,base64,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/geometry-dynamic-submission-native.py';tree=ast.parse(path.read_text());stop=next(i for i,node in enumerate(tree.body)if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='index'for v in node.targets));ns={'__file__':str(path)};exec(compile(ast.Module(body=tree.body[:stop],type_ignores=[]),str(path),'exec'),ns)
n=ns['n'];D=n.DATA;SIZE=0x100000;ns['SIZE']=SIZE;u=ns['u'];w=ns['w'];f32=ns['f32'];floats=ns['floats'];storefloats=ns['storefloats'];x=ns['x87'];MASKS=D+0x6c00;DESCRIPTOR=D+0x6a00;CONTEXTS=[D+0x10000,D+0x30000,D+0x50000];normalRecords=set(ns['records']);observedRecords=[];calls=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI
def observe(mu,address,size,user):
 calls.append(address)
 if address==0x5e0530:observedRecords.append(mu.reg_read(UC_X86_REG_ESI))
for address in [0x5ea6a0,0x5c7050,0x5c6dc0,0x607820,0x5e0530]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def planeDistance(point,plane):
 v=x.store(x.add(x.add(x.mul(x.wide(point[0]),x.wide(plane[0])),x.mul(x.wide(point[1]),x.wide(plane[1]))),x.mul(x.wide(point[2]),x.wide(plane[2]))));return x.store(x.add(x.wide(v),x.wide(plane[3])))
def secondary(b,o,first,second,flag):
 masks=[u(b,MASKS+i*4)for i in range(len(o['initialMasks']))]
 if flag:return int(any(0<v<0x80000000 for v in masks[:o['shadowCount']])),flag
 for ci,context in enumerate(o['shadowContexts'][:o['shadowCount']]):
  mask=0
  for vi in range(u(b,context+0x710)):
   planes=[floats(b,context+vi*0x380+0x1a0+pi*16,4)for pi in range(u(b,context+vi*0x380+0x260))];accepted=True
   for plane in planes:
    if not any(planeDistance([second[k]if q[k]else first[k]for k in range(3)],plane)>0 for q in [(0,0,0),(0,1,0),(1,1,0),(1,0,0),(0,0,1),(0,1,1),(1,1,1),(1,0,1)]):accepted=False;break
   if accepted:mask|=1<<(vi&31)
  masks[ci]=mask;w(b,MASKS+ci*4,mask)
 return int(any(0<v<0x80000000 for v in masks[:o['shadowCount']])),1
def shadowShader(b,record,shader,control,descriptor):
 if not shader or u(b,u(b,record+8)+0x20)==u(b,shader+0x20):return
 ctx=u(b,record+8)
 if ns['ss']['hh'](b,ctx+0x30)!=ns['ss']['hh'](b,shader+0x30):
  p=ns['ss']['payload'](b,0x5fcfd0,shader,control,descriptor)
  if p:ns['ss']['append'](b,control,record,0xa9,p)
  ns['ss']['wh'](b,ctx+0x30,ns['ss']['hh'](b,shader+0x30))
 w(b,ctx+0x20,u(b,shader+0x20))
expectedRecords=[]
def model(before,o):
 b=bytearray(before);result=0;draws=[];flag=o['shadowMask'];h=o['handle'];expectedRecords.clear()
 if not h:return b,result,flag,draws
 sp=u(b,h+8);mat=floats(b,o['matrix'],16);minimum=floats(b,sp+0x80,3);maximum=floats(b,sp+0x90,3);result=o['forcedVisibility']
 if result==-1:
  result,cm,points,far=ns['bs']['classify'](minimum,maximum,mat,o['view'],o['near'],o['far'],o['farOverride'],0.,o['sx'],o['sy'],o['enabled'])
  if o['enabled']:storefloats(b,ns['combined'],cm);storefloats(b,ns['farLanes'],far)
 owner=u(b,u(b,h)+0x110);instance=u(b,sp+0xc0);instanceFlags=b[u(b,owner+0x48)-D+instance];prior=0;shadowVisible=0
 if instanceFlags&0x20 and o['shadowCount']>0:
  prior=flag;shadowVisible,flag=secondary(b,o,ns['bs']['points'](minimum,mat),ns['bs']['points'](maximum,mat),flag)
 if result==0 and shadowVisible==0:return b,0,flag,draws
 center=ns['bs']['points']([f32(f32(a+c)*.5)for a,c in zip(minimum,maximum)],mat);diff=[f32(a-c)for a,c in zip(center,o['camera'])];wide=x.wide(0)
 for v in diff:wide=x.add(wide,x.mul(x.wide(v),x.wide(v)))
 distance=x.store(wide);tp=u(b,sp+0xbc);lod=0
 if floats(b,tp,1)[0]!=0:
  if o['forcedLod']==0:
   while distance<floats(b,tp+lod*4,1)[0]:lod+=1
  else:
   while floats(b,tp+lod*4,1)[0]!=0 and lod!=o['forcedLod']:lod+=1
 modelAddress=u(b,sp+0xb0)+lod*12;w(b,ns['cache'],0)
 def packet(record,material,ci,metadata):
  cmd=u(b,owner+8)+ci*16;prefix=bool(u(b,material+0xb4)&0x80000000 and ci>1 and b[cmd-D-32]in [0xb0,0xae,0xaf]);args=[ns['control'],record,cmd,o['matrix'],ns['cache'],ns['output'],ns['scale'],ns['translation'],0x3f800000,metadata];b[:],unused,trace=ns['os']['evaluate']('prefix'if prefix else'ordinary',b,args,o['uv']);draws.append([material,ci,0x5e02b0 if prefix else 0x5e0200]);expectedRecords.append(record)
 for part in range(u(b,modelAddress)):
  source=u(b,u(b,owner+0x50)+u(b,u(b,modelAddress+4)+part*4)*4);tag=b[source-D+0x9a];replacement=o['globalOverride']if not o['overrideTable']or tag==0 else u(b,o['overrideTable']+tag*4);material=replacement or source
  while material:
   gate=list(b[material-D+248:material-D+251]);accepted=(gate[0]==255 or sum(gate)==0)if o['filterMode']==1 else gate[0]!=255
   if accepted:
    ci=u(b,u(b,modelAddress+8)+part*4)
    if result:
     record=u(b,material+0x3c);mo=u(b,record);mi=u(b,record+4);of=u(b,mo+0x74)|2;w(b,mo+0x74,of);p=u(b,mo+0x58+((of>>15)&1)*4)+mi//8;b[p-D]|=1<<(mi&7);b[:],unused=ns['ds']['model']('override',b,[ns['shader'],o['overrideFirst'],0,o['overrideScalarWord'],0,material]);b[:],trace=ns['ss']['emit'](b,record,ns['shader'],ns['control'],o['descriptor'],0x12345678);packet(record,material,ci,int(bool(instanceFlags&0x20)and not o['shadowMetadataDisabled']))
    shadowClass=(u(b,material+0x40)>>14)&3
    if shadowVisible and not o['shadowMetadataDisabled']and shadowClass not in [1,3]:
     for contextIndex,context in enumerate(o['shadowContexts'][:o['shadowCount']]):
      mask=u(b,MASKS+contextIndex*4)if flag else 0xffffffff
      for vi in range(u(b,context+0x710)):
       if mask>>(vi&31)&1:
        record=context+vi*0x380+0x2a4+(0x44 if b[material-D+0x268]else 0);w(b,record,owner);b[:],unused=ns['ds']['model']('reserve',b,[ns['control'],record,1]);p=u(b,record+0x24);b[p-D]=0x80;b[p-D+1]=3;w(b,p+4,material);w(b,record+0x24,p+16);shadowShader(b,record,ns['shader'],ns['control'],o['descriptor']);packet(record,material,ci,1)
   material=u(b,material+0x30)
 b[:],unused=ns['ds']['model']('override',b,[ns['shader'],0,0,0,0,0]);return b,result,flag if prior else 0,draws
ns['model']=model;ns['base64']=base64
runNode=next(v for v in tree.body if isinstance(v,ast.FunctionDef)and v.name=='run');text=ast.get_source_segment(path.read_text(),runNode);text=text.replace('(0x966384,0)',"(0x966384,o['shadowCount'])").replace('(0x9738a4,0)',"(0x9738a4,o['descriptor'])").replace('actual=bytearray(n.read(BASE,SIZE))',"actual=bytearray(n.read(BASE,SIZE));actual[MASKS-BASE:MASKS-BASE+len(o['initialMasks'])*4]=n.read(0x96e550,len(o['initialMasks'])*4)").replace("'before':bytes(before).hex(),","'beforeZ':base64.b64encode(gzip.compress(bytes(before),mtime=0)).decode(),");ns['MASKS']=MASKS;exec(compile(text,'shadow-normal-run','exec'),ns)
normalRows=[r for r in json.loads(gzip.decompress((R/'geometry-dynamic-submission-fixtures.json.gz').read_bytes()))['cases']if r['label'][0]!='synthetic'and r['label'][2]==1];portals=json.loads((R/'geometry-portal-predicate-fixtures.json').read_text())['portals'];counts=collections.Counter();proofs=[]
def execute(row,index,contextCounts,flag,visible,pattern=0):
 old=bytes.fromhex(row['before']);minimum=list(struct.unpack_from('<3f',old,0x680));maximum=list(struct.unpack_from('<3f',old,0x690));matrix=list(struct.unpack_from('<16f',old,0x700));thresholds=[]
 for j in range(64):
  v=struct.unpack_from('<f',old,0x800+j*4)[0];thresholds.append(v)
  if v==0:break
 before,o=ns['setup'](minimum,maximum,matrix,thresholds,index,visible);w(before,ns['control'],D+0x80000+(index&15));before[ns['flags']-D+3]=0x20 if index%13!=0 else 0;o['shadowMetadataDisabled']=int(index%17==0);o['shadowMask']=flag;o.update(shadowCount=len(contextCounts),shadowContexts=CONTEXTS[:len(contextCounts)],initialMasks=[0,1,0x80000000,0xffffffff,0x7fffffff,2,0xa5a5a5a5,0xdeadbeef],descriptor=DESCRIPTOR if index&1 else 0);before[DESCRIPTOR-D]=[0,1,3,255][index%4];before[DESCRIPTOR-D+2]=index&255;w(before,DESCRIPTOR+4,DESCRIPTOR+32);before[DESCRIPTOR-D+32:DESCRIPTOR-D+288]=bytes((j*11+index)&255 for j in range(256))
 for i,m in enumerate(ns['materials']):w(before,m+0x40,((i+index)%4)<<14);before[m-D+0x268]=(i+index)&1
 cache=D+0x70000
 for ci,vc in enumerate(contextCounts):
  context=CONTEXTS[ci];before[context-D:context-D+0x20000]=bytes(0x20000);w(before,context+0x710,vc)
  for vi in range(vc):
   planes=[]if pattern==1 or vi%4==0 else [[0.,0.,0.,-1.]]if pattern==2 or vi%4==1 else [portals[(index+vi)%len(portals)]['plane']]
   w(before,context+vi*0x380+0x260,len(planes))
   for pi,plane in enumerate(planes):storefloats(before,context+vi*0x380+0x1a0+pi*16,plane)
   for alternate in [0,1]:
    record=context+vi*0x380+0x2a4+alternate*0x44;w(before,record,0x12345678);w(before,record+4,0);w(before,record+8,cache);w(before,record+0x14,cache+0x40);w(before,record+0x18,cache+0x60);w(before,cache+0x20,index^0xffffffff);struct.pack_into('<H',before,cache-D+0x30,(index+vi+alternate)&65535);cache+=0x100
 if flag:
  for i in range(len(contextCounts)):o['initialMasks'][i]=[0,1,0x80000000,0xffffffff,0x7fffffff,2][(index+i)%6]
 for i,v in enumerate(o['initialMasks']):w(before,MASKS+i*4,v)
 for i,p in enumerate(o['shadowContexts']):n.pack('<I',0x96d9d0+i*4,p)
 n.pack('<8I',0x96e550,*o['initialMasks']);calls.clear();observedRecords.clear();ns['run'](before,o,['shadow',index,contextCounts,flag,visible]);case=ns['cases'][-1];case.update(sourceObject=row['label'],nativeRecords=observedRecords.copy(),portalPlaneProbe={'source':portals[index%len(portals)]['source'],'index':portals[index%len(portals)]['index']});counts['cases']+=1;counts['secondary']+=calls.count(0x5ea6a0);counts['volumeTests']+=calls.count(0x5c6dc0);counts['shadowShader']+=calls.count(0x607820);counts['shadowPackets']+=sum(p not in normalRecords for p in observedRecords);counts['normalPackets']+=sum(p in normalRecords for p in observedRecords);counts['shadowOnlyCases']+=int(case['nativeReturn']==0 and bool(observedRecords))
 if observedRecords!=expectedRecords:raise AssertionError(['record order',observedRecords,expectedRecords])
 if ns['errors']:raise AssertionError(ns['errors'][:3])
for i,row in enumerate(normalRows):
 for mode in [0,1]:execute(row,i*2+mode,[4,3]if i%3 else[4],0 if mode==0 else[1,0x80000000,0xffffffff][i%3],[-1,0,1,2][(i+mode)%4])
 if i%100==0:print('shadow objects',i,'errors',len(ns['errors']),flush=True)
for i in range(64):execute(normalRows[i],2000+i,[0]if i%4==0 else[32,1]if i%4==1 else[33]if i%4==2 else[],0 if i&1 else 1,0 if i%3==0 else 1,1 if i&2 else 2)
fp=R/'geometry-dynamic-shadow-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(cases=ns['cases'],maskMirror=MASKS),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-dynamic-shadow-native-v1',passed=not ns['errors'],binarySHA256=n.sha256,counts=dict(counts),normalCounts=ns['counts'],sourceObjects=len(normalRows),sources=len(set(r['label'][0]for r in normalRows)),errors=ns['errors'],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Full original5f0f00 normal/shadow path with actual5ea6a0/5c7050/5c6dc0 visibility, signed cached masks, both shader emitters, allocator and ordinary/prefix writers. Observation hooks only.','480 authored local bounds/world/LOD objects across60scenes, controlled relocated material/shadow-context records. Authored portal planes probe secondary math; no claim of shipped shadow-volume construction.','Zero sway/fade, null skin/morph, same-layout overrides, finite scalar arithmetic and successful disjoint capacities. Context count0..2, volume count0..33 includes modulo32 mask shifts and signed bit31 aggregate.','Whole1MiB persistent image compared including mirrored mask array/shader/bounds/scratch state, excluding established32-byte cache/output adapter. Exact writer and packet-record ordering checked.','Shadow-only packets may be emitted while the original return remains0; cleanup of9715a0 depends on captured incoming cache flag. GPU consumption and managed runtime equality remain separate.']);(R/'geometry-dynamic-shadow-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not ns['errors']
