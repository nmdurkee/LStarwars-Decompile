// Finite CPU light-volume math. Original-x86 versus Python fixtures pass;
// compiled C# runtime comparison remains pending. GPU behavior is not modeled.
using System;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public static class ShadowVolume
    {
        static readonly int[,] Faces={{0,1,2,3},{3,2,6,7},{7,6,5,4},{4,5,1,0},{1,5,6,2},{4,0,3,7}};
        static readonly int[,] Edges={{0,1},{1,2},{2,3},{3,0},{4,5},{5,6},{6,7},{7,4},{0,4},{1,5},{2,6},{3,7}};
        static readonly int[,] Adjacent={{3,0},{4,0},{1,0},{5,0},{2,3},{2,4},{2,1},{2,5},{5,3},{3,4},{4,1},{1,5}};
        static float Finite(float value)
        {if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite shadow-volume arithmetic required.");return value;}
        static void Inputs(float[] direction,float[] corners)
        {if(direction==null||direction.Length<3||corners==null||corners.Length<32)throw new ArgumentException("Direction and eight XYZW corners required.");for(int j=0;j<3;++j)Finite(direction[j]);for(int i=0;i<8;++i)for(int j=0;j<3;++j)Finite(corners[i*4+j]);}
        static float Store(Wide exact,double approximate)
        {float value=Finite(exact.Store());return value==0&&approximate==0?(float)approximate:value;}
        static Wide Product(float a,float b){return Wide.Multiply(Wide.From(a),Wide.From(b));}
        static float Dot(float[] a,float[] b)
        {return Store(Wide.Add(Wide.Add(Product(a[1],b[1]),Product(a[0],b[0])),Product(a[2],b[2])),((double)a[1]*b[1]+(double)a[0]*b[0])+(double)a[2]*b[2]);}
        static float[] Corner(float[] corners,int index){return new float[]{corners[index*4],corners[index*4+1],corners[index*4+2]};}
        static float[] Cross(float[] a,float[] b)
        {int[] first={1,2,0},second={2,0,1};var result=new float[3];for(int k=0;k<3;++k){int i=first[k],j=second[k];result[k]=Store(Wide.Add(Product(a[i],b[j]),Product(-a[j],b[i])),(double)a[i]*b[j]-(double)a[j]*b[i]);}return result;}
        static float[] Normalize(float[] value)
        {float length=Finite((float)Math.Sqrt(Dot(value,value)));float inverse=length>0?Finite(Wide.Divide(Wide.From(1),Wide.From(length)).Store()):0;var result=new float[3];for(int j=0;j<3;++j)result[j]=Store(Product(value[j],inverse),(double)value[j]*inverse);return result;}
        //0x5c82c0. Native global extrusion length is120. Plane order follows
        // source face/edge tables; at most nine planes are written. Rest untouched.
        public static int SelectPlanes(float[] direction,float[] corners,float[] output)
        {
            Inputs(direction,corners);if(output==null||output.Length<36||Object.ReferenceEquals(output,direction)||Object.ReferenceEquals(output,corners))throw new ArgumentException("Disjoint storage for nine planes required.");
            var extrusion=new float[3];for(int j=0;j<3;++j)extrusion[j]=Finite((float)(-120.0*direction[j]));var facing=new bool[6];int count=0;
            for(int f=0;f<6;++f)
            {
                float[] a=Corner(corners,Faces[f,0]),b=Corner(corners,Faces[f,1]),c=Corner(corners,Faces[f,2]);var left=new float[3];var right=new float[3];for(int j=0;j<3;++j){left[j]=Finite((float)((double)b[j]-a[j]));right[j]=Finite((float)((double)c[j]-a[j]));}float[] cross=Cross(left,right);facing[f]=Dot(cross,extrusion)>=0;
                if(!facing[f]){for(int j=0;j<3;++j)cross[j]=-cross[j];float[] normal=Normalize(cross);for(int j=0;j<3;++j)output[count*4+j]=normal[j];output[count*4+3]=-Dot(normal,a);++count;}
            }
            for(int e=0;e<12&&count<9;++e)
            {
                if(facing[Adjacent[e,0]]==facing[Adjacent[e,1]])continue;float[] a=Corner(corners,Edges[e,0]),b=Corner(corners,Edges[e,1]);var c=new float[3];for(int j=0;j<3;++j)c[j]=Finite((float)((double)a[j]+extrusion[j]));float[] p=facing[Adjacent[e,0]]?ShadowFrustum.PlaneFromPoints(a,b,c):ShadowFrustum.PlaneFromPoints(c,b,a);Array.Copy(p,0,output,count*4,4);++count;
            }
            return count;
        }
        //0x5c8540 known-lane projection. It accumulates center sequentially.
        // Native computes a maximum squared distance but passes corner7's LAST
        // distance to sqrt; this deliberately preserves that instruction behavior.
        // Position W comes from undefined native stack padding and stays untouched.
        public static float Aggregate(float[] direction,float[] corners,float[] center,float[] position)
        {
            Inputs(direction,corners);Finite(corners[3]);if(center==null||center.Length<4||position==null||position.Length<4||Object.ReferenceEquals(center,position)||Object.ReferenceEquals(center,direction)||Object.ReferenceEquals(center,corners)||Object.ReferenceEquals(position,direction)||Object.ReferenceEquals(position,corners))throw new ArgumentException("Disjoint center and position outputs required.");
            Array.Copy(corners,center,4);for(int i=1;i<8;++i)for(int j=0;j<3;++j)center[j]=Finite((float)((double)corners[i*4+j]+center[j]));for(int j=0;j<3;++j)center[j]=Finite((float)((double)center[j]*.125));
            float last=0;for(int i=0;i<8;++i){var difference=new float[3];for(int j=0;j<3;++j)difference[j]=Finite((float)((double)center[j]-corners[i*4+j]));last=Dot(difference,difference);}float radius=Finite((float)Math.Sqrt(last));
            for(int j=0;j<3;++j){float offset=Finite((float)((double)direction[j]*100.0));position[j]=Finite((float)((double)center[j]-offset));}return radius;
        }
    }
}
