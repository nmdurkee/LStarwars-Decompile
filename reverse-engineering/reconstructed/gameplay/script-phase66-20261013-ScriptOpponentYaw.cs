// Final builtin yaw predicate composes original sine-table rotation and513-word signed direction-angle helper.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptOpponentYaw
 {
  static float Difference(float a,float b){if(float.IsNaN(a)||float.IsInfinity(a)||float.IsNaN(b)||float.IsInfinity(b))throw new ArgumentException("Finite yaw coordinates required.");return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.Multiply(PlaybackWide.From(b),PlaybackWide.From(-1f))).Store();}
  public static uint Evaluate(TakeoverReleaseMemory m,uint actor,float[] sine,ushort[] angleTable){if(actor==0)return m.Read32(0x760010);uint opponent=m.Read32(actor+0xe4);if(opponent==0)return m.Read32(0x760010);uint controller=m.Read32(actor+0xd0);float x=Difference(m.Float(opponent+0x5c),m.Float(controller+0x5c)),z=Difference(m.Float(opponent+0x64),m.Float(controller+0x64));if(sine==null||sine.Length!=32768||angleTable==null||angleTable.Length!=513)throw new ArgumentException("Original complete trig tables required.");int heading=-(int)m.Read16(controller+0x27a);float s=sine[(heading>>1)&32767],c=sine[((heading+0x4000)>>1)&32767];float rx=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(s),PlaybackWide.From(z)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(x))).Store(),rz=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(z),PlaybackWide.From(c)),PlaybackWide.Multiply(PlaybackWide.From(-1f),PlaybackWide.Multiply(PlaybackWide.From(x),PlaybackWide.From(s)))).Store();int angle=PathAngles.Direction(rx,rz,angleTable);double scale=BitConverter.Int64BitsToDouble(unchecked((long)(((ulong)m.Read32(0x76001c)<<32)|m.Read32(0x760018))));return TakeoverReleaseMemory.Bits(PlaybackWide.Multiply(PlaybackWide.FromDouble(angle),PlaybackWide.FromDouble(scale)).Store());}
 }
}
