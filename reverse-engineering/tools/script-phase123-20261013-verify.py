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
def target_circle(address,system,packet,actor,args,count,first):
 player=address==0x535420
 if not actor or player and(not system or not rd(system+0x138c)):return 1
 if first:
  for i in range(max(0,count)):
   if rd(0x9238b0)and token_port(rd(args+i*4),actor+0x13f,True):continue
   token=lambda:rd(args+i*4)
   if eq(token(),KEYS['anticlockwise']):wd(actor+0x1e8,rd(actor+0x1e8)&0xfffffdff)
   elif eq(token(),KEYS['clockwise']):wd(actor+0x1e8,rd(actor+0x1e8)|0x200)
   elif eq(token(),KEYS['reverse']):wd(actor+0x1e8,rd(actor+0x1e8)^0x200)
   elif not player and eq(token(),KEYS['random']):
    seed=(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff;wd(0x95e5d4,seed);wd(actor+0x1e8,rd(actor+0x1e8)|0x200 if seed&0x7fffff>=0x400000 else rd(actor+0x1e8)&0xfffffdff)
   elif eq(token(),KEYS['facing']):shadow[packet+0x68]=rb(packet+0x68)|1
   elif eq(token(),KEYS['offpath']):shadow[packet+0x68]=rb(packet+0x68)|2
   elif eq(token(),KEYS['currentdist']):shadow[packet+0x68]=rb(packet+0x68)|4
   else:wd(actor+0x180,expression122(actor,packet,token()))
 reference=rd(system+0x138c)if player else rd(actor+0xe4)
 if not reference:return 0
 target=rd(reference+4)
 if not player and not target:return 0
 if rb(packet+0x68)&4:wd(actor+0x180,range123(actor+0x14c,target+0x170))
 reference=rd(system+0x138c)if player else rd(actor+0xe4);target=rd(reference+4);point=(target+(0x14c if rb(packet+0x68)&2 else 0x170))&0xffffffff;target=rd(reference+4);radius=rd(target+0x120);goal=rd(actor+0x180);words=(target+0x158)&0xffffffff
 if point:copy3(actor+0x1b4,point)
 if words:
  for i in range(6):wd(actor+0x1cc+i*4,rd(words+i*4))
 wd(actor+0x1c0,radius);wd(actor+0x1c4,goal);wd(actor+0x1e8,(rd(actor+0x1e8)&0xfffffffb)|3)
 if rb(packet+0x68)&1:wd(actor+0x1e4,point)
 return 0
def execute123(address,c):
 global config,shadow,segments,checks,events,ordinal
 config=c;n.write(D,bytes(0x30000));target=ACTOR+c['targetOffset']if 'targetOffset'in c else TARGET;tokens=c.get('tokens',[]);n.pack('<I',SYS+0x138c,0 if c.get('noReference')else REF);n.pack('<I',ACTOR+0xe4,0 if c.get('noReference')else REF);n.pack('<I',REF+4,0 if c.get('nullTarget')else target)
 n.pack('<3f',ACTOR+0x14c,*c.get('actorPosition',[1.,2.,3.]));n.pack('<I',ACTOR+0x180,c.get('radius',bits(2.)));n.pack('<I',ACTOR+0x1e8,c.get('actorFlags',0xabcdef04));n.write(P+0x68,bytes([c.get('mode',0)]));n.pack('<4f',P+0x14,2.,3.,4.,5.);n.pack('<I',0x9238b0,CB if c.get('customToken')else 0);n.pack('<I',0x9238c0,0);n.pack('<I',0x95e5d4,c.get('seed',123456789));n.write(0x92224c,bytes(0x18))
 for base in[target,OTHER]:
  n.pack('<f',base+0x120,5.);n.pack('<3f',base+0x14c,*c.get('targetPosition',[10.,20.,30.]));n.pack('<6I',base+0x158,*[0x12340000+i for i in range(6)]);n.pack('<3f',base+0x170,*c.get('targetPathPosition',[7.,8.,9.]))
 for i,value in enumerate(tokens):n.pack('<I',ARGS+i*4,TOKENS+i*0x100);n.write(TOKENS+i*0x100,value.encode('latin1')+b'\0')
 raw=[(SYS,0x1400),(ACTOR,0x300),(REF,0x100),(target,0x300),(OTHER,0x300),(P,0x200),(ARGS,0x100),(TOKENS,0x1000),(0x92224c,0x18),(0x9238b0,4),(0x9238c0,4),(0x95e5d4,4),(0x760b80,0x60),(0x758208,16)]
 merged=[]
 for p,z in sorted(raw):
  if merged and p<=merged[-1][0]+merged[-1][1]:merged[-1][1]=max(merged[-1][1],p+z-merged[-1][0])
  else:merged.append([p,z])
 segments=[tuple(x)for x in merged];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;count=c.get('count',len(tokens));first=c.get('first',1);events=[];ordinal=0;mfault=False;want=0
 try:want=target_circle(address,system,P,actor,ARGS,count,first)
 except KeyError:mfault=True
 model=snap(True);me=events.copy();events=[];ordinal=0;nfault=False;got=0
 try:got=n.call(address,[system,P,actor,ARGS,count&0xffffffff,first],count=4000000)
 except RuntimeError:nfault=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,packet=P,actor=actor,args=ARGS,count=count,first=first),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
sets=[[],['ANTICLOCKWISE'],['clockwise'],['reverse'],['RANDOM'],['facing'],['can_go_off_path'],['currentdist'],['2.5'],['param0*2'],['Rand'],['currentdist','can_go_off_path','facing'],['CLOCKWISE','REVERSE','ANTICLOCKWISE','REVERSE'],['RANDOM','RANDOM','RANDOM']]
for address,tokens,mode,first in itertools.product([0x535420,0x5356b0],sets,[0,1,2,4,7],[0,1]):execute123(address,dict(tokens=tokens,mode=mode,first=first))
for address,c in itertools.product([0x535420,0x5356b0],[dict(nullActor=True,tokens=['RANDOM']),dict(nullSystem=True,tokens=['RANDOM']),dict(noReference=True,tokens=['RANDOM']),dict(nullTarget=True),dict(nullTarget=True,mode=4),dict(count=-1),dict(customToken=True,tokens=['RANDOM','facing'],handled={'1':1}),dict(customToken=True,tokens=['can_go_off_path','currentdist'],patches={'1':[[REF+4,4,OTHER]]}),dict(customToken=True,tokens=['facing'],patches={'1':[[SYS+0x138c,4,0],[ACTOR+0xe4,4,0]]})]):execute123(address,c)
for address,shift,mode in itertools.product([0x535420,0x5356b0],[-0x1c,0,0x40],[0,2,4,7]):execute123(address,dict(targetOffset=shift,mode=mode))
for seed in[0,1,0xffffffff,0x80000000,123456789]:execute123(0x5356b0,dict(tokens=['RANDOM','RANDOM','RANDOM'],seed=seed))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['optional custom movement-token callback only'],closure='actual535420/5356b0→4f8b10/514920/5b9dd0/5bed80; actual full math/sqrt')
(nm.BASE/'reports/script-phase123-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase123-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
