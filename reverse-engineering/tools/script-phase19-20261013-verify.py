"""Actual52c880/52c800/52caf0 with only predicate and expression child ports."""
import importlib.util,json,struct,itertools,random,math
from pathlib import Path
sp=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(sp);sp.loader.exec_module(native);n=native.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI,UC_X86_REG_ECX,UC_X86_REG_EDI
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
D=n.DATA;P=D+0x1000;L=D+0x2000;N=L+0x100;DESC=D+0x3000;SCRIPT=D+0x4000;IDLE=SCRIPT+0x100;TARGET=SCRIPT+0x200;REF=SCRIPT+0x300;ACTOR=D+0x5000;SYS=D+0x6000;CB=n.STOP+0x500;BAD=0x30000000
segments=[(P-0x200,0x500),(L,0x500),(DESC,0x200),(SCRIPT,0x500)]
cases=[];errors=[];checks=0;config={};shadow={};events=[];ordinal={};trace=[]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def signed(v):return v-0x100000000 if v>=0x80000000 else v
def rb(p):
 if p not in shadow:raise RuntimeError('unmapped read '+hex(p))
 return shadow[p]
def wb(p,v):
 if p not in shadow:raise RuntimeError('unmapped write '+hex(p))
 shadow[p]=v&255
 def_unused=0
def rd(p):return sum(rb((p+i)&0xffffffff)<<(i*8)for i in range(4))
def wd(p,v):
 for i in range(4):wb((p+i)&0xffffffff,v>>(i*8))
def rw(p):return rb(p)|(rb(p+1)<<8)
def ww(p,v):wb(p,v);wb(p+1,v>>8)
def slot(node):v=rb(node+0xd);return v-256 if v>=128 else v
def cache(bank,node):return (P+(bank*5+10+slot(node))*4)&0xffffffff
def port(name,args,model):
 global events,ordinal
 key=name;ordinal[key]=ordinal.get(key,0)+1;count=ordinal[key]
 read=rd if model else lambda p:n.unpack('<I',p)[0]
 events.append(dict(name=name,args=args,observed=[read(P+4),read(P+8),read(P+0x50),read(P+0x64)]))
 for key in [name,name+'#'+str(count)]:
  for p,size,v in config.get('patches',{}).get(key,[]):
   if model:
    for i in range(size):wb(p+i,v>>(i*8))
   else:n.write(p,int(v).to_bytes(size,'little'))
 values=config.get('results',{}).get(name,[bits(config.get('left',1.))]if name=='Predicate'else[bits(config.get('right',1.))]);return values[min(count-1,len(values)-1)]
def hook(mu,address,size,data):
 if address in [0x52c880,0x52c800,0x52caf0,0x514640,0x5145a0]:trace.append(hex(address))
 if address not in [CB,CB+0x10,0x514920]:return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x514920:name='Expression';args=list(n.unpack('<3I',sp+4))
 else:name='Predicate';args=[address]+list(n.unpack('<5I',sp+4))
 result=port(name,args,False);n.pack('<I',D+0xf000,result);n.write(n.STOP+0x100,b'\xd9\x05'+struct.pack('<I',D+0xf000)+b'\xc3');mu.reg_write(UC_X86_REG_EIP,n.STOP+0x100)
n.mu.hook_add(UC_HOOK_CODE,hook)
def expr(bank,actor,packet,node):
 result=port('Expression',[actor,packet,rd(node+0x10)],True);wd(cache(bank,node),result)
def finish(bank,lst,actor,packet,current):
 flag=(packet+0x38+bank*20)&0xffffffff
 if not rb(flag+1):return
 if rb(flag):
  node=rd(current if current else lst)
  while node:
   if rb(node+0xe)&8:expr(bank,actor,packet,node)
   node=rd(node)
 wb(flag+1,0)
def evaluate(bank,system,lst,actor,packet):
 if not packet or not lst:return 0
 node=rd(lst);left=0;flag=(packet+0x38+bank*20)&0xffffffff
 while node:
  desc=rd(node+0x1c);match=False
  if desc:
   callback=rd(desc+4)
   if callback:arg18=rd(node+0x18);arg14=rd(node+0x14);left=port('Predicate',[callback,system,packet,actor,arg14,arg18],True)
   other=rd(node+0x28);otherDesc=rd(other+0x1c)if other else 0
   if otherDesc:
    callback=rd(otherDesc+4)
    if callback:arg18=rd(node+0x18);arg14=rd(node+0x14);right=port('Predicate',[callback,system,packet,actor,arg14,arg18],True)
    else:right=left
   else:
    flags=rw(node+0xe)
    if flags&8:
     if rb(flag):expr(bank,actor,packet,node)
     right=rd(cache(bank,node))
    elif flags&4:right=rd((packet+0x14+slot(node)*4)&0xffffffff)
    else:right=rd(node+8)
   op=rb(node+0xc);a,b=fl(left),fl(right)
   if op==0:match=a==b
   elif op==1:match=a<b
   elif op==2:match=a>b
   elif op==3:match=a<=b
   elif op==4:match=a>=b
   elif op==5:match=a!=b
  if match:
   if not rb(node+0xe)&1:finish(bank,lst,actor,packet,node);wb(flag,0);return node
  else:
   while rb(node+0xe)&1:
    node=rd(node)
    if not node:break
    if rb(flag)and rb(node+0xe)&8:expr(bank,actor,packet,node);wd(node+8,rd(cache(bank,node)))
   if not node:break
  node=rd(node)
 finish(bank,lst,actor,packet,0);wb(flag,0);return 0
def enter(packet,target):
 if not target:return
 flags=rd(packet+0x50)
 if not flags&4:ww(packet+0xb2,0)
 wd(packet+0x50,flags&0xfffffffb);wd(packet+8,target);wd(packet+0xc,0);wd(packet+0x10,0);wb(packet+0x38,1);first=rd(rd(packet+8)+0x10)
 if first:wd(packet+0x50,rd(packet+0x50)|1)
 wd(packet+0xc,first)
def bind(packet,script,target):
 wd(packet+0x50,rd(packet+0x50)&0xfffffffb);ww(packet+0xb2,0)
 if not script:raise RuntimeError('nonnull supplied script domain')
 empty=rd(packet)==0;wd(packet+4,script);wd(packet+0x10,0)
 if empty:wd(packet,script)
 for i in range(4):wd(packet+0x14+i*4,rd(script+0x1c+i*8))
 if not target:raise RuntimeError('nonnull target domain')
 enter(packet,target);wb(packet+0xb4,0);wd(packet+0xb8,0);wb(packet+0xb5,0);wd(packet+0xbc,0);wd(packet+0xc0,0)
def scan(system,actor,packet):
 if not system or not packet:return 0
 script=rd(packet+4)
 if not script or signed(rd(packet+0x64))>=4:return 0
 node=rd(script+0x40);statePass=False
 while True:
  while node:
   wb(packet+0x4c,1);wb(packet+0x4d,1);guard=node+0x1c
   if not rd(guard)or evaluate(1,system,guard,actor,packet):
    if rd(node+0xc):
     wb(packet+0x38,1);wb(packet+0x39,1);other=rd(node+0xc);idle=rd(other+0x38);match=evaluate(0,system,idle+8,actor,packet)
     if match:
      other=rd(node+0xc);target=rd(match+0x24)
      if target!=rd(other+0x38):
       depth=rd(packet+0x64);wd((packet+0x54+depth*4)&0xffffffff,node);wd(packet+0x64,rd(packet+0x64)+1);target=rd(match+0x24);other=rd(node+0xc);bind(packet,other,target);return 1
   if not statePass:rd(packet+4)
   node=rd(node)
  if statePass:return 0
  state=rd(packet+8)
  if not state:return 0
  node=rd(state+0x1c);statePass=True

def prepare(c,method):
 n.write(D,bytes(0x10000))
 def put(p,v,size=4):n.write(p,int(v&((1<<(size*8))-1)).to_bytes(size,'little'))
 put(P,SCRIPT);put(P+4,SCRIPT);put(P+8,IDLE);put(P+0x50,0xa5);put(P+0x64,c.get('depth',0));put(P+0xb8,bits(4.));put(P+0xb2,0x1234,2)
 for i in range(4):put(SCRIPT+0x1c+i*8,bits(i+.5))
 put(SCRIPT+0x38,IDLE);put(TARGET+0x10,0);put(L,N);put(IDLE+8,N)
 count=c.get('count',1)
 for i in range(count):
  node=N+i*0x40;put(node,N+(i+1)*0x40 if i+1<count else 0);put(node+8,c.get('rightBits',bits(c.get('right',1.))));put(node+0xc,c.get('ops',[c.get('op',0)])[min(i,len(c.get('ops',[c.get('op',0)]))-1)],1);put(node+0xd,c.get('slots',[c.get('slot',0)])[min(i,len(c.get('slots',[c.get('slot',0)]))-1)]&255,1);put(node+0xe,c.get('flagsList',[c.get('flags',0)])[min(i,len(c.get('flagsList',[c.get('flags',0)]))-1)],2);put(node+0x10,DESC+0x100+i*4);put(node+0x14,0x11110000+i);put(node+0x18,0x22220000+i);put(node+0x1c,0 if i in c.get('noDesc',[])else DESC+i*0x10);put(DESC+i*0x10+4,0 if i in c.get('noHandler',[])else CB);put(node+0x24,TARGET)
  if c.get('alternate'):put(node+0x28,DESC+0x80);put(DESC+0x80+0x1c,DESC+0xc0);put(DESC+0xc0+4,0 if c.get('alternateNull')else CB+0x10)
 for bank in [0,1]:
  put(P+0x38+bank*20,c.get('cacheFlag',1),1);put(P+0x39+bank*20,c.get('finishFlag',1),1)
  for i in range(5):put(P+(10+bank*5+i)*4,c.get('cachedBits',bits(c.get('right',1.))))
 for bank in [0,1]:put(P+0x38+bank*20,c.get('cacheFlag',1),1);put(P+0x39+bank*20,c.get('finishFlag',1),1)
 for i in range(4):put(P+0x14+i*4,c.get('parameterBits',bits(c.get('right',1.))))
 if method=='Scan'or(method=='Tick'and c.get('refs')):
  put(REF+0xc,SCRIPT);put(SCRIPT+0x40,0 if c.get('stateRefs')else REF);put(IDLE+0x1c,REF if c.get('stateRefs')else 0)
  if c.get('guard'):put(REF+0x1c,N+0x100);put(N+0x100+0x1c,DESC);put(N+0x100+8,bits(c.get('guardValue',1.)));put(N+0x100+0x14,0xaabbccdd);put(N+0x100+0x18,0xeeff0011)
  if c.get('sameTarget'):put(N+0x24,IDLE)
  if c.get('noScript'):put(REF+0xc,0)
 if c.get('empty'):put(L,0);put(IDLE+8,0)
 if c.get('noCurrent'):put(P+4,0)
 for p,size,v in c.get('initialPatches',[]):put(p,v,size)
 return [dict(address=p,bytes=n.read(p,z).hex())for p,z in segments]
def execute(c,method='Evaluate'):
 global config,shadow,events,ordinal,trace,checks
 config=c;initial=prepare(c,method);shadow={p+i:x for row in initial for p in [row['address']]for i,x in enumerate(bytes.fromhex(row['bytes']))};events=[];ordinal={};trace=[]
 packet=0 if c.get('nullPacket')else P;lst=0 if c.get('nullList')else L;system=0 if c.get('nullSystem')else SYS;bank=c.get('bank',0);current=c.get('current',0);got=want=0;fault=wantfault=None
 try:
  if method=='Evaluate':got=n.call(0x52c880,[system,lst,ACTOR,packet],{UC_X86_REG_EAX:bank})
  elif method=='Finish':got=n.call(0x52c800,[lst,ACTOR,packet],{UC_X86_REG_EDI:bank,UC_X86_REG_ECX:current})
  elif method=='Tick':got=n.call(0x52cc90,[system,ACTOR,ACTOR,packet,0])
  else:got=n.call(0x52caf0,[system,ACTOR],{UC_X86_REG_ESI:packet})
 except RuntimeError as exc:fault=str(exc)
 nativeEvents=events.copy();nativeTrace=trace.copy();nativeState=[dict(address=p,bytes=n.read(p,z).hex())for p,z in segments];events=[];ordinal={}
 try:
  if method=='Evaluate':want=evaluate(bank,system,lst,ACTOR,packet)
  elif method=='Finish':finish(bank,lst,ACTOR,packet,current)
  elif method=='Tick':
   if packet and rd(packet+4):
    if not scan(system,ACTOR,packet):
     currentState=rd(packet+8)
     if currentState:
      match=evaluate(0,system,currentState+8,ACTOR,packet)
      if match:message=rw(match+0xe);flags=rd(packet+0x50);wd(packet+0x50,flags^(((message*2)^flags)&4));enter(packet,rd(match+0x24))
  else:want=scan(system,ACTOR,packet)
 except RuntimeError as exc:wantfault=str(exc)
 modelState=[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex())for p,z in segments]
 comparisons=[('fault',bool(fault),bool(wantfault)),('events',nativeEvents,events),('memory',nativeState,modelState)]
 if method not in ['Finish','Tick']and not fault:comparisons.append(('return',got,want))
 for group,a,b in comparisons:
  checks+=1
  if a!=b:errors.append(dict(case=len(cases),method=method,group=group,got=a,want=b,context=c))
 cases.append(dict(method=method,context=c,inputs=dict(bank=bank,system=system,list=lst,actor=ACTOR,packet=packet,current=current),initial=initial,returnValue=got,fault=fault,nativeEvents=nativeEvents,nativeTrace=nativeTrace,final=nativeState))
values=[0,0x80000000,bits(-2.),bits(.5),bits(1.),bits(2.),0x7f800000,0xff800000,0x7fc00001,0xffc12345]
for bank,op,a,b in itertools.product([0,1],range(6),values,values):execute(dict(bank=bank,op=op,rightBits=b,results={'Predicate':[a]}))
for op in [6,127,128,255]:execute(dict(op=op,count=3,flagsList=[1,0,0],noDesc=[1]))
for flags,cacheFlag,finishFlag,bank in itertools.product([0,1,4,5,8,9,12,13],[0,1],[0,1],[0,1]):execute(dict(flags=flags,cacheFlag=cacheFlag,finishFlag=finishFlag,bank=bank,count=3,ops=[1,0,0]))
for slotValue in range(-128,128):
 for flags in [4,8]:execute(dict(slot=slotValue,flags=flags))
for c in [dict(empty=True),dict(nullPacket=True),dict(nullList=True),dict(noDesc=[0]),dict(noHandler=[0],right=0),dict(alternate=True,results={'Predicate':[bits(2.),bits(2.)]}),dict(alternate=True,alternateNull=True),dict(count=3,noHandler=[1,2],ops=[1,0,0],right=2,results={'Predicate':[bits(2.)]}),dict(count=3,flagsList=[1,8,8],ops=[1,0,0]),dict(count=3,flagsList=[0,8,8],ops=[0,0,0]),dict(count=3,flagsList=[1,9,8],ops=[1,0,0]),dict(count=3,flagsList=[1,9,8],ops=[0,0,0])]:execute(c)
patchCases=[dict(flags=8,patches={'Expression#1':[[N+0xd,1,1]]}),dict(flags=8,patches={'Expression#1':[[P+0x38,1,0]]}),dict(count=3,flagsList=[1,8,8],ops=[1,0,0],patches={'Expression#1':[[N+0x40+0xd,1,2]]}),dict(alternate=True,patches={'Predicate#1':[[N+0x14,4,0xabcdef01],[N+0x18,4,0xfedcba98]]}),dict(patches={'Predicate#1':[[N+0xc,1,5]]}),dict(count=3,patches={'Predicate#1':[[N,4,N+0x80],[N+0xe,2,1]]}),dict(count=3,flagsList=[0,8,8],patches={'Expression#1':[[N+0x40,4,0]]}),dict(count=3,flagsList=[0,8,8],patches={'Predicate#1':[[P+0x39,1,0]]}),dict(initialPatches=[[N+0x1c,4,BAD]]),dict(initialPatches=[[N+0x28,4,BAD]]),dict(flags=8,patches={'Expression#1':[[N,4,BAD]]}),dict(count=2,flagsList=[0,8],initialPatches=[[N+0x40+0x10,4,BAD]])]
for c in patchCases:execute(c)
for bank,flag,finishFlag,current in itertools.product([0,1],[0,1],[0,1],[0,N,N+0x40]):execute(dict(bank=bank,cacheFlag=flag,finishFlag=finishFlag,count=3,flags=8,current=current),'Finish')
for depth,state,guard,left in itertools.product([-1,0,1,2,3,4,0x7fffffff],[False,True],[False,True],[0.,1.]):execute(dict(depth=depth,stateRefs=state,guard=guard,left=left),'Scan')
for c in [dict(nullSystem=True),dict(nullPacket=True),dict(noCurrent=True),dict(sameTarget=True),dict(noScript=True),dict(empty=True),dict(stateRefs=True,guard=True,guardValue=0),dict(depth=-4),dict(depth=-5),dict(guard=True,patches={'Predicate#1':[[P+4,4,BAD]]}),dict(patches={'Predicate#1':[[P+0x64,4,3]]}),dict(patches={'Predicate#1':[[N+0x24,4,BAD]]}),dict(initialPatches=[[REF+0xc,4,BAD]]),dict(initialPatches=[[SCRIPT+0x1c,4,bits(3.)],[SCRIPT+0x24,4,bits(7.)]])]:execute(c,'Scan')
for refs,guard,left,flags in itertools.product([False,True],[False,True],[0.,1.],[0,2,8]):execute(dict(refs=refs,guard=guard,left=left,flags=flags),'Tick')
assembly=[];cs=Cs(CS_ARCH_X86,CS_MODE_32)
for a,z in [(0x52c800,114),(0x52c880,587),(0x52caf0,401)]:assembly.append(dict(address=hex(a),size=z,bytes=n.read(a,z).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,z),a)]))
report=dict(binarySha256=n.sha256,nativeChecks=checks,cases=len(cases),mismatches=len(errors),errors=errors,faultCases=sum(bool(c['fault'])for c in cases),counts={k:sum(c['method']==k for c in cases)for k in ['Evaluate','Finish','Scan','Tick']},remainingPorts=['Predicate dynamic callback ST0 float','Expression514920 ST0 float'],limits=['Finite/infinity/quietNaN predicate values, signalingNaN FPU payload/status outside paired domain.','Nonnull supplied reference script/target and finite binding defaults. Acyclic prepared lists.','No new address or authored-command credit.'] )
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,cases=cases)),('assembly',dict(binarySha256=n.sha256,functions=assembly,jumpTable=dict(address='0x52cacc',bytes=n.read(0x52cacc,24).hex(),targets=[hex(x)for x in n.unpack('<6I',0x52cacc)])))]:(native.BASE/'reports'/('script-phase19-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:3])[:5000])
