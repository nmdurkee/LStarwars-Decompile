"""Isolated original scenery clocks and active-group updates; no native replacements."""
from pathlib import Path
import importlib.util,struct,copy,json,math
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('scene_tick_native','native-x86.py');x=module('scene_tick_wide','animation-x87.py');n=nx.NativeX86();B=nx.BASE;D=n.DATA
SCENE=D;DESCRIPTOR=D+0x400;DISPLAY=D+0x1000;NORMAL=D+0x3000;INSTANCE=D+0x4000;TARGET=D+0x5000;MATRIX=D+0x6000;CLIPS=D+0x7000;QUEUE=D+0x8000;GROUP=D+0x9000;NODE=D+0xa000;SALI=D+0x10000;CLIP=D+0x20000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ECX
evaluations=[];poseEvaluations=[];poseCopies=[];clipCache={}
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);reference,frame=n.unpack('<II',sp+4);evaluations.append([(reference-NODE-4)//40,frame])
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x552760,end=0x552760)
def pose_observe(mu,address,size,user):
 if address==0x5ea390:
  sp=mu.reg_read(UC_X86_REG_ESP);_,_,frame,matrix=n.unpack('<4I',sp+4);poseEvaluations.append([(matrix-MATRIX)//64,frame])
 else:poseCopies.append((mu.reg_read(UC_X86_REG_ECX)-TARGET)//0x60)
n.mu.hook_add(UC_HOOK_CODE,pose_observe,begin=0x5ea390,end=0x5ea390)
n.mu.hook_add(UC_HOOK_CODE,pose_observe,begin=0x5c19d0,end=0x5c19d0)
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def value(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f32(v):return value(bits(v))
def W(v):return x.wide(v)
def add(a,b):return x.add(a,b)
def sub(a,b):return x.add(a,(-b[0],b[1]))
def scalar(a):return x.store(a)
def signed(value,reference):return math.copysign(0.,reference)if value==0 else value
def stored_add(a,b):return signed(scalar(add(W(a),W(b))),a+b)
def stored_sub(a,b):return signed(scalar(sub(W(a),W(b))),a-b)
def setup_groups(groups):
 n.write(D,bytes(0x18000));evaluations.clear();n.pack('<III',SCENE+0x4c,TARGET,MATRIX,CLIPS)
 cursor=0;nodeRows=[]
 for gi,g in enumerate(groups):
  address=GROUP+gi*64;queue=g.get('queue',True);queued=g.get('queued',queue)
  n.pack('<H',address+10,g.get('flags',4));n.pack('<i',address+12,g.get('state',4));n.pack('<I',address+20,QUEUE if queue else 0);n.pack('<I',address+24,NODE+cursor*40 if g['nodes']else 0)
  for j,o in enumerate(g['nodes']):
   at=NODE+cursor*40;t=TARGET+cursor*0x60;display=DISPLAY+cursor*0xd0;normal=NORMAL+cursor*0x80;instance=INSTANCE+cursor*0x60
   n.pack('<I',at,NODE+(cursor+1)*40 if j+1<len(g['nodes'])else 0)
   kind=o.get('kind',2);n.pack('<III',at+4,SCENE if kind else 0,normal if kind==1 else 0,display if kind==2 else 0);n.pack('<IIff',at+16,t if o.get('present',True)else 0,1,o['start'],o['end'])
   n.pack('<I',normal+0x40,instance);n.pack('<II',instance+0x44,o.get('instanceFlags',0),t);n.pack('<I',display+0xb8,o.get('displayFlags',0));n.pack('<I',display+0xc4,t)
   n.pack('<ffffIffHH',t+0x40,o.get('rate',1.),0.,0.,o['frame'],o.get('targetFlags',1),0.,0.,0,cursor)
   nodeRows.append(o);cursor+=1
 for gi,g in enumerate(groups):
  if g.get('queued',g.get('queue',True)):n.call(0x4f1310,[QUEUE,GROUP+gi*64])
 return nodeRows
def group_state(groups,rows):
 result={'groups':[[n.unpack('<H',GROUP+i*64+10)[0],n.unpack('<i',GROUP+i*64+12)[0]]for i in range(len(groups))],
  'targets':[list(n.unpack('<I',TARGET+i*0x60+0x4c))+list(n.unpack('<I',TARGET+i*0x60+0x40))+list(n.unpack('<I',TARGET+i*0x60+0x50))for i in range(len(rows))],
  'specials':[[n.unpack('<I',INSTANCE+i*0x60+0x44)[0],n.unpack('<I',DISPLAY+i*0xd0+0xb8)[0]]for i in range(len(rows))],'queue':[],'evaluations':copy.deepcopy(evaluations)}
 p=n.unpack('<I',QUEUE)[0]
 while p:
  if len(result['queue'])>len(groups):raise ValueError('Queue cycle')
  result['queue'].append((p-GROUP)//64);p=n.unpack('<I',p)[0]
 return result
def group_model(groups,operation='update',selected=0):
 groups=copy.deepcopy(groups);rows=[o for g in groups for o in g['nodes']];r={'groups':[[g.get('flags',4),g.get('state',4)]for g in groups],'targets':[[bits(o['frame']),bits(o.get('rate',1.)),o.get('targetFlags',1)]for o in rows],'specials':[[o.get('instanceFlags',0),o.get('displayFlags',0)]for o in rows],'queue':[i for i,g in enumerate(groups)if g.get('queued',g.get('queue',True))],'evaluations':[]};offsets=[];i=0
 for g in groups:offsets.append(i);i+=len(g['nodes'])
 def refresh(gi):
  if r['groups'][gi][0]&4:return
  atStart=atEnd=True
  for j,o in enumerate(groups[gi]['nodes']):
   if not o.get('present',True):continue
   t=r['targets'][offsets[gi]+j];direction=1 if o['start']<=o['end']else-1;frame=value(t[0])*direction
   atStart&=frame<=o['start']*direction;atEnd&=frame>=o['end']*direction
  r['groups'][gi][1]=2 if atEnd else 0 if atStart else 4
 def remove(gi):
  if not groups[gi].get('queue',True):return
  if r['groups'][gi][0]&4:
   r['queue'].remove(gi);r['groups'][gi][0]&=0xfffb
  refresh(gi)
 if operation=='remove':remove(selected);return r
 if operation=='reset':
  for j,o in enumerate(groups[selected]['nodes']):
   if o.get('present',True):
    t=r['targets'][offsets[selected]+j];t[0]=bits(o['start']);t[1]=bits(1.);t[2]&=0xfffffffa
   remove(selected)
  return r
 for gi in r['queue'].copy():
  status=r['groups'][gi];previous=status[0];status[0]&=0xfffe
  if previous&2:status[0]=previous&0xfffc;remove(gi);continue
  status[1]=0;forward=atStart=atEnd=True;anyNo=False
  for j,o in enumerate(groups[gi]['nodes']):
   ix=offsets[gi]+j;t=r['targets'][ix];sp=r['specials'][ix];kind=o.get('kind',2);anyNo|=bool(sp[0]&8 if kind==1 else sp[1]&128 if kind==2 else 0)
   if not o.get('present',True):continue
   start,end=o['start'],o['end'];direction=1 if start<=end else-1;prior=value(t[0]);rate=value(t[1])*direction;frame=prior
   if prior*direction>=end*direction:
    if rate<0:frame=end
    elif t[2]&8:frame=stored_add(stored_sub(prior,end),start)
    else:frame=end;t[2]&=0xfffffffe
   elif prior*direction<=start*direction:
    if rate>0:frame=start
    elif t[2]&8:frame=stored_sub(end,stored_sub(start,prior))
    else:frame=start;t[2]&=0xfffffffe
   t[0]=bits(frame)
   if frame!=prior:r['evaluations'].append([ix,bits(frame)])
   if t[2]&1:status[0]|=1;forward&=rate>=0
   atStart&=frame*direction<=start*direction;atEnd&=frame*direction>=end*direction
  if bool(status[0]&1)!=anyNo:
   for j,o in enumerate(groups[gi]['nodes']):
    sp=r['specials'][offsets[gi]+j];kind=o.get('kind',2)
    if kind==1:sp[0]=(sp[0]&0xfffffff7)|(8 if status[0]&1 else 0)
    elif kind==2:sp[1]=(sp[1]&0xffffff7f)|(128 if status[0]&1 else 0)
  if not(status[0]&1):
   status[1]=2 if atEnd else 0 if atStart else 4
   if previous&1:status[0]|=2
  else:status[1]=1 if forward else 3
  if not(status[0]&3):remove(gi)
 return r

def setup_scene(options):
 n.write(D,bytes(0x18000));poseEvaluations.clear();poseCopies.clear();n.pack('<hhIII',SCENE+0x48,len(options['instances']),options.get('dataCount',1),TARGET,MATRIX,CLIPS if options.get('table',True)else 0);n.pack('<I',SCENE+0x110,DESCRIPTOR);n.pack('<I',DESCRIPTOR+0x70,DISPLAY)
 if options.get('clip'):
  key=(options['clip']['source'],options['clip']['animationIndex'])
  if key not in clipCache:
   data=json.loads((B/'exports/animation-scenes'/(key[0]+'.json')).read_text());animation=data['animations'][key[1]];h=animation['header'];offset=animation['sourceOffset'];raw=(B/'extracted'/key[0]).read_bytes();blob=bytearray(raw[offset:offset+h['flagsOffset']+h['nodeCount']+16]);magic=struct.unpack_from('<I',blob)[0]
   for p in [36,40,44,48,52,56]:
    v=struct.unpack_from('<i'if magic==0x414e4935 else'<I',blob,p)[0]
    if v:struct.pack_into('<I',blob,p,CLIP+v+(p if magic==0x414e4935 else 0))
   clipCache[key]=bytes(blob)
  n.write(CLIP,clipCache[key]);n.pack('<I',CLIPS,CLIP);n.pack('<I',0x973880,D+0xc000);n.pack('<I',D+0xc008,D+0xc100);n.write(0x9737de,b'\0');n.write(0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes())
 tracks=options.get('tracks');n.pack('<I',SCENE+0x1e0,SALI if tracks is not None else 0);n.pack('<i',SALI-4,options.get('owners',2))
 if tracks is not None:
  for i,t in enumerate(tracks):
   times=SALI+0x100+i*0x1000;values=times+0x800;n.pack('<HHII',SALI+i*12,len(t['times']),t['end'],times,values);n.pack('<'+'f'*len(t['times']),times,*t['times']);n.write(values,bytes(t['values']))
 for i,o in enumerate(options['instances']):
  t=TARGET+i*0x60;n.pack('<ffffIffHH',t+0x40,o['rate'],o['first'],o['interval'],o['frame'],o['flags'],0.,o['previous'],o.get('animationIndex',0),i);n.pack('<I',DISPLAY+i*0xd0+0xb8,o.get('displayFlags',2))
def scene_state(options):return {'instances':[{'frame':n.unpack('<I',TARGET+i*0x60+0x4c)[0],'flags':n.unpack('<I',TARGET+i*0x60+0x50)[0],'previous':n.unpack('<I',TARGET+i*0x60+0x58)[0],'displayFlags':n.unpack('<I',DISPLAY+i*0xd0+0xb8)[0]}for i in range(len(options['instances']))],'lookupPresent':n.unpack('<I',SCENE+0x1e0)[0]!=0,'evaluations':copy.deepcopy(poseEvaluations),'copies':poseCopies.copy()}
def scene_model(options,delta):
 opts=copy.deepcopy(options);tracks=opts.get('tracks');rows=opts['instances'];lookup=tracks is not None
 if opts.get('table',True)and lookup and opts.get('owners',2)<2:lookup=False
 evaluation=0.;evals=[];copies=[]
 for ix,o in enumerate(rows):
  if not opts.get('table',True)or o.get('animationIndex',0)>=opts.get('dataCount',1):continue
  index=o['flags']>>22;state=tracks[index-1]if index and lookup else None
  if state is None and not(o.get('displayFlags',2)&2):continue
  hasClip=bool(opts.get('clip'))
  if state is None and not hasClip:continue
  end=float(opts['clip']['end']if hasClip else state['end'])
  if end==0:continue
  if not(o['flags']&1):evaluation=o['frame']
  else:
   o['frame']=signed(scalar(add(x.mul(W(o['rate']),W(delta)),W(o['frame']))),o['rate']*delta+o['frame'])
   if o['flags']&4 and o['frame']>=o['first']:o['flags']&=0xfffffffb;o['frame']=scalar(sub(W(o['frame']),sub(W(o['first']),W(1))))
   if not(o['flags']&4):
    intervalEnd=add(W(o['interval']),W(end));evaluation=end
    if scalar(sub(W(o['frame']),intervalEnd))<0:
     if o['frame']<=end:
      if o['frame']>=1:evaluation=o['frame']
      else:o['frame']=evaluation=1.;o['flags']&=0xfffffffe
    elif not(o['flags']&8):o['flags']&=0xfffffffe;o['frame']=end
    else:
     ratio=scalar(x.div(sub(W(o['frame']),W(1)),sub(intervalEnd,W(1))));count=f32(int(ratio));amount=scalar(x.mul(sub(add(W(end),W(o['interval'])),W(1)),W(count)));o['frame']=scalar(sub(W(o['frame']),W(amount)));evaluation=o['frame']
    if o['flags']&2:evaluation=scalar(sub(add(W(end),W(1)),W(evaluation)))
  if o['previous']!=evaluation:
   if state is not None:
    cursor=min((o['flags']>>14)&255,len(state['times'])-1);before=state['values'][cursor]
    if state['times'][cursor]>evaluation:
     while cursor>0 and state['times'][cursor]>evaluation:cursor-=1
    else:
     while cursor+1<len(state['times'])and state['times'][cursor+1]<=evaluation:cursor+=1
    val=state['values'][cursor];o['flags']=(o['flags']&0xffc03fff)|(cursor<<14)
    if val!=before:
     o['displayFlags']=(o.get('displayFlags',2)&0xfffffffd)|(2 if val else 0)
     if val==0:hasClip=False
   if hasClip:evals.append([ix,bits(evaluation)])
   o['previous']=evaluation
  if hasClip:copies.append(ix)
 return {'instances':[{'frame':bits(o['frame']),'flags':o['flags'],'previous':bits(o['previous']),'displayFlags':o.get('displayFlags',2)}for o in rows],'lookupPresent':lookup,'evaluations':evals,'copies':copies}
