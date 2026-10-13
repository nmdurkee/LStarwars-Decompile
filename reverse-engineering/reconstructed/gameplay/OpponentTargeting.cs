// Original-PC opponent assignment, distance band and player obstruction helpers.
// Attached fields expose offsets without inferring the producer of their values.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public struct OpponentVector
    {
        public float X,Y,Z;
        public OpponentVector(float x,float y,float z){X=x;Y=y;Z=z;}
    }
    public sealed class OpponentFields
    {
        public OpponentVector Origin80;
        public float Radius1dc;
        public uint FlagsEf4;
        public byte AssignedPlayer1084=255;
        public sbyte PersonalIndex280=-1;
        public ActorStateRecord Reference3ac;
    }
    public sealed class OpponentWorld
    {
        public ActorStateWorld Actors;
        public readonly Dictionary<ActorStateRecord,OpponentFields> Fields=new Dictionary<ActorStateRecord,OpponentFields>();
        // Nine rows of seventeen actor references: native entry stride is 8 bytes.
        public readonly ActorStateRecord[][] AttackerRows=new ActorStateRecord[9][];
        public int UnassignedPerBand=32;
        public float BandStep=.75f,BandBase=.75f;
        public OpponentFields State(ActorStateRecord a){return Fields[a];}
    }
    public static class OpponentTargeting
    {
        static float F(double d){return MessageNumbers.Round((float)d);}
        static OpponentVector Difference(OpponentVector a,OpponentVector b)
        {return new OpponentVector(F((double)a.X-b.X),F((double)a.Y-b.Y),F((double)a.Z-b.Z));}
        static float Squared(OpponentVector d){return FiniteX87.Dot3PlusConstant(d.X,d.Y,d.Z,d.X,d.Y,d.Z,0);}

        // 0x43d410. The assigned slot only restricts actors with ef4 bit 0x2000.
        public static bool AssignedTargetAllowed(OpponentWorld w,ActorStateRecord own,ActorStateRecord target)
        {
            if(own==null)return false;
            OpponentFields s=w.State(own);if((s.FlagsEf4&0x2000)==0)return true;
            int i=s.AssignedPlayer1084;if(i==255)return false;
            if(i>=8)throw new ArgumentOutOfRangeException("AssignedPlayer1084","Native caller must supply a valid player slot or 255.");
            return Object.ReferenceEquals(w.Actors.Players[i],target);
        }

        // 0x43d450. Table generation and the meaning of personal indices are supplied.
        public static float PreferredRange(OpponentWorld w,ActorStateRecord own)
        {
            int row=w.State(w.State(own).Reference3ac).PersonalIndex280;
            if(row<0||row>8)return .75f;
            ActorStateRecord[] entries=w.AttackerRows[row];if(entries==null||entries.Length<17)throw new ArgumentException("Seventeen attacker entries required.");
            int unassigned=0,band=0;
            for(int i=0;i<17&&entries[i]!=null;i++)
            {
                if(Object.ReferenceEquals(entries[i],own))return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(band),PlaybackWide.From(w.BandStep)),PlaybackWide.From(w.BandBase)).Store();
                if(w.State(entries[i]).AssignedPlayer1084==255)++unassigned;
                if(unassigned>=w.UnassignedPerBand){++band;unassigned=0;}
            }
            return w.BandBase;
        }

        // 0x551730. Direction is accepted as supplied; caller normally normalizes it.
        // Float stores are deliberate: dot, squared distance, dot squared, residual.
        public static bool RaySphere(OpponentVector origin,OpponentVector direction,OpponentVector center,float radiusSquared,ref float output)
        {
            OpponentVector d=Difference(center,origin);
            float dot=FiniteX87.Dot3PlusConstant(d.Y,d.X,d.Z,direction.Y,direction.X,direction.Z,0);
            if(dot<0)return false;
            float squared=FiniteX87.Dot3PlusConstant(d.Z,d.X,d.Y,d.Z,d.X,d.Y,0);
            float residual=F((double)squared-F((double)dot*dot));
            if(residual>radiusSquared)return false;
            output=residual;return true;
        }

        // 0x440150. Only the eight player references can obstruct this firing ray.
        public static bool PlayerObstructs(OpponentWorld w,ActorStateRecord own,ActorStateRecord target)
        {
            if((own.Flags1f8&5)!=0)return false;
            OpponentVector origin=w.State(own).Origin80,delta=Difference(w.State(target).Origin80,origin);
            float distance=Squared(delta),length=F(Math.Sqrt(distance)),scale=length==0?0:F(1.0/length);
            OpponentVector direction=new OpponentVector(F((double)delta.X*scale),F((double)delta.Y*scale),F((double)delta.Z*scale));
            for(int i=0;i<8;i++)
            {
                ActorStateRecord candidate=w.Actors.Players[i];
                if(candidate==null||(candidate.Flags1fc&0x1001)!=0x1001||Object.ReferenceEquals(candidate,own)||Object.ReferenceEquals(candidate,target))continue;
                OpponentFields state=w.State(candidate);
                if(Squared(Difference(origin,state.Origin80))>=distance)continue;
                float radius=F((double)state.Radius1dc+.125),unused=0;
                if(RaySphere(origin,direction,state.Origin80,F((double)radius*radius),ref unused))return true;
            }
            return false;
        }
    }
}
