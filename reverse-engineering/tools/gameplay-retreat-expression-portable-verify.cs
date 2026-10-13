using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class GameplayRetreatExpressionVerify
{
    static Dictionary<string,object> O(object v){return (Dictionary<string,object>)v;}
    static object[] A(object v){return (object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float F(object v){return BitConverter.ToSingle(BitConverter.GetBytes(U(v)),0);}
    static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    static SpawnVector V(object v){object[] a=A(v);return new SpawnVector(F(a[0]),F(a[1]),F(a[2]));}
    static uint[] Words(object v){object[] a=A(v);uint[] r=new uint[a.Length];for(int i=0;i<a.Length;i++)r[i]=U(a[i]);return r;}
    static bool Option(Dictionary<string,object> d,string k,bool fallback){return d.ContainsKey(k)?Convert.ToBoolean(d[k]):fallback;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    class Services:MovementServices
    {
        public bool Callback;public readonly List<object> Events=new List<object>();
        public override bool MovementToken(LocatorCreature c,string token)
        {
            if(!Callback)return false;string t=token.ToLowerInvariant();int mode=t=="walk"?17:t=="run"?34:t=="tiptoe"?51:0;Events.Add(new object[]{"token",token,mode!=0});if(mode!=0)c.MovementMode=(byte)mode;return mode!=0;
        }
        public override float Evaluate(LocatorCreature c,LocatorPacket p,string token){throw new InvalidOperationException("The composed adapter must handle expressions.");}
        public override float NextFloat(){throw new InvalidOperationException("Retreat does not draw RNG.");}
        public override SpawnVector Rotate(SpawnVector v,int angle){throw new InvalidOperationException("Retreat does not rotate.");}
        public override bool SpecialCompletion(LocatorActor a,LocatorRecord b){throw new InvalidOperationException("Retreat does not check completion.");}
        public override void FormationOwnerCommand(LocatorCreature c,int mode){throw new InvalidOperationException("Retreat bypasses formations.");}
        public override void FormationIntent(LocatorCreature c){throw new InvalidOperationException("Retreat bypasses formations.");}
    }
    static object Snapshot(LocatorCreature c)
    {return new Dictionary<string,object>{{"goal",B(c.GoalRange)},{"mode",c.MovementMode},{"flags",c.Flags},{"point",new uint[]{B(c.IntentPoint.X),B(c.IntentPoint.Y),B(c.IntentPoint.Z)}},{"radius",B(c.IntentRadius)},{"intentGoal",B(c.IntentGoal)},{"words",c.IntentWords}};}
    public static int Main(string[] args)
    {
        JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(j.DeserializeObject(File.ReadAllText(args[0])));int checks=0,failures=0;List<object> errors=new List<object>();
        List<object> all=new List<object>();all.AddRange(A(data["cases"]));all.AddRange(A(data["sequences"]));
        foreach(object row in all)
        {
            Dictionary<string,object> v=O(row),o=O(v["options"]),b=O(O(v["before"])["state"]),other=O(v["opponent"]);try
            {
                Services service=new Services{Callback=!Option(o,"noTokenCallback",false)};MovementWorld w=new MovementWorld{Movement=service};LocatorCreature c=new LocatorCreature{GoalRange=F(b["goal"]),MovementMode=(byte)U(b["mode"]),Flags=U(b["flags"]),IntentPoint=V(b["point"]),IntentRadius=F(b["radius"]),IntentGoal=F(b["intentGoal"]),IntentWords=Words(b["words"])};
                if(Option(o,"formation",false))c.Formation=new MovementFormation{Enabled=true};
                if(Option(o,"opponent",true))c.Opponent=new LocatorActor{Controller=Option(o,"opponentController",true)?new LocatorCreature{PathPoint=V(other["point"]),PathWords=Words(other["words"]),FollowRadius=F(other["radius"])}:null};
                ScriptPacket numbers=new ScriptPacket{Script=new ScriptDefinition()};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){numbers.Script.ParameterNames[i]=names[i];numbers.Parameters[i]=values[i];}
                object[] ts=A(v["tokens"]);string[] tokens=new string[ts.Length];for(int i=0;i<ts.Length;i++)tokens[i]=(string)ts[i];
                ExpressionEnvironment environment=new ExpressionEnvironment();environment.Random.State=U(O(v["before"])["rng"]);
                object[] expected=v["native"] is object[]?A(v["native"]):new object[]{v["native"]};
                foreach(object wanted in expected)
                {
                    service.Events.Clear();
                    bool done=RetreatExpressionAdapter.Execute(w,new LocatorPacket{Numbers=numbers},Option(o,"creature",true)?c:null,tokens,Convert.ToBoolean(v["first"]),environment,delegate(string text){service.Events.Add(new object[]{"expression",text});});
                    if(!Object.ReferenceEquals(w.Movement,service))throw new InvalidOperationException("Movement service was not restored.");
                    object got=new Dictionary<string,object>{{"result",done?1:0},{"state",Snapshot(c)},{"events",service.Events},{"tokens",tokens},{"rng",environment.Random.State}};
                    ++checks;if(!Equal(got,wanted)){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,got,want=wanted});}
                }
            }
            catch(Exception e){++failures;if(errors.Count<12)errors.Add(new{index=checks,error=e.ToString()});}
        }
        string output=j.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
