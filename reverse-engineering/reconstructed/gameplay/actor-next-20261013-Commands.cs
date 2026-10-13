// Bounded original-PC command branches and fixed64-record Sock table.
// Evidence: reports/actor-next-20261013-contract.json. Native loaders/consumers are external.
using System;
namespace Recovered.Gameplay
{
    public sealed class SockRecordProjection
    {
        public byte Present32;
        public ushort Flags68;
        public string NameE4;
    }
    public sealed class SockTableProjection
    {
        public readonly SockRecordProjection[] Records=new SockRecordProjection[64];
        public Action<string,int> Observe;
        internal void Event(string operation,int index){if(Observe!=null)Observe(operation,index);}
    }
    public static class ActorStateContinuationCommands
    {
        static string Text(string value)
        {value=SceneryText.C(value);if(value!=null)MessageNumbers.RequireAscii(value);return value;}
        // @0x44ccd0. @confidence: H. Whole handler with valid attached actor projection.
        // FALSE is an exact case-insensitive comparison, not a substring test.
        public static int CannotBeSeen(ActorStateRecord reference,string[] tokens,bool first)
        {
            if(reference!=null&&reference.WorldObject!=null&&first)
            {
                ActorStateRecord actor=reference.WorldObject;actor.ProtectionFlagsEf0|=2;
                foreach(string input in tokens)
                {
                    string token=Text(input);
                    if(token!=null&&SceneryText.Equal(token,"FALSE"))actor.ProtectionFlagsEf0&=0xfffffffdu;
                }
            }
            return 1;
        }
        // @0x53f7e0. @confidence: H. Exactly64 records, byte presence gate, first name match.
        public static int FindSock(SockTableProjection table,string name)
        {
            if(table==null)return -1;name=Text(name);
            if(name==null)throw new ArgumentNullException("name");
            for(int i=0;i<64;++i)
            {
                SockRecordProjection record=table.Records[i];
                if(record==null)throw new ArgumentException("All64 native record projections must exist.");
                if(record.Present32!=0)
                {
                    string candidate=Text(record.NameE4);
                    if(candidate!=null&&SceneryText.Equal(name,candidate))return i;
                }
            }
            return -1;
        }
        // @0x541430 /0x541460. @confidence: H. Signed indices are tested as uint.
        // No record presence check occurs here. Mask0x100 means disabled.
        public static void SetSockEnabled(SockTableProjection table,int index,bool enabled)
        {
            if(table==null||unchecked((uint)index)>=64)return;
            SockRecordProjection record=table.Records[index];
            if(record==null)throw new ArgumentException("Missing native Sock record.");
            if(enabled)
            {if((record.Flags68&0x100)!=0)record.Flags68=(ushort)(record.Flags68&0xfeff);}
            else
            {if((record.Flags68&0x100)==0)record.Flags68=(ushort)(record.Flags68|0x100);}
        }
        // Native6e6b90 truncates extended value to signed64, returning low32.
        // MessageNumbers.Resolve composes existing0x5147c0 packet/numeric behavior.
        static int Index(float value)
        {
            if(float.IsNaN(value)||float.IsInfinity(value)||(double)value>=9223372036854775808.0||(double)value< -9223372036854775808.0)return 0;
            return unchecked((int)(long)value);
        }
        // @0x44ce00. @confidence: M. Handler composed with fixed-table helpers;
        // numeric values must remain within existing finite float32 resolver domain.
        // ix= outranks name= and FALSE within one token; failed name lookup retains index.
        public static int EnableSock(SockTableProjection table,ScriptPacket packet,string[] tokens,bool first)
        {return EnableSock(table,packet,tokens,first,table==null?null:table.Observe);}
        public static int EnableSock(SockTableProjection table,ScriptPacket packet,string[] tokens,bool first,Action<string,int> observe)
        {
            int index=-1;bool enabled=true;
            if(!first)return 1;
            foreach(string input in tokens)
            {
                string token=Text(input);if(token==null)throw new ArgumentNullException("tokens");
                int at=SceneryText.Index(token,"ix=");
                if(at>=0)
                {
                    string operand=token.Substring(at+3);index=Index(MessageNumbers.Resolve(packet,operand));
                    if(observe!=null)observe("ix",index);
                }
                else
                {
                    at=SceneryText.Index(token,"name=");
                    if(at>=0)
                    {
                        int found=FindSock(table,token.Substring(at+5));
                        if(observe!=null)observe("name",found);
                        if(found!=-1)index=found;
                    }
                    else if(SceneryText.Index(token,"FALSE")>=0)enabled=false;
                }
            }
            if(observe!=null)observe(enabled?"enable":"disable",index);
            SetSockEnabled(table,index,enabled);return 1;
        }
        // @0x4545d0. @confidence: H. Last character= lookup replaces/clears actor;
        // actual takeover release remains inherited TagControlServices.Release adapter.
        public static int ReleaseTakeOver(TagControlWorld world,ActorStateRecord reference,string[] tokens,bool first)
        {
            if(first)
            {
                ActorStateRecord actor=reference==null?null:reference.WorldObject;
                foreach(string input in tokens)
                {
                    string token=Text(input);if(token==null)throw new ArgumentNullException("tokens");
                    int at=SceneryText.Index(token,"character=");
                    if(at>=0)actor=world.Actors.ResolveObject(token.Substring(at+10));
                }
                if(actor!=null&&world.Get(actor).LinkedCd0!=null)
                {
                    if(world.Services==null)throw new InvalidOperationException("Takeover release service required.");
                    world.Services.Release(actor);
                }
            }
            return 1;
        }
    }
}
