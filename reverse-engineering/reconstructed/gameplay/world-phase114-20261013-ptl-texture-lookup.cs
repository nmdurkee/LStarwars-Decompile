// Original5e5310; signed index>0 gates the table read, with uint32 address wrapping and no count guard.
// Live REA ev_718a7ee47cba9c24cd0e41201dfe02e64f77cabf97a09efe964e67b3211942fc.
namespace Recovered.Gameplay {public static class PtlTextureLookup {public static uint Lookup(SoundSetupImage m,int index){if(index<=0)return 0;return m.Word(unchecked(m.Word(0x97157c)+(uint)index*4-4));}}}
