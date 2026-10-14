"""Original compressed seek via actual memory/buffered seek, plus prepared compressed record close."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
from unicorn.x86_const import UC_X86_REG_EDX
COMP=0x297dc60;CONTAINER=D+0xb000;STREAM=0x8ceb50;segments=[(TABLE,400),(COMP,0x300),(CONTAINER,0x200),(STREAM,64)];MASK64=(1<<64)-1

def q(p):return rd(p)|(rd(p+4)<<32)
def wq(p,v):wd(p,v&0xffffffff);wd(p+4,v>>32)
def seekParent86(handle,low,high):
 if handle==1:wq(STREAM+8,low|(high<<32));return low|(high<<32)
 slot=TABLE+(handle-0x400)*20;cursor=(rd(slot)+low)&0xffffffff;wd(slot+8,cursor);value=(cursor-rd(slot))&0xffffffff;return value|(0xffffffff00000000 if value&0x80000000 else 0)
def seek86(handle,low,high,origin):
 record=COMP+(handle-0x800)*48;parent=(rd(record)+((rd(record+0x20)+3)<<4))&0xffffffff;offset=low|(high<<32)
 target=(q(record+16)+offset if origin==1 else q(record+8)+signed(rd(record+24))-offset if origin==2 else q(record+8)+offset)&MASK64
 value=seekParent86(rd(parent),target&0xffffffff,target>>32);wd(record+20,value>>32);wd(record+16,value&0xffffffff);wd(parent+8,value&0xffffffff);wd(parent+12,rd(record+20));return q(record+16)
def close86(handle):
 record=COMP+(handle-0x800)*48;index=rd(record+32);wd((rd(record)+(index<<4)+52)&0xffffffff,0xffffffff);wd(record+36,0);return record

def execute86(c):
 global shadow,checks
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 record=COMP+c['index']*48;parent=CONTAINER+(c.get('slot',0)+3)*16;method=c['method'];base=c.get('base',17)|(c.get('baseHigh',0)<<32);current=0xfffffff8|(0xffffffff<<32)
 n.pack('<I',record,CONTAINER);n.pack('<Q',record+8,base);n.pack('<Q',record+16,current);n.pack('<I',record+24,c.get('length',31));n.pack('<III',record+32,c.get('slot',0),7,2);n.pack('<I',parent,c.get('parentHandle',0x400));n.pack('<5I',TABLE,DATA,DATA+1023,DATA+7,0,1);n.write(STREAM,bytes(64));n.pack('<I',STREAM+0x2c,1)
 if c.get('alias'):
  parent=record+12;n.pack('<I',record,parent-48);n.pack('<I',record+32,0);n.pack('<I',parent,c.get('parentHandle',0x400))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};handle=0x800+c['index']
 if method=='Close':inputs=dict(handle=handle);want=[close86(handle)];address=0x4f6bc0;args=[handle]
 else:
  low=c['low'];high=c['high'];origin=c['origin'];inputs=dict(handle=handle,low=low,high=high,origin=origin);chosenHigh=(0xffffffff if low&0x80000000 else 0)if method=='PublicSeek'else high;value=seek86(handle,low,chosenHigh,origin);want=[value&0xffffffff,value>>32];address=0x4f6de0 if method=='PublicSeek'else 0x4f0ae0;args=list(inputs.values())
 model=snap(True);eax=n.call(address,args);actual=[eax]if method=='Close'else[eax,n.mu.reg_read(UC_X86_REG_EDX)];final=snap()
 for group,a,b in [('return',actual,want),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual,final=final))
for method,parent,origin,low,high,index in itertools.product(['Seek','PublicSeek'],[1,0x400],[0,1,2,3,0xffffffff],[0,1,0x80000000,0xffffffff],[0,0xffffffff,0x12345678],[0,3]):execute86(dict(method=method,parentHandle=parent,origin=origin,low=low,high=high,index=index,base=0xfffffff8 if len(cases)&1 else 17,baseHigh=0xffffffff if len(cases)&2 else 0,length=0x80000000 if len(cases)&4 else 31))
for method,parent,origin in itertools.product(['Seek','PublicSeek'],[1,0x400],[0,1,2]):execute86(dict(method=method,parentHandle=parent,origin=origin,low=17,high=0x12345678,index=0,alias=True))
for index,slot in itertools.product([0,3],[0,1,7]):execute86(dict(method='Close',index=index,slot=slot))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=1,ports=[],closure='Original4f0ae0→4f6de0→actual memory4f6c70 or buffered64bit seek; original4f6bc0 compressed close branch, no adapters')
(nm.BASE/'reports/script-phase86-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase86-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
