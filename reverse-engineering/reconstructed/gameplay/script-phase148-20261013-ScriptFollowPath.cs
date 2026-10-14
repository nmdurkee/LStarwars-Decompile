// Raw FollowPath536DC0 with exact two-draw timing and actual random formation scheduler.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptFollowPath
 {
  static float F(uint x){float v=BitConverter.ToSingle(BitConverter.GetBytes(x),0);if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite prepared path timers required.");return v;}
  static PlaybackWide W(float x){return PlaybackWide.From(x);}
  static float Draw(TakeoverReleaseMemory m){uint seed=PreparedScriptFormationRandomRow.Draw(m);return (seed&0x7fffff)/8388608f;}
  public static uint Execute(TakeoverReleaseMemory m,ScriptFollowServices follow,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first,uint delta)
  {
   if(actor==0)return 1;uint reference=m.Read32(actor+0xd0);if(reference==0||m.Read32(reference)==0)return 1;if(m.Read32(actor+0x158)==0||m.Read32(actor+0x15c)==0)return 0;
   if(first!=0)
   {
    m.Write32(actor+0x188,0);float minimum=0,maximum=0;
    for(int i=0;i<count;i++){uint callback=m.Read32(0x9238b0);if(callback!=0&&tokens.Token(m,callback,m.Read32(args+(uint)i*4),actor+0x13f)!=0)continue;uint at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x7581bc);if(at!=0)minimum=F(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,at+8));else{at=PreparedScriptByteLookup.Substring(m,m.Read32(args+(uint)i*4),0x7581b4);if(at!=0)maximum=F(PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,at+8));else m.Write32(packet+0x9c,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+(uint)i*4)));}}
    if(minimum<maximum){float firstDraw=Draw(m);double firstTerm=PlaybackWide.Multiply(PlaybackWide.Add(W(1),W(-firstDraw)),W(minimum)).StoreDouble();float secondDraw=Draw(m);float wait=PlaybackWide.Add(PlaybackWide.Multiply(W(secondDraw),W(maximum)),PlaybackWide.FromDouble(firstTerm)).Store();m.Write32(packet+0x9c,TakeoverReleaseMemory.Bits(wait));}
   }
   uint formation=m.Read32(actor+0x144);if(formation==0||(m.Read8(formation+0x50)&8)==0){m.Write32(actor+0x1c0,0);m.Write32(actor+0x1c4,m.Read32(actor+0x180));m.Write32(actor+0x1e8,(m.Read32(actor+0x1e8)&0xfffffffc)|4);}else{if(m.Read32(formation)==m.Read32(actor+0xd0))follow.Schedule(m,0x51c6a0);PreparedScriptFollow.Formation(m,actor);}
   float remaining=F(m.Read32(packet+0x9c));if(remaining>0){remaining=PlaybackWide.Add(W(remaining),W(-F(delta))).Store();m.Write32(packet+0x9c,TakeoverReleaseMemory.Bits(remaining));if(remaining<=0)return 1;}return 0;
  }
 }
}
