// Original finite shadow frustum geometry. Far-corner W is native undefined
// stack padding; this portable known-lane projection leaves caller W untouched.
using System;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public static class ShadowFrustum
    {
        static float Finite(float v)
        {if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite shadow frustum arithmetic required.");return v;}
        static void Vector(float[] v,int length)
        {if(v==null||v.Length<length)throw new ArgumentException("Complete finite vector required.");for(int i=0;i<length;++i)Finite(v[i]);}
        static float Store(Wide exact,double approximate)
        {float v=Finite(exact.Store());return v==0&&approximate==0?(float)approximate:v;}
        static Wide Product(float a,float b){return Wide.Multiply(Wide.From(a),Wide.From(b));}
        static float[] Cross(float[] a,float[] b)
        {
            var v=new float[3];int[] first={1,2,0},second={2,0,1};for(int k=0;k<3;++k){int i=first[k],j=second[k];v[k]=Store(Wide.Add(Product(a[i],b[j]),Product(-a[j],b[i])),(double)a[i]*b[j]-(double)a[j]*b[i]);}return v;
        }
        //0x5c7fa0. Original ESI=a,ECX=b,EAX=c,EDI=output.
        public static float[] PlaneFromPoints(float[] a,float[] b,float[] c)
        {
            Vector(a,3);Vector(b,3);Vector(c,3);var left=new float[3];var right=new float[3];for(int i=0;i<3;++i){left[i]=Finite((float)((double)b[i]-a[i]));right[i]=Finite((float)((double)c[i]-a[i]));}float[] cross=Cross(left,right);
            float squared=Finite(Wide.Add(Wide.Add(Product(cross[1],cross[1]),Product(cross[0],cross[0])),Product(cross[2],cross[2])).Store());float length=Finite((float)Math.Sqrt(squared));float reciprocal=length>0?Finite(Wide.Divide(Wide.From(1),Wide.From(length)).Store()):0;
            var result=new float[4];for(int i=0;i<3;++i)result[i]=Store(Product(cross[i],reciprocal),(double)cross[i]*reciprocal);
            float constant=Store(Wide.Add(Wide.Add(Product(result[1],a[1]),Product(result[0],a[0])),Product(result[2],a[2])),((double)result[1]*a[1]+(double)result[0]*a[0])+(double)result[2]*a[2]);result[3]=-constant;return result;
        }
        static float[] Transform(float[] p,float[] matrix)
        {
            var result=new float[3];for(int i=0;i<3;++i)result[i]=Store(Wide.Add(Wide.Add(Wide.Add(Product(p[0],matrix[i]),Product(p[1],matrix[i+4])),Product(p[2],matrix[i+8])),Wide.From(matrix[i+12])),(((double)p[0]*matrix[i]+(double)p[1]*matrix[i+4])+(double)p[2]*matrix[i+8])+matrix[i+12]);return result;
        }
        //0x5c8030: eight XYZ corners and a far plane. FOV is radians.
        // Original half-FOV stores tofloat32 before the signed CRT conversion.
        // Bounded FOV[-1,3] fits both original conversion policies identically.
        // Corners has32 floats: near W becomes1, four far W remain untouched.
        public static uint Build(float[] matrix,float fov,float aspect,float near,float far,float[] sineTable,float[] corners,float[] farPlane)
        {
            Vector(matrix,16);Finite(fov);Finite(aspect);Finite(near);Finite(far);if(fov<-1||fov>3||aspect==0||near==0)throw new ArgumentException("Bounded FOV and nonzero aspect/near required.");
            if(sineTable==null||sineTable.Length!=32768||corners==null||corners.Length<32||farPlane==null||farPlane.Length<4)throw new ArgumentException("Original sine table and complete output storage required.");if(Object.ReferenceEquals(corners,matrix)||Object.ReferenceEquals(corners,farPlane)||Object.ReferenceEquals(farPlane,matrix)||Object.ReferenceEquals(sineTable,corners)||Object.ReferenceEquals(sineTable,farPlane))throw new ArgumentException("Disjoint inputs and output arrays required.");
            float phase=Finite((float)((double)fov*.5));uint angle=unchecked((uint)(int)(phase*10430.3779296875));float sy=Finite(sineTable[(angle>>1)&32767]),cy=Finite(sineTable[(unchecked(angle+0x4000)>>1)&32767]);if(cy==0)throw new ArgumentException("Nonzero sampled cosine required.");
            float y=Store(Wide.Divide(Product(sy,near),Wide.From(cy)),(double)sy*near/cy),x=Store(Wide.Divide(Wide.From(y),Wide.From(aspect)),(double)y/aspect),ratio=Store(Wide.Divide(Wide.From(far),Wide.From(near)),(double)far/near);
            float[][] local={new float[]{-x,-y,near},new float[]{-x,y,near},new float[]{x,y,near},new float[]{x,-y,near}};var transformed=new float[8][];
            for(int i=0;i<8;++i)
            {
                float[] p=(float[])local[i&3].Clone();if(i>=4)for(int j=0;j<3;++j)p[j]=Store(Product(p[j],ratio),(double)p[j]*ratio);transformed[i]=Transform(p,matrix);for(int j=0;j<3;++j)corners[i*4+j]=transformed[i][j];if(i<4)corners[i*4+3]=1;
            }
            float[] plane=PlaneFromPoints(transformed[4],transformed[5],transformed[6]);Array.Copy(plane,farPlane,4);return angle;
        }
    }
}
