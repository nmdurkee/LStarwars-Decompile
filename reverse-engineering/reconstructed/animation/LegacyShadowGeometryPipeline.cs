// Compose PC 5e4840 with all three recovered CPU shape writers.
using System;
namespace Recovered.Animation
{
    public static class LegacyShadowGeometryPipeline
    {
        // Resolvers bind source/native identities to immutable typed records;
        // they are resource adapters, not replacement shape computations.
        public static void Process(CharacterShadowQueueState queue,LegacyShadowConsumerState consumer,LegacyShadowGeometryState geometry,Func<uint,float[]> ellipse,Func<uint,float[]> cylinder,Func<uint,uint,LegacyShadowPolygons> polygons,uint ellipseColor)
        {
            if(queue==null||consumer==null||geometry==null)throw new ArgumentNullException();
            Action<LegacyShadowShapeCall> prior=consumer.Emit;
            consumer.Emit=delegate(LegacyShadowShapeCall call)
            {
                var matrix=new float[16];for(int i=0;i<16;++i)matrix[i]=BitConverter.ToSingle(queue.Records,checked(call.RecordIndex*104+i*4));geometry.GeneratedValue=consumer.GeneratedValue;
                switch(call.NativeEntry)
                {
                    case 0x5e2920:
                        if(cylinder==null)throw new ArgumentNullException("cylinder");LegacyCylinderShadows.Emit(geometry,cylinder(call.Resource),matrix,call.Direction);break;
                    case 0x5e3b50:
                        if(ellipse==null)throw new ArgumentNullException("ellipse");LegacyEllipseShadows.Emit(geometry,ellipse(call.Resource),matrix,call.Direction,consumer.Direction.Circle,ellipseColor);break;
                    case 0x5e4280:
                        if(polygons==null)throw new ArgumentNullException("polygons");LegacyPolygonShadows.Emit(geometry,polygons(call.First,call.Second),matrix,call.Direction);break;
                    default:throw new ArgumentException("Unknown legacy shape entry.");
                }
                consumer.GeneratedValue=geometry.GeneratedValue;
            };
            try{LegacyShadowConsumer.Process(queue,consumer);geometry.GeneratedValue=consumer.GeneratedValue;}
            finally{consumer.Emit=prior;}
        }
    }
}
