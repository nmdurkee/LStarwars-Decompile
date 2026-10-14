// Complete raw536700 own body. CRT sprintf and optional completion callbacks remain explicit services.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class ScriptLocatorServices
 {
  public abstract byte[] Format(TakeoverReleaseMemory m,uint format,uint first,uint second,int arguments);
  public abstract uint Complete(TakeoverReleaseMemory m,uint callback,uint controller,uint point);
 }
 public static class PreparedScriptGoToLocator
 {

  static float F(uint x){float v=BitConverter.ToSingle(BitConverter.GetBytes(x),0);if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite prepared origin values required.");return v;}
  static uint B(float x){return TakeoverReleaseMemory.Bits(x);}static PlaybackWide W(float x){return PlaybackWide.From(x);}
  static float Sum(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(W(a),W(b)).Store();}
  static float ProductSum(float a,float b,float c,float d){if((a==0||b==0)&&(c==0||d==0))return F((B(a)^B(b))&(B(c)^B(d))&0x80000000);return PlaybackWide.Add(PlaybackWide.Multiply(W(a),W(b)),PlaybackWide.Multiply(W(c),W(d))).Store();}
  static float Square(TakeoverReleaseMemory m,uint a,uint b,bool xz){float x=Sum(F(m.Read32(a)),-F(m.Read32(b))),y=xz?0:Sum(F(m.Read32(a+4)),-F(m.Read32(b+4))),z=Sum(F(m.Read32(a+8)),-F(m.Read32(b+8)));return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(W(x),W(x)),PlaybackWide.Multiply(W(y),W(y))),PlaybackWide.Multiply(W(z),W(z))).Store();}
  static float Draw(TakeoverReleaseMemory m){return(PreparedScriptFormationRandomRow.Draw(m)&0x7fffff)/8388608f;}

  sealed class NameMemory:TakeoverReleaseMemory
  {
   readonly TakeoverReleaseMemory m;readonly byte[] name;public NameMemory(TakeoverReleaseMemory source,byte[] value){if(value==null||value.Length>63)throw new ArgumentException("Prepared formatter result must fit64 byte local buffer.");m=source;name=value;}
   public override byte Read8(uint p){uint at=unchecked(p-0xfff80000);if(at<=name.Length)return at==name.Length?(byte)0:name[at];return m.Read8(p);}
   public override void Write8(uint p,byte value){m.Write8(p,value);}
  }
  static uint Tail(TakeoverReleaseMemory m,uint args,int i,uint key,out uint at){at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),key);return at==0?0:unchecked(at+PreparedScriptByteStrings.Length(m,key)+1);}
  static int Integer(uint value){float v=F(value);if((double)v>=9223372036854775808.0||(double)v< -9223372036854775808.0)return 0;return unchecked((int)(uint)(long)v);}
  static void Facing(TakeoverReleaseMemory m,uint packet,uint point,uint heading)
  {
   m.Write32(packet+0x78,0);m.Write32(packet+0x7c,0);m.Write32(packet+0x80,0x3f800000);int angle=unchecked((int)m.Read32(heading));float sine=F(m.Read32(0x29899a0+((uint)(angle>>1)&0x7fff)*4)),cosine=F(m.Read32(0x29899a0+((uint)(unchecked(angle+0x4000)>>1)&0x7fff)*4));float x=F(m.Read32(packet+0x78)),y=F(m.Read32(packet+0x7c)),z=F(m.Read32(packet+0x80));m.Write32(packet+0x78,B(ProductSum(sine,z,cosine,x)));m.Write32(packet+0x7c,B(y));m.Write32(packet+0x80,B(ProductSum(cosine,z,-sine,x)));for(uint i=0;i<3;i++)m.Write32(packet+0x78+i*4,B(Sum(F(m.Read32(packet+0x78+i*4)),F(m.Read32(point+i*4)))));
  }
  public static uint Execute(TakeoverReleaseMemory m,ScriptFollowServices follow,ScriptCircleServices tokens,ScriptExpressionServices symbols,ScriptLocatorServices locators,uint system,uint packet,uint actor,uint args,int count,uint first,uint delta)
  {
   if(actor==0||m.Read32(actor+0xd0)==0||m.Read32(m.Read32(actor+0xd0))==0||m.Read32(actor+0x158)==0||m.Read32(actor+0x15c)==0)return 1;
   if(first!=0)
   {
    m.Write8(packet+0x68,0);m.Write32(packet+0x6c,m.Read32(packet+0xa4));bool personal=false,indexed=false;int random=0;float minimum=0,maximum=0;
    for(int i=0;i<count;i++)
    {
     uint callback=m.Read32(0x9238b0);if(callback!=0&&tokens.Token(m,callback,m.Read32(args+(uint)i*4),actor+0x13f)!=0)continue;uint at,tail;
     if(PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x75782c)!=0||PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x75850c)!=0)
     {
      i++;if(i<count){uint owner=m.Read32(actor+0xd0),name=m.Read32(args+(uint)i*4),format=name,a=0,b=0;int n=0;sbyte index=-1;if(indexed)index=unchecked((sbyte)m.Read8(owner+0x280));if(indexed&&index!=-1){format=0x7577d4;a=name;b=unchecked((uint)(int)index);n=2;}else if(personal&&m.Read32(owner+0x54)!=0){format=0x7577cc;a=name;b=m.Read32(m.Read32(owner+0x54)+0xc);n=2;}else if(random!=0){int value=unchecked((int)PreparedScriptLocatorIntegerRandom.Draw(m,0));format=0x7577d4;a=name;b=unchecked((uint)(value%random));n=2;}byte[] bytes=locators.Format(m,format,a,b,n);var names=new NameMemory(m,bytes);m.Write32(packet+0x6c,PreparedScriptByteLookup.Locator(names,system,0xfff80000));}
      if(PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)(i-1)*4),0x75850c)!=0){uint selected=m.Read32(packet+0x6c);if(selected!=0){uint owner=m.Read32(actor+0xd0);for(uint j=0;j<3;j++)m.Write32(owner+0x5c+j*4,m.Read32(selected+0x10+j*4));}return 1;}
     }
     else if(PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x7577f4)!=0)personal=true;
     else if(PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x7577ec)!=0)indexed=true;
     else if((tail=Tail(m,args,i,0x757824,out at))!=0)random=Integer(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,tail));
     else if((tail=Tail(m,args,i,0x760be4,out at))!=0)m.Write32(packet+0x9c,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,tail));
     else if((tail=Tail(m,args,i,0x7581bc,out at))!=0)minimum=F(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,tail));
     else if((tail=Tail(m,args,i,0x7581b4,out at))!=0)maximum=F(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,tail));
     else if((tail=Tail(m,args,i,0x757994,out at))!=0)m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,tail));
     else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+(uint)i*4),0x760c24))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|1));
     else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+(uint)i*4),0x760bd4))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|2));
     else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+(uint)i*4),0x760c14))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|4));
     else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+(uint)i*4),0x760c08))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|8));
     else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+(uint)i*4),0x760bf0))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|16));
     else m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+(uint)i*4)));
    }
    if(F(m.Read32(packet+0x9c))==0)m.Write32(packet+0x9c,B(maximum<=minimum?.01f:PlaybackWide.Add(PlaybackWide.Multiply(W(Draw(m)),PlaybackWide.Add(W(maximum),W(-minimum))),W(minimum)).Store()));uint chosen=m.Read32(packet+0x6c);if(chosen==0)return 1;uint point=chosen+0x10;PreparedScriptFollow.SetIntent(m,follow,actor,point,0,chosen+0x20,(m.Read8(packet+0x68)&8)==0?1u:7u,m.Read32(actor+0x180));Facing(m,packet,point,chosen+0x1c);return 0;
   }
   uint selectedNow=m.Read32(packet+0x6c);if(selectedNow==0)return 1;uint destination=selectedNow+0x10;PreparedScriptFollow.SetIntent(m,follow,actor,destination,0,selectedNow+0x20,(m.Read8(packet+0x68)&8)==0?1u:7u,m.Read32(actor+0x180));if((m.Read8(packet+0x68)&4)!=0&&m.Read32(actor+0xe4)!=0)m.Write32(actor+0x1e4,m.Read32(actor+0xe4)+0x5c);if((m.Read8(packet+0x68)&1)!=0&&m.Read8(m.Read32(actor+0xd0)+0x281)==0)return 0;
   float distance=Square(m,actor+0x14c,destination,(m.Read8(packet+0x68)&2)!=0);uint reference=m.Read32(actor+0xd0);float basis=Sum(F(m.Read32(actor+0x180)),F(m.Read32(0x801c6c))),threshold=PlaybackWide.Add(PlaybackWide.Multiply(W(F(delta)),W(F(m.Read32(reference+0x22c)))),W(basis)).Store();if((double)distance>=PlaybackWide.Multiply(W(threshold),W(threshold)).StoreDouble()){uint completion=m.Read32(0x9238b8);if((m.Read32(actor+0x1e8)&0x400000)!=0&&(m.Read8(packet+0x68)&16)!=0&&completion!=0&&locators.Complete(m,completion,reference,destination)!=0)return 1;return 0;}
   if((m.Read8(packet+0x68)&4)==0||m.Read32(actor+0xe4)==0)m.Write32(actor+0x1e4,packet+0x78);float remaining=F(m.Read32(packet+0x9c));if(remaining<=0)return 1;remaining=Sum(remaining,-F(delta));m.Write32(packet+0x9c,B(remaining));if(remaining<0)m.Write32(packet+0x9c,0);return 0;
  }
 }
}
