// Actual integer viewport forwarding, including source/cached packet distinction.
using System;
namespace Recovered.Geometry
{
 public sealed class RawViewportView
 {
  public readonly byte[] Image;
  public readonly uint Offset;
  public RawViewportView(byte[] image,uint offset){Image=image;Offset=offset;}
 }
 public sealed class ViewportCpuState
 {
  public readonly byte[] BackendImage;
  public readonly int[] Screen;
  public ViewportCpuState(byte[] backendImage,int[] screen){BackendImage=backendImage;Screen=screen;}
 }
 public sealed class ViewportComCall
 {
  public readonly ViewportCpuState Backend;
  public readonly RawViewportView Input;
  public readonly uint Device;
  public readonly uint[] Arguments;
  public ViewportComCall(ViewportCpuState backend,RawViewportView input,uint device,uint[] arguments){Backend=backend;Input=input;Device=device;Arguments=arguments;}
 }
 public static class ViewportCpuProduction
 {
  static void Range(byte[] image,uint offset,int count){if(image==null||image.Length<count||offset>(uint)(image.Length-count))throw new ArgumentException("Resolved fixed viewport byte image required.");}
  static uint Read(byte[] image,uint offset){Range(image,offset,4);int i=(int)offset;return(uint)image[i]|((uint)image[i+1]<<8)|((uint)image[i+2]<<16)|((uint)image[i+3]<<24);}
  static void Write(byte[] image,uint offset,uint word){Range(image,offset,4);int i=(int)offset;image[i]=(byte)(word&255);image[i+1]=(byte)((word>>8)&255);image[i+2]=(byte)((word>>16)&255);image[i+3]=(byte)(word>>24);}
  // Original 0x6e2470, thiscall backend, input pointer, ret4. COM receives a
  // separate locally clamped packet. After it returns, forward-copy ORIGINAL
  // source words into backend+170, including callback/overlap effects.
  public static uint Apply(ViewportCpuState state,RawViewportView input,Func<ViewportComCall,uint> setViewport)
  {
   if(state==null||state.Screen==null||state.Screen.Length!=2||input==null||setViewport==null)throw new ArgumentException("Resolved viewport/backend and explicit COM service required.");Range(state.BackendImage,0x170,24);Range(input.Image,input.Offset,24);uint[] arguments=new uint[6];for(uint i=0;i<6;++i)arguments[i]=Read(input.Image,input.Offset+i*4);uint width=unchecked((uint)state.Screen[0]),height=unchecked((uint)state.Screen[1]);if(arguments[2]>=width)arguments[2]=width;if(arguments[3]>=height)arguments[3]=height;setViewport(new ViewportComCall(state,input,Read(state.BackendImage,4),arguments));uint last=0;for(uint i=0;i<6;++i){last=Read(input.Image,input.Offset+i*4);Write(state.BackendImage,0x170+i*4,last);}return last;
  }
  // Original 0x6e57b0 selects fixed backend0x29765c8. Caller provides that
  // resolved global image; null input returns0 without touching its contents.
  public static uint Global(ViewportCpuState globalBackend,RawViewportView input,Func<ViewportComCall,uint> setViewport)
  {return input==null?0:Apply(globalBackend,input,setViewport);}
 }
}
