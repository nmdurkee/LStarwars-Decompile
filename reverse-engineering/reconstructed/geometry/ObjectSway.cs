// Original PC5ec3d0 coefficients and5ec590 ordered matrix mutation.
// Original/model comparisons are separate from pending managed execution.
using System;
using System.Collections.Generic;
using Recovered.Animation;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public sealed class ObjectSwayState
    {
        public uint FrameCounter;
        public float Amplitude=1,Rate=1;
        public bool UseSseConversion;
        public float[] SineTable;
    }
    public sealed class ObjectSwayCoefficients
    {
        public float X,Z;
        // Diagnostic six native CRT-conversion low words, in call order.
        public readonly List<uint> Angles=new List<uint>();
    }
    public static class ObjectSway
    {
        private static float Finite(float value)
        {if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite sway arithmetic required");return value;}
        private static float Store(Wide value,double approximate)
        {float result=Finite(value.Store());return result==0&&approximate==0?(float)approximate:result;}
        private static float Scaled(float value,double factor)
        {return Store(Wide.Multiply(Wide.From(value),Wide.FromDouble(factor)),value*factor);}
        private static float Sample(ObjectSwayState s,ObjectSwayCoefficients result,float phase,bool negative,bool cosine)
        {
            // Both operands are exactly promoted binary32 values, so the
            // product has at most48 significant bits and is exact in double.
            double product=phase*(negative?-10430.3779296875:10430.3779296875);
            if(!(product>-9223372036854775808.0&&product<9223372036854775808.0))throw new ArgumentOutOfRangeException("phase","Signed64-bit conversion domain required");
            long integer=(long)product;uint angle=s.UseSseConversion&&(integer<Int32.MinValue||integer>Int32.MaxValue)?0x80000000u:unchecked((uint)integer);result.Angles.Add(angle);
            uint index=(cosine?unchecked(0x4000u-angle):angle)>>1&0x7fff;return Finite(s.SineTable[index]);
        }
        // Whole finite helper5ec3d0. Caller5f0f00 sign-extends two shorts,
        // but this entry itself accepts signed32-bit amplitude/seed values.
        public static ObjectSwayCoefficients Coefficients(ObjectSwayState s,int amplitudeParameter,int seed)
        {
            if(s==null||s.SineTable==null||s.SineTable.Length!=32768)throw new ArgumentException("Original32768-entry sine table required");Finite(s.Amplitude);Finite(s.Rate);
            float amplitude=Store(Wide.Multiply(Wide.Divide(Wide.FromDouble(amplitudeParameter),Wide.From(65535)),Wide.From(s.Amplitude)),(double)amplitudeParameter/65535*s.Amplitude);
            float rate=Store(Wide.Multiply(Wide.Divide(Wide.FromDouble(seed),Wide.From(65535)),Wide.From(s.Rate)),(double)seed/65535*s.Rate);
            uint randomState=unchecked((uint)seed*0x19660du+0x3c6ef35fu);float random=PcObjectImage.FromBits((randomState&0x7fffffu)|0x3f800000u)-1;
            Wide randomPhase=Wide.Multiply(Wide.From(random),Wide.FromDouble(3.1419999599456787));float phase0=Wide.Add(randomPhase,randomPhase).Store();
            // Native fild plus2^32 correction retains the exact uint frame
            // before multiplication; it does not first store it as float32.
            float phase=Store(Wide.Add(Wide.Multiply(Wide.FromDouble(s.FrameCounter),Wide.From(rate)),Wide.From(phase0)),(double)s.FrameCounter*rate+phase0);
            ObjectSwayCoefficients result=new ObjectSwayCoefficients();float cy1=Sample(s,result,Scaled(phase,2.299999952316284),true,true),half=Scaled(cy1,.5);
            float cy2=Sample(s,result,Scaled(phase,4.400000095367432),true,true),quarter=Scaled(cy2,.25);
            float sx1=Sample(s,result,Scaled(phase,2.0999999046325684),false,false),halfSine=Scaled(sx1,.5);
            float sx2=Sample(s,result,phase,false,false),sx3=Sample(s,result,Scaled(phase,4.199999809265137),false,false),quarterSine=Scaled(sx3,.25);
            result.X=Store(Wide.Multiply(Wide.From(amplitude),Wide.Add(Wide.Add(Wide.From(halfSine),Wide.From(sx2)),Wide.From(quarterSine))),amplitude*(((double)halfSine+sx2)+quarterSine));
            float cy3=Sample(s,result,Scaled(phase,1.100000023841858),true,true);
            result.Z=Store(Wide.Multiply(Wide.Add(Wide.Add(Wide.From(cy3),Wide.From(half)),Wide.From(quarter)),Wide.From(amplitude)),((double)cy3+half+quarter)*amplitude);return result;
        }
        private static float Read(RenderPacketMemory m,uint p)
        {return Finite(PcObjectImage.FromBits(m.Dword(p)));}
        // Whole bounded helper5ec590. Forward DWORD copy intentionally retains
        // partial alias effects. The original then changes only row1's4 words.
        public static ObjectSwayCoefficients Transform(RenderPacketMemory memory,uint output,uint source,ObjectSwayState s,int amplitudeParameter,int seed)
        {
            if(memory==null)throw new ArgumentNullException("memory");ObjectSwayCoefficients c=Coefficients(s,amplitudeParameter,seed);
            for(uint i=0;i<16;++i)memory.Dword(checked(output+i*4),memory.Dword(checked(source+i*4)));
            for(uint i=0;i<4;++i)
            {
                float a=Read(memory,checked(source+i*4)),b=Read(memory,checked(source+(i+4)*4)),z=Read(memory,checked(source+(i+8)*4));
                float value=Store(Wide.Add(Wide.Add(Wide.Multiply(Wide.From(a),Wide.From(c.X)),Wide.From(b)),Wide.Multiply(Wide.From(z),Wide.From(c.Z))),((double)a*c.X+b)+(double)z*c.Z);
                memory.Dword(checked(output+(i+4)*4),PcObjectImage.ToBits(value));
            }
            return c;
        }
    }
}
