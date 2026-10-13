"""Original normal submission through different-layout clone lifecycle."""
import ast,importlib.util,json,struct,gzip,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
# Reuse the already-verified normal fixture/model helpers, stopping before its
# authored-case batch. No original instructions are patched by model loading.
path=B/'tools/geometry-dynamic-submission-native.py';tree=ast.parse(path.read_text());prefix=[]
for node in tree.body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='index'for t in node.targets):break
 prefix.append(node)
ns={'__file__':str(path)};exec(compile(ast.Module(body=prefix,type_ignores=[]),str(path),'exec'),ns);n=ns['n'];BASE=ns['BASE'];SIZE=0x30000;ns['SIZE']=SIZE
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
pool=BASE+0x10000;queue=BASE+0x18000;container=BASE+0x19000;nodes=BASE+0x19200;device=BASE+0x1a000;PENDING=BASE+0x1a700;manager=BASE+0x20000;factoryResults=[manager+8*0x4d8+4,manager+9*0x4d8+4];deviceGlobal=0x29765c8+0x654;u=ns['u'];w=ns['w'];hh=lambda b,p:struct.unpack_from('<H',b,p-BASE)[0]
def wh(b,p,v):struct.pack_into('<H',b,p-BASE,v&65535)
def load(file,names,scope):
 for node in ast.parse((B/'tools'/file).read_text()).body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),file,'exec'),scope)
cs={'BASE':BASE,'struct':struct,'container':container,'u':u,'w':w,'hh':hh,'wh':wh};load('geometry-material-clone-native.py',{'nextnode','allocate','find','declaration'},cs)
ps={'BASE':BASE,'struct':struct,'pool':pool,'queue':queue,'math':__import__('math'),'u':u,'w':w,'hh':hh,'wh':wh};load('geometry-material-pool-native.py',{'reset','initialize','allocate'},ps)
rs={'BASE':BASE,'struct':struct,'manager':manager,'device':device,'material':0,'factoryResults':factoryResults,'u':u,'w':w,'hh':hh,'wh':wh};load('geometry-material-refresh-native.py',{'lookup','release','mode','factory','fmt','model'},rs);rawFactory=rs['factory']
expectedFactories=[];expectedDeclarations=[];actualFactories=[];actualDeclarations=[];nativeEntries=[];ordinal=0;currentOptions={}
def merge(b,source,replacement):
 layout=u(b,source+0x1f0);existing=cs['find'](b,replacement,layout)
 if existing:return existing
 node=cs['allocate'](b,container,77);po={'capacity':16,'pending':u(b,PENDING)};p=ps['allocate'](b,po,1,currentOptions['typeWord'],1);w(b,PENDING,po['pending']);w(b,node,p);w(b,node+4,replacement);w(b,node+8,layout);save28=u(b,p+0x28);save2c=u(b,p+0x2c);b[p-BASE:p-BASE+708]=b[replacement-BASE:replacement-BASE+708];wh(b,p+0x1f4,0);wh(b,p+0x1f6,0);w(b,p+0x28,save28);w(b,p+0x2c,save2c);wh(b,p,hh(b,p)|1);w(b,p+0x1f0,layout);w(b,p+0x2bc,cs['declaration'](layout));expectedDeclarations.append(layout);rs['material']=p;offset=len(expectedFactories);rs['factory']=lambda mem,args,opt,number:rawFactory(mem,args,opt,number+offset);after,_,trace=rs['model']('refresh',b,[],{'variant':currentOptions['factoryVariant']});b[:]=after;expectedFactories.extend(trace);expectedDeclarations.append(u(b,p+0x1f0));wh(b,p+0x2c0,hh(b,p+0x2c0)+1);return cs['find'](b,replacement,layout)
ns['materialMerge']=merge;ns['PENDING']=PENDING
modelNode=next(x for x in tree.body if isinstance(x,ast.FunctionDef)and x.name=='model');sourceModel=ast.get_source_segment(path.read_text(),modelNode);needle='material=replacement or source';assert sourceModel.count(needle)==1;sourceModel=sourceModel.replace(needle,'material=materialMerge(b,source,replacement) if replacement and u(b,source+0x1f0)!=u(b,replacement+0x1f0) else replacement or source');exec(compile(sourceModel,'normal-with-material-service-model','exec'),ns)
runNode=next(x for x in tree.body if isinstance(x,ast.FunctionDef)and x.name=='run');sourceRun=ast.get_source_segment(path.read_text(),runNode);needle='actual=bytearray(n.read(BASE,SIZE))';assert sourceRun.count(needle)==1;sourceRun=sourceRun.replace(needle,needle+";w(actual,PENDING,n.unpack('<I',0x973e4c)[0])");exec(compile(sourceRun,'normal-lifecycle-pending-mirror','exec'),ns)
def hook(mu,address,size,_):
 global ordinal
 nativeEntries.append(address);sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x7418c0:actualDeclarations.append(n.unpack('<I',sp+4)[0])
 elif address==0x7416a0:
  a=[mu.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<5I',sp+4));b=bytearray(n.read(BASE,SIZE));rs['material']=a[2];p=rawFactory(b,a,{'variant':currentOptions['factoryVariant']},ordinal);ordinal+=1;actualFactories.append(a);n.write(BASE,b);n.write(deviceGlobal,b[device-BASE+0x654:device-BASE+0x655]);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EAX,p)
for a in[0x5e5020,0x5e4b20,0x601030,0x7418c0,0x7416a0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
baseReport=json.loads((R/'geometry-dynamic-submission-native-validation.json').read_text());rows=json.loads(gzip.decompress((R/baseReport['fixtureFile']).read_bytes()))['cases'];selected=[c for c in rows if isinstance(c['label'][0],str)and c['label'][0]!='synthetic'and c['options']['forcedVisibility']==1][::4];counts={'cases':0,'clones':0,'mergeCalls':0,'refreshes':0,'factories':0,'declarations':0};materials=ns['materials']
for ci,row in enumerate(selected):
 for variant in range(3):
  b=bytearray.fromhex(row['before']);b.extend(bytes(SIZE-len(b)));o=dict(row['options']);o['globalOverride']=materials[5];o['overrideTable']=ns['overrides']if variant else 0;b[materials[0]-BASE+0x9a]=7 if variant else 0;w(b,ns['overrides']+28,materials[2]if variant==1 else 0);w(b,materials[5]+0x1f0,9);w(b,materials[2]+0x1f0,11);w(b,container,nodes);w(b,container+4,nodes+7*64);w(b,container+24,77)
  for i in range(8):w(b,nodes+i*64+4,nodes+(i+1)*64 if i<7 else 0);w(b,nodes+i*64+8,nodes+(i-1)*64 if i else 0)
  b[device-BASE+0x654]=32 if ci&1 else 0;w(b,PENDING,ci%4)
  for i in range(12):p=manager+i*0x4d8+4;wh(b,p,i+1);w(b,p+4,0xffffffff if ci&2 else i)
  currentOptions={'typeWord':ci,'factoryVariant':ci%16};ordinal=0;expectedFactories.clear();expectedDeclarations.clear();actualFactories.clear();actualDeclarations.clear();nativeEntries.clear()
  for p,v in[(0x973ff8,container),(0x973ff4,ci),(0x297ad54,77),(0x96e560,pool),(0x971590,16),(0x973e50,queue),(0x973e4c,ci%4),(0x973fa4,0),(0x297ae20,0),(0x297cc6c,manager),(0x297cc70,1)]:n.pack('<I',p,v)
  n.pack('<2I',0x297cc78,7,cs['declaration'](7));n.write(deviceGlobal,b[device-BASE+0x654:device-BASE+0x655]);ns['run'](b,o,[row['label'],variant])
  for field,av,ev in[('factory',actualFactories,expectedFactories),('declarations',actualDeclarations,expectedDeclarations)]:
   if av!=ev and len(ns['errors'])<20:ns['errors'].append({'case':ci,'variant':variant,'field':field,'native':av,'model':ev})
  assert n.unpack('<I',ns['control'])[0]<pool,'Packet arena overlaps material pool'
  ns['cases'][-1].update(lifecycleOptions=dict(currentOptions),nativeFactory=list(actualFactories),nativeDeclarations=list(actualDeclarations));counts['cases']+=1;counts['clones']+=nativeEntries.count(0x5e4b20);counts['mergeCalls']+=nativeEntries.count(0x5e5020);counts['refreshes']+=nativeEntries.count(0x601030);counts['factories']+=len(actualFactories);counts['declarations']+=len(actualDeclarations)
 if(ci+1)%20==0:print('dynamic material objects',ci+1,'errors',len(ns['errors']),flush=True)
 if ns['errors']:break
fp=R/'geometry-dynamic-material-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':ns['cases']},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-material-native-v1','passed':not ns['errors'],'binarySHA256':n.sha256,'counts':counts,'normalCounts':ns['counts'],'sourceObjects':len(selected),'sources':baseReport['sources'],'errors':ns['errors'],'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['Original5f0f00 normal ordinary/prefix path includes actual different-layout merge→cache→pool→refresh before original shader emission and packet writing. Only7416a0 shader factory is controlled.','120 authored objects across60scenes, three override policies each: global replacement, tagged table replacement, empty tagged entry suppressing global fallback. Forced visibility1, zero shadows/sway/fade and null skin/morph inputs.','Complete persistent compact image compared, including mirrored pending queue count and native shader/bounds/scratch globals. Existing32-byte portable transient stack scratch excluded.','Successful bounded capacities, same-thread cache, zero locks, original declaration-cache hits and finite matrix/color math. Device/shader-factory internals and GPU output excluded.','No managed/game/GPU launch.']};(R/'geometry-dynamic-material-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','normalCounts','errors','fixtureBytes']}));raise SystemExit(bool(ns['errors']))
