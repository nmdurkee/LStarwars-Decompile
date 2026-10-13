// CPU pass-state helpers and normal primary-context registration gates.
// Packet-list finalization and actual pass submission remain separate.
using System;
namespace Recovered.Geometry
{
    public static class ShadowPassState
    {
        static void Need(byte[] state){if(state==null||state.Length<0x218)throw new ArgumentException("Complete original pass-state record required.");}
        static void Write(byte[] state,int offset,uint value){Array.Copy(BitConverter.GetBytes(value),0,state,offset,4);}
        //0x5d4290 resets selected fields, preserving the rest of the0x218 record.
        public static uint Reset(byte[] state)
        {
            Need(state);
            foreach(int offset in new int[]{0x4c,8,4,0x24,0x28,0x58,0x38,0x3c,0x48,0xac,0xc4,0xe4,0xe0,0x178,0x174,0x188,0x214})Write(state,offset,0);
            Write(state,0,UInt32.MaxValue);Write(state,0x40,UInt32.MaxValue);return 1;
        }
        //0x5d4300 forwards an argument that the original reset does not read.
        public static uint ResetAdapter(byte[] state,uint ignored){return Reset(state);}
        //0x5954c0: context originally ECX, volume is a raw32-bit stack value.
        // This only selects state; it never dereferences the supplied context.
        public static void SelectVolume(byte[] state,uint context,uint volume)
        {Need(state);Write(state,0x38,1);Write(state,0x3c,context);Write(state,0x40,volume);}
        //0x5d0530 returns previous806ccc. Disable writesffffffff and ignores
        // the requested value; it does not restore that value automatically.
        public static uint SetMode(ref uint mode,uint enabled,uint value)
        {uint previous=mode;mode=enabled==0?UInt32.MaxValue:value;return previous;}
        //0x5d0650 clears only the shared visibility-cache validity word.
        public static void Invalidate(ShadowContextRegistryState state)
        {if(state==null)throw new ArgumentNullException("state");state.CacheFlag=0;}
        //0x596920 tail-jumps to Register, overwriting its unused caller argument.
        public static void RegisterPrimaryTail(RenderPacketMemory memory,ShadowContextRegistryState state,byte enabled,uint configuration,uint primary)
        {if(enabled!=0&&configuration==2)ShadowContextRegistry.Register(memory,state,primary);}
        //0x596980 makes an ordinary call with the same two global gates.
        public static void RegisterPrimaryCall(RenderPacketMemory memory,ShadowContextRegistryState state,byte enabled,uint configuration,uint primary)
        {if(enabled!=0&&configuration==2)ShadowContextRegistry.Register(memory,state,primary);}
    }
}
