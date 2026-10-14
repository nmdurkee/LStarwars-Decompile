using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class PodProjectileContext
 {
  public uint SpriteHandle,Template,Target;
  public float Range,Amplitude,TargetSpeed,ProjectileSpeed,Gravity,RangeLimit,TimerCenter,TimerSpread;
  public uint[] InitialDirection=new uint[3];
  public ScriptRandom Random;
  // 64d270 actor/projectile construction is the remaining lifecycle boundary.
  public Action<uint> Spawn;
 }
 public static class PodFrameUpdate
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N D(double f){return new N{v=PlaybackWide.FromDouble(f),neg=BitConverter.DoubleToInt64Bits(f)<0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator-(N a){return Make(PlaybackWide.Multiply(a.v,PlaybackWide.From(-1)),!a.neg);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N operator/(N a,N b){return Make(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public double Wide(){return v.StoreDouble();}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static void Difference(OriginPathMemory m,uint pod,out float[]d,out float square,out float dot)
  {
   d=new float[3];for(uint j=0;j<3;j++)d[j]=(N.From(m.F32(pod+0x50+j*4))-N.From(m.F32(pod+0x30+j*4))).Store();N x=N.From(d[0]),y=N.From(d[1]),z=N.From(d[2]);square=(y*y+x*x+z*z).Store();dot=(y*N.From(m.F32(pod+0x24))+x*N.From(m.F32(pod+0x20))+z*N.From(m.F32(pod+0x28))).Store();
  }
  public static void CommitPose(OriginPathMemory m,uint pod)
  {
   m.SetFloat(pod+0x3c,1);uint actor=m.U32(pod+0x90);if(actor==0)return;for(uint j=0;j<16;j++)m.Set32(actor+0xc04+j*4,m.U32(pod+j*4));actor=m.U32(pod+0x90);m.Set32(actor+0x5c,m.U32(actor+0xc34));m.Set32(actor+0x60,m.U32(actor+0xc38));m.Set32(actor+0x64,m.U32(actor+0xc3c));actor=m.U32(pod+0x90);for(uint j=0;j<3;j++)m.Set32(actor+0x10bc+j*4,m.U32(actor+0x5c+j*4));
  }

  static ushort Word16(OriginPathMemory m,uint p){return(ushort)(m.U8(p)|(m.U8(p+1)<<8));}
  static void RotateY(PodFrameWorld w,uint vector,ushort angle)
  {
   var m=w.Memory;N s=N.From(w.SineTable[angle>>1]),c=N.From(w.SineTable[((angle+0x4000)>>1)&32767]),x=N.From(m.F32(vector)),z=N.From(m.F32(vector+8));float nx=(s*z+c*x).Store(),nz=(z*c-x*s).Store();m.SetFloat(vector,nx);m.SetFloat(vector+8,nz);
  }
  static void AddVector(OriginPathMemory m,uint output,uint a,uint b){for(uint j=0;j<3;j++)m.SetFloat(output+j*4,(N.From(m.F32(a+j*4))+N.From(m.F32(b+j*4))).Store());}
  static void Projectile(PodFrameWorld w,PodProjectileContext p,uint pod,uint scratch)
  {
   if(p==null)throw new ArgumentNullException("projectile");var m=w.Memory;if(m.U32(p.SpriteHandle+4)==0&&m.U32(p.SpriteHandle+8)==0)return;uint actor=m.U32(pod+0x90);m.SetFloat(actor+0x1090,(N.From(m.F32(actor+0x1090))-N.From(w.Delta)).Store());actor=m.U32(pod+0x90);if(!(m.F32(actor+0x1090)<0))return;
   uint target=p.Target,origin=scratch,difference=scratch+0x10,landing=scratch+0x20,velocity=scratch+0x30,direction=scratch+0x40,matrix=scratch+0x80,arguments=scratch+0xc0;
   m.Set32(origin,m.U32(actor+0x5c));m.SetFloat(origin+4,(N.From(m.F32(actor+0x60))+N.From(1)).Store());m.Set32(origin+8,m.U32(actor+0x64));if(target==0)return;
   for(uint j=0;j<3;j++)m.Set32(direction+j*4,p.InitialDirection[j]);float distance=PodProjectileMath.DistanceSquared(m,target+0x80,actor+0x80,difference);
   if(distance>(N.From(p.Range)*N.D(4)*N.From(p.Range)).Wide())
   {
    N amplitude=N.From(p.Amplitude);float random=p.Random.Next();m.SetFloat(landing,(amplitude-(amplitude+amplitude)*N.From(random)).Store());m.Set32(landing+4,0);m.SetFloat(landing+8,p.Range);RotateY(w,landing,Word16(m,target+0x696));AddVector(m,landing,landing,p.Target+0x80);
    m.Set32(velocity,0);m.Set32(velocity+4,0);m.SetFloat(velocity+8,p.TargetSpeed);RotateY(w,velocity,Word16(m,target+0x696));PodProjectileMath.Aim(m,direction,origin,landing,velocity,p.ProjectileSpeed,p.Gravity,w.Delta,w.SineTable,w.AngleTable);
    if(distance>(N.From(p.RangeLimit)*N.From(p.RangeLimit)).Wide())
    {
     m.Set32(direction+4,0);SpawnVector unit=PodCurveEvaluation.NormalizeStored(new SpawnVector(m.F32(direction),m.F32(direction+4),m.F32(direction+8)));m.SetFloat(direction,unit.X);m.SetFloat(direction+4,unit.Y);m.SetFloat(direction+8,unit.Z);for(uint j=0;j<3;j++)m.SetFloat(direction+j*4,(N.From(m.F32(direction+j*4))*N.From(p.RangeLimit)).Store());AddVector(m,landing,origin,direction);for(uint j=0;j<3;j++)m.Set32(velocity+j*4,0);PodProjectileMath.Aim(m,direction,origin,landing,velocity,p.ProjectileSpeed,p.Gravity,w.Delta,w.SineTable,w.AngleTable);
    }
   }
   PodProjectileMath.MatrixOrigin(m,matrix,origin);for(uint j=0;j<50;j++)m.Set32(arguments+j*4,m.U32(p.Template+j*4));m.Set32(arguments,matrix);m.Set32(arguments+8,direction);float scale=PodProjectileMath.SpriteScale(m,p.SpriteHandle);m.SetFloat(arguments+0x14,scale);m.SetFloat(arguments+0x18,scale);m.Set32(arguments+0x24,0x881cc8);m.Set32(arguments+0x2c,0x29a);m.Set32(arguments+0x40,0x42cf20);m.SetFloat(arguments+0x1c,p.Gravity);m.Set32(arguments+0x44,0x4d9710);m.SetFloat(arguments+0x8c,w.Delta);m.SetFloat(arguments+0xa4,5);p.Spawn(arguments);
   float next=p.Random.Next();actor=m.U32(pod+0x90);m.SetFloat(actor+0x1090,((N.From(p.TimerCenter)-N.From(p.TimerSpread))+(N.From(p.TimerSpread)+N.From(p.TimerSpread))*N.From(next)).Store());
  }
  // 4d9760 whole prepared own body, with recovered math and explicit constructor.
  public static uint Update(PodFrameWorld w,PodProjectileContext projectile,uint pod,uint scratch)
  {
   var m=w.Memory;if(m.U32(pod+0x80)==0)return 0;uint actor=m.U32(pod+0x90);if(actor==0||(m.U8(actor+0x1fc)&1)==0||m.U8(actor+0x28b)!=0){for(uint j=0;j<0xa0;j++)m.Set8(pod+j,0);return 0;}
   if(m.F32(w.TimeState+0xb000)>0){CommitPose(m,pod);return 1;}float[]d;float square,dot;Difference(m,pod,out d,out square,out dot);
   if(m.F32(pod+0x84)<=1)
   {
    int guard=0;while(square<1||dot<0){if(++guard>8192)throw new InvalidOperationException("Nonterminating look-ahead outside prepared domain.");float phase=(N.From(m.F32(pod+0x84))+N.From(w.LookAhead)).Store();m.SetFloat(pod+0x84,phase);if(phase>1){m.SetFloat(pod+0x84,1);break;}PodCurveEvaluation.Normalized(m,m.U32(pod+0x80),pod+0x50,phase);Difference(m,pod,out d,out square,out dot);}
   }
   float length=(float)Math.Sqrt(square);bool moved=false;
   if(m.F32(pod+0x84)<1)
   {
    if(length!=0)
    {
     float speed=m.F32(pod+0x7c),ratio=(N.From(m.F32(w.TimeState+0xb004))/N.From(m.F32(w.TimeState+0xb00c))).Store();if(ratio>1)ratio=1;N desired;
     if(m.U32(w.World+0x128)==w.SpecialGame&&w.SpecialMode==1){speed=(N.From(speed)/N.D((double).995f)).Store();if(ratio<.01f)desired=N.From(speed)*N.From(ratio)/N.D((double).01f);else desired=N.From(speed)*N.D(1.5)-(N.From(ratio)-N.D((double).01f))*N.From(speed);}
     else desired=N.From(speed)*N.D(1.5)-N.From(ratio)*N.From(speed);
     float target=desired.Store(),scale=(N.From(target)/N.From(length)).Store();for(uint j=0;j<3;j++)m.SetFloat(pod+0x40+j*4,(N.From(scale)*N.From(d[j])).Store());moved=true;
    }
   }
   else moved=true;
   if(moved)
   {
    for(uint j=0;j<3;j++)m.SetFloat(scratch+j*4,(N.From(w.Delta)*N.From(m.F32(pod+0x40+j*4))).Store());m.Set32(scratch+0xc,w.DisplacementW);for(uint j=0;j<3;j++)m.SetFloat(pod+0x30+j*4,(N.From(m.F32(pod+0x30+j*4))+N.From(m.F32(scratch+j*4))).Store());float factor=(N.From(length)/N.D(5)).Store();PodHeadingCommands.Apply(new PodHeadingWorld{Memory=m,SineTable=w.SineTable,AngleTable=w.AngleTable,Delta=w.Delta},pod,scratch,factor,0,scratch+0x40);for(uint j=0;j<4;j++)m.Set32(pod+0x60+j*4,m.U32(scratch+j*4));
   }
   if(m.U32(w.World+0x128)==w.ProjectileGame&&m.U32(pod+0x90)!=0&&(ushort)m.U32(pod+0x88)==w.ProjectileType)Projectile(w,projectile,pod,scratch+0x200);CommitPose(m,pod);return 1;
  }
 }
}
