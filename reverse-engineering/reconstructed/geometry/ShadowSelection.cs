// Bounded original596a30 orchestration. Power backend5be630 is explicit;
// native fixtures execute original CRT/cache, portable code makes no such claim.
using System;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public sealed class ShadowSelectionState
    {
        public uint World,CameraInfo,DefaultCamera,AlternateCamera,FixedCamera,FirstContext,SecondContext,ScratchCuts;
        public uint[] Players;
        public bool Mode,AlternateView;
        public float[] DirectionSeed,Tuning,SineTable,Projection,View;
        // Tuning adapts ten consecutive floats805100..805124; final item is not
        // used for mutable Height. Height/Mask adapt805124/955b40 separately.
        public float Height;
        public uint Mask;
        public Func<float,float,float> Power;
    }
    public static class ShadowSelection
    {
        static float Finite(float v){if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite shadow selection arithmetic required.");return v;}
        static float F(RenderPacketMemory m,uint p){return BitConverter.ToSingle(BitConverter.GetBytes(m.Dword(p)),0);}
        static float[] Read(RenderPacketMemory m,uint p,int count){var v=new float[count];for(int i=0;i<count;++i)v[i]=F(m,checked(p+(uint)i*4));return v;}
        static void Write(RenderPacketMemory m,uint p,float[] v){for(int i=0;i<v.Length;++i)m.Dword(checked(p+(uint)i*4),BitConverter.ToUInt32(BitConverter.GetBytes(v[i]),0));}
        static Wide Product(float a,float b){return Wide.Multiply(Wide.From(a),Wide.From(b));}
        static float Store(Wide exact,double approximate){float v=Finite(exact.Store());return v==0&&approximate==0?(float)approximate:v;}
        static float Squared(float[] v){return Finite(Wide.Add(Wide.Add(Product(v[1],v[1]),Product(v[0],v[0])),Product(v[2],v[2])).Store());}
        // Private support for existing5b3b30 and5becc0 maps; no duplicate credit.
        static float[] Normalize(float[] v)
        {float length=Finite((float)Math.Sqrt(Squared(v))),inverse=length>0?Finite(Wide.Divide(Wide.From(1),Wide.From(length)).Store()):0;var result=new float[3];for(int j=0;j<3;++j)result[j]=Store(Product(v[j],inverse),(double)v[j]*inverse);return result;}
        static float Distance(float[] a,float[] b){var d=new float[3];for(int j=0;j<3;++j)d[j]=Finite((float)((double)a[j]-b[j]));return Finite((float)Math.Sqrt(Squared(d)));}
        static float[] Slice(float[] v,int p){return new float[]{v[p],v[p+1],v[p+2]};}
        // Diagnostic bool reports whether both context extractions occurred;
        // original function returns void. Input records/context/scratch are
        // required disjoint, finite and within recovered helper domains.
        public static bool Update(RenderPacketMemory m,ShadowSelectionState state)
        {
            if(m==null||state==null||state.Tuning==null||state.Tuning.Length<10)throw new ArgumentException("Resolved shadow selection state required.");if((ulong)state.FirstContext<(ulong)state.SecondContext+0x830&&(ulong)state.SecondContext<(ulong)state.FirstContext+0x830)throw new ArgumentException("Disjoint shadow contexts required.");float[] target=new float[3];
            if(state.Mode){float[] fixedCamera=Read(m,state.FixedCamera,16);for(int j=0;j<3;++j)target[j]=Store(Wide.Add(Product(fixedCamera[j+8],2),Wide.From(fixedCamera[j+12])),(double)fixedCamera[j+8]*2+fixedCamera[j+12]);state.Height=-2;}
            else if(!ShadowPlayers.AveragePosition(m,state.Players,target))return false;
            uint lightAddress=m.Dword(checked(state.World+0x5110));if(!state.Mode){if(lightAddress==0)throw new NotSupportedException("Original normal path dereferences light before its null guard.");state.Height=F(m,checked(lightAddress+0x30));}if(lightAddress==0)return false;float[] light=Read(m,lightAddress,13),offsetTarget=(float[])target.Clone();offsetTarget[1]=Finite((float)((double)state.Height+target[1]));uint model=m.Dword(state.World+0x12c);bool special=model!=0&&(m.Word(checked(model+0x7a))&0x100)!=0&&(m.Dword(checked(m.Dword(state.World+0x128)+0x64))&0x400)==0;
            float strength;float[] direction;bool fallback=false;
            if(state.Mode){direction=Slice(light,0);strength=light[3];}
            else{direction=new float[3];int active=ShadowPlayers.AverageDirection(m,state.Players,state.DirectionSeed,direction,out strength);fallback=active==0||strength<0;if(!fallback){for(int j=0;j<3;++j)direction[j]=Finite((float)((double)direction[j]+light[j]));direction=Normalize(direction);}}
            float[] first,second;float r=state.Tuning[8];
            if(fallback){float[] p=Read(m,state.CameraInfo+0x11c,3);first=new float[]{Finite((float)((double)p[0]-1.2000000476837158)),state.Tuning[7],Finite((float)((double)p[2]-1.5))};second=(float[])first.Clone();}
            else{first=new float[3];for(int j=0;j<3;++j)first[j]=Store(Wide.Add(Wide.From(target[j]),Product(-r,direction[j])),target[j]-(double)r*direction[j]);second=new float[]{Finite((float)(target[0]+(double)r*2)),Finite((float)(target[1]+(double)r*10)),Finite((float)(target[2]+(double)r*2))};}
            if(special)strength=.5f;uint camera=state.DefaultCamera;float[] forward,cameraPosition;
            if(state.Mode){forward=Read(m,state.CameraInfo+0xd8,3);cameraPosition=Read(m,state.CameraInfo+0xe8,3);}
            else if(state.AlternateView){forward=Read(m,state.FixedCamera+0x20,3);cameraPosition=Read(m,state.FixedCamera+0x30,3);camera=state.AlternateCamera;}
            else{cameraPosition=Read(m,state.CameraInfo+0x11c,3);forward=Read(m,state.CameraInfo+0x128,3);for(int j=0;j<3;++j)forward[j]=Finite((float)((double)forward[j]-cameraPosition[j]));}
            forward=Normalize(forward);float factor=Finite((float)Math.Min(1.0,(double)forward[1]+1)),separation=Distance(cameraPosition,offsetTarget),range=special?16:light[8];if(state.Power==null)throw new ArgumentException("Explicit original power backend boundary required.");float power=Finite(state.Power(factor,state.Tuning[6]));float end=Store(Wide.Add(Wide.From(separation),Wide.Multiply(Wide.From(power),Wide.Add(Wide.From(range),Wide.From(-separation)))),separation+(double)power*((double)range-separation)),start=F(m,state.DefaultCamera+0x48);float[] cuts=state.Mode?new float[]{start,Finite((float)((double)start+state.Tuning[5])),end}:new float[]{start,end};state.Mask=state.Mode?3u:1u;
            uint context=state.FirstContext;Write(m,context+0x80c,new float[]{special?strength:light[3],light[4],light[5]});foreach(uint at in new uint[]{0x100,0x480}){Write(m,context+at,new float[]{light[7],light[6]});Write(m,context+at+0x10,new float[]{state.Tuning[1]});}Write(m,context+0x81c,new float[]{Finite((float)((double)end*state.Tuning[0])),end});Write(m,state.ScratchCuts,cuts);float[] up=Slice(state.Tuning,2);
            ShadowLight.ConfigureView(m,context,first,target,up);ShadowExtraction.Extract(m,context,camera,state.ScratchCuts,cuts.Length,state.SineTable,state.Projection,state.View);Write(m,state.SecondContext+0x80c,new float[]{strength});ShadowLight.ConfigureView(m,state.SecondContext,second,target,up);ShadowExtraction.Extract(m,state.SecondContext,camera,state.ScratchCuts,cuts.Length,state.SineTable,state.Projection,state.View);return true;
        }
    }
}
