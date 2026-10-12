"""Isolated original-x86 connection-controller fixture; import performs no tests."""
import importlib.util,struct,json,itertools,random,math,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI
n=native.NativeX86();BASE=native.BASE;D=n.DATA;WORLD=D;MANAGER=D+0x6000;NAV=D+0x7000;NAVTABLE=D+0x8800;PATH=D+0x9000;PATHLIST=D+0x9f00;POOL=D+0xa000;CNX=D+0xb000;SCENE=D+0xc000;MODEL=D+0xc100;INSTANCE=D+0xc200;INFO=D+0xc400;CLIP=D+0xc600;TABLE=D+0xc700;OBJ=D+0xd000;INDIRECT=D+0xd800;ARGS=D+0xe000;TEXT=D+0xf000;LOCATORS=D+0x18000;LOCLINKS=D+0x19000;PARAM=D+0x20000;DEF=D+0x20100;NAMES=D+0x21000
calls=[];options={};frame_calls=[]
TABLES=[{'JUMP':1,'COMBATROLL':2,'BATGLIDE':4,'GRAPPLE':8,'USEHATCH':16,'HOVERTUBE':64,'FORGOODIES':128,'FORBADDIES':256,'OBSTACLE':0x20000000,'JUMP_NOW':0x400,'DONT_JUMP_NOW':0x800}, {'DBLJUMP':2,'R2D2GLIDE':4,'ZIPUP':8,'USEHATCH':16,'JARJARJUMP':32,'HOVERTUBE':64,'SWAMP':0x4000,'TAKEOVER':0x8000,'VEHICLE':0x10000,'PARTY':0x20000,'FORGOODIES':128,'FORBADDIES':256,'OBSTACLE':0x20000000,'JUMP_NOW':0x400,'DONT_JUMP_NOW':0x800,'BLOCKAGE':0x40000,'JUMP':1,'DONTTOGGLE':0x80000,'FULLTERRAIN':0x100000}, {'DBLJUMP':2,'BIGJUMP':4,'JUMP':1,'GRAPPLE':8,'CLIMB':16,'NO_DEST_CHECK':32,'JUMP_NOW':64,'DONT_JUMP_NOW':128,'FORGOODIES':256,'FORBADDIES':512,'OBSTACLE':0x20000000,'WHIPSWING':0x400}]

def cstr(p):return None if not p else n.read(p,256).split(b'\0')[0].decode('latin1')
def trim(t):return t.split('\0')[0]
def flag(name,mode=1,fallback=(4,0x1000000,0x4000000)):
 key=trim(name).upper();return TABLES[mode].get(key,{'BLOCK':0x80000000,'BIGJUMP':fallback[0],'REQUIRESPERMISSION':fallback[1],'NO_DESTINATION_CHECK':fallback[2]}.get(key,0))
def result(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x43cfb0:frame_calls.append(list(n.unpack('<ii',sp+8)));return
 if address==0x51ad20:
  name=cstr(n.unpack('<I',sp+8)[0]);calls.append(['path',name]);result(mu,0 if options.get('pathMissing')else PATH);return
 if address==0x55a1b0:
  calls.append(['output',n.unpack('<I',sp+12)[0]]);result(mu,options.get('output',0));return
 if address==0x5cf5b0:
  registry,ref,name,extra=n.unpack('<4I',sp+4);calls.append(['target',0,cstr(name)])
  if not options.get('targetMissing'):n.pack('<3I',ref,SCENE,INSTANCE,0)
  result(mu,1);return
 if address==0x55a020:
  registry,kind,name=n.unpack('<3I',sp+4);kind={0xffffffff:3,104:4,107:7,108:8,109:9}[kind];calls.append(['target',kind,cstr(name)]);result(mu,0 if options.get('targetMissing')else OBJ if kind==3 else INDIRECT);return
 kind={0x57c920:1,0x58e980:2,0x59f7a0:6}[address];name=cstr(n.unpack('<I',sp+8)[0]);calls.append(['target',kind,name]);result(mu,0 if options.get('targetMissing')else OBJ)
for address in [0x43cfb0,0x51ad20,0x5cf5b0,0x55a020,0x57c920,0x58e980,0x59f7a0,0x55a1b0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)

def setup(tokens=(),**opts):
 options.clear();options.update(opts);calls.clear();frame_calls.clear();n.write(D,bytes(0x22000))
 n.pack('<I',0x802c54,WORLD);n.pack('<II',WORLD+0x2ae8,NAV,0);n.pack('<I',WORLD+0x4670,MANAGER)
 n.pack('<I',WORLD+0x2ab0,OBJ);n.pack('<II',WORLD+0x2ac8,OBJ,OBJ)
 for a,v in [(0x802f54,104),(0x7f8cc4,107),(0x802644,108),(0x7ffc20,109)]:n.pack('<I',a,v)
 mode=opts.get('mode',1);n.pack('<I',0x876580,int(mode==2));n.pack('<I',0x7f39e4,int(mode==1));n.pack('<3I',0x950d68,*opts.get('fallback',(4,0x1000000,0x4000000)))
 n.pack('<II',MANAGER,opts.get('capacity',4),POOL);n.call(0x43cc30,[MANAGER])
 n.pack('<I',NAV+0x10,NAVTABLE);n.pack('<B',NAVTABLE,1);n.pack('<II',NAVTABLE+4,PATHLIST,PATH);n.pack('<I',PATHLIST,PATH)
 n.pack('<B',PATH+0x10,2);n.pack('<I',PATH+0x7c,LOCATORS);n.pack('<I',LOCLINKS,CNX)
 from_name=opts.get('fromName','a');to_name=opts.get('toName','b')
 for i,name in enumerate([from_name,to_name]):
  loc=LOCATORS+0x5c*i;np=NAMES+0x100*i;n.write(np,name.encode('latin1')+b'\0');n.pack('<I',loc,np);n.pack('<B',loc+0x28,0 if opts.get('connectionMissing')else 1);n.pack('<I',loc+0x34,LOCLINKS)
 n.pack('<II',CNX,*opts.get('edgeFlags',(0x12345678,0x87654321)));n.pack('<BB',CNX+0x10,0,1);n.pack('<B',CNX+0x16,opts.get('edgeObstacle',3))
 n.pack('<I',SCENE+0x54,TABLE);n.pack('<I',TABLE,CLIP);n.pack('<I',INSTANCE+0x40,MODEL);n.pack('<I',MODEL+0x48,0 if opts.get('noAnimation')else INFO);n.pack('<I',MODEL+0x44,1 if opts.get('visible',True)else 0);n.pack('<H',INFO+0x5c,0);n.pack('<f',INFO+0x4c,opts.get('frame',1.));n.pack('<f',CLIP,opts.get('end',60.))
 n.pack('<I',OBJ+0x58,CLIP);n.pack('<f',CLIP+8,opts.get('end',60.));n.pack('<f',OBJ+0x90,opts.get('frame',1.));n.pack('<I',OBJ+0x34,MODEL);n.pack('<I',INDIRECT,OBJ)
 n.pack('<f',0x876844,opts.get('end',60.));n.pack('<f',0x876cc4,opts.get('frame',1.))
 n.pack('<B',OBJ+0x6d,opts.get('buildState',2));n.pack('<B',OBJ+0x94,opts.get('blowupFlags',0));n.pack('<B',OBJ+10,opts.get('flowFlags',2));n.pack('<I',MODEL+12,opts.get('obstacleState',2));n.pack('<H',OBJ+0x68,opts.get('zipFlags',0xc0))
 n.pack('<I',OBJ+0x74,opts.get('forceFlags',0));n.pack('<I',OBJ+0xa0,opts.get('forceFlags2',0));n.pack('<f',OBJ+0x4c,opts.get('forceTimer',0.));n.pack('<I',OBJ+0x28,MODEL if opts.get('forceHasObstacle',False)else 0)
 n.pack('<I',PARAM+4,DEF);n.pack('<4f',PARAM+0x14,5.9,-1.2,16.75,.25)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.write(NAMES+0x400+i*32,name.encode()+b'\0');n.pack('<I',DEF+0x18+i*8,NAMES+0x400+i*32)
 for i,t in enumerate(tokens):n.write(TEXT+256*i,t.encode('latin1')+b'\0');n.pack('<I',ARGS+4*i,TEXT+256*i)
 return PARAM if opts.get('parameters',True)else 0

def numeric(value,parameters=True):
 low=trim(value).lower()
 if parameters:
  if low in ['alpha','beta','gamma','delta']:return [5,-1,16,0][['alpha','beta','gamma','delta'].index(low)]
  if'param'in low:return 5
 try:return math.trunc(float(low))
 except ValueError:return 0

def parse(tokens,opts):
 p={'from':None,'to':None,'kind':0,'target':None,'fake':-1,'output':0,'path':False,'on':0,'off':0,'both':False,'visible':False,'onObstacle':False,'offObstacle':False,'ranges':[],'calls':[]}
 for raw in tokens:
  t=trim(raw);low=t.lower()
  if'on_frames'in low:continue
  if'from='in low:p['from']=t[low.index('from=')+5:]
  elif'to='in low:p['to']=t[low.index('to=')+3:]
  elif'pathname='in low:p['calls'].append(['path',t[low.index('pathname=')+9:]]);p['path']=not opts.get('pathMissing',False)
  elif'checkvisible'in low:p['visible']=True
  elif'bothways'in low:p['both']=True
  elif'on_flag'in low or'off_flag'in low:
   on='on_flag'in low
   if'obstacle_open'in low:p['onObstacle'if on else'offObstacle']=True
   elif'obstacle_closed'in low:p['onObstacle'if on else'offObstacle']=False
   else:
    start=low.index('on_flag'if on else'off_flag')+(8 if on else 9);p['on'if on else'off']|=flag(t[start:],opts.get('mode',1),opts.get('fallback',(4,0x1000000,0x4000000)))
  else:
   specs=[('obj=',0),('cutscene=',1),('buildit=',2),('fakeanimid=',5),('gizmo_output=',None),('gizmo=',3),('flowbox=',6),('blowup=',4),('force=',7),('obstacle=',8),('zipup=',9)]
   for key,kind in specs:
    if key not in low:continue
    value=t[low.index(key)+len(key):]
    if kind is None:p['output']=numeric(value,opts.get('parameters',True))&0xffffffff
    elif kind==5:p['fake']=numeric(value,opts.get('parameters',True));p['kind']=5
    else:p['kind']=kind;p['target']=value
    break
 for raw in tokens:
  t=trim(raw);low=t.lower();i=low.find('on_frames')
  if i<0:continue
  value=t[i+10:];low=value.lower();j=low.find('to')
  if j<0:continue
  def endpoint(v):return -2 if v.lower()=='lastframe-1'else-1 if v.lower()=='lastframe'else numeric(v,opts.get('parameters',True))
  first,last=endpoint(value[:j]),endpoint(value[j+2:])
  if first<=last or last in[-1,-2]:p['ranges'].append([first,last])
 return p

def mask_range(mask,kind,end,start,stop,no_animation=False):
 if kind in[2,3,4,6]:return
 last=min(1024,math.trunc(end))if kind in[0,1,5]and not(kind==0 and no_animation)else 1
 start=last if start==-1 else last-1 if start==-2 else start;stop=last if stop==-1 else last-1 if stop==-2 else stop
 for i in range(max(1,start)-1,min(last,stop)):mask[i//32]|=1<<(i%32)

def valid_creation(p,opts):
 valid_names=p['from']is not None and p['to']is not None
 edge=valid_names and p['from'].lower()!=p['to'].lower()and not opts.get('connectionMissing',False)
 if not valid_names or opts.get('capacity',4)==0:return False
 if not edge:return p['kind']==5 # native bypasses fake-index check when connection lookup fails
 if p['kind']==5:return p['fake']==0
 return not opts.get('targetMissing',False)and(p['target']is not None or p['kind']!=0)

def projection(record=POOL):return {'on':n.unpack('<I',record+0x1c)[0],'off':n.unpack('<I',record+0x20)[0],'mask':list(n.unpack('<32I',record+0x24)),'kind':n.read(record+0xa4,1)[0],'pathIndex':n.read(record+0xa5,1)[0],'flags':n.unpack('<H',record+0xa6)[0],'connection':n.unpack('<I',record+8)[0]!=0,'targetWords':list(n.unpack('<3I',record+12)),'output':n.unpack('<I',record+0x18)[0]}

def command(tokens,first=1,**opts):
 ctx=setup(tokens,**opts);ret=n.call(0x44d900,[WORLD,ctx,0,ARGS,len(tokens),first],count=2000000);used=n.unpack('<I',MANAGER+16)[0]
 return {'result':ret,'created':used!=0,'record':projection(used)if used else None,'calls':calls.copy(),'ranges':frame_calls.copy()}
