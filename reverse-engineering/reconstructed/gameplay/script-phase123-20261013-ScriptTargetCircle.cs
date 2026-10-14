// Full CirclePlayer535420 and CircleOpponent5356b0 with live reference guards and token ordering.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptTargetCircle
 {
  static float F(uint v){float x=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite orbit radius and distance required.");return x;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static float Difference(float a,float b){if(a==0&&b==0)return F(B(a)&(B(b)^0x80000000)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();}
  static uint Range(TakeoverReleaseMemory m,uint a,uint b){float x=Difference(F(m.Read32(a)),F(m.Read32(b))),z=Difference(F(m.Read32(a+8)),F(m.Read32(b+8)));float square=PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(x),PlaybackWide.From(x)),PlaybackWide.From(0)),PlaybackWide.Multiply(PlaybackWide.From(z),PlaybackWide.From(z))).Store();return B((float)Math.Sqrt(square));}
  static bool Eq(TakeoverReleaseMemory m,uint args,uint i,uint key){return PreparedScriptByteLookup.Equal(m,m.Read32(args+i*4),key);}
  static uint Execute(TakeoverReleaseMemory m,ScriptCircleServices circle,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first,bool player)
  {
   if(actor==0||player&&(system==0||m.Read32(system+0x138c)==0))return 1;
   if(first!=0)for(int index=0;index<count;index++)
   {
    uint i=(uint)index,callback=m.Read32(0x9238b0);if(callback!=0&&circle.Token(m,callback,m.Read32(args+i*4),actor+0x13f)!=0)continue;
    if(Eq(m,args,i,0x760bbc))m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)&0xfffffdff);
    else if(Eq(m,args,i,0x760bb0))m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)|0x200);
    else if(Eq(m,args,i,0x760ba8))m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)^0x200);
    else if(!player&&Eq(m,args,i,0x760bcc)){uint random=PreparedBuiltinPredicates.Random(m);m.Write32(actor+0x1e8,F(random)>=.5f?m.Read32(actor+0x1e8)|0x200:m.Read32(actor+0x1e8)&0xfffffdff);}
    else if(Eq(m,args,i,0x760ba0))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|1));
    else if(Eq(m,args,i,0x758208))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|2));
    else if(Eq(m,args,i,0x760b94))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|4));
    else m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+i*4)));
   }
   uint reference=player?m.Read32(system+0x138c):m.Read32(actor+0xe4);
   if(reference==0)return 0;uint target=m.Read32(reference+4);if(!player&&target==0)return 0;
   if((m.Read8(packet+0x68)&4)!=0)m.Write32(actor+0x180,Range(m,actor+0x14c,target+0x170));
   reference=player?m.Read32(system+0x138c):m.Read32(actor+0xe4);target=m.Read32(reference+4);uint point=unchecked(target+((m.Read8(packet+0x68)&2)==0?0x170u:0x14cu));
   target=m.Read32(reference+4);uint radius=B(F(m.Read32(target+0x120))),goal=B(F(m.Read32(actor+0x180))),words=unchecked(target+0x158);
   if(point!=0)for(uint i=0;i<3;i++)m.Write32(actor+0x1b4+i*4,m.Read32(point+i*4));
   if(words!=0)for(uint i=0;i<6;i++)m.Write32(actor+0x1cc+i*4,m.Read32(words+i*4));
   m.Write32(actor+0x1c0,radius);m.Write32(actor+0x1c4,goal);m.Write32(actor+0x1e8,(m.Read32(actor+0x1e8)&0xfffffffb)|3);if((m.Read8(packet+0x68)&1)!=0)m.Write32(actor+0x1e4,point);return 0;
  }
  public static uint Player(TakeoverReleaseMemory m,ScriptCircleServices circle,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,circle,symbols,system,packet,actor,args,count,first,true);}
  public static uint Opponent(TakeoverReleaseMemory m,ScriptCircleServices circle,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,circle,symbols,system,packet,actor,args,count,first,false);}
 }
}
