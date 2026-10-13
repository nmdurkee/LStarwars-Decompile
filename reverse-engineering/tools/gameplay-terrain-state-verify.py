"""Original actor terrain-result consumption with explicit geometry query services."""
import importlib.util,struct,json,copy,itertools,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('r','gameplay-reinitialization-verify.py');angle=load('angle','gameplay-path-angle-verify.py');cm=load('cm','gameplay-path-corner-math-verify.py');W=cm.W;n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=D;CHAR=D+0x2000;TUNE=D+0x2200;REC=D+0x3000;PTR=D+0x4000;OBJECT=D+0x4200;VEC=D+0x6000;OUT=D+0x6100;H1=D+0x6200;H2=D+0x6204;STUB=D+0x8000;FRET=D+0x8100;CALLBACK=D+0x8200
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
assembly=json.loads((BASE/'reports/gameplay-terrain-state-assembly.json').read_text());n.write(0x29899a0,r.SINE_BYTES);n.write(STUB,b'\xd9\x05'+struct.pack('<I',FRET)+b'\xc3');executed=set();events=[];options={};calls=0
for fn in assembly['functions']:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=int(fn['address'],16),end=int(fn['endExclusive'],16)-1)
def probe(a):return [*[a[i] for i in [0x283,0x284,0x285,0x286,0x287,0xe42,0x107b]],r.u(a,0x21c),r.u(a,0x220),r.u(a,0x224),r.u(a,0x1014),r.h(a,0x106c)]
def effects(a,o,index):
 for e in o.get('effects',[]):
  if e['call']==index:r.put(a,e['offset'],e['value'],e.get('size',4))
def hook(mu,address,size,user):
 global calls
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address in [0x5506f0,0x553500]:
  count=4 if address==0x5506f0 else 1;events.append(['query' if count==4 else 'secondary',*n.unpack('<'+'I'*count,sp+4)]);n.pack('<f',FRET,r.f(options.get('queryHeight' if count==4 else 'secondaryHeight',3 if count==4 else 2e6)));mu.reg_write(UC_X86_REG_EIP,STUB)
 else:
  a=bytearray(n.read(A,0x10d8));events.append(['callback',n.unpack('<I',sp+4)[0],probe(a)]);calls+=1;effects(a,options,calls);n.write(A,a);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for addr in [0x5506f0,0x553500,CALLBACK]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=addr,end=addr)
def vector(o,key,default):return [r.fl(v) for v in o[key+'Words']] if key+'Words' in o else [r.f(v) for v in o.get(key,default)]
def rotate(v,a):
 s=W(r.SINE[(a>>1)&32767]);c=W(r.SINE[((a+16384)>>1)&32767]);return [v[0],(c*W(v[1])-s*W(v[2])).store(),(W(v[1])*s+c*W(v[2])).store()]
def normal(v):
 first=angle.direction(v[2],v[1])&65535;out=rotate(v,-first);return [first,(-angle.direction(out[0],out[1]))&65535]
def setup(o):
 global events,options,calls
 events=[];options=o;calls=0;n.write(A,bytes(0x7000));a=r.pattern(0x10d8,1);r.put(a,0x54,CHAR);n.pack('<I',CHAR+0x24,TUNE);n.pack('<I',TUNE+0x90,o.get('characterFlags',0))
 for off,key,default in [(0x21c,'floor',3),(0x84,'predictedY',1),(0x17c,'lowerY',-1),(0x188,'upperY',5)]:r.put(a,off,r.bits(r.f(o.get(key,default))))
 for i,value in enumerate(vector(o,'position',[2,3,4])):r.put(a,0x5c+4*i,r.bits(value))
 n.write(A,a)
 for addr,key,offset,idx in [(0x292fbf0,'material',0x60,0),(0x292fd44,'upperType',0x61,1),(0x292182c,'lowerType',0x60,2)]:
  val=o.get(key,1);pointer=0 if val<0 else REC+idx*0x100;n.pack('<I',addr,pointer)
  if pointer:n.pack('<B',pointer+offset,val)
 n.pack('<I',0x292fc68,0 if o.get('nullObject') else PTR);n.pack('<I',PTR,OBJECT);n.pack('<i',0x2961fdc,o.get('objectIndex',0))
 for i in range(3):n.pack('<Ih',OBJECT+0x2c+i*0x38,o.get('objectKind',1),o.get('objectId',7))
 for i in range(32):n.pack('<B',0x8034cc+12*i,o.get('materialFlags',10))
 for addr,key,default in [(0x2920d84,'upperHeight',2),(0x2921864,'lowerHeight',-2)]:n.pack('<f',addr,r.f(o.get(key,default)))
 for addr,key,default in [(0x802500,'defaultNormal',[0,1,0]),(0x292fdb8,'groundNormal',[.25,1,-.5]),(0x2962000,'upperNormal',[-.5,1,.25])]:n.pack('<3f',addr,*vector(o,key,default))
 for addr,key in [(0x951288,'modeA'),(0x951154,'modeB'),(0x8034c4,'maskA'),(0x95100c,'maskB')]:n.pack('<I',addr,o.get(key,0))
 n.pack('<I',0x951010,CALLBACK if o.get('callback',True) else 0);n.pack('<H',0x92b0c4,0x1234);n.pack('<H',0x92b0c0,0x5678);n.pack('<3f',VEC,*vector(o,'vector',[.25,1,-.5]));n.write(OUT,bytes.fromhex('12345678'*3));n.pack('<H',H1,0x3333);n.pack('<H',H2,0x4444)
 return a
def getter(o,kind):
 if kind=='object':return o.get('objectId',7) if not o.get('nullObject') and o.get('objectIndex',0)!=-1 and o.get('objectKind',1)==1 else -1
 return o.get(kind,1)
def apply(a,o,publish,height,z):
 if height==2e6:material=raw=0;r.put(a,0x1014,r.bits(2e6));r.put(a,0x107b,0,1);r.put(a,0x106c,65535,2)
 else:
  raw=getter(o,'material');material=raw if 0<=raw<32 else 0;r.put(a,0x107b,2,1);value=height if not o.get('characterFlags',0)&0x8000 and o.get('materialFlags',10)&2 else 2e6;r.put(a,0x1014,r.bits(value));r.put(a,0x106c,getter(o,'object'),2)
 if publish:
  r.put(a,0xe42,raw,1);r.put(a,0x285,material,1);v=vector(o,'defaultNormal',[0,1,0]) if r.fl(r.u(a,0x21c))==2e6 else vector(o,'groundNormal',[.25,1,-.5])
  for i,value in enumerate(v):r.put(a,0xf24+4*i,r.bits(value))
 height=r.f(o.get('upperHeight',2));r.put(a,0x220,r.bits(height));valid=height!=2e6
 if valid:
  value=getter(o,'upperType')&255;r.put(a,0x283,value,1)
  if o.get('modeA',0) and o.get('modeB',0) and value in [7,16]:r.put(a,0x220,r.bits(2e6));valid=False
  else:
   if value>16:value=0
   r.put(a,0x283,value&~(o.get('maskA',0)|o.get('maskB',0)|0x40),1);z['angles']=normal(vector(o,'upperNormal',[-.5,1,.25]));r.put(a,0x105c,z['angles'][0],2);r.put(a,0x105e,z['angles'][1],2)
 if not valid:r.put(a,0x105c,0,2);r.put(a,0x105e,0,2);r.put(a,0x283,255,1)
 height=r.f(o.get('lowerHeight',-2));r.put(a,0x224,r.bits(height));value=255 if height==2e6 else getter(o,'lowerType')&255
 if height!=2e6 and value>31:value=0
 r.put(a,0x284,value,1);callback(a,o,z)
def callback(a,o,z):
 if o.get('callback',True):z['events'].append(['callback',A,probe(a)]);z['calls']+=1;effects(a,o,z['calls'])
def model(before,o,kind):
 a=copy.deepcopy(before);z=dict(angles=[0x1234,0x5678],events=[],calls=0)
 if kind=='apply':apply(a,o,o.get('publish',1),r.f(o.get('height',3)),z)
 else:
  z['events'].append(['query',A,A+0x5c,r.bits(5.),0xffffffff]);height=r.f(o.get('queryHeight',3));r.put(a,0x21c,r.bits(height));apply(a,o,0 if height==2e6 else 1,height,z)
  if height==2e6:
   r.put(a,0xd6c,0);r.put(a,0x285,0,1);r.put(a,0xe42,0,1)
   for i,value in enumerate(vector(o,'defaultNormal',[0,1,0])):r.put(a,0xf24+i*4,r.bits(value))
  else:
   r.put(a,0xd6c,r.bits(1. if o.get('materialFlags',10)&8 else 0.));z['angles']=normal([r.fl(r.u(a,0xf24+i*4)) for i in range(3)])
   for off,index in [(0x1056,0),(0x1052,0),(0x1058,1),(0x1054,1)]:r.put(a,off,z['angles'][index],2)
  upper=r.fl(r.u(a,0x220));eligible=a[0x283] in [1,9];r.put(a,0x286,int(eligible and upper>=r.fl(r.u(a,0x84))),1);r.put(a,0x287,int(eligible and upper<=r.fl(r.u(a,0x188)) and r.fl(r.u(a,0x17c))<=upper),1)
  r.put(a,0x220,r.bits(2e6));r.put(a,0x224,r.bits(2e6));r.put(a,0x283,255,1);r.put(a,0x284,255,1);apply(a,o,1,r.fl(r.u(a,0x21c)),z)
  if not o.get('characterFlags',0)&0x8000 and r.fl(r.u(a,0x1014))==2e6 and r.h(a,0x106c)!=65535:
   z['events'].append(['secondary',A+0x5c]);height=r.f(o.get('secondaryHeight',2e6))
   if height!=2e6:r.put(a,0x1014,r.bits(height));r.put(a,0x107b,2,1)
  callback(a,o,z)
 return dict(changes=r.changes(before,a),angles=z['angles'],events=z['events'])
cases=[];errors=[];counts={}
def run(kind,o):
 if 'vector' in o:o=dict(o,vectorWords=[r.bits(v) for v in o['vector']])
 before=setup(o)
 if kind in ['apply','refresh']:
  n.call(0x572440 if kind=='apply' else 0x5728a0,[A,o.get('publish',1),r.bits(r.f(o.get('height',3)))] if kind=='apply' else [A]);got=dict(changes=r.changes(before,n.read(A,0x10d8)),angles=[n.unpack('<H',0x92b0c4)[0],n.unpack('<H',0x92b0c0)[0]],events=copy.deepcopy(events));want=model(before,o,kind)
 elif kind=='rotate':
  out=VEC if o.get('alias') else OUT;n.call(0x5b35a0,[out,VEC,o.get('angle',0)]);got=list(n.unpack('<3I',out));want=[r.bits(v) for v in rotate(vector(o,'vector',[.25,1,-.5]),o.get('angle',0))]
 elif kind=='normal':
  n.call(0x54fec0,[VEC,H1 if o.get('first',True) else 0,H2 if o.get('second',True) else 0]);got=[n.unpack('<H',0x92b0c4)[0],n.unpack('<H',0x92b0c0)[0],n.unpack('<H',H1)[0],n.unpack('<H',H2)[0]];values=normal(vector(o,'vector',[.25,1,-.5]));want=values+[values[0] if o.get('first',True) else 0x3333,values[1] if o.get('second',True) else 0x4444]
 else:
  got=n.call({'material':0x67a600,'upperType':0x67a670,'lowerType':0x67a690,'object':0x67a6e0}[kind]);want=getter(o,kind)&0xffffffff
 cases.append(dict(kind=kind,options=o,native=got));counts[kind]=counts.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 for kind in ['material','upperType','lowerType']:
  for value in [-1,*range(256)]:run(kind,{kind:value})
 for null,index,typ,oid in itertools.product([False,True],[-1,0,1,2],[0,1,2],[-32768,-1,0,7,32767]):run('object',dict(nullObject=null,objectIndex=index,objectKind=typ,objectId=oid))
 vectors=[[0,0,0],[1,0,0],[0,1,0],[0,0,1],[-.0,-.0,-.0],[.25,1,-.5],[1,2**-12,2**-27]]
 rng=random.Random(0x572440)
 vectors.extend([[r.f(rng.uniform(-10,10)) for _ in range(3)] for _ in range(160)])
 for v in vectors:
  for a in [0,1,16384,32767,32768,49152,65535]:
   for alias in [False,True]:run('rotate',dict(vector=v,angle=a,alias=alias))
  for first,second in itertools.product([False,True],repeat=2):run('normal',dict(vector=v,first=first,second=second))
 for kind in ['apply','refresh']:
  for material,flags,char in itertools.product([-1,0,1,31,32,255],[0,2,8,10],[0,0x8000]):run(kind,dict(material=material,materialFlags=flags,characterFlags=char))
  for upper,lower in itertools.product([-1,0,1,7,9,16,17,31,32,127,128,255],repeat=2):run(kind,dict(upperType=upper,lowerType=lower))
  for modeA,modeB,typ,mask in itertools.product([0,1],[0,1],[1,7,9,16],[0,1,8,255]):run(kind,dict(modeA=modeA,modeB=modeB,upperType=typ,maskA=mask))
  for height,publish,floor,up,low,cb in itertools.product([2e6,0,3],[0,1],[2e6,3],[2e6,2],[2e6,-2],[False,True]):run(kind,dict(height=height,queryHeight=height,publish=publish,floor=floor,upperHeight=up,lowerHeight=low,callback=cb))
 for typ,up,low,high,pred in itertools.product([1,9,7],[-2,0,2,6],[-1,2],[1,5],[0,3]):run('refresh',dict(upperType=typ,upperHeight=up,lowerY=low,upperY=high,predictedY=pred))
 for flags,oid,secondary in itertools.product([0,2,8,10],[-1,7],[2e6,0,-2,4]):run('refresh',dict(materialFlags=flags,objectId=oid,secondaryHeight=secondary))
 for off,val,size in [(0x283,9,1),(0x220,r.bits(6),4),(0x21c,r.bits(2e6),4),(0x1014,r.bits(2e6),4),(0x106c,7,2),(0xf24,r.bits(1.25),4)]:
  for call in [1,2,3]:run('refresh',dict(materialFlags=0,secondaryHeight=4,effects=[dict(call=call,offset=off,value=val,size=size)]))
 for fn in assembly['functions']:
  for row in fn['instructions']:row['executed']=int(row['address'],16) in executed
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],instructionCoverage={fn['address']:dict(total=len(fn['instructions']),executed=sum(row['executed'] for row in fn['instructions']),missing=[row['address'] for row in fn['instructions'] if not row['executed']]) for fn in assembly['functions']},services=['5506f0 actor-aware terrain query','553500 secondary height query','951010 optional callback']);(BASE/'reports/gameplay-terrain-state-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-terrain-state-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-terrain-state-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
