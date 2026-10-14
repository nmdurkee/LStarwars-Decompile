// Raw GoToOrigin536330 with actual origin cache, full intent/formation and finite exact x87 stores.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptGoToOrigin
 {
  static float F(uint x){float v=BitConverter.ToSingle(BitConverter.GetBytes(x),0);if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite prepared origin values required.");return v;}
  static uint B(float x){return TakeoverReleaseMemory.Bits(x);}static PlaybackWide W(float x){return PlaybackWide.From(x);}
  static float Sum(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(W(a),W(b)).Store();}
  static float ProductSum(float a,float b,float c,float d){if((a==0||b==0)&&(c==0||d==0))return F((B(a)^B(b))&(B(c)^B(d))&0x80000000);return PlaybackWide.Add(PlaybackWide.Multiply(W(a),W(b)),PlaybackWide.Multiply(W(c),W(d))).Store();}
  static float Square(TakeoverReleaseMemory m,uint a,uint b,bool xz){float x=Sum(F(m.Read32(a)),-F(m.Read32(b))),y=xz?0:Sum(F(m.Read32(a+4)),-F(m.Read32(b+4))),z=Sum(F(m.Read32(a+8)),-F(m.Read32(b+8)));return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(W(x),W(x)),PlaybackWide.Multiply(W(y),W(y))),PlaybackWide.Multiply(W(z),W(z))).Store();}
  static float Draw(TakeoverReleaseMemory m){return(PreparedScriptFormationRandomRow.Draw(m)&0x7fffff)/8388608f;}
  public static uint Execute(TakeoverReleaseMemory m,ScriptFollowServices follow,ScriptCircleServices tokens,ScriptExpressionServices symbols,ScriptOriginServices origins,uint system,uint packet,uint actor,uint args,int count,uint first,uint delta)
  {
   if(actor==0||m.Read32(actor+0xd0)==0||m.Read32(actor+0x158)==0||m.Read32(actor+0x15c)==0||(m.Read32(m.Read32(actor+0xd0)+0x1f8)&0x400)==0||m.Read8(actor+0x138)==255)return 1;
   uint record=unchecked(m.Read32(system+0x18)+(uint)m.Read8(actor+0x138)*0xa4),point=0,callback=m.Read32(0x923908);if(callback!=0)point=origins.Origin(m,callback,system,actor);if(point==0)point=record+0x20;
   if(first!=0)
   {
    m.Write32(actor+0x180,0x3e4ccccd);float minimum=0,maximum=0;
    for(int i=0;i<count;i++){callback=m.Read32(0x9238b0);if(callback!=0&&tokens.Token(m,callback,m.Read32(args+(uint)i*4),actor+0x13f)!=0)continue;uint at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x760be4);if(at!=0)m.Write32(packet+0x9c,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,at+PreparedScriptByteStrings.Length(m,0x760be4)+1));else{at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x7581bc);if(at!=0)minimum=F(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,at+PreparedScriptByteStrings.Length(m,0x7581bc)+1));else{at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x7581b4);if(at!=0)maximum=F(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,at+PreparedScriptByteStrings.Length(m,0x7581b4)+1));else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+(uint)i*4),0x760bd4))m.Write8(packet+0x69,1);else{at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x757994);m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,at!=0?at+PreparedScriptByteStrings.Length(m,0x757994)+1:m.Read32(args+(uint)i*4)));}}}}
    if(F(m.Read32(packet+0x9c))==0){float wait=maximum<=minimum?.01f:PlaybackWide.Add(PlaybackWide.Multiply(W(Draw(m)),PlaybackWide.Add(W(maximum),W(-minimum))),W(minimum)).Store();m.Write32(packet+0x9c,B(wait));}
    PreparedScriptFollow.SetIntent(m,follow,actor,point,0,record+0x30,1,m.Read32(actor+0x180));m.Write32(packet+0x78,0);m.Write32(packet+0x7c,0);m.Write32(packet+0x80,0x3f800000);int angle=unchecked((int)m.Read32(record+0x2c));float sine=F(m.Read32(0x29899a0+((uint)(angle>>1)&0x7fff)*4)),cosine=F(m.Read32(0x29899a0+((uint)(unchecked(angle+0x4000)>>1)&0x7fff)*4));float x=F(m.Read32(packet+0x78)),y=F(m.Read32(packet+0x7c)),z=F(m.Read32(packet+0x80));m.Write32(packet+0x78,B(ProductSum(sine,z,cosine,x)));m.Write32(packet+0x7c,B(y));m.Write32(packet+0x80,B(ProductSum(cosine,z,-sine,x)));for(uint i=0;i<3;i++)m.Write32(packet+0x78+i*4,B(Sum(F(m.Read32(packet+0x78+i*4)),F(m.Read32(point+i*4)))));return 0;
   }
   PreparedScriptFollow.SetIntent(m,follow,actor,point,0,record+0x30,1,m.Read32(actor+0x180));float distance=Square(m,actor+0x14c,point,m.Read8(packet+0x69)!=0),basis=Sum(F(m.Read32(0x801c6c)),F(m.Read32(actor+0x180)));float threshold=PlaybackWide.Add(PlaybackWide.Multiply(W(F(delta)),W(F(m.Read32(m.Read32(actor+0xd0)+0x22c)))),W(basis)).Store();double thresholdSquare=PlaybackWide.Multiply(W(threshold),W(threshold)).StoreDouble();if((double)distance<thresholdSquare){m.Write32(actor+0x1e4,packet+0x78);float wait=F(m.Read32(packet+0x9c));if(wait<=0)return 1;wait=Sum(wait,-F(delta));m.Write32(packet+0x9c,B(wait));if(wait<0)m.Write32(packet+0x9c,0);}return 0;
  }
 }
}
