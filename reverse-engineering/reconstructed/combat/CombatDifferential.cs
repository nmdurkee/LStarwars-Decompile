// Differential runner only; excludes native game integration and live services.
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Text.RegularExpressions;
using System.Web.Script.Serialization;
using Recovered.Combat;

public sealed class CombatDifferential
{
    static Dictionary<string,object> Map(object o) { return (Dictionary<string,object>)o; }
    static int Int(Dictionary<string,object> d, string k) { return Convert.ToInt32(d[k], CultureInfo.InvariantCulture); }
    static uint UInt(Dictionary<string,object> d, string k) { return Convert.ToUInt32(d[k], CultureInfo.InvariantCulture); }
    static float Float(Dictionary<string,object> d, string k) { return Convert.ToSingle(d[k], CultureInfo.InvariantCulture); }
    static bool Bool(Dictionary<string,object> d, string k) { return d.ContainsKey(k) && Convert.ToBoolean(d[k]); }
    static string[] Tokens(Dictionary<string,object> d)
    {
        object[] values = (object[])d["tokens"];
        return Array.ConvertAll(values, x => (string)x);
    }
    const uint Obj=0x10100000, Other=Obj+0x2000, Pool=Obj+0xc000;
    sealed class Services : ICombatScriptServices
    {
        public CombatObject self, other;
        public bool parameters, message;
        public List<CombatObject> objects = new List<CombatObject>();
        public List<object> calls = new List<object>();
        public IEnumerable<CombatObject> Characters { get { return objects; } }
        // Bounded literal fixture adapter. Production numeric evaluation is a separate
        // dependency. No claim that host double reproduces every native x87 input.
        public int EvaluateInteger(string expression)
        {
            if(parameters)
            {
                if(expression.IndexOf("param",StringComparison.OrdinalIgnoreCase)>=0)return 5;
                string[] names={"alpha","beta","gamma","delta"};int[] values={5,-1,260,0};
                for(int i=0;i<4;i++)if(String.Equals(expression,names[i],StringComparison.OrdinalIgnoreCase))return values[i];
            }
            string value = Regex.Match(expression, @"^-?[0-9]*(?:\.[0-9]*)?").Value;
            double parsed;
            return Double.TryParse(value, NumberStyles.AllowLeadingSign | NumberStyles.AllowDecimalPoint,
                CultureInfo.InvariantCulture, out parsed) ? (int)parsed : 0;
        }
        public CombatObject FindCharacter(string name) { return name=="self"?self:name=="other"?other:null; }
        public bool TryMessageInteger(string name, out int value) { value=6; return message && name=="hp"; }
        public void Hit(CombatObject attacker, CombatObject target, int damage, ushort flags, bool probe, int context)
        {
            calls.Add(new object[] { attacker==null?0:attacker.Id,target.Id,unchecked((uint)damage),flags,probe?1:0,context });
        }
    }
    static object Evaluate(string name, Dictionary<string,object> m)
    {
        CombatObject o = new CombatObject();
        if (name=="attacker_hit_flags")
        {
            if (Bool(m,"null")) return CombatRules.AttackerHitFlags(null);
            o.Flags=UInt(m,"objectFlags");o.IdentityFlags=UInt(m,"identity");return CombatRules.AttackerHitFlags(o);
        }
        if (name=="cannot_kill_context_and_character")
        {
            o.CharacterFlags94=UInt(m,"characterFlags");o.PlayerSlot=(sbyte)Int(m,"slot");
            return CombatRules.CannotKill(o,UInt(m,"contextFlags"))?1:0;
        }
        if (name=="player_invincibility")
        {
            o.InvincibilityTimer=Float(m,"timer");return CombatRules.PlayerInvincible(Bool(m,"null")?null:o,UInt(m,"cheatFlags"))?1:0;
        }
        if (name=="post_hit_protection_timer")
        {
            o.ProtectionFlags=UInt(m,"flags");CombatRules.SetPostHitProtection(o,Float(m,"timer"));
            return new object[]{o.ProtectionFlags,o.ProtectionTimer};
        }
        if (name=="shield_hit_arithmetic_and_guards")
        {
            o.Flags=0x1001u+(Bool(m,"player")?128u:0u);o.ShieldHealth=(byte)Int(m,"shield");
            o.ShieldScale=Float(m,"scale");o.ShieldFlickerTimer=Float(m,"timer");
            string type=(string)m["attacker"];CombatObject a=type=="none"?null:new CombatObject();
            if(a!=null){a.Flags=type=="inactive"?0u:type=="player"?129u:1u;a.Context=(sbyte)(type=="special_npc"?57:0);}
            CombatRules.ApplyShieldDamage(a,o,Int(m,"damage"),Bool(m,"cut"),Bool(m,"invincible")?128u:0u,0.1f);
            return new object[]{o.ShieldHealth,o.ShieldFlickerTimer,o.ShieldScale};
        }
        if(name=="HitPoints_signed_byte_and_actor_resolution")
        {
            if(!m.ContainsKey("storedByte"))return CombatRules.HitPoints(null);
            o.Health=(byte)Int(m,"storedByte");return CombatRules.HitPoints(o);
        }
        
        
        if(name=="currency_deduction_and_return_suppression"||name=="currency_early_protection_guards")
        {
            bool protection=name=="currency_early_protection_guards";
            uint balance=protection?10000u:UInt(m,"amount");
            string suppression=protection?"none":(string)m["suppression"];
            uint dropped=CombatEconomy.DeductStuds(ref balance,!protection||Bool(m,"hasWallet"),Int(m,"reason"),
                !protection&&Bool(m,"specialMode"),protection?0:Int(m,"dynamicAdjustment"),
                protection?UInt(m,"cheatFlags"):suppression=="cheat"?4u:0u,
                protection?Float(m,"invincibilityTimer"):0,protection?UInt(m,"characterFlags90"):0,
                suppression=="timer"?1:0);
            return new object[]{balance,dropped};
        }
        if(name=="heart_drop_health_pickups_difficulty_and_rng")
        {
            PlayerHealth[] p=new PlayerHealth[2];
            for(int i=0;i<2;i++)p[i]=new PlayerHealth{
                Present=Convert.ToBoolean(((object[])m["present"])[i]),Dead=Convert.ToBoolean(((object[])m["dead"])[i]),
                Maximum=Convert.ToByte(((object[])m["maxima"])[i]),Current=Convert.ToByte(((object[])m["health"])[i])};
            uint seed=UInt(m,"seed");bool drop=CombatEconomy.ShouldDropHeart(p[0],p[1],Int(m,"activeHearts"),
                (byte)Int(m,"counter"),Int(m,"dynamicAdjustment"),ref seed);
            return new object[]{drop?1:0,seed};
        }

        if(name=="command_named_or_value_adapters")
        {
            o.Id=Obj;o.DefaultHealth=4;o.DefaultShieldHealth=6;o.MaximumHealth=17;o.Health=19;o.ShieldHealth=23;
            CombatObject second=new CombatObject{Id=Other,DefaultHealth=8,DefaultShieldHealth=9,MaximumHealth=29,Health=31,ShieldHealth=37};
            ScriptActor namedActor=new ScriptActor{Character=Bool(m,"actor")?o:null,Opponent=second};
            Services named=new Services{self=o,other=second,parameters=Bool(m,"parameters"),message=Bool(m,"message")};
            string command=(string)m["command"];int returned;
            if(command=="SetHitPoints")returned=HealthCommands.SetHitPoints(namedActor,Tokens(m),Bool(m,"firstCall"),named);
            else if(command=="SetShieldHitPoints")returned=HealthCommands.SetShieldHitPoints(namedActor,Tokens(m),Bool(m,"firstCall"),named);
            else returned=HealthCommands.TakeDamage(namedActor,Tokens(m),Bool(m,"firstCall"),named);
            return new object[]{new object[]{o.MaximumHealth,o.Health,o.ShieldHealth},new object[]{second.MaximumHealth,second.Health,second.ShieldHealth},named.calls.ToArray(),returned};
        }

        bool authored=name=="all_authored_combat_command_forms";
        bool first=authored||Bool(m,"firstCall"), actor=authored||Bool(m,"actor");
        o.Id=Obj;o.DefaultHealth=4;o.DefaultShieldHealth=6;o.MaximumHealth=17;o.Health=19;o.ShieldHealth=23;
        ScriptActor sa=new ScriptActor();sa.Character=actor?o:null;
        sa.Opponent=authored||Bool(m,"opponent")?new CombatObject{Id=Other}:null;
        Services services=new Services();
        int[] ids={1,2,16,1,2,16};uint[] flags={1,1,1,0,128,129};int count=m.ContainsKey("poolCount")?Int(m,"poolCount"):6;
        for(int i=0;i<count;i++)services.objects.Add(new CombatObject{Id=Pool+(uint)i*0x10d8,Set=(byte)ids[i],Flags=flags[i]});
        int result;
        if(name=="SetHitPoints_defaults_truncation_and_maximum" || authored&&(string)m["key"]=="SetHitPoints")
        {
            result=HealthCommands.SetHitPoints(sa,Tokens(m),first,services);return new object[]{o.MaximumHealth,o.Health,result};
        }
        if(name=="SetShieldHitPoints_defaults_and_truncation")
        {
            string token=(string)m["token"];
            result=HealthCommands.SetShieldHitPoints(sa,token==null?new string[0]:new string[]{token},first,services);
            return new object[]{o.ShieldHealth,result};
        }
        if(name=="TakeDamage_command_hit_dispatch"||name=="TakeDamage_set_selection_and_order"||authored)
        {
            result=HealthCommands.TakeDamage(sa,Tokens(m),first,services);return new object[]{services.calls.ToArray(),result};
        }
        throw new InvalidOperationException("Unknown contract "+name);
    }
    static bool Equal(object actual,object expected)
    {
        var aa=actual as object[];var ee=expected as object[];
        if(aa!=null||ee!=null)
        {
            if(aa==null||ee==null||aa.Length!=ee.Length)return false;
            for(int i=0;i<aa.Length;i++)if(!Equal(aa[i],ee[i]))return false;
            return true;
        }
        if(actual is float)return (float)actual==Convert.ToSingle(expected,CultureInfo.InvariantCulture);
        return Convert.ToDecimal(actual,CultureInfo.InvariantCulture)==Convert.ToDecimal(expected,CultureInfo.InvariantCulture);
    }
    public static int Main(string[] args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=Int32.MaxValue;
        var byContract=new Dictionary<string,int>();var failures=new List<object>();int total=0, mismatchCount=0;
        for(int f=0;f<args.Length-1;f++)
        {
            var root=Map(json.DeserializeObject(File.ReadAllText(args[f])));
            foreach(object entry in (object[])root["vectors"])
            {
                var vector=Map(entry);string name=(string)vector["contract"];var input=Map(vector["input"]);
                total++;if(!byContract.ContainsKey(name))byContract[name]=0;byContract[name]++;
                try
                {
                    object actual=Evaluate(name,input);
                    if(!Equal(actual,vector["native"])) { mismatchCount++; if(failures.Count<30)
                        failures.Add(new{contract=name,input=input,actual=actual,native=vector["native"]}); }
                }
                catch(Exception ex){mismatchCount++;if(failures.Count<30)failures.Add(new{contract=name,error=ex.Message});}
            }
        }
        File.WriteAllText(args[args.Length-1],json.Serialize(new{cases=total,failures=mismatchCount,contracts=byContract,examples=failures}));
        Console.WriteLine("Combat compiled differential: "+total+" cases, "+mismatchCount+" failures");
        return mismatchCount==0?0:1;
    }
}
