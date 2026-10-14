"""Actual52c880 caller interoperability for49builtin descriptors, retaining independent per-body native/model witnesses."""
import importlib.util,json,struct,itertools,math,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;LIST67=D+0xa000;NODE67=D+0xa100;DESC67=D+0xa200;OUT67=D+0x5040;sineBytes=(nm.BASE/'references/native-animation-sine-table.f32').read_bytes();n.write(0x29899a0,sineBytes)
checks=0;errors=[];cases=[]
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates'];datasets={};witnesses={}
for phase in[27,51,52,53,55,56,58,60,61,63,64,65,66]:
 data=json.loads((nm.BASE/f'reports/script-phase{phase}-20261013-native-fixtures.json').read_text());datasets[phase]=data
 for row in data['cases']:
  if row.get('fault')or row.get('method')in['Conditions','Bind','Free']or phase==27 and row.get('method')!='Predicate':continue
  if phase==53 and row.get('method')!='Y':continue
  address=row.get('address',0x514aa0 if phase==53 else 0x515320 if phase==55 else 0x515290 if phase==66 else 0)
  if not address or address not in {r['words'][1]for r in table if r['words'][1]}:continue
  context=row['context']
  if context.get('callback')or context.get('patches'):continue
  old=witnesses.get(address)
  if old is None or not old[1]['returnValue']and row['returnValue']:witnesses[address]=(phase,row)
assert set(witnesses)=={r['words'][1]for r in table if r['words'][1]},(set(witnesses),[r['name']for r in table if r['words'][1]not in witnesses])
def write(rows):
 for row in rows:n.write(row['address'],bytes.fromhex(row['bytes']))
def put(rows,p,data):
 for row in rows:
  first=row['address'];payload=bytearray.fromhex(row['bytes'])
  if first<=p and p+len(data)<=first+len(payload):payload[p-first:p-first+len(data)]=data;row['bytes']=payload.hex();return
 raise KeyError(hex(p))
def take(rows,p,size):
 for row in rows:
  first=row['address'];data=bytes.fromhex(row['bytes'])
  if first<=p and p+size<=first+len(data):return data[p-first:p-first+size]
 raise KeyError(hex(p))
def execute67(entry,op,right):
 global checks
 address=entry['words'][1];phase,witness=witnesses[address]if address else witnesses[0x5149f0];initial=json.loads(json.dumps(witness['initial']));final=json.loads(json.dumps(witness['final']));inputs=witness['inputs'];system=inputs.get('system',D+0x8000);actor=inputs.get('actor',D+0x6000);packet=inputs.get('packet',D+0x1000);arg14=inputs.get('arg14',D+0x3000);arg18=inputs.get('arg18',inputs.get('bound',0));left=witness['returnValue']if address else 0
 if not address:final=json.loads(json.dumps(initial))
 put(final,OUT67,take(initial,OUT67,4))
 node=struct.pack('<11I',0,0,right,op,0,arg14,arg18,DESC67,0,0,0);desc=struct.pack('<3I',0,address,0)
 for rows in[initial,final]:put(rows,LIST67,struct.pack('<II',NODE67,NODE67));put(rows,NODE67,node);put(rows,DESC67,desc)
 put(initial,packet+0x38,b'\1\1');put(final,packet+0x38,b'\0\0');a=struct.unpack('<f',struct.pack('<I',left))[0];b=struct.unpack('<f',struct.pack('<I',right))[0];matched=[a==b,a<b,a>b,a<=b,a>=b,a!=b][op];want=NODE67 if matched else 0;write(initial);n.pack('<I',0x1000dff8,0);got=n.call(0x52c880,[system,LIST67,actor,packet],regs={UC_X86_REG_EAX:0},count=6000000);actual=[dict(address=row['address'],bytes=n.read(row['address'],len(row['bytes'])//2).hex())for row in final]
 for group,x,y in [('return',got,want),('images',actual,final)]:
  checks+=1
  if x!=y:errors.append(dict(name=entry['name'],address=hex(address),op=op,right=right,group=group,native=x,model=y))
 cases.append(dict(name=entry['name'],callback=address,context=dict(op=op,right=right),inputs=dict(system=system,actor=actor,packet=packet,list=LIST67),witness=dict(phase=phase,expectedPredicateBits=left),initial=initial,returnValue=got,final=actual))
from unicorn.x86_const import UC_X86_REG_EAX
for entry,op,right in itertools.product(table,range(6),[0,0x3f800000]):execute67(entry,op,right)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,builtinDescriptors=len(table),nonzeroHandlers=len(witnesses),ports=[],method='Eachcallbackwitness independentlynative/model-provedinpriorphase;actual52c880+actualbuiltinbody executeswithsameinputs, compare6operators andretainedheapeffects.',witnessPhases=sorted(datasets))
(nm.BASE/'reports/script-phase67-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase67-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
