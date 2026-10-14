"""Actual5143a0 initializercaller for all14 builtininitializerentries +rawlookup children; ownbodywitnesses independentlymatched."""
import importlib.util,json,struct,itertools
from pathlib import Path
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;SCRIPT68=D+0xe000;STATE68=D+0xe100;NODE68=D+0xe200;DESC68=D+0xe300;OTHER68=D+0xe400;OUT68=D+0x5040
checks=0;errors=[];cases=[];witnesses={}
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates'];allowed={r['words'][2]for r in table if r['words'][2]}
for phase in[28,51,57,59,62]:
 data=json.loads((nm.BASE/f'reports/script-phase{phase}-20261013-native-fixtures.json').read_text())
 for row in data['cases']:
  if row.get('fault'):continue
  address=row.get('address',0x5149b0 if phase==28 and row.get('method')=='AlwaysTrueInitializer'else 0)
  if address not in allowed:continue
  if phase==51 and row['context'].get('binding',True):continue
  old=witnesses.get(address)
  if old is None or not old[1]['returnValue']and row['returnValue']:witnesses[address]=(phase,row)
numeric28=json.loads((nm.BASE/'reports/script-phase28-20261013-native-fixtures.json').read_text())['cases'];witnesses[0x5149b0]=(28,next(r for r in numeric28 if r.get('method')=='AlwaysTrueInitializer'and r['context'].get('argument')=='-1.75'))
assert set(witnesses)==allowed

def put(rows,p,data):
 for row in rows:
  first=row['address'];payload=bytearray.fromhex(row['bytes'])
  if first<=p and p+len(data)<=first+len(payload):payload[p-first:p-first+len(data)]=data;row['bytes']=payload.hex();return
 raise KeyError(hex(p))
def read(rows,p,size):
 for row in rows:
  first=row['address'];data=bytes.fromhex(row['bytes'])
  if first<=p and p+size<=first+len(data):return data[p-first:p-first+size]
 raise KeyError(hex(p))
def ensure(rows,p,data):
 try:put(rows,p,data)
 except KeyError:rows.append(dict(address=p,bytes=data.hex()))
def execute68(address,scoped,cached,oldValue,alternate):
 global checks
 phase,witness=witnesses[address];initial=json.loads(json.dumps(witness['initial']));final=json.loads(json.dumps(witness['final']));inputs=witness['inputs'];system=inputs.get('system',D+0x8000);argument=inputs.get('defaultArgument',inputs.get('arg14',inputs.get('name',0)));value=witness['returnValue'];name=0x753270
 for rows in[initial,final]:
  ensure(rows,0x921ee8,struct.pack('<II',0 if scoped else SCRIPT68,0 if scoped else SCRIPT68));ensure(rows,name,n.read(name,5));put(rows,system+0x1c,struct.pack('<II',SCRIPT68 if scoped else 0,SCRIPT68 if scoped else 0));put(rows,system+0x1386,bytes([cached]));put(rows,SCRIPT68,bytes(88));put(rows,SCRIPT68+8,struct.pack('<I',argument));put(rows,SCRIPT68+0x10,struct.pack('<II',STATE68,STATE68));put(rows,STATE68,bytes(36));put(rows,STATE68+8,struct.pack('<II',NODE68,NODE68));put(rows,STATE68+0x18,struct.pack('<I',name));put(rows,NODE68,bytes(44));put(rows,NODE68+0x14,struct.pack('<II',argument,oldValue));put(rows,NODE68+0x1c,struct.pack('<I',DESC68));put(rows,NODE68+0x28,struct.pack('<I',OTHER68 if alternate else 0));put(rows,DESC68,struct.pack('<III',0,0,address));put(rows,OTHER68,bytes(44));put(rows,OTHER68+0x14,struct.pack('<II',argument,oldValue));put(rows,OTHER68+0x1c,struct.pack('<I',DESC68))
 if phase==51:put(final,OUT68,read(initial,OUT68,4))
 if scoped or not cached&4 or not oldValue:put(final,NODE68+0x18,struct.pack('<I',value))
 if scoped and alternate:put(final,OTHER68+0x18,struct.pack('<I',value))
 put(final,SCRIPT68+0x38,struct.pack('<I',STATE68))
 for row in initial:n.write(row['address'],bytes.fromhex(row['bytes']))
 n.call(0x5143a0,[system],count=6000000);actual=[dict(address=row['address'],bytes=n.read(row['address'],len(row['bytes'])//2).hex())for row in final];checks+=1
 if actual!=final:errors.append(dict(callback=hex(address),scoped=scoped,cached=cached,oldValue=oldValue,alternate=alternate,native=actual,model=final))
 cases.append(dict(callback=address,context=dict(scoped=scoped,cached=cached,oldValue=oldValue,alternate=alternate),inputs=dict(system=system),witness=dict(phase=phase,initializerReturnValue=value),initial=initial,final=actual))
for address,scoped,cached,oldValue,alternate in itertools.product(sorted(allowed),[False,True],[0,4],[0,0xabcdef01],[False,True]):execute68(address,scoped,cached,oldValue,alternate)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,distinctInitializerEntries=len(allowed),ports=[],method='Actual5143a0→all14initializerbodies→rawlookups/floatparser with priorindependentownbodywitnesses; globalcache/skopedalternate policies compared.')
(nm.BASE/'reports/script-phase68-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase68-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
