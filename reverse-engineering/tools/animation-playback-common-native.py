"""Verify native common-animation path callback against all emitted definitions."""
import importlib.util,json,struct,hashlib,collections
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE;P=n.DATA;NAME=P+0x1000;PREFIX=P+0x2000;OUT=P+0x3000
def string(at):return n.read(at,512).split(b'\0')[0].decode('latin1')
table=[]
for i in range(256):
 at=0x7f2228+8*i;ptr,raw=n.unpack('<II',at)
 if not ptr:break
 table.append({'address':hex(at),'name':string(ptr),'namePointer':hex(ptr),'actionId':struct.unpack('<h',struct.pack('<H',raw&65535))[0],'raw':n.read(at,8).hex()})
else:raise ValueError('Common-animation table unterminated')
catalog=json.loads((BASE/'reports/animation-playback-catalog-native.json').read_text());counts=collections.Counter();rows=[];errors=[];files={p.relative_to(BASE/'extracted').as_posix().casefold():p for p in (BASE/'extracted/CHARS').rglob('*.AN3')}
n.write(PREFIX,b'chars\\commonanims\\\0')
for row in catalog['rows']:
 if row['status']!='loaded':continue
 definition=bytearray.fromhex(row['definitionHex']);struct.pack_into('<I',definition,0,NAME);n.write(NAME,row['nativeName'].encode('latin1')+b'\0');n.write(P,definition);n.write(OUT,bytes([0xa5])*256)
 matched=any(t['name'].casefold()==row['nativeName'].casefold()and t['actionId']==row['actionId']for t in table)
 result=n.call(0x55b260,[PREFIX,0x7f2228,P,OUT]);want=bytearray(definition)
 if matched:struct.pack_into('<I',want,4,row['flags']&~8)
 path=string(OUT)if result else None;expected='chars\\commonanims\\'+row['nativeName']if matched else None
 if result!=int(matched)or n.read(P,76)!=want or path!=expected:errors.append({'source':row['source'],'line':row['line'],'result':result,'expected':matched,'path':path,'expectedPath':expected})
 info={'source':row['source'],'line':row['line'],'actionId':row['actionId'],'name':row['nativeName'],'nativeResult':result,'nativePathPrefixAndName':path,'flagsBefore':row['flags'],'flagsAfter':n.unpack('<I',P+4)[0]}
 if result:
  clip=files.get((path.replace('\\','/')+'.an3').casefold());counts['commonMatched']+=1
  if clip:info['clipSource']=clip.relative_to(BASE).as_posix();info['clipSha256']=hashlib.sha256(clip.read_bytes()).hexdigest();counts['commonFilePresent']+=1
  else:counts['commonFileMissing']+=1
 else:
  counts['commonNotMatched']+=1
  if row['localClip']:counts['localCandidatePresent']+=1
  else:counts['unresolvedLocalMiss']+=1
 counts['comparisons']+=1;rows.append(info)
# No registered table is also a valid full native branch.
n.write(P,definition);n.write(OUT,bytes([0xa5])*256);result=n.call(0x55b260,[PREFIX,0,P,OUT]);counts['nullTableCases']+=1
if result or n.read(P,76)!=definition or n.read(OUT,256)!=bytes([0xa5])*256:errors.append({'case':'nullTable'})
report={'binarySha256':n.sha256,'nativeEntry':'0x55b260','registrationEntry':'0x62d4a0','initializerEvidence':'FUN_42e160 uses table0x7f2228 in its later initializer branch; another branch passes0x855f6c. This report does not infer which initialization branch applies to every runtime character.','tableAddress':'0x7f2228','tableBytesSha256':hashlib.sha256(n.read(0x7f2228,(len(table)+1)*8)).hexdigest(),'table':table,'counts':dict(counts),'mismatches':len(errors),'errors':errors,'rows':rows,'contract':'Only exact actionId AND case-insensitive name matches redirect to supplied common directory plus name. It clears definition flag8 (BSA) and returns1. No match or null table returns0 without writes. Extension is appended by caller62d540.','limits':['Original callback executed without replacements; caller archive/filesystem loaders not executed.','The callback table is explicit and source-pinned. Runtime branch/table selection remains an integration input.','File presence does not verify model/joint compatibility or inherited/merged configuration state.']}
(BASE/'reports/animation-playback-common-native.json').write_text(json.dumps(report,indent=2));print(json.dumps({'tableEntries':len(table),'counts':dict(counts),'mismatches':len(errors),'errors':errors[:3]},indent=2))
if errors:raise SystemExit(1)
