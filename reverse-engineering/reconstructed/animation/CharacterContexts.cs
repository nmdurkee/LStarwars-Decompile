// Recovered PC contracts. See reports/animation-portable-findings.txt.
// This is reconstructed logic, not the game's original source.
using System;
using System.Runtime.InteropServices;

namespace Recovered.Animation
{
    // Partial layout only: unspecified bytes are deliberately not given names.
    // The source object's array stride is 0x10d8. Pointers are PC 32-bit values.
    [StructLayout(LayoutKind.Explicit, Size = 0x10d8)]
    public struct PcCharacterKnownFields
    {
        [FieldOffset(0x42)] public short RequestedAction;
        [FieldOffset(0x50)] public uint ModelPointer;
        [FieldOffset(0x54)] public uint CharacterDataPointer;
        [FieldOffset(0x5c)] public float PositionX;
        [FieldOffset(0x60)] public float PositionY;
        [FieldOffset(0x64)] public float PositionZ;
        [FieldOffset(0x6c)] public float VelocityY;
        [FieldOffset(0x1f8)] public uint ApiFlags;
        [FieldOffset(0x1fc)] public uint ObjectFlags;
        [FieldOffset(0x280)] public sbyte PlayerIndex;
        [FieldOffset(0x281)] public byte GroundFlags;
        [FieldOffset(0x28b)] public byte DeathState;
        [FieldOffset(0x778)] public float StunHoldDuration;
        [FieldOffset(0x77c)] public float ContextTimer;
        [FieldOffset(0x784)] public float AirborneActionDuration;
        [FieldOffset(0x7aa)] public short ContextAnimation;
        [FieldOffset(0x7b3)] public byte HitSubstate;
        [FieldOffset(0x7b5)] public sbyte Context;
        [FieldOffset(0x7b8)] public byte MovementState;
        [FieldOffset(0x7bc)] public uint ContextFlags;
        [FieldOffset(0xca4)] public uint GamepadPointer;
        [FieldOffset(0xd2c)] public float FallAnimationTimer;
        [FieldOffset(0xdfc)] public float ResetVelocityY;
        [FieldOffset(0xe10)] public short PreviousBlockAnimation;
        [FieldOffset(0xe20)] public uint RuntimeFlags;
        [FieldOffset(0xe24)] public uint RuntimeFlags2;
        [FieldOffset(0x1030)] public float TerrainImpactSpeed;
        [FieldOffset(0x1078)] public byte TerrainContact;
    }

    [StructLayout(LayoutKind.Explicit)]
    internal struct FloatBits
    {
        [FieldOffset(0)] public float Value;
        [FieldOffset(0)] public uint Bits;
    }

    // A byte image preserves unknown fields and original 32-bit pointer identities.
    // It never dereferences native pointers. Engine adapters supply model data.
    public sealed class PcObjectImage
    {
        public const int Size = 0x10d8;
        public readonly byte[] Bytes;
        public PcObjectImage(byte[] image)
        {
            if (image == null || image.Length != Size) throw new ArgumentException("Expected one 0x10d8-byte PC object image.");
            Bytes = (byte[])image.Clone();
        }
        public byte U8(int p) { return Bytes[p]; }
        public sbyte I8(int p) { return unchecked((sbyte)Bytes[p]); }
        public ushort U16(int p) { return (ushort)(Bytes[p] | Bytes[p + 1] << 8); }
        public short I16(int p) { return unchecked((short)U16(p)); }
        public uint U32(int p) { return (uint)Bytes[p] | (uint)Bytes[p + 1] << 8 | (uint)Bytes[p + 2] << 16 | (uint)Bytes[p + 3] << 24; }
        public float F32(int p) { return FromBits(U32(p)); }
        public void Set8(int p, int v) { Bytes[p] = unchecked((byte)v); }
        public void Set16(int p, int v) { Bytes[p] = unchecked((byte)v); Bytes[p + 1] = unchecked((byte)(v >> 8)); }
        public void Set32(int p, uint v) { Bytes[p] = (byte)v; Bytes[p + 1] = (byte)(v >> 8); Bytes[p + 2] = (byte)(v >> 16); Bytes[p + 3] = (byte)(v >> 24); }
        public void SetFloat(int p, float v) { Set32(p, ToBits(v)); }
        public static float FromBits(uint bits) { FloatBits f = new FloatBits(); f.Bits = bits; return f.Value; }
        public static uint ToBits(float value) { FloatBits f = new FloatBits(); f.Value = value; return f.Bits; }
    }

    public sealed class ClipInfo
    {
        public bool Present;
        public uint Flags;
        public float FrameCount;
        public float FramesPerSecond;
        public float BlendOutSeconds;
    }

    public sealed class ClipSet
    {
        public readonly ClipInfo[] Actions;
        public ClipSet(int count) { Actions = new ClipInfo[count]; }
        public bool Has(int id) { return id >= 0 && id < Actions.Length && Actions[id] != null && Actions[id].Present; }
    }

    public enum DeathEffectRequest { None = 0, StunDeath = 1, AirborneDeath = 2 }

    public static class CharacterContexts
    {
        // PC 0x55e300. Each native start-table row is 16 bytes; the adapter
        // supplies its first 32-bit pointer. Heading is a separate row field.
        public static uint SelectStartPositionPointer(sbyte playerIndex, byte fallbackIndex, uint[] positionPointers)
        {
            if (positionPointers == null || positionPointers.Length != 8)
                throw new ArgumentException("Expected eight PC spawn-position pointers.");
            int index = playerIndex >= 0 && playerIndex <= 7 ? (int)playerIndex : (int)fallbackIndex;
            uint selected = positionPointers[index & 7];
            return selected != 0 ? selected : positionPointers[0];
        }

        // PC 0x41b420 with resetMoves=0. This is NOT full respawn placement.
        public static void ResetWithoutMoves(PcObjectImage o)
        {
            if (o == null) return;
            o.Set32(0xdc8, 0);
            o.Set32(0x1fc, o.U32(0x1fc) & 0xfffdfa83u);
            o.SetFloat(0xff8, 1); o.Set32(0xef0, o.U32(0xef0) | 0x80);
            o.Set32(0x1010, 0); o.Set32(0xda8, 0);
            o.Set32(0xe20, o.U32(0xe20) | 0x8000); o.SetFloat(0xd78, 1);
            o.Set8(0x28b, 0); o.Set8(0xe37, 0); o.SetFloat(0x218, 2000000);
            o.Set8(0x289, 0); o.Set32(0x1f8, o.U32(0x1f8) & ~0x100u);
            o.Set32(0xdbc, 0); o.Set32(0xf10, 0); o.SetFloat(0xc64, -1); o.Set32(0xde0, 0);
        }

        // PC 0x62f150: result is a packet-relative time-field offset, or -1.
        public static int PlayingTimeOffset(PcObjectImage o, int action, bool targetDuringBlend, bool sourceDuringBlend)
        {
            if (action == -1) return -1;
            if (o.U8(0x39) == 0) return o.I16(0x3e) == action ? 0 : -1;
            if (targetDuringBlend && o.I16(0x3c) == action) return 0x14;
            if (sourceDuringBlend && o.I16(0x3a) == action) return 0x10;
            return -1;
        }

        // PC 0x62e040 scalar part. Caller resolves model/clip existence separately.
        public static float DurationSeconds(ClipInfo clip, float startFrame, float endFrame, bool subtractBlendOut)
        {
            if (clip == null || !clip.Present) return 0;
            float length = clip.FrameCount;
            float span;
            if (startFrame < 1 || length <= startFrame)
                span = (endFrame < 1 || length <= endFrame || endFrame <= startFrame) ? length - 1 : endFrame - 1;
            else
                span = (endFrame < 1 || length <= endFrame || endFrame <= startFrame) ? length - startFrame : endFrame - startFrame;
            // Original constant is the double representation of float32(1/30).
            float seconds = (float)((1.0 / ((double)clip.FramesPerSecond / 30.0)) * 0.03333333507180214 * span);
            return subtractBlendOut ? (float)((double)seconds - clip.BlendOutSeconds) : seconds;
        }

        // PC 0x49c080 through the boundary immediately before KillParts.
        // Engine adapter must perform debris/cleanup, arcade credit and pickups.
        public static DeathEffectRequest AdvanceHitContext(PcObjectImage o, ClipSet clips, float dt)
        {
            int action = o.I16(0x7aa);
            bool active = action != -1 && (!clips.Has(action) || PlayingTimeOffset(o, action, true, false) != -1);
            int context = o.I8(0x7b5);
            if (!active) return DeathEffectRequest.None;
            if (context == 21)
            {
                float t = (float)((double)o.F32(0x77c) - dt); o.SetFloat(0x77c, t);
                if (t <= 0) o.Set8(0x7b5, -1);
                return DeathEffectRequest.None;
            }
            if (context == 90)
            {
                float t = (float)((double)o.F32(0x77c) - dt); o.SetFloat(0x77c, t);
                if (t > 0) return DeathEffectRequest.None;
                int substate = o.U8(0x7b3);
                if (substate != 0)
                {
                    if (substate == 1) o.Set8(0x7b5, -1);
                    return DeathEffectRequest.None;
                }
                o.Set32(0xe24, o.U32(0xe24) | 0x8000);
                if (action == 185) return DeathEffectRequest.StunDeath;
                if (action == 61) { o.Set8(0x7b5, -1); return DeathEffectRequest.None; }
                action = action == 167 ? 170 : action == 168 ? 171 : action == 169 ? 172 : 1;
                o.Set16(0x7aa, action); o.Set8(0x7b3, 1);
                o.SetFloat(0x77c, clips.Has(action) && (clips.Actions[action].Flags & 2) == 0
                    ? DurationSeconds(clips.Actions[action], 0, 0, true) : o.F32(0x778));
                return DeathEffectRequest.None;
            }
            if (context != 95) return DeathEffectRequest.None;
            float timer = (float)((double)o.F32(0x77c) + dt); o.SetFloat(0x77c, timer);
            float duration = o.F32(0x784);
            if (timer >= duration) return DeathEffectRequest.AirborneDeath;
            if (timer <= 0.5f) return DeathEffectRequest.None;
            if (o.F32(0xdfc) < 0 && o.U8(0x281) != 0) return DeathEffectRequest.AirborneDeath;
            if (o.U8(0x1078) != 0 && o.F32(0x1030) > (double)timer / duration * -0.800000011920929 + 0.800000011920929)
                return DeathEffectRequest.AirborneDeath;
            return DeathEffectRequest.None;
        }

        // PC 0x4a54b0. Boolean magneticSuit comes from the engine's resolved suit.
        public static void SelectMovementAnimation(PcObjectImage o, ClipSet clips, float speed,
            bool allowWeapon, bool allowTiptoe, float tiptoe, float walk, float run, bool magneticSuit)
        {
            bool armed = allowWeapon && (o.F32(0xd3c) == 1 || o.U8(0xe33) == 1);
            int action;
            if (allowTiptoe && speed <= ((double)walk + tiptoe) * 0.5)
                action = armed && clips.Has(63) ? 63 : 4;
            else if (speed > ((double)run + walk) * 0.5)
                action = armed && clips.Has(23) ? 23 : 3;
            else if (armed && clips.Has(64)) action = 64;
            else action = clips.Has(80) && (o.U32(0xef0) & 0x4000) != 0 ? 80 : 0;
            if (magneticSuit && !(o.I8(0x7b5) == 67 && o.U8(0x7b6) == 5))
            {
                int replacement = action == 4 ? 198 : action == 0 ? 199 : action == 3 ? 200 : -1;
                if (clips.Has(replacement)) action = replacement;
            }
            for (int i = 0; i < 3 && !clips.Has(action); ++i)
                action = action == 4 ? 0 : action == 0 ? 3 : action == 3 ? 0 : action;
            o.Set16(0x42, action);
        }

        // PC 0x4a7360. Inputs are seconds; distance remains source scene units.
        public static void SelectJumpAnimation(PcObjectImage o, ClipSet clips, float dt, float fallDelay)
        {
            uint flags = o.U32(0x7bc); bool falling = (flags & 0x8000) != 0;
            int state = o.U8(0x7b8), action = o.I16(0x7aa);
            if (falling && state == 8 && clips.Has(181)) { o.Set16(0x42, 181); return; }
            if (falling && clips.Has(5)) { o.Set16(0x42, 5); return; }
            o.Set16(0x42, action);
            if (falling || action == 73 || !(state == 0 || state == 1 || state == 6 || state == 7 || state == 9)) return;
            if (o.U8(0x39) == 0 && o.I16(0x3e) == action && (o.U8(0x38) & 1) != 0)
            {
                if (fallDelay <= 0) flags |= 0x8000;
                else o.SetFloat(0xd2c, (float)((double)o.F32(0xd2c) + dt));
            }
            else o.Set32(0xd2c, 0);
            if (fallDelay > 0 && fallDelay <= o.F32(0xd2c) && (o.F32(0xda0) == 2000000 || o.F32(0xda0) > 0.35)) flags |= 0x8000;
            o.Set32(0x7bc, flags);
        }

        // PC 0x58dfa0 plus 0x54fa60; registry block flag8 marks IDs26/27/28.
        public static bool SelectBlockAnimation(PcObjectImage o, ClipSet clips, ref uint randomState)
        {
            int[] available = new int[3]; int count = 0;
            for (int id = 26; id <= 28; ++id) if (clips.Has(id)) available[count++] = id;
            if (count == 0) return false;
            int chosen = available[0];
            if (count > 1)
            {
                do { randomState = (randomState * 0x24cdu + 1) & 65535; chosen = available[randomState / (65535u / (uint)count + 1)]; }
                while (chosen == o.I16(0xe10));
            }
            o.Set16(0xe10, chosen); o.Set16(0x7aa, chosen); return true;
        }

        // PC 0x62e650. The embedded packet begins at object+8.
        public static void ResetAnimationPacket(PcObjectImage o, int action)
        {
            o.SetFloat(0xc, 1); o.Set16(0x42, action); o.SetFloat(0x1c, 1);
            o.Set16(0x40, action); o.SetFloat(8, 1); o.Set16(0x3e, action);
            o.Set8(0x39, 0); o.Set8(0x38, 4); o.Set16(0x4a, -1);
            o.Set8(0x46, 0); o.Set8(0x44, 0); o.Set8(0x45, 0);
        }

        // PC 0x49e2b0 state writes. Audio is an explicit engine-adapter concern.
        public static void StartBlockJump(PcObjectImage o, int variant, float secondJumpSpeed)
        {
            uint flags = o.U32(0x7bc) & 0xfffeffffu;
            o.SetFloat(0x6c, secondJumpSpeed); o.Set8(0x7b5, 0); o.Set8(0x7b8, 2);
            int action = variant == 0 ? 18 : 12; o.Set16(0x7aa, action);
            flags = variant == 0 ? flags & 0xffffdfffu : flags | 0x2000;
            o.Set32(0xe20, o.U32(0xe20) | 0x100000); o.Set32(0x77c, 0); o.Set32(0xd48, 0);
            o.Set32(0x7bc, flags & 0xffff6fffu); o.Set32(0xd2c, 0);
            o.Set8(0x281, 0); o.Set16(0x1050, 0); o.Set32(0xd1c, 0);
            ResetAnimationPacket(o, action);
            if ((o.U32(0x1fc) & 0x80) != 0) o.Set32(0xeec, o.U32(0xeec) | 0x800);
        }
    }
}
