"""Original container allocators, critical-section wrappers, lazy parent and64-bit offset helpers."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
COMP=0x297dc60;CON=D+0x7000;LOCK=0x88ab48;BASEOFFSET=0x91ee9c;segments=[(COMP,960),(CON,256),(LOCK,4),(BASEOFFSET,4)];events=[];config={};ENTER=n.STOP+0x100;LEAVE=n.STOP+0x200;n.pack('<I',0x7510b8,ENTER);n.pack('<I',0x7510b4,LEAVE)
def port92(name,args,model):
 events.append(dict(name=name,args=args));write=wd if model else lambda p,v:n.pack('<I',p,v)
 for p,v in config.get('patches',{}).get(name,[]):write(p,v)
 return config.get('openResult',0)
def lock92(name,id):
 if((id-1)&0xffffffff)<=11:port92(name,[0x91ef70+id*24],True)
def record92():
 lock92('Enter',rd(LOCK));selected=0xffffffff
 for i in range(20):
  if not rd(COMP+36+i*48):selected=i;wd(COMP+36+i*48,1);break
 lock92('Leave',rd(LOCK));return selected

def parent92(container,index):
 lock92('Enter',rd(LOCK));selected=0xffffffff
 for i in range(8):
  if rd(container+52+i*16)==0xffffffff:selected=i;wd(container+52+i*16,index);break
 lock92('Leave',rd(LOCK));return selected

def ensure92(container,index):
 parent=container+(index+3)*16;handle=rd(parent)
 if handle:return handle
 mode=(rb(container+178)|(rb(container+179)<<8));mode=(mode-65536 if mode&32768 else mode)&0xffffffff;path=rd(container+184);handle=port92('Open',[path,mode,0,0],True);wd(parent,handle);wd(parent+8,0);wd(parent+12,0);return handle

def offset92(container,value):
 offset=signed(value)
 if signed(rd(container))<=-2:offset<<=8
 result=(offset+signed(rd(BASEOFFSET)))&((1<<64)-1);return[result&0xffffffff,result>>32]

def hook92(mu,address,size,data):
 if address not in[ENTER,LEAVE,0x4fa3f0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);name='Enter'if address==ENTER else'Leave'if address==LEAVE else'Open';args=list(n.unpack('<4I'if name=='Open'else'<I',sp+4));value=port92(name,args,False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+(4 if name=='Open'else 8));mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook92)
def execute92(c):
 global shadow,checks,config,events
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.pack('<I',LOCK,c.get('id',1));n.pack('<I',BASEOFFSET,c.get('base',0));method=c['method']
 for i in range(20):n.pack('<I',COMP+36+i*48,0 if i in c.get('free',[])else c.get('live',1))
 for i in range(8):n.pack('<I',CON+52+i*16,0xffffffff if i in c.get('free',[])else c.get('live',1))
 if method=='Ensure':parent=CON+(c['index']+3)*16;n.pack('<I',parent,c['handle']);n.pack('<h',CON+178,c['mode']);n.pack('<I',CON+184,DATA)
 if method=='Offset':n.pack('<I',CON,c['marker'])
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];regs={}
 if method=='Record':want=[record92()];address=0x4f0bd0;args=[];inputs={}
 elif method=='Parent':want=[parent92(CON,c['recordIndex'])];address=0x4f0c40;args=[CON,c['recordIndex']];inputs=dict(container=CON,recordIndex=c['recordIndex'])
 elif method=='Ensure':want=[ensure92(CON,c['index'])];address=0x4f0cb0;args=[];regs={UC_X86_REG_EAX:CON,UC_X86_REG_ECX:c['index']};inputs=dict(container=CON,index=c['index'])
 elif method=='Offset':want=offset92(CON,c['offset']);address=0x4f0a80;args=[CON,c['offset']];inputs=dict(container=CON,offset=c['offset'])
 else:lock92(method,c['id']);want=None;address=0x4ffaa0 if method=='Enter'else 0x4ffac0;args=[c['id']];inputs=dict(id=c['id'])
 model=snap(True);me=events.copy();events=[];eax=n.call(address,args,regs);actual=[eax,n.mu.reg_read(UC_X86_REG_EDX)]if method=='Offset'else[eax];final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  if group=='return'and want is None:continue
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual if want is not None else None,final=final,nativeEvents=ne))
for method,id in itertools.product(['Enter','Leave'],[0,1,7,12,13,0xffffffff]):execute92(dict(method=method,id=id))
for free,id,live in itertools.product([[0],[1],[19],[],[3,7]],[0,1,12,13],[1,0xffffffff]):execute92(dict(method='Record',free=free,id=id,live=live))
for free,id,record in itertools.product([[0],[1],[7],[],[3,7]],[0,1,12,13],[0,19,0xffffffff]):execute92(dict(method='Parent',free=free,id=id,recordIndex=record))
for index,handle,mode,result in itertools.product([0,7],[0,1,0xffffffff],[0,1,-1,-32768],[0,1,0x400,0xffffffff]):execute92(dict(method='Ensure',index=index,handle=handle,mode=mode,openResult=result))
for marker,offset,base in itertools.product([0,1,0xfffffffe,0xfffffffd,0x80000000,0xffffffff],[0,1,0xffffffff,0x80000000,0x7fffffff],[0,17,0xffffffff,0x80000000]):execute92(dict(method='Offset',marker=marker,offset=offset,base=base))
execute92(dict(method='Record',id=1,free=[7],patches={'Enter':[[LOCK,12],[COMP+36,0]],'Leave':[[COMP+36,7]]}))
execute92(dict(method='Parent',id=1,free=[7],recordIndex=19,patches={'Enter':[[LOCK,13],[CON+52,0xffffffff]]}))
execute92(dict(method='Ensure',index=0,handle=0,mode=-1,openResult=0x400,patches={'Open':[[CON+48,7],[CON+56,9],[CON+60,11]]}))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=6,ports=['EnterCriticalSectionIAT7510b8','LeaveCriticalSectionIAT7510b4','gameOpen4fa3f0'],closure='Original record/parent allocators→actual4ffaa0/4ffac0→final critical-section ports; actual lazy parent and64bit base helper')
(nm.BASE/'reports/script-phase92-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase92-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
