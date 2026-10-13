using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class PodHeadingWorld
 {
  public OriginPathMemory Memory;
  public float[] SineTable;
  public ushort[] AngleTable;
  public float Delta;
 }
 public static class PodHeadingCommands
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
  static int Short(int v){return unchecked((short)v);}
  static int Angle(PodHeadingWorld w,float a,float b){return Short(PathAngles.Direction(a,b,w.AngleTable));}
  static N Sin(PodHeadingWorld w,int angle){return N.From(w.SineTable[(angle>>1)&32767]);}
  static N Cos(PodHeadingWorld w,int angle){return N.From(w.SineTable[(unchecked(angle+0x4000)>>1)&32767]);}
  static float[] VectorY(PodHeadingWorld w,float[]v,int angle){N s=Sin(w,angle),c=Cos(w,angle),x=N.From(v[0]),z=N.From(v[2]);return new float[]{(s*z+c*x).Store(),v[1],(z*c-x*s).Store()};}
  static float[] VectorX(PodHeadingWorld w,float[]v,int angle){N s=Sin(w,angle),c=Cos(w,angle),y=N.From(v[1]),z=N.From(v[2]);return new float[]{v[0],(c*y-s*z).Store(),(s*y+c*z).Store()};}
  public static void VectorZ(OriginPathMemory m,uint output,uint input,int angle,float[]table)
  {
   N s=N.From(table[(angle>>1)&32767]),c=N.From(table[(unchecked(angle+0x4000)>>1)&32767]),x=N.From(m.F32(input));m.SetFloat(output,(c*x-s*N.From(m.F32(input+4))).Store());m.SetFloat(output+4,(x*s+c*N.From(m.F32(input+4))).Store());m.Set32(output+8,m.U32(input+8));
  }
  public static void Apply(PodHeadingWorld w,uint pod,uint direction,float factor,int mode,uint scratch)
  {
   if(w.SineTable==null||w.SineTable.Length!=32768||w.AngleTable==null||w.AngleTable.Length!=513)throw new ArgumentException("Exact runtime sine andnative513word angle tables required.");var m=w.Memory;PodMatrixMath.TransformVector(m,scratch,direction,pod);float[]v=m.Vector(scratch);int yaw=Angle(w,v[0],v[2]);m.Set32(pod+0x74,unchecked((uint)yaw));v=VectorY(w,v,-yaw);m.SetVector(scratch,v);int pitch=Angle(w,v[1],v[2]);m.Set32(pod+0x70,unchecked((uint)pitch));PodMatrixMath.RotateY(m,pod,yaw,w.SineTable);PodMatrixMath.RotateX(m,pod,-pitch,w.SineTable);
   if(mode!=0){PodMatrixMath.RotateZ(m,pod,512,w.SineTable);return;}
   float[]fresh=m.Vector(direction);int rawYaw=Angle(w,fresh[0],fresh[2]);float[]flat=VectorY(w,fresh,-rawYaw);int rawPitch=Angle(w,flat[1],flat[2]);m.SetVector(scratch+0x10,new float[]{1,0,0});int curveAngle=Short(PlaybackWide.From(m.F32(pod+0x5c)).TruncateInt32());VectorZ(m,scratch+0x10,scratch+0x10,curveAngle+0x4000,w.SineTable);float[]roll=VectorX(w,m.Vector(scratch+0x10),-rawPitch);roll=VectorY(w,roll,rawYaw);m.SetVector(scratch+0x10,roll);PodMatrixMath.TransformVector(m,scratch+0x20,scratch+0x10,pod);roll=m.Vector(scratch+0x20);int bank=Angle(w,roll[0],roll[1]);PlaybackWide high=PlaybackWide.Multiply(PlaybackWide.From(w.Delta),PlaybackWide.From(24000)),low=PlaybackWide.Multiply(PlaybackWide.From(w.Delta),PlaybackWide.From(-24000));if(bank>high.StoreDouble())bank=Short(high.TruncateInt32());if(bank<low.StoreDouble())bank=Short(low.TruncateInt32());float bankFloat=bank;if(factor>2)bankFloat=0;else if(factor>1)bankFloat=((N.From(2)-N.From(factor))*N.From(bankFloat)).Store();int final=Short(PlaybackWide.From(bankFloat).TruncateInt32());PodMatrixMath.RotateZ(m,pod,-final,w.SineTable);
  }
 }
}
