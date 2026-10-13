"""Original height factor and clip-dependent collision dimension producer."""
from pathlib import Path
p=Path(__file__).with_name('movement-phase25-20261013-native.py');exec(compile(p.read_text().split('for player,fb,pointers in itertools.product')[0],str(p),'exec'))
MODEL=D+0x8000;CB=n.STOP+0x400;vectors=[];errors=[];groups={};events=[];config={}
def hook26(mu,a,size,user):
 if a!=CB:return
 sp=mu.reg_read(m.UC_X86_REG_ESP);actor=n.unpack('<I',sp+4)[0];events.append(['updated',actor,list(n.unpack('<2I',actor+0x1dc))]);
 if config.get('mutate'):n.pack('<2I',actor+0x1dc,0xdeadbeef,0x7f800001)
 mu.reg_write(m.UC_X86_REG_EAX,0x12345678);mu.reg_write(m.UC_X86_REG_ESP,sp+4);mu.reg_write(m.UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook26)
def setup26(c):
 before=setup25(c);n.pack('<I',ACT+0x50,0 if c.get('nullModel')else MODEL);n.pack('<B',ACT+0x1079,c.get('enabled',1));n.pack('<I',ACT+0xd30,c.get('modeBits',0x3f800000));n.pack('<B',DATA+0x10d,c.get('clip',2));n.pack('<f',DATA+0x4c,c.get('specialRadius',3.125));n.pack('<B',ACT+0x28c,c.get('ready',1));n.pack('<f',ACT+0xac,c.get('radius',1.25));n.pack('<f',ACT+0xb0,c.get('bound',2.5));idx=c.get('clip',2);idx=idx if idx<128 else idx-256;n.pack('<I',MODEL+0x14+idx*4,c.get('clipPointer',0x12345678));n.pack('<I',0x93d508,CB if c.get('callback',True)else 0);events.clear();config.clear();config.update(c);return bytearray(n.read(D,SIZE))
def oracle26(k,c,img):
 ev=[]
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def fl(p):return struct.unpack_from('<f',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def pf(p,v):struct.pack_into('<f',img,p-D,v)
 if k=='height':
  ty=u(ACT+0x54);put(ACT+0xff0,u(ty+0x34));top=fl(ty+0x38);pf(ACT+0xff4,top);radius=fl(ACT+0xffc)
  if radius==0:pf(ACT+0x1004,0)
  else:
   num=X.fl(top)-X.fl(fl(ACT+0xff0));den=X.fl(radius)+X.fl(radius);pf(ACT+0x1004,X(quant(num.v/den.v,64),num.neg!=den.neg).flstore())
  return ev
 special=False;data=0
 if img[ACT-D+0x1079]and fl(ACT+0xd30)==1:
  data=u(u(ACT+0x54)+0x24);idx=img[data-D+0x10d];idx=idx if idx<128 else idx-256
  if idx!=-1 and u(u(ACT+0x50)+0x14+idx*4)and img[ACT-D+0x28c]:special=True
 if special:
  v=(X.fl(fl(data+0x4c))*X.fl(fl(ACT+0xff8))).flstore();pf(ACT+0x1e0,v);pf(ACT+0x1dc,v)
 else:put(ACT+0x1dc,u(ACT+0xac));put(ACT+0x1e0,u(ACT+0xb0))
 if c.get('callback',True):
  ev.append(['updated',ACT,[u(ACT+0x1dc),u(ACT+0x1e0)]])
  if c.get('mutate'):put(ACT+0x1dc,0xdeadbeef);put(ACT+0x1e0,0x7f800001)
 return ev

def run26(k,c,group):
 before=setup26(c);expected=bytearray(before);ev=oracle26(k,c,expected);n.call(0x55cd20 if k=='height'else 0x55cc40,[ACT]);after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected or(k=='update'and events!=ev):errors.append(dict(kind=k,input=c,events=[events.copy(),ev],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(kind=k,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),events=events.copy()))
for j in range(512):run26('height',dict(tuning=[f32(r.uniform(-1e4,1e4))for j in range(4)],actorRadius=f32(r.uniform(.001,100))*[-1,1][j%2]),'finite-height-difference-division')
for ty,rad in itertools.product([TYPE,ACT+0xfc0,ACT+0xfc4,ACT+0xfc8,ACT+0xfcc],[0.,-0.,1.,-1.,2.125]):run26('height',dict(typePointer=ty,actorRadius=rad),'height-aliases-zero-radius')
for clip,enabled,mode,ready,pointer,callback in itertools.product(range(256),[0,1],[0,0x3f800000],[0,1],[0,1],[False,True]):run26('update',dict(clip=clip,enabled=enabled,modeBits=mode,ready=ready,clipPointer=pointer,callback=callback),'signed-clip-lazy-gate-grid')
for mode,enabled,callback in itertools.product([0x7f800000,0xff800000,0x7fc00001,0x7f800001,0x80000000],[0,255],[False,True]):run26('update',dict(modeBits=mode,enabled=enabled,callback=callback,nullModel=True,mutate=callback),'raw-mode-unordered-gate-no-model-read')
for clip,callback in itertools.product([255],[False,True]):run26('update',dict(clip=clip,nullModel=True,callback=callback),'minus-one-clip-no-model-read')
for j in range(256):run26('update',dict(specialRadius=f32(r.uniform(-1e5,1e5)),heightScale=f32(r.uniform(-20,20)),mutate=j%2==1),'callback-observes-final-radius-values')
checks=sum(1 if v['kind']=='height'else 2 for v in vectors);report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=checks,groups=groups,mismatches=len(errors),errors=errors[:20],nativeAdapters=['Optional final tail-callback 93d508 only; complete numeric/branch bodies execute.'],limits=['Finite consumed radius/tuning/height arithmetic and output values; raw all-IEEE mode gate permitted because it stores no value and skips numeric special branch.','Valid complete raw backing; null model only in proven lazy bypasses. Character/frame lifecycle remains open.'])
(m.BASE/'reports/movement-phase26-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase26-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);fun=[]
for a,b in[(0x55cd20,0x55cd72),(0x55cc40,0x55cccb)]:fun.append(dict(address=hex(a),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/movement-phase26-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=fun),indent=2)+'\n')
print(json.dumps(dict(cases=len(vectors),checks=checks,mismatches=len(errors),errors=errors[:3])))
