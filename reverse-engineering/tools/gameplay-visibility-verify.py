"""Original scene/gizmo visibility command handlers with original lookup/callbacks.
Synthetic type registries use actual NuSpecial callbacks; no native call is replaced.
This does not establish the distinct implementations of every shipped gizmo type.
"""
import importlib.util,json,itertools,struct
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
n=native.NativeX86();BASE=native.BASE;D=n.DATA
WORLD=D;SCENE=D+0x6000;DYNAMIC=D+0x6200;STATIC=D+0x7000;DYNINST=D+0x7400;BOUNDS=D+0x8000;AUX=D+0x9000;NAMES=D+0xa000;ARGS=D+0xb000;TEXT=D+0xc000
REG=D+0x10000;TYPES=D+0x10100;SYS=D+0x11000;SYSTYPES=D+0x11200;HANDLES=D+0x12000;OBJS=D+0x13000;FLOW=D+0x16000
checks={};errors=[];vectors=[];trace=[]
def check(kind,got,want,meta=None):
 checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,got=got,want=want,input=meta))
def observer(mu,address,size,user):
 if address in [0x5ae450,0x5ae520,0x5cfc00]:
  sp=mu.reg_read(UC_X86_REG_ESP);trace.append(dict(address=hex(address),args=list(n.unpack('<II',sp+4))))
n.mu.hook_add(UC_HOOK_CODE,observer,begin=0x5ae450,end=0x5cfc00)
def init(ts,names=('first','second','first'),dynamic=False,aux=True,type_names=('NuSpecial','Other'),visibility=True):
 n.write(D,bytes(0x18000));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x13c,SCENE);n.pack('<I',WORLD+0x2ac8,SYS);n.pack('<I',0x97388c,0);n.pack('<I',0x93b268,REG)
 n.pack('<I',SCENE+0x110,DYNAMIC if dynamic else 0);n.pack('<II',SCENE+0x24,len(names),STATIC);n.pack('<II',DYNAMIC+0x6c,len(names),DYNINST);n.pack('<B',DYNAMIC+0x76,int(aux));n.pack('<I',DYNAMIC+0x48,AUX)
 for i,name in enumerate(names):
  n.write(NAMES+128*i,name.encode()+b'\0');n.pack('<I',STATIC+0x4c*i+0x44,NAMES+128*i);n.pack('<I',STATIC+0x4c*i+0x40,BOUNDS+0x80*i);n.pack('<I',STATIC+0x4c*i+0x48,0x80000200 if visibility else 0x80000000);n.pack('<I',BOUNDS+0x80*i+0x44,0x10|int(visibility))
  n.pack('<I',DYNINST+0xd0*i+0xb4,NAMES+128*i);n.pack('<I',DYNINST+0xd0*i+0xb8,0x80000202 if visibility else 0x80000000);n.pack('<I',DYNINST+0xd0*i+0xc0,i);n.pack('<B',AUX+i,0xa4|int(visibility))
 n.pack('<3I',REG,len(type_names),0,TYPES);n.pack('<I',SYS,SYSTYPES);n.pack('<I',FLOW,SYS)
 registration=n.call(0x5ae8e0,[0])
 for t,type_name in enumerate(type_names):
  n.write(TYPES+t*0x9c,type_name.encode()+b'\0')
  for run,reg in [(0x44,0x24),(0x54,0x34),(0x5c,0x3c)]:n.pack('<I',TYPES+t*0x9c+run,n.unpack('<I',registration+reg)[0])
  # Two first-match candidates per type, laid out like runtime handles.
  n.pack('<I',SYSTYPES+t*20+4,2);n.pack('<I',SYSTYPES+t*20+12,HANDLES+t*16)
  for j in range(2):
   k=t*2+j;o=OBJS+k*0x400;h=HANDLES+k*8;an=o+0x80;item=o+0x100;control=o+0x180
   name=names[0] if j==0 else names[1];assert len(name)<32
   n.write(o,name.encode()+b'\0');n.pack('<I',h,o);n.pack('<B',h+6,t);n.pack('<I',o+0x20,an);n.pack('<B',o+0x24,2);n.pack('<H',an+10,4);n.pack('<I',an+12,1);n.pack('<I',an+24,item)
   n.pack('<4I',item,0,SCENE,STATIC+0x4c*k,0);n.pack('<I',item+16,control);n.pack('<f',control+0x40,.75);n.pack('<I',control+0x50,1)
   # Physical NuSpecial item uses its own static record; ensure fourth item exists.
   n.pack('<I',STATIC+0x4c*k+0x40,BOUNDS+0x80*k);n.pack('<I',STATIC+0x4c*k+0x48,0x80000200 if visibility else 0x80000000);n.pack('<I',BOUNDS+0x80*k+0x44,0x10|int(visibility))
 for i,s in enumerate(ts):n.write(TEXT+i*256,s.encode()+b'\0');n.pack('<I',ARGS+4*i,TEXT+i*256)
 trace.clear()
def scene_snapshot(dynamic=False):
 return [dict(flags=n.unpack('<I',(DYNINST+0xd0*i+0xb8) if dynamic else (STATIC+0x4c*i+0x48))[0],secondary=n.unpack('<B',AUX+i)[0] if dynamic else n.unpack('<I',BOUNDS+0x80*i+0x44)[0]) for i in range(3)]
def gizmo_snapshot():return [dict(visible=bool(n.unpack('<I',STATIC+0x4c*i+0x48)[0]&0x200),active=bool(n.unpack('<B',OBJS+0x400*i+0x24)[0]&2),playing=n.unpack('<I',OBJS+0x400*i+0x180+0x50)[0]&1) for i in range(4)]
def scan(ts,kind):
 name=None;visible=True;type_name=None
 for token in ts:
  lower=token.lower()
  if 'name=' in lower:name=token[lower.index('name=')+5:]
  elif kind=='gizmo-git' and 'type=' in lower:type_name=token[lower.index('type=')+5:]
  elif (lower=='false' if kind=='gizmo-scp' else 'false' in lower):visible=False
 return name,visible,type_name
forms=[[],['name=first'],['name=first','FALSE'],['FALSE','name=first','TRUE'],['name=first','prefixFALSEsuffix'],['prefixNAME=FiRsT','false'],['name=first','name=second','FALSE'],['name=first','name=missing','FALSE'],['name=missing','name=first','FALSE'],['name=false','TRUE']]
for dynamic,aux,first,ts in itertools.product([False,True],[False,True],[False,True],forms):
 for kind,address in [('scene-git',0x464480),('scene-scp',0x44cd40)]:
  init(ts,dynamic=dynamic,aux=aux);before=scene_snapshot(dynamic);n.call(address,[0,0,ARGS,len(ts)] if kind.endswith('git') else [0,0,0,ARGS,len(ts),int(first)]);got=scene_snapshot(dynamic);name,visible,_=scan(ts,kind);want=[dict(x) for x in before]
  selected=next((i for i,s in enumerate(['first','second','first']) if name and s.lower()==name.lower()),None)
  if selected is not None and (first or kind.endswith('git')):
   want[selected]['flags']=(want[selected]['flags']&~(0x202 if dynamic else 0x200))|((0x202 if dynamic else 0x200) if visible else 0)
   if not dynamic or aux:want[selected]['secondary']=(want[selected]['secondary']&~1)|int(visible)
  check('scene-command-and-physical-flags',got,want,dict(kind=kind,dynamic=dynamic,aux=aux,first=first,tokens=ts));vectors.append(dict(kind=kind,dynamic=dynamic,aux=aux,first=first,tokens=ts,native=got))

gforms=forms+[['name=first','type=Other','FALSE'],['name=first','type=other','FALSE'],['type=Other','name=first','type=missing','FALSE'],['type=Other','name=second','FALSE'],['name=second','FALSE','TRUE']]
for kind,address,first,ts in itertools.product(['gizmo-git','gizmo-scp'],[0],[False,True],gforms):
 address=0x464530 if kind=='gizmo-git' else 0x456350;init(ts);before=gizmo_snapshot();n.call(address,[FLOW,0,ARGS,len(ts)] if kind=='gizmo-git' else [0,0,0,ARGS,len(ts),int(first)]);got=gizmo_snapshot();name,visible,typ=scan(ts,kind);want=[dict(x) for x in before];selected=None
 search=[2,3] if kind=='gizmo-git' and typ=='Other' else [0,1] if kind=='gizmo-git' and typ=='NuSpecial' else [0,1,2,3]
 for i in search:
  if name and ['first','second'][i%2].lower()==name.lower():selected=i;break
 if selected is not None and (first or kind=='gizmo-git'):
  want[selected]['visible']=visible
  if not visible:want[selected]['active']=False;want[selected]['playing']=0
 check('gizmo-command-and-real-NuSpecial',got,want,dict(kind=kind,first=first,tokens=ts))
 called=[x['address'] for x in trace];expected=(['0x5ae450'] if not visible else [])+['0x5ae520','0x5cfc00'] if selected is not None and (first or kind=='gizmo-git') else []
 check('gizmo-hide-deactivation-order',called,expected,ts);vectors.append(dict(kind=kind,first=first,tokens=ts,native=got))

ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text());shipped=[]
addresses={'0x464480':'scene-git','0x44cd40':'scene-scp','0x464530':'gizmo-git','0x456350':'gizmo-scp'}
for row in ledger['rows']:
 if row['function'] not in addresses:continue
 kind=addresses[row['function']]
 for use in row['uses']:
  ts=use['args'];name,visible,typ=scan(ts,kind);assert name is not None
  # Authored type labels select a synthetic registered category backed by real
  # NuSpecial callbacks; this verifies lookup/dispatch, not that category's engine.
  init(ts,names=(name,'__other__',name),type_names=(typ or 'NuSpecial','Other'))
  n.call(int(row['function'],16),[FLOW,0,ARGS,len(ts)] if kind.endswith('git') else [0,0,0,ARGS,len(ts),1])
  if kind.startswith('scene'):
   got=scene_snapshot();want=[dict(flags=0x80000200,secondary=0x11)]*3;want=[dict(x) for x in want];want[0]=dict(flags=0x80000000|(0x200 if visible else 0),secondary=0x10|int(visible))
  else:
   got=gizmo_snapshot();want=[dict(visible=True,active=True,playing=1) for _ in range(4)];want[0]=dict(visible=visible,active=visible,playing=int(visible))
  check('shipped-'+kind,got,want,use);shipped.append(dict(kind=kind,source=use['source'],line=use['line'],tokens=ts,fixtureName=name,fixtureType=typ or 'NuSpecial',native=got))
report={'binarySha256':n.sha256,'checks':sum(checks.values()),'mismatches':len(errors),'groups':checks,'errors':errors[:20],'shippedOccurrences':len(shipped),'method':'Unmodified PC scene/gizmo command functions, original scene/type/name lookup, native visibility wrapper and real NuSpecial animation/scene callbacks. Code hooks observe arguments only; no function replacement. Synthetic finite registries and scene records.',
 'limits':['Synthetic category labels for authored type= arguments use NuSpecial callbacks to validate command dispatch; distinct GizForce/GizObstacle/etc physical implementations are not validated.','Dynamic scene fallback global 0x97388c is zero; external named fallback function 0x5c1300 remains outside scope.','Static scene and dynamic scene branches are tested separately, with at most three name entries, first duplicate match and current scene binding.','Compiled C# differential execution pending.']}
(BASE/'reports/gameplay-visibility-tests.json').write_text(json.dumps(report,indent=2),encoding='utf-8');(BASE/'reports/gameplay-visibility-native-fixtures.json').write_text(json.dumps({'binarySha256':n.sha256,'cases':vectors,'shipped':shipped},separators=(',',':')),encoding='utf-8')
print(json.dumps(report));assert not errors
