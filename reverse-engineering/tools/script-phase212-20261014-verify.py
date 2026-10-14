"""Complete raw201-byte relocation entry; literal pointer arithmetic, no repaired layout."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
POOL=D+0x100;ROOT=D+0x300;POINTER=D+0x1000;NEXTLIST=D+0x500;cases=[];checks=0;errors=[]
U=lambda v:v&0xffffffff
def run212(c):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x4000)));p=0 if c.get('nullPointer')else POINTER+c.get('alignment',0);pool=0 if c.get('nullPool')else POOL;size=c['size'];following=p+size+4 if p else POINTER+size+4;n.pack('<4I',POOL,ROOT-16,2048,17,12345);n.pack('<3I',ROOT,0x80000000,following,0);n.pack('<I',POINTER+c.get('alignment',0)-12,size|0x80000000);n.pack('<3I',following,c['freeSize']|(0x80000000 if c['busy']else 0),NEXTLIST if c['next']else 0,ROOT if c['previous']else 0);n.pack('<3I',NEXTLIST,33,0,following);initial=n.read(D,0x4000);model=bytearray(initial)
 def rd(q):return int.from_bytes(model[q-D:q-D+4],'little')
 def wr(q,v):model[q-D:q-D+4]=U(v).to_bytes(4,'little')
 want=p
 if p and not rd(p+size+4)&0x80000000:
  free=rd(p+size+4)&0x7fffffff;prev=rd(p+size+12)
  if prev:wr(prev+4,rd(p+size+8))
  nxt=rd(p+size+8)
  if nxt:wr(nxt+8,rd(p+size+12))
  destination=p+free+28
  for i in range(size-1,-1,-1):model[destination-D+i]=model[p-D+i]
  block=p+free+16;wr(block+4,0);wr(block+8,0);wr(block,size|0x80000000);wr(block+size+12,block);wr(p,free);wr(p+4,0);wr(p+8,0);wr(p+free+12,p);root=rd(pool)+16;head=rd(root+4)
  if head:wr(head+8,p)
  wr(p+4,rd(root+4));wr(p+8,root);wr(root+4,p);want=destination
 actual=n.call(0x4efc60,[pool,p],count=1000000);after=n.read(D,0x4000)
 for group,a,b in [('return',actual,want),('images',after,bytes(model))]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(D+i),u,v]for i,(u,v)in enumerate(zip(a,b))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(inputs=dict(pool=pool,pointer=p),context=c,initial=[dict(address=D,bytes=initial.hex())],final=[dict(address=D,bytes=after.hex())],returnValue=actual))
for size,freeSize,busy,previous,nxt,alignment in itertools.product([0,1,15,16,17,128],[0,1,16,127,128],[False,True],[False,True],[False,True],range(4)):run212(dict(size=size,freeSize=freeSize,busy=busy,previous=previous,next=nxt,alignment=alignment))
for nullPointer,nullPool,busy in[(True,True,False),(True,False,True),(False,True,True)]:run212(dict(size=16,freeSize=32,busy=busy,previous=True,next=True,nullPointer=nullPointer,nullPool=nullPool))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=[],rawEntryConsumers=['0x4efc60'],closure='Whole201-byte raw relocation, backwardsbytecopy andliteral metadata/boundary/free-list offsets; busy/null earlyreturn no pool read; noports, no corrected interpretation')
(nm.BASE/'reports/script-phase212-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase212-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
