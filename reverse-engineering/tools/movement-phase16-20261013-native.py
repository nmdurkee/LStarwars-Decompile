"""IsVisible composition using actual static/dynamic lookup, validity andflags helpers."""
import importlib.util,struct,json,gzip,itertools,base64
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;W=D+0x1000;S=D+0x2000;HDR=D+0x3000;NROWS=D+0x4000;DROWS=D+0x8000;MODEL=D+0xa000;NAMES=D+0xc000;QUERY=D+0xd000;RESULT=D+0xe000;SIZE=0x10000;vectors=[];errors=[];groups={}
STUB=n.STOP+0x400;code=b'\xff\x74\x24\x14'*5;call=STUB+len(code);code+=b'\xe8'+struct.pack('<i',0x440ad0-(call+5))+b'\x83\xc4\x14\xd9\x1d'+struct.pack('<I',RESULT)+b'\xc3';n.write(STUB,code)
names=['Alpha','Beta','ALPHA','']
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',0x802c54,0 if c.get('worldNull')else W);n.pack('<I',W+0x13c,0 if c.get('noScene')else S);n.pack('<I',S+0x110,HDR if c.get('dynamic')else 0);n.pack('<i',S+0x24,c.get('count',4));n.pack('<I',S+0x28,NROWS);n.pack('<i',HDR+0x6c,c.get('count',4));n.pack('<I',HDR+0x70,DROWS);n.pack('<I',0x97388c,c.get('diagnostic',0))
 for j,name in enumerate(names):
  np=NAMES+j*0x40;n.write(np,name.encode()+b'\0');n.pack('<I',NROWS+j*0x4c+0x44,np);n.pack('<I',NROWS+j*0x4c+0x40,0 if c.get('noModel')else MODEL+j*0x100);n.pack('<I',MODEL+j*0x100+0x44,c.get('flags',0xa5a5a5a5)if j==0 else c.get('otherFlags',0));n.pack('<I',DROWS+j*0xd0+0xb4,np);n.pack('<I',DROWS+j*0xd0+0xb8,c.get('flags',0xa5a5a5a5)if j==0 else c.get('otherFlags',0))
 name=c.get('query','Alpha')
 if name is not None:n.write(QUERY,name.encode()+b'\0')
 return bytearray(n.read(D,SIZE))
def oracle(c):
 if c.get('worldNull'):return None,True
 if c.get('noScene')or c.get('query','Alpha')is None:return 0,False
 for j in range(max(0,c.get('count',4))):
  if names[j].lower()!=c.get('query','Alpha').lower():continue
  if not c.get('dynamic')and c.get('noModel'):return None,True
  flags=c.get('flags',0xa5a5a5a5)if j==0 else c.get('otherFlags',0);return(0x3f800000 if flags&(2 if c.get('dynamic')else 1)else 0),False
 return 0,False

def run(c,group):
 before=setup(c);want,wfault=oracle(c);fault=False;result=None
 try:n.call(STUB,[0,0,0,0,0 if c.get('query','Alpha')is None else QUERY]);result=n.unpack('<I',RESULT)[0]
 except RuntimeError:fault=True
 after=n.read(D,SIZE);expected=bytearray(before)
 if not fault:struct.pack_into('<I',expected,RESULT-D,result)
 groups[group]=groups.get(group,0)+1
 if after!=expected or fault!=wfault or(not fault and result!=want):errors.append(dict(input=c,result=[result,want],fault=[fault,wfault],memoryMismatch=after!=expected))
 vectors.append(dict(input=dict(c),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,fault=fault))
for worldNull,noScene,dynamic,count,query,diag in itertools.product([False,True],[False,True],[False,True],[-1,0,1,2,3,4],[None,'Alpha','alpha','Beta','missing',''],[0,1]):run(dict(worldNull=worldNull,noScene=noScene,dynamic=dynamic,count=count,query=query,diagnostic=diag),'lookup-guard-order-dynamic-diagnostics')
for dynamic,flags,query,noModel in itertools.product([False,True],[0,1,2,3,0x200,0x202,0xffffffff],['Alpha','Beta','ALPHA','missing'],[False,True]):run(dict(dynamic=dynamic,flags=flags,otherFlags=flags^3,query=query,noModel=noModel),'normal-display-flags-duplicates-model-fault')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());row=next(r for r in ledger['rows']if r['kind']=='scp-condition'and r['name']=='IsVisible')
for use in row['uses']:run({},'authored-IsVisible-body')
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],faultCases=sum(v['fault']for v in vectors),authoredOccurrences=row['sourceUses'],nativeAdapters=0,method='Original440ad0/5cf5b0/5cf510/5cfac0/5cfd60 andcase-insensitive comparison execute unchanged. Diagnostic5c1300 isactualRET-only, notadapted. Explicit5arg ABI wrappercapturesFPU result; complete65536byte image,fault,result retained.',limits=['Prepared valid static/dynamic current scene/name order andmodel backing with explicit nullworld/staticmodel faults. Arbitraryinvalid pointers excluded.','C# bridge composes existing typedlookup/validity/flags projections. No new helperaddress credit.','Authored condition-body occurrences retained; original namebinding/conditioninitializer/comparison outside scope.'])
(m.BASE/'reports/movement-phase16-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase16-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),faultCases=report['faultCases'],errors=errors[:5])))
