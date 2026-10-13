import importlib.util,json,struct,itertools,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('text',Path(__file__).with_name('world-phase4-20261013-verify.py'));t=importlib.util.module_from_spec(s);s.loader.exec_module(t);n=t.n;B=t.B;D=t.D
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
WORLD=D;ARENA=D+0x10000;ARENAEND=D+0x50000;LEVELS=D+0x60000;LEVEL=LEVELS+0x130;LEVEL2=LEVELS+0x260;GROUP=D+0x80000;GROUPARRAY=D+0x81000;GROUPOBJECTS=D+0x82000;GLYPH=D+0x90000;SCENE=D+0x90100;PHOTO=D+0x90200;ALTERNATE=D+0x90300;FAIL=0x93d840;TAG=0x2854d4c;HANDOFF=0x48d063
REGIONS=sorted([(0x7fac04,4),(0x8264bc,4),(0x87b060,44),(0x87b164,16),(0x87b71c,4),(t.ARCHIVE,4),(t.SPECIAL,4),(t.ERROR,4),(t.GLOBAL,0x10010),(FAIL,4),(0x951b78,4),(0x951b88,4),(0x951b9c,4),(0x951ba8,4),(0x955870,4),(TAG,4),(0x2913a2c,32),(0x2948eb0,32),(D,0xa0000)])
t.REGIONS=REGIONS
class NativeView:
 def read(self,a,z):return n.read(a,z)
 def write(self,a,b):n.write(a,b)
 def get(self,a):return n.unpack('<I',a)[0]
 def put(self,a,v):n.pack('<I',a,v&0xffffffff)
 def string(self,a):return t.cstring(a)
t.capture=lambda:NativeView();t.load=lambda image:None
RESOURCE_ARGS={0x578f60:3,0x6d34c0:1,0x48c270:3,0x5528b0:1,0x48c630:1,0x5934d0:2,0x652b40:1,0x59a030:1,0x55b5b0:1,0x57cf00:1,0x5ef880:1,0x68e900:1,0x68ea00:1,0x648a30:1,0x64c6e0:1,0x689e70:1,0x689ed0:1,0x65ceb0:1,0x65a5c0:1,0x65a5d0:1,0x5a29d0:1,0x566630:1}
current=None;resourceState=None;handoff=False;teardownEntries=0;rows=[];errors=[]
def signed(v):return v if v<0x80000000 else v-0x100000000
def options(o):
 p=dict(kind='Prefix',io={},initialFail=0,flags=4,title=0,backendMode=0,stageByte=3,channelByte=2,tableMatch=0,titleSuffix='selected_title',scenePresent=True,picturePresent=True,sceneBytes=64,pictureBytes=32,failAt='none',metaFlags=-1,metaSwap=False,flipBackend=False,clearSceneAtBounds=False,rebindSceneAtPost=False,groupPresent=False,groupCount=0,newGroupCount=-99,glyphPresent=False,sceneBefore=False,photoBefore=False,handles=[-1]*5,mutateHandles=False,mutateValue=0xdeadbea5,rebindSceneAtTeardown=False,poolMask=0,poolSkip=1,mutatePools=False,loadedMarker=0);p.update(o);p['io']=t.options(p['io']);return p
def setup(p):
 image=t.Image();image.write(WORLD,bytes(0x51ac));image.text(WORLD,p['io']['path']);image.text(WORLD+0x80,p['io']['path']);image.put(WORLD+0x100,ARENA);image.put(WORLD+0x104,ARENA+p['io']['cursorOffset']);image.put(WORLD+0x108,ARENAEND);image.put(WORLD+0x110,p['loadedMarker']);image.put(WORLD+0x11c,1);image.put(WORLD+0x120,2);image.put(WORLD+0x124,3);image.put(WORLD+0x128,LEVEL)
 image.put(WORLD+0x2ab0,GROUP if p['groupPresent'] else 0);image.put(GROUP,GROUPARRAY);image.put(GROUP+4,p['groupCount'])
 for i in range(3):image.put(GROUPARRAY+i*4,GROUPOBJECTS+i*32);image.put(GROUPOBJECTS+i*32+4,0xa0+i)
 image.put(WORLD+0x2964,GLYPH if p['glyphPresent'] else 0);image.put(WORLD+0x13c,SCENE if p['sceneBefore'] else 0);image.put(WORLD+0x140,PHOTO if p['photoBefore'] else 0)
 for offset,value in zip([0x2a98,0x2a9c,0x2aa4,0x2aa8,0x2aa0],p['handles']):image.put(WORLD+offset,value)
 for a,v in [(0x7fac04,p['poolSkip']),(0x8264bc,p['backendMode']),(0x87b71c,0),(t.ARCHIVE,p['io']['archive']),(t.SPECIAL,p['io']['special']),(t.ERROR,0xdeadbeef),(FAIL,p['initialFail']),(0x951b78,LEVELS),(0x951b88,LEVEL if p['title']==1 else 0),(0x951b9c,LEVEL if p['title']==2 else 0),(0x951ba8,0x1234),(0x955870,0x5678),(TAG,0x87654321)]:image.put(a,v)
 image.write(0x87b060,bytes(44));image.write(0x87b164,bytes(16))
 if p['tableMatch']&1:image.put(0x87b060+40,LEVEL)
 if p['tableMatch']&2:image.put(0x87b164+12,LEVEL)
 for i in range(8):image.put(0x2948eb0+i*4,0x1000+i if p['poolMask']&(1<<i) else 0);image.put(0x2913a2c+i*4,0x2000+i if p['poolMask']&(1<<i) else 0)
 for record,delta in [(LEVEL,0),(LEVEL2,7)]:
  image.put(record+0x64,p['flags']);image.write(record+0xa0,bytes([(p['stageByte']+delta)&255]));image.write(record+0xa2,bytes([(p['channelByte']+delta)&255]));image.write(record+0xa3,b'\x02')
 return image

def emit(trace,entry,args,**fields):trace.append(dict(entry=hex(entry),args=[a&0xffffffff for a in args],**fields))
def fresh_resource():return dict(audioStops=0,allocations=0)
def service(image,p,s,trace,entry,args):
 emit(trace,entry,args)
 if entry==0x578f60:
  if p['metaSwap']:image.put(WORLD+0x128,LEVEL2)
  if p['metaFlags']!=-1:image.put(image.get(WORLD+0x128)+0x64,p['metaFlags'])
  if p['failAt']=='metadata':image.put(FAIL,1)
 elif entry==0x6d34c0:
  if p['flipBackend']:image.put(0x8264bc,2)
 elif entry==0x48c270:
  image.put(args[1],0xc0270)
  if p['clearSceneAtBounds']:image.put(WORLD+0x13c,0)
  if p['failAt']=='bounds':image.put(FAIL,1)
 elif entry==0x5528b0:
  image.put(WORLD+0x150,image.get(WORLD+0x150)+1)
  if p['rebindSceneAtPost']:image.put(WORLD+0x13c,ALTERNATE)
  if p['failAt']=='postscene':image.put(FAIL,1)
 elif entry==0x48c630:
  image.put(WORLD+0x2b00,image.get(WORLD+0x2b00)+1)
  if p['failAt']=='special':image.put(FAIL,1)
 elif entry==0x5934d0:image.put(WORLD+0x2b00,image.get(WORLD+0x2b00)+1)
 elif entry==0x652b40:
  s['audioStops']+=1
  if s['audioStops']==1 and p['newGroupCount']!=-99:image.put(GROUP+4,p['newGroupCount'])
 elif entry==0x5ef880:
  if D<=args[0]<D+0xa0000:image.put(args[0],0xd15ab1ed)
 elif entry==0x5a29d0:
  if p['rebindSceneAtTeardown']:image.put(WORLD+0x13c,ALTERNATE)
 if p['mutateHandles']:
  offset={0x68e900:0x2a98,0x648a30:0x2a9c,0x689e70:0x2aa4,0x65a5c0:0x2aa0}.get(entry)
  if offset is not None:image.put(WORLD+offset,p['mutateValue'])
 if p['mutatePools'] and args:
  if entry==0x68ea00 and 2<=args[0]<7:image.put(0x2948eb0+(args[0]+1)*4,0)
  if entry==0x64c6e0 and 1<=args[0]<7:image.put(0x2913a2c+(args[0]+1)*4,0)
 return 0

def scene_load(image,p,s,trace,entry,args,path,role):
 emit(trace,entry,args,path=path,role=role,tag=image.get(TAG),cursor=image.get(args[0]));size=p['pictureBytes'] if role=='pictures' else p['sceneBytes'];ptr=image.get(args[0]);image.write(ptr,bytes([0xab if role=='pictures' else 0xcd])*size);image.put(args[0],ptr+size);s['allocations']+=1
 if p['failAt']==role:image.put(FAIL,1)
 return ptr if (p['picturePresent'] if role=='pictures' else p['scenePresent']) else 0

def teardown(image,p,s,trace):
 count=1;service(image,p,s,trace,0x5934d0,[image.get(0x955870),WORLD]);group=image.get(WORLD+0x2ab0)
 if group and signed(image.get(group+4))>0:
  i=0
  while True:
   group=image.get(WORLD+0x2ab0);record=image.get(image.get(group)+i*4);service(image,p,s,trace,0x652b40,[image.get(record+4)]);i+=1
   if i>=signed(image.get(image.get(WORLD+0x2ab0)+4)):break
 for a,args in [(0x59a030,[WORLD]),(0x55b5b0,[WORLD]),(0x57cf00,[image.get(WORLD+0x2ab0)])]:service(image,p,s,trace,a,args)
 if image.get(WORLD+0x2964):service(image,p,s,trace,0x5ef880,[image.get(WORLD+0x2964)]);image.put(WORLD+0x2964,0)
 for offset,entries in [(0x2a98,[0x68e900,0x68ea00]),(0x2a9c,[0x648a30,0x64c6e0]),(0x2aa4,[0x689e70,0x689ed0]),(0x2aa8,[0x65ceb0]),(0x2aa0,[0x65a5c0,0x65a5d0])]:
  if image.get(WORLD+offset)!=0xffffffff:
   for entry in entries:service(image,p,s,trace,entry,[image.get(WORLD+offset) if offset==0x2aa0 else image.read(WORLD+offset,1)[0]])
 if image.get(0x7fac04)==0:
  for i in range(2,8):
   if image.get(0x2948eb0+i*4):service(image,p,s,trace,0x68e900,[i]);service(image,p,s,trace,0x68ea00,[i])
  for i in range(1,8):
   if image.get(0x2913a2c+i*4):service(image,p,s,trace,0x648a30,[i]);service(image,p,s,trace,0x64c6e0,[i])
 service(image,p,s,trace,0x5a29d0,[WORLD])
 for offset in [0x13c,0x140]:
  if image.get(WORLD+offset):service(image,p,s,trace,0x5ef880,[image.get(WORLD+offset)]);image.put(WORLD+offset,0)
 return count

def reset_after_abort(image,p,s,trace):
 service(image,p,s,trace,0x566630,[0]);count=0
 if image.get(WORLD+0x110):count+=teardown(image,p,s,trace)
 start=image.get(WORLD+0x100);end=image.get(WORLD+0x108);image.write(WORLD,bytes(0x51ac));image.put(WORLD+0x100,start);image.put(WORLD+0x104,start);image.put(WORLD+0x108,end)
 if signed((end-start)&0xffffffff)>0:image.write(start,bytes(end-start))
 for off in [0x11c,0x120,0x124]:image.put(WORLD+off,0xffffffff)
 return count

def model_prefix(image,p,s,trace):
 io=p['io'];ioState=t.fresh();image.write(t.GLOBAL,b'\0');path=image.string(WORLD+0x80)+'.txt';t.emit(trace,'Format',format='%s.txt',source=image.string(WORLD+0x80),path=path);cursor=(image.get(WORLD+0x104)+3)&0xfffffffc;image.put(WORLD+0x104,cursor);value=t.read_whole(image,io,ioState,trace,path,cursor,0x10000);image.put(WORLD+0x10c,value)
 if value>0:image.write(image.get(WORLD+0x104)+value,b'\0');image.put(WORLD+0x10c,t.normalize(image,image.get(WORLD+0x104),t.GLOBAL,1))
 aborted=image.get(FAIL)!=0
 if not aborted and signed(image.get(WORLD+0x10c))>0:service(image,p,s,trace,0x578f60,[image.get(WORLD+0x128),t.GLOBAL,image.get(0x951ba8)]);aborted=image.get(FAIL)!=0
 if not aborted:
  level=image.get(WORLD+0x128)
  if image.read(level+0x64,1)[0]&4:
   image.put(WORLD+0x104,(image.get(WORLD+0x104)+3)&0xfffffffc)
   if level==image.get(0x951b88):emit(trace,0x489aa0,[],suffix=p['titleSuffix']);path='levels\\titles\\'+p['titleSuffix']
   else:path=image.string(WORLD+0x80)
   path+='.gsc';level=image.get(WORLD+0x128);image.put(TAG,image.read(level+0xa0,1)[0]+1)
   if any(image.get(0x87b060+i*4)==level for i in range(11)):channel=1
   elif any(image.get(0x87b164+i*4)==level for i in range(4)):channel=3
   else:channel=image.read(level+0xa2,1)[0];channel=(channel-256 if channel>=128 else channel)+1
   service(image,p,s,trace,0x6d34c0,[channel]);entry=0x5f4f00 if image.get(0x8264bc)==2 else 0x5ef7f0;args=[WORLD+0x104,image.get(WORLD+0x108)]+([2] if entry==0x5f4f00 else []);scene=scene_load(image,p,s,trace,entry,args,path,'scene');image.put(WORLD+0x13c,scene);service(image,p,s,trace,0x6d34c0,[0]);image.put(TAG,0);service(image,p,s,trace,0x48c270,[image.get(WORLD+0x13c),WORLD+0x15c,1]);service(image,p,s,trace,0x5528b0,[image.get(WORLD+0x13c)])
   if image.get(WORLD+0x13c):service(image,p,s,trace,0x48c630,[WORLD])
   aborted=image.get(FAIL)!=0
 if not aborted:
  level=image.get(WORLD+0x128)
  if level==image.get(0x951b88) or level==image.get(0x951b9c):image.put(TAG,image.read(level+0xa0,1)[0]+1);scene=scene_load(image,p,s,trace,0x5ef7f0,[WORLD+0x104,image.get(WORLD+0x108)],'levels\\titles\\pictures.gsc','pictures');image.put(WORLD+0x140,scene);aborted=image.get(FAIL)!=0
 count=0
 if aborted:count+=teardown(image,p,s,trace);count+=reset_after_abort(image,p,s,trace)
 return not aborted,count,ioState

def observe(mu,address,size,user):
 global handoff,teardownEntries
 if address==HANDOFF:handoff=True;mu.reg_write(UC_X86_REG_EIP,n.STOP);return
 if address==0x55f6c0:teardownEntries+=1;return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x489aa0:n.write(mu.reg_read(UC_X86_REG_EAX),current['titleSuffix'].encode()+b'\0');emit(t.trace,address,[],suffix=current['titleSuffix']);value=0
 elif address in [0x5ef7f0,0x5f4f00]:
  raw=list(n.unpack('<'+('4I' if address==0x5f4f00 else '3I'),sp+4));path=t.cstring(raw[2]);args=raw[:2]+(raw[3:] if address==0x5f4f00 else []);role='pictures' if n.unpack('<I',sp)[0]==0x48d04d else 'scene';value=scene_load(NativeView(),current,resourceState,t.trace,address,args,path,role)
 else:value=service(NativeView(),current,resourceState,t.trace,address,list(n.unpack('<'+'I'*RESOURCE_ARGS[address],sp+4)))
 mu.reg_write(UC_X86_REG_EAX,value&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for address in [HANDOFF,0x55f6c0,0x489aa0,0x5ef7f0,0x5f4f00]+list(RESOURCE_ARGS):n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)

def run(inputs):
 global current,resourceState,handoff,teardownEntries
 p=options(inputs);current=p;resourceState=fresh_resource();handoff=False;teardownEntries=0;t.current=p['io'];t.state=t.fresh();t.trace=[];expected=setup(p)
 for a,data in expected.regions.items():n.write(a,data)
 wantTrace=[];modelState=fresh_resource()
 if p['kind']=='Prefix':wantHandoff,wantTeardowns,wantIO=model_prefix(expected,p,modelState,wantTrace);n.call(0x48ce00,[WORLD],count=10000000)
 else:wantHandoff=False;wantTeardowns=teardown(expected,p,modelState,wantTrace);wantIO=t.fresh();n.call(0x55f6c0,[WORLD],count=10000000)
 actual=t.Image()
 for a,z in REGIONS:actual.regions[a][:]=n.read(a,z)
 bad=[]
 if actual.sha()!=expected.sha():
  diffs=[]
  for a,z in REGIONS:diffs.extend(hex(a+i) for i,(x,y) in enumerate(zip(actual.regions[a],expected.regions[a])) if x!=y)
  bad.append(dict(differences=diffs[:24]))
 if t.trace!=wantTrace:bad.append(dict(trace=t.trace,want=wantTrace))
 if handoff!=wantHandoff or teardownEntries!=wantTeardowns:bad.append(dict(handoff=handoff,want=wantHandoff,teardowns=teardownEntries,wantTeardowns=wantTeardowns))
 if t.state!=wantIO or resourceState!=modelState:bad.append(dict(io=t.state,wantIO=wantIO,resources=resourceState,wantResources=modelState))
 if bad:errors.append(dict(index=len(rows),options=p,bad=bad))
 rows.append(dict(options=p,nativeSha=actual.sha(),handoff=handoff,teardownEntries=teardownEntries,trace=t.trace.copy(),resourceState=resourceState.copy(),ioState=t.state.copy()))

def main():
 for flags,title,mode,present,fail in itertools.product([0,4],[0,1,2],[0,2],[False,True],['none','metadata','scene','bounds','postscene','special','pictures']):run(dict(flags=flags,title=title,backendMode=mode,scenePresent=present,failAt=fail))
 for stage,channel,match in itertools.product([0,255],[-128,-1,0,127],[0,1,2,3]):run(dict(stageByte=stage,channelByte=channel,tableMatch=match))
 for initial,text,metaFlags,swap,flip,clear,rebind in itertools.product([0,1],['',';allcomments'],[-1,0,4],[False,True],[False,True],[False,True],[False,True]):run(dict(initialFail=initial,io=dict(text=text),metaFlags=metaFlags,metaSwap=swap,flipBackend=flip,clearSceneAtBounds=clear,rebindSceneAtPost=rebind,failAt='bounds'))
 for loaded,group,newCount,rebind in itertools.product([0,1],[0,1,3],[0,1,3],[False,True]):run(dict(failAt='scene',loadedMarker=loaded,groupPresent=group!=0,groupCount=group,newGroupCount=newCount,rebindSceneAtTeardown=rebind,glyphPresent=True,photoBefore=True,handles=[257,258,259,260,0x12345678],mutateHandles=True,poolMask=255,poolSkip=0,mutatePools=True))
 for enabled in itertools.product([False,True],repeat=5):run(dict(kind='Teardown',handles=[0x1234+i if on else -1 for i,on in enumerate(enabled)],groupPresent=True,groupCount=3,glyphPresent=True,sceneBefore=True,photoBefore=True,poolMask=255,poolSkip=0))
 for value,count,newCount,skip,mutate in itertools.product([-1,0,1,255,256,0x80000000],[-1,0,1,3],[0,1,3],[0,1],[False,True]):run(dict(kind='Teardown',handles=[value]*5,loadedMarker=0x12345678,groupPresent=True,groupCount=count,newGroupCount=newCount,glyphPresent=True,sceneBefore=True,photoBefore=True,poolMask=255,poolSkip=skip,mutateHandles=mutate,mutatePools=mutate,rebindSceneAtTeardown=mutate))
 report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(errors),groups={k:sum(r['options']['kind']==k for r in rows) for k in ['Prefix','Teardown']},handoffs=sum(r['handoff'] for r in rows),abortedPrefixes=sum(r['options']['kind']=='Prefix' and not r['handoff'] for r in rows),teardownExecutions=sum(r['teardownEntries'] for r in rows),bytesHashedPerCase=sum(z for a,z in REGIONS),examples=errors[:2],method='Original48ce00 initial text/scene/pictures phase through48d063 handoff; original full abort48d64d executes complete55f6c0 teardown and55ffb0 world/arena reset. Original57a420→4fd5d0→54be70 text pipeline composes unchanged with explicit previous transport/formatter services. Resource scene/payload/postbind/release calls are mutable adapters; complete caller state, trace, fresh reads after adapter mutation, handoff/abort and nested teardown count compare.',limits=['48ce00 coverage ends at48d063, before auxiliary resource allocation5a05b0. Handoff is not full loader success or populated+110 commit. Failure cleanup executes original code through return.','Scene/pictures payload loading and subsystem release semantics are explicit mutable service fixtures, not real graphics/audio/terrain backends. Title helper489aa0 output is a bounded prepared64-byte service; original copy/append routines execute.','Prepared world/catalog/arena/group/registry backing, nonnegative or sentinel signed group counts, fixed resource pointer lists and valid service mutations. Resource callbacks may change live group count/handle fields/scene pointers; native rereads are preserved.','Normal prefix resource return pointers reside in prepared arena; teardown alternative resources have prepared external backing. Fixed cache-force global87b71c is0. Loaded-marker abort cases exercise original repeated teardown.','The reused fixed%s.txt CRT formatter/I/O services remain adapted, as documented in phase4. Managed replay remains pending; no executable retry.'])
 (B/'reports/world-phase5-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/world-phase5-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=REGIONS,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
