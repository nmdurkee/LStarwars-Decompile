using System;
namespace Recovered.Gameplay
{
    public interface ISoundVoiceServices
    {
        uint TimeMilliseconds(SoundSetupImage image);
        uint GetStatus(SoundSetupImage image,uint function,uint instance);
        int GetVolume(SoundSetupImage image,uint function,uint instance);
        void SetVolume(SoundSetupImage image,uint function,uint instance,int volume);
        void Stop(SoundSetupImage image,uint function,uint instance);
        void Release(SoundSetupImage image,uint function,uint instance);
    }
    public static class SoundVoiceLifecycle
    {
        static uint Function(SoundSetupImage m,uint instance,uint slot){return m.Word(m.Word(instance)+slot);}
        static void Release(SoundSetupImage m,uint instance,ISoundVoiceServices s){s.Release(m,Function(m,instance,8),instance);}
        // Native697690, loaded voice indexes0..63. Callbacks may change voice pointers.
        public static void Retire(SoundSetupImage m,uint owner,int index,ISoundVoiceServices s)
        {
            uint record=unchecked(owner+12+(uint)index*52);
            if(m.Word(record)!=0)
            {
                uint auxiliary=m.Word(record+4);if(auxiliary!=0)Release(m,auxiliary,s);
                uint instance=m.Word(record);s.Stop(m,Function(m,instance,0x48),instance);
                instance=m.Word(record);Release(m,instance,s);
                m.Word(record,0);m.Word(record+4,0);m.Word(owner+0xd10,unchecked(m.Word(owner+0xd10)-1));
            }
            m.Zero(record,52);
        }
        // Native696b40. Signed32 wrapping addition precedes clamping to[-10000,0].
        public static void SetVolume(SoundSetupImage m,uint instance,int volume,ISoundVoiceServices s)
        {
            int adjusted=unchecked(volume+(int)m.Word(0x810dc0));if(adjusted>0)adjusted=0;if(adjusted< -10000)adjusted= -10000;
            s.SetVolume(m,Function(m,instance,0x3c),instance,adjusted);
        }
        // Native698cc0; finite fade delta whose product with-3500 fits signed32.
        public static void Update(SoundSetupImage m,uint owner,ISoundVoiceServices s)
        {
            m.Word(0x2972c1c,0);m.Word(0x2972c20,0);m.Word(0x2972c18,s.TimeMilliseconds(m)&0x7fffffff);
            for(int index=32;index<64;index++)
            {
                uint record=owner+12+(uint)index*52,instance=m.Word(record);if(instance==0)continue;
                uint function=Function(m,instance,0x24);m.Word(0x2972c1c,unchecked(m.Word(0x2972c1c)+1));uint status=s.GetStatus(m,function,instance);
                if(m.Word(record+0x14)==0||(status&4)==0)continue;
                int elapsed=unchecked((int)(m.Word(0x2972c18)-m.Word(record+0x28)));if(elapsed<0)elapsed=unchecked(elapsed-int.MinValue);
                bool expired=elapsed>unchecked((int)m.Word(record+0x2c));m.Byte(record+0x19,expired?(byte)1:(byte)0);
                if(expired)
                {
                    instance=m.Word(record);int volume=s.GetVolume(m,Function(m,instance,0x18),instance);
                    float delta=BitConverter.ToSingle(BitConverter.GetBytes(m.Word(0x297dbfc)),0);
                    //24-bit significand times3500 is exact in double and native x87.
                    int change=(int)((double)delta*-3500.0);volume=unchecked(volume+change);
                    if(volume< -7000)Retire(m,owner,index,s);else SetVolume(m,m.Word(record),volume,s);
                }
                m.Byte(record+0x18,0);
            }
            for(int index=0;index<32;index++)
            {
                uint record=owner+12+(uint)index*52,instance=m.Word(record);if(instance==0)continue;
                uint function=Function(m,instance,0x24);m.Word(0x2972c20,unchecked(m.Word(0x2972c20)+1));uint status=s.GetStatus(m,function,instance);
                if((status&1)==0)Retire(m,owner,index,s);
            }
        }
    }
}
