"""Independent controller state reconstruction against original PC functions."""
import importlib.util,json,struct,random,math,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESI
n=m.NativeX86();B=m.BASE;PAD=n.DATA;PAIR=PAD+0x1000
def f32(x):
 try:return struct.unpack('<f',struct.pack('<f',x))[0]
 except OverflowError:return math.copysign(math.inf,x)
pack=lambda fmt,b,o,v:struct.pack_into(fmt,b,o,v)
read=lambda fmt,b,o:struct.unpack_from(fmt,b,o)[0]
report={'binarySha256':n.sha256,'contracts':{},'failures':[],'method':'Unmodified original0x4f4110/4f40a0 deadzones and0x4f4370 whole pad update, including0x4f4280 response table. No hooks, no input APIs, no game process.'};vectors=[]

def group(name):
 r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r

def check(r,want,got,meta):
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<10:r['examples'].append({'input':meta,'expected':want,'actual':got})

def deadzone(x,y,d,scaled):
 if scaled:
  def axis(v):return math.trunc(((v-d+1)*127 if v>=d else(v+d)*127 if v < -d else 0)/(128-d))
  return axis(x),axis(y)
 a=max(-1,min(1,f32(x/127)));b=max(-1,min(1,f32(y/127)));radius=f32(math.sqrt(f32(a*a+b*b)))
 return(0,0)if radius<f32(d/127)else(x,y)

def curve(v):
 for end,result in [(0.,0.),(.5,f32(.1)),(.75,.25),(f32(.85),.5),(1.,1.)]:
  if v<=end:return result
 return 1.

def model(before,scaled,frame):
 b=bytearray(before);held=read('<I',b,0x10);old=read('<I',b,0x1c);changed=held^old
 for off,val in[(0x14,held&changed),(0x18,old&changed),(0x1c,held)]:pack('<I',b,off,val)
 axes=[b[8]-128,128-b[9],b[10]-128,128-b[11]];d=read('<i',b,0x34)
 if d:
  axes[:2]=deadzone(*axes[:2],d,scaled);axes[2:]=deadzone(*axes[2:],d,scaled)
  b[8:12]=bytes([(axes[0]+128)&255,(128-axes[1])&255,(axes[2]+128)&255,(128-axes[3])&255])
 for j,v in enumerate(axes):
  pack('<i',b,0x24+j*4,v);value=f32(v/128);bias=read('<f',b,0x48+j*4)
  if value>0:value=max(0,f32(value-bias))
  if value<0:value=min(0,f32(value+bias))
  pack('<f',b,[0x38,0x3c,0x58,0x5c][j],value)
 flags=read('<I',b,0x20)
 if flags&1:b[0x78:0x7c]=b[0x7c:0x80]
 else:
  step=f32(frame/30)
  for j,bit in enumerate([0x1000,0x4000,0x8000,0x2000]):
   off=0x68+j*4;v=min(1,f32(read('<f',b,off)+step))if held&bit else 0;pack('<f',b,off,v)
  for j,off in enumerate([0x70,0x74,0x68,0x6c]):b[0x78+j]=math.trunc(curve(read('<f',b,off))*255)&255
 b[0x82:0x84]=b[0x80:0x82]if flags&2 else bytes([127,127])
 return bytes(b)

try:
 r=group('both_deadzone_modes_six_thresholds')
 for scaled,d in itertools.product([0,1],[1,8,16,32,64,127]):
  n.pack('<B',0x91eef6,scaled)
  for x,y in itertools.product(range(-128,129),repeat=2):
   n.pack('<ii',PAIR,x,y);n.call(0x4f4110,[d],{UC_X86_REG_EAX:PAIR,UC_X86_REG_ESI:PAIR+4});want=deadzone(x,y,d,scaled);got=n.unpack('<ii',PAIR);check(r,want,got,{'x':x,'y':y,'deadzone':d,'scaled':scaled})
 r=group('whole_generic_pad_state_with_bias_ramps_and_flags');rng=random.Random(0x4f4370)
 for i in range(12000):
  b=bytearray(rng.randbytes(0x84));scaled=i%2;d=rng.choice([0,1,8,16,32,64,127]);flags=i%4;frame=f32(rng.choice([0,.1,.5,1,2,30]))
  pack('<i',b,0x34,d);pack('<I',b,0x20,flags)
  for j in range(4):pack('<f',b,0x48+j*4,f32(rng.choice([-.25,0,.1,.2,.5,1])));pack('<f',b,0x68+j*4,f32(rng.random()))
  n.pack('<B',0x91eef6,scaled);n.pack('<f',0x8004ec,frame);n.write(PAD,b);n.call(0x4f4370,[PAD]);actual=n.read(PAD,0x84);want=model(b,scaled,frame)
  check(r,want.hex(),actual.hex(),{'index':i,'scaled':scaled,'deadzone':d,'flags':flags,'frame':frame,'offsets':[j for j in range(0x84)if want[j]!=actual[j]]})
  vectors.append({'before':bytes(b).hex(),'after':actual.hex(),'scaled':scaled,'frame':frame})
 r=group('finite_frame_overflow_and_persistent_infinite_ramps')
 maxf=struct.unpack('<f',bytes.fromhex('ffff7f7f'))[0]
 for frame,start,held in itertools.product([-maxf,-1.,0.,1.,maxf],[-maxf,0.,maxf,-math.inf,math.inf],[0,0xf000]):
  b=bytearray(0x84);b[8:12]=bytes([128]*4);pack('<I',b,0x10,held)
  for j in range(4):pack('<f',b,0x68+4*j,start)
  n.pack('<B',0x91eef6,0);n.pack('<f',0x8004ec,frame);n.write(PAD,b);n.call(0x4f4370,[PAD]);actual=n.read(PAD,0x84);want=model(b,False,frame)
  meta={'frame':frame,'start':str(start),'held':held,'offsets':[j for j in range(0x84)if want[j]!=actual[j]]};check(r,want.hex(),actual.hex(),meta)
  vectors.append({'before':bytes(b).hex(),'after':actual.hex(),'scaled':0,'frame':frame})
except Exception as e:report['failures'].append({'error':str(e),'completed':{k:v['cases']for k,v in report['contracts'].items()}})
report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])}
report['limits']=['Controller raw staging and logical mapping are separate from this generic pad layer.','Finite bias/frame values, finite or infinite ramp values, byte axis domain, valid thresholds1..127; threshold128 would divide by zero in scaled mode and is excluded.','Whole132-byte images compare unchanged bytes as well as edge/axis/ramp/output fields.','Random pad records are bounded representation fixtures, not claimed normal gameplay state.']
(B/'reports/native-controller-state.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-controller-state-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n');print(json.dumps(report,indent=2));raise SystemExit(1 if report['totals']['mismatches']or report['failures']else 0)
