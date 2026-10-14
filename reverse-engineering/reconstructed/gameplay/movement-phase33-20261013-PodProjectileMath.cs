using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PodProjectileMath
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
  static float Sub(float a,float b){return(N.From(a)-N.From(b)).Store();}
  static float Length(float x,float y,float z){N a=N.From(x),b=N.From(y),c=N.From(z);float square=(a*a+b*b+c*c).Store();return(float)Math.Sqrt(square);}
  // 5b4500: the three translation copies precede every identity store.
  public static void MatrixOrigin(OriginPathMemory m,uint output,uint origin)
  {
   for(uint j=0;j<3;j++)m.Set32(output+0x30+j*4,m.U32(origin+j*4));
   foreach(uint j in new uint[]{0x2c,0x24,0x20,0x1c,0x18,0x10,0xc,8,4})m.Set32(output+j,0);
   foreach(uint j in new uint[]{0x3c,0x28,0x14,0})m.Set32(output+j,0x3f800000);
  }
  // 5b3c50: optional output participates in subsequent live reads under aliases.
  public static float DistanceSquared(OriginPathMemory m,uint a,uint b,uint output)
  {
   float x,y,z;if(output!=0){m.SetFloat(output,Sub(m.F32(a),m.F32(b)));m.SetFloat(output+4,Sub(m.F32(a+4),m.F32(b+4)));z=Sub(m.F32(a+8),m.F32(b+8));m.SetFloat(output+8,z);y=m.F32(output+4);x=m.F32(output);}else{x=Sub(m.F32(a),m.F32(b));y=Sub(m.F32(a+4),m.F32(b+4));z=Sub(m.F32(a+8),m.F32(b+8));}N nx=N.From(x),ny=N.From(y),nz=N.From(z);return(nx*nx+ny*ny+nz*nz).Store();
  }
  // 5d02e0: legacy branch wins; backend scale adds its sphere-vector length.
  public static float SpriteScale(OriginPathMemory m,uint handle)
  {
   uint legacy=m.U32(handle+4);if(legacy!=0){uint header=m.U32(legacy+0x40);short index=unchecked((short)(m.U8(header+0x40)|(m.U8(header+0x41)<<8)));uint scene=m.U32(handle),table=m.U32(scene+0x18),record=m.U32(unchecked(table+(uint)(index*4)));return m.F32(record+0x14);}
   uint modern=m.U32(handle+8);float length=Length(m.F32(modern+0xa0),m.F32(modern+0xa4),m.F32(modern+0xa8));modern=m.U32(handle+8);return(N.From(length)+N.From(m.F32(modern+0xac))).Store();
  }
  // 49f630: three predictor iterations, then horizontal travel time and heading.
  public static void Aim(OriginPathMemory m,uint output,uint origin,uint target,uint velocity,float speed,float gravity,float delta,float[] sine,ushort[] angles)
  {
   if(sine==null||sine.Length!=32768||angles==null||angles.Length!=513)throw new ArgumentException("Exact native sine and angle tables required.");
   float[] predicted=m.Vector(target);
   for(int i=0;i<3;i++)
   {
    float dx=Sub(predicted[0],m.F32(origin)),dy=predicted[1],dz=Sub(predicted[2],m.F32(origin+8));float time=(N.From(Length(dx,dy,dz))/N.From(speed)).Store();
    for(uint j=0;j<3;j++)predicted[j]=(N.From(m.F32(target+j*4))+N.From(time)*N.From(m.F32(velocity+j*4))).Store();
   }
   float x=Sub(predicted[0],m.F32(origin)),z=Sub(predicted[2],m.F32(origin+8));float timeFlat=(N.From(Length(x,0,z))/N.From(speed)).Store(),height=Sub(predicted[1],m.F32(origin+4));float y=(N.From(height)/(N.From(timeFlat)+N.From(delta))-N.From(gravity)*N.From(.5f)*N.From(timeFlat)).Store();
   int angle=PathAngles.Direction(x,z,angles)&65535;float vx=(N.From(sine[(angle>>1)&32767])*N.From(speed)).Store(),vz=(N.From(speed)*N.From(sine[((angle+0x4000)>>1)&32767])).Store();m.SetFloat(output,vx);m.SetFloat(output+4,y);m.SetFloat(output+8,vz);
  }
 }
}
