// Complete container entry open through concrete lookup, allocation, lazy parent and public seek children.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptContainerOpenServices:ScriptContainerSlotServices
 {
  public abstract void Diagnostic(TakeoverReleaseMemory m,uint[] args);
 }
 public static class PreparedScriptContainerOpen
 {
  //4f9bd0 cdecl(container,path,mode). Prepared progressing parent seek and mapped valid entries.
  public static uint Open(ConditionParserMemory m,ScriptContainerOpenServices io,ScriptHostFileServices host,ScriptRemainingSeekServices seeks,uint container,uint path,uint mode,uint privatePath)
  {
   if(mode!=0)return 0;uint entry=PreparedHierarchicalScriptContainerIndex.Find(m,container,path,privatePath),offset=unchecked(entry<<4);
   if(unchecked((int)entry)<0||m.Read32(unchecked(m.Read32(container+8)+offset+4))==0){io.Diagnostic(m,new uint[]{path});return 0;}
   uint index=PreparedScriptContainerSlots.Record(m,io);if(index==0xffffffff){io.Diagnostic(m,new uint[0]);return 0;}uint parentIndex=PreparedScriptContainerSlots.Parent(m,io,container,index),record=unchecked(0x297dc60+index*48);
   if(parentIndex==0xffffffff){m.Write32(record+0x24,0);return 0;}uint parent=unchecked(container+((parentIndex+3)<<4));PreparedScriptContainerSlots.EnsureParent(m,io,container,parentIndex);m.Write32(record,container);
   ulong baseOffset=PreparedScriptContainerSlots.Offset(m,container,m.Read32(unchecked(m.Read32(container+8)+offset)));m.Write32(record+8,(uint)baseOffset);m.Write32(record+12,(uint)(baseOffset>>32));m.Write32(record+16,(uint)baseOffset);m.Write32(record+20,(uint)(baseOffset>>32));
   m.Write32(record+24,m.Read32(unchecked(m.Read32(container+8)+offset+4)));m.Write32(record+28,m.Read32(unchecked(m.Read32(container+8)+offset+8)));m.Write32(record+40,m.Read32(unchecked(m.Read32(container+8)+offset+12)));m.Write32(record+32,parentIndex);m.Write32(parent+8,m.Read32(record+16));m.Write32(parent+12,m.Read32(record+20));
   uint budget=0;while(true){if(budget++>=1024)throw new ArgumentException("Prepared progressing parent seek required.");ulong position=PreparedScriptSeekDispatch.Seek(m,host,seeks,m.Read32(parent),m.Read32(record+8),m.Read32(record+12),0);if(unchecked((int)(position>>32))>=0)break;io.Diagnostic(m,new uint[0]);}
   if(m.Read32(record+40)==2){m.Write32(0x91ce60,record);m.Write32(0x917844,parent);m.Write32(0x88ab40,m.Read32(record+8));m.Write32(0x88ab44,m.Read32(record+12));m.Write32(0x90fba4,0);}
   return unchecked(index+0x800);
  }
 }
}
