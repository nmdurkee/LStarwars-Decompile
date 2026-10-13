"""Original41c120 caller and three actual helpers; explicit lifecycle callbacks.
Only detached emulated memory is touched. Complete byte changes and ordered calls
are compared with an independent model, not merely retained as native traces.
"""
import importlib.util,json,struct,copy,itertools,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
x=load('native','native-x86.py');wide=load('wide','animation-x87.py');n=x.NativeX86();BASE=x.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
A=D;SYS=D+0x2000;WORLD=D+0x3000;CHAR=D+0x6000;TUNE=D+0x7000;MODEL=D+0x8000;RIG=D+0x9000;SPAWN=D+0xa000;LOC=D+0xc000;FORM=D+0x10000;PATH=D+0x20000;MASKS=D+0x22000;SCRATCH=D+0x30000
SINE_BYTES=(BASE/'references/native-animation-sine-table.f32').read_bytes();SINE=struct.unpack('<32768f',SINE_BYTES)
OPERATIONS={0x498a40:('BeforeReset',1),0x41b0a0:('ResetActor',1),0x41af70:('ResetMoves',1),0x55e4a0:('ClearRuntimeSystems',2),0x55e4e0:('ResetMovementContext',1),0x547cb0:('StartAccessory',3),0x5728a0:('ResetTerrain',1),0x572660:('ClearTerrain',2),0x51b890:('BindPath',4),0x514640:('BindScript',9),0x52f800:('ResetState',5),0x62e650:('SetAnimation',2),0x62e6c0:('CommitAnimation',2),0x55d6a0:('AssignRoom',5)}
ENTRIES=[(0x41c120,0x4fc),(0x4b6b80,0x6f),(0x51a7c0,0xc6),(0x5b3710,0x48)]
checks={};errors=[];vectors=[];executed=set();events=[];options={}
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f(v):return fl(bits(v))
def u(b,p):return struct.unpack_from('<I',b,p)[0]
def h(b,p):return struct.unpack_from('<H',b,p)[0]
def put(b,p,v,size=4):b[p:p+size]=int(v&((1<<(size*8))-1)).to_bytes(size,'little')
def pattern(size,seed):return bytearray((i*37+seed*11)&255 for i in range(size))
def shift(c):c&=255;return 1<<c if c<32 else 0
def mul(a,b):return fl((bits(a)^bits(b))&0x80000000) if a==0 or b==0 else wide.store(wide.mul(wide.wide(a),wide.wide(b)))
def add(a,b):return fl(bits(a)&bits(b)&0x80000000) if a==0 and b==0 else wide.store(wide.add(wide.wide(a),wide.wide(b)))
def products(a,b,c,d):
 if (a==0 or b==0) and (c==0 or d==0):return add(mul(a,b),mul(c,d))
 return wide.store(wide.add(wide.mul(wide.wide(a),wide.wide(b)),wide.mul(wide.wide(c),wide.wide(d))))
def direction(speed,angle):return [bits(mul(speed,SINE[(angle>>1)&32767])),0,bits(mul(speed,SINE[((angle+16384)>>1)&32767]))]
def probe(b):return [u(b,0x5c),u(b,0x4b0),b[0x406],u(b,0x420)]
def effects(b,name,o):
 for e in o.get('effects',[]):
  if e['operation']==name:put(b,e['offset'],e['value'],e.get('size',4))
def hook(mu,addr,size,user):
 name,count=OPERATIONS[addr];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4));events.append([name,args,probe(n.read(A,0x10d8))])
 b=bytearray(n.read(A,0x10d8));effects(b,name,options);n.write(A,b)
 mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EAX,0)
for addr in OPERATIONS:n.mu.hook_add(UC_HOOK_CODE,hook,begin=addr,end=addr)
def trace(mu,addr,size,user):executed.add(addr)
for start,size in ENTRIES:n.mu.hook_add(UC_HOOK_CODE,trace,begin=start,end=start+size-1)
def initial(o):
 b=pattern(0x10d8,o.get('seed',1));formation=pattern(0x54+256*0x34,o.get('seed',1)+3)
 for at,v in [(0x50,MODEL),(0x54,CHAR),(0x478,LOC if o.get('locator',False) else 0),(0x40c,FORM if o.get('formation',False) else 0),(0x4c4,o.get('count',0)),(0x420,PATH if o.get('samePath',False) else 0),(0x3f8,o.get('maskLow',0xa5a5a5a5)),(0x3fc,o.get('maskHigh',0x80000001))]:put(b,at,v)
 for at,v in [(0x400,o.get('spawn',0)),(0x410,o.get('slot',0)),(0x411,o.get('column',0)),(0x412,o.get('row',0)),(0x281,o.get('ground',0))]:put(b,at,v,1)
 put(b,0xe1c,o.get('accessoryState',17),2);put(b,0xe24,o.get('accessoryFlags',0x12340000))
 for at,v in [(0x5c,20.),(0x60,30.),(0x64,40.)]:put(b,at,bits(v))
 spawns=[]
 for i in range(3):
  s=pattern(0xa4,4+i);put(s,0x4c,3+i,1);put(s,0x48,o.get('spawnFlags',i&1),1);put(s,0x51,o.get('columns',3),1)
  for j,v in enumerate(o.get('position',[1.25+i,-2.5-i,3.75+i])):put(s,0x20+j*4,bits(f(v)))
  put(s,0x2c,o.get('angle',0x2345));put(s,0x5c,bits(o.get('spacing',1.25)));put(s,0x60,bits(o.get('rowSpacing',2.75)))
  put(s,0x30,0 if o.get('nullPath',False) else PATH);put(s,0x34,0x12345600+i);put(s,0x38,7+i,1)
  for j in range(4):put(s,0x94+4*j,bits(i+j+.125))
  spawns.append(s)
 loc=pattern(0x3c,9)
 for j,v in enumerate([19.5,23.25,-17.75]):put(loc,0x10+4*j,bits(v))
 put(loc,0x1c,o.get('locatorAngle',0xdeadbeef));put(loc,0x20,0 if o.get('nullPath',False) else PATH);put(loc,0x24,0x87654321);put(loc,0x28,254,1)
 masks=o.get('masks',[0,1,0x100000000,0x8000000000000000,0x400,0xffffffffffffffff])
 char=dict(flags=o.get('characterFlags',0),callback=o.get('callback',0),accessory=o.get('accessory',-1),magnitude=o.get('magnitude',9),f4=33,f5=44)
 return dict(actor=b,formation=formation,spawns=spawns,locator=loc,masks=masks,char=char,origin=[0xaaaa0001,0xbbbb0002,0xcccc0003],reset=[bits(v) for v in o.get('reset',[0.,0.,0.])])
def setup(o):
 global options,events
 options=o;events=[];z=initial(o);n.write(D,bytes(0x31000));n.write(A,z['actor']);n.write(FORM,z['formation'])
 n.write(0x29899a0,SINE_BYTES);n.pack('<I',0x802c54,WORLD);n.pack('<II',WORLD+0x2ae8,SYS,0);n.pack('<I',WORLD+0x13c,0x24681357);n.pack('<I',SYS+0x18,SPAWN)
 for i,s in enumerate(z['spawns']):n.write(SPAWN+0xa4*i,s)
 n.write(LOC,z['locator']);n.pack('<III',0x93d620,*z['origin']);n.pack('<III',0x93b0cc,*z['reset'])
 c=z['char'];n.pack('<I',CHAR+4,c['flags']);n.pack('<I',CHAR+0x18,c['callback']);n.pack('<I',CHAR+0x24,TUNE);n.pack('<h',TUNE+0xe8,c['accessory']);n.pack('<B',TUNE+0x11e,c['magnitude']);n.pack('<BB',TUNE+0xf4,c['f4'],c['f5']);n.pack('<I',MODEL+0xc,RIG);n.pack('<I',RIG+0x104,int(o.get('clip',False)))
 n.pack('<B',PATH+0x14,len(z['masks']));n.pack('<I',PATH+0x88,MASKS)
 for i,v in enumerate(z['masks']):n.pack('<Q',MASKS+0x28*i+0x18,v)
 return z
def model(z,o,kind='reinitialize'):
 z=copy.deepcopy(z);b=z['actor'];ev=[]
 def call(name,*args):ev.append([name,list(args),probe(b)]);effects(b,name,o)
 def copyv(to,fr):b[to:to+12]=b[fr:fr+12]
 def accessory():
  b[0x1085]=0;c=z['char']
  if c['accessory']!=-1:call('StartAccessory',A,c['accessory']&0xffffffff,bits(float(c['magnitude'])))
  if c['callback']!=0x4b5120 and h(b,0xe1c) and not u(b,0xe24)&0x2000:put(b,0xe1c,0,2)
 def pathbind(identity):
  p=0x2c8
  if u(b,p+0x158)==identity:return
  for at in [0x15c,0x160,0x164,0x168,0x16c,0x17c]:put(b,p+at,0)
  put(b,p+0x158,identity);b[p+0x161]=255;put(b,p+0x13a,0,2);put(b,p+0x124,65535,2);b[p+0x13c]=255;b[p+0x13d]=0
  if identity:
   member=u(b,p+0x130)|(u(b,p+0x134)<<32)
   for i,m in enumerate(z['masks']):
    if member&m:put(b,p+0x13a,h(b,p+0x13a)|(shift(i)&65535),2)
 if kind=='path':pathbind(0 if o.get('nullPath') else PATH);return z,ev
 if kind=='accessory':accessory();return z,ev
 if o.get('nullActor'):return z,ev
 call('BeforeReset',A);accessory()
 if o.get('noSystem'):return z,ev
 call('ResetActor',A);call('ResetMoves',A);call('ClearRuntimeSystems',A,1);call('ResetMovementContext',A+0x6c4)
 c=z['char'];b[0x107e]=b[0x107f]=c['f4'];b[0xe38]=c['f5'];b[0xe39]=4;spawn=z['spawns'][b[0x400]];spawnid=SPAWN+0xa4*b[0x400];b[0x378]=spawn[0x4c];put(b,0x4b0,((u(b,0x4b0)&~128)|(128 if spawn[0x48]&1 else 0))&~0x40000)
 b[0x230:0x240]=spawn[0x94:0xa4];lx=mul((b[0x411]+1)//2,fl(u(spawn,0x5c)))
 if b[0x411]&1:lx=fl(bits(lx)^0x80000000)
 lz=mul(b[0x412],fl(u(spawn,0x60)^0x80000000));loc=u(b,0x4c4)!=0 and u(b,0x478)!=0;basis=z['locator'] if loc else spawn;pos=0x10 if loc else 0x20;hd=0x1c if loc else 0x2c;path=0x20 if loc else 0x30;angle=u(basis,hd);sin=SINE[(angle>>1)&32767];cos=SINE[((angle+16384)>>1)&32767]
 v=[products(sin,lz,cos,lx),0.,products(lz,cos,-lx,sin)]
 for i in range(3):put(b,0x5c+4*i,bits(add(v[i],fl(u(basis,pos+4*i)))))
 if loc:put(b,0x478,0)
 copyv(0x80,0x5c);copyv(0x98,0x5c);z['origin']=[u(b,0x80+i*4) for i in range(3)];copyv(0x8c,0x80)
 for i,v in enumerate(z['reset']):put(b,0xdf8+i*4,v);put(b,0x68+i*4,v)
 call('ResetTerrain',A);call('ClearTerrain',A,0)
 for at in [0x27a,0x58,0x5a]:put(b,at,angle,2)
 for i,v in enumerate(direction(1.,angle&65535)):put(b,0xf30+i*4,v)
 pathbind(u(basis,path));call('BindPath',A+0x2c8,A+0x5c,u(basis,path+4),basis[path+8]);b[0x28b]=0
 call('BindScript',SYS,A+0x2c8,A+0x2c8,spawnid,spawnid+0x10,0,1,0,0);put(b,0x3ec,65535,2);b[0x404]=255;b[0x405]=0
 call('ResetState',SYS,A,A+0x2c8,255,(b[0x281] if b[0x281]<128 else b[0x281]-256)&0xffffffff);call('SetAnimation',A+8,1);call('CommitAnimation',u(b,0x50),A+8)
 put(b,0x3d8,0);put(b,0x1090,0);put(b,0x4b0,u(b,0x4b0)&~0x1000000);copyv(0x3cc,0x5c);put(b,0x44c,0);b[0x1086]=b[0x1087]=0
 call('AssignRoom',A,1,1,0xffffffff,0x24681357);form=u(b,0x40c);put(b,0x1fc,u(b,0x1fc)|0x1000);put(b,0x4c4,u(b,0x4c4)+1);b[0x406]=2
 if form:
  g=z['formation'];put(g,0x4c,u(g,0x4c)|shift(b[0x410]));row=0x54+0x34*b[0x412];g[row+0x2d]|=shift(b[0x410]-b[0x412]*spawn[0x51])&255
  if b[0x411]==0:g[row+0x18:row+0x24]=b[0x5c:0x68];g[row:row+0x18]=b[0x420:0x438];put(g,row+0x24,h(b,0x27a));put(g,row+0x28,0);put(g,row+0x30,u(g,row+0x30)&~2)
 copyv(0x1b4,0x5c);copyv(0x10bc,0x5c)
 if c['flags']&0x20000000 and o.get('clip'):put(b,0x77c,0x4e6e6b28);b[0x7b5]=0x17;put(b,0x7aa,0x41,2);call('SetAnimation',A+8,0x41)
 return z,ev
def changes(a,b):
 out=[];i=0
 while i<len(a):
  if a[i]==b[i]:i+=1;continue
  j=i+1
  while j<len(a) and a[j]!=b[j]:j+=1
  out.append([i,bytes(b[i:j]).hex()]);i=j
 return out
def summarize(before,after,ev):return dict(actor=changes(before['actor'],after['actor']),formation=changes(before['formation'],after['formation']),origin=after['origin'],events=ev)
def run(o,kind='reinitialize'):
 before=setup(o);addr,args={'reinitialize':(0x41c120,[0 if o.get('nullActor') else A,0 if o.get('noSystem') else SYS]),'accessory':(0x4b6b80,[A]),'path':(0x51a7c0,[A+0x2c8,0 if o.get('nullPath') else PATH])}[kind]
 n.call(addr,args);after=dict(actor=n.read(A,0x10d8),formation=n.read(FORM,len(before['formation'])),origin=list(n.unpack('<III',0x93d620)));got=summarize(before,after,events);out,ev=model(before,o,kind);want=summarize(before,out,ev);checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
 saved=copy.deepcopy(o)
 if 'masks' in saved:saved['masks']=[format(v,'016x') for v in saved['masks']]
 vectors.append(dict(kind=kind,options=saved,native=got))
def check_direction(speed,angle):
 n.write(0x29899a0,SINE_BYTES);n.call(0x5b3710,[SCRATCH,bits(speed),angle]);got=list(n.unpack('<III',SCRATCH));want=direction(speed,angle);checks['direction']=checks.get('direction',0)+1
 if got!=want:errors.append(dict(kind='direction',speed=bits(speed),angle=angle,got=got,want=want))
 vectors.append(dict(kind='direction',speed=bits(speed),angle=angle,native=got))
def main():
 run({});run(dict(nullActor=True));run(dict(noSystem=True,accessory=17));run(dict(count=0xffffffff,formation=True))
 for loc,count,col,row in itertools.product([False,True],[0,1],[0,1,2,3,7,255],[0,1,31,255]):run(dict(locator=loc,count=count,column=col,row=row,formation=True,slot=(row*3+col)&255,accessory=12))
 for slot in [0,1,7,8,15,16,31,32,63,64,127,128,255]:
  for row,cols in [(0,3),(1,3),(255,255),(32,8)]:run(dict(formation=True,slot=slot,row=row,columns=cols))
 for flag,clip,spawn in itertools.product([0,0x20000000],[False,True],[0,1,2]):run(dict(characterFlags=flag,clip=clip,spawn=spawn,spawnFlags=spawn,locator=True,count=1))
 for grd in [0,1,127,128,255]:run(dict(ground=grd,reset=[-1.25,2.5,-3.75]))
 for op,at,value,size in [('BeforeReset',0x400,2,1),('ResetActor',0x411,7,1),('ResetMoves',0x412,3,1),('ResetMovementContext',0x400,1,1),('ResetTerrain',0x5c,bits(99.5),4),('ClearTerrain',0x60,bits(-12.25),4),('BindPath',0x5c,bits(1.125),4),('BindScript',0x281,255,1),('ResetState',0x5c,bits(-16.5),4),('SetAnimation',0x4b0,0xffffffff,4),('CommitAnimation',0x64,bits(51.),4),('AssignRoom',0x40c,FORM,4),('AssignRoom',0x410,31,1),('AssignRoom',0x4c4,0xffffffff,4)]:run(dict(effects=[dict(operation=op,offset=at,value=value,size=size)],column=0,row=2))
 for accessory,callback,state,flags in itertools.product([-32768,-1,0,32767],[0,0x4b5120],[0,17,65535],[0,0x2000]):run(dict(accessory=accessory,callback=callback,accessoryState=state,accessoryFlags=flags,magnitude=255),'accessory')
 run(dict(accessory=4,effects=[dict(operation='StartAccessory',offset=0xe24,value=0x2000)]),'accessory')
 for same,null,count,mask in itertools.product([False,True],[False,True],[0,1,16,17,32,64,65,255],[0,0xffffffffffffffff,0x8000000000000000]):run(dict(samePath=same,nullPath=null,masks=[(1<<(i%64)) for i in range(count)],maskLow=mask&0xffffffff,maskHigh=mask>>32),'path')
 for speed,angle in itertools.product([0.,-0.,1.,-1.,.125,2000.],[0,1,2,16383,16384,32767,32768,49152,65535,65536,0x7fffffff,0xffffffff]):check_direction(speed,angle)
 rng=random.Random(410120)
 for i in range(256):check_direction(f(rng.uniform(-1000,1000)),rng.randrange(2**32))
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,size in ENTRIES:
  ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in d.disasm(n.read(start,size),start)];functions.append(dict(address=hex(start),endExclusive=hex(start+size),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:5],method='Original41c120 executes real4b6b80,51a7c0,5b3620,5b37d0,5b3710 and CRT64-bit shift. Fourteen external lifecycle services record arguments/probe state and selected fixtures mutate actor bytes. Entire actor and256-row formation images are compared as sparse byte deltas with an independent finite-x87 model.',instructionCoverage={p['address']:dict(total=len(p['instructions']),executed=sum(i['executed'] for i in p['instructions']),missing=[i['address'] for i in p['instructions'] if not i['executed']]) for p in functions},limits=['Loaded finite actor/spawn/locator/path/formation records; malformed pointers and nonfinite float payloads excluded.','Fourteen explicit services preserve call order/arguments; their downstream allocation, terrain, path traversal, scripts, animation and room effects are not implemented by this contract.','Actual path-set binder covered separately; path traversal51b890 remains a service.','Managed core/harness compile only; no generated managed executable is launched.'])
 (BASE/'reports/gameplay-reinitialization-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-reinitialization-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-reinitialization-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
