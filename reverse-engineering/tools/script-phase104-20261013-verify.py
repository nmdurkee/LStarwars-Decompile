"""Original file bootstrap→actual critical-slot allocator/CRT byte getter/63row reversed extension initializer and release noops. Final InitializeCriticalSection only."""
from pathlib import Path
import importlib.util,json,struct,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EDI
D=n.DATA;OUT=D+0x40;TEXT=D+0x200;API=n.STOP+0x100;COUNTER=0x92124c;REGCOUNT=0x88ab38;REGISTRY=0x90fba8;segments=[(0x297dc60,0x3c0),(0x2983740,0x190),(REGCOUNT,0x14),(REGISTRY,0x600),(0x91ce60,4),(0x917844,4),(COUNTER,4),(0x8264c7,1),(D,0x1000),(0x75ea5c,0x170),(0x75d000,0x30),(0x75a1f0,0x30)];shadow={};events=[];cases=[];checks=0;errors=[];config={};rows=json.loads((nm.BASE/'reports/script-phase104-20261013-initializer-rows.json').read_text());n.pack('<I',0x7510d0,API)
def snapshot(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rb(p):return shadow[p]
def wb(p,v):shadow[p]=v&255
def rd(p):return sum(rb(p+i)<<(i*8)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(i*8))
def signed(v):return v if v<0x80000000 else v-0x100000000
def critical104(model,p):
 events.append(dict(name='InitializeCriticalSection',args=[p]))
 if 'criticalPatch'in config:
  if model:wd(COUNTER,config['criticalPatch'])
  else:n.pack('<I',COUNTER,config['criticalPatch'])
def hook104(mu,address,size,data):
 if address!=API:return
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];critical104(False,n.unpack('<I',sp+4)[0]);mu.reg_write(UC_X86_REG_EAX,0xabcdef01);mu.reg_write(UC_X86_REG_ESP,sp+8);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook104)
def criticalSlot104():
 if signed(rd(COUNTER))>12:return 0
 wd(COUNTER,(rd(COUNTER)+1)&0xffffffff);critical104(True,(0x91ef70+rd(COUNTER)*24)&0xffffffff);return rd(COUNTER)
def row104(name,slot,type):
 index=rd(REGCOUNT);p=(REGISTRY+(index<<4))&0xffffffff;length=0
 while rb(name+length):length+=1
 wb(p+15,length)
 for i in range(length):wb(p+i,rb(name+length-1-i))
 wb(p+length,0);wd(REGCOUNT,(index+1)&0xffffffff);wb(p+13,slot);wb(p+14,type);return slot&255
def initialize104(arg):
 for i in range(0x400):wb(REGISTRY+i,0)
 wd(REGCOUNT,0)
 for row in rows:row104(row.get('nameWhenNonzero',row['name'])if arg else row['name'],row['slot'],row['type'])
 return rows[-1]['slot']&255
def bootstrap104(a,b,c):
 for p,z in[(0x2983740,0x190),(0x297dc60,0x3c0)]:
  for i in range(z):wb(p+i,0)
 wd(0x88ab48,criticalSlot104());initialize104(1 if rb(0x8264c7)==0 else 0);wd(0x91ce60,0);wd(0x917844,0);wd(0x88ab40,0xffffffff);wd(0x88ab44,0xffffffff);return a

def execute104(c):
 global config,shadow,events,checks
 config=c
 for p,z in segments:
  if p not in[0x75ea5c,0x75d000,0x75a1f0]:n.write(p,bytes([0xa5])*z)
 n.pack('<I',COUNTER,c.get('count',0)&0xffffffff);n.pack('<I',REGCOUNT,c.get('rowCount',0));n.pack('<B',0x8264c7,c.get('crt',0));n.write(TEXT,c.get('text','abc').encode('latin1')+b'\0');initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[]
 method=c['method'];args=c.get('args',[0,1,0]);wanted=bootstrap104(*args)if method=='Bootstrap'else criticalSlot104()if method=='Critical'else initialize104(args[0])if method=='Initialize'else row104(TEXT,args[0],args[1])if method=='Row'else rb(0x8264c7);model=snapshot(True);me=events.copy();events=[]
 address={'Bootstrap':0x4f9940,'Critical':0x4ffa60,'Initialize':0x4f78b0,'Row':0x4f7830,'CrtByte':0x6db910}[method];actual=n.call(address,args if method in['Bootstrap','Initialize','Row']else[],regs={UC_X86_REG_EDI:TEXT}if method=='Row'else{},count=4000000);final=snapshot();ne=events.copy()
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(text=TEXT),initial=initial,final=final,returnValue=actual,nativeEvents=ne))
for count,crt,args in itertools.product([-2,-1,0,11,12,13,14,0x80000000],[0,1,2,127,255],[[0,1,0],[1,0,0xffffffff],[0xdeadbeef,0x80000000,123]]):execute104(dict(method='Bootstrap',count=count,crt=crt,args=args))
for count,patch in itertools.product([-2,-1,0,11,12,13,14,0x80000000],[None,0,0xffffffff]):
 c=dict(method='Critical',count=count)
 if patch is not None:c['criticalPatch']=patch
 execute104(c)
for arg in[0,1,0xffffffff,0x80000000]:execute104(dict(method='Initialize',args=[arg]))
for content,rowCount,args in itertools.product(['','a','Abc.123','x'*12,'y'*13,'z'*16],[0,1,63,64],[[0,6],[0xffffffff,0x12345678]]):execute104(dict(method='Row',text=content,rowCount=rowCount,args=args))
for crt in[0,1,2,127,255]:execute104(dict(method='CrtByte',crt=crt))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=6,ports=['InitializeCriticalSection'],closure='Actual4f9940→4ff4a0 RET/4ffa60 criticalslots/6db910 CRTbyte/4f78b0 all63literalrows→4f7830/release diagnostics; finalOS critical initialization only')
(nm.BASE/'reports/script-phase104-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase104-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,initializerRows=rows),separators=(',',':')));print(json.dumps(report))
