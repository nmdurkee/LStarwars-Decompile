// Actual PC dirty viewport clipping, screen/depth transform and normal camera composition.
using System;
using Recovered.Animation;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class CameraViewportInputs
 {
  // Screen dimensions are global973900/973904. Rectangle components are
  // global963e10..1c in sixteenths of a pixel; all arithmetic wrapsInt32.
  public int[] Screen,Rectangle;
  public uint[] DepthWords;
  public float[] Ranges;
 }
 public sealed class CameraViewportState
 {
  public uint Dirty;
  public CameraPlaneGlobals Globals;
  public float[] Identity;
  // Diagnostic device arguments, not an original persistent global field.
  public uint[] LastDeviceViewport;
 }
 public static class CameraViewport
 {
  static W I(int value){return W.FromDouble(value);}
  static float Neg(float value){return PcObjectImage.FromBits(PcObjectImage.ToBits(value)^0x80000000u);}
  static float Store(W value){float result=value.Store();NativeFrustum.Finite(result);return result;}
  static void Inputs(CameraViewportInputs input)
  {
   if(input==null||input.Screen==null||input.Screen.Length!=2||input.Rectangle==null||input.Rectangle.Length!=4||input.DepthWords==null||input.DepthWords.Length!=2||input.Ranges==null||input.Ranges.Length!=4)throw new ArgumentException("Resolved viewport input arrays required.");NativeFrustum.Finite(PcObjectImage.FromBits(input.DepthWords[0]));foreach(float value in input.Ranges)NativeFrustum.Finite(value);
  }
  // Original0x5ff2d0. Integer screen dimensions spillfloat32 before half
  // scaling. Depthmaximum constant is16777215, with raw minimumdepth copied.
  public static float[] PixelDepth(int[] screen,uint minimumDepthWord)
  {
   if(screen==null||screen.Length!=2)throw new ArgumentException("Two signed screen dimensions required.");float depth=PcObjectImage.FromBits(minimumDepthWord);NativeFrustum.Finite(depth);float x=(float)((double)(float)screen[0]*.5),y=(float)((double)(float)screen[1]*.5);float[] result=new float[16];result[0]=x;result[5]=Neg(y);result[10]=(float)(16777215.0-(double)depth);NativeFrustum.Finite(result[10]);result[12]=(float)((double)x+0.0);result[13]=(float)((double)y+0.0);result[14]=depth;result[15]=1;return result;
  }
  // Original0x5ff390. Device service runs after dirty clears and correction
  // changes, before identity copy,pixel/depth transform andclip-scale changes.
  // Empty clipped rectangles still emit sixwords with XYWH0 andrawdepths.
  public static bool Reset(CameraViewportState state,CameraViewportInputs input,Action<uint[]> deviceViewport)
  {
   if(state==null)throw new ArgumentNullException("state");if(state.Dirty==0)return false;Inputs(input);if(state.Globals==null||state.Identity==null||state.Identity.Length!=16||deviceViewport==null)throw new ArgumentException("Viewport globals,identity anddevice service required.");foreach(float value in state.Identity)NativeFrustum.Finite(value);
   int x=input.Rectangle[0],y=input.Rectangle[1],width=input.Rectangle[2],height=input.Rectangle[3],right=unchecked(x+width),bottom=unchecked(y+height),maxX=unchecked(input.Screen[0]<<4),maxY=unchecked(input.Screen[1]<<4),clippedWidth=width,clippedHeight=height,viewportX=x,viewportY=y;float[] correction={1,1,0,0};
   if(right>=0&&x<maxX&&bottom>=0&&y<maxY)
   {
    if(x<0){viewportX=0;clippedWidth=right;}if(right>maxX)clippedWidth=unchecked(clippedWidth+unchecked(maxX-right));if(y<0){viewportY=0;clippedHeight=bottom;}if(bottom>maxY)clippedHeight=unchecked(clippedHeight+unchecked(maxY-bottom));
    if(clippedWidth>0&&clippedHeight>0)
    {
     W denominatorX=W.From((float)clippedWidth),denominatorY=W.From((float)clippedHeight);int differenceX=unchecked(width-clippedWidth),differenceY=unchecked(height-clippedHeight);correction[0]=Store(W.Divide(I(width),denominatorX));correction[1]=Store(W.Divide(I(height),denominatorY));correction[2]=Store(W.Divide(I(differenceX),denominatorX));correction[3]=differenceY==0?PcObjectImage.FromBits(0x80000000u):Store(W.Divide(W.Multiply(W.From(-1),I(differenceY)),denominatorY));if(x<0)correction[2]=Neg(correction[2]);if(y<0)correction[3]=Neg(correction[3]);
    }
    else viewportX=viewportY=clippedWidth=clippedHeight=0;
   }
   else viewportX=viewportY=clippedWidth=clippedHeight=0;
   uint[] words={unchecked((uint)(viewportX>>4)),unchecked((uint)(viewportY>>4)),unchecked((uint)(clippedWidth>>4)),unchecked((uint)(clippedHeight>>4)),input.DepthWords[0],input.DepthWords[1]};state.Globals.Correction=correction;state.Dirty=0;state.LastDeviceViewport=(uint[])words.Clone();deviceViewport(words);
   // Native reads these inputs after the device edge; no old snapshot is used.
   state.Globals.ClipTransform=(float[])state.Identity.Clone();state.Globals.Auxiliary=PixelDepth(input.Screen,input.DepthWords[0]);float[] scales=new float[4];for(int axis=0;axis<2;++axis){float low=input.Ranges[axis],high=input.Ranges[axis+2];if(low==0&&high==1){scales[axis]=1;scales[axis+2]=Store(W.Multiply(I(input.Rectangle[axis+2]),W.FromDouble(1.0/65536)));}else{W denominator=W.Add(W.From(high),W.Multiply(W.From(-1),W.From(low)));scales[axis]=scales[axis+2]=Store(W.Divide(W.From(1),denominator));}}state.Globals.ClipScales=scales;return true;
  }
  // Extends original0x5ed540 normal camera path with actual dirty viewport
  // before view/projection generation. Renderer/GPU services remain explicit.
  public static void ApplyNormal(CameraPlaneState camera,float[] inputCamera,CameraViewportState viewport,CameraViewportInputs inputViewport,Action<uint[]> deviceViewport,CameraPlaneServices services)
  {
   if(camera==null||inputCamera==null||inputCamera.Length!=30||viewport==null)throw new ArgumentException("Resolved camera andviewport required.");camera.Current=(float[])inputCamera.Clone();Reset(viewport,inputViewport,deviceViewport);CameraPlaneProduction.ApplyNormal(camera,inputCamera,viewport.Globals,services);
  }
 }
}
