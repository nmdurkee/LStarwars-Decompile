using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PodCurveEvaluation
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
  static float RAdd(float a,float b){return(N.From(a)+N.From(b)).Store();}
  static float RSub(float a,float b){return(N.From(a)-N.From(b)).Store();}
  static float RMul(float a,float b){return(N.From(a)*N.From(b)).Store();}
  public static SpawnVector NormalizeStored(SpawnVector v)
  {
   float square=FiniteX87.Dot3PlusConstant(v.X,v.Y,v.Z,v.X,v.Y,v.Z,0),length=(float)Math.Sqrt(square),reciprocal=length<=0?0:(N.From(1)/N.From(length)).Store();return new SpawnVector(RMul(reciprocal,v.X),RMul(reciprocal,v.Y),RMul(reciprocal,v.Z));
  }
  static float[] Ghost(OriginPathMemory m,uint p,uint q)
  {
   float[] a=m.Vector(p),b=m.Vector(q);SpawnVector unit=NormalizeStored(new SpawnVector(RSub(a[0],b[0]),RSub(a[1],b[1]),RSub(a[2],b[2])));float[]v={unit.X,unit.Y,unit.Z};for(int j=0;j<3;j++)v[j]=RAdd(a[j],RMul(v[j],10));return v;
  }
  public static void Normalized(OriginPathMemory m,uint curve,uint output,float parameter)
  {
   int count=unchecked((int)m.U32(curve+0x400));if(count<2||count>64)throw new ArgumentOutOfRangeException("count","Prepared native control backing requires2..64 points.");float scaled=RMul(count-1,parameter);int original=PlaybackWide.From(scaled).TruncateInt32();float f=RSub(scaled,original);int index=original;float[] before;
   if(index<=0){before=Ghost(m,curve,curve+0x10);index=0;}else{if(index>count-1)index=count;before=m.Vector(curve+(uint)index*0x10-0x10);}
   uint current=curve+(uint)index*0x10;float[] after=index<count-2?m.Vector(curve+(uint)(index+2)*0x10):Ghost(m,curve+(uint)(count-1)*0x10,curve+(uint)(count-2)*0x10),p=m.Vector(current),q=m.Vector(current+0x10);float[]twice=new float[3],linear=new float[3],quadratic=new float[3],cubic=new float[3];
   for(int j=0;j<3;j++){twice[j]=RAdd(p[j],p[j]);linear[j]=RMul(RSub(q[j],before[j]),f);quadratic[j]=RSub(RAdd(RSub(RAdd(before[j],before[j]),RMul(p[j],5)),RMul(q[j],4)),after[j]);cubic[j]=RAdd(RSub(RMul(RSub(p[j],q[j]),3),before[j]),after[j]);}
   N square=N.From(f)*N.From(f);float squared=square.Store(),cubed=(square*N.From(f)).Store();
   for(int j=0;j<3;j++){quadratic[j]=RMul(quadratic[j],squared);cubic[j]=RMul(cubic[j],cubed);}
   for(int j=0;j<3;j++)m.SetFloat(output+(uint)j*4,RMul(RAdd(RAdd(RAdd(linear[j],twice[j]),quadratic[j]),cubic[j]),.5f));
   //Native reads the W components after all XYZ stores, preserving shifted aliases.
   float nextW=m.F32(current+0x1c),currentW=m.F32(current+0xc);m.SetFloat(output+0xc,((N.From(nextW)-N.From(currentW))*N.From(f)+N.From(currentW)).Store());
  }
  public static void Distance(OriginPathMemory m,uint curve,uint output,float distance)
  {
   if(distance>=m.F32(curve+0x410)){Normalized(m,curve,output,1);return;}int count=unchecked((int)m.U32(curve+0x400));float parameter=distance;
   for(int j=0;j<count;j++){float end=m.F32(curve+0x414+(uint)j*4);if(distance<end){float previous=j==0?0:m.F32(curve+0x410+(uint)j*4);float ratio=((N.From(distance)-N.From(previous))/(N.From(end)-N.From(previous))).Store();parameter=((N.From(ratio)+N.From(j))/N.From(count)).Store();break;}}
   Normalized(m,curve,output,parameter);
  }
 }
}
