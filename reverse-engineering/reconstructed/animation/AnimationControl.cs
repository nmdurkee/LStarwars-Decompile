// Reconstructed PC animation controls. Scope: animation-control-findings.txt.
using System;

namespace Recovered.Animation
{
    public sealed class MiniAnimationPacket
    {
        public readonly byte[] Bytes;
        public MiniAnimationPacket(byte[] bytes)
        {
            if (bytes == null || bytes.Length != 36) throw new ArgumentException("Expected 36 compact packet bytes");
            Bytes = (byte[])bytes.Clone();
        }
        public static MiniAnimationPacket FromObject(PcObjectImage o)
        {
            byte[] bytes = new byte[36]; Array.Copy(o.Bytes, 0x7d0, bytes, 0, 36); return new MiniAnimationPacket(bytes);
        }
        public void CopyToObject(PcObjectImage o) { Array.Copy(Bytes, 0, o.Bytes, 0x7d0, 36); }
    }

    public sealed class PlayerAnimationInputs
    {
        public float Seconds, InputMagnitude, MovementSpeed, BackwardsMultiplier;
        public uint GameCharacterFlags;
        public int BlendMode;
        public short SpecialSpeedCharacterId = -1;
    }

    public static class AnimationControl
    {
        private static bool Has(PlaybackClip[] clips, int id) { return id >= 0 && id < clips.Length && clips[id] != null; }

        // PC 0x62efb0. Destination bytes not explicitly copied/reset are preserved.
        public static void ExpandMini(MiniAnimationPacket mini, AnimationPacket full)
        {
            Array.Copy(mini.Bytes, 0, full.Bytes, 0, 24); Array.Copy(mini.Bytes, 24, full.Bytes, 48, 12);
            full.SetByte(60, 0); full.SetByte(61, 0); full.SetByte(62, 0); full.SetShort(66, -1);
        }
        // PC 0x62f030. Reverse/overlay state has no compact-packet representation.
        public static void CompactFull(AnimationPacket full, MiniAnimationPacket mini)
        {
            Array.Copy(full.Bytes, 0, mini.Bytes, 0, 24); Array.Copy(full.Bytes, 48, mini.Bytes, 24, 12);
        }
        // PC 0x62f0a0, including the original wrapper's backwards multiplier zero.
        public static void UpdateMini(MiniAnimationPacket mini, PlaybackClip[] clips, float frameStep,
            float movementSpeed, float blendStep, int blendMode)
        {
            AnimationPacket full = new AnimationPacket(new byte[72]); ExpandMini(mini, full);
            AnimationPlayback.UpdatePacket(full, clips, frameStep, movementSpeed, blendStep, 0, blendMode);
            CompactFull(full, mini);
        }
        // PC 0x62f100. Null model skips availability checks, but never the ID checks.
        public static bool IsBlendingFromTo(AnimationPacket packet, int source, int target, bool modelPresent, bool[] available)
        {
            return packet.Byte(49) != 0 && source != -1 && target != -1 && packet.Short(50) == source && packet.Short(52) == target &&
                (!modelPresent || (available[source] && available[target]));
        }
        // PC 0x62f1a0. During a blend this returns the target action, not the source.
        public static int CurrentAction(AnimationPacket packet) { return packet.Short(packet.Byte(49) != 0 ? 52 : 54); }

        // PC 0x418ca0, bounded branch. Adapter validation is deliberately explicit:
        // no selection callback, special speed override, force time multiplier,
        // wake variation95 or active weapon/footstep effects are implemented here.
        public static void AdvancePlayerWithoutEvents(PcObjectImage o, PlaybackClip[] clips, PlayerAnimationInputs inputs)
        {
            if ((o.U32(0x1f8) & 0x40000) == 0) throw new ArgumentException("Selection callback must be suppressed for this branch");
            o.Set16(0x40, o.I16(0x3e)); o.Set16(0x7f0, o.I16(0x7ee));
            int replacement = o.I16(0x3ee);
            if (replacement != -1 && ((replacement == 233 && o.I8(0x7b5) != 28) || o.I16(0x42) == replacement)) o.Set16(0x42, o.I16(0x3f0));
            if (o.U32(0x50) == 0 || (o.U8(0x28b) != 0 && o.F32(0x100c) == 0) || o.U8(0x28b) == 1) return;
            if (o.I8(0x7b5) == 45 && o.U32(0x798) != 0) throw new ArgumentException("Force time multiplier remains external");
            if (Has(clips, 1) && inputs.MovementSpeed > 0 && o.I16(0x1064) == inputs.SpecialSpeedCharacterId)
                throw new ArgumentException("Special character speed override remains external");
            for (int i = 0; i < clips.Length; ++i)
                if (clips[i] != null && (clips[i].Flags & 0xd00) != 0) throw new ArgumentException("Weapon and footstep clip effects remain external");
            AnimationPacket packet = AnimationPacket.FromObject(o);
            foreach (int offset in new int[] { 50, 52, 54, 56, 58, 66 })
                if (packet.Short(offset) == 95) throw new ArgumentException("Wake animation randomization remains external");
            float direction = (o.U32(0xef0) & 0x4000) != 0 ? -1 : 1;
            float movement;
            if (Has(clips, 1)) movement = inputs.MovementSpeed;
            else if ((inputs.GameCharacterFlags & 0x100000) != 0)
            {
                movement = PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(o.F32(0xf30)), PlaybackWide.From(o.F32(0x68))),
                    PlaybackWide.Multiply(PlaybackWide.From(o.F32(0xf38)), PlaybackWide.From(o.F32(0x70)))).Store();
                if (movement < 0) movement = 0;
            }
            else movement = inputs.InputMagnitude;
            float step = PlaybackWide.Multiply(PlaybackWide.From(inputs.Seconds), PlaybackWide.From(30)).Store();
            AnimationPlayback.UpdatePacket(packet, clips, step, movement * direction, inputs.Seconds, inputs.BackwardsMultiplier, inputs.BlendMode);
            // Original effect helpers require an active definition even when dt=0.
            int current = CurrentAction(packet);
            if (current != -1 && !Has(clips, current)) throw new ArgumentException("Active action must resolve to a definition");
            packet.CopyToObject(o);
        }
    }
}
