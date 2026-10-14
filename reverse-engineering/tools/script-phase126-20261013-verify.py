"""Actual51D130 dispatcher and FollowPlayer124 through real scheduling; final row callbacks only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase124-20261013-verify.py').read_text().split('\ndef execute124(')[0])
from unicorn.x86_const import UC_X86_REG_ESI
n=nm.NativeX86();n.mu.hook_add(UC_HOOK_CODE,hook122);ROWCB=n.STOP+0x800
# Fresh native instance excludes the previous scheduler adapter.
def row_port(callback,form,row,previous,owner,model):
 global ordinal
 ordinal+=1;events.append(dict(callback=callback,args=[form,row,previous,owner]))
 for p,z,v in config.get('rowPatches',{}).get(str(ordinal),[]):
  if model:
   for i in range(z):shadow[p+i]=(v>>(i*8))&255
  else:n.write(p,int(v).to_bytes(z,'little'))
 return config.get('rowReturns',{}).get(str(ordinal),0)
def row_hook(mu,address,size,data):
 if address not in[ROWCB,0x51cbc0,0x51c6a0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=n.unpack('<4I',sp+4);value=row_port(address,*args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,row_hook)
def dispatch126(form,callback):
 previous=0;blocked=False
 if callback and rd(form+0x50)&8:
  reverse=bool(rd(form+0x50)&4)
  if reverse:
   index=rb(form+6)-1
   while index>=0:
    row=form+0x54+index*0x34
    if rb(row+0x2d):
     if row_port(callback,form,row,previous,rd(form),True):break
     if rb(row+0x30)&2:blocked=True
     previous=row
    index-=1
  else:
   index=0
   while index<rb(form+6):
    row=form+0x54+index*0x34
    if rb(row+0x2d):
     if row_port(callback,form,row,previous,rd(form),True):break
     if rb(row+0x30)&2:blocked=True
     previous=row
    index+=1
 wd(form+0x50,(rd(form+0x50)&~0x10)|(0x10 if blocked else 0))
def schedule(callback,model):dispatch126(rd(ACTOR+0x144),callback)
def execute126(method,c):
 global config,shadow,segments,checks,events,ordinal
 config=c;n.write(D,bytes(0x30000));count=c.get('count',3);flags=c.get('formFlags',8);n.pack('<I',FORM,OWNREF);n.write(FORM+6,bytes([count]));n.pack('<I',FORM+0x50,flags);n.pack('<f',FORM+0x128,3.);n.pack('<I',FORM2,OWNREF);n.write(FORM2+6,b'\3');n.pack('<I',FORM2+0x50,8);n.pack('<f',FORM2+0x128,7.)
 for form in[FORM,FORM2]:
  for i in range(8):
   row=form+0x54+i*0x34;n.pack('<6I',row,*[0x12340000+j for j in range(6)]);n.pack('<3f',row+0x18,1.,2.,3.);n.pack('<I',row+0x24,0);n.write(row+0x2d,bytes([c.get('active',[1,1,1,1,1,1,1,1])[i]]));n.write(row+0x30,bytes([c.get('blocked',[0,2,0,0,0,0,0,0])[i]]))
 n.pack('<I',SYS+0x138c,TARGETREF);n.pack('<I',TARGETREF+4,TARGET);n.pack('<I',OWNREF+4,ACTOR);n.pack('<I',ACTOR+0xd0,OWNREF);n.pack('<I',ACTOR+0x144,FORM);n.write(ACTOR+0x149,b'\1\0');n.pack('<I',ACTOR+0x180,bits(2.));n.pack('<3f',TARGET+0x14c,10.,20.,30.);n.pack('<3f',TARGET+0x170,7.,8.,9.);n.pack('<f',TARGET+0x120,5.);n.pack('<6I',TARGET+0x158,*[0x12340000+i for i in range(6)]);n.pack('<f',TABLE,0.);n.pack('<f',TABLE+0x8000,1.);n.pack('<I',0x9238b0,0);n.pack('<I',0x9238c0,0);n.write(P+0x68,bytes([c.get('packetFlags',0)]));n.write(0x92224c,bytes(0x18));n.pack('<I',0x95e5d4,123456789)
 segments=[(D,0x10000),(TABLE,4),(TABLE+0x8000,4),(0x9238b0,4),(0x9238c0,4),(0x92224c,0x18),(0x95e5d4,4)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};callback=0 if c.get('nullCallback')else ROWCB;events=[];ordinal=0;want=0
 if method=='Dispatch':dispatch126(FORM,callback)
 elif method=='Player':want=follow124(SYS,P,ACTOR,ARGS,0,0)
 else:set124(ACTOR,TARGET+0x14c,bits(5.),TARGET+0x158,4,bits(2.))
 model=snap(True);me=events.copy();events=[];ordinal=0;got=0
 if method=='Dispatch':n.call(0x51d130,[callback],regs={UC_X86_REG_ESI:FORM},count=4000000)
 elif method=='Player':got=n.call(0x535000,[SYS,P,ACTOR,ARGS,0,0],count=4000000)
 else:n.call(0x52fcb0,[ACTOR,TARGET+0x14c,bits(5.),TARGET+0x158,4,bits(2.)],count=4000000)
 native=snap();ne=events.copy()
 for group,a,b in [('return',got,want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(formation=FORM,callback=callback,system=SYS,packet=P,actor=ACTOR,args=ARGS,point=TARGET+0x14c,words=TARGET+0x158),initial=initial,returnValue=got,final=native,nativeEvents=ne))
for flags,count,active,stop in itertools.product([0,4,8,12,24,28,0xffffffff],[0,1,3,5],[[1]*8,[0,1,0,1,0,1,0,1],[0]*8],[0,1,2]):execute126('Dispatch',dict(formFlags=flags,count=count,active=active,rowReturns={str(stop):7}if stop else{}))
mutations=[dict(rowPatches={'1':[[FORM+6,1,5]]}),dict(rowPatches={'1':[[FORM+6,1,1]]}),dict(rowPatches={'1':[[FORM,4,OWNREF+0x100]]}),dict(rowPatches={'1':[[FORM+0x50,4,12]]}),dict(rowPatches={'1':[[FORM+0x54+0x30,1,2]]}),dict(rowPatches={'1':[[FORM+0x54+0x34+0x2d,1,0]]}),dict(nullCallback=True)]
for flags,c in itertools.product([8,12],mutations):execute126('Dispatch',dict(c,formFlags=flags))
for method,flags,c in itertools.product(['Player','Mode4'],[8,12],[{},dict(rowReturns={'1':1}),dict(rowPatches={'1':[[ACTOR+0x144,4,FORM2]]}),dict(rowPatches={'1':[[FORM+0x128,4,bits(7.)]]})]):execute126(method,dict(c,formFlags=flags))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=0,refinements=['51d130'],ports=['formation row callback value ports51cbc0/51c6a0 or explicitly supplied callback'],closure='actual535000→534e10→52fcb0→real51d130→rowcallbacks→real52fda0 math')
(nm.BASE/'reports/script-phase126-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase126-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(report['errors']))
