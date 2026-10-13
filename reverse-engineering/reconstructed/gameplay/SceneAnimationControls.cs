// Recovered PC scene-animation group controls; native-obstacle-contract.json.
// Group membership, rendering, animation ticking and collision updates remain external.
using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class ScenePlaybackTarget
    {
        public float Frame, Rate, RateScale;
        public uint Flags;
    }
    public sealed class ScenePlaybackNode
    {
        public ScenePlaybackTarget Target;
        public float Start, End;
        public bool HasOwner = true, ReferenceValid = true;
    }
    public sealed class ScenePlaybackQueue
    {
        public readonly List<ScenePlaybackGroup> Groups = new List<ScenePlaybackGroup>();
    }
    public sealed class ScenePlaybackGroup
    {
        public ushort Flags;
        public int State;
        public byte MemberCount;
        public ScenePlaybackQueue Queue;
        public readonly List<ScenePlaybackNode> Nodes = new List<ScenePlaybackNode>();
    }
    public static class SceneAnimationControls
    {
        static void Finite(float x)
        { if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite scene-animation inputs required."); }
        static float Direction(ScenePlaybackNode node)
        { Finite(node.Start);Finite(node.End);return node.Start<=node.End?1:-1; }
        // 0x5a0670: the active queue flag suppresses state recomputation.
        public static void Refresh(ScenePlaybackGroup group)
        {
            if(group==null)throw new ArgumentNullException("group");
            if((group.Flags&4)!=0)return;
            bool atEnd=true,atStart=true;
            foreach(ScenePlaybackNode node in group.Nodes)
            {
                if(node.Target==null)continue;
                float direction=Direction(node);Finite(node.Target.Frame);
                double frame=(double)node.Target.Frame*direction;
                if(frame<(double)node.End*direction)atEnd=false;
                if((double)node.Start*direction<frame)atStart=false;
            }
            group.State=atEnd?2:atStart?0:4;
        }
        // 0x5a1030: clears stop flag even when already at the requested endpoint.
        // Target aliases and member order are preserved through object references.
        public static int Play(ScenePlaybackGroup group,float speed,bool evaluate)
        {
            if(group==null)return 1;
            Finite(speed);if(evaluate)Refresh(group);group.Flags=(ushort)(group.Flags&0xfffd);
            if(speed<0?group.State==0:group.State==2)return 1;
            foreach(ScenePlaybackNode node in group.Nodes)
            {
                ScenePlaybackTarget target=node.Target;if(target==null)continue;
                float direction=Direction(node);Finite(target.Frame);Finite(target.RateScale);
                target.Flags=(target.Flags|1)&0xfffffffb;
                double frame=(double)target.Frame*direction;
                if((double)node.Start*direction>frame)target.Frame=node.Start;
                else if((double)node.End*direction<frame)target.Frame=node.End;
                target.Rate=(float)((target.RateScale==0?1:(double)target.RateScale)*speed*direction);
            }
            if((group.Flags&4)==0&&group.Queue!=null){group.Queue.Groups.Add(group);group.Flags|=4;}
            return 1;
        }
        // 0x5a1170: only native states1 and3 are stoppable.
        public static int Stop(ScenePlaybackGroup group)
        {
            if(group==null||(group.State!=1&&group.State!=3))return 1;
            group.Flags|=2;foreach(ScenePlaybackNode node in group.Nodes)if(node.Target!=null)node.Target.Flags&=0xfffffffe;
            return 1;
        }
        // 0x5a11b0 uses the low input bit, even for non-Boolean integer callers.
        public static int SetLoop(ScenePlaybackGroup group,int value)
        {
            if(group!=null)foreach(ScenePlaybackNode node in group.Nodes)if(node.Target!=null)
                node.Target.Flags=(node.Target.Flags&0xfffffff7)|((uint)(value&1)<<3);
            return 1;
        }
        // 0x5a11f0 and0x5a1230 do not refresh the group state or queue membership.
        public static int JumpToEnd(ScenePlaybackGroup group){return Jump(group,true);}
        public static int JumpToStart(ScenePlaybackGroup group){return Jump(group,false);}
        static int Jump(ScenePlaybackGroup group,bool end)
        {
            if(group!=null)foreach(ScenePlaybackNode node in group.Nodes)if(node.Target!=null)
            {node.Target.Flags&=0xfffffffe;node.Target.Frame=end?node.End:node.Start;}
            return 1;
        }
        // 0x5a1270: interpolate in native x87 precision, storefloat32, then clamp.
        public static void Seek(ScenePlaybackGroup group,float fraction)
        {
            if(group==null)return;Finite(fraction);
            foreach(ScenePlaybackNode node in group.Nodes)
            {
                ScenePlaybackTarget target=node.Target;if(target==null||!node.HasOwner)continue;
                float direction=Direction(node);target.Flags&=0xfffffffe;
                PlaybackWide delta=PlaybackWide.Add(PlaybackWide.From(node.End),PlaybackWide.From(-node.Start));
                float frame=PlaybackWide.Add(PlaybackWide.Multiply(delta,PlaybackWide.From(fraction)),PlaybackWide.From(node.Start)).Store();
                // PlaybackWide deliberately normalizes exact zero. Restore the
                // native negative-zero sum when a negative-zero start participates.
                if(frame==0&&node.Start==0)
                {
                    float zeroSign=(float)(((double)node.End-node.Start)*fraction+node.Start);
                    frame=PcObjectImage.FromBits(PcObjectImage.ToBits(zeroSign)&0x80000000);
                }
                if((double)node.End*direction<(double)frame*direction)frame=node.End;
                if((double)frame*direction<(double)node.Start*direction)frame=node.Start;
                target.Frame=frame;
            }
        }
    }
    // Connects existing SpecialGizmo callbacks to these recovered controls.
    // Visibility is supplied explicitly until its scene/render dependencies exist.
    public sealed class SceneAnimationBinding : ISceneAnimation
    {
        readonly ScenePlaybackGroup group;
        readonly Action<bool> visibility;
        public SceneAnimationBinding(ScenePlaybackGroup group,Action<bool> visibility)
        {this.group=group;this.visibility=visibility;}
        public void JumpToStart(){SceneAnimationControls.JumpToStart(group);}
        public void Play(float speed,bool evaluate){SceneAnimationControls.Play(group,speed,evaluate);}
        public void Stop(){SceneAnimationControls.Stop(group);}
        public void SetVisibility(bool visible){if(visibility==null)throw new InvalidOperationException("Visibility adapter required.");visibility(visible);}
    }
}
