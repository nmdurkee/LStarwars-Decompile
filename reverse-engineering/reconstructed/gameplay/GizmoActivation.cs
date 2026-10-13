using System;
namespace Recovered.Gameplay
{
 public sealed class GizmoActivationWorld
 {
  public SceneryWorld Scenery;
  public SceneryNameBindings Types;
  public string[] TypeNames;
  public Action<SceneryGizmo,int>[] Activate,Visibility;
 }
 public static class GizmoActivation
 {
  //0x559e20: signed count, exact case-sensitive first type-name match.
  public static int FindType(GizmoActivationWorld world,string name)
  {
   if(world.Types==null||world.Types.NameAccessors==null||world.Scenery.Registry==null||name==null)return -1;
   name=SceneryText.C(name);for(int i=0;i<world.Types.TypeCount;i++)
   {
    if(world.TypeNames==null||i>=world.TypeNames.Length)throw new ArgumentException("Missing type-name table backing.");
    if(String.Equals(SceneryText.C(world.TypeNames[i]),name,StringComparison.Ordinal))return i;
   }
   return -1;
  }
  //0x55a250: enable makes visible first, then rereads activation slot.
  public static void SetActive(GizmoActivationWorld world,SceneryGizmo record,int active)
  {
   if(world.Types==null||world.Types.NameAccessors==null||world.Scenery.Registry==null||record==null||record.Type>=world.Types.TypeCount)return;
   int type=record.Type;if(world.Activate==null||type>=world.Activate.Length||world.Visibility==null||type>=world.Visibility.Length)throw new ArgumentException("Missing physical callback table backing.");
   if(world.Activate[type]==null)return;
   if(active!=0&&world.Visibility[type]!=null)world.Visibility[type](record,1);
   Action<SceneryGizmo,int> callback=world.Activate[type];if(callback==null)throw new ArgumentException("Native activation callback was cleared before its unguarded reread.");callback(record,active);
  }
  //0x464820: parse all tokens before one name lookup and activation.
  public static void Execute(GizmoActivationWorld world,string[] tokens)
  {
   string name=null;int type=-1,active=1;
   foreach(string raw in tokens)
   {
    string token=SceneryText.C(raw);int at=SceneryText.Index(token,"name=");
    if(at>=0)name=token.Substring(at+5);
    else if((at=SceneryText.Index(token,"type="))>=0)type=FindType(world,token.Substring(at+5));
    else if(SceneryText.Index(token,"FALSE")>=0)active=0;
   }
   if(name==null)return;SceneryGizmo selected=world.Scenery.Bindings.Find(world.Scenery.Registry,type,name);if(selected!=null)SetActive(world,selected,active);
  }
 }
}
