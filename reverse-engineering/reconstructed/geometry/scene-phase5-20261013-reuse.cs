// Nonzero projection-reuse branch of original PC camera producer.
using System;
using Recovered.Animation;
using Recovered.Gameplay;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public static class CameraProjectionReuse
 {
  static void Matrix(float[] values){if(values==null||values.Length!=16)throw new ArgumentException("Resolved finite cached matrix required.");foreach(float value in values)NativeFrustum.Finite(value);}
  static float Store(W value){float result=value.Store();NativeFrustum.Finite(result);return result;}
  static float Product(float a,float b){float value=(float)((double)a*b);NativeFrustum.Finite(value);return value;}
  static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
  static float[] Multiply(CameraPlaneServices services,float[] a,float[] b)
  {Matrix(a);Matrix(b);if(services==null||services.Multiply==null)throw new ArgumentException("Explicit matrix service required.");float[] result=services.Multiply(a,b);Matrix(result);return result;}
  // Original0x5ed300 nonzero param4. The native camera pointer is ignored,
  // including null/poison pointer probes; no camera argument is required here.
  public static float[] CachedSymmetric(CameraPlaneState state,float[] view,CameraPlaneServices services)
  {if(state==null)throw new ArgumentNullException("state");return Multiply(services,view,state.SymmetricCache);}
  // Original0x5ed420 nonzero param4, with same ignored camera-pointer contract.
  public static float[] CachedAsymmetric(CameraPlaneState state,float[] view,CameraPlaneServices services)
  {if(state==null)throw new ArgumentNullException("state");return Multiply(services,view,state.AsymmetricCache);}
  static void Derived(CameraPlaneState state,float[] camera,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(g.Sine==null||g.ScreenSize==null||g.ScreenSize.Length!=2||g.SourceSize==null||g.SourceSize.Length!=2||g.ScreenSize[0]==0||g.ScreenSize[1]==0)throw new ArgumentException("Resolved derived camera metadata required.");float half=Product(camera[16],.5f);int angle=W.Multiply(W.From(half),W.FromDouble(g.AngleScale)).TruncateInt32();float sine=g.Sine[(angle>>1)&32767],cosine=g.Sine[(unchecked(angle+16384)>>1)&32767];float tan=Store(W.Divide(W.From(sine),W.From(cosine))),width=Store(W.Divide(W.From(tan),W.From(camera[17])));
   state.Scales=new[]{width,tan,Store(W.Divide(W.Multiply(W.FromDouble(g.SourceSize[0]),W.From(width)),W.FromDouble(g.ScreenSize[0]))),Store(W.Divide(W.Multiply(W.From(tan),W.FromDouble(g.SourceSize[1])),W.FromDouble(g.ScreenSize[1])))};float ratio=Store(W.Divide(W.Divide(W.From(sine),W.From(cosine)),W.From(camera[17]))),square=Store(W.Add(W.Multiply(W.From(ratio),W.From(ratio)),W.From(1))),normal=Store(W.Divide(W.From(1),W.From(BuildEffectSound.SquareRoot(square))));state.EdgePlanes=new float[16];state.EdgePlanes[0]=Neg(normal);state.EdgePlanes[1]=normal;state.EdgePlanes[6]=cosine;state.EdgePlanes[7]=Neg(cosine);state.EdgePlanes[8]=Product(normal,ratio);state.EdgePlanes[9]=state.EdgePlanes[8];state.EdgePlanes[10]=state.EdgePlanes[11]=sine;state.Frustum=CameraPlaneProduction.OrdinaryFrustum(camera,state.View,state.Scales,g.Template,services);
  }
  // Original0x5ed540 with any nonzero param2, normal view973944=0.
  // It skips the viewport reset and projection block before testing culling
  // mode change. That later reset rebuilds second clip output and derived
  // scales/frustum, but cannot retroactively regenerate the old projection.
  public static void ApplyCached(CameraPlaneState state,float[] input,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(state==null||input==null||input.Length!=30||g==null||services==null||services.UpdateLight==null||services.UpdateRenderCache==null)throw new ArgumentException("Resolved finite camera/cache/renderer services required.");foreach(float value in input)NativeFrustum.Finite(value);Matrix(g.Auxiliary);state.Current=(float[])input.Clone();float[] camera=state.Current;state.View=CameraPlaneProduction.Inverse(camera);for(int column=0;column<3;++column)for(int row=0;row<4;++row)state.View[row*4+column]=Product(state.View[row*4+column],camera[27+column]);state.Primary=CachedSymmetric(state,state.View,services);bool changed=g.CullingMode!=state.PreviousCullingMode;if(changed)state.PreviousCullingMode=g.CullingMode;
   if(g.CullingMode==0)state.Secondary=changed?CameraPlaneProduction.Asymmetric(state,camera,state.View,g,services):CachedAsymmetric(state,state.View,services);else state.Secondary=changed?CameraPlaneProduction.Symmetric(state,camera,state.View,g,services):CachedSymmetric(state,state.View,services);state.AuxiliaryCopy=(float[])g.Auxiliary.Clone();state.Combined=Multiply(services,state.View,state.Projection);state.MappedCombined=Multiply(services,state.Combined,state.AuxiliaryCopy);state.MappedProjection=Multiply(services,state.Projection,state.AuxiliaryCopy);if(changed)Derived(state,camera,g,services);state.PassWord=1;state.ResetWord=0;services.UpdateLight(state);services.UpdateRenderCache(state);
  }
 }
}
