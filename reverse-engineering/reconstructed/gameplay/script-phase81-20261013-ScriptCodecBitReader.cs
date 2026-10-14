// LZ2K shared bit collector and block-to-output decoding wrapper.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptCodecBits
 {
  //4f5d00 cdecl(consumedBits); bounded prepared counts 0..32, x86 shift counts modulo32.
  public static uint Consume(TakeoverReleaseMemory m,uint count)
  {
   if(count>32)throw new ArgumentException("Prepared bit count 0..32 required.");
   uint available=m.Read32(0x90f79c),value=m.Read32(0x8cf394);
   m.Write32(0x297e024,unchecked(m.Read32(0x297e024)<<(int)(count&31)));
   if(count>available)
   {
    uint remaining=m.Read32(0x2982724),cursor=m.Read32(0x297dc50);
    do
    {
     count=unchecked(count-available);value=unchecked(value<<(int)(count&31));m.Write32(0x297e024,m.Read32(0x297e024)|value);
     if(remaining!=0){remaining--;m.Write32(0x2982724,remaining);value=m.Read8(cursor);cursor=unchecked(cursor+1);m.Write32(0x297dc50,cursor);}else value=0;
     available=8;
    }while(count>8);
    m.Write32(0x8cf394,value);
   }
   available=unchecked(available-count);value>>=(int)(available&31);m.Write32(0x90f79c,available);m.Write32(0x297e024,m.Read32(0x297e024)|value);return value;
  }
 }
 public abstract class ScriptCodecBlockServices
 {
  public abstract void Decode(TakeoverReleaseMemory m,uint ring,uint count);
 }
 public static class PreparedScriptCodecDecode
 {
  //4faea0 cdecl(source,destination,packedLength,plainLength), original collector and copy bodies.
  public static uint Decode(TakeoverReleaseMemory m,ScriptCodecBlockServices blocks,uint source,uint destination,uint packedLength,uint plainLength)
  {
   if(m.Read32(0x800544)==0)return 0;
   m.Write32(0x297dc50,source);m.Write32(0x297e020,destination);m.Write32(0x29838d4,plainLength);m.Write32(0x2982724,packedLength);m.Write32(0x297e024,0);m.Write32(0x8cf394,0);m.Write32(0x90f79c,0);
   PreparedScriptCodecBits.Consume(m,32);uint total=0;m.Write32(0x915fac,0);m.Write32(0x88ab3c,0);
   while(m.Read32(0x29838d4)!=0)
   {
    uint count=Math.Min(m.Read32(0x29838d4),8192u);blocks.Decode(m,0x91ce80,count);uint output=m.Read32(0x297e020);
    for(uint i=0;i<count;i++)m.Write8(unchecked(output+i),m.Read8(0x91ce80+i));
    uint remaining=m.Read32(0x29838d4);m.Write32(0x297e020,unchecked(m.Read32(0x297e020)+count));m.Write32(0x29838d4,unchecked(remaining-count));total=unchecked(total+count);
   }
   return total;
  }
 }
}
