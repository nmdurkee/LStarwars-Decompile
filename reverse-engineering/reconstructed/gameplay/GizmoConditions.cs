namespace Recovered.Gameplay
{
 public static class GizmoConditions
 {
  //0x443a00: null operand returns before loading current-world registry.
  public static SceneryGizmo BindAny(SceneryWorld world,string name){return name==null?null:world.Bindings.Find(world.Registry,-1,SceneryText.C(name));}
  //0x441630: type comes from native global802f54; return the record itself.
  public static SceneryGizmo BindBlowup(SceneryWorld world,int blowupType,string name){return world.Bindings.Find(world.Registry,blowupType,SceneryText.C(name));}
  //0x443a30/443a70/443ab0: unsigned callback value at SCP float32 storage.
  public static float Output0(SceneryRegistry registry,SceneryGizmo bound){return bound==null?0f:(float)SceneryRegistry.Output(registry,bound,0,1);}
  public static float Output1(SceneryRegistry registry,SceneryGizmo bound){return bound==null?0f:(float)SceneryRegistry.Output(registry,bound,1,1);}
  public static float Output2(SceneryRegistry registry,SceneryGizmo bound){return bound==null?0f:(float)SceneryRegistry.Output(registry,bound,2,1);}
  //0x441660: any nonzero output0 becomes boolean1, including high-bit values.
  public static float BlowupBlownup(SceneryRegistry registry,SceneryGizmo bound){return bound!=null&&SceneryRegistry.Output(registry,bound,0,1)!=0?1f:0f;}
 }
}
