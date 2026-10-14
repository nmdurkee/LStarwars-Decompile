"""Whole Circle5350e0, original string/locator/expression/origin/distance children; custom token port only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0])
expression122=evaluate
exec(Path(__file__).with_name('script-phase110-20261013-verify.py').read_text().split('\ndef execute(address,c):')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
P=D+0x7000;ARGS=D+0x8000;TOKENS=D+0x9000;LOCATORS=D+0x6000;CB=n.STOP+0x700;events=[];config={};ordinal=0
KEYS=dict(anticlockwise=0x760bbc,clockwise=0x760bb0,reverse=0x760ba8,facing=0x760ba0,currentdist=0x760b94,locator=0x7581a8,current_position=0x760b80,origin=0x75771c)
foldbyte=lambda c:(c-32)&255 if 97<=c<=122 or c>=224 else c
def byte_text(p):
 a=[]
 while rb(p):a.append(rb(p));p+=1
 return bytes(a)
def eq(a,b):return bytes(map(foldbyte,byte_text(a)))==bytes(map(foldbyte,byte_text(b)))
def substring(a,b):
 text=byte_text(a);pattern=byte_text(b)
 for i in range(len(text)):
  if i+len(pattern)<=len(text)and all(foldbyte(x)==foldbyte(y)for x,y in zip(text[i:i+len(pattern)],pattern)):return a+i
 return 0
def locator(query,system):
 if not system:return 0
 count=rd(system+0x24);count=count if count<0x80000000 else count-0x100000000
 for i in range(max(0,count)):
  if eq(rd(system+0x28)+i*0x3c,query):return rd(system+0x28)+i*0x3c
 return 0
def token_port(token,flags,model):
 global ordinal
 ordinal+=1;events.append(dict(callback=CB,args=[token,flags]))
 for p,z,v in config.get('patches',{}).get(str(ordinal),[]):
  if model:
   for i in range(z):shadow[p+i]=(v>>(i*8))&255
  else:n.write(p,int(v).to_bytes(z,'little'))
 return config.get('handled',{}).get(str(ordinal),0)
def hook122(mu,address,size,data):
 if address!=CB:return
 sp=mu.reg_read(UC_X86_REG_ESP);token,flags=n.unpack('<2I',sp+4);value=token_port(token,flags,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook122)
def copy3(output,source):
 for i in range(3):wd(output+i*4,rd(source+i*4))
TARGET=D+0x5000;OTHER=D+0x5800
KEYS['random']=0x760bcc;KEYS['offpath']=0x758208
def range123(a,b):
 x=add(fl(rd(a)),-fl(rd(b)));z=add(fl(rd(a+8)),-fl(rd(b+8)));square=w.store(w.add(w.add(w.mul(w.wide(x),w.wide(x)),w.wide(0.)),w.mul(w.wide(z),w.wide(z))));return bits(math.sqrt(square))
ADDRESS=[0x535940,0x535aa0,0x535c00,0x535d60,0x535e90]

def token_game(token,output):
 name=bytes(map(foldbyte,byte_text(token)));value={b'RUN':0,b'WALK':1,b'TIPTOE':2}.get(name)
 if value is None:return 0
 shadow[output]=value;return 1

def retreat140(kind,system,packet,actor,args,count,first):
 if not actor:return 1
 retreat=kind>=3
 if first:
  if retreat:wd(actor+0x180,bits(1.))
  for i in range(max(0,count)):
   callback=rd(0x9238b0)
   if callback:
    handled=token_game(rd(args+i*4),actor+0x13f)if callback==0x43c0c0 else token_port(rd(args+i*4),actor+0x13f,True)
    if handled:continue
   if not retreat and eq(rd(args+i*4),0x757e80):shadow[packet+0x68]=1
   else:wd(actor+0x180,expression122(actor,packet,rd(args+i*4)))
 reference=rd(actor+0xe4)if kind in[0,3]else rd(actor+0xd4)if kind==4 else rd(system+(0x138c if kind==1 else 0x1390))
 if reference:
  target=rd(reference+4)
  if kind in[0,3]and not target:return 0
  radius=rd(target+0x120);goal=rd(actor+0x180);point=(target+0x170)&0xffffffff;words=(target+0x158)&0xffffffff
  if point:copy3(actor+0x1b4,point)
  if words:
   for i in range(6):wd(actor+0x1cc+i*4,rd(words+i*4))
  wd(actor+0x1c0,radius);wd(actor+0x1c4,goal);wd(actor+0x1e8,(rd(actor+0x1e8)&0xfffffffa)|2)
  if not retreat and rb(packet+0x68):
   facing=reference if kind==0 else rd(system+(0x138c if kind==1 else 0x1390));wd(actor+0x1e4,(facing+0x5c)&0xffffffff)
 return 0

def execute140(kind,c):
 global config,shadow,segments,checks,events,ordinal
 config=c;n.write(D,bytes(0x30000));tokens=c.get('tokens',[]);system=ACTOR+0x1cc-(0x138c if kind==1 else 0x1390)if c.get('systemAlias')else SYS;target=ACTOR+c['targetOffset']if 'targetOffset'in c else TARGET;reference=REF;n.pack('<I',reference+4,0 if c.get('nullTarget')else target);n.pack('<3f',target+0x170,7.,8.,9.);n.pack('<6I',target+0x158,*[0x12340000+i for i in range(6)]);n.pack('<f',target+0x120,5.);n.pack('<I',ACTOR+0x180,c.get('goal',bits(2.)));n.pack('<I',ACTOR+0x1e8,c.get('actorFlags',0xabcdef07));n.pack('<I',ACTOR+0xe4,0 if c.get('noReference')else reference);n.pack('<I',ACTOR+0xd4,0 if c.get('noReference')else reference);n.pack('<I',system+0x138c,0 if c.get('noReference')else reference);n.pack('<I',system+0x1390,0 if c.get('noReference')else reference);n.write(P+0x68,bytes([c.get('mode',0)]));n.pack('<4f',P+0x14,2.,3.,4.,5.);n.write(ACTOR+0x13f,b'\xee');callback=c.get('callback','game');n.pack('<I',0x9238b0,0 if callback=='none'else 0x43c0c0 if callback=='game'else CB);n.pack('<I',0x9238c0,0);n.pack('<I',0x95e5d4,123456789);n.write(0x92224c,bytes(0x18))
 for i,value in enumerate(tokens):n.pack('<I',ARGS+i*4,TOKENS+i*0x100);n.write(TOKENS+i*0x100,value.encode('latin1')+b'\0')
 raw=[(system,0x1400),(ACTOR,0x300),(reference,0x100),(target,0x300),(OTHER,0x300),(P,0x200),(ARGS,0x100),(TOKENS,0x1000),(0x755d34,24),(0x757e80,5),(0x9238b0,4),(0x9238c0,4),(0x92224c,0x18),(0x95e5d4,4)]
 # Mutable custom callback may switch to another prepared target.
 n.pack('<I',OTHER+0x120,bits(6.));n.pack('<3f',OTHER+0x170,20.,30.,40.);n.pack('<6I',OTHER+0x158,*[0x56780000+i for i in range(6)])
 merged=[]
 for p,z in sorted(raw):
  if merged and p<=merged[-1][0]+merged[-1][1]:merged[-1][1]=max(merged[-1][1],p+z-merged[-1][0])
  else:merged.append([p,z])
 segments=[tuple(x)for x in merged];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};systemArg=0 if c.get('nullSystem')else system;actor=0 if c.get('nullActor')else ACTOR;count=c.get('count',len(tokens));first=c.get('first',1);events=[];ordinal=0;mfault=False;want=0
 try:want=retreat140(kind,systemArg,P,actor,ARGS,count,first)
 except KeyError:mfault=True
 model=snap(True);me=events.copy();events=[];ordinal=0;nfault=False;got=0
 try:got=n.call(ADDRESS[kind],[systemArg,P,actor,ARGS,count&0xffffffff,first],count=4000000)
 except RuntimeError:nfault=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(kind=kind,group=group,context=c,native=a,model=b))
 cases.append(dict(kind=kind,address=ADDRESS[kind],context=c,inputs=dict(system=systemArg,packet=P,actor=actor,args=ARGS,count=count,first=first),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
sets=[[],['face'],['2.5'],['param0*2'],['Rand'],['RUN'],['WALK'],['TIPTOE'],['RUN','2.5','face'],['face','TIPTOE','param1+1'],['facing'],['max']]
for kind,tokens,mode,first,callback in itertools.product(range(5),sets,[0,2,0x80],[0,1],['none','game']):execute140(kind,dict(tokens=tokens,mode=mode,first=first,callback=callback))
for kind,c in itertools.product(range(5),[dict(nullActor=True,tokens=['RUN','face']),dict(nullSystem=True,tokens=['RUN','face']),dict(noReference=True),dict(nullTarget=True),dict(count=-1),dict(callback='custom',tokens=['RUN','face'],handled={'1':1}),dict(callback='custom',tokens=['face'],patches={'1':[[REF+4,4,OTHER]]}),dict(callback='custom',tokens=['face'],patches={'1':[[ACTOR+0xe4,4,0],[ACTOR+0xd4,4,0],[SYS+0x138c,4,0],[SYS+0x1390,4,0]]})]):execute140(kind,c)
for kind,shift,mode in itertools.product(range(5),[-0x1c,0,0x40],[0,1]):execute140(kind,dict(targetOffset=shift,mode=mode))
for kind in[1,2]:execute140(kind,dict(systemAlias=True,tokens=['face']))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=4,refinements=['535d60'],ports=['explicit custom movement-token callback only'],closure='actualfive MoveAway/Retreat bodies→real43C0C0 movementtoken/4F8B10/514920 expression')
(nm.BASE/'reports/script-phase140-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase140-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
