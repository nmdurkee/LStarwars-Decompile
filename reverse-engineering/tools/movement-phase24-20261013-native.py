"""Original actor pool allocation and creator gate with character initializer as sole service."""
import importlib.util,struct,json,gzip,itertools,base64,random
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
n=m.NativeX86();D=n.DATA;SIZE=0xc0000;WORLD=D+0x1000;REG=D+0x8000;TYPES=D+0xa000;DESC=D+0xc000;POOL=D+0x10000;AV=0x7f9000;AVSIZE=0x3000;INDEX=0x7fa190;TABLE=0x7fa138;OUT=AV+0x10;vectors=[];errors=[];groups={};events=[];cfg={};counts={}
def u(p):return n.unpack('<I',p)[0]
def hook24(mu,a,size,user):
 if a in[0x475850,0x41f8f0,0x55c9f0,0x55c980,0x62a870]:counts[hex(a)]=counts.get(hex(a),0)+1
 if a!=0x41c7c0:return
 sp=mu.reg_read(m.UC_X86_REG_ESP);actor,typ,mode=n.unpack('<3I',sp+4);events.append(['initialize',actor,typ,mode,n.read(actor,0x400).hex(),u(0x93d500)]);
 if cfg.get('mutate'):n.pack('<I',actor+0x1fc,0);n.pack('<I',REG+0x1c,0);n.pack('<I',actor+0x398,0x12345678)
 mu.reg_write(m.UC_X86_REG_EAX,cfg.get('initReturn',0));mu.reg_write(m.UC_X86_REG_ESP,sp+4);mu.reg_write(m.UC_X86_REG_EIP,u(sp))
n.mu.hook_add(UC_HOOK_CODE,hook24)
def setup24(c):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x298c,0 if c.get('nullDescriptor')else DESC);n.pack('<I',0x29130e4,REG);n.pack('<I',REG+0x1c,TYPES);n.pack('<340H',TYPES,*[65535 if c.get('missingType')else 17]*340);n.pack('<2I',DESC,c.get('stride',0x10d8),POOL);n.pack('<I',0x93d504,POOL);n.pack('<I',0x93d500,0xdeadbeef)
 mask=c.get('activeMask',(1<<64)-1);stride=c.get('stride',0x10d8)
 for j in range(64):n.pack('<I',POOL+j*0x10d8+0x1fc,1 if(mask>>j)&1 else 0)
 for j in range(64):n.pack('<I',POOL+j*stride+0x1fc,1 if j!=c.get('free',0)else 0)
 cfg.clear();cfg.update(c);events.clear();return bytearray(n.read(D,SIZE))
def oracle24(k,c,img):
 highest=0xdeadbeef;ev=[]
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def allocate():
  if c.get('nullDescriptor'):return 0
  stride=u(DESC)
  if not stride:return 0
  current=u(DESC+4)
  for j in range(64):
   if not(img[current-D+0x1fc]&1):img[current-D:current-D+stride]=bytes(stride);put(current+0x1fc,u(current+0x1fc)|1);img[current-D+0x28d]=j;return current
   current+=stride
  return 0
 def high():
  return max([j+1 for j in range(64)if img[POOL-D+j*0x10d8+0x1fc]&1]or[0])
 if k=='highest':return 0,high(),ev
 typ=c.get('type',1)
 if k=='create'and(typ>0x153 or(u(TYPES+typ*2)&65535)==65535):return 0,highest,ev
 actor=allocate()
 if k=='allocate'or not actor:return actor,highest,ev
 put(actor+0x1fc,u(actor+0x1fc)|0x1001);put(actor+0xa8,0x3f800000);put(actor+0xff8,0x3f800000);put(actor+0x1014,0x49f42400);img[actor-D+0x671]=255;img[actor-D+0x107a]=2;index=img[actor-D+0x28d];mask=1<<index if index<64 else 0;put(actor+0x1e8,mask);put(actor+0x224,0x49f42400);put(actor+0x1ec,mask>>32);put(actor+0x220,0x49f42400);put(actor+0x1048,1);put(actor+0x21c,0x49f42400)
 for off in[0x284,0x283,0x285]:img[actor-D+off]=255
 highest=high();put(actor,actor);put(actor+0x398,actor);put(actor+4,actor+0x2c8);put(actor+0x2b0,0);put(actor+0x2b4,0)
 if k=='create':
  ev.append(['initialize',actor,typ,c.get('mode',0),bytes(img[actor-D:actor-D+0x400]).hex(),highest])
  if c.get('mutate'):put(actor+0x1fc,0);put(REG+0x1c,0);put(actor+0x398,0x12345678)
 return actor,highest,ev

def run24(k,c,group):
 before=setup24(c)
 if k=='highest':
  for j in range(64):n.pack('<I',POOL+j*0x10d8+0x1fc,1 if(c.get('activeMask',0)>>j)&1 else 0)
  before=bytearray(n.read(D,SIZE))
 expected=bytearray(before);ret,highest,ev=oracle24(k,c,expected);address={'allocate':0x62a870,'prepare':0x55c9f0,'create':0x41f8f0,'highest':0x55c980}[k];args=[0 if c.get('nullDescriptor')else DESC]if k=='allocate'else[c.get('type',1),c.get('mode',0)]if k=='create'else[];result=n.call(address,args,count=1000000);after=n.read(D,SIZE);actualhigh=u(0x93d500);groups[group]=groups.get(group,0)+1;matchRet=k=='highest'or result==ret
 if after!=expected or actualhigh!=highest or events!=ev or not matchRet:errors.append(dict(kind=k,input=c,result=[result,ret],highest=[actualhigh,highest],events=[events.copy(),ev],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12]))
 vectors.append(dict(kind=k,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,highest=actualhigh,events=events.copy()))
for k,free in itertools.product(['allocate','prepare','create'],range(65)):run24(k,dict(free=free),'all-64-slot-selection-and-exhaustion')
for k,null,stride in itertools.product(['allocate','prepare','create'],[False,True],[0,0x300,0x800,0x10d8,0x2000]):run24(k,dict(nullDescriptor=null,stride=stride,free=7),'descriptor-stride-null-and-cleared-bytes')
for typ,missing,mutate,ret in itertools.product([0,1,0x153,0x154,0xffff,0xffffffff],[False,True],[False,True],[0,0xdeadbeef]):run24('create',dict(type=typ,missingType=missing,mutate=mutate,initReturn=ret,mode=0xfedcba98),'unsigned-type-gate-init-return-ignored')
# Independent highest scan: allocator selection setup is overwritten to requested published mask.
for j in range(65):run24('highest',dict(free=64,activeMask=(1<<j)-1),'highest-active-one-based-mask')
for k in['allocate','prepare','create']:
 c=dict(free=64);setup24(c)
 for j in range(64):n.pack('<I',POOL+j*0x10d8+0x1fc,0)
 for j in range(65):
  events.clear();before=bytearray(n.read(D,SIZE));highbefore=u(0x93d500);expected=bytearray(before);ret,highest,ev=oracle24(k,c,expected)
  # Oracle default is prior untouched high-water value for raw allocation/exhaustion.
  if k=='allocate'or not ret:highest=highbefore
  result=n.call({'allocate':0x62a870,'prepare':0x55c9f0,'create':0x41f8f0}[k],[DESC]if k=='allocate'else[1,0]if k=='create'else[]);after=n.read(D,SIZE);actualhigh=u(0x93d500)
  if after!=expected or result!=ret or actualhigh!=highest or events!=ev:errors.append(dict(kind=k,step=j,result=[result,ret],high=[actualhigh,highest],image=after==expected,events=events==ev))
  vectors.append(dict(kind=k,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,highest=actualhigh,highestBefore=highbefore,events=events.copy(),sequenceStep=j));groups['whole-pool-repeated-reservation']=groups.get('whole-pool-repeated-reservation',0)+1
# Availability context indexes are signed bytes and reread after aliased output stores.
for raw,active,out in itertools.product(range(256),[0,1,0xffffffff],[0,OUT,INDEX,INDEX-1,INDEX+1,TABLE]):
 n.write(AV,bytes([0xa5])*AVSIZE)
 for idx in range(-128,128):n.pack('<I',TABLE+idx*12,(idx*0x1234567+0xfedcba98)&0xffffffff)
 n.pack('<B',INDEX,raw);n.pack('<I',0x93b324,active);before=bytearray(n.read(AV,AVSIZE));expected=bytearray(before)
 if not active:
  if out:struct.pack_into('<I',expected,out-AV,0)
  ret=0xffffffff
 else:
  signed=raw if raw<128 else raw-256
  if out:v=struct.unpack_from('<I',expected,TABLE-AV+signed*12)[0];struct.pack_into('<I',expected,out-AV,v)
  rawret=expected[INDEX-AV];ret=(rawret if rawret<128 else rawret-256)&0xffffffff
 result=n.call(0x475850,[out]);after=n.read(AV,AVSIZE);groups['availability-signed-index-and-output-alias']=groups.get('availability-signed-index-and-output-alias',0)+1
 if after!=expected or result!=ret:errors.append(dict(kind='availability',input=dict(raw=raw,active=active,output=out),result=[result,ret],image=after==expected))
 vectors.append(dict(kind='availability',input=dict(raw=raw,active=active,output=out),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result))
checks=sum(2 if v['kind']=='availability'else 3 if v['kind']=='highest'else 4 for v in vectors);report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=checks,groups=groups,mismatches=len(errors),errors=errors[:20],nativeEntryCounts=counts,nativeAdapters=['Character initializer 41c7c0 only; raw pool allocator, memset, 64-bit shift and highest scan execute.'],limits=['Valid mapped pool backing, bounded stride and complete 64-slot flag fields; wrap-invalid pool images excluded.','Availability signed index uses mapped original table neighborhood; optional output alias and late index reread retained.','Actual character initializer and full actor creation 43d890 remain open.'])
(m.BASE/'reports/movement-phase24-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase24-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);fun=[]
for a,b in[(0x475850,0x47588e),(0x41f8f0,0x41f933),(0x55c9f0,0x55cac4),(0x55c980,0x55c9ef),(0x62a870,0x62a8bb)]:
 ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)];fun.append(dict(address=hex(a),instructions=ins))
(m.BASE/'reports/movement-phase24-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=fun),indent=2)+'\n')
print(json.dumps(dict(cases=len(vectors),checks=checks,mismatches=len(errors),errors=errors[:3])))
