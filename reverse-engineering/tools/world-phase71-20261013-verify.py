import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167),(0x971690,0x40,0),(0x97396c,4,0),(0x9209d8,24,0),(0x91ef80,8,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))

import math
P=D+0x1000;A=D+0x2000;B0=D+0x3000;REC=D+0x4000;TICKS=D+0x6000;LABELS=D+0x7000;MODES=D+0x8000;PROBE=D+0x1fff0;SHIM=0x10300000;IMPORT=0x10301000
n.mu.mem_map(SHIM,0x2000);code=bytes.fromhex('ff742404e8')+struct.pack('<i',0x4f3ca0-(SHIM+9))+bytes.fromhex('83c404d91d')+struct.pack('<I',PROBE)+b'\xc3';n.write(SHIM,code);n.write(IMPORT,b'\xc3');n.write(0x751110,struct.pack('<I',IMPORT))
def counter(im,c,trace):
 trace.append([0x751110,[]])
 for p in c.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 lo,hi=c['counter'];bl=im.W(0x9209e0);bh=im.W(0x9209e4)
 if S(hi)>S(bh) or hi==bh and lo>bl:return [U(lo-bl),U(hi-bh-(lo<bl))]
 total=((hi<<32)|lo)+0x7fffffffffffffff-((bh<<32)|bl);return [U(total),U(total>>32)]
def duration(low,high,fl,fh):
 a=N(S(high))*N(4294967295)+N(low);b=N(fh)*N(4294967295)+N(fl)
 if not b.v:return 0xffc00000 if not a.v else (0xff800000 if a.v<0 else 0x7f800000)
 return (N(rot['quant'](a.v/b.v,64))*N(1000000)).store()
def trunc(w):
 f=F(w)
 return 0 if not math.isfinite(f) or f>=2**63 or f< -2**63 else U(int(f))
def apply(im,c):
 tr=[];e=c['entry'];args=c['args'];result=None
 if e==0x4ffb20 or e==0x4f3bd0:
  value=counter(im,c,tr);low=args[0];high=args[1] if e==0x4ffb20 else U(low+4);im.W(low,value[0]);im.W(high,value[1])
 elif e==0x4ffb90:
  v=im.W(0x91ef80);im.W(args[0],v);im.W(args[1],im.W(0x91ef84))
 elif e==0x4f3bf0:
  dest,a,b=args;lo=im.W(a);lb=im.W(b);im.W(dest,U(lo-lb));im.W(dest+4,U(im.W(a+4)-im.W(b+4)-(lo<lb)))
 elif e==0x4f3ca0:
  fl=im.W(0x91ef80);fh=im.W(0x91ef84);result=duration(im.W(args[0]),im.W(args[0]+4),fl,fh);im.W(PROBE,result)
 elif e==0x5d8400:
  group,slot,label=args
  if im.W(0x97396c):
   record=im.W(U(0x9716a4+group*4));dest=U(im.W(record+0x10)+slot*8);v=counter(im,c,tr);im.W(dest,v[0]);im.W(dest+4,v[1]);im.W(U(im.W(record+0x24)+slot*4),label)
 else:
  group,slot=args;result=0
  if im.W(0x97396c):
   record=im.W(U(0x9716a4+group*4));now=counter(im,c,tr);start=U(im.W(record+0x10)+slot*8);low=im.W(start);delta=[U(now[0]-low),U(now[1]-im.W(start+4)-(now[0]<low))];w=duration(*delta,im.W(0x91ef80),im.W(0x91ef84));mode=im.W(record+0x20);dest=U(im.W(U(record+U(3-im.W(U(mode+slot*4)))*4))+slot*4);im.W(dest,U(im.W(dest)+trunc(w)));mode=im.W(record+0x20);dest=U(im.W(U(record+U(3-im.W(U(mode+slot*4)))*4))+slot*4);result=im.W(dest)
 return result,tr
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={};nativeTrace=[];current={}
def hook(uc,a,z,user):
 if a in [0x5d8400,0x5d8440,0x4f3bd0,0x4f3bf0,0x4f3ca0,0x4ffb20,0x4ffb90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=IMPORT:return
 nativeTrace.append([0x751110,[]]);sp=uc.reg_read(UC_X86_REG_ESP);dest=n.unpack('<I',sp+4)[0]
 for p in current.get('mutations',[]):n.write(p['address'],base64.b64decode(p['data']))
 n.write(dest,struct.pack('<2I',*current['counter']));uc.reg_write(UC_X86_REG_EAX,1);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+8)
n.mu.hook_add(UC_HOOK_CODE,hook)
def seed(e):
 c=dict(entry=e,args={0x4ffb20:[P,P+4],0x4ffb90:[P,P+4],0x4f3bd0:[P],0x4f3bf0:[P,A,B0],0x4f3ca0:[P],0x5d8400:[0,0,0xdeadbeef],0x5d8440:[0,0]}[e],counter=[100,0],writes=[word(0x97396c,1),word(0x9716a4,REC),word(0x9209e0,0),word(0x9209e4,0),word(0x91ef80,1000000),word(0x91ef84,0),word(REC+0x10,TICKS),word(REC+0x20,MODES),word(REC+0x24,LABELS),patch(TICKS,struct.pack('<8I',0,0,0,0,0,0,0,0)),patch(MODES,struct.pack('<4I',0,1,2,3))])
 for i in range(4):c['writes'] += [word(REC+i*4,D+0x9000+i*0x100),patch(D+0x9000+i*0x100,struct.pack('<4I',10,20,30,40))]
 c['writes'] += [patch(P,struct.pack('<2I',1234,0)),patch(A,struct.pack('<2I',0xffffffff,0x80000000)),patch(B0,struct.pack('<2I',1,0xffffffff))];return c
cases=[];rng=random.Random(2026101371)
words=[0,1,0xffffffff,0x80000000,0x7fffffff]
for e in [0x4ffb20,0x4f3bd0]:
 for hi in words:
  for lo in words:
   for bh in words:
    c=seed(e);c['counter']=[lo,hi];c['writes'] += [word(0x9209e4,bh),word(0x9209e0,rng.choice(words))];cases.append(c)
 for shift in range(-4,5):
  c=seed(e);c['args']=[0x9209e0] if e==0x4f3bd0 else [0x9209e0,0x9209e0+shift];cases.append(c)
for dest in [P,A,B0]+[A+s for s in range(-8,9)]+[B0+s for s in range(-8,9)]:
 for i in range(8):
  c=seed(0x4f3bf0);c['args'][0]=dest;c['writes'] += [patch(A,struct.pack('<2I',rng.getrandbits(32),rng.getrandbits(32))),patch(B0,struct.pack('<2I',rng.getrandbits(32),rng.getrandbits(32)))];cases.append(c)
for high in words:
 for low in words:
  for freq in [(0,0),(1,0),(1000000,0),(0,1),(0xffffffff,0xffffffff),(0x80000000,0x80000000)]:
   c=seed(0x4f3ca0);c['writes'] += [patch(P,struct.pack('<2I',low,high)),patch(0x91ef80,struct.pack('<2I',*freq))];cases.append(c)
for low in [P,0x91ef80,0x91ef84]:
 for high in [P+4,0x91ef80,0x91ef84]:
  c=seed(0x4ffb90);c['args']=[low,high];c['writes'] += [word(0x91ef80,0x12345678),word(0x91ef84,0x87654321)];cases.append(c)
for e in [0x5d8400,0x5d8440]:
 for gate in [0,1,0xffffffff]:
  for mode in range(4):
   for slot in range(4):
    c=seed(e);c['args'][1]=slot;c['counter']=[rng.getrandbits(32),rng.getrandbits(32)];c['writes'] += [word(0x97396c,gate),word(MODES+slot*4,mode),patch(TICKS+slot*8,struct.pack('<2I',rng.getrandbits(32),rng.getrandbits(32)))];cases.append(c)
for i in range(128):
 c=seed(0x5d8440);c['counter']=[rng.getrandbits(32),rng.getrandbits(32)];c['writes'] += [patch(0x91ef80,struct.pack('<2I',rng.getrandbits(32),rng.getrandbits(32)))];cases.append(c)
# Counter import mutates cached-record roots before wrappers reload them.
for e in [0x5d8400,0x5d8440]:
 for field,value in [(0x24,LABELS+0x100),(0x10,TICKS+0x40),(0x20,MODES+4),(0,D+0x9100)]:
  c=seed(e);c['mutations']=[word(REC+field,value)];c['writes'] += [patch(TICKS+0x40,b'\0'*32)];cases.append(c)
# Accumulator aliases mode: addition changes the return lookup from array3 to array2.
for micros in [1,2,3]:
 c=seed(0x5d8440);c['counter']=[micros,0];c['writes'] += [word(REC+12,MODES),word(MODES,0)];cases.append(c)
rows=[];errors=[];checks=0;startTime=time.time()
for i,c in enumerate(cases):
 im=Image(c);predicted,tr=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 current=c;nativeTrace=[];rv=n.call(SHIM if c['entry']==0x4f3ca0 else c['entry'],c['args']);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();observed=n.unpack('<I',PROBE)[0] if c['entry']==0x4f3ca0 else rv if c['entry']==0x5d8440 else None;checks+=2+(predicted is not None)
 if actual!=im.hash() or observed!=predicted or nativeTrace!=tr:
  errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash(),nativeResult=observed,modelResult=predicted,nativeTrace=nativeTrace,modelTrace=tr));break
 c['expected']=dict(sha256=actual,result=observed,trace=tr);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors,entryCounts=entries,binarySha256=n.sha256,nativeAdapters=['imported QueryPerformanceCounter751110 value/mutation port'],seconds=round(time.time()-startTime,3),syntheticExcluded=0)
(B/'reports/world-phase71-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase71-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],probe=PROBE,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
