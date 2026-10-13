// Prepared original packet-dispatch replay; compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class SkeletalPacketDispatchVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}
    static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static byte[] Unhex(string v){byte[] b=new byte[v.Length/2];for(int i=0;i<b.Length;++i)b[i]=Byte.Parse(v.Substring(i*2,2),NumberStyles.HexNumber,CultureInfo.InvariantCulture);return b;}
    static string Hex(byte[] v){return BitConverter.ToString(v).Replace("-","").ToLowerInvariant();}
    static string Digest(float[][] rows)
    {using(var stream=new MemoryStream()){foreach(var row in rows)foreach(float v in row){byte[] bytes=BitConverter.GetBytes(PcObjectImage.ToBits(v));stream.Write(bytes,0,4);}using(var hash=SHA256.Create())return Hex(hash.ComputeHash(stream.ToArray()));}}
    static bool Same(object a,object b)
    {
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    static object Request(SkeletalPoseRequest request)
    {
        if(request.Kind==SkeletalRequestKind.BindPose)return new{kind="bind"};
        if(request.Kind==SkeletalRequestKind.Single)return new{kind="single",clip=request.SourceClip,frame=PcObjectImage.ToBits(request.SourceFrame)};
        return new{kind="blend",source=request.SourceClip,target=request.TargetClip,sourceFrame=PcObjectImage.ToBits(request.SourceFrame),targetFrame=PcObjectImage.ToBits(request.TargetFrame),weight=PcObjectImage.ToBits(request.TargetWeight)};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("<packet-pose-fixtures.json.gz> <native-sine-table.f32> <result.json>");
        Dictionary<string,object> fixture;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        byte[] sine=File.ReadAllBytes(args[1]);if(sine.Length!=131072)throw new ArgumentException("Invalid sine table");float[] table=new float[32768];for(int i=0;i<table.Length;++i)table[i]=BitConverter.ToSingle(sine,i*4);
        object[] clipRows=A(fixture["clips"]);var clips=new SkeletalClip[clipRows.Length];for(int i=0;i<clips.Length;++i)clips[i]=new SkeletalClip(Convert.FromBase64String((string)M(clipRows[i])["raw"]));
        object[] rigRows=A(fixture["rigs"]);var rigs=new SkeletalJoint[rigRows.Length][];
        for(int i=0;i<rigs.Length;++i){object[] rows=A(M(rigRows[i])["joints"]);rigs[i]=new SkeletalJoint[rows.Length];for(int j=0;j<rows.Length;++j){var row=M(rows[j]);rigs[i][j]=new SkeletalJoint{Parent=(byte)I(row["parent"]),AnimationBindMatrix=Floats(row["bind"])};}}
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);string kind=(string)row["kind"];object actual;var expected=new Dictionary<string,object>(M(row["native"]));bool present=Convert.ToBoolean(row["present"]);
            if(kind=="layers")
            {
                actual=new{ids=SkeletalPacketDispatch.SelectLayers(present?new SkeletalPacketModel{LayerCount=I(row["count"])}:null,U(row["mask"]))};expected.Remove("untouchedTail");
            }
            else if(kind=="dispatch")
            {
                string raw=(string)row["packet"];var packet=new AnimationPacket(Unhex(raw));object[] slotRows=A(row["slots"]);var slots=new SkeletalClip[slotRows.Length];for(int i=0;i<slots.Length;++i)slots[i]=slotRows[i]==null?null:clips[I(slotRows[i])];
                object[] localRows=A(row["local"]);var local=new float[localRows.Length][];for(int i=0;i<local.Length;++i)local[i]=Floats(localRows[i]);
                var joints=rigs[I(row["rig"])];var model=present?new SkeletalPacketModel{Joints=joints,LocalBindMatrices=local,Clips=slots,LayerCount=I(row["layerCount"])}:null;
                var result=SkeletalPacketDispatch.Evaluate(packet,model,U(row["mask"]),table,SkeletalPose.D3dx9_35ScalarMultiply);float[][] matrices;var requests=new List<object>();
                if(result==null){matrices=new float[joints.Length][];for(int i=0;i<matrices.Length;++i){matrices[i]=new float[16];for(int j=0;j<16;++j)matrices[i][j]=PcObjectImage.FromBits(0xa5a5a5a5);}}
                else{matrices=result.WorldMatrices;requests.Add(Request(SkeletalPacketDispatch.Select(packet,slots)));}
                actual=new{matricesSha256=Digest(matrices),requests,packetPreserved=Hex(packet.Bytes)==raw};expected.Remove("arenaRestored");
            }
            else throw new ArgumentException(kind);
            actual=Json.DeserializeObject(Json.Serialize(actual));++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{kind,caseIndex=checks-1,actual,expected});}
        }
        File.WriteAllText(args[2],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
