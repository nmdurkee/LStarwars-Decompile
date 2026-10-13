// PC tree visibility, retaining explicit prepared planes and native stack residue.
//0x5b30a0 writes three radius components;0x5d8b60 reads an uninitialized fourth.
using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Geometry
{
    public sealed class TreeVisibilityPlanes
    {
        public float[] Outer,Inner,AbsOuter,AbsInner,Depth,AbsDepth;
        public float Near,GlobalFar;
    }
    public struct TreeVisibilityBounds
    {
        public Point3 Center,Extent;
        public TreeVisibilityBounds(Point3 center,Point3 extent){Center=center;Extent=extent;}
    }
    public struct TreeVisibilityNode
    {
        public ushort Bound,FullMemberCount,ChildCount,FirstChild,LeafMemberCount,FirstMember;
        public TreeVisibilityNode(ushort bound,ushort full,ushort children,ushort firstChild,ushort leaf,ushort firstMember)
        {Bound=bound;FullMemberCount=full;ChildCount=children;FirstChild=firstChild;LeafMemberCount=leaf;FirstMember=firstMember;}
    }
    public sealed class TreeVisibilityData
    {
        public TreeVisibilityNode[] Nodes;
        public TreeVisibilityBounds[] NodeBounds,ItemBounds;
        public ushort[] Members,Roots;
        public float[] FarLimits;
    }
    public struct TreeVisibilityVisit
    {
        public TreeVisibilityBounds Bounds;
        public float Far;
        public bool Individual;
        public TreeVisibilityVisit(TreeVisibilityBounds bounds,float far,bool individual){Bounds=bounds;Far=far;Individual=individual;}
    }
    public sealed class TreeVisibilityRuntime
    {
        public SchedulingState CurrentContext;
        public bool PlanesInitialized;
    }
    public static class TreeVisibility
    {
        private static void Matrix(float[] v,int length)
        {if(v==null||v.Length!=length)throw new ArgumentException("Invalid prepared tree planes.");foreach(float f in v)NativeFrustum.Finite(f);}
        private static void Planes(TreeVisibilityPlanes p)
        {if(p==null)throw new ArgumentNullException("p");Matrix(p.Outer,16);Matrix(p.Inner,16);Matrix(p.AbsOuter,16);Matrix(p.AbsInner,16);Matrix(p.Depth,4);Matrix(p.AbsDepth,4);NativeFrustum.Finite(p.Near);NativeFrustum.Finite(p.GlobalFar);}
        private static float Dot(Point3 p,float[] m,int j,float constant)
        {return FiniteX87.Dot3PlusConstant(p.X,p.Y,p.Z,m[j],m[j+4],m[j+8],constant);}
        private static void Bounds(TreeVisibilityBounds b)
        {NativeFrustum.CheckPoint(b.Center);NativeFrustum.CheckPoint(b.Extent);if(b.Extent.X<0||b.Extent.Y<0||b.Extent.Z<0)throw new ArgumentException("Negative extent outside tree domain.");}
        // Original0x5d8b60. FourthRadiusWord is the exact preexisting native
        //local+0x3c word. It is deliberately NOT a fourth extent projection.
        public static int Classify(TreeVisibilityPlanes p,TreeVisibilityBounds b,float far,bool individual,uint fourthRadiusWord)
        {
            Planes(p);Bounds(b);NativeFrustum.Finite(far);float stale=PcObjectImage.FromBits(fourthRadiusWord);NativeFrustum.Finite(stale);
            float radius=FiniteX87.Dot3PlusConstant(b.Extent.X,b.Extent.Y,b.Extent.Z,p.AbsDepth[0],p.AbsDepth[1],p.AbsDepth[2],0);
            float projected=FiniteX87.Dot3PlusConstant(b.Center.X,b.Center.Y,b.Center.Z,p.Depth[0],p.Depth[1],p.Depth[2],0);
            // There is a float spill BEFORE adding the camera-plane constant.
            float depth=(float)((double)projected+p.Depth[3]);float farOffset=(float)((double)depth-far),nearOffset=(float)((double)depth-p.Near);
            if(!(farOffset<=radius&&-radius<=nearOffset))return 0;
            float[] d=new float[4],r=new float[4];bool inside=true;
            for(int j=0;j<4;++j){d[j]=Dot(b.Center,p.Outer,j,p.Outer[12+j]);r[j]=j==3?stale:Dot(b.Extent,p.AbsOuter,j,p.AbsOuter[12+j]);if(!(d[j]<=r[j]))return 0;if(!(d[j]<=-r[j]))inside=false;}
            if(inside)return !individual&&(-radius<farOffset||nearOffset<radius)?2:1;
            if(individual)
            {
                inside=true;
                for(int j=0;j<4;++j){d[j]=Dot(b.Center,p.Inner,j,p.Inner[12+j]);r[j]=j==3?stale:Dot(b.Extent,p.AbsInner,j,p.AbsInner[12+j]);if(!(d[j]<=r[j]))return 0;if(!(d[j]<=-r[j]))inside=false;}
                if(inside)return 1;
            }
            return 2;
        }
        private static void Range(int start,int count,int length)
        {if(start<0||count<0||start>length||count>length-start)throw new ArgumentException("Tree range outside resolved arrays.");}
        private static void Validate(TreeVisibilityData t,byte[] bits)
        {
            if(t==null||t.Nodes==null||t.NodeBounds==null||t.ItemBounds==null||t.Members==null||t.Roots==null||t.FarLimits==null||bits==null)throw new ArgumentNullException();
            if(t.Nodes.Length>65535||t.Roots.Length>65535||t.Roots.Length!=t.FarLimits.Length)throw new ArgumentException("Invalid native u16 tree arrays.");
            foreach(ushort root in t.Roots)if(root>=t.Nodes.Length)throw new ArgumentException("Invalid root.");
            foreach(float f in t.FarLimits)NativeFrustum.Finite(f);
            foreach(ushort i in t.Members)if((i>>2)>=bits.Length)throw new ArgumentException("Member outside packed two-bit output.");
            foreach(TreeVisibilityNode n in t.Nodes){if(n.Bound>=t.NodeBounds.Length)throw new ArgumentException("Invalid node bound.");Range(n.FirstChild,n.ChildCount,t.Nodes.Length);Range(n.FirstMember,n.FullMemberCount,t.Members.Length);Range(n.FirstMember,n.LeafMemberCount,t.Members.Length);Range(n.FirstMember,n.LeafMemberCount,t.ItemBounds.Length);}
        }
        private static void Or(byte[] bits,int member,int value){bits[member>>2]|=(byte)(value<<((member&3)*2));}
        // Original0x5d8e20: rootIndex arrives in ECX,tree pointer on stack.
        // Residue supplier exposes the native uninitialized-local dependency.
        // Visits occur before classification and are available for exact replay.
        public static void TraverseRoot(TreeVisibilityData t,int rootIndex,TreeVisibilityPlanes p,byte[] bits,Func<TreeVisibilityVisit,uint> residue)
        {
            Validate(t,bits);Planes(p);if(rootIndex<0||rootIndex>=t.Roots.Length||residue==null)throw new ArgumentException("Root/residue source required.");
            float far=t.FarLimits[rootIndex];if(far==0)far=p.GlobalFar;
            int[] stack=new int[100];int count=1;stack[0]=t.Roots[rootIndex];int visits=0;
            while(count!=0)
            {
                if(++visits>100000)throw new ArgumentException("Cyclic or excessive tree outside bounded domain.");
                TreeVisibilityNode node=t.Nodes[stack[--count]];TreeVisibilityBounds b=t.NodeBounds[node.Bound];var visit=new TreeVisibilityVisit(b,far,false);int result=Classify(p,b,far,false,residue(visit));
                if(result==0)continue;
                if(result==1){for(int i=0;i<node.FullMemberCount;++i)Or(bits,t.Members[node.FirstMember+i],1);continue;}
                if(node.ChildCount>100-count)throw new ArgumentException("Native100-entry pending-node stack exceeded.");
                for(int i=0;i<node.ChildCount;++i)stack[count++]=node.FirstChild+i;
                for(int i=0;i<node.LeafMemberCount;++i){int member=node.FirstMember+i;b=t.ItemBounds[member];visit=new TreeVisibilityVisit(b,far,true);result=Classify(p,b,far,true,residue(visit));Or(bits,t.Members[member],result);}
            }
        }
        // Original0x5d8fb0 context gate and reverse-root composition, with the
        //actual numerical plane producer represented by supplied prepared state.
        //Packed bits are workspace/context+0x20,NOT instance-tree bits+0x24.
        public static void ProducePrepared(SchedulingState context,bool enabled,TreeVisibilityData tree,TreeVisibilityPlanes p,byte[] bits,TreeVisibilityRuntime runtime,Func<TreeVisibilityVisit,uint> residue)
        {
            if(context==null||runtime==null)throw new ArgumentNullException();bool active=enabled&&tree!=null;context.ContextFlags=active?context.ContextFlags|16u:context.ContextFlags&~16u;if(!active)return;
            runtime.CurrentContext=context;runtime.PlanesInitialized=true;
            Validate(tree,bits);Planes(p);
            for(int root=tree.Roots.Length-1;root>=0;--root)TraverseRoot(tree,root,p,bits,residue);
        }
        // Host composition into the recovered dispatcher. Caller resolves the
        //workspace token to packed bits and supplies exact finite stack residue.
        public static Action<SceneVisibilityPreparationCall> PreparedService(TreeVisibilityData tree,TreeVisibilityPlanes planes,byte[] bits,TreeVisibilityRuntime runtime,Func<TreeVisibilityVisit,uint> residue)
        {return delegate(SceneVisibilityPreparationCall call){ProducePrepared(call.State,call.Options.TreeEnabled,tree,planes,bits,runtime,residue);};}
    }
}
