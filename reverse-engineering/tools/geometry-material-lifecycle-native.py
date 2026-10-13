"""Original clone→constructor→refresh chain with only shader factory boundary."""
import ast,importlib.util,json,struct,gzip,hashlib,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA;SIZE=0x18000;container=BASE+0x100;source=BASE+0x400;device=BASE+0x800;material=BASE+0x2000;pool=BASE+0x4000;queue=BASE+0x9000;manager=BASE+0x10000;factoryResults=[manager+8*0x4d8+4,manager+9*0x4d8+4];deviceGlobal=0x29765c8+0x654
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
def load(file,names,scope):
 for node in ast.parse((B/'tools'/file).read_text()).body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),file,'exec'),scope)
common={'BASE':BASE,'struct':struct,'container':container};load('geometry-material-clone-native.py',{'u','w','hh','wh','nextnode','allocate','find','declaration'},common);u=common['u'];w=common['w'];hh=common['hh'];wh=common['wh']
ps={'BASE':BASE,'struct':struct,'pool':pool,'queue':queue,'math':__import__('math'),'u':u,'w':w,'hh':hh,'wh':wh};load('geometry-material-pool-native.py',{'reset','initialize','allocate'},ps)
rs={'BASE':BASE,'struct':struct,'manager':manager,'device':device,'material':material,'factoryResults':factoryResults,'u':u,'w':w,'hh':hh,'wh':wh};load('geometry-material-refresh-native.py',{'lookup','release','mode','factory','fmt','model'},rs)
cases=[];errors=[];sources=[];factoryCalls=[];declarationCalls=[];originalCalls=[];ordinal=0;options={};counts={'miss':0,'hit':0,'changedLayoutReturnsZero':0,'authoredMaterials':0,'checkedBytes':0,'constructors':0,'refreshes':0,'factories':0,'declarations':0}
def model(before,o):
 b=bytearray(before);eo=dict(o);layout=u(b,source+0x1f0);existing=common['find'](b,material,layout)
 if existing:return b,existing,eo,[],[]
 node=common['allocate'](b,container,77);p=ps['allocate'](b,eo,1,o['typeWord'],1);w(b,node,p);w(b,node+4,material);w(b,node+8,layout);preserved28=u(b,p+0x28);preserved2c=u(b,p+0x2c);b[p-BASE:p-BASE+708]=b[material-BASE:material-BASE+708];wh(b,p+0x1f4,0);wh(b,p+0x1f6,0);w(b,p+0x28,preserved28);w(b,p+0x2c,preserved2c);wh(b,p,hh(b,p)|1);w(b,p+0x1f0,layout);w(b,p+0x2bc,common['declaration'](layout));rs['material']=p;secondLayout=rs['fmt'](b);b,_,trace=rs['model']('refresh',b,[],o);wh(b,p+0x2c0,hh(b,p+0x2c0)+1);return b,common['find'](b,material,layout),eo,trace,[layout,secondLayout]
def hook(mu,address,size,_):
 global ordinal
 originalCalls.append(address);sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x7418c0:declarationCalls.append(n.unpack('<I',sp+4)[0])
 elif address==0x7416a0:
  a=[mu.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<5I',sp+4));b=bytearray(n.read(BASE,SIZE));rs['material']=a[2];p=rs['factory'](b,a,options,ordinal);ordinal+=1;factoryCalls.append(a);n.write(BASE,b);n.write(deviceGlobal,b[device-BASE+0x654:device-BASE+0x655]);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EAX,p)
for address in[0x5e4b20,0x601030,0x7418c0,0x7416a0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def setup(raw,seed):
 b=bytearray(SIZE);b[material-BASE:material-BASE+708]=raw;node=BASE+0x1000;w(b,container,node);w(b,container+4,node+3*64);w(b,container+24,77)
 for i in range(4):w(b,node+i*64+4,node+(i+1)*64 if i<3 else 0);w(b,node+i*64+8,node+(i-1)*64 if i else 0)
 b[device-BASE+0x654]=32 if seed&1 else 0
 for i in range(12):p=manager+i*0x4d8+4;wh(b,p,i+1);w(b,p+4,0xffffffff if seed&2 else i)
 w(b,source+0x1f0,u(b,material+0x1f0));return b,{'capacity':16,'pending':seed%3,'variant':seed%16,'typeWord':seed&0xffffffff}
def run(kind,b,o,label):
 global ordinal,options
 expected,ret,eo,trace,decl=model(b,o);options=o;ordinal=0;factoryCalls.clear();declarationCalls.clear();originalCalls.clear();n.write(BASE,b)
 for p,v in[(0x973ff8,container),(0x973ff4,o['typeWord']),(0x297ad54,77),(0x96e560,pool),(0x971590,o['capacity']),(0x973e50,queue),(0x973e4c,o['pending']),(0x973fa4,0),(0x297ae20,0),(0x297cc6c,manager)]:n.pack('<I',p,v)
 keys=sorted(set(decl or[u(b,source+0x1f0)]));n.pack('<I',0x297cc70,len(keys));n.write(0x297cc78,b''.join(struct.pack('<2I',k,common['declaration'](k))for k in keys));n.write(deviceGlobal,b[device-BASE+0x654:device-BASE+0x655]);actualRet=n.call(0x5e5020,args=[source,material],count=500000);actual=n.read(BASE,SIZE);pending=n.unpack('<I',0x973e4c)[0]
 for field,av,ev in[('memory',actual,bytes(expected)),('return',actualRet,ret),('pending',pending,eo['pending']),('factory',factoryCalls,trace),('declarations',declarationCalls,decl)]:
  if av!=ev and len(errors)<20:errors.append({'kind':kind,'label':label,'field':field,'native':av if field!='memory'else None,'model':ev if field!='memory'else None,'offsets':[i for i,(v,x)in enumerate(zip(av,ev))if v!=x][:20]if field=='memory'else None})
 counts[kind]+=1;counts['checkedBytes']+=SIZE;counts['changedLayoutReturnsZero']+=int(actualRet==0);counts['constructors']+=originalCalls.count(0x5e4b20);counts['refreshes']+=originalCalls.count(0x601030);counts['factories']+=len(factoryCalls);counts['declarations']+=len(declarationCalls);cases.append({'kind':kind,'label':label,'before':bytes(b).hex(),'options':o,'nativeReturn':actualRet,'nativePending':pending,'nativeFactory':list(factoryCalls),'nativeDeclarations':list(declarationCalls),'nativeSHA256':hashlib.sha256(actual).hexdigest()});return expected,ret,eo
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/index[sr['source']]['report']).read_text());ms=[m for m in data['materials']if m['recordSize']==708];selected=ms[::max(1,len(ms)//8)][:8];indices=[]
 for mi,mat in enumerate(selected):
  b,o=setup(raw[mat['address']:mat['address']+708],si*8+mi);after,ret,eo=run('miss',b,o,[sr['source'],mat['index']])
  if ret:run('hit',after,eo,[sr['source'],mat['index']])
  counts['authoredMaterials']+=1;indices.append(mat['index'])
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'materialIndices':indices})
 if(si+1)%10==0:print('lifecycle sources',si+1,'errors',len(errors),flush=True)
 if errors:break
for tc,flag,variant in itertools.product([-1,0,1],[0,0x800000],range(16)):
 b,o=setup(bytes(708),variant);wh(b,material+0x74,tc);w(b,material+0x44,flag);struct.pack_into('<3f',b,material-BASE+0x54,1.,.5,-1.);wh(b,material+0x2c0,65535);run('miss',b,o,['synthetic',tc,flag,variant])
fp=R/'geometry-material-lifecycle-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-material-lifecycle-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['Complete original5e5020→cache/node→5e4f30→5e4b20/defaults/queue→601030/ref/mode/wrappers and declaration-cache hits execute unchanged. Only7416a0 shader factory is a mutable controlled service.','Finite successful capacity, zero locks, same-thread cache, valid current708-byte material copies. Raw internal pointers are opaque except fields consumed by this chain.','Factory callback alias/index/device/texture mutations retained. Real refresh can change clone layout and cause original final lookup to return0; no fabricated successful clone return.','Authored480material records from60scenes plus synthetictexture/layout/registration cases. Native versus composed Python evidence; managed execution separate.','Device creation,shader compiler/cache internals,invalid capacities/pointers/conversions and GPU output excluded. No managed/game/GPU launch.']};(R/'geometry-material-lifecycle-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))
