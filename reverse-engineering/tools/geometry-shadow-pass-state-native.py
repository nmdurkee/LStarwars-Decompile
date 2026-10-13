"""Original pass-state helpers and gated context registration, no stubs."""
import ast,struct,json,gzip,hashlib,base64,collections,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/geometry-shadow-registry-native.py';tree=ast.parse(path.read_text());body=[]
for node in tree.body:
 if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name)and t.id=='flags'for t in node.targets):break
 body.append(node)
r={'__file__':str(path)};exec(compile(ast.Module(body=body,type_ignores=[]),str(path),'exec'),r);n=r['n'];D=r['D'];SIZE=r['SIZE'];w=r['w']
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
calls=[]
def hook(mu,address,size,user):calls.append(address)
n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x5d0560,end=0x5d0560)
addresses=dict(reset=0x5d4290,adapter=0x5d4300,select=0x5954c0,mode=0x5d0530,invalidate=0x5d0650,tail=0x596920,call=0x596980)
zeros=[0x4c,8,4,0x24,0x28,0x58,0x38,0x3c,0x48,0xac,0xc4,0xe4,0xe0,0x178,0x174,0x188,0x214]
cases=[];counts=collections.Counter()
def execute(kind,count,flag,feature,config,enabled,registered,value,index):
 before,state=r['setup'](count,flag,index);context=r['contexts'][index%8];w(before,context+0x808,enabled);w(before,context+0x824,registered)
 if kind in ['tail','call']and(feature==0 or config!=2 or count==4):context=0xdeadbeef
 pass_before=bytes((j*37+index*13)&255 for j in range(0x218));expected_pass=bytearray(pass_before);mode=(index*0x19660d+0x3c6ef35f)&0xffffffff;expected_mode=mode;expected=bytearray(before);expected_state=json.loads(json.dumps(state));ret=None;trace=[];args=[];regs={}
 if kind in ['reset','adapter']:
  for offset in zeros:struct.pack_into('<I',expected_pass,offset,0)
  for offset in [0,0x40]:struct.pack_into('<I',expected_pass,offset,0xffffffff)
  ret=1;args=[value]if kind=='adapter'else[]
 elif kind=='select':struct.pack_into('<3I',expected_pass,0x38,1,context,value);args=[value];regs={UC_X86_REG_ECX:context}
 elif kind=='mode':expected_mode=0xffffffff if enabled==0 else value;ret=mode;args=[enabled,value]
 elif kind=='invalidate':expected_state['flag']=0
 else:
  args=[0xabcdef01]if kind=='tail'else[]
  if feature!=0 and config==2:expected,expected_state,_=r['model'](before,state,'register',context);trace=[0x5d0560]
 n.write(D,before);n.write(0x9718a0,pass_before);n.pack('<I',0x806ccc,mode);n.pack('<I',0x966384,count);n.pack('<I',0x9715a0,flag);n.pack('<8I',0x96d9d0,*state['contexts']);n.pack('<8I',0x96e550,*state['masks']);n.pack('<B',0x8264c4,feature);n.pack('<I',0x8264bc,config);n.pack('<I',0x955b38,context);calls.clear()
 actual_ret=n.call(addresses[kind],args,regs,count=100000);actual=n.read(D,SIZE);actual_pass=n.read(0x9718a0,0x218);actual_mode=n.unpack('<I',0x806ccc)[0];actual_state=dict(count=n.unpack('<i',0x966384)[0],flag=n.unpack('<I',0x9715a0)[0],contexts=list(n.unpack('<8I',0x96d9d0)),masks=list(n.unpack('<8I',0x96e550)))
 assert actual==expected and actual_pass==expected_pass and actual_mode==expected_mode and actual_state==expected_state and calls==trace and(ret is None or actual_ret==ret),dict(kind=kind,index=index,got=actual_state,want=expected_state,calls=calls,trace=trace)
 digest=hashlib.sha256(actual+actual_pass+struct.pack('<I',actual_mode)).hexdigest();cases.append(dict(kind=kind,beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),state=state,passBefore=pass_before.hex(),mode=mode,feature=feature,configuration=config,enabled=enabled,value=value,context=context,nativeState=actual_state,nativeReturn=ret,nativeSHA256=digest));counts['cases']+=1;counts[kind]+=1;counts['persistentBytes']+=SIZE+0x218+4+72
words=[0,1,2,0x80000000,0xffffffff,0xdeadbeef]
for kind in ['reset','adapter','select','mode','invalidate']:
 for i in range(192):execute(kind,i%5,words[i%6],i%256,words[i//6%6],words[i//12%6],words[i%6],words[(i+3)%6],i)
for kind in ['tail','call']:
 for i,(count,feature,config,enabled,registered)in enumerate(itertools.product(range(5),[0,1,128,255],[0,2,0xffffffff],[0,1],[0,1])):execute(kind,count,words[i%6],feature,config,enabled,registered,0,i)
fp=R/'geometry-shadow-pass-state-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,cases=cases),separators=(',',':')).encode(),mtime=0))
report=dict(schema='geometry-shadow-pass-state-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['All seven original entries and actual5d0560 registration execute unchanged. Observation hook verifies gated register calls; no computation replacement.', 'Reset/select copy raw32-bit fields in original0x218-byte state at9718a0. Unwritten bytes retained. Mode helper returns old806ccc and uses exact nonzero enable semantics.', 'Registry mutations retain established count0..4 and disjoint valid-context domain. Gate-disabled and full-registry cases supply invalid context pointers to prove short-circuit behavior.', 'Only CPU state, selection and registration covered. Actual596870 draw/packet finalization, full frame lifecycle, GPU output and managed runtime equality remain separate.'])
(R/'geometry-shadow-pass-state-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
