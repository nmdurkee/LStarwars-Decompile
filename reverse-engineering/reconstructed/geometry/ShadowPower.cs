// Recovered 0x5be630 cache orchestration. The log/exp backend is explicit;
// native/Python cache comparisons do not establish managed or CRT equivalence.
using System;
namespace Recovered.Geometry
{
    public sealed class ShadowPowerCache
    {
        public uint Initialize, Next;
        public readonly float[] Values = new float[32];
        public readonly float[] Exponents = new float[32];
        public readonly float[] Results = new float[32];
    }
    public static class ShadowPower
    {
        // The backend must return the float32-stored result of exp(log(value)
        // * exponent), and must not mutate this cache. It is deliberately not
        // replaced by System.Math.Pow: the original uses its own x87 CRT.
        public static float Evaluate(ShadowPowerCache cache, float value,
                                     float exponent, Func<float,float,float> backend)
        {
            // Original returns positive zero before reading state or exponent.
            if (value == 0) return 0;
            if (cache == null) throw new ArgumentNullException("cache");
            if (Single.IsNaN(value) || Single.IsInfinity(value) ||
                Single.IsNaN(exponent) || Single.IsInfinity(exponent))
                throw new ArgumentException("Nonzero calls require finite input values.");
            if (cache.Initialize != 0)
            {
                cache.Initialize = 0;
                for (int i=0; i<32; ++i) cache.Values[i] = Single.MaxValue;
                // Exponents, results and ring cursor are deliberately retained.
            }
            for (int i=0; i<32; ++i)
                if (cache.Values[i] == value && cache.Exponents[i] == exponent)
                    return cache.Results[i];
            if (cache.Next >= 32) throw new ArgumentOutOfRangeException("cache.Next");
            if (backend == null) throw new ArgumentNullException("backend");
            float result = backend(value, exponent);
            int slot = (int)cache.Next;
            cache.Values[slot] = value;
            cache.Exponents[slot] = exponent;
            cache.Results[slot] = result;
            cache.Next = (cache.Next + 1) & 31;
            return cache.Results[slot];
        }
    }
}
