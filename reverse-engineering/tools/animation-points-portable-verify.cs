// Prepared exact PC point/packet-output replay. Compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class SkeletalPointsVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}
    static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static float[][] Rows(object v){return Array.ConvertAll(A(v),Floats);}
    static byte[] Unhex(string v){byte[] b=new byte[v.Length/2];for(int i=0;i<b.Length;++i)b[i]=Byte.Parse(v.Substring(i*2,2),NumberStyles.HexNumber,CultureInfo.InvariantCulture);return b;}
    static string Hex(byte[] v){return BitConverter.ToString(v).Replace("-","").ToLowerInvariant();}
    static string Digest(float[][] rows)
    {using(var stream=new MemoryStream()){foreach(var row in rows)foreach(float v in row){byte[] bytes=BitConverter.GetBytes(PcObjectImage.ToBits(v));stream.Write(bytes,0,4);}using(var hash=SHA256.Create())return Hex(hash.ComputeHash(stream.ToArray()));}}
    static float[][] Sentinel(int n,int width){var rows=new float[n][];for(int i=0;i<n;++i){rows[i]=new float[width];for(int j=0;j<width;++j)rows[i][j]=PcObjectImage.FromBits(0xa5a5a5a5);}return rows;}
    static bool Same(object a,object b)
    {
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    static SkeletalPointBindings Bindings(Dictionary<string,object> model)
    {
        var raw=M(model["bindings"]);var points=A(raw["points"]);var b=new SkeletalPointBindings{Points=new SkeletalPoint[points.Length],Lookup=Array.ConvertAll(A(raw["lookup"]),v=>(byte)I(v)),EnabledSlots=Array.ConvertAll(A(raw["enabled"]),U)};
        for(int i=0;i<points.Length;++i){var row=M(points[i]);b.Points[i]=new SkeletalPoint{LocalMatrix=Floats(row["matrix"]),JointIndex=(byte)I(row["joint"])};}return b;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("<points-native-fixtures.json.gz> <native-sine-table.f32> <result.json>");
        Dictionary<string,object> fixture;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        byte[] sine=File.ReadAllBytes(args[1]);if(sine.Length!=131072)throw new ArgumentException("Invalid sine table");float[] table=new float[32768];for(int i=0;i<table.Length;++i)table[i]=BitConverter.ToSingle(sine,i*4);
        object[] clipRows=A(fixture["clips"]);var clips=new SkeletalClip[clipRows.Length];for(int i=0;i<clips.Length;++i)clips[i]=new SkeletalClip(Convert.FromBase64String((string)M(clipRows[i])["raw"]));object[] models=A(fixture["models"]);
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);string kind=(string)row["kind"];var input=M(row["input"]);var model=M(models[I(input["model"])]);var bindings=Bindings(model);float[] world=Floats(model["world"]);float[][] jointWorld=Rows(model["jointWorld"]);object actual,expected=row["native"];
            if(kind=="point")
            {
                bindings.Lookup=new byte[]{(byte)I(input["point"])};
                if(Convert.ToBoolean(input["joint255Supplied"]))
                {var extended=new float[256][];Array.Copy(jointWorld,extended,jointWorld.Length);for(int i=jointWorld.Length;i<256;++i)extended[i]=new float[]{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};extended[255]=Floats(model["slot255"]);jointWorld=extended;}
                actual=Array.ConvertAll(SkeletalPoints.EvaluatePoint(bindings,0,world,jointWorld,SkeletalPose.D3dx9_35ScalarMultiply),PcObjectImage.ToBits);
            }
            else
            {
                bool wantPosition=Convert.ToBoolean(input["position"]),wantMatrix=Convert.ToBoolean(input["matrix"]);var positions=Sentinel(16,3);var matrices=Sentinel(16,16);
                if(kind=="outputs")
                {SkeletalPoints.WritePoints(bindings,world,jointWorld,wantPosition?positions:null,wantMatrix?matrices:null,SkeletalPose.D3dx9_35ScalarMultiply);actual=new{positions=Digest(positions),matrices=Digest(matrices)};}
                else if(kind=="packet")
                {
                    object[] jointsRaw=A(model["joints"]);var joints=new SkeletalJoint[jointsRaw.Length];for(int i=0;i<joints.Length;++i){var j=M(jointsRaw[i]);joints[i]=new SkeletalJoint{Parent=(byte)I(j["parent"]),AnimationBindMatrix=Floats(j["bind"])};}
                    object[] slotsRaw=A(input["slots"]);var slots=new SkeletalClip[slotsRaw.Length];for(int i=0;i<slots.Length;++i)slots[i]=slotsRaw[i]==null?null:clips[I(slotsRaw[i])];string raw=(string)input["packet"];var packet=new AnimationPacket(Unhex(raw));
                    var packetModel=new SkeletalPacketModel{Joints=joints,LocalBindMatrices=Rows(model["localBind"]),Clips=slots,LayerCount=I(model["layers"])};
                    var pose=SkeletalPoints.EvaluatePacket(packet,packetModel,U(input["mask"]),bindings,world,wantPosition?positions:null,wantMatrix?matrices:null,table,SkeletalPose.D3dx9_35ScalarMultiply);
                    actual=new{positions=Digest(positions),matrices=Digest(matrices),skeletalSha256=Digest(pose==null?Sentinel(joints.Length,16):pose.WorldMatrices),packetPreserved=Hex(packet.Bytes)==raw};var copy=new Dictionary<string,object>(M(expected));copy.Remove("arenaRestored");expected=copy;
                }
                else throw new ArgumentException(kind);
            }
            actual=Json.DeserializeObject(Json.Serialize(actual));++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{kind,caseIndex=checks-1,actual,expected});}
        }
        File.WriteAllText(args[2],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
