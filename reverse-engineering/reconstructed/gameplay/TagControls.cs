// Bounded original-PC tag selection/control, with explicit full world-transfer
// and vehicle/takeover release services. See gameplay-tag-control-contract.json.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class TagControlState
    {
        public byte Flags7c5,Blocked28b;
        public ActorStateRecord LinkedCd0,Pending7c8;
        public float Wait7c0;
    }
    public abstract class TagControlServices
    {
        // Native 0x4876a0(from,to,0,0,argument). Full world/controller transfer
        // remains outside this projection. Return 0=failure, 2=pending.
        public abstract int Transfer(ActorStateRecord from,ActorStateRecord to,uint argument);
        // Native 0x4882d0. Full vehicle/takeover release remains external.
        public abstract void Release(ActorStateRecord actor);
    }
    public sealed class TagControlWorld
    {
        public ActorStateWorld Actors;
        public TagControlServices Services;
        public ActorStateRecord SecondaryPlayer;
        public readonly Dictionary<ActorStateRecord,TagControlState> State=new Dictionary<ActorStateRecord,TagControlState>();
        internal TagControlState Get(ActorStateRecord actor)
        {TagControlState value;if(actor==null||!State.TryGetValue(actor,out value))throw new ArgumentException("Missing tag-state attachment.");return value;}
        // 0x55e410: only slots0/1 take part, regardless of the eight-slot scan
        // used by the candidate selector. The no-player branch retains secondary.
        public void RefreshPlayers()
        {
            ActorStateRecord first=Actors.Players[0],second=Actors.Players[1];
            if(first==null||(first.Flags1fc&0x80)==0)
            {
                if(second==null||(second.Flags1fc&0x80)==0){Actors.PrimaryPlayer=null;return;}
                Actors.PrimaryPlayer=second;
            }
            else
            {
                Actors.PrimaryPlayer=first;
                if(second!=null&&(second.Flags1fc&0x80)!=0){SecondaryPlayer=second;return;}
            }
            SecondaryPlayer=null;
        }
    }
    public static class TagControls
    {
        static bool Eligible(TagControlWorld world,ActorStateRecord source,ActorStateRecord target)
        {
            if(target==null||Object.ReferenceEquals(source,target)||(target.Flags1fc&0x1081)!=0x1001)return false;
            TagControlState tag=world.Get(target);return tag.Blocked28b==0&&(tag.Flags7c5&2)==0;
        }
        // 0x487ca0: preferred valid candidate precedes the ordered eight slots.
        public static int TryTransfer(TagControlWorld world,ActorStateRecord source,ActorStateRecord preferred,uint argument)
        {
            if(source==null)throw new ArgumentNullException("source");
            ActorStateRecord target=preferred;
            if(!Eligible(world,source,target))
            {
                target=null;
                for(int i=0;i<8;i++)if(Eligible(world,source,world.Actors.Players[i])){target=world.Actors.Players[i];break;}
                if(target==null)return 0;
            }
            uint sourceFlags=source.Flags1fc,targetFlags=target.Flags1fc;
            if(world.Services==null)throw new InvalidOperationException("Transfer service required.");
            int result=world.Services.Transfer(source,target,argument);
            if(result==2)
            {
                TagControlState tag=world.Get(source);tag.Wait7c0=3;tag.Pending7c8=target;tag.Flags7c5=(byte)((tag.Flags7c5&0xf7)|4);return 0;
            }
            if(result==0)return 0;
            // Preserve other post-service bits, but exchange the PRE-service
            // ownership bits captured by the original function.
            target.Flags1fc=(target.Flags1fc&~0x80u)|(sourceFlags&0x80);
            source.Flags1fc=(source.Flags1fc&~0x80u)|(targetFlags&0x80);
            return 1;
        }
        // 0x44f930: FALSE requests disabling tagging. If currently controlled,
        // transfer/release and primary-player refresh precede the final flag write.
        public static int SetTaggable(TagControlWorld world,ActorStateRecord reference,string[] tokens,bool first)
        {
            if(!first)return 1;
            ActorStateRecord actor=reference==null?null:reference.WorldObject,tagTarget=null;bool disabled=false;
            foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase);
                if(at>=0)actor=world.Actors.ResolveObject(token.Substring(at+10));
                else
                {
                    at=token.IndexOf("tag_to=",StringComparison.OrdinalIgnoreCase);
                    if(at>=0)tagTarget=world.Actors.ResolveObject(token.Substring(at+7));
                    else if(ActorStateWorld.Equal(token,"FALSE"))disabled=true;
                }
            }
            if(actor!=null)
            {
                TagControlState state=world.Get(actor);
                if(disabled&&(actor.Flags1fc&0x80)!=0)
                {
                    if(state.LinkedCd0==null){if(TryTransfer(world,actor,tagTarget,0)==0)disabled=false;}
                    else
                    {
                        if(world.Services==null)throw new InvalidOperationException("Release service required.");
                        world.Services.Release(actor);
                    }
                    world.RefreshPlayers();
                }
                state.Flags7c5=(byte)((state.Flags7c5&~2)|(disabled?2:0));
            }
            return 1;
        }
    }
}
