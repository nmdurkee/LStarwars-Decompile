"""Separate room-consumer source handoff; does not edit stable geometry maps."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 data=(B/p).read_bytes();return {'file':p,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/PortalRoomOutputs.cs'
report={'schema':'recovered-geometry-room-outputs-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':'0x5da2d0','method':'PortalRoomOutputs.HasClipForRoom','sourceFile':core,'coverage':'whole helper within valid allocated-header list; pointer scene presence/portal count represented by Boolean','evidence':'geometry-portal-room-outputs-native-validation.json'},{'address':'0x5da330','method':'PortalRoomOutputs.WriteRoomMask','sourceFile':core,'coverage':'whole helper within valid successful-entry root and output bounds; null/no-portal branch retained','evidence':'geometry-portal-room-outputs-native-validation.json'}],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.RoomOutputs.dll'),'harness':info('reconstructed/geometry/harness/PortalRoomOutputsHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','reference':'reconstructed/geometry/Recovered.Geometry.dll','commands':['csc /nologo /target:library /reference:Recovered.Geometry.dll /out:Recovered.Geometry.RoomOutputs.dll PortalRoomOutputs.cs','csc /nologo /reference:Recovered.Geometry.dll /reference:Recovered.Geometry.RoomOutputs.dll /out:GeometryRoomOutputsHarness.exe harness\\PortalRoomOutputsHarness.cs']},'managed':json.loads((R/'geometry-portal-room-outputs-managed-check.json').read_text()),'native':json.loads((R/'geometry-portal-room-outputs-native-validation.json').read_text()),'limits':['Original native behavior was compared against Python expectations. Compiled C# execution remains pending; no managed launch attempted.','Invalid root indices and corrupt header/output pointers are outside the portable adapter; native out-of-bounds writes are not reproduced.','Does not change the stable PortalTraversal source or existing shared source map.']}
(R/'geometry-portal-room-outputs-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-portal-room-outputs-findings.txt').write_text('''Original room-output consumers: 0x5da2d0 and 0x5da330

All 7,888 saved original traversal outputs were replayed through both unchanged
native consumers: 90,574 room queries and 7,888 masks, plus 12 disabled queries
and 6 disabled masks. There are zero mismatches; 16 tail canary bytes beyond
every room mask remain intact.

The contracts intentionally differ. The query searches only the allocated clip
header room IDs, including negative values, while the mask clears roomCount
bytes and sets the selected root plus every nonnegative clip room. In 7,875
fixtures the root appears in the mask but has no allocated clip carrying its ID.
Initial clip room -2 can be queried, but negative clip IDs are omitted from masks.
Null or zero-portal scenes make queries return true and leave mask bytes alone.

PortalRoomOutputs.cs and its harness compile successfully as a separate library
referencing the stable geometry assembly. The compact 112,626-byte replay covers
all query/mask outputs and canaries. Managed execution remains pending; no
compiled equivalence or operating-system workaround is claimed. Mapping and
hashes are in geometry-portal-room-outputs-source.json, separate from the stable
geometry source ledger. Invalid roots or corrupt native pointers are excluded.
''')
print(json.dumps({'mappings':len(report['nativeMappings']),'build':report['build']['status'],'managed':report['managed']['status']}))
