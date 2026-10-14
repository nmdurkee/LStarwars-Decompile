// Complete raw MoveAway/Retreat action family, preserving distinct late guards and facing identities.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptRetreatActions
 {
  static uint Stored(uint value){float x=BitConverter.ToSingle(BitConverter.GetBytes(value),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite target radius and actor goal required.");return BitConverter.ToUInt32(BitConverter.GetBytes(x),0);}
  static uint Execute(TakeoverReleaseMemory m,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first,int kind)
  {
   if(actor==0)return 1;bool retreat=kind>=3;
   if(first!=0){if(retreat)m.Write32(actor+0x180,0x3f800000);for(int index=0;index<count;index++){uint i=(uint)index,callback=m.Read32(0x9238b0);if(callback!=0&&tokens.Token(m,callback,m.Read32(args+i*4),actor+0x13f)!=0)continue;if(!retreat&&PreparedScriptByteLookup.Equal(m,m.Read32(args+i*4),0x757e80))m.Write8(packet+0x68,1);else m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+i*4)));}}
   uint reference=kind==0||kind==3?m.Read32(actor+0xe4):kind==4?m.Read32(actor+0xd4):m.Read32(system+(kind==1?0x138cu:0x1390u));
   if(reference!=0)
   {
    uint target=m.Read32(reference+4);if((kind==0||kind==3)&&target==0)return 0;uint radius=Stored(m.Read32(target+0x120)),goal=Stored(m.Read32(actor+0x180)),point=unchecked(target+0x170),words=unchecked(target+0x158);
    if(point!=0)for(uint i=0;i<3;i++)m.Write32(actor+0x1b4+i*4,m.Read32(point+i*4));if(words!=0)for(uint i=0;i<6;i++)m.Write32(actor+0x1cc+i*4,m.Read32(words+i*4));m.Write32(actor+0x1c0,radius);m.Write32(actor+0x1c4,goal);m.Write32(actor+0x1e8,(m.Read32(actor+0x1e8)&0xfffffffa)|2);
    if(!retreat&&m.Read8(packet+0x68)!=0){uint facing=kind==0?reference:m.Read32(system+(kind==1?0x138cu:0x1390u));m.Write32(actor+0x1e4,unchecked(facing+0x5c));}
   }
   return 0;
  }
  public static uint AwayOpponent(TakeoverReleaseMemory m,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,tokens,symbols,system,packet,actor,args,count,first,0);}
  public static uint AwayPlayer(TakeoverReleaseMemory m,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,tokens,symbols,system,packet,actor,args,count,first,1);}
  public static uint AwayPlayer2(TakeoverReleaseMemory m,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,tokens,symbols,system,packet,actor,args,count,first,2);}
  public static uint Opponent(TakeoverReleaseMemory m,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,tokens,symbols,system,packet,actor,args,count,first,3);}
  public static uint Nearest(TakeoverReleaseMemory m,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first){return Execute(m,tokens,symbols,system,packet,actor,args,count,first,4);}
 }
}
