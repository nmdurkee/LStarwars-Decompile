"""Exercise obstacle commands through original name lookup and playback functions."""
import importlib.util,itertools,json,copy
from pathlib import Path
p=Path(__file__).with_name('native-obstacle-fixture.py');s=importlib.util.spec_from_file_location('obstacle_concrete_fixture',p);f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
# Replace fixture instance with a fresh emulator; its original name hook stays
# on the old instance and therefore cannot intercept these cases.
f.n=f.native.NativeX86();n=f.n;B=f.BASE
rows=[];errors=[]
def setup(tokens,options):
 nodes=f.setup(tokens,**options);globalhead=f.D+0x6000;buckets=f.D+0x6100
 n.pack('<I',0x93b268,0 if options.get('typesMissing')else globalhead);n.pack('<3I',globalhead,2,0,f.TYPES);n.pack('<I',f.REG,buckets)
 for kind,accessor in [(0,0x558770),(1,0x5ae390)]:
  first=f.RECORDS+kind*0x100;n.pack('<I',f.TYPES+kind*0x9c+0x44,accessor);n.pack('<i',buckets+kind*20+4,2);n.pack('<I',buckets+kind*20+12,first)
  for j,name in enumerate(['a','b']):
   record=first+j*8;n.pack('<I',record,f.OBJECTS+j*0x200);n.pack('<B',record+6,kind);n.write(f.OBJECTS+j*0x200,name.encode()+b'\0')
 return nodes
sequences=[['name=a'],['name=b'],['name=missing'],['NAME=A','snap'],['name=a','name=missing','stayshut'],['name=a','name=b','BACKWARD','FORWARD','snap'],['name=a','backwards','stayopen'],['name=b','BACKWARD','stayshut'],['name=missing','name=b','SNAP'],['name=a','stayopen','stayshut']]
for kind,tokens,first,flags,state,speed in itertools.product(['scp','git','special'],sequences,[False,True],[0,2,4],[0,1,2,3,4],[-1.,0.,2.]):
 options=dict(controlFlags=flags,state=state,speed=speed,concreteBindings=True);nodes=setup(tokens,options)
 expected=f.parse_command(kind,tokens,options,nodes,first);expected['calls']=[]
 if kind=='scp':result=n.call(0x44ea70,[0,0,0,f.ARGS,len(tokens),int(first)])
 else:n.call(0x465720 if kind=='special'else 0x465590,[f.WORLD+0x2ac8,0,f.ARGS,len(tokens)]);result=1
 actual={'result':result,'state':f.state(nodes)};expected={'result':1,'state':expected}
 row={'group':'command','input':{'kind':kind,'tokens':tokens,'first':first,'options':options},'expected':actual};rows.append(row)
 if actual!=expected:errors.append({'input':row['input'],'expected':expected,'native':actual})
report={'binarySha256':n.sha256,'cases':len(rows),'mismatches':len(errors),'examples':errors[:10],'adapters':[],'nativeBodies':['0x44ea70','0x465590','0x465720','0x55a020','0x558770','0x5ae390','0x4f8b10','0x557960','0x5579d0','0x558970','0x558990','0x5a1030','0x5a11b0','0x5a11f0','0x5a1230','0x4f1310'],'domain':'Prepared two-type/two-object registry, bounded valid tokens, finite scene fields and rates, well-formed member/queue records. Native temporal animation update and registry loader remain outside this suite.','vectors':'reports/native-obstacle-binding-vectors.json'}
(B/'reports/native-obstacle-binding-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-obstacle-binding-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'cases':rows},indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));print(json.dumps(errors[:1],indent=2));assert not errors
