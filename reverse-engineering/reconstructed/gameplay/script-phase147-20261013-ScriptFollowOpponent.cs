// Complete registered FollowOpponent534F20 through actual full follow intent and formation dependencies.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptFollowOpponent
 {
  public static uint Execute(TakeoverReleaseMemory m,ScriptFollowServices follow,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first)
  {
   if(actor==0)return 1;
   if(first!=0)for(int i=0;i<count;i++){uint callback=m.Read32(0x9238b0);if(callback!=0&&tokens.Token(m,callback,m.Read32(args+(uint)i*4),actor+0x13f)!=0)continue;uint token=m.Read32(args+(uint)i*4);if(PreparedScriptByteLookup.Equal(m,token,0x758218))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|2));else if(PreparedScriptByteLookup.Equal(m,token,0x758208))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|1));else m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+(uint)i*4)));}
   uint target=m.Read32(actor+0xe4);if(target!=0&&m.Read32(target+4)!=0)PreparedScriptFollow.Intent(m,follow,m.Read32(actor+0xd0),target,m.Read8(packet+0x68),m.Read32(actor+0x180));return 0;
  }
 }
}
