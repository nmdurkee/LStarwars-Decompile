// PC billboard CPU payload and packets; shader/GPU consumption remains separate.
using System;
using Recovered.Geometry;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Animation
{
    public static class BillboardMeshPackets
    {
        static float Finite(float x){if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite billboard arithmetic required");return x;}
        static void Size(float[] x,int n){if(x==null||x.Length!=n)throw new ArgumentException("Billboard input dimensions");foreach(float v in x)Finite(v);}
        static float Store(Wide value,double approximate)
        {float x=Finite(value.Store());return x==0&&approximate==0?(float)approximate:x;}
        static float Squared(float[] v)
        {return Finite(Wide.Add(Wide.Add(Wide.Multiply(Wide.From(v[1]),Wide.From(v[1])),Wide.Multiply(Wide.From(v[0]),Wide.From(v[0]))),Wide.Multiply(Wide.From(v[2]),Wide.From(v[2]))).Store());}
        static float[] Cross(float[] a,float[] b)
        {
            var r=new float[3];int[] p={1,2,0},q={2,0,1};for(int i=0;i<3;++i)r[i]=Store(Wide.Add(Wide.Multiply(Wide.From(a[p[i]]),Wide.From(b[q[i]])),Wide.Multiply(Wide.From(-a[q[i]]),Wide.From(b[p[i]]))),(double)a[p[i]]*b[q[i]]-(double)a[q[i]]*b[p[i]]);return r;
        }
        static float[] Normalized(float[] v)
        {
            float length=(float)Math.Sqrt(Squared(v)),inverse=length<=0?0:Finite(Wide.Divide(Wide.From(1),Wide.From(length)).Store());var result=new float[3];for(int i=0;i<3;++i)result[i]=Store(Wide.Multiply(Wide.From(inverse),Wide.From(v[i])),(double)inverse*v[i]);return result;
        }
        // 0x5edbb0. Transposed view basis with X/Z sign changes, supplied origin.
        public static float[] FaceCamera(float[] view,float[] origin)
        {
            Size(view,16);Size(origin,3);var m=new float[16];for(int i=0;i<3;++i){m[i]=-view[i*4];m[4+i]=view[i*4+1];m[8+i]=-view[i*4+2];m[12+i]=origin[i];}m[15]=1;return m;
        }
        // 0x5edd10. Camera-forward cross supplied axis; normalize first row only.
        public static float[] FaceAxis(float[] cameraForward,float[] axis)
        {
            Size(cameraForward,3);Size(axis,3);float[] right=Normalized(Cross(cameraForward,axis)),forward=Cross(right,axis);var m=new float[16];for(int i=0;i<3;++i){m[i]=right[i];m[4+i]=axis[i];m[8+i]=forward[i];}m[15]=1;return m;
        }
        static float[] Read(RenderPacketMemory memory,uint p,int count)
        {var a=new float[count];for(int i=0;i<count;++i)a[i]=Finite(PcObjectImage.FromBits(memory.Dword(p+(uint)i*4)));return a;}
        static void Write(RenderPacketMemory memory,uint p,float[] values)
        {for(int i=0;i<values.Length;++i)memory.Dword(p+(uint)i*4,PcObjectImage.ToBits(values[i]));}
        // 0x603610. Material argument is unused. Payload is64+4+64 bytes.
        public static uint BuildPayload(RenderPacketMemory memory,uint allocatorControl,uint matrix,uint resource,float[] view,float[] cameraForward)
        {
            uint start=checked(memory.Dword(allocatorControl)+3)&~3u;memory.Dword(allocatorControl,start);float[] world=Read(memory,matrix,16);memory.Block(start,memory.Block(matrix,64));
            float y=Squared(new[]{world[4],world[5],world[6]}),x=Squared(new[]{world[0],world[1],world[2]}),z=Squared(new[]{world[8],world[9],world[10]});
            double xy=Wide.Add(Wide.From(x),Wide.FromDouble((double)y)).StoreDouble();float mean=Finite(Wide.Multiply(Wide.Add(Wide.From(z),Wide.FromDouble(xy)),Wide.FromDouble(0.3333333432674408)).Store());float scale=(float)Math.Sqrt(mean);
            memory.Dword(allocatorControl,checked(start+64));memory.Dword(start+64,PcObjectImage.ToBits(scale));memory.Dword(allocatorControl,checked(start+132));
            float[] facing=memory.Dword(resource)==0?FaceCamera(view,new float[3]):FaceAxis(cameraForward,new[]{world[4],world[5],world[6]});Write(memory,start+68,facing);return start;
        }
        // 0x603970 ignores allocator/world arguments and returns the resource.
        public static uint ResourceIdentity(uint resource){return resource;}
        static uint Command(RenderPacketMemory memory,uint record,byte opcode,uint payload)
        {uint p=memory.Dword(record+0x24);memory.Byte(p,opcode);memory.Byte(p+1,3);memory.Dword(p+4,payload);memory.Dword(record+0x24,checked(p+16));return p;}
        // 0x5e0490: EAX record / EDI output, stack command/world/alpha.
        public static void Build(RenderPacketMemory memory,uint allocatorControl,uint record,uint command,uint matrix,uint output,uint alphaWord,float[] view,float[] cameraForward)
        {
            DynamicCommandSupport.Reserve(memory,allocatorControl,record,2);uint owner=memory.Dword(record);memory.Dword(memory.Dword(owner+0x50)+memory.Dword(record+4)*4);uint resource=memory.Dword(command+4);
            uint payload=BuildPayload(memory,allocatorControl,matrix,resource,view,cameraForward);uint first=Command(memory,record,0x90,payload);memory.Dword(output,first);uint second=Command(memory,record,0x8f,ResourceIdentity(resource));memory.Dword(output+4,second);DynamicCommandSupport.StoreAlpha(memory,first,alphaWord);
        }
    }
}
