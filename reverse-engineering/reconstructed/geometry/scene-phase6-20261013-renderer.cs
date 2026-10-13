// Original PC render-cache CPU producer and concrete viewport scale inputs.
using System;
using Recovered.Animation;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class RenderCacheInputs
 {
  public int[] Screen,Source,Rectangle,Origin;
 }
 public sealed class CameraRenderCache
 {
  // Byte image 0x9869b0..0x986a33, including untouched gaps.
  public byte[] Image;
  public uint Counter;
  public ushort ShortCounter;
 }
 public static class CameraRenderCacheProduction
 {
  static void Inputs(RenderCacheInputs v,bool nonzero)
  {if(v==null||v.Screen==null||v.Screen.Length!=2||v.Source==null||v.Source.Length!=2||v.Rectangle==null||v.Rectangle.Length!=4||v.Origin==null||v.Origin.Length!=2)throw new ArgumentException("Resolved signed viewport/source/origin words required.");if(nonzero&&(v.Screen[0]==0||v.Screen[1]==0||v.Source[0]==0||v.Source[1]==0))throw new ArgumentException("Finite nonzero screen/source ratios required.");}
  static bool Negative(float v){return(PcObjectImage.ToBits(v)&0x80000000u)!=0;}
  static float Store(W v,bool negativeZero)
  {float result=v.Store();NativeFrustum.Finite(result);return result==0&&negativeZero?PcObjectImage.FromBits(0x80000000u):result;}
  static float SpillInt(int v){return Store(W.FromDouble(v),false);}
  static W Int(int v){return W.FromDouble(v);}
  static W Sub(W a,W b){return W.Add(a,W.Multiply(b,W.From(-1)));}
  // Original 0x5dad10. Screen/source integers first spill to float32.
  // Any zero screen, source or offset yields positive zero for that axis.
  public static float[] Offsets(RenderCacheInputs v)
  {
   Inputs(v,false);float[] output=new float[2];for(int i=0;i<2;++i){float ratio=v.Screen[i]!=0&&v.Source[i]!=0?Store(W.Divide(W.From(SpillInt(v.Screen[i])),W.From(SpillInt(v.Source[i]))),false):0;float delta=Store(Sub(W.Multiply(Int(v.Rectangle[i]),W.FromDouble(.0625)),Sub(Int(v.Origin[i]),Int(v.Screen[i]>>1))),false);output[i]=delta!=0&&ratio!=0?Store(W.Divide(W.From(delta),W.From(ratio)),Negative(delta)!=Negative(ratio)):0;}return output;
  }
  // Original 0x5daef0: unlike offsets, screen/source ratio and rectangle
  // multiplication stay in x87 precision through the final output spill.
  public static float[] Extents(RenderCacheInputs v)
  {
   Inputs(v,true);float[] output=new float[2];for(int i=0;i<2;++i){W numerator=W.Multiply(Int(v.Rectangle[i+2]),W.FromDouble(.0625)),ratio=W.Divide(Int(v.Screen[i]),Int(v.Source[i]));output[i]=Store(W.Divide(numerator,ratio),v.Rectangle[i+2]==0&&((v.Screen[i]<0)!=(v.Source[i]<0)));}return output;
  }
  static void Write(byte[] image,int offset,uint word)
  {image[offset]=(byte)word;image[offset+1]=(byte)(word>>8);image[offset+2]=(byte)(word>>16);image[offset+3]=(byte)(word>>24);}
  // Original 0x5fcc80, including actual 0x5d6180/0x5d6190 globals.
  // View is raw copied data; only five projection words are x87 sampled.
  public static int Update(CameraRenderCache state,RenderCacheInputs input,uint[] viewWords,float[] projection)
  {
   Inputs(input,true);if(state==null||state.Image==null||state.Image.Length!=0x84||viewWords==null||viewWords.Length!=16||projection==null||projection.Length!=16)throw new ArgumentException("Resolved cache image and view/projection required.");int[] sampled={0,5,10,11,14};foreach(int at in sampled)NativeFrustum.Finite(projection[at]);Write(state.Image,0,0);for(int i=0;i<16;++i)Write(state.Image,4+i*4,viewWords[i]);for(int i=0;i<5;++i)Write(state.Image,0x44+i*4,PcObjectImage.ToBits(projection[sampled[i]]));float[][] pairs={Offsets(input),Extents(input)};for(int pair=0;pair<2;++pair)for(int axis=0;axis<2;++axis){float value=pairs[pair][axis];W factor=W.Divide(Int(input.Screen[axis]),W.FromDouble(axis==0?640:224));float result=Store(W.Multiply(W.From(value),factor),Negative(value)!=(input.Screen[axis]<0));Write(state.Image,0x74+(pair*2+axis)*4,PcObjectImage.ToBits(result));}state.Counter=unchecked(state.Counter+1);state.ShortCounter=unchecked((ushort)(state.ShortCounter+1));return 1;
  }
  // Bind directly to the camera producer's existing CPU cache callback.
  public static Action<CameraPlaneState> CameraCallback(CameraRenderCache state,RenderCacheInputs input)
  {return delegate(CameraPlaneState camera){if(camera==null||camera.View==null||camera.View.Length!=16)throw new ArgumentException("Resolved camera view required.");uint[] words=new uint[16];for(int i=0;i<16;++i)words[i]=PcObjectImage.ToBits(camera.View[i]);Update(state,input,words,camera.Projection);};}
 }
}
