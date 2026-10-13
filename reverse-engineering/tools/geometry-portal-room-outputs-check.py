"""Prepare compact original room-output replay; never launches managed code."""
import argparse,gzip,json,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-portal-room-outputs-native-validation.json').read_text());assert native['passed']
with gzip.open(R/native['fixturesFile'],'rt',encoding='utf8')as f:cases=json.load(f)['cases']
buffer=bytearray(b'PROI'+struct.pack('<I',len(cases)));expected=bytearray(b'PROO'+struct.pack('<I',len(cases)))
for c in cases:
 buffer.extend(struct.pack('<IhI',c['roomCount'],c['root'],len(c['volumeRooms'])))
 for room in c['volumeRooms']:buffer.extend(struct.pack('<h',room))
 expected.extend(bytes(c['nativeQueries']));expected.extend(bytes.fromhex(c['nativeMask']));expected.extend(bytes([0xa5])*16)
for present in [False,True]:
 expected.extend(bytes([1])*6)
 for value in [0,0xa5,255]:expected.extend(bytes([value])*16)
inputPath=D/'portal-room-outputs.bin';inputPath.write_bytes(buffer)
report={'schema':'portal-room-outputs-managed-check-v1','nativeEvidence':'geometry-portal-room-outputs-native-validation.json','fixtureCount':len(cases),'fixtureBytes':len(buffer),'fixtureSHA256':hashlib.sha256(buffer).hexdigest(),'expectedOutputBytes':len(expected),'expectedOutputSHA256':hashlib.sha256(expected).hexdigest(),'status':'prepared-not-executed','mainType':'PortalRoomOutputsHarness','arguments':['inputFixture','outputFile'],'comparison':'All original query results,mask bytes,16-byte tail canaries and18 disabled calls; exact byte equality.','resultClaim':'No compiled-source equivalence until ordinary managed output is compared.'}
if args.compare:
 output=args.compare.read_bytes();report.update(status='passed'if output==expected else'failed',outputSHA256=hashlib.sha256(output).hexdigest(),outputBytes=len(output),resultClaim='Saved compiled output compared to original-PC results.')
 if output!=expected:report['firstDifferentByte']=next((i for i,(a,b)in enumerate(zip(output,expected))if a!=b),min(len(output),len(expected)))
(R/'geometry-portal-room-outputs-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']=='failed':raise SystemExit(1)
