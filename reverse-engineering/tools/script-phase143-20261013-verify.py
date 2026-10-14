"""Actual GoToNode and MoveAwayFromNode, including raw lookup, binding, expression, movement callback, distance and intent."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0])
SYS=D+0x1000;ACTOR=D+0x3000;REF=D+0x4000;P=D+0x5000;PATH=D+0x6000;ROWS=D+0x7000;EDGES=D+0x8000;POINTERS=D+0x9000;ARGS=D+0xa000;TOKENS=D+0xb000;NAMES=D+0xc000;checks=0;cases=[];errors=[]
def equal(a,b):return fold(text(a,True))==fold(text(b,True))
def lookup(system,path,name):
 if not path:
  if not system:return 0
  r=rd(system+0x10)
  if not r or not rb(r):return 0
  path=rd(r+8)
  if not path:return 0
 if not rb(path+0x10):return 0
 i=0
 while True:
  p=rd(rd(path+0x7c)+i*0x5c)
  if p and equal(p,name):return rd(path+0x7c)+i*0x5c
  i+=1
  if i>=rb(path+0x10):return 0
def intent(actor,point,words,mode,goal):
 if point:
  for i in range(3):wd(actor+0x1b4+i*4,rd(point+i*4))
 if words:
  for i in range(6):wd(actor+0x1cc+i*4,rd(words+i*4))
 wd(actor+0x1c0,0);wd(actor+0x1e8,(rd(actor+0x1e8)&0xfffffff8)|mode);wd(actor+0x1c4,goal)
def square(a,b):
 x=add(fl(rd(a)),-fl(rd(b)));z=add(fl(rd(a+8)),-fl(rd(b+8)));return w.store(w.add(w.add(w.mul(w.wide(x),w.wide(x)),w.wide(0.)),w.mul(w.wide(z),w.wide(z))))
def execute_model(address,system,packet,actor,args,count,first):
 away=address==0x536fc0
 if not actor or not rd(actor+0xd0)or not rd(actor+0x158)or not rd(actor+0x15c):return 1
 if first:
  if count==0:return 0
  for i in range(1,max(1,count)):
   token=rd(args+i*4)
   if rd(0x9238b0):
    value={'RUN':0,'WALK':1,'TIPTOE':2}.get(fold(text(token,True)))
    if value is not None:wb(actor+0x13f,value);continue
   wd(actor+0x180,evaluate(actor,packet,rd(args+i*4)))
  node=lookup(system,rd(actor+0x158),rd(args));wd(packet+0x6c,node)
  if not node or not rb(node+0x28):return 1
  path=rd(actor+0x158);difference=(node-rd(path+0x7c))&0xffffffff;difference=difference if difference<0x80000000 else difference-0x100000000;index=abs(difference)//0x5c*(-1 if difference<0 else 1)
  # BindPathSet is called with the already captured actor path and therefore executes its equal-identity return.
  if not away:wd(packet+0x84,path)
  edge=rd(rd(node+0x34));wd(packet+0x88,edge);wd(packet+0x94,0 if rb(edge+0x10)==index else bits(1.));wr16=rb(packet+0x92)|rb(packet+0x93)<<8;wb(packet+0x92,wr16|1);wb(packet+0x93,wr16>>8);wd(packet+0x98,0);wb(packet+0x8c,0);intent(actor,node+4,packet+0x84,2 if away else 1,rd(actor+0x180));return 0
 selected=rd(packet+0x6c)
 if selected:
  distance=square(actor+0x14c,selected+4)
  if not away:intent(actor,selected+4,packet+0x84,1,rd(actor+0x180))
  if fl(rd(selected+0x14))<=distance:
   if away:intent(actor,selected+4,packet+0x84,2,rd(actor+0x180))
   return 0
 return 1
def execute143(address,c):
 global shadow,segments,events,checks,config
 config={};n.write(D,bytes(0x10000));n.write(0x92224c,bytes(0x18));n.pack('<I',0x9238c0,0);n.pack('<I',0x9238b0,0x43c0c0 if c.get('movement',True)else 0);n.pack('<I',0x95e5d4,c.get('seed',123));n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else REF);n.pack('<I',ACTOR+0x158,0 if c.get('noPath')else PATH);n.pack('<I',ACTOR+0x15c,0 if c.get('noNode')else ROWS);n.pack('<I',ACTOR+0x144,0);n.pack('<I',ACTOR+0x180,bits(c.get('goal',2.)));n.pack('<I',ACTOR+0x1e8,0xabcdef07);n.pack('<3f',ACTOR+0x14c,*c.get('position',[1.,2.,3.]));n.write(PATH+0x10,bytes([3]));n.pack('<I',PATH+0x7c,ROWS);n.pack('<6I',P+0x84,*[0x12340000+i for i in range(6)]);n.pack('<I',P+0x6c,0 if c.get('noSelected')else ROWS+c.get('index',1)*0x5c)
 for i in range(3):
  p=ROWS+i*0x5c;n.pack('<I',p,NAMES+i*0x20);n.write(NAMES+i*0x20,['alpha','beta','gamma'][i].encode()+b'\0');n.pack('<3f',p+4,*c.get('nodePosition',[4.,9.,7.]));n.pack('<f',p+0x14,c.get('radius',4.));n.write(p+0x28,bytes([c.get('connected',1)]));n.pack('<I',p+0x34,0 if c.get('badEdge')else POINTERS+i*4);n.pack('<I',POINTERS+i*4,EDGES+i*0x20);n.write(EDGES+i*0x20+0x10,bytes([i if c.get('forward',True)else(i+1)%3]))
 tokens=c.get('tokens',['beta'])
 for i,t in enumerate(tokens):n.pack('<I',ARGS+i*4,TOKENS+i*0x100);n.write(TOKENS+i*0x100,t.encode('latin1')+b'\0')
 segments=[(SYS,0x100),(ACTOR,0x300),(REF,0x100),(P,0x200),(PATH,0x100),(ROWS,0x200),(EDGES,0x100),(POINTERS,0x100),(ARGS,0x100),(TOKENS,0x1000),(NAMES,0x100),(0x92224c,0x18),(0x9238b0,4),(0x9238c0,4),(0x95e5d4,4)]
 for p,z,v in c.get('patches',[]):n.write(p,int(v).to_bytes(z,'little'))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;packet=c.get('packet',P);count=c.get('count',len(tokens));first=c.get('first',1);mf=False;want=0
 try:want=execute_model(address,system,packet,actor,ARGS,count,first)
 except KeyError:mf=True
 model=snapshot(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(address,[system,packet,actor,ARGS,count&0xffffffff,first],count=4000000)
 except RuntimeError:nf=True
 native=snapshot();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:
   difference=[]
   if group=='images':
    for x,y in zip(a,b):
     for i,(aa,bb)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes']))):
      if aa!=bb:difference.append([hex(x['address']+i),aa,bb])
   errors.append(dict(group=group,context=c,address=hex(address),native=a if group!='images'else difference[:12],model=b if group!='images'else'byte image'))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,packet=packet,actor=actor,args=ARGS,count=count,first=first),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for a,t,first,forward,connected in itertools.product([0x535fc0,0x536fc0],[['beta'],['missing'],['BETA'],['beta','RUN','WALK','TIPTOE'],['beta','2.5'],['beta','param0*2'],['beta','RAND'],[]],[0,1],[0,1],[0,1]):execute143(a,dict(tokens=t,first=first,forward=forward,connected=connected))
for a,c in itertools.product([0x535fc0,0x536fc0],[dict(nullActor=True),dict(nullSystem=True),dict(noController=True),dict(noPath=True),dict(noNode=True),dict(noSelected=True,first=0),dict(badEdge=True),dict(count=-1),dict(count=0),dict(first=0,radius=0.),dict(first=0,radius=32.),dict(first=0,radius=40.),dict(first=0,position=[4.,99.,7.],radius=0.),dict(packet=ACTOR+0x12c),dict(packet=ACTOR+0x14c)]):execute143(a,c)
for a,position,radius in itertools.product([0x535fc0,0x536fc0],[[0.,0.,0.],[-0.,-0.,-0.],[123.125,-49.,-321.75],[1.0000001192092896,0.,-1.0000001192092896]],[0.,1.,4.,50.,1000.]):execute143(a,dict(first=0,position=position,radius=radius))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:6],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=[],closure='actual535FC0/536FC0→51AD80/51A7C0/514920/43C0C0/5B3CF0/52FCB0, no callee adapters')
(nm.BASE/'reports/script-phase143-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase143-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
