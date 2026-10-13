using System;
namespace Recovered.Gameplay
{
 //Composition of recovered571ba0 with recovered650f20. The supplied typed sound
 //registry and effect vectors are valid snapshots of the corresponding image.
 //The position and cooldown remain shared with mutable backend services.
 public static class BuildEffectPlaybackBridge
 {
  public static void Run(BuildEffectSoundWorld world,BuildEffectSoundState effect,SoundSetupImage image,uint positionAddress,Action<SoundSetupImage,uint,uint[]> backend)
  {
   world.CooldownWord=image.Word(0x951000);Action<int,uint[],float,float> previous=world.Play;
   world.Play=delegate(int id,uint[] position,float volume,float scale)
   {
    image.Word(0x951000,world.CooldownWord);for(uint i=0;i<3;i++)image.Word(positionAddress+i*4,position[i]);
    SoundPlayback.Play(image,id,positionAddress,volume,scale,backend);
    for(uint i=0;i<3;i++)position[i]=image.Word(positionAddress+i*4);world.CooldownWord=image.Word(0x951000);
   };
   try{BuildEffectSound.OnBuildEffect(world,effect);}finally{image.Word(0x951000,world.CooldownWord);world.Play=previous;}
  }
 }
}
