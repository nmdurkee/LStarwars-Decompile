using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class SteeringPath
    {
        public uint Identity;
        //All three views share point identities/backing and connection topology.
        public TargetingPath Targeting;
        public CorridorPath Corridor;
        public RoutingPath Routing;
    }
    public sealed class PathSteeringWorld
    {
        public uint ContextIdentity,OwnerIdentity;
        public PcObjectImage Owner;
        public ushort[] AngleTable;
        public ActorPathBindingWorld Binding;
        public readonly Dictionary<uint,SteeringPath> Paths=new Dictionary<uint,SteeringPath>();
        public readonly Dictionary<uint,PcObjectImage> References=new Dictionary<uint,PcObjectImage>();
        //51d5e0 can compose PathTransitions.Select with a loaded neighboring
        //path world. This batch verifies call/restore ordering, not that join.
        public Action<PathSteeringWorld> Transition;
        //Registered9238fc callback. Existing PathActionDispatch supplies three
        //recovered variants; host maps owner/reference identities and services.
        public Func<PathSteeringWorld,PcObjectImage,uint,int> Special;
    }
    public static class PathSteering
    {
        const int P=0x2c8;
        struct W
        {
            PlaybackWide exact;double approximate;
            public W(float v){exact=PlaybackWide.From(v);approximate=v;}
            static W Make(PlaybackWide e,double d){return new W{exact=e,approximate=d};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approximate+b.approximate);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(PlaybackWide.From(-1),b.exact)),a.approximate-b.approximate);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approximate*b.approximate);}
            public static W operator /(W a,W b){return Make(PlaybackWide.Divide(a.exact,b.exact),a.approximate/b.approximate);}
            public float Store(){float v=exact.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximate)<0?0x80000000u:0u):v;}
            public bool Positive(){return exact.StoreDouble()>0;}
        }
        static uint Get(PcObjectImage a,int at){return a.U32(P+at);}
        static float F(PcObjectImage a,int at){return a.F32(P+at);}
        static int B(PcObjectImage a,int at){return a.U8(P+at);}
        static void Set(PcObjectImage a,int at,uint v){a.Set32(P+at,v);}
        static void Flag(PcObjectImage a,uint bits){Set(a,0x1e8,Get(a,0x1e8)|bits);}
        static ushort Word(ReinitializationRecord p,int at){return (ushort)(p.U8(at)|p.U8(at+1)<<8);}
        static ushort Shift(int b){return b<16?(ushort)(1<<b):(ushort)0;}
        static SpawnVector Read(PcObjectImage a,int at){return new SpawnVector(a.F32(at),a.F32(at+4),a.F32(at+8));}
        static SpawnVector Position(ReinitializationRecord n){return new SpawnVector(n.F32(4),n.F32(8),n.F32(12));}
        static SpawnVector Subtract(SpawnVector a,SpawnVector b){return new SpawnVector((new W(a.X)-new W(b.X)).Store(),(new W(a.Y)-new W(b.Y)).Store(),(new W(a.Z)-new W(b.Z)).Store());}
        static void Output(PcObjectImage a,SpawnVector p,float radius){a.SetFloat(P+0x104,p.X);a.SetFloat(P+0x108,p.Y);a.SetFloat(P+0x10c,p.Z);a.SetFloat(P+0x110,radius);}
        static ReinitializationRecord Edge(PathSteeringWorld w,uint id){return id==0?null:w.Binding.Connections[id];}
        static SteeringPath Current(PathSteeringWorld w){return w.Paths[Get(w.Owner,0x158)];}
        static int Ensure(PathSteeringWorld w){return PathTargeting.EnsureTarget(Current(w).Targeting,w.Owner);}
        static void Bind(PathSteeringWorld w,PcObjectImage reference,ReinitializationRecord e,uint direction){ActorPathBinding.Bind(w.Binding,w.Owner,reference.F32(0x5c),reference.F32(0x64),e.Identity,direction);}
        static bool Contains(PathSteeringWorld w,ReinitializationRecord e,SpawnVector query,ReinitializationRecord previous,float margin,uint stamp){return PathCorridor.Contains(Current(w).Corridor,e,query,previous,(uint)B(w.Owner,0x13c),margin,stamp,null);}
        //Synchronize the typed route-cache view with the shared native records.
        //This is host projection glue, not an additional native helper mapping.
        static void RouteInput(PathSteeringWorld w,SteeringPath path)
        {
            for(int i=0;i<path.Routing.Points.Length;i++){ReinitializationRecord p=path.Corridor.Points[i];RoutingPoint q=path.Routing.Points[i];q.Membership58=Word(p,0x58);q.Boundary5a=Word(p,0x5a);q.CacheDestination0=p.U8(0x2e);q.CacheDestination1=p.U8(0x2f);q.CacheDistance0=p.F32(0x38);q.CacheDistance1=p.F32(0x3c);}
            foreach(KeyValuePair<uint,RoutingConnection> row in path.Routing.Connections){ReinitializationRecord e=w.Binding.Connections[row.Key];row.Value.Endpoint0=e.U8(0x10);row.Value.Endpoint1=e.U8(0x11);row.Value.RouteMask=Word(e,0x14);row.Value.Distance=e.F32(0x18);}
        }
        static void RouteOutput(SteeringPath path)
        {for(int i=0;i<path.Routing.Points.Length;i++){ReinitializationRecord p=path.Corridor.Points[i];RoutingPoint q=path.Routing.Points[i];p.Set8(0x2e,q.CacheDestination0);p.Set8(0x2f,q.CacheDestination1);p.Set32(0x38,PcObjectImage.ToBits(q.CacheDistance0));p.Set32(0x3c,PcObjectImage.ToBits(q.CacheDistance1));}}
        static float Distance(PathSteeringWorld w,int start,int end){SteeringPath p=Current(w);RouteInput(w,p);float v=PathRouting.Distance(p.Routing,start,end,B(w.Owner,0x13c),0);RouteOutput(p);return v;}
        static ReinitializationRecord Next(PathSteeringWorld w,ref uint direction)
        {
            PcObjectImage a=w.Owner;SteeringPath path=Current(w);uint dest=Get(a,0x17c);int? index=null;if(dest!=0){for(int i=0;i<path.Corridor.Points.Length;i++)if(path.Corridor.Points[i].Identity==dest){index=i;break;}if(!index.HasValue)throw new ArgumentException("Loaded aligned destination point required.");}
            RouteInput(w,path);uint next=PathRouting.NextConnection(path.Routing,Get(a,0x15c),(byte)B(a,0x160),(byte)B(a,0x13c),index,ref direction);RouteOutput(path);return Edge(w,next);
        }
        static void Restore(PcObjectImage a,int[] offsets,uint[] saved){for(int i=0;i<offsets.Length;i++)Set(a,offsets[i],saved[i]);}
        static void Fallback(PathSteeringWorld w,SteeringPath cached,PcObjectImage reference)
        {PcObjectImage a=w.Owner;ReinitializationRecord e=Edge(w,Get(a,0x15c));SpawnVector p=Position(cached.Corridor.Points[e.U8(0x10+(B(a,0x160)==0?1:0))]);Output(a,LocatorCommands.DistanceSquared(p,Read(reference,0x5c),false)<1?Read(reference,0x5c):p,0);Flag(a,0x400000);}
        //0x51d7b0: full caller logic for finite static/pre-refreshed backing.
        //It writes a steering target/radius and state flags, not actor motion.
        public static void Update(PathSteeringWorld world,PcObjectImage reference,uint queryIdentity)
        {
            PcObjectImage a=world.Owner;int[] savedOffsets={0x1b4,0x1b8,0x1bc,0x1c0,0x1c4,0x1cc,0x1d0,0x1d4,0x1d8,0x1dc,0x1e0};uint[] saved=new uint[savedOffsets.Length];for(int i=0;i<saved.Length;i++)saved[i]=Get(a,savedOffsets[i]);int status=Ensure(world);
            if(status<0){Output(a,Read(world.References[Get(a,0xd0)],0x5c),0);return;}
            SteeringPath path=Current(world);ReinitializationRecord old=Edge(world,Get(a,0x15c)),target=Edge(world,Get(a,0x1d0));SpawnVector delta=Subtract(Read(a,P+0x1b4),Read(reference,0x5c));float distance=LocatorCommands.DistanceSquared(Read(a,P+0x1b4),Read(reference,0x5c),false),radius=F(a,0x1c4);
            bool attachment=reference.U16(0x27e)!=65535,dynamic=!attachment||(path.Corridor.Points[old.U8(0x10)].U8(0x2a)!=0&&path.Corridor.Points[old.U8(0x11)].U8(0x2a)!=0);
            if(dynamic&&radius!=0&&delta.Y<.5f&&delta.Y>-.5f&&(new W(radius)*new W(radius)-new W(distance)).Positive())
            {
                if(status==0){Output(a,Read(reference,0x5c),0);return;}
                if((B(a,0x1ec)&4)!=0){Restore(a,savedOffsets,saved);world.Transition(world);Ensure(world);path=Current(world);old=Edge(world,Get(a,0x15c));target=Edge(world,Get(a,0x1d0));}
            }
            if(old==null||target==null){Output(a,Read(world.References[Get(a,0xd0)],0x5c),0);return;}
            uint direction=0;
            if(Get(a,0x15c)!=Get(a,0x1d0))
            {
                ReinitializationRecord current=Edge(world,Get(a,0x15c));if(Contains(world,target,Read(a,P+0x14c),current,reference.F32(0xac),0)){direction=(uint)(target.U8(0x10)==current.U8(0x10)||target.U8(0x10)==current.U8(0x11)?0:1);Bind(world,reference,target,direction);}
                if(Get(a,0x15c)!=Get(a,0x1d0))
                {
                    direction=(uint)B(a,0x160);float best=Single.MaxValue,progress=F(a,0x168);if(progress>1)progress=1;else if(progress<0)progress=0;float[] costs={Math.Abs((new W(old.F32(0x18))*new W(progress)).Store()),Math.Abs((new W(old.F32(0x18))*(new W(1)-new W(progress))).Store())};float costA=(new W(F(a,0x1dc))*new W(target.F32(0x18))).Store(),costB=((new W(1)-new W(F(a,0x1dc)))*new W(target.F32(0x18))).Store();int destination=target.U8(0x10);uint visited=0;if(B(a,0x13c)!=255)Flag(a,0x100000);
                    while(true)
                    {
                        costA=Math.Abs(costA);costB=Math.Abs(costB);int route=B(a,0x13c);ushort mask=Shift(route);
                        if(route!=255&&(Word(target,0x14)&mask)==0){ReinitializationRecord p=path.Corridor.Points[target.U8(0x10)];if((~Word(p,0x5a)&Word(p,0x58)&mask)!=0)costA=Single.MaxValue;p=path.Corridor.Points[target.U8(0x11)];if((~Word(p,0x5a)&Word(p,0x58)&mask)!=0)costB=Single.MaxValue;}
                        for(int turn=0;turn<2;turn++)
                        {
                            int currentDirection=B(a,0x160),opposite=currentDirection==0?1:0,departure=turn==0?opposite:currentDirection,blocked=turn==0?currentDirection:opposite;uint proposed=(uint)(turn==0?currentDirection:opposite);if((old.U32(blocked*4)&0x40000000)!=0)continue;
                            for(int end=0;end<2;end++){float cost=end==0?costA:costB,candidate=Single.MaxValue;if(cost!=Single.MaxValue&&costs[departure]!=Single.MaxValue){float d=Distance(world,old.U8(0x10+departure),target.U8(0x10+end));if(d!=Single.MaxValue)candidate=(new W(costs[departure])+new W(cost)+new W(d)).Store();}if(candidate<best){best=candidate;direction=proposed;destination=target.U8(0x10+end);Set(a,0x1e8,Get(a,0x1e8)&~0x100000u);}}
                        }
                        if((Get(a,0x1e8)&0x100000)==0)break;if(route!=255)visited|=1u<<(route&31);ActorPathBinding.SelectRoute(world.Binding,a);if((visited&(1u<<(B(a,0x13c)&31)))!=0)return;costA=(new W(F(a,0x1dc))*new W(target.F32(0x18))).Store();costB=((new W(1)-new W(F(a,0x1dc)))*new W(target.F32(0x18))).Store();
                    }
                    Set(a,0x17c,path.Corridor.Points[destination].Identity);Bind(world,reference,old,direction);ReinitializationRecord previous=null,next=Next(world,ref direction);
                    if(next==null){uint required=(target.U32(0)|target.U32(4))&0xdfffffffu;if((required&0xd8000000)==0&&(required==0||(Get(a,0x1f4)&required)!=0)&&Contains(world,target,Read(a,P+0x14c),Edge(world,Get(a,0x15c)),reference.F32(0xac),0))Bind(world,reference,target,0);}
                    else while(next!=null){if(next==previous||!Contains(world,next,Read(a,P+0x14c),Edge(world,Get(a,0x15c)),reference.F32(0xac),0)||old==target)break;previous=next;Bind(world,reference,next,direction);old=next;if(Get(a,0x15c)!=next.Identity||B(a,0x160)!=direction)break;next=Next(world,ref direction);}
                }
            }
            if(world.Special!=null){if(old!=target)Flag(a,0x20000000);if(world.Special(world,reference,queryIdentity)!=0){Flag(a,0x40080000);return;}}
            ReinitializationRecord selected=Edge(world,Get(a,0x15c));direction=(uint)B(a,0x160);uint requirement=selected.U32((int)direction*4);
            if((requirement&0xd8000000)!=0){Output(a,Position(path.Corridor.Points[selected.U8(0x10+(int)direction)]),0);Flag(a,0x400000);Set(a,0x1f8,requirement);return;}
            if(selected==target&&(B(a,0x13c)==255||(Word(target,0x14)&Shift(B(a,0x13c)))!=0))
            {
                if((B(a,0x166)&1)==0||F(a,0x1c4)==0){Output(a,Read(a,P+0x1b4),F(a,0x1c0));return;}
                if((new W(F(a,0x1c4))*new W(F(a,0x1c4))-new W(distance)).Positive()){if(status==0){Output(a,Read(reference,0x5c),0);return;}if((B(a,0x1ec)&4)!=0){Restore(a,savedOffsets,saved);world.Transition(world);Ensure(world);}}
                float length=BuildEffectSound.SquareRoot(distance),scale=(new W(F(a,0x1c4))/new W(length)).Store();SpawnVector p=Read(a,P+0x1b4);p.X=(new W(p.X)-new W((new W(delta.X)*new W(scale)).Store())).Store();p.Z=(new W(p.Z)-new W((new W(delta.Z)*new W(scale)).Store())).Store();Output(a,p,F(a,0x1c4)<=F(a,0x1c0)?F(a,0x1c0):0);return;
            }
            int common=-1;direction=0;for(int i=0;i<2&&common<0;i++)for(int j=0;j<2;j++)if(selected.U8(0x10+i)==target.U8(0x10+j)){common=selected.U8(0x10+i);direction=(uint)j;break;}
            ReinitializationRecord future=target;if(common<0||(B(a,0x13c)!=255&&((Word(target,0x14)|Word(path.Corridor.Points[common],0x5a))&Shift(B(a,0x13c)))==0))future=Next(world,ref direction);
            if(future==null){Fallback(world,path,reference);return;}
            requirement=future.U32((int)direction*4);
            if((requirement&0xdfffffff)!=0){if((requirement&0xd8000000)!=0){Output(a,Read(reference,0x5c),0);Flag(a,0x400000);Set(a,0x1f8,requirement);return;}if((Get(a,0x1f4)&requirement)==0){Flag(a,0x600000);Set(a,0x1f8,requirement);Fallback(world,path,reference);return;}Set(a,0x1ec,Get(a,0x1ec)|1);}
            SpawnVector result=future==target?Read(a,P+0x1b4):Position(path.Corridor.Points[future.U8(0x10+(int)direction)]);if(future!=target)Flag(a,0x80000);
            if(Contains(world,selected,result,Edge(world,Get(a,0x15c)),reference.F32(0xac),0)){Output(a,result,0);return;}
            if(!PathCorners.Update(Current(world).Corridor,a,selected,future,reference.F32(0xac)))result=Position(path.Corridor.Points[future.U8(0x10+(int)direction)]);
            else for(int i=0;i<2;i++){uint mask=i==0?0x40u:0x20u;if((Get(a,0x1e8)&mask)==0)continue;SpawnVector corner=Read(a,P+(i==0?0x1a4:0x198)),d1=Subtract(corner,Read(reference,0x5c)),d2=Subtract(result,Read(reference,0x5c));int difference=PathCornerMath.DifferenceAngles(PathAngles.Direction(d2.X,d2.Z,world.AngleTable),PathAngles.Direction(d1.X,d1.Z,world.AngleTable));if(i==0?difference<0:difference>0){result=corner;Flag(a,0x80000);break;}}
            Output(a,result,0);
        }
    }
}
