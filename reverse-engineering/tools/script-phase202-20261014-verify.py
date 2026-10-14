"""Four complete raw archive metadata/comparison/hash/invalidation leaves; no hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
import random,struct
from unicorn.x86_const import UC_X86_REG_EDX
TABLE=0x297dc60;cases=[];checks=0;errors=[]

def run202(c):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x3000)));n.write(TABLE,bytes((i*19+7)&255 for i in range(64*48)));method=c['method'];args=[];regs={};inputs={}
 if method=='Greater':
  left=D+0x100;right=left+c.get('aliasOffset',0x40)
  if 'left'in c:
   for p,key in [(left,'left'),(right,'right')]:
    v=c[key];n.pack('<H',p+22,v[0]&65535)
    for offset,value in zip([20,19,18,17,16],v[1:]):n.write(p+offset,bytes([value&255]))
  def key(p):return(struct.unpack('<h',n.read(p+22,2))[0],*[struct.unpack('<b',n.read(p+i,1))[0]for i in[20,19,18,17,16]])
  want=int(key(right)>key(left));address=0x4f0a20;args=[left,right];inputs=dict(left=left,right=right)
 elif method=='Position':
  h=c['handle'];p=TABLE+(h-0x800)*48;begin=c['begin'];current=c['current'];n.pack('<QQ',p+8,begin,current);want=(current-begin)&0xffffffffffffffff;address=0x4f0ab0;args=[h];inputs=dict(handle=h)
 elif method=='Hash':
  payload=bytes.fromhex(c['payload']);source=D+0x100+c.get('alignment',0);n.write(source,payload+b'\0');want=0x811c9dc5
  for b in payload.split(b'\0')[0]:want=((want^((b if b<128 else b-256)&0xffffffff))*0x199933)&0xffffffff
  address=0x4f0b70;regs={UC_X86_REG_EDX:source};inputs=dict(source=source)
 else:
  h=c['handle'];p=TABLE+(h-0x800)*48;base=p+c['baseOffset']if'baseOffset'in c else D+0x100;index=c['index'];n.pack('<I',p,base);n.pack('<I',p+0x20,index&0xffffffff);address=0x4f0ba0;args=[h];inputs=dict(handle=h);want=None
 rows=[dict(address=D,bytes=n.read(D,0x3000).hex()),dict(address=TABLE,bytes=n.read(TABLE,64*48).hex())];model={r['address']+i:b for r in rows for i,b in enumerate(bytes.fromhex(r['bytes']))}
 def wr(p,v):
  for i in range(4):model[p+i]=(v>>(i*8))&255
 if method=='Invalidate':
  if index>=0:wr(base+index*16+0x34,0xffffffff)
  wr(p+0x24,0)
 expected=[dict(address=r['address'],bytes=bytes(model[r['address']+i]for i in range(len(r['bytes'])//2)).hex())for r in rows];actual=n.call(address,args,regs=regs,count=1000000)
 if method=='Position':actual|=n.mu.reg_read(UC_X86_REG_EDX)<<32
 final=[dict(address=r['address'],bytes=n.read(r['address'],len(r['bytes'])//2).hex())for r in rows]
 for group,a,b in [('images',final,expected)]+([]if want is None else [('return',actual,want)]):
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=rows,final=final,returnValue=None if want is None else actual))
# Equal prefixes force every signed tier and right-greater behavior.
for tier in range(6):
 values=[-32768,-1,0,1,32767]if tier==0 else[-128,-1,0,1,127]
 for a,b in itertools.product(values,values):
  left=[0]*6;right=[0]*6;left[tier]=a;right[tier]=b;run202(dict(method='Greater',left=left,right=right))
rng=random.Random(202)
for i in range(300):run202(dict(method='Greater',left=[rng.randrange(-32768,32768),*[rng.randrange(-128,128)for _ in range(5)]],right=[rng.randrange(-32768,32768),*[rng.randrange(-128,128)for _ in range(5)]]))
for delta in[-23,-1,0,1,23]:run202(dict(method='Greater',aliasOffset=delta))
values=[0,1,0xffffffff,0x100000000,0x7fffffffffffffff,0x8000000000000000,0xffffffffffffffff]
for h,begin,current in itertools.product([0x800,0x801,0x83f],values,values):run202(dict(method='Position',handle=h,begin=begin,current=current))
for length,alignment in itertools.product([0,1,2,3,7,16,128,511],range(4)):
 for flavor in range(3):run202(dict(method='Hash',payload=bytes(rng.randrange(1,256)if flavor==0 else 255 if flavor==1 else 65 for _ in range(length)).hex(),alignment=alignment))
for h,index in itertools.product([0x800,0x801,0x83f],[-2,-1,0,1,7,8,31]):run202(dict(method='Invalidate',handle=h,index=index))
for offset,index in itertools.product([-0x34,-0x10,0,0x24],[0,1]):run202(dict(method='Invalidate',handle=0x801,index=index,baseOffset=offset))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=[],rawEntryConsumers=['0x4f0a20','0x4f0ab0','0x4f0b70','0x4f0ba0'],closure='Whole four raw entries, signedlexicographicright-greater boolean,64-bitborrowposition, signed-byte199933hash andlivebacking invalidation aliases')
(nm.BASE/'reports/script-phase202-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase202-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
