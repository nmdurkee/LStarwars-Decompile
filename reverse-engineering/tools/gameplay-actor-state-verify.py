"""Original PC actor-state commands with real registered name/type callbacks.
Only CRT sprintf("Player%d", index) is replaced by bounded formatting.
"""
import importlib.util,json,struct,itertools,copy,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;CRE=D+0x2000;PACK=D+0x3000;ACT=D+0x4000;DEF=D+0x20000;TYPES=D+0x24000;SPAWN=D+0x25000;DATABASE=D+0x35000;NAMES=D+0x40000;ARGS=D+0x50000;TEXT=D+0x51000
ADDRESSES={'DontPush':0x4497b0,'SetInvulnerable':0x449440,'SetSide':0x444940,'KeepWeaponOut':0x44ef00}
TYPE_NAMES=['Alpha','Beta','clone_ep3','clone_ep3_sand','moseisleycitizen','cloudcitycitizen','engineer','RebelScum','Gamma','Delta','T10','T11','T12']
OFFSETS=[0x1f8,0x1fc,0xeec,0xef0,0x4b0,0x4bc,0xec0,0xec4,0x3ac]
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'))
uses={r['name']:r['uses'] for r in ledger['rows'] if r['name'] in ADDRESSES}
events=[];checks={};errors=[];vectors=[];helper_vectors=[]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def actor(i):return ACT+i*0x10d8 if i>=0 else 0
def aid(p):return (p-ACT)//0x10d8 if p else -1
def string(p):return n.read(p,256).split(b'\0')[0].decode('ascii')
def ret(mu,v):
 sp=mu.reg_read(UC_X86_REG_ESP);ip=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,v&0xffffffff);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ip)
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x6e69ef:
  assert string(arg(1))=='Player%d';value='Player'+str(arg(2));assert len(value)<64;n.write(arg(0),value.encode()+b'\0');ret(mu,len(value))
 elif address==0x43c220:events.append(['name',string(arg(1))])
 elif address==0x43bc00:events.append(['type',string(arg(0))])
 elif address==0x43bed0:events.append(['typeIndex',arg(0)&255])
for address in [0x6e69ef,0x43c220,0x43bc00,0x43bed0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)

def context(o):
 c=dict(system=True,creature=True,reference=0,callback=True,typeNameCallback=True,typeIndexCallback=True,table=True,count=8,primary=1,players=[1,2,3,-1,-1,-1,-1,7],goodMask=0x4000000,badMask=0x8000000)
 c.update(o)
 c['definitions']=[dict(name=x,flags=[0,4,0x200,0x204][i%4]) for i,x in enumerate(TYPE_NAMES)]
 c['typeTable']=list(range(13))+[-1]*243;c['typeTable'][64]=8
 if 'tableEntries' in o:c['typeTable'][:len(o['tableEntries'])]=o['tableEntries']
 c['actors']=[]
 for i in range(8):
  a=dict(world=i,definition=i,type=i,spawn=i,spawnName='order66' if i==1 else 'spawn'+str(i),spawnDefinition=i,position=[float(i),float(i%2),float(i%3)],state=[0x400|[0,1,4,0x10000][i%4],0x1001,0xa5a5a5a5,0x11401022,0xa5a50800,0x5a5a5a5a,0x100+i,0x200+i,0x300+i])
  for k,v in o.get('actorOverrides',{}).get(str(i),{}).items():a[k]=copy.deepcopy(v)
  if 'flags' in a:a['state'][0]=a.pop('flags')
  if 'active' in a:a['state'][1]=a.pop('active')
  a['position']=[f(v) for v in a['position']]
  c['actors'].append(a)
 return c

def setup(c,tokens):
 n.write(D,bytes(0x57000));events.clear()
 n.pack('<I',SYS+0x18,SPAWN);n.pack('<I',CRE+0xd0,actor(c['reference']));n.pack('<II',0x93d500,c['count'],ACT)
 n.pack('<I',0x923904,0x43c220 if c['callback'] else 0);n.pack('<I',0x923884,0x43bc00 if c['typeNameCallback'] else 0);n.pack('<I',0x923894,0x43bed0 if c['typeIndexCallback'] else 0)
 n.pack('<I',0x29130e4,DATABASE);n.pack('<I',DATABASE+0x20,DEF);n.pack('<I',0x951374,TYPES if c['table'] else 0)
 for i,a in enumerate(c['definitions']):
  n.pack('<I',DEF+0x4c*i+4,a['flags']);n.pack('<I',DEF+0x4c*i+0xc,NAMES+i*128);n.write(NAMES+i*128,a['name'].encode()+b'\0')
 for i,v in enumerate(c['typeTable']):n.pack('<h',TYPES+4*i,v)
 for i,a in enumerate(c['actors']):
  p=actor(i);n.pack('<I',p,actor(a['world']));n.pack('<I',p+0x54,DEF+0x4c*a['definition']);n.pack('<3f',p+0x5c,*a['position']);n.pack('<B',p+0x400,a['spawn']);n.pack('<h',p+0x1064,a['type'])
  for off,v in zip(OFFSETS,a['state']):n.pack('<I',p+off,v)
  n.write(SPAWN+i*0xa4,a['spawnName'].encode()+b'\0');n.pack('<h',SPAWN+i*0xa4+0x4e,a['spawnDefinition'])
 n.pack('<I',0x93d810,actor(c['primary']))
 for i,ix in enumerate(c['players']):n.pack('<I',0x93d7f0+4*i,actor(ix))
 n.pack('<II',0x950d60,c['goodMask'],c['badMask']);n.pack('<I',PACK+4,NAMES+0x1000);n.pack('<4f',PACK+0x14,2.75,1.5,3.,4.)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.pack('<I',NAMES+0x1018+i*8,NAMES+0x1100+i*32);n.write(NAMES+0x1100+i*32,name.encode()+b'\0')
 for i,t in enumerate(tokens):assert len(t)<255;n.pack('<I',ARGS+i*4,TEXT+i*256);n.write(TEXT+i*256,t.encode()+b'\0')
def snapshot():return [[n.unpack('<I',actor(i)+off)[0] for off in OFFSETS] for i in range(8)]
def resolve_name(c,name):
 low=name.lower()
 if c['system']:
  for i,a in enumerate(c['actors'][:c['count']]):
   if not a['state'][1]&1:continue
   if a['state'][0]&0x400 and a['spawn']!=255 and c['actors'][a['spawn']]['spawnName'].lower()==low:return i
   if c['definitions'][a['definition']]['name'].lower()==low:return i
 if low=='player':return c['primary']
 if low=='player_2':return c['players'][1] if c['players'][0]==c['primary'] else c['players'][0]
 return next((ix for i,ix in enumerate(c['players']) if ix>=0 and low=='player'+str(i)),-1)
def type_name(c,name):
 if name.lower()=='everyone':return 64
 if not c['table']:return 255
 for i,v in enumerate(c['typeTable'][:64]):
  if v==-1:break
  if c['definitions'][v]['name'].lower()==name.lower():return i
 return 255
def type_index(c,index):return c['typeTable'][index&255] if (index&255)!=255 and c['table'] else -1
def number(t):
 low=t.lower()
 if 'param' in low:return 2.75
 if low in ['alpha','beta','gamma','delta']:return [2.75,1.5,3.,4.][['alpha','beta','gamma','delta'].index(low)]
 i=0;value=0.;den=1.
 if t.startswith('-'):i=1;den=-1.
 while i<len(t) and '0'<=t[i]<='9':value=f(f(value*10)+int(t[i]));i+=1
 if i<len(t) and t[i]=='.':
  i+=1
  while i<len(t) and '0'<=t[i]<='9':den=f(den*10);value=f(f(value*10)+int(t[i]));i+=1
 return f(value/den)

def model(command,tokens,c,first):
 out=copy.deepcopy([a['state'] for a in c['actors']]);ev=[]
 if not first:return dict(result=1,state=out,events=ev)
 own=c['reference'] if c['creature'] else -1
 target=c['actors'][own]['world'] if own>=0 and (command!='SetSide' or c['actors'][own]['state'][1]&1) else -1
 types=[];enabled=True;still=False;side=0;radius=0.
 for t in tokens:
  low=t.lower()
  if command=='SetSide' and low in ['neutral','goodie','goody','baddie','baddy','goodiebaddie','goodybaddy','default']:
   side={'neutral':0,'goodie':-1,'goody':-1,'baddie':1,'baddy':1,'goodiebaddie':2,'goodybaddy':2,'default':3}[low]
  elif command!='KeepWeaponOut' and 'type' in low:
   name=t[low.index('type')+5:]
   if c['typeNameCallback'] and c['typeIndexCallback']:
    ev.append(['type',name]);idx=type_name(c,name)
    if idx!=255:
     ev.append(['typeIndex',idx]);typ=type_index(c,idx)
     if typ!=-1 and len(types)<10:types.append(typ)
  elif 'character=' in low:
   name=t[low.index('character=')+10:];ref=-1
   if c['callback']:ev.append(['name',name]);ref=resolve_name(c,name)
   target=c['actors'][ref]['world'] if ref>=0 else -1
  elif command=='SetSide' and 'range=' in low:
   v=number(t[low.index('range=')+6:]);radius=f(v*v)
  elif low=='false':enabled=False
  elif command=='SetInvulnerable' and low=='still_do_take_hit_anim':still=True
 selected=[]
 if command!='KeepWeaponOut' and (types or (command=='SetSide' and radius>0)):
  for i,a in enumerate(c['actors'][:c['count']]):
   if (a['state'][1]&0x1001)!=0x1001 or not a['state'][0]&0x400:continue
   if types and a['type'] not in types:continue
   if command=='SetSide' and radius>0:
    distance=0.
    if target>=0:
     delta=[f(x-y) for x,y in zip(c['actors'][target]['position'],a['position'])];distance=f(delta[2]*delta[2]+delta[0]*delta[0]+delta[1]*delta[1])
    if radius<=distance:continue
   selected.append(i)
 elif target>=0:selected=[target]
 for i in selected:
  a=c['actors'][i];v=out[i]
  if command=='DontPush':v[1]=(v[1]&~2)|(2 if enabled else 0)
  elif command=='SetInvulnerable':
   if v[0]&0x400:v[3]=((v[3]&~0x1000)|0x400000|(0x1000 if still else 0)) if enabled else v[3]&~0x400000
  elif command=='KeepWeaponOut':v[2]=(v[2]&~0x10)|(0x10 if enabled else 0)
  else:
   old=v[0];v[0]&=0xfffefffa
   if side==0:v[0]|=4
   elif side==1:v[0]|=1
   elif side==2:v[0]|=0x10000
   elif side==3 and old&0x400 and a['spawn']!=255:
    flags=c['definitions'][c['actors'][a['spawn']]['spawnDefinition']]['flags'];v[0]|=4 if flags&0x200 else 1 if flags&4 else 0
   v[5]&=~(c['goodMask']|c['badMask'])
   if v[0]&1:v[5]|=c['badMask']
   elif not v[0]&4:v[5]|=c['goodMask']
   if not old&0x10005&v[0]:v[4]&=~0x800;v[6]=v[7]=v[8]=0
 return dict(result=1,state=out,events=ev)

def check(group,got,want,meta):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def run(command,tokens,o=None,first=True,source=None):
 o=o or {};c=context(o);setup(c,tokens);result=n.call(ADDRESSES[command],[SYS if c['system'] else 0,PACK,CRE if c['creature'] else 0,ARGS,len(tokens),int(first)],count=1000000)
 got=dict(result=result,state=snapshot(),events=events.copy());expected=model(command,tokens,c,first);check('command:'+command,got,expected,dict(tokens=tokens,options=o,first=first,source=source))
 vectors.append(dict(command=command,tokens=tokens,options=o,first=first,source=source,native=got))

def helper(kind,name,o=None):
 o=o or {};c=context(o);setup(c,[]);n.write(TEXT,str(name).encode()+b'\0')
 if kind=='name':got=aid(n.call(0x43c220,[SYS if c['system'] else 0,TEXT]));want=resolve_name(c,name)
 elif kind=='object':
  got=aid(n.call(0x440120,[SYS if c['system'] else 0,TEXT]));ix=resolve_name(c,name) if c['callback'] else -1;want=c['actors'][ix]['world'] if ix>=0 else -1
 elif kind=='type':got=n.call(0x43bc00,[TEXT])&255;want=type_name(c,name)
 else:got=n.call(0x43bed0,[name]);got=got if got<0x80000000 else got-0x100000000;want=type_index(c,name)
 check('helper:'+kind,got,want,dict(name=name,options=o));helper_vectors.append(dict(kind=kind,name=name,options=o,native=got))

def main():
 for command,rows in uses.items():
  for row in rows:
   tokens=row['args']
   for first in [True,False]:run(command,tokens,first=first,source={k:row[k] for k in ['source','line','state'] if k in row})
 base_options=[{},dict(creature=False),dict(reference=-1),dict(callback=False),dict(typeNameCallback=False),dict(typeIndexCallback=False),dict(table=False),dict(count=0),dict(actorOverrides={'0':dict(world=-1)}),dict(actorOverrides={'0':dict(world=1)}),dict(actorOverrides={'0':dict(active=0)}),dict(actorOverrides={'0':dict(flags=0)}),dict(primary=2),dict(system=False)]
 tokensets=[[],['FALSE'],['FALSE','TRUE'],['character=order66'],['character=missing'],['character=player'],['character=player_2'],['character=Player7'],['type=Alpha'],['type=clone_ep3','type=clone_ep3_sand'],['type=Everyone'],['type=missing','FALSE'],['prefixtype=Beta','character=order66','FALSE']]
 for command in ADDRESSES:
  for options,tokens in itertools.product(base_options,tokensets):run(command,tokens,options)
 for active,generic in itertools.product([0,1,0x1000,0x1001,0xffffffff],[0,0x400,0x10405]):
  for command in ADDRESSES:
   o=dict(actorOverrides={'0':dict(active=active,flags=generic)})
   for tokens in [['type=Alpha'],['character=Alpha'],[]]:run(command,tokens,o)
 for command in ['DontPush','SetInvulnerable','SetSide']:
  for names in [TYPE_NAMES[:10],TYPE_NAMES[:11],['Alpha']*10+['Beta'],['missing']*12+['Beta']]:run(command,['type='+x for x in names]+['FALSE','baddie'])
  run(command,['type=Everyone'],dict(actorOverrides={'7':dict(type=8)}))
 for enabled,still,old in itertools.product([True,False],[True,False],[0,0x1000,0x400000,0x401000,0xffffffff]):
  run('SetInvulnerable',(['FALSE'] if not enabled else [])+(['still_do_take_hit_anim'] if still else []),dict(actorOverrides={'0':dict(state=[0x400,0x1001,0,old,0,0,0,0,0])}))
 for old,side,mask in itertools.product([0,1,4,0x10000,5,0x10001,0x10004,0x10005],['neutral','goody','baddy','goodiebaddie','default'],[(0,0),(0x4000000,0x8000000),(0x33,0x3c)]):
  run('SetSide',[side],dict(goodMask=mask[0],badMask=mask[1],actorOverrides={'0':dict(flags=0x400|old)}))
 for who,spawn in itertools.product(range(8),[0,1,2,3,255]):run('SetSide',['character=Player'+str(who),'default'],dict(players=list(range(8)),actorOverrides={str(who):dict(spawn=spawn)}))
 for radius,types,center in itertools.product(['0','1','-1','2.5','6','alpha','param3','2.75junk','+6'],[[],['type=Beta'],['type=Alpha','type=clone_ep3']],[[],['character=missing']]):
  run('SetSide',['baddie','range='+radius]+types+center)
 for xyz in [[0,0,0],[1,0,0],[0,1,0],[0,0,1],[.99999994,0,0],[1.000000119,0,0],[.6,.8,0],[10000,10000,10000]]:
  run('SetSide',['range=1','baddie'],dict(actorOverrides={'0':dict(position=[0,0,0]),'1':dict(position=xyz)}))
 randomizer=random.Random(0x444940)
 for i in range(64):
  point=[f(randomizer.uniform(-8,8)) for j in range(3)];other=[f(randomizer.uniform(-8,8)) for j in range(3)]
  run('SetSide',['range=6','goody'],dict(actorOverrides={'0':dict(position=point),'1':dict(position=other)}))
 for name,options in itertools.product(['Alpha','aLpHa','spawn0','order66','Beta','player','PLAYER_2','Player0','player1','Player7','Player8',' Player0','missing'],base_options):
  helper('name',name,options);helper('object',name,options)
 for name in ['player','player_2','Player0']:
  for i in [0,1,2]:helper('name',name,dict(actorOverrides={str(i):dict(spawnName=name)},primary=7))
 for name in TYPE_NAMES+['Everyone','EVERYONE','missing',' Alpha']:
  for options in [{},dict(table=False),dict(tableEntries=[1,0,-1]),dict(tableEntries=[-1]),dict(tableEntries=[0]*64+[1])]:helper('type',name,options)
 for at in [0,1,62,63,64]:
  entries=[0]*65;entries[at]=1;helper('type','Beta',dict(tableEntries=entries))
 for index in range(256):
  for options in [{},dict(table=False)]:helper('typeIndex',index,options)
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:15],commandCases=len(vectors),helperCases=len(helper_vectors),authoredOccurrences={k:len(v) for k,v in uses.items()},method='Unmodified original-PC commands, registered name/type callbacks, numeric and string helpers. Only Player%d CRT formatting is a bounded service. Independent Python state/reference model compared after each call.',limits=['Finite valid data and ASCII strings; invalid pointers and corrupt character indices are excluded.','Runtime world attachment, actor allocation and character/spawn/type table construction remain external.','Flag consumers (pushing, damage, allegiance AI and weapon animation) are not reconstructed by these setters.','Portable source comparison is pending managed execution.'])
 (BASE/'reports/gameplay-actor-state-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8')
 (BASE/'reports/gameplay-actor-state-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,typeNames=TYPE_NAMES,offsets=OFFSETS,commands=vectors,helpers=helper_vectors),separators=(',',':')),encoding='utf8')
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 dis=Cs(CS_ARCH_X86,CS_MODE_32)
 assembly=dict(binarySha256=n.sha256,entry='0x43c220',endExclusive='0x43c397',registration='0x43c830 -> 0x520460 -> global0x923904',reason='REA corpus labels this executable callback DAT_0043c220; direct bytes and verified callback invocation establish the body.',instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in dis.disasm(n.read(0x43c220,0x177),0x43c220)])
 (BASE/'reports/gameplay-actor-name-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8')
 print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
