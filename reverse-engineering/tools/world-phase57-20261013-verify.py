import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;OUT=D+0x2000;SIZE=D+0x1000;REGIONS=[(D,0x40000,167),(0x2961f00,0x400,167),(0x2921100,0x200,167),(0x2947b70,4,167),(0x2923180,0x80,167),(0x2947d00,0x200,167),(0x2948e00,0x200,167),(0x8108e8,24,0),(0x292fa00,0x600,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];word=rot['word'];patch=rot['patch'];Image=rot['Image'];case={};trace=[]
def chunk(im,d):
 im.write(d,bytes([0x52]));im.W(d+4,0);im.W(d+0x14,0);im.W(d+0x18,0);im.W(d+0x1c,0);im.W(d+0x20,0)
 for i in range(32):
  at=d+0x20+i*32
  for field,bits in [(0,0x3f800000),(4,0x40000000),(8,0x40400000),(16,0x40800000),(20,0x40a00000),(24,0x40c00000),(12,0xbf800000),(28,0x43000000)]:im.W(at+field,bits)
 im.W(d+0x420,0);return d,0x424
def S(v):return struct.unpack('<i',struct.pack('<I',U(v)))[0]
def total(im):return U(im.W(0x8108e8)+im.W(0x8108ec))
def clear(im,at,length):
 if length>0x40000:raise ValueError('unreadable reset capacity')
 im.write(at,bytes(length))
def initialize(im,c):
 if not im.W(0x2962078):return
 pointer=c['arenaPointer'];cursor=im.W(0x2962070)
 if not cursor:
  if not pointer:return
  cursor=U(im.W(pointer)+15)&0xfffffff0;im.W(pointer,cursor)
 clear(im,im.W(0x2947d94),U(total(im)*0x58));clear(im,im.W(0x2923198),U(total(im)*8));clear(im,im.W(0x2921200),U(im.W(0x8108e8)*4));clear(im,im.W(0x29211fc),U(im.W(0x8108ec)*4));clear(im,im.W(0x2961fec),U(total(im)*100))
 for countAddress,table in [(0x8108e8,0x2921200),(0x8108ec,0x29211fc),(0x8108fc,0x2962090)]:
  if countAddress==0x8108fc:im.W(0x2948e98,0);im.W(0x2947d84,0)
  i=0
  while i<S(im.W(countAddress)):
   value,size=(U(cursor+15)&0xfffffff0,0xa4c) if countAddress==0x8108fc else chunk(im,cursor);im.W(im.W(table)+i*4,value);cursor=U(cursor+size);i+=1
 if not im.W(0x2962070):im.W(0x2962070,im.W(pointer));im.W(0x2962074,cursor-im.W(pointer));im.W(pointer,cursor)
 count=U(total(im)*2);im.W(0x292fbfc,0);im.W(0x292fc00,0);i=0
 while i<S(count):im.W(im.W(0x2923198)+i*4,im.W(0x2947d94)+i*0x2c);count=U(total(im)*2);i+=1
 capacity=total(im);im.W(0x2947b70,0);i=0
 while i<S(capacity):
  offset=i*100
  for field in [0,4,8,0x58,0x5c]:im.W(im.W(0x2961fec)+offset+field,0)
  capacity=total(im);i+=1
 for at in range(0x292fd30,0x292fd44,4):im.W(at,0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x654ba0,0x5ffdc0,0x5ffe70,0x5ffe80,0x6e6950]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
ARENA=D+0x10000;POINTER=D+0x1000;ORDINARY=D+0x2000;ALT=D+0x3000;DESCRIPTORS=D+0x4000;NODES=D+0x5000;RETURNS=D+0x7000;PACKETS=D+0x8000
def seed(a=1,b=1,d=1,mode=0,alignment=0):return dict(arenaPointer=0 if mode==2 else POINTER,writes=[word(0x2962078,1),word(0x2962070,ARENA+alignment if mode==1 else 0),word(0x2962074,0x12345678),word(POINTER,ARENA+alignment),word(0x8108e8,a),word(0x8108ec,b),word(0x8108fc,d),word(0x2947d94,NODES),word(0x2923198,RETURNS),word(0x2921200,ORDINARY),word(0x29211fc,ALT),word(0x2961fec,PACKETS),word(0x2962090,DESCRIPTORS)])
cases=[seed(a,b,d,mode) for a in [0,1,2,4] for b in [0,1,2,4] for d in [0,1,2,4] for mode in [0,1,2]]
for alignment in range(32):
 for mode in [0,1]:cases.append(seed(alignment=alignment,mode=mode))
for ready in [0,1,2,0xffffffff]:c=seed();c['writes'].append(word(0x2962078,ready));cases.append(c)
c=seed(mode=1);c['arenaPointer']=0;cases.append(c)
c=seed(mode=1);c['arenaPointer']=0x2962070;cases.append(c)
rng=random.Random(2026101357)
for i in range(256):cases.append(seed(rng.randrange(9),rng.randrange(9),rng.randrange(9),rng.randrange(2),rng.randrange(32)))
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:initialize(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x654ba0,[c['arenaPointer']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase57-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase57-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
