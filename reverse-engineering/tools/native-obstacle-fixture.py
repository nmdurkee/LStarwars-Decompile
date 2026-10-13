"""Original PC obstacle/scene-control fixture; only named registry binding is adapted."""
import importlib.util,struct,copy,math
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
native=module('native_x86','native-x86.py');wide=module('animation_x87','animation-x87.py')
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA;WORLD=D;REG=D+0x7000;TYPES=D+0x7200;RECORDS=D+0x8000;OBJECTS=D+0x9000;ANIMS=D+0xa000;QUEUE=D+0xa900;NODES=D+0xb000;TARGETS=D+0xc000;TEXT=D+0xe000;ARGS=D+0x14000;RESULT=D+0x15000
calls=[];opts={}
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def f32(v):
 try:return struct.unpack('<f',struct.pack('<f',v))[0]
 except OverflowError:return math.copysign(math.inf,v)
def cstr(p):return None if not p else n.read(p,256).split(b'\0')[0].decode('latin1')
def trim(s):return s.split('\0')[0]
def fold(s):return ''.join(chr(ord(c)-32)if 'a'<=c<='z'or ord(c)>=224 else c for c in trim(s))
def lookup(name,special):
 if opts.get('registryMissing')or opts.get('targetMissing')or name is None or fold(name)=='MISSING':return None
 if fold(name)=='NULLOBJECT':return 2
 return 1 if fold(name)=='B'else 0

def named(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);registry,kind,name=n.unpack('<3I',sp+4);special=kind==1;name=cstr(name);calls.append(['find',int(special),name]);which=lookup(name,special)
 result=0 if which is None else RECORDS+which*0x20
 if which in [0,1]:n.pack('<B',result+6,int(special))
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,named,begin=0x55a020,end=0x55a020)

def setup(tokens=(),**options):
 opts.clear();opts.update(options);calls.clear();n.write(D,bytes(0x16000));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ac8,0 if opts.get('registryMissing')else REG);n.pack('<I',0x802644,0);n.pack('<I',0x805ebc,1)
 n.pack('<I',0x93b268,0 if opts.get('typesMissing')else REG);n.pack('<3I',REG,opts.get('typeCount',2),0,TYPES);n.pack('<I',TYPES+0x48,0 if opts.get('outputMissing')else 0x558780);n.pack('<I',TYPES+0x9c+0x48,0 if opts.get('outputMissing')else 0x5ae3a0)
 nodes=copy.deepcopy(opts.get('nodes',[dict(start=1.,end=61.,frame=17.,rate=3.,scale=0.,flags=0xabcdef12,present=True,reference=True),dict(start=81.,end=2.,frame=97.,rate=-2.,scale=.5,flags=0x13579bdf,present=True,reference=True)]))
 for i in range(2):
  rec=RECORDS+i*0x20;obj=OBJECTS+i*0x200;anim=ANIMS+i*0x400;first=NODES+i*0x400
  n.pack('<I',rec,obj);n.pack('<B',rec+6,opts.get('recordType',0));n.pack('<I',obj+0x20,anim if opts.get('animationPresent',True)else 0);n.pack('<B',obj+0x24,opts.get('specialFlags',2));n.pack('<I',obj+0x34,anim if opts.get('animationPresent',True)else 0);n.pack('<3f',obj+0x48,opts.get('speed',1.),opts.get('forwardRate',2.),opts.get('backwardRate',3.));n.pack('<B',obj+0x90,opts.get('loopMode',2));n.pack('<3I',obj+0x94,opts.get('obstacleStatus',3),opts.get('proximity',0),opts.get('obstacleFlags',0xf0f0a5a5))
  n.pack('<B',anim+8,opts.get('memberCount',len(nodes)))
  n.pack('<H',anim+10,opts.get('controlFlags',0));n.pack('<i',anim+12,opts.get('state',4));n.pack('<I',anim+20,QUEUE if opts.get('queue',True)else 0);n.pack('<I',anim+24,first if nodes else 0)
  for j,node in enumerate(nodes):
   p=first+j*0x40;t=TARGETS+i*0x1000+j*0x80
   n.pack('<I',p,p+0x40 if j+1<len(nodes)else 0);n.pack('<III',p+4,0,t if node.get('reference',True)else 0,0);n.pack('<IIff',p+16,t if node.get('present',True)else 0,1 if node.get('owner',True)else 0,node['start'],node['end'])
   n.write(t,bytes([0xa5])*0x80);n.pack('<f',t+0x40,node.get('rate',0));n.pack('<fIf',t+0x4c,node['frame'],node.get('flags',0),node.get('scale',0))
 n.pack('<I',RECORDS+0x40,0)
 for i,t in enumerate(tokens):n.write(TEXT+i*256,t.encode('latin1')+b'\0');n.pack('<I',ARGS+i*4,TEXT+i*256)
 return nodes

def state(nodes):
 values=[]
 for i in range(2):
  a=ANIMS+i*0x400;o=OBJECTS+i*0x200
  values.append(dict(controlFlags=n.unpack('<H',a+10)[0],state=n.unpack('<i',a+12)[0],obstacleFlags=n.unpack('<I',o+0x9c)[0],nodes=[dict(frameBits=n.unpack('<I',TARGETS+i*0x1000+j*0x80+0x4c)[0],rateBits=n.unpack('<I',TARGETS+i*0x1000+j*0x80+0x40)[0],flags=n.unpack('<I',TARGETS+i*0x1000+j*0x80+0x50)[0])for j in range(len(nodes))]))
 queue=[];p=n.unpack('<I',QUEUE)[0]
 while p:
  if len(queue)>4:raise ValueError('Corrupt queue')
  queue.append((p-ANIMS)//0x400);p=n.unpack('<I',p)[0]
 return dict(targets=values,queue=queue,calls=copy.deepcopy(calls))

def floating(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]

def model_state(nodes,options):
 return dict(targets=[dict(controlFlags=options.get('controlFlags',0),state=options.get('state',4),obstacleFlags=options.get('obstacleFlags',0xf0f0a5a5),nodes=[dict(frameBits=bits(x['frame']),rateBits=bits(x.get('rate',0)),flags=x.get('flags',0))for x in nodes])for i in range(2)],queue=[],calls=[])
def value(b):return struct.unpack('<f',struct.pack('<I',b))[0]
def refresh(target,nodes):
 if target['controlFlags']&4:return
 end=start=True
 for source,item in zip(nodes,target['nodes']):
  if not source.get('present',True):continue
  direction=1 if source['start']<=source['end']else-1;f=value(item['frameBits'])*direction
  if f<source['end']*direction:end=False
  if source['start']*direction<f:start=False
 target['state']=2 if end else 0 if start else 4

def control(model,nodes,options,operation,index=0,argument=1.,evaluate=False):
 if not options.get('animationPresent',True):return
 target=model['targets'][index]
 if operation=='refresh':refresh(target,nodes);return
 if operation=='stop':
  if target['state']not in [1,3]:return
  target['controlFlags']|=2
 if operation=='play':
  if evaluate:refresh(target,nodes)
  target['controlFlags']&=0xfffd
  if (argument<0 and target['state']==0)or(argument>=0 and target['state']==2):return
 for source,item in zip(nodes,target['nodes']):
  if not source.get('present',True):continue
  start,end=source['start'],source['end'];direction=1 if start<=end else-1
  if operation=='play':
   item['flags']=(item['flags']|1)&0xfffffffb;frame=value(item['frameBits'])*direction
   if start*direction>frame:item['frameBits']=bits(start)
   elif end*direction<frame:item['frameBits']=bits(end)
   scale=source.get('scale',0);item['rateBits']=bits(f32((scale if scale!=0 else 1)*argument*direction))
  elif operation=='loop':item['flags']=(item['flags']&0xfffffff7)|((int(argument)&1)<<3)
  elif operation in ['start','end','stop']:
   item['flags']&=0xfffffffe
   if operation!='stop':item['frameBits']=bits(start if operation=='start'else end)
  elif operation=='seek'and source.get('owner',True):
   item['flags']&=0xfffffffe
   frame=wide.store(wide.add(wide.mul(wide.add(wide.wide(end),wide.wide(-start)),wide.wide(argument)),wide.wide(start)))
   if frame==0 and start==0:frame=math.copysign(0.,(end-start)*argument+start)
   if end*direction<frame*direction:frame=end
   if frame*direction<start*direction:frame=start
   item['frameBits']=bits(frame)
 if operation=='play'and not(target['controlFlags']&4)and options.get('queue',True):model['queue'].append(index);target['controlFlags']|=4

def obstacle(model,nodes,options,index,backwards=False,snap=False):
 if snap:control(model,nodes,options,'start'if backwards else'end',index);return
 control(model,nodes,options,'loop',index,options.get('loopMode',2)==2)
 speed=options.get('speed',1);forward=options.get('forwardRate',2);backward=options.get('backwardRate',3)
 rate= -speed*(forward if speed<0 else backward)if backwards else speed*(backward if speed<0 else forward)
 control(model,nodes,options,'play',index,f32(rate))

def parse_command(kind,tokens,options,nodes,first=True):
 model=model_state(nodes,options)
 if kind=='scp'and(not first or not tokens):return model
 selected=None;name=None;backwards=False;snap=False;stayopen=stayshut=False
 for raw in tokens:
  text=trim(raw);upper=fold(text);marker='NAME='if kind=='scp'else'NAME'
  at=upper.find(marker)
  if at>=0:
   suffix=text[at+5:]
   if kind=='scp':
    model['calls'].append(['find',0,suffix]);found=lookup(suffix,False)
    if found is not None:selected=found
   else:name=suffix
  elif upper==('BACKWARDS'if kind=='scp'else'BACKWARD'):backwards=True
  elif kind!='scp'and upper=='FORWARD':backwards=False
  elif upper=='SNAP':snap=True
  elif kind!='special'and upper=='STAYOPEN':stayopen=True
  elif kind!='special'and upper=='STAYSHUT':stayshut=True
 if kind!='scp'and name is not None:model['calls'].append(['find',int(kind=='special'),name]);selected=lookup(name,kind=='special')
 if selected is None or selected==2:return model
 if kind=='special':control(model,nodes,options,'start'if backwards else'end',selected)if snap else control(model,nodes,options,'play',selected,-1. if backwards else 1.)
 else:
  obstacle(model,nodes,options,selected,backwards or(kind=='scp'and stayshut),snap)
  t=model['targets'][selected];t['obstacleFlags']=(t['obstacleFlags']&0xfffffff3)|(4 if stayopen else 0)|(8 if stayshut else 0)
 return model
