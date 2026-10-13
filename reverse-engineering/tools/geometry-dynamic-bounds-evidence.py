"""Stable scalar dynamic bounds source/evidence handoff."""
import json,hashlib,importlib.util
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);assembly={}
for address,size in [(0x6042e0,0x648),(0x5b5430,0x2d0),(0x603f10,0x200)]:assembly[hex(address)]={'windowBytes':size,'instructions':[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in c.disasm(n.read(address,size),address)]}
(R/'geometry-dynamic-bounds-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
core='reconstructed/geometry/DynamicBounds.cs';native=json.loads((R/'geometry-dynamic-bounds-native-validation.json').read_text());managed=json.loads((R/'geometry-dynamic-bounds-managed-check.json').read_text())
rows=[('0x6042e0','Classify','bounded-scalar-branch','Scalar runtime297c0d0=0 and native fifth argument0. Enabled=false returns1 unchanged; otherwise finite bounds/matrix/scalars and finite stored transformed values. Explicit view/far/slope inputs and scratch arrays replace globals. SIMD604110 excluded.'),('0x5b5430','MultiplyAffine','bounded-whole-helper-projection','Finite affine arithmetic with finite stored results; returned new matrix replaces native destination buffer. Native exact input/output aliases verified; arbitrary partial overlaps excluded. Perspective column input ignored; output0/0/0/1.'),('0x603f10','TransformPoints','bounded-whole-helper-projection','Finite packed XYZ input, valid16-float matrix, count<=1000000; no input/output overlap. Native four-point/remainder loops reduced to same per-point arithmetic. Stored results finite.')]
report={'schema':'recovered-geometry-dynamic-bounds-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'DynamicBounds.'+m,'sourceFile':core,'coverage':coverage,'limitations':limits+' Native-vs-Python classification and every float word exact, including signed zero. Compiled C# comparison pending.','evidence':'geometry-dynamic-bounds-native-validation.json'}for a,m,coverage,limits in rows],'dependencies':['Recovered.Animation.PlaybackWide with local ordered IEEE zero-sign tracking'],'dependencySources':[info('reconstructed/animation/AnimationPlayback.cs'),info('reconstructed/animation/CharacterContexts.cs')],'native':{'report':'geometry-dynamic-bounds-native-validation.json','passed':native['passed'],'counts':native['counts'],'classes':native['classes'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'cameraPreparation':native['cameraPreparation'],'assembly':info('reports/geometry-dynamic-bounds-assembly.json')},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicBounds.dll'),'harness':info('reconstructed/geometry/harness/DynamicBoundsHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /out:Recovered.Geometry.DynamicBounds.dll DynamicBounds.cs ..\\animation\\CharacterContexts.cs ..\\animation\\AnimationPlayback.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.DynamicBounds.dll /out:DynamicBoundsHarness.exe harness\\DynamicBoundsHarness.cs'},'fields':{'0x80e85c':'Classification enabled;0 returns1 with scratch unchanged','0x297c0d0':'0 scalar branch; nonzero SIMD branch excluded','0x80b708':'Prepared view matrix','0x280c480':'Combined affine transform scratch','0x973730/0x973734/0x97374c':'Near/far/global far override','0x966378/0x97313c':'Horizontal/vertical slopes','0x80e8f0..0x80e8fc':'Four replicated selected far floats'},'observations':['Nonzero caller far wins; otherwise nonzero global override wins; otherwise camera far.','Null transform and original806680 sentinel both copy the view matrix unchanged. Other transforms use original affine multiply.','Eight corner masks in original order:0,7,4,3,2,6,1,5. Near/far bits32/16; left/right1/2; lower/upper8/4. All-corner bitwise AND rejects; zero OR accepts; otherwise partial.','Disabled branch does not mutate combined matrix/far scratch or dereference bound contents.','Initial168 signed-zero model differences were corrected by ordered IEEE zero tracking and omitting nonexistent translation additions in linear affine rows.192 targeted sign-pattern cases added;196477 words now compare exactly.'], 'remainingGaps':[{'id':'simd-box','address':'0x604110','status':'Not represented; scalar runtime branch explicitly selected.'},{'id':'unsupported-native-mode','status':'Nonzero fifth argument6042e0 calls literal ret helper then loops forever; excluded rather than simulated.'},{'id':'camera-runtime','status':'Two CU2 world matrices inverted with NumPy for fixtures; live camera-view production remains separate.'},{'id':'dynamic-caller','address':'0x5f0f00','status':'Transformed clipping dependency now recovered; LOD/material selection and full caller integration still separate.'},{'id':'signed-zero','status':'Resolved in native-vs-Python model: all196477 words exact after192 targeted sign cases; compiled C# comparison pending.'},{'id':'managed-execution','status':'Compile passed; no launch; saved-output comparison pending.'},{'id':'gpu-command-consumption','status':'CPU classification only; GPU results unclaimed.'}]}
(R/'geometry-dynamic-bounds-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-bounds-findings.txt').write_text('''Scalar dynamic transformed-box clipping

Original6042e0 generates eight local-box corners, transforms them by local*view,
forms near/far/left/right/lower/upper outcodes and returns0outside,1inside,2partial.
The global enable0 path returns1 before dereferencing bounds and leaves scratch
unchanged. Null transform or806680 sentinel copies the view. Caller far wins
when nonzero, then global override, then camera far. Chosen far is replicated
to four original scratch floats. Nonzero fifth argument is an unsupported
native infinite-loop path and is explicitly excluded.

The general path uses original5b5430 affine multiplication, not imported D3DX.
Original603f10 packs XYZ point transforms in a four-point loop plus remainder.
Both recovered methods use the shared finite64-significand x87 helper. Side
predicate products multiply two float32 values exactly in double, with no
prematurefloat32 store. The scalar runtime branch297c0d0=0 is selected; the
alternate SIMD604110 implementation remains separate.

4,404 original classifier cases across60 authored source scenes pass, plus96
affine destination/input alias cases and12 packed-point dimensions0..17.
196,477 float words compare exactly, including signed zero. An initial168
zero-sign differences were corrected by ordered IEEE zero propagation and
omitting a nonexistent translation addition in affine linear rows.192
targeted sign cases were added(128point,64affine); no differences remain.
Original bits and the correction are retained. Results:
3,232outside,1,116inside,56partial.480 authored special local min/max and matrix
records are evaluated with three prepared views and three far-mode pairs.
Two views are float32 NumPy inverses of authored CU2 camera world transforms;
this is fixture preparation, not proof of native camera-view production.

DynamicBounds.cs and Main DynamicBoundsHarness compile with shared animation
PlaybackWide dependencies. The compact gzip fixture takes
compressedInputFixture/outputFile. geometry-dynamic-bounds-check.py only
prepares or compares saved output, requiring every classification and float
word to match, including signed zero. Managed execution
remains pending. No game, managed harness or GPU was launched.
''')
print(json.dumps({'mappings':len(rows),'cases':managed['caseCount'],'signedZeroDifferences':native['counts']['signedZeroDifferences'],'managed':managed['status']}))
