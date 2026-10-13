"""Original CPU material refresh; only shader factory is a mutable boundary."""
import importlib.util,json,struct,gzip,hashlib,itertools,math
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA;SIZE=0x10000;material=BASE+0x2000;manager=BASE+0x4000;device=BASE+0x800;factoryResults=[manager+8*0x4d8+4,manager+9*0x4d8+4];deviceGlobal=0x29765c8+0x654
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
cases=[];errors=[];sources=[];calls=[];options={};ordinal=0;counts={'refresh':0,'lookup':0,'release':0,'firstMode':0,'secondMode':0,'defaultRequest':0,'modeRequest':0,'authoredMaterials':0,'factoryCalls':0,'checkedBytes':0}
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def hh(b,p):return struct.unpack_from('<H',b,p-BASE)[0]
def wh(b,p,v):struct.pack_into('<H',b,p-BASE,v&65535)
def lookup(index):return manager+index*0x4d8+4 if index<401 else 0
def release(b,p):w(b,p+4,u(b,p+4)-1)
def mode(b,first):return(16 if first else 1)if b[device-BASE+0x654]&32 else 0
def factory(b,args,o,number):
 p=factoryResults[0]if number==0 or o['variant']&1 else factoryResults[1];w(b,p+4,u(b,p+4)+1)
 if number==1 and o['variant']&2:wh(b,factoryResults[0],33)
 if number==0 and o['variant']&4:b[device-BASE+0x654]^=32
 if number==0 and o['variant']&8:wh(b,material+0x74,0)
 return p
def fmt(b):
 value=u(b,material+0x1f0);tc=struct.unpack_from('<h',b,material-BASE+0x74)[0]
 if tc>0 and not value&0x3800:value=(value&0xffffcfff)|0x800
 if u(b,material+0x44)&0x800000 and not u(b,material+0x3c):value|=0x40000
 return value
def model(kind,before,args,o):
 b=bytearray(before);trace=[];ret=None
 def request(runtime,p,md):
  a=[manager,runtime,p,md,0,0];result=factory(b,a,o,len(trace));trace.append(a);return result
 if kind=='lookup':ret=lookup(args[0])
 elif kind=='release':release(b,args[0])
 elif kind in['firstMode','secondMode']:ret=mode(b,kind=='firstMode')
 elif kind in['defaultRequest','modeRequest']:ret=request(args[0],args[1],0 if kind=='defaultRequest'else args[2])
 else:
  tc=struct.unpack_from('<h',b,material-BASE+0x74)[0]
  if tc>0:w(b,material+0xb8,tc);b[material-BASE+0x15c]=b[material-BASE+0x15c]or 1
  w(b,material+0x1f0,fmt(b))
  for off in[0x1f4,0x1f6]:
   index=struct.unpack_from('<h',b,material-BASE+off)[0]
   if index>0:release(b,lookup(index))
  if u(b,material+0x44)&0x800000 and not u(b,material+0x3c):wh(b,material+0x1f4,hh(b,request(material+0xb4,material,0)))
  else:
   first=request(material+0xb4,material,mode(b,True));second=request(material+0xb4,material,mode(b,False));wh(b,material+0x1f4,hh(b,first));wh(b,material+0x1f6,hh(b,second))
  w(b,material+0x2bc,u(b,material+0x1f0)^0x76543210)
  if hh(b,material+0x74)==0:
   colors=[int(struct.unpack_from('<f',b,material-BASE+off)[0]*255)&255 for off in[0x54,0x58,0x5c]];w(b,material+0xc8,0xff000000|colors[2]<<16|colors[1]<<8|colors[0])
 return b,ret,trace
def boundary(mu,address,size,_):
 global ordinal
 sp=mu.reg_read(UC_X86_REG_ESP);a=[mu.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<5I',sp+4));b=bytearray(n.read(BASE,SIZE));p=factory(b,a,options,ordinal);ordinal+=1;calls.append(a);n.write(BASE,b);n.write(deviceGlobal,b[device-BASE+0x654:device-BASE+0x655]);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EAX,p)
n.mu.hook_add(UC_HOOK_CODE,boundary,begin=0x7416a0,end=0x7416a0)
def setup(raw,seed):
 b=bytearray(SIZE);b[material-BASE:material-BASE+708]=raw;b[device-BASE+0x654]=32 if seed&1 else 0
 for i in range(12):p=lookup(i);wh(b,p,i+1);w(b,p+4,[0,1,0xffffffff,0x80000000][(i+seed)%4])
 wh(b,material+0x1f4,[0,1,2,65535][seed%4]);wh(b,material+0x1f6,[0,1,3,32768][(seed//4)%4]);return b,{'variant':seed%16}
def run(kind,b,a,o,label):
 global options,ordinal
 expected,ret,trace=model(kind,b,a,o);options=o;ordinal=0;calls.clear();n.write(BASE,b);n.pack('<I',0x297cc6c,manager);n.pack('<I',0x297ae20,0);n.write(deviceGlobal,b[device-BASE+0x654:device-BASE+0x655]);layout=fmt(b);n.pack('<I',0x297cc70,1);n.pack('<2I',0x297cc78,layout,layout^0x76543210)
 if kind=='refresh':nativeRet=n.call(0x601030,args=[material])
 elif kind=='lookup':nativeRet=n.call(0x741620,args=a)
 elif kind=='release':nativeRet=n.call(0x7415b0,args=a)
 elif kind in['firstMode','secondMode']:nativeRet=n.call(0x6e27d0 if kind=='firstMode'else 0x6e27f0,regs={UC_X86_REG_ECX:device})
 else:nativeRet=n.call(0x741770 if kind=='defaultRequest'else 0x741790,args=a)
 actual=n.read(BASE,SIZE)
 for field,av,ev in[('memory',actual,bytes(expected)),('return',nativeRet if ret is not None else None,ret),('factory',calls,trace)]:
  if av!=ev and len(errors)<20:errors.append({'kind':kind,'label':label,'field':field,'native':av if field!='memory'else None,'model':ev if field!='memory'else None,'offsets':[i for i,(x,y)in enumerate(zip(av,ev))if x!=y][:20]if field=='memory'else None})
 counts[kind]+=1;counts['factoryCalls']+=len(calls);counts['checkedBytes']+=SIZE;cases.append({'kind':kind,'label':label,'before':bytes(b).hex(),'args':a,'options':o,'nativeReturn':nativeRet if ret is not None else None,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeFactory':list(calls)})
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/index[sr['source']]['report']).read_text());ms=[m for m in data['materials']if m['recordSize']==708];selected=ms[::max(1,len(ms)//8)][:8];indices=[]
 for mi,mat in enumerate(selected):
  for flip in[0,1]:
   b,o=setup(raw[mat['address']:mat['address']+708],si*8+mi+flip*7);w(b,material+0x44,(u(b,material+0x44)&~0x800000)|(0x800000 if flip else 0));w(b,material+0x3c,0);run('refresh',b,[],o,[sr['source'],mat['index'],flip])
  counts['authoredMaterials']+=1;indices.append(mat['index'])
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'materialIndices':indices})
 if(si+1)%10==0:print('refresh sources',si+1,'errors',len(errors),flush=True)
 if errors:break
raw=bytes(708)
for tc,flag,control,variant in itertools.product([-32768,-1,0,1,32767],[0,0x800000],[0,0x1234],range(16)):
 b,o=setup(raw,variant);wh(b,material+0x74,tc);w(b,material+0x44,flag);w(b,material+0x3c,control);w(b,material+0x1f0,[0,0x1000,0x3000,0xffffffff][variant%4]);struct.pack_into('<3f',b,material-BASE+0x54,-1.,.5,257.);run('refresh',b,[],o,['branches',tc,flag,control,variant])
for indexValue in list(range(403))+[0x7fffffff,0x80000000,0xffffffff]:b,o=setup(raw,0);run('lookup',b,[indexValue],o,['lookup',indexValue])
for value in[0,1,2,0x7fffffff,0x80000000,0xffffffff]:b,o=setup(raw,0);w(b,factoryResults[0]+4,value);run('release',b,[factoryResults[0]],o,['release',value])
for value in range(256):
 b,o=setup(raw,value);b[device-BASE+0x654]=value
 for kind in['firstMode','secondMode']:run(kind,b,[],o,[kind,value])
for md in[0,1,16,0xffffffff]:
 b,o=setup(raw,0);run('modeRequest',b,[material+0xb4,material,md],o,['request',md])
b,o=setup(raw,0);run('defaultRequest',b,[material+0xb4,material],o,['default'])
fp=R/'geometry-material-refresh-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-material-refresh-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['Original601030 plus program-index/release/mode/wrapper helpers execute unchanged; only thiscall7416a0 shader factory is an explicit mutable boundary. Native wrappers and original cached declaration7418c0/741860 execute.','Controlled factory returns logical records, mutates reference counters, and can alias/change first-result index or device mode between requests. This is not a shader compiler/device implementation.','Zero-lock runtime297ae20=0; valid positive old shader IDs1..400 and finite used color products in signedInt32 range. Refresh fixtures use oldIDs1..3; standalone lookup covers boundary400/401.','Authored708-byte materials preserve source fields with controlled old shader slots/registration selector. Negative texture count skips color refresh; zero count updates; positive count adjusts layout.','Whole compact image, return where meaningful and six-argument factory ABI compared. Fixed device mode byte mirrored into explicit fixture location.','No managed/game/GPU launch.']};(R/'geometry-material-refresh-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))
