"""Original canonical prefix table builder, no table/memory/cookie adapters."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
LENGTHS=DATA;LOOKUP=D+0x3000;LEFT=0x2982740;RIGHT=0x2982f40
segments=[(LENGTHS,510),(LOOKUP,8192),(LEFT,4096),(RIGHT,4096)]
def rw(p):return rb(p)|(rb(p+1)<<8)
def ww(p,v):wb(p,v);wb(p+1,v>>8)
def build83(entries,lengths,bits,lookup):
 count=[0]*17;start=[0]*18;weight=[0]*17
 for symbol in range(entries):length=rb(lengths+symbol);assert length<=16;count[length]=(count[length]+1)&65535
 for length in range(1,17):start[length+1]=(start[length]+(count[length]<<(16-length)))&65535
 assert start[17]==0
 shift=16-bits
 for length in range(1,17):
  if length<=bits:start[length]>>=shift;weight[length]=1<<(bits-length)
  else:weight[length]=1<<(16-length)
 tail=start[bits+1]>>shift;size=1<<bits
 if tail and tail!=size:
  for i in range(tail,size):ww(lookup+i*2,0)
 nextNode=entries;branch=1<<((15-bits)&31)
 for symbol in range(entries):
  length=rb(lengths+symbol)
  if not length:continue
  code=start[length];end=code+weight[length]
  if length<=bits:
   for i in range(code,end):ww(lookup+i*2,symbol)
  else:
   pointer=lookup+(code>>shift)*2;depth=length-bits
   while depth:
    node=rw(pointer)
    if not node:ww(LEFT+nextNode*2,0);ww(RIGHT+nextNode*2,0);ww(pointer,nextNode);node=nextNode;nextNode+=1
    pointer=(RIGHT if code&branch else LEFT)+node*2;code=(code+code)&0xffffffff;depth-=1
   ww(pointer,symbol)
  start[length]=end&65535

def execute83(lengths,bits,tag):
 global shadow,checks
 entries=len(lengths);n.write(LENGTHS,bytes(lengths)+bytes(510-entries));n.write(LOOKUP,bytes(8192));n.write(LEFT,bytes([0xa5])*4096);n.write(RIGHT,bytes([0x5a])*4096);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};build83(entries,LENGTHS,bits,LOOKUP);model=snap(True);n.call(0x4f6000,[entries,LENGTHS,bits,LOOKUP],count=12000000);final=snap();checks+=1
 if final!=model:errors.append(dict(tag=tag,bits=bits,lengths=lengths,differences=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(final,model)if x!=y][:1]))
 cases.append(dict(inputs=dict(entries=entries,lengths=LENGTHS,bits=bits,lookup=LOOKUP),context=dict(tag=tag),initial=initial,final=final))
for bits in[8,12]:
 for entries in[0,14,19,510]:execute83([0]*entries,bits,'empty')
 for depth in range(1,9):execute83([depth]*(1<<depth),bits,'uniform')
 #Complete unbalanced chain reaches16 and exercises shared internal nodes.
 execute83(list(range(1,16))+[16,16]+[0]*493,bits,'depth16')
rng=random.Random(0x4f6000)
for i in range(128):
 leaves=[1,1];target=rng.randrange(2,200)
 while len(leaves)<target:
  candidates=[j for j,v in enumerate(leaves)if v<16];j=rng.choice(candidates);depth=leaves.pop(j)+1;leaves.extend([depth,depth])
 entries=rng.choice([max(19,len(leaves)),510]);leaves.extend([0]*(entries-len(leaves)));rng.shuffle(leaves);execute83(leaves,8 if i&1 else 12,'random'+str(i))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=1,ports=[],closure='Whole original4f6000 canonical builder with real memory stores and cookie check; no adapters')
(nm.BASE/'reports/script-phase83-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase83-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
