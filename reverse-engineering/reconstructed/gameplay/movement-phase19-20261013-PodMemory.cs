using System;
namespace Recovered.Gameplay
{
 public static class PodMemoryHelpers
 {
  public static uint FindFree(OriginPathMemory m,uint race){for(uint j=0;j<16;j++)if(m.U32(unchecked(race+0xa694+j*0xa0))==0)return unchecked(race+0xa600+j*0xa0);return 0;}
  //Native4d8280 performs ordered FLD/FSTP; signaling NaN hardware behavior is excluded.
  public static void CopyFloatMatrix(OriginPathMemory m,uint source,uint target)
  {
   for(uint j=0;j<16;j++){uint bits=m.U32(source+j*4);if((bits&0x7f800000)==0x7f800000&&(bits&0x7fffff)!=0&&(bits&0x400000)==0)throw new ArgumentException("Signaling NaN float-copy hardware behavior is outside this contract.");m.Set32(target+j*4,bits);}
  }
 }
}
