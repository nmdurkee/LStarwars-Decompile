"""Original16-byte-block fill/move wrappers and zero/arena leaves; actual existing memory children."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
from unicorn.x86_const import UC_X86_REG_EAX
from unicorn import UC_HOOK_CODE
CPU=0x29a9c48;ARENA=0x88ab28;cases=[];checks=0;errors=[];bodyExecutions={}
def trace(mu,address,size,data):
 if address in[0x4ef6c0,0x4ef6d0,0x4ef6e0,0x4ef700,0x4ef660,0x6e6950,0x6eec22,0x6eebcb]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
n.mu.hook_add(UC_HOOK_CODE,trace)
def run216(c):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x3000)));n.write(CPU,bytes((i*19+7)&255 for i in range(0x1000)));n.pack('<I',CPU,c.get('cpu',0));n.pack('<I',ARENA,c.get('arena',0));method=c['method'];source=D+0x800+c.get('alignment',0);destination=(CPU if c.get('aliasCpu')else D+0x100)+c.get('alignment',0)
 if method=='Move':destination=source+c.get('offset',0)
 if'pointer'in c:destination=c['pointer'];source=c.get('source',source)
 initial=[dict(address=p,bytes=n.read(p,z).hex())for p,z in[(D,0x3000),(CPU,0x1000),(ARENA,4)]];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};count=(c.get('blocks',0)<<4)&0xffffffff;args=[];regs={UC_X86_REG_EAX:c.get('seed',0)}
 if method=='Fill':
  for i in range(count):shadow[destination+i]=c['value']&255
  want=destination;address=0x4ef6e0;args=[destination,c['value'],c['blocks']]
 elif method=='Move':
  if destination<source:
   for i in range(count):shadow[destination+i]=shadow[source+i]
   want=(destination+count)&0xffffffff
  else:
   for i in range(count-1,-1,-1):shadow[destination+i]=shadow[source+i]
   want=0
  address=0x4ef700;args=[destination,source,c['blocks']]
 else:want=c.get('arena',0)if method=='Arena'else 0;address=0x4ef6d0 if method=='Arena'else 0x4ef6c0
 expected=[dict(address=r['address'],bytes=bytes(shadow[r['address']+i]for i in range(len(r['bytes'])//2)).hex())for r in initial];actual=n.call(address,args,regs=regs,count=1000000);final=[dict(address=r['address'],bytes=n.read(r['address'],len(r['bytes'])//2).hex())for r in initial]
 for group,a,b in [('return',actual,want),('images',final,expected)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,inputs=dict(destination=destination,source=source,blocks=c.get('blocks',0),value=c.get('value',0)),context=c,initial=initial,final=final,returnValue=actual))
blocks=[0,1,2,16,17,128,0x10000000,0x10000001]
for block,value,alignment,cpu,alias in itertools.product(blocks,[0,1,255,256,0x10000,0x80000000,0xffffffff],range(4),[0,1],[False,True]):run216(dict(method='Fill',blocks=block,value=value,alignment=alignment,cpu=cpu,aliasCpu=alias))
for block,alignment,offset in itertools.product(blocks,range(4),[-16,-1,0,1,16,256]):run216(dict(method='Move',blocks=block,alignment=alignment,offset=offset))
for method,seed in itertools.product(['Zero','Arena'],[0,1,0xffffffff,0x80000000,0x12345678]):run216(dict(method=method,seed=seed,arena=seed))
for method,pointer in itertools.product(['Fill','Move'],[0,0xdead0000]):run216(dict(method=method,pointer=pointer,source=0xffffffff,blocks=0x10000000,value=0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=1,bodyExecutions=bodyExecutions,ports=[],closure='Whole scaled-block wrappers→actual world memset/SSE/memmove; uintcount<<4 wrap, low-byte value truncation, overlaps andCPUflag backing aliases, zero/arena leaves')
(nm.BASE/'reports/script-phase216-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase216-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
