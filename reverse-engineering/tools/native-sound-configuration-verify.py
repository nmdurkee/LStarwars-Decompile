import importlib.util,json,struct,gzip,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('base',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.x.NativeX86();B=b.B;D=b.D;b.REGIONS=[(0x2920000,0x44000),(D,0x10000)]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
PARSER=D+0x1000;TOKEN=D+0x2000;BANKS=D+0x4000;ALT=D+0x8000;PATH=D+0x3000;CURSOR=D+0x3100
TARGETS={0x4fc860:('open',1),0x4f10e0:('configure',2),0x4fc5b0:('line',1),0x4f7fb0:('token',1),0x4fa020:('dispatch',1),0x4fa300:('close',1),0x697a50:('banks',3),0x698710:('mask',2),0x698e70:('finish',0)}
def setup(p):
 m=b.Image(p['seed']);m.put(0x2947d70,BANKS);m.put(0x2962014,p['count']);m.put(0x2962034,p['flag']);m.put(PARSER+0x510,TOKEN);m.text(TOKEN,'prior');m.text(PATH,p['path']);m.put(CURSOR,D+0xa000);return m
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def service(m,p,state,kind,args):
 state['events'].append(dict(kind=kind,args=list(args),sha=m.sha()));result=0
 if kind=='open':result=PARSER if p['open'] else 0
 elif kind=='configure':m.put(PARSER+0x20,args[1])
 elif kind=='line':state['line']+=1;result=p['lineResult'] if state['line']<len(p['lines']) else 0
 elif kind=='token':m.text(TOKEN,p['lines'][state['line']]);m.put(PARSER+0x510,TOKEN);result=p['tokenResult']
 elif kind=='dispatch':m.put(0x2962014,m.get(0x2962014)+1);m.put(D+0x3200,m.get(D+0x3200)+1)
 elif kind=='close':
  m.put(0x2962014,m.get(0x2962014)+p['closeAdd'])
  if p['redirect']:m.put(0x2947d70,ALT)
 elif kind=='banks':m.write(0x2921760,b'\xee'*200);m.put(0x2962034,p['afterFlag']);m.put(CURSOR,m.get(CURSOR)+p['advance'])
 elif kind=='mask':m.write(0x2921760,bytes((i*3+p['seed'])&255 for i in range(200)))
 elif kind=='finish':m.put(D+0x3300,0x12345678)
 return result
def model(m,p):
 state=dict(line=-1,events=[])
 def call(k,args=[]):return service(m,p,state,k,args)
 parser=call('open',[PATH])
 if parser:
  call('configure',[parser,0x810470])
  while call('line',[parser]):
   call('token',[parser])
   if m.read(m.get(parser+0x510),1)!=b'\0':call('dispatch',[parser])
  call('close',[parser])
 offset=m.get(0x2962014)*28
 for j,v in enumerate([0,0,0,0xffffffff]):m.put(m.get(0x2947d70)+offset+j*4,v)
 call('banks',[m.get(0x2947d70),CURSOR,0xaabbccdd]);m.write(0x2921760,bytes(200))
 if m.get(0x2962034)==0:call('mask',[0x2921760,100])
 call('finish');return state['events']
current=None;state=None;visited=set()
def observe(mu,a,z,u):
 if 0x6520b0<=a<0x6521a5:visited.add(a)
 if a not in TARGETS:return
 sp=mu.reg_read(UC_X86_REG_ESP);kind,count=TARGETS[a];args=n.unpack('<'+str(count)+'I',sp+4) if count else [];m=capture();result=service(m,current,state,kind,args);load(m);mu.reg_write(UC_X86_REG_EAX,result&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x6520b0,end=0x6521a4)
for a in TARGETS:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def main():
 global current,state
 rows=[];errors=[];rng=random.Random(0x6520b0);cases=[]
 for opened,lines,flag,after,redirect,tokenResult in itertools.product([False,True],[[],[''],['Sample'],['','Sample','','Group','Unknown','']], [0,1,0xffffffff],[0,1,0xffffffff],[False,True],[0,1]):
  cases.append(dict(open=opened,lines=lines,flag=flag,afterFlag=after,redirect=redirect,tokenResult=tokenResult,lineResult=rng.choice([1,2,0xffffffff]),count=rng.choice([0,1,7,31]),closeAdd=rng.choice([0,3]),advance=rng.randrange(32),seed=rng.randrange(256),path=rng.choice(['','AUDIO/AUDIO.CFG','x'*255])))
 for index,p in enumerate(cases):
  current=p;state=dict(line=-1,events=[]);m=setup(p);load(m);expected=model(m,p);n.call(0x6520b0,[PATH,CURSOR,0xaabbccdd],count=1000000);actual=capture();bad=[]
  if state['events']!=expected:bad.append(dict(events=state['events'],want=expected))
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(hex(a+i) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:20]))
  if bad:errors.append(dict(index,input=p,bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),events=state['events']))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:2],method='Original6520b0 including actual memset executes. File/scanner/dispatch/close and bank/device services expose raw argument order and complete entry-image hashes; mutable count, bank base, mask and post-load flag changes are exercised.',limits=['This recovers configuration orchestration, not the native file scanner, dispatcher, bank loader or audio device. Valid parser/token/bank backing, adequate capacity and terminating service sequence are required.','The token-reader return value is ignored; dispatch tests current token first byte. Missing file still proceeds through bank terminator, load, zero mask, optional mask application and finish.','Bank terminator touches only its first16bytes. Post-load flag is reread after clearing200mask bytes. Services are synchronous and may mutate shared state. Managed replay pending.'])
 (B/'reports/native-sound-configuration-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-configuration-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
