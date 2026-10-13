// Original PC finite tree plane production with explicit D3DX and prior-stack boundaries.
using System;
using Recovered.Animation;
using Recovered.Gameplay;
namespace Recovered.Geometry
{
 public sealed class TreePlaneInputs
 {
  public float Near,Far;
  // Globals966378,97313c,966270,96dce4 in that order.
  public float[] Scales,Template,View;
  public Point3 Direction,Position;
 }
 public sealed class TreePlaneRuntime
 {
  public float[] LocalOuter,LocalInner;
  public TreeVisibilityPlanes Prepared;
  public readonly TreeVisibilityRuntime Visibility=new TreeVisibilityRuntime();
 }
 public static class TreePlaneProduction
 {
  static void ArrayFinite(float[] values,int count)
  {if(values==null||values.Length!=count)throw new ArgumentException("Missing finite plane input array.");foreach(float v in values)NativeFrustum.Finite(v);}
  static float Mul(float a,float b){float v=(float)((double)a*b);NativeFrustum.Finite(v);return v;}
  static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
  static float InverseNorm(float component,float squaredNear)
  {
   PlaybackWide a=PlaybackWide.From(component);float squared=PlaybackWide.Add(PlaybackWide.Multiply(a,a),PlaybackWide.From(squaredNear)).Store();NativeFrustum.Finite(squared);
   float root=BuildEffectSound.SquareRoot(squared);if(!(root>0))throw new ArgumentException("Plane norm must be nonzero.");
   float inverse=PlaybackWide.Divide(PlaybackWide.From(1),PlaybackWide.From(root)).Store();NativeFrustum.Finite(inverse);return inverse;
  }
  static float[] Local(float near,float square,float widthScale,float heightScale,float[] template)
  {
   float width=Mul(near,widthScale),height=Mul(near,heightScale),iw=InverseNorm(width,square),ih=InverseNorm(height,square);float[] matrix=(float[])template.Clone();
   matrix[0]=Mul(Neg(near),iw);matrix[1]=Neg(matrix[0]);matrix[8]=Mul(Neg(width),iw);matrix[9]=matrix[8];
   matrix[6]=Mul(near,ih);matrix[7]=Neg(matrix[6]);matrix[10]=Mul(Neg(height),ih);matrix[11]=matrix[10];return matrix;
  }
  //0x5d86f0. Original5b44c0 copies a runtime template, not a literal identity.
  public static void BuildLocal(TreePlaneInputs input,TreePlaneRuntime runtime)
  {
   if(input==null||runtime==null)throw new ArgumentNullException();NativeFrustum.Finite(input.Near);if(!(input.Near>0))throw new ArgumentException("Finite positive near plane required.");ArrayFinite(input.Scales,4);ArrayFinite(input.Template,16);
   runtime.Visibility.PlanesInitialized=true;float squared=Mul(input.Near,input.Near);
   runtime.LocalOuter=Local(input.Near,squared,input.Scales[0],input.Scales[1],input.Template);runtime.LocalInner=Local(input.Near,squared,input.Scales[2],input.Scales[3],input.Template);
  }
  static float DepthConstant(Point3 direction,Point3 position)
  {
   PlaybackWide y=PlaybackWide.Multiply(PlaybackWide.From(direction.Y),PlaybackWide.From(position.Y)),x=PlaybackWide.Multiply(PlaybackWide.From(direction.X),PlaybackWide.From(position.X)),z=PlaybackWide.Multiply(PlaybackWide.From(direction.Z),PlaybackWide.From(position.Z));
   float dot=PlaybackWide.Add(PlaybackWide.Add(y,x),z).Store();
   // Exact signed zero when all three extended products are zero; cancellation
   // of nonzero products produces positive zero under native round-to-nearest.
   if((direction.X==0||position.X==0)&&(direction.Y==0||position.Y==0)&&(direction.Z==0||position.Z==0))
   {
    bool nx=((PcObjectImage.ToBits(direction.X)^PcObjectImage.ToBits(position.X))&0x80000000u)!=0,ny=((PcObjectImage.ToBits(direction.Y)^PcObjectImage.ToBits(position.Y))&0x80000000u)!=0,nz=((PcObjectImage.ToBits(direction.Z)^PcObjectImage.ToBits(position.Z))&0x80000000u)!=0;
    dot=PcObjectImage.FromBits(nx&&ny&&nz?0x80000000u:0u);
   }
   NativeFrustum.Finite(dot);return Neg(dot);
  }
  static float[] Absolute(float[] input)
  {float[] output=new float[16];for(int i=0;i<12;++i)output[i]=PcObjectImage.FromBits(PcObjectImage.ToBits(input[i])&0x7fffffffu);return output;}
  //0x5d8950. Matrix multiplication is the unresolved imported D3DX boundary.
  public static TreeVisibilityPlanes Transform(TreePlaneInputs input,TreePlaneRuntime runtime,Func<float[],float[],float[]> multiply)
  {
   if(input==null||runtime==null||multiply==null)throw new ArgumentNullException();ArrayFinite(input.View,16);ArrayFinite(runtime.LocalOuter,16);ArrayFinite(runtime.LocalInner,16);NativeFrustum.CheckPoint(input.Direction);NativeFrustum.CheckPoint(input.Position);NativeFrustum.Finite(input.Near);NativeFrustum.Finite(input.Far);
   float[] outer=multiply(input.View,runtime.LocalOuter),inner=multiply(input.View,runtime.LocalInner);ArrayFinite(outer,16);ArrayFinite(inner,16);
   float[] depth={input.Direction.X,input.Direction.Y,input.Direction.Z,DepthConstant(input.Direction,input.Position)},absoluteDepth={Math.Abs(input.Direction.X),Math.Abs(input.Direction.Y),Math.Abs(input.Direction.Z),0};
   return runtime.Prepared=new TreeVisibilityPlanes{Outer=outer,Inner=inner,AbsOuter=Absolute(outer),AbsInner=Absolute(inner),Depth=depth,AbsDepth=absoluteDepth,Near=input.Near,GlobalFar=input.Far};
  }
  // Explicit finite scalar fixture adapter, not a recovered D3DX entrypoint.
  public static float[] ScalarMatrixAdapter(float[] a,float[] b)
  {
   ArrayFinite(a,16);ArrayFinite(b,16);float[] result=new float[16];for(int i=0;i<4;++i)for(int j=0;j<4;++j){double sum=0;for(int k=0;k<4;++k)sum+=(double)a[i*4+k]*b[k*4+j];result[i*4+j]=(float)sum;NativeFrustum.Finite(result[i*4+j]);}return result;
  }
  // Composition of0x5d8fb0's recovered producers and original root traversal.
  // The prior-stack residue source remains explicit: neither producer nor
  // any root/predicate initializes the fourth radius word in the actual chain.
  public static void Produce(SchedulingState context,bool enabled,TreeVisibilityData tree,TreePlaneInputs input,TreePlaneRuntime runtime,byte[] bits,Func<float[],float[],float[]> multiply,Func<TreeVisibilityVisit,uint> residue)
  {
   if(context==null||runtime==null)throw new ArgumentNullException();bool active=enabled&&tree!=null;context.ContextFlags=active?context.ContextFlags|16u:context.ContextFlags&~16u;if(!active)return;
   runtime.Visibility.CurrentContext=context;if(!runtime.Visibility.PlanesInitialized)BuildLocal(input,runtime);TreeVisibilityPlanes planes=Transform(input,runtime,multiply);
   for(int root=tree.Roots.Length-1;root>=0;--root)TreeVisibility.TraverseRoot(tree,root,planes,bits,residue);
  }
  // Explicit CPU integration binding context+20 to the selected scene clip
  // buffer, followed by the recovered0x5df910 control writer.
  public static void ProduceAndPatch(SchedulingState context,TreeVisibilityData tree,TreePlaneInputs input,TreePlaneRuntime runtime,SceneVisibility scene,byte[] items,Func<float[],float[],float[]> multiply,Func<TreeVisibilityVisit,uint> residue)
  {
   if(scene==null)throw new ArgumentNullException("scene");int parity=(int)((scene.Flags>>15)&1);Produce(context,true,tree,input,runtime,scene.ClipBits[parity],multiply,residue);SceneSubmission.PatchClipControls(scene,items);
  }
 }
}
