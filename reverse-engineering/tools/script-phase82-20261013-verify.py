"""Original symbol/distance lookups and incremental ring decoder, with original bit collection."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase81-20261013-verify.py').read_text().split('\nfor count,available')[0])
SYM=0x913fa8;SMALL=0x8cf398;SLEN=0x90f598;PLEN=0x91ce68;LEFT=0x2982740;RIGHT=0x2982f40;INDEX=0x91ef34
segments=common+[(SYM,8192),(SMALL,512),(SLEN,510),(PLEN,24),(LEFT,4096),(RIGHT,4096),(INDEX,4),(RING,8192)]
def ww(p,v):wb(p,v);wb(p+1,v>>8)
def rw(p):return rb(p)|(rb(p+1)<<8)
def table82(name,args,model):
 events.append(dict(name=name,args=args));write=wd if model else lambda p,v:n.pack('<I',p,v);word=ww if model else lambda p,v:n.pack('<H',p,v)
 if name=='Small':
  for i in range(256):word(SMALL+i*2,config.get('category',0))
  for i in range(24):
   if model:wb(PLEN+i,4)
   else:n.write(PLEN+i,b'\4')
 else:
  for i in range(4096):word(SYM+i*2,config.get('symbol',17))
  for i in range(510):
   if model:wb(SLEN+i,8)
   else:n.write(SLEN+i,b'\10')

def leaf82(node,threshold,bits,mask):
 budget=0
 while node>=threshold:
  budget+=1;assert budget<=32;node=rw((RIGHT if bits&mask else LEFT)+node*2);mask>>=1
 return node

def symbol82():
 if not rd(BLOCKLEFT):
  count=rd(ACC)>>16;bits81(16);wd(BLOCKLEFT,count);table82('Small',[19,5,3],True);table82('Symbols',[],True);table82('Small',[14,4,0xffffffff],True)
 bits=rd(ACC);wd(BLOCKLEFT,(rd(BLOCKLEFT)-1)&0xffffffff);node=leaf82(rw(SYM+(bits>>20)*2),510,bits,0x80000);bits81(rb(SLEN+node));return node

def distance82():
 bits=rd(ACC);node=leaf82(rw(SMALL+(bits>>24)*2),14,bits,0x800000);bits81(rb(PLEN+node))
 if not node:return 0
 if node==1:return 1
 extra=node-1;tail=rd(ACC)>>((32-extra)&31);bits81(extra);return ((1<<(extra&31))+tail)&0xffffffff

def block82(ring,count):
 output=0;left=(rd(MATCHLEFT)-1)&0xffffffff;wd(MATCHLEFT,left)
 if signed(left)>=0:
  index=rd(INDEX)
  while True:
   value=rb(ring+index);index=(index+1)&8191;wb(ring+output,value);output+=1
   if output==count:wd(MATCHLEFT,left);wd(INDEX,index);return
   left=(left-1)&0xffffffff
   if signed(left)<0:break
  wd(MATCHLEFT,left);wd(INDEX,index)
 while output<count:
  symbol=symbol82()
  if symbol<=255:wb(ring+output,symbol);output+=1;continue
  distance=distance82();index=(output-distance-1)&8191;left=(symbol-254)&0xffffffff;wd(INDEX,index);wd(MATCHLEFT,left)
  if signed(left)<0:continue
  while True:
   value=rb(ring+index);index=(index+1)&8191;wb(ring+output,value);output+=1;wd(INDEX,index)
   if output==count:return
   left=(left-1)&0xffffffff;wd(MATCHLEFT,left)
   if signed(left)<0:break

n=nm.NativeX86()
def hook82(mu,address,size,data):
 if address not in[0x4f9570,0x4f96b0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);name='Small'if address==0x4f9570 else'Symbols';args=list(n.unpack('<3I',sp+4))if name=='Small'else[];table82(name,args,False);mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook82)
def execute82(c):
 global shadow,checks,events,config
 config=c
 for p,z in segments:n.write(p,bytes(z))
 n.write(DATA,bytes((i*37+11)&255 for i in range(64)));n.write(RING,bytes((i*19+23)&255 for i in range(8192)));n.pack('<I',CURSOR,DATA);n.pack('<I',PACKEDLEFT,c.get('packed',17));n.pack('<I',ACC,c.get('bits',0x12345678));n.pack('<I',AVAIL,c.get('available',0));n.pack('<I',BYTE,0xd3);n.pack('<I',BLOCKLEFT,c.get('blockLeft',10000));n.pack('<I',MATCHLEFT,c.get('pending',0));n.pack('<I',INDEX,c.get('index',8191));n.write(SLEN,bytes([8])*510);n.write(PLEN,bytes([4])*24);n.write(SYM,struct.pack('<H',c.get('symbol',17))*4096);n.write(SMALL,struct.pack('<H',c.get('category',0))*256)
 if c.get('symbolTree'):
  n.write(SYM,struct.pack('<H',510)*4096);n.pack('<H',LEFT+510*2,17);n.pack('<H',RIGHT+510*2,511);n.pack('<H',LEFT+511*2,31);n.pack('<H',RIGHT+511*2,509)
 if c.get('distanceTree'):
  n.write(SMALL,struct.pack('<H',14)*256);n.pack('<H',LEFT+14*2,0);n.pack('<H',RIGHT+14*2,15);n.pack('<H',LEFT+15*2,1);n.pack('<H',RIGHT+15*2,13)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];method=c['method']
 if method=='Symbol':want=symbol82();address=0x4f9820;args=[];regs={}
 elif method=='Distance':want=distance82();address=0x4f5f30;args=[];regs={}
 else:want=None;block82(RING,c['count']);address=0x4fa320;args=[c['count']];regs={UC_X86_REG_EDI:RING}
 model=snap(True);me=events.copy();events=[];actual=n.call(address,args,regs,count=12000000);final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  if group=='return'and want is None:continue
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else [y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(method=method,context=c,inputs=dict(ring=RING,count=c.get('count',0)),initial=initial,returnValue=actual if want is not None else None,final=final,nativeEvents=ne))
for symbol,bits,init,tree in itertools.product([0,17,255,256,509],[0,0x12345678,0xffffffff],[False,True],[False,True]):execute82(dict(method='Symbol',symbol=symbol,bits=bits,blockLeft=0 if init else 10000,symbolTree=tree))
for category,bits,tree in itertools.product(range(14),[0,0x12345678,0xffffffff],[False,True]):execute82(dict(method='Distance',category=category,bits=bits,distanceTree=tree))
for symbol,category,count,pending,index in itertools.product([17,256,257,509],[0,1,13],[1,17,257],[0,3],[0,8191]):execute82(dict(method='Block',symbol=symbol,category=category,count=count,pending=pending,index=index))
for symbol in[17,256,509]:execute82(dict(method='Block',symbol=symbol,category=3,count=257,blockLeft=0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=3,ports=['smallLengthReader4f9570','symbolLengthReader4f96b0'],closure='Original4fa320 block→original4f9820/4f5f30→original4f5d00; only table setup readers normalized')
(nm.BASE/'reports/script-phase82-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase82-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
