// Compose the legacy queue consumer with its recovered polygon writer.
using System;
namespace Recovered.Animation
{
    public static class LegacyPolygonPipeline
    {
        // Refines5e4840. The resolver binds the two exact native pair values;
        // ellipse/cylinder handlers remain the caller's explicit services.
        // OtherShape may update consumer.GeneratedValue but not queue/geometry.
        public static void Process(CharacterShadowQueueState queue,LegacyShadowConsumerState consumer,LegacyShadowGeometryState geometry,Func<uint,uint,LegacyShadowPolygons> resolve,Action<LegacyShadowShapeCall> otherShape)
        {
            if(queue==null||consumer==null||geometry==null)throw new ArgumentNullException();
            Action<LegacyShadowShapeCall> prior=consumer.Emit;
            consumer.Emit=delegate(LegacyShadowShapeCall call)
            {
                if(call.NativeEntry!=0x5e4280){if(otherShape==null)throw new ArgumentNullException("otherShape");otherShape(call);return;}
                if(resolve==null)throw new ArgumentNullException("resolve");LegacyShadowPolygons shape=resolve(call.First,call.Second);if(shape==null)throw new ArgumentException("Resolved polygon pair required.");
                var matrix=new float[16];for(int i=0;i<16;++i)matrix[i]=BitConverter.ToSingle(queue.Records,checked(call.RecordIndex*104+i*4));
                geometry.GeneratedValue=consumer.GeneratedValue;LegacyPolygonShadows.Emit(geometry,shape,matrix,call.Direction);consumer.GeneratedValue=geometry.GeneratedValue;
            };
            try{LegacyShadowConsumer.Process(queue,consumer);geometry.GeneratedValue=consumer.GeneratedValue;}
            finally{consumer.Emit=prior;}
        }
    }
}
