"""Raw original path lookup/binding, including real byte compare and shift helpers."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
n.w32=lambda p,v:n.write(p,struct.pack('<I',v&0xffffffff))
D=n.DATA;SYS=D+0x100;REF=D+0x200;ACT=D+0x400;PATH=D+0x1000;ROWS=D+0x2000;TEXT=D+0x9000;NAME=D+0x9800
shadow={};segments=[];cases=[];errors=[];checks=0
rd=lambda p:sum(shadow[p+i]<<(8*i)for i in range(4))
def wr(p,v,z=4):
 for i in range(z):shadow[p+i]=(v>>(8*i))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def text(p):
 r=[]
 while shadow[p]:r.append(shadow[p]);p+=1
 return bytes((x-32)&255 if 97<=x<=122 or x>=224 else x for x in r)
def find(system,path,name):
 if not path:
  if not system:return 0
  ref=rd(system+0x10)
  if not ref or not shadow[ref]:return 0
  path=rd(ref+8)
  if not path:return 0
 if not shadow[path+0x10]:return 0
 i=0
 while True:
  p=rd(rd(path+0x7c)+i*0x5c)
  if p and text(p)==text(name):return rd(path+0x7c)+i*0x5c
  i+=1
  if i>=shadow[path+0x10]:return 0
def bind(actor,path):
 if rd(actor+0x158)==path:return
 for p in [0x15c,0x160,0x164,0x168,0x16c]:wr(actor+p,0)
 wr(actor+0x158,path);wr(actor+0x161,255,1);wr(actor+0x13a,0,2);wr(actor+0x124,65535,2);wr(actor+0x13c,255,1);wr(actor+0x13d,0,1);wr(actor+0x17c,0)
 if not path or not shadow[path+0x14]:return
 i=0
 while True:
  p=rd(path+0x88)+i*0x28
  if(rd(p+0x18)&rd(actor+0x130))or(rd(p+0x1c)&rd(actor+0x134)):wr(actor+0x13a,(shadow[actor+0x13a]|shadow[actor+0x13b]<<8)|(1<<i if i<16 else 0),2)
  i+=1
  if i>=shadow[path+0x14]:return
def execute(c):
 global shadow,segments,checks
 n.write(D,bytes(0xa000));rng=random.Random(c['seed']);n.write(ACT,bytes(rng.randrange(256)for _ in range(0x300)))
 n.w32(SYS+0x10,REF if c.get('ref',1)else 0);n.write(REF,bytes([c.get('enabled',1)]));n.w32(REF+8,PATH if c.get('fallback',1)else 0)
 count=c['count'];n.write(PATH+0x10,bytes([count]));n.write(PATH+0x14,bytes([count]));n.w32(PATH+0x7c,ROWS);n.w32(PATH+0x88,ROWS)
 n.w32(ACT+0x158,c.get('old',0));n.w32(ACT+0x130,c.get('low',0x80000001));n.w32(ACT+0x134,c.get('high',0x80000000))
 for i in range(count):
  p=TEXT+i*7;n.write(p,bytes([0x61+i%26,0xe0+i%32,0]))
  n.w32(ROWS+i*0x5c,p if i%3 else 0);n.w32(ROWS+i*0x28+0x18,rng.getrandbits(32));n.w32(ROWS+i*0x28+0x1c,rng.getrandbits(32))
 # Lookup records are rebuilt after membership masks; the two operations have separate prepared layouts.
 if c['address']==0x51ad80:
  for i in range(count):n.w32(ROWS+i*0x5c,TEXT+i*7 if i%3 else 0)
 raw=bytes(c.get('name',[0x41,0xc0]));n.write(NAME,raw+b'\0')
 path=c.get('path',PATH);actor=c.get('actor',ACT);system=c.get('system',SYS)
 if c.get('alias'):path=ACT;n.write(path+0x14,bytes([count]));n.w32(path+0x88,ROWS)
 segments=[(D,0x1800),(ROWS,max(0x100,count*0x5c)),(TEXT,0x1000)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};want=0;mf=False
 try:
  if c['address']==0x51ad80:want=find(system,path,NAME)
  else:bind(actor,path)
 except KeyError:mf=True
 model=snap(True);nf=False;got=0
 try:got=n.call(c['address'],[system,path,NAME]if c['address']==0x51ad80 else[actor,path])
 except RuntimeError:nf=True
 if c['address']!=0x51ad80:got=want=0
 native=snap()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else'byte image',model=b if group!='images'else'byte image'))
 cases.append(dict(context=c,inputs=dict(address=c['address'],system=system,path=path,name=NAME,actor=actor),initial=initial,fault=nf,returnValue=0 if nf else got,final=native))
for count,path,sys,enabled,ref,fallback in itertools.product([0,1,3,17,255],[0,PATH],[0,SYS],[0,1],[0,1],[0,1]):execute(dict(address=0x51ad80,seed=1,count=count,path=path,system=sys,enabled=enabled,ref=ref,fallback=fallback))
for count,old,path,low,high in itertools.product([0,1,15,16,17,31,32,63,64,65,255],[0,PATH],[0,PATH],[0,0x80000001],[0,0x80000000]):execute(dict(address=0x51a7c0,seed=2,count=count,old=old,path=path,low=low,high=high))
for count in [0,1,16,17,255]:execute(dict(address=0x51a7c0,seed=3,count=count,alias=True))
for i in range(1,256):execute(dict(address=0x51ad80,seed=i,count=3,name=[0x61+1,0xe0+1]if i%2 else[i]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,refinements=['51ad80','51a7c0'],ports=[])
(nm.BASE/'reports/script-phase142-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase142-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
