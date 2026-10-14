using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlParticleAttributes {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Double(double d){return new N(PlaybackWide.FromDouble(d),d<0);}
   public static N Integer(int i){return Double(i);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=Bits(v.Store());return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static void Horizontal(SoundSetupImage m,uint p,double constant){N factor=N.Double(constant);m.Word(p+16,N.Mul(N.Word(m.Word(p)),factor).Store());m.Word(p+24,N.Mul(factor,N.Word(m.Word(p+8))).Store());}
  // Original frozen binary64 constants; source input pointers and private stack are disjoint from those literal cells.
  public static void OutwardTwo(SoundSetupImage m,uint p){Horizontal(m,p,2);}
  public static void Inward(SoundSetupImage m,uint p){m.Word(p+16,m.Word(p)^0x80000000);m.Word(p+24,m.Word(p+8)^0x80000000);}
  public static void OutwardFour(SoundSetupImage m,uint p){Horizontal(m,p,4);}
  public static void OutwardSixteen(SoundSetupImage m,uint p){Horizontal(m,p,16);}
  public static void Radial(SoundSetupImage m,uint p){N factor=N.Double(5.400000095367432);m.Word(p+16,N.Mul(N.Word(m.Word(p)),factor).Store());m.Word(p+20,N.Mul(N.Word(m.Word(p+4)),factor).Store());m.Word(p+24,N.Mul(factor,N.Word(m.Word(p+8))).Store());}
  // 6e8e1e own body: TLS-context acquisition explicit; raw supplied context state and original CRT output.
  public static uint CrtRandom(SoundSetupImage m,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{uint context=service(m,0x6f040c,new uint[0]);uint s=m.Word(context+20)*214013+2531011;m.Word(context+20,s);return (s>>16)&0x7fff;}}
  // 654a00: horizontal drag, vertical displacement via existing root, then CRT-randomized reciprocal lifetime.
  public static void Gravity(SoundSetupImage m,uint record,uint p,Func<SoundSetupImage,uint,uint[],uint> service){
   N factor=N.Double(0.6000000238418579);N product=N.Mul(N.Word(m.Word(p)),factor);m.Word(p+16,N.Sub(N.Word(m.Word(p+16)),product).Store());product=N.Mul(N.Word(m.Word(p+8)),factor);m.Word(p+24,N.Sub(N.Word(m.Word(p+24)),product).Store());N y=N.Word(m.Word(p+4));N z=N.Word(m.Word(p+8)),x=N.Word(m.Word(p));uint squared=N.Add(N.Mul(z,z),N.Mul(x,x)).Store();uint root=Bits(BuildEffectSound.SquareRoot(F(squared)));m.Word(p+4,N.Sub(y,N.Mul(N.Word(root),N.Double(0.4000000059604645))).Store());
   uint random=CrtRandom(m,service);N value=N.Mul(N.Integer((int)random),N.Word(m.Word(record+0xa4)));value=N.Divide(value,N.Double(1503238528));value=N.Add(value,N.Word(m.Word(record+0xa4)));uint life=m.Word(record+0xa4);if((life&0x7fffffff)==0)m.Word(p+28,(life&0x80000000)|0x7f800000u);else m.Word(p+28,N.Divide(N.Integer(64),value).Store());
  }
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> service){switch(address){case 0x654950:OutwardTwo(m,args[2]);break;case 0x654970:Radial(m,args[2]);break;case 0x6549a0:Inward(m,args[2]);break;case 0x6549c0:OutwardFour(m,args[2]);break;case 0x6549e0:OutwardSixteen(m,args[2]);break;case 0x654a00:Gravity(m,args[1],args[2],service);break;case 0x6e8e1e:return CrtRandom(m,service);default:return service(m,address,args);}return 0;}
 }
}
