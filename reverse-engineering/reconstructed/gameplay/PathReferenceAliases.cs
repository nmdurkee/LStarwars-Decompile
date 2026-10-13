using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
    public sealed class PathAliasReference
    {
        public uint Scene,Normal,Display;
        public PathAliasReference(uint scene,uint normal,uint display){Scene=scene;Normal=normal;Display=display;}
    }
    public sealed class PathAliasGroup
    {
        public short Count;
        public PathAliasReference[] References;
    }
    public sealed class PathAliasWorld
    {
        //Loader supplies the original ordered groups. Count remains signed;
        //native row strides and memory lifetime are a validated host boundary.
        public int Count;
        public PathAliasGroup[] Groups;
        public readonly Dictionary<uint,PathSceneNormal> Normals=new Dictionary<uint,PathSceneNormal>();
        public readonly Dictionary<uint,PathSceneDisplay> Displays=new Dictionary<uint,PathSceneDisplay>();
        public PathSceneReference Project(PathAliasReference r)
        {return new PathSceneReference{ScenePresent=r.Scene!=0,Normal=r.Normal==0?null:Normals[r.Normal],Display=r.Display==0?null:Displays[r.Display]};}
    }
    public static class PathReferenceAliases
    {
        //0x5cfac0. Validity ignores the scene word.
        public static bool Valid(PathAliasReference r){return r!=null&&(r.Normal!=0||r.Display!=0);}
        //0x5d0450. Normal OR display identity matches; scene identity is ignored.
        public static bool Same(PathAliasReference a,PathAliasReference b)
        {return a.Normal!=0&&a.Normal==b.Normal||a.Display!=0&&a.Display==b.Display;}
        //0x55fd40. Only the first matching group is eligible, even if none of
        //its members is visible. Copies all three words in source order.
        public static bool Resolve(PathAliasWorld world,PathAliasReference reference)
        {
            if(!Valid(reference)||world.Groups==null)return false;
            for(int i=0;i<world.Count;i++)
            {
                PathAliasGroup group=world.Groups[i];bool found=false;for(int j=0;j<group.Count;j++)if(Same(reference,group.References[j])){found=true;break;}
                if(!found)continue;
                for(int j=0;j<group.Count;j++)
                {
                    PathAliasReference candidate=group.References[j];if(!PathSceneBindings.Visible(world.Project(candidate)))continue;
                    reference.Scene=candidate.Scene;reference.Normal=candidate.Normal;reference.Display=candidate.Display;return true;
                }
                return false;
            }
            return false;
        }
        //0x43c780. Context is ignored; current world is reread on each call.
        //The provider projects the already recovered55f450 global-world getter.
        public static bool GameResolve(Func<PathAliasWorld> currentWorld,PathAliasReference reference)
        {return Resolve(currentWorld(),reference);}
        //Composition adapter, not an additional native mapping. Original raw
        //reference writes and the typed scene view are updated together.
        public static void Attach(PathAttachmentWorld attachment,Func<PathAliasWorld> currentWorld)
        {
            attachment.ResolveUnavailable=delegate(PathAttachmentWorld world,ReinitializationRecord point)
            {
                PathAliasWorld aliases=currentWorld();PathAliasReference r=new PathAliasReference(point.U32(0x40),point.U32(0x44),point.U32(0x48));bool success=Resolve(aliases,r);
                if(success){point.Set32(0x40,r.Scene);point.Set32(0x44,r.Normal);point.Set32(0x48,r.Display);world.References[point.Identity]=aliases.Project(r);}return success;
            };
        }
    }
}
