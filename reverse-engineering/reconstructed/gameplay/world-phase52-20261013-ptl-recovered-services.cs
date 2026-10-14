using System;
namespace Recovered.Gameplay {
 // Dispatch composition only. Address credit belongs to the sealed original-body modules.
 public static class PtlRecoveredServices {
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> external){Func<SoundSetupImage,uint,uint[],uint> child=delegate(SoundSetupImage image,uint target,uint[] values){return Invoke(image,target,values,external);};switch(address){
   case 0x653970:return PtlParticleInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x654930:return PtlParticleInitializer.Forward(m,args[0],args[1],args[2],child);
   case 0x653c50:return PtlSphericalInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x653f40:return PtlPolarInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x681f70:return PtlEllipsoidInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x682290:return PtlQuadraticInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x6826a0:return PtlPlaneInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x654270:return PtlConeInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x6545d0:return PtlLobedInitializer.Initialize(m,args[0],args[1],args[2],child);
   case 0x600260:PtlParticleDescriptor.Produce(m,args[0],child);return 0;
   case 0x654950:case 0x654970:case 0x6549a0:case 0x6549c0:case 0x6549e0:case 0x654a00:case 0x6e8e1e:return PtlParticleAttributes.Invoke(m,address,args,child);
   default:return external(m,address,args);
  }}
  public static void Emit(SoundSetupImage m,uint physical,uint position,uint velocity,uint delta,int count,uint duration,uint secondary,uint primary,uint priority,uint flags,Func<SoundSetupImage,uint,uint[],uint> external){PtlEmitterBurst.Emit(m,physical,position,velocity,delta,count,duration,secondary,primary,priority,flags,delegate(SoundSetupImage image,uint address,uint[] args){return Invoke(image,address,args,external);});}
 }
}
