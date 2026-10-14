"""Whole329byte original block-close on bounded memory/CRT handles through real position/write/seek children. No hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase130-20261013-verify.py').read_text().split('\nfor index,length,offset,count,mode,alignment')[0])
import struct
DEPTH=0x800468;ALIGN=0x80046c;STACK=0x918e60;segments=[(TABLE,400),(D,0x1000),(DEPTH,8),(STACK,0x400)];cases=[];checks=0;errors=[]

def writeBytes132(h,data,count):
 if h>=0x1000:return 0
 slot=TABLE+(h-0x400)*20;cursor=rd(slot+8);available=signed((rd(slot+4)-cursor+1)&0xffffffff);copied=min(count,available)
 if copied<0:raise ValueError('nonnegative writer count required')
 for i in range(copied):wb(cursor+i,data[i])
 if copied:wd(slot+8,(rd(slot+8)+copied)&0xffffffff)
 return copied

def position132(h):
 if h>=0x1000:return 0
 p=TABLE+(h-0x400)*20;return signed((rd(p+8)-rd(p))&0xffffffff)&0xffffffffffffffff

def seek132(h,value):
 if h>=0x1000:return 0
 p=TABLE+(h-0x400)*20;wd(p+8,(rd(p)+(value&0xffffffff))&0xffffffff);return signed(value&0xffffffff)&0xffffffffffffffff

def close132(h):
 depth=(rd(DEPTH)-1)&0xffffffff;wd(DEPTH,depth);record=STACK+depth*16;current=position132(h);begin=rd(record+8)|(rd(record+12)<<32);length=signed(((current&0xffffffff)-(begin&0xffffffff))&0xffffffff);align=signed(rd(ALIGN));quotient=abs(length)//align
 if length<0:quotient=-quotient
 remainder=length-quotient*align;pad=align-remainder
 if pad!=align:
  current=(current+pad)&0xffffffffffffffff;length=signed((length+pad)&0xffffffff);data=struct.pack('<IQ',0,current);writeBytes132(h,data,pad)
 if signed(rd(record+4))<0:length=signed((-length)&0xffffffff)
 seek132(h,(begin+4)&0xffffffffffffffff);writeBytes132(h,struct.pack('<I',length&0xffffffff),4);return seek132(h,current)

def run132(c):
 global shadow,checks
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 h=c['handle'];depth=c['depth'];n.pack('<2I',DEPTH,depth,c['alignment']);record=STACK+(depth-1)*16;n.pack('<4I',record,0xdeadbeef,c['marker'],c['beginLow'],c.get('beginHigh',0))
 if h<0x1000:
  index=h-0x400
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<index else 0)
  assert n.call(0x4f02d0,[DATA,c['fileLength'],c.get('mode',1)])==h;n.call(0x4f6de0,[h,c['current'],0,0])
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};wanted=close132(h);model=snap(True);actual=n.call(0x4f6f60,[h],count=4000000);actual|=n.mu.reg_read(UC_X86_REG_EDX)<<32;final=snap()
 for group,a,b in[('return',actual,wanted),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group=='return'else'diff'))
 cases.append(dict(method='CloseBlock',context=c,inputs=dict(handle=h,privateLocal=D+0x2000),initial=initial,final=final,returnValue=actual))
for h,depth,alignment,begin,current,marker in itertools.product([0x400,0x403,0x413],[1,2,64],[1,2,4,8,12],[0,4,8],[0,1,4,8,12,16],[0,0xffffffff]):
 if begin<=current:run132(dict(handle=h,depth=depth,alignment=alignment,beginLow=begin,current=current,marker=marker,fileLength=64,mode=len(cases)&1))
for current,begin,alignment in itertools.product([12,16,17],[0,8,13],[4,8,12]):
 if begin<=current and begin+4<=17:run132(dict(handle=0x400,depth=1,alignment=alignment,beginLow=begin,current=current,marker=0xffffffff,fileLength=17))
for h,depth,alignment,begin,marker in itertools.product([0x1000,0x1007,0x7fffffff],[1,2,64],[1,2,4,8,12],[0,1,7,0xffffffff],[0,0xffffffff]):run132(dict(handle=h,depth=depth,alignment=alignment,beginLow=begin,beginHigh=0x12345678,current=0,marker=marker,fileLength=64))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],managedExecution=False,newEntries=1,ports=[],closure='Whole4f6f60 block-close→wholeposition4f6d10/4f6c20→memory4f0380 orreleaseCRTwrite6dee60→wholepublicseek4f6de0/6dee90; exactpost-adjustment localpadding spill up11bytes, nohooks')
(nm.BASE/'reports/script-phase132-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase132-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
