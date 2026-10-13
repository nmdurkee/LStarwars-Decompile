"""Stable dependency fragment for dynamic material queue reconstruction."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 d=(B/p).read_bytes();return {'file':p,'bytes':len(d),'sha256':hashlib.sha256(d).hexdigest()}
core='reconstructed/geometry/DynamicMaterialPackets.cs';native=json.loads((R/'geometry-dynamic-packets-native-validation.json').read_text());managed=json.loads((R/'geometry-dynamic-packets-managed-check.json').read_text())
rows=[('0x603440','SetReserved1','Writes opcode87/control0/zero resource; other command bytes unchanged.'),('0x603450','SetReserved2','Writes opcode87/control0/zero resource; additional source caller argument ignored.'),('0x603460','SetMaterial','Writes opcode80/control3/material pointer; remaining command bytes unchanged.'),('0x603480','SetReserved4','Writes opcode87/control0/zero resource; additional source caller argument ignored.'),('0x603490','SetReserved5','Writes opcode87/control0/zero resource; additional source caller argument ignored.'),('0x5de100','ConstructMaterial','128-byte unaligned packet constructor; supplied link count1..255 replaces original global80baa8(value8). Original first/fourth caller arguments ignored. Link target need not be in this record for writer-only contract.'),('0x5de390','RefreshRanges','Nonnegative finite sort count and summed material counts at most1,000,000; valid table/record pointers. Updates first matching material index for each nonempty group; preserves missing-key start values.')]
report={'schema':'recovered-geometry-dynamic-packets-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'DynamicMaterialPackets.'+m,'sourceFile':core,'coverage':'bounded-whole-helper-projection','limitations':l+' Finite valid memory domain and no pointer wrap. Managed execution pending.','evidence':'geometry-dynamic-packets-native-validation.json'}for a,m,l in rows],'adaptersWithoutNativeEntry':['MaterialSortKey is the inline original signed16-shift/priority expression; it is not a new native entry.','RenderPacketMemory supplies finite read/write pointer projection.'],'dependencies':['RenderPacketMemory'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicPackets.dll'),'harness':info('reconstructed/geometry/harness/DynamicMaterialPacketsHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.DynamicPackets.dll DynamicMaterialPackets.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicPackets.dll /out:DynamicMaterialPacketsHarness.exe harness/DynamicMaterialPacketsHarness.cs'},'native':{'report':'geometry-dynamic-packets-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources'])},'managed':managed,'nativeDefaultGlobals':{'0x80baa8':8,'0x80baac':6,'0x80bab0':7},'fields':{'material+0x00':'Low16 tag shifts left4,truncates signed16,then arithmetic-right-shifts8 to layer value','material+0x76':'Signed16 priority term; key=layer*0x20000+priority','sort record+0x00/+0x20/+0x22':'Key,unsigned16 material count,unsigned16 first material index','display+0x50/+0x60/+0x64':'Material pointer array,sort count,36-byte sort record array','constructed packet':'85 header;two87reserved;80material;two87reserved;8b link;84/control4 terminator'},'remainingGaps':[{'id':'dynamic-list-flush','address':'0x5de440','status':'Dependencies reconstructed; actual add/remove/refcount/list compaction still next phase'},{'id':'managed-execution','status':'Compiled only; compact fixture prepared; no launch/bypass'},{'id':'gpu-command-consumption','status':'These helpers write command bytes only; GPU semantics remain unclaimed'}]}
(R/'geometry-dynamic-packets-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-packets-findings.txt').write_text('''Dynamic material packet dependencies

Original5de100 reserves exactly128bytes without aligning its caller cursor.
It writes an85 header,two87 placeholders,an80 material command,two more87
placeholders,an8b link and an84/control4 terminator. Both links use the original
global80baa8(value8),while the saved-command and final-link indexes used by the
caller are80baac=6 and80bab0=7. Five small setters modify only opcode,control
and resource bytes; the extra material/index arguments to four setters are
ignored by this PC binary. Unchanged packet padding is explicitly checked.

Original5de390 sums unsigned16 group counts and searches that many material
pointers for the first matching key of each nonempty sort group. A missing key
leaves its existing first-material index unchanged. The key uses signed16
truncation after shifting the material tag left4,then arithmetic-right-shift8,
multiplied by0x20000,plus signed16 material+0x76. This is distinct from treating
the initial tag or final priority as unsigned.

600 unchanged original cases pass:320 setter cases,96 constructor/link-count/
unaligned-cursor cases,120 authored/reversed material-table cases across60
scenes,and64 signed-key boundary cases.1,696 range matches and3,812,352 compared
state/call bytes agree. Constructor first/fourth ignored caller arguments are
deliberately nonzero. Link counts1/2/6/8/16/255 verify the writer contract;
only8 is the observed original global default.

DynamicMaterialPackets.cs has seven native mappings and compiles with its
harness. The508,037-byte gzip fixture covers every case. Main
DynamicMaterialPacketsHarness takes compressedInputFixture/outputFile.
Compiled execution remains pending. The actual5de440 add/remove/refcount and
list-compaction algorithm is still separate work; these recovered dependencies
make its next batch concrete. No game,managed harness,or GPU was launched.
''')
print(json.dumps({'mappings':len(rows),'native':native['passed'],'managed':managed['status']}))

