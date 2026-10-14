"""Whole raw table configuration153 and release79 byte bodies; allocation/release boundaries explicit."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
START=0x91ee80;COUNT=0x91eea8;ONE=0x91eeac;TWO=0x91eeb0;STATE=0x91ce64;shadow={};events=[];config={};ordinals={};cases=[];checks=0;errors=[]
def rd(p):return sum(shadow[p+i]<<(i*8)for i in range(4))
def wr(p,v):
 for i in range(4):shadow[p+i]=(v>>(i*8))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in[(START,52),(STATE,4)]]
def port204(address,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];write=wr if model else lambda p,v:n.pack('<I',p,v&0xffffffff);name='Allocate'if address==0x4eef40 else'Release';ordinal=ordinals.get(name,0);ordinals[name]=ordinal+1;events.append(dict(callback=address,args=args,globals=[read(p)for p in[COUNT,ONE,TWO,STATE,START]]))
 for row in config.get('patchOn'+name,[]):
  if row['ordinal']==ordinal:
   for p,v in row['patches']:write(p,v)
 return config.get('allocations',[0x10101000,0x10102000])[ordinal]if name=='Allocate'else 0

def hook204(mu,address,size,data):
 if address not in[0x4eef40,0x4ef280]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<3I',sp+4));result=port204(address,args,False);mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook204)
def run204(c):
 global config,shadow,events,ordinals,checks
 config=c;n.write(START,bytes((i*37+11)&255 for i in range(52)));n.pack('<3I',COUNT,c['old'],c['one'],c['two']);n.pack('<I',STATE,0x12345678);n.pack('<I',START,0x87654321);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinals={};method=c['method']
 if method=='Configure':
  value=c['value']
  if value!=rd(COUNT):
   if rd(ONE):port204(0x4ef280,[rd(ONE),0x75e978,0xa58],True)
   if rd(TWO):port204(0x4ef280,[rd(TWO),0x75e978,0xa59],True)
   wr(COUNT,value);a=port204(0x4eef40,[(value<<4)&0xffffffff,0x75e978,0xa5d],True);wr(ONE,a);b=port204(0x4eef40,[(rd(COUNT)<<4)&0xffffffff,0x75e978,0xa5e],True);wr(TWO,b)
  wr(STATE,0);wr(START,0)
 else:
  if rd(ONE):port204(0x4ef280,[rd(ONE),0x75e978,0xa68],True);wr(ONE,0)
  if rd(TWO):port204(0x4ef280,[rd(TWO),0x75e978,0xa6d],True);wr(TWO,0)
  wr(COUNT,0)
 expected=snap(True);me=events.copy();events=[];ordinals={};n.call(0x4f0930 if method=='Configure'else 0x4f09d0,[c['value']]if method=='Configure'else[],count=1000000);final=snap();ne=events.copy()
 for group,a,b in [('images',final,expected),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(value=c.get('value',0)),initial=initial,final=final,nativeEvents=ne))
for method,old,value,one,two,allocations in itertools.product(['Configure','Release'],[0,1,7,0xffffffff],[0,1,16,0xffffffff,0x80000000],[0,0x11223344],[0,0x55667788],[[0,0],[0x10101000,0x10102000]]):run204(dict(method=method,old=old,value=value,one=one,two=two,allocations=allocations))
for method in['Configure','Release']:
 run204(dict(method=method,old=1,value=7,one=0x11223344,two=0,patchOnRelease=[dict(ordinal=0,patches=[[TWO,0x12340000],[ONE,0xffffffff],[COUNT,9],[STATE,5],[START,6]])],patchOnAllocate=[dict(ordinal=0,patches=[[COUNT,3],[ONE,0xffffffff],[TWO,0x87650000]]),dict(ordinal=1,patches=[[ONE,0xabcd1234],[STATE,7],[START,8]])]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=['4EEF40 allocation','4EF280 release'],rawEntryConsumers=['0x4f0930','0x4f09d0'],closure='Whole configuration/release bodies withexact allocation/free events, uintsizewrap, equalityskip, liveglobalreloads and boundedcallbackpatches; allocator children explicit')
(nm.BASE/'reports/script-phase204-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase204-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
