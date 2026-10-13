using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayLocatorVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float Float(object v){return BitConverter.ToSingle(BitConverter.GetBytes(U(v)),0);}
    static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    static SpawnVector Vector(object o){object[] a=Arr(o);return new SpawnVector(Float(a[0]),Float(a[1]),Float(a[2]));}
    static uint[] Words(SpawnVector v){return new uint[]{Bits(v.X),Bits(v.Y),Bits(v.Z)};}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;
        IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object key in ad.Keys)if(!bd.Contains(key)||!Equal(ad[key],bd[key]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Check(string group,object got,object want,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<20)errors.Add(new{group,got,want,index});}}
    class World:LocatorWorld
    {
        public readonly List<object> Events=new List<object>();
        public LocatorActor[] Actors=new LocatorActor[3];
        public LocatorPacket Caller;
        public LocatorCreature Creature;
        public uint State;
        public override LocatorRecord Find(string name){Events.Add(new object[]{"find",name});return base.Find(name);}
        int Named(string name){if(name.StartsWith("missing",StringComparison.OrdinalIgnoreCase))return -1;int h=0;foreach(char c in name.ToLowerInvariant())h+=c;return 1+h%2;}
        LocatorActor Bind(string kind,string name){Events.Add(new object[]{kind,name});int ix=Named(name);return ix<0?null:Actors[ix];}
        int Draw(){unchecked{int x=(int)(State^0x75bd924);int v=x*0x41a7-(x/0x1f31d)*0x7fffffff;if(v<0)v+=0x7fffffff;State=(uint)v^0x75bd924;return (int)State;}}
        public World(Dictionary<string,object> c,object[] before)
        {
            foreach(object row in Arr(c["records"]))
            {
                Dictionary<string,object> r=Obj(row);LocatorRecord l=new LocatorRecord{Name=(string)r["name"],Position=Vector(r["position"]),Heading=unchecked((int)U(r["heading"]))};object[] orient=Arr(r["orientation"]);for(int i=0;i<6;i++)l.Orientation[i]=U(orient[i]);Locators.Add(l);
            }
            ScriptDefinition script=new ScriptDefinition();ScriptPacket numbers=new ScriptPacket{Script=script};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){script.ParameterNames[i]=names[i];numbers.Parameters[i]=values[i];}Caller=new LocatorPacket{Numbers=numbers};
            for(int i=0;i<3;i++)
            {
                Dictionary<string,object> b=Obj(before[i]);object[] pos=Arr(b["positions"]),ang=Arr(b["angles"]),ori=Arr(b["orientation"]);
                LocatorActor a=new LocatorActor{Id=i,Packet=new LocatorPacket{Numbers=numbers,Selected=Int(b["selected"])<0?null:Locators[Int(b["selected"])]},SpawnLocator=Int(b["spawnLocator"])<0?null:Locators[Int(b["spawnLocator"])],PersonalIndex=(sbyte)Int(Arr(c["indices"])[i]),CharacterName=(string)Arr(c["characterNames"])[i],Position=Vector(pos[0]),Origin80=Vector(pos[1]),Cache8c=Vector(pos[2]),Cache98=Vector(pos[3]),Cache1b4=Vector(pos[4]),Cache1cc=Vector(pos[5]),Cache10bc=Vector(pos[6]),Velocity=Vector(b["velocity"]),Angle58=(ushort)Int(ang[0]),Angle5a=(ushort)Int(ang[1]),Angle27a=(ushort)Int(ang[2])};for(int j=0;j<6;j++)a.Orientation420[j]=U(ori[j]);Actors[i]=a;
            }
            int worldObject=Int(c["worldObject"]);Actors[0].WorldObject=worldObject<0?null:Actors[worldObject];Actors[1].WorldObject=Actors[1];Actors[2].WorldObject=Actors[2];
            if(Convert.ToBoolean(c["creature"]))Creature=new LocatorCreature{Reference=Convert.ToBoolean(c["reference"])?Actors[0]:null,Position=Vector(c["position"])};
            for(int i=0;i<2;i++){int player=Int(Arr(c["players"])[i]);Players[i]=player<0?null:Actors[player];}
            if(Convert.ToBoolean(c["callback"]))ResolveReference=delegate(string name){return Bind("reference",name);};
            ResolveObject=delegate(string name){return Bind("object",name);};
            NextInteger=Draw;State=U(c["seed"]);VelocityReset=Vector(c["resetVelocity"]);LastSnapOrigin=new SpawnVector(Float(0x1234),Float(0x5678),Float(0x9abc));
            RefreshTerrain=delegate(LocatorActor a){Events.Add(new object[]{"refresh",a.Id});};CheckTerrain=delegate(LocatorActor a){Events.Add(new object[]{"terrain",a.Id});};
        }
        public object Snapshots()
        {
            List<object> rows=new List<object>();foreach(LocatorActor a in Actors)rows.Add(new Dictionary<string,object>{{"selected",a.Packet.Selected==null?-1:Locators.IndexOf(a.Packet.Selected)},{"spawnLocator",a.SpawnLocator==null?-1:Locators.IndexOf(a.SpawnLocator)},{"positions",new object[]{Words(a.Position),Words(a.Origin80),Words(a.Cache8c),Words(a.Cache98),Words(a.Cache1b4),Words(a.Cache1cc),Words(a.Cache10bc)}},{"angles",new ushort[]{a.Angle58,a.Angle5a,a.Angle27a}},{"orientation",a.Orientation420},{"velocity",Words(a.Velocity)}});return rows;
        }
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
        foreach(object item in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(item),expected=Obj(v["native"]);World w=new World(Obj(v["context"]),Arr(v["before"]));object[] ts=Arr(v["tokens"]);string[] tokens=new string[ts.Length];for(int i=0;i<ts.Length;i++)tokens[i]=(string)ts[i];
            try
            {
                bool result=(string)v["command"]=="SetLocator"?LocatorCommands.SetLocator(w,w.Caller,w.Creature,tokens,Convert.ToBoolean(v["first"])):LocatorCommands.SnapToLocator(w,w.Caller,w.Creature,tokens,Convert.ToBoolean(v["first"]));
                Check("actors",w.Snapshots(),expected["actors"],index);Check("events",w.Events,expected["events"],index);Check("rng",w.State,expected["rng"],index);Check("globalOrigin",Words(w.LastSnapOrigin),expected["globalOrigin"],index);Check("result",result?1:0,expected["result"],index);
            }
            catch(Exception ex){++failures;if(errors.Count<20)errors.Add(new{index,error=ex.ToString()});}
            ++index;
        }
        foreach(object item in Arr(data["conditions"]))
        {Dictionary<string,object> v=Obj(item);Check("GotLocator",Bits(LocatorCommands.GotLocator(new LocatorPacket{Selected=Convert.ToBoolean(v["pointerPresent"])?new LocatorRecord():null})),v["nativeBits"],index++);}
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
