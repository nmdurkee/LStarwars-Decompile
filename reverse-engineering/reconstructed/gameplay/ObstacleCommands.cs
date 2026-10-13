// Bounded PC obstacle/special commands and output dispatch.
// Evidence and explicit host boundaries: reports/native-obstacle-contract.json.
using System;
namespace Recovered.Gameplay
{
    public sealed class SceneryObject
    {
        public string Name;
        public ScenePlaybackGroup Animation;
        public float Speed=1,ForwardRate=1,BackwardRate=1;
        public byte LoopMode,SpecialFlags;
        public uint StatusFlags,StayFlags,Proximity;
    }
    public sealed class SceneryGizmo
    {
        public byte Type;
        public SceneryObject Target;
    }
    public sealed class SceneryRegistry
    {
        public SceneryNameBucket[] NameBuckets;
        public Func<SceneryGizmo,uint,int,uint>[] Outputs;
        // 0x55a1b0 after resolving the global type table and world registry.
        public static uint Output(SceneryRegistry registry,SceneryGizmo gizmo,uint index,int includeInactive)
        {
            if(registry==null||gizmo==null||registry.Outputs==null||gizmo.Type>=registry.Outputs.Length)return 0;
            Func<SceneryGizmo,uint,int,uint> output=registry.Outputs[gizmo.Type];
            return output==null?0:output(gizmo,index,includeInactive);
        }
    }
    public interface ISceneryBindings
    {
        SceneryGizmo Find(SceneryRegistry registry,int type,string name);
    }
    public sealed class SceneryWorld
    {
        public SceneryRegistry Registry;
        public ISceneryBindings Bindings;
        public int ObstacleType,SpecialType=1;
    }
    internal static class SceneryText
    {
        public static string C(string value){if(value==null)return null;int i=value.IndexOf('\0');return i<0?value:value.Substring(0,i);}
        static int Fold(char value)
        {if(value>255)throw new ArgumentException("Native strings must be byte encoded.");return(value>='a'&&value<='z')||value>=224?value-32:value;}
        public static int Index(string text,string part)
        {
            for(int i=0;i+part.Length<=text.Length;++i){bool equal=true;for(int j=0;j<part.Length;++j)if(Fold(text[i+j])!=Fold(part[j])){equal=false;break;}if(equal)return i;}return -1;
        }
        public static bool Equal(string text,string expected){return text.Length==expected.Length&&Index(text,expected)==0;}
    }
    public static class ObstacleCommands
    {
        // 0x4408b0 /0x4408e0 return the gizmo record, not its object pointer.
        public static SceneryGizmo Initialize(SceneryWorld world,string name,bool special)
        {return world.Bindings.Find(world.Registry,special?world.SpecialType:world.ObstacleType,SceneryText.C(name));}
        // 0x4409b0 differs: it dereferences the record for LockedShut and related conditions.
        public static SceneryObject InitializeObject(SceneryWorld world,string name)
        {SceneryGizmo gizmo=Initialize(world,name,false);return gizmo==null?null:gizmo.Target;}
        // 0x440910 treats an unavailable output callback as outputzero => AtStart.
        public static float AtStart(SceneryRegistry registry,SceneryGizmo gizmo)
        {return gizmo!=null&&SceneryRegistry.Output(registry,gizmo,1,1)==0?1:0;}
        // 0x440940.
        public static float AtEnd(SceneryRegistry registry,SceneryGizmo gizmo)
        {return gizmo!=null&&SceneryRegistry.Output(registry,gizmo,0,1)!=0?1:0;}
        // 0x440970 requires a valid initialized object; native has no null guard.
        public static float LockedShut(SceneryObject target)
        {if(target==null)throw new ArgumentNullException("target");return(target.StayFlags&8)!=0?1:0;}
        // 0x558780, all five registered obstacle outputs.
        public static uint ObstacleOutput(SceneryGizmo gizmo,uint index,int includeInactive)
        {
            if(gizmo==null)throw new ArgumentNullException("gizmo");
            SceneryObject target=gizmo.Target;if(target==null||((target.StatusFlags&3)!=3&&includeInactive==0)||target.Animation==null)return 0;
            int state=target.Animation.State;
            return(uint)(index==0?(state==2?1:0):index==1?(state!=0?1:0):index==2?(target.Proximity!=0?1:0):index==3?(state==0?1:0):index==4?(state==1?1:0):0);
        }
        // 0x5ae3a0; scene reference validity replaces original0x5cfac0 record projection.
        public static uint SpecialOutput(SceneryGizmo gizmo,uint index,int includeInactive)
        {
            if(gizmo==null||gizmo.Target==null)return 0;SceneryObject target=gizmo.Target;ScenePlaybackGroup group=target.Animation;
            if(group==null)throw new InvalidOperationException("Native special output requires an animation group.");
            if(group.MemberCount==0)return 0;
            if(group.Nodes.Count==0)throw new InvalidOperationException("Native member count requires a first member.");
            if(!group.Nodes[0].ReferenceValid||((target.SpecialFlags&2)==0&&includeInactive==0))return 0;
            if((group.Flags&4)==0)SceneAnimationControls.Refresh(group);
            return(uint)(index==0?(group.State==2?1:0):index==1?(group.State!=0?1:0):0);
        }
        // 0x557960 /0x5579d0 use separate rates according to the signed base speed.
        public static void Play(SceneryObject target,bool backwards)
        {
            if(target==null)return;
            SceneAnimationControls.SetLoop(target.Animation,target.LoopMode==2?1:0);
            float speed=target.Speed;
            float rate=(float)(backwards?-(double)speed*(speed<0?target.ForwardRate:target.BackwardRate):(double)speed*(speed<0?target.BackwardRate:target.ForwardRate));
            SceneAnimationControls.Play(target.Animation,rate,false);
        }
        // 0x558970 /0x558990 preserve group state and obstacle stay flags.
        public static void Snap(SceneryObject target,bool backwards)
        {if(target==null||target.Animation==null)return;if(backwards)SceneAnimationControls.JumpToStart(target.Animation);else SceneAnimationControls.JumpToEnd(target.Animation);}
        static void Stay(SceneryObject target,bool open,bool shut)
        {target.StayFlags=(target.StayFlags&0xfffffff3)|(open?4u:0)|(shut?8u:0);}
        // 0x44ea70 shared by SCP PlayObstacle and PlayGizObstacle.
        public static int ExecuteScript(SceneryWorld world,string[] tokens,bool firstCall)
        {
            if(!firstCall||tokens.Length==0)return 1;
            SceneryObject target=null;bool backwards=false,snap=false,open=false,shut=false;
            foreach(string raw in tokens)
            {
                string token=SceneryText.C(raw);int at=SceneryText.Index(token,"name=");
                if(at>=0){SceneryGizmo found=Initialize(world,token.Substring(at+5),false);if(found!=null)target=found.Target;}
                else if(SceneryText.Equal(token,"backwards"))backwards=true;
                else if(SceneryText.Equal(token,"stayopen"))open=true;
                else if(SceneryText.Equal(token,"stayshut"))shut=true;
                else if(SceneryText.Equal(token,"snap"))snap=true;
            }
            if(target!=null){if(snap)Snap(target,backwards||shut);else Play(target,backwards||shut);Stay(target,open,shut);}return 1;
        }
        // 0x465590 /0x465720 parse all tokens before one lookup. "Name" is a
        //substring followed by one skipped delimiter; separator must be present.
        public static void ExecuteGraph(SceneryWorld world,string[] tokens,bool special)
        {
            string name=null;bool backwards=false,snap=false,open=false,shut=false;
            foreach(string raw in tokens)
            {
                string token=SceneryText.C(raw);int at=SceneryText.Index(token,"Name");
                if(at>=0)name=token.Substring(at+5);
                else if(SceneryText.Equal(token,"BACKWARD"))backwards=true;
                else if(SceneryText.Equal(token,"FORWARD"))backwards=false;
                else if(SceneryText.Equal(token,"SNAP"))snap=true;
                else if(!special&&SceneryText.Equal(token,"STAYOPEN"))open=true;
                else if(!special&&SceneryText.Equal(token,"STAYSHUT"))shut=true;
            }
            if(name==null)return;SceneryGizmo found=Initialize(world,name,special);if(found==null||found.Target==null)return;
            SceneryObject target=found.Target;
            if(special)
            {if(snap){if(backwards)SceneAnimationControls.JumpToStart(target.Animation);else SceneAnimationControls.JumpToEnd(target.Animation);}else SceneAnimationControls.Play(target.Animation,backwards?-1:1,false);}
            else{if(snap)Snap(target,backwards);else Play(target,backwards);Stay(target,open,shut);}
        }
    }
}
