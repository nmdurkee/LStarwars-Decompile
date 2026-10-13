"""Original shadow parameter setters and complete two-context startup chain."""
import ast,struct,json,gzip,hashlib,random,collections,base64
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
path=B/'tools/geometry-shadow-construction-native.py';tree=ast.parse(path.read_text());body=[]
for node in tree.body:
 if isinstance(node,ast.For) and isinstance(node.target,ast.Tuple):break
 body.append(node)
c={'__file__':str(path)};exec(compile(ast.Module(body=body,type_ignores=[]),str(path),'exec'),c)
n=c['n'];D=c['D'];SIZE=c['SIZE'];CP=c['CP'];HP=c['HP'];SP=c['SP'];w=c['w'];u=c['u'];calls=c['calls']
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
for address in [0x5953b0,0x5c6c90,0x5c6cc0,0x5b79d0]:n.mu.hook_add(UC_HOOK_CODE,c['hook'],begin=address,end=address)
OFFSETS={0:0x80c,1:0x810,2:0x814,3:0x818,6:0x110,7:0x110,8:0x490,9:0x104,10:0x104,11:0x104,12:0x100,13:0x100,14:0x100,15:0x484,16:0x484,17:0x480,18:0x480,19:0x81c,20:0x820}
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
cases=[];counts=collections.Counter()
def scalar(b,p,selector,word,trace,cdecl):
 if cdecl:trace.append(0x5c6c90)
 trace.append(0x5953b0)
 if selector in OFFSETS:w(b,p+OFFSETS[selector],word)
def integer(b,p,selector,word,trace):
 trace.append(0x5c6cc0)
 if selector in (4,5):w(b,p+0x800+(selector-4)*4,word)
def setup_model(before):
 b=bytearray(before);trace=[];contexts=[]
 for first in [True,False]:
  trace.append(0x5f7420);p=c['alloc'](b,CP,0x830,trace,0x5f20c0);assert p;c['context'](b,p,trace);contexts.append(p)
  integer(b,p,5,2,trace)
  values=[(0,0x3f59999a if first else 0x3e800000),(1,0x40600000),(2,0x3ecccccd if first else 0x3f59999a),(3,0x3e4ccccd),(14,0x38d1b717),(11,0x38d1b717)]
  if first:values.extend([(18,0x38d1b717),(16,0x38d1b717)])
  for selector,word in values:scalar(b,p,selector,word,trace,True)
  w(b,p+0x800,0);trace.append(0x5b79d0);matrix=[0]*16;matrix[0]=matrix[5]=bits(2/120);matrix[10]=bits(2/300);matrix[12]=matrix[13]=0x80000000;matrix[14]=bits(-1);matrix[15]=bits(1)
  for i,word in enumerate(matrix):w(b,p+0x7c0+4*i,word)
 p=contexts[1]
 for volume in range(2):
  for alternate in range(2):record=p+volume*0x380+0x2a4+alternate*0x44;w(b,record+20,u(b,record+16))
 w(b,p+0x808,1)
 return b,contexts,trace
def execute(kind,before,context,selector,word,label):
 if kind=='initialize':expected,contexts,trace=setup_model(before);address=0x596530;args=[];regs={}
 else:
  expected=bytearray(before);contexts=[0x12345678,0x87654321];trace=[]
  if kind=='integer':integer(expected,context,selector,word,trace);address=0x5c6cc0;args=[context,selector,word];regs={}
  else:
   cdecl=kind=='cdecl';scalar(expected,context,selector,word,trace,cdecl);address=0x5c6c90 if cdecl else 0x5953b0;args=[context,selector,word] if cdecl else [selector,word];regs={} if cdecl else {UC_X86_REG_ECX:context}
 n.write(D,before);n.pack('<2I',0x955b38,0x12345678,0x87654321);calls.clear();n.call(address,args,regs,count=1000000);actual=n.read(D,SIZE);got_contexts=list(n.unpack('<2I',0x955b38))
 assert actual==expected and got_contexts==contexts and calls==trace,dict(kind=kind,label=label,contexts=got_contexts,expectedContexts=contexts,calls=calls,trace=trace,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:15])
 counts['cases']+=1;counts[kind]+=1;counts['persistentBytes']+=SIZE+8
 cases.append(dict(kind=kind,label=label,beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),context=context,selector=selector,word=word,contexts=contexts,nativeSHA256=hashlib.sha256(struct.pack('<2I',*contexts)+actual).hexdigest(),nativeCalls=trace))
# Unknown selectors must not dereference the intentionally invalid context.
selectors=list(range(32))+[0x7fffffff,0x80000000,0xffffffff]
words=[0,0x80000000,1,0x80000001,0x7f7fffff,0xff7fffff,bits(.0001),bits(-3.5)]
for selector in selectors:
 for word in words:
  for kind in ['float','cdecl','integer']:
   valid=selector in ((4,5) if kind=='integer' else OFFSETS);context=CP+((selector+word)&7)*0x830 if valid else 0xdeadbeef
   execute(kind,c['setup'](len(cases)),context,selector,word,[selector,word])
rng=random.Random(0x596530)
for i in range(512):
 before=c['setup'](i);mask=rng.randrange(256)
 while mask.bit_count()>6:mask=rng.randrange(256)
 before[CP+8*0x830-D]=mask;w(before,CP+8*0x830+4,i&7);w(before,HP+8*16+4,(i//8)&7);w(before,SP+8*64+4,(i//64)&7)
 execute('initialize',before,0,0,0,i)
fp=R/'geometry-shadow-setup-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,contextPool=CP,commandPool=HP,shaderPool=SP,cases=cases),separators=(',',':')).encode(),mtime=0))
report=dict(schema='geometry-shadow-setup-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Original setters and full596530 constructor/configuration chains execute unchanged; no computational stubs or device callbacks.', '512 complete chains vary all three allocation cursors and context occupancy, with sufficient space for two contexts and all eight command/shader slots. Native allocation failure would dereference null and is excluded.', 'Scalar selectors0..31 plus signed/unsigned extremes are tested with finite float32 words including subnormals and signed zero. Unknown selectors use invalid context addresses to verify no dereference.', 'Integer setters copy raw32-bit values. Scalar setter instructions use x87 load/store; signalingNaN and nonfinite values are outside portable validated scope.', 'Pool byte comparisons retain untouched padding; adapted two-global output pointers are checked. Ordered constructor/parameter/matrix calls agree with the independent model.', 'C# runtime equality, full frame scheduling and GPU output remain unclaimed.'])
(R/'geometry-shadow-setup-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
