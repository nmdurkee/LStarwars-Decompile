import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x40000,167),(0x2961f00,0x400,0),(0x2921100,0x200,0),(0x2947b70,4,0),(0x2923180,0x80,0),(0x292fa00,0x600,0),(0x8108e8,8,0),(0x2947d00,0x200,0),(0x2948e00,0x200,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
def functions(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());ctx=dict(U=U,F=F,S=S);exec(compile(ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]),str(p),'exec'),ctx);return ctx
links=functions(24);unlinks=functions(26)
from fractions import Fraction
def recycle(im,node):
 count=im.W(0x2947b70);table=im.W(0x2923198);count=U(count-1);im.W(0x2947b70,count);im.W(table+count*4,node)
def expire(im,node,alternate):
 at=0x2947d84 if alternate else 0x2948e98;table=im.W(0x29211fc if alternate else 0x2921200);count=U(im.W(at)-1);im.W(at,count);im.W(table+count*4,im.W(node))
 for i in range(12 if alternate else 32):im.W(im.W(node)+0x2c+i*32,0x501502f9);im.W(im.W(node)+0x3c+i*32,0x43000000)
 recycle(im,node);im.W(node,0)
def advance(im,node,head):im.W(node+4,(N.word(im.W(node+4))+N(Fraction.from_float(0.1))).store());links['timed'](im,node,head)
def process(im,c):
 bank=c['bank'];clock=F(im.W(0x2962060 if bank==1 else 0x296205c));head=U(0x292fbfc+bank*4);node=im.W(head);assert not im.W(0x2962058);im.W(0x2962058,1);iterations=0
 while node and F(im.W(node+4))<=clock:
  iterations+=1
  if iterations>1000:raise ValueError('unbounded staged time advance')
  im.W(head,im.W(node+16));tag=im.W(node+8);im.W(node+16,0)
  if tag in [3,8]:expire(im,node,tag==8)
  elif tag in [2,9]:links['commands'](im,node,1);im.W(node+8,3 if tag==2 else 8);advance(im,node,head)
  elif tag in [0,7]:
   capacity=S(im.W(0x8108e8)+im.W(0x8108ec))
   if capacity>0:
    packets=im.W(0x2961fec);chunk=im.W(node)
    for i in range(capacity):
     packet=packets+i*100
     if im.W(packet)==chunk:
      record=im.W(packet+4);bank=S8(im.B(record+0x2f1));unlinks['priority'](im,packet,U(0x292fd30+bank*4));offset=i*100;im.W(im.W(0x2961fec)+offset,0);im.W(im.W(0x2961fec)+offset+4,0);im.W(im.W(0x2961fec)+offset+8,0);break
   tag=im.W(node+8);im.W(node+4,(N.word(im.W(node+4))+N(Fraction.from_float(0.1))).store())
   if tag==0:im.W(node+8,2)
   elif tag==7:im.W(node+8,9)
   links['timed'](im,node,head)
  elif tag in [1,5,6]:raise ValueError('remaining attachment/bounce own-body branch')
  node=im.W(head)
 im.W(0x2962058,0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x657110,0x5ffea0,0x654ea0,0x6551d0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
NODES=D+0x1000;CHUNKS=D+0x10000;RETURN=D+0x3000;FREE=D+0x4000;ALT=D+0x5000;PACKETS=D+0x6000;R=D+0x8000
def seed(tag=0,bank=0,length=1,clock=10):
 c=dict(bank=bank,writes=[word(0x292fbfc,NODES if bank==0 and length else 0),word(0x292fc00,NODES if bank==1 and length else 0),word(0x296205c,bits(clock)),word(0x2962060,bits(clock)),word(0x2962058,0),word(0x2947b70,32),word(0x2923198,RETURN),word(0x2948e98,32),word(0x2947d84,32),word(0x2921200,FREE),word(0x29211fc,ALT),word(0x8108e8,8),word(0x8108ec,8),word(0x2961fec,PACKETS),word(0x292fd30,PACKETS),word(0x292fd40,0)])
 for i in range(8):c['writes'] += [word(NODES+i*0x40,CHUNKS+i*0x500),word(NODES+i*0x40+4,bits(i/10)),word(NODES+i*0x40+8,tag),word(NODES+i*0x40+16,NODES+(i+1)*0x40 if i+1<length else 0)]
 for i in range(16):c['writes'] += [word(PACKETS+i*100,CHUNKS+i*0x500),word(PACKETS+i*100+4,R),word(PACKETS+i*100+8,0),word(PACKETS+i*100+0x58,PACKETS+(i-1)*100 if i else 0),word(PACKETS+i*100+0x5c,PACKETS+(i+1)*100 if i+1<16 else 0)]
 c['writes'] += [byte(R+0x2f1,0)]
 return c
cases=[seed(tag,bank,length,clock) for tag in [0,2,3,4,7,8,9,10,0xffffffff] for bank in [0,1] for length in [0,1,2,8] for clock in [-1,0,.05,.1,.2,10]]
for bank in [0,1]:
 for clock in [0x7fc12345,0x7f800000,0xff800000,0x80000000]:c=seed(3,bank);c['writes'] += [word(0x296205c,clock),word(0x2962060,clock)];cases.append(c)
for tag in [0,7]:
 for physicalBank in [-1,0,1,4,127]:
  c=seed(tag);c['writes'] += [byte(R+0x2f1,physicalBank),word(U(0x292fd30+physicalBank*4),PACKETS)];cases.append(c)
# Packet clearing aliases the timed node tag; fresh tag selects ordinary second stage even from initial7.
c=seed(7,0,1,1e-20);c['writes'] += [word(0x2961fec,NODES),word(NODES,CHUNKS),word(NODES+4,R),word(NODES+8,7),word(NODES+0x58,0),word(NODES+0x5c,0),word(0x292fd30,NODES)];cases.append(c)
c=seed(2,0,1,0);c['writes'].append(word(NODES,NODES+8));cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:process(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x657110,[c['bank']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase60-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase60-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
