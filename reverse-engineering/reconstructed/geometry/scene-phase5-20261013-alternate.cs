// Alternate/reflected PC camera view and normal fresh numeric composition.
using System;
using Recovered.Animation;
using Recovered.Gameplay;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class CameraAlternateView
 {
  public int ConversionMode;
  public float[] Reference;
  public uint[] TemplateWords;
 }
 public static class CameraAlternateProduction
 {
  static void Matrix(float[] values){if(values==null||values.Length!=16)throw new ArgumentException("Resolved finite matrix required.");foreach(float value in values)NativeFrustum.Finite(value);}
  static float Store(W value){float result=value.Store();NativeFrustum.Finite(result);return result;}
  static float Product(float a,float b){float result=(float)((double)a*b);NativeFrustum.Finite(result);return result;}
  static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
  static float[] Multiply(CameraPlaneServices services,float[] a,float[] b)
  {Matrix(a);Matrix(b);if(services==null||services.Multiply==null)throw new ArgumentException("Explicit D3DX matrix service required.");float[] result=services.Multiply(a,b);Matrix(result);return result;}
  // Original0x5c19d0: EAXsource,ECXdestination. Read/write each word in native
  // order, preserving shifted-overlap propagation and every raw bit pattern.
  public static void CopyRaw(uint[] source,int sourceOffset,uint[] output,int outputOffset)
  {
   if(source==null||output==null||sourceOffset<0||outputOffset<0||sourceOffset>source.Length-16||outputOffset>output.Length-16)throw new ArgumentException("Sixteen valid raw words required.");for(int i=0;i<16;++i)output[outputOffset+i]=source[sourceOffset+i];
  }
  // Actual view subchain of0x5ed540. Mode1 overwrites template word5 with-1
  // and applies that Yreflection between inverseReference andReference.
  // Other nonzero modes still compose inverseReference*Reference*inverseCamera.
  // These transposed-basis inverses are not simplified to mathematical identities.
  public static float[] View(float[] camera,CameraAlternateView frame)
  {
   if(camera==null||camera.Length!=30||frame==null)throw new ArgumentException("Resolved camera andviewmode required.");foreach(float value in camera)NativeFrustum.Finite(value);
   if(frame.ConversionMode==0){float[] normal=CameraPlaneProduction.Inverse(camera);for(int column=0;column<3;++column)for(int row=0;row<4;++row)normal[row*4+column]=Product(normal[row*4+column],camera[27+column]);return normal;}
   Matrix(frame.Reference);uint[] copied=new uint[16];CopyRaw(frame.TemplateWords,0,copied,0);copied[5]=0xbf800000u;float[] inverseCamera=new float[16],view=new float[16];ShadowCamera.RigidInverse(camera,inverseCamera);ShadowCamera.RigidInverse(frame.Reference,view);
   if(frame.ConversionMode==1){float[] reflection=new float[16];for(int i=0;i<16;++i)reflection[i]=PcObjectImage.FromBits(copied[i]);view=DynamicBounds.MultiplyAffine(view,reflection);}
   view=DynamicBounds.MultiplyAffine(view,frame.Reference);return DynamicBounds.MultiplyAffine(view,inverseCamera);
  }
  static void Derived(CameraPlaneState state,float[] camera,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(g.Sine==null||g.ScreenSize==null||g.ScreenSize.Length!=2||g.SourceSize==null||g.SourceSize.Length!=2||g.ScreenSize[0]==0||g.ScreenSize[1]==0)throw new ArgumentException("Resolved derived camera metadata required.");float half=Product(camera[16],.5f);int angle=W.Multiply(W.From(half),W.FromDouble(g.AngleScale)).TruncateInt32();float sine=g.Sine[(angle>>1)&32767],cosine=g.Sine[(unchecked(angle+16384)>>1)&32767];float tan=Store(W.Divide(W.From(sine),W.From(cosine))),width=Store(W.Divide(W.From(tan),W.From(camera[17])));
   state.Scales=new[]{width,tan,Store(W.Divide(W.Multiply(W.FromDouble(g.SourceSize[0]),W.From(width)),W.FromDouble(g.ScreenSize[0]))),Store(W.Divide(W.Multiply(W.From(tan),W.FromDouble(g.SourceSize[1])),W.FromDouble(g.ScreenSize[1])))};float ratio=Store(W.Divide(W.Divide(W.From(sine),W.From(cosine)),W.From(camera[17]))),square=Store(W.Add(W.Multiply(W.From(ratio),W.From(ratio)),W.From(1))),normal=Store(W.Divide(W.From(1),W.From(BuildEffectSound.SquareRoot(square))));state.EdgePlanes=new float[16];state.EdgePlanes[0]=Neg(normal);state.EdgePlanes[1]=normal;state.EdgePlanes[6]=cosine;state.EdgePlanes[7]=Neg(cosine);state.EdgePlanes[8]=Product(normal,ratio);state.EdgePlanes[9]=state.EdgePlanes[8];state.EdgePlanes[10]=state.EdgePlanes[11]=sine;state.Frustum=CameraPlaneProduction.OrdinaryFrustum(camera,state.View,state.Scales,g.Template,services);
  }
  // Original0x5ed540 fresh projection,clean viewport,all conversion modes.
  // Nonzero mode deliberately omits normal-view column scaling; raw camera
  // direction/position still produce ordinary clipping depth, as native does.
  public static void ApplyFresh(CameraPlaneState state,float[] input,CameraPlaneGlobals g,CameraAlternateView frame,CameraPlaneServices services)
  {
   if(frame==null)throw new ArgumentNullException("frame");if(frame.ConversionMode==0){CameraPlaneProduction.ApplyNormal(state,input,g,services);return;}
   if(state==null||input==null||input.Length!=30||g==null||services==null||services.UpdateLight==null||services.UpdateRenderCache==null)throw new ArgumentException("Resolved camera/globals/renderer services required.");state.Current=(float[])input.Clone();float[] camera=state.Current;state.View=View(camera,frame);
   if(g.Orthographic){state.Projection=new float[16];state.Projection[0]=Product(g.OrthographicScale,camera[17]);state.Projection[5]=g.OrthographicScale;state.Projection[10]=state.Projection[15]=1;}
   else{state.Projection=CameraPlaneProduction.Projection(camera,g);state.Projection[0]=Product(state.Projection[0],camera[22]);state.Projection[5]=Product(state.Projection[5],camera[23]);state.Projection[8]=(float)((double)state.Projection[8]+camera[20]);state.Projection[9]=(float)((double)state.Projection[9]+camera[21]);}
   state.Primary=CameraPlaneProduction.Symmetric(state,camera,state.View,g,services);state.PreviousCullingMode=g.CullingMode;state.Secondary=g.CullingMode==0?CameraPlaneProduction.Asymmetric(state,camera,state.View,g,services):CameraPlaneProduction.Symmetric(state,camera,state.View,g,services);state.AuxiliaryCopy=(float[])g.Auxiliary.Clone();state.Combined=Multiply(services,state.View,state.Projection);state.MappedCombined=Multiply(services,state.Combined,state.AuxiliaryCopy);state.MappedProjection=Multiply(services,state.Projection,state.AuxiliaryCopy);Derived(state,camera,g,services);state.PassWord=1;state.ResetWord=0;services.UpdateLight(state);services.UpdateRenderCache(state);
  }
 }
}
