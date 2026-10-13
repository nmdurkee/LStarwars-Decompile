using System;
namespace Recovered.Gameplay
{
    public static class PortalDoorRuntime
    {
        static float Float(uint bits){return BitConverter.ToSingle(BitConverter.GetBytes(bits),0);}
        //0x5ca4b0. The magic test is on rawDWORDbits, not a floating-point cast.
        //The returned value has no inferred time unit. QuietNaN/Infinity inputs are retained.
        public static float DurationValue(SoundSetupImage memory,uint clip)
        {
            uint header=memory.Word(clip);
            if(header==0x414e4934u||header==0x414e4935u)
            {
                ushort explicitValue=memory.Half(clip+0x16);
                return explicitValue!=0?explicitValue:memory.Half(clip+0x0a)+memory.Half(clip+0x0e);
            }
            return Float(header);
        }
        //0x5d9060. Portal ids are signed bytes compared to the full32-bit argument.
        //The original count is unsigned, and all matching records are updated.
        //Observer records calls only; prepared backing and bounded count are host preconditions.
        public static void SetPortalState(SoundSetupImage memory,uint scene,int id,int mode,Action<uint,int,int> observer=null)
        {
            if(observer!=null)observer(scene,id,mode);
            uint offset=0;
            for(uint i=0;i<memory.Word(scene+0x6c);i++,offset=unchecked(offset+0x20))
            {
                uint portal=unchecked(memory.Word(scene+0x70)+offset);
                if(unchecked((sbyte)memory.Byte(portal+0x1a))!=id)continue;
                memory.Word(portal+0x1c,mode==0?0:memory.Word(portal+0x1c)|1);
            }
        }
        //Raw-memory composition of the existing0x5d0420 selector contract; no new entry credit.
        static uint Animation(SoundSetupImage memory,uint reference)
        {
            uint normal=memory.Word(reference+4);
            if(normal!=0)return memory.Word(memory.Word(normal+0x40)+0x48);
            uint dynamic=memory.Word(reference+8);if(dynamic==0)return 0;
            uint animation=memory.Word(dynamic+0xc4);return animation==uint.MaxValue?0:animation;
        }
        //0x55fac0. The entry scene supplies its clip table; world+13c supplies mutation targets.
        //Configured bit0 selects current>=duration; otherwise current>1. Unordered comparisons close.
        //Transition bits2/4 suppress repeated portal writes, including conflicting cached state.
        public static void Update(SoundSetupImage memory,uint world,Action<uint,int,int> observer=null)
        {
            uint entry=memory.Word(world+0x5048);if(entry==0)return;
            for(int i=0;i<unchecked((int)memory.Word(world+0x504c));i++,entry=unchecked(entry+16))
            {
                uint animation=Animation(memory,entry);if(animation==0)continue;
                uint scene=memory.Word(entry),clips=memory.Word(scene+0x54);
                uint clip=memory.Word(unchecked(clips+(uint)memory.Half(animation+0x5c)*4));
                float end=DurationValue(memory,clip),current=Float(memory.Word(animation+0x4c));
                ushort flags=memory.Half(entry+12);bool enabled=(flags&1)!=0?current>=end:current>1f;
                if(enabled)
                {
                    if((flags&2)!=0)continue;
                    SetPortalState(memory,memory.Word(world+0x13c),memory.Byte(entry+14),1,observer);
                    memory.Half(entry+12,(ushort)((memory.Half(entry+12)&0xfffb)|2));
                }
                else if((flags&2)!=0||(flags&4)==0)
                {
                    SetPortalState(memory,memory.Word(world+0x13c),memory.Byte(entry+14),0,observer);
                    memory.Half(entry+12,(ushort)((memory.Half(entry+12)&0xfffd)|4));
                }
            }
        }
    }
}
