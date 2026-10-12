// Reconstructed PC idle contracts; see reports/animation-idle-findings.txt.
using System;

namespace Recovered.Animation
{
    public sealed class IdleClip
    {
        public uint Flags;
        public byte MinimumRepetitions, MaximumRepetitions;
        public float EndFrame, FramesPerSecond, BlendOut;
        public static IdleClip FromDefinition(byte[] definition, byte[] header)
        {
            PlaybackClip p = PlaybackClip.FromDefinition(definition, header);
            return new IdleClip { Flags = p.Flags, MinimumRepetitions = definition[12], MaximumRepetitions = definition[13],
                EndFrame = p.EndFrame, FramesPerSecond = p.FramesPerSecond, BlendOut = p.BlendOut };
        }
    }

    // Resolved pointer-dependent facts, supplied by the engine adapter.
    public sealed class IdleContext
    {
        public byte Variant;
        public uint CharacterFlags;
        public bool ThrowHeld, DurationLookupValid, ModelPresent;
    }

    public static class IdleScheduling
    {
        private static bool Has(IdleClip[] clips, int id) { return id >= 0 && id < clips.Length && clips[id] != null; }
        private static int Alternate(IdleContext c) { return c.Variant == 0 && (c.CharacterFlags & 128) != 0 ? 118 : 25; }
        private static uint Random(ref uint state) { state = unchecked(state * 0x24cd + 1) & 65535; return state; }
        private static int Bucket(ref uint state, int count) { return (int)(Random(ref state) / (uint)(65535 / count + 1)); }
        private static float F(double value) { return PcObjectImage.FromBits(PcObjectImage.ToBits((float)value)); }

        // PC 0x415050. Actions 1=idle,25=weaponidle,118=extra_weaponidle,151=throw_wait.
        public static int SelectBaseIdleAction(PcObjectImage o, IdleClip[] clips, IdleContext context)
        {
            if (context.ThrowHeld) return 151;
            int a = Alternate(context);
            return Has(clips, a) && (!Has(clips, 1) || (o.U8(0xe22) & 1) != 0 || o.U8(0xe33) == 1) ? a : 1;
        }

        // Native duration helper 0x62e040 called with start/end/subtract arguments zero.
        // Failed character mapping returns zero without clearing the shared blend-out global.
        private static float Duration(IdleClip clip, IdleContext context, ref float durationBlendOut)
        {
            if (!context.DurationLookupValid) return 0;
            PlaybackWide rate = PlaybackWide.Divide(PlaybackWide.From(clip.FramesPerSecond), PlaybackWide.From(30));
            float value = PlaybackWide.Multiply(PlaybackWide.Multiply(PlaybackWide.Divide(PlaybackWide.From(1), rate),
                PlaybackWide.From((float)0.03333333507180214)), PlaybackWide.From(F((double)clip.EndFrame - 1))).Store();
            durationBlendOut = clip.BlendOut;
            return value;
        }
        private static float Limit(IdleClip clip, int cycles, IdleContext context, ref float durationBlendOut)
        {
            float seconds = Duration(clip, context, ref durationBlendOut);
            return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(seconds), PlaybackWide.From(cycles)), PlaybackWide.From(-durationBlendOut)).Store();
        }

        // PC 0x4150d0. Mode>0 also clears total time; mode>1 clears previous variation.
        public static void ResetIdleSchedule(PcObjectImage o, IdleClip[] clips, IdleContext context,
            int mode, int action, ref uint random, ref float durationBlendOut)
        {
            if (action == 151) return;
            o.SetFloat(0x2bc, 0); o.Set16(0x2c4, action);
            IdleClip clip = Has(clips, action) ? clips[action] : null;
            float limit;
            if (clip != null && clip.MinimumRepetitions != 0)
            {
                int repetitions = clip.MinimumRepetitions;
                if (repetitions < clip.MaximumRepetitions) repetitions += Bucket(ref random, clip.MaximumRepetitions - repetitions);
                limit = Limit(clip, repetitions, context, ref durationBlendOut);
            }
            else
                limit = PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.Multiply(PlaybackWide.From(Random(ref random)),
                    PlaybackWide.FromDouble(1.5259021893143654e-05)), PlaybackWide.From(7)), PlaybackWide.From(8)).Store();
            o.SetFloat(0x2c0, limit);
            if (mode > 0) { o.SetFloat(0x2b8, 0); if (mode > 1) o.Set16(0x2c6, -1); }
        }

        // PC 0x4151c0. Candidate scan is ascending across exactly 233 native action IDs.
        public static void ChooseIdleVariation(PcObjectImage o, IdleClip[] clips, IdleContext context,
            int defaultIdle, ref uint random, ref float durationBlendOut)
        {
            bool weaponGroup = defaultIdle == Alternate(context); int[] candidates = new int[233]; int count = 0;
            for (int i = 0; i < 233; ++i)
                if (Has(clips, i) && (clips[i].Flags & 16) != 0 && ((clips[i].Flags & 0x800) != 0) == weaponGroup) candidates[count++] = i;
            if (count == 0) { ResetIdleSchedule(o, clips, context, 0, defaultIdle, ref random, ref durationBlendOut); return; }
            int chosen;
            do { chosen = candidates[count > 1 ? Bucket(ref random, count) : 0]; o.Set16(0x2c4, chosen); }
            while (count > 1 && chosen == o.I16(0x2c6));
            IdleClip clip = clips[chosen]; int minimum = clip.MinimumRepetitions, maximum = clip.MaximumRepetitions;
            int cycles = minimum == 0 ? 1 : minimum;
            if (minimum != 0 && maximum != 0 && minimum < maximum) cycles += Bucket(ref random, maximum - minimum);
            o.Set16(0x2c6, chosen);
            if (cycles > 1 && (clip.Flags & 2) == 0) cycles = 1;
            o.SetFloat(0x2bc, 0); o.SetFloat(0x2c0, Limit(clip, cycles, context, ref durationBlendOut));
        }

        // PC 0x415370. Call after context action selection and before packet playback.
        public static void FinalizeIdleSelection(PcObjectImage o, IdleClip[] clips, IdleContext context,
            float stepSeconds, ref uint random, ref float durationBlendOut)
        {
            if (!context.ModelPresent) return;
            int alternate = Alternate(context), requested = o.I16(0x42), previous = o.I16(0x40);
            if (requested != 1 && requested != alternate)
            {
                int selected = SelectBaseIdleAction(o, clips, context);
                if (selected != -1) { ResetIdleSchedule(o, clips, context, 1, selected, ref random, ref durationBlendOut); return; }
            }
            if ((requested == 1 && previous == alternate) || (requested == alternate && previous == 1))
            { ResetIdleSchedule(o, clips, context, 1, requested, ref random, ref durationBlendOut); return; }
            if (requested == 1 || requested == alternate)
            {
                o.SetFloat(0x2b8, F((double)o.F32(0x2b8) + stepSeconds));
                float elapsed = F((double)o.F32(0x2bc) + stepSeconds); o.SetFloat(0x2bc, elapsed);
                if (elapsed >= o.F32(0x2c0))
                {
                    if (o.I16(0x2c4) == requested) ChooseIdleVariation(o, clips, context, requested, ref random, ref durationBlendOut);
                    else ResetIdleSchedule(o, clips, context, 1, requested, ref random, ref durationBlendOut);
                }
                o.Set16(0x42, o.I16(0x2c4)); return;
            }
            ResetIdleSchedule(o, clips, context, 1, SelectBaseIdleAction(o, clips, context), ref random, ref durationBlendOut);
        }
    }
}
