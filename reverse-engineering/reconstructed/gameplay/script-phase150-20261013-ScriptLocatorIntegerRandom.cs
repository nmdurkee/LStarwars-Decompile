// Raw existing5B9E90, signed quotient and unsigned wrapped update; local zero seed normalization only.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptLocatorIntegerRandom
 {
  public static uint Draw(TakeoverReleaseMemory m,uint state)
  {
   if(state==0)state=0x8066c0;else if(m.Read32(state)==0)m.Write32(state,1);
   uint x=m.Read32(state)^0x075bd924;int quotient=unchecked((int)x)/0x1f31d;uint value=unchecked(x*0x41a7+(uint)((long)quotient*-0x7fffffffL));m.Write32(state,value);if(unchecked((int)value)<0)m.Write32(state,unchecked(value+0x7fffffff));value=m.Read32(state)^0x075bd924;m.Write32(state,value);return value;
  }
 }
}
