using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class FacingPoint { public SpawnVector Position; }
    public sealed class FacingPacket
    {
        public LocatorPacket Shared=new LocatorPacket();
        public ushort Angle;
        public float Offset;
    }
    public sealed class FacingLookRequest
    {
        public FacingPoint Target;
        public SpawnVector CachedPosition;
        public sbyte Priority;
        public float Duration, Delay;
    }
    public sealed class FacingWorld
    {
        public MovementWorld World;
        public LocatorActor PrimaryPlayer,NearestOpponent;
        // PC0x5d6170 always returns the fixed camera record, rather than null.
        public FacingPoint Camera;
        public float[] SineTable;
        public QRandom Random;
        public readonly Dictionary<LocatorActor,FacingPoint> CameraLookPoints=new Dictionary<LocatorActor,FacingPoint>();
        public readonly Dictionary<LocatorActor,FacingLookRequest> LookRequests=new Dictionary<LocatorActor,FacingLookRequest>();
        // Native actor+0x2c8 creature storage aliases its look pointer at+0x4ac.
        // The loader supplies this relation explicitly when records are attached.
        public readonly Dictionary<LocatorCreature,LocatorActor> EmbeddedCreatureOwners=new Dictionary<LocatorCreature,LocatorActor>();
    }
    public static class FacingMath
    {
        static float R(double v){return MessageNumbers.Round((float)v);}
        public static SpawnVector Normalize(SpawnVector v)
        {
            float length=R(Math.Sqrt(R((double)v.X*v.X+(double)v.Y*v.Y+(double)v.Z*v.Z)));
            float reciprocal=length<=0?0:R(1.0/length);
            return new SpawnVector(R((double)reciprocal*v.X),R((double)reciprocal*v.Y),R((double)reciprocal*v.Z));
        }
        public static SpawnVector RotateY(SpawnVector v,ushort angle,float[] sine)
        {
            if(sine==null||sine.Length<32768)throw new ArgumentException("Complete native sine table required.");
            float s=sine[(angle>>1)&32767],c=sine[((angle+16384)>>1)&32767];
            return new SpawnVector(R((double)s*v.Z+(double)c*v.X),v.Y,R((double)v.Z*c-(double)v.X*s));
        }
    }
    public static class FacingCommands
    {
        static float R(double v){return MessageNumbers.Round((float)v);}
        static bool Match(string token,string key,out int at){at=token.IndexOf(key,StringComparison.OrdinalIgnoreCase);return at>=0;}
        static bool Eq(string a,string b){return String.Equals(a,b,StringComparison.OrdinalIgnoreCase);}
        static string Tail(string text,int at,int count){if(at+count>text.Length)throw new ArgumentException("Native token skip crosses terminator.");return text.Substring(at+count);}
        static float Eval(FacingWorld w,FacingPacket p,LocatorCreature c,string t){return w.World.Movement.Evaluate(c,p.Shared,t);}
        static bool Timed(FacingPacket p,float delta)
        {if(p.Shared.Wait>0){p.Shared.Wait=R((double)p.Shared.Wait-delta);if(p.Shared.Wait<=0){p.Shared.Wait=0;return true;}}return false;}
        static void RandomWait(FacingWorld w,FacingPacket p,float min,float max)
        {if(p.Shared.Wait==0&&min<max)p.Shared.Wait=R((double)w.World.Movement.NextFloat()*((double)max-min)+min);}

        // Actual registered callback0x43c0c0; caller owns the mode-byte storage.
        public static bool MovementToken(string token,ref byte mode)
        {MessageNumbers.RequireAscii(token);if(Eq(token,"RUN")){mode=0;return true;}if(Eq(token,"WALK")){mode=1;return true;}if(Eq(token,"TIPTOE")){mode=2;return true;}return false;}

        public static bool FacePlayer(FacingWorld w,FacingPacket p,LocatorCreature c,string[] tokens,bool first,float delta)
        {
            if(c==null)return true;
            if(first){float min=0,max=0;if(tokens!=null)foreach(string t in tokens){int a;MessageNumbers.RequireAscii(t);if(Match(t,"mintime",out a))min=Eval(w,p,c,Tail(t,a,8));else if(Match(t,"maxtime",out a))max=Eval(w,p,c,Tail(t,a,8));else p.Shared.Wait=Eval(w,p,c,t);}RandomWait(w,p,min,max);}
            if(w.PrimaryPlayer!=null)c.LookTarget=w.PrimaryPlayer;
            return Timed(p,delta);
        }
        public static bool FaceCharacter(FacingWorld w,FacingPacket p,LocatorCreature c,string[] tokens,bool first,float delta)
        {
            if(first&&tokens!=null)foreach(string t in tokens)
            {int a;MessageNumbers.RequireAscii(t);if(Match(t,"character=",out a)){LocatorActor reference=w.World.ResolveReference==null?null:w.World.ResolveReference(Tail(t,a,10));p.Shared.FollowTarget=reference==null?null:reference.WorldObject;}else p.Shared.Wait=MessageNumbers.Resolve(p.Shared.Numbers,t);}
            if(c!=null&&p.Shared.FollowTarget!=null)c.LookTarget=p.Shared.FollowTarget;
            return Timed(p,delta);
        }
        public static bool FaceOpponent(FacingWorld w,FacingPacket p,LocatorCreature c,string[] tokens,bool first,float delta)
        {
            if(c==null)return true;
            if(first)
            {
                float min=0,max=0;
                if(tokens!=null)foreach(string t in tokens)
                {MessageNumbers.RequireAscii(t);if(w.World.Movement.MovementToken(c,t))continue;int a;if(Match(t,"mintime",out a))min=Eval(w,p,c,Tail(t,a,8));else if(Match(t,"maxtime",out a))max=Eval(w,p,c,Tail(t,a,8));else if(Match(t,"faceoffset",out a))p.Offset=Eval(w,p,c,Tail(t,a,11));else if(Eq(t,"nearest_opponent"))p.Shared.Flags=1;else p.Shared.Wait=Eval(w,p,c,t);}
                RandomWait(w,p,min,max);
            }
            LocatorActor opponent=p.Shared.Flags==0?c.Opponent:w.NearestOpponent;
            if(opponent!=null&&opponent.Controller!=null)
            {
                if(p.Offset==0)c.LookTarget=opponent;
                else
                {
                    if(c.Reference==null)throw new InvalidOperationException("Offset facing requires the creature reference.");
                    SpawnVector a=opponent.Position,b=c.Reference.Position,side=FacingMath.Normalize(new SpawnVector(R((double)a.Z-b.Z),0,R((double)b.X-a.X)));
                    p.Shared.FacingPoint=new SpawnVector(R((double)p.Offset*side.X+a.X),a.Y,R((double)p.Offset*side.Z+a.Z));c.LookTarget=p.Shared;
                }
            }
            return Timed(p,delta);
        }
        public static bool FaceCamera(FacingWorld w,FacingPacket p,LocatorCreature c,string[] tokens,bool first,float delta)
        {
            if(c==null||c.Reference==null||c.Reference.WorldObject==null)return true;
            LocatorActor actor=c.Reference.WorldObject;
            if(first)
            {float min=0,max=0;if(tokens!=null)foreach(string t in tokens){int a;MessageNumbers.RequireAscii(t);if(Eq(t,"look_at_camera"))p.Shared.Flags=1;else if(Match(t,"mintime",out a))min=Eval(w,p,c,Tail(t,a,8));else if(Match(t,"maxtime",out a))max=Eval(w,p,c,Tail(t,a,8));else p.Shared.Wait=MessageNumbers.Resolve(p.Shared.Numbers,t);}RandomWait(w,p,min,max);}
            if(w.Camera==null)throw new InvalidOperationException("Native fixed camera projection is required.");
            c.LookTarget=w.Camera;
            if(p.Shared.Flags!=0)
            {FacingPoint target;LocatorActor owner;if(w.EmbeddedCreatureOwners.TryGetValue(c,out owner)&&Object.ReferenceEquals(owner,actor))target=w.Camera;else w.CameraLookPoints.TryGetValue(actor,out target);FacingLookRequest request;if(!w.LookRequests.TryGetValue(actor,out request))throw new InvalidOperationException("Missing actor look-request record.");RequestLook(request,target,6,1,0,0,w.Random);}
            return Timed(p,delta);
        }
        public static bool FaceLocator(FacingWorld w,FacingPacket p,LocatorCreature c,string[] tokens,bool first)
        {
            if(c==null||c.Reference==null||c.Reference.WorldObject==null||c.Path==null||c.Node==null)return true;
            if(first)
            {p.Shared.Active=p.Shared.Selected;if(tokens!=null)for(int i=0;i<tokens.Length;i++){string t=tokens[i];MessageNumbers.RequireAscii(t);if(w.World.Movement.MovementToken(c,t))continue;int a;if(Match(t,"name",out a)){p.Shared.Active=w.World.Find(Tail(t,a,5));++i;}}}
            if(p.Shared.Active==null)return false;c.LookTarget=p.Shared.Active;return true;
        }
        public static bool SpinOnSpot(FacingWorld w,FacingPacket p,LocatorCreature c,string[] tokens,bool first,float delta)
        {
            if(c==null||c.Reference==null||c.Reference.WorldObject==null)return true;
            LocatorActor actor=c.Reference.WorldObject;
            if(first)
            {
                float min=0,max=0;if(tokens!=null)foreach(string t in tokens)
                {int a;MessageNumbers.RequireAscii(t);if(Match(t,"mintime=",out a))min=Eval(w,p,c,Tail(t,a,8));else if(Match(t,"maxtime=",out a))max=Eval(w,p,c,Tail(t,a,8));else if(Match(t,"time=",out a))p.Shared.Wait=Eval(w,p,c,Tail(t,a,5));else if(Match(t,"rot_rate=",out a)){double value=Eval(w,p,c,Tail(t,a,9))*182.04444885253906;if(Double.IsNaN(value)||Double.IsInfinity(value)||value< -2147483648.0||value>=2147483648.0)throw new ArgumentOutOfRangeException("tokens");p.Offset=R((int)value);}}
                if(min!=max)p.Shared.Wait=R((double)w.World.Movement.NextFloat()*((double)max-min)+min);p.Angle=actor.Angle27a;
            }
            double turn=Math.Truncate((double)p.Offset*delta);
            if(turn<Int32.MinValue||turn>Int32.MaxValue)throw new ArgumentOutOfRangeException("delta");
            p.Angle=unchecked((ushort)(p.Angle+(int)turn));p.Shared.FacingPoint=SpawnVector.Add(FacingMath.RotateY(new SpawnVector(0,0,1),p.Angle,w.SineTable),actor.Origin80);c.LookTarget=p.Shared;
            return Timed(p,delta);
        }
        //0x58bee0. Pointer identity and source vector are separate, as in the PC.
        public static void RequestLook(FacingLookRequest state,FacingPoint target,sbyte priority,float duration,float minDelay,float maxDelay,QRandom random)
        {
            if(target==null){state.Duration=state.Delay=0;state.Target=null;state.Priority=0;return;}
            if(state.Target==null||(!Object.ReferenceEquals(target,state.Target)&&state.Priority<=priority))
            {
                if(random==null)throw new InvalidOperationException("Shared QRAND required.");
                uint draw=random.Next();state.Target=target;state.Priority=priority;
                double fraction=R(draw*1.5259021893143654e-5);float delay=R((1.0-fraction)*minDelay+(double)maxDelay*fraction);
                state.Delay=delay;state.Duration=R((double)delay+duration);
            }
            state.CachedPosition=state.Target.Position;
        }
    }
}
