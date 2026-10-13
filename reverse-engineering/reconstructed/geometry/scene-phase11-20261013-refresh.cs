// Actual finite viewport setters and context refresh through recovered CPU forwarding.
using System;
using Recovered.Animation;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class ViewportSetterRuntime
 {
  public CameraViewportState Viewport;
  public CameraViewportInputs Input;
  public int[] Source,Origin;
  public float[] Scale,Bias;
  // Original integer converter6e6b90 mode0, truncated output fitsInt32.
  public int ConversionMode;
 }
 public static class ContextViewportRefresh
 {
  static W I(int value){return W.FromDouble(value);}
  static W Sub(W a,W b){return W.Add(a,W.Multiply(b,W.From(-1)));}
  static float Store(W value){float result=value.Store();NativeFrustum.Finite(result);return result;}
  static void Runtime(ViewportSetterRuntime v)
  {if(v==null||v.Viewport==null||v.Input==null||v.Input.Screen==null||v.Input.Screen.Length!=2||v.Input.Rectangle==null||v.Input.Rectangle.Length!=4||v.Input.DepthWords==null||v.Input.DepthWords.Length!=2)throw new ArgumentException("Resolved fixed viewport globals required.");}
  static void Numeric(ViewportSetterRuntime v)
  {Runtime(v);if(v.Source==null||v.Source.Length!=2||v.Source[0]==0||v.Source[1]==0||v.Origin==null||v.Origin.Length!=2||v.Scale==null||v.Scale.Length!=2||v.Bias==null||v.Bias.Length!=2||v.ConversionMode!=0)throw new ArgumentException("Finite source/bias/scale and converter mode0 required.");foreach(float value in v.Scale)NativeFrustum.Finite(value);foreach(float value in v.Bias)NativeFrustum.Finite(value);}
  // Original0x5dabf0 finite FLD/FSTP depth setter. Dirty is unconditional.
  public static void Depth(ViewportSetterRuntime v,float minimum,float maximum)
  {Runtime(v);NativeFrustum.Finite(minimum);NativeFrustum.Finite(maximum);v.Viewport.Dirty=1;v.Input.DepthWords[0]=PcObjectImage.ToBits(minimum);v.Input.DepthWords[1]=PcObjectImage.ToBits(maximum);}
  // Original0x5dac70: bias+input spillsfloat32, but integer screen/source
  // multiply/divide and origin-minus-arithmetic-shift-half stay x87 wide.
  public static void Position(ViewportSetterRuntime v,float x,float y)
  {Numeric(v);float[] values={x,y};for(int axis=0;axis<2;++axis){NativeFrustum.Finite(values[axis]);float adjusted=Store(W.Add(W.From(v.Bias[axis]),W.From(values[axis])));W offset=Sub(I(v.Origin[axis]),I(v.Input.Screen[axis]>>1)),ratio=W.Divide(W.Multiply(W.From(adjusted),I(v.Input.Screen[axis])),I(v.Source[axis]));v.Input.Rectangle[axis]=W.Multiply(W.Add(ratio,offset),W.From(16)).TruncateInt32();}v.Viewport.Dirty=1;}
  // Original0x5ef9a0 performs guarded float32 screen/source ratios and delta
  // stores before calling the actual position setter. Do not cancel this
  // round trip algebraically: input/spill/bias precision is observable.
  public static void Physical(ViewportSetterRuntime v,float x,float y)
  {Numeric(v);float[] values={x,y},output=new float[2];for(int axis=0;axis<2;++axis){NativeFrustum.Finite(values[axis]);float ratio=v.Input.Screen[axis]!=0?Store(W.Divide(W.From((float)v.Input.Screen[axis]),W.From((float)v.Source[axis]))):0;float delta=Store(Sub(W.Multiply(W.From(values[axis]),W.FromDouble(.0625)),Sub(I(v.Origin[axis]),I(v.Input.Screen[axis]>>1))));output[axis]=delta!=0&&ratio!=0?Store(W.Divide(W.From(delta),W.From(ratio))):0;}Position(v,output[0],output[1]);}
  // Original0x5dae80: size*scale spillsfloat32, then wide signed screen/source
  // ratio and times16 feed converter mode0. No intermediate double spill.
  public static void Extent(ViewportSetterRuntime v,float width,float height)
  {Numeric(v);float[] values={width,height};for(int axis=0;axis<2;++axis){NativeFrustum.Finite(values[axis]);float adjusted=Store(W.Multiply(W.From(v.Scale[axis]),W.From(values[axis])));v.Input.Rectangle[axis+2]=W.Multiply(W.Divide(W.Multiply(W.From(adjusted),I(v.Input.Screen[axis])),I(v.Source[axis])),W.From(16)).TruncateInt32();}v.Viewport.Dirty=1;}
  static void Write(byte[] image,int offset,uint word){if(image==null||offset<0||offset>image.Length-4)throw new ArgumentException("Resolved context viewport image required.");image[offset]=(byte)(word&255);image[offset+1]=(byte)((word>>8)&255);image[offset+2]=(byte)((word>>16)&255);image[offset+3]=(byte)(word>>24);}
  static void Full(byte[] caller,int[] screen){Write(caller,0x170,0);Write(caller,0x174,0);Write(caller,0x178,unchecked((uint)screen[0]));Write(caller,0x17c,unchecked((uint)screen[1]));Write(caller,0x180,0);Write(caller,0x184,0x3f800000);}
  // Original0x6e2510. Caller viewport and fixed global backend may alias.
  // Depth/physical/extent setters and real dirty viewport reset execute before
  // caller viewport is rebuilt and forwarded a second time. COM stays explicit.
  public static uint Refresh(byte[] callerImage,ViewportCpuState globalBackend,ViewportSetterRuntime runtime,Func<ViewportComCall,uint> setViewport)
  {
   Numeric(runtime);if(globalBackend==null||!Object.ReferenceEquals(globalBackend.Screen,runtime.Input.Screen))throw new ArgumentException("One shared screen global array required.");Full(callerImage,runtime.Input.Screen);Depth(runtime,0,1);Physical(runtime,0,0);Extent(runtime,640,224);CameraViewport.Reset(runtime.Viewport,runtime.Input,delegate(uint[] words){byte[] packet=new byte[24];for(int i=0;i<6;++i)Write(packet,i*4,words[i]);ViewportCpuProduction.Global(globalBackend,new RawViewportView(packet,0),setViewport);});Full(callerImage,runtime.Input.Screen);return ViewportCpuProduction.Global(globalBackend,new RawViewportView(callerImage,0x170),setViewport);
  }
 }
}
