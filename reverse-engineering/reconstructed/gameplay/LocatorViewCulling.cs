using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class LocatorView
 {
  public float[] ViewMatrix,PlaneMatrix;
  public float Near,Far;
 }
 public static class LocatorViewCulling
 {
  struct W
  {
   PlaybackWide exact;double approx;
   public W(float v){exact=PlaybackWide.From(v);approx=v;}
   static W Make(PlaybackWide e,double a){return new W{exact=e,approx=a};}
   public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approx+b.approx);}
   public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(b.exact,PlaybackWide.From(-1))),a.approx-b.approx);}
   public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approx*b.approx);}
   public float Store(){float value=exact.Store();return value==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approx)<0?0x80000000u:0u):value;}
   public bool Negative(){return (PcObjectImage.ToBits(exact.Store())&0x80000000u)!=0;}
  }
  static W N(float v){return new W(v);}
  // 0x5b3ec0: allfour affine columns; native computes1,2,3 before0.
  public static float[] PlaneDistances(float[] matrix,float[] point)
  {
   float[] output=new float[4];
   for(int c=0;c<4;c++)output[c]=(N(matrix[c])*N(point[0])+N(matrix[4+c])*N(point[1])+N(matrix[8+c])*N(point[2])+N(matrix[12+c])).Store();
   return output;
  }
  // 0x5d6620 returns true outside the prepared view. Matrix setup is separate.
  public static bool Outside(LocatorView view,float[] point,float radius,float[] objectMatrix)
  {
   if(objectMatrix!=null)point=SceneAnimationBounds.TransformPoint(objectMatrix,point);
   point=SceneAnimationBounds.TransformPoint(view.ViewMatrix,point);
   if((N(radius)+(N(point[2])-N(view.Near))).Negative())return true;
   if((N(radius)+(N(view.Far)-N(point[2]))).Negative())return true;
   float[] planes=PlaneDistances(view.PlaneMatrix,point);
   for(int i=0;i<4;i++)if(planes[i]<-radius)return true;
   return false;
  }
 }
}
