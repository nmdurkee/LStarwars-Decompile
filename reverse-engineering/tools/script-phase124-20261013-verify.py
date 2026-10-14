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
OWNREF=REF;TARGETREF=D+0x4200;PATH=D+0xa000;NODEA=D+0xb000;NODEB=D+0xb100;TABLEPTR=D+0xc000;NEXT=D+0xd000;FORM=D+0xf000;FORM2=D+0xf400
KEYS['ignore']=0x758218
# Final scheduler is an explicit caller mutation port; formation and math remain actual native children.
def schedule(callback,model):
 events.append(dict(schedule=callback))
 for p,z,v in config.get('schedulePatches',[]):
  if model:
   for i in range(z):shadow[p+i]=(v>>(i*8))&255
  else:n.write(p,int(v).to_bytes(z,'little'))
def scheduler_hook(mu,address,size,data):
 if address!=0x51d130:return
 sp=mu.reg_read(UC_X86_REG_ESP);callback=n.unpack('<I',sp+4)[0];schedule(callback,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0x12345678);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,scheduler_hook)
def rotate124(x,y,z,heading):
 sine=fl(rd(TABLE+((heading>>1)&0x7fff)*4));cosine=fl(rd(TABLE+(((heading+0x4000)>>1)&0x7fff)*4));return[products(sine,z,cosine,x),y,products(cosine,z,fl(bits(sine)^0x80000000),x)]
def formation124(actor):
 form=rd(actor+0x144);index=rb(actor+0x14a)
 if rb(form+6)<=index:return
 row=form+0x54+index*0x34;column=rb(actor+0x149)
 if rb(actor+0x1eb)&1:x=0. if rb(form+8)&1 else fl(bits(product(fl(rd(form+0x128)),.5))^0x80000000)
 else:
  x=product(fl(rd(form+0x128)),(column+1)//2)
  if column&1:x=fl(bits(x)^0x80000000)
 if rb(form+0x50)&4:x=fl(bits(x)^0x80000000)
 rotated=rotate124(x,0.,0.,rd(row+0x24));position=[add(rotated[i],fl(rd(row+0x18+i*4)))for i in range(3)];wd(actor+0x1e8,rd(actor+0x1e8)|8);current=rd(actor+0x144);mode=1 if current and rb(current+0x50)&8 else 5
 for i,v in enumerate(position):wd(actor+0x1b4+i*4,bits(v))
 for i in range(5):wd(actor+0x1cc+i*4,rd(row+i*4))
 sixth=rd(row+20);wd(actor+0x1c0,0);wd(actor+0x1e0,sixth);wd(actor+0x1c4,0);wd(actor+0x78,0);wd(actor+0x7c,0);wd(actor+0x80,bits(100.));wd(actor+0x1e8,(rd(actor+0x1e8)&~7)|mode)
 facing=rotate124(fl(rd(actor+0x78)),fl(rd(actor+0x7c)),fl(rd(actor+0x80)),rd(row+0x24))
 for i,v in enumerate(facing):wd(actor+0x78+i*4,bits(v))
 for i in range(3):wd(actor+0x78+i*4,bits(add(fl(rd(actor+0x78+i*4)),fl(rd(row+0x18+i*4)))))
 wd(actor+0x1e4,actor+0x78)
def set124(actor,point,radius,words,mode,goal):
 form=rd(actor+0x144)
 if form and rb(form+0x50)&8:
  if mode in[1,4]:
   if rd(form)==rd(actor+0xd0):schedule(0x51cbc0 if mode==1 else 0x51c6a0,True)
   formation124(actor);return
  if mode==5:mode=1
 if point:copy3(actor+0x1b4,point)
 if words:
  for i in range(6):wd(actor+0x1cc+i*4,rd(words+i*4))
 wd(actor+0x1c0,radius);wd(actor+0x1e8,(rd(actor+0x1e8)&~7)|(mode&7));wd(actor+0x1c4,goal)
def intent124(own,targetref,flags,goal):
 target=rd(targetref+4);mode=1;point=target+0x170
 if flags&1:
  actor=rd(own+4);path=rd(actor+0x158);off=not path or path!=rd(target+0x158)
  if not off:
   start=rd(actor+0x15c);dest=rd(target+0x15c);off=not rb(target+0x166)&1 and start==dest or not start or not dest or rd(actor+0x1e8)&0x100000
   if not off:
    a=rb(start+0x10);b=rb(dest+0x10);next=rd(rd(path+0x84)+a*4);off=rb(next+b)==255 and a!=b
  mode=7 if off else 1;point=target+(0x14c if off else 0x170)
 radius=0 if flags&2 else rd(target+0x120);set124(rd(own+4),point,radius,target+0x158,mode,goal)
def follow124(system,packet,actor,args,count,first):
 if not actor:return 1
 if first:
  for i in range(max(0,count)):
   if rd(0x9238b0)and token_port(rd(args+i*4),actor+0x13f,True):continue
   token=rd(args+i*4)
   if eq(token,KEYS['ignore']):shadow[packet+0x68]=rb(packet+0x68)|2
   elif eq(rd(args+i*4),KEYS['offpath']):shadow[packet+0x68]=rb(packet+0x68)|1
   else:wd(actor+0x180,expression122(actor,packet,rd(args+i*4)))
 targetref=rd(system+0x138c)
 if targetref and rd(targetref+4):intent124(rd(actor+0xd0),targetref,rb(packet+0x68),rd(actor+0x180))
 return 0
def execute124(method,c):
 global config,shadow,segments,checks,events,ordinal
 config=c;n.write(D,bytes(0x30000));tokens=c.get('tokens',[]);rowIndex=c.get('row',0);heading=c.get('heading',0)&0xffffffff;fromIndex=c.get('fromIndex',0);toIndex=c.get('toIndex',1)
 n.pack('<I',SYS+0x138c,0 if c.get('noTargetReference')else TARGETREF);n.pack('<I',OWNREF+4,ACTOR);n.pack('<I',TARGETREF+4,0 if c.get('nullTarget')else TARGET);n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else OWNREF);n.pack('<I',ACTOR+0x144,FORM if c.get('formation')else 0);n.pack('<I',ACTOR+0x158,0 if c.get('noPath')else PATH);n.pack('<I',TARGET+0x158,PATH+0x100 if c.get('differentPath')else PATH);n.pack('<I',ACTOR+0x15c,0 if c.get('noFrom')else NODEA);n.pack('<I',TARGET+0x15c,0 if c.get('noTo')else NODEA if c.get('sameNode')else NODEB);n.write(TARGET+0x166,bytes([c.get('targetOnPath',1)]));n.pack('<I',ACTOR+0x1e8,c.get('actorFlags',0));n.write(ACTOR+0x149,bytes([c.get('column',1),rowIndex]));n.pack('<I',ACTOR+0x180,bits(2.));n.pack('<f',TARGET+0x120,5.);n.pack('<3f',TARGET+0x14c,10.,20.,30.);n.pack('<3f',TARGET+0x170,7.,8.,9.);n.write(NODEA+0x10,bytes([fromIndex]));n.write(NODEB+0x10,bytes([toIndex]));n.pack('<I',PATH+0x84,TABLEPTR);n.pack('<I',TABLEPTR+fromIndex*4,NEXT);n.write(NEXT+toIndex,bytes([c.get('nextHop',0)]))
 formRow=FORM+0x54+rowIndex*0x34
 for form in[FORM,FORM2]:
  n.pack('<I',form,OWNREF if c.get('owner',True)else OWNREF+0x100);n.write(form+6,bytes([c.get('rowCount',255)]));n.write(form+8,bytes([c.get('centerFlag',0)]));n.write(form+0x50,bytes([c.get('formationFlags',8)]));n.pack('<f',form+0x128,c.get('width',3.));row=form+0x54+rowIndex*0x34;n.pack('<6I',row,*[0x12340000+i for i in range(6)]);n.pack('<3f',row+0x18,1.,2.,3.);n.pack('<I',row+0x24,heading)
 si=(heading>>1)&0x7fff;ci=((heading+0x4000)>>1)&0x7fff;n.pack('<f',TABLE+si*4,c.get('sine',0.));n.pack('<f',TABLE+ci*4,c.get('cosine',1.));n.write(P+0x68,bytes([c.get('flags',0)]));n.pack('<4f',P+0x14,2.,3.,4.,5.);n.pack('<I',0x9238b0,CB if c.get('customToken')else 0);n.pack('<I',0x9238c0,0);n.pack('<I',0x95e5d4,123456789);n.write(0x92224c,bytes(0x18))
 for i,value in enumerate(tokens):n.pack('<I',ARGS+i*4,TOKENS+i*0x100);n.write(TOKENS+i*0x100,value.encode('latin1')+b'\0')
 raw=[(SYS,0x1400),(ACTOR,0x300),(OWNREF,0x100),(TARGETREF,0x100),(TARGET,0x300),(P,0x200),(ARGS,0x100),(TOKENS,0x1000),(PATH,0x200),(NODEA,0x200),(TABLEPTR,0x400),(NEXT,0x100),(FORM,0x150),(formRow,0x34),(FORM2,0x150),(FORM2+0x54+rowIndex*0x34,0x34),(TABLE+si*4,4),(TABLE+ci*4,4),(0x92224c,0x18),(0x9238b0,4),(0x9238c0,4),(0x95e5d4,4),(0x758208,30)]
 merged=[]
 for p,z in sorted(raw):
  if merged and p<=merged[-1][0]+merged[-1][1]:merged[-1][1]=max(merged[-1][1],p+z-merged[-1][0])
  else:merged.append([p,z])
 segments=[tuple(x)for x in merged];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;count=c.get('count',len(tokens));first=c.get('first',1);flags=c.get('flags',0);mode=c.get('mode',1);events=[];ordinal=0;mfault=False;want=0
 try:
  if method=='Player':want=follow124(system,P,actor,ARGS,count,first)
  elif method=='Intent':intent124(OWNREF,TARGETREF,flags,bits(2.))
  elif method=='SetIntent':set124(ACTOR,TARGET+0x14c,bits(5.),TARGET+0x158,mode,bits(2.))
  else:formation124(ACTOR)
 except KeyError:mfault=True
 model=snap(True);me=events.copy();events=[];ordinal=0;nfault=False;got=0
 try:
  if method=='Player':got=n.call(0x535000,[system,P,actor,ARGS,count&0xffffffff,first],count=4000000)
  elif method=='Intent':n.call(0x534e10,[OWNREF,TARGETREF,flags,bits(2.)],count=4000000)
  elif method=='SetIntent':n.call(0x52fcb0,[ACTOR,TARGET+0x14c,bits(5.),TARGET+0x158,mode,bits(2.)],count=4000000)
  else:n.call(0x52fda0,[ACTOR],count=4000000)
 except RuntimeError:nfault=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(system=system,packet=P,actor=actor,args=ARGS,count=count,first=first,actorReference=OWNREF,targetReference=TARGETREF,point=TARGET+0x14c,words=TARGET+0x158,flags=flags,mode=mode),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
for flags,c in itertools.product([0,1,2,3,0xff],[{},dict(noPath=True),dict(differentPath=True),dict(sameNode=True,targetOnPath=0),dict(sameNode=True,targetOnPath=1),dict(noFrom=True),dict(noTo=True),dict(actorFlags=0x100000),dict(nextHop=255),dict(fromIndex=254,toIndex=255,nextHop=255),dict(fromIndex=255,toIndex=255,nextHop=255)]):execute124('Intent',dict(c,flags=flags))
for method,flags,formation in itertools.product(['Player','Intent'],[0,1,2,3],[False,True]):execute124(method,dict(flags=flags,formation=formation))
for mode,owner,formFlags in itertools.product([0,1,4,5,7,8,0xffffffff],[False,True],[0,8,12]):execute124('SetIntent',dict(mode=mode,owner=owner,formation=True,formationFlags=formFlags))
for row,column,actorFlags,formFlags,center in itertools.product([0,1,254,255],[0,1,255],[0,0x1000000],[0,4,8,12],[0,1]):execute124('Formation',dict(formation=True,row=row,column=column,actorFlags=actorFlags,formationFlags=formFlags,centerFlag=center))
for tokens,first in itertools.product([[],['ignore_radius'],['can_go_off_path'],['2.5'],['param0*2'],['Rand'],['ignore_radius','can_go_off_path','2.5']],[0,1]):execute124('Player',dict(tokens=tokens,first=first))
for c in[dict(nullActor=True),dict(nullSystem=True),dict(noController=True),dict(noTargetReference=True),dict(nullTarget=True),dict(customToken=True,tokens=['can_go_off_path'],handled={'1':1}),dict(customToken=True,tokens=['can_go_off_path'],patches={'1':[[ACTOR+0x158,4,0]]}),dict(formation=True,schedulePatches=[[ACTOR+0x144,4,FORM2]]),dict(formation=True,schedulePatches=[[FORM+0x128,4,bits(7.)]])]:execute124('Player',c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,refinements=['534e10','52fcb0','52fda0'],ports=['optional custom movement-token callback','final51d130scheduler'],closure='actual535000→534e10→52fcb0→52fda0→rotation/addition; actual matcher/expression/route tables')
(nm.BASE/'reports/script-phase124-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase124-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
