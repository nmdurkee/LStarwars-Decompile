"""Original pool/default helpers, plus clone misses using real constructor."""
import ast,importlib.util,json,struct,gzip,hashlib,itertools,math,random
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA;SIZE=0xb000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
pool=BASE+0x4000;queue=BASE+0x9000;material=BASE+0x2000;container=BASE+0x100;source=BASE+0x400;cases=[];errors=[];sources=[];calls=[];counts={'reset':0,'initialize':0,'allocate':0,'cloneIntegration':0,'authoredMaterials':0,'checkedBytes':0,'constructorCalls':0};options={}
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def hh(b,p):return struct.unpack_from('<H',b,p-BASE)[0]
def wh(b,p,v):struct.pack_into('<H',b,p-BASE,v&65535)
def reset(b,p):
 if not p:return
 b[p-BASE:p-BASE+520]=bytes(520)
 for off,value in[(0x1b8,0x1000),(0x24,0x3f800000),(0x13c,0x101),(0,0x1000),(0x14,0xff8080ff)]+[(0x10c+i*4,0xffffffff)for i in range(4)]:w(b,p+off,value)
def initialize(b,p,registered):
 reset(b,p+0xb4);count=struct.unpack_from('<h',b,p-BASE+0x74)[0]
 if count<1:
  color=[]
  for off in[0x54,0x58,0x5c]:
   product=struct.unpack_from('<f',b,p-BASE+off)[0]*255.;assert math.isfinite(product)and -2147483648<=product<=2147483647;color.append(int(product)&255)
  w(b,p+0xc8,0xff000000|color[2]<<16|color[1]<<8|color[0])
 else:w(b,p+0xb8,count);b[p-BASE+0x15c]=1;w(b,p+0x1f0,0x901)
 if registered==0:w(b,p+0x1f0,u(b,p+0x1f0)|0x40000)
def allocate(b,o,count,typeword,registered):
 head=0
 for j in range(count):
  p=next((pool+i*708 for i in range(o['capacity'])if not(b[pool+i*708-BASE]&1)and u(b,pool+i*708+0x3c)==0),0);assert p
  b[p-BASE:p-BASE+708]=bytes(708)
  for off,value in[(0x54,0x3f800000),(0x58,0x3f800000),(0x5c,0x3f800000),(0x70,0x3f800000),(0x44,0x10),(0x40,0x3f962010)]:w(b,p+off,value)
  wh(b,p,((typeword&255)<<4)|5)
  if registered==0:w(b,p+0x44,u(b,p+0x44)|0x800000)
  else:w(b,queue+o['pending']*4,p);o['pending']+=1
  w(b,p+0x30,head);head=p
 initialize(b,head,registered);return head
cs={'BASE':BASE,'struct':struct,'container':container,'u':u,'w':w,'hh':hh,'wh':wh}
for node in ast.parse((B/'tools/geometry-material-clone-native.py').read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in{'nextnode','allocate','find','declaration','refresh'}:exec(compile(ast.Module(body=[node],type_ignores=[]),'clone-model','exec'),cs)
def clone(b,o):
 layout=u(b,source+0x1f0);existing=cs['find'](b,material,layout)
 if existing:return existing
 node=cs['allocate'](b,container,77);p=allocate(b,o,1,o['typeWord'],1);w(b,node,p);w(b,node+4,material);w(b,node+8,layout);save28=u(b,p+0x28);save2c=u(b,p+0x2c);b[p-BASE:p-BASE+708]=b[material-BASE:material-BASE+708];wh(b,p+0x1f4,0);wh(b,p+0x1f6,0);w(b,p+0x28,save28);w(b,p+0x2c,save2c);wh(b,p,hh(b,p)|1);w(b,p+0x1f0,layout);w(b,p+0x2bc,cs['declaration'](layout));cs['refresh'](b,p,{'refreshXor':o['refreshXor'],'counter':65535});wh(b,p+0x2c0,hh(b,p+0x2c0)+1);return cs['find'](b,material,layout)
def observe(mu,address,size,_):
 calls.append(address)
 if address==0x601030:
  sp=mu.reg_read(UC_X86_REG_ESP);p=n.unpack('<I',sp+4)[0];b=bytearray(n.read(BASE,SIZE));cs['refresh'](b,p,{'refreshXor':options['refreshXor'],'counter':65535});n.write(BASE,b);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);mu.reg_write(UC_X86_REG_EAX,0)
for a in[0x5e5140,0x600f20,0x5e4b20,0x4ffaa0,0x4ffac0,0x601030,0x7418c0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def setup(seed):
 b=bytearray(SIZE)
 for i in range(SIZE):b[i]=(i*37+seed*17)&255
 for i in range(16):b[pool+i*708-BASE]=2 if i%3 else 1;w(b,pool+i*708+0x3c,0 if i%3!=2 else 0x1234)
 o={'capacity':16,'pending':0,'refreshXor':0,'typeWord':seed&0xffffffff};return b,o
def run(kind,b,a,o,label):
 global options
 expected=bytearray(b);eo=dict(o);ret=None;options=o
 if kind=='reset':reset(expected,a[0])
 elif kind=='initialize':initialize(expected,*a)
 elif kind=='allocate':ret=allocate(expected,eo,*a)
 else:ret=clone(expected,eo)
 n.write(BASE,b);n.pack('<I',0x96e560,pool);n.pack('<I',0x971590,o['capacity']);n.pack('<I',0x973e50,queue);n.pack('<I',0x973e4c,o['pending']);n.pack('<I',0x973fa4,0);n.pack('<I',0x973ff8,container);n.pack('<I',0x973ff4,o['typeWord']);n.pack('<I',0x297ad54,77);layout=u(b,source+0x1f0);n.pack('<I',0x297cc70,1);n.pack('<2I',0x297cc78,layout,cs['declaration'](layout));calls.clear()
 if kind=='reset':actualRet=n.call(0x5e5140,args=a)
 elif kind=='initialize':actualRet=n.call(0x600f20,args=a)
 elif kind=='allocate':actualRet=n.call(0x5e4b20,args=[a[2]],regs={UC_X86_REG_ECX:a[0],UC_X86_REG_EAX:a[1]})
 else:actualRet=n.call(0x5e5020,args=[source,material])
 actual=n.read(BASE,SIZE);pending=n.unpack('<I',0x973e4c)[0]
 for field,av,ev in[('memory',actual,bytes(expected)),('return',actualRet if ret is not None else None,ret),('pending',pending,eo['pending'])]:
  if av!=ev and len(errors)<20:errors.append({'kind':kind,'label':label,'field':field,'native':av if field!='memory'else None,'model':ev if field!='memory'else None,'offsets':[i for i,(v,x)in enumerate(zip(av,ev))if v!=x][:20]if field=='memory'else None})
 counts[kind]+=1;counts['checkedBytes']+=SIZE;counts['constructorCalls']+=calls.count(0x5e4b20);cases.append({'kind':kind,'label':label,'before':bytes(b).hex(),'args':a,'options':o,'nativeReturn':actualRet if ret is not None else None,'nativePending':pending,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeCalls':list(calls)})
for shift in range(17):b,o=setup(shift);run('reset',b,[0 if shift==16 else material+shift],o,['reset',shift])
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/index[sr['source']]['report']).read_text());ms=[m for m in data['materials']if m['recordSize']==708];selected=ms[::max(1,len(ms)//8)][:8];indices=[]
 for mi,mat in enumerate(selected):
  b,o=setup(si*8+mi);b[material-BASE:material-BASE+708]=raw[mat['address']:mat['address']+708]
  for registered in[0,1]:run('initialize',b,[material,registered],o,[sr['source'],mat['index'],registered])
  # Whole original clone miss now includes actual material constructor,
  # registration queue, default runtime initializer and declaration hit.
  b[container-BASE:container-BASE+32]=bytes(32);node=BASE+0x1000;b[node-BASE:node-BASE+64]=bytes(64);w(b,container,node);w(b,container+4,node);w(b,container+24,77);w(b,source+0x1f0,mat['formatBits']);o['refreshXor']=mi&1;run('cloneIntegration',b,[],o,[sr['source'],mat['index'],'clone']);counts['authoredMaterials']+=1;indices.append(mat['index'])
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'materialIndices':indices})
 if(si+1)%10==0:print('pool sources',si+1,'errors',len(errors),flush=True)
 if errors:break
for count,typeword,registered,pending in itertools.product([1,2,3,5],[0,1,15,255,0xffffffff],[0,1,-1],[0,595,599,600]):
 if registered and pending+count>600:continue
 b,o=setup(typeword&255);o['pending']=pending;run('allocate',b,[count,typeword,registered],o,['pool',count,typeword,registered,pending])
colors=[-257.,-1.,-0.,0.,.5,1.,1.5,257.,2**22,-2**22]
for textureCount,color,registered in itertools.product([-32768,-1,0,1,2,32767],colors,[0,1]):
 b,o=setup(textureCount&255);wh(b,material+0x74,textureCount);struct.pack_into('<3f',b,material-BASE+0x54,color,color*.5,-color);run('initialize',b,[material,registered],o,['colorTexture',textureCount,color,registered])
fp=R/'geometry-material-pool-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-material-pool-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['Original5e5140/600f20/5e4b20 and nested memset/zero-lock helpers execute unchanged. Successful positive-count pool and600-entry queue domain; lock token0.','480 original5e5020 clone chains include real pool constructor, cache/list helpers and declaration-cache lookup. Only shader refresh601030 remains a controlled mutable service in those cases.','Authored708-byte material fields are copied opaquely; initializer reads preserved RGB/signed texture count then resets runtime range. This is not complete game-state relocation.','Finite RGB*255 products inside signedInt32 range. Native temporarily forces truncation toward zero before low-byte packing. NaN/overflow FISTP behavior excluded.','Pool exhaustion,queue overflow,nonpositive allocation count and operating-system locks excluded. No managed/game/GPU launch.']};(R/'geometry-material-pool-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))
