// Reconstructed PC contracts, not original source. See animation-playback-findings.txt.
using System;

namespace Recovered.Animation
{
    public sealed class PlaybackClip
    {
        public uint Flags;
        public float EndFrame, BlendIn, BlendOut, FramesPerSecond, MovementReference, RateCap;
        // Adapter for the original 76-byte character animation definition.
        public static PlaybackClip FromDefinition(byte[] definition, byte[] header)
        {
            if (definition == null || definition.Length != 76) throw new ArgumentException("Expected 76 definition bytes");
            AnimationPacket values = new AnimationPacket(new byte[72]);
            Array.Copy(definition, values.Bytes, 72);
            return new PlaybackClip { Flags = (uint)definition[4] | (uint)definition[5] << 8 | (uint)definition[6] << 16 | (uint)definition[7] << 24, EndFrame = AnimationPlayback.EndFrame(header),
                BlendIn = values.Float(0x10), BlendOut = values.Float(0x14), FramesPerSecond = values.Float(0x18),
                MovementReference = values.Float(0x1c), RateCap = values.Float(0x20) };
        }
    }

    // Exactly one native 0x48-byte animpacket. Unknown bytes survive every update.
    public sealed class AnimationPacket
    {
        public readonly byte[] Bytes;
        public AnimationPacket(byte[] bytes)
        {
            if (bytes == null || bytes.Length != 72) throw new ArgumentException("Expected 72 packet bytes");
            Bytes = (byte[])bytes.Clone();
        }
        public static AnimationPacket FromObject(PcObjectImage o)
        {
            byte[] bytes = new byte[72]; Array.Copy(o.Bytes, 8, bytes, 0, 72); return new AnimationPacket(bytes);
        }
        public void CopyToObject(PcObjectImage o) { Array.Copy(Bytes, 0, o.Bytes, 8, 72); }
        public int Byte(int p) { return Bytes[p]; }
        public int Short(int p) { return unchecked((short)(Bytes[p] | Bytes[p + 1] << 8)); }
        public float Float(int p) { return PcObjectImage.FromBits((uint)Bytes[p] | (uint)Bytes[p + 1] << 8 | (uint)Bytes[p + 2] << 16 | (uint)Bytes[p + 3] << 24); }
        public void SetByte(int p, int v) { Bytes[p] = unchecked((byte)v); }
        public void SetShort(int p, int v) { Bytes[p] = unchecked((byte)v); Bytes[p + 1] = unchecked((byte)(v >> 8)); }
        public void SetFloat(int p, float v)
        {
            uint bits = PcObjectImage.ToBits(v);
            for (int i = 0; i < 4; ++i) Bytes[p + i] = unchecked((byte)(bits >> (8 * i)));
        }
        internal void Flag(int f) { Bytes[0x30] |= (byte)f; }
    }

    // Finite multiply/divide/store subset of x87 precision-control=64 arithmetic.
    // Uses only integer operations, including explicit 128-bit multiplication.
    // Required because ordinary double intermediates differ at float32 midpoints.
    internal struct PlaybackWide
    {
        private ulong significand;
        private int exponent;
        private bool negative;
        private const ulong High = 0x8000000000000000UL;
        public static PlaybackWide FromDouble(double value)
        {
            ulong bits = unchecked((ulong)BitConverter.DoubleToInt64Bits(value)), field = (bits >> 52) & 2047;
            if (field == 2047) throw new ArgumentException("Finite animation inputs required");
            ulong m = bits & 0xfffffffffffffUL; int e = -1074;
            if (field != 0) { m |= 0x10000000000000UL; e = (int)field - 1075; }
            if (m == 0) return new PlaybackWide();
            while ((m & High) == 0) { m <<= 1; --e; }
            return new PlaybackWide { significand = m, exponent = e, negative = (bits >> 63) != 0 };
        }
        public static PlaybackWide From(float value)
        {
            uint bits = PcObjectImage.ToBits(value), field = (bits >> 23) & 255;
            if (field == 255) throw new ArgumentException("Finite animation inputs required");
            ulong m = bits & 0x7fffff;
            int e = -149;
            if (field != 0) { m |= 0x800000; e = (int)field - 150; }
            if (m == 0) return new PlaybackWide();
            while ((m & High) == 0) { m <<= 1; --e; }
            return new PlaybackWide { significand = m, exponent = e, negative = (bits >> 31) != 0 };
        }
        private static PlaybackWide Finish(ulong sig, int exp, bool neg, bool round)
        {
            if (round)
            {
                sig = unchecked(sig + 1);
                if (sig == 0) { sig = High; ++exp; }
            }
            return new PlaybackWide { significand = sig, exponent = exp, negative = neg };
        }
        public static PlaybackWide Divide(PlaybackWide a, PlaybackWide b)
        {
            if (b.significand == 0) throw new DivideByZeroException();
            if (a.significand == 0) return new PlaybackWide();
            ulong rem, q = 1, d = b.significand;
            int e = a.exponent - b.exponent - 63;
            if (a.significand >= d) rem = a.significand - d;
            else { rem = unchecked((a.significand << 1) - d); --e; }
            for (int i = 0; i < 63; ++i)
            {
                bool carry = (rem & High) != 0;
                rem <<= 1; q <<= 1;
                if (carry || rem >= d) { rem = unchecked(rem - d); q |= 1; }
            }
            bool over = (rem & High) != 0;
            ulong twice = rem << 1;
            return Finish(q, e, a.negative != b.negative, over || twice > d || (twice == d && (q & 1) != 0));
        }
        public static PlaybackWide Multiply(PlaybackWide a, PlaybackWide b)
        {
            if (a.significand == 0 || b.significand == 0) return new PlaybackWide();
            const ulong mask = 0xffffffff;
            ulong al = a.significand & mask, ah = a.significand >> 32, bl = b.significand & mask, bh = b.significand >> 32;
            ulong w0 = al * bl, t = unchecked(ah * bl + (w0 >> 32)), w1 = t & mask, w2 = t >> 32;
            w1 = unchecked(w1 + al * bh);
            ulong hi = unchecked(ah * bh + w2 + (w1 >> 32)), lo = unchecked((w1 << 32) + (w0 & mask));
            bool shift64 = (hi & High) != 0;
            ulong sig = shift64 ? hi : (hi << 1) | (lo >> 63);
            ulong remainder = shift64 ? lo : lo & (High - 1);
            ulong half = shift64 ? High : High >> 1;
            return Finish(sig, a.exponent + b.exponent + (shift64 ? 64 : 63), a.negative != b.negative,
                remainder > half || (remainder == half && (sig & 1) != 0));
        }
        private static bool Bit(uint[] value, int bit) { return bit >= 0 && (value[bit / 32] & (1u << (bit % 32))) != 0; }
        private static uint[] Aligned(PlaybackWide value, int baseExponent, int length)
        {
            uint[] words = new uint[length]; int shift = value.exponent - baseExponent;
            for (int i = 0; i < 64; ++i)
                if ((value.significand & (1UL << i)) != 0) words[(shift + i) / 32] |= 1u << ((shift + i) % 32);
            return words;
        }
        // Exact integer alignment then one round to 64 bits. This path also handles
        // cancellation without first reducing the operands to IEEE double.
        public static PlaybackWide Add(PlaybackWide a, PlaybackWide b)
        {
            if (a.significand == 0) return b;
            if (b.significand == 0) return a;
            int e = Math.Min(a.exponent, b.exponent), length = (Math.Max(a.exponent, b.exponent) - e + 96) / 32 + 1;
            uint[] av = Aligned(a, e, length), bv = Aligned(b, e, length), result = new uint[length];
            bool neg = a.negative;
            if (a.negative == b.negative)
            {
                ulong carry = 0;
                for (int i = 0; i < length; ++i) { ulong sum = (ulong)av[i] + bv[i] + carry; result[i] = unchecked((uint)sum); carry = sum >> 32; }
            }
            else
            {
                int compare = 0;
                for (int i = length - 1; i >= 0; --i) if (av[i] != bv[i]) { compare = av[i] > bv[i] ? 1 : -1; break; }
                if (compare == 0) return new PlaybackWide();
                if (compare < 0) { uint[] swap = av; av = bv; bv = swap; neg = b.negative; }
                long borrow = 0;
                for (int i = 0; i < length; ++i) { long diff = (long)av[i] - bv[i] - borrow; result[i] = unchecked((uint)diff); borrow = diff < 0 ? 1 : 0; }
            }
            int highest = length * 32 - 1;
            while (!Bit(result, highest)) --highest;
            ulong sig = 0;
            for (int i = 0; i < 64; ++i) if (Bit(result, highest - i)) sig |= 1UL << (63 - i);
            bool round = false;
            if (highest >= 64 && Bit(result, highest - 64))
            {
                round = (sig & 1) != 0;
                for (int i = highest - 65; i >= 0 && !round; --i) round = Bit(result, i);
            }
            return Finish(sig, e + highest - 63, neg, round);
        }
        // Truncation toward zero for finite values whose integral part fits Int32.
        // Avoids a float/double store before native FOV index conversion.
        internal int TruncateInt32()
        {
            if (significand == 0 || exponent <= -64) return 0;
            if (exponent >= 0) throw new OverflowException("Finite x87 result exceeds Int32");
            ulong magnitude = significand >> -exponent;
            ulong limit = negative ? 0x80000000UL : 0x7fffffffUL;
            if (magnitude > limit) throw new OverflowException("Finite x87 result exceeds Int32");
            return negative ? unchecked(-(int)magnitude) : (int)magnitude;
        }
        // Explicit x87 FSTP qword rounding, for the few PC call sites that
        // spill a wide intermediate to double before continuing arithmetic.
        // Like Store(), exact zero has the shared representation's positive
        // sign; nonzero underflow retains its sign.
        internal double StoreDouble()
        {
            if (significand == 0) return 0;
            int raw = exponent + 1086, shift = 11 + Math.Max(0, 1 - raw);
            ulong q = 0;
            if (shift < 64)
            {
                q = significand >> shift;
                ulong r = significand & ((1UL << shift) - 1), half = 1UL << (shift - 1);
                if (r > half || (r == half && (q & 1) != 0)) ++q;
            }
            else if (shift == 64 && significand > High) q = 1;
            ulong bits = negative ? 0x8000000000000000UL : 0;
            if (raw <= 0) bits |= q;
            else
            {
                if (q == 0x20000000000000UL) { q >>= 1; ++raw; }
                bits |= raw >= 2047 ? 0x7ff0000000000000UL : ((ulong)raw << 52) | (q & 0xfffffffffffffUL);
            }
            return BitConverter.Int64BitsToDouble(unchecked((long)bits));
        }
        public float Store()
        {
            if (significand == 0) return 0;
            int raw = exponent + 190, shift = 40 + Math.Max(0, 1 - raw);
            ulong q = 0;
            if (shift < 64)
            {
                q = significand >> shift;
                ulong r = significand & ((1UL << shift) - 1), half = 1UL << (shift - 1);
                if (r > half || (r == half && (q & 1) != 0)) ++q;
            }
            else if (shift == 64 && significand > High) q = 1;
            uint bits = negative ? 0x80000000 : 0;
            if (raw <= 0) bits |= (uint)q;
            else
            {
                if (q == 0x1000000) { q >>= 1; ++raw; }
                bits |= raw >= 255 ? 0x7f800000 : ((uint)raw << 23) | ((uint)q & 0x7fffff);
            }
            return PcObjectImage.FromBits(bits);
        }
    }

    // Shared finite arithmetic contract; this is not an additional recovered game
    // entrypoint. Geometry consumes it for PC x87 plane calculations.
    public static class FiniteX87
    {
        public static float Dot3PlusConstant(float x, float y, float z, float a, float b, float c, float d)
        {
            PlaybackWide xy = PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(x), PlaybackWide.From(a)), PlaybackWide.Multiply(PlaybackWide.From(y), PlaybackWide.From(b)));
            return PlaybackWide.Add(PlaybackWide.Add(xy, PlaybackWide.Multiply(PlaybackWide.From(z), PlaybackWide.From(c))), PlaybackWide.From(d)).Store();
        }
    }

    public static class AnimationPlayback
    {
        private static float F(double value) { return PcObjectImage.FromBits(PcObjectImage.ToBits((float)value)); }
        private static bool Has(PlaybackClip[] clips, int id) { return id >= 0 && id < clips.Length && clips[id] != null; }
        // PC 0x5ca470. Header is resolved by the host; no native pointers are followed.
        public static float EndFrame(byte[] header)
        {
            if (header == null || header.Length < 4) throw new ArgumentException("Missing animation header");
            uint magic = (uint)header[0] | (uint)header[1] << 8 | (uint)header[2] << 16 | (uint)header[3] << 24;
            if (magic == 0x414e4934 || magic == 0x414e4935)
            {
                if (header.Length < 16) throw new ArgumentException("Truncated ANI header");
                return (header[10] | header[11] << 8) + (header[14] | header[15] << 8);
            }
            return PcObjectImage.FromBits(magic);
        }
        private static void Reset(AnimationPacket p)
        {
            p.SetFloat(0, 1); p.SetFloat(4, 1); p.SetFloat(0x14, 1);
            p.SetShort(0x36, -1); p.SetShort(0x38, -1); p.SetShort(0x3a, -1);
            p.SetByte(0x31, 0); p.SetByte(0x30, 4); p.SetShort(0x42, -1);
            p.SetByte(0x3c, 0); p.SetByte(0x3d, 0); p.SetByte(0x3e, 0);
        }
        // PC 0x62e760. Model/action lookup is supplied as a resolved clip.
        public static float UpdateTimer(AnimationPacket p, PlaybackClip clip, float time, float step, float movement,
            bool events, int reverseOffset, bool backwards, float backwardsMultiplier)
        {
            float rate = clip.FramesPerSecond;
            if (clip.MovementReference > 0)
            {
                rate = PlaybackWide.Multiply(PlaybackWide.Divide(PlaybackWide.From(movement), PlaybackWide.From(clip.MovementReference)), PlaybackWide.From(rate)).Store();
                if (rate < 0) { if (clip.RateCap < 0 && rate < clip.RateCap) rate = clip.RateCap; }
                else if (clip.RateCap > 0 && rate > clip.RateCap) rate = clip.RateCap;
            }
            PlaybackWide deltaWide = PlaybackWide.From(step);
            bool reversed = p.Byte(reverseOffset) != 0;
            if (reversed) deltaWide = PlaybackWide.Multiply(deltaWide, PlaybackWide.From(backwardsMultiplier));
            float delta = PlaybackWide.Multiply(PlaybackWide.Divide(deltaWide, PlaybackWide.From(reversed ? -30 : 30)), PlaybackWide.From(rate)).Store();
            time = F((double)time + delta);
            float end = clip.EndFrame;
            if (delta < 0)
            {
                if (events) p.Flag(8);
                if (time >= 1) return time;
                if ((clip.Flags & 2) == 0) { if (events) p.Flag(1); return 1; }
                if (end > 1) { while (time < 1) time = F((double)time + ((double)end - 1)); }
                else time = 1;
            }
            else
            {
                if (time <= end) return time;
                if ((clip.Flags & 2) == 0) { if (events) p.Flag(1); return end; }
                if (end > 1) { while (time > end) time = F((double)time - ((double)end - 1)); }
                else time = 1;
            }
            if (events) p.Flag(2);
            if (reversed) { if (!backwards) p.SetByte(reverseOffset, 0); }
            else if (backwards && (clip.Flags & 128) != 0) p.SetByte(reverseOffset, 1);
            return time;
        }
        // PC 0x62e9b0. Frame step uses native 30-Hz units; blendStep is seconds.
        // Selection/caller writes of previous/requested ID and callback dispatch remain external.
        public static void UpdatePacket(AnimationPacket p, PlaybackClip[] clips, float step, float movement,
            float blendStep, float backwardsMultiplier, int blendMode)
        {
            bool backwards = movement < 0; movement = Math.Abs(movement);
            int oldFlags = p.Byte(0x30); p.SetByte(0x30, 0); p.SetFloat(4, p.Float(p.Byte(0x31) != 0 ? 0x14 : 0));
            if (step == 0) { p.SetByte(0x30, 32); return; }
            if (p.Short(0x42) == -1)
            {
                int requested = p.Short(0x3a); bool begin = true, interrupted = false;
                if (p.Byte(0x31) != 0)
                {
                    if (requested != -1 && requested != p.Short(0x34) && Has(clips, requested) && clips[requested].BlendIn == 0)
                    {
                        p.SetShort(0x36, requested); bool reverse = backwards && (clips[requested].Flags & 128) != 0;
                        p.SetByte(0x3e, reverse ? 1 : 0); p.SetFloat(0, reverse ? clips[requested].EndFrame : 1);
                        p.Flag(4); p.SetByte(0x31, 0); p.SetFloat(4, p.Float(0)); begin = false;
                    }
                    else
                    {
                        float elapsed = F((double)p.Float(8) + blendStep); p.SetFloat(8, elapsed);
                        if (elapsed >= p.Float(12))
                        {
                            p.SetByte(0x31, 0); p.SetFloat(0, p.Float(0x14)); p.SetShort(0x36, p.Short(0x34));
                            p.SetByte(0x3e, p.Byte(0x3d)); p.SetByte(0x30, 64); begin = false;
                        }
                        else if (blendMode != 1 || requested == p.Short(0x34) || !Has(clips, requested)) begin = false;
                        else
                        {
                            interrupted = true;
                            if (elapsed >= (double)p.Float(12) * .5) { p.SetShort(0x38, p.Short(0x34)); p.SetFloat(0x10, p.Float(0x14)); }
                            else p.SetShort(0x38, p.Short(0x32));
                        }
                    }
                }
                else if (requested == p.Short(0x38) && ((oldFlags & 128) == 0 || requested != p.Short(0x36) || !Has(clips, p.Short(0x36))))
                { p.SetShort(0x36, requested); p.SetByte(0x31, 0); begin = false; }
                if (begin)
                {
                    int previous = p.Short(0x38);
                    if (Has(clips, previous) && Has(clips, requested) && clips[previous].BlendOut > blendStep && clips[requested].BlendIn > blendStep)
                    {
                        PlaybackClip a = clips[previous], b = clips[requested];
                        p.SetByte(0x31, 1); p.SetShort(0x32, previous); p.SetShort(0x34, requested);
                        if (!interrupted) p.SetFloat(0x10, p.Float(0));
                        p.SetByte(0x3c, p.Byte(0x3e)); // Native overwrites the interrupted source reverse choice.
                        bool reverse = backwards && (b.Flags & 128) != 0; p.SetByte(0x3d, reverse ? 1 : 0);
                        if ((a.Flags & 2) != 0 && (b.Flags & 2) != 0 && a.FramesPerSecond == b.FramesPerSecond && a.EndFrame == b.EndFrame)
                            p.SetFloat(0x14, p.Float(0x10));
                        else p.SetFloat(0x14, reverse ? b.EndFrame : 1);
                        p.SetFloat(8, 0); p.SetFloat(12, Math.Min(a.BlendOut, b.BlendIn)); p.Flag(4);
                    }
                    else
                    {
                        p.SetShort(0x36, requested); bool reverse = backwards && Has(clips, requested) && (clips[requested].Flags & 128) != 0;
                        p.SetByte(0x3e, reverse ? 1 : 0); p.SetFloat(0, reverse ? clips[requested].EndFrame : 1);
                        p.SetByte(0x31, 0); p.SetFloat(4, p.Float(0)); p.Flag(4);
                    }
                }
            }
            if (p.Short(0x42) != -1 || p.Byte(0x31) != 0)
            {
                bool overlay = p.Short(0x42) != -1;
                int a = p.Short(overlay ? 0x3a : 0x32), b = p.Short(overlay ? 0x42 : 0x34);
                if (Has(clips, a) && Has(clips, b))
                {
                    p.SetFloat(0x10, UpdateTimer(p, clips[a], p.Float(0x10), step, movement, false, 0x3c, backwards, backwardsMultiplier));
                    p.SetFloat(0x14, UpdateTimer(p, clips[b], p.Float(0x14), step, movement, true, 0x3d, backwards, backwardsMultiplier));
                }
            }
            else if (Has(clips, p.Short(0x36)))
                p.SetFloat(0, UpdateTimer(p, clips[p.Short(0x36)], p.Float(0), (oldFlags & 16) != 0 ? 0 : step, movement, true, 0x3e, backwards, backwardsMultiplier));
            else { int requested = p.Short(0x3a); Reset(p); p.SetShort(0x3a, requested); }
        }
    }
}
