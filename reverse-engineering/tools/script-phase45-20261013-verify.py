"""Originalfour-slot pool/BOMattach/free/close/filesystemconstructor; onlyfinal prefix/byte/seek/size/exists/open/close I/O leaves."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
def wb(p,v):
 if p not in shadow:raise KeyError(p)
 shadow[p]=v&255
n=nm.NativeX86();CUSTOMPOOL45=D+0x1000;CUSTOMBUFFER45=D+0x4000;PATH45=D+0x3000;segments=[(D,0x10000),(0x91eebc,8),(0x91ee88,4),(0x917850,0x1610),(0x8cab50,0x4000)];selected45=0

def zero45(p,size):
 for i in range(size):wb(p+i,0)
def allocate45():
 first=rd(0x91eebc)
 if not first:first=0x917850;wd(0x91eebc,first);zero45(first,0x1610);wd(0x91eec0,0x8cab50)
 for i in range(4):
  p=first+i*0x584
  if not rd(p):zero45(p,0x584);buffer=(rd(0x91eec0)+i*0x1000)&0xffffffff;wd(p,buffer);zero45(buffer,0x1000);return p
 return 0
def port45(name,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];p=selected45;events.append(dict(name=name,args=args,fields=[]if not p else[read(p),read(p+4),read(p+0x574)],options=read(0x91ee88)))
 for address,size,value in config.get('patches',{}).get(name,[]):
  if model:
   for i in range(size):wb(address+i,value>>(8*i))
  else:n.write(address,int(value).to_bytes(size,'little'))
 return {'Prefix':config.get('prefix',0),'Byte':config.get('nextByte',0xbf),'Size':config.get('size',17),'Exists':config.get('exists',1),'Open':config.get('handle',0x12345678)}.get(name,0)
def attach45(handle):
 global selected45
 p=allocate45();selected45=p
 if not p:return 0
 for off in[0x52c,0x51c,0x570]:wd(p+off,0xffffffff)
 wd(p+0x50c,p+0x108);wd(p+4,handle);wd(p+0x57c,0);wd(p+0x580,0);wd(p+0x510,p+0x30a);wd(p+0x514,512);wd(p+0x518,512);prefix=port45('Prefix',[handle],True)&65535;wb(p+0x578,0);wb(p+0x579,0)
 if prefix==0xfffe:wb(p+0x578,2)
 elif prefix==0xfeff:wb(p+0x578,1)
 elif prefix==0xbbef:
  if port45('Byte',[handle],True)&255==0xbf:wb(p+0x579,1)
 elif prefix==0xefbb:
  if port45('Byte',[handle],True)&255==0xbf:wb(p+0x579,2)
 if not rb(p+0x578)and not rb(p+0x579):port45('Seek',[handle,0,0,0],True)
 value=port45('Size',[handle],True);wd(p+0x574,value);return p
def close45(parser):wd(parser,0);port45('Close',[rd(parser+4)],True)
def openfile45(path):
 if not port45('Exists',[path],True):return 0
 handle=port45('Open',[path,0,rd(0x91ee88),0],True)
 if not handle:return 0
 parser=attach45(handle)
 if not parser:port45('Close',[handle],True);return 0
 for i in range(256):
  c=rb(path+i);wb(parser+8+i,c)
  if not c:break
 return parser

def hook45(mu,address,size,data):
 global selected45
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x4fc758:selected45=mu.reg_read(UC_X86_REG_EAX);return
 if address==0x4fb550:handle,buffer,count=n.unpack('<3I',sp+4);prefix=port45('Prefix',[handle],False);n.pack('<H',buffer,prefix&65535);value=2
 elif address==0x4fb7f0:value=port45('Byte',list(n.unpack('<I',sp+4)),False)
 elif address==0x4f6de0:value=port45('Seek',list(n.unpack('<4I',sp+4)),False)
 elif address==0x4f6b40:value=port45('Size',list(n.unpack('<I',sp+4)),False)
 elif address==0x4ff120:value=port45('Exists',list(n.unpack('<I',sp+4)),False)
 elif address==0x4fa3f0:value=port45('Open',list(n.unpack('<4I',sp+4)),False)
 elif address==0x4f99e0:value=port45('Close',list(n.unpack('<I',sp+4)),False)
 else:return
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook45)
def execute45(c,method):
 global config,shadow,events,checks,selected45
 config=c;n.write(D,bytes([0xa5])*0x10000);n.write(0x917850,bytes([0xa5])*0x1610);n.write(0x8cab50,bytes([0xa5])*0x4000);n.pack('<II',0x91eebc,0 if c.get('defaultPool')else CUSTOMPOOL45,CUSTOMBUFFER45);n.pack('<I',0x91ee88,0x12345678);n.write(PATH45,c.get('path','AI\\root.scp').encode('latin1')+b'\0')
 for i in range(4):n.pack('<I',CUSTOMPOOL45+i*0x584,0x87654321 if c.get('mask',0)&(1<<i)else 0)
 parser=0 if c.get('nullParser')else CUSTOMPOOL45+c.get('slot',0)*0x584;n.pack('<I',parser+4,c.get('handle',0x12345678))if parser else None;initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];selected45=parser if method in['Free','Close']else 0;want=0;modelFault=False
 try:
  if method=='Allocate':want=allocate45()
  elif method=='Attach':want=attach45(c.get('handle',0x12345678))
  elif method=='Free':wd(parser,0)
  elif method=='Close':close45(parser)
  else:want=openfile45(PATH45)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];selected45=parser if method in['Free','Close']else 0;nativeFault=False;got=0
 try:
  if method=='Allocate':got=n.call(0x4f1240)
  else:got=n.call({'Attach':0x4fc750,'Free':0x4f12e0,'Close':0x4fa300,'OpenFile':0x4fc860}[method],[PATH45 if method=='OpenFile'else c.get('handle',0x12345678)if method=='Attach'else parser])
  if method in['Free','Close']:got=0
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=parser,path=PATH45,handle=c.get('handle',0x12345678)),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne))
for mask,defaultPool in itertools.product(range(16),[False,True]):execute45(dict(mask=mask,defaultPool=defaultPool),'Allocate')
for mask,prefix,nextByte,size in itertools.product([0,1,3,7,15],[0,0xfffe,0xfeff,0xbbef,0xefbb,0x1234],[0xbf,0x1bf,0],[0,1,4096]):execute45(dict(mask=mask,prefix=prefix,nextByte=nextByte,size=size),'Attach')
for method,slot in itertools.product(['Free','Close'],range(4)):execute45(dict(slot=slot),method)
for method in['Free','Close']:execute45(dict(nullParser=True),method)
for exists,handle,mask in itertools.product([0,1],[0,0x400,0x12345678],[0,15]):execute45(dict(exists=exists,handle=handle,mask=mask),'OpenFile')
for prefix in[0,0xfffe,0xfeff,0xbbef,0xefbb]:execute45(dict(prefix=prefix,defaultPool=True),'OpenFile')
for patches in[{'Prefix':[[CUSTOMPOOL45+0x578,1,9],[CUSTOMPOOL45+0x579,1,9]]},{'Byte':[[CUSTOMPOOL45+0x578,1,7]]},{'Size':[[CUSTOMPOOL45+4,4,0x98765432]]},{'Close':[[CUSTOMPOOL45,4,0x24681357]]}]:execute45(dict(prefix=0xbbef,patches=patches),'Close'if 'Close'in patches else 'Attach')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=5,methods={method:sum(r['method']==method for r in cases)for method in['Allocate','Attach','Free','Close','OpenFile']},ports=['4fb550 normalizedzero-localprefix','4fb7f0Byte','4f6de0Seek','4f6b40Size','4ff120Exists','4fa3f0Open','4f99e0Close'])
(nm.BASE/'reports/script-phase45-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase45-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
