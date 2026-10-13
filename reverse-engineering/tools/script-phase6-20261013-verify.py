"""Original hint producers, Force dispatch/output and socket affine/distance.
No native helper is replaced; all mutable state and source-derived fixtures retained.
"""
import importlib.util,json,struct,itertools,random,re,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn.x86_const import UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;PACK=D+0x1000;SCRIPT=D+0x2000;ARGS=D+0x3000;TEXT=D+0x4000;HINTS=D+0x10000;REGISTERED=D+0x13000;DONE=D+0x18000;RESULT=D+0x19000;CRE=D+0x1a000;REF=D+0x1b000;SELF=D+0x1c000;PLAYER=D+0x1e000;SOCKREG=D+0x21000;SOCKROWS=D+0x30000;SEGMENTS=D+0x50000;REGISTRY=D+0x22000;BUCKET=D+0x23000;TYPES=D+0x24000;TYPEGLOBAL=D+0x25000;GIZMO=D+0x26000;FORCE=D+0x27000;GROUP=D+0x28000;LINK=D+0x29000;LIST=D+0x2a000;COND=D+0x2a100;DEF=D+0x2a200
checks={};errors=[];hintcases=[];forcecases=[];socketcases=[];initializers=[];shipped=[];comparison_omissions=[]
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def fl(x):return struct.unpack('<f',struct.pack('<I',x))[0]
def f32(x):return fl(bits(x))
def token(t):
 if t is None:return 0
 n.write(TEXT+0x4000,t.encode()+b'\0');return TEXT+0x4000
def base(tokens=None,c=None):
 c=c or {};tokens=tokens or [];n.write(D,bytes(0x70000));n.pack('<I',0x802c54,SYS);n.pack('<I',PACK+4,SCRIPT if c.get('script',True)else 0);n.pack('<4f',PACK+0x14,*c.get('parameters',[1.75,2.,7.,-1.]))
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.write(TEXT+0x3000+i*128,name.encode()+b'\0');n.pack('<I',SCRIPT+0x18+i*8,TEXT+0x3000+i*128)
 for i,t in enumerate(tokens):
  if t is None:n.pack('<I',ARGS+i*4,0)
  else:n.write(TEXT+i*512,t.encode()+b'\0');n.pack('<I',ARGS+i*4,TEXT+i*512)
def floating(a,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(a,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]
def num(t,c):
 if t is None:return 0.
 if c.get('packet',True):
  if 'param'in t.lower():return f32(c.get('parameters',[1.75,2.,7.,-1.])[0])
  if c.get('script',True)and t.lower()in ['alpha','beta','gamma','delta']:return f32(c.get('parameters',[1.75,2.,7.,-1.])[['alpha','beta','gamma','delta'].index(t.lower())])
 i=0;v=0.;d=1.
 if t.startswith('-'):i=1;d=-1.
 while i<len(t)and'0'<=t[i]<='9':v=f32(f32(v*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':d=f32(d*10);v=f32(f32(v*10)+int(t[i]));i+=1
 return f32(v/d)
def hinit(c,tokens=None):
 base(tokens,c);rows=c.get('rows',[dict(id=1,flags=0,complete=0,cooldownBits=bits(2.5),timerBits=0),dict(id=2,flags=1,complete=0,cooldownBits=bits(5.),timerBits=0),dict(id=-1,flags=0,complete=0,cooldownBits=0,timerBits=0)])
 n.pack('<I',0x9514b4,HINTS if c.get('list',True)else 0)
 for i,row in enumerate(rows):p=HINTS+i*0x1c;n.pack('<hB',p,row['id'],row['flags']);n.pack('<I',p+0xc,row['cooldownBits']);n.pack('<B',p+0x14,row['complete']);n.pack('<I',p+0x18,row['timerBits'])
 active=c.get('activeIndex');n.pack('<I',0x9514b8,HINTS+active*0x1c if active is not None else 0);n.pack('<B',0x9514bd,c.get('lastVariant',0));n.pack('<II',0x9514c8,c.get('counterC8Bits',bits(12.5)),c.get('counterCcBits',bits(-3.25)));n.pack('<I',0x80253c,c.get('rng',1));n.pack('<I',0x926c20,REGISTERED)
 for idx in c.get('registered',[0,1,2,7]):assert 0<=idx<=32767;n.pack('<I',REGISTERED+idx*4,0xdeadbeef)
 words=c.get('doneWords',[0x80000000,0x12340000]);n.pack('<I',0x9514c0,DONE if c.get('bitmap',True)else 0);n.pack('<i',0x9514c4,c.get('doneWordCount',len(words)))
 for i,word in enumerate(words):n.pack('<I',DONE+i*4,word)
 return rows
def hsnap(rows,c):
 active=n.unpack('<I',0x9514b8)[0];return dict(activeIndex=(active-HINTS)//0x1c if active else None,lastVariant=n.unpack('<B',0x9514bd)[0],rng=n.unpack('<I',0x80253c)[0],counterC8Bits=n.unpack('<I',0x9514c8)[0],counterCcBits=n.unpack('<I',0x9514cc)[0],rows=[dict(complete=n.unpack('<B',HINTS+i*0x1c+0x14)[0],timerBits=n.unpack('<I',HINTS+i*0x1c+0x18)[0])for i in range(len(rows))],doneWords=[n.unpack('<I',DONE+i*4)[0]for i in range(len(c.get('doneWords',[0x80000000,0x12340000])))])
def hexpected(rows,c,method,requested=None,force=False,ignore=False,target=None,tokens=None):
 out=dict(activeIndex=c.get('activeIndex'),lastVariant=c.get('lastVariant',0),rng=c.get('rng',1),counterC8Bits=c.get('counterC8Bits',bits(12.5)),counterCcBits=c.get('counterCcBits',bits(-3.25)),rows=[dict(complete=r['complete'],timerBits=r['timerBits'])for r in rows],doneWords=list(c.get('doneWords',[0x80000000,0x12340000])))
 def mark(index):
  if not c.get('list',True)or not c.get('bitmap',True):return
  for i,row in enumerate(rows):
   if row['id']==-1:return
   if row['id']==rows[index]['id']:
    word=i>>5
    if word<c.get('doneWordCount',len(out['doneWords'])):out['doneWords'][word]|=1<<(i&31)
    return
 def activate(index):
  if out['activeIndex']is not None and out['activeIndex']==index:return
  if index is None:out['activeIndex']=None;return
  row=rows[index];timer=fl(row['timerBits'])
  if not force and((row['complete']!=0 and not ignore)or not(timer<=0 or timer!=timer)):return
  out['activeIndex']=index;out['counterC8Bits']=out['counterCcBits']=0
  if not force and row['flags']&1:out['rows'][index]['complete']=1;mark(index)
  for step in range(1000):
   out['rng']=((out['rng']*0x24cd)+1)&65535;variant=out['rng']//16384
   if variant!=out['lastVariant']:out['lastVariant']=variant;break
  else:raise AssertionError('Fixture RNG loop did not terminate')
  out['counterCcBits']=0;out['rows'][index]['timerBits']=row['cooldownBits']
 if method=='SetHint':
  requested=-1;force=False;ignore=False
  for t in tokens:
   at=(t or '').lower().find('id')
   if at>=0:requested=int(num(t[at+3:],c))
   elif'ignore_done_flag'in(t or '').lower():ignore=True
  if not c.get('first',True):return out
 if method=='Activate':activate(target)
 elif method=='MarkDone':mark(target)
 elif method in ['Request','SetHint']:
  if out['activeIndex']is not None and rows[out['activeIndex']]['id']==requested:return out
  if requested<0 or requested not in c.get('registered',[0,1,2,7]):out['activeIndex']=None
  elif c.get('list',True):
   for i,row in enumerate(rows):
    if row['id']==-1:break
    if row['id']==requested:activate(i);break
 return out
def hintcase(c,method,requested=1,force=False,ignore=False,target=0,tokens=None,source=None):
 rows=hinit(c,tokens);before=hsnap(rows,c)
 if method=='SetHint'and c.get('first',True)and any(t is None for t in(tokens or [])):
  try:n.call(0x44d470,[SYS,PACK if c.get('packet',True)else 0,0,ARGS,len(tokens or []),1])
  except RuntimeError as e:check('SetHint-null-token-native-fault',True,True);check('SetHint-null-token-state-before-fault',hsnap(rows,c),before);hintcases.append(dict(method=method,context=c,rows=rows,requested=requested,force=force,ignore=ignore,target=target,tokens=tokens,nativeFault=str(e),native=before));return
  check('SetHint-null-token-native-fault',False,True);return
 if method=='SetHint':ret=n.call(0x44d470,[SYS,PACK if c.get('packet',True)else 0,0,ARGS,len(tokens or []),int(c.get('first',True))]);check('SetHint-return',ret,1)
 elif method=='Request':n.call(0x576910,[requested,int(force),int(ignore)])
 elif method=='Activate':n.call(0x576860,[HINTS+target*0x1c if target is not None else 0,int(force),int(ignore)])
 else:n.call(0x5766e0,[HINTS+target*0x1c])
 got=hsnap(rows,c);want=hexpected(rows,c,method,requested,force,ignore,target,tokens);check('hint-producer-full-state-'+method,got,want,c);hintcases.append(dict(method=method,context=c,rows=rows,requested=requested,force=force,ignore=ignore,target=target,tokens=tokens,native=got,**({'source':source}if source else{})))
# Eligibility, repeated pointer/ID, sentinel, bitmap flags and timer/cooldown state.
for method,active,complete,flag,timer,force,ignore in itertools.product(['Request','Activate'],[None,0,1],[0,1,255],[0,1],[bits(-1.),0,bits(.25),0x7fc00000],[False,True],[False,True]):
 rows=[dict(id=1,flags=flag,complete=complete,cooldownBits=bits(9.5),timerBits=timer),dict(id=2,flags=0,complete=0,cooldownBits=bits(2.),timerBits=0),dict(id=-1,flags=0,complete=0,cooldownBits=0,timerBits=0)];hintcase(dict(rows=rows,activeIndex=active),method,force=force,ignore=ignore)
for requested,listing,registered,active in itertools.product([-2,-1,0,1,2,3,7],[False,True],[False,True],[None,0,1]):hintcase(dict(list=listing,registered=[0,1,2,3,7]if registered else[],activeIndex=active),'Request',requested=requested)
for seed,last in itertools.product([0,1,2,17,65535,0xffffffff]+list(range(64)),[0,1,2,3,255]):hintcase(dict(rng=seed,lastVariant=last),'Activate')
# Done bitmap uses first matching ID ordinal and bounds declared word count.
for ordinal,count,present in itertools.product([0,1,31,32,33,63],[0,1,2,-1],[False,True]):
 rows=[dict(id=i+1,flags=1,complete=0,cooldownBits=bits(4.),timerBits=0)for i in range(64)]+[dict(id=-1,flags=0,complete=0,cooldownBits=0,timerBits=0)];hintcase(dict(rows=rows,doneWordCount=count,bitmap=present),'MarkDone',target=ordinal)
# Registered but missing target preserves active; unregistered clears it.
rows=[dict(id=1,flags=1,complete=0,cooldownBits=0x7fc12345,timerBits=0),dict(id=1,flags=1,complete=0,cooldownBits=bits(7.),timerBits=0),dict(id=-1,flags=0,complete=0,cooldownBits=0,timerBits=0)]
hintcase(dict(rows=rows),'Activate',target=1);hintcase(dict(rows=rows),'Activate',target=None)
tokensets=[[],[None],['id=1'],['ID=2'],['prefixid=1'],['id=1','id=2'],['id=2','id=1'],['id=-1'],['ignore_done_flag'],['id=1','prefixignore_done_flag'],['id=1','ignore_done_flagID=2'],['id=param3'],['id=alpha'],['id=beta'],['id:2'],['id=0.99999994']]
for ts,first,packet,script,done in itertools.product(tokensets,[False,True],[False,True],[False,True],[False,True]):
 rows=[dict(id=1,flags=1,complete=int(done),cooldownBits=bits(2.),timerBits=0),dict(id=2,flags=0,complete=int(done),cooldownBits=bits(4.),timerBits=0),dict(id=-1,flags=0,complete=0,cooldownBits=0,timerBits=0)];hintcase(dict(rows=rows,first=first,packet=packet,script=script),'SetHint',tokens=ts)
# CurrentHintId original signed-short helper and x87 wrapper complete word samples.
currentcases=[]
for active,id in itertools.product([False,True],[-32768,-1,0,1,32767]+[random.Random(0x576460+i).randrange(-32768,32768)for i in range(256)]):
 rows=hinit(dict(rows=[dict(id=id,flags=0,complete=0,cooldownBits=0,timerBits=0)],activeIndex=0 if active else None));iv=n.call(0x576460);got=floating(0x442a10,[]);want=id if active else -1;check('CurrentHintId-signed-int-helper',iv,want&0xffffffff);check('CurrentHintId-float-reader',got,bits(float(want)));currentcases.append(dict(active=active,id=id,nativeInt=iv,nativeBits=got))
# Actual generic Force registry/name/output/completion helpers, no callback hooks.
def finit(c=None,name='Alpha'):
 c=c or {};base(c=c);n.pack('<I',SYS+0x2ac8,REGISTRY);n.pack('<I',0x93b268,TYPEGLOBAL if c.get('typeTable',True)else 0);n.pack('<II',TYPEGLOBAL,c.get('typeCount',3),0);n.pack('<I',TYPEGLOBAL+8,TYPES);n.pack('<I',REGISTRY,BUCKET);n.pack('<i',0x7f8cc4,c.get('forceType',1))
 for t in range(4):n.pack('<II',TYPES+t*0x9c+0x44,0x558770,0x467b40 if c.get('callback',True)else 0);n.pack('<I',BUCKET+t*0x14+4,1);n.pack('<I',BUCKET+t*0x14+0xc,GIZMO)
 n.pack('<I',GIZMO,FORCE if c.get('target',True)else 0);n.pack('<B',GIZMO+6,c.get('recordType',1));n.write(FORCE,name.encode()+b'\0');n.pack('<I',FORCE+0xa0,c.get('flags',0));n.pack('<h',FORCE+0x88,c.get('mode',-1));n.pack('<I',FORCE+0x28,GROUP if c.get('group',True)else 0);n.pack('<i',GROUP+0xc,c.get('groupState',2));n.pack('<I',FORCE+0x40,LINK if c.get('link',True)else 0);n.pack('<B',LINK+0x24,c.get('linkFlags',6));n.pack('<I',FORCE+0x74,c.get('flags74',0));n.pack('<I',FORCE+0x4c,c.get('timerBits',0))
def force_expected(c,output,include):
 flags=c.get('flags',0);group=c.get('group',True);state=c.get('groupState',2)
 if not include and not((flags&2 or c.get('mode',-1)!=-1)and flags&1):return 0
 if output==0:return int(group and state==2)
 if output==1:return int(group and state!=0)
 if output==2:return int(group and state==0)
 if output in [3,4]:return int(c.get('link',True)and c.get('linkFlags',6)&(2 if output==3 else 4)!=0)
 if output==5:return int(flags&0x10000!=0)
 if output==7:return int(flags&0x200000!=0)
 if output==6:
  a=c.get('flags74',0);timer=fl(c.get('timerBits',0));return int(a&2==0 and(timer<=0 or flags&0x2000)and(a&0x40==0 or flags&0x800)and(not group or state==(0 if flags&0x40 else 2)))
 return 0
for output,include,flags,mode,group,state,linkflag in itertools.product(range(9),[0,1],[0,1,2,3,0x10000,0x200000,0xffffffff],[-1,0],[False,True],[-1,0,1,2,3],[0,2,4,6]):
 c=dict(flags=flags,mode=mode,group=group,groupState=state,linkFlags=linkflag);finit(c);got=n.call(0x467b40,[GIZMO,output,include]);check('ForceOutput-actual-handler-all-output-gates',got,force_expected(c,output,include),c);forcecases.append(dict(method='Output',context=c,output=output,include=include,nativeReturn=got))
# ForceAtEnd ignores reverse-completion flags and calls output0/includeInactive1.
for bound,table,callback,type_ok,group,state,flags in itertools.product([False,True],[False,True],[False,True],[False,True],[False,True],[0,1,2],[0,0x40]):
 c=dict(bound=bound,typeTable=table,callback=callback,recordType=1 if type_ok else 3,group=group,groupState=state,flags=flags);finit(c);got=floating(0x440a90,[SYS,PACK,CRE,0,GIZMO if bound else 0]);want=bits(float(bound and table and callback and type_ok and group and state==2));check('ForceAtEnd-native-output-dispatch',got,want,c);forcecases.append(dict(method='AtEnd',context=c,nativeBits=got))
finit(dict(target=False))
try:floating(0x440a90,[SYS,PACK,CRE,0,GIZMO])
except RuntimeError as e:check('ForceAtEnd-null-target-fault',True,True);forcecases.append(dict(method='AtEnd',context=dict(target=False,bound=True),nativeFault=str(e)))
else:check('ForceAtEnd-null-target-fault',False,True)
for operand,typ in itertools.product([None,'','alpha','missing'],[-1,0,1,3,4]):
 finit(dict(forceType=typ));got=n.call(0x440a30,[SYS,token(operand),0]);want=GIZMO if operand and operand.lower()=='alpha'else 0;check('ForceAtEnd-original-initializer',got,want);initializers.append(dict(operand=operand,forceType=typ,nativePointer=got))
# Independent finite binary integer arithmetic models x87 precision64 then F32.
def binary(raw):
 field=(raw>>23)&255;mant=raw&0x7fffff;assert field!=255;return(-1 if raw>>31 else 1)*(mant if field==0 else mant|0x800000),-149 if field==0 else field-150

def round_shift(m,s):
 if s<=0:return m<<-s
 q,r=divmod(m,1<<s);half=1<<(s-1);return q+int(r>half or(r==half and q&1))
def wide_round(m,e):
 if m==0:return 0,e
 sign=-1 if m<0 else 1;a=abs(m);s=max(0,a.bit_length()-64);return sign*round_shift(a,s),e+s

def store(m,e,zero=0):
 if m==0:return zero
 sign=0x80000000 if m<0 else 0;a=abs(m);highest=e+a.bit_length()-1
 if highest<-126:return sign|round_shift(a,-149-e)
 s=a.bit_length()-24;q=round_shift(a,s);field=e+s+150
 if q==1<<24:q>>=1;field+=1
 if field>=255:return sign|0x7f800000
 return sign|(field<<23)|(q&0x7fffff)
def affine(scale,progress,offset):
 sm,se=binary(scale);pm,pe=binary(progress);om,oe=binary(offset);prod=sm*pm;exp=se+pe;basee=min(exp,oe);m=(prod<<(exp-basee))+(om<<(oe-basee));m,e=wide_round(m,basee);zero=0x80000000 if prod==0 and om==0 and(scale^progress)&0x80000000 and offset&0x80000000 else 0;return store(m,e,zero)
def sub(a,b):
 am,ae=binary(a);bm,be=binary(b);basee=min(ae,be);m=(am<<(ae-basee))-(bm<<(be-basee));m,e=wide_round(m,basee);zero=0x80000000 if am==0 and bm==0 and a>>31 and not b>>31 else 0;return store(m,e,zero)
def sinit(c):
 base(c=c);n.pack('<I',SYS+0x2988,SOCKREG if c.get('registry',True)else 0);n.pack('<I',SOCKREG,SOCKROWS);n.pack('<I',CRE+0xd0,REF if c.get('reference',True)else 0);n.pack('<I',REF,SELF if c.get('target',True)else 0);n.pack('<I',0x93d810,PLAYER if c.get('player',True)else 0)
 for index in [-2,0,1,2]:n.pack('<I',SOCKROWS+index*0x13c+0x34,SEGMENTS+0x200)
 for segment in [-2,-1,0,1,2]:n.pack('<II',SEGMENTS+0x200+segment*0x80+0x78,c.get('scaleBits',bits(10.)),c.get('offsetBits',bits(3.)))
 for p,index,seg,progress in [(SELF,c.get('selfSocket',0),c.get('selfSegment',0),c.get('selfProgressBits',bits(.25))),(PLAYER,c.get('playerSocket',0),c.get('playerSegment',0),c.get('playerProgressBits',bits(.75)))]:n.pack('<bhI',p+0x671,index,seg,progress)
 # bhI packs socket at+671,segment+672,progress+674 exactly.
for primitive,socket,segment in itertools.product([False,True],[-2,-1,0,1,2],[-2,-1,0,1,2]):
 c=dict(selfSocket=socket,selfSegment=segment);sinit(c);got=floating(0x53f7a0,[SOCKREG if primitive else 0,SELF+0x670]);want=affine(c.get('scaleBits',bits(10.)),c.get('selfProgressBits',bits(.25)),c.get('offsetBits',bits(3.)))if primitive and socket!=-1 else 0;check('SocketScalar-native-signed-indices',got,want,c);socketcases.append(dict(method='Scalar',context=dict(c,registry=primitive),nativeBits=got))
for creature,reference_present,target,player,reg,ps,ss in itertools.product([False,True],[False,True],[False,True],[False,True],[False,True],[-1,0,1],[-1,0,1]):
 c=dict(creature=creature,reference=reference_present,target=target,player=player,registry=reg,playerSocket=ps,selfSocket=ss);sinit(c)
 if creature and reference_present and player and ps!=-1 and not target:
  try:floating(0x442790,[SYS,PACK,CRE,0,0])
  except RuntimeError as e:check('SockDistance-null-target-fault',True,True);socketcases.append(dict(method='Distance',context=c,nativeFault=str(e)));continue
  check('SockDistance-null-target-fault',False,True);continue
 got=floating(0x442790,[SYS,PACK,CRE if creature else 0,0,0]);want=bits(5.)if creature and reference_present and target and player and reg and ps==ss and ps!=-1 else 0;check('SockDistance-native-pointer-socket-gates',got,want,c);socketcases.append(dict(method='Distance',context=c,nativeBits=got))
rng=random.Random(0x53f7a0);nums=[bits(x)for x in [-1e20,-10.,-1.,-.5,-0.,0.,.25,1.,10.,1e20]]+[1,0x80000001,0x00800000,0x80000000]
for i in range(1024):
 scale=rng.choice(nums);offset=rng.choice(nums);a=rng.choice(nums[:10]);b=rng.choice(nums[:10]);av=affine(scale,a,offset);bv=affine(scale,b,offset)
 if(av&0x7f800000)==0x7f800000 or(bv&0x7f800000)==0x7f800000:continue
 c=dict(scaleBits=scale,offsetBits=offset,playerProgressBits=a,selfProgressBits=b);sinit(c);sgot=floating(0x53f7a0,[SOCKREG,SELF+0x670]);check('SocketScalar-finite-x87-rounding',sgot,bv,c);socketcases.append(dict(method='Scalar',context=c,nativeBits=sgot));got=floating(0x442790,[SYS,PACK,CRE,0,0]);check('SockDistance-finite-stored-scalar-subtraction',got,sub(av,bv),c);socketcases.append(dict(method='Distance',context=c,nativeBits=got))
# All62cataloged uses: actual mutable hint state, real Force callback, and finite
# socket scalars with original condition comparator, preserving source text.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'));ops={'==':(0,lambda a,b:a==b),'!=':(5,lambda a,b:a!=b),'<':(1,lambda a,b:a<b),'>':(2,lambda a,b:a>b),'<=':(3,lambda a,b:a<=b),'>=':(4,lambda a,b:a>=b)}
for row in ledger['rows']:
 name=row['name']
 if name not in ['SetHint','CurrentHintId','ForceAtEnd','SockDistanceToPlayer']:continue
 for use in row['uses']:
  if name=='SetHint':
   ids=[int(float(t[3:]))for t in use['args']if t.lower().startswith('id=')];requested=ids[-1]if ids else -1;rows=[dict(id=requested if requested>=0 else 1,flags=1,complete=0,cooldownBits=bits(3.),timerBits=0),dict(id=-1,flags=0,complete=0,cooldownBits=0,timerBits=0)]
   for first in [False,True]:hintcase(dict(rows=rows,registered=[requested]if requested>=0 else[],first=first),'SetHint',tokens=use['args'],source=use)
   shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text']));continue
  q=re.findall(r'"([^"]*)"',use['text']);operand=q[0]if q else None;line=use['line'];bound=0;c={}
  if name=='CurrentHintId':c=dict(activeIndex=0 if line%2 else None);rows=hinit(c);address=0x442a10;got=floating(address,[]);want=bits(1. if line%2 else -1.)
  elif name=='ForceAtEnd':c=dict(groupState=2 if line%2 else 1);finit(c,operand);bound=n.call(0x440a30,[SYS,token(operand),0]);address=0x440a90;got=floating(address,[SYS,PACK,CRE,0,bound]);want=bits(float(line%2))
  else:c=dict(playerProgressBits=bits(float(line%5)),selfProgressBits=bits(2.25));sinit(c);address=0x442790;got=floating(address,[SYS,PACK,CRE,0,0]);want=sub(affine(bits(10.),c['playerProgressBits'],bits(3.)),affine(bits(10.),c['selfProgressBits'],bits(3.)))
  check('shipped-'+name+'-body',got,want,use);m=re.search(r'(==|!=|<=|>=|<|>)\s*(-?(?:\d+(?:\.\d*)?|\.\d+))(?:\s+(?:goto|and|or)\b|\s*$)',use['text'],re.I)
  if not m:
   comparison_omissions.append(dict(source=use['source'],line=line,text=use['text'],reason='No explicit comparator or numeric RHS; source loader default/validity not inferred.'))
   shipped.append(dict(command=name,source=use['source'],line=line,text=use['text'],operand=operand,context=c,nativePointer=bound,nativeBits=got,comparison=None));continue
  op=m[1];rhs=float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,rhs);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,bound);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,address);matched=n.call(0x52c880,[SYS,LIST,CRE,PACK],regs={UC_X86_REG_EAX:0})!=0;check('shipped-'+name+'-original-comparison',matched,ops[op][1](fl(got),rhs),use);shipped.append(dict(command=name,source=use['source'],line=line,text=use['text'],operand=operand,context=c,nativePointer=bound,nativeBits=got,comparison=dict(operator=op,thresholdBits=bits(rhs),matched=matched)))
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,z in [(0x44d470,142),(0x576910,70),(0x576860,165),(0x5766e0,99),(0x576460,17),(0x442a10,14),(0x440a30,39),(0x440a90,43),(0x467b40,193),(0x53f7a0,64),(0x442790,132)]:
 code=n.read(a,z);assembly.append(dict(entry=hex(a),size=z,bytes=code.hex(),sha256=hashlib.sha256(code).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in md.disasm(code,a)]))
for row in assembly:
 if row['entry']=='0x467b40':row['jumpTable']=dict(address='0x467c04',targets=[hex(x)for x in n.unpack('<8I',0x467c04)],bytes=n.read(0x467c04,32).hex())
report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,errors=errors[:20],savedHintCases=len(hintcases),savedCurrentCases=len(currentcases),savedForceCases=len(forcecases),savedSocketCases=len(socketcases),savedInitializers=len(initializers),shippedOccurrences=len(shipped),shippedByName={name:sum(x['command']==name for x in shipped)for name in ['SetHint','CurrentHintId','ForceAtEnd','SockDistanceToPlayer']},shippedConditionComparisons=sum(x.get('comparison')is not None for x in shipped),comparisonOmissions=comparison_omissions,method='Unmodified native hint request/activation/list/bitmap/QRAND/parsing/readers; Force named registry/dispatcher/eight-output callback/completion helper; signed socket affine helper and original distance reader; original SCP comparator. All callee pointers are original entries and no instruction hooks replace any native behavior.',adapters=[],limits=['Synthetic prepared hint/registry/socket records and registration backing; loader and reference lifetimes external.','Hint state updates are recovered, not UI rendering, audio playback or future timer ticks.','Quiet NaN timer/cooldown input cases included; signaling NaN/x87 exception policy outside contract.','SetHint numeric conversion finite float32 within int32 range; keyid substring then3-byte advance, valid terminated tokens required.','Socket affine inputs and stored scalar results finite; original64-bit x87 rounding modeled before singlefloat32 store. Final distance overflow to infinity may be preserved.','Negative socket/segment indices exercised only where synthetic backing explicitly exists; no claim about actual live table allocation ranges.','Force completion output6 uses previously recovered finite Force state contract; actual Force simulation external.','Native count includes producer-state/return/assertion correlations; not a whole-game scenario count.','Managed comparison execution pending under established EPERM restriction; no launch retry.'])
(BASE/'reports/script-phase6-20261013-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/script-phase6-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,hintCases=hintcases,currentCases=currentcases,forceCases=forcecases,socketCases=socketcases,initializers=initializers,shipped=shipped),separators=(',',':')),encoding='utf8');(BASE/'reports/script-phase6-20261013-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report));assert not errors
