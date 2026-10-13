import importlib.util,json,struct,itertools,copy,gzip,random,math
from pathlib import Path
from fractions import Fraction as F
s=importlib.util.spec_from_file_location('distance',Path(__file__).with_name('native-distance-rounding-verify.py'));d=importlib.util.module_from_spec(s);s.loader.exec_module(d);v=d.v;n=v.n;B=v.B;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
TABLE=D+0x1000;HEADS=D+0x2000;ENTRIES=D+0x3000;NAMES=D+0x4000;EFFECT=D+0x7000;QUERY=D+0x8000;OUT=D+0x9000
SINE=(B/'references/native-animation-sine-table.f32').read_bytes();SINEWORDS=struct.unpack('<32768I',SINE);rows=[];errors=[];groups={};events=[];current={};visited=set()
def crc_table():
 out=[]
 for i in range(256):
  value=i<<24
  for j in range(8):value=((value<<1)^(0x04c11db7 if value&0x80000000 else 0))&0xffffffff
  out.append(value)
 return out
TABLEWORDS=crc_table()
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def flt(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f(f):return flt(bits(f))
def options(o):
 p=dict(name='LegoSingle',names=['other','LegoSingle','LEGOSINGLE','a'*32+'x',None,''],next=[1,2,3,4,5,-1],head=0,heads=True,table=TABLEWORDS,cooldown=0,velocity=[0x3f000000,0,0],position=[0x3f800000,0x80000000,0x7fc12345],mutate=False,id=1,volume=0x3eaaaaab,positionPresent=True);p.update(copy.deepcopy(o));return p
def setup(o):
 current.clear();current.update(o);events.clear();n.write(D,bytes(0x9004));n.pack('<256I',TABLE,*o['table']);n.pack('<256h',HEADS,*([o['head']]*256));n.pack('<I',0x2947d80,TABLE);n.pack('<I',0x292fda0,HEADS if o['heads'] else 0);n.pack('<I',0x2947b74,ENTRIES);n.pack('<I',0x951000,o['cooldown']);n.pack('<I',0x29a9c48,0);n.write(0x29899a0,SINE)
 for i,name in enumerate(o['names']):
  n.pack('<I',ENTRIES+i*0x40,NAMES+i*0x100 if name is not None else 0);n.pack('<h',ENTRIES+i*0x40+0x10,o['next'][i])
  if name is not None:n.write(NAMES+i*0x100,name.encode('ascii')+b'\0')
 if o['name'] is not None:n.write(QUERY,o['name'].encode('ascii')+b'\0')
 n.pack('<3I',EFFECT+0x30,*o['position']);n.pack('<3I',EFFECT+0x80,*o['velocity'])
def observe(mu,address,size,user):
 visited.add(address)
 if address!=0x650f20:return
 sp=mu.reg_read(UC_X86_REG_ESP);a=n.unpack('<4I',sp+4);events.append(dict(id=a[0] if a[0]<0x80000000 else a[0]-0x100000000,position=list(n.unpack('<3I',a[1])) if a[1] else None,volume=a[2],scale=a[3]))
 if current['mutate']:
  n.pack('<I',0x951000,0xbf800000)
  if a[1]:n.pack('<I',a[1]+4,0xdeadbeef)
 mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for start,end in [(0x571ba0,0x571c4c),(0x5bec80,0x5becb0),(0x5c0240,0x5c0261),(0x650430,0x65046f),(0x650dc0,0x650e33),(0x681eb0,0x681ed2),(0x650f20,0x650f20)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=start,end=end)
def hash_name(name,table):
 value=0
 for c in name.split('\0')[0].encode('ascii'):
  if 97<=c<=122:c-=32
  value=((value<<8)^table[c^(value>>24)])&0xffffffff
 return value
def find(o,name):
 if name is None or not o['heads']:return -1
 hash_name(name,o['table']);index=o['head'];name=name.split('\0')[0].upper()[:32]
 while index!=-1:
  candidate=o['names'][index]
  if candidate is not None and candidate.split('\0')[0].upper()[:32]==name:return index
  index=o['next'][index]
 return -1
def length(words):
 x,y,z=map(flt,words);squared=d.store(v.add(v.add(v.mul(y,y),v.mul(x,x)),v.mul(z,z)));return f(math.sqrt(squared))
def model(kind,o,value):
 cooldown=o['cooldown'];position=o['position'].copy();result=None;ev=[]
 if kind=='hash':result=hash_name(o['name'],o['table'])
 elif kind=='find':result=find(o,o['name'])
 elif kind=='sqrt':result=bits(0. if flt(value)<0 else math.sqrt(flt(value)))
 elif kind=='length':result=bits(length(o['velocity']))
 else:
  call=kind=='play';volume=o['volume'];ident=o['id'];present=o['positionPresent'] if kind=='play' else True
  if kind=='callback' and flt(cooldown)<=0:
   speed=length(o['velocity'])
   if speed>0:
    clamped=min(speed,1.);converted=int(v.add(v.mul(v.add(1,-clamped),16384),16384));volume=SINEWORDS[(converted>>1)&32767];ident=find(o,'LegoSingle');call=True
  if call:
   ev.append(dict(id=ident,position=position.copy() if present else None,volume=volume,scale=0x3f800000))
   if o['mutate']:
    cooldown=0xbf800000
    if present:position[1]=0xdeadbeef
   if kind=='callback':cooldown=0x3dcccccd
 return dict(result=result,events=ev,cooldown=cooldown,position=position)
def run(kind,inputs=None,value=0):
 o=options(inputs or {});setup(o);before=n.read(D,0x9000);want=model(kind,o,value);query=QUERY if o['name'] is not None else 0
 if kind in ['sqrt','length']:
  n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(0x5c0240 if kind=='sqrt' else 0x5bec80,[value if kind=='sqrt' else EFFECT+0x80]);n.mu.emu_start(n.STOP,n.STOP+6);result=n.unpack('<I',OUT)[0]
 elif kind in ['hash','find']:
  result=n.call(0x650430 if kind=='hash' else 0x650dc0,[query])
  if kind=='find' and result>=0x80000000:result-=0x100000000
 elif kind=='play':n.call(0x681eb0,[o['id'],EFFECT+0x30 if o['positionPresent'] else 0,o['volume']]);result=None
 else:n.call(0x571ba0,[EFFECT]);result=None
 got=dict(result=result,events=copy.deepcopy(events),cooldown=n.unpack('<I',0x951000)[0],position=list(n.unpack('<3I',EFFECT+0x30)));expected=bytearray(before);struct.pack_into('<3I',expected,EFFECT+0x30-D,*want['position']);bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x9000)!=bytes(expected):bad.append('Complete input region differs')
 if bad:errors.append(dict(kind=kind,options=o,value=value,bad=bad))
 rows.append(dict(kind=kind,options=o,value=value,native=got));groups[kind]=groups.get(kind,0)+1

def main():
 rng=random.Random(0x571ba0)
 names=['','LegoSingle','legosingle','LEGOSINGLE','other','missing','a'*32+'x','a'*32+'y','a'*31,'LegoSingle\0ignored']+[''.join(chr(rng.randrange(1,128)) for j in range(rng.randrange(1,65))) for i in range(256)]
 for name in names:
  run('hash',dict(name=name))
  for head in [-1,0,1,3,4,5]:run('find',dict(name=name,head=head))
 for head,heads in itertools.product([-1,0,1,3],[False,True]):run('find',dict(name=None,head=head,heads=heads))
 for i in range(128):run('hash',dict(name=names[i%len(names)],table=[rng.getrandbits(32) for j in range(256)]))
 for sign,exponent,mantissa in itertools.product([0,0x80000000],[0,1,2,8,32,64,96,126,127,128,160,200,253,254],[0,1,0x3fffff,0x400000,0x7ffffe,0x7fffff]):run('sqrt',value=sign|(exponent<<23)|mantissa)
 for i in range(1024):run('sqrt',value=rng.randrange(0x7f800000))
 vectors=[[0,0,0],[0x80000000,0x80000000,0x80000000],[bits(1),bits(2**-12),bits(2**-27)],[bits(1e19)]*3]
 for exp in range(-149,64):vectors.append([bits(2.**exp),0,0])
 for exp in range(-75,1):
  base=bits(2.**exp)
  for offset in [-1,0,1]:vectors.append([base+offset,bits(2.**(exp-8)),0])
 for i in range(1024):vectors.append([bits(math.ldexp(rng.uniform(-1.9,1.9),rng.randrange(-75,60))) for j in range(3)])
 for vector in vectors:run('length',dict(velocity=vector))
 for vector in vectors[:500]:
  for mutate in [False,True]:run('callback',dict(velocity=vector,mutate=mutate))
 for cooldown,heads,head,vector,mutate in itertools.product([0,0x80000000,0xbf800000,0x3dcccccd,0x7f800000,0xff800000,0x7fc12345,0x7fa12345],[False,True],[-1,0,2],[[0,0,0],[bits(.25),0,0],[bits(1.5),bits(.2),0]],[False,True]):run('callback',dict(cooldown=cooldown,heads=heads,head=head,velocity=vector,mutate=mutate))
 for ident,present,volume,mutate in itertools.product([-1,0,1,0x7fffffff],[False,True],[0,0x80000000,0x3f800000,0x3f7fffff,0xbf800000],[False,True]):run('play',dict(id=ident,positionPresent=present,volume=volume,mutate=mutate))
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),visitedInstructions=len(visited),examples=errors[:4],method='Original571ba0,5bec80,5c0240,650430,650dc0,681eb0 run with actual CRT sqrt and x87-to-integer helper. Original sound hashing and32-byte comparator run against prepared signed-short chains. Only final650f20 playback is a mutable service. Exact returns, volume/scale/position calls, cooldown and complete36KiB data image compare.',limits=['Finite float32 root operands; vector inputs and rounded sum of squares finite. Mathematical sqrt uses the supplied scalar CRT path with masked exceptions. Numeric helper6e6b90 executes original fallback mode0 and is not separately mapped by this batch.','ASCII names and valid finite acyclic sound chains. The256-word hash table and sound database are supplied runtime records; table construction, sound-bank loading and playback650f20 internals remain external.','Original32768-entry sine table is supplied from the preserved native reference. Callback clamps speed to1, computes x87((1-speed)*16384+16384), truncates before shifting and masks to15bits; tiny positive speeds test values lost by binary64 rounding.','Callback captures volume before lookup, always forwards the found index including-1 with scale1, and resets cooldown to exactfloat0.1 after playback. Playback may mutate position or cooldown. No sound device/game/managed execution.'])
 (B/'reports/native-build-sound-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-build-sound-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
