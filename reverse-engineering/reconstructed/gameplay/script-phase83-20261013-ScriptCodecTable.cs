// Canonical16-bit code construction into direct lookup and shared left/right word trees.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptCodecTable
 {
  static uint Word(TakeoverReleaseMemory m,uint p){return (uint)(m.Read8(p)|(m.Read8(p+1)<<8));}
  static void Word(TakeoverReleaseMemory m,uint p,uint v){m.Write8(p,(byte)v);m.Write8(p+1,(byte)(v>>8));}
  //4f6000 cdecl(entries,lengthBytes,lookupBits,lookupWords). Prepared complete prefix lengths0..16.
  public static void Build(TakeoverReleaseMemory m,uint entries,uint lengths,uint lookupBits,uint lookup)
  {
   if(entries>510||lookupBits==0||lookupBits>16)throw new ArgumentException("Prepared codec table dimensions required.");
   ushort[] count=new ushort[17],start=new ushort[18],weight=new ushort[17];
   for(uint symbol=0;symbol<entries;symbol++){uint length=m.Read8(lengths+symbol);if(length>16)throw new ArgumentException("Prepared code lengths0..16 required.");count[length]=unchecked((ushort)(count[length]+1));}
   for(int length=1;length<=16;length++)start[length+1]=unchecked((ushort)(start[length]+(count[length]<<(16-length))));
   if(start[17]!=0)throw new ArgumentException("Prepared complete prefix code required.");int shift=(int)(16-lookupBits);
   for(int length=1;length<=16;length++){if(length<=lookupBits){start[length]=(ushort)(start[length]>>shift);weight[length]=(ushort)(1u<<(int)(lookupBits-(uint)length));}else weight[length]=(ushort)(1u<<(16-length));}
   uint tail=(uint)(start[lookupBits+1]>>shift),size=1u<<(int)lookupBits;if(tail!=0&&tail!=size)for(uint i=tail;i<size;i++)Word(m,lookup+i*2,0);
   uint next=entries,branch=1u<<(int)(15-lookupBits);
   for(uint symbol=0;symbol<entries;symbol++)
   {
    uint length=m.Read8(lengths+symbol);if(length==0)continue;uint code=start[length],end=code+weight[length];
    if(length<=lookupBits){for(uint i=code;i<end;i++)Word(m,lookup+i*2,symbol);}
    else
    {
     uint pointer=lookup+(code>>shift)*2,depth=length-lookupBits;
     do{uint node=Word(m,pointer);if(node==0){Word(m,0x2982740+next*2,0);Word(m,0x2982f40+next*2,0);Word(m,pointer,next);node=next;next++;}pointer=((code&branch)!=0?0x2982f40u:0x2982740u)+node*2;code=unchecked(code+code);depth--;}while(depth!=0);Word(m,pointer,symbol);
    }
    start[length]=unchecked((ushort)end);
   }
  }
 }
}
