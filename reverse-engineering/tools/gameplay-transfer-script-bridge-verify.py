"""Native tag/transfer chain with actual existing SCP binder, no binder adapter."""
import importlib.util,json,struct,itertools,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('transfer',Path(__file__).with_name('gameplay-player-transfer-verify.py'));t=importlib.util.module_from_spec(s);s.loader.exec_module(t)
a=t.a;n=a.native.NativeX86();t.n=n;a.n=n;BASE=a.BASE;STATE=t.SCRIPT+0x1000;ACTION=STATE+0x400;NAMES=STATE+0x800
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
checks=0;errors=[];vectors=[]
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x514640:a.events.append(['script',a.aid(arg(1)-0x2c8),(arg(7)-t.SCRIPT)//0x100,arg(8)])
 else:t.hook(mu,address,size,user)
for address in [0x514640,0x698900]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def st(i,j):return STATE+i*0x100+j*0x40
def sid(p):return ((p-STATE)//0x100)*2+((p-STATE)%0x100)//0x40 if p else -1
def scriptid(p):return (p-t.SCRIPT)//0x100 if p else -1
def snapshot():
 p=a.actor(0)+0x2c8
 return dict(base=scriptid(n.unpack('<I',p)[0]),script=scriptid(n.unpack('<I',p+4)[0]),state=sid(n.unpack('<I',p+8)[0]),action=0 if n.unpack('<I',p+12)[0]==ACTION else -1,pending=sid(n.unpack('<I',p+16)[0]),parameters=list(n.unpack('<4I',p+20)),timer=n.unpack('<I',p+0x24)[0],flags=n.unpack('<I',p+0x50)[0],depth=n.unpack('<I',p+0x64)[0],blocked=n.unpack('<H',p+0xb2)[0],marker=n.unpack('<B',p+0xb4)[0],deadline=n.unpack('<I',p+0xb8)[0],deadlineState=sid(n.unpack('<I',p+0xbc)[0]))
def run(sourceScript=0,blocked=False,idle=True,action=True,flags=0x25,kind='transfer',first=True):
 global checks
 options=dict(blocked=blocked,players=[0,1,-1,-1,-1,-1,-1,-1],records={'0':dict(script=sourceScript),'1':{}})
 c=t.context(options)
 for i in range(2):c['records'][i]['scriptState']=st(i,1) if idle else 0
 c['records'][0]['words'][-1]=2;t.setup(c)
 n.write(NAMES,b'Base\0');n.write(NAMES+32,b'Idle\0')
 for i in range(2):
  n.pack('<II',t.SCRIPT+i*0x100+0x10,st(i,0),st(i,1))
  for j in range(4):n.pack('<f',t.SCRIPT+i*0x100+0x1c+8*j,i*10+j+.25)
  for j in range(2):
   n.pack('<I',st(i,j),st(i,1) if j==0 else 0);n.pack('<I',st(i,j)+0x18,NAMES+j*32);n.pack('<I',st(i,j)+0x10,ACTION if action else 0)
 p=a.actor(0)+0x2c8;n.pack('<I',p+4,t.SCRIPT+0x100);n.pack('<I',p+8,st(1,1));n.pack('<I',p+0xc,0);n.pack('<I',p+0x10,st(1,0));n.pack('<4f',p+0x14,9.,8.,7.,6.);n.pack('<f',p+0x24,3.5);n.pack('<I',p+0x50,flags);n.pack('<H',p+0xb2,0x7654);n.pack('<BB',p+0xb4,7,8);n.pack('<f',p+0xb8,8.);n.pack('<I',p+0xbc,st(1,0));before=snapshot();a.events.clear()
 if kind=='tag':
  n.write(a.TEXT,b'FALSE\0');n.pack('<I',a.ARGS,a.TEXT);result=n.call(0x44f930,[a.SYS,a.PACK,a.CRE,a.ARGS,1,int(first)],count=1000000);expectedTransfer=t.tag_model(c,first)
 else:result=n.call(0x4876a0,[a.actor(0),a.actor(1),0,0,0],count=1000000);expectedTransfer=t.model(c)
 expectedScript=copy.deepcopy(before)
 if sourceScript>=0 and not blocked and (kind!='tag' or first):
  expectedScript.update(script=sourceScript,state=sourceScript*2+int(idle),action=0 if action else -1,pending=-1,parameters=[a.bits(sourceScript*10+i+.25) for i in range(4)],flags=(flags&~4)|(1 if action else 0),depth=0,blocked=0,marker=0,deadline=0,deadlineState=-1)
 native=dict(transfer=dict(result=result,state=t.snapshot(),events=a.events.copy()),script=snapshot());wanted=dict(transfer=expectedTransfer,script=expectedScript);checks+=1
 if native!=wanted:errors.append(dict(sourceScript=sourceScript,blocked=blocked,idle=idle,action=action,flags=flags,kind=kind,first=first,got=native,want=wanted))
 vectors.append(dict(context=c,scriptBefore=before,idle=idle,action=action,kind=kind,first=first,native=native))
def main():
 for sourceScript,blocked,idle,action,flags in itertools.product([-1,0,1],[False,True],[False,True],[False,True],[0,4,0x25]):run(sourceScript,blocked,idle,action,flags)
 for sourceScript,blocked,idle,first in itertools.product([-1,0,1],[False,True],[False,True],[False,True]):run(sourceScript,blocked,idle,True,0x25,'tag',first)
 report=dict(binarySha256=n.sha256,checks=checks,mismatches=len(errors),examples=errors[:8],method='Actual SetTaggable/candidate/ordinary-transfer/script-reset/514640 binder/linked-list state/action helpers run unchanged. Only platform feedback698900 is substituted. Existing ScriptMachine.Bind is reused by a composition bridge, with no new mapped function credit.',limits=['Resolved valid script/state/action records; source loading and opaque condition/animation callback state remain outside this bounded existing binder projection.','Mode1 takeover/release is excluded. Generated managed replay is compile-only.'])
 (BASE/'reports/gameplay-transfer-script-bridge-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-transfer-script-bridge-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
