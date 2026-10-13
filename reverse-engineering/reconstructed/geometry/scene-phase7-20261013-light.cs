// Original PC light constant cache consumer, with explicit numeric producer input.
using System;
namespace Recovered.Geometry
{
 public sealed class LightRenderInputs
 {
  public uint[] VectorWords,MatrixWords,ColorWords;
 }
 public sealed class LightRenderCache
 {
  // Raw 22 words at 0x986930: matrix16, color3, vector3.
  public uint[] Words;
  public ushort ShortCounter;
  public uint Dirty;
 }
 public static class LightRenderCacheProduction
 {
  static void Array(uint[] words,int length){if(words==null||words.Length!=length)throw new ArgumentException("Resolved raw light words required.");}
  // Original 0x5fcc10. All copies are integer MOV/REP MOVSD. Sources are
  // resolved disjoint regions; raw payloads are never interpreted as floats.
  public static int Update(CameraRenderCache sharedCounter,LightRenderCache state,LightRenderInputs input)
  {
   if(sharedCounter==null||state==null||input==null)throw new ArgumentException("Resolved shared counter and light state required.");Array(state.Words,22);Array(input.VectorWords,3);Array(input.MatrixWords,16);Array(input.ColorWords,3);for(int i=0;i<16;++i)state.Words[i]=input.MatrixWords[i];for(int i=0;i<3;++i)state.Words[16+i]=input.ColorWords[i];for(int i=0;i<3;++i)state.Words[19+i]=input.VectorWords[i];sharedCounter.Counter=unchecked(sharedCounter.Counter+1);state.ShortCounter=unchecked((ushort)(state.ShortCounter+1));state.Dirty=0;return 1;
  }
  // Only the packer is recovered here. The original 0x5ff840 finite numeric
  // orientation/blending output remains a supplied producer service.
  public static Action<CameraPlaneState> CameraCallback(CameraRenderCache sharedCounter,LightRenderCache state,Func<CameraPlaneState,LightRenderInputs> producer)
  {if(producer==null)throw new ArgumentException("Explicit light numeric producer required.");return delegate(CameraPlaneState camera){Update(sharedCounter,state,producer(camera));};}
 }
}
