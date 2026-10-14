"""Whole original6e3940 caller with actual mode/cache/reset/viewport CPU children.
Resource lifecycle graphs remain named explicit adapters; no host operations."""
import importlib.util,struct,json,gzip,random,copy,ast
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase15-20261013-device-bootstrap'
def load(name,file):
 q=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(q);q.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86();W=x87.wide;A=x87.add;M=x87.mul;D=x87.div;S=x87.store;sub=lambda a,b:A(a,(-b[0],b[1]));f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];words=lambda v:[word(a)for a in v];i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
for file,names in [('scene-phase11-20261013-refresh-native.py',['trunc','position','physical','extent','setup','inputs','seed']),('scene-phase5-20261013-viewport-native.py',['readViewport','modelReset','auxiliary']),('scene-phase14-20261013-target-reset-native.py',['maximum','modelTarget','modelViewport','modelRefresh','modelResetConsumer']),('scene-phase14-20261013-mode-selection-native.py',['distance','select','classify'])]:
 t=ast.parse((P/file).read_text());defs=[v for v in t.body if isinstance(v,ast.FunctionDef)and v.name in names];exec(compile(ast.Module(body=defs,type_ignores=[]),file,'exec'))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
GLOBAL=0x29765c8;CACHE=0x297bea0;MARKERS=0x97f998;SETTINGS=0x826070;TABLE=n.DATA+0x7000;D3D=n.DATA+0x1000;D3DVT=n.DATA+0x2000;DEVICEA=n.DATA+0x3000;VTA=n.DATA+0x4000;DEVICEB=n.DATA+0x5000;VTB=n.DATA+0x6000
identity=list(n.unpack('<16f',0x806680));vendorRecords=n.read(0x8283e8,0x10c0);vids=[struct.unpack_from('<I',vendorRecords,i*16)[0]for i in range(267)];targets=[n.unpack('<d',a)[0]for a in [0x75d168,0x776f48,0x76f8b0]];rng=random.Random(0x6e394015);checks=0;errors=[];cases=[];events=[];scenario={};sourcePointer=None;creating=0;qualityCall=0
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v&0xffffffff)
EDGES={};offsetCounter=0
for kind,device,vt,offsets in [('d3d',D3D,D3DVT,{0x38:3,0x24:5,0x14:3,0x2c:6,0x40:6}),('device',DEVICEA,VTA,{0xc:0,0x14:0,0x40:1,0x1c:1,0x94:2,0x9c:1,0xbc:1,0xac:6,0x44:4,0x114:3,0x134:1,0xe4:2})]:
 n.pack('<I',device,vt)
 for offset,count in offsets.items():
  edge=n.STOP+0x100+offsetCounter*16;offsetCounter+=1;EDGES[edge]=(kind,offset,count);n.pack('<I',vt+offset,edge)
  if kind=='device':n.pack('<I',VTB+offset,edge)
n.pack('<I',DEVICEB,VTB)
for i,(iat,kind,count)in enumerate([(0x751264,'window',6),(0x7510ac,'sleep',1),(0x75128c,'message',4),(0x7510b8,'enter',1),(0x7510b4,'exit',1)]):
 edge=n.STOP+0x500+i*16;EDGES[edge]=(kind,0,count);n.pack('<I',iat,edge)
LOSS=n.STOP+0x600;EDGES[LOSS]=('loss',0,1)
RESOURCE_EDGES={0x6df0e0:'release',0x6dfe20:'rebuild',0x6e2d20:'resources',0x6e0080:'error',0x6e8b9e:'settings-open'}
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<12:errors.append({'label':label,'native':a,'expected':e})
def globalsRead():return {'window':n.unpack('<I',0x924864)[0],'criticalIndex':n.unpack('<I',0x297ae20)[0],'resetEnabled':n.unpack('<I',0x827610)[0],'aspectMode':n.unpack('<I',0x297dbd0)[0],'lossCallback':bool(n.unpack('<I',0x297be98)[0]),'desktop':list(n.unpack('<2I',0x2976bd0)),'types':list(n.unpack('<5I',0x828230)),'enabled':n.read(0x8282b4,1)[0],'echoVendor':n.unpack('<I',0x8283e0)[0],'echoDevice':n.unpack('<I',0x8283e4)[0]}
def snap():return {'backendHex':n.read(GLOBAL,0x800).hex(),'cacheHex':n.read(CACHE,0x300).hex(),'markerHex':n.read(MARKERS,0x80).hex(),'modesHex':n.read(TABLE,0x200).hex(),'settingsHex':n.read(SETTINGS,0x460).hex(),'configuration':n.unpack('<i',0x2974d1c)[0],'globals':globalsRead(),'inputs':inputs(),'viewport':readViewport()}
def decode(v):
 s=copy.deepcopy(v)
 for key in ['backend','cache','marker','modes','settings']:s[key]=bytearray.fromhex(s.pop(key+'Hex'))
 return s
def encode(s):return dict({k+'Hex':s[k].hex()for k in ['backend','cache','marker','modes','settings']},**{k:copy.deepcopy(s[k])for k in ['configuration','globals','inputs','viewport']})
def eventPlan(kind,offset,args,index):
 global creating,qualityCall
 q={'return':0,'backendChanges':[],'cacheChanges':[],'markerChanges':[],'sourceChanges':[],'argumentChanges':[],'outputWord':None,'configuration':None,'screen':None,'enabled':None}
 if kind=='d3d':
  if offset==0x38:q['backendChanges']=[{'offset':0xcc,'word':scenario['shaderVersion']},{'offset':0x24,'word':scenario['capsBit']},{'offset':0x1c,'word':scenario['capsWindow']},{'offset':0xf8,'word':scenario['targetCount']}]
  elif offset==0x24:q['return']=scenario['formatResult']
  elif offset==0x14:q['backendChanges']=[{'offset':0x5cc,'word':scenario['vendor']},{'offset':0x5d0,'word':scenario['vendorDevice']}]
  elif offset==0x2c:
   q['return']=scenario['qualityResults'][qualityCall%10];q['outputWord']=scenario['qualityValues'][qualityCall%10];qualityCall+=1
  elif offset==0x40:
   success=creating>=scenario['createFailures'];creating+=1;q['return']=0 if success else scenario['createFailureCode']
   if success:q['backendChanges']=[{'offset':4,'word':DEVICEA},{'offset':0x138,'word':scenario['createdSize'][0]},{'offset':0x13c,'word':scenario['createdSize'][1]}]
 elif kind=='device':
  q['return']=scenario['status']if offset==0xc else scenario['resetResult']if offset==0x40 else (0x80004005 if scenario['opaqueFailures'] else 0)
  if offset==0x40:q['backendChanges']=[{'offset':0x138,'word':scenario['resetSize'][0]},{'offset':0x13c,'word':scenario['resetSize'][1]}]
  if offset==0xbc:
   if scenario['mutatePackets']:q['sourceChanges']=[{'index':index%6,'word':0x7fc00000+index}];q['argumentChanges']=[{'index':(index+1)%6,'word':0xfedcba98}]
  elif offset in [0x94,0x9c]and scenario['mutateHeaders']:q['backendChanges']+=[{'offset':0x138,'word':scenario['lateSize'][0]},{'offset':0x13c,'word':scenario['lateSize'][1]}]
  elif offset==0x114 and scenario['mutateScreen']:q['screen']=scenario['lateSize']
 elif kind in ['resources','rebuild']:
  q['backendChanges']=[{'offset':0x6b0,'word':0x12340001},{'offset':0x6ec,'word':0x12340002},{'offset':0x6e4,'word':2},{'offset':0x6f4,'word':0x12340003},{'offset':0x6f8,'word':0x12340004}]
 elif kind=='loss':q['backendChanges']=[{'offset':0x13c,'word':scenario['resetSize'][1]}]
 elif kind=='error':q['backendChanges']=[{'offset':4,'word':DEVICEA}]
 elif kind=='settings-open':
  if scenario['mutateScreen']:q['screen']=scenario['createdSize']
 if kind in ['enter','exit']:q['return']=scenario['criticalReturn']
 return q

def applyNativePlan(q,output,source,packet):
 for c in q['backendChanges']:n.pack('<I',GLOBAL+c['offset'],c['word'])
 for c in q['cacheChanges']:n.pack('<I',CACHE+c['offset'],c['word'])
 for c in q['markerChanges']:n.pack('<I',MARKERS+c['offset'],c['word'])
 if q['outputWord']is not None:n.pack('<I',output,q['outputWord'])
 if q['configuration']is not None:n.pack('<i',0x2974d1c,q['configuration'])
 if q['screen']is not None:n.pack('<2i',0x973900,*q['screen'])
 if q['enabled']is not None:n.write(0x8282b4,bytes([q['enabled']]))
 for c in q['sourceChanges']:n.pack('<I',source+c['index']*4,c['word'])
 for c in q['argumentChanges']:n.pack('<I',packet+c['index']*4,c['word'])
def entry(mu,address,size,_):
 global sourcePointer
 sourcePointer=n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0]
def host(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];output=None;source=None;packet=None
 if address in RESOURCE_EDGES:
  kind=RESOURCE_EDGES[address];offset=0;receiver=GLOBAL;args=[];pop=0
  if kind in ['release','rebuild']:args=[n.unpack('<I',sp+4)[0]]
  elif kind=='resources':args=[0]
  elif kind=='error':receiver,msg=n.unpack('<2I',sp+4);args=[msg]+([n.unpack('<I',sp+12)[0]]if msg==0x777010 else [])
  elif kind=='settings-open':receiver=0;args=list(n.unpack('<2I',sp+4))
 else:
  kind,offset,count=EDGES[address];raw=list(n.unpack('<'+str(count+(1 if kind in ['d3d','device']else 0))+'I',sp+4));pop=len(raw)*4
  if kind in ['d3d','device']:receiver=raw[0];args=raw[1:]
  elif kind in ['window','message']:receiver=raw[0];args=raw[1:]
  elif kind in ['enter','exit']:receiver=raw[0];args=[]
  else:receiver=0;args=raw
  if kind=='d3d'and offset==0x2c:output=args[-1]
  if kind=='device'and offset==0xbc:packet=args[0];args=list(n.unpack('<6I',packet));source=sourcePointer
 event={'kind':kind,'receiver':receiver,'offset':offset,'arguments':args,'before':snap()}
 if source is not None:event['sourceHex']=n.read(source,24).hex()
 q=eventPlan(kind,offset,args,len(events));event['service']=copy.deepcopy(q);events.append(event);applyNativePlan(q,output,source,packet);mu.reg_write(UC_X86_REG_EAX,q['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+4+pop);mu.reg_write(UC_X86_REG_EIP,ret)
for a in list(EDGES)+list(RESOURCE_EDGES):n.mu.hook_add(UC_HOOK_CODE,host,begin=a,end=a)
n.mu.hook_add(UC_HOOK_CODE,entry,begin=0x6e2470,end=0x6e2470)

def generic(s,kind,offset,args,out,output=None,source=None,sourceOffset=0):
 receiver=u(s['backend'],0 if kind=='d3d'else 4)if kind in ['d3d','device']else s['globals']['window']if kind in ['window','message']else 0x91ef70+s['globals']['criticalIndex']*24 if kind in ['enter','exit']else GLOBAL if kind in ['release','rebuild','resources']else 0x2976078 if kind=='error'else 0
 event={'kind':kind,'receiver':receiver,'offset':offset,'arguments':args[:],'before':encode(s)}
 if source is not None:event['sourceHex']=source[sourceOffset:sourceOffset+24].hex()
 q=copy.deepcopy(events[len(out)]['service']);event['service']=q;out.append(event)
 for c in q['backendChanges']:w(s['backend'],c['offset'],c['word'])
 for c in q['cacheChanges']:w(s['cache'],c['offset'],c['word'])
 for c in q['markerChanges']:w(s['marker'],c['offset'],c['word'])
 if q['outputWord']is not None:w(output,0,q['outputWord'])
 if q['configuration']is not None:s['configuration']=q['configuration']
 if q['screen']is not None:s['inputs']['screen']=q['screen'][:]
 if q['enabled']is not None:s['globals']['enabled']=q['enabled']
 for c in q['sourceChanges']:w(source,sourceOffset+c['index']*4,c['word'])
 return q['return']
def modelCom(s,tag,args,out,source=None,offset=0):return generic(s,'device',{'target':0x94,'depth':0x9c,'viewport':0xbc}[tag],args,out,source=source,sourceOffset=offset)
def wrapper(s,offset,args,out,save=True):
 result=generic(s,'device',offset,args,out)
 if save:w(s['cache'],0,result)
 return result
def sampler(s,stage,type,value,out):
 w(s['marker'],0x20+stage*8,0xffffffff);w(s['marker'],0x24+stage*8,0xffffffff);at=0x34+stage*56+type*4
 if s['globals']['enabled']:
  if u(s['cache'],at)==value:return stage
  w(s['cache'],at,value)
 return wrapper(s,0x114,[stage,type,value],out)
def vendor(s):
 b=s['backend'];g=s['globals'];v=u(b,0x5cc);d=u(b,0x5d0);g['echoVendor']=v;g['echoDevice']=d;w(s['cache'],0x2d8,1);selected=0
 if v==0x10de and d!=0xffffffff:
  for i in range(268):
   val=u(vendorRecords,i*16)
   if val==0xffffffff or selected:break
   if val==d:selected=0x8283e8+i*16
  if selected==0:selected=0x8294a8
 w(s['cache'],0x2dc,selected)
def screen(s):
 width=i32(u(s['backend'],0x138));height=i32(u(s['backend'],0x13c));s['inputs']['screen']=[width,height];s['inputs']['origin']=[int(width/2),int(height/2)]
def critical(s,enter,out):
 index=s['globals']['criticalIndex']
 return index if ((index-1)&0xffffffff)>11 else generic(s,'enter'if enter else'exit',0,[],out)
def bootstrap(s,move,out):
 b=s['backend'];g=s['globals'];settings=s['settings'];critical(s,True,out);w(b,0x670,u(b,0x620));b[0x66e]=int(u(b,0x158)==1);b[0x67c:0x67e]=b[0x6e4:0x6e6];w(b,0x678,u(b,0x638));b[0x674]=b[0x634];w(b,0x680,u(settings,0x424));generic(s,'d3d',0x38,[0,1,GLOBAL+8],out);w(b,0x154,g['window']);w(b,0x158,b[0x65c])
 for offset,val in [(0x15c,1),(0x164,2),(0x150,1),(0x160,0x4b),(0x144,2),(0x16c,1)]:w(b,offset,val)
 if b[0x664]and not(b[0x1c]&1):b[0x664]=0
 b[0x634]=b[0x664]
 if u(b,0x158)and move:
  x=u(settings,0x414);y=u(settings,0x418);width=u(settings,0x40c);height=u(settings,0x410)
  if i32(x)<0:x=((g['desktop'][0]-width)&0xffffffff)>>1
  if i32(y)<0:y=((g['desktop'][1]-height)&0xffffffff)>>1
  generic(s,'window',0,[x,y,width,height,1],out)
 def mode(index):return u(s['modes'],u(b,0x660)*16+index*4)
 fmt=generic(s,'d3d',0x24,[0,1,mode(3),0x15,u(b,0x158)],out);w(b,0x140,mode(3)if i32(fmt)<0 else 0x15)
 for offset,index in [(0x138,0),(0x13c,1),(0x168,2)]:w(b,offset,mode(index))
 if u(b,0x158):w(b,0x168,0)
 flags=(0x10 if b[0x5f8]==0 else 0)|(4 if b[0x5fa]else 0)
 if b[0x5f8]:flags|=0x20
 elif u(b,0xcc)>=0xfffe0101:flags|=0x40
 elif u(b,0x24)&0x10000:flags|=0x80
 else:flags|=0x20
 w(b,0x5f4,flags);w(b,0x5f0,1);w(b,0x1a0,0);generic(s,'d3d',0x14,[0,0,GLOBAL+0x1a4],out);vendor(s)
 if not b[0x63c]:
  for i in range(5):
   first=bytearray(4);second=bytearray(4);a=generic(s,'d3d',0x2c,[u(b,0x1a0),u(b,0x5f0),u(b,0x140),u(b,0x158),g['types'][i],n.STACK+0xe004],out,first);ok=i32(a)>=0
   if ok:ok=i32(generic(s,'d3d',0x2c,[u(b,0x1a0),u(b,0x5f0),u(b,0x160),u(b,0x158),g['types'][i],n.STACK+0xdffc],out,second))>=0
   quality=max(u(first,0),u(second,0));w(b,0x640+i*4,quality-1 if ok and quality else 0xffffffff)
  w(b,0x640,0);w(b,0x658,0);b[0x63c]=1
 req=u(b,0x668);cur=u(b,0x638)
 if b[0x63c]and u(b,0x640+req*4)!=0xffffffff:w(b,0x638,req)
 elif not b[0x63c]or u(b,0x640+cur*4)==0xffffffff:w(b,0x638,0)
 cur=u(b,0x638);w(b,0x148,g['types'][cur]);maximum=u(b,0x640+cur*4);w(b,0x14c,0 if i32(maximum)<0 else maximum);initialize=True
 def create():
  result=generic(s,'d3d',0x40,[u(b,0x1a0),u(b,0x5f0),u(b,0x154),u(b,0x5f4),GLOBAL+0x138,GLOBAL+4],out);w(s['cache'],0,result);return result
 if u(b,4)==0:
  result=create();retry=0
  while i32(result)<0 and retry<15:generic(s,'sleep',0,[500],out);result=create();retry+=1
  if u(b,4)==0:
   w(b,0x138,640);w(b,0x13c,480);w(b,0x168,60);result=create()
   if u(b,4)==0:
    msg={0x8876017c:0x776f80,0x88760868:0x776fb0,0x8876086a:0x776fdc}.get(result,0x777010);generic(s,'error',0,[msg]+([result]if msg==0x777010 else []),out)
  screen(s)
 elif g['resetEnabled']:
  status=wrapper(s,0xc,[],out,False)
  if i32(status)<0:
   if status==0x88760869:
    wrapper(s,0x14,[],out);generic(s,'release',0,[0],out);result=generic(s,'device',0x40,[GLOBAL+0x138],out)
    if i32(result)>=0:generic(s,'rebuild',0,[0],out);initialize=False
   elif status==0x88760868:
    if g['lossCallback']:generic(s,'loss',0,[GLOBAL+0x138],out)
   else:generic(s,'message',0,[0x10,0,0],out)
  else:wrapper(s,0x14,[],out);generic(s,'release',0,[1],out);generic(s,'device',0x40,[GLOBAL+0x138],out);screen(s);generic(s,'rebuild',0,[1],out);initialize=False
 w(b,0x638,0)
 for i in range(5):
  if g['types'][i]==u(b,0x148):w(b,0x638,i);break
 width=u(b,0x138);height=u(b,0x13c);aspect,_=classify(width,height);w(b,0x62c,aspect);w(b,0x630,word(S(D(W(width),W(height)))));override=u(settings,0x424);g['aspectMode']=aspect if override==3 else override;refresh=mode(2)if u(b,0x158)else u(b,0x168);newModes,index=select(b,s['modes'],[i32(u(b,0x138)),i32(u(b,0x13c)),i32(refresh)]);s['modes'][:]=newModes;w(b,0x620,index);generic(s,'device',0x1c,[GLOBAL+8],out)
 if initialize:generic(s,'resources',0,[0],out)
 modelResetConsumer(s,'clear',out);wrapper(s,0xac,[0,0,1,0,0x3f800000,0],out);w(b,0x5fc,generic(s,'device',0x44,[0,0,0,0],out))
 for stage in range(8):
  for type in [5,6,7]:sampler(s,stage,type,2,out)
 if s['configuration']==0:wrapper(s,0x134,[0],out)
 w(s['cache'],0x1f4,0xffffffff);wrapper(s,0xe4,[161,int(u(b,0x638)!=0)],out)
 for i in range(4):w(b,0x6f0+i*4,0)
 w(settings,0x404,s['inputs']['screen'][0]&0xffffffff);w(settings,0x408,s['inputs']['screen'][1]&0xffffffff)
 if u(b,0x158)==0:w(settings,0x41c,u(b,0x168))
 w(settings,0x420,u(b,0x638));generic(s,'settings-open',0,[SETTINGS+4,0x76f4d8],out)
 for offset,val in [(0x188,0),(0x18c,0),(0x190,s['inputs']['screen'][0]),(0x194,s['inputs']['screen'][1]),(0x198,0),(0x19c,0x3f800000)]:w(b,offset,val)
 b[0x65c]=int(u(b,0x158)==1);w(b,0x660,u(b,0x620));b[0x664]=b[0x634];w(b,0x668,u(b,0x638));b[0x66c:0x66e]=b[0x6e4:0x6e6];return critical(s,False,out)

for case in range(256):
 n.write(GLOBAL,rng.randbytes(0x800))
 if case%2==0:n.call(0x6e1930,regs={UC_X86_REG_ECX:GLOBAL})
 b=bytearray(n.read(GLOBAL,0x800));w(b,0,D3D);w(b,4,0 if case%4==0 else DEVICEA);w(b,0x618,8);w(b,0x61c,TABLE);w(b,0x660,case%8);w(b,0x620,(case+1)%8);w(b,0x638,case%5);w(b,0x668,(case+1)%5);w(b,0x158,case%3);b[0x65c]=case%3;b[0x664]=case%2;b[0x634]=case%2;b[0x5f8]=case%2;b[0x5fa]=case%2;b[0x63c]=case%2;w(b,0x6b0,0x12340001);w(b,0x6ec,0x12340002)
 for i in range(5):w(b,0x640+i*4,0 if i==0 else [0,1,3,0xffffffff][(case+i)%4])
 w(b,0x6f4,0x12340003);w(b,0x6f8,0x12340004);n.write(GLOBAL,b);modes=bytearray(0x200)
 for i in range(32):
  for off,val in [(0,640+(i%8)*32),(4,480+(i%4)*16),(8,[60,75][i%2]),(12,[0x15,0x16][i%2])]:w(modes,i*16+off,val)
 n.write(TABLE,modes);settings=bytearray(rng.randbytes(0x460));settings[4:4+14]=b'captured.cfg\x00\x00';w(settings,0x40c,800);w(settings,0x410,600);w(settings,0x414,0xffffffff if case%2 else 17);w(settings,0x418,0xffffffff if case%3 else 19);w(settings,0x424,case%4);n.write(SETTINGS,settings);n.write(CACHE,rng.randbytes(0x300));n.write(MARKERS,rng.randbytes(0x80));n.write(0x8282b4,bytes([0 if case%7==0 else 1]));n.pack('<5I',0x828230,0,2,4,8,16);n.pack('<I',0x924864,0x12340005);n.pack('<2I',0x2976bd0,1920,1080);n.pack('<I',0x297ae20,[0,1,12,13][case%4]);n.pack('<I',0x827610,0 if case%9==0 else 1);n.pack('<I',0x297be98,LOSS if case%2 else 0);n.pack('<I',0x297dbd0,rng.getrandbits(32));n.pack('<i',0x2974d1c,[0,1,2,3][case%4]);n.pack('<I',0x29a9c48,0);c=seed(case);c['screen']=[640,480];c['origin']=[320,240];setup(c)
 for a in [0x80ba68,0x971620]:n.pack('<16f',a,*[f32(rng.uniform(-2,2))for _ in range(16)])
 for a in [0x28492f8,0x981c48,0x992294,0x981c94,0x963e40,0x963e44,0x963e48,0x963e4c]:n.pack('<f',a,f32(rng.uniform(-2,2)))
 n.pack('<16f',0x806680,*identity);scenario={'shaderVersion':[0xfffe0100,0xfffe0101,0xffffffff][case%3],'capsBit':0x10000 if case%2 else 0,'capsWindow':case%2,'targetCount':[0,1,2,4][case%4],'formatResult':0 if case%2 else 0x80004005,'vendor':0x10de if case%2 else 0x1002,'vendorDevice':vids[case%267]if case%3 else 0xfedcba98,'qualityResults':[0 if(case+i)%4 else 0x80004005 for i in range(10)],'qualityValues':[(case+i)%5 for i in range(10)],'createFailures':[0,1,2,16,18][case%5],'createFailureCode':[0x80004005,0x8876017c,0x88760868,0x8876086a][case%4],'createdSize':[700+case%17,500+case%19],'resetSize':[800+case%23,600+case%29],'lateSize':[900+case%13,700+case%11],'status':[0,0x88760827,0x88760868,0x88760869,0x80004005][case%5],'resetResult':0x80004005 if case%3==0 else 0,'opaqueFailures':case%2==0,'criticalReturn':rng.getrandbits(32),'mutatePackets':case%7==0,'mutateHeaders':case%11==0,'mutateScreen':case%13==0};creating=0;qualityCall=0;events.clear();before=snap();move=0 if case%3==0 else 1;
 try:result=n.call(0x6e3940,[move],regs={UC_X86_REG_ECX:GLOBAL},count=1000000)
 except Exception:
  print('FAILCASE',case,'ESP',hex(n.mu.reg_read(UC_X86_REG_ESP)),'lastEdges',[(e['kind'],hex(e['offset']),e['arguments'])for e in events[-8:]],'stack',list(n.unpack('<12I',n.mu.reg_read(UC_X86_REG_ESP))));raise
 after=snap();s=decode(before);out=[];expectedResult=bootstrap(s,move,out);ck(after,encode(s),['full bootstrap context/global state',case]);ck(events,out,['all explicit host/resource boundaries',case]);ck(result,expectedResult,['actual final caller result',case]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe008,['thiscall ret4',case]);cases.append({'moveWindow':move,'scenario':copy.deepcopy(scenario),'before':before,'native':after,'nativeEvents':copy.deepcopy(events),'nativeResult':result})
fixture={'identityWords':words(identity),'callerStack':n.STACK+0xe000,'vendorRecordsHex':vendorRecords.hex(),'cases':cases};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));report={'schema':'original-device-dimension-bootstrap-caller-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'bootstrapCalls':len(cases),'hostResourceCalls':sum(len(c['nativeEvents'])for c in cases),'originalConstructorSetupCases':128},'adapters':{'final COM/window/critical/sleep':'Raw recorded calls and controlled outputs/mutations; no device/window/OS actions.','resource lifecycle6df0e0/6dfe20/6e2d20':'Explicit release/rebuild/resource graph boundaries. Their internal CPU/device effects are NOT recovered by this caller comparison.','device error6e0080':'Recorded original message/format selection with controlled continuation installing a resolved fake device; no original fatal/process behavior claim.','settings file open6e8b9e':'Original6db1c0 executes unchanged, but fopen returns0. No file creation or settings write.'},'limits':['Whole original6e3940 caller, real mode/aspect/vendor/sampler/cache/reset/viewport/critical wrappers and original settings scalar setters execute unchanged.','All supplied images/global pointers and device objects are resolved in isolated memory. Fixed global caller/backend29765c8; mode records disjoint/stable; finite positive dimensions and fitting viewport mode0 arithmetic.','All host/resource boundaries and coherent context/global mutation plans are retained. Numeric viewport globals stable at viewport COM; later sampler/file-open screen mutation is retained.','Create retries include15 recorded sleep calls, fallback640x480/60 and error continuation policies. Existing-device reset/status/loss paths retained with explicit release/rebuild graph adapters.','Successful settings-file open/format/write graph, large resource lifecycle CPU bodies, physical COM/GPU/OS behavior, authored frame binding and later caller-stack lifetime remain open.','Native/Python caller differential passed; source library compile is separate; no managed/game launch or live settings changes.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report));raise SystemExit(0 if not errors else 1)
