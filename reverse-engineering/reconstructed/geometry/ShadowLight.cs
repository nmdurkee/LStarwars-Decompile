// Original CPU light view/projection setup. Native/model exact comparisons pass;
// compiled managed execution remains pending. Inputs are finite/disjoint.
using System;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public static class ShadowLight
    {
        static float Finite(float v){if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite light arithmetic required.");return v;}
        static void Vector(float[] v){if(v==null||v.Length<3)throw new ArgumentException("Complete finite vector required.");for(int j=0;j<3;++j)Finite(v[j]);}
        static Wide Product(float a,float b){return Wide.Multiply(Wide.From(a),Wide.From(b));}
        static float Store(Wide exact,double approximate){float value=Finite(exact.Store());return value==0&&approximate==0?(float)approximate:value;}
        static float[] Cross(float[] a,float[] b){int[] first={1,2,0},second={2,0,1};var r=new float[3];for(int k=0;k<3;++k){int i=first[k],j=second[k];r[k]=Store(Wide.Add(Product(a[i],b[j]),Product(-a[j],b[i])),(double)a[i]*b[j]-(double)a[j]*b[i]);}return r;}
        // Private numerical support for an existing5b3b30 mapping, no new claim.
        static float[] Normalize(float[] v)
        {
            float squared=Finite(Wide.Add(Wide.Add(Product(v[1],v[1]),Product(v[0],v[0])),Product(v[2],v[2])).Store());float length=Finite((float)Math.Sqrt(squared)),inverse=length>0?Finite(Wide.Divide(Wide.From(1),Wide.From(length)).Store()):0;var r=new float[3];for(int i=0;i<3;++i)r[i]=Store(Product(v[i],inverse),(double)v[i]*inverse);return r;
        }
        static float[] Direction(float[] eye,float[] target){var d=new float[3];for(int j=0;j<3;++j)d[j]=Finite((float)((double)target[j]-eye[j]));return Normalize(d);}
        //0x5b7390. All three basis vectors normalized in original order.
        // Degenerate eye=target or parallel up retains original zero vectors.
        public static float[] LookAt(float[] eye,float[] target,float[] up)
        {
            Vector(eye);Vector(target);Vector(up);float[] forward=Direction(eye,target),right=Normalize(Cross(up,forward)),vertical=Normalize(Cross(forward,right));var result=new float[16];for(int i=0;i<3;++i){result[i*4]=right[i];result[i*4+1]=vertical[i];result[i*4+2]=forward[i];}float[][] axes={right,vertical,forward};
            for(int j=0;j<3;++j){float[] a=axes[j];result[12+j]=Store(Wide.Add(Wide.Add(Product(-eye[0],a[0]),Product(-eye[1],a[1])),Product(-eye[2],a[2])),(-(double)eye[0]*a[0]-(double)eye[1]*a[1])-(double)eye[2]*a[2]);}result[15]=1;return result;
        }
        static void Write(RenderPacketMemory m,uint address,float[] values){for(int i=0;i<values.Length;++i)m.Dword(checked(address+(uint)i*4),BitConverter.ToUInt32(BitConverter.GetBytes(values[i]),0));}
        //0x5952c0 original ECX=context, stack eye/target/up; callee pops12B.
        public static void ConfigureView(RenderPacketMemory m,uint context,float[] eye,float[] target,float[] up)
        {
            Vector(eye);Vector(target);Vector(up);if(m==null)throw new ArgumentNullException("m");m.Block(context,0x830);float[] d=Direction(eye,target);Write(m,checked(context+0x770),new float[]{d[0],d[1],d[2],1});Write(m,context+0x760,new float[]{eye[0],eye[1],eye[2],1});Write(m,context+0x780,LookAt(eye,target,up));
        }
        //0x5c6c10 ABI adapter; native moves context from cdecl arg1 intoECX.
        public static void ConfigureViewCdecl(RenderPacketMemory m,uint context,float[] eye,float[] target,float[] up){ConfigureView(m,context,eye,target,up);}
        //0x5b79d0. Extents are left/right,bottom/top,near/far.
        public static float[] Orthographic(float[] extents)
        {
            if(extents==null||extents.Length<6)throw new ArgumentException("Six finite orthographic extents required.");var result=new float[16];for(int axis=0;axis<3;++axis){float low=Finite(extents[axis*2]),high=Finite(extents[axis*2+1]);if(low==high)throw new ArgumentException("Nonzero orthographic extent required.");result[axis*5]=Store(Wide.Divide(Wide.From(2),Wide.Add(Wide.From(high),Wide.From(-low))),2.0/((double)high-low));result[12+axis]=Store(Wide.Divide(Wide.Add(Wide.From(low),Wide.From(high)),Wide.Add(Wide.From(low),Wide.From(-high))),((double)low+high)/((double)low-high));}result[15]=1;return result;
        }
        //0x595360 sets mode0 and forwards six extents to5b79d0.
        public static void ConfigureOrthographic(RenderPacketMemory m,uint context,float[] extents)
        {if(m==null)throw new ArgumentNullException("m");m.Block(context,0x830);m.Dword(checked(context+0x800),0);Write(m,context+0x7c0,Orthographic(extents));}
    }
}
