using System;
namespace Recovered.Gameplay
{
 //No new native entry: compose6521b0 initialization with recovered6520b0 text loading.
 public static class SoundInitializationPipeline
 {
  public static void Initialize(SoundSetupImage image,uint cursor,uint opaque,uint path,ISoundConfigurationServices host,Func<SoundSetupImage,uint,uint,int,int> readFile)
  {
   var text=new SoundTextConfiguration(host,readFile);
   SoundInitialization.Initialize(image,cursor,opaque,path,delegate(SoundSetupImage m,uint file,uint arena,uint options){SoundConfiguration.Load(m,file,arena,options,text);});
  }
 }
}
