// LZ2K small and symbol code-length readers, including uniform-table shortcuts and zero runs.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptCodecLengths
 {
  static uint Word(TakeoverReleaseMemory m,uint p){return (uint)(m.Read8(p)|(m.Read8(p+1)<<8));}
  static void Word(TakeoverReleaseMemory m,uint p,uint v){m.Write8(p,(byte)v);m.Write8(p+1,(byte)(v>>8));}
  static void Zero(TakeoverReleaseMemory m,uint p,uint count){for(uint i=0;i<count;i++)m.Write8(p+i,0);}
  //4f9570 cdecl(entries,countBits,specialZeroIndex).
  public static void Small(TakeoverReleaseMemory m,uint entries,uint countBits,int special)
  {
   if(entries>19||countBits>5)throw new ArgumentException("Prepared small-table dimensions required.");uint count=0,leaf=0;
   if(countBits!=0){count=m.Read32(0x297e024)>>(int)((32-countBits)&31);PreparedScriptCodecBits.Consume(m,countBits);if(count==0){leaf=m.Read32(0x297e024)>>(int)((32-countBits)&31);PreparedScriptCodecBits.Consume(m,countBits);}}
   if(count==0){if(unchecked((int)entries)>0)Zero(m,0x91ce68,entries);for(uint i=0;i<256;i++)Word(m,0x8cf398+i*2,leaf);return;}
   if(count>entries)throw new ArgumentException("Prepared bounded length sequence required.");uint output=0;
   do
   {
    uint bits=m.Read32(0x297e024),length=bits>>29;
    if(length==7){uint mask=0x10000000;while((bits&mask)!=0){mask>>=1;length++;if(mask==0)throw new ArgumentException("Prepared terminating unary length required.");}}
    PreparedScriptCodecBits.Consume(m,length<7?3:length-3);m.Write8(0x91ce68+output,(byte)length);output++;
    if(unchecked((int)output)==special){uint zeros=m.Read32(0x297e024)>>30;PreparedScriptCodecBits.Consume(m,2);Zero(m,0x91ce68+output,zeros);output=unchecked(output+zeros);}
   }while(output<count);
   if(output<entries)Zero(m,0x91ce68+output,entries-output);PreparedScriptCodecTable.Build(m,entries,0x91ce68,8,0x8cf398);
  }
  //4f96b0 no arguments.
  public static void Symbols(TakeoverReleaseMemory m)
  {
   uint count=m.Read32(0x297e024)>>23;PreparedScriptCodecBits.Consume(m,9);
   if(count==0){uint leaf=m.Read32(0x297e024)>>23;PreparedScriptCodecBits.Consume(m,9);Zero(m,0x90f598,510);for(uint i=0;i<4096;i++)Word(m,0x913fa8+i*2,leaf);return;}
   uint output=0;
   do
   {
    uint bits=m.Read32(0x297e024),code=Word(m,0x8cf398+(bits>>24)*2),mask=0x800000,budget=0;
    while(code>=19){if(++budget>32)throw new ArgumentException("Prepared acyclic code-length tree required.");code=Word(m,((bits&mask)!=0?0x2982f40u:0x2982740u)+code*2);mask>>=1;}
    PreparedScriptCodecBits.Consume(m,m.Read8(0x91ce68+code));
    if(code<=2){uint zeros=1;if(code==1){zeros=(m.Read32(0x297e024)>>28)+3;PreparedScriptCodecBits.Consume(m,4);}else if(code==2){zeros=(m.Read32(0x297e024)>>23)+20;PreparedScriptCodecBits.Consume(m,9);}if(output+zeros>510)throw new ArgumentException("Prepared bounded zero run required.");Zero(m,0x90f598+output,zeros);output+=zeros;}
    else{if(output>=510)throw new ArgumentException("Prepared symbol count required.");m.Write8(0x90f598+output,(byte)(code-2));output++;}
   }while(output<count);
   if(output<510)Zero(m,0x90f598+output,510-output);PreparedScriptCodecTable.Build(m,510,0x90f598,12,0x913fa8);
  }
 }
 public sealed class RecoveredScriptCodecTables:ScriptCodecTableServices
 {
  public override void SmallLengths(TakeoverReleaseMemory m,uint n,uint bits,int special){PreparedScriptCodecLengths.Small(m,n,bits,special);}
  public override void SymbolLengths(TakeoverReleaseMemory m){PreparedScriptCodecLengths.Symbols(m);}
 }
 public sealed class RecoveredScriptCodec:ScriptCompressedChunkServices
 {
  public override void Fill(TakeoverReleaseMemory m){throw new InvalidOperationException("Use recovered chunk loader for payload loading.");}
  public override uint Decode(TakeoverReleaseMemory m,uint p,uint d,uint packed,uint plain){return PreparedScriptCodecDecode.Decode(m,new RecoveredScriptCodecBlocks(new RecoveredScriptCodecTables()),p,d,packed,plain);}
 }
}
