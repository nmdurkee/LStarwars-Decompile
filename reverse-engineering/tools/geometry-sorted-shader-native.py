"""Run original sorted completion with full original shader emission."""
import ast,struct,json,gzip,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
# Load the earlier bounded harness setup/model definitions, stopping before its
# authored batch. This does not import/rerun its prior tests.
p=B/'tools/geometry-sorted-packets-native.py';text=p.read_text();tree=ast.parse(text);prefix=[]
for node in tree.body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='sourceRows'for t in node.targets):break
 prefix.append(node)
ns={'__file__':str(p)};exec(compile(ast.Module(body=prefix,type_ignores=[]),str(p),'exec'),ns)
# Reuse the independently original-verified emission model only.
q=B/'tools/geometry-shader-emission-native.py';et=ast.parse(q.read_text());en={'BASE':ns['BASE'],'struct':struct}
wanted={'u','w','hh','wh','align','payload','append','emit'}
for node in et.body:
 if isinstance(node,ast.FunctionDef)and node.name in wanted:exec(compile(ast.Module(body=[node],type_ignores=[]),str(q),'exec'),en)
original=next(node for node in tree.body if isinstance(node,ast.FunctionDef)and node.name=='complete_model')
model=ast.get_source_segment(text,original)
old="     if get(get(record+8)+0x20)!=get(shader+0x20):raise ValueError('Fixture crosses unknown shader emission gate')"
new="     changed,inner=emit_cpu(b,record,shader,allocator,descriptor,tokenBase);b[:]=changed;trace.extend([[address]for address in inner[1:]])"
if model.count(old)!=1:raise ValueError('Expected explicit shader boundary changed')
ns['emit_cpu']=en['emit'];exec(model.replace(old,new),ns)
n=ns['n'];BASE=ns['BASE'];calls=ns['calls'];compare=ns['compare']
# Observe nested payload/append entries as well as the existing completion trace.
from unicorn import UC_HOOK_CODE
for a in [0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0]:n.mu.hook_add(UC_HOOK_CODE,ns['observe'],begin=a,end=a)
fixtures=json.loads(gzip.decompress((R/'geometry-sorted-packets-fixtures.json.gz').read_bytes()))['cases'];out=[];counts={'cases':0,'changedShaderCalls':0,'appendCalls':0,'payloadCalls':0,'checkedBytes':0};sizes=[]
for caseIndex,case in enumerate(fixtures):
 if case['kind']!='complete' or not isinstance(case['label'][0],str)or case['label'][0]=='boundary' or case['label'][1]not in [1,2]:continue
 memory=bytearray.fromhex(case['before']);ns['memory']=memory;count=sum(ns['read'](owner+0x4c)for owner in case['registered']);control=ns['alloc'](4,101);descriptor=ns['alloc'](8,102);source=ns['alloc'](256,103);ns['write'](descriptor+4,source);memory[descriptor-BASE]=[0,3,255][caseIndex%3];memory[descriptor-BASE+2]=caseIndex&255;arena=ns['alloc'](count*1408+4096,104);ns['write'](control,arena+(caseIndex&15));tokenBase=(0x92345678+caseIndex*79)&0xffffffff
 for owner in case['registered']:
  shader=ns['read'](owner+0x80)
  for offset in [0x34,0x110,0x168,0x180,0x198]:ns['write'](shader+offset,0)
  for j in range(ns['read'](owner+0x4c)):
   record=ns['read'](ns['read'](owner+0x54)+j*4);ctx=ns['read'](record+8);ns['write'](ctx+0x20,ns['read'](shader+0x20)^0xffffffff)
   # Independent tail choice breaks the earlier fixture's correlation between
   # inactive controls and changed tails; both live relinking branches run.
   if j%2:ns['write'](record+0x14,ns['alloc'](16,j+105))
   for offset in [0x24,0x2c,0x2e,0x1e,0x32,0x30]:struct.pack_into('<H',memory,ctx-BASE+offset,struct.unpack_from('<H',memory,shader-BASE+offset)[0]^1)
 before=bytes(memory);ns.update(allocator=control,descriptor=descriptor,tokenBase=tokenBase);expected,trace,processed=ns['complete_model'](before,case['head'],case['registered'],case['global']);n.write(BASE,before);n.write(0x9868a0,before[case['global']-BASE:case['global']-BASE+420]);n.pack('<I',0x973ecc,case['head']);n.pack('<I',0x9739b8,len(case['registered']));n.pack('<I',0x9736e0,control);n.pack('<I',0x9738a4,descriptor);n.pack('<I',0x297dc00,tokenBase)
 for i,pointer in enumerate(case['registered']):n.pack('<I',0x9739bc+i*4,pointer)
 calls.clear();n.call(0x5e0d00,count=12000000);actual=bytearray(n.read(BASE,len(before)));actual[case['global']-BASE:case['global']-BASE+420]=n.read(0x9868a0,420);compare(bytes(actual),expected,['fullIntegration',caseIndex]);compare(json.dumps(calls).encode(),json.dumps(trace).encode(),['fullIntegrationCalls',caseIndex]);counts['cases']+=1;counts['changedShaderCalls']+=sum(c[0]==0x607590 for c in calls);counts['appendCalls']+=sum(c[0]==0x6034b0 for c in calls);counts['payloadCalls']+=sum(c[0]in[0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0]for c in calls);sizes.append(len(before))
 out.append({'sourceCase':caseIndex,'source':case['label'][0],'before':before.hex(),'head':case['head'],'registered':case['registered'],'global':case['global'],'control':control,'descriptor':descriptor,'tokenBase':tokenBase,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeCalls':list(calls)})
counts['checkedBytes']=ns['counts']['checkedBytes'];fp=R/'geometry-sorted-shader-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':out},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-sorted-shader-native-v1','passed':not ns['errors'],'binarySHA256':n.sha256,'counts':counts,'errors':ns['errors'],'sources':len(set(c['source']for c in out)),'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'maximumArenaBytes':max(sizes),'dependencies':[{'file':str(x.relative_to(B)),'sha256':hashlib.sha256(x.read_bytes()).hexdigest()}for x in[p,q]],'boundaries':['All original sorted completion,changed shader emission,payload builders,append,context reset and CRT code execute unchanged; hooks only observe.','Authored material flags,index maps and sort ranges plus controlled valid runtime packet/context state.','Finite nonoverlapping metadata/arena storage; original global template relocated only in saved snapshot adapter.','No compiled C# launch or GPU command consumption claimed.']}
(R/'geometry-sorted-shader-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','sources','fixtureBytes']}));raise SystemExit(bool(ns['errors']))

