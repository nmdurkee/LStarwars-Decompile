// Original-PC scenery temporal and active-group contracts. See scene-animation-update-contract.json.
using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class ScenePlaybackSpecial
    {
        public bool HasScene = true, HasInstance, HasDisplay = true;
        public uint InstanceFlags, DisplayFlags;
    }
    public sealed class ScenePlaybackStateTrack
    {
        public ushort EndFrame;
        public float[] Times;
        public byte[] Values;
    }
    public sealed class ScenePlaybackInstance
    {
        public ScenePlaybackTarget Target;
        public ScenePlaybackSpecial Special;
        public ushort AnimationIndex;
        public bool HasClip = true;
        public float ClipEndFrame, FirstFrame, Interval, PreviousEvaluation;
    }
    public sealed class ScenePlaybackScene
    {
        public bool HasAnimationTable = true;
        public short AnimationDataCount;
        public ScenePlaybackStateTrack[] StateTracks;
        public int StateTableOwnerCount = 2;
        public readonly List<ScenePlaybackInstance> Instances = new List<ScenePlaybackInstance>();
    }
    public sealed class ScenePlaybackEvaluation
    {
        public ScenePlaybackInstance Instance;
        public float Frame;
        public bool EvaluatePose, CopyPose;
    }
    public sealed class ScenePlaybackNodeBinding
    {
        public ScenePlaybackSpecial Special;
        // Native 0x552760 evaluates a changed/clamped frame, updates matrices and
        // scene bounds. This ordered hook is separate from recovered time/state math.
        public Action<float> EvaluateChangedFrame;
    }
    public static class SceneAnimationUpdate
    {
        static PlaybackWide W(float v) { return PlaybackWide.From(v); }
        static PlaybackWide Neg(PlaybackWide v) { return PlaybackWide.Multiply(v,W(-1)); }
        static PlaybackWide Add(PlaybackWide a,PlaybackWide b) { return PlaybackWide.Add(a,b); }
        static PlaybackWide Sub(PlaybackWide a,PlaybackWide b) { return Add(a,Neg(b)); }
        static float Sum(float a,float b) { float v=Add(W(a),W(b)).Store();return v==0?(float)((double)a+b):v; }
        static float Difference(float a,float b) { float v=Sub(W(a),W(b)).Store();return v==0?(float)((double)a-b):v; }
        static float Advance(float frame,float rate,float delta)
        {float v=Add(PlaybackWide.Multiply(W(rate),W(delta)),W(frame)).Store();return v==0?(float)((double)rate*delta+frame):v;}
        static bool Less(float a,PlaybackWide b) { return Sub(W(a),b).Store()<0; }
        static void Finite(float v) { if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite scene-animation inputs required"); }
        // 0x5cfde0 and0x5cfd90 use different bits for instance and display records.
        public static bool GetNoVisibilityTest(ScenePlaybackSpecial s)
        {
            return s!=null&&s.HasScene&&(s.HasInstance?(s.InstanceFlags&8)!=0:s.HasDisplay&&(s.DisplayFlags&0x80)!=0);
        }
        public static void SetNoVisibilityTest(ScenePlaybackSpecial s,bool value)
        {
            if(s==null||!s.HasScene)return;
            if(s.HasInstance)s.InstanceFlags=(s.InstanceFlags&0xfffffff7)|(value?8u:0);
            else if(s.HasDisplay)s.DisplayFlags=(s.DisplayFlags&0xffffff7f)|(value?0x80u:0);
        }
        // 0x5a0720: queue availability gates both removal and state refresh.
        public static void Remove(ScenePlaybackGroup group)
        {
            if(group==null||group.Queue==null)return;
            if((group.Flags&4)!=0){group.Queue.Groups.Remove(group);group.Flags=(ushort)(group.Flags&0xfffb);}
            SceneAnimationControls.Refresh(group);
        }
        // 0x5a0fb0: removal/refresh occurs inside the member loop, even for null
        // targets; a completely empty member list therefore does not dequeue.
        public static int Reset(ScenePlaybackGroup group)
        {
            if(group==null)return 1;
            foreach(ScenePlaybackNode node in group.Nodes)
            {
                if(node.Target!=null){node.Target.Flags&=0xfffffffa;node.Target.Frame=node.Start;node.Target.Rate=1;}
                Remove(group);
            }
            return 1;
        }
        // 0x5a1780. Iterates the original queue snapshot: removal never skips the
        // successor. Bindings must not mutate lists, time, flags or other targets.
        public static void UpdateGroups(ScenePlaybackQueue queue,IDictionary<ScenePlaybackNode,ScenePlaybackNodeBinding> bindings)
        {
            if(queue==null)return;
            ScenePlaybackGroup[] pending=queue.Groups.ToArray();
            foreach(ScenePlaybackGroup group in pending)
            {
                ushort previous=group.Flags;group.Flags=(ushort)(previous&0xfffe);
                if((previous&2)!=0){group.Flags=(ushort)(previous&0xfffc);Remove(group);continue;}
                group.State=0;bool forward=true,atStart=true,atEnd=true,anyNoTest=false;
                foreach(ScenePlaybackNode node in group.Nodes)
                {
                    ScenePlaybackNodeBinding binding=null;if(bindings!=null)bindings.TryGetValue(node,out binding);
                    if(binding!=null&&GetNoVisibilityTest(binding.Special))anyNoTest=true;
                    ScenePlaybackTarget target=node.Target;if(target==null)continue;
                    Finite(node.Start);Finite(node.End);Finite(target.Frame);Finite(target.Rate);
                    float direction=node.Start<=node.End?1:-1,prior=target.Frame;
                    double directed=(double)prior*direction,rate=(double)target.Rate*direction;
                    if(directed>=(double)node.End*direction)
                    {
                        if(rate<0)target.Frame=node.End;
                        else if((target.Flags&8)!=0)target.Frame=Sum(Difference(prior,node.End),node.Start);
                        else{target.Frame=node.End;target.Flags&=0xfffffffe;}
                    }
                    else if(directed<=(double)node.Start*direction)
                    {
                        if(rate>0)target.Frame=node.Start;
                        else if((target.Flags&8)!=0)target.Frame=Difference(node.End,Difference(node.Start,prior));
                        else{target.Frame=node.Start;target.Flags&=0xfffffffe;}
                    }
                    if(target.Frame!=prior&&binding!=null&&binding.EvaluateChangedFrame!=null)binding.EvaluateChangedFrame(target.Frame);
                    if((target.Flags&1)!=0){group.Flags|=1;if(rate<0)forward=false;}
                    directed=(double)target.Frame*direction;
                    if((double)node.Start*direction<directed)atStart=false;
                    if(directed<(double)node.End*direction)atEnd=false;
                }
                if(((group.Flags&1)!=0)!=anyNoTest)
                    foreach(ScenePlaybackNode node in group.Nodes)
                    {ScenePlaybackNodeBinding binding=null;if(bindings!=null)bindings.TryGetValue(node,out binding);if(binding!=null)SetNoVisibilityTest(binding.Special,(group.Flags&1)!=0);}
                if((group.Flags&1)==0){if(atEnd)group.State=2;else if(!atStart)group.State=4;if((previous&1)!=0)group.Flags|=2;}
                else group.State=forward?1:3;
                if((group.Flags&3)==0)Remove(group);
            }
        }
        // 0x5da480 finite nonempty state tracks; byte cursor matches the PC field.
        public static bool EvaluateState(ScenePlaybackStateTrack track,ref byte cursor,out byte value,float frame)
        {
            if(track==null||track.Times==null||track.Values==null||track.Times.Length==0||track.Times.Length!=track.Values.Length||track.Times.Length>256)throw new ArgumentException("Nonempty byte-indexed state track required");
            Finite(frame);int count=track.Times.Length,index=Math.Min(cursor,count-1);byte before=track.Values[index];
            if(track.Times[index]>frame){while(index>0&&track.Times[index]>frame)--index;}
            else{while(index+1<count&&track.Times[index+1]<=frame)++index;}
            cursor=(byte)index;value=track.Values[index];return value!=before;
        }
        // Bounded temporal/state stage of0x5f4b90. The native caller supplies
        // dtSeconds*60. Pose evaluation/copy and draw translation are emitted as
        // ordered work items; they are not silently represented by a no-op.
        public static List<ScenePlaybackEvaluation> UpdateScene(ScenePlaybackScene scene,float frameDelta)
        {
            if(scene==null)throw new ArgumentNullException("scene");Finite(frameDelta);
            List<ScenePlaybackEvaluation> work=new List<ScenePlaybackEvaluation>();if(!scene.HasAnimationTable)return work;
            if(scene.StateTracks!=null&&scene.StateTableOwnerCount<2)scene.StateTracks=null;
            float evaluation=0;
            foreach(ScenePlaybackInstance instance in scene.Instances)
            {
                if(instance.AnimationIndex>=scene.AnimationDataCount)continue;
                ScenePlaybackTarget target=instance.Target;ScenePlaybackSpecial special=instance.Special;
                if(target==null||special==null||!special.HasDisplay)throw new ArgumentException("Valid scene instance/display records required");
                uint lookup=target.Flags>>22;ScenePlaybackStateTrack state=null;
                if(lookup!=0&&scene.StateTracks!=null){if(lookup>scene.StateTracks.Length)throw new ArgumentException("Invalid state-table index");state=scene.StateTracks[lookup-1];}
                else if((special.DisplayFlags&2)==0)continue;
                if(!instance.HasClip&&state==null)continue;
                float end=instance.HasClip?instance.ClipEndFrame:state.EndFrame;Finite(end);if(end==0)continue;
                if((target.Flags&1)==0)evaluation=target.Frame;
                else
                {
                    target.Frame=Advance(target.Frame,target.Rate,frameDelta);
                    if((target.Flags&4)!=0&&target.Frame>=instance.FirstFrame)
                    {target.Flags&=0xfffffffb;target.Frame=Sub(W(target.Frame),Sub(W(instance.FirstFrame),W(1))).Store();}
                    if((target.Flags&4)==0)
                    {
                        PlaybackWide intervalEnd=Add(W(instance.Interval),W(end));evaluation=end;
                        if(Less(target.Frame,intervalEnd))
                        {
                            if(target.Frame<=end)
                            {if(target.Frame>=1)evaluation=target.Frame;else{target.Frame=evaluation=1;target.Flags&=0xfffffffe;}}
                        }
                        else if((target.Flags&8)==0){target.Flags&=0xfffffffe;target.Frame=end;}
                        else
                        {
                            PlaybackWide length=Sub(intervalEnd,W(1));
                            if(length.Store()<=0)throw new ArgumentException("Positive finite repeat period required");
                            float quotient=PlaybackWide.Divide(Sub(W(target.Frame),W(1)),length).Store();
                            float count=PlaybackWide.From(quotient).TruncateInt32();
                            float amount=PlaybackWide.Multiply(Sub(Add(W(end),W(instance.Interval)),W(1)),W(count)).Store();
                            target.Frame=Sub(W(target.Frame),W(amount)).Store();evaluation=target.Frame;
                        }
                        if((target.Flags&2)!=0)evaluation=Sub(Add(W(end),W(1)),W(evaluation)).Store();
                    }
                }
                bool animation=instance.HasClip,changed=instance.PreviousEvaluation!=evaluation;
                if(changed)
                {
                    if(state!=null)
                    {
                        byte cursor=(byte)(target.Flags>>14),value;bool stateChanged=EvaluateState(state,ref cursor,out value,evaluation);
                        target.Flags=(target.Flags&0xffc03fff)|((uint)cursor<<14);
                        if(stateChanged){if(value==0){special.DisplayFlags&=0xfffffffd;animation=false;}else special.DisplayFlags|=2;}
                    }
                    instance.PreviousEvaluation=evaluation;
                }
                work.Add(new ScenePlaybackEvaluation{Instance=instance,Frame=evaluation,EvaluatePose=changed&&animation,CopyPose=animation});
            }
            return work;
        }
    }
}
