"""Original64slot stream open, final CreateFile only normalized."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
HANDLES=0x80079c;PATH=DATA;segments=[(HANDLES,260),(PATH,32)];events=[];config={};API=n.STOP+0x100;n.pack('<I',0x7510dc,API)
def port89(args,model):
 events.append(args);write=wd if model else lambda p,v:n.pack('<I',p,v)
 for p,v in config.get('patches',[]):write(p,v)
 return config['result']
def open89(path,mode):
 access=0;disposition=0
 if mode==0:access=0x80000000;disposition=3
 elif mode==1:access=0x40000000;disposition=2
 elif mode==2:access=0x40000000;disposition=4
 selected=0xffffffff
 for i in range(64):
  if rd(0x8007a0+i*4)==0xffffffff:selected=i;break
 value=port89([path,access,1,0,disposition,0,0],True);wd((0x8007a0+(selected<<2))&0xffffffff,value);return value if value==0xffffffff else selected

def hook89(mu,address,size,data):
 if address!=API:return
 sp=mu.reg_read(UC_X86_REG_ESP);value=port89(list(n.unpack('<7I',sp+4)),False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+32);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook89)
def execute89(c):
 global shadow,checks,events,config
 config=c;n.write(PATH,b'file.dat\0'+bytes(23));n.pack('<I',HANDLES,0xabcdef01)
 for i in range(64):n.pack('<I',0x8007a0+i*4,0xffffffff if i in c['free']else c.get('live',0x12345678))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];want=open89(PATH,c['mode']);model=snap(True);me=events.copy();events=[];actual=n.call(0x4ff2f0,[PATH,c['mode']]);final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(path=PATH,mode=c['mode']),initial=initial,returnValue=actual,final=final,nativeEvents=ne))
for mode,result,free,live in itertools.product([0,1,2,3,0xffffffff],[0,1,0x80000000,0xffffffff],[[0],[1],[63],[],[3,7]],[0,0x12345678]):execute89(dict(mode=mode,result=result,free=free,live=live))
execute89(dict(mode=0,result=17,free=[3,7],patches=[[0x8007a0+12,99],[0x8007a0,0xffffffff]]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=1,ports=['CreateFileIAT7510dc'],closure='Whole original4ff2f0 stream open and64slot handle scan/store; only final CreateFile normalized')
(nm.BASE/'reports/script-phase89-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase89-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
