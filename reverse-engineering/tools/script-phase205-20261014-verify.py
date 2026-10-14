"""Whole application allocator471/free450 and actual release diagnostic RETs, actual world memset children."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
import random
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
G=0x88ab18;PATTERN=0x800444;CPU=0x29a9c48;ARENA=D+0x100;CURSOR=D+0x200;BUMP=D+0x300;HEAP=D+0x1000;FILE=D+0x6000;PREV=D+0x5000;NEXT=D+0x5100;shadow={};config={};events=[];cases=[];checks=0;errors=[];bodyExecutions={}
U=lambda v:v&0xffffffff
I=lambda v:(v&0x7fffffff)-(v&0x80000000)
def rd(p):return sum(shadow[U(p+i)]<<(i*8)for i in range(4))
def rb(p):return shadow[U(p)]
def wr(p,v):
 for i in range(4):shadow[U(p+i)]=(v>>(i*8))&255
def wb(p,v):shadow[U(p)]=v&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in[(D,0x7000),(G,32),(PATTERN,28),(CPU,4)]]
def port205(address,args,model):
 events.append(dict(callback=address,args=args));return config.get('heapResult',HEAP)if address in[0x6e7570,0x4f6740]else config.get('freeResult',0)
def hook205(mu,address,size,data):
 if address in[0x4eef40,0x4ef280,0x4eeda0,0x4eedc0,0x6e6950,0x6eec22,0x6eebcb]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
 argc={0x6e7570:1,0x4f6740:3,0x6e7633:1,0x4efb00:2}.get(address)
 if argc is None:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*argc,sp+4));result=port205(address,args,False);mu.reg_write(UC_X86_REG_EAX,U(result));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook205)
def length(p):
 q=p
 while rb(q):q=U(q+1)
 return U(q-p)
def zero(p,count):
 if count>4096:raise ValueError('bounded general allocation')
 for i in range(count):wb(p+i,0)
def allocate205(size,filename,line):
 arena=rd(G+16)
 if arena:
  cursor=rd(arena);wr(cursor,U(rd(cursor)+15)&0xfffffff0);cursor=rd(arena);limit=rd(arena+4);available=U(limit-rd(cursor))
  if available<size:return 0
  result=rd(cursor);wr(cursor,U(result+size));return result
 bump=rd(G+8)
 if bump:
  aligned=U(size+15)&0xfffffff0;remaining=rd(bump+4)
  if I(aligned)>=I(remaining):return 0
  result=rd(bump+8);wr(bump+8,U(result+aligned));wr(bump+4,U(remaining-aligned));return result
 pool=rd(G+20);total=U(length(filename)+size+45)
 if pool:base=port205(0x4f6740,[pool,total,4],True)
 else:
  base=port205(0x6e7570,[total],True)
  if base:zero(base,U(length(filename)+size+45))
 if base:
  zero(base,U(length(filename)+size+45));wr(G+4,U(rd(G+4)+size));wr(base+16,size)
  for i in range(3):wr(base+20+i*4,rd(PATTERN+i*4))
  for i in range(3):wr(base+size+32+i*4,rd(PATTERN+16+i*4))
  p=filename;q=base+size+44
  while True:
   b=rb(p);wb(q,b);p+=1;q+=1
   if not b:break
  seq=rd(G+12);wr(base+12,seq);wr(G+12,U(seq+1));head=rd(G);wr(base+8,line);wr(base,head)
  if head:wr(head+4,base)
  wr(base+4,0);wr(G,base);result=base+32
 else:result=0
 end=U(result+size)
 if I(end)>I(rd(G+24)):wr(G+24,end)
 if I(end)>I(rd(G+28)):wr(G+28,end)
 return result

def release205(pointer,filename,line):
 if not pointer:return
 base=U(pointer-32)
 # Both canary comparisons execute in native, but release diagnostics are RET and do not stop unlink/free.
 prev=rd(base);nxt=rd(base+4)
 if prev:wr(prev+4,nxt)
 nxt=rd(base+4)
 if nxt:wr(nxt,rd(base))
 else:wr(G,rd(base))
 wr(G+4,U(rd(G+4)-rd(base+16)));wr(base,0);wr(base+4,0);pool=rd(G+20)
 if pool:port205(0x4efb00,[pool,base],True)
 else:port205(0x6e7633,[base],True)
def run205(c):
 global shadow,events,config,checks
 config=c;n.write(D,bytes((i*37+11)&255 for i in range(0x7000)));n.write(G,bytes(32));n.write(PATTERN,bytes((i*19+7)&255 for i in range(28)));n.pack('<I',CPU,c.get('cpu',0));n.pack('<4I',G,c.get('head',0),c.get('bytes',0),0,c.get('sequence',0));n.pack('<4I',G+16,0,c.get('pool',0),c.get('high',0),c.get('high2',0));n.write(FILE,c.get('filename','file.cpp').encode('latin1')+b'\0');method=c['method'];size=U(c.get('size',16));pointer=HEAP+32
 if c.get('arena'):
  n.pack('<I',G+16,ARENA);n.pack('<2I',ARENA,CURSOR,U(c.get('cursor',D+0x400)+c.get('capacity',128)));n.pack('<I',CURSOR,c.get('cursor',D+0x400))
 if c.get('bump'):
  n.pack('<I',G+8,BUMP);n.pack('<3I',BUMP,0,U(c['remaining']),D+0x400)
 if method=='Release':
  pointer=c.get('pointer',HEAP+32);n.pack('<5I',HEAP,c.get('prev',0),c.get('next',0),123,7,size);n.write(HEAP+20,n.read(PATTERN,12));n.write(HEAP+size+32,n.read(PATTERN+16,12))
  if'corrupt'in c:p=HEAP+20+c['corrupt']if c['corrupt']<12 else HEAP+size+32+c['corrupt']-12;n.write(p,bytes([n.read(p,1)[0]^255]))
 rows=snap();shadow={r['address']+i:b for r in rows for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];want=allocate205(size,FILE,c.get('line',77))if method=='Allocate'else release205(pointer,FILE,c.get('line',77));expected=snap(True);me=events.copy();events=[];actual=n.call(0x4eef40 if method=='Allocate'else 0x4ef280,[size,FILE,c.get('line',77)]if method=='Allocate'else[pointer,FILE,c.get('line',77)],count=2000000);final=snap();ne=events.copy()
 for group,a,b in [('images',final,expected),('events',ne,me)]+([('return',actual,want)]if method=='Allocate'else[]):
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(size=size,filename=FILE,line=c.get('line',77),pointer=pointer),initial=rows,final=final,returnValue=actual if method=='Allocate'else None,nativeEvents=ne))
for size,filename,pool,result,head,cpu in itertools.product([0,1,15,16,255,256],['','file.cpp','a'*17],[0,D+0x4000],[0,HEAP],[0,PREV],[0,1]):run205(dict(method='Allocate',size=size,filename=filename,pool=pool,heapResult=result,head=head,cpu=cpu,bytes=0xfffffff0,sequence=0xffffffff,high=0x80000000,high2=0x7fffffff))
for size,capacity,alignment in itertools.product([0,1,15,16,17,127,128,0xffffffff,0x80000000],[0,16,128],range(4)):run205(dict(method='Allocate',arena=True,size=size,capacity=capacity,cursor=D+0x400+alignment))
for size,remaining in itertools.product([0,1,15,16,17,128,0xffffffff,0x80000000],[-1,0,1,16,32,128,-2147483648]):run205(dict(method='Allocate',bump=True,size=size,remaining=remaining))
for size,prev,nxt,pool,corrupt in itertools.product([0,1,16,128],[0,PREV],[0,NEXT],[0,D+0x4000],[None,0,5,11,12,23]):
 c=dict(method='Release',size=size,prev=prev,next=nxt,pool=pool,bytes=0xffffffff,head=HEAP)
 if corrupt is not None:c['corrupt']=corrupt
 run205(c)
for pointer,arena in itertools.product([0,HEAP+32],[False,True]):run205(dict(method='Release',pointer=pointer,arena=arena))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=4,bodyExecutions=bodyExecutions,ports=['6E7570 CRT allocation','6E7633 CRT free','4F6740 private pool allocation','4EFB00 private pool free'],closure='Complete allocation471/free450+two release diagnosticRET bodies; actual world memset/SSE children; arena/bump/debug-header/canary/list/high-water branches, heap mechanisms explicit')
(nm.BASE/'reports/script-phase205-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase205-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
