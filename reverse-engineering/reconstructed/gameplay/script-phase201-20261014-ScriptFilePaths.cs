// Whole raw file path extractors and indexed current-record getter.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptFilePaths
 {
  //4f0890 includes the last literal backslash. Forward slashes have no delimiter role.
  public static uint Directory(TakeoverReleaseMemory m,uint destination,uint source){uint slash=RecoveredScriptCrtByteStrings.Last(m,source,92);uint length=slash==0?0:unchecked(slash+1-source);RecoveredScriptCrtByteStrings.Copy(m,destination,source,length);m.Write8(destination+length,0);return length;}
  //4f08d0 finds the last dot across the entire original path, including directory names.
  //A dot preceding basename yields native unsigned underflow; excluded from prepared bounded copy.
  public static uint Stem(TakeoverReleaseMemory m,uint destination,uint source){uint slash=RecoveredScriptCrtByteStrings.Last(m,source,92);uint start=slash==0?source:unchecked(slash+1);uint end=RecoveredScriptCrtByteStrings.Last(m,source,46);if(end==0){end=source;while(m.Read8(end)!=0)end++;}if(end<start||end-start>16384)throw new ArgumentException("Prepared extension at or after basename required.");uint length=end-start;RecoveredScriptCrtByteStrings.Copy(m,destination,start,length);m.Write8(destination+length,0);return length;}
  //Raw4f0880 has no range guard; caller supplies backing for the selected record.
  public static uint CurrentRecordValue(TakeoverReleaseMemory m){return m.Read32(unchecked(0x90ff9c+(m.Read32(0x800464)<<4)));}
 }
}
