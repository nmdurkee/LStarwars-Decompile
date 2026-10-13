"""Original unmodified487270/62f1a0 takeover selector, no adapters."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_EDI
n=native.NativeX86();D=n.DATA;V=D+0x1000;R=D+0x4000;DEF=D+0x8000;CL=D+0x9000;MODEL=D+0xa000;CLIPS=D+0xb000
ids=[0x7f1814,0x7f1850,0x7f1934,0x7f1938,0x7f193c,0x7f1940,0x7f1aa4,0x7f1944,0x7f1948,0x7f194c,0x7f1950,0x7f1954,0x7f19bc,0x7f1920];actions=[0x70,0x83,0x84,0x86,0xc0,0xc1,0xc2,0xc3,0xc4];checks={};errors=[];cases=[];helpercalls=0
cs=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,size in [(0x487270,344),(0x62f1a0,20)]:assembly.append(dict(address=hex(a),size=size,bytes=n.read(a,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,size),a)]))
def observe(mu,a,size,data):
 global helpercalls
 if a==0x62f1a0:helpercalls+=1
n.mu.hook_add(UC_HOOK_CODE,observe)
def check(k,got,want,c):
 checks[k]=checks.get(k,0)+1
 if got!=want:errors.append(dict(group=k,got=got,want=want,input=c))
def prepare(c):
 n.write(D,bytes(0x10000));rng=random.Random(713)
 for a in [V,R]:n.write(a,bytes(rng.randrange(256)for _ in range(0x1100)))
 n.pack('<I',V+0x54,0 if c.get('nullDef')else DEF);n.pack('<I',DEF+0x24,0 if c.get('nullClass')else CL);n.pack('<B',CL+0x116,c.get('subtype',0));n.pack('<I',R+0x50,0 if c.get('nullModel')else MODEL);n.pack('<I',MODEL+0xc,0 if c.get('nullClips')else CLIPS);n.pack('<h',V+0x1064,c.get('type',100));n.pack('<B',V+8+0x31,c.get('active',0));n.pack('<hh',V+8+0x34,c.get('action34',3),c.get('action36',23));n.pack('<I',0x7f39e4,c.get('gate',1)&0xffffffff)
 values=c.get('runtimeIds',list(range(100,114)))
 for a,x in zip(ids,values):n.pack('<h',a,x)
 for action in actions:n.pack('<I',CLIPS+action*4,0xffffffff if action in c.get('available',actions)else 0)
 return [dict(address=p,bytes=n.read(p,z).hex())for p,z in [(V,0x1100),(R,0x1100),(DEF,0x100),(CL,0x200),(MODEL,0x100),(CLIPS,0x400),(0x7f39e4,4)]+[(a,2)for a in ids]]
def expected(c):
 vals=c.get('runtimeIds',list(range(100,114)));t=c.get('type',100);q=0
 if c.get('nullVehicle'):return None,q,True
 if t==vals[0]:a=0x70
 elif t==vals[1]:a=0x83
 elif not c.get('gate',1):return 0x6c,q,c.get('nullRider',False)
 else:
  if c.get('nullDef')or c.get('nullClass'):return None,q,True
  if c.get('subtype',0)==12:
   v=c.get('action34',3)if c.get('active',0)else c.get('action36',23);q=1 if v==3 else 2;a=0xc4 if v in [3,23]else 0xc3
  elif t in [vals[2],vals[3]]:a=0x70
  elif t==vals[4]:a=0x83
  elif t in [vals[5],vals[6]]:a=0x84
  elif t==vals[7]:a=0x86
  elif t==vals[8]:a=0xc0
  elif t in [vals[9],vals[10]]:a=0xc1
  elif t==vals[11]:
   if c.get('nullRider')or c.get('nullModel')or c.get('nullClips'):return None,q,True
   a=0xc2 if 0xc2 in c.get('available',actions)else 0xc1
  elif t==vals[12]:a=0xc1
  elif t==vals[13]:a=0xc0
  else:return 0x6c,q,c.get('nullRider',False)
 if c.get('nullRider')or c.get('nullModel')or c.get('nullClips'):return None,q,True
 return a if a in c.get('available',actions)else 0x6c,q,False
def execute(c):
 global helpercalls
 initial=prepare(c);beforeV=n.read(V,0x1100);beforeR=n.read(R,0x1100);helpercalls=0;fault=None;v=0 if c.get('nullVehicle')else V;r=0 if c.get('nullRider')else V if c.get('sameActor')else R
 if c.get('sameActor'):n.pack('<I',V+0x50,MODEL);initial= [dict(address=x['address'],bytes=n.read(x['address'],len(x['bytes'])//2).hex())for x in initial];beforeV=n.read(V,0x1100)
 try:n.call(0x487270,[],{UC_X86_REG_ECX:v,UC_X86_REG_EDI:r})
 except RuntimeError as e:fault=str(e)
 action,count,expectedFault=expected(c);check('selector-fault-parity',fault is not None,expectedFault,c);check('actual-current-action-call-count',helpercalls,count,c)
 wantV=bytearray(beforeV);wantR=bytearray(beforeR)
 if not expectedFault:struct.pack_into('<H',wantV if c.get('sameActor')else wantR,0x7aa,action)
 got=[n.read(V,0x1100).hex(),n.read(R,0x1100).hex()];check('only-selected-short-write',got,[wantV.hex(),wantR.hex()],c);cases.append(dict(context=c,vehicle=v,rider=r,initial=initial,nativeActors=got,nativeFault=fault,currentActionCalls=helpercalls))
for t,gate,subtype,available in itertools.product(list(range(100,115))+[-1,-32768,32767],[0,1,-1],[0,12,255],[actions,[],[0xc1],[0xc2]]):execute(dict(type=t,gate=gate,subtype=subtype,available=available))
for active,a34,a36,available in itertools.product([0,1,255],[3,23,-1,-32768,32767,0],[3,23,-1,-32768,32767,0],[actions,[],[0xc3],[0xc4]]):execute(dict(type=114,subtype=12,active=active,action34=a34,action36=a36,available=available))
# Runtime-ID collisions exercise exact priority, including default-all-FFFF image IDs.
for values,t in [(list(range(100,114)),100),([-1]*14,-1),([77]*14,77),([0]*14,0),([100,101]+[77]*12,77)]:
 for available in [actions,[],[0xc1],[0xc2]]:execute(dict(runtimeIds=values,type=t,available=available,subtype=12))
for flag,t,gate in itertools.product(['nullVehicle','nullRider','nullDef','nullClass','nullModel','nullClips'],[100,102,111,114],[0,1]):execute({flag:True,'type':t,'gate':gate})
for t,subtype in itertools.product([100,102,111,114],[0,12]):execute(dict(type=t,subtype=subtype,sameActor=True))
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,cases=len(cases),adapters=[],limitations=['Prepared runtime type IDs and mapped definition/model/clip backing; no invented live table bounds.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,cases=cases)),('assembly',dict(binarySha256=n.sha256,functions=assembly))]:(native.BASE/'reports'/('script-phase9-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
