// Recovered PC spawn reinitialization. Raw records preserve unknown fields;
// external lifecycle services remain explicit and are not silently simulated.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public enum ReinitializationOperation
    {
        BeforeReset, ResetActor, ResetMoves, ClearRuntimeSystems, ResetMovementContext,
        StartAccessory, ResetTerrain, ClearTerrain, BindPath, BindScript, ResetState,
        SetAnimation, CommitAnimation, AssignRoom
    }
    public abstract class ActorReinitializationServices
    {
        // Arguments retain PC scalar/reference IDs, not managed/native pointers.
        // Implementations may change the actor/world: caller read order matters.
        public abstract void Invoke(ReinitializationOperation operation, ActorReinitializationWorld world,
            PcObjectImage actor, params uint[] arguments);
    }
    public sealed class ReinitializationRecord
    {
        public readonly byte[] Bytes;
        public readonly uint Identity;
        public ReinitializationRecord(uint identity,byte[] bytes)
        {if(bytes==null)throw new ArgumentNullException("bytes");Identity=identity;Bytes=(byte[])bytes.Clone();}
        public byte U8(int p){return Bytes[p];}
        public uint U32(int p){return (uint)(Bytes[p]|Bytes[p+1]<<8|Bytes[p+2]<<16|Bytes[p+3]<<24);}
        public float F32(int p){return PcObjectImage.FromBits(U32(p));}
        public void Set8(int p,int v){Bytes[p]=(byte)v;}
        public void Set32(int p,uint v){for(int i=0;i<4;i++)Bytes[p+i]=(byte)(v>>(i*8));}
    }
    public sealed class ReinitializationCharacter
    {
        public uint Flags04, Callback18;
        public short AccessoryE8=-1;
        public byte AccessoryMagnitude11e, TuningF4, TuningF5;
    }
    public sealed class ReinitializationPathSet
    {
        // Native count is a byte; rows are original paired32-bit masks.
        public ulong[] MembershipMasks=new ulong[0];
    }
    public sealed class ActorReinitializationWorld
    {
        public ActorReinitializationServices Services;
        public uint ActorIdentity, ScriptSystemIdentity, SceneIdentity;
        public float[] Sine;
        public readonly uint[] ResetVector=new uint[3], LastSpawnOrigin=new uint[3];
        public ReinitializationRecord[] Spawns;
        public readonly Dictionary<uint,ReinitializationRecord> Locators=new Dictionary<uint,ReinitializationRecord>();
        public readonly Dictionary<uint,ReinitializationRecord> Formations=new Dictionary<uint,ReinitializationRecord>();
        public readonly Dictionary<uint,ReinitializationCharacter> Characters=new Dictionary<uint,ReinitializationCharacter>();
        public readonly Dictionary<uint,bool> ModelHasAnimation65=new Dictionary<uint,bool>();
        public readonly Dictionary<uint,ReinitializationPathSet> PathSets=new Dictionary<uint,ReinitializationPathSet>();
    }
    public static class ActorReinitialization
    {
        static void Call(ActorReinitializationWorld w,PcObjectImage a,ReinitializationOperation op,params uint[] args)
        {if(w.Services==null)throw new ArgumentException("Explicit lifecycle services required.");w.Services.Invoke(op,w,a,args);}
        static void CopyVector(PcObjectImage a,int target,int source)
        {for(int i=0;i<3;i++)a.Set32(target+4*i,a.U32(source+4*i));}
        static float Mul(float a,float b){if(a==0||b==0)return PcObjectImage.FromBits((PcObjectImage.ToBits(a)^PcObjectImage.ToBits(b))&0x80000000u);return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static float Sum(float a,float b){if(a==0&&b==0)return PcObjectImage.FromBits(PcObjectImage.ToBits(a)&PcObjectImage.ToBits(b)&0x80000000u);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static float ProductSum(float a,float b,float c,float d)
        {if((a==0||b==0)&&(c==0||d==0))return Sum(Mul(a,b),Mul(c,d));return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(d))).Store();}
        static float Negate(float f){return PcObjectImage.FromBits(PcObjectImage.ToBits(f)^0x80000000u);}
        static uint ShiftLow32(int count){count&=255;return count<32?1u<<count:0;}
        static void SineRequired(float[] sine){if(sine==null||sine.Length!=32768)throw new ArgumentException("Original32768-entry sine table required.");}

        //0x5b3710: scaled horizontal direction, not a matrix builder.
        public static float[] Direction(float speed,uint angle,float[] sine)
        {SineRequired(sine);return new float[]{Mul(speed,sine[(int)((angle>>1)&32767)]),0,Mul(speed,sine[(int)(((angle+16384u)>>1)&32767)])};}

        //0x4b6b80; only547cb0 accessory construction/activation remains a service.
        public static void ResetAccessory(ActorReinitializationWorld w,PcObjectImage a)
        {
            a.Set8(0x1085,0);ReinitializationCharacter c=w.Characters[a.U32(0x54)];
            if(c.AccessoryE8!=-1)Call(w,a,ReinitializationOperation.StartAccessory,w.ActorIdentity,unchecked((uint)c.AccessoryE8),PcObjectImage.ToBits((float)c.AccessoryMagnitude11e));
            c=w.Characters[a.U32(0x54)];
            if(c.Callback18!=0x4b5120 && a.U16(0xe1c)!=0 && (a.U32(0xe24)&0x2000)==0)a.Set16(0xe1c,0);
        }

        //0x51a7c0 on the embedded creature at actor+2c8. Equal identity is a no-op.
        public static void BindPathSet(ActorReinitializationWorld w,PcObjectImage a,uint identity)
        {
            const int p=0x2c8;if(a.U32(p+0x158)==identity)return;
            foreach(int at in new int[]{0x15c,0x160,0x164,0x168,0x16c,0x17c})a.Set32(p+at,0);
            a.Set32(p+0x158,identity);a.Set8(p+0x161,255);a.Set16(p+0x13a,0);a.Set16(p+0x124,65535);a.Set8(p+0x13c,255);a.Set8(p+0x13d,0);
            if(identity==0)return;
            ulong[] masks=w.PathSets[identity].MembershipMasks;if(masks.Length>255)throw new ArgumentException("Native path count is a byte.");
            ulong member=a.U32(p+0x130)|((ulong)a.U32(p+0x134)<<32);
            for(int i=0;i<masks.Length;i++)if((member&masks[i])!=0)a.Set16(p+0x13a,a.U16(p+0x13a)|(int)(ShiftLow32(i)&65535));
        }

        //0x41c120 complete caller flow. Downstream runtime effects are explicit
        // services; this does not reconstruct allocation or every reset callee.
        public static void Reinitialize(ActorReinitializationWorld w,PcObjectImage a,bool systemPresent)
        {
            if(a==null)return;
            uint id=w.ActorIdentity;
            Call(w,a,ReinitializationOperation.BeforeReset,id);ResetAccessory(w,a);
            if(!systemPresent)return;
            Call(w,a,ReinitializationOperation.ResetActor,id);
            Call(w,a,ReinitializationOperation.ResetMoves,id);
            Call(w,a,ReinitializationOperation.ClearRuntimeSystems,id,1);
            Call(w,a,ReinitializationOperation.ResetMovementContext,id+0x6c4);
            ReinitializationCharacter c=w.Characters[a.U32(0x54)];
            a.Set8(0x107e,c.TuningF4);a.Set8(0x107f,c.TuningF4);a.Set8(0xe38,c.TuningF5);a.Set8(0xe39,4);
            ReinitializationRecord spawn=w.Spawns[a.U8(0x400)];
            a.Set8(0x378,spawn.U8(0x4c));a.Set32(0x4b0,((a.U32(0x4b0)&~0x80u)|((spawn.U8(0x48)&1)!=0?0x80u:0))&~0x40000u);
            for(int i=0;i<4;i++)a.Set32(0x230+i*4,spawn.U32(0x94+i*4));
            float x=Mul((float)((a.U8(0x411)+1)/2),spawn.F32(0x5c));
            if((a.U8(0x411)&1)!=0)x=Negate(x);
            float z=Mul((float)a.U8(0x412),Negate(spawn.F32(0x60)));
            ReinitializationRecord basis=spawn;int position=0x20,heading=0x2c,path=0x30;
            bool fromLocator=a.U32(0x4c4)!=0&&a.U32(0x478)!=0;
            if(fromLocator){basis=w.Locators[a.U32(0x478)];position=0x10;heading=0x1c;path=0x20;}
            uint angle=basis.U32(heading);SineRequired(w.Sine);
            float sin=w.Sine[(int)((angle>>1)&32767)],cos=w.Sine[(int)(((angle+16384u)>>1)&32767)];
            // Actual5b3620 order, with64-significand x87 intermediates.
            float rx=ProductSum(sin,z,cos,x),rz=ProductSum(z,cos,Negate(x),sin);
            a.SetFloat(0x5c,Sum(rx,basis.F32(position)));a.SetFloat(0x60,Sum(0,basis.F32(position+4)));a.SetFloat(0x64,Sum(rz,basis.F32(position+8)));
            if(fromLocator)a.Set32(0x478,0);
            CopyVector(a,0x80,0x5c);CopyVector(a,0x98,0x5c);
            for(int i=0;i<3;i++)w.LastSpawnOrigin[i]=a.U32(0x80+i*4);
            CopyVector(a,0x8c,0x80);
            for(int i=0;i<3;i++){a.Set32(0xdf8+i*4,w.ResetVector[i]);a.Set32(0x68+i*4,w.ResetVector[i]);}
            Call(w,a,ReinitializationOperation.ResetTerrain,id);Call(w,a,ReinitializationOperation.ClearTerrain,id,0);
            a.Set16(0x27a,(int)angle);a.Set16(0x58,(int)angle);a.Set16(0x5a,(int)angle);
            float[] facing=Direction(1,angle&65535,w.Sine);for(int i=0;i<3;i++)a.SetFloat(0xf30+4*i,facing[i]);
            uint creature=id+0x2c8;BindPathSet(w,a,basis.U32(path));
            Call(w,a,ReinitializationOperation.BindPath,creature,id+0x5c,basis.U32(path+4),basis.U8(path+8));
            a.Set8(0x28b,0);
            Call(w,a,ReinitializationOperation.BindScript,w.ScriptSystemIdentity,creature,creature,spawn.Identity,spawn.Identity+0x10,0,1,0,0);
            a.Set16(0x3ec,65535);a.Set8(0x404,255);a.Set8(0x405,0);
            Call(w,a,ReinitializationOperation.ResetState,w.ScriptSystemIdentity,id,creature,255,unchecked((uint)a.I8(0x281)));
            Call(w,a,ReinitializationOperation.SetAnimation,id+8,1);Call(w,a,ReinitializationOperation.CommitAnimation,a.U32(0x50),id+8);
            a.Set32(0x3d8,0);a.Set32(0x1090,0);a.Set32(0x4b0,a.U32(0x4b0)&~0x1000000u);CopyVector(a,0x3cc,0x5c);
            a.Set32(0x44c,0);a.Set8(0x1086,0);a.Set8(0x1087,0);
            Call(w,a,ReinitializationOperation.AssignRoom,id,1,1,0xffffffff,w.SceneIdentity);
            uint formation=a.U32(0x40c);a.Set32(0x1fc,a.U32(0x1fc)|0x1000u);a.Set32(0x4c4,unchecked(a.U32(0x4c4)+1));a.Set8(0x406,2);
            if(formation!=0)
            {
                ReinitializationRecord group=w.Formations[formation];group.Set32(0x4c,group.U32(0x4c)|ShiftLow32(a.U8(0x410)));
                int row=0x54+0x34*a.U8(0x412);
                group.Set8(row+0x2d,group.U8(row+0x2d)|(int)(ShiftLow32(a.U8(0x410)-a.U8(0x412)*spawn.U8(0x51))&255));
                if(a.U8(0x411)==0)
                {
                    for(int i=0;i<3;i++)group.Set32(row+0x18+i*4,a.U32(0x5c+i*4));
                    for(int i=0;i<6;i++)group.Set32(row+i*4,a.U32(0x420+i*4));
                    group.Set32(row+0x24,a.U16(0x27a));group.Set32(row+0x28,0);group.Set32(row+0x30,group.U32(row+0x30)&~2u);
                }
            }
            CopyVector(a,0x1b4,0x5c);CopyVector(a,0x10bc,0x5c);
            if((w.Characters[a.U32(0x54)].Flags04&0x20000000)!=0&&w.ModelHasAnimation65[a.U32(0x50)])
            {a.Set32(0x77c,0x4e6e6b28);a.Set8(0x7b5,0x17);a.Set16(0x7aa,0x41);Call(w,a,ReinitializationOperation.SetAnimation,id+8,0x41);}
        }
    }
}
