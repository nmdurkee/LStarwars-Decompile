using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlQuadraticRoots {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Neg(N a){return new N(PlaybackWide.Multiply(a.v,PlaybackWide.FromDouble(-1)),!a.neg);}
   public static N Sub(N a,N b){return Add(a,Neg(b));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public bool Negative{get{return v.StoreDouble()<0;}}
   public bool IsZero{get{return Zero;}}
   public uint Store(){uint w=Bits(v.Store());return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static uint Compute(uint a,uint b,uint c,out uint first,out uint second,out bool repeated){first=second=0;repeated=false;if((a&0x7fffffff)==0){if((b&0x7fffffff)==0)return 0;first=second=N.Divide(N.Neg(N.Word(c)),N.Word(b)).Store();repeated=true;return 1;}N av=N.Word(a),bv=N.Word(b),product=N.Mul(N.Mul(N.Integer(4),av),N.Word(c)),square=N.Mul(bv,bv);N difference=N.Sub(square,product);if(difference.Negative)return 0;N denominator=N.Add(av,av);if(difference.IsZero){first=second=N.Divide(N.Neg(bv),denominator).Store();repeated=true;return 1;}uint discriminant=difference.Store();N root=N.Word(Bits(BuildEffectSound.SquareRoot(F(discriminant))));first=N.Divide(N.Sub(N.Neg(bv),root),denominator).Store();second=N.Divide(N.Sub(root,bv),denominator).Store();return 1;}
  // Private-stack value projection used by original callers; no separate address credit.
  public static uint Values(uint a,uint b,uint c,out uint first,out uint second){bool repeated;return Compute(a,b,c,out first,out second,out repeated);}
  // 653840 complete body. Linear/equal roots write second then first; distinct roots write first then second.
  public static uint Solve(SoundSetupImage m,uint a,uint b,uint c,uint firstOutput,uint secondOutput){uint first,second;bool repeated;uint result=Compute(a,b,c,out first,out second,out repeated);if(result==0)return 0;if(repeated){m.Word(secondOutput,second);m.Word(firstOutput,first);}else{m.Word(firstOutput,first);m.Word(secondOutput,second);}return 1;}
 }
}
