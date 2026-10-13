import json,struct,hashlib,base64,random,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase7-20261013-verify.py');io={'__file__':str(peer)};s=peer.read_text();exec(compile(s[:s.index('cases=[];provenance=[]')],str(peer),'exec'),io)
n=io['n'];B=io['B'];D=io['D'];PTR=D+0xba000;RECORDS=D+0x10000;AUDIO=D+0xc0000;SCRATCH=D+0xf0000;FLAGS=0x2924b10
REGIONS=[(D,0xf0000)]+io['REGIONS'][1:]+[(0x2962098,12),(0x2962a24,8),(FLAGS,32),(0x2947bdc,32),(0x2947b74,4),(0x296293c,4),(0x2962920,4),(0x8109c8,8)];io['REGIONS']=REGIONS
U=io['U'];S=io['S'];patch=io['patch'];wp=io['wp']
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
f=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
def round32(v):
 try:return f(bits(v))
 except OverflowError:return float('inf') if v>0 else float('-inf')
class Image(io['Image']):
 def __init__(self,c):
  self.regions={a:bytearray([167 if a==D else 0])*z for a,z in REGIONS};self.regions[SCRATCH]=bytearray([167])*1064
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def F(self,a,v=None):
  if v is None:return f(self.word(a))
  self.word(a,bits(round32(v)))
word=io['word'];byte=io['byte'];flt=io['word']
def half(m):return int.from_bytes(io['raw'](m,2),'big' if m.word(io['SWAP']) else 'little')
def name(m):return io['raw'](m,16)
audioHash=None;audioCalls=0;services=[];entryCounts={}
def audio(m,q):
 global audioCalls
 audioCalls+=1;audioHash.update(struct.pack('<I',0x650e40)+q+struct.pack('<I',16));return 0xffffffff
def color(v):
 x=f(v)
 if not -2147483648<=x<2147483648:return 0
 return int(x)&255
def floats(m,r,count):
 for i in range(count):m.word(r+i*4,flt(m))
def decode(m,r,v,mode):
 m.write(r,name(m));m.write(r+16,bytes([mode&255]));rate=struct.unpack('<h',struct.pack('<H',half(m)))[0]
 converted=rate if v>=28 else rate*60 if rate>0 else int(-60/rate) if rate<0 else 0;m.half(r+22,converted);m.half(r+20,half(m))
 for off in range(24,41,4):
  if v<28:m.F(r+off,struct.unpack('<h',struct.pack('<H',half(m)))[0]/60.0)
  else:m.word(r+off,flt(m))
 rate=struct.unpack('<h',struct.pack('<H',m.half(r+22)))[0]
 if rate:
  minimum=round32(1.0/rate)
  if m.F(r+28)<minimum:m.F(r+28,minimum)
 m.write(r+44,bytes([byte(m)]));m.write(r+45,bytes([byte(m)]));m.write(r+18,bytes([0 if v<35 else byte(m)]));m.write(r+19,b'\0');m.write(r+46,bytes([byte(m)]))
 if v<39:byte(m)
 m.write(r+47,b'\x01');m.write(r+1042,bytes([0 if v<40 else byte(m)]));m.word(r+48,flt(m))
 if v<6:m.word(r+52,0);m.word(r+56,bits(25.0))
 else:floats(m,r+52,2)
 m.word(r+60,0 if v<10 else flt(m));m.word(r+64,0 if v<23 else flt(m));m.word(r+68,bits(0.5) if v<24 else flt(m))
 if v<7:word(m);word(m)
 floats(m,r+72,4)
 if v<18:
  for i in range(3):flt(m)
 floats(m,r+88,3)
 if v<18:
  for i in range(3):flt(m)
 if v in [18,19] and m.byte(r+44)==6:m.F(r+84,m.F(r+84)*2);m.F(r+96,m.F(r+96)*2)
 if v<29:
  for off in [100,104,108]:m.word(r+off,0)
 else:floats(m,r+100,3)
 floats(m,r+112,14);m.half(r+168,half(m));m.write(r+170,bytes([byte(m)]));m.write(r+171,bytes([byte(m)]));floats(m,r+172,5)
 for i in range(8):
  at=r+192+i*8;m.word(at,flt(m))
  if v<33:
   for j in range(3):m.write(at+4+j,bytes([color(flt(m))]))
  else:
   for j in range(4):m.write(at+4+j,bytes([byte(m)]))
 floats(m,r+256,16)
 if v<21:m.word(r+320,bits(0.125));m.word(r+324,bits(0.125))
 else:floats(m,r+320,2)
 floats(m,r+328,2)
 for at in [336,400]:floats(m,r+at,16)
 floats(m,r+464,2)
 for at in [472,536,600]:floats(m,r+at,16)
 floats(m,r+664,4);floats(m,r+688,16);m.write(r+752,bytes([byte(m)]));m.write(r+753,bytes([0 if v<17 else byte(m)]))
 if m.byte(r+46)==7:m.write(r+753,b'\x02')
 m.write(r+754,bytes([3 if v<31 else byte(m)]))
 if v<32:
  m.write(r+755,b'\0')
  for off in [760,764,768]:m.word(r+off,bits(1.0))
 else:m.write(r+755,bytes([byte(m)]));floats(m,r+760,3)
 if v<36:m.word(r+756,bits(4.0))
 else:
  m.word(r+756,flt(m))
  if v==36 and m.F(r+756)<4:m.word(r+756,bits(4.0))
 if v<30:
  m.word(r+772,bits(1.0));m.word(r+776,bits(0.1));m.word(r+780,0)
  for at in [784,848,912]:m.word(r+at,0);m.word(r+at+4,0);m.word(r+at+8,bits(1.0));m.word(r+at+12,bits(1.0))
 else:
  floats(m,r+772,3)
  for at in [784,848,912]:floats(m,r+at,16)
 for i in range(4):m.word(r+976+i*4,0xffffffff)
 if v<23:
  for i in range(4):
   at=r+992+i*12;m.word(at,0xffffffff if v<11 else word(m));m.word(at+4,0 if v<11 else word(m));m.word(at+8,0 if v<11 else word(m))
 else:
  count=S(word(m));assert 0<=count<=4
  for i in range(count):
   q=name(m);at=r+992+i*12;m.word(at,audio(m,q));m.word(at+4,word(m));m.word(at+8,word(m))
  for i in range(count,4):m.word(r+992+i*12,0xffffffff)
 if v<16:m.write(r+1040,b'\0');m.word(r+1044,0)
 else:m.write(r+1040,bytes([(word(m)&255) if v<41 else byte(m)]));m.word(r+1044,flt(m))
 if v<25:m.write(r+1041,b'\x05');m.word(r+1052,bits(0.5))
 else:m.write(r+1041,bytes([(word(m)&255) if v<41 else byte(m)]));m.word(r+1052,flt(m))
 m.word(r+1048,0 if v<26 else flt(m));m.word(r+1056,bits(1.0));m.word(r+1060,0)
def service(m,kind,arg):services.append([kind,arg])
def load(m,c):
 original=c['mode']&255;mode=1 if original==6 else original;bank=0
 if original==5:bank=1
 elif original:
  bank=2
  while m.word(FLAGS+bank*4):
   bank+=1
   if bank>=8:return 0xffffffff
 m.word(io['MODE'],1)
 if not io['open_read'](m):return 0xffffffff
 version=S(word(m))
 if not 5<=version<42:io['close_read'](m);return 0xffffffff
 m.word(FLAGS+bank*4,1);m.word(0x2947bdc+bank*4,c['scene']);requested=S(word(m));overflow=0
 if S(m.word(0x2962098))<S(m.word(0x2962a24))+requested:overflow=S(m.word(0x2962a24))-S(m.word(0x2962098))+requested;requested=S(m.word(0x2962098))-S(m.word(0x2962a24));m.word(0x296293c,300)
 slot=1
 for i in range(max(0,requested)):
  while m.word(m.word(0x296209c)+slot*4):slot+=1
  at=m.word(0x29620a0)+slot*1064;decode(m,at,version,mode);m.write(at+17,bytes([bank]));m.word(at+680,0);m.word(at+684,0);m.word(m.word(0x296209c)+slot*4,at);service(m,'normalize',at);m.word(0x2962a24,m.word(0x2962a24)+1)
 for i in range(max(0,overflow)):decode(m,SCRATCH,version,mode)
 io['close_read'](m);service(m,'select',0x3f800000)
 if original==0:m.word(0x2962920,bank)
 elif original==5:m.word(0x8109c8,bank)
 return bank
def seed(payload,mode=6,capacity=512,swap=0):return dict(payload=base64.b64encode(payload).decode(),mode=mode,scene=D+0xf8000,writes=[wp(io['HANDLE'],0xffffffff),wp(io['SWAP'],swap),wp(0x2962098,capacity),wp(0x296209c,PTR),wp(0x29620a0,RECORDS),wp(0x2962a24,1),wp(0x2962a28,0),wp(0x2947b74,AUDIO),patch(PTR,bytes(512*4)),wp(PTR,RECORDS),patch(AUDIO,bytes(0x19000)),patch(io['PATH'],b'levels/ptl.bin\0'),wp(0x2962920,0x11111111),wp(0x8109c8,0x22222222)])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI
def observe(uc,a,z,data):
 global audioCalls
 entryCounts[hex(a)]=entryCounts.get(hex(a),0)+1
 sp=uc.reg_read(UC_X86_REG_ESP)
 if a==0x650e40:
  q=n.read(n.unpack('<I',sp+4)[0],16);audioCalls+=1;audioHash.update(struct.pack('<I',a)+q+struct.pack('<I',n.unpack('<I',sp+8)[0]));return
 if a not in [0x68cfd0,0x661f60]:return
 arg=uc.reg_read(UC_X86_REG_ESI) if a==0x68cfd0 else n.unpack('<I',sp+4)[0];service(None,'normalize' if a==0x68cfd0 else 'select',arg);uc.reg_write(UC_X86_REG_EAX,0);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x66a190,0x68df20,0x650e40,0x68cfd0,0x661f60]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
cases=[];provenance=[]
for i,path in enumerate(sorted((B/'extracted').rglob('*.PTL'))):
 raw=path.read_bytes();provenance.append(dict(path=str(path.relative_to(B)).replace('\\','/'),bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest()));c=seed(raw,[0,5,6][i%3]);c['authored']=provenance[-1]['path'];cases.append(c)
# Generate structured payload through the model's typed wire reads; original bytes independently validate the result.
rng=random.Random(20261013016)
def generated(v,swap=False):
 global name,half,byte,flt,word
 saved=[name,half,byte,flt,word];out=bytearray();fmt='>' if swap else '<'
 def nn(m):q=b'SyntheticPTL'.ljust(16,b'\0');out.extend(q);return q
 def hh(m):v=rng.choice([0,1,2,60,65535,0x8000]);out.extend(struct.pack(fmt+'H',v));return v
 def bb(m):v=rng.choice([0,1,6,7,31,128,255]);out.append(v);return v
 def ff(m):v=bits(rng.choice([-3.75,-0.0,0.0,0.125,0.5,1.0,2.25,64.0,250.0,257.25]));out.extend(struct.pack(fmt+'I',v));return v
 def ww(m):out.extend(struct.pack(fmt+'I',0));return 0
 name,half,byte,flt,word=nn,hh,bb,ff,ww;decode(Image(seed(b'')),RECORDS+1064,v,1);name,half,byte,flt,word=saved
 return struct.pack(fmt+'II',v,1)+out+struct.pack(fmt+'I',0)
for version in range(5,42):
 for swapped in [False,True]:
  for mode in [0,5,6]:c=seed(generated(version,swapped),mode,swap=int(swapped));cases.append(c)
for capacity in [1,2,3]:cases.append(seed(generated(41),6,capacity))
for mode in [0,5,6]:
 c=seed(generated(41),mode);c['writes'] += [wp(FLAGS+i*4,1) for i in range(8)];cases.append(c)
for version in [0,4,42,0xffffffff]:cases.append(seed(struct.pack('<II',version,0)))
for ret in [0,0xffffffff]:c=seed(generated(41));c['openResult']=ret;cases.append(c)
# Prepare readable audio names from exact decoder requests; table lookup itself remains original.
assetpeer=Path(__file__).with_name('world-phase15-20261013-verify.py');assets={'__file__':str(assetpeer)};asc=assetpeer.read_text();exec(compile(asc[:asc.index('rng=random.Random')],str(assetpeer),'exec'),assets)
AUDIO_NAMES=D+0xda000;audioNames=[]
def gather_audio(m,q):
 if q not in audioNames:audioNames.append(q)
 return 0xffffffff
def loaded_audio(m,q):
 global audioCalls
 audioCalls+=1;audioHash.update(struct.pack('<I',0x650e40)+q+struct.pack('<I',16));return assets['sound'](m,q,16)
for c in cases:
 audio=gather_audio;audioNames=[];io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;load(Image(c),c);assert len(audioNames)<=1600
 c['audioNamesB64']=[base64.b64encode(q).decode() for q in audioNames]
 for i,q in enumerate(audioNames):c['writes'] += [wp(AUDIO+i*64,AUDIO_NAMES+i*32),patch(AUDIO_NAMES+i*32,q)]
audio=loaded_audio
rows=[];fails=[];start=time.time()
for index,c in enumerate(cases):
 io['current']=c;m=Image(c)
 if index%20==0:print('progress',index,flush=True)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;audioHash=hashlib.sha256();audioCalls=0;services=[]
 result=n.call(0x68df20,[io['PATH'],c['mode'],c['scene']],count=100000000);actual=dict(result=result,sha256=io['vm'].digest(),audioSha256=audioHash.hexdigest(),audioCalls=audioCalls,services=services.copy(),trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;audioHash=hashlib.sha256();audioCalls=0;services=[]
 predicted=load(m,c);expected=dict(result=predicted,sha256=m.digest(),audioSha256=audioHash.hexdigest(),audioCalls=audioCalls,services=services.copy(),trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 if actual!=expected:
  diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=m.read(a+j,4).hex()) for a,z in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=m.read(a+j,4)][:25];fails.append(dict(case=index,actual=actual,expected=expected,diffs=diffs));print(json.dumps(fails[-1]));break
 c['expected']=actual;rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),entryCalls=entryCounts,authoredFiles=provenance,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase16-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase16-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==D else 0) for a,z in REGIONS],authoredFiles=provenance,cases=rows),separators=(',',':'))+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='authoredFiles'}));assert not fails
