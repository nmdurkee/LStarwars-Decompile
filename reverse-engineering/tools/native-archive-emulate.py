"""Exercise original PC LZ2K decompressor in isolated Unicorn memory; no game/OS process execution."""
import importlib.util, json, hashlib, struct, time
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
base=mod.BASE; assets=json.loads((base/'reports/all-assets.json').read_text()); native=mod.NativeX86()
files=[]
for archive in sorted(set(a['archive'] for a in assets)):
 candidates=sorted([a for a in assets if a['archive']==archive and a['flags']==2],key=lambda a:a['size'])
 files += [candidates[0],candidates[len(candidates)//2],candidates[-1]]
result={'method':'Original PC x86 function0x4faea0 with original callees executed in Unicorn against real LZ2K chunks; compare extracted bytes. No patched/stubbed target routines.','binarySha256':native.sha256,'address':'0x4faea0','cases':[],'failures':[],'started':time.time()}
seen=set()
for a in files:
 with (base.parent/'Lego Star Wars Saga'/a['archive']).open('rb') as h:h.seek(a['offset']);stored=h.read(a['storedSize'])
 chunks=[];p=0;o=0
 while p<len(stored):
  magic=stored[p:p+4];expanded,compressed=struct.unpack_from('<II',stored,p+4)
  if magic!=b'LZ2K':raise ValueError(magic)
  chunks.append((p,o,expanded,compressed));p+=12+compressed;o+=expanded
 for ix in sorted(set([0,len(chunks)//2,len(chunks)-1])):
  p,o,expanded,compressed=chunks[ix]
  if expanded==compressed:continue
  data=stored[p+12:p+12+compressed];digest=hashlib.sha256(data).hexdigest()
  if digest in seen:continue
  seen.add(digest)
  case={'archive':a['archive'],'path':a['path'],'chunk':ix,'storedChunkOffset':p,'expandedOffset':o,'compressedBytes':compressed,'expandedBytes':expanded,'compressedSha256':digest}
  try:
   native.write(native.DATA,data);native.write(native.DATA+0x80000,b'\xcc'*expanded)
   returned=native.call(0x4faea0,[native.DATA,native.DATA+0x80000,compressed,expanded],count=200000000)
   actual=native.read(native.DATA+0x80000,expanded)
   with (base/'extracted'/a['path']).open('rb') as h:h.seek(o);expected=h.read(expanded)
   case.update(returnedBytes=returned,matched=actual==expected,outputSha256=hashlib.sha256(actual).hexdigest())
   if returned!=expanded or actual!=expected:raise ValueError('Output mismatch')
   result['cases'].append(case)
  except Exception as e:case['error']=str(e);result['failures'].append(case)
  print(json.dumps({'cases':len(result['cases']),'failures':len(result['failures']),'last':case}),flush=True)
result.update(finished=time.time(),passed=not result['failures'],totalBytes=sum(c['expandedBytes'] for c in result['cases']))
(base/'reports/native-archive-emulation.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items() if k not in ['cases','failures']}))
if result['failures']:raise SystemExit(1)
