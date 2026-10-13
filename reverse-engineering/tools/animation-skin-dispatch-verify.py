"""Original5e0530 dispatch plus actual ordinary/prefix/skin-morph writers."""
from pathlib import Path
import ast,json,gzip,struct,hashlib,collections
B=Path(__file__).resolve().parent.parent
path=B/'tools/animation-morph-packets-verify.py';prefix=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='cases'for v in node.targets):break
 prefix.append(node)
mp={'__file__':str(path)};exec(compile(ast.Module(body=prefix,type_ignores=[]),str(path),'exec'),mp)
n=mp['n'];D=n.DATA;SIZE=mp['SIZE'];f=mp['f'];MATERIAL=D+0xd000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI,UC_X86_REG_ECX,UC_X86_REG_EDX
def extract(path,names,namespace):
 for node in ast.parse((B/path).read_text()).body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),path,'exec'),namespace)
support={'BASE':D,'struct':struct};extract('tools/geometry-dynamic-command-native.py',['u','w','quiet','alpha','model'],support)
ordinary={'BASE':D,'struct':struct,'ns':support,'u':support['u'],'w':support['w']};extract('tools/geometry-ordinary-packets-native.py',['transpose','matrix','evaluate'],ordinary)
for a in[0x5e0530,0x5e0200,0x5e02b0]:n.mu.hook_add(UC_HOOK_CODE,mp['observe'],begin=a,end=a)
def sha(b):return hashlib.sha256(b).hexdigest()
cases=[];errors=[];counts=collections.Counter();uv=[0x3f000000,0x40000000,0x80000000,0xbf800000]
def execute(mi,index,skin,weights,flags,previous,commandIndex,opcode=0x82):
 mesh=mp['meshes'][mi];matrixRow=mp['matrixRows'][index%len(mp['matrixRows'])];matrix=bytes.fromhex(matrixRow['before'])[0x600:0x640];metadata=[0,-2147483648,2147483647,16777217,-1][index%5];alpha=[0,0x80000000,0xbf800000,0x3e800000,0x3f800000,0x40000000,0x7fc12345][index%7]
 before=mp['initial'](mesh,weights,index,matrix);before[mp['CMD']-D]=opcode;before[mp['CMD']-D-32]=previous;mp['w'](before,mp['CMD']-28,0x89abcdef);mp['w'](before,MATERIAL+0xb4,flags);skinAddress=D+0x10000+(index%4)*0x4000 if skin else 0
 if skin:mp['put'](before,skinAddress,mp['matrices'])
 selected=0x5e0390 if skin else 0x5e02b0 if flags&0x80000000 and commandIndex>1 and previous in[0xb0,0xae,0xaf]else 0x5e0200
 if skin:want,trace,ev=mp['model'](before,mesh,weights,metadata,uv)
 else:
  args=[mp[k]for k in['CONTROL','RECORD','CMD','SRC','CACHE','OUT','SCALE','TRANS']]+[alpha,metadata&0xffffffff];want,unused,trace=ordinary['evaluate']('prefix'if selected==0x5e02b0 else'ordinary',before,args,uv);ev=[]
 mp['current']=mesh;n.write(D,before);n.write(mp['BASEVERTEX'],mesh['vertices']);at=mp['DELTA']
 for delta in mesh['deltas']:
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 n.pack('<I',0x9736e0,mp['CONTROL']);n.pack('<4I',0x80e258,*uv);n.write(0x2857230,before[mp['SCALE']-D:mp['SCALE']-D+64]);n.write(0x28571f0,before[mp['TRANS']-D:mp['TRANS']-D+64]);mp['calls'].clear();mp['events'].clear()
 n.call(0x5e0530,[MATERIAL,commandIndex,mp['OUT'],mp['CACHE'],skinAddress,mp['WEIGHT']if weights is not None else 0,alpha,metadata&0xffffffff],regs={UC_X86_REG_ECX:mp['CMD'],UC_X86_REG_EDX:mp['SRC'],UC_X86_REG_ESI:mp['RECORD']},count=30000000)
 actual=bytearray(n.read(D,SIZE));mp['put'](actual,mp['SCALE'],n.read(0x2857230,64));mp['put'](actual,mp['TRANS'],n.read(0x28571f0,64));actualCalls=mp['calls'].copy();actualEvents=mp['events'].copy();trace=[0x5e0530]+trace;counts[hex(selected)]+=1
 if bytes(actual)!=bytes(want)or actualCalls!=trace or actualEvents!=ev:
  counts['mismatches']+=1
  if len(errors)<12:errors.append(dict(mesh=mi,index=index,selected=hex(selected),offsets=[i for i,(a,b)in enumerate(zip(actual,want))if a!=b][:20],expectedCalls=trace,nativeCalls=actualCalls,expectedEvents=ev,nativeEvents=actualEvents))
 cases.append(dict(mesh=mi,index=index,skin=skin,skinAddress=skinAddress,weights=None if weights is None else[f.bits(v)for v in weights],matrix=matrix.hex(),matrixOrigin=matrixRow['label'],metadata=metadata,alpha=alpha,flags=flags,previous=previous,commandIndex=commandIndex,opcode=opcode,writer=selected,nativeSha256=sha(actual),calls=actualCalls,events=actualEvents))
for mi,mesh in enumerate(mp['meshes']):
 weights=[f.f32((j%7-2)*.125)for j in range(len(mesh['deltas']))]
 for mode in range(4):execute(mi,mi*4+mode,mode<2,weights if mode in[1,2]else None,0x80000000 if mode<3 else 0,[0xb0,0xae,0xaf][mi%3],2)
 if mi%100==0:print(mi,'meshes;',counts['mismatches'],'mismatches',flush=True)
# Signed command index and previous-opcode branch boundaries, including other
# command opcodes. 0x8f is explicitly excluded from this writer composition.
for i in range(192):
 mi=i%len(mp['meshes']);mesh=mp['meshes'][mi];weights=[.5]*len(mesh['deltas'])if i%2 else None
 execute(mi,5000+i,bool(i%3==0),weights,[0,0x7fffffff,0x80000000,0xffffffff][i%4],[0,0xae,0xaf,0xb0,0xb1][i%5],[-2147483648,-1,0,1,2,2147483647][i%6],[0,0x82,0x98,0xff][i%4])
fixturePath=mp['fixturePath'];matrixFixture=mp['matrixFixture'];out=B/'reports/animation-skin-dispatch-native-fixtures.json.gz'
addresses=dict(base=D,size=SIZE,material=MATERIAL,**{k:mp[v]for k,v in[('mesh','M'),('weights','WEIGHT'),('joints','MATRIX'),('gpu','GPU'),('vtable','VTABLE'),('targets','TARGETS'),('control','CONTROL'),('owner','OWNER'),('table','TABLE'),('record','RECORD'),('command','CMD'),('matrix','SRC'),('cache','CACHE'),('output','OUT'),('scale','SCALE'),('translation','TRANS'),('arena','ARENA'),('lock','LOCK'),('unlock','UNLOCK'),('delta','DELTA')]})
out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,meshFixture=dict(path=fixturePath.relative_to(B).as_posix(),sha256=sha(fixturePath.read_bytes())),matrixFixture=dict(path=matrixFixture.relative_to(B).as_posix(),sha256=sha(matrixFixture.read_bytes())),addresses=addresses,scratchInputs=uv,cases=cases),separators=(',',':')).encode(),mtime=0))
dependencies=['tools/animation-morph-packets-verify.py','tools/geometry-ordinary-packets-native.py','tools/geometry-dynamic-command-native.py']
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors,fixture=dict(path=out.relative_to(B).as_posix(),bytes=out.stat().st_size,sha256=sha(out.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],checkedBytes=len(cases)*SIZE,authoredMeshes=sum('path'in m['source']for m in mp['meshes']),method='Original5e0530 and each selected ordinary/prefix/skin-morph writer execute unchanged, including CPU payload producers and COM wrappers. Only successful virtual COM Lock/Unlock methods are callbacks. Whole1MiB memory image, scratch matrices, nested call order and COM events compared. Skin pointer relocates among four distinct buffers while null/nonnull morph weights vary independently.',limits=['Billboard opcode8f excluded from this full-writer composition; prior selection projection retains its precedence evidence.','Valid disjoint memory, finite active deformation, non-signaling-NaN transform/alpha words and successful buffer lock.','CPU packet production only; no full5f0f00 caller or GPU draw equivalence.','Managed source execution remains pending; compile only.'])
(B/'reports/animation-skin-dispatch-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in['dependencies','method','limits']},indent=2));assert counts['mismatches']==0
