"""Full block-close Win32 branch and live block-record aliases; only final seek/write APIs ported."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase132-20261013-verify.py').read_text().split('\nfor h,depth,alignment,begin,current,marker')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_EIP
STREAM=0x8ceb50;HANDLES=0x8007a0;SEEK=n.STOP+0x100;WRITE=n.STOP+0x200;segments+=[(STREAM,4096),(HANDLES,256)];cases=[];errors=[];checks=0;events=[];config={};ms={};ns={};n.pack('<I',0x7510ec,SEEK);n.pack('<I',0x7510e8,WRITE)
def quad(p):return rd(p)|(rd(p+4)<<32)
def putquad(p,v):wd(p,v&0xffffffff);wd(p+4,v>>32)
def patches134(name,ordinal,model):
 for item in config.get('patchOn'+name,[]):
  if item['ordinal']==ordinal:
   for p,v in item['patches']:
    if model:wd(p,v)
    else:n.pack('<I',p,v)
def seekPort134(model,raw,low,high,origin):
 state=ms if model else ns;ordinal=state['seeks'];state['seeks']+=1;events.append(dict(name='SetFilePointerEx',args=[raw,low,high,origin]));success=0 if ordinal in config.get('seekFailures',[])else 1;offset=low|(high<<32)
 if offset>=0x8000000000000000:offset-=0x10000000000000000
 if success:
  state['position']=offset if origin==0 else state['position']+offset if origin==1 else len(state['bytes'])+offset
  if state['position']<0:raise ValueError('nonnegative prepared physical position')
 value=state['position'];patches134('Seek',ordinal,model);return value,success
def writePort134(model,raw,data,count,overlapped):
 state=ms if model else ns;ordinal=state['writes'];state['writes']+=1;events.append(dict(name='WriteFile',args=[raw,data[:count].hex(),count,overlapped]));amount=min(count,config.get('writeCap',64));start=state['position'];end=start+amount
 if end>len(state['bytes']):state['bytes'].extend(b'\0'*(end-len(state['bytes'])))
 state['bytes'][start:end]=data[:amount];state['position']=end;patches134('Write',ordinal,model);return config.get('writeBoolean',1),amount if config.get('reportWritten',True)else None

def hook134(mu,address,size,data):
 if address not in[SEEK,WRITE]:return
 sp=mu.reg_read(UC_X86_REG_ESP);a,b,c,out,e=n.unpack('<5I',sp+4)
 if address==SEEK:
  value,success=seekPort134(False,a,b,c,e);n.pack('<2I',out,value&0xffffffff,value>>32)
 else:
  success,got=writePort134(False,a,n.read(b,c),c,e)
  if got is not None:n.pack('<I',out,got)
 mu.reg_write(UC_X86_REG_EAX,success);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook134)

def position134(h):
 if h>=0x1000:return 0
 if h>=0x400:return position132(h)
 p=STREAM+(h-1)*64
 if rd(p+44):return quad(p+8)
 while True:
  value,ok=seekPort134(True,rd(HANDLES+(h-1)*4),0,0,1)
  if ok and value<0x8000000000000000:return value

def seek134(h,value):
 if h>=0x400:return seek132(h,value)
 p=STREAM+(h-1)*64
 if rd(p+44):putquad(p+8,value);return value
 out,ok=seekPort134(True,rd(HANDLES+(h-1)*4),value&0xffffffff,value>>32,0);return out if ok else 0xffffffffffffffff

def write134(h,data,count):
 if h>=0x400:return writeBytes132(h,data,count)
 ok,got=writePort134(True,rd(HANDLES+(h-1)*4),data,count,0);return (got or 0)if ok else 0

def close134(h):
 depth=(rd(DEPTH)-1)&0xffffffff;wd(DEPTH,depth);record=STACK+depth*16;current=position134(h);align=signed(rd(ALIGN));length=signed(((current&0xffffffff)-rd(record+8))&0xffffffff);quotient=abs(length)//align
 if length<0:quotient=-quotient
 pad=align-(length-quotient*align)
 if pad!=align:current=(current+pad)&0xffffffffffffffff;length=signed((length+pad)&0xffffffff);write134(h,struct.pack('<IQ',0,current),pad)
 if signed(rd(record+4))<0:length=signed((-length)&0xffffffff)
 patch=(quad(record+8)+4)&0xffffffffffffffff;seek134(h,patch);write134(h,struct.pack('<I',length&0xffffffff),4);return seek134(h,current)
def fileState134(state):return dict(position=state['position'],bytes=state['bytes'].hex(),seekCalls=state['seeks'],writeCalls=state['writes'])

def run134(c):
 global shadow,checks,events,config,ms,ns
 config=c
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 h=c['handle'];depth=c['depth'];record=STACK+(depth-1)*16;n.pack('<2I',DEPTH,depth,c['alignment']);n.pack('<4I',record,0xdeadbeef,c['marker'],c['beginLow'],c.get('beginHigh',0));data=DATA
 if 0x400<=h<0x1000:
  if 'dataOffset'in c:data=record+c['dataOffset']
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<h-0x400 else 0)
  assert n.call(0x4f02d0,[data,64,1])==h;n.call(0x4f6de0,[h,c['currentLow'],0,0])
 elif h<0x400:
  p=STREAM+(h-1)*64;n.pack('<2I',p+8,c['currentLow'],c.get('currentHigh',0));n.pack('<I',p+44,c['buffered']);n.pack('<I',HANDLES+(h-1)*4,0x12345678+h)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};initialFile=dict(position=c.get('physical',0),bytes=bytes((i*37+11)&255 for i in range(64)).hex());ms=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);ns=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);events=[];wanted=close134(h);model=snap(True);me=events.copy();mf=fileState134(ms);events=[];actual=n.call(0x4f6f60,[h],count=4000000);actual|=n.mu.reg_read(UC_X86_REG_EDX)<<32;final=snap();ne=events.copy();nf=fileState134(ns)
 for group,a,b in[('return',actual,wanted),('images',final,model),('events',ne,me),('file',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method='CloseBlock',context=c,inputs=dict(handle=h,privateLocal=D+0x2000),initial=initial,initialFile=initialFile,final=final,returnValue=actual,nativeEvents=ne,finalFile=nf))
for h,align,current,cap,boolean,report in itertools.product([1,2,64],[1,4,8,12],[1,5,17],[0,2,64],[0,1],[False,True]):run134(dict(handle=h,depth=1,alignment=align,beginLow=1,currentLow=current,marker=0xffffffff,buffered=0,physical=current,writeCap=cap,writeBoolean=boolean,reportWritten=report))
for h,align,current,high,physical,cap in itertools.product([1,64],[4,8,12],[1,5],[0,1],[0,42,63],[2,64]):run134(dict(handle=h,depth=2,alignment=align,beginLow=0,beginHigh=high,currentLow=current,currentHigh=high,marker=0,buffered=7,physical=physical,writeCap=cap,writeBoolean=1,reportWritten=True))
for failures in[[0],[1],[2],[0,2],[0,3]]:run134(dict(handle=1,depth=1,alignment=8,beginLow=0,currentLow=5,marker=0xffffffff,buffered=0,physical=5,writeCap=2,writeBoolean=1,reportWritten=True,seekFailures=failures))
run134(dict(handle=1,depth=1,alignment=4,beginLow=0,currentLow=5,marker=0,buffered=0,physical=5,writeCap=64,writeBoolean=1,reportWritten=True,patchOnSeek=[dict(ordinal=0,patches=[[ALIGN,8],[DEPTH,7],[STACK+8,2]])],patchOnWrite=[dict(ordinal=0,patches=[[STACK+8,3],[STACK+4,0xffffffff],[STREAM+44,7]])]))
for h,depth,offset,marker in itertools.product([0x400,0x413],[1,2],[0,4],[0,0xffffffff]):run134(dict(handle=h,depth=depth,alignment=8,beginLow=1,currentLow=4,marker=marker,dataOffset=offset))
for h in[0x400,0x413,0x1000,0x7fffffff]:run134(dict(handle=h,depth=1,alignment=12,beginLow=0,currentLow=5,marker=0xffffffff))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],managedExecution=False,newEntries=0,ports=['SetFilePointerEx','WriteFile'],closure='Whole4f6f60raw/bufferedWin32blockclose→realposition/write/publicseek; fullphysicalfilebytes/cursor+logicalimage, livealignment/marker/beginreload andboundedmemory/globalstackaliases')
(nm.BASE/'reports/script-phase134-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase134-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
