using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Frame;
public static class FramePausedPresentationVerify
{
    static Dictionary<string,object> M(object value) { return (Dictionary<string,object>)value; }
    static uint U(Dictionary<string,object> value,string key) { return Convert.ToUInt32(value[key]); }
    static uint[] Words(object value) { object[] a=(object[])value;uint[] r=new uint[a.Length];for(int i=0;i<a.Length;i++)r[i]=Convert.ToUInt32(a[i]);return r; }
    sealed class Services : IPausedPresentationServices
    {
        public readonly List<object> Calls=new List<object>();
        public uint[] AtApply;
        void Add(string va,params object[] args) { Calls.Add(new object[]{va,args}); }
        public void SetPresentationScale(float value) { Add("0x5e4e00",BitConverter.ToUInt32(BitConverter.GetBytes(value),0)); }
        public void SetUpdateMask(uint value) { Add("0x5d3490",value); }
        public void SetPausedMode(uint value) { Add("0x5d4770",value); }
        public void ApplyCamera(uint[] matrix) { AtApply=(uint[])matrix.Clone();Add("0x603cc0",0); }
        public void UpdatePlayerContexts(uint address,uint mode) { Add("0x495310",address,mode); }
        public void PresentPlayer(uint renderObject,uint playerFlag,int variant) { Add("0x570a80",renderObject,playerFlag,variant); }
        public void FinishPausedPresentation(uint mode) { Add("0x690610",mode); }
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("Fixture and report paths required.");
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=Int32.MaxValue;
        var data=M(json.DeserializeObject(File.ReadAllText(args[0])));int cases=0,failed=0;var errors=new List<object>();
        foreach(object v in (object[])data["gateVectors"])
        {
            var row=M(v);var input=M(row["input"]);int calls=0;
            bool actual=PausedPresentation.ShouldRun(U(input,"paused"),U(input,"forceUpdate"),delegate{calls++;return unchecked((byte)U(input,"override"));});cases++;
            if(actual!=Convert.ToBoolean(row["native"]) || calls!=Convert.ToInt32(row["nativeFirstGateCallbackCount"])) { failed++;errors.Add(new{input=input,actual=actual,callbacks=calls}); }
        }
        foreach(object v in (object[])data["vectors"])
        {
            var row=M(v);var input=M(row["input"]);var native=M(row["native"]);cases++;
            try
            {
                uint[] camera=Words(input["cameraWords"]),matrix=new uint[16];object[] pp=(object[])input["players"];var players=new PausedPlayerProjection[8];
                for(int i=0;i<2;i++)if(pp[i]!=null){var p=M(pp[i]);players[i]=new PausedPlayerProjection{RenderObject=U(p,"renderObject"),Flags=U(p,"flags"),Variant=Convert.ToSByte(p["variant"])};}
                // Filled extra slots must remain outside the native two-player loop.
                for(int i=2;i<8;i++)players[i]=new PausedPlayerProjection{RenderObject=(uint)i,Flags=0x80,Variant=-1};
                var services=new Services();PausedPresentation.Run(camera,matrix,players,services);
                if(json.Serialize(services.Calls)!=json.Serialize(native["calls"]) || json.Serialize(matrix)!=json.Serialize(native["matrix"]) || json.Serialize(services.AtApply)!=json.Serialize(matrix)) { failed++;if(errors.Count<10)errors.Add(new{input=input,calls=services.Calls,matrix=matrix,native=native}); }
            }
            catch(Exception e) {failed++;if(errors.Count<10)errors.Add(new{error=e.Message,input=input});}
        }
        File.WriteAllText(args[1],json.Serialize(new{cases=cases,failures=failed,examples=errors}));
        Console.WriteLine("Paused frame compiled comparisons: "+cases+" cases, "+failed+" failures");return failed==0?0:1;
    }
}
