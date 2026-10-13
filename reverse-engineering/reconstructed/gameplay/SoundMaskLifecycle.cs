using System;
namespace Recovered.Gameplay
{
    public interface ISoundMaskServices
    {
        uint Allocate(SoundSetupImage image,uint bytes,uint sourceFile,uint line);
        void Signal(SoundSetupImage image,uint handle);
        void CommitDevice(SoundSetupImage image,uint function,uint instance);
        void UpdateVoices(SoundSetupImage image,uint instance);
    }
    // Native698710 and698e70. Valid nonnegative counts and adequate backing.
    public static class SoundMaskLifecycle
    {
        public static void Configure(SoundSetupImage image,uint source,int wordCount,ISoundMaskServices services)
        {
            uint count=unchecked((uint)wordCount);
            if(image.Word(0x2972bf0)!=count)
            {
                // The original696a90 called for a prior buffer is an empty RET.
                uint size=unchecked(count*2),buffer=services.Allocate(image,size,0x76ef4c,0x8c4);
                image.Word(0x2972bf4,buffer);image.Zero(buffer,size);
            }
            image.Word(0x2972bf0,count);image.Word(0x2972be8,source);
        }
        public static void Commit(SoundSetupImage image,ISoundMaskServices services)
        {
            uint buffer=image.Word(0x2972bf4);if(buffer==0)return;
            uint source=image.Word(0x2972be8);
            if(source!=0){uint count=image.Word(0x2972bf0);if(count!=0)image.Copy(buffer,source,unchecked(count*2));}
            uint handle=image.Word(0x2972c24);if(handle!=0)services.Signal(image,handle);
            uint instance=image.Word(0x2972c34);
            if(instance!=0)services.CommitDevice(image,image.Word(image.Word(instance)+0x44),instance);
            services.UpdateVoices(image,0x2972c48);
        }
    }
}
