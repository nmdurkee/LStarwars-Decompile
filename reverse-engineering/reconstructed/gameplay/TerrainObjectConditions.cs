using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class SceneObjectIndexBinding {public object StaticInstance;public int DynamicIndex=-1;}
 public sealed class TerrainObjectRecord {public bool HasTransform;public short SceneIndex;public float Height;}
 public sealed class TerrainObjectWorld
 {
  public bool TerrainPresent=true;
  public CameraScene Scene;
  public int StaticInstanceCount,TerrainCount;
  public readonly List<object> StaticInstances=new List<object>();
  public readonly List<TerrainObjectRecord> Terrain=new List<TerrainObjectRecord>();
  public readonly Dictionary<CameraSceneObject,SceneObjectIndexBinding> Bindings=new Dictionary<CameraSceneObject,SceneObjectIndexBinding>();
  public ActorStatusWorld Actors;
  public readonly Dictionary<ActorStateRecord,short> GroundObjects=new Dictionary<ActorStateRecord,short>();
 }
 public static class TerrainObjectConditions
 {
  //0x5cffb0: static instance identity scan, or direct dynamic+0xc0 index.
  public static int SceneIndex(TerrainObjectWorld world,CameraSceneReference reference)
  {
   SceneObjectIndexBinding binding;
   if(reference.Static==null){if(reference.Dynamic==null)return -1;if(!world.Bindings.TryGetValue(reference.Dynamic,out binding))throw new ArgumentException("Missing dynamic scene-index binding.");return binding.DynamicIndex;}
   if(reference.Scene==null)throw new ArgumentException("Native static reference requires its scene.");
   if(!world.Bindings.TryGetValue(reference.Static,out binding))throw new ArgumentException("Missing static instance identity.");
   for(int i=0;i<world.StaticInstanceCount;i++)if(Object.ReferenceEquals(world.StaticInstances[i],binding.StaticInstance))return i;
   return -1;
  }
  //0x67c760: first nonnull-transform terrain record with signed-short scene id.
  public static int FindTerrainObject(TerrainObjectWorld world,int sceneIndex)
  {
   if(sceneIndex==-1)return -1;
   if(!world.TerrainPresent)throw new ArgumentException("Native terrain registry must be attached.");
   for(int i=0;i<world.TerrainCount;i++){TerrainObjectRecord item=world.Terrain[i];if(item.HasTransform&&item.SceneIndex==sceneIndex)return i;}
   return -1;
  }
  //0x4418c0, ordinary static/dynamic lookup; diagnostic fallback remains external.
  public static int Bind(TerrainObjectWorld world,string name)
  {
   if(!world.TerrainPresent)return -1;CameraSceneReference reference=new CameraSceneReference();
   if(!CameraSceneLookup.Find(world.Scene,reference,SceneryText.C(name)))return -1;
   return FindTerrainObject(world,SceneIndex(world,reference));
  }
  //0x441910: actor signed-short object id, grounded bytes, and inclusive height.
  public static float PlayerOnObject(TerrainObjectWorld world,int bound)
  {
   ActorStateRecord player=world.Actors.Tags.Actors.PrimaryPlayer;if(player==null||bound==-1)return 0;
   ActorStatusState state=world.Actors.Get(player);if(state.Ground281==0&&state.Ground282==0)return 0;
   short index;if(!world.GroundObjects.TryGetValue(player,out index))throw new ArgumentException("Missing player ground-object field.");
   if(index!=bound)return 0;
   if(!world.TerrainPresent||index<0||index>=world.Terrain.Count||!world.Terrain[index].HasTransform)throw new ArgumentException("Native terrain transform dereference requires readable backing.");
   return world.Terrain[index].Height<=player.Y?1f:0f;
  }
 }
}
