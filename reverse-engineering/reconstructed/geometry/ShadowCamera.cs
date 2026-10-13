// Original finite camera matrix helpers, recovered from PC instruction order.
// Native/Python fixtures pass; compiled managed execution remains pending.
using System;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public static class ShadowCamera
    {
        static float Finite(float v){if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite camera arithmetic required.");return v;}
        static void Matrix(float[] v){if(v==null||v.Length<16)throw new ArgumentException("Complete matrix required.");for(int i=0;i<16;++i)Finite(v[i]);}
        static Wide Product(float a,float b){return Wide.Multiply(Wide.From(a),Wide.From(b));}
        static float Store(Wide exact,double approximate){float value=Finite(exact.Store());return value==0&&approximate==0?(float)approximate:value;}
        //0x5b5a40. Transpose3x3 and transform negated translation. Valid as a
        // mathematical inverse only for an orthonormal affine basis; no scale fix.
        // Exact self-aliasing is supported, as in the original implementation.
        public static void RigidInverse(float[] source,float[] output)
        {
            Matrix(source);if(output==null||output.Length<16)throw new ArgumentException("Complete output matrix required.");float[] matrix=(float[])source.Clone();for(int i=0;i<3;++i)for(int j=0;j<3;++j)output[i*4+j]=matrix[j*4+i];float x=-matrix[12],y=-matrix[13],z=-matrix[14];
            for(int j=0;j<3;++j)output[j+12]=Store(Wide.Add(Wide.Add(Product(x,output[j]),Product(y,output[j+4])),Product(z,output[j+8])),((double)x*output[j]+(double)y*output[j+4])+(double)z*output[j+8]);
            output[3]=output[7]=output[11]=0;output[15]=1;
        }
        //0x5b7670. FOV is DEGREES. This bounded domain fits both original CRT
        // signed conversion paths. Sine table is the recovered32768-float table.
        public static void Perspective(float fovDegrees,float aspect,float near,float far,float[] sineTable,float[] output)
        {
            Finite(fovDegrees);Finite(aspect);Finite(near);Finite(far);if(Math.Abs(fovDegrees)<1||Math.Abs(fovDegrees)>170||aspect==0||far==near||sineTable==null||sineTable.Length!=32768||output==null||output.Length<16||Object.ReferenceEquals(sineTable,output))throw new ArgumentException("Bounded degreeFOV, nonzero denominators and disjoint complete table/output required.");
            Wide half=Product(fovDegrees,.5f);int angle=Wide.Multiply(half,Wide.FromDouble(182.04444885253906)).TruncateInt32(),negativeAngle=Wide.Multiply(half,Wide.FromDouble(-182.04444885253906)).TruncateInt32();float sy=Finite(sineTable[(angle>>1)&32767]),cy=Finite(sineTable[((0x4000-negativeAngle)>>1)&32767]);if(cy==0)throw new ArgumentException("Nonzero sampled cosine required.");float tangent=Store(Wide.Divide(Wide.From(sy),Wide.From(cy)),(double)sy/cy);if(tangent==0)throw new ArgumentException("Nonzero stored tangent required.");
            Wide denominator=Wide.Add(Wide.From(far),Wide.From(-near));var result=new float[16];result[0]=Store(Wide.Divide(Wide.From(1),Product(tangent,aspect)),1.0/((double)tangent*aspect));result[5]=Store(Wide.Divide(Wide.From(1),Wide.From(tangent)),1.0/tangent);result[10]=Store(Wide.Divide(Wide.From(far),denominator),(double)far/((double)far-near));result[11]=1;result[14]=Store(Wide.Divide(Product(-far,near),denominator),(-(double)far*near)/((double)far-near));Array.Copy(result,output,16);
        }
    }
}
