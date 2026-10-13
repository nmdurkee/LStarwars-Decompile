import importlib.util,json,struct,gzip,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('base',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.x.NativeX86();B=b.B;D=b.D;b.REGIONS=[(0x2972000,0x4000),(D,0x8000)]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
SOURCE=D+0x1000;BUFFER=D+0x2000;ALLOC=D+0x3000;TABLE=D+0x4000;COM=D+0x4100;ALT=D+0x4200;SIGNAL=D+0xf000;METHOD=D+0xf010;ALTMETHOD=D+0xf020
TARGETS={0x4eef40:('allocate',3,0),SIGNAL:('signal',1,4),METHOD:('device',1,4),ALTMETHOD:('device',1,4),0x698cc0:('voices',0,0)}
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def setup(p):
 m=b.Image(p['seed']);m.put(0x2972bf0,p['prior']);m.put(0x2972bf4,BUFFER if p['buffer'] else 0);m.put(0x2972be8,p['source']);m.put(0x2972c24,0xabc123 if p['event'] else 0);m.put(0x2972c34,COM if p['device'] else 0);m.put(COM,TABLE);m.put(ALT,TABLE+0x100);m.put(TABLE+0x44,METHOD);m.put(TABLE+0x144,ALTMETHOD);return m
def service(m,p,events,kind,args):
 events.append(dict(kind=kind,args=list(args),sha=m.sha()));result=0
 if kind=='allocate':
  m.put(0x2972bf0,999);m.put(0x2972be8,D+0x6000);m.put(D+0x5000,m.get(D+0x5000)^0x1234);result=0 if p['nullAllocation'] else ALLOC
 elif kind=='signal':
  if p['redirect']>=0:m.put(0x2972c34,[0,COM,ALT][p['redirect']])
  m.put(0x2972be8,0);m.put(0x2972bf4,0);m.put(D+0x5004,0xabcd)
 elif kind=='device':m.put(0x2972c34,0);m.put(D+0x5008,args[1])
 elif kind=='voices':m.put(D+0x500c,args[0])
 return result
def model(m,p):
 events=[]
 if p['kind']!='commit':
  if m.get(0x2972bf0)!=p['count']:
   size=p['count']*2;buf=service(m,p,events,'allocate',[size,0x76ef4c,0x8c4]);m.put(0x2972bf4,buf)
   if size:m.write(buf,bytes(size))
  m.put(0x2972bf0,p['count']);m.put(0x2972be8,p['source'])
 if p['kind']!='configure':
  buf=m.get(0x2972bf4)
  if buf:
   source=m.get(0x2972be8);count=m.get(0x2972bf0)
   if source and count:m.write(buf,m.read(source,count*2))
   handle=m.get(0x2972c24)
   if handle:service(m,p,events,'signal',[handle])
   obj=m.get(0x2972c34)
   if obj:service(m,p,events,'device',[m.get(m.get(obj)+0x44),obj])
   service(m,p,events,'voices',[0x2972c48])
 return events
current=None;events=[];visited=set();noops=0
def observe(mu,a,z,u):
 global noops
 if 0x698710<=a<0x698774 or 0x698e70<=a<0x698ec6:visited.add(a)
 if a==0x696a90:noops+=1
 if a not in TARGETS:return
 sp=mu.reg_read(UC_X86_REG_ESP);kind,count,pop=TARGETS[a];args=list(n.unpack('<'+str(count)+'I',sp+4)) if count else []
 if kind=='device':args=[a]+args
 if kind=='voices':args=[mu.reg_read(UC_X86_REG_ECX)]
 m=capture();result=service(m,current,events,kind,args);load(m);mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4+pop)
for lo,hi in [(0x698710,0x698773),(0x698e70,0x698ec5),(0x696a90,0x696a90)]+[(a,a) for a in TARGETS]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=lo,end=hi)
n.write(0x7510b0,struct.pack('<I',SIGNAL))
def main():
 global current,events
 rows=[];errors=[];rng=random.Random(0x698710);cases=[]
 for kind,count,buffer,source,event,device in itertools.product(['configure','commit','both'],[0,1,2,31,100,256],[False,True],[0,SOURCE,BUFFER],[False,True],[False,True]):
  for same in [False,True]:
   prior=count if same or kind=='commit' else count+1
   cases.append(dict(kind=kind,count=count,prior=prior,buffer=buffer,source=source,event=event,device=device,redirect=rng.choice([-1,0,1,2]),nullAllocation=count==0 and bool(rng.randrange(2)),seed=rng.randrange(256)))
 for i,p in enumerate(cases):
  current=p;events=[];m=setup(p);load(m);expected=model(m,p)
  if p['kind']!='commit':n.call(0x698710,[p['source'],p['count']])
  if p['kind']!='configure':n.call(0x698e70,[])
  actual=capture();bad=[]
  if events!=expected:bad.append(dict(events=events,want=expected))
  if actual.sha()!=m.sha():bad.append(dict(differences=[hex(a+j) for a,v in m.r.items() for j,x in enumerate(v) if actual.r[a][j]!=x][:20]))
  if bad:errors.append(dict(index=i,input=p,bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),events=events))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),visitedInstructions=len(visited),noopCalls=noops,bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:2],method='Original698710/698e70 and actual memset/memcpy/no-op696a90 execute. Allocation, SetEvent, COM slot44 and voice update are mutable services; all image bytes and ordered service entry hashes compare.',limits=['Nonnegative word counts0..256, adequate disjoint or exactly aliased source/buffer regions, successful allocation for nonzero size; undefined invalid capacities and partial-overlap memcpy excluded.','Equal-count configuration preserves existing or null buffer. Changed count calls the original empty retirement routine, allocates and zeros. Caller-owned arguments override allocator mutations to globals.','Commit copies before event/COM, rereads COM after event mutation and unconditionally updates fixed voice receiver2972c48 after a nonnull initial buffer. Hardware behavior and voice-update internals remain services. Managed replay pending.'])
 (B/'reports/native-sound-mask-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-mask-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
