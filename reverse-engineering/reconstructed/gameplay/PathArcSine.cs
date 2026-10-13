using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public static class PathArcSine
    {
        static PlaybackWide W(float v){return PlaybackWide.From(v);}
        static PlaybackWide M(PlaybackWide a,PlaybackWide b){return PlaybackWide.Multiply(a,b);}
        static PlaybackWide A(PlaybackWide a,PlaybackWide b){return PlaybackWide.Add(a,b);}
        static float Clamp(PlaybackWide v){float f=v.Store();return f>1?1:f< -1?-1:f;}
        //0x512900, finite sine inputs[-1,1]. Constants are exact original PC
        // values; the polynomial's ordered wide operations and float stores
        // follow machine code. Result is the full truncated native EAX value.
        public static int Evaluate(float value)
        {
            if(Single.IsNaN(value)||Single.IsInfinity(value)||value< -1||value>1)throw new ArgumentException("Finite sine input in[-1,1] required.");
            PlaybackWide x=W(value),scale=W(3.402820018375656e38f);
            float root=BuildEffectSound.SquareRoot(A(W(1),M(W(-1),M(x,x))).Store());
            float absolute=Math.Abs(value),minimum=Math.Min(root,absolute);
            float b=Clamp(M(A(W(absolute),W(-0.7071067690849304f)),scale));
            float c=Clamp(M(x,scale));
            PlaybackWide bc=M(W(b),W(c)),t=M(W(minimum),bc),t2=M(t,t),t3=M(t2,t),t4=M(t2,t2);
            float d=A(W(c),bc).Store();
            PlaybackWide sum=A(M(W(d),W(0.785398006439209f)),M(W(-1),t));
            sum=A(sum,M(M(W(-0.16666699945926666f),t),t2));
            sum=A(sum,M(M(W(-0.07500000298023224f),t2),t3));
            sum=A(sum,M(M(W(-0.04464289918541908f),t3),t4));
            PlaybackWide t5=M(t2,t3);sum=A(sum,M(M(W(-0.03038189932703972f),t4),t5));
            return M(sum,W(10430.400390625f)).TruncateInt32();
        }
    }
}
