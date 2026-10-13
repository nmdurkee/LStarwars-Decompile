using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class GameplayEngageOpponentVerify
{
    static Dictionary<string,object> O(object v){return (Dictionary<string,object>)v;}
    static object[] A(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float F(object v){return Convert.ToSingle(v);}
    static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    static object Get(Dictionary<string,object> d,string key,object fallback){return d.ContainsKey(key)?d[key]:fallback;}
    static Dictionary<string,object> Child(Dictionary<string,object> d,string key){return d.ContainsKey(key)?O(d[key]):new Dictionary<string,object>();}
    static SpawnVector V(object v){object[] a=A(v);return new SpawnVector(F(a[0]),F(a[1]),F(a[2]));}
    static uint[] Words(object v){object[] a=A(v);uint[] w=new uint[a.Length];for(int i=0;i<a.Length;i++)w[i]=U(a[i]);return w;}
    static uint[] VB(SpawnVector v){return new uint[]{B(v.X),B(v.Y),B(v.Z)};}
    static ActorStateRecord Actor(EngageWorld w,int id){return id<0?null:w.Targeting.Actors.Actors[id];}
    static int Id(object a){ActorStateRecord r=a as ActorStateRecord;return r==null?-1:r.Id;}
    sealed class Context
    {
        public EngageWorld World;public EngageCreature Creature;public EngagePacket Packet;
        public bool HasCreature;public List<object> Events=new List<object>(),Intents=new List<object>();
    }
    static Context Setup(Dictionary<string,object> o)
    {
        Context c=new Context();EngageWorld w=c.World=new EngageWorld{Targeting=new OpponentWorld{Actors=new ActorStateWorld()},Movement=new MovementWorld()};ActorStateWorld aw=w.Targeting.Actors;
        aw.SystemPresent=Convert.ToBoolean(Get(o,"system",true));aw.NameCallback=Convert.ToBoolean(Get(o,"callback",true));aw.ActiveCount=I(Get(o,"count",8));aw.Observe=delegate(string k,object v){c.Events.Add(new object[]{k,v});};
        string[] names={"Alpha","Beta","clone_ep3","clone_ep3_sand","moseisleycitizen","cloudcitycitizen","engineer","RebelScum","Gamma","Delta","T10","T11","T12"};for(int i=0;i<names.Length;i++)aw.Definitions.Add(new ActorStateDefinition{Name=names[i],Flags=new uint[]{0,4,0x200,0x204}[i%4]});
        Dictionary<string,object> overrides=Child(o,"actorOverrides"),extras=Child(o,"fields");
        for(int i=0;i<8;i++)
        {
            Dictionary<string,object> d=Child(overrides,i.ToString());object[] state=A(Get(d,"state",new object[]{0x400u|new uint[]{0,1,4,0x10000}[i%4],0x1001u,0xa5a5a5a5u,0x11401022u,0xa5a50800u,0x5a5a5a5au,(uint)(0x100+i),(uint)(0x200+i),(uint)(0x300+i)}));SpawnVector p=V(Get(d,"position",new object[]{(float)i,(float)(i%2),(float)(i%3)}));
            ActorStateRecord ar=new ActorStateRecord{Id=i,X=p.X,Y=p.Y,Z=p.Z,Flags1f8=U(Get(d,"flags",state[0])),Flags1fc=U(Get(d,"active",state[1])),WeaponFlagsEec=U(state[2]),ProtectionFlagsEf0=U(state[3]),Definition=aw.Definitions[I(Get(d,"definition",i))],SpawnIndex=(byte)I(Get(d,"spawn",i))};
            aw.Actors.Add(ar);aw.Spawns.Add(new ActorStateSpawn{Name=(string)Get(d,"spawnName",i==1?"order66":"spawn"+i),DefinitionIndex=(short)I(Get(d,"spawnDefinition",i))});
        }
        for(int i=0;i<8;i++)
        {
            Dictionary<string,object> d=Child(overrides,i.ToString()),e=Child(extras,i.ToString());ActorStateRecord ar=Actor(w,i);ar.WorldObject=Actor(w,I(Get(d,"world",i)));
            SpawnVector origin=V(Get(e,"origin",new object[]{ar.X,ar.Y,ar.Z}));w.Targeting.Fields[ar]=new OpponentFields{Origin80=new OpponentVector(origin.X,origin.Y,origin.Z),Radius1dc=F(Get(e,"radius",.25f)),FlagsEf4=U(Get(e,"ef4",0u)),AssignedPlayer1084=(byte)I(Get(e,"assigned",255)),PersonalIndex280=(sbyte)I(Get(e,"personal",i)),Reference3ac=Actor(w,I(Get(e,"ref3ac",1)))};
            w.Fields[ar]=new EngageActorFields{ControllerPresent=Convert.ToBoolean(Get(e,"controller",true)),Blocked28b=(byte)I(Get(e,"blocked",0)),Visible288=(byte)I(Get(e,"visible",1)),MatrixIndex28d=(byte)I(Get(e,"matrixIndex",i)),Mode7b5=(byte)I(Get(e,"mode",0)),AttackOverride1085=(byte)I(Get(e,"attack",12)),BlockedTimer1010=F(Get(e,"blockedTimer",0f)),OwnerTimer1000=F(Get(e,"ownerTimer",0f)),FollowRadius3e8=F(Get(e,"followRadius",.5f)),TuningFlags90=U(Get(e,"tuning",0u)),Input8=U(Get(e,"input8",0x10u)),AttackTargetEa0=Actor(w,I(Get(e,"attackTarget",-1))),PathPoint438=V(Get(e,"path",new object[]{11f+i,12f+i,13f+i})),Orientation420=Words(Get(e,"words",new object[]{20+i*6,21+i*6,22+i*6,23+i*6,24+i*6,25+i*6}))};
        }
        aw.PrimaryPlayer=Actor(w,I(Get(o,"primary",1)));object[] players=A(Get(o,"players",new object[]{1,2,3,-1,-1,-1,-1,7}));for(int i=0;i<8;i++)aw.Players[i]=Actor(w,I(players[i]));
        Dictionary<string,object> rows=Child(o,"matrixRows");for(int i=0;i<256;i++){object[] pair=A(Get(rows,i.ToString(),Convert.ToBoolean(Get(o,"permission",true))?new object[]{0xffffffffu,0xffffffffu}:new object[]{0u,0u}));w.PermissionRows[i]=((ulong)U(pair[1])<<32)|U(pair[0]);}
        Dictionary<string,object> attackers=Child(o,"attackerRows");for(int i=0;i<9;i++){w.Targeting.AttackerRows[i]=new ActorStateRecord[17];if(attackers.ContainsKey(i.ToString())){object[] aa=A(attackers[i.ToString()]);for(int k=0;k<aa.Length&&k<17;k++)w.Targeting.AttackerRows[i][k]=Actor(w,I(aa[k]));}}
        w.Targeting.UnassignedPerBand=I(Get(o,"bandThreshold",32));w.Targeting.BandStep=F(Get(o,"bandStep",.75f));w.Targeting.BandBase=F(Get(o,"bandBase",.75f));w.NearMode876584=Convert.ToBoolean(Get(o,"nearMode",false));w.Minicut855de0=Convert.ToBoolean(Get(o,"minicut",false));w.AlternativeDistance7f39e4=Convert.ToBoolean(Get(o,"alternative",false));w.Random.State=U(Get(o,"seed",123u));w.FireButton80227c=U(Get(o,"fireButton",0x800u));w.Touched876cd0=U(Get(o,"touched",0u));
        w.ObserveIntent=delegate(ActorStateRecord target,float radius,uint mode,float goal){c.Intents.Add(new object[]{"intent",Id(target),B(radius),mode,B(goal)});};
        c.HasCreature=Convert.ToBoolean(Get(o,"creature",true));c.Creature=new EngageCreature{Reference=Actor(w,I(Get(o,"reference",0))),OpponentReference=Actor(w,I(Get(o,"opponent",1)))};LocatorCreature m=c.Creature.Movement;m.GoalRange=F(Get(o,"goal",2f));m.MovementMode=(byte)I(Get(o,"mode",9));m.Flags=U(Get(o,"flags",0x80000000u));m.IntentPoint=new SpawnVector(90,91,92);m.IntentRadius=.25f;m.IntentGoal=.5f;m.IntentWords=new uint[]{10,11,12,13,14,15};m.LookTarget=Actor(w,I(Get(o,"look",-1)));
        ScriptPacket numbers=new ScriptPacket{Script=new ScriptDefinition()};string[] pn={"alpha","beta","gamma","delta"};float[] pv={2.75f,1.5f,3,4};for(int i=0;i<4;i++){numbers.Parameters[i]=pv[i];numbers.Script.ParameterNames[i]=pn[i];}
        c.Packet=new EngagePacket{Numbers=numbers,Flags=(byte)I(Get(o,"packetFlags",0)),AttackOverride=(ushort)I(Get(o,"override",0)),CachedOpponent=Actor(w,I(Get(o,"cached",-1))),FireRange=F(Get(o,"fireRange",3f)),FireInterval=F(Get(o,"interval",1.5f)),Timer=F(Get(o,"timer",.25f))};return c;
    }
    static object Snapshot(Context c)
    {
        EngageWorld w=c.World;EngagePacket p=c.Packet;LocatorCreature m=c.Creature.Movement;List<object> actors=new List<object>();for(int i=0;i<8;i++){ActorStateRecord a=Actor(w,i);EngageActorFields e=w.State(a);actors.Add(new object[]{a.WeaponFlagsEec,a.ProtectionFlagsEf0,e.AttackOverride1085,Id(e.AttackTargetEa0),e.Input8});}
        return new Dictionary<string,object>{{"packetFlags",p.Flags},{"override",p.AttackOverride},{"cached",Id(p.CachedOpponent)},{"fireRange",B(p.FireRange)},{"interval",B(p.FireInterval)},{"timer",B(p.Timer)},{"goal",B(m.GoalRange)},{"mode",m.MovementMode},{"flags",m.Flags},{"point",VB(m.IntentPoint)},{"radius",B(m.IntentRadius)},{"intentGoal",B(m.IntentGoal)},{"words",m.IntentWords},{"look",Id(m.LookTarget)},{"touched",w.Touched876cd0},{"rng",w.Random.State},{"actors",actors}};
    }
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(j.DeserializeObject(File.ReadAllText(args[0])));int checks=0,failures=0;List<object> errors=new List<object>();string prior=null;Context c=null;
        foreach(object row in A(data["cases"]))
        {
            Dictionary<string,object> v=O(row);string sequence=(string)Get(v,"sequence",null);try
            {
                if(sequence==null||sequence!=prior)c=Setup(O(v["options"]));prior=sequence;c.Events.Clear();c.Intents.Clear();object[] ts=A(v["tokens"]);string[] tokens=new string[ts.Length];for(int i=0;i<ts.Length;i++)tokens[i]=(string)ts[i];
                bool done=EngageOpponentCommand.Execute(c.World,c.Packet,c.HasCreature?c.Creature:null,tokens,Convert.ToBoolean(v["first"]),F(v["delta"]));object got=new Dictionary<string,object>{{"result",done?1:0},{"state",Snapshot(c)},{"events",c.Events},{"intents",c.Intents}};
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<12)errors.Add(new{index=checks,error=e.ToString()});}
        }
        string output=j.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
