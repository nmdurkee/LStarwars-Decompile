"""Compose all four native-proven5e0530 branches; no duplicate native case claim."""
from pathlib import Path
import json,gzip,hashlib,subprocess,os
B=Path(__file__).resolve().parent.parent;R=B/'reports';source='reconstructed/animation/SkinMeshPacketDispatch.cs';harness='tools/animation-full-dispatch-portable-verify.cs'
def hashed(p):return dict(path=p,sha256=hashlib.sha256((B/p).read_bytes()).hexdigest())
meshTests=json.loads((R/'animation-skin-dispatch-tests.json').read_text());billboardTests=json.loads((R/'animation-billboard-tests.json').read_text());assert meshTests['mismatches']==billboardTests['mismatches']==0
components=[dict(kind='mesh',path=meshTests['fixture']['path'],sha256=meshTests['fixture']['sha256'],nativeCases=meshTests['comparisons'],evidence='reports/animation-skin-dispatch-tests.json'),dict(kind='billboard',path=billboardTests['fixture']['path'],sha256=billboardTests['fixture']['sha256'],nativeCases=billboardTests['counts']['dispatch'],evidence='reports/animation-billboard-tests.json')]
for c in components:assert hashed(c['path'])['sha256']==c['sha256']
manifest='reports/animation-full-dispatch-fixtures.json';(B/manifest).write_text(json.dumps(dict(components=components),indent=2)+'\n')
# Generate isolated replayers from the existing reviewed fixture readers; only
# the invocation changes. They return JSON to the top-level harness in memory.
mesh=(B/'tools/animation-skin-dispatch-portable-verify.cs').read_text().replace('SkinMeshPacketDispatchVerify','FullDispatchMeshReplay')
mesh=mesh.replace('public static int Main(string[] args)','public static string Replay(string path)')
mesh=mesh.replace('if(args.Length!=2)throw new ArgumentException("<skin-dispatch-native-fixtures.json.gz> <result.json>");','').replace('args[0]','path')
old='SkinMeshPacketDispatch.Build(memory,P("control"),P("record"),P("material"),I(c["commandIndex"]),P("command"),P("matrix"),P("cache"),P("output"),resource,weights,Convert.ToBoolean(c["skin"])?jointMatrices:null,U(c["alpha"]),I(c["metadata"]),P("scale"),P("translation"),uv)'
new=old.replace('.Build(','.BuildWithBillboards(')[:-1]+',null,null)';assert old in mesh;mesh=mesh.replace(old,new)
end='File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;';assert end in mesh;mesh=mesh.replace(end,'return Json.Serialize(new{checks,failures,errors});')
bill=(B/'tools/animation-billboard-portable-verify.cs').read_text().replace('BillboardMeshPacketsVerify','FullDispatchBillboardReplay').replace('public static int Main(string[] args)','public static string Replay(string path)')
bill=bill.replace('if(args.Length!=2)throw new ArgumentException("<billboard-native-fixtures.json.gz> <result.json>");','').replace('args[0]','path')
needle='var c=M(item);int seed=';assert needle in bill;bill=bill.replace(needle,'var c=M(item);if((string)c["kind"]!="dispatch")continue;int seed=')
old='else BillboardMeshPackets.Build(memory,d,record,command,world,output,U(c["alpha"]),Floats(c["view"]),Floats(c["forward"]));';assert old in bill
bill=bill.replace(old,'else { uint writer=SkinMeshPacketDispatch.BuildWithBillboards(memory,d,record,owner,2,command,world,0xdead0001,output,null,null,new byte[0][],U(c["alpha"]),Int32.MinValue,0,0,null,Floats(c["view"]),Floats(c["forward"])); if(writer!=0x5e0490)throw new InvalidOperationException("Billboard dispatch lost precedence"); }')
end='File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;';assert end in bill;bill=bill.replace(end,'return json.Serialize(new{checks,failures,errors});')
# Strip repeated using directives so all classes share one compilation unit.
imports=[]
def strip(s):
 out=[]
 for l in s.splitlines():
  if l.startswith('using '):
   if l not in imports:imports.append(l)
  else:out.append(l)
 return '\n'.join(out)
mesh=strip(mesh);bill=strip(bill)
main='''
public static class FullSkinMeshPacketDispatchVerify
{
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<full-dispatch-fixtures.json> <result.json>");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var manifest=(Dictionary<string,object>)json.DeserializeObject(File.ReadAllText(args[0]));string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));int checks=0,failures=0;var components=new List<object>();
        foreach(object item in(object[])manifest["components"])
        {
            var c=(Dictionary<string,object>)item;string path=Path.Combine(root,(string)c["path"]),digest;using(var h=SHA256.Create())digest=BitConverter.ToString(h.ComputeHash(File.ReadAllBytes(path))).Replace("-","").ToLowerInvariant();if(digest!=(string)c["sha256"])throw new ArgumentException("Native fixture hash changed");
            string result=(string)c["kind"]=="mesh"?FullDispatchMeshReplay.Replay(path):FullDispatchBillboardReplay.Replay(path);var parsed=(Dictionary<string,object>)json.DeserializeObject(result);int count=Convert.ToInt32(parsed["checks"]);if(count!=Convert.ToInt32(c["nativeCases"]))throw new InvalidOperationException("Replay count differs from selected native cases");checks+=count;failures+=Convert.ToInt32(parsed["failures"]);components.Add(new{kind=c["kind"],result=parsed});
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,components}));return failures==0?0:1;
    }
}
'''
(B/harness).write_text('// Generated by animation-full-dispatch-report.py from hash-bound fixture readers.\n'+'\n'.join(imports)+'\n'+mesh+'\n'+bill+'\n'+main)
deps=['reconstructed/animation/CharacterContexts.cs','reconstructed/animation/AnimationPlayback.cs','reconstructed/animation/MorphMeshDeformation.cs','reconstructed/animation/MorphMeshPackets.cs','reconstructed/animation/BillboardMeshPackets.cs','reconstructed/geometry/SortedPackets.cs','reconstructed/geometry/FrameReset.cs','reconstructed/geometry/DynamicCommandSupport.cs','reconstructed/geometry/OrdinaryMeshPackets.cs'];core=deps+[source];compiler=Path(os.environ.get('WINDIR',r'C:\Windows'))/'Microsoft.NET/Framework64/v4.0.30319/csc.exe';build=B/'reconstructed/animation/full-dispatch-build';build.mkdir(exist_ok=True);results=[]
for name,target,files,extra in [('Recovered.FullSkinMeshPacketDispatch.dll','library',core,[]),('FullSkinMeshPacketDispatchVerify.exe','exe',core+[harness],['/main:FullSkinMeshPacketDispatchVerify','/reference:System.Web.Extensions.dll'])]:
 command=[str(compiler),'/nologo','/optimize+','/platform:anycpu','/target:'+target,'/out:'+str(build/name)]+extra+[str(B/p)for p in files];run=subprocess.run(command,capture_output=True,text=True);r=dict(command=command,exitCode=run.returncode,stdout=run.stdout,stderr=run.stderr)
 if run.returncode==0:r['artifact']=hashed((build/name).relative_to(B).as_posix())
 results.append(r)
(R/'animation-full-dispatch-compile.json').write_text(json.dumps(dict(compile=results,sourceHashes=[hashed(p)for p in core+[harness]],execution='Compiled only. No managed executable launched.'),indent=2)+'\n')
count=sum(c['nativeCases']for c in components);portable=dict(source=hashed(source),coreDependencies=deps,harness=hashed(harness),entrypoint='FullSkinMeshPacketDispatchVerify.Main',arguments=[manifest,'<result.json>'],preparedComparisons=count,status='Compiled only; no managed execution.',compileEvidence='reports/animation-full-dispatch-compile.json');lines=(B/source).read_text().splitlines()
mapping=dict(address='0x5e0530',sourceFile='reverse-engineering/'+source,sourceSha256=hashed(source)['sha256'],methods=[dict(name='SkinMeshPacketDispatch.BuildWithBillboards',line=next(i+1 for i,l in enumerate(lines)if 'public static uint BuildWithBillboards('in l))],coverage='complete four-branch selector and bounded CPU writer composition',qualification='Adds BillboardMeshPackets ahead of the existing non-billboard Build API, preserving original opcode8f precedence and ignoring unused skin/morph/cache inputs on that branch. Existing geometry selector projection and non-billboard implementation retained. Scalar finite valid-memory payload domains, successful COM buffer services; no full caller,shader execution or GPU claim.',comparisonStatus='All branch native evidence passed; unified managed replay compiled only.',nativeEvidence='reverse-engineering/reports/animation-full-dispatch-contract.json')
(R/'animation-full-dispatch-source-map.json').write_text(json.dumps(dict(binarySha256=meshTests['binarySha256'],primaryNativeEntryPoints=1,newNativeEntryPoints=0,refines=['0x5e0530'],mappings=[mapping],portable=portable,nativeEvidence=['reverse-engineering/reports/animation-skin-dispatch-tests.json','reverse-engineering/reports/animation-billboard-tests.json']),indent=2)+'\n')
contract=dict(binarySha256=meshTests['binarySha256'],portable=portable,nativeEvidenceReused=components,uniqueReusedNativeCases=count,additionalNativeComparisons=0,mismatches=0,scope='Unified host composition of all four actual original5e0530 branches; evidence is reused explicitly, not counted as new original execution.',behavior=['Opcode8f invokes recovered BillboardMeshPackets before touching skin,weights,cache or material flags.','All other opcodes delegate to the unchanged Build API, preserving skin-pointer selection and ordinary/prefix behavior.','New full replay invokes BuildWithBillboards for every case; a nonnull empty skin adapter and invalid cache sentinel on billboard cases establish the intended public branch precedence.','Existing Build remains a backward-compatible non-billboard API.'],limits=['Finite scalar CPU payloads and valid storage; original branch-specific exclusions retain force.','All5,135 source-replay cases reuse native observations from the earlier suites. No duplicate native-case increment is claimed.','Managed harness compiled only; no generated executable launched.'],readerSources=[hashed('tools/animation-skin-dispatch-portable-verify.cs'),hashed('tools/animation-billboard-portable-verify.cs')])
(R/'animation-full-dispatch-contract.json').write_text(json.dumps(contract,indent=2)+'\n');print(json.dumps(dict(reusedNativeCases=count,additionalNativeComparisons=0,compileExitCodes=[r['exitCode']for r in results],source=hashed(source),harness=hashed(harness),errors=[r['stdout']for r in results if r['exitCode']]),indent=2));assert all(r['exitCode']==0 for r in results)
