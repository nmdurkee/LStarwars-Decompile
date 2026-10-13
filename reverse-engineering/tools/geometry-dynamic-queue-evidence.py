"""Stable source/evidence fragment for original PC dynamic material queue."""
import hashlib,json
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/DynamicMaterialQueue.cs'
native=json.loads((R/'geometry-dynamic-queue-native-validation.json').read_text())
managed=json.loads((R/'geometry-dynamic-queue-managed-check.json').read_text())
domain='Finite valid memory; slot capacity<=4096, queue counts<=1000000, native sort capacity600; free material/packet slots available and reachable acyclic sort removal lists. Original packet constants8/6/7. Pointer overflow, malformed memory and original-faulting compaction states excluded. Managed comparison pending.'
report={
 'schema':'recovered-geometry-dynamic-queue-source-v1','namespace':'Recovered.Geometry',
 'coreModules':[info(core)],
 'nativeMappings':[{'address':'0x5de440','method':'DynamicMaterialQueue.Flush','sourceFile':core,'coverage':'bounded-whole-helper-projection','limitations':domain,'evidence':'geometry-dynamic-queue-native-validation.json'}],
 'dependencies':['RenderPacketMemory','DynamicMaterialPackets.MaterialSortKey','DynamicMaterialPackets.ConstructMaterial','DynamicMaterialPackets.RefreshRanges'],
 'adaptersWithoutNativeEntry':['Stack-local packet constructor cursor uses a private132-byte image, copying only128 native packet bytes back.','Returned function-address trace is diagnostic; native function has no equivalent list return.','Finite capacity and list guards replace out-of-domain faults; they do not claim native recovery behavior.'],
 'native':{'report':'geometry-dynamic-queue-native-validation.json','passed':native['passed'],'counts':native['counts'],'binarySHA256':native['binarySHA256'],'excludedUnsafeCases':native['excludedUnsafeCases'],'fixture':info('reports/geometry-dynamic-queue-fixtures.json.gz')},
 'managed':managed,
 'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicQueue.dll'),
 'harness':info('reconstructed/geometry/harness/DynamicMaterialQueueHarness.cs'),
 'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicPackets.dll /out:Recovered.Geometry.DynamicQueue.dll DynamicMaterialQueue.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicPackets.dll /reference:Recovered.Geometry.DynamicQueue.dll /out:DynamicMaterialQueueHarness.exe harness\\DynamicMaterialQueueHarness.cs'},
 'fields':{'root':'Original extended display/global region begins0x973dbc; portable root explicit.','+0x4c/+0x50/+0x54':'Slot capacity/material pointer table/control record pointer table','+0x60/+0x64':'Sort count/36-byte sort array','+0x90/+0x94':'Add count/queue','+0x98/+0x9c':'Remove count/queue','+0xa0/+0xa4':'Byte reference counts/new sort node type','+0xa8/+0xac/+0xb0':'128-byte packet pool/ignored constructor argument/packet-used bytes','+0x10c/+0x110':'Linked sort count/head'},
 'observations':['Remove queue precedes add queue; both counts are cleared after processing.','Reference counts wrap as bytes, including increment255->0 and decrement0->255.','Original material key is signed16 shifted tag plus signed16 priority.','Empty sort-group removal unlinks by address then copies later36-byte records forward physically, without repairing every moved link.','Material pointer/control/reference arrays compact; final control pointer recycled; stale final material pointer preserved.','One controlled batched-removal state faults inside unchanged original0x5de612 and fails source reachability guard; its full input is preserved under excludedUnsafe in native fixture. This does not establish an in-game reachable bug.'],
 'remainingGaps':[{'id':'normal-finish-integration','status':'Populated native queue and sorted shader completion are independently validated; full original finish caller integration remains separate.'},{'id':'dynamic-submission','address':'0x5f0f00','status':'Actual selected mesh/transform handoff remains a boundary.'},{'id':'managed-execution','status':'Compiled only; fixture prepared; no launch/bypass.'},{'id':'gpu-command-consumption','status':'CPU command bytes and state verified; GPU results unclaimed.'}]
}
(R/'geometry-dynamic-queue-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-queue-findings.txt').write_text('''Dynamic material queue: original PC0x5de440

The complete finite add/remove/refcount/list-compaction helper is reconstructed
in DynamicMaterialQueue.Flush. It uses the original128-byte packet constructor,
five setter helpers, signed material-key expression and range refresh. Original
queue instructions and all dependencies execute unchanged during native tests;
hooks observe calls only. Whole memory snapshots retain pointer identities,
untouched padding, reference byte overflow and physical array compaction.

261 original-vs-Python cases pass:1,067 queued adds,362 removes,291 packet
constructors,307 range refreshes and7,399,424 compared bytes. Slot capacities
0/1/2/3/4/8/12/16/32/64, signed sort keys, persistent retain/release sequences,
absent/unattached materials and byte overflow/underflow are covered.

One controlled batched-removal state is excluded and retained byte-for-byte:
the original faults at0x5de612 after physical sort-record compaction makes a
later removal node unreachable through the existing linked addresses. The
portable model rejects the same stale/cyclic traversal. It deliberately keeps
the original compaction writes instead of inventing pointer repairs. This
controlled malformed sequence is not evidence of a reachable game defect.

The portable capacity guard4096 and queue guard1000000 are projection limits;
600 sort groups is the original branch bound. Valid allocated pointers, free
slots and finite reachable lists are required. The original fixed packet
constants are8/6/7. Root0x973dbc and its extended globals become an explicit
RenderPacketMemory image; the native stack-local constructor cursor uses a
private temporary image and introduces no extra visible arena writes.

Core and harness compile with ordinary AnyCPU settings. The36,174-byte gzip
fixture contains all261 passing snapshots; Main DynamicMaterialQueueHarness
takes compressedInputFixture and outputFile. geometry-dynamic-queue-check.py
prepares the fixture or compares saved output; it never launches a program.
Compiled C# equivalence is still pending. No game or GPU execution is claimed.
''')
print(json.dumps({'mappings':1,'nativeCases':native['counts']['cases'],'managed':managed['status']}))
