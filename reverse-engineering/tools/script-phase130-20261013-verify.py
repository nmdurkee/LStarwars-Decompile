"""Actual bounded memory-file writer and corrected release CRT seek/write endpoint provenance. No hooks."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EDX
D=n.DATA;TABLE=0x2983740;DATA=D+0x400;SOURCE=D+0x1000;segments=[(TABLE,400),(D,0x2000)];cases=[];errors=[];checks=0;shadow={}
def snap(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rb(p):return shadow[p]
def wb(p,v):shadow[p]=v&255
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(8*i))
def signed(v):return v if v<0x80000000 else v-0x100000000

def write130(handle,source,count):
 slot=TABLE+(handle-0x400)*20;cursor=rd(slot+8);available=signed((rd(slot+4)-cursor+1)&0xffffffff);copied=min(available,signed(count))
 if copied<0:raise ValueError('bounded nonnegative copy')
 if copied:
  for i in range(copied):wb(cursor+i,rb(source+i))
  wd(slot+8,(rd(slot+8)+copied)&0xffffffff)
 return copied

def run130(c):
 global shadow,checks
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 method=c['method'];handle=c['handle'];source=SOURCE+c.get('alignment',0);count=c.get('count',0);slot=TABLE+(handle-0x400)*20 if method=='Write'else TABLE
 if method=='Write':
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<c['index']else 0)
  actualHandle=n.call(0x4f02d0,[DATA,c['length'],c['mode']]);assert actualHandle==handle;n.call(0x4f6de0,[handle,c['offset'],0,0])
  if c.get('alias')=='same':source=DATA+c['offset']
  if c.get('alias')=='record':n.pack('<3I',slot,slot+8,slot+11,slot+8);count=4
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};wanted=write130(handle,source,count)if method=='Write'else 0;model=snap(True)
 if method=='Write':actual=n.call(0x4f0380,[handle,source,count],count=4000000)
 else:actual=n.call(0x4f6de0,[handle,c['low'],c['high'],c['origin']]);actual|=n.mu.reg_read(UC_X86_REG_EDX)<<32
 final=snap()
 for group,a,b in[('return',actual,wanted),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group=='return'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(handle=handle,source=source,count=count),initial=initial,final=final,returnValue=actual))
for index,length,offset,count,mode,alignment in itertools.product([0,3,19],[1,17,128],[0,1],[0,1,16,17,128],[0,1],[0,1,3,7]):
 if offset<=length:run130(dict(method='Write',index=index,handle=0x400+index,length=length,offset=offset,count=count,mode=mode,alignment=alignment))
for alias in['same','record']:run130(dict(method='Write',index=0,handle=0x400,length=64,offset=1,count=17,mode=1,alias=alias))
for handle,low,high,origin in itertools.product([0x1000,0x1007,0x7fffffff],[0,0xffffffff,0x80000000],[0,0xffffffff],[0,1,2,7]):run130(dict(method='CrtSeek',handle=handle,low=low,high=high,origin=origin))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=[],closure='Wholememory writer4f0380→actual6e6d90 memcpy withlivecursorreload; allocator/publicmemoryseek preparation. CorrectactualpublicCRTseek child6dee90, while6dee60 is CRTwrite endpoint, nohooks')
(nm.BASE/'reports/script-phase130-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase130-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
