// Original PC polygon shadow sides and scalar4D transforms.
using System;
namespace Recovered.Animation
{
    public sealed class LegacyShadowPolygons
    {
        // Original first vertex+12 is signed polygon count; each normal+12
        //is its signed edge count. XYZ vertices are concatenated by polygon.
        public int PolygonCount;
        public float[][] Normals,Vertices;
        public int[] EdgeCounts;
    }
    public sealed class LegacyShadowGeometryState
    {
        public byte[] Vertices; //963f94; each output isXYZ floats then color
        public uint VertexCount,GroupCount,GeneratedValue; //973fec,973ff0,971878
        public uint[] GroupStarts,GroupEdgeCounts; //963f88,96e568;250 entries
    }
    public static class LegacyPolygonShadows
    {
        struct N
        {
            PlaybackWide value;bool negative;
            public N(float v){value=PlaybackWide.From(v);negative=(PcObjectImage.ToBits(v)&0x80000000u)!=0;}
            static N Make(PlaybackWide v,bool z){double d=v.StoreDouble();return new N{value=v,negative=d<0||(d==0&&z)};}
            public static N operator +(N a,N b){return Make(PlaybackWide.Add(a.value,b.value),a.negative&&b.negative);}
            public static N operator *(N a,N b){return Make(PlaybackWide.Multiply(a.value,b.value),a.negative!=b.negative);}
            public double CompareValue(){return value.StoreDouble();}
            public float Store(){float v=value.Store();if(Single.IsInfinity(v)||Single.IsNaN(v))throw new ArgumentException("Finite shadow transform output required.");return v==0&&value.StoreDouble()==0?PcObjectImage.FromBits(negative?0x80000000u:0u):v;}
        }
        static void Check(float[] v,int count){if(v==null||v.Length!=count)throw new ArgumentException("Resolved finite vector/matrix required.");foreach(float x in v)if(Single.IsInfinity(x)||Single.IsNaN(x))throw new ArgumentException("Finite input required.");}
        static float[] Transform(float[] vector,float[] matrix,bool direction)
        {
            Check(vector,4);Check(matrix,16);var result=new float[4];
            for(int i=0;i<(direction?3:4);++i)
            {
                N v=new N(vector[0])*new N(matrix[i])+new N(vector[1])*new N(matrix[4+i])+new N(vector[2])*new N(matrix[8+i]);
                if(!direction)v=v+new N(vector[3])*new N(matrix[12+i]);result[i]=v.Store();
            }
            if(direction)result[3]=vector[3];return result;
        }
        //0x5c03e0. Owned result supports source in-place usage by assignment;
        //native shifted overlaps and output-overlapping matrix are excluded.
        public static float[] TransformPoint(float[] vector,float[] matrix){return Transform(vector,matrix,false);}
        //0x5c0490. W is copied; translation and matrix fourth column ignored.
        public static float[] TransformDirection(float[] vector,float[] matrix){return Transform(vector,matrix,true);}
        static float[] Four(float[] v){Check(v,3);return new[]{v[0],v[1],v[2],1f};}
        static bool QuietNaNNormal(float[] normal)
        {
            if(normal==null||normal.Length!=3)throw new ArgumentException("Three normal values required.");bool unordered=false;
            foreach(float v in normal)
            {
                uint bits=PcObjectImage.ToBits(v);if((bits&0x7f800000u)!=0x7f800000u)continue;
                if((bits&0x00400000u)==0)throw new ArgumentException("Infinite/signalingNaN normals outside this bound.");unordered=true;
            }
            return unordered;
        }
        static void U(byte[] b,int p,uint v){b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
        static void Vertex(LegacyShadowGeometryState state,float[] v)
        {
            ulong p=(ulong)state.VertexCount*16;if(state.Vertices==null||p+16>(ulong)state.Vertices.Length)throw new ArgumentException("Sufficient disjoint vertex output backing required.");
            for(int i=0;i<3;++i)U(state.Vertices,(int)p+i*4,PcObjectImage.ToBits(v[i]));U(state.Vertices,(int)p+12,0xffffffff);state.VertexCount=unchecked(state.VertexCount+1);
        }
        //0x5e4280. Whole bounded polygon side writer; no graphics API calls.
        //Inputs and output arenas must be disjoint. Normals are transformed by
        //the upper3x3 (not inverse-transpose). Ordered dot<=0 and unordered
        //quietNaN normals both pass the original x87 status-bit test.
        public static void Emit(LegacyShadowGeometryState state,LegacyShadowPolygons shape,float[] matrix,float[] direction)
        {
            if(state==null||shape==null)throw new ArgumentNullException();Check(matrix,16);if(shape.PolygonCount<=0)return;Check(direction,3);
            if(shape.Normals==null||shape.EdgeCounts==null||shape.Normals.Length<shape.PolygonCount||shape.EdgeCounts.Length<shape.PolygonCount||shape.Vertices==null)throw new ArgumentException("Resolved polygon backing required.");
            int first=0;
            for(int i=0;i<shape.PolygonCount;++i)
            {
                int count=shape.EdgeCounts[i];if(count<0||first>shape.Vertices.Length-count)throw new ArgumentException("Nonnegative backed edge counts required.");
                bool accepted=QuietNaNNormal(shape.Normals[i]);
                if(!accepted){float[] normal=TransformDirection(Four(shape.Normals[i]),matrix);N dot=new N(normal[0])*new N(direction[0])+new N(normal[1])*new N(direction[1])+new N(normal[2])*new N(direction[2]);accepted=dot.CompareValue()<=0;}
                if(accepted)
                {
                    if(state.GroupCount<250)
                    {
                        if(state.GroupStarts==null||state.GroupEdgeCounts==null||state.GroupStarts.Length<250||state.GroupEdgeCounts.Length<250)throw new ArgumentException("Two250-entry group arrays required.");
                        state.GroupStarts[state.GroupCount]=state.VertexCount;state.GroupEdgeCounts[state.GroupCount]=(uint)count;++state.GroupCount;
                    }
                    for(int j=0;j<count;++j)
                    {
                        state.GeneratedValue=unchecked(state.GeneratedValue+6);float[] a=TransformPoint(Four(shape.Vertices[first+j]),matrix),b=TransformPoint(Four(shape.Vertices[first+(j+1)%count]),matrix);var ea=new float[3];var eb=new float[3];
                        for(int k=0;k<3;++k){ea[k]=(new N(a[k])+new N(direction[k])).Store();eb[k]=(new N(b[k])+new N(direction[k])).Store();}
                        Vertex(state,a);Vertex(state,ea);Vertex(state,eb);Vertex(state,b);
                    }
                }
                first=checked(first+count);
            }
        }
    }
}
