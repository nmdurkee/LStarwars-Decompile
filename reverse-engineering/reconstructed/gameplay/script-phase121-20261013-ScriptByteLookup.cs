// Raw-memory byte-folded substring4f8a70 and locator51ac10 refinements; existing address credit reused.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptByteLookup
 {
  static byte Fold(byte c){return (c>=97&&c<=122)||c>=224?unchecked((byte)(c-32)):c;}
  public static uint Substring(TakeoverReleaseMemory m,uint text,uint pattern)
  {
   for(uint i=0;i<4096;i++){if(m.Read8(unchecked(text+i))==0)return 0;uint j=0;for(;j<4096;j++){byte needle=m.Read8(unchecked(pattern+j));if(needle==0)return unchecked(text+i);byte value=m.Read8(unchecked(text+i+j));if(value==0||Fold(value)!=Fold(needle))break;}if(j==4096)throw new ArgumentException("Bounded byte pattern required.");}throw new ArgumentException("Bounded byte text required.");
  }
  public static bool Equal(TakeoverReleaseMemory m,uint a,uint b){for(uint i=0;i<4096;i++){byte x=m.Read8(unchecked(a+i)),y=m.Read8(unchecked(b+i));if(Fold(x)!=Fold(y))return false;if(x==0)return true;}throw new ArgumentException("Bounded byte names required.");}
  public static uint Locator(TakeoverReleaseMemory m,uint system,uint query)
  {
   if(system==0)return 0;uint i=0;for(;unchecked((int)i)<unchecked((int)m.Read32(system+0x24));i++){if(i>=65536)throw new ArgumentException("Bounded locator count required.");uint row=unchecked(m.Read32(system+0x28)+i*0x3c);if(Equal(m,row,query))return unchecked(m.Read32(system+0x28)+i*0x3c);}return 0;
  }
 }
}
