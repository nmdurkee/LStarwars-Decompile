"""Stable shader CPU emission and sorted integration source handoff."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 b=(B/p).read_bytes();return {'file':p,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
core='reconstructed/geometry/ShaderContextEmission.cs';native=json.loads((R/'geometry-shader-emission-native-validation.json').read_text());integration=json.loads((R/'geometry-sorted-shader-native-validation.json').read_text());managed=json.loads((R/'geometry-shader-emission-managed-check.json').read_text());im=json.loads((R/'geometry-sorted-shader-managed-check.json').read_text())
rows=[('0x607590','Emit','Six-key context/cache comparison,changed payload allocation,command linking and cached context update; supplied values replace three fixed globals.'),('0x5fcdf0','BuildVectorMatrixPayload','SevenXYZ vectors with inserted1.0 W words,16-word matrix and3 trailing words;188-byte output.'),('0x5fcef0','BuildOptionalScalarPayload','Shader+f4 selects raw+f8 or1.0word;4-byte output.'),('0x5fcf30','BuildWordPayload','Copy shader+194 raw word;4-byte output.'),('0x5fcf60','BuildConditionalWordsPayload','Shader+16c raw word plus four additional raw words only when nonzero;4/20-byte output.'),('0x5fcfd0','BuildSignedBytePayload','Optional global descriptor: unsigned bytecount/secondary value then sign-extended bytes converted to exactfloat32 integers; trailing rounded slots preserved.')]
report={'schema':'recovered-geometry-shader-emission-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'ShaderContextEmission.'+m,'sourceFile':core,'coverage':'bounded-whole-helper-projection','limitations':l+' Valid finite nonoverlapping record/context/arena storage; no uint address overflow; GPU consumption excluded; managed execution pending.','evidence':'geometry-shader-emission-native-validation.json'}for a,m,l in rows],'adaptersWithoutNativeEntry':['CompleteSorted connects recovered SortedPackets.Complete to recovered mutating Emit and joins diagnostic nested call traces. It introduces no new native mapping.','Private matrix-payload construction is inline original607590 behavior,not an independently mapped entry.','Supplied allocator-control pointer,signed-byte descriptor and token base replace globals0x9736e0/0x9738a4/0x297dc00.'],'dependencies':['RenderPacketMemory','SortedPackets.Append','SortedPackets.Complete','FrameReset.ResetShaderContext'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.ShaderEmission.dll'),'harnesses':[info('reconstructed/geometry/harness/ShaderContextEmissionHarness.cs'),info('reconstructed/geometry/harness/SortedShaderHarness.cs')],'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.FrameReset.dll /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.ShaderEmission.dll ShaderContextEmission.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.FrameReset.dll /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.ShaderEmission.dll /out:ShaderContextEmissionHarness.exe harness/ShaderContextEmissionHarness.cs','integrationHarnessCommand':'csc /nologo /reference:Recovered.Geometry.FrameReset.dll /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.ShaderEmission.dll /out:SortedShaderHarness.exe harness/SortedShaderHarness.cs'},'native':{'report':'geometry-shader-emission-native-validation.json','passed':native['passed'],'counts':native['counts']},'integratedNative':{'report':'geometry-sorted-shader-native-validation.json','passed':integration['passed'],'counts':integration['counts'],'sources':integration['sources']},'managed':managed,'integratedManaged':im,'keyCommandMap':[{'contextWord':hex(k),'payloadCacheWord':hex(c)if c else None,'command':hex(cmd)}for k,c,cmd in[(0x24,0x34,0x94),(0x2c,0x110,0x9a),(0x2e,0x168,0xa6),(0x1e,0x180,0xa5),(0x32,0x198,0xab),(0x30,0,0xa9)]],'definedDetails':['The entire helper returns early if shader pointer is0 or context+20 equals shader+20,regardless of differing subordinate keys.','Keys compare16-bit equality; matrix token sign-extends shader+2c then applies32-bit wrap arithmetic with shader+20 and the token base.','Raw payload words preserve bit patterns including arbitrary float encodings; only signed-byte payload performs numerical conversion.','Every allocation is16-byte aligned; signed-byte arrays reserve4-float blocks and do not clear trailing padded floats.','Absent signed-byte descriptor emits noA9command but still updates that context key.','Original append return is allocator-control pointer only for inline payload; these shader commands pass explicit payloads.'],'remainingGaps':[{'id':'managed-execution','status':'Both harnesses compile; comparison fixtures prepared; no executable launch or bypass'},{'id':'live-runtime-adapters','status':'CPU source uses decoded valid memory projections; no live captured engine frame or Unity integration'},{'id':'dynamic-list-flush','address':'0x5de440','status':'still outside recovered finish integration'},{'id':'gpu-command-consumption','status':'Generated command bytes verified; downstream D3D state/rendering interpretation remains separate'}],'supersedesBoundaries':[{'report':'geometry-sorted-packets-source.json','boundary':'Mutating607590 shader emission was explicit there; this new module and120 original integration cases now recover its finite CPU domain. Prior report remains a historical scoped result.'},{'report':'geometry-static-finish-source.json','boundary':'Sorted5e0d00 callback can now be connected toCompleteSorted for the verified valid memory domain; dynamic5de440 callback remains.'}]}
(R/'geometry-shader-emission-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-shader-emission-findings.txt').write_text('''CPU shader context emission and sorted command integration

Original607590 first tests null shader or equal identifier words at+20 and
returns immediately. Otherwise it compares six16-bit keys in order:
+24/+2c/+2e/+1e/+32/+30. Commands94/9a/a6/a5/ab/a9 carry their changed payloads.
Five payload pointers are cached in shader+34/+110/+168/+180/+198; the final
signed-byte descriptor is rebuilt when its key changes. Context keys update
even when the optional final descriptor is absent and noA9command is emitted.
The identifier updates after all subordinate work.

The188-byte vector/matrix payload copies opaque words and inserts1.0 vectorW.
The4-byte scalar uses a raw optional word or1.0. Another helper copies one raw
word; a conditional payload writes one or five words. The optional byte-array
payload has twoDWORD header values and converts signed bytes to exactfloat32
integers. It reserves four-float blocks and preserves unused trailing bytes.
The inline148-byte matrix payload includes a signed16-bit key in a wrapping
32-bit token expression,matrix words,a zero-initialized local matrix with five
assigned words,and four trailing source words. Native tests cover edge keys
0/1/7fff/8000/ffff and identifier values0/1/ffffffff/80000000/7fffffff.

All1,680 isolated original cases pass:640 payload/alignment cases,1,024 context
key/cache/identifier/descriptor combinations,and16 null shader cases.
8,856,384 state/call bytes match. Every64-key subset is covered,cached and
uncached payloads,matching and different identifiers,and absent/empty/3/255
byte descriptors. Additional payload lengths1/4/5/127 exercise rounding.

Integration adds120 cases across all60 authored portal scenes. Original
5e0d00 calls changed-context607590,which calls original payload writers and
6034b0.6,422 changed shader calls,38,532 appends,6,902 payload calls and
47,862,269 compared state/call bytes match. Independent tail choices ensure
active materials exercise both original tail-equal and tail-different paths.
This corrects a correlation in the earlier sorted fixture patterns; no
unexecuted branch is silently inferred. Authored material flags/index maps/
sort ranges combine with controlled valid runtime cursors,not a live capture.
All original instructions execute unchanged; hooks only observe entries.

ShaderContextEmission.cs has six bounded native mappings. CompleteSorted is
an integration adapter toSortedPackets,not an extra recovered native entry.
Both harnesses compile. Their gzip fixtures are2,244,390 and3,291,547bytes,
respectively. Arguments are compressedInputFixture/outputFile. Check scripts
only prepare or compare saved output. Compiled C# behavior remains pending.

The static sorted-finalization callback now has a recovered finite CPU
implementation including shader emission. Dynamic-list flush5de440 remains
separate. This does not establish downstream GPU interpretation/rendering,
a live engine frame,or a Unity project. Invalid pointers,partial metadata/
arena overlap and allocator address overflow remain outside the source domain.
''')
print(json.dumps({'mappings':len(rows),'native':native['passed'],'integration':integration['passed'],'managed':managed['status']}))

