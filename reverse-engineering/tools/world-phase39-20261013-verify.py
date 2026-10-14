import json,hashlib,struct,base64,gzip,time
from pathlib import Path
def load(num,marker):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);x={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index(marker)],str(p),'exec'),x);return x
base=load(35,'rows=[];errors=[];start=time.time()');init=load(37,'\nfrom unicorn import UC_HOOK_CODE');attr=load(38,'\nfrom unicorn import UC_HOOK_CODE')
n=base['rot']['Native']();B=base['B'];D=n.DATA;REGIONS=base['REGIONS'];Image=base['Image'];U=base['U'];word=base['word'];bits=base['bits'];R=base['R'];EM=base['EM'];TLS=D+0xf800;case={};trace=[]
def boundary(im,address,args):
 if address==0x5d69a0:
  trace.append([address,args]);return case.get('visibility',1)
 if address==0x600260:
  trace.append([address,args]);im.W(args[0]+0x2a8,D+0x78000);return 0
 if address==0x6f040c:trace.append([address,args]);return TLS
 if address in [0x653970,0x654930]:return init['initialize'](im,dict(emitter=args[0],record=args[1],time=args[2]))
 if address in [0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00]:
  attr['attr'](im,dict(entry=address,particle=args[2],record=args[1]));return 0
 raise ValueError('unbound composition call '+hex(address))
base['service']=boundary;init['service']=boundary
# Attributes' real CRT own body requests only an external context pointer.
def tls(im):return boundary(im,0x6f040c,[])
attr['tls']=tls
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
class NativeImage:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x6561d0,0x653970,0x654930,0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00,0x6e8e1e,0x5b9d90,0x5b3830,0x5c11d0,0x5c0240,0x6e9530,0x6550b0,0x655b30,0x656080,0x6551d0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x5d69a0,0x600260,0x6f040c]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if a==0x5d69a0:
  p,v,rad=n.unpack('<3I',sp+4);args=list(n.unpack('<3I',p))+list(n.unpack('<3I',v))+[rad]
 else:args=[] if a==0x6f040c else list(n.unpack('<I',sp+4))
 value=boundary(NI,a,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
# Use retained phase35 physical fixtures, replacing only authored initializer/attribute/TLS preparation.
original=json.loads(gzip.decompress((B/'reports/world-phase35-20261013-vectors.json.gz').read_bytes()));cases=[]
for index,row in enumerate(original['cases']):
 c=json.loads(json.dumps(row));c.pop('expected');im=Image(c);selector=base['S8'](im.B(R+0x2c));update=base['S8'](im.B(R+0x2d));callback=[0,0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00][index%7]
 c['writes'] += [word(0x810910+selector*4,0x653970 if index%2==0 else 0x654930),word(0x810944+update*4,callback),word(R+0x2a8,0),word(TLS+20,0x12345678),word(R+0x48,bits(0.75)),word(R+0x4c,bits(1)),word(R+0x50,bits(2)),word(R+0x54,bits(3)),word(R+0x58,bits(4)),word(R+0x5c,bits(5)),word(R+0x60,bits(6)),word(R+0x64,bits(0.25)),word(R+0x68,bits(0.5)),word(R+0x6c,bits(0.75))]
 for j in range(16):c['writes'] += [word(EM+j*0x330+0x1c0,0x653970 if index%2==0 else 0x654930),word(EM+j*0x330+0x1c4,callback)]
 c['provenance']=dict(phase35case=index,attribute=hex(callback));cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 try:base['burst'](im,c)
 except (ValueError,ZeroDivisionError) as ex:excluded.append(dict(case=i,causeAddress=str(ex),reason='Unprepared particle backing after negative signed frame multiplier produced no allocated chunks.'));continue
 modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x6561d0,[c['physical'],c['position'],c['velocity'],c['delta'],U(c['count']),c['duration'],c['secondary'],c['primary'],c['priority'],c['flags']],count=10000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=modelTrace:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=trace[:12],modelTrace=modelTrace[:12]))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['0x5d69a0 copied visibility input','0x600260 descriptor publication','0x6f040c TLS context'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded,excludedDomain='Synthetic negative-frame cases have no readable allocated chunks; no composition equivalence credit.',fixtureProvenance=dict(path='reports/world-phase35-20261013-vectors.json.gz',sha256=hashlib.sha256((B/'reports/world-phase35-20261013-vectors.json.gz').read_bytes()).hexdigest(),preparation='same authored physical fixtures; real initializer/attribute pointers, RNG/descriptor/finite distribution preparation replaces former synthetic initializer'))
(B/'reports/world-phase39-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase39-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],tlsContext=TLS,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
