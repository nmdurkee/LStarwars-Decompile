// Bounded native BigJump request and action composition. Not a locomotion tick.
using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public abstract class BigJumpServices
    {
        //55e4a0 broader actor reset, model/clip dispatch, invalidation and feedback
        //remain explicit services. Control reset and heading are recovered bodies.
        public abstract void ResetActor(BigJumpWorld world,uint identity,PcObjectImage actor);
        public abstract short SelectAnimation(BigJumpWorld world,uint identity,PcObjectImage actor);
        public abstract float Duration(BigJumpWorld world,short model,short animation);
        public abstract void InvalidateAnimation(BigJumpWorld world,uint identity,PcObjectImage actor);
        public abstract void Feedback(BigJumpWorld world,uint identity,PcObjectImage actor,int kind);
    }
    public sealed class BigJumpWorld
    {
        public int ContextId31=31;
        public short FallbackAnimation;
        public ushort[] AngleTable;
        public PathRelocationWorld Controls;
        public LocatorWorld Locators;
        public BigJumpServices Services;
        public readonly Dictionary<uint,ReinitializationRecord> Definitions=new Dictionary<uint,ReinitializationRecord>();
        public readonly Dictionary<uint,string> CharacterNames=new Dictionary<uint,string>();
        public Action<string,string> Observe;
    }
    public static class BigJumpActions
    {
        struct W
        {
            PlaybackWide exact;double approximate;
            public W(float f){exact=PlaybackWide.From(f);approximate=f;}
            static W Make(PlaybackWide e,double a){return new W{exact=e,approximate=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approximate+b.approximate);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(PlaybackWide.From(-1),b.exact)),a.approximate-b.approximate);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approximate*b.approximate);}
            public float Store(){float f=exact.Store();return f==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximate)<0?0x80000000u:0):f;}
        }
        // @0x561e20. @confidence: M. Own state writes with actual55e4e0 and
        //5be2d0 composition; broader reset/clip resolution/feedback services.
        public static bool Request(BigJumpWorld world,uint identity,PcObjectImage actor,
            uint[] position,uint directed,float heightFactor,float speedFactor,byte mode)
        {
            if(world.ContextId31==-1)return false;
            if((world.Definitions[actor.U32(0x54)].U32(4)&0x200000)!=0)return false;
            world.Services.ResetActor(world,identity,actor);
            PathRelocation.ResetControls(world.Controls,actor);
            actor.Set8(0x7b4,mode);actor.Set8(0x7b5,world.ContextId31);actor.Set8(0x7b3,1);
            short animation=world.Services.SelectAnimation(world,identity,actor);actor.Set16(0x7aa,animation);
            float duration=world.Services.Duration(world,actor.I16(0x1064),animation);actor.SetFloat(0x784,duration);
            if(duration==0){actor.SetFloat(0x784,1);actor.Set16(0x7aa,world.FallbackAnimation);}
            else world.Services.InvalidateAnimation(world,identity,actor);
            actor.Set32(0x748,actor.U32(0x5c));
            actor.SetFloat(0x784,(new W(speedFactor)*new W(actor.F32(0x784))).Store());
            actor.Set32(0x74c,actor.U32(0x60));actor.Set32(0x77c,0);actor.Set32(0x750,actor.U32(0x64));
            if(position==null||position.Length!=3)throw new ArgumentException("Three prepared target words required.");
            for(int i=0;i<3;i++)actor.Set32(0x754+i*4,position[i]);
            actor.SetFloat(0x758,(new W(actor.F32(0x758))-new W(actor.F32(0xff0))*new W(actor.F32(0xa8))).Store());
            float dx=(new W(PcObjectImage.FromBits(position[0]))-new W(actor.F32(0x748))).Store();
            float dz=(new W(PcObjectImage.FromBits(position[2]))-new W(actor.F32(0x750))).Store();
            ushort angle=unchecked((ushort)PathAngles.Direction(dx,dz,world.AngleTable));
            actor.Set16(0x5a,angle);actor.Set16(0x58,angle);actor.Set16(0x27a,angle);
            uint flags=actor.U32(0xef0);actor.Set32(0xef0,flags^(((directed<<13)^flags)&0x2000));
            world.Services.Feedback(world,identity,actor,2);
            actor.Set32(0x4b0,actor.U32(0x4b0)|0x2000000);actor.SetFloat(0xf0c,heightFactor);actor.Set32(0x44c,0);
            if(heightFactor<0){actor.Set32(0x7bc,actor.U32(0x7bc)&0xfffffeff);actor.Set32(0xf0c,0);return true;}
            actor.Set32(0x7bc,actor.U32(0x7bc)&0xfffffeff);return true;
        }
        static string Text(string text){text=SceneryText.C(text);if(text==null)throw new ArgumentNullException("tokens");MessageNumbers.RequireAscii(text);return text;}
        static string Tail(string text,int at,int skip){if(at+skip>text.Length)throw new ArgumentException("Native fixed skip passes token terminator.");return text.Substring(at+skip);}
        static int Integer(float f)
        {if(float.IsNaN(f)||float.IsInfinity(f)||(double)f>=9223372036854775808.0||(double)f< -9223372036854775808.0)return 0;return unchecked((int)(long)f);}
        // @0x446450. @confidence: M. Assembly corrects decompiler void signature:
        //return1 except while actor context byte equals31. Actor selection supplied
        //from the original creature->reference->object chain; no actor means done.
        public static bool ToLocator(BigJumpWorld world,uint identity,PcObjectImage actor,
            LocatorPacket packet,string[] tokens,bool first)
        {
            if(actor==null)return true;float factor=1;bool personal=false,indexed=false;int random=0;string name=null;
            if(first)
            {
                packet.Active=packet.Selected;
                if(tokens.Length>0)
                {
                    foreach(string input in tokens)
                    {
                        string token=Text(input);int at=SceneryText.Index(token,"name");
                        if(at>=0)name=Tail(token,at,5);
                        else if(SceneryText.Index(token,"personal")>=0)personal=true;
                        else if(SceneryText.Index(token,"indexed")>=0)indexed=true;
                        else if((at=SceneryText.Index(token,"random"))>=0)random=Integer(MessageNumbers.Resolve(packet.Numbers,Tail(token,at,9)));
                        else if((at=SceneryText.Index(token,"jump_factor="))>=0)
                        {factor=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,12));if(factor<0)factor=0;}
                    }
                    if(name!=null)
                    {
                        var actorView=new LocatorActor{PersonalIndex=actor.I8(0x280)};
                        if(personal&&(!indexed||actor.I8(0x280)==-1)&&actor.U32(0x54)!=0)actorView.CharacterName=world.CharacterNames[actor.U32(0x54)];
                        string query=LocatorCommands.FormatName(world.Locators,actorView,name,indexed,personal,random);
                        if(world.Observe!=null)world.Observe("lookup",query);
                        packet.Active=world.Locators.Find(query);
                    }
                }
                LocatorRecord target=packet.Active;
                if(target!=null)
                {
                    uint[] position={PcObjectImage.ToBits(target.Position.X),PcObjectImage.ToBits(target.Position.Y),PcObjectImage.ToBits(target.Position.Z)};
                    Request(world,identity,actor,position,0,factor,1,0);
                    for(int i=0;i<6;i++)actor.Set32(0x420+i*4,target.Orientation[i]);
                    for(int i=0;i<3;i++)actor.Set32(0x438+i*4,position[i]);
                }
            }
            return actor.U8(0x7b5)!=31;
        }
    }
}
