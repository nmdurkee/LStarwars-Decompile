using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Geometry;
public static class CharacterSecondaryPipelineVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}static float F(object v){return PcObjectImage.FromBits(U(v));}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}static float[][] Rows(object v){return Array.ConvertAll(A(v),Floats);}
    static string Hash(byte[] v){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(v)).Replace("-","").ToLowerInvariant();}
    static byte[] Pack(float[][] rows){var b=new byte[rows.Length*64];for(int i=0;i<rows.Length;++i)Buffer.BlockCopy(rows[i],0,b,i*64,64);return b;}
    static uint[] Bits(float[] v){return Array.ConvertAll(v,PcObjectImage.ToBits);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;var ma=a as IDictionary;var mb=b as IDictionary;if(ma!=null&&mb!=null){if(ma.Count!=mb.Count)return false;foreach(object k in ma.Keys)if(!mb.Contains(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as IList;var ab=b as IList;if(aa!=null&&ab!=null){if(aa.Count!=ab.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static CharacterShadowBinding Binding(object v)
    {var a=A(v);return new CharacterShadowBinding{EllipsePointer=U(a[0]),CylinderPointer=U(a[1]),OtherPointer=U(a[2]),EllipseCount=Convert.ToByte(a[3]),CylinderCount=Convert.ToByte(a[4]),OtherCount=Convert.ToByte(a[5]),JointIndex=Convert.ToByte(a[6])};}
    sealed class Rig
    {
        public CharacterRenderModel Model;public float[][] Joints;public CharacterShadowBinding[] Bindings;public readonly Dictionary<uint,uint> Returns=new Dictionary<uint,uint>();
        CharacterRenderHandle Handle(object item){if(item==null)return null;var row=M(item);uint id=U(row["identity"]);Returns[id]=U(row["return"]);return new CharacterRenderHandle{Identity=id,Scene=U(row["scene"]),DisplaySpecial=U(row["display"])};}
        CharacterRenderHandle[] Handles(object item){return item==null?null:Array.ConvertAll(A(item),Handle);}
        public Rig(Dictionary<string,object> row)
        {
            Joints=Rows(row["joints"]);Bindings=row["bindings"]==null?null:Array.ConvertAll(A(row["bindings"]),Binding);Model=new CharacterRenderModel{InverseBind=Rows(row["inverse"]),BoundsMinimum=Floats(row["minimum"]),BoundsMaximum=Floats(row["maximum"])};var layers=A(row["layers"]);Model.Layers=new CharacterRenderLayer[layers.Length];
            for(int i=0;i<layers.Length;++i){var l=M(layers[i]);Model.Layers[i]=new CharacterRenderLayer{Rigid=Handles(l["rigid"]),AlternateRigid=Handles(l["alternateRigid"]),Smooth=Handle(l["smooth"]),AlternateSmooth=Handle(l["alternateSmooth"])};}
        }
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<character-secondary-native-fixtures.json.gz> <result.json>");Dictionary<string,object> fixture;
        using(var file=File.OpenRead(args[0]))using(var zip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(zip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));var rigs=Array.ConvertAll(A(fixture["rigs"]),r=>new Rig(M(r)));uint arena=U(fixture["arena"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var c=M(item);Rig rig=rigs[I(c["rig"])];var input=M(c["state"]);var state=new CharacterSubmissionState{ArenaCursor=U(input["cursor"]),CachedVisibility=I(input["cached"]),SecondaryVisibilityCount=I(input["secondaryCount"]),SubmissionFlag=0xa5a5a5a5};var events=new List<object>();var p=A(input["camera"]);var camera=new DynamicBoxState{Near=F(p[0]),Far=F(p[1]),FarOverride=F(p[2]),HorizontalSlope=F(p[3]),VerticalSlope=F(p[4]),Enabled=I(p[5])!=0,View=Floats(input["view"]),CombinedMatrix=Floats(fixture["beforeMatrix"]),FarLanes=Floats(fixture["beforeFar"])};
            var sc=M(input["shadow"]);var parameters=A(sc["parameters"]);var distances=A(sc["distances"]);var shadows=new CharacterShadowQueueState{Count=I(sc["count"]),Sequence=U(sc["sequence"]),SubmissionFlag=U(sc["flag"]),Enabled=Convert.ToByte(sc["enabled"]),Mode=I(sc["mode"]),SubmissionEnabled=U(sc["submissionEnabled"]),Parameter0=U(parameters[0]),Parameter1=U(parameters[1]),Parameter2=U(parameters[2]),PackedParameter=U(parameters[3]),FadeDistance=F(distances[0]),MaximumDistance=F(distances[1])};for(int i=0;i<shadows.Records.Length;++i)shadows.Records[i]=0xa5;
            var environment=new CharacterPipelineEnvironment{Camera=camera,CenterBoundsOnRoot=Convert.ToBoolean(input["center"]),Shadows=shadows,ShadowBindings=rig.Bindings,SuppressShadow=Convert.ToByte(sc["suppress"])};
            var secondaryInput=M(input["secondary"]);var secondary=new SecondaryVisibilityState{Masks=Array.ConvertAll(A(secondaryInput["initial"]),U),Contexts=Array.ConvertAll(A(secondaryInput["contexts"]),context=>new SecondaryVisibilityContext{Volumes=Array.ConvertAll(A(context),volume=>new SecondaryVisibilityVolume{Planes=Array.ConvertAll(A(volume),Floats)})})};
            environment.Submit=delegate(CharacterRenderHandle h,float[] matrix,int mode,CharacterSkinPalette palette,uint morph)
            {
                events.Add(new{kind="submit",handle=h.Identity,mode,transformSha256=Hash(Pack(new[]{matrix})),skinAddress=palette==null?0:palette.Address,skinSha256=palette==null?null:Hash(Pack(palette.Matrices)),morph,visible=state.CachedVisibility,shadowCount=shadows.Count,shadowSequence=shadows.Sequence,shadowFlag=shadows.SubmissionFlag,secondaryFlag=state.SubmissionFlag});
                if(Convert.ToBoolean(input["allocation"]))state.ArenaCursor+=(h.Identity%3)*16;
                if(Convert.ToBoolean(input["mutateShadowSequence"]))shadows.Sequence=unchecked(shadows.Sequence+h.Identity%5);state.SubmissionFlag=new uint[]{0,0xffffffff,1}[h.Identity%3];return rig.Returns[h.Identity];
            };
            short[] map=input["map"]==null?null:Array.ConvertAll(A(input["map"]),v=>Convert.ToInt16(v));uint[] morphs=input["morph"]==null?null:Array.ConvertAll(A(input["morph"]),U);
            uint result=CharacterSecondaryPipeline.Submit(rig.Model,Floats(input["world"]),rig.Joints,I(input["count"]),map,morphs,state,environment,secondary);int size=checked((int)(state.ArenaCursor-arena));if(size>I(fixture["arenaSize"]))throw new ArgumentException("Fixture arena exceeded");var bytes=new byte[size];for(int i=0;i<size;++i)bytes[i]=0xa5;foreach(var palette in state.Palettes){byte[] data=Pack(palette.Matrices);Array.Copy(data,0,bytes,(int)(palette.Address-arena),data.Length);}
            object actual=new{result,cached=state.CachedVisibility,flag=state.SubmissionFlag,cursor=state.ArenaCursor,arenaSha256=Hash(bytes),events,masks=secondary.Masks,combined=Bits(camera.CombinedMatrix),far=Bits(camera.FarLanes),shadow=new{count=shadows.Count,sequence=shadows.Sequence,flag=shadows.SubmissionFlag,queueSha256=Hash(shadows.Records)}};actual=Json.DeserializeObject(Json.Serialize(actual));var expected=new Dictionary<string,object>(M(c["native"]));var projectedEvents=new List<object>();foreach(object e in A(expected["events"]))if((string)M(e)["kind"]=="submit")projectedEvents.Add(e);expected["events"]=projectedEvents;expected.Remove("secondaryCalls");
            // Visibility, secondary masks and shadow production are internal.
            // Keep the explicit dynamic draw callbacks in the replay projection.
            ++checks;if(!Same(actual,expected)||secondary.CacheFlag!=state.SubmissionFlag){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,actual,expected});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
