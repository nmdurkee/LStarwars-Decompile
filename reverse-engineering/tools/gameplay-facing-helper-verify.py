"""Original PC movement callback, look arbitration, normalization and rotation."""
import importlib.util,json,itertools,random,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('facing',Path(__file__).with_name('gameplay-facing-verify.py'));v=importlib.util.module_from_spec(s);s.loader.exec_module(v)
n=v.n;b=v.b;D=v.D;P=v.SCRATCH;bits=v.bits;fl=v.fl;f=v.f
checks={};errors=[];fixtures=[]
def check(group,got,want,meta):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def token_tests():
 for token,mode in itertools.product(['RUN','run','Run','WALK','wAlK','TIPTOE','tiptoe',' RUN','run ','prefixrun','run=1','tiptoe2','walk\t',''],range(256)):
  n.write(P,token.encode()+b'\0');n.pack('<B',P+256,mode);result=n.call(0x43c0c0,[P,P+256]);out=n.unpack('<B',P+256)[0];expected={'run':0,'walk':1,'tiptoe':2}.get(token.lower());got=[result,out];want=[int(expected is not None),mode if expected is None else expected];check('movement-token',got,want,dict(token=token,mode=mode));fixtures.append(dict(kind='token',token=token,mode=mode,native=got))
def look_tests():
 for current,target,priority,oldpriority,seed,delay in itertools.product([-1,0,1],[-1,0,1],[-128,0,6,127],[-128,0,6,127],[0,123,65535],[(0.,0.),(-.25,1.5)]):
  c=v.setup('FaceCamera',[],dict(oldLook=current,priority=oldpriority,qrand=seed));before=v.headstate(0);n.call(0x58bee0,[b.actor(0),v.HEAD+target*16 if target>=0 else 0,priority&255,bits(.75),bits(delay[0]),bits(delay[1])]);state=v.headstate(0);qr=n.unpack('<I',0x80253c)[0];want,wr=v.request(before,target,priority,.75,*delay,seed,c['headpoints']);got=dict(state=state,qrand=qr);expected=dict(state=want,qrand=wr);check('look-arbitration',got,expected,dict(current=current,target=target,priority=priority,oldPriority=oldpriority,seed=seed,delay=delay));fixtures.append(dict(kind='look',before=before,target=target,priority=priority,duration=bits(.75),minDelay=bits(delay[0]),maxDelay=bits(delay[1]),seed=seed,positions=c['headpoints'],native=got))
def math_tests():
 randomizer=random.Random(0x5b3b30);n.write(0x29899a0,v.sine_bytes)
 vectors=[[0.,0.,0.],[1.,0.,0.],[-1.,0.,0.],[1.,2.,3.],[1e-20,-1e-20,1e-20]]+[[f(randomizer.uniform(-10000,10000)) for j in range(3)] for i in range(512)]
 for i,point in enumerate(vectors):
  point=[f(x) for x in point]
  n.pack('<3f',P,*point);n.call(0x5b3b30,[P,P]);got=list(n.unpack('<3I',P));want=v.vec(v.normalize(point));check('normalize',got,want,point);fixtures.append(dict(kind='normalize',point=v.vec(point),native=got))
  angle=(i*19337)&65535;n.pack('<3f',P,*point);n.call(0x5b3620,[P,P,angle]);got=list(n.unpack('<3I',P));sn=v.sines[(angle>>1)&32767];cs=v.sines[((angle+16384)>>1)&32767];want=v.vec([sn*point[2]+cs*point[0],point[1],point[2]*cs-point[0]*sn]);check('rotation',got,want,dict(point=point,angle=angle));fixtures.append(dict(kind='rotate',point=v.vec(point),angle=angle,native=got))
if __name__=='__main__':
 token_tests();look_tests();math_tests()
 result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:10],method='Unmodified PC callback, look-priority helper, vector normalize and actual sine-table rotation; no replaced native helpers in this suite.',limits=['Finite valid vector/timing data; valid pointer identities projected explicitly.','Default PC numeric control state; arbitrary x87 precision/NaN/overflow excluded.','Head-look consumer and actual character turning remain external.','Compiled portable comparison pending.'])
 (b.BASE/'reports/gameplay-facing-helper-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8');(b.BASE/'reports/gameplay-facing-helper-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=fixtures),separators=(',',':')),encoding='utf8');print(json.dumps(result))
 if errors:raise SystemExit(1)
