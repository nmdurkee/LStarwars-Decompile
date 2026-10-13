"""Execute original named-gizmo lookup and accessors without name-binding hooks."""
import importlib.util,itertools,json,random,hashlib,struct
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');s=importlib.util.spec_from_file_location('scenery_native',p);native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();B=native.BASE;D=n.DATA;GLOBAL=D;TYPES=D+0x100;REG=D+0x1000;BUCKETS=D+0x1100;RECORDS=D+0x2000;STRINGS=D+0x4000;QUERY=D+0x10000
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
calls=[]
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);record=n.unpack('<I',sp+4)[0];delta=record-RECORDS;calls.append([delta//0x100,(delta%0x100)//8])
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x558770,end=0x558770);n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x5ae390,end=0x5ae390)
def fold(s):return bytes(c-32 if 97<=c<=122 or c>=224 else c for c in s.encode('latin1').split(b'\0')[0])
def fixture(v):
 n.write(D,bytes(0x11000));calls.clear();n.pack('<I',0x93b268,0 if v.get('globalMissing')else GLOBAL);n.pack('<iII',GLOBAL,v['count'],0,TYPES);n.pack('<I',REG,BUCKETS)
 for i,b in enumerate(v['buckets']):
  n.pack('<I',TYPES+i*0x9c+0x44,(0x558770 if i%2==0 else 0x5ae390)if b['accessor']else 0)
  n.pack('<iI',BUCKETS+i*20+4,b['count'],0);n.pack('<I',BUCKETS+i*20+12,RECORDS+i*0x100)
  for j,name in enumerate(b['names']):
   rec=RECORDS+i*0x100+j*8;sp=STRINGS+i*0x1000+j*0x100;n.pack('<I',rec,sp if name is not None else 0)
   if name is not None:n.write(sp,name.encode('latin1')+b'\0')
 name=v['name'];ptr=QUERY if name is not None else 0
 if ptr:n.write(ptr,name.encode('latin1')+b'\0')
 got=n.call(0x55a020,[0 if v.get('registryMissing')else REG,v['type'],ptr]);identity=None if not got else [(got-RECORDS)//0x100,((got-RECORDS)%0x100)//8]
 return {'record':identity,'calls':list(calls)}
def model(v):
 result={'record':None,'calls':[]}
 if v.get('globalMissing')or v.get('registryMissing')or v['name']is None:return result
 kinds=range(max(0,v['count']))if v['type']<0 or v['count']<v['type']else [v['type']]
 for i in kinds:
  b=v['buckets'][i]
  if not b['accessor']:continue
  for j in range(max(0,b['count'])):
   result['calls'].append([i,j]);candidate=b['names'][j]
   if candidate is not None and fold(candidate)==fold(v['name']):result['record']=[i,j];return result
 return result
rows=[];errors=[]
def add(group,v):
 expect=model(v);actual=fixture(v);row={'group':group,'input':v,'expected':expect,'native':actual};rows.append(row)
 if expect!=actual:errors.append(row)
base=[{'accessor':True,'count':4,'names':['alpha','B','alpha',None]},{'accessor':True,'count':4,'names':['b','ALPHA','gamma','']},{'accessor':False,'count':2,'names':['alpha','b']},{'accessor':True,'count':2,'names':['edge','alpha']}]
for count,kind,name in itertools.product([-1,0,1,2,3],[-2147483648,-1,0,1,2,3,4,2147483647],[None,'','alpha','ALPHA','B','gamma','edge','missing','Alpha\0ignored']):add('count-index-and-order',dict(count=count,type=kind,name=name,buckets=base))
for globalmissing,regmissing,name in itertools.product([False,True],[False,True],[None,'alpha','missing']):add('null-guards',dict(count=3,type=-1,name=name,buckets=base,globalMissing=globalmissing,registryMissing=regmissing))
for c in range(1,256):
 names=[{'accessor':True,'count':3,'names':[None,chr(c),'other']}]
 for query in [chr(c),fold(chr(c)).decode('latin1')]:add('byte-fold',dict(count=1,type=0,name=query,buckets=names))
r=random.Random(550020)
for i in range(1800):
 buckets=[]
 for j in range(4):
  names=[r.choice([None,'a','A','b','\xe0','\xc0','','A\0rest','missing'])for k in range(5)];buckets.append(dict(accessor=r.choice([True,True,False]),count=r.choice([-2,-1,0,1,2,3,4,5]),names=names))
 add('randomized-bucket-order',dict(count=r.choice([-1,0,1,2,3]),type=r.choice([-2,-1,0,1,2,3,4]),name=r.choice([None,'a','A','b','\xe0','\xc0','','a\0tail','missing']),buckets=buckets))
# The two accessors return the object pointer verbatim (object begins with name).
accessors=[]
for address,record,objectptr in itertools.product([0x558770,0x5ae390],[0,RECORDS],[0,STRINGS,0xffffffff]):
 n.pack('<I',RECORDS,objectptr);actual=n.call(address,[record]);expected=objectptr if record else 0;accessors.append({'address':hex(address),'recordPresent':bool(record),'objectPointer':objectptr,'expected':expected,'native':actual})
 if actual!=expected:errors.append(accessors[-1])
assembly=[{'address':hex(a),'instructions':[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,z),a)]}for a,z in [(0x55a020,0x151),(0x558770,0x10),(0x5ae390,0x10)]]
(B/'reports/native-scenery-name-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'procedures':assembly},indent=2)+'\n')
report={'binarySha256':n.sha256,'cases':len(rows),'accessorCases':len(accessors),'mismatches':len(errors),'examples':errors[:10],'groups':{g:sum(x['group']==g for x in rows)for g in sorted(set(x['group']for x in rows))},'adapters':[],'instrumentation':'Read-only entry hooks log accessor order without replacing instructions. All lookup, accessor and comparator bodies execute unchanged.','boundaries':['Projected valid global type and registry bucket arrays; name bytes encode Latin1 with C NUL termination.','Native type==count executes indexed lookup. Tests allocate the extra readable slot; an absent slot is an unsafe original read, not an invented null result.','Negative counts and record counts preserved. Invalid pointers, concurrent registry mutation and arbitrary callback side effects excluded.'],'vectors':'reports/native-scenery-name-vectors.json'}
(B/'reports/native-scenery-name-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-scenery-name-vectors.json').write_text(json.dumps({'lookup':rows,'accessors':accessors},indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
