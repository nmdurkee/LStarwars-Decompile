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
def circle122(system,packet,actor,args,count,first):
 if not actor or not system or not rd(system+0x138c):return 1
 if first:
  for i in range(max(0,count)):
   if rd(0x9238b0)and token_port(rd(args+i*4),actor+0x13f,True):continue
   token=lambda:rd(args+i*4)
   if eq(token(),KEYS['anticlockwise']):wd(actor+0x1e8,rd(actor+0x1e8)&0xfffffdff)
   elif eq(token(),KEYS['clockwise']):wd(actor+0x1e8,rd(actor+0x1e8)|0x200)
   elif eq(token(),KEYS['reverse']):wd(actor+0x1e8,rd(actor+0x1e8)^0x200)
   elif eq(token(),KEYS['facing']):shadow[packet+0x68]=rb(packet+0x68)|1
   elif eq(token(),KEYS['currentdist']):shadow[packet+0x68]=rb(packet+0x68)|4
   else:
    found=substring(token(),KEYS['locator'])
    if found:
     loc=locator(found+8,system);wd(packet+0x6c,loc)
     if loc:shadow[packet+0x68]=rb(packet+0x68)|0x10
    elif substring(token(),KEYS['current_position']):shadow[packet+0x68]=rb(packet+0x68)|8;copy3(packet+0x78,actor+0x14c)
    elif eq(token(),KEYS['origin']):
     if rb(actor+0x138)!=255:shadow[packet+0x68]=rb(packet+0x68)|0x20
    else:wd(actor+0x180,expression122(actor,packet,token()))
  if not rb(packet+0x68)&0x38:shadow[packet+0x68]=rb(packet+0x68)|8;copy3(packet+0x78,actor+0x14c)
 mode=rb(packet+0x68)
 if mode&8:point=packet+0x78;words=actor+0x158
 elif mode&0x10:loc=rd(packet+0x6c);point=loc+0x10;words=loc+0x20
 else:
  if not mode&0x20:return 0
  record=rd(system+0x18)+rb(actor+0x138)*0xa4;words=record+0x30;point=origin(system,actor)if rd(0x923908)else 0
  if not point:point=record+0x20
 if words and point:
  if rb(packet+0x68)&4:
   x=add(fl(rd(actor+0x14c)),-fl(rd(point)));z=add(fl(rd(actor+0x154)),-fl(rd(point+8)));square=w.store(w.add(w.add(w.mul(w.wide(x),w.wide(x)),w.wide(0.)),w.mul(w.wide(z),w.wide(z))));wd(actor+0x180,bits(math.sqrt(square)))
  radius=rd(actor+0x180);copy3(actor+0x1b4,point)
  for i in range(5):wd(actor+0x1cc+i*4,rd(words+i*4))
  sixth=rd(words+20);wd(actor+0x1c0,0);wd(actor+0x1c4,radius);wd(actor+0x1e0,sixth);wd(actor+0x1e8,(rd(actor+0x1e8)&0xfffffffb)|3)
  if rb(packet+0x68)&1:wd(actor+0x1e4,point)
 return 0
def execute122(c):
 global config,shadow,segments,checks,events,ordinal
 config=c;tokens=c.get('tokens',[]);selector=c.get('selector',0);record=BASE+selector*0xa4;n.write(D,bytes(0x30000));n.pack('<I',SYS+0x18,BASE);n.pack('<I',SYS+0x138c,0 if c.get('noPlayer')else REF);n.pack('<I',SYS+0x24,c.get('locatorCount',2)&0xffffffff);n.pack('<I',SYS+0x28,LOCATORS)
 for i,name in enumerate([b'Alpha',b'ALPHA']):n.write(LOCATORS+i*0x3c,name+b'\0');n.pack('<3f',LOCATORS+i*0x3c+0x10,10.+i,20.+i,30.+i);n.pack('<6I',LOCATORS+i*0x3c+0x20,*[0x11220000+j+i for j in range(6)])
 n.pack('<3f',ACTOR+0x14c,*c.get('actorPosition',[1.,2.,3.]));n.pack('<6I',ACTOR+0x158,*[0x12340000+j for j in range(6)]);n.pack('<I',ACTOR+0x180,c.get('radius',bits(2.)));n.pack('<I',ACTOR+0x1e8,c.get('actorFlags',0xabcdef04));n.pack('<I',ACTOR+0x1ec,c.get('cacheFlags',0));n.write(ACTOR+0x138,bytes([selector]));n.write(ACTOR+0x149,bytes([c.get('column',1),c.get('row',2)]));n.pack('<3f',record+0x20,*c.get('origin',[7.,8.,9.]));n.pack('<I',record+0x2c,0);n.pack('<6I',record+0x30,*[0x56780000+j for j in range(6)]);n.pack('<2f',record+0x5c,2.,3.)
 n.write(P+0x68,bytes([c.get('mode',0)]));n.pack('<I',P+0x6c,LOCATORS if c.get('locatorAttached',True)else 0);n.pack('<3f',P+0x78,2.,4.,6.);n.pack('<4f',P+0x14,2.,3.,4.,5.);n.pack('<I',0x9238b0,CB if c.get('customToken')else 0);n.pack('<I',0x923908,0x43c3a0 if c.get('gameOrigin')else 0);n.pack('<I',0x9238c0,0);n.pack('<I',0x95e5d4,123456789);n.write(0x92224c,bytes(0x18));n.pack('<f',TABLE,0.);n.pack('<f',TABLE+0x8000,1.)
 for i,value in enumerate(tokens):n.pack('<I',ARGS+i*4,TOKENS+i*0x100);n.write(TOKENS+i*0x100,value.encode('latin1')+b'\0')
 segments=[(SYS,0x1400),(ACTOR,0x300),(LOCATORS,0x100),(P,0x200),(ARGS,0x100),(TOKENS,0x1000),(record,0xa4),(0x92224c,0x18),(0x9238b0,4),(0x9238c0,4),(0x923908,4),(0x95e5d4,4),(TABLE,4),(TABLE+0x8000,4),(0x760b80,0x50),(0x7581a8,9),(0x75771c,7)]
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;packet=P;count=c.get('count',len(tokens));first=c.get('first',1);events=[];ordinal=0;mfault=False;want=0
 try:want=circle122(system,packet,actor,ARGS,count,first)
 except KeyError:mfault=True
 model=snap(True);me=events.copy();events=[];ordinal=0;nfault=False;got=0
 try:got=n.call(0x5350e0,[system,packet,actor,ARGS,count&0xffffffff,first],count=4000000)
 except RuntimeError:nfault=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(system=system,packet=packet,actor=actor,args=ARGS,count=count,first=first),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
sets=[[],['ANTICLOCKWISE'],['clockwise'],['reverse'],['facing'],['currentdist'],['origin'],['current_position'],['precurrent_positionpost'],['locator=Alpha'],['locator=missing'],['prelocator=Alpha'],['2.5'],['param0*2'],['Rand'],['origin','currentdist','facing'],['locator=Alpha','currentdist','facing'],['origin','locator=Alpha','current_position'],['CLOCKWISE','REVERSE','ANTICLOCKWISE','REVERSE']]
for tokens,mode,game,selector in itertools.product(sets,[0,1,4,8,0x10,0x20],[False,True],[0,255]):execute122(dict(tokens=tokens,mode=mode,gameOrigin=game,selector=selector))
for mode,first,game in itertools.product([0,1,4,8,9,12,16,17,20,32,33,36,0x38],[0,1,7],[False,True]):execute122(dict(mode=mode,first=first,gameOrigin=game))
for c in[dict(nullActor=True,tokens=['origin']),dict(nullSystem=True,tokens=['origin']),dict(noPlayer=True,tokens=['origin']),dict(count=-1),dict(customToken=True,tokens=['origin','facing'],handled={'1':1}),dict(customToken=True,tokens=['origin','facing'],patches={'1':[[P+0x68,1,8]]}),dict(customToken=True,tokens=['origin','facing'],patches={'1':[[ACTOR+0x138,1,255]]}),dict(customToken=True,tokens=['origin','facing'],patches={'1':[[ARGS+4,4,TOKENS]]})]:execute122(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=['optional custom movement-token callback only'],closure='actual5350e0→4f8b10/4f8a70/51ac10/514920/43c3a0/5bed80 and actual arithmetic/sqrt')
(nm.BASE/'reports/script-phase122-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase122-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
