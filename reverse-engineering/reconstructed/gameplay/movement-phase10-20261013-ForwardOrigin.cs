using System;
using Recovered.Animation;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Gameplay
{
 public sealed class ForwardOriginWorld
 {
  public OriginPathWorld Movement;
  public bool HasPlayer=true;
  public ScriptPacket Numbers;
  public readonly ScriptRandom FloatRandom=new ScriptRandom();
  public readonly LocatorIntegerRandom IntegerRandom=new LocatorIntegerRandom();
 }
 public static class ForwardOriginCommands
 {
  const double TurnScale=182.04444885253906;
  struct N
  {
   Wide v;bool neg;
   static N Make(Wide w,bool zero){double d=w.StoreDouble();return new N{v=w,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=Wide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N operator+(N a,N b){return Make(Wide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator*(N a,N b){return Make(Wide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static int Truncate(float f){if(Single.IsNaN(f)||Single.IsInfinity(f)||(double)f< -2147483648.0||(double)f>=2147483648.0)throw new ArgumentOutOfRangeException("f");return(int)f;}
  static int Turn(ForwardOriginWorld w,uint packet,string text)
  {
   if(w.Numbers!=null)for(int i=0;i<4;i++)w.Numbers.Parameters[i]=w.Movement.Memory.F32(packet+0x14+(uint)i*4);
   int degrees=Truncate(MessageNumbers.Resolve(w.Numbers,text));
   if(Math.Abs((double)degrees)>1000000)throw new ArgumentOutOfRangeException("degrees","Bounded native signed conversion domain.");
   return Wide.Multiply(Wide.FromDouble(degrees),Wide.FromDouble(TurnScale)).TruncateInt32();
  }
  static string Tail(string t,int at,int skip){if(at+skip>t.Length)throw new ArgumentException("Native skip exceeds terminator.");return t.Substring(at+skip);}
  static float[] Ahead(OriginPathWorld w,int heading)
  {
   if(w.SineTable==null||w.SineTable.Length!=32768)throw new ArgumentException("32768 runtime sine words required.");
   N s=N.From(w.SineTable[(heading>>1)&32767]),c=N.From(w.SineTable[((unchecked(heading+0x4000))>>1)&32767]);
   return new float[]{(s*N.From(10)+c*N.From(0)).Store(),0,(N.From(10)*c+N.From(PcObjectImage.FromBits(0x80000000u))*s).Store()};
  }
  static float[] Add(float[] a,float[] b){return new float[]{(N.From(a[0])+N.From(b[0])).Store(),(N.From(a[1])+N.From(b[1])).Store(),(N.From(a[2])+N.From(b[2])).Store()};}
  //0x4527e0. Actor pointer is captured before callbacks; never completes itself.
  public static bool MoveForward(ForwardOriginWorld w,uint packet,uint creature,string[] tokens,bool first,uint scratchPoint)
  {
   if(!w.HasPlayer||creature==0)return false;OriginPathMemory m=w.Movement.Memory;uint reference=m.U32(creature+0xd0);if(reference==0)return false;uint actor=m.U32(reference);if(actor==0)return false;
   if(first)
   {
    m.SetFloat(packet+0x70,(float)(m.U8(actor+0x27a)|m.U8(actor+0x27b)<<8));
    if(tokens!=null&&tokens.Length>0)
    {
     int minimum=0,maximum=0,turn=0;bool randomDirection=false;
     foreach(string token in tokens)
     {
      MessageNumbers.RequireAscii(token);if(w.Movement.MovementToken!=null&&w.Movement.MovementToken(token,creature+0x13f))continue;int at;
      if((at=token.IndexOf("min_turn",StringComparison.OrdinalIgnoreCase))>=0)minimum=Turn(w,packet,Tail(token,at,9));
      else if((at=token.IndexOf("max_turn",StringComparison.OrdinalIgnoreCase))>=0)maximum=Turn(w,packet,Tail(token,at,9));
      else if(token.IndexOf("rand_turn_dir",StringComparison.OrdinalIgnoreCase)>=0)randomDirection=true;
      else if((at=token.IndexOf("turn",StringComparison.OrdinalIgnoreCase))>=0)turn=Turn(w,packet,Tail(token,at,5));
     }
     if(maximum!=0){int span=unchecked(maximum-minimum);turn=unchecked(Wide.Multiply(Wide.From(w.FloatRandom.Next()),Wide.FromDouble(span)).TruncateInt32()+minimum);}
     if(turn!=0)
     {
      if(randomDirection&&(w.IntegerRandom.Next(null)&1)!=0)turn=unchecked(-turn);
      int current=Truncate(m.F32(packet+0x70));int angle=unchecked(current+turn)&65535;if(angle>=32768)angle-=65536;m.SetFloat(packet+0x70,angle);
     }
    }
   }
   if((m.U8(creature+0x166)&1)!=0)
   {
    float[] point=Add(Ahead(w.Movement,Truncate(m.F32(packet+0x70))),m.Vector(actor+0x5c));
    // scratchPoint is caller-owned backing for the native stack temporary.
    m.SetVector(scratchPoint,point);OriginPathCommands.SetIntent(w.Movement,creature,scratchPoint,0,creature+0x158,1,.01f);
   }
   return false;
  }
  //0x515360. Origin callback precedes world/spawn fallback guards; no reference chain gate.
  public static float OriginRange(OriginPathWorld w,uint world,uint creature)
  {
   if(creature==0)return 0;uint origin=w.OriginPosition==null?0:w.OriginPosition(world,creature);
   if(origin==0)
   {
    if(world==0||w.Memory.U8(creature+0x138)==255)return 0;
    origin=w.Memory.U32(world+0x18)+(uint)w.Memory.U8(creature+0x138)*0xa4+0x20;
   }
   float[] a=w.Memory.Vector(creature+0x14c),b=w.Memory.Vector(origin);
   // Original null-scratch5becc0 has the same ordered float32-difference/sum/sqrt stores.
   return LocatorRandomConditions.Distance(new SpawnVector(a[0],a[1],a[2]),new SpawnVector(b[0],b[1],b[2]));
  }
 }
}
