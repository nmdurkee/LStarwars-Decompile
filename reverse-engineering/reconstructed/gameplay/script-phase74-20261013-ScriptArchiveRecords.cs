// Original archive record lookup and information: three magic-selected header layouts,28-byte records.
namespace Recovered.Gameplay
{
 public static class PreparedScriptArchiveRecords
 {
  static uint First(uint archive,uint magic){return unchecked(archive+(magic==0x12345678?12u:magic==0x1234567a?24u:20u));}
  //4f9de0 cdecl(archive,name); magic read precedes error reset, first unavailable matching record returns0.
  public static uint Find(ConditionParserMemory m,uint archive,uint name)
  {
   uint magic=m.Read32(archive);m.Write32(0x91eeb8,0);uint first=First(archive,magic),count=m.Read32(unchecked(archive+4));
   for(uint i=0;i<count;i++){uint row=unchecked(first+i*28),candidate=unchecked(archive+m.Read32(row));if(TextParserDispatch.Compare(m.Image,candidate,name)==0)return (m.Read8(unchecked(row+16))&2)!=0?0:i+1;}
   return 0;
  }
  //4f0f30 cdecl(archive,oneBasedEntry,dataOutput,sizeOutput). Outputs are optional and remain live/sequential aliases.
  public static uint Information(TakeoverReleaseMemory m,uint archive,uint entry,uint dataOutput,uint sizeOutput)
  {
   uint index=unchecked(entry-1);m.Write32(0x91eeb8,0);
   if(unchecked((int)index)<0||index>=m.Read32(unchecked(archive+4)))return 0;
   uint row=unchecked(First(archive,m.Read32(archive))+index*28);
   if((m.Read8(unchecked(row+16))&2)!=0)return 0;
   if(dataOutput!=0)m.Write32(dataOutput,unchecked(archive+m.Read32(unchecked(row+4))));
   if(sizeOutput!=0)m.Write32(sizeOutput,m.Read32(unchecked(row+8)));
   return 1;
  }
 }
}
