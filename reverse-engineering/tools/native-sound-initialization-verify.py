import importlib.util,json,struct,gzip,hashlib,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86();B=x.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
REGIONS=[(0x810368,0x108),(0x2920000,0x11000),(0x2947000,0x1c000),(D,0x80000)]
CURSOR=D+0x1000;BUILTIN=D+0x4000;NAMES=D+0x8000;PATH=D+0x9000
class Image:
 def __init__(self,seed):self.r={a:bytearray(bytes(((i*7+seed)&255 for i in range(256)))*(size//256)+bytes(((i*7+seed)&255 for i in range(size%256)))) for a,size in REGIONS}
 def at(self,a):
  for p,b in self.r.items():
   if p<=a<p+len(b):return b,a-p
  raise ValueError(hex(a))
 def read(self,a,k):b,o=self.at(a);return bytes(b[o:o+k])
 def write(self,a,data):b,o=self.at(a);b[o:o+len(data)]=data
 def get(self,a):return struct.unpack('<I',self.read(a,4))[0]
 def put(self,a,v):self.write(a,struct.pack('<I',v&0xffffffff))
 def text(self,a,s):self.write(a,s.encode('ascii')+b'\0')
 def stringcopy(self,to,src):
  while True:
   v=self.read(src,1);self.write(to,v);to+=1;src+=1
   if v==b'\0':break
 def sha(self):return hashlib.sha256(b''.join(self.r.values())).hexdigest()
def signed(v):return v if v<0x80000000 else v-0x100000000
def setup(p):
 m=Image(p['seed']);m.put(CURSOR,D+0x10000+p['alignment']);m.put(0x2962044,p['initialized']);m.put(0x2947d80,D+0x2000);m.put(0x2962028,BUILTIN);m.put(0x296202c,p['builtinCount']);m.put(0x2962018,p['nameCount']);m.text(PATH,p['path'])
 for i in range(max(0,p['builtinCount'])):
  for j in range(7):m.put(BUILTIN+i*28+j*4,(p['seed']*0x10001+i*97+j*131)&0xffffffff)
  m.put(BUILTIN+i*28,NAMES+i*64);m.text(NAMES+i*64,p['names'][i])
 return m
def service(m,p):
 m.put(CURSOR,m.get(CURSOR)+p['advance']);m.put(0x2962014,m.get(0x2962014)+2);m.put(0x2962018,m.get(0x2962018)+3);m.put(0x296201c,p['soundCount']);m.write(0x2921760,b'\xff'*200);m.write(0x2947ca8,b'\xee'*200)
 if p['redirect']:m.put(0x2947b74,D+0x50000)
 records=m.get(0x2947b74)
 for i,f in enumerate(p['flags']):m.put(records+i*64+4,f)
 m.put(D+0x70000,0xcafebabe)
def model(m,p):
 def reserve(size):a=(m.get(CURSOR)+3)&0xfffffffc;m.put(CURSOR,a+size);return a
 m.put(0x292fda0,reserve(0x200))
 for a,k in [(0x2947d70,0xaf00),(0x2947b74,0x19000),(0x292fda4,0x19000)]:m.put(a,reserve(k));m.write(m.get(a),bytes(k))
 if not m.get(0x2962044):
  a=reserve(1024);m.put(0x2947d80,a)
  for i in range(256):
   v=i<<24
   for j in range(8):v=((v<<1)^(0x04c11db7 if v&0x80000000 else 0))&0xffffffff
   m.put(a+i*4,v)
  m.put(0x2962044,1)
 m.write(m.get(0x292fda0),b'\xff'*512);m.put(0x2962014,0);m.put(0x296201c,0);index=0
 while index<signed(m.get(0x296202c)):
  off=index*28;to=m.get(0x2947d70)+off;src=m.get(0x2962028)+off
  for j in range(7):m.put(to+j*4,m.get(src+j*4))
  m.put(to+12,index);name=0x2948f10+index*64;m.stringcopy(name,m.get(to));m.put(0x2962014,m.get(0x2962014)+1);m.put(0x2962018,m.get(0x2962018)+1);m.put(to,name);index+=1
 to=m.get(0x2947d70)+index*28
 for j,v in enumerate([0,0,0,0xffffffff]):m.put(to+j*4,v)
 m.stringcopy(0x810368,PATH);entry=m.sha();service(m,p);m.write(0x2947ca8,bytes(200));count=signed(m.get(0x296201c));records=m.get(0x2947b74)
 for i in range(max(0,count)):
  flags=m.get(records+i*64+4)
  if flags&0x20000:
   idx=signed((flags<<17)&0xffffffff)>>17;a=0x2947ca8+(idx>>4)*2;v=struct.unpack('<H',m.read(a,2))[0]|(1<<(idx&15));m.write(a,struct.pack('<H',v))
 m.write(0x2921760,m.read(0x2947ca8,200));return entry
current=None;events=[];visited=set()
def observe(mu,address,size,user):
 if 0x6521b0<=address<0x6523f7:visited.add(address)
 if address!=0x6520b0:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=n.unpack('<3I',sp+4);m=Image(0)
 for a,size in REGIONS:m.r[a]=bytearray(n.read(a,size))
 events.append(dict(args=list(args),sha=m.sha()));service(m,current)
 for a,data in m.r.items():n.write(a,data)
 mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x6521b0,end=0x6523f6);n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x6520b0,end=0x6520b0)
def main():
 global current,events
 rows=[];errors=[];rng=random.Random(0x6521b0)
 cases=[]
 for alignment,initialized,builtins in itertools.product(range(8),[0,1,-1,-2147483648],[-1,0,1,3]):
  count=rng.choice([-1,0,1,16,64]);flags=[rng.randrange(1600)|(rng.randrange(2)*0x20000)|(rng.getrandbits(12)<<20) for _ in range(max(0,count))]
  cases.append(dict(seed=rng.randrange(256),alignment=alignment,initialized=initialized,builtinCount=builtins,nameCount=rng.choice([0,0x7fffffff,0xfffffffe]),names=['Bank_'+str(i)+'x'*rng.randrange(50) for i in range(max(0,builtins))],path=rng.choice(['','AUDIO\\SOUNDS.TXT','x'*255]),advance=rng.randrange(32),soundCount=count,flags=flags,redirect=bool(rng.randrange(2))))
 for id in range(1600):
  if id%16 not in [0,15] and id not in [1,1598]:continue
  cases.append(dict(seed=id%256,alignment=id%16,initialized=0,builtinCount=1,nameCount=7,names=['z'*63],path='Audio',advance=0,soundCount=3,flags=[0x20000|id,0x20000|id,id],redirect=True))
 for index,p in enumerate(cases):
  current=p;events=[];m=setup(p)
  for a,data in m.r.items():n.write(a,data)
  entry=model(m,p);n.call(0x6521b0,[CURSOR,0xaabbccdd,PATH],count=1000000);got=hashlib.sha256(b''.join(n.read(a,size) for a,size in REGIONS)).hexdigest();wanted=m.sha();bad=[]
  if events!=[dict(args=[PATH,CURSOR,0xaabbccdd],sha=entry)]:bad.append('service-entry')
  if got!=wanted:
   bad.append('whole-image');diff=[]
   for a,data in m.r.items():
    actual=n.read(a,len(data));diff.extend(hex(a+i) for i,(x,y) in enumerate(zip(actual,data)) if x!=y)
   bad.append(diff[:12])
  if bad:errors.append(dict(index,bad=bad))
  rows.append(dict(input=p,entrySha=entry,finalSha=got))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),originalEntryCalls=len(rows),visitedInstructions=len(visited),bytesComparedPerCase=sum(s for a,s in REGIONS),examples=errors[:4],method='Original6521b0 and650280/CRT zero/copy/string functions execute unchanged;6520b0 configuration/bank loading is the only mutable service. Whole declared memory regions compare byte-for-byte, with exact SHA256 and argument sequence at service entry and after completion.',limits=['Valid disjoint arena/cursor/builtin records/globals and terminated ASCII bank/path strings. Name slots64bytes, path capacity264bytes, enabled sound IDs0..1599. Invalid capacity/pointers/negative mask index excluded.','The load service may redirect sound records, change counts/cursor/name count and both masks; final scan rereads the current sound pointer and count. Existing nonzero CRC initialized flag preserves its table.','Raw virtual32-bit addresses index owned byte arrays only. No native pointer or external process access. Configuration parsing, bank loading and audio hardware remain external. Managed replay pending.'])
 (B/'reports/native-sound-initialization-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-initialization-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
