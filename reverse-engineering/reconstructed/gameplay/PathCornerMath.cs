using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public static class PathCornerMath
    {
        struct W
        {
            PlaybackWide exact;double approximate;
            public W(float v){exact=PlaybackWide.From(v);approximate=v;}
            static W Make(PlaybackWide v,double a){return new W{exact=v,approximate=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approximate+b.approximate);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(PlaybackWide.From(-1),b.exact)),a.approximate-b.approximate);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approximate*b.approximate);}
            public static W operator /(W a,W b){return Make(PlaybackWide.Divide(a.exact,b.exact),a.approximate/b.approximate);}
            public float Store(){float v=exact.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximate)<0?0x80000000u:0u):v;}
        }
        static W S(W v){return new W(v.Store());}
        //0x5be590/5be5b0 return the signed16-bit wrapped result in full EAX.
        public static int AddAngles(int a,int b){return unchecked((short)(a+b));}
        public static int DifferenceAngles(int a,int b){return unchecked((short)(a-b));}
        //0x5bee20. Infinite-line parameters in3D; no coplanarity or segment
        //bounds test. Both outputs are written even when the scale is zero.
        public static bool LineParameters(SpawnVector p,SpawnVector direction,SpawnVector q,SpawnVector otherDirection,out float first,out float second)
        {
            W x=new W(direction.X),y=new W(direction.Y),z=new W(direction.Z),u=new W(otherDirection.X),v=new W(otherDirection.Y),w=new W(otherDirection.Z);
            W cx=S(y*w-z*v),cy=S(z*u-x*w),cz=S(x*v-u*y);float length=BuildEffectSound.SquareRoot((cy*cy+cx*cx+cz*cz).Store());W inverse=length==0?new W(0):S(new W(1)/new W(length));W scale=S(inverse*inverse);
            W dx=S(new W(q.X)-new W(p.X)),dy=S(new W(q.Y)-new W(p.Y)),dz=S(new W(q.Z)-new W(p.Z));
            W a=S((v*cz-w*cy)*dx-dy*(cz*u-cx*w)+dz*(cy*u-cx*v));
            W b=S((cz*y-cy*z)*dx-(x*cz-cx*z)*dy+dz*(cy*x-y*cx));
            first=(a*scale).Store();second=(b*scale).Store();return scale.Store()!=0;
        }
    }
}
