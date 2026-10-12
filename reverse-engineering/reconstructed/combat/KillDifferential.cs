// Managed comparison against saved original-x86 Kill results. Execution status is reported separately.
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Web.Script.Serialization;
using Recovered.Combat;
public static class KillDifferential
{
    static Dictionary<string,object> Map(object o) { return (Dictionary<string,object>)o; }
    static int Int(Dictionary<string,object> m,string k) { return Convert.ToInt32(m[k],CultureInfo.InvariantCulture); }
    static uint UInt(Dictionary<string,object> m,string k) { return Convert.ToUInt32(m[k],CultureInfo.InvariantCulture); }
    sealed class Services : IKillServices
    {
        public List<KillTarget> actors=new List<KillTarget>();
        public List<object> calls=new List<object>();
        public bool resolver,parameters;
        public IEnumerable<KillTarget> Characters { get { return actors; } }
        int Lookup(string name)
        {
            string s=name.ToLowerInvariant();
            return s=="self"||s=="player"?0:s=="other"||s=="player_2"?1:s=="ai_dooku"?2:s=="ai_vader"?3:s=="ai_spy"?4:-1;
        }
        public KillTarget FindCharacter(string name)
        {
            if(!resolver)return null;
            int i=Lookup(name);calls.Add(new object[]{"find",name,i});return i<0?null:actors[i];
        }
        public KillTarget ResolveReference(string name)
        {
            int i=Lookup(name);calls.Add(new object[]{"reference",name,i});return i<0?null:actors[i];
        }
        // Bounded fixture adapter; full numeric and world-name services are separate contracts.
        public int EvaluateInteger(string expression)
        {
            string s=expression.ToLowerInvariant();
            if(parameters)
            {
                if(s=="alpha"||s.Contains("param"))return 5;
                if(s=="beta")return -1;
                if(s=="gamma")return 16;
                if(s=="delta")return 0;
            }
            double value;return Double.TryParse(s,NumberStyles.Float,CultureInfo.InvariantCulture,out value)?(int)value:0;
        }
        public void ActivateParts(KillTarget target,int a,int b,int c,int d,int e,int f)
        { calls.Add(new object[]{"parts",actors.IndexOf(target),unchecked((uint)a),unchecked((uint)b),c,d,e,f}); }
        public void DeathCleanup(KillTarget target,int mode,int arg)
        { calls.Add(new object[]{"death",actors.IndexOf(target),mode,arg}); }
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("Expected native fixture path and output report path.");
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=Int32.MaxValue;
        Dictionary<string,object> root=Map(json.DeserializeObject(File.ReadAllText(args[0])));
        int cases=0,mismatches=0;List<object> examples=new List<object>();
        foreach(object item in (object[])root["vectors"])
        {
            Dictionary<string,object> row=Map(item),input=Map(row["input"]),expected=Map(row["native"]);
            Services s=new Services();s.resolver=Convert.ToBoolean(input["resolver"]);s.parameters=Convert.ToBoolean(input["parameters"]);
            foreach(object actor in (object[])input["actors"])
            {
                Dictionary<string,object> a=Map(actor);s.actors.Add(new KillTarget{Flags=UInt(a,"flags"),IdentityFlags=UInt(a,"identity"),DeathState=(byte)Int(a,"death"),Set=(byte)Int(a,"set"),HitFlags=UInt(a,"hit"),SpawnTimer=BitConverter.ToSingle(BitConverter.GetBytes(UInt(a,"timerBits")),0)});
            }
            int self=Int(input,"self"),opponent=Int(input,"opponent");
            int result=KillCommand.Execute(self<0?null:s.actors[self],opponent<0?null:s.actors[opponent],opponent!=-1,
                Array.ConvertAll((object[])input["tokens"],x=>(string)x),Int(input,"first")!=0,s);
            uint[] hits=s.actors.ConvertAll(a=>a.HitFlags).ToArray();
            bool ok=result==Int(expected,"result")&&json.Serialize(hits)==json.Serialize(expected["hits"])&&json.Serialize(s.calls)==json.Serialize(expected["calls"]);
            cases++;
            if(!ok){mismatches++;if(examples.Count<12)examples.Add(new{index=cases-1,input=input,expected=expected,result=result,hits=hits,calls=s.calls});}
        }
        string report=json.Serialize(new{fixture=args[0],binarySha256=root["binarySha256"],cases=cases,mismatches=mismatches,examples=examples,scope="Portable bounded Kill command; name/numeric/parts/death services remain explicit adapters."});
        File.WriteAllText(args[1],report+Environment.NewLine);Console.WriteLine(report);return mismatches==0?0:1;
    }
}
