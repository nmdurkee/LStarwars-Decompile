"""Stable composition handoff; does not double-count the native finish mapping."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/SceneFinishPipeline.cs';native=json.loads((R/'geometry-finish-pipeline-native-validation.json').read_text());managed=json.loads((R/'geometry-finish-pipeline-managed-check.json').read_text())
report={'schema':'recovered-geometry-finish-pipeline-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[],'compositionMappings':[{'address':'0x5f0d70','method':'SceneFinishPipeline.Run','sourceFile':core,'coverage':'composition-adapter-of-existing-native-mappings','existingNativeMapping':'StaticFinalization.Finish in geometry-static-finish-source.json','limitations':'Zero-lock normal finish only; finite<=256 registered scenes, dimensions<=1000000, valid writable pointers, acyclic sorted links and available command capacity. DynamicMaterialQueue finite domain applies. Metadata/packet regions must not partially overlap; identical command targets and matrix aliases retained. Compiled execution pending.'}],'dependencies':['DynamicMaterialQueue.Flush','StaticFinalization.PatchMaterials','StaticFinalization.PatchAlpha','SceneSubmission.PatchClipControls','ShaderContextEmission.CompleteSorted','RenderPacketMemory'],'native':{'report':'geometry-finish-pipeline-native-validation.json','passed':native['passed'],'counts':native['counts'],'binarySHA256':native['binarySHA256'],'boundaries':native['boundaries']},'managed':managed,'harness':info('reconstructed/geometry/harness/SceneFinishPipelineHarness.cs'),'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.FinishPipeline.dll'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.dll /reference:Recovered.Geometry.StaticFinish.dll /reference:Recovered.Geometry.FrameReset.dll /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.ShaderEmission.dll /reference:Recovered.Geometry.DynamicPackets.dll /reference:Recovered.Geometry.DynamicQueue.dll /out:Recovered.Geometry.FinishPipeline.dll SceneFinishPipeline.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.FinishPipeline.dll /out:SceneFinishPipelineHarness.exe harness\\SceneFinishPipelineHarness.cs'},'adapters':['Raw original pointer records become typed StaticFinishScene views only while invoking existing patch helpers. Duplicate material command targets share compact item indices; repeated matrix pointers share float arrays. Only control bytes and the alpha lane are committed.','Passed memory root replaces original0x973dbc, root+0x118/root+0x178 are current/previous24-DWORD counters; root+0x1e8 is zero lock handle; root+0x110 is shared sort head.','Shader global template,allocator control,signed-byte descriptor,token base and material gate mode are supplied explicitly.','Diagnostic entry-address list is not a native return value.'], 'remainingGaps':[{'id':'dynamic-submission','address':'0x5f0f00','status':'Selection and transform handoff remains separate; the new fixture queues valid material additions explicitly.'},{'id':'nonzero-os-lock','status':'Original lock acquisition/release side effects are external; only original zero-handle branches validated.'},{'id':'live-game-frame','status':'Authored maps combined with controlled runtime state; not captured live frame state.'},{'id':'managed-execution','status':'Compiled only; saved-output comparison pending.'},{'id':'gpu-command-consumption','status':'CPU byte streams and state verified; GPU visual output unclaimed.'}]}
(R/'geometry-finish-pipeline-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-finish-pipeline-findings.txt').write_text('''Populated normal scene finish integration

Original0x5f0d70 now executes unchanged with all recovered CPU dependencies in
the same invocation: dynamic material queue, clip command controls, instance
alpha writes, material controls,24-DWORD statistics copy, sorted packet links,
changed shader emission, payload construction and context resets. Entry hooks
observe only. Original lock helpers execute their zero-handle branches.

60 authored scenes pass original-vs-Python whole-memory and call-order checks:
47,080,960 memory bytes,240 queued new material additions,40 clip/alpha dispatch
pairs,120 material patch dispatches,837 shader emission calls and5,022 command
appends. Source material flags/gates, material indexes,sort ranges,clip-item
maps and predecessor-matrix aliases are used directly. Packet links, visibility
bits,shader contexts and the single-owner registry are controlled fixtures.
They are not a captured live frame. Newly created dynamic sort groups select
the native null-owner completion branch.

SceneFinishPipeline.Run composes existing recovered C# helpers through explicit
memory adapters. It introduces no new native-entry credit:0x5f0d70 remains
mapped by StaticFinalization.Finish. Typed views preserve duplicate command
targets and matrix aliases; only actual control bytes and matrix alpha lanes
are copied back. The original statistics copy precedes sorted completion.
The root-relative zero lock field is checked rather than simulating OS locks.

Core and Main SceneFinishPipelineHarness compile with ordinary AnyCPU settings.
The2,771,827-byte gzip input fixture takes compressedInputFixture/outputFile.
geometry-finish-pipeline-check.py prepares it or compares already saved output;
it launches nothing. Compiled equivalence remains pending. Dynamic mesh
submission0x5f0f00, live frame integration and GPU results remain separate.
''')
print(json.dumps({'newNativeMappings':0,'composition':'SceneFinishPipeline.Run','cases':native['counts']['cases'],'managed':managed['status']}))
