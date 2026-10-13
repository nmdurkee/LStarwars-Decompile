using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public abstract class TerrainActorServices
    {
        //5506f0 receives actor, actor+5c, range5, maskffffffff. The service
        //may update the result globals represented by TerrainActorWorld.
        public abstract float Query(TerrainActorWorld world,uint identity,PcObjectImage actor,float range,uint mask);
        //553500 receives actor+5c; its internal terrain query is not recovered here.
        public abstract float SecondaryHeight(TerrainActorWorld world,uint identity,PcObjectImage actor);
    }
    public sealed class TerrainActorWorld
    {
        //Nullable metadata pointers292fbf0/292fd44/292182c. The fields consumed
        //here are ground+60, upper+61 and lower+60; no semantic names guessed.
        public ReinitializationRecord GroundMetadata,UpperMetadata,LowerMetadata;
        //Projects292fc68 -> record base, with record stride38 and index2961fdc.
        public ReinitializationRecord[] ObjectRecords;
        public int ObjectIndex;
        public byte[] MaterialFlags=new byte[32];
        public float UpperHeight,LowerHeight;
        public float[] DefaultNormal,GroundNormal,UpperNormal,Sine;
        public ushort[] AngleTable;
        public ushort FirstAngle92b0c4,SecondAngle92b0c0;
        public uint Mode951288,Mode951154,Mask8034c4,Mask95100c;
        public readonly Dictionary<uint,ReinitializationRecord> Records=new Dictionary<uint,ReinitializationRecord>();
        public TerrainActorServices Services;
        public Action<TerrainActorWorld,uint,PcObjectImage> Callback951010;
    }
    public static class TerrainActorState
    {
        public const float NoHeight=2000000;
        struct W
        {
            PlaybackWide value;double approximate;
            public W(float v){value=PlaybackWide.From(v);approximate=v;}
            static W Make(PlaybackWide v,double a){return new W{value=v,approximate=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.value,b.value),a.approximate+b.approximate);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.value,PlaybackWide.Multiply(PlaybackWide.From(-1),b.value)),a.approximate-b.approximate);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.value,b.value),a.approximate*b.approximate);}
            public float Store(){float v=value.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximate)<0?0x80000000u:0):v;}
        }
        //0x67a600,0x67a670,0x67a690: return full-width-1 for a null pointer,
        //otherwise a zero-extended byte. Clamp/masking belongs to their caller.
        public static int GroundMetadata(TerrainActorWorld world){return world.GroundMetadata==null?-1:world.GroundMetadata.U8(0x60);}
        public static int UpperMetadata(TerrainActorWorld world){return world.UpperMetadata==null?-1:world.UpperMetadata.U8(0x61);}
        public static int LowerMetadata(TerrainActorWorld world){return world.LowerMetadata==null?-1:world.LowerMetadata.U8(0x60);}
        //0x67a6e0. Other than index-1 the original does not bounds-check.
        public static int ObjectId(TerrainActorWorld world)
        {
            if(world.ObjectRecords==null||world.ObjectIndex==-1)return -1;
            ReinitializationRecord r=world.ObjectRecords[world.ObjectIndex];
            return r.U32(0x2c)==1?unchecked((short)(r.U8(0x30)|(r.U8(0x31)<<8))):-1;
        }
        //0x5b35a0. In-place destination==source is supported. Angles index the
        //original32768-float table; products/sums retain x87 precision.
        public static void RotateX(float[] destination,float[] source,int angle,float[] sine)
        {
            float y=source[1];W c=new W(sine[((angle+16384)>>1)&32767]),s=new W(sine[(angle>>1)&32767]);
            destination[0]=source[0];destination[1]=(c*new W(y)-s*new W(source[2])).Store();destination[2]=(new W(y)*s+c*new W(source[2])).Store();
        }
        //0x54fec0. Optional one-word outputs must not overlap vector backing.
        //First global/output is written before rotation, second after it.
        public static void NormalAngles(TerrainActorWorld world,float[] vector,ushort[] first,ushort[] second)
        {
            world.FirstAngle92b0c4=unchecked((ushort)PathAngles.Direction(vector[2],vector[1],world.AngleTable));
            if(first!=null)first[0]=world.FirstAngle92b0c4;
            float[] rotated=new float[3];RotateX(rotated,vector,-(int)world.FirstAngle92b0c4,world.Sine);
            ushort angle=unchecked((ushort)-PathAngles.Direction(rotated[0],rotated[1],world.AngleTable));
            if(second!=null)second[0]=angle;world.SecondAngle92b0c0=angle;
        }
        static uint CharacterFlags(TerrainActorWorld world,PcObjectImage actor)
        {return world.Records[world.Records[actor.U32(0x54)].U32(0x24)].U32(0x90);}
        static void CopyNormal(PcObjectImage actor,float[] vector)
        {for(int i=0;i<3;i++)actor.SetFloat(0xf24+i*4,vector[i]);}
        static void Callback(TerrainActorWorld world,uint identity,PcObjectImage actor)
        {if(world.Callback951010!=null)world.Callback951010(world,identity,actor);}
        //0x572440. The supplied height decides contact state; actor21c
        //independently selects the normal. publish==0 skips only normal/byte writes.
        public static void Apply(TerrainActorWorld world,uint identity,PcObjectImage actor,int publish,float height)
        {
            int raw,material;
            if(height==NoHeight){raw=material=0;actor.SetFloat(0x1014,NoHeight);actor.Set8(0x107b,0);actor.Set16(0x106c,65535);}
            else
            {
                raw=GroundMetadata(world);material=raw>=0&&raw<32?raw:0;actor.Set8(0x107b,2);
                actor.SetFloat(0x1014,(CharacterFlags(world,actor)&0x8000)==0&&(world.MaterialFlags[material]&2)!=0?height:NoHeight);
                actor.Set16(0x106c,ObjectId(world));
            }
            if(publish!=0){actor.Set8(0xe42,raw);actor.Set8(0x285,material);CopyNormal(actor,actor.F32(0x21c)==NoHeight?world.DefaultNormal:world.GroundNormal);}
            actor.SetFloat(0x220,world.UpperHeight);bool valid=actor.F32(0x220)!=NoHeight;
            if(valid)
            {
                byte type=unchecked((byte)UpperMetadata(world));actor.Set8(0x283,type);
                if(world.Mode951288!=0&&world.Mode951154!=0&&(type==7||type==16)){actor.SetFloat(0x220,NoHeight);valid=false;}
                else
                {
                    if(type>16)type=0;
                    actor.Set8(0x283,type&~(int)(world.Mask8034c4|world.Mask95100c|0x40));
                    NormalAngles(world,world.UpperNormal,null,null);actor.Set16(0x105c,world.FirstAngle92b0c4);actor.Set16(0x105e,world.SecondAngle92b0c0);
                }
            }
            if(!valid){actor.Set16(0x105e,0);actor.Set16(0x105c,0);actor.Set8(0x283,255);}
            actor.SetFloat(0x224,world.LowerHeight);
            if(actor.F32(0x224)==NoHeight)actor.Set8(0x284,255);
            else{byte type=unchecked((byte)LowerMetadata(world));actor.Set8(0x284,type<32?type:0);}
            Callback(world,identity,actor);
        }
        //0x5728a0. Apply executes twice, then the callback executes again.
        //Callbacks may change fields used by later guards; do not cache them.
        public static void Refresh(TerrainActorWorld world,uint identity,PcObjectImage actor)
        {
            float height=world.Services.Query(world,identity,actor,5,0xffffffff);actor.SetFloat(0x21c,height);
            if(height==NoHeight)
            {Apply(world,identity,actor,0,height);actor.SetFloat(0xd6c,0);actor.Set8(0x285,0);actor.Set8(0xe42,0);CopyNormal(actor,world.DefaultNormal);}
            else
            {
                Apply(world,identity,actor,1,height);actor.SetFloat(0xd6c,(world.MaterialFlags[actor.I8(0x285)]&8)!=0?1:0);
                NormalAngles(world,new float[]{actor.F32(0xf24),actor.F32(0xf28),actor.F32(0xf2c)},null,null);
                actor.Set16(0x1056,world.FirstAngle92b0c4);actor.Set16(0x1052,world.FirstAngle92b0c4);actor.Set16(0x1058,world.SecondAngle92b0c0);actor.Set16(0x1054,world.SecondAngle92b0c0);
            }
            byte type=actor.U8(0x283);float upper=actor.F32(0x220);bool eligible=type==1||type==9;
            actor.Set8(0x286,eligible&&upper>=actor.F32(0x84)?1:0);actor.Set8(0x287,eligible&&upper<=actor.F32(0x188)&&actor.F32(0x17c)<=upper?1:0);
            actor.SetFloat(0x220,NoHeight);actor.SetFloat(0x224,NoHeight);actor.Set8(0x283,255);actor.Set8(0x284,255);
            Apply(world,identity,actor,1,actor.F32(0x21c));
            if((CharacterFlags(world,actor)&0x8000)==0&&actor.F32(0x1014)==NoHeight&&actor.I16(0x106c)!=-1)
            {height=world.Services.SecondaryHeight(world,identity,actor);if(height!=NoHeight){actor.SetFloat(0x1014,height);actor.Set8(0x107b,2);}}
            Callback(world,identity,actor);
        }
    }
}
