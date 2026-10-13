// PC 5e2920: bounded four-edge and ten-edge legacy shadow side writer.
using System;
using Recovered.Gameplay;
namespace Recovered.Animation
{
    public static class LegacyCylinderShadows
    {
        struct N
        {
            PlaybackWide value;bool negative;
            public N(float v){value=PlaybackWide.From(v);negative=(PcObjectImage.ToBits(v)&0x80000000u)!=0;}
            static N Make(PlaybackWide v,bool z){double d=v.StoreDouble();return new N{value=v,negative=d<0||(d==0&&z)};}
            public static N operator +(N a,N b){return Make(PlaybackWide.Add(a.value,b.value),a.negative&&b.negative);}
            public static N operator -(N a,N b){return Make(PlaybackWide.Add(a.value,PlaybackWide.Multiply(b.value,PlaybackWide.From(-1))),a.negative&&!b.negative);}
            public static N operator -(N a){return Make(PlaybackWide.Multiply(a.value,PlaybackWide.From(-1)),!a.negative);}
            public static N operator *(N a,N b){return Make(PlaybackWide.Multiply(a.value,b.value),a.negative!=b.negative);}
            public N RoundDouble(){return Make(PlaybackWide.FromDouble(value.StoreDouble()),negative);}
            public float Store(){float v=value.Store();if(Single.IsInfinity(v)||Single.IsNaN(v))throw new ArgumentException("Finite cylinder output required.");return v==0&&value.StoreDouble()==0?PcObjectImage.FromBits(negative?0x80000000u:0u):v;}
        }
        static void Finite(float x){if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite active cylinder input required.");}
        static void Check(float[] v,int length){if(v==null||v.Length!=length)throw new ArgumentException("Resolved vector required.");foreach(float x in v)Finite(x);}
        static float Reciprocal(float x){return x==0?0:PlaybackWide.Divide(PlaybackWide.From(1),PlaybackWide.From(x)).Store();}
        static void U(byte[] b,int p,uint v){b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
        static void Vertex(LegacyShadowGeometryState s,float[] v)
        {
            ulong p=(ulong)s.VertexCount*16;if(s.Vertices==null||p+16>(ulong)s.Vertices.Length)throw new ArgumentException("Sufficient output backing required.");
            for(int i=0;i<3;++i)U(s.Vertices,(int)p+i*4,PcObjectImage.ToBits(v[i]));U(s.Vertices,(int)p+12,0xffffffff);s.VertexCount=unchecked(s.VertexCount+1);
        }
        static float[][] Edge(int edge,float[] axis,float[] side,float radius,float inverse,bool rounded)
        {
            var result=new[]{new float[3],new float[3]};N k=new N(.707f),r=new N(radius),inv=new N(inverse);
            for(int j=0;j<3;++j)
            {
                N a=new N(axis[j]),s=new N(side[j]),sr=s*r,x,y;
                if(!rounded){N[] v={s+a,s-a,-a-s,a-s,s+a};x=v[edge];y=v[edge+1];}
                else switch(edge)
                {
                    case 0:x=sr+a;y=sr.RoundDouble()-a;break;
                    case 1:x=sr-a;y=(sr.RoundDouble()*k-a)-(j==2?a*inv:inv*a)*r*k;break;
                    case 2:x=(sr*k-a)-(j==2?a*inv:inv*a)*r*k;y=-a-(j==2?inv*r*a:r*a*inv);break;
                    case 3:x=-a-(j==2?inv*r*a:r*a*inv);y=(-a-sr*k)-inv*a*r*k;break;
                    case 4:x=(-a-sr*k)-(j==2?r*inv*a:inv*a*r)*k;y=-a-sr.RoundDouble();break;
                    case 5:x=-a-sr;y=a-sr.RoundDouble();break;
                    case 6:x=a-sr;y=(a-sr.RoundDouble()*k)+r*a*inv*k;break;
                    case 7:N cap7=(r*a*inv).RoundDouble();x=(a-sr*k)+cap7*k;y=a+cap7;break;
                    case 8:N cap8=r*a*inv;x=cap8+a;y=(sr*k+a)+cap8.RoundDouble()*k;break;
                    default:x=(sr*k+a)+r*a*inv*k;y=a+sr.RoundDouble();break;
                }
                result[0][j]=x.Store();result[1][j]=y.Store();
            }
            return result;
        }
        // The raw low bit of center X selects the rounded branch. It is not
        // cleared before center X is used. Words 9 and 13..15 are never read.
        public static void Emit(LegacyShadowGeometryState state,float[] cylinder,float[] matrix,float[] direction)
        {
            if(state==null)throw new ArgumentNullException("state");if(cylinder==null||cylinder.Length!=16)throw new ArgumentException("Sixteen source words required.");for(int i=0;i<13;++i)if(i!=9)Finite(cylinder[i]);Check(matrix,16);Check(direction,3);
            bool rounded=(PcObjectImage.ToBits(cylinder[0])&1)!=0;uint edges=rounded?10u:4u;
            if(state.GroupCount<250)
            {
                if(state.GroupStarts==null||state.GroupEdgeCounts==null||state.GroupStarts.Length<250||state.GroupEdgeCounts.Length<250)throw new ArgumentException("Two 250-entry group arrays required.");state.GroupStarts[state.GroupCount]=state.VertexCount;state.GroupEdgeCounts[state.GroupCount]=edges;++state.GroupCount;
            }
            float[] center=LegacyPolygonShadows.TransformPoint(new[]{cylinder[0],cylinder[1],cylinder[2],1f},matrix);var axes=new float[3][];int[] offsets={3,6,10};
            for(int i=0;i<3;++i)
            {
                var endpoint=new float[4];endpoint[3]=1;for(int j=0;j<3;++j)endpoint[j]=(new N(cylinder[j])+new N(cylinder[offsets[i]+j])).Store();endpoint=LegacyPolygonShadows.TransformPoint(endpoint,matrix);axes[i]=new float[3];for(int j=0;j<3;++j)axes[i][j]=(new N(endpoint[j])-new N(center[j])).Store();
            }
            N x=new N(axes[0][0]),y=new N(axes[0][1]),z=new N(axes[0][2]),dx=new N(direction[0]),dy=new N(direction[1]),dz=new N(direction[2]);var side=new[]{(y*dz-z*dy).Store(),(dx*z-dz*x).Store(),(x*dy-y*dx).Store()};N sx=new N(side[0]),sy=new N(side[1]),sz=new N(side[2]);float squared=(sx*sx+sy*sy+sz*sz).Store();
            if(squared>0)squared=Reciprocal(BuildEffectSound.SquareRoot(squared));for(int j=0;j<3;++j)side[j]=(new N(side[j])*new N(squared)).Store();
            squared=(x*x+y*y+z*z).Store();float inverse=0;if(squared>0)inverse=Reciprocal(BuildEffectSound.SquareRoot(squared));var dots=new float[2];for(int i=0;i<2;++i)dots[i]=(new N(side[1])*new N(axes[i+1][1])+new N(side[0])*new N(axes[i+1][0])+new N(side[2])*new N(axes[i+1][2])).Store();float radius=BuildEffectSound.SquareRoot((new N(dots[0])*new N(dots[0])+new N(dots[1])*new N(dots[1])).Store());
            if(!rounded)for(int j=0;j<3;++j)side[j]=(new N(side[j])*new N(radius)).Store();
            for(int edge=0;edge<edges;++edge)
            {
                if(rounded)state.GeneratedValue=unchecked(state.GeneratedValue+2);float[][] pair=Edge(edge,axes[0],side,radius,inverse,rounded);var ea=new float[3];var eb=new float[3];
                for(int j=0;j<3;++j){pair[0][j]=(new N(center[j])+new N(pair[0][j])).Store();pair[1][j]=(new N(pair[1][j])+new N(center[j])).Store();ea[j]=(new N(direction[j])*new N(5)+new N(pair[0][j])).Store();eb[j]=(new N(direction[j])*new N(5)+new N(pair[1][j])).Store();}
                Vertex(state,pair[0]);Vertex(state,ea);Vertex(state,eb);Vertex(state,pair[1]);
            }
        }
    }
}
