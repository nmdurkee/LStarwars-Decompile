"""Original LZ2K length readers and complete decoder with no body adapters."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase82-20261013-verify.py').read_text().split('\nfor symbol,bits')[0])
exec(Path(__file__).with_name('script-phase83-20261013-verify.py').read_text().split('\nfor bits in')[0].split('def rw(p):')[1].split('def execute83')[0].join(['def rw(p):','']))
#Use fresh native instance: no symbol/block/table hooks from earlier proofs.
n=nm.NativeX86();OUT=D+0x8000;segments=common+[(SYM,8192),(SMALL,512),(SLEN,510),(PLEN,24),(LEFT,4096),(RIGHT,4096),(INDEX,4),(RING,8192),(OUT,17000),(DATA,512)];cases=[];checks=0;errors=[]
def zero84(p,z):
 for i in range(z):wb(p+i,0)
def small84(entries,countBits,special):
 count=0;leaf=0
 if countBits:
  count=rd(ACC)>>((32-countBits)&31);bits81(countBits)
  if not count:leaf=rd(ACC)>>((32-countBits)&31);bits81(countBits)
 if not count:
  zero84(PLEN,entries)
  for i in range(256):ww(SMALL+i*2,leaf)
  return
 output=0
 while True:
  bits=rd(ACC);length=bits>>29
  if length==7:
   mask=0x10000000
   while bits&mask:mask>>=1;length+=1;assert mask
  bits81(3 if length<7 else length-3);wb(PLEN+output,length);output+=1
  if output==special:zeros=rd(ACC)>>30;bits81(2);zero84(PLEN+output,zeros);output+=zeros
  if output>=count:break
 if output<entries:zero84(PLEN+output,entries-output)
 build83(entries,PLEN,8,SMALL)
def symbols84():
 count=rd(ACC)>>23;bits81(9)
 if not count:
  leaf=rd(ACC)>>23;bits81(9);zero84(SLEN,510)
  for i in range(4096):ww(SYM+i*2,leaf)
  return
 output=0
 while True:
  bits=rd(ACC);code=leaf82(rw(SMALL+(bits>>24)*2),19,bits,0x800000);bits81(rb(PLEN+code))
  if code<=2:
   zeros=1
   if code==1:zeros=(rd(ACC)>>28)+3;bits81(4)
   elif code==2:zeros=(rd(ACC)>>23)+20;bits81(9)
   zero84(SLEN+output,zeros);output+=zeros
  else:wb(SLEN+output,code-2);output+=1
  if output>=count:break
 if output<510:zero84(SLEN+output,510-output)
 build83(510,SLEN,12,SYM)
def table82(name,args,model):
 assert model
 if name=='Small':small84(args[0],args[1],signed(args[2]))
 else:symbols84()
def bitstring(value,count):return format(value,'0'+str(count)+'b')if count else''
def stream(bits):bits+='0'*((-len(bits))%8);return bytes(int(bits[i:i+8],2)for i in range(0,len(bits),8))
def smallStream(entries,countBits,special,lengths):
 bits=bitstring(len(lengths),countBits);i=0
 while i<len(lengths):
  length=lengths[i];bits+=bitstring(length,3)if length<7 else'111'+'1'*(length-7)+'0';i+=1
  if i==special:
   zeros=0
   while i+zeros<len(lengths)and lengths[i+zeros]==0 and zeros<3:zeros+=1
   bits+=bitstring(zeros,2);i+=zeros
 return bits

def execute84(c,bits):
 global shadow,checks,config,events
 config=c
 for p,z in segments:n.write(p,bytes(z))
 n.write(RING,bytes((i*19+23)&255 for i in range(8192)));n.write(OUT,bytes([0xa5])*17000);payload=stream(bits)+bytes(16);n.write(DATA,payload);n.pack('<I',CURSOR,DATA);n.pack('<I',PACKEDLEFT,len(payload));n.pack('<I',GATE,1);n.call(0x4f5d00,[32]);method=c['method']
 if method=='Symbols':
  n.write(SMALL,struct.pack('<H',c.get('code',3))*256);n.write(PLEN,bytes(24))
  if c.get('pair'):
   n.write(SMALL,struct.pack('<H',3)*128+struct.pack('<H',4)*128);n.write(PLEN+3,b'\1\1')
  if c.get('tree'):
   n.write(SMALL,struct.pack('<H',19)*256);n.pack('<H',LEFT+38,3);n.pack('<H',RIGHT+38,4);n.write(PLEN+3,b'\11\11')
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[]
 if method=='Small':small84(c['entries'],c['countBits'],c['special']);address=0x4f9570;args=[c['entries'],c['countBits'],c['special']]
 elif method=='Symbols':symbols84();address=0x4f96b0;args=[]
 else:want=wrapper81(DATA,OUT,len(payload),c['plain']);address=0x4faea0;args=[DATA,OUT,len(payload),c['plain']]
 model=snap(True);actual=n.call(address,args,count=15000000);final=snap();checks+=1
 if final!=model:errors.append(dict(context=c,differences=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(final,model)if x!=y][:1]))
 if method=='Decode':
  checks+=1
  if actual!=want:errors.append(dict(context=c,native=actual,model=want))
 cases.append(dict(method=method,context=c,inputs=dict(source=DATA,destination=OUT,packed=len(payload),plain=c.get('plain',0)),initial=initial,returnValue=actual if method=='Decode'else None,final=final))
#Restore actual block model in wrapper, replacing the earlier normalized block callback.
def block81(ring,count,model):assert model;block82(ring,count)
for entries,countBits,special in[(19,5,3),(14,4,-1),(0,0,-1),(19,0,3)]:
 for leaf in[0,1,13,18,31]:
  if countBits and leaf>=(1<<countBits):continue
  execute84(dict(method='Small',entries=entries,countBits=countBits,special=special),bitstring(0,countBits)+bitstring(leaf,countBits))
for lengths,entries,special in[([1,1],14,-1),([1,2,2],19,3),([1,2,0,0,2],19,3),(list(range(1,16))+[16,16],19,3),([3]*8,14,-1)]:
 execute84(dict(method='Small',entries=entries,countBits=5 if entries==19 else 4,special=special),smallStream(entries,5 if entries==19 else 4,special,lengths))
for leaf in[0,17,255,256,509,511]:execute84(dict(method='Symbols'),bitstring(0,9)+bitstring(leaf,9))
for depth in range(1,9):execute84(dict(method='Symbols',code=depth+2),bitstring(1<<depth,9))
for code,count,extra in[(0,7,''),(1,7,'0000'*3),(2,31,'000000000'*2)]:execute84(dict(method='Symbols',code=code),bitstring(count,9)+extra)
execute84(dict(method='Symbols',pair=True),bitstring(3,9)+'011')
execute84(dict(method='Symbols',tree=True),bitstring(3,9)+'000000000'+'000000001'*2)
for symbol,category,plain in itertools.product([0,17,255,256,257,509],[0,1,13],[0,1,17,8192,8193,16384]):
 bits=bitstring(65535,16)+bitstring(0,5)+bitstring(0,5)+bitstring(0,9)+bitstring(symbol,9)+bitstring(0,4)+bitstring(category,4)
 execute84(dict(method='Decode',plain=plain),bits)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=2,ports=[],closure='Original4f9570/4f96b0→4f5d00/4f6000; complete4faea0→4fa320→4f9820/4f5f30→all table/bit/memory children, no adapters')
(nm.BASE/'reports/script-phase84-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase84-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
