// Actual registered game-origin callback43c3a0, with finite x87 stores and live cache flags.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptLine
 {
  static float F(uint v){float x=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite prepared origin arithmetic required.");return x;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static float Product(float a,float b){if(a==0||b==0)return F((B(a)^B(b))&0x80000000);return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Sum(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Products(float a,float b,float c,float d){if((a==0||b==0)&&(c==0||d==0))return F((B(a)^B(b))&(B(c)^B(d))&0x80000000);return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(d))).Store();}

  static float Difference(float a,float b){if(a==0&&b==0)return F(B(a)&(B(b)^0x80000000)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();}
  static float[] Vector(TakeoverReleaseMemory m,uint p){return new float[]{F(m.Read32(p)),F(m.Read32(p+4)),F(m.Read32(p+8))};}
  static float Dot(float[] a,float[] b){if((a[0]==0||b[0]==0)&&(a[1]==0||b[1]==0)&&(a[2]==0||b[2]==0))return Sum(Sum(Product(a[0],b[0]),Product(a[1],b[1])),Product(a[2],b[2]));return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a[0]),PlaybackWide.From(b[0])),PlaybackWide.Multiply(PlaybackWide.From(a[1]),PlaybackWide.From(b[1]))),PlaybackWide.Multiply(PlaybackWide.From(a[2]),PlaybackWide.From(b[2]))).Store();}
  //5BFAE0 cdecl(first,second,point,optionalClosest), ST0 binary32 squared distance. Infinite line, no segment clamping.
  public static uint SquaredDistance(TakeoverReleaseMemory m,uint first,uint second,uint point,uint closest)
  {
   float[] a=Vector(m,first),b=Vector(m,second);float[] normal=new float[]{Difference(b[0],a[0]),Difference(b[1],a[1]),Difference(b[2],a[2])};float square=Dot(normal,normal);float length=(float)Math.Sqrt(square);if(length==0||Single.IsInfinity(length))throw new ArgumentException("Finite nondegenerate line length required.");float inverse=PlaybackWide.Divide(PlaybackWide.From(1),PlaybackWide.From(length)).Store();
   for(int i=0;i<3;i++)normal[i]=Product(normal[i],inverse);float[] query=Vector(m,point);a=Vector(m,first);float[] offset=new float[]{Difference(query[0],a[0]),Difference(query[1],a[1]),Difference(query[2],a[2])};float projection=Dot(offset,normal);float[] position=new float[3];for(int i=0;i<3;i++){float delta=Product(normal[i],projection);position[i]=Sum(F(m.Read32(first+(uint)i*4)),delta);}
   query=Vector(m,point);float[] difference=new float[]{Difference(position[0],query[0]),Difference(position[1],query[1]),Difference(position[2],query[2])};uint result=B(Dot(difference,difference));if(closest!=0)for(uint i=0;i<3;i++)m.Write32(closest+i*4,B(position[i]));return result;
  }
  //5BFC30: wrapper supplies a null optionalClosest to the same body.
  public static uint WithoutProjection(TakeoverReleaseMemory m,uint first,uint second,uint point){return SquaredDistance(m,first,second,point,0);}
 }
}
