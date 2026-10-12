// Recovered from LEGO Star Wars TCS PC original instructions. No Unity dependency.
// Evidence: reports/geometry-uv-native-validation.json and geometry-uv-findings.txt.
using System;
using System.Collections.Generic;

namespace Recovered.Geometry
{
    public sealed class UvLayer
    {
        public int Handle;
        public byte UMode, VMode;
        public float UAmplitude, VAmplitude, UFrequency, VFrequency;
        public float UOffset, VOffset;
    }

    public sealed class UvMaterial
    {
        public byte DisableU, DisableV;
        public readonly UvLayer[] Layers = { new UvLayer(), new UvLayer(), new UvLayer(), new UvLayer() };

        // Serialized current PC material is exactly 708 bytes. Legacy 628-byte records
        // are intentionally unsupported: the ordinary native loader does not expand them.
        public static UvMaterial DecodeCurrentRecord(byte[] bytes)
        {
            if (bytes == null || bytes.Length != 708) throw new ArgumentException("Expected a 708-byte current PC material record.");
            UvMaterial m = new UvMaterial();
            m.DisableU = bytes[0x7b]; m.DisableV = bytes[0x7c];
            for (int i = 0; i < 4; ++i)
            {
                UvLayer l = m.Layers[i]; int p = 0x1f8 + i * 20;
                l.Handle = ReadInt32(bytes, 0x1c0 + i * 4);
                l.UOffset = ReadFloat32(bytes, 0x1d0 + i * 8);
                l.VOffset = ReadFloat32(bytes, 0x1d4 + i * 8);
                l.UMode = bytes[p]; l.VMode = bytes[p + 1];
                l.UAmplitude = ReadFloat32(bytes, p + 4); l.VAmplitude = ReadFloat32(bytes, p + 8);
                l.UFrequency = ReadFloat32(bytes, p + 12); l.VFrequency = ReadFloat32(bytes, p + 16);
            }
            return m;
        }

        internal static int ReadInt32(byte[] bytes, int offset)
        {
            return unchecked(bytes[offset] | bytes[offset + 1] << 8 | bytes[offset + 2] << 16 | bytes[offset + 3] << 24);
        }
        internal static float ReadFloat32(byte[] bytes, int offset)
        {
            if (BitConverter.IsLittleEndian) return BitConverter.ToSingle(bytes, offset);
            byte[] reversed = { bytes[offset + 3], bytes[offset + 2], bytes[offset + 1], bytes[offset] };
            return BitConverter.ToSingle(reversed, 0);
        }
    }

    public sealed class NativeSineTable
    {
        private readonly float[] values;
        private NativeSineTable(float[] values) { this.values = values; }
        public float this[int index] { get { return values[index]; } }
        public static NativeSineTable DecodeLittleEndian(byte[] bytes)
        {
            if (bytes == null || bytes.Length != 32768 * 4) throw new ArgumentException("Expected 32768 original float32 sine-table entries.");
            float[] values = new float[32768];
            for (int i = 0; i < values.Length; ++i)
            {
                values[i] = UvMaterial.ReadFloat32(bytes, i * 4);
                if (Single.IsNaN(values[i]) || Single.IsInfinity(values[i])) throw new ArgumentException("Nonfinite sine-table entry.");
            }
            return new NativeSineTable(values);
        }
    }

    public sealed class UvScene
    {
        public readonly IList<UvMaterial> Materials;
        // Exact reset predicate: display scene+0x78 -> header+0x158 is nonzero.
        public bool ResetEligible;
        public UvScene(IList<UvMaterial> materials) { if (materials == null) throw new ArgumentNullException("materials"); Materials = materials; }
    }
    public sealed class UvAnimationSet
    {
        public readonly UvScene Scene;
        public readonly IList<int> MaterialIndices;
        public UvAnimationSet(UvScene scene, IList<int> materialIndices)
        {
            if (scene == null || materialIndices == null) throw new ArgumentNullException();
            Scene = scene; MaterialIndices = materialIndices;
        }
    }
    public sealed class UvClock
    {
        public float PhaseTime;        // Original global 0x97add0.
        public float UnscaledTime;     // Original global 0x28571e8.
        public float SpeedScale = 1;   // Original global 0x80bac4.
        public bool ResetPending;      // Original global 0x80e9e4 != 0.
    }

    public static class MaterialUv
    {
        // Original 0x5dfbd0. Membership order and duplicates are significant; do not deduplicate.
        // Caller owns synchronization, mirroring the original critical-section boundary.
        public static void Advance(float delta, ref float phaseTime, IList<UvAnimationSet> sets, NativeSineTable sine)
        {
            if (sets == null || sine == null) throw new ArgumentNullException();
            phaseTime = (float)((double)phaseTime + delta);
            foreach (UvAnimationSet set in sets)
            {
                foreach (int index in set.MaterialIndices)
                {
                    if (index < 0 || index >= set.Scene.Materials.Count) throw new ArgumentOutOfRangeException("MaterialIndices");
                    UvMaterial m = set.Scene.Materials[index];
                    if (m.DisableU == 1 || m.DisableV == 1) continue;
                    foreach (UvLayer l in m.Layers)
                    {
                        if (l.Handle == -1) continue;
                        l.UOffset = EvaluateAxis(l.UMode, l.UOffset, l.UAmplitude, l.UFrequency, delta, phaseTime, sine);
                        l.VOffset = EvaluateAxis(l.VMode, l.VOffset, l.VAmplitude, l.VFrequency, delta, phaseTime, sine);
                    }
                }
            }
        }

        private static float EvaluateAxis(byte mode, float previous, float amplitude, float frequency, float delta, float time, NativeSineTable sine)
        {
            if (mode == 2)
            {
                // Original x87 multiply+add stays extended until the sum is stored as float32.
                float value = (float)((double)frequency * delta + previous);
                return (float)((double)value - TruncateToNativeInt32(value));
            }
            if (mode == 3 || mode == 4)
            {
                double phase = (double)frequency * time * (mode == 3 ? 65536.0 : -65536.0);
                int angle = TruncateToNativeInt32(phase);
                int index = unchecked((mode == 3 ? angle : 16384 - angle) >> 1) & 32767;
                return (float)((double)sine[index] * amplitude);
            }
            return 0.0f; // Includes authored mode128. Do not mask its high bit.
        }

        private static int TruncateToNativeInt32(double value)
        {
            // Original FTOL slow path returns signed64; its consumer uses low32 bits.
            // The validated corpus stays inside signed32 range. Overflow/NaN paths
            // depend on CPU-feature globals and are deliberately rejected here.
            if (Double.IsNaN(value) || Double.IsInfinity(value) || value >= 2147483648.0 || value < -2147483648.0)
                throw new ArgumentOutOfRangeException("value", "Outside the validated native integer-conversion domain.");
            return (int)Math.Truncate(value);
        }

        // Original wrapper0x601330 followed by reset helper0x6012a0.
        public static void Tick(float delta, UvClock clock, IList<UvAnimationSet> sets, IList<UvScene> registeredScenes, NativeSineTable sine)
        {
            if (clock == null || registeredScenes == null) throw new ArgumentNullException();
            float scaledDelta = (float)((double)delta * clock.SpeedScale);
            Advance(scaledDelta, ref clock.PhaseTime, sets, sine);
            clock.UnscaledTime = (float)((double)clock.UnscaledTime + delta);
            if (!clock.ResetPending) return;
            foreach (UvScene scene in registeredScenes)
                if (scene.ResetEligible)
                    foreach (UvMaterial material in scene.Materials)
                        foreach (UvLayer layer in material.Layers) { layer.UOffset = 0; layer.VOffset = 0; }
            clock.ResetPending = false;
        }
    }
}
