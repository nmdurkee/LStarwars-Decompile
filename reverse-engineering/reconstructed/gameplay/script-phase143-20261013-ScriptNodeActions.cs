// Complete GoToNode535FC0 and MoveAwayFromNode536FC0 with actual lookup/binding and intent children.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptNodeActions
 {
  static float F(uint x){float v=BitConverter.ToSingle(BitConverter.GetBytes(x),0);if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite prepared node distance/radius required.");return v;}
  static float Difference(float a,float b){if(a==0&&b==0)return F((TakeoverReleaseMemory.Bits(a)&(TakeoverReleaseMemory.Bits(b)^0x80000000))&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();}
  static float Squared(TakeoverReleaseMemory m,uint a,uint b){float x=Difference(F(m.Read32(a)),F(m.Read32(b))),z=Difference(F(m.Read32(a+8)),F(m.Read32(b+8)));return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(x),PlaybackWide.From(x)),PlaybackWide.From(0)),PlaybackWide.Multiply(PlaybackWide.From(z),PlaybackWide.From(z))).Store();}
  static uint Execute(TakeoverReleaseMemory m,ScriptFollowServices intent,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first,bool away)
  {
   if(actor==0||m.Read32(actor+0xd0)==0||m.Read32(actor+0x158)==0||m.Read32(actor+0x15c)==0)return 1;
   if(first!=0)
   {
    if(count==0)return 0;for(int i=1;i<count;i++){uint callback=m.Read32(0x9238b0),token=m.Read32(args+(uint)i*4);if(callback!=0&&tokens.Token(m,callback,token,actor+0x13f)!=0)continue;m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+(uint)i*4)));}
    uint node=PreparedScriptPathLookup.Find(m,system,m.Read32(actor+0x158),m.Read32(args));m.Write32(packet+0x6c,node);if(node==0||m.Read8(node+0x28)==0)return 1;
    uint path=m.Read32(actor+0x158);int index=unchecked((int)(node-m.Read32(path+0x7c)))/0x5c;if(away)PreparedScriptPathLookup.Bind(m,actor,path);else m.Write32(packet+0x84,path);
    uint edge=m.Read32(m.Read32(node+0x34));m.Write32(packet+0x88,edge);m.Write32(packet+0x94,m.Read8(edge+0x10)==index?0u:0x3f800000);m.Write16(packet+0x92,(ushort)(m.Read16(packet+0x92)|1));m.Write32(packet+0x98,0);m.Write8(packet+0x8c,0);PreparedScriptFollow.SetIntent(m,intent,actor,node+4,0,packet+0x84,away?2u:1u,m.Read32(actor+0x180));return 0;
   }
   uint selected=m.Read32(packet+0x6c);if(selected!=0){float square=Squared(m,actor+0x14c,selected+4);if(!away)PreparedScriptFollow.SetIntent(m,intent,actor,selected+4,0,packet+0x84,1,m.Read32(actor+0x180));if(F(m.Read32(selected+0x14))<=square){if(away)PreparedScriptFollow.SetIntent(m,intent,actor,selected+4,0,packet+0x84,2,m.Read32(actor+0x180));return 0;}}
   return 1;
  }
  public static uint Go(TakeoverReleaseMemory m,ScriptFollowServices intent,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,intent,tokens,symbols,system,packet,actor,args,count,first,false);}
  public static uint Away(TakeoverReleaseMemory m,ScriptFollowServices intent,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,intent,tokens,symbols,system,packet,actor,args,count,first,true);}
 }
}
