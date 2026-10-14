"""Original projectile RNG selectors/offsets including raw shared-state aliases."""
from pathlib import Path
import importlib.util,struct,json,gzip,base64,random,itertools
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);n=m.NativeX86();BASE=0x810000;SIZE=0x10000;RNG=0x8102e8;P=BASE+0x6000;vectors=[];errors=[];counts={}
from unicorn import UC_HOOK_CODE
def hook(mu,a,size,user):
 if a in[0x64a740,0x64a7c0,0x5b9e10,0x5b9d90,0x6e6b90]:counts[hex(a)]=counts.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,hook)
def run(kind,c):
 p=c.get('projectile',P);n.write(BASE,bytes([0xa5])*SIZE);n.pack('<3I',p+0x10c,*c.get('offsetWords',[0x7fffffff,0x80000000,0xffffffff]));n.pack('<3I',p+0x118,*c.get('amplitudeWords',[0x7fffffff,0x80000000,0xffffffff]));n.pack('<I',RNG,c.get('randomState',0x12345678));before=n.read(BASE,SIZE);img=bytearray(before);expected_counts={hex(0x64a740 if kind=='axes'else 0x64a7c0):1}
 def u(p):return struct.unpack_from('<I',img,p-BASE)[0]
 def put(p,v):struct.pack_into('<I',img,p-BASE,v&0xffffffff)
 def step(integer):
  address=0x5b9e10 if integer else 0x5b9d90;expected_counts[hex(address)]=expected_counts.get(hex(address),0)+1;value=(u(RNG)*1664525+1013904223)&0xffffffff;put(RNG,value)
  if not integer:expected_counts['0x6e6b90']=expected_counts.get('0x6e6b90',0)+1
  return value
 if kind=='axes':
  slot=0;guard=0
  while slot<2:
   guard+=1
   if guard>10000:raise ValueError('Nonterminating selector outside prepared domain')
   value=step(True);img[p-BASE+0x142+slot]=(value%65535)//21845+1
   if slot==1 and img[p-BASE+0x143]==img[p-BASE+0x142]:continue
   value=step(False);numerator=(value&0x7fffff)*2-8388608;angle=(abs(numerator)//128)*(-1 if numerator<0 else 1);put(p+0x130+slot*4,angle);slot+=1
 else:
  for j in range(3):
   value=step(False);amplitude=struct.unpack('<i',struct.pack('<I',u(p+0x118+j*4)))[0];product=((value&0x7fffff)*2-8388608)*amplitude;delta=(abs(product)//8388608)*(-1 if product<0 else 1);put(p+0x124+j*4,delta+u(p+0x10c+j*4))
 counts.clear();n.call(0x64a740 if kind=='axes'else 0x64a7c0,[p],count=200000);after=n.read(BASE,SIZE);bad=[]
 if after!=img:bad.append('image')
 if counts!=expected_counts:bad.append('childCounts')
 if bad:errors.append(dict(kind=kind,input=c,bad=bad,diff=[[hex(j),after[j],img[j]]for j in range(SIZE)if after[j]!=img[j]][:12],counts=dict(counts),expectedCounts=expected_counts))
 vectors.append(dict(kind=kind,input=c,projectile=p,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),nativeEntryCounts=dict(counts)))
for state in[0,1,2,0x7fffff,0x800000,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]:
 for kind in['axes','offsets']:run(kind,dict(randomState=state))
for state in range(256):
 for kind in['axes','offsets']:run(kind,dict(randomState=state))
r=random.Random(37)
for j in range(256):
 for kind in['axes','offsets']:run(kind,dict(randomState=r.randrange(2**32),offsetWords=[r.randrange(2**32)for _ in range(3)],amplitudeWords=[r.randrange(2**32)for _ in range(3)]))
for offset,state,kind in itertools.product([0x130,0x134,0x140,0x141,0x142,0x143,0x124,0x128,0x12c,0x10c,0x110,0x114],[0,1,0x12345678,0xffffffff],['axes','offsets']):run(kind,dict(projectile=RNG-offset,randomState=state))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=2*len(vectors),mismatches=len(errors),errors=errors[:8],nativeAdapters=0);(m.BASE/'reports/movement-phase37-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:3])))
if errors:raise SystemExit('Projectile RNG mismatch; no paired fixture')
with gzip.open(m.BASE/'reports/movement-phase37-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(base=BASE,random=RNG,vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);func=[]
for a,b in[(0x64a740,0x64a7bf),(0x64a7c0,0x64a845)]:func.append(dict(address=hex(a),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/movement-phase37-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=func),indent=2)+'\n')
