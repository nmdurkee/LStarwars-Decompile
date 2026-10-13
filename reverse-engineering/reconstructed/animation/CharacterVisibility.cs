// OriginalPC5da980 hierarchy bounds preprocessing and scalar camera classifier.
using System;
using Recovered.Geometry;
namespace Recovered.Animation
{
    public static class CharacterVisibility
    {
        static void Require(float[] v,int size){if(v==null||v.Length!=size)throw new ArgumentException("Resolved finite visibility inputs required");foreach(float x in v)if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite visibility input required");}
        static float Store(PlaybackWide value,double approximate)
        {
            float result=value.Store();
            // Restore exact-negative-zero input arithmetic without replacing a
            // signed underflow already retained by the wide representation.
            if(PcObjectImage.ToBits(result)==0&&approximate==0&&BitConverter.DoubleToInt64Bits(approximate)<0)result=PcObjectImage.FromBits(0x80000000);
            if(Single.IsNaN(result)||Single.IsInfinity(result))throw new ArgumentException("Finite stored visibility intermediates required");return result;
        }
        // This helper is the original5da980 composition, not a new mapping for
        // its shared math callees. Flag9739a8 controls the alternate root path.
        public static int Classify(DynamicBoxState camera,float[] minimum,float[] maximum,float[] objectWorld,float[] rootJointMatrix,bool centerOnRoot)
        {
            Require(minimum,3);Require(maximum,3);
            if(!centerOnRoot)return DynamicBounds.Classify(camera,minimum,maximum,objectWorld,0);
            Require(objectWorld,16);Require(rootJointMatrix,16);float[] low=new float[3],high=new float[3],matrix=(float[])objectWorld.Clone();
            for(int i=0;i<3;++i)
            {
                float difference=Store(PlaybackWide.Add(PlaybackWide.From(maximum[i]),PlaybackWide.From(-minimum[i])),(double)maximum[i]-minimum[i]);
                high[i]=Store(PlaybackWide.Multiply(PlaybackWide.From(difference),PlaybackWide.From(.5f)),(double)difference*.5);low[i]=-high[i];
            }
            // Original5b4960 adds root translation through the object's basis.
            // X adds Z+X+Y; Y/Z add Z+Y+X. Keep that distinct x87 operation order.
            float x=rootJointMatrix[12],y=rootJointMatrix[13],z=rootJointMatrix[14];
            for(int i=0;i<3;++i)
            {
                var px=PlaybackWide.Multiply(PlaybackWide.From(objectWorld[i]),PlaybackWide.From(x));var py=PlaybackWide.Multiply(PlaybackWide.From(objectWorld[4+i]),PlaybackWide.From(y));var pz=PlaybackWide.Multiply(PlaybackWide.From(objectWorld[8+i]),PlaybackWide.From(z));
                var sum=i==0?PlaybackWide.Add(PlaybackWide.Add(pz,px),py):PlaybackWide.Add(PlaybackWide.Add(pz,py),px);
                double approximate=i==0?((double)objectWorld[8+i]*z+(double)objectWorld[i]*x)+(double)objectWorld[4+i]*y:((double)objectWorld[8+i]*z+(double)objectWorld[4+i]*y)+(double)objectWorld[i]*x;
                matrix[12+i]=Store(PlaybackWide.Add(sum,PlaybackWide.From(objectWorld[12+i])),approximate+objectWorld[12+i]);
            }
            return DynamicBounds.Classify(camera,low,high,matrix,0);
        }
    }
}
