"""Original action lookup, registration, custom-register array allocator and deep action-list copier."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
from unicorn.x86_const import UC_X86_REG_ECX
n=nm.NativeX86();actionRows=[];at=0x8019c0
while n.unpack('<I',at)[0]:p=n.unpack('<I',at)[0];actionRows.append(dict(address=at,name=native_text(p),namePointer=p));at+=12
originalTable=n.read(0x8019c0,at+12-0x8019c0);segments=[(D,0x10000),(0x922214,0x38),(0x8019c0,len(originalTable))]+[(r['namePointer'],len(r['name'])+1)for r in actionRows];SOURCE=D+0x1100;DEST=D+0x1500;ACTION1=D+0x1200;ACTION2=D+0x1280;ARRAY1=D+0x1800;ARRAY2=D+0x1820;CUSTOM=D+0x2000;KEY=D+0x2400

def zero36(p,size):
 for i in range(size):
  if p+i not in shadow:raise KeyError(p+i)
  wb(p+i,0)
def diag36():events.append(dict(name='Diagnostic',callback=0x512850,args=[]))
def find36(name):
 for table in[rd(0x922228),0x8019c0]:
  if not table:continue
  row=table
  while rd(row):
   if name and fold(text(name))==fold(text(rd(row))):return row
   row+=12
 return 0
def allocate36(top,bottom,size):
 if not top or not bottom:return 0
 if((rd(top)+size)&0xffffffff)>=rd(bottom):return 0
 result=(rd(top)+15)&0xfffffff0;wd(top,(result+size)&0xffffffff);zero36(result,size);return result
def setactions36(table):
 wd(0x922228,table);row=table;count=0
 while rd(row):ww(row+10,count);wb(row+9,1);count+=1;row+=12
 row=0x8019c0;count=0
 while rd(row):ww(row+10,count);wb(row+9,0);count+=1;row+=12
def append36(listp,node):
 tail=rd(listp+4);wd(node,0);wd(node+4,tail)
 if tail:wd(tail,node)
 else:wd(listp,node)
 wd(listp+4,node)
def copytoken36(top,bottom,source):
 if not source:return 0
 size=len(text(source))
 if not size:return 0
 size+=1;target=0
 if((rd(top)+size)&0xffffffff)<rd(bottom):target=(rd(top)+15)&0xfffffff0;wd(top,(target+size)&0xffffffff);zero36(target,size)
 else:diag36()
 for i in range(4096):
  c=rb(source+i)
  if target+i not in shadow:raise KeyError(target+i)
  wb(target+i,c)
  if not c:return target
 raise ValueError('unterminated')
def copy36(source,destination,top,bottom):
 node=rd(source)
 while node:
  if not top or not bottom or((rd(top)+20)&0xffffffff)>=rd(bottom):diag36();node=rd(node);continue
  copy=(rd(top)+15)&0xfffffff0;wd(top,(copy+20)&0xffffffff);zero36(copy,20)
  if copy:
   size=(rd(node+12)*4)&0xffffffff;array=0
   if((rd(top)+size)&0xffffffff)<rd(bottom):array=(rd(top)+15)&0xfffffff0;wd(top,(array+size)&0xffffffff);zero36(array,size)
   else:diag36()
   wd(copy+8,array);wd(copy+12,rd(node+12));i=0
   while i<(rd(copy+12)if rd(copy+12)<0x80000000 else rd(copy+12)-0x100000000):sourceText=rd(rd(node+8)+i*4);target=copytoken36(top,bottom,sourceText);wd(rd(copy+8)+i*4,target);i+=1
   wd(copy+16,rd(node+16));append36(destination,copy)
  node=rd(node)
def hook36(mu,address,size,data):
 if address==0x512850:diag36()
n.mu.hook_add(UC_HOOK_CODE,hook36)
def execute36(c,method):
 global config,shadow,events,checks
 config=c;n.write(D,bytes(0x10000));n.write(0x8019c0,originalTable);n.write(0x922214,bytes(0x38));n.pack('<II',TOP,BANK+c.get('alignment',0),BANK+c.get('bankSize',0x4000));n.write(KEY,c.get('name','__missing__').encode('latin1')+b'\0')
 for i,name in enumerate(c.get('customNames',['custom','AlwaysTrue','custom'])):p=KEY+0x100+i*0x100;n.write(p,name.encode('latin1')+b'\0');n.pack('<III',CUSTOM+i*12,p,0x12345678,0xa5b6c7d8)
 n.pack('<III',CUSTOM+len(c.get('customNames',['custom','AlwaysTrue','custom']))*12,0,0x87654321,0x11223344);n.pack('<I',0x922228,CUSTOM if c.get('custom',True)else 0);n.pack('<I',0x922224,0xdeadbeef)
 for index,node,array in[(0,ACTION1,ARRAY1),(1,ACTION2,ARRAY2)]:
  count=c.get('count',2);n.pack('<5I',node,ACTION2 if index==0 and c.get('twoNodes')else 0,ACTION1 if index==1 else 0,array,count,0x87654321+index)
  for i in range(count):p=KEY+0x800+index*0x400+i*0x80;value=c.get('tokens',['alpha','beta','gamma'])[i%len(c.get('tokens',['alpha','beta','gamma']))];n.write(p,value.encode('latin1')+b'\0');n.pack('<I',array+i*4,0 if c.get('nullToken')and i==0 else p)
 n.pack('<II',SOURCE,0 if c.get('empty')else ACTION1,ACTION2 if c.get('twoNodes')else ACTION1);n.pack('<II',DEST,0,0)
 if c.get('existing'):n.pack('<II',DEST,DEST+0x80,DEST+0x80)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];modelFault=False;want=0;top=0 if c.get('nullTop')else TOP;bottom=0 if c.get('nullBottom')else BOTTOM;table=0 if c.get('nullTable')else CUSTOM
 try:
  if method=='FindAction':want=find36(0 if c.get('nullName')else KEY)
  elif method=='AllocateBytes':want=allocate36(top,bottom,c.get('size',0))
  elif method=='SetActions':setactions36(table)
  elif method=='SetPredicates':wd(0x922224,c.get('value',CUSTOM))
  else:copy36(SOURCE,DEST,top,bottom)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];nativeFault=False;got=0
 try:
  if method=='FindAction':got=n.call(0x512f00,regs={UC_X86_REG_EDI:0 if c.get('nullName')else KEY})
  elif method=='AllocateBytes':got=n.call(0x512e60,regs={UC_X86_REG_EDI:top,UC_X86_REG_EAX:bottom,UC_X86_REG_ECX:c.get('size',0)})
  elif method=='SetActions':n.call(0x512f60,[table])
  elif method=='SetPredicates':n.call(0x512fb0,[c.get('value',CUSTOM)])
  else:n.call(0x513b30,[SOURCE,DEST,top,bottom])
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(name=0 if c.get('nullName')else KEY,top=top,bottom=bottom,source=SOURCE,destination=DEST,table=table,size=c.get('size',0),value=c.get('value',CUSTOM)),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne))
for row in actionRows:
 for lower in[False,True]:execute36(dict(name=row['name'].lower()if lower else row['name'],custom=False),'FindAction')
for name,custom in itertools.product(['custom','CUSTOM','alwaysTrue','missing','','\xe0Action'],[False,True]):execute36(dict(name=name,custom=custom,customNames=['custom','AlwaysTrue','\xe0Action']),'FindAction')
execute36(dict(nullName=True),'FindAction')
for size,align,bankSize in itertools.product([0,1,4,12,64,4096],[0,1,7,15],[0,1,64,0x4000]):execute36(dict(size=size,alignment=align,bankSize=bankSize),'AllocateBytes')
for count,tokens,twoNodes,existing in itertools.product([0,1,2,3],[['alpha','beta','gamma'],['','beta','gamma'],['\xe0one','two','three']],[False,True],[False,True]):execute36(dict(count=count,tokens=tokens,twoNodes=twoNodes,existing=existing),'CopyActions')
for count,bankSize,align in itertools.product([0,1,2],[0,20,21,24,32,36,48,64,96],[0,1,15]):execute36(dict(count=count,bankSize=bankSize,alignment=align),'CopyActions')
for method,c in[('CopyActions',dict(nullTop=True,twoNodes=True)),('CopyActions',dict(nullBottom=True,twoNodes=True)),('CopyActions',dict(nullToken=True)),('CopyActions',dict(empty=True)),('AllocateBytes',dict(nullTop=True)),('AllocateBytes',dict(nullBottom=True))]:execute36(c,method)
for names in[[],['custom'],['first','FIRST','\xe0Action']]:execute36(dict(customNames=names),'SetActions')
execute36(dict(nullTable=True),'SetActions')
for value in[0,1,CUSTOM,0xffffffff]:execute36(dict(value=value),'SetPredicates')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['FindAction','AllocateBytes','CopyActions','SetActions','SetPredicates']},builtinActionRows=len(actionRows),newEntries=5,ports=['512850 actualRET diagnostic observer only'])
(nm.BASE/'reports/script-phase36-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase36-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
