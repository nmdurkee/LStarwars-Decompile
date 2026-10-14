// Original reversed file-type registry consumers. Complete bodies within mapped bounded strings/rows.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptFileTypeRegistry
 {
  public const uint Registry=0x90fba8;
  static byte Fold(byte value){return value>=65&&value<=90||value>=192&&value<=223?unchecked((byte)(value+32)):value;}
  //4f77d0: ECX=reversed suffix, EAX=length, cdecl(end). Only input filename bytes are folded.
  public static uint Match(TakeoverReleaseMemory m,uint reversed,uint end,uint length){uint i=0;while(m.Read8(unchecked(reversed+i))!=0){end=unchecked(end-1);if(length==0||m.Read8(unchecked(reversed+i))!=Fold(m.Read8(end)))return 0;i++;length=unchecked(length-1);if(i>4096)throw new ArgumentException("Bounded suffix required.");}return 1;}
  //4f7c70: length zero computes strlen. Rows end at first empty name, independent of88ab38 count.
  public static uint Find(TakeoverReleaseMemory m,uint text,uint length){if(length==0){while(m.Read8(unchecked(text+length))!=0){if(++length>4096)throw new ArgumentException("Bounded filename required.");}}uint row=Registry;for(uint i=0;i<96;i++,row=unchecked(row+16)){if(m.Read8(row)==0)return 0;if(Match(m,row,unchecked(text+length),length)!=0)return row;}throw new ArgumentException("Mapped registry sentinel required.");}
  //Unregistered byte-entry4f7cd0: signed slot projection, not additional REA function credit.
  public static uint Slot(TakeoverReleaseMemory m,uint text,uint length){uint row=Find(m,text,length);return row==0?0xffffffff:unchecked((uint)(sbyte)m.Read8(row+13));}
  static uint Copy(TakeoverReleaseMemory m,uint destination,uint source){uint length=0;if(source!=0)while(m.Read8(unchecked(source+length))!=0){m.Write8(unchecked(destination+length),m.Read8(unchecked(source+length)));if(++length>4096)throw new ArgumentException("Bounded live filename copy required.");}m.Write8(unchecked(destination+length),0);return length;}
  //4f7cf0: copy first; preserve type4 names; otherwise replace suffix with matching signed-slot type4 row.
  //Native search has no empty-row stop. A counterpart inside the prepared96-row backing is required.
  public static uint ConvertToType4(TakeoverReleaseMemory m,uint destination,uint source){if(source==0)throw new ArgumentException("Native null source faults after writing destination terminator.");uint length=Copy(m,destination,source),row=Find(m,source,length);if(row==0)return 0;if(m.Read8(row+14)==4)return 1;sbyte slot=unchecked((sbyte)m.Read8(row+13));uint other=Registry;bool found=false;for(uint i=0;i<96;i++,other=unchecked(other+16))if(m.Read8(other+14)==4&&unchecked((sbyte)m.Read8(other+13))==slot){found=true;break;}if(!found)throw new ArgumentException("Native type4 counterpart required.");uint cursor=unchecked(destination+length+(uint)((sbyte)m.Read8(other+15)-(sbyte)m.Read8(row+15)));m.Write8(cursor,0);for(uint i=0;m.Read8(unchecked(other+i))!=0;i++){cursor=unchecked(cursor-1);m.Write8(cursor,m.Read8(unchecked(other+i)));if(i>=4096)throw new ArgumentException("Bounded suffix required.");}return 1;}
  //Unregistered byte-entry4f7d90: copy, truncate matched signed-length suffix, return signed slot.
  public static uint Strip(TakeoverReleaseMemory m,uint destination,uint source){if(source==0)throw new ArgumentException("Native null source faults after writing destination terminator.");uint length=Copy(m,destination,source),row=Find(m,source,length);if(row==0)return 0xffffffff;m.Write8(unchecked(destination+length-(uint)(sbyte)m.Read8(row+15)),0);return unchecked((uint)(sbyte)m.Read8(row+13));}
 }
}
