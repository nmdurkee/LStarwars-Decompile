// Prepared command/name-lookup replay. Compile only; expression is a fixture service.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class ScriptAnimationOverrideVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}
    static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static bool Bool(object v){return Convert.ToBoolean(v,CultureInfo.InvariantCulture);}
    static void Put(byte[] b,int at,uint v){for(int i=0;i<4;++i)b[at+i]=(byte)(v>>(8*i));}
    static string Digest(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static bool Same(object a,object b)
    {
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    static AnimationNameEntry[] Definitions(object raw)
    {
        if(raw==null)return null;var rows=A(raw);var result=new AnimationNameEntry[rows.Length];
        for(int i=0;i<rows.Length;++i)if(rows[i]!=null){var r=M(rows[i]);result[i]=new AnimationNameEntry{Name=(string)r["name"],Action=unchecked((short)I(r["action"]))};}return result;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<override-fixtures.json.gz> <result.json>");
        Dictionary<string,object> fixture;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        var tables=A(fixture["tables"]);var addresses=M(fixture["addresses"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var row=M(item);var input=M(row["input"]);var definitions=Definitions(tables[I(input["table"])]);string kind=(string)row["kind"];object expected=row["native"],actual;
            if(kind=="lookup")actual=ScriptAnimationOverride.FindAction(definitions,(string)input["query"]);
            else
            {
                var c=M(input["state"]);byte[] raw=new byte[PcObjectImage.Size];for(int i=0;i<raw.Length;++i)raw[i]=0xa5;var actor=new PcObjectImage(raw);
                actor.Set32(0,Bool(c["world"])?U(addresses["actor"]):0);actor.Set32(0x50,0);actor.Set32(0x54,Bool(c["definitions"])?U(addresses["character"]):0);actor.Set32(0x1f8,0x40000);actor.Set32(0x398,Bool(c["owner"])?U(addresses["actor"]):0);
                actor.Set16(0x3ee,I(c["from"]));actor.Set16(0x3f0,I(c["to"]));actor.Set16(0x42,I(c["requested"]));actor.Set16(0x3e,123);actor.Set16(0x40,456);actor.Set16(0x7ee,-234);actor.Set16(0x7f0,-345);actor.Set8(0x7b5,I(c["context"]));
                byte[] processorBytes=new byte[256];Put(processorBytes,4,U(addresses["script"]));Put(processorBytes,0x14,PcObjectImage.ToBits(2.75f));Put(processorBytes,0x18,PcObjectImage.ToBits(-1.5f));Put(processorBytes,0x9c,U(c["timer"]));
                var processor=new ScriptAnimationProcessor{ActionTimer=PcObjectImage.FromBits(U(c["timer"]))};var events=new List<object>();string[] tokens=Array.ConvertAll(A(input["tokens"]),v=>(string)v);
                int result=ScriptAnimationOverride.Run(Bool(c["packet"])?actor:null,Bool(c["owner"]),Bool(c["world"]),Bool(c["definitions"])?definitions:null,I(c["total"]),tokens,I(c["count"]),I(c["first"]),Bool(c["processor"])?processor:null,
                    t=>{events.Add(new object[]{"expression",t});return PcObjectImage.FromBits(U(input["expressionValue"]));});
                if(Bool(c["consume"]))AnimationControl.AdvancePlayerWithoutEvents(actor,null,null);
                Put(processorBytes,0x9c,PcObjectImage.ToBits(processor.ActionTimer));actual=new{from=actor.I16(0x3ee),to=actor.I16(0x3f0),timer=PcObjectImage.ToBits(processor.ActionTimer),requested=actor.I16(0x42),previous=actor.I16(0x40),miniPrevious=actor.I16(0x7f0),result,events,actorSha256=Digest(actor.Bytes),processorSha256=Digest(processorBytes)};
                // Lookup call tracing is a native-only observation; direct lookup
                // result cases and complete destination digests cover its result.
                var copy=new Dictionary<string,object>(M(expected));var filtered=new List<object>();foreach(var ev in A(copy["events"]))if((string)A(ev)[0]=="expression")filtered.Add(ev);copy["events"]=filtered.ToArray();expected=copy;
            }
            actual=Json.DeserializeObject(Json.Serialize(actual));++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{kind,caseIndex=checks-1,actual,expected});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
