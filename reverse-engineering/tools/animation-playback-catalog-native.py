"""Inventory every cataloged anim_start through original PC first-load parsing.

Not a full character loader: native per-file BSA-default directives are replayed,
effects disabled, each block begins at count zero. Local matches are candidates.
"""
import importlib.util,struct,json,hashlib,collections
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE;P=n.DATA;LINE=P+0x1000;WORD=P+0x2000;SET=P+0x3000;CHAR=P+0x4000;DEF=P+0x5000;CURSOR=P+0x6000;DELIM=P+0x7000;INPUT=P+0x10000;PREP=P+0x90000
n.pack('<I',0x29130e4,SET);n.pack('<I',SET+8,233);n.call(0x6306e0,[n.unpack('<I',0x7fbec8)[0],0x7fbed0]);n.pack('<I',0x954400,CHAR);n.pack('<I',CHAR+0x10,DEF);n.pack('<I',0x954420,CURSOR);n.write(DELIM,b'=\0')
catalog=json.loads((BASE/'reports/gameplay-catalog/characters.json').read_text());configs=catalog['configs'];registry=json.loads((BASE/'reports/animation-context-registry.json').read_text());names={a['id']:a['name']for a in registry['actions']}
files={};by_name=collections.defaultdict(list)
for path in (BASE/'extracted/CHARS').rglob('*.AN3'):
 raw=path.read_bytes();info={'source':path.relative_to(BASE).as_posix(),'sha256':hashlib.sha256(raw).hexdigest(),'bytes':len(raw)}
 magic=struct.unpack_from('<I',raw)[0];info['endFrame']=sum(struct.unpack_from('<H',raw,o)[0]for o in (10,14))if magic in(0x414e4934,0x414e4935)else struct.unpack_from('<f',raw)[0]
 files[str(path).casefold()]=info;by_name[path.stem.casefold()].append(info['source'])
rows=[];counts=collections.Counter();failures=[];configurationRows=[]
def prepare(payload):
 if len(payload)>0x60000:raise ValueError('Tail exceeds bounded in-memory parser buffer')
 n.write(P,bytes(0x600));n.write(LINE,bytes(4096));n.write(WORD,bytes(512));n.write(INPUT,payload+b'\0')
 length=n.call(0x54be70,[INPUT,PREP,1],count=2000000);prepared=n.read(PREP,length)
 n.pack('<I',P,PREP);n.pack('<IIII',P+0x50c,LINE,WORD,4096,512);n.pack('<III',P+0x524,0,0,length);n.pack('<I',P+0x574,length);n.pack('<I',P+0x57c,DELIM)
 n.call(0x4fc5b0,[P]);n.call(0x4f7fb0,[P]);return prepared
for cfg in configs:
 path=BASE.parent/cfg['source'];raw=path.read_bytes();lines=raw.splitlines(keepends=True);sourceHash=hashlib.sha256(raw).hexdigest();cfgRows=[]
 defaults=[];n.pack('<I',0x95440c,0x20)
 for setting in sorted((v for v in cfg['settings']if v['key']=='bsa_default'),key=lambda v:v['line']):
  prepare(lines[setting['line']-1]);n.call(0x584d50,[P]);value=n.unpack('<I',0x95440c)[0];defaults.append({'line':setting['line'],'flagsAfter':value,'handler':'0x584d50'});counts['nativeBsaDefaultDirectives']+=1
 for authored in cfg['animations']:
  defaultBefore=[v for v in defaults if v['line']<authored['line']];initialFlags=defaultBefore[-1]['flagsAfter']if defaultBefore else 0x20
  offset=sum(len(v)for v in lines[:authored['line']-1]);tail=raw[offset:];row={'source':cfg['source'],'sourceSha256':sourceHash,'line':authored['line'],'catalogEndLine':authored.get('endLine'),'catalogName':authored['name'],'catalogAction':authored.get('action'),'sourceByteOffset':offset,'fixtureGlobalFlags':initialFlags,'fixturePriorAnimationCount':0,'sourceBsaDefaultDirective':defaultBefore[-1]if defaultBefore else None}
  try:
   n.write(DEF,bytes(76));n.pack('<I',0x95440c,initialFlags);n.pack('<H',0x95441e,0);n.pack('<I',CURSOR,0)
   prepared=prepare(tail);row['nativePreprocessedSha256']=hashlib.sha256(prepared).hexdigest();row['nativePreprocessedBytes']=len(prepared)
   n.call(0x585760,[P],count=2000000);count=n.unpack('<H',0x95441e)[0];consumed=n.unpack('<I',P+0x524)[0];row['consumedPreprocessedBytes']=consumed;row['consumedPreprocessedSha256']=hashlib.sha256(prepared[:consumed]).hexdigest();row['nativeEndLine']=authored['line']+prepared[:consumed].count(b'\n')-1
   if count==1:
    definition=n.read(DEF,76);name=n.read(0x954428,40).split(b'\0')[0].decode('latin1');action=struct.unpack_from('<h',definition,8)[0];flags=struct.unpack_from('<I',definition,4)[0]
    row.update({'status':'loaded','nativeName':name,'actionId':action,'actionName':names.get(action),'definitionHex':definition.hex(),'definitionSha256':hashlib.sha256(definition).hexdigest(),'flags':flags,'playback':dict(zip(['blendIn','blendOut','fps','movementReference','rateCap'],struct.unpack_from('<5f',definition,16)))})
    clip=files.get(str(path.parent/(name+'.AN3')).casefold());row['localClip']=clip
    if not clip:row['sameNameElsewhereCandidates']=by_name.get(name.casefold(),[])
    counts['loaded']+=1;counts['localClipFound'if clip else'localClipMissing']+=1
    if clip:row['playback']['endFrame']=clip['endFrame']
   elif count==0:
    name=authored.get('name')or'';action=authored.get('action')
    if not action:reason='no_action_directive_in_catalog_block'
    else:
     n.write(WORD,action.encode('latin1')+b'\0');value=n.call(0x630740,[WORD]);reason='action_name_not_in_native_registry'if value==0xffffffff else'parser_skipped_requires_source_inspection'
    row.update({'status':'skipped','reason':reason});counts['skipped']+=1;counts['skip_'+reason]+=1
   else:raise ValueError('Unexpected native output count '+str(count))
  except Exception as e:
   row.update({'status':'fixture_failure','error':str(e)});counts['fixtureFailures']+=1;failures.append({'source':cfg['source'],'line':authored['line'],'error':str(e)})
  cfgRows.append(len(rows));rows.append(row);counts['blocks']+=1
 configurationRows.append({'source':cfg['source'],'sourceSha256':sourceHash,'blocks':cfgRows,'nativeBsaDefaultDirectives':defaults,'loadPlan':cfg['loadPlan'],'note':'LoadPlan retained as context; rows are isolated first-load blocks, not merged effective definitions.'})
 if len(configurationRows)%50==0:print('configs',len(configurationRows),'blocks',len(rows),'failures',len(failures),flush=True)
report={'binarySha256':n.sha256,'nativeEntry':'0x585760','nativeCallees':'Original text preprocessing54be70(mode1), GetLine/GetWord/numeric parsing/action registry and conditional subhandlers; no replacement code. Native bsa_default584d50 replayed in source order.','configurations':len(configs),'counts':dict(counts),'failures':failures,'rows':rows,'configs':configurationRows,'limits':['Isolated block first-load mode0x20, animation count0; full configuration loading and inherited replacement behavior not claimed.','Global BSA-default bit starts clear per native589410 memset; preceding same-file bsa_default directives replayed through original584d50. Per-block explicit bsa directives interpreted natively. Mode0x40 effect allocation disabled.','Native output definition flags include same-file BSA defaults; other character/effect allocation state remains fixture-supplied.','Local AN3 matches and same-name alternatives are source inventory evidence, not proof of runtime fallback or automatic binding.','Tail includes remaining original source and runs through native preprocessing, so malformed blocks may consume subsequent lines; consumed prepared hash/end line retained.','No portable C# definition parser verification is implied. PlaybackClip.FromDefinition is only a binary-record adapter.']}
out=BASE/'reports/animation-playback-catalog-native.json';out.write_text(json.dumps(report,indent=2));print(json.dumps({'report':str(out.relative_to(BASE)),'configurations':len(configs),'counts':dict(counts),'failures':failures[:10]},indent=2))
if failures:raise SystemExit(1)
