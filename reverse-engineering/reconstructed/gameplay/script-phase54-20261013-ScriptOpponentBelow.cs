// Original opponent-below predicate: actor/reference guards, unguarded actor controller, double threshold.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptOpponentBelow
 {
  public static uint Evaluate(TakeoverReleaseMemory m,uint actor){if(actor==0)return 0;uint opponent=m.Read32(actor+0xe4);if(opponent==0)return 0;float opponentY=m.Float(opponent+0x60);uint controller=m.Read32(actor+0xd0);float actorY=m.Float(controller+0x60);uint lo=m.Read32(0x751788),hi=m.Read32(0x75178c);double threshold=BitConverter.Int64BitsToDouble(unchecked((long)(((ulong)hi<<32)|lo)));if(threshold!=0.10000000149011612)throw new ArgumentException("Original threshold required.");if(!float.IsNaN(actorY)&&!float.IsInfinity(actorY)&&Math.Abs((double)actorY)>1000000||!float.IsNaN(opponentY)&&!float.IsInfinity(opponentY)&&Math.Abs((double)opponentY)>1000000)throw new ArgumentException("Prepared bounded vertical comparison domain required.");return ((double)actorY-(double)opponentY)>threshold?0x3f800000u:0;}
 }
}
