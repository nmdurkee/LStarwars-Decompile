// Reconstructed PC reset state. Full loaded-world respawn is not implemented.
using System;

namespace Recovered.Animation
{
    public sealed class CharacterResetParameters
    {
        public float BaseRadius; // character data +0x2c
        public float Radius;     // +0x30
        public float Bottom;     // +0x34
        public float Top;        // +0x38
        public float Scale;      // +0x3c
        public float ResetDistance = 1; // PC global0x802be8 -> object+0xda4
    }

    public static class RespawnState
    {
        private const int S = 0x6c4;
        private static uint Random16(ref uint state) { state = (state * 0x24cdu + 1) & 65535; return state; }
        private static void Clear(PcObjectImage o, int basis, int[] offsets)
        { foreach (int at in offsets) o.Set32(basis + at, 0); }
        private static void Put32(byte[] b, int p, uint v)
        { b[p] = (byte)v; b[p + 1] = (byte)(v >> 8); b[p + 2] = (byte)(v >> 16); b[p + 3] = (byte)(v >> 24); }

        // Original0x41af70 and original callees. Bounded branch: no loaded clips,
        // no suit and no companion. Original PC vectors are v000=(0,0,0), v010=(0,1,0).
        // All 4312 object bytes, 96 pad bytes, 16 coin bytes and RNG are oracle-covered.
        // Managed differential execution is tracked separately from native evidence.
        public static void ResetMovesWithoutClips(PcObjectImage o, byte[] pad, byte[] coin,
            CharacterResetParameters tuning, ref uint randomState)
        {
            if (o == null || tuning == null || pad == null || pad.Length != 96)
                throw new ArgumentException("Expected an object, tuning and 96-byte PC pad state.");
            if (o.U32(0xcbc) != 0 || o.U32(0xcc0) != 0)
                throw new ArgumentException("This recovered reset branch requires no suit or companion.");
            if (o.U32(0x7fc) != 0 && (coin == null || coin.Length != 16))
                throw new ArgumentException("A nonnull native coin pointer requires its 16-byte state.");

            //0x4148a0 core, taking object+0x6c4;0x55e4e0 is its first callee.
            o.Set8(S + 0x101, o.U8(S + 0x101) & 0xfe);
            Clear(o, S, new int[] { 0x660, 0x684 });
            foreach (int at in new int[] { 0x754, 0x756, 0x758 }) o.Set16(S + at, 0);
            o.Set32(S + 0xfc, 0); o.Set8(S + 0x100, 255);
            o.SetFloat(S + 0x678, (o.U8(S + 0x75e) & 1) != 0 ? 1 : 0);
            o.SetFloat(S + 0x67c, 5);
            foreach (int at in new int[] { 0x76f, 0xf5, 0xf4, 0xee, 0x76e }) o.Set8(S + at, 0);
            o.Set8(S + 0xf1, 255);
            Clear(o, S, new int[] { 0x66c, 0x674, 0x664, 0x65c, 0x648, 0x694, 0x698, 0x670,
                0x6d0, 0x6e8, 0x700, 0x714, 0x720, 0x724, 0x60c });
            o.Set8(S + 0x77d, (int)(Random16(ref randomState) >> 15)); o.Set16(S + 0xe8, 0);
            foreach (int at in new int[] { 0x74c, 0x750, 0x752 }) o.Set16(S + at, 65535);
            foreach (int at in new int[] { 4, 8, 12, 16, 20, 24, 28, 32, 0x40, 0x44, 0x48, 0x4c, 0x54 }) Put32(pad, at, 0);
            int flags = (pad[0x5a] | pad[0x5b] << 8) & 0xffe9;
            pad[0x5a] = (byte)flags; pad[0x5b] = (byte)(flags >> 8);
            o.Set32(S + 0x75c, o.U32(S + 0x75c) & 0xfffffbffu); o.Set32(S + 0x65c, 0);

            //0x589f60 and0x4a4ca0 original substructure resets.
            foreach (int at in new int[] { 4, 0x18, 0x2c, 0x40, 0x54 }) o.SetFloat(S + at, 2000000);
            Clear(o, S, new int[] { 0x614, 0x618, 0x61c, 0x620, 0x624, 0x628, 0x62c, 0x630,
                0x6b8, 0x6d8, 0x6bc, 0x6c0, 0x650, 0x6cc, 0x654 });
            o.SetFloat(S + 0x6c4, 0.2f); o.Set32(S + 0x75c, o.U32(S + 0x75c) & 0xfffffffeu);
            o.SetFloat(S + 0x6dc, 2000000);
            Clear(o, S, new int[] { 0x72c, 0x6ec, 0x708, 0x70c, 0x604, 0x710, 0x718, 0x690, 0x688, 0x784 });
            o.Set16(S + 0x75a, 65535); o.Set16(S + 0x74c, 65535);
            o.Set16(S + 0x74e, Random16(ref randomState) > 32767 ? 79 : 38);
            for (int at = 0x764; at < 0x768; ++at) o.Set8(S + at, (int)(Random16(ref randomState) >> 8));
            o.Set32(S + 0x760, o.U32(S + 0x760) & 0xfffff3feu); o.Set8(S + 0x77f, 255);
            o.Set32(S + 0x5d4, 0); o.SetFloat(S + 0x5d8, 1); o.Set32(S + 0x5dc, 0);

            Clear(o, 0, new int[] { 0x103c, 0x200, 0x204, 0x208, 0xd60 });
            o.SetFloat(0xda4, tuning.ResetDistance); o.Set32(0xef0, o.U32(0xef0) | 0x80);
            //0x415050 returns1 with all clips absent.0x4150d0 resetLevel=2.
            o.Set32(0x2bc, 0); o.Set16(0x2c4, 1);
            o.SetFloat(0x2c0, (float)(Random16(ref randomState) * 1.5259021893143654e-05 * 7.0 + 8.0));
            o.Set32(0x2b8, 0); o.Set16(0x2c6, 65535);
            CharacterContexts.ResetAnimationPacket(o, -1);
            o.Set8(0x281, 0); o.Set8(0x282, 0);
            o.SetFloat(0xa8, tuning.Scale); o.SetFloat(0xffc, tuning.Radius);
            o.SetFloat(0xff0, tuning.Bottom); o.SetFloat(0xff4, tuning.Top);
            //0x55ccd0 writes float32 at each destination.
            o.SetFloat(0xa4, (float)((double)tuning.BaseRadius * tuning.Scale));
            o.SetFloat(0xac, (float)((double)tuning.Radius * tuning.Scale));
            o.SetFloat(0xb0, (float)((double)o.F32(0xac) * o.F32(0x1004)));
            o.SetFloat(0xb4, (float)(((double)tuning.Top - tuning.Bottom) * o.F32(0xff8)));
            o.Set32(0xe24, o.U32(0xe24) & 0xfff8ffffu); o.Set32(0x1000, 0); o.Set32(0x1018, 0);
            if (o.U32(0x7fc) != 0) { coin[10] = 1; Put32(coin, 4, 0x3f800000); Put32(coin, 12, 0); }
            o.Set32(0x1fc, o.U32(0x1fc) & 0xffffdfffu); o.Set32(0x1d8, 0);
            Clear(o, 0, new int[] { 0xe94, 0xe98, 0xe9c }); //0x4988b0 immediate, no suit/context offset
        }
    }
}
