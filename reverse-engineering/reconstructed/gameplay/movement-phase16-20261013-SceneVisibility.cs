using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class SceneConditionWorld
 {
  public bool HasWorld=true;
  public CameraScene Scene;
  public readonly Dictionary<CameraSceneObject,PathSceneNormal> Normals=new Dictionary<CameraSceneObject,PathSceneNormal>();
  public readonly Dictionary<CameraSceneObject,PathSceneDisplay> Displays=new Dictionary<CameraSceneObject,PathSceneDisplay>();
 }
 public static class SceneVisibilityConditions
 {
  public static float IsVisible(SceneConditionWorld w,string name)
  {
   if(!w.HasWorld)throw new InvalidOperationException("Native global world dereference faults before lookup guards.");
   var r=new CameraSceneReference();CameraSceneLookup.Find(w.Scene,r,name);var raw=new PathAliasReference(r.Scene==null?0u:1u,r.Static==null?0u:1u,r.Dynamic==null?0u:1u);if(!PathReferenceAliases.Valid(raw))return 0;
   var projected=new PathSceneReference{ScenePresent=r.Scene!=null};
   if(r.Static!=null){PathSceneNormal normal;if(!w.Normals.TryGetValue(r.Static,out normal)||normal==null)throw new InvalidOperationException("Native static model flags dereference requires valid backing.");projected.Normal=normal;}
   else{PathSceneDisplay display;if(!w.Displays.TryGetValue(r.Dynamic,out display)||display==null)throw new InvalidOperationException("Native dynamic record requires valid backing.");projected.Display=display;}
   return PathSceneBindings.Visible(projected)?1:0;
  }
 }
}
