"""Original tolower/isdigit wrappers, raw unsigned wrapping table index and locale forwarding."""
import importlib.util,json,random,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
D=n.DATA;TABLE=D+0x800;ARGS=n.STACK+0xe004;shadow={};segments=[];events=[];config={};cases=[];errors=[];checks=0;rng=random.Random(170)
U=lambda v:v&0xffffffff
def rd(p,z=4):return sum(shadow[p+i]<<(i*8)for i in range(z))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255

def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def port(address,args,model):
 events.append(dict(callback=address,args=list(args)));write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(z*8))-1)).to_bytes(z,'little'))
 for p,z,v in config.get('patches',[]):write(p,v,z)
 return config.get('childReturn',0xfedcba98)
def hook(mu,address,size,data):
 if address not in[0x70138e,0x700f21]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<2I',sp+4));ret=n.unpack('<I',sp)[0];value=port(address,args,False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def execute(c):
 global config,shadow,segments,events,checks
 config=c;method=c['method'];word=U(c['character']);n.write(D,bytes(rng.randrange(256)for i in range(0x2000)));n.pack('<I',0x297cb10,c.get('mode',0));n.pack('<I',0x82a668,c.get('table',TABLE));n.pack('<I',ARGS,word);segments=[(D,0x2000),(0x297cb10,4),(0x82a668,4),(ARGS,4)];target=U(c.get('table',TABLE)+word*2)
 if method=='Digit'and not c.get('mode',0)and not D<=target<D+0x2000:
  try:n.read(target,1);segments.append((target,1))
  except Exception:pass
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];mf=False;want=0
 try:
  if rd(0x297cb10):want=port(0x70138e if method=='Lower'else 0x700f21,[word,0],True)
  elif method=='Lower':want=U(word+32)if U(word-65)<=25 else word
  else:want=rd(U(rd(0x82a668)+word*2),1)&4
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(0x7014a5 if method=='Lower'else 0x700f70,[word])
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else'images',model=b if group!='images'else'images'))
 cases.append(dict(context=c,inputs=dict(method=method,character=word),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for method,word,mode in itertools.product(['Lower','Digit'],range(256),[0,1]):execute(dict(method=method,character=word,mode=mode))
for method,word,mode in itertools.product(['Lower','Digit'],[-1025,-1024,-256,-129,-128,-1,256,511,512,1024,65535,0x10000000,0x7fffffff,0x80000000,0xffffffff,0xdeadbeef],[0,1,0xffffffff]):execute(dict(method=method,character=word,mode=mode))
for i in range(384):execute(dict(method='Lower'if i&1 else'Digit',character=rng.getrandbits(32),mode=rng.randrange(2),childReturn=rng.getrandbits(32)))
for method,result in itertools.product(['Lower','Digit'],[0,1,4,0x80000000,0xffffffff]):execute(dict(method=method,character=65,mode=1,childReturn=result,patches=[[0x297cb10,4,0],[ARGS,4,90]]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['70138E locale lower','700F21 locale digit'])
(nm.BASE/'reports/script-phase170-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase170-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
