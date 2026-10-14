// Complete original Circle5350e0 action, using raw token/locator/expression and game-origin services.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class ScriptCircleServices{public abstract uint Token(TakeoverReleaseMemory m,uint callback,uint token,uint actorFlags);}
 public static class PreparedScriptCircle
 {
  static float F(uint v){float x=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite circle distance required.");return x;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static float Difference(float a,float b){if(a==0&&b==0)return F(B(a)&(B(b)^0x80000000)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();}
  static uint RangeXZ(TakeoverReleaseMemory m,uint a,uint b){float x=Difference(F(m.Read32(a)),F(m.Read32(b))),z=Difference(F(m.Read32(a+8)),F(m.Read32(b+8)));float square=PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(x),PlaybackWide.From(x)),PlaybackWide.From(0)),PlaybackWide.Multiply(PlaybackWide.From(z),PlaybackWide.From(z))).Store();return B((float)Math.Sqrt(square));}
  static void Copy3(TakeoverReleaseMemory m,uint output,uint source){for(uint i=0;i<3;i++)m.Write32(output+i*4,m.Read32(source+i*4));}
  static bool Eq(TakeoverReleaseMemory m,uint args,uint i,uint key){return PreparedScriptByteLookup.Equal(m,m.Read32(args+i*4),key);}
  public static uint Execute(TakeoverReleaseMemory m,ScriptCircleServices circle,ScriptExpressionServices symbols,ScriptOriginServices origins,uint system,uint packet,uint actor,uint args,int count,uint first)
  {
   if(actor==0||system==0||m.Read32(system+0x138c)==0)return 1;
   if(first!=0)
   {
    for(int index=0;index<count;index++)
    {
     uint i=(uint)index,callback=m.Read32(0x9238b0);if(callback!=0&&circle.Token(m,callback,m.Read32(args+i*4),actor+0x13f)!=0)continue;
     if(Eq(m,args,i,0x760bbc))m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)&0xfffffdff);
     else if(Eq(m,args,i,0x760bb0))m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)|0x200);
     else if(Eq(m,args,i,0x760ba8))m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)^0x200);
     else if(Eq(m,args,i,0x760ba0))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|1));
     else if(Eq(m,args,i,0x760b94))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|4));
     else
     {
      uint found=PreparedScriptByteLookup.Substring(m,m.Read32(args+i*4),0x7581a8);
      if(found!=0){uint locator=PreparedScriptByteLookup.Locator(m,system,unchecked(found+8));m.Write32(packet+0x6c,locator);if(locator!=0)m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|0x10));}
      else if(PreparedScriptByteLookup.Substring(m,m.Read32(args+i*4),0x760b80)!=0){m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|8));Copy3(m,packet+0x78,actor+0x14c);}
      else if(Eq(m,args,i,0x75771c)){if(m.Read8(actor+0x138)!=255)m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|0x20));}
      else m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+i*4)));
     }
    }
    if((m.Read8(packet+0x68)&0x38)==0){m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|8));Copy3(m,packet+0x78,actor+0x14c);}
   }
   uint mode=m.Read8(packet+0x68),point,words;
   if((mode&8)!=0){words=actor+0x158;point=packet+0x78;}
   else if((mode&0x10)!=0){uint locator=m.Read32(packet+0x6c);words=locator+0x20;point=locator+0x10;}
   else{if((mode&0x20)==0)return 0;uint record=unchecked(m.Read32(system+0x18)+(uint)m.Read8(actor+0x138)*0xa4);words=record+0x30;uint callback=m.Read32(0x923908);point=callback==0?0:origins.Origin(m,callback,system,actor);if(point==0)point=record+0x20;}
   if(words!=0&&point!=0)
   {
    if((m.Read8(packet+0x68)&4)!=0)m.Write32(actor+0x180,RangeXZ(m,actor+0x14c,point));
    uint radius=m.Read32(actor+0x180);Copy3(m,actor+0x1b4,point);for(uint i=0;i<5;i++)m.Write32(actor+0x1cc+i*4,m.Read32(words+i*4));uint sixth=m.Read32(words+20);m.Write32(actor+0x1c0,0);m.Write32(actor+0x1c4,radius);m.Write32(actor+0x1e0,sixth);m.Write32(actor+0x1e8,(m.Read32(actor+0x1e8)&0xfffffffb)|3);
    if((m.Read8(packet+0x68)&1)!=0)m.Write32(actor+0x1e4,point);
   }
   return 0;
  }
 }
}
