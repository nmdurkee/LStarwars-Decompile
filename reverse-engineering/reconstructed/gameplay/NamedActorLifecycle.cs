// Named actor activation/deactivation helpers. Physical image fields and typed
// ScriptPacket state are complementary projections, not duplicate authorities.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public sealed class ActorPlacementSource
    {
        public PcObjectImage Image;
        public int Offset;
        public uint[] Words;
        // Read lazily: original sequential copies preserve source/destination
        // aliasing. A source inside the target image must not be snapshotted.
        public uint Read(int index){return Image!=null?Image.U32(Offset+4*index):Words[index];}
    }
    public abstract class NamedActorLifecycleServices
    {
        public abstract void ResetState(NamedActorWorld world,ActorStateRecord actor,uint systemIdentity,byte state,int ground);
        public abstract void ResetTerrain(NamedActorWorld world,ActorStateRecord actor);
        public abstract void ClearTerrain(NamedActorWorld world,ActorStateRecord actor,int mode);
        public abstract void Refresh(NamedActorWorld world,ActorStateRecord actor,uint contextIdentity);
    }
    public sealed class NamedActorWorld
    {
        public LevelModeWorld Modes;
        public ActorActivationWorld Activation;
        public ActorReinitializationWorld SpawnWorld;
        public NamedActorLifecycleServices Services;
        // Optional explicit host boundary. If absent, the already recovered
        // ActorReinitialization body runs directly on prepared spawn records.
        public Action<NamedActorWorld,ActorStateRecord,uint> SpawnReinitialize;
        public uint RestrictedMode93b2a4,RefreshContext2ab4;
        public readonly Dictionary<ActorStateRecord,PcObjectImage> Images=new Dictionary<ActorStateRecord,PcObjectImage>();
        public readonly Dictionary<ActorStateRecord,uint> Identities=new Dictionary<ActorStateRecord,uint>();
        // Raw physical fields are imported for actual name lookup and flags.
        // ScriptPacket and ActivationActorFields remain the script authority;
        // no fake PC pointers are written into those raw-image script slots.
        public void ImportPhysical(ActorStateRecord actor)
        {
            PcObjectImage p=Images[actor];actor.Flags1f8=p.U32(0x1f8);actor.Flags1fc=p.U32(0x1fc);actor.SpawnIndex=p.U8(0x400);actor.X=p.F32(0x5c);actor.Y=p.F32(0x60);actor.Z=p.F32(0x64);
        }
        internal ActorStateRecord Resolve(string name)
        {
            foreach(ActorStateRecord actor in Images.Keys)ImportPhysical(actor);
            Activation.Actors.SystemPresent=SpawnWorld.ScriptSystemIdentity!=0;
            return Activation.Actors.ResolveObject(name);
        }
    }
    public static class NamedActorLifecycle
    {
        static void Copy(PcObjectImage p,int to,int from)
        {for(int i=0;i<3;i++)p.Set32(to+i*4,p.U32(from+i*4));}
        //0x41f6d0. Returns the actual world object, not the name-reference row.
        public static ActorStateRecord Activate(NamedActorWorld world,string name,ActorPlacementSource position,ushort angle)
        {
            if(LevelModeConditions.ResolveMission(world.Modes,null)!=null)return null;
            if(name==null)return null;
            ActorStateRecord actor=world.Resolve(name);if(actor==null)return null;PcObjectImage image=world.Images[actor];
            if((image.U32(0x1fc)&0x1000)!=0||(world.RestrictedMode93b2a4!=0&&(image.U32(0x1f8)&0x400)==0))return null;
            if(image.U8(0x400)==255)
            {
                image.Set32(0x1fc,image.U32(0x1fc)|0x1000u);actor.Flags1fc=image.U32(0x1fc);world.Activation.Change(actor,"Base");
                if(position!=null)
                {
                    for(int i=0;i<3;i++)image.Set32(0x5c+i*4,position.Read(i));
                    image.Set16(0x27a,angle);image.Set16(0x58,angle);image.Set16(0x5a,angle);
                    world.Services.ResetState(world,actor,world.SpawnWorld.ScriptSystemIdentity,255,1);
                    Copy(image,0x80,0x5c);Copy(image,0x98,0x5c);
                    for(int i=0;i<3;i++)world.SpawnWorld.LastSpawnOrigin[i]=image.U32(0x80+i*4);
                    Copy(image,0x8c,0x80);Copy(image,0x1cc,0x5c);Copy(image,0x1b4,0x5c);Copy(image,0x10bc,0x5c);
                    for(int i=0;i<3;i++){image.Set32(0xdf8+i*4,world.SpawnWorld.ResetVector[i]);image.Set32(0x68+i*4,world.SpawnWorld.ResetVector[i]);}
                    world.Services.ResetTerrain(world,actor);world.Services.ClearTerrain(world,actor,0);
                }
            }
            else
            {
                uint system=world.SpawnWorld.ScriptSystemIdentity;
                if(world.SpawnReinitialize!=null)world.SpawnReinitialize(world,actor,system);
                else{world.SpawnWorld.ActorIdentity=world.Identities[actor];ActorReinitialization.Reinitialize(world.SpawnWorld,image,system!=0);}
            }
            world.Services.Refresh(world,actor,world.RefreshContext2ab4);world.ImportPhysical(actor);return actor;
        }
        //0x414c50. Deliberately has no already-active/inactive guard.
        public static void Deactivate(NamedActorWorld world,string name)
        {
            if(LevelModeConditions.ResolveMission(world.Modes,null)!=null||name==null)return;
            ActorStateRecord actor=world.Resolve(name);if(actor==null)return;PcObjectImage image=world.Images[actor];
            if(world.RestrictedMode93b2a4!=0&&(image.U32(0x1f8)&0x400)==0)return;
            ActorActivation.DeactivateActor(world.Activation,actor);
            image.Set32(0x1fc,actor.Flags1fc);image.Set8(0x406,world.Activation.Get(actor).Phase406);world.ImportPhysical(actor);
        }
    }
}
