"""Actual4faf60 container andmode2 chunk reader withreal77/78 seek/read children; chunk fill anddecode remainexplicit."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase78-20261013-verify.py').read_text().split('\nfor handle,low')[0])
COMP=0x297dc60;CONTAINER=D+0xc000;PACKED=0x88ab50;DECODED=0x8cf598;AVAILABLE=0x90fba4;OFFSET=0x8cf390;PACKEDLEN=0x917840;PLAINLEN=0x91784c;segments +=[(COMP,0x300),(CONTAINER,0x200),(PACKED,0x4000),(DECODED,0x4000),(AVAILABLE,4),(OFFSET,8),(PACKEDLEN,16)];fillOrdinal=0

def chunk79(name,args,model):
 global fillOrdinal
 events.append(dict(name=name,args=args.copy()));patches76(name,model);write=wd if model else lambda p,v:n.pack('<I',p,v)
 if name=='FillChunk':
  plans=config.get('plan',[dict(packed=17,plain=17)]);row=plans[min(fillOrdinal,len(plans)-1)];fillOrdinal+=1;write(PACKEDLEN,row['packed']);write(PLAINLEN,row['plain']);payload=bytes((fillOrdinal*31+41+i)&255 for i in range(row['packed']));target=PACKED
 else:payload=bytes((fillOrdinal*53+19+i)&255 for i in range(args[3]));target=args[1]
 if model:
  for i,b in enumerate(payload):wb(target+i,b)
 else:n.write(target,payload)
 return 0

def compressed79(handle,destination,count):
 record=COMP+(handle-0x800)*48;parent=(rd(record)+((rd(record+0x20)+3)<<4))&0xffffffff
 if rd(record+0x28)==2:
  if not count:return 0
  available=rd(AVAILABLE);total=0;budget=0
  while count:
   budget+=1
   if budget>8192:raise ValueError('nonprogress')
   if not available:
    chunk79('FillChunk',[],True);packed=rd(PACKEDLEN);plain=rd(PLAINLEN)
    if packed==plain:
     for i in range(packed):wb(DECODED+i,rb(PACKED+i))
    else:chunk79('Decode',[PACKED,DECODED,packed,plain],True)
    available=rd(PLAINLEN);wd(OFFSET,0)
   copied=min(signed(count),signed(available));assert copied>=0
   source=DECODED+rd(OFFSET)
   for i in range(copied):wb(destination+i,rb(source+i))
   wd(OFFSET,(rd(OFFSET)+copied)&0xffffffff);total=(total+copied)&0xffffffff;available=(available-copied)&0xffffffff;count=(count-copied)&0xffffffff;destination=(destination+copied)&0xffffffff;wd(AVAILABLE,available)
  return total
 current=q(record+0x10)
 if current!=q(parent+8):public_seek78(rd(parent),current&0xffffffff,current>>32,0);wq(parent+8,q(record+0x10))
 difference=(q(record+8)+signed(rd(record+0x18))-q(record+0x10))&MASK64;clamped=max(0,signed64(difference));chosen=min(signed(count),clamped)&0xffffffff
 if not chosen:return 0
 value=reader77(rd(parent),destination,chosen)
 if signed(value)>=0:wq(record+0x10,(q(record+0x10)+value)&MASK64);wq(parent+8,q(record+0x10))
 return value
n=nm.NativeX86()
def crt_only79(mu,address,size,data):
 if address==0x6dee50:hook77(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook76);n.mu.hook_add(UC_HOOK_CODE,crt_only79);n.mu.hook_add(UC_HOOK_CODE,hook78)
def hook79(mu,address,size,data):
 if address not in[0x4f6760,0x4faea0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);name='FillChunk'if address==0x4f6760 else'Decode';args=[]if name=='FillChunk'else list(n.unpack('<4I',sp+4));value=chunk79(name,args,False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook79)
def execute79(c):
 global config,shadow,events,checks,backend,fillOrdinal
 config=c;setup77(dict(c,handle=0x400,wanted=0,size=2048,position=c.get('currentLow',17)));n.write(COMP,bytes(0x300));n.write(CONTAINER,bytes(0x200));n.write(PACKED,bytes([0xa5])*0x4000);n.write(DECODED,bytes((i*19+23)&255 for i in range(0x4000)));n.pack('<I',AVAILABLE,c.get('cached',0));n.pack('<II',OFFSET,c.get('readOffset',0),0xabcdef01);n.pack('<4I',PACKEDLEN,0,0,0,c.get('cached',0));record=COMP+c.get('index',0)*48;parent=CONTAINER+(c.get('parentIndex',0)+3)*16;current=c.get('currentLow',17)|(c.get('currentHigh',0)<<32);base=c.get('baseLow',0)|(c.get('baseHigh',c.get('currentHigh',0))<<32);parentPosition=current if not c.get('forceSeek')else(current+1)&MASK64;n.pack('<I',record,CONTAINER);n.pack('<Q',record+8,base);n.pack('<Q',record+0x10,current);n.pack('<I',record+0x18,c.get('length',31));n.pack('<III',record+0x20,c.get('parentIndex',0),1,c['mode']);n.pack('<I',parent,c.get('parentHandle',0x400));n.pack('<Q',parent+8,parentPosition)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];backend=0;fillOrdinal=0;handle=0x800+c.get('index',0);want=compressed79(handle,OUT,c['wanted']);model=snap(True);me=events.copy();mb=backend;mf=fillOrdinal;events=[];backend=0;fillOrdinal=0;actual=n.call(0x4faf60,[handle,OUT,c['wanted']],count=12000000);final=snap();ne=events.copy();nb=backend;nf=fillOrdinal
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me),('providerState',[nb,nf],[mb,mf])]:
  checks+=1
  if a!=b:
   e=dict(group=group,context=c)
   if group=='images':e['differences']=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(a,b)if x!=y][:2]
   else:e.update(native=a,model=b)
   errors.append(e)
 cases.append(dict(context=c,inputs=dict(handle=handle,destination=OUT,count=c['wanted']),initial=initial,returnValue=actual,final=final,nativeEvents=ne,providerState=dict(hostPosition=[nb&0xffffffff,nb>>32],fillOrdinal=nf)))
for mode,index,baseLow,currentLow,length,wanted in itertools.product([0,1,3],[0,3],[0,7],[0,17,31],[0,1,31,1024],[0,17,1024]):execute79(dict(mode=mode,index=index,baseLow=baseLow,currentLow=currentLow,length=length,wanted=wanted,forceSeek=bool(len(cases)&1),currentHigh=(len(cases)>>1)&1))
for result in[0,7,0x80000000,0xffffffff]:execute79(dict(mode=1,parentHandle=0x1000,currentLow=17,length=31,wanted=17,portResult=result))
for cached,offset,wanted,plan,index in itertools.product([0,17,64],[0,5],[0,1,17,64,1024],[ [dict(packed=17,plain=17)],[dict(packed=5,plain=17)],[dict(packed=5,plain=17),dict(packed=31,plain=31)] ],[0,3]):execute79(dict(mode=2,cached=cached,readOffset=offset,wanted=wanted,plan=plan,index=index))
execute79(dict(mode=2,wanted=64,plan=[dict(packed=5,plain=17)],patches={'Decode':[[PLAINLEN,4,11],[OFFSET,4,7],[AVAILABLE,4,0x12345678]]}))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=['chunkFill4f6760','decode4faea0','CRTread6dee50'],closure='Actual4faf60 container→real4f6de0/4f6c70/4fb550/4fb4f0; mode2globalcache/refill/rawcopy withchunk/decode ports')
(nm.BASE/'reports/script-phase79-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase79-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
