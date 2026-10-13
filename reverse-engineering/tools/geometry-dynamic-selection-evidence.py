"""Stable LOD/material branch projection from original dynamic submission."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/DynamicSelection.cs';native=json.loads((R/'geometry-dynamic-selection-native-validation.json').read_text());managed=json.loads((R/'geometry-dynamic-selection-managed-check.json').read_text());arrays=[s['thresholds']for f in native['sources']for s in f['specials']];coverage={'authoredArrays':len(arrays),'multiLod':sum(len(a)>1 for a in arrays),'unique':len(set(tuple(a)for a in arrays)),'maximumLevels':max(map(len,arrays))}
rows=[('SelectLod','Finite nonempty bounded threshold array and finite nonnegative stored squared distance; signed forced index. No center/distance,fade,visibility or matrix-sway producer reconstruction implied.'),('ChooseMaterial','Valid finite material/table pointers; clone5e5020 is an explicit callback boundary for layout mismatch. No clone allocation/cache implementation.'),('FilterChain','Finite acyclic material chain of at most1000000 records, preserving native order and raw gate bytes. No visibility marking,shader or packet side effects.')]
report={'schema':'recovered-geometry-dynamic-selection-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':'0x5f0f00','method':'DynamicSelection.'+method,'sourceFile':core,'coverage':'small-extracted-branch','limitations':limit+' Compiled comparison pending; not complete5f0f00.','evidence':'geometry-dynamic-selection-native-validation.json'}for method,limit in rows],'dependencies':['RenderPacketMemory'],'native':{'report':'geometry-dynamic-selection-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources']),'authoredLodCoverage':coverage,'binarySHA256':native['binarySHA256'],'boundaries':native['bounds']},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicSelection.dll'),'harness':info('reconstructed/geometry/harness/DynamicSelectionHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.DynamicSelection.dll DynamicSelection.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicSelection.dll /out:DynamicSelectionHarness.exe harness\\DynamicSelectionHarness.cs'},'observations':['Forced LOD0 uses strict distance<threshold; equality keeps current level. Any other signed forced index walks until equality or the zero terminator; negative forced indexes therefore reach terminator. An initialzero always chooseslevel0.','Nonzero material tag plus present override table suppresses global fallback even when that table entry is0. Zero tag or absent table selects global override when nonzero.','Selected replacement with different source/layout+1f0 calls unresolved5e5020; equal layout uses replacement directly.','Filtermode1 accepts gateA255 or allthreezero; every othermode accepts gateA!=255.'], 'remainingGaps':[{'id':'whole-dynamic-submission','address':'0x5f0f00','status':'Three branches recovered; remaining arithmetic,visibility/material marking,shader/packet orchestration and shadow paths not represented by this module.'},{'id':'material-clone-cache','address':'0x5e5020','status':'Boundary callback recorded; native linked lookup/allocation/copy behavior remains separate.'},{'id':'managed-execution','status':'Compile passed,fixture prepared; no launch.'},{'id':'gpu-command-consumption','status':'Branch choices only; GPU output unclaimed.'}]}
(R/'geometry-dynamic-selection-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-selection-findings.txt').write_text('''Dynamic LOD/material-selection branches

Three pure branch projections from5f0f00 are now buildable. SelectLod uses
strict distance<threshold; equality retains the current level. Forcedindex0
uses distance, any other signed forced value walks until matching index or
zero terminator. Initialzero always chooseslevel0. Negative forced values
therefore reach the terminator. Distances are supplied float32 squared values;
the complete center/distance producer is not claimed by this projection.

ChooseMaterial retains a subtle precedence rule: nonzero material+9a tag with
a present override table selects its entry, including0. An empty tagged entry
keeps the source material rather than falling back to the global override.
Zero tag or absent table permits global override. Different+1f0 layout requires
the unresolved5e5020 clone/cache callback. FilterChain preserves linked order:
mode1 accepts gateA255 or allthree gatebytes zero; other modes require A!=255.

5,928 original LOD cases and96 override/linked-gate cases pass.24 clone-boundary
calls are observed.60 authored scenes supply threshold arrays, with controlled
single-part LOD records used to expose the selected index. Original center,
transform and distance helpers run; force-visibility1,zero shadows,no fade or
sway bound this slice.5fd220/607590/5e0530 are skipped downstream boundaries;
5e5020 returns a controlled clone. This does not validate their side effects
or the complete dynamic caller. Synthetic threshold/equality/forced cases
complement the actual authored-array coverage recorded in the source report.

DynamicSelection.cs and Main DynamicSelectionHarness compile with default
AnyCPU. The1,391-byte gzip fixture takes compressedInputFixture/outputFile;
geometry-dynamic-selection-check.py prepares or compares saved results only.
Managed execution remains pending. Three mappings share one native entry and
must not be counted as three newly recovered functions.
''')
print(json.dumps({'branchMappings':len(rows),'nativeAddresses':1,'cases':managed['caseCount'],'coverage':coverage,'managed':managed['status']}))
