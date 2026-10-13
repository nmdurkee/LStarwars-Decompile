// Original5e8950 CPU camera-to-light-volume extraction, known-lane projection.
// Original-PC/model equality passed; C# runtime equality remains pending.
using System;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public static class ShadowExtraction
    {
        static float F(RenderPacketMemory m,uint p){return BitConverter.ToSingle(BitConverter.GetBytes(m.Dword(p)),0);}
        static void F(RenderPacketMemory m,uint p,float v){m.Dword(p,BitConverter.ToUInt32(BitConverter.GetBytes(v),0));}
        static float[] Read(RenderPacketMemory m,uint p,int count){var result=new float[count];for(int i=0;i<count;++i)result[i]=F(m,checked(p+(uint)i*4));return result;}
        static void Write(RenderPacketMemory m,uint p,float[] values,int count){for(int i=0;i<count;++i)F(m,checked(p+(uint)i*4),values[i]);}
        static void Disjoint(uint a,uint an,uint b,uint bn){if((ulong)a+an>0x100000000UL||(ulong)b+bn>0x100000000UL||(an!=0&&bn!=0&&(ulong)a<(ulong)b+bn&&(ulong)b<(ulong)a+an))throw new ArgumentException("Finite disjoint input/context ranges required.");}
        static float Store(Wide value,double approximate){float f=value.Store();if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentException("Finite extraction arithmetic required.");return f==0&&approximate==0?(float)approximate:f;}
        // Original ECX=context; stack(camera,cuts,cutCount), callee pops12B.
        // projection/view adapt original globals978440/97ac80. Camera near/far
        // end unchanged, matching native temporary mutation/restoration.
        public static void Extract(RenderPacketMemory m,uint context,uint camera,uint cuts,int cutCount,float[] sineTable,float[] projection,float[] view)
        {
            if(m==null||cutCount<0||cutCount>3||projection==null||projection.Length<16||view==null||view.Length<16||Object.ReferenceEquals(projection,view)||Object.ReferenceEquals(sineTable,view))throw new ArgumentException("Fixed two-volume context and disjoint complete matrices required.");Disjoint(context,0x830,camera,80);Disjoint(context,0x830,cuts,(uint)cutCount*4);Disjoint(camera,80,cuts,(uint)cutCount*4);m.Block(context,0x830);float[] cam=Read(m,camera,20),split=Read(m,cuts,cutCount),direction=Read(m,context+0x770,3);var world=new float[16];Array.Copy(cam,world,16);
            float degrees=Store(Wide.Divide(Wide.Multiply(Wide.From(cam[16]),Wide.FromDouble(180)),Wide.FromDouble(3.1415927410125732)),(double)cam[16]*180/3.1415927410125732),aspect=Store(Wide.Divide(Wide.From(1),Wide.From(cam[17])),1.0/cam[17]);ShadowCamera.Perspective(degrees,aspect,cam[18],cam[19],sineTable,projection);ShadowCamera.RigidInverse(world,view);
            Write(m,context+0x740,new float[]{cam[12],cam[13],cam[14],1},4);Write(m,context+0x750,new float[]{cam[8],cam[9],cam[10],0},4);m.Dword(context+0x710,unchecked((uint)(cutCount-1)));Write(m,context+0x700,split,cutCount);
            for(int i=0;i<cutCount-1;++i)
            {
                uint volume=context+(uint)i*0x380;float[] corners=Read(m,volume+0x120,32),farPlane=new float[4];ShadowFrustum.Build(world,cam[16],cam[17],split[i],split[i+1],sineTable,corners,farPlane);
                for(int k=0;k<8;++k)for(int j=0;j<(k<4?4:3);++j)F(m,volume+0x120+(uint)k*16+(uint)j*4,corners[k*4+j]);Write(m,volume+0x270,farPlane,4);
                var planes=new float[36];int count=ShadowVolume.SelectPlanes(direction,corners,planes);Write(m,volume+0x1a0,planes,count*4);m.Dword(volume+0x260,(uint)count);m.Block(volume,m.Block(context+0x780,128));
                var center=new float[4];float[] position=Read(m,volume+0x290,4);float radius=ShadowVolume.Aggregate(direction,corners,center,position);Write(m,volume+0x280,center,4);Write(m,volume+0x290,position,3);F(m,volume+0x2a0,radius);
            }
            for(int i=0;i<cutCount-1;++i)Write(m,context+0x720+(uint)i*16,new float[]{0,0,Store(Wide.Divide(Wide.From(1),Wide.From(split[i+1])),1.0/split[i+1]),-1},4);
        }
    }
}
