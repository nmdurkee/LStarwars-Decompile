using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public abstract class PathRelocationServices
    {
        //5728a0 refreshes terrain-dependent actor state, including floor21c.
        public abstract void RefreshGround(PathRelocationWorld world,uint identity,PcObjectImage actor);
        //55e4a0 broader actor systems and4d1780 alternate placement remain boundaries.
        public abstract void ResetActor(PathRelocationWorld world,uint identity,PcObjectImage actor,int mode);
        public abstract int Alternate(PathRelocationWorld world,uint identity,PcObjectImage actor,ReinitializationRecord point);
    }
    public sealed class PathRelocationWorld
    {
        public LocatorView View;
        public uint LevelFlags,RandomState;
        public float Gate876ce4;
        public uint[] Origin93d620=new uint[3],Velocity93b0cc=new uint[3];
        public PathRelocationServices Services;
        public readonly Dictionary<uint,PcObjectImage> Actors=new Dictionary<uint,PcObjectImage>();
        public readonly Dictionary<uint,ReinitializationRecord> Records=new Dictionary<uint,ReinitializationRecord>();
    }
    public static class PathRelocation
    {
        const int S=0x6c4;
        static readonly float[] Identity={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
        struct W
        {
            PlaybackWide exact;double approximate;
            public W(float value){exact=PlaybackWide.From(value);approximate=value;}
            static W Make(PlaybackWide e,double a){return new W{exact=e,approximate=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approximate+b.approximate);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(PlaybackWide.From(-1),b.exact)),a.approximate-b.approximate);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approximate*b.approximate);}
            public float Store(){float v=exact.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximate)<0?0x80000000u:0):v;}
            public bool Nonnegative(){return exact.StoreDouble()>=0;}
        }
        static void Height(PcObjectImage actor,float height)
        {
            //Original double751788 is exactly the promoted float32 value0.1f.
            float value=(new W(height)-new W(actor.F32(0xff0))*new W(actor.F32(0xa8))+new W(.1f)).Store();
            actor.SetFloat(0x60,value);actor.SetFloat(0x9c,value);actor.SetFloat(0x84,value);
        }
        //0x572660. LevelFlags projects55f450()->world128->level64, reread per call.
        public static bool SnapFloor(PathRelocationWorld world,PcObjectImage actor,uint mode)
        {
            float floor=actor.F32(0x21c);
            if(floor==2000000||(world.LevelFlags&0x40000)!=0)return false;
            if(mode==2)Height(actor,actor.F32(0x17c));
            bool accept=mode==0||(new W(floor)+new W(.1f)-(new W(actor.F32(0xff0))*new W(actor.F32(0xa8))+new W(actor.F32(0x60)))).Nonnegative();
            if(accept)Height(actor,floor);
            actor.SetFloat(0x6c,-1);return accept;
        }
        //0x55e4e0 receives actor+6c4. This entry projects that subobject onto
        //the parent byte image; unlike the broader reset it clears pad bits14.
        public static void ResetControls(PathRelocationWorld world,PcObjectImage actor)
        {
            actor.Set32(S+0xfc,0);actor.Set8(S+0x100,255);
            actor.SetFloat(S+0x678,(actor.U8(S+0x75e)&1)!=0?1:0);actor.SetFloat(S+0x67c,5);actor.Set8(S+0xf1,255);
            foreach(int offset in new int[]{0x76f,0xf5,0xf4,0xee,0x76e})actor.Set8(S+offset,0);
            foreach(int offset in new int[]{0x66c,0x674,0x664,0x65c,0x648,0x694,0x698,0x670,0x6d0,0x6e8,0x700,0x714,0x720,0x724,0x60c})actor.Set32(S+offset,0);
            ReinitializationRecord pad=world.Records[actor.U32(S+0x5e0)];int flags=pad.U8(0x5a)|(pad.U8(0x5b)<<8);flags&=0xffeb;pad.Set8(0x5a,flags);pad.Set8(0x5b,flags>>8);
            actor.Set32(S+0x75c,actor.U32(S+0x75c)&~0x400u);
            world.RandomState=unchecked(world.RandomState*0x24cd+1)&65535;actor.Set8(S+0x77d,(int)(world.RandomState>>15));
            actor.Set16(S+0xe8,0);foreach(int offset in new int[]{0x74c,0x750,0x752})actor.Set16(S+offset,65535);
        }
        static void ClearPlacement(PcObjectImage actor)
        {actor.Set32(0x1090,0);actor.Set8(0x1086,0);actor.Set8(0x1087,0);actor.Set8(0x401,0);}
        //0x43c9a0. Node position begins at+4; original applies the identity
        //object transform before the prepared view transform and plane tests.
        public static bool Relocate(PathRelocationWorld world,uint identity,ReinitializationRecord point,uint mode)
        {
            PcObjectImage actor=world.Actors[identity];
            if((actor.U32(0x1f8)&0x400)!=0||(actor.U8(0x42e)&1)==0)return false;
            if(!(actor.F32(0xf10)>=1||(actor.U8(0x288)==0&&(actor.U8(0x7c5)&2)==0&&world.Gate876ce4>0)))return false;
            float radius=actor.F32(0x1e0);float[] center={point.F32(4),(new W(radius)+new W(point.F32(8))).Store(),point.F32(12)};
            if(!LocatorViewCulling.Outside(world.View,center,radius,Identity))return false;
            if(mode!=0){if(world.Services.Alternate(world,identity,actor,point)==0)return false;ClearPlacement(actor);return true;}
            PcObjectImage reference=world.Actors[actor.U32(0x398)];
            for(int i=0;i<3;i++)reference.Set32(0x5c+i*4,point.U32(4+i*4));
            for(int i=0;i<3;i++)actor.Set32(0x98+i*4,reference.U32(0x5c+i*4));
            for(int i=0;i<3;i++)actor.Set32(0x80+i*4,reference.U32(0x5c+i*4));
            for(int i=0;i<3;i++)world.Origin93d620[i]=actor.U32(0x80+i*4);
            for(int i=0;i<3;i++)actor.Set32(0x8c+i*4,actor.U32(0x80+i*4));
            for(int i=0;i<3;i++)actor.Set32(0x68+i*4,world.Velocity93b0cc[i]);
            world.Services.RefreshGround(world,identity,actor);SnapFloor(world,actor,0);ClearPlacement(actor);
            if(actor.U32(0xcd0)==0){world.Services.ResetActor(world,identity,actor,0);ResetControls(world,actor);}
            return true;
        }
    }
}
