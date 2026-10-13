using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PodMatrixMath
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator-(N a){return Make(PlaybackWide.Multiply(a.v,PlaybackWide.From(-1)),!a.neg);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N operator/(N a,N b){return Make(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static void Rotate(OriginPathMemory m,uint matrix,int angle,float[] sine,int first,int second,bool minus)
  {
   if(sine==null||sine.Length!=32768)throw new ArgumentException("Complete runtime sine table required.");N s=N.From(sine[(angle>>1)&32767]),c=N.From(sine[(unchecked(angle+0x4000)>>1)&32767]);float[]a=m.Vector(matrix+(uint)first*0x10),b=m.Vector(matrix+(uint)second*0x10),aa=new float[3],bb=new float[3];
   for(int j=0;j<3;j++){N x=N.From(a[j]),y=N.From(b[j]);aa[j]=(minus?c*x-s*y:c*x+s*y).Store();bb[j]=(minus?c*y+s*x:c*y-s*x).Store();}
   m.SetVector(matrix+(uint)first*0x10,aa);m.SetVector(matrix+(uint)second*0x10,bb);
  }
  public static void RotateY(OriginPathMemory m,uint matrix,int angle,float[]sine){Rotate(m,matrix,angle,sine,0,2,true);}
  public static void RotateX(OriginPathMemory m,uint matrix,int angle,float[]sine){Rotate(m,matrix,angle,sine,1,2,false);}
  public static void RotateZ(OriginPathMemory m,uint matrix,int angle,float[]sine){Rotate(m,matrix,angle,sine,0,1,false);}
  public static void TransformVector(OriginPathMemory m,uint output,uint input,uint matrix)
  {
   float[]v=m.Vector(input),r0=m.Vector(matrix),r1=m.Vector(matrix+0x10),r2=m.Vector(matrix+0x20);N x=N.From(v[0]),y=N.From(v[1]),z=N.From(v[2]);float a=(N.From(r0[1])*y+N.From(r0[0])*x+N.From(r0[2])*z).Store(),b=(N.From(r1[0])*x+N.From(r1[1])*y+N.From(r1[2])*z).Store(),c=(N.From(r2[0])*x+N.From(r2[1])*y+N.From(r2[2])*z).Store();m.SetVector(output,new float[]{a,b,c});
  }
 }
}
