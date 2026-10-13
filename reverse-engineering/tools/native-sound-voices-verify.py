import importlib.util,json,struct,gzip,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('base',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.x.NativeX86();B=b.B;D=b.D;b.REGIONS=[(0x810dc0,4),(0x2972000,0x10000),(D,0x10000)]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
OWNER=D+0x1000;TABLE=D+0x3000;OBJECTS=D+0x4000;AUX=D+0x7000;ALTS=D+0x8000;CLOCK=D+0xf000
SLOTS={8:'release',0x18:'volume',0x24:'status',0x3c:'set',0x48:'stop'};TARGETS={D+0xf100+k:(v,2 if v in ['volume','status','set'] else 1) for k,v in SLOTS.items()};TARGETS[CLOCK]=('clock',0)
def u(v):return v&0xffffffff
def i(v):return b.signed(u(v))
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def setup(p):
 m=b.Image(p['seed']);m.put(0x810dc0,p['master']);m.put(0x297dbfc,p['delta']);m.put(OWNER+0xd10,p['live'])
 for slot in SLOTS:m.put(TABLE+slot,D+0xf100+slot)
 for index,r in enumerate(p['voices']):
  record=OWNER+12+index*52;obj=OBJECTS+index*64;alt=ALTS+index*64;aux=AUX+index*16
  m.put(record,obj if r[0] else 0);m.put(record+4,aux if r[1] else 0);m.put(record+0x14,r[2]);m.put(record+0x28,r[3]);m.put(record+0x2c,r[4])
  for target in [obj,alt]:m.put(target,TABLE);m.put(target+4,index);m.put(target+8,r[5]);m.put(target+12,r[6])
  m.put(aux,TABLE);m.put(aux+4,index+128)
 return m
def service(m,p,events,kind,args):
 events.append(dict(kind=kind,args=list(args),sha=m.sha()));result=0
 if kind=='clock':
  if p['mutate']:m.put(0x2972c1c,3);m.put(0x2972c20,5)
  return p['time']
 obj=args[1];index=m.get(obj+4);record=OWNER+12+(index%128)*52;alt=ALTS+(index%128)*64
 if kind=='status':
  result=m.get(obj+8)
  if p['mutate']:
   if index<32 and index%5==0:m.put(record,0)
   elif index%5==1:m.put(record,alt)
   elif index>=32 and index%5==2:m.put(record+0x14,1);m.put(record+0x2c,0xffffffff);m.put(record+0x28,u(m.get(0x2972c18)+2))
 elif kind=='volume':
  result=m.get(obj+12)
  if p['mutate']:m.put(0x297dbfc,p['changedDelta']);m.put(record,alt)
 elif kind=='set':m.put(obj+12,args[2])
 elif kind=='stop':
  m.put(obj+0x10,m.get(obj+0x10)^0x1234)
  if p['mutate']:m.put(record,alt)
 elif kind=='release':
  m.put(obj+0x14,m.get(obj+0x14)^0x5678)
  if p['mutate'] and index>=128:m.put(record,alt)
 return result

def model(m,p):
 events=[]
 def invoke(kind,obj,value=None):
  slot=next(k for k,v in SLOTS.items() if v==kind);args=[m.get(m.get(obj)+slot),obj]
  if value is not None:args.append(u(value))
  return service(m,p,events,kind,args)
 def retire(index):
  record=OWNER+12+index*52
  if m.get(record):
   aux=m.get(record+4)
   if aux:invoke('release',aux)
   invoke('stop',m.get(record));invoke('release',m.get(record));m.put(record,0);m.put(record+4,0);m.put(OWNER+0xd10,m.get(OWNER+0xd10)-1)
  m.write(record,bytes(52))
 def setvolume(obj,value):invoke('set',obj,max(-10000,min(0,i(value+m.get(0x810dc0)))))
 if p['kind']=='retire':retire(p['index'])
 elif p['kind']=='set':setvolume(OBJECTS+p['index']*64,p['value'])
 else:
  m.put(0x2972c1c,0);m.put(0x2972c20,0);m.put(0x2972c18,service(m,p,events,'clock',[])&0x7fffffff)
  for index in range(32,64):
   record=OWNER+12+index*52;obj=m.get(record)
   if not obj:continue
   m.put(0x2972c1c,m.get(0x2972c1c)+1);status=invoke('status',obj)
   if not m.get(record+0x14) or not status&4:continue
   elapsed=i(m.get(0x2972c18)-m.get(record+0x28))
   if elapsed<0:elapsed=i(elapsed-0x80000000)
   expired=elapsed>i(m.get(record+0x2c));m.write(record+0x19,bytes([expired]))
   if expired:
    volume=i(invoke('volume',m.get(record)));change=int(fl(m.get(0x297dbfc))*-3500.0);volume=i(volume+change)
    if volume< -7000:retire(index)
    else:setvolume(m.get(record),volume)
   m.write(record+0x18,b'\0')
  for index in range(32):
   record=OWNER+12+index*52;obj=m.get(record)
   if not obj:continue
   m.put(0x2972c20,m.get(0x2972c20)+1);status=invoke('status',obj)
   if not status&1:retire(index)
 return events
current=None;events=[];visited=set()
def observe(mu,a,z,user):
 if 0x698cc0<=a<0x698e10 or 0x697690<=a<0x6976f2 or 0x696b40<=a<0x696b70:visited.add(a)
 if a not in TARGETS:return
 sp=mu.reg_read(UC_X86_REG_ESP);kind,count=TARGETS[a];raw=list(n.unpack('<'+str(count)+'I',sp+4)) if count else [];args=[] if kind=='clock' else [a,raw[0]]
 if kind=='set':args.append(raw[1])
 m=capture();result=service(m,current,events,kind,args);load(m)
 if kind in ['status','volume']:n.pack('<I',raw[1],result)
 mu.reg_write(UC_X86_REG_EAX,result if kind=='clock' else 0);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4+count*4)
for lo,hi in [(0x698cc0,0x698e0f),(0x697690,0x6976f1),(0x696b40,0x696b6f)]+[(a,a) for a in TARGETS]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=lo,end=hi)
n.pack('<I',0x75129c,CLOCK)
def main():
 global current,events
 rng=random.Random(0x698cc0);cases=[];rows=[];errors=[];deltas=[bits(v) for v in [0,-0.0,0.016666667,-0.016666667,1,-1,2,0.0001,613566,-613566]]
 for kind in ['update','retire','set']:
  for k in range(384 if kind=='update' else 256):
   now=rng.choice([0,1,2,0x7ffffffe,0x7fffffff,0x80000000,0xffffffff,rng.getrandbits(32)]);voices=[]
   for index in range(64):
    present=bool(rng.randrange(4)) if k%8 else k%16!=0
    voices.append([present,bool(rng.randrange(2)),rng.choice([0,1,0xffffffff]),rng.choice([0,now&0x7fffffff,u((now&0x7fffffff)-1),u((now&0x7fffffff)+1),rng.getrandbits(32)]),rng.choice([0,1,2,0x7fffffff,0x80000000,0xffffffff,rng.randrange(1000)]),rng.randrange(8),u(rng.choice([-10000,-7001,-7000,-6999,-1,0,1,0x7fffffff,-0x80000000]))])
   cases.append(dict(kind=kind,index=k%64,value=u(rng.choice([-10001,-10000,-9999,-7000,-1,0,1,0x7fffffff,-0x80000000,rng.getrandbits(32)])),master=u(rng.choice([-10000,-1,0,1,10000,0x7fffffff,-0x80000000])),time=now,delta=rng.choice(deltas),changedDelta=rng.choice(deltas),live=rng.choice([0,1,64,0xffffffff]),mutate=bool(k%2),seed=rng.randrange(256),voices=voices))
 for idx,p in enumerate(cases):
  current=p;events=[];m=setup(p);load(m);expected=model(m,p)
  if p['kind']=='update':n.call(0x698cc0,[],regs={UC_X86_REG_ECX:OWNER})
  elif p['kind']=='retire':n.call(0x697690,[p['index']],regs={UC_X86_REG_ECX:OWNER})
  else:n.call(0x696b40,[OBJECTS+p['index']*64,p['value']])
  actual=capture();bad=[]
  if events!=expected:bad.append(dict(events=events,want=expected))
  if actual.sha()!=m.sha():bad.append(dict(differences=[hex(a+j) for a,v in m.r.items() for j,x in enumerate(v) if actual.r[a][j]!=x][:20]))
  if bad:errors.append(dict(index=idx,input=p,bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),events=events))
  if idx%128==0:print(json.dumps(dict(case=idx,mismatches=len(errors))),flush=True)
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:1],method='Original698cc0 with actual697690 retirement,696b40 volume clamp, native x87/CRT conversion and memset. Only time and COM device methods are services. Complete prepared memory and raw ordered device observations compare.',limits=['Loaded64-slot voice storage, valid COM backing and callback mutations that preserve any pointer subsequently dereferenced. Status and volume outputs always initialized by service.','Finite float32 delta multiplied by exact-3500; product fits signed32. Wrapping32-bit elapsed, volume/master addition, decrement and counters preserved.','No hardware playback or COM ownership implementation; external timer/device calls remain mutable host services. Managed replay pending.'])
 (B/'reports/native-sound-voices-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-voices-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
