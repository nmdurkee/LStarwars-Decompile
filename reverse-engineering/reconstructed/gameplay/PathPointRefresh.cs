using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class PathSceneMatrix { public uint Identity;public float[] Values; }
    public sealed class PathSceneAnimation { public PathSceneMatrix Matrix;public float Speed40;public uint Flags50; }
    public sealed class PathSceneNormal { public PathSceneMatrix Matrix;public PathSceneAnimation Animation;public uint Flags44; }
    public sealed class PathSceneDisplay { public PathSceneMatrix Matrix;public PathSceneAnimation Animation;public uint FlagsB8; }
    public sealed class PathSceneReference
    {
        public bool ScenePresent;
        public PathSceneNormal Normal;
        public PathSceneDisplay Display;
    }
    public static class PathSceneBindings
    {
        //0x5cfd60. Normal instance takes priority; only this getter gates on scene.
        public static bool Visible(PathSceneReference r)
        {return r.ScenePresent&&(r.Normal!=null?(r.Normal.Flags44&1)!=0:r.Display!=null&&(r.Display.FlagsB8&2)!=0);}
        //0x5d0330. Display animation sentinels0/-1 are represented by null.
        //The normal-instance branch accepts only0 as a fallback, not-1.
        public static PathSceneMatrix Transform(PathSceneReference r)
        {if(r.Normal!=null)return r.Normal.Animation==null?r.Normal.Matrix:r.Normal.Animation.Matrix;if(r.Display==null)return null;return r.Display.Animation==null?r.Display.Matrix:r.Display.Animation.Matrix;}
        //0x5d0420. Does not test scene visibility or scene presence.
        public static PathSceneAnimation Animation(PathSceneReference r)
        {return r.Normal!=null?r.Normal.Animation:r.Display==null?null:r.Display.Animation;}
    }
    public sealed class PathAttachmentWorld
    {
        public CorridorPath Path;
        public ushort[] AngleTable;
        public readonly Dictionary<uint,PathSceneReference> References=new Dictionary<uint,PathSceneReference>();
        public readonly Dictionary<uint,ReinitializationRecord[]> Adjacency=new Dictionary<uint,ReinitializationRecord[]>();
        //The registered9238d8 callback is unresolved. It may repair this reference
        //or modify point state. Null is the original unregistered-callback branch.
        public Func<PathAttachmentWorld,ReinitializationRecord,bool> ResolveUnavailable;
    }
    public static class PathPointRefresh
    {
        static float Add(float a,float b)
        {return a==0&&b==0?PcObjectImage.FromBits(PcObjectImage.ToBits(a)&PcObjectImage.ToBits(b)&0x80000000u):PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static float Sub(float a,float b)
        {return a==0&&b==0?PcObjectImage.FromBits(PcObjectImage.ToBits(a)&~PcObjectImage.ToBits(b)&0x80000000u):PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();}
        static SpawnVector Position(ReinitializationRecord p){return new SpawnVector(p.F32(4),p.F32(8),p.F32(12));}
        static void EdgeFlags(ReinitializationRecord e,uint mask,bool set)
        {for(int p=0;p<=4;p+=4)e.Set32(p,set?e.U32(p)|mask:e.U32(p)&~mask);}
        //0x51af40. Valid records within the original contiguous5c-stride backing.
        public static void Update(PathAttachmentWorld world,ReinitializationRecord point)
        {
            if(point.U8(0x2a)==0)return;CorridorPath path=world.Path;
            int index=checked((int)((point.Identity-path.Points[0].Identity)/0x5c));int bit=1<<(index&7);
            if((path.RefreshedBits[index>>3]&bit)!=0)return;path.RefreshedBits[index>>3]|=(byte)bit;
            if((point.U8(0x2b)&4)!=0)
            {
                if(!PathSceneBindings.Visible(world.References[point.Identity]))return;point.Set8(0x2b,point.U8(0x2b)&~4);
                for(int i=0;i<point.U8(0x28);i++){ReinitializationRecord edge=world.Adjacency[point.Identity][i];int other=edge.U8(0x10)==index?edge.U8(0x11):edge.U8(0x10);if((path.Points[other].U8(0x2b)&4)==0)EdgeFlags(edge,0x10000000,false);}
            }
            else if(!PathSceneBindings.Visible(world.References[point.Identity])&&(world.ResolveUnavailable==null||!world.ResolveUnavailable(world,point)))
            {
                point.Set8(0x2b,point.U8(0x2b)|4);for(int i=0;i<point.U8(0x28);i++)EdgeFlags(world.Adjacency[point.Identity][i],0x10000000,true);return;
            }
            SpawnVector old=Position(point);PathSceneMatrix matrix=PathSceneBindings.Transform(world.References[point.Identity]);
            if(matrix==null)throw new ArgumentException("Successful attachment resolution requires a valid transform.");
            float[] local={point.F32(0x4c),point.F32(0x50),point.F32(0x54)};float[] transformed=SceneAnimationBounds.TransformPoint(matrix.Values,local);
            for(int i=0;i<3;i++)point.Set32(4+4*i,PcObjectImage.ToBits(transformed[i]));point.Set32(0x18,PcObjectImage.ToBits(Add(point.F32(0x1c),point.F32(8))));point.Set32(0x20,PcObjectImage.ToBits(Add(point.F32(0x24),point.F32(8))));
            for(int i=0;i<point.U8(0x28);i++)
            {
                ReinitializationRecord edge=world.Adjacency[point.Identity][i];int first=edge.U8(0x10),second=edge.U8(0x11);ReinitializationRecord other=path.Points[first==index?second:first];
                SpawnVector a=Position(path.Points[second]),b=Position(path.Points[first]);float dx=Sub(a.X,b.X),dz=Sub(a.Z,b.Z),length=SpatialConditions.DistanceXZ(a,b);edge.Set32(0x1c,PcObjectImage.ToBits(length));ushort heading=PathAngles.StoredHeading(dx,dz,world.AngleTable);edge.Set8(0x12,heading);edge.Set8(0x13,heading>>8);
                if(edge.F32(0x20)!=0){PlaybackWide limit=PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.From(point.F32(0x10)),PlaybackWide.From(edge.F32(0x20))),PlaybackWide.From(other.F32(0x10)));PlaybackWide difference=PlaybackWide.Add(PlaybackWide.From(length),PlaybackWide.Multiply(limit,PlaybackWide.From(-1)));EdgeFlags(edge,0x08000000,difference.StoreDouble()>0);}
            }
            bool moved=old.X!=point.F32(4)||old.Y!=point.F32(8)||old.Z!=point.F32(12);
            if(!moved){PathSceneAnimation animation=PathSceneBindings.Animation(world.References[point.Identity]);moved=animation!=null&&(animation.Flags50&1)!=0&&animation.Speed40!=0;}
            point.Set8(0x2b,moved?point.U8(0x2b)|2:point.U8(0x2b)&~2);
        }
        //Host wiring only, not an additional mapped native helper.
        public static void Attach(PathAttachmentWorld world)
        {world.Path.Refresh=delegate(CorridorPath path,ReinitializationRecord point){Update(world,point);};}
    }
}
