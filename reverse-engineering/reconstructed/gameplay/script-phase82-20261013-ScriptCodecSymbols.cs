// LZ2K symbol and distance tree traversal, and incremental8192-byte match ring.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptCodecTableServices
 {
  public abstract void SmallLengths(TakeoverReleaseMemory m,uint entries,uint countBits,int special);
  public abstract void SymbolLengths(TakeoverReleaseMemory m);
 }
 public static class PreparedScriptCodecSymbols
 {
  static uint Word(TakeoverReleaseMemory m,uint p){return (uint)(m.Read8(p)|(m.Read8(p+1)<<8));}
  static uint Leaf(TakeoverReleaseMemory m,uint node,uint threshold,uint bits,uint mask){int budget=0;while(node>=threshold){if(++budget>32)throw new ArgumentException("Prepared acyclic bit tree required.");uint table=(bits&mask)!=0?0x2982f40u:0x2982740u;node=Word(m,unchecked(table+node*2));mask>>=1;}return node;}
  //4f9820 no arguments.
  public static uint Symbol(TakeoverReleaseMemory m,ScriptCodecTableServices tables)
  {
   if(m.Read32(0x915fac)==0){uint count=m.Read32(0x297e024)>>16;PreparedScriptCodecBits.Consume(m,16);m.Write32(0x915fac,count);tables.SmallLengths(m,19,5,3);tables.SymbolLengths(m);tables.SmallLengths(m,14,4,-1);}
   uint bits=m.Read32(0x297e024);m.Write32(0x915fac,unchecked(m.Read32(0x915fac)-1));uint node=Word(m,0x913fa8+(bits>>20)*2);node=Leaf(m,node,510,bits,0x80000);PreparedScriptCodecBits.Consume(m,m.Read8(0x90f598+node));return node;
  }
  //4f5f30 no arguments.
  public static uint Distance(TakeoverReleaseMemory m)
  {
   uint bits=m.Read32(0x297e024),node=Word(m,0x8cf398+(bits>>24)*2);node=Leaf(m,node,14,bits,0x800000);PreparedScriptCodecBits.Consume(m,m.Read8(0x91ce68+node));
   if(node==0)return 0;if(node==1)return 1;uint extra=node-1,tail=m.Read32(0x297e024)>>(int)((32-extra)&31);PreparedScriptCodecBits.Consume(m,extra);return unchecked((1u<<(int)(extra&31))+tail);
  }
 }
 public static class PreparedScriptCodecBlock
 {
  //4fa320 customEDI=ring, cdecl(positiveCount). Exact incremental pending-match globals.
  public static void Decode(TakeoverReleaseMemory m,ScriptCodecTableServices tables,uint ring,uint count)
  {
   if(count==0||count>8192)throw new ArgumentException("Prepared output count1..8192 required.");uint output=0,left=unchecked(m.Read32(0x88ab3c)-1);m.Write32(0x88ab3c,left);
   if(unchecked((int)left)>=0){uint index=m.Read32(0x91ef34);do{byte value=m.Read8(ring+index);index=unchecked(index+1)&8191;m.Write8(ring+output,value);output++;if(output==count){m.Write32(0x88ab3c,left);m.Write32(0x91ef34,index);return;}left=unchecked(left-1);}while(unchecked((int)left)>=0);m.Write32(0x88ab3c,left);m.Write32(0x91ef34,index);}
   while(output<count)
   {
    uint symbol=PreparedScriptCodecSymbols.Symbol(m,tables);if(symbol<=255){m.Write8(ring+output,(byte)symbol);output++;continue;}
    uint distance=PreparedScriptCodecSymbols.Distance(m),index=unchecked(output-distance-1)&8191;left=unchecked(symbol-254);m.Write32(0x91ef34,index);m.Write32(0x88ab3c,left);if(unchecked((int)left)<0)continue;
    do{byte value=m.Read8(ring+index);index=unchecked(index+1)&8191;m.Write8(ring+output,value);output++;m.Write32(0x91ef34,index);if(output==count)return;left=unchecked(left-1);m.Write32(0x88ab3c,left);}while(unchecked((int)left)>=0);
   }
  }
 }
 public sealed class RecoveredScriptCodecBlocks:ScriptCodecBlockServices
 {
  readonly ScriptCodecTableServices tables;public RecoveredScriptCodecBlocks(ScriptCodecTableServices t){tables=t;}
  public override void Decode(TakeoverReleaseMemory m,uint ring,uint count){PreparedScriptCodecBlock.Decode(m,tables,ring,count);}
 }
}
