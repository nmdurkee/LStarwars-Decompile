// Scalar dynamic transformed-box classification from original PC6042e0.
// Evidence: geometry-dynamic-bounds-native-validation.json. Ordered zero-sign
// arithmetic supplements shared finite64-significand arithmetic.
// Compiled-source equivalence remains pending. SIMD branch is not represented.
using System;
using Recovered.Animation;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public sealed class DynamicBoxState
    {
        public bool Enabled=true;
        public float[] View,CombinedMatrix=new float[16],FarLanes=new float[4];
        public float Near,Far,FarOverride,HorizontalSlope,VerticalSlope;
        // Diagnostic local corner buffer, not a native persistent global.
        public float[] LastCorners;
    }
    public static class DynamicBounds
    {
        private static float Finite(float value)
        {if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite dynamic bounds domain required.");return value;}
        private static void Size(float[] values,int length)
        {if(values==null||values.Length!=length)throw new ArgumentException("Invalid dynamic bounds dimensions.");foreach(float value in values)Finite(value);}
        private static float Dot(float x,float y,float z,float a,float b,float c,bool translate,float translation)
        {
            Wide exact=Wide.Add(Wide.Add(Wide.Multiply(Wide.From(x),Wide.From(a)),Wide.Multiply(Wide.From(y),Wide.From(b))),Wide.Multiply(Wide.From(z),Wide.From(c)));
            double approximate=((double)x*a+(double)y*b)+(double)z*c;
            if(translate){exact=Wide.Add(exact,Wide.From(translation));approximate+=translation;}
            float value=exact.Store();
            // The shared integer representation intentionally collapses zero
            // sign. Ordered IEEE operations retain it for all-zero terms;
            // a nonzero exact result is never replaced by approximation.
            if(value==0 && approximate==0)return (float)approximate;return value;
        }
        // Original5b5430 affine product; original exact output aliases use a
        // temporary matrix. This value-returning adapter keeps both inputs.
        // The source ignores input perspective column values and sets0/0/0/1.
        public static float[] MultiplyAffine(float[] left,float[] right)
        {
            Size(left,16);Size(right,16);float[] result=new float[16];result[15]=1;
            for(int row=0;row<4;++row)for(int col=0;col<3;++col)
                result[row*4+col]=Finite(Dot(left[row*4],left[row*4+1],left[row*4+2],right[col],right[4+col],right[8+col],row==3,row==3?right[12+col]:0));
            return result;
        }
        // Original603f10 for nonoverlapping packed XYZ arrays. The original
        // four-vector loop and remainder use the same arithmetic order.
        public static float[] TransformPoints(float[] packed,float[] matrix)
        {
            Size(matrix,16);if(packed==null || packed.Length%3!=0 || packed.Length>3000000)throw new ArgumentException("Bounded packed XYZ array required.");foreach(float value in packed)Finite(value);float[] output=new float[packed.Length];
            for(int i=0;i<packed.Length;i+=3)for(int c=0;c<3;++c)
                output[i+c]=Finite(Dot(packed[i],packed[i+1],packed[i+2],matrix[c],matrix[c+4],matrix[c+8],true,matrix[c+12]));
            return output;
        }
        // Original6042e0 scalar branch (runtime297c0d0==0), fifth native arg0.
        // Null transform represents native null/806680 default-view pointers.
        // Enabled=false returns1 before dereferencing bounds/camera inputs and
        // leaves scratch globals unchanged. Returns0outside/1inside/2partial.
        public static int Classify(DynamicBoxState state,float[] minimum,float[] maximum,float[] transform,float requestedFar)
        {
            if(state==null)throw new ArgumentNullException("state");if(!state.Enabled)return 1;
            Size(minimum,3);Size(maximum,3);Size(state.View,16);Finite(state.Near);Finite(state.Far);Finite(state.FarOverride);Finite(state.HorizontalSlope);Finite(state.VerticalSlope);Finite(requestedFar);
            if(state.CombinedMatrix==null || state.CombinedMatrix.Length!=16 || state.FarLanes==null || state.FarLanes.Length!=4)throw new ArgumentException("Explicit original scratch storage required.");
            float limit=requestedFar!=0?requestedFar:state.FarOverride!=0?state.FarOverride:state.Far;
            float[] combined=transform==null?(float[])state.View.Clone():MultiplyAffine(transform,state.View);Array.Copy(combined,state.CombinedMatrix,16);for(int i=0;i<4;++i)state.FarLanes[i]=limit;
            float[] corners=new float[24];int[] masks=new int[]{0,7,4,3,2,6,1,5};for(int i=0;i<8;++i)for(int c=0;c<3;++c)corners[i*3+c]=(masks[i]&(1<<c))!=0?maximum[c]:minimum[c];
            corners=TransformPoints(corners,combined);state.LastCorners=corners;int all=63,any=0;
            for(int i=0;i<8;++i)
            {
                float x=corners[i*3],y=corners[i*3+1],z=corners[i*3+2];int code=0;
                if(z<state.Near)code|=32;if(limit<z)code|=16;
                // Two float32 factors multiply exactly within double's53-bit
                // significand, matching these unrounded finite x87 products.
                double horizontal=(double)z*state.HorizontalSlope,vertical=(double)z*state.VerticalSlope;
                if(x< -horizontal)code|=1;if(horizontal<x)code|=2;if(y< -vertical)code|=8;if(vertical<y)code|=4;all&=code;any|=code;
            }
            return all!=0?0:any!=0?2:1;
        }
    }
}
