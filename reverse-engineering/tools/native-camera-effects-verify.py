"""Camera effects/reset/side predicate original-instruction checks, no game launch."""
import json,struct,importlib.util,itertools,random,base64,gzip
from fractions import Fraction
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA;CAM=D;ALT=D+0x1000;WORLD=D+0x2000;SETTINGS=D+0x2400;PACK=D+0x3000;SCRIPT=D+0x3400;ARGS=D+0x4000;TEXT=D+0x5000;CRE=D+0x9000;REF=D+0xa000;OBJ=D+0xb000;RESULT=D+0xc000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
calls={}
def observe(mu,a,size,user):calls[hex(a)]=calls.get(hex(a),0)+1
for a in [0x451c20,0x44d110,0x44d210,0x44d300,0x549bb0,0x549de0,0x54a2f0,0x576c40,0x441c00,0x54fa60,0x5147c0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(i):return struct.unpack('<f',struct.pack('<I',i))[0]
def f(v):return fl(bits(v))
def enc(b):return base64.b64encode(b).decode()
def dec(s):return bytearray(base64.b64decode(s))
def fold(t):return bytes(c-32 if 97<=c<=122 or c>=224 else c for c in t.split('\0')[0].encode('latin1')).decode('latin1').lower()
def number(t):
 t=t.split('\0')[0];low=t.lower()
 if 'param'in low:return 2.75
 if low in ['alpha','beta','gamma','delta']:return[2.75,1.5,3.,4.][['alpha','beta','gamma','delta'].index(low)]
 i=0;v=0.;d=1.
 if t.startswith('-'):i=1;d=-1.
 while i<len(t)and'0'<=t[i]<='9':v=f(f(v*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':d=f(d*10);v=f(f(v*10)+int(t[i]));i+=1
 return f(v/d)
def defaults(**kw):
 camera=bytearray([0xa5]*0x230);struct.pack_into('<6f',camera,0x110,0,0,1,2,3,4);struct.pack_into('<f',camera,0x1c8,.2)
 v=dict(camera=enc(camera),alternate=enc(bytes([0x5a])*0x230),bindings=enc(bytes([0x37])*0x3fc),first=True,active=True,end=bits(50),elapsed=bits(3),blendOut=bits(.5),selected=0x12345678,seed=7,defaults=[5,9],tokens=[],position=[5.,7.,9.],gate=3,nullCamera=False,magnitude=bits(.7),time=bits(4),speed=bits(2),axis=2)
 v.update(kw);return v
def setup(v):
 n.write(D,bytes(0xd000));n.write(CAM,dec(v['camera']));n.write(ALT,dec(v['alternate']));n.write(0x951500,dec(v['bindings']));n.pack('<I',0x8021b4,CAM);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,SETTINGS);n.pack('<2B',SETTINGS+0xcb,*v['defaults']);n.pack('<I',0x855de0,int(v['active']));n.pack('<I',0x9514e8,v['end']);n.pack('<I',0x95191c,v['elapsed']);n.pack('<I',0x9514ec,v['blendOut']);n.pack('<I',0x9514e4,v['selected']);n.pack('<I',0x80253c,v['seed']);n.pack('<I',PACK+4,SCRIPT);n.pack('<4f',PACK+0x14,2.75,1.5,3,4)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.pack('<I',SCRIPT+0x18+i*8,SCRIPT+0x80+i*32);n.write(SCRIPT+0x80+i*32,name.encode()+b'\0')
 for i,t in enumerate(v['tokens']):n.pack('<I',ARGS+i*4,TEXT+i*256);n.write(TEXT+i*256,t.encode('latin1')+b'\0')
 n.pack('<I',CRE+0xd0,REF if v['gate']>=2 else 0);n.pack('<I',REF,OBJ if v['gate']>=3 else 0);n.pack('<3f',OBJ+0x80,*v['position']);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT))
def snapshot():return dict(camera=enc(n.read(CAM,0x230)),alternate=enc(n.read(ALT,0x230)),bindings=enc(n.read(0x951500,0x3fc)),end=n.unpack('<I',0x9514e8)[0],elapsed=n.unpack('<I',0x95191c)[0],blendOut=n.unpack('<I',0x9514ec)[0],selected=n.unpack('<I',0x9514e4)[0],active=bool(n.unpack('<I',0x855de0)[0]),seed=n.unpack('<I',0x80253c)[0])
def wide(v):
 if not v:return v
 sign=-1 if v<0 else 1;v=abs(v);n,d=v.numerator,v.denominator;shift=max(0,n.bit_length()-64)
 if shift:
  q,r=divmod(n,1<<shift);half=1<<(shift-1)
  if r>half or r==half and q&1:q+=1
  n=q<<shift
 return sign*Fraction(n,d)
def model(op,v):
 o=snapshot();out=dec(o['alternate']if op in ['setShake','setJudder','resetHelper']and not v['nullCamera']else o['camera']);result=1
 def read(off):return struct.unpack_from('<f',out,off)[0]
 def sf(off,value):struct.pack_into('<f',out,off,value)
 def shake(a,t,s):sf(0x1d4,a);sf(0x1d8,t);sf(0x1dc,s)
 def judder(value,axis):
  if read(0x1c8)<abs(value):sf(0x1c8,abs(value));sf(0x1cc,abs(value));out[0x228]=int(value<0);out[0x229]=axis&255
 def clear():o['bindings']=enc(bytes(0x3fc))
 def reset():
  for p in [0x1c8,0x1d0,0x1d4,0x1d8,0x1c0,0x1bc,0x1b8,0x1ec,0x1e8,0x1f4,0x1f0,0x214,0x218,0x20c,0x210,0x204,0x208]:sf(p,0)
  for p in [0x22d,0x22c,2,3,1]:out[p]=255
  sf(0x1dc,1);sf(0x1e0,v['defaults'][0]);sf(0x1e4,v['defaults'][1]);o['active']=False;o['selected']=0;clear()
 if op=='end':
  if v['first']and v['active']:
   for t in v['tokens']:
    low=fold(t)
    if'end_time='in low:o['end']=bits(f(number(t[low.index('end_time=')+9:])+fl(v['elapsed'])))
    elif'blend_out_time='in low:o['blendOut']=bits(number(t[low.index('blend_out_time=')+15:]))
 elif op=='shake':
  if v['first']:
   a,t,s=1.,0.,1.
   for token in v['tokens']:
    low=fold(token)
    if'mul='in low:a=number(token[low.index('mul=')+4:])
    elif'time='in low:t=number(token[low.index('time=')+5:])
    elif'speed='in low:s=number(token[low.index('speed=')+6:])
   shake(a,t,s)
 elif op=='judder':
  if v['first']:
   a,axis=f(.1),0
   for t in v['tokens']:
    low=fold(t)
    if'axis=x'in low:axis=0
    elif'axis=y'in low:axis=1
    elif'axis=z'in low:axis=2
    elif'time'in low:a=number(t[low.index('time')+5:])
   if v['tokens']and axis==2:
    o['seed']=(v['seed']*0x24cd+1)&65535
    if o['seed']<32768:a=-a
   judder(a,axis)
 elif op=='reset':
  if v['first']:reset()
 elif op=='setShake':shake(fl(v['magnitude']),fl(v['time']),fl(v['speed']))
 elif op=='setJudder':judder(fl(v['magnitude']),v['axis'])
 elif op=='resetHelper':reset()
 elif op=='clearBindings':clear()
 elif op=='behind':
  result=0
  if v['gate']==3:
   delta=[f(v['position'][i]-read(0x11c+i*4))for i in range(3)];dot=wide(Fraction(read(0x114))*Fraction(delta[1])+Fraction(read(0x110))*Fraction(delta[0]));dot=wide(dot+Fraction(read(0x118))*Fraction(delta[2]));result=bits(1.)if dot<0 else 0
 o['alternate'if op in ['setShake','setJudder','resetHelper']and not v['nullCamera']else'camera']=enc(out);return o,result
entries={'end':0x451c20,'shake':0x44d210,'judder':0x44d110,'reset':0x44d300,'setShake':0x549bb0,'setJudder':0x549de0,'resetHelper':0x54a2f0,'clearBindings':0x576c40,'behind':0x441c00};rows=[];errors=[]
def run(op,v,source=None):
 setup(v);expected,want=model(op,v);a=0 if v['nullCamera']else ALT
 if op in ['end','shake','judder','reset']:args=[0,PACK,CRE,ARGS,len(v['tokens']),int(v['first'])]
 elif op=='setShake':args=[a,v['magnitude'],v['time'],v['speed']]
 elif op=='setJudder':args=[a,v['magnitude'],v['axis'],0]
 elif op=='resetHelper':args=[a]
 elif op=='clearBindings':args=[]
 else:args=[0,PACK,CRE if v['gate']else 0]
 got=n.call(entries[op],args,count=500000)
 if op=='behind':n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0]
 elif op not in ['end','shake','judder','reset']:got=1
 actual=snapshot()
 if actual!=expected or got!=want:errors.append(dict(index=len(rows),op=op,fields=[k for k in actual if actual[k]!=expected[k]],result=[want,got],tokens=v['tokens']))
 row=dict(operation=op,input=v,expected=actual,result=got)
 if source:row['source']=source
 rows.append(row)
for op,tokens in [('end',[]),('end',['end_time=1','blend_out_time=.5']),('end',['blend_out_time=1end_time=2']),('end',['end_time=2','end_time=4']),('end',['end_time=infinite']),('end',['end_time=param3']),('end',['end_time=-0','blend_out_time=-0']),('shake',[]),('shake',['mul=-0.5','time=12','speed=5']),('shake',['speed=1mul=2']),('shake',['mul=-0','time=-0','speed=-0']),('judder',[]),('judder',['axis=z','time=.4']),('judder',['axis=z','axis=x','time=-.4']),('judder',['axis=y','time=param1']),('judder',['axis=zx','time=.8']),('reset',[])]:
 for first,active,seed in itertools.product([False,True],[False,True],[0,1,7,32768,65535]):run(op,defaults(tokens=tokens,first=first,active=active,seed=seed))
for op,null,raw in itertools.product(['setShake','setJudder','resetHelper'],[False,True],[0,0x80000000,1,0x80000001,bits(-2),bits(.1),bits(.2),bits(.3),0x7f7fffff,0xff7fffff]):run(op,defaults(nullCamera=null,magnitude=raw,time=raw,speed=raw,axis=258,defaults=[0,255]))
run('clearBindings',defaults())
r=random.Random(0x441c00)
for i in range(800):
 v=defaults(gate=i%4,position=[f(r.uniform(-100,100))for _ in range(3)]);b=dec(v['camera']);struct.pack_into('<6f',b,0x110,*[f(r.uniform(-100,100))for _ in range(6)]);v['camera']=enc(b);run('behind',v)
# Negative products below float32 storage precision must still compare belowzero.
for sign in [-1,0,1]:
 v=defaults(position=[sign*fl(1),0,0]);b=dec(v['camera']);struct.pack_into('<6f',b,0x110,fl(1),0,0,0,0,0);v['camera']=enc(b);run('behind',v)
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());names={'EndCameraCut':'end','JudderGameCamera':'judder','CameraShake':'shake','ResetGameCamera':'reset','BehindCamera':'behind'};authored={}
for command in ledger['rows']:
 if command['name']not in names:continue
 authored[command['name']]=command['sourceUses']
 for use in command['uses']:
  for first in [False,True]:run(names[command['name']],defaults(tokens=use['args'],first=first),{k:use[k]for k in ['source','line']})
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(errors),examples=errors[:12],authoredUses=authored,nativeCalls=calls,adapters=[],comparison='Complete576-byte camera and alternate-camera records plus1020-byte binding region and cut/RNG scalars per case.',limits=['Finite operands and float32 position differences; behind-camera comparison retains extended sign even on float32 underflow.','Judder helper covers nonspatial fourth-argument-zero branch used by the script command; distance attenuation remains unrecovered.','World camera/settings/actor records are supplied; no live camera movement or rendered output.','Managed replay remains unexecuted.'])
(B/'reports/native-camera-effects-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-camera-effects-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(records=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));raise SystemExit(bool(errors))
