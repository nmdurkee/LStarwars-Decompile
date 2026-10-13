import json,struct,hashlib,base64,random,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase7-20261013-verify.py');scope={'__file__':str(peer)};code=peer.read_text();exec(compile(code[:code.index('cases=[];provenance=[]')],str(peer),'exec'),scope)
n=scope['n'];B=scope['B'];D=scope['D'];REC=0x2913a58;U=scope['U'];S=scope['S'];wp=scope['wp'];patch=scope['patch'];vm=scope['vm'];REGIONS=[(D,0xc0000)]+[(a,z) for a,z in scope['REGIONS'] if a!=D]+[(REC,128*376),(0x291f688,128),(0x29208d0,128),(0x2947b74,4),(0x2962098,8),(0x2924b10,32),(0x8101b8,4)];scope['REGIONS']=REGIONS
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
assetHash=None;assetCounts={};totals={}
def emit(code,name,a=0,b=0):
 assetHash.update(struct.pack('<I',code)+name+struct.pack('<II',U(a),U(b)));key=hex(code);assetCounts[key]=assetCounts.get(key,0)+1
# Observation only: no computational lookup is intercepted or rewritten.
def observe(uc,code,z,data):
 totals[hex(code)]=totals.get(hex(code),0)+1
 if code==0x64ba10:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[n.unpack('<I',sp+4+i*4)[0] for i in range(3 if code==0x658330 else 2)];emit(code,n.read(args[0],16),args[1],args[2] if code==0x658330 else 0)
for address in [0x64ba10,0x6488e0,0x658330,0x658490,0x650e40]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
class Image(scope['Image']):
 def __init__(self,c):
  self.regions={a:bytearray([167 if a==REC else 0])*z for a,z in REGIONS}
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def half(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
def word(m):return scope['word'](m)
def byte(m):return scope['byte'](m)
def half(m):return int.from_bytes(scope['raw'](m,2),'big' if m.word(scope['SWAP']) else 'little')
def name(m):return scope['raw'](m,16)
def sprite(m,q,scene):
 assert scene==0;emit(0x6488e0,q,scene);return 9999 if q.split(b'\0',1)[0]==b'NULL instance' else -1
def effect_name(m,q):
 bank=m.word(0x8101b8);emit(0x658330 if bank==0xffffffff else 0x658490,q,0 if bank==0xffffffff else bank);return 0xffffffff
def effect(m):return effect_name(m,name(m))
def sound(m,q):emit(0x650e40,q,16);return 0xffffffff
def eq16(a,b):
 for x,y in zip(a,b):
  if 97<=x<=122:x-=32
  if 97<=y<=122:y-=32
  if x!=y:return False
  if not x or not y:return True
 return True
def decode(m,r,v,group):
 m.write(r,name(m))
 if v<6:m.write(r+160,bytes([0 if v<2 else byte(m)])+b'\xff'*7)
 else:m.write(r+160,scope['raw'](m,8))
 for slot in range(1 if v<6 else 8):
  q=name(m);m.write(r+16+slot*16,q);idx=r+144+slot*2;m.half(idx,65535);selector=m.read(r+160+slot,1)[0]
  if selector in [0,1]:
   wanted=group if selector==0 else 0
   for i in range(32):
    if m.word(0x291f688+i*4)==wanted:m.half(idx,sprite(m,q,m.word(0x29208d0+i*4)))
    if m.half(idx)!=65535:m.write(r+168+slot,bytes([i]));break
  if m.half(idx)==65535 and q[0]:m.half(idx,9998)
 m.write(r+176,bytes([sum(m.half(r+144+i*2) not in [65535,9999] for i in range(8))]));m.write(r+177,bytes([0 if v<6 else byte(m)]))
 m.word(r+180,0x3f800000 if v<16 else word(m));m.word(r+184,0x3f800000 if v<16 else word(m));m.word(r+188,word(m));m.word(r+192,0 if v<14 else word(m))
 for at in range(196,205,4):m.word(r+at,word(m))
 m.word(r+208,0x3f400000 if v<8 else word(m))
 for at in range(212,249,4):m.word(r+at,word(m))
 for at in range(252,273,4):m.word(r+at,struct.unpack('<h',struct.pack('<H',half(m)))[0] if v<13 else word(m))
 flags=word(m);m.word(r+276,flags|(16 if m.half(r+144)==9999 else 0))
 for at in [280,284,296]:m.word(r+at,0xffffffff)
 if v<3:m.word(r+288,0x42700000);m.word(r+292,0x42700000)
 elif v<5:
  selector=byte(m);q=name(m)
  if selector==0:m.word(r+280,effect_name(m,q))
  elif selector==1:m.word(r+296,effect_name(m,q))
  m.word(r+288,word(m));m.word(r+292,0x42700000)
 elif v<9:m.word(r+280,effect(m));m.word(r+296,effect(m));m.word(r+288,word(m));m.word(r+292,0x42700000)
 else:m.word(r+280,effect(m));m.word(r+284,effect(m));m.word(r+296,effect(m));m.word(r+288,word(m));m.word(r+292,word(m))
 if v<4:m.word(r+300,0xffffffff);m.word(r+324,0xffffffff)
 else:m.word(r+324,effect(m));m.word(r+300,effect(m))
 linked=0xffffffff
 if v<12:m.write(r+308,b'\0')
 else:
  m.write(r+308,name(m))
  if m.read(r+308,1)[0]:
   for i in range(128):
    if eq16(m.read(r+308,16),m.read(REC+i*376,16)):linked=i;break
 m.word(r+304,linked)
 if v<7:
  for i in range(4):m.word(r+328+i*4,0xffffffff);m.write(r+344+i,b'\0')
 else:
  for i in range(4):m.word(r+328+i*4,sound(m,name(m)))
  m.write(r+344,scope['raw'](m,4))
 m.word(r+348,0x41c80000 if v<10 else word(m))
 for at in range(352,361,4):m.word(r+at,0x3f800000 if v<15 else word(m))
 m.word(r+368,0x3f800000);m.word(r+372,0)
def seed(payload,bank=0xffffffff,authored=None):
 return dict(payload=base64.b64encode(payload).decode(),openResult=1,authored=authored,writes=[wp(scope['HANDLE'],0xffffffff),wp(0x2947b74,D+0x50000),wp(0x8101b8,bank),patch(scope['PATH'],b'levels\\authored.par\0')])
cases=[];provenance=[]
for f in sorted((B/'extracted').rglob('*.PAR')):
 payload=f.read_bytes();p=str(f.relative_to(B)).replace('\\','/');provenance.append(dict(path=p,bytes=len(payload),sha256=hashlib.sha256(payload).hexdigest()));cases.append(seed(payload,authored=p))
# Structured bounded records cover every version gate, including versions absent in authored files.
rng=random.Random(0x64ba10)
def packed_name(value):return value.encode().ljust(16,b'\0')[:16]
def record(v,swap=False):
 out=packed_name('RECORD');fmt='>' if swap else '<';f=lambda:struct.pack(fmt+'I',rng.choice([0,0x80000000,0x3f800000,0xbf800000,0x7fc01234,0x7f800000,0xff800000]));q=lambda:packed_name(rng.choice(['','NULL_instance','NULL instance','missing']))
 if v>=6:out+=bytes(rng.randrange(4) for i in range(8))
 elif v>=2:out+=bytes([rng.randrange(4)])
 for i in range(1 if v<6 else 8):out+=q()
 if v>=6:out+=bytes([rng.randrange(256)])
 if v>=16:out+=f()+f()
 out+=f()
 if v>=14:out+=f()
 out+=f()*3
 if v>=8:out+=f()
 out+=b''.join(f() for i in range(10))
 out+=b''.join(struct.pack(fmt+'H',rng.randrange(65536)) if v<13 else struct.pack(fmt+'I',rng.randrange(0x100000000)) for i in range(6));out+=struct.pack('<I',rng.randrange(0x100000000))
 if 3<=v<5:out+=bytes([rng.randrange(4)])+q()+f()
 elif 5<=v<9:out+=q()+q()+f()
 elif v>=9:out+=q()+q()+q()+f()+f()
 if v>=4:out+=q()+q()
 if v>=12:out+=packed_name(rng.choice(['RECORD','','missing']))
 if v>=7:out+=q()+q()+q()+q()+bytes(rng.randrange(256) for i in range(4))
 if v>=10:out+=f()
 if v>=15:out+=f()+f()+f()
 return out
for v in range(1,17):
 for i in range(4):cases.append(seed(struct.pack('<II',v,2)+record(v)+record(v)+struct.pack('<I',0),bank=[0xffffffff,2,0x102,0][i]))
for v in range(1,17):
 c=seed(struct.pack('>II',v,1)+record(v,True)+struct.pack('>I',0));c['writes'].append(wp(scope['SWAP'],1));cases.append(c)
start=time.time();rows=[];fails=[];decoded=0
for index,c in enumerate(cases):
 scope['current']=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 scope['trace']=[];scope['filepos']=scope['opens']=scope['reads']=scope['closes']=0;assetHash=hashlib.sha256();assetCounts={}
 n.call(0x6211c0,[1]);assert n.call(0x621270,[scope['PATH'],0])==1;version=n.call(0x6217e0);count=n.call(0x6217e0);assert 1<=version<=16 and count<=128
 for i in range(count):n.write(REC+i*376+144,b'\xff'*16);n.call(0x64ba10,[REC+i*376,version,1],count=30000000)
 position=n.unpack('<I',scope['POS'])[0];n.call(0x6213e0)
 observed=dict(version=version,count=count,sha256=vm.digest(),assetSha256=assetHash.hexdigest(),assetCalls=assetCounts.copy(),bufferPosition=position,trace=scope['trace'].copy(),state=dict(filePosition=scope['filepos'],opens=scope['opens'],reads=scope['reads'],closes=scope['closes']))
 scope['trace']=[];scope['filepos']=scope['opens']=scope['reads']=scope['closes']=0;assetHash=hashlib.sha256();assetCounts={};m.word(scope['MODE'],1);assert scope['open_read'](m)==1;ver=word(m);amount=word(m)
 for i in range(amount):m.write(REC+i*376+144,b'\xff'*16);decode(m,REC+i*376,ver,1)
 pos=m.word(scope['POS']);scope['close_read'](m);prediction=dict(version=ver,count=amount,sha256=m.digest(),assetSha256=assetHash.hexdigest(),assetCalls=assetCounts.copy(),bufferPosition=pos,trace=scope['trace'].copy(),state=dict(filePosition=scope['filepos'],opens=scope['opens'],reads=scope['reads'],closes=scope['closes']))
 if observed!=prediction:fails.append(dict(case=index,observed=observed,prediction=prediction));print(json.dumps(fails[-1]));break
 c['expected']=observed;rows.append(c);decoded+=count
report=dict(binarySha256=n.sha256,cases=len(rows),recordCalls=decoded,mismatches=len(fails),nativeLookupCalls=totals,nativeReaderEntryCalls=scope['calls'].copy(),authoredFiles=provenance,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase11-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase11-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==REC else 0) for a,z in REGIONS],authoredFiles=provenance,cases=rows),separators=(',',':'))+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='authoredFiles'}));assert not fails
