"""Pod free-slot selector and masked-x87 float copier with overlaps/partial faults."""
import importlib.util,struct,json,gzip,itertools,base64,random
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX
n=m.NativeX86();D=n.DATA;RACE=D+0x1000;SIZE=0x10000;n.mu.mem_unmap(D+SIZE,0x1000);vectors=[];errors=[];groups={};r=random.Random(20261020)
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',0x882a6c,0 if c.get('raceNull')else RACE)
 if'words'in c:
  for j,w in enumerate(c['words']):n.pack('<I',RACE+0xa694+j*0xa0,w)
 else:
  for j in range(16):n.pack('<I',RACE+0xa694+j*0xa0,0 if j>=c.get('free',0)and c.get('free',0)>=0 else 0xffffffff)
 for j in range(16):n.pack('<I',D+0x2000+j*4,c.get('bits',[r.getrandbits(32)for v in range(16)])[j])
 n.write(D+SIZE-16,struct.pack('<4I',0x7f800001,0xff800003,0x80000000,0x3f800000));return bytearray(n.read(D,SIZE))
def oracle(k,c,image):
 if k=='pool':
  if c.get('raceNull'):return None,True,False
  for j in range(16):
   if struct.unpack_from('<I',image,RACE-D+0xa694+j*0xa0)[0]==0:return RACE+0xa600+j*0xa0,False,False
  return 0,False,False
 unsupported=False
 for j in range(16):
  si=c['source']-D+j*4;ti=c['target']-D+j*4
  if si<0 or si+4>SIZE:return None,True,unsupported
  w=struct.unpack_from('<I',image,si)[0]
  if w&0x7f800000==0x7f800000 and w&0x7fffff and not w&0x400000:unsupported=True
  if ti<0 or ti+4>SIZE:return None,True,unsupported
  struct.pack_into('<I',image,ti,w)
 return None,False,unsupported

def run(k,c,group):
 before=setup(c);expected=bytearray(before);want,wfault,unsupported=oracle(k,c,expected);fault=False;result=None
 try:
  if k=='pool':result=n.call(0x4d94b0)
  else:n.call(0x4d8280,regs={UC_X86_REG_EAX:c['source'],UC_X86_REG_ECX:c['target']})
 except RuntimeError:fault=True
 after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected or fault!=wfault or(k=='pool'and not fault and result!=want):errors.append(dict(kind=k,input=c,result=[result,want],fault=[fault,wfault],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(kind=k,input=dict(c),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,fault=fault,sourceSupported=not unsupported))
for free in range(-1,16):run('pool',dict(free=free),'each-first-free-slot-and-full')
for j in range(256):
 words=[r.choice([0,1,0xffffffff,0x80000000,r.getrandbits(32)])for v in range(16)];run('pool',dict(words=words),'raw-slot-status-order')
run('pool',dict(raceNull=True),'nullrace-dereference-fault')
patterns=[0,0x80000000,1,0x80000001,0x7f7fffff,0xff7fffff,0x7f800000,0xff800000,0x7f800001,0xff800001,0x7fc00001,0xffc00001,0x7fbfffff,0xffbfffff]+[r.getrandbits(32)for j in range(256)]
for j,offset in itertools.product(range(len(patterns)),[-63,-16,-4,-1,0,1,3,4,16,63,64]):run('copy',dict(source=D+0x2000,target=D+0x2000+offset,bits=[patterns[(j+v)%len(patterns)]for v in range(16)]),'allbit-ordered-unaligned-overlap')
for source,target in[(0,D+0x3000),(D+0x2000,0),(D+SIZE-16,D+0x3000),(D+0x2000,D+SIZE-8),(D+SIZE-16,D+SIZE-12)]:run('copy',dict(source=source,target=target,bits=patterns[:16]),'precise-first-and-partial-copy-fault')
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*sum(v['kind']=='pool'for v in vectors)+2*sum(v['kind']=='copy'for v in vectors),groups=groups,mismatches=len(errors),errors=errors[:20],faultCases=sum(v['fault']for v in vectors),preparedSourceCases=sum(v['sourceSupported']for v in vectors),preparedSourceAssertionGroups=3*sum(v['kind']=='pool'and v['sourceSupported']for v in vectors)+2*sum(v['kind']=='copy'and v['sourceSupported']for v in vectors),signalingNaNProbeCases=sum(not v['sourceSupported']for v in vectors),nativeAdapters=0,limits=['Default masked x87CW037F; floatcopy memory output andfault ordering only, FPUstatus/exception flags excluded.','Emulated signalingNaN payload preservation is probe-only; actualhardware conversion notcertified andportablecontract excludes these rows. qNaN,infinity,signedzero,subnormal sourcewords supported.16 orderedfloatloads/stores; physical pointer/OS backing remains external.','A singleguardpage in isolated emulatorData+65536 isunmapped forpartial nativefaults, matching supplied finiteportableimage boundary. No host/OS changes.','No CreatePod command credit yet; curve andheading/spawn composition remains unrecovered.'])
(m.BASE/'reports/movement-phase19-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase19-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),faultCases=report['faultCases'],errors=errors[:5])))
