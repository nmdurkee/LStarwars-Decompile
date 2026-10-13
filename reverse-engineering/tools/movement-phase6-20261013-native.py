"""Original SetDoomedEscapeLocator plus original integer RNG and locator lookup."""
from pathlib import Path
src=Path(__file__).with_name('movement-phase3-20261013-native.py').read_text().split('def model_request')[0]
src=src.replace("r['name']=='BigJumpToLocator'","r['name']=='SetDoomedEscapeLocator'").replace('for va in [0x55e4a0,SELECT,0x62e040,0x62e650,0x547f30,0x6e69ef,0x51ac10,0x44661e]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=va,end=va)','n.mu.hook_add(UC_HOOK_CODE,hook)')
exec(compile(src,str(Path(__file__).with_name('movement-phase3-20261013-native.py')),'exec'))
import base64
SECOND=D+0x40000;SECOND_DEF=D+0x42000;SECOND_REF=D+0x45000;CHAR=n.STOP+0x200;vectors=[];errors=[];groups={};case_options={}
# Missing random suffixes are valid lookup failures; add all four for successful random tests.
for name in ['L_1','L_2','L_Other']:
 if not any(r['name']==name for r in records):records.append({'name':name,'position':[0,0,0],'orientation':[0]*6})

def charhook(mu,address,size,user):
 if address!=CHAR:return
 sp=mu.reg_read(UC_X86_REG_ESP);name=cstr(n.unpack('<I',sp+8)[0]);events.append(['character',name]);mapping={'Self':REFERENCE,'Other':SECOND_REF,'Null':SECOND_REF+0x100};value=mapping.get(name,0)
 return_int(mu,n.unpack('<I',sp)[0],sp,value)
n.mu.hook_add(UC_HOOK_CODE,charhook)
def rng(seed):
 x=seed^0x075bd924;sv=signed(x);q=(abs(sv)//0x1f31d)*(-1 if sv<0 else 1);v=(x*0x41a7-q*0x7fffffff)&0xffffffff
 if signed(v)<0:v=(v+0x7fffffff)&0xffffffff
 return v^0x075bd924

def numeric(text):
 if'param'in text.lower():return .5
 sign=-1 if text.startswith('-')else 1;text=text[1:]if text.startswith(('-','+'))else text;whole=dec=0.;div=1.;after=False
 for ch in text:
  if ch=='.':after=True;continue
  if ch<'0'or ch>'9':break
  if after:dec=f32(dec*10+int(ch));div=f32(div*10)
  else:whole=f32(whole*10+int(ch))
 return f32(sign*f32(whole+f32(dec/div)))
def model(images,meta,tokens,first):
 ev=[];seed=meta.get('seed',123);target=0 if meta.get('gate',3)==3 else None;name=None;personal=indexed=damage=False;rand=0
 if not first or not tokens:return seed,ev
 for text in tokens:
  low=text.lower()
  if'character='in low:
   nm=text[low.index('character=')+10:]
   if meta.get('characterCallback',True):ev.append(['character',nm]);target={'Self':0,'Other':1}.get(nm)
   else:target=None
   if nm=='Self'and meta.get('gate',3)==2:target=None
  elif'name'in low:name=text[low.index('name')+5:]
  elif'personal'in low:personal=True
  elif'indexed'in low:indexed=True
  elif'take_damage'in low:damage=True
  elif'random'in low:rand=int(numeric(text[low.index('random')+9:]))
 if target is None:return seed,ev
 image=images[target];flags=struct.unpack_from('<I',image,0xef0)[0]&~0x800;struct.pack_into('<II',image,0xf14,0,struct.unpack_from('<I',image,0xf18)[0]);struct.pack_into('<I',image,0xef0,flags)
 if name is None:return seed,ev
 index=struct.unpack_from('<b',image,0x280)[0];definition=struct.unpack_from('<I',image,0x54)[0]
 if indexed and index!=-1:name+='_'+str(index)
 elif personal and definition:name+='_'+('Hero'if target==0 else'Other')
 elif rand:
  seed=rng(seed);draw=signed(seed);remainder=(abs(draw)%abs(rand))*(-1 if draw<0 else 1);name+='_'+str(remainder)
 ev.append(['lookup',name]);ix=next((i for i,r in enumerate(records)if r['name'].lower()==name.lower()),-1)
 if ix>=0:struct.pack_into('<I',image,0xf14,LOCATORS+ix*0x3c);struct.pack_into('<I',image,0xef0,flags|(0x800 if damage else 0))
 return seed,ev

def run(meta,tokens,first=True,group='synthetic'):
 setup(meta,tokens);n.pack('<I',ACTOR+0xf14,0xdeadbeef);n.pack('<I',ACTOR+0xef0,meta.get('flags',0xffffffff));n.pack('<I',ACTOR+0x54,0 if meta.get('noDefinition')else DEFINITION)
 n.write(SECOND,n.read(ACTOR,SIZE));n.pack('<I',SECOND+0x54,0 if meta.get('secondNoDefinition')else SECOND_DEF);n.pack('<b',SECOND+0x280,meta.get('secondIndex',-128));n.pack('<I',SECOND+0xef0,0xa5a5a5a5);n.pack('<I',SECOND_DEF+0xc,TEXT+0x1200);n.write(TEXT+0x1200,b'Other\0');n.pack('<I',SECOND_REF,SECOND);n.pack('<I',SECOND_REF+0x100,0)
 n.pack('<I',0x923904,CHAR if meta.get('characterCallback',True)else 0);n.pack('<I',0x8066c0,meta.get('seed',123))
 gate=meta.get('gate',3)
 if gate==1:n.pack('<I',CREATURE+0xd0,0)
 if gate==2:n.pack('<I',REFERENCE,0)
 before=[bytearray(n.read(a,SIZE))for a in[ACTOR,SECOND]];expected=[bytearray(a)for a in before];want_seed,want_events=model(expected,meta,tokens,first)
 n.call(0x446b30,[WORLD,PACKET,0 if gate==0 else CREATURE,TOKENS,len(tokens),int(first)])
 after=[n.read(a,SIZE)for a in[ACTOR,SECOND]];actual_seed=n.unpack('<I',0x8066c0)[0];groups[group]=groups.get(group,0)+1
 if after!=expected or actual_seed!=want_seed or events!=want_events:errors.append({'meta':meta,'tokens':tokens,'first':first,'rng':[actual_seed,want_seed],'events':[events,want_events],'diff':[[j,hex(i),after[j][i],expected[j][i]]for j in range(2)for i in range(SIZE)if after[j][i]!=expected[j][i]][:30]})
 vectors.append({'input':dict(meta),'tokens':tokens,'first':first,'before':[a.hex()for a in before],'after':[a.hex()for a in after],'seed':actual_seed,'events':list(events)})
for first,gate,tokens in itertools.product([False,True],[0,1,2,3],[[],['take_damage'],['name=L'],['character=Other','name=L'],['character=Null','name=L']]):run({'gate':gate},tokens,first,'gates-and-zero-token')
for index,secondIndex,noDef,personal,indexed,randomCount,damage,retarget in itertools.product([-1,0,3],[-128,-1,3],[False,True],[False,True],[False,True],[0,4],[False,True],[False,True]):
 toks=(['character=Other']if retarget else[])+(['indexed']if indexed else[])+(['personal']if personal else[])+(['randomix='+str(randomCount)]if randomCount else[])+['name=L']+(['take_damage']if damage else[])
 run(dict(index=index,secondIndex=secondIndex,noDefinition=noDef,secondNoDefinition=noDef),toks,group='format-target-damage-grid')
for cb,toks in itertools.product([False,True],[['name=L','character=Other','name=Missing'],['character=Missing','character=Self','name=L'],['name=L','name=Missing','name=L'],['personalname=L','xxindexed','xxname=L'],['xrandomix=4','name=L'],['name=L','randomix=-4'],['take_damage','name=Missing'],['name=L','character=Null','take_damage']]):run({'characterCallback':cb},toks,group='ordered-substrings')
for seed in [0,1,0x075bd924,0x7fffffff,0x80000000,0xffffffff]:run({'seed':seed},['randomix=4','name=L'],group='native-integer-rng-composition')
for gate,first in itertools.product([0,1,2,3],[False,True]):run({'gate':gate},['character=Missing','character=Self','name=L'],first,'retarget-reference-first-word')
for u in authored['uses']:run({},u['args'],group='authored')
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':4*len(vectors),'mismatches':len(errors),'errors':errors,'groups':groups,'authoredOccurrences':authored['sourceUses'],'method':'Original SetDoomedEscapeLocator with real locator lookup/packet numeric parse/integer RNG/string search/security cookie; both4312byteactorimages,RNG,callbackorder compared. C# replay separate and pending.','adapters':['Character-name-reference resolver returns prepared Self/Other/Null/missing references; callback absence included.','Only bounded ASCII printf name formats are adapted; plain names have no directives and fit63bytes.'],'limits':['Finite numeric operands with representable signedinteger conversion; boundedname length and no printf directives.','Prepared actor/definition/name/locator memory; target state producer and escape/damage consumers remain external.','Shipped forms and positive/zero native token counts; negative counts outside sourceAPI.']}
(B/'reports/movement-phase6-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(B/'reports/movement-phase6-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'records':records,'vectors':vectors,'rngVectors':json.loads((B/'reports/movement-phase6-20261013-rng-fixtures.json').read_text())['vectors']},out,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'checks':4*len(vectors),'mismatches':len(errors),'examples':errors[:4]}))
