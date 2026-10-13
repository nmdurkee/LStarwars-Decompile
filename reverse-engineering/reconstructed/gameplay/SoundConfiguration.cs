using System;
namespace Recovered.Gameplay
{
 public interface ISoundConfigurationServices
 {
  uint Open(SoundSetupImage image,uint path);
  void Configure(SoundSetupImage image,uint parser,uint commandTable);
  int ReadLine(SoundSetupImage image,uint parser);
  void ReadToken(SoundSetupImage image,uint parser);
  void Dispatch(SoundSetupImage image,uint parser);
  void Close(SoundSetupImage image,uint parser);
  void LoadBanks(SoundSetupImage image,uint banks,uint cursor,uint opaque);
  void SetMask(SoundSetupImage image,uint mask,int words);
  void Finish(SoundSetupImage image);
 }
 public static class SoundConfiguration
 {
  //0x6520b0. Scanner/dispatch and audio-device operations are explicit mutable services.
  //Caller owns valid parser token backing and bank capacity. Return values from
  //ReadToken are unused by the native caller: dispatch depends on the token's first byte.
  public static void Load(SoundSetupImage image,uint path,uint cursor,uint opaque,ISoundConfigurationServices services)
  {
   uint parser=services.Open(image,path);
   if(parser!=0)
   {
    services.Configure(image,parser,0x810470);
    while(services.ReadLine(image,parser)!=0)
    {
     services.ReadToken(image,parser);
     if(image.Byte(image.Word(parser+0x510))!=0)services.Dispatch(image,parser);
    }
    services.Close(image,parser);
   }
   uint offset=unchecked(image.Word(0x2962014)*28);
   image.Word(unchecked(image.Word(0x2947d70)+offset),0);
   image.Word(unchecked(image.Word(0x2947d70)+offset+4),0);
   image.Word(unchecked(image.Word(0x2947d70)+offset+8),0);
   image.Word(unchecked(image.Word(0x2947d70)+offset+12),0xffffffff);
   services.LoadBanks(image,image.Word(0x2947d70),cursor,opaque);
   image.Zero(0x2921760,200);
   if(image.Word(0x2962034)==0)services.SetMask(image,0x2921760,100);
   services.Finish(image);
  }
 }
}
