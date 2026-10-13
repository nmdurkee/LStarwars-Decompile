"""Build a standalone replay harness, reusing the stable refresh fixture setup."""
from pathlib import Path
p=Path(__file__).parent
source=(p/'gameplay-path-refresh-portable-verify.cs').read_text()
source=source[:source.index('    public static int Main(')].replace('public class GameplayPathRefreshVerify','public class GameplayPathAliasVerify')
needle='        byte[][] beforeNodes='
insert='''        if(kind=="aliasRefresh")
        {
            Dictionary<string,object> aliasOptions=new Dictionary<string,object>{{"groups",o["aliasGroups"]},{"normalFlags",new object[]{0,0,0,0}},{"displayFlags",new object[]{2,2,2,2}}};
            PathAliasWorld aliases=Aliases(aliasOptions,Normal,Display);aliases.Normals[Normal]=normal;aliases.Displays[Display]=display;PathReferenceAliases.Attach(world,delegate{return aliases;});
        }
'''
assert needle in source
source=source.replace(needle,insert+needle)
source+='''    static PathAliasReference Reference(object value,uint normalBase,uint displayBase)
    {if(value==null)return null;object[] a=Arr(value);return new PathAliasReference(U(a[0]),I(a[1])==0?0:normalBase+(U(a[1])-1)*0x100,I(a[2])==0?0:displayBase+(U(a[2])-1)*0x100);}
    static object Logical(PathAliasReference r,uint normalBase,uint displayBase)
    {return r==null?null:new object[]{r.Scene,r.Normal==0?0:(r.Normal-normalBase)/0x100+1,r.Display==0?0:(r.Display-displayBase)/0x100+1};}
    static PathAliasWorld Aliases(Dictionary<string,object> o,uint normalBase,uint displayBase)
    {
        object[] groups=o.ContainsKey("groups")?Arr(o["groups"]):new object[0];PathAliasWorld w=new PathAliasWorld{Count=Opt(o,"count",groups.Length),Groups=Flag(o,"noGroups")?null:new PathAliasGroup[groups.Length]};
        for(int i=0;i<4;i++){w.Normals.Add(normalBase+(uint)(i*0x100),new PathSceneNormal{Flags44=o.ContainsKey("normalFlags")?U(Arr(o["normalFlags"])[i]):(uint)(i%2)});w.Displays.Add(displayBase+(uint)(i*0x100),new PathSceneDisplay{FlagsB8=o.ContainsKey("displayFlags")?U(Arr(o["displayFlags"])[i]):(uint)(i%2*2)});}
        if(w.Groups!=null)for(int i=0;i<groups.Length;i++){Dictionary<string,object> g=Obj(groups[i]);object[] rr=Arr(g["refs"]);PathAliasGroup group=new PathAliasGroup{Count=(short)Opt(g,"count",rr.Length),References=new PathAliasReference[rr.Length]};for(int j=0;j<rr.Length;j++)group.References[j]=Reference(rr[j],normalBase,displayBase);w.Groups[i]=group;}return w;
    }
    static object Direct(Dictionary<string,object> o,string kind)
    {
        const uint normalBase=0x10110000,displayBase=0x10120000;PathAliasReference r=Reference(o["ref"],normalBase,displayBase);
        if(kind=="valid")return PathReferenceAliases.Valid(r)?1:0;
        if(kind=="same")return PathReferenceAliases.Same(r,Reference(o["other"],normalBase,displayBase))?1:0;
        PathAliasWorld world=Aliases(o,normalBase,displayBase);bool result=kind=="callback"?PathReferenceAliases.GameResolve(delegate{return world;},r):PathReferenceAliases.Resolve(world,r);return new Dictionary<string,object>{{"result",result?1:0},{"ref",Logical(r,normalBase,displayBase)}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=4)throw new ArgumentException("fixture JSON, angle table u16, sine table f32, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));byte[] raw=File.ReadAllBytes(args[1]);ushort[] table=new ushort[513];for(int i=0;i<table.Length;i++)table[i]=BitConverter.ToUInt16(raw,2*i);byte[] sr=File.ReadAllBytes(args[2]);float[] sine=new float[32768];for(int i=0;i<sine.Length;i++)sine[i]=BitConverter.ToSingle(sr,i*4);int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();
        foreach(object item in Arr(root["cases"]))try
        {
            Dictionary<string,object> c=Obj(item),o=Obj(c["options"]);string kind=(string)c["kind"];object got;
            if(kind=="refreshChain"){Dictionary<string,object> input=new Dictionary<string,object>(o);input["visible"]=0;input["displayFlags"]=2;got=Run(input,"aliasRefresh",table,sine);}else got=Direct(o,kind);
            checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;
        }
        catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}
        string result=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[3],result);Console.WriteLine(result);return mismatches==0?0:1;
    }
}
'''
# The original callback trace is part of the composed fixture output.
source=source.replace('PathReferenceAliases.Attach(world,delegate{return aliases;});','PathReferenceAliases.Attach(world,delegate{events.Add(new object[]{"resolve",world.Path.ContextIdentity,index});return aliases;});')
(p/'gameplay-path-alias-portable-verify.cs').write_text(source,encoding='utf8')
