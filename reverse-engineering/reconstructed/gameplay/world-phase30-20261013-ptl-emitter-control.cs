using System;
namespace Recovered.Gameplay {
 public static class PtlEmitterControl {
  static void Emitter(SoundSetupImage m,uint reference,byte state){unchecked{uint id=m.Word(reference);if(id==0xffffffff)return;m.Byte(m.Word(0x29620a4)+id*0x330+0x2f4,state);}}
  static void Physical(SoundSetupImage m,uint id,byte state){unchecked{if(id==0xffffffff)return;uint record=m.Word(m.Word(0x296209c)+id*4);m.Byte(record+0x2f,state);}}
  // Original6552c0/6552e0/655300 reference-based emitter byte setters.
  public static void EmitterState0(SoundSetupImage m,uint reference){Emitter(m,reference,0);}
  public static void EmitterState2(SoundSetupImage m,uint reference){Emitter(m,reference,2);}
  public static void EmitterState1(SoundSetupImage m,uint reference){Emitter(m,reference,1);}
  //655360 new physical state1 body;655320/655340 raw-pointer refinements of existing EffectActivation mappings, no additional entry credit.
  public static void PhysicalState1(SoundSetupImage m,uint id){Physical(m,id,1);}
  public static void PhysicalState0(SoundSetupImage m,uint id){Physical(m,id,0);}
  public static void PhysicalState2(SoundSetupImage m,uint id){Physical(m,id,2);}
  //6558f0 uses a private stack ID cell in native code. Portable callers supply disjoint temporary backing outside the retained memory projection.
  public static void CleanupAll(SoundSetupImage m,uint temporaryId){unchecked{int i=0;uint offset=0;while(i<(int)m.Word(0x2962094)){uint emitter=m.Word(0x29620a4)+offset;if(m.Half(emitter+0x182)!=0){m.Word(temporaryId,(uint)i);PtlEmitterChunkCleanup.Cleanup(m,temporaryId);}i++;offset+=0x330;}}}
 }
}
