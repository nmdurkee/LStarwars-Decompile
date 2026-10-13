// Normal PC camera numeric production and real visibility-preparation composition.
// Imported D3DX, device transforms, light/cache outputs and tree stack residue
// remain explicit host boundaries. This is reconstructed code, not original source.
using System;
using Recovered.Animation;
using Recovered.Gameplay;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class CameraPlaneGlobals
 {
  public NativeSineTable Sine;
  public double AngleScale=10430.3779296875;
  public float[] Correction,ClipScales,Auxiliary,ClipTransform;
  // PE virtual data tail initializes this runtime template to zero. A host may
  // supply its later runtime value; indirect writes have not been ruled out.
  public float[] Template=new float[16];
  public float FarBias,OrthographicScale;
  public bool Orthographic;
  public int CullingMode;
  public int[] ScreenSize,SourceSize;
 }
 public sealed class CameraPlaneState
 {
  public float[] Current,Base,Saved;
  public int Mode,PreviousCullingMode;
  public float[] View,Projection,ClipTransform,AuxiliaryCopy,Combined,Secondary,Primary,SymmetricCache,MappedCombined,MappedProjection,EdgePlanes,AsymmetricCache,Scales;
  public byte[] Frustum;
  public uint PassWord,ResetWord;
 }
 public sealed class CameraPlaneServices
 {
  public Func<float[],float[],float[]> Multiply;
  // Original helpers execute in native evidence. Their renderer-global output
  // images are outside this numeric camera projection and belong to the host.
  public Action<CameraPlaneState> UpdateLight,UpdateRenderCache;
  public Action<int,float[]> DeviceTransform;
 }
 public static class CameraPlaneProduction
 {
  static W F(float v){return W.From(v);}
  static W I(int v){return W.FromDouble(v);}
  static W Add(W a,W b){return W.Add(a,b);}
  static W Mul(W a,W b){return W.Multiply(a,b);}
  static W Div(W a,W b){return W.Divide(a,b);}
  static W Sub(W a,W b){return Add(a,Mul(F(-1),b));}
  static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
  static float Store(W w){float v=w.Store();NativeFrustum.Finite(v);return v;}
  static float Product(float a,float b){float v=(float)((double)a*b);NativeFrustum.Finite(v);return v;}
  static float Sum(float a,float b){float v=(float)((double)a+b);NativeFrustum.Finite(v);return v;}
  static void Array(float[] values,int count){if(values==null||values.Length!=count)throw new ArgumentException("Invalid finite camera array.");foreach(float v in values)NativeFrustum.Finite(v);}
  static float Dot(float[] a,float[] b,bool yFirst)
  {
   W x=Mul(F(a[0]),F(b[0])),y=Mul(F(a[1]),F(b[1])),z=Mul(F(a[2]),F(b[2]));float result=Store(Add(yFirst?Add(y,x):Add(x,y),z));
   if((a[0]==0||b[0]==0)&&(a[1]==0||b[1]==0)&&(a[2]==0||b[2]==0))
   {bool nx=((PcObjectImage.ToBits(a[0])^PcObjectImage.ToBits(b[0]))&0x80000000u)!=0,ny=((PcObjectImage.ToBits(a[1])^PcObjectImage.ToBits(b[1]))&0x80000000u)!=0,nz=((PcObjectImage.ToBits(a[2])^PcObjectImage.ToBits(b[2]))&0x80000000u)!=0;result=PcObjectImage.FromBits(nx&&ny&&nz?0x80000000u:0u);}
   return result;
  }
  static void Camera(float[] camera){Array(camera,30);}
  static void Globals(CameraPlaneGlobals g)
  {
   if(g==null||g.Sine==null||Double.IsNaN(g.AngleScale)||Double.IsInfinity(g.AngleScale))throw new ArgumentException("Resolved camera globals required.");Array(g.Correction,4);Array(g.ClipScales,4);Array(g.Template,16);Array(g.Auxiliary,16);Array(g.ClipTransform,16);NativeFrustum.Finite(g.FarBias);NativeFrustum.Finite(g.OrthographicScale);
   if(g.ScreenSize==null||g.ScreenSize.Length!=2||g.SourceSize==null||g.SourceSize.Length!=2||g.ScreenSize[0]==0||g.ScreenSize[1]==0)throw new ArgumentException("Nonzero signed screen dimensions required.");
  }
  static float[] Multiply(CameraPlaneServices services,float[] a,float[] b)
  {if(services==null||services.Multiply==null)throw new ArgumentException("Explicit D3DX matrix service required.");float[] result=services.Multiply(a,b);Array(result,16);return result;}
  static void Trig(float fieldOfView,CameraPlaneGlobals g,out float sine,out float cosine)
  {
   float half=Product(fieldOfView,.5f);int angle=Mul(F(half),W.FromDouble(g.AngleScale)).TruncateInt32();sine=g.Sine[(angle>>1)&32767];cosine=g.Sine[(unchecked(angle+16384)>>1)&32767];if(sine==0||cosine==0)throw new ArgumentException("Zero camera sine/cosine outside validated projection domain.");
  }
  // Original0x5c0940 transpose/translation routine, including in-place numeric
  // output. It does not claim an inverse for arbitrary non-orthogonal matrices.
  public static float[] Inverse(float[] camera)
  {
   if(camera==null||camera.Length<16)throw new ArgumentException("Missing camera transform.");for(int i=0;i<16;++i)NativeFrustum.Finite(camera[i]);float[] result=new float[16];for(int i=0;i<3;++i)for(int j=0;j<3;++j)result[i*4+j]=camera[j*4+i];float[] translation={Neg(camera[12]),Neg(camera[13]),Neg(camera[14])};
   result[12]=Dot(translation,new[]{result[0],result[4],result[8]},false);result[13]=Dot(translation,new[]{result[1],result[5],result[9]},true);result[14]=Dot(translation,new[]{result[2],result[6],result[10]},false);result[15]=1;return result;
  }
  // Original0x604a80 with output bound to its global0x80b748 projection.
  // Other output aliases and native's separate global side effects are excluded.
  public static float[] Projection(float[] camera,CameraPlaneGlobals g)
  {
   Camera(camera);Globals(g);float sine,cosine;Trig(camera[16],g,out sine,out cosine);float cot=Store(Div(F(cosine),F(sine))),ratio=Store(Div(F(camera[19]),Sub(F(camera[19]),F(camera[18]))));float[] result=new float[16];result[0]=Product(cot,camera[17]);result[5]=cot;result[10]=ratio;result[11]=1;result[14]=Product(Neg(ratio),camera[18]);result[0]=Product(result[0],g.Correction[0]);result[5]=Product(result[5],g.Correction[1]);result[8]=g.Correction[2];result[9]=g.Correction[3];return result;
  }
  static float[] ClipCache(float[] camera,CameraPlaneGlobals g,bool asymmetric)
  {
   Camera(camera);Globals(g);float sine,cosine;Trig(camera[16],g,out sine,out cosine);float cot=Store(Div(F(cosine),F(sine))),near=camera[24]!=0?camera[24]:camera[18],far=Sum(camera[25]!=0?camera[25]:camera[19],Neg(g.FarBias));W denominator=Sub(F(far),F(near));int offset=asymmetric?2:0;float[] result=new float[16];
   result[0]=Store(asymmetric?Mul(Mul(F(camera[17]),F(g.ClipScales[offset])),F(cot)):Mul(Mul(F(camera[17]),F(cot)),F(g.ClipScales[offset])));result[5]=Store(Mul(F(g.ClipScales[offset+1]),F(cot)));result[10]=Store(Div(Add(F(near),F(far)),denominator));result[11]=1;result[14]=Store(Div(Mul(Mul(F(far),F(-2)),F(near)),denominator));return result;
  }
  // Original0x5ed300 fresh projection branch and original matrix wrapper.
  public static float[] Symmetric(CameraPlaneState state,float[] camera,float[] view,CameraPlaneGlobals g,CameraPlaneServices services)
  {if(state==null)throw new ArgumentNullException("state");state.SymmetricCache=ClipCache(camera,g,false);return Multiply(services,view,state.SymmetricCache);}
  // Original0x5ed420 fresh projection branch and original matrix wrapper.
  public static float[] Asymmetric(CameraPlaneState state,float[] camera,float[] view,CameraPlaneGlobals g,CameraPlaneServices services)
  {if(state==null)throw new ArgumentNullException("state");state.AsymmetricCache=ClipCache(camera,g,true);return Multiply(services,view,state.AsymmetricCache);}
  static byte[] PlaneBytes(params float[][] arrays)
  {byte[] bytes=new byte[336];int offset=0;foreach(float[] a in arrays)foreach(float value in a){byte[] b=BitConverter.GetBytes(value);if(!BitConverter.IsLittleEndian)System.Array.Reverse(b);System.Array.Copy(b,0,bytes,offset,4);offset+=4;}return bytes;}
  static float[] Absolute(float[] values){float[] result=new float[16];for(int i=0;i<12;++i)result[i]=PcObjectImage.FromBits(PcObjectImage.ToBits(values[i])&0x7fffffffu);return result;}
  // Original0x5d5500 ordinary clipping-plane block, distinct from tree planes.
  public static byte[] OrdinaryFrustum(float[] camera,float[] view,float[] scales,float[] template,CameraPlaneServices services)
  {
   Camera(camera);Array(view,16);Array(scales,4);Array(template,16);var local=new TreePlaneRuntime();TreePlaneProduction.BuildLocal(new TreePlaneInputs{Near=camera[18],Scales=scales,Template=template},local);float[][] matrices={local.LocalOuter,local.LocalInner};foreach(float[] a in matrices)foreach(int index in new[]{6,7,8,9,10,11})a[index]=Neg(a[index]);float[] outer=Multiply(services,view,matrices[0]),inner=Multiply(services,view,matrices[1]);float[] direction={camera[8],camera[9],camera[10]},position={camera[12],camera[13],camera[14]};float q=Dot(direction,position,true),near=Sum(Neg(q),Neg(camera[18])),far=Sum(camera[19],q);float[] nf=new float[16];for(int i=0;i<3;++i){int at=i*4;nf[at]=Neg(direction[i]);nf[at+1]=direction[i];nf[at+2]=nf[at+3]=Math.Abs(direction[i]);}nf[12]=far;nf[13]=near;nf[14]=Math.Abs(far);nf[15]=Math.Abs(near);return PlaneBytes(outer,inner,nf,new[]{direction[0],direction[1],direction[2],near},Absolute(outer),Absolute(inner));
  }
  // Original0x5ed540 normal conversion, param2=0 and clean viewport domain.
  // Calls the numeric camera/clip/frustum producers, preserving raw current
  // camera direction and position. Renderer light/cache outputs are services.
  public static void ApplyNormal(CameraPlaneState state,float[] input,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(state==null||services==null||services.UpdateLight==null||services.UpdateRenderCache==null)throw new ArgumentException("Resolved camera state and renderer services required.");Camera(input);Globals(g);state.Current=(float[])input.Clone();float[] camera=state.Current;state.View=Inverse(camera);for(int column=0;column<3;++column)for(int row=0;row<4;++row)state.View[row*4+column]=Product(state.View[row*4+column],camera[27+column]);
   if(g.Orthographic){state.Projection=new float[16];state.Projection[0]=Product(g.OrthographicScale,camera[17]);state.Projection[5]=g.OrthographicScale;state.Projection[10]=state.Projection[15]=1;}
   else{state.Projection=Projection(camera,g);state.Projection[0]=Product(state.Projection[0],camera[22]);state.Projection[5]=Product(state.Projection[5],camera[23]);state.Projection[8]=Sum(state.Projection[8],camera[20]);state.Projection[9]=Sum(state.Projection[9],camera[21]);}
   state.Primary=Symmetric(state,camera,state.View,g,services);state.PreviousCullingMode=g.CullingMode;state.Secondary=g.CullingMode==0?Asymmetric(state,camera,state.View,g,services):Symmetric(state,camera,state.View,g,services);state.AuxiliaryCopy=(float[])g.Auxiliary.Clone();state.Combined=Multiply(services,state.View,state.Projection);state.MappedCombined=Multiply(services,state.Combined,state.AuxiliaryCopy);state.MappedProjection=Multiply(services,state.Projection,state.AuxiliaryCopy);
   float sine,cosine;Trig(camera[16],g,out sine,out cosine);float tan=Store(Div(F(sine),F(cosine))),width=Store(Div(F(tan),F(camera[17])));state.Scales=new[]{width,tan,Store(Div(Mul(I(g.SourceSize[0]),F(width)),I(g.ScreenSize[0]))),Store(Div(Mul(F(tan),I(g.SourceSize[1])),I(g.ScreenSize[1])))};float ratio=Store(Div(Div(F(sine),F(cosine)),F(input[17]))),square=Store(Add(Mul(F(ratio),F(ratio)),F(1))),normal=Store(Div(F(1),F(BuildEffectSound.SquareRoot(square))));state.EdgePlanes=new float[16];state.EdgePlanes[0]=Neg(normal);state.EdgePlanes[1]=normal;state.EdgePlanes[6]=cosine;state.EdgePlanes[7]=Neg(cosine);state.EdgePlanes[8]=Product(normal,ratio);state.EdgePlanes[9]=state.EdgePlanes[8];state.EdgePlanes[10]=state.EdgePlanes[11]=sine;state.Frustum=OrdinaryFrustum(camera,state.View,state.Scales,g.Template,services);state.PassWord=1;state.ResetWord=0;services.UpdateLight(state);services.UpdateRenderCache(state);
  }
  // Original0x603cc0: full normal-camera restore, copied clip transform,
  // recomposed primary/secondary matrix, then view/projection device services.
  public static void RestoreNormal(CameraPlaneState state,float[] camera,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(services==null||services.DeviceTransform==null)throw new ArgumentException("Device transform service required.");ApplyNormal(state,camera,g,services);state.ClipTransform=(float[])g.ClipTransform.Clone();state.Primary=Multiply(services,state.Combined,state.ClipTransform);state.Secondary=(float[])state.Primary.Clone();services.DeviceTransform(2,state.View);services.DeviceTransform(3,state.Projection);
  }
  // Original0x5d6900. Nonzero requests ALWAYS save/apply, including same-mode
  // requests. Zero changes the mode without applying a matrix. Mode assignment
  // happens after the nested restore/device calls.
  public static void Switch(CameraPlaneState state,int requested,CameraPlaneGlobals g,CameraPlaneServices services)
  {
   if(state==null)throw new ArgumentNullException("state");Camera(state.Current);if(requested!=state.Mode&&state.Mode==0)state.Base=(float[])state.Current.Clone();if(requested!=0){state.Saved=(float[])state.Current.Clone();RestoreNormal(state,state.Base,g,services);}state.Mode=requested;
  }
  public static TreePlaneInputs TreeInputs(CameraPlaneState state,CameraPlaneGlobals g)
  {
   Camera(state.Current);Array(state.View,16);Array(state.Scales,4);return new TreePlaneInputs{Near=state.Current[18],Far=state.Current[19],Scales=state.Scales,Template=g.Template,View=state.View,Direction=new Point3(state.Current[8],state.Current[9],state.Current[10]),Position=new Point3(state.Current[12],state.Current[13],state.Current[14])};
  }
  static PortalEntryCamera PortalCamera(CameraPlaneState state)
  {float[] world=new float[16];System.Array.Copy(state.Current,world,16);return new PortalEntryCamera{World=world,Projection=state.Projection,FieldOfView=state.Current[16],Aspect=state.Current[17],Near=state.Current[18]};}
  // Composition into recovered0x5f3c80. Grid/portal-disabled evidence covers
  // actual camera mode switching, tree production and conditional restoration.
  // Exact finite fourth-radius words are still supplied per native predicate.
  public static SceneVisibilityPreparationServices PreparationServices(CameraPlaneState camera,CameraPlaneGlobals globals,CameraPlaneServices services,TreePlaneRuntime planeRuntime,TreeVisibilityData tree,byte[] bits,Func<TreeVisibilityVisit,uint> residue)
  {
   return new SceneVisibilityPreparationServices{
    SwitchCamera=delegate(SceneVisibilityPreparationCall call,int requested){Switch(camera,requested,globals,services);call.Options.CurrentCameraMode=camera.Mode;call.Camera=PortalCamera(camera);},
    TraverseTree=delegate(SceneVisibilityPreparationCall call){TreePlaneProduction.Produce(call.State,call.Options.TreeEnabled,tree,TreeInputs(camera,globals),planeRuntime,bits,services.Multiply,residue);},
    RestoreCamera=delegate(SceneVisibilityPreparationCall call){RestoreNormal(camera,camera.Saved,globals,services);call.Camera=PortalCamera(camera);}
   };
  }
 }
}
