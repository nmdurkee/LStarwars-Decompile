// Prepared character layer/matrix replay. No generated binary is launched here.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class CharacterLayerSubmissionVerify
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
    sealed class Rig
    {
        public CharacterRenderModel Model;public float[][] Joints;public readonly Dictionary<uint,uint> Returns=new Dictionary<uint,uint>();
        CharacterRenderHandle Handle(object item){if(item==null)return null;var row=M(item);uint id=U(row["identity"]);Returns[id]=U(row["return"]);return new CharacterRenderHandle{Identity=id,Scene=U(row["scene"]),DisplaySpecial=U(row["display"])};}
        CharacterRenderHandle[] Handles(object item){return item==null?null:Array.ConvertAll(A(item),Handle);}
        public Rig(Dictionary<string,object> row)
        {
            Joints=Rows(row["joints"]);Model=new CharacterRenderModel{InverseBind=Rows(row["inverse"]),BoundsMinimum=Floats(row["minimum"]),BoundsMaximum=Floats(row["maximum"])};var layers=A(row["layers"]);Model.Layers=new CharacterRenderLayer[layers.Length];
            for(int i=0;i<layers.Length;++i){var l=M(layers[i]);Model.Layers[i]=new CharacterRenderLayer{Rigid=Handles(l["rigid"]),AlternateRigid=Handles(l["alternateRigid"]),Smooth=Handle(l["smooth"]),AlternateSmooth=Handle(l["alternateSmooth"])};}
        }
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<layer-submission-native-fixtures.json.gz> <result.json>");Dictionary<string,object> fixture;
        using(var file=File.OpenRead(args[0]))using(var zip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(zip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));var rigs=Array.ConvertAll(A(fixture["rigs"]),r=>new Rig(M(r)));uint arena=U(fixture["arena"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var c=M(item);Rig rig=rigs[I(c["rig"])];string kind=(string)c["kind"];object actual,expected=c["native"];
            if(kind=="skinWrapper")actual=Hash(Pack(CharacterLayerSubmission.PrepareSkin(rig.Model.InverseBind,rig.Joints,rig.Joints.Length)));
            else if(kind=="rigidWrapper")actual=Hash(Pack(new[]{CharacterLayerSubmission.Concatenate(rig.Joints[0],Floats(c["world"]))}));
            else
            {
                var input=M(c["state"]);var state=new CharacterSubmissionState{ArenaCursor=U(input["cursor"]),CachedVisibility=I(input["cached"]),SecondaryVisibilityCount=I(input["secondaryCount"]),SubmissionFlag=0xa5a5a5a5};var events=new List<object>();var services=new CharacterSubmissionServices();
                services.ResolveVisibility=delegate(CharacterRenderModel m,float[] world,float[][] joints){events.Add(new{kind="visibility"});return I(input["resolved"]);};
                services.SecondaryVisibility=delegate(float[] low,float[] high,int mode){events.Add(new{kind="secondary",low=Bits(low),high=Bits(high),mode});return I(input["secondaryResult"]);};
                services.SubmitAttachments=delegate(CharacterRenderModel m,float[] world,float[][] joints){events.Add(new{kind="attachments",visible=state.CachedVisibility});};
                services.Submit=delegate(CharacterRenderHandle h,float[] matrix,int mode,CharacterSkinPalette palette,uint morph)
                {
                    events.Add(new{kind="submit",handle=h.Identity,mode,transformSha256=Hash(Pack(new[]{matrix})),skinAddress=palette==null?0:palette.Address,skinSha256=palette==null?null:Hash(Pack(palette.Matrices)),morph,visible=state.CachedVisibility});
                    if(Convert.ToBoolean(input["allocation"]))state.ArenaCursor+=(h.Identity%3)*16;return rig.Returns[h.Identity];
                };
                short[] map=input["map"]==null?null:Array.ConvertAll(A(input["map"]),v=>Convert.ToInt16(v));uint[] morphs=input["morph"]==null?null:Array.ConvertAll(A(input["morph"]),U);
                uint result=CharacterLayerSubmission.Submit(rig.Model,Floats(input["world"]),rig.Joints,I(input["count"]),map,morphs,state,services);int size=checked((int)(state.ArenaCursor-arena));if(size>I(fixture["arenaSize"]))throw new ArgumentException("Fixture arena exceeded");var bytes=new byte[size];for(int i=0;i<size;++i)bytes[i]=0xa5;foreach(var palette in state.Palettes){byte[] data=Pack(palette.Matrices);Array.Copy(data,0,bytes,(int)(palette.Address-arena),data.Length);}
                actual=new{result,cached=state.CachedVisibility,flag=state.SubmissionFlag,cursor=state.ArenaCursor,arenaSha256=Hash(bytes),events};actual=Json.DeserializeObject(Json.Serialize(actual));var projected=new Dictionary<string,object>(M(expected));projected.Remove("calls");expected=projected;
                // Native-vs-model suite additionally observes each helper entry;
                // this replay verifies ordered external events and payloads.
            }
            ++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind,actual,expected});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
