"""Original room-query/mask consumers over every validated authored traversal output."""
import importlib.util,json,struct,hashlib,gzip
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
with gzip.open(R/'geometry-portal-runtime-fixtures.json.gz','rt',encoding='utf8')as f:source=json.load(f)
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};scene=n.DATA;headers=scene+0x1000;output=scene+0x3000
counts={'roomQueries':0,'roomMasks':0,'disabledQueries':0,'disabledMasks':0};errors=[];cases=[];digest=hashlib.sha256();queryDiffersFromMask=0
def compare(kind,actual,expected,meta):
 counts[kind]+=1;digest.update(str((actual,expected)).encode())
 if actual!=expected and len(errors)<30:errors.append({'kind':kind,'context':meta,'native':actual,'expected':expected})
for ci,c in enumerate(source['traversal']):
 row=index[c['source']];roomCount=row['rooms'];volumeRooms=c['nativeVolumeRooms'];root=c['root'];n.write(scene,b'\0'*0x200);n.pack('<I',scene+0x6c,row['portals']);n.pack('<I',scene+0x74,roomCount);n.pack('<I',scene+0xdc,len(volumeRooms));n.pack('<i',scene+0xe0,root)
 for vi,room in enumerate(volumeRooms):n.pack('<I',scene+0x9c+vi*4,headers+160*vi);n.pack('<h',headers+160*vi+0x9e,room)
 queries=[]
 for room in range(-2,roomCount+1):
  actual=n.call(0x5da2d0,[scene,room]);expected=int(room in volumeRooms);compare('roomQueries',actual,expected,{'case':ci,'room':room});queries.append(actual)
 n.write(output,bytes([0xa5])*(roomCount+16));n.call(0x5da330,[scene,output]);mask=bytearray(roomCount);mask[root]=1
 for room in volumeRooms:
  if room>=0:mask[room]=1
 actual=n.read(output,roomCount+16);expected=bytes(mask)+bytes([0xa5])*16;compare('roomMasks',actual.hex(),expected.hex(),{'case':ci})
 if not queries[root+2]and mask[root]:queryDiffersFromMask+=1
 cases.append({'source':c['source'],'traversalCase':ci,'roomCount':roomCount,'root':root,'volumeRooms':volumeRooms,'nativeQueries':queries,'nativeMask':n.read(output,roomCount).hex()})
for present in [False,True]:
 n.write(scene,b'\0'*0x200)
 for room in [-32768,-2,-1,0,1,32767]:compare('disabledQueries',n.call(0x5da2d0,[scene if present else 0,room]),1,{'scenePresent':present,'room':room})
 for before in [bytes(16),bytes([0xa5])*16,bytes([255])*16]:
  n.write(output,before);n.call(0x5da330,[scene if present else 0,output]);compare('disabledMasks',n.read(output,16).hex(),before.hex(),{'scenePresent':present})
report={'schema':'original-portal-room-outputs-v1','binarySHA256':n.sha256,'passed':not errors,'counts':counts,'errors':errors,'traversalCases':len(cases),'sourceRooms':403,'sourcePortals':326,'rootMaskQueryDifferenceCases':queryDiffersFromMask,'resultSHA256':digest.hexdigest(),'fixturesFile':'geometry-portal-room-outputs-fixtures.json.gz','scope':['Original5da2d0 and5da330 execute with no result or code adapters.','Input allocated-room sequences come directly from all validated original recursive outputs.','Room mask retains16-byte canary beyond the declared room count; null/no-portal calls leave output unchanged.'],'observations':['5da2d0 searches only allocated clip-header room IDs,including negative values; it does not independently include the root room.','5da330 clears declared room bytes,sets the current root,andsets each nonnegative allocated clip room.','Null scene or zero portal count makes5da2d0 return1 but makes5da330 a no-op.'],'limits':['Successful-entry root must be a valid room; invalid root would write outside native output and is excluded.','Portable compiled execution remains pending; no managed launches.']}
(R/'geometry-portal-room-outputs-native-validation.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(R/'geometry-portal-room-outputs-fixtures.json.gz','wt',encoding='utf8')as f:json.dump({'cases':cases},f,separators=(',',':'))
print(json.dumps({k:report[k]for k in ['passed','counts','rootMaskQueryDifferenceCases','errors']},indent=2))
if errors:raise SystemExit(1)
