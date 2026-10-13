import importlib.util,json,struct,itertools,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('force',Path(__file__).with_name('native-force-action-verify.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;B=f.B;D=f.D;q=f.q;NAMES=D+0x33000;QUERY=D+0x34000
rows=[];errors=[];excluded=[];groups={}
ADDR={'Find':0x55bc20,'Bind':0x440c00,'CategoryIs':0x440c30,'UseTimeBasedUpdate':0x455290}
def options(o):
 p=f.options(dict(categoryNames=['Blaster','Jedi','JEDI',None,'Droid'],capabilityCount=5,capabilities=[[0,0],[8,1],[16,2],[32,4],[0,8]],bound=1,flagsEf4=0x1234abcd,system=True,table=True,name='Jedi'));p.update(o);return p
def setup(o):
 f.setup(o,None);n.pack('<I',0x93b280,f.CAP if o['table'] else 0);n.pack('<I',f.ACT+0xef4,o['flagsEf4'])
 for i,name in enumerate(o['categoryNames']):
  n.pack('<I',f.CAP+i*12,0 if name is None else NAMES+i*0x40)
  if name is not None:n.write(NAMES+i*0x40,name.encode()+b'\0')
 if o['name'] is not None:n.write(QUERY,o['name'].encode()+b'\0')
def model(kind,o):
 if kind in ['Find','Bind']:
  if not o['table'] or kind=='Bind' and (not o['system'] or o['name'] is None):return -1
  return next((i for i in range(max(0,o['capabilityCount'])) if o['categoryNames'][i] is not None and o['name'] is not None and o['categoryNames'][i].split('\0')[0].lower()==o['name'].split('\0')[0].lower()),-1)
 if kind=='CategoryIs':
  bound=o['bound']
  if bound==-1 or not o['creature'] or not o['reference'] or bound<0 or bound>=o['capabilityCount']:return 0
  if not o['table']:return None
  masks=o['capabilities'][bound]
  if not o['actor'] and any(masks):return None
  return q.bits(float(f.capable(o,bound)))
 if o['creature'] and o['reference']:
  if not o['actor']:return None
  enabled=False
  if o['first']:
   for token in o['tokens']:
    value=token.split('\0')[0].lower()
    if value=='true':enabled=True
    elif value=='false':enabled=False
  o['flagsEf4']=(o['flagsEf4']&~0x20)|(0 if enabled else 0x20)
 return 1
def run(kind,inputs=None,source=None):
 o=options(inputs or {});wantOptions=copy.deepcopy(o);want=model(kind,wantOptions)
 if want is None:excluded.append(dict(kind=kind,options=o));return
 setup(o);before=bytearray(n.read(D,0x40000));query=0 if o['name'] is None else QUERY
 if kind=='Find':value=n.call(ADDR[kind],[query]);got=value if value<0x80000000 else value-0x100000000
 elif kind=='Bind':value=n.call(ADDR[kind],[1 if o['system'] else 0,query]);got=value if value<0x80000000 else value-0x100000000
 elif kind=='CategoryIs':n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',f.OUT));n.call(ADDR[kind],[0,0,f.CRE if o['creature'] else 0,0,o['bound']]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',f.OUT)[0]
 else:got=n.call(ADDR[kind],[0,0,f.CRE if o['creature'] else 0,f.ARGS,len(o['tokens']),int(o['first'])])
 struct.pack_into('<I',before,f.ACT+0xef4-D,wantOptions['flagsEf4']);bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x40000)!=before:bad.append('Full memory mismatch')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 native=dict(result=got,flags=n.unpack('<I',f.ACT+0xef4)[0]);rows.append(dict(kind=kind,options=o,native=native,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 for kind in ['Find','Bind']:
  for name,count,table,system in itertools.product([None,'','Blaster','blaster','Jedi','JEDI','Droid','missing','jedi\0ignored'],[-1,0,1,2,4,5],[False,True],[False,True]):run(kind,dict(name=name,capabilityCount=count,table=table,system=system))
 for bound,creature,reference,actor,definition,class90,class94 in itertools.product([-2,-1,0,1,2,4,5],[False,True],[False,True],[False,True],[0,8,0xffffffff],[0,1,0xffffffff],[0,0x8000]):run('CategoryIs',dict(bound=bound,creature=creature,reference=reference,actor=actor,definitionFlags=definition,class90=class90,class94=class94))
 for tokens,first,flags,creature,reference,actor in itertools.product([[],['TRUE'],['FALSE'],['true','FALSE','TRUE'],['FALSE','TRUE','FALSE'],['xTRUE'],['TRUE\0ignored']],[False,True],[0,0x20,0x1234abcd,0xffffffff],[False,True],[False,True],[False,True]):run('UseTimeBasedUpdate',dict(tokens=tokens,first=first,flagsEf4=flags,creature=creature,reference=reference,actor=actor))
 for table,count,bound in itertools.product([False,True],[-1,0,5],[-2,-1,0,4,5]):run('CategoryIs',dict(table=table,capabilityCount=count,bound=bound))
 uses={r['name']:r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name'] in ['CategoryIs','UseTimeBasedUpdate']}
 for use in uses['CategoryIs']:run('Bind',dict(name=use['args'][0]),source=use)
 for use in uses['UseTimeBasedUpdate']:
  for first in [False,True]:run('UseTimeBasedUpdate',dict(tokens=use['args'],first=first),source=use)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),excludedInvalidPointerCases=len(excluded),authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:5],method='Unchanged55bc20/440c00/440c30/455290 with actual55bc80 and4f8b10. Compare returned index/float/integer and complete fixture memory, including ef4 flags. No replacements.',limits=['Bounded category table with nullable names and native case-folded comparisons. Actor definition/class requirements are inherited from actual capability masks.','Null actor is valid for mask-free CategoryIs but invalid for reached time-based-update flag write. Invalid backing cases explicitly excluded.','Only ef4bit20 producer recovered, not downstream update cadence. Authored operands exercised with prepared category tables; managed replay pending.'])
 (B/'reports/native-category-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-category-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows,excluded=excluded),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
