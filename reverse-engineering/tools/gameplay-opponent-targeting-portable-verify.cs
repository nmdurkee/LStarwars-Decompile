using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class GameplayOpponentTargetingVerify
{
    static Dictionary<string,object> O(object v){return (Dictionary<string,object>)v;}
    static object[] A(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float F(object v){return Convert.ToSingle(v);}
    static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    static OpponentVector V(object v){object[] a=A(v);return new OpponentVector(F(a[0]),F(a[1]),F(a[2]));}
    static ActorStateRecord Actor(OpponentWorld w,int id){return id<0?null:w.Actors.Actors[id];}
    static OpponentWorld World()
    {
        OpponentWorld w=new OpponentWorld{Actors=new ActorStateWorld()};
        for(int i=0;i<8;i++){ActorStateRecord a=new ActorStateRecord{Id=i};w.Actors.Actors.Add(a);w.Fields[a]=new OpponentFields();}
        return w;
    }
    static bool Equal(object a,object b)
    {
        IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(j.DeserializeObject(File.ReadAllText(args[0])));
        int checks=0,failures=0;List<object> errors=new List<object>();
        foreach(object row in A(data["cases"]))
        {
            Dictionary<string,object> v=O(row),d=O(v["data"]);string kind=(string)v["kind"];OpponentWorld w=World();object got=null;
            try
            {
                if(kind=="assignment")
                {
                    OpponentFields s=w.State(Actor(w,0));s.FlagsEf4=U(d["flags"]);s.AssignedPlayer1084=(byte)I(d["index"]);object[] ps=A(d["players"]);for(int i=0;i<8;i++)w.Actors.Players[i]=Actor(w,I(ps[i]));
                    got=OpponentTargeting.AssignedTargetAllowed(w,Convert.ToBoolean(d["own"])?Actor(w,0):null,Actor(w,I(d["target"])))?1:0;
                }
                else if(kind=="band")
                {
                    int index=I(d["row"]);w.State(Actor(w,0)).Reference3ac=Actor(w,1);w.State(Actor(w,1)).PersonalIndex280=(sbyte)index;
                    w.UnassignedPerBand=I(d["threshold"]);w.BandStep=F(d["step"]);w.BandBase=F(d["base"]);
                    object[] es=A(d["entries"]),assigned=A(d["assigned"]);if(index>=0&&index<=8){w.AttackerRows[index]=new ActorStateRecord[es.Length];for(int i=0;i<es.Length;i++)w.AttackerRows[index][i]=Actor(w,I(es[i]));}
                    for(int i=0;i<8;i++)w.State(Actor(w,i)).AssignedPlayer1084=(byte)I(assigned[i]);got=B(OpponentTargeting.PreferredRange(w,Actor(w,0)));
                }
                else if(kind=="raySphere")
                {
                    float value=123.25f;bool yes=OpponentTargeting.RaySphere(V(d["origin"]),V(d["direction"]),V(d["center"]),F(d["radius"]),ref value);
                    got=new Dictionary<string,object>{{"result",yes?1:0},{"output",B(Convert.ToBoolean(d["output"])?value:123.25f)}};
                }
                else
                {
                    object[] origins=A(d["origins"]),radii=A(d["radii"]),active=A(d["active"]),players=A(d["players"]);
                    for(int i=0;i<8;i++){ActorStateRecord a=Actor(w,i);a.Flags1fc=U(active[i]);w.State(a).Origin80=V(origins[i]);w.State(a).Radius1dc=F(radii[i]);w.Actors.Players[i]=Actor(w,I(players[i]));}
                    Actor(w,0).Flags1f8=U(d["flags"]);got=OpponentTargeting.PlayerObstructs(w,Actor(w,0),Actor(w,1))?1:0;
                }
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<12)errors.Add(new{index=checks,kind,error=e.ToString()});}
        }
        string output=j.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
