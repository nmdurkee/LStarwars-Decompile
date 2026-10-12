"""Classify residual clip bindings without guessing or repairing asset paths."""
import importlib.util,json,hashlib,collections,re,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE;P=n.DATA;NAME=P+0x1000;PREFIX=P+0x2000;OUT=P+0x3000
catalog=json.loads((BASE/'reports/animation-playback-catalog-native.json').read_text());common=json.loads((BASE/'reports/animation-playback-common-native.json').read_text());characters=json.loads((BASE/'reports/gameplay-catalog/characters.json').read_text());bsa=json.loads((BASE/'reports/animation-bsa-export.json').read_text())
shared={(r['source'],r['line']):r for r in common['rows']if r['nativeResult']};loaded=[r for r in catalog['rows']if r['status']=='loaded'];missing=[r for r in loaded if not r['localClip']and(r['source'],r['line'])not in shared];registered={r['config'].casefold()for r in characters['registry']if r.get('config')};bsaBy={r['path'].casefold():r for r in bsa['success']};counts=collections.Counter();rows=[];errors=[];nativeCases=0
n.write(PREFIX,b'chars\\commonanims\\\0');alternateHead=n.read(0x855f6c,8)
for row in missing:
 path=BASE.parent/row['source'];local=[p for p in path.parent.iterdir()if p.is_file()];sameStem=[p for p in local if p.stem.casefold()==row['nativeName'].casefold()];normalize=lambda v:re.sub('[^a-z0-9]','',v.casefold());variants=[p for p in local if p.suffix.upper()=='.AN3'and normalize(p.stem)==normalize(row['nativeName'])]
 alternatives=[{'line':r['line'],'name':r['nativeName'],'localClip':r['localClip'],'common':shared.get((r['source'],r['line']))}for r in loaded if r['source']==row['source']and r['actionId']==row['actionId']and r['line']!=row['line']and(r['localClip']or(r['source'],r['line'])in shared)]
 record={k:row[k]for k in ['source','sourceSha256','line','nativeName','actionId','actionName','flags']};record['directlyRegisteredConfig']=row['source'].casefold()in registered;record['sameActionAvailableDefinitions']=alternatives;record['localSameStemFiles']=[{'source':p.relative_to(BASE).as_posix(),'sha256':hashlib.sha256(p.read_bytes()).hexdigest(),'extension':p.suffix,'decodedBsa':bsaBy.get(p.relative_to(BASE/'extracted').as_posix().casefold())}for p in sameStem];record['punctuationVariantCandidates']=[{'source':p.relative_to(BASE).as_posix(),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()}for p in variants];record['elsewhereSameNameCount']=len(row['sameNameElsewhereCandidates'])
 if path.parent.name=='DARTHPLAGUEIS':status='unregistered_config_no_local_model_or_clips'
 elif alternatives:status='same_action_available_in_another_definition'
 elif sameStem:status='local_bsa_explicitly_enabled'if row['flags']&8 else'local_bsa_not_enabled_in_fixture'
 elif variants:status='filename_punctuation_variant_not_native_redirect'
 else:status='requested_local_asset_absent_no_verified_redirect'
 record['classification']=status;counts[status]+=1
 definition=bytearray.fromhex(row['definitionHex']);struct.pack_into('<I',definition,0,NAME);n.write(NAME,row['nativeName'].encode('latin1')+b'\0');n.write(P,definition);n.write(OUT,bytes([0xa5])*256);ret=n.call(0x55b260,[PREFIX,0x855f6c,P,OUT]);nativeCases+=1
 if ret or n.read(P,76)!=definition or n.read(OUT,256)!=bytes([0xa5])*256:errors.append({'source':row['source'],'line':row['line'],'case':'alternate-empty-table'})
 record['alternateTableReturned']=ret;rows.append(record)
initializers=[]
for old in [0,1,2,255,0xffffffff]:
 n.pack('<I',0x7f39e4,old);n.pack('<I',0x876580,0xffffffff);n.call(0x401100,regs={native.UC_X86_REG_ECX:0,native.UC_X86_REG_EAX:P});mode=n.unpack('<I',0x7f39e4)[0];other=n.unpack('<I',0x876580)[0];nativeCases+=1;initializers.append({'before':old,'after':mode,'otherAfter':other})
 if mode!=1 or other!=0:errors.append({'case':'initializer','before':old})
keywords=[]
for table in [0x804248,0x7f1724]:
 for i in range(512):
  at=table+8*i;name,fn=n.unpack('<II',at)
  if not name:break
  if not 0x400000<=name<0x3000000:break
  word=n.read(name,256).split(b'\0')[0].decode('latin1')
  if word in ['variant','bsa_default']:keywords.append({'keyword':word,'tableEntry':hex(at),'handler':hex(fn)})
PAR=P+0x6000;WORD=P+0x7000;GAME=P+0x8000
def tokenParser(token):
 n.write(PAR,bytes(0x600));n.write(NAME,token.encode('latin1')+b'\0');n.write(WORD,bytes(512));n.pack('<IIII',PAR+0x50c,NAME,WORD,512,512)
variantNames=['weirdo','stormtrooper','fett','macewindu','battledroid','wookiee','obiwankenobi','leia','clone','rebel','tie','lando','luke','hansolo','padme','walker2legs','walker4legs','hoverdroid','critter','naboostarfighter','pod','republicgunship','henchman'];variantMap={name:i for i,name in enumerate(variantNames)}
observed=sorted(set(s['args'][0]for cfg in characters['configs']for s in cfg['settings']if s['key']=='variant'and s['args']))
variantResults=[];n.pack('<I',0x954404,GAME)
for token in sorted(set(variantNames+observed+[v.upper()for v in variantNames]+['','unknown'])):
 before=bytes(range(256))*4;want=bytearray(before);expected=variantMap.get(token.casefold())
 if expected is not None:want[0x116]=expected
 tokenParser(token);n.write(GAME,before);n.call(0x413b70,[PAR]);nativeCases+=1
 if n.read(GAME,len(before))!=want:errors.append({'case':'variant','token':token})
 variantResults.append({'token':token,'expectedValue':expected,'actualValue':n.read(GAME+0x116,1)[0]})
bsaDefaultCases=0
for cfg in characters['configs']:
 for setting in cfg['settings']:
  if setting['key']!='bsa_default':continue
  token=setting['args'][0]if setting['args']else'';before=0xdeadbeec;want=before|1 if token.casefold()=='on' else before&~1 if token.casefold()=='off' else before
  tokenParser(token);n.pack('<I',0x95440c,before);n.call(0x584d50,[PAR]);nativeCases+=1;bsaDefaultCases+=1
  if n.unpack('<I',0x95440c)[0]!=want:errors.append({'case':'bsa-default','source':cfg['source'],'line':setting['line']})
report={'binarySha256':n.sha256,'rows':rows,'counts':dict(counts),'remainingRows':len(rows),'nativeVerification':{'cases':nativeCases,'mismatches':len(errors),'errors':errors,'alternateTableHeadHex':alternateHead.hex(),'initializerCases':initializers},'keywordAddresses':keywords,'branchProvenance':{'modeGlobal':'0x7f39e4','initializer':'0x401100 assigns1; original complete entry executed with ECX=0 (constructor loop empty).','selector':'0x42e160 tests global==0: registers0x855f6c; otherwise registers0x7f2228. Callback is55b260 and directory chars/commonanims in both.','alternative':'0x855f6c starts with null pointer in the pinned PC image, and native callback returns0 without any writes for all68 residual definitions. No direct writes to this table found in saved decompiled corpus.','scope':'Full game initialization42e160 not executed; no proof claimed against unseen indirect future mutations.'},'sourceFindings':{'darthPlagueis':'CHARS/CHARS.TXT lines1287-1291 comments out registration. Folder contains only DARTHPLAGUEIS.TXT;44 residual AN3 names therefore lack a shipped local model/clip set.','weirdo':'WEIRDO1/2 request highjumpland; shipped local file is HIGHJUMP_LAND.AN3. Native resolver only does case-insensitive exact matching, not punctuation normalization. Candidate retained without repair.','bsa':'Only WATTO residual names have local BSA files. throw explicitly enables BSA, while slide/ride_landspeeder/ride do not enable it in the fixture. BSA existence is not an AN3 skeleton substitute.','duplicates':'Two HanSolo configs also have shared ride_generic_new_blasterchar bound to the same action; Watto later defines force_choke for the same action. Native62d540 scans definitions and only installs an action whose destination pointer is still null. Full caller loading not emulated.','defaults':'PC589410 clears954400..954400+fc8 before each invocation;95440c BSA-default bit begins0, permanent bit40 supplied. Per-file bsa_default directives can change it before a block; isolated inventory intentionally fixes bit0 clear.'},'limits':['Do not replace missing names with similarly named files automatically.','Registered config membership does not imply every action is reachable.','Local absence is with respect to the fully extracted shipped asset corpus; same names in unrelated characters do not establish a supported fallback.','No new portable source or mapped-entrypoint claim; native callback/initializer evidence only.']}
report['nativeVerification'].update({'variantCases':len(variantResults),'bsaDefaultCases':bsaDefaultCases,'variantResults':variantResults})
report['sourceFindings']['defaults']='PC589410 clears954400..954400+fc8 before each invocation;95440c BSA-default bit begins0, permanent bit40 supplied. Catalog now replays160 same-file bsa_default directives through original584d50 before each block; inherited replacement remains separate.'
report['sourceFindings']['variant']='Original413b70 writes only gameCharacter+116 for known variants; full1024-byte game-character fixtures checked. It performs no path resolution or asset loading. Unknown names preserve prior value. Do not infer an animation asset fallback from variant=padme/fett.'
(BASE/'reports/animation-playback-binding-audit.json').write_text(json.dumps(report,indent=2));print(json.dumps({'counts':dict(counts),'nativeCases':nativeCases,'mismatches':len(errors),'variantCases':len(variantResults),'bsaDefaultCases':bsaDefaultCases,'keywords':keywords},indent=2))
if errors:raise SystemExit(1)
