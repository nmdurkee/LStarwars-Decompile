// Composed numeric paths from original PC camera and populated visibility dispatcher.
using System;
using Recovered.Animation;
using Recovered.Gameplay;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public static class CameraNumericPipeline
 {
  static float Store(W value){float result=value.Store();NativeFrustum.Finite(result);return result;}
  static float Product(float a,float b){float result=(float)((double)a*b);NativeFrustum.Finite(result);return result;}
  static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
  static float[] Multiply(CameraPlaneServices services,float[] a,float[] b){if(services==null||services.Multiply==null)throw new ArgumentException("Explicit matrix service required.");return services.Multiply(a,b);}
  static void Derived(CameraPlaneState state,float[] camera,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(g.Sine==null||g.ScreenSize==null||g.ScreenSize.Length!=2||g.SourceSize==null||g.SourceSize.Length!=2||g.ScreenSize[0]==0||g.ScreenSize[1]==0)throw new ArgumentException("Resolved derived camera metadata required.");float half=Product(camera[16],.5f);int angle=W.Multiply(W.From(half),W.FromDouble(g.AngleScale)).TruncateInt32();float sine=g.Sine[(angle>>1)&32767],cosine=g.Sine[(unchecked(angle+16384)>>1)&32767];float tan=Store(W.Divide(W.From(sine),W.From(cosine))),width=Store(W.Divide(W.From(tan),W.From(camera[17])));
   state.Scales=new[]{width,tan,Store(W.Divide(W.Multiply(W.FromDouble(g.SourceSize[0]),W.From(width)),W.FromDouble(g.ScreenSize[0]))),Store(W.Divide(W.Multiply(W.From(tan),W.FromDouble(g.SourceSize[1])),W.FromDouble(g.ScreenSize[1])))};float ratio=Store(W.Divide(W.Divide(W.From(sine),W.From(cosine)),W.From(camera[17]))),square=Store(W.Add(W.Multiply(W.From(ratio),W.From(ratio)),W.From(1))),normal=Store(W.Divide(W.From(1),W.From(BuildEffectSound.SquareRoot(square))));state.EdgePlanes=new float[16];state.EdgePlanes[0]=Neg(normal);state.EdgePlanes[1]=normal;state.EdgePlanes[6]=cosine;state.EdgePlanes[7]=Neg(cosine);state.EdgePlanes[8]=Product(normal,ratio);state.EdgePlanes[9]=state.EdgePlanes[8];state.EdgePlanes[10]=state.EdgePlanes[11]=sine;state.Frustum=CameraPlaneProduction.OrdinaryFrustum(camera,state.View,state.Scales,g.Template,services);
  }

  // Original 0x5ed540: viewport reset is before view/projection only for
  // zero reuse. Later culling-mode change never regenerates old projection.
  public static void Apply(CameraPlaneState state,float[] input,CameraViewportState viewport,CameraViewportInputs inputs,CameraAlternateView frame,int reuse,Action<uint[]> emitViewport,CameraPlaneServices services)
  {
   if(state==null||input==null||input.Length!=30||viewport==null||viewport.Globals==null||frame==null||services==null)throw new ArgumentException("Resolved camera, viewport, conversion mode and services required.");CameraPlaneGlobals g=viewport.Globals;
   if(reuse==0){state.Current=(float[])input.Clone();CameraViewport.Reset(viewport,inputs,emitViewport);CameraAlternateProduction.ApplyFresh(state,input,g,frame,services);return;}
   if(frame.ConversionMode==0){CameraProjectionReuse.ApplyCached(state,input,g,services);return;}
   if(services.UpdateLight==null||services.UpdateRenderCache==null)throw new ArgumentException("Renderer services required.");state.Current=(float[])input.Clone();float[] camera=state.Current;state.View=CameraAlternateProduction.View(camera,frame);state.Primary=CameraProjectionReuse.CachedSymmetric(state,state.View,services);bool changed=g.CullingMode!=state.PreviousCullingMode;if(changed)state.PreviousCullingMode=g.CullingMode;
   if(g.CullingMode==0)state.Secondary=changed?CameraPlaneProduction.Asymmetric(state,camera,state.View,g,services):CameraProjectionReuse.CachedAsymmetric(state,state.View,services);else state.Secondary=changed?CameraPlaneProduction.Symmetric(state,camera,state.View,g,services):CameraProjectionReuse.CachedSymmetric(state,state.View,services);state.AuxiliaryCopy=(float[])g.Auxiliary.Clone();state.Combined=Multiply(services,state.View,state.Projection);state.MappedCombined=Multiply(services,state.Combined,state.AuxiliaryCopy);state.MappedProjection=Multiply(services,state.Projection,state.AuxiliaryCopy);if(changed)Derived(state,camera,g,services);state.PassWord=1;state.ResetWord=0;services.UpdateLight(state);services.UpdateRenderCache(state);
  }
  public static void Restore(CameraPlaneState state,float[] camera,CameraViewportState viewport,CameraViewportInputs inputs,CameraAlternateView frame,Action<uint[]> emitViewport,CameraPlaneServices services)
  {if(services==null||services.DeviceTransform==null)throw new ArgumentException("Device transform service required.");Apply(state,camera,viewport,inputs,frame,0,emitViewport,services);state.ClipTransform=(float[])viewport.Globals.ClipTransform.Clone();state.Primary=Multiply(services,state.Combined,state.ClipTransform);state.Secondary=(float[])state.Primary.Clone();services.DeviceTransform(2,state.View);services.DeviceTransform(3,state.Projection);}
  public static void Switch(CameraPlaneState state,int requested,CameraViewportState viewport,CameraViewportInputs inputs,CameraAlternateView frame,Action<uint[]> emitViewport,CameraPlaneServices services)
  {if(state==null||state.Current==null||state.Current.Length!=30)throw new ArgumentException("Resolved current camera required.");if(requested!=state.Mode&&state.Mode==0)state.Base=(float[])state.Current.Clone();if(requested!=0){state.Saved=(float[])state.Current.Clone();Restore(state,state.Base,viewport,inputs,frame,emitViewport,services);}state.Mode=requested;}
  static PortalEntryCamera PortalCamera(CameraPlaneState state)
  {float[] world=new float[16];Array.Copy(state.Current,world,16);return new PortalEntryCamera{World=world,Projection=state.Projection,FieldOfView=state.Current[16],Aspect=state.Current[17],Near=state.Current[18]};}
  // Original 0x5f3c80 composition. Grid/portal services and renderer bytes
  // remain external; every tree fourth word is provided from caller evidence.
  public static SceneVisibilityPreparationServices PreparationServices(CameraPlaneState camera,CameraViewportState viewport,CameraViewportInputs inputs,CameraAlternateView frame,Action<uint[]> emitViewport,CameraPlaneServices services,TreePlaneRuntime planeRuntime,TreeVisibilityData tree,byte[] bits,Func<TreeVisibilityVisit,uint> residue)
  {
   return new SceneVisibilityPreparationServices{
    SwitchCamera=delegate(SceneVisibilityPreparationCall call,int requested){Switch(camera,requested,viewport,inputs,frame,emitViewport,services);call.Options.CurrentCameraMode=camera.Mode;call.Camera=PortalCamera(camera);},
    TraverseTree=delegate(SceneVisibilityPreparationCall call){TreePlaneProduction.Produce(call.State,call.Options.TreeEnabled,tree,CameraPlaneProduction.TreeInputs(camera,viewport.Globals),planeRuntime,bits,services.Multiply,residue);},
    RestoreCamera=delegate(SceneVisibilityPreparationCall call){Restore(camera,camera.Saved,viewport,inputs,frame,emitViewport,services);call.Camera=PortalCamera(camera);}
   };
  }
 }
}
