"""Original AlertCreatures and real global alert producer; callback only boundary."""
from pathlib import Path
src=Path(__file__).with_name('movement-phase6-20261013-native.py').read_text().split('for first,gate,tokens in itertools.product')[0]
src=src.replace("r['name']=='SetDoomedEscapeLocator'","r['name']=='AlertCreatures'")
exec(compile(src,str(Path(__file__).with_name('movement-phase6-20261013-native.py')),'exec'))
n=m.NativeX86();n.mu.hook_add(UC_HOOK_CODE,charhook)
TYPE=D+0x46000;G=0x876cb0;vectors=[];errors=[];groups={}

def setup_alert(meta,tokens):
 setup(meta,tokens);n.write(SECOND,n.read(ACTOR,SIZE));n.pack('<I',SECOND+0x54,SECOND_DEF);n.pack('<I',SECOND_REF,SECOND);n.pack('<I',SECOND_REF+0x100,0)
 n.pack('<I',0x923904,CHAR if meta.get('characterCallback',True)else 0)
 for j,a in enumerate([ACTOR,SECOND]):
  n.pack('<I',a+0x1fc,meta.get('actorFlags',0x1001));n.pack('<B',a+0x1f8,meta.get('actorMask',0));n.pack('<I',a+0x54,(DEFINITION if j==0 else SECOND_DEF)if not meta.get('missingDefinition')else 0)
  df=DEFINITION if j==0 else SECOND_DEF;n.pack('<I',df+0x24,TYPE+0x100*j if not meta.get('missingType')else 0);n.pack('<I',TYPE+0x100*j+0x90,meta.get('typeFlags',0));n.pack('<3I',a+0x80,*meta.get('position',[0x7fc12345,0x80000000,0x3f800000]))
 n.pack('<3I',TARGET,*meta.get('bodyPosition',[0xffffffff,0x80000000,0x7f800000]));n.write(G,bytes([0xa5])*48);n.pack('<I',0x7f6728,meta.get('duration',0x7fc98765))
 if meta.get('gate',3)==1:n.pack('<I',CREATURE+0xd0,0)
 if meta.get('gate',3)==2:n.pack('<I',REFERENCE,0)

def model_alert(meta,tokens,first,kind,before):
 ev=[];target=0 if meta.get('gate',3)==3 else None;out=bytearray(before);fault=False
 if kind=='body':target=meta.get('bodyTarget',0)
 elif not first:return out,ev,fault
 else:
  for text in tokens:
   low=text.lower()
   if'character='in low:
    name=text[low.index('character=')+10:]
    if meta.get('characterCallback',True):ev.append(['character',name]);target={'Self':0,'Other':1}.get(name)
    else:target=None
    if name=='Self'and meta.get('gate',3)==2:target=None
  if target is None:return out,ev,fault
 actorFlags=meta.get('actorFlags',0x1001);mask=meta.get('actorMask',0);accept=target is None
 if target is not None and actorFlags&1 and actorFlags&0x1000 and mask&5==0:
  if meta.get('missingDefinition')or meta.get('missingType'):return out,ev,True
  accept=meta.get('typeFlags',0)&0x8000==0
 if accept:
  source=0 if target is None else[ACTOR,SECOND][target];pos=meta.get('bodyPosition',[0xffffffff,0x80000000,0x7f800000])if kind=='body'else meta.get('position',[0x7fc12345,0x80000000,0x3f800000]);struct.pack_into('<3I',out,8,*pos);struct.pack_into('<II',out,0x28,source,meta.get('duration',0x7fc98765))
 return out,ev,fault

def run_alert(kind,meta=None,tokens=None,first=True,group='synthetic'):
 meta=meta or {};tokens=tokens or [];setup_alert(meta,tokens);before=n.read(G,48);actorBefore=[n.read(a,SIZE)for a in[ACTOR,SECOND]];want,wev,wfault=model_alert(meta,tokens,first,kind,before);fault=False;result=None
 try:
  if kind=='body':result=n.call(0x4399e0,[0 if meta.get('bodyTarget',0)is None else[ACTOR,SECOND][meta.get('bodyTarget',0)],TARGET])
  else:result=n.call(0x454150,[WORLD,PACKET,0 if meta.get('gate',3)==0 else CREATURE,TOKENS,len(tokens),int(first)])
 except RuntimeError as ex:fault=True
 after=n.read(G,48);actors=[n.read(a,SIZE)for a in[ACTOR,SECOND]];groups[group]=groups.get(group,0)+1
 if after!=want or events!=wev or fault!=wfault or actors!=actorBefore or(kind!='body'and not fault and result!=1):errors.append({'kind':kind,'meta':meta,'tokens':tokens,'first':first,'fault':[fault,wfault],'globals':[after.hex(),want.hex()],'events':[list(events),wev]})
 vectors.append({'kind':kind,'input':dict(meta),'tokens':tokens,'first':first,'before':before.hex(),'after':after.hex(),'actors':[a.hex()for a in actorBefore],'events':list(events),'fault':fault,'result':None if kind=='body'or fault else result})
for kind,flags,mask,types,duration in itertools.product(['body','command'],[0,1,0x1000,0x1001,0xffffffff],[0,1,2,4,5,255],[0,0x8000,0xffffffff],[0,0x80000000,0x7fc98765]):
 run_alert(kind,dict(actorFlags=flags,actorMask=mask,typeFlags=types,duration=duration),group='producer-bit-grid')
for bodyTarget,flags,missingDef,missingType in itertools.product([None,0,1],[0,0x1001],[False,True],[False,True]):
 run_alert('body',dict(bodyTarget=bodyTarget,actorFlags=flags,missingDefinition=missingDef,missingType=missingType),group='null-and-fault-gates')
for first,gate,callback,tokens in itertools.product([False,True],[0,1,2,3],[False,True],[[],['ignored'],['character=Other'],['character=Missing','character=Self'],['character=Self','character=Null'],['xxcharacter=Other','character=Self']]):
 run_alert('command',dict(gate=gate,characterCallback=callback),tokens,first,'ordered-reference-gates')
for u in authored['uses']:run_alert('command',{},u['args'],True,'authored')
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':sum(4 if v['kind']=='body'else 5 for v in vectors),'mismatches':len(errors),'errors':errors,'groups':groups,'authoredOccurrences':authored['sourceUses'],'faultCases':sum(v['fault']for v in vectors),'method':'Original454150 invokes unchanged4399e0. Complete48byteglobalimage,two4312byteactorimages,callbackorder,guardedfaults andparentreturn compared; C# replay separate/pending.','adapters':['Character-reference lookup callback returns prepared Self/Other/Null/missing reference. Callback absence tested.'],'limits':['Prepared valid actor/definition/type memory except deliberate null faults; recordallocation/lifetime and downstreamalert consumers remain external.','All position/timer words copiedraw, including quietNaN/infinity/signedzero. No arithmetic/nonfinite policy inferred.']}
(B/'reports/movement-phase7-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(B/'reports/movement-phase7-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'vectors':vectors},out,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'checks':report['assertionGroups'],'mismatches':len(errors),'faultCases':report['faultCases'],'examples':errors[:4]}))
