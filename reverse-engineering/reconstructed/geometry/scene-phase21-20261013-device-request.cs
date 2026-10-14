// Original requested mode producer, composed with the real mode selector.
using System;
namespace Recovered.Geometry
{
 public static class DeviceModeRequest
 {
  static uint Read(byte[] b,int o){if(b==null||o<0||o>b.Length-4)throw new ArgumentException("Resolved backend bytes required.");return(uint)b[o]|(uint)b[o+1]<<8|(uint)b[o+2]<<16|(uint)b[o+3]<<24;}
  public static uint Apply(byte[] backend,byte[] modes,int width,int height,int refresh)
  {
   uint selected=DisplayModeCpuSelection.Select(backend,modes,width,height,refresh);if(selected>=Read(backend,0x618))selected=Read(backend,0x620);int at=0x660;Read(backend,at);backend[at]=(byte)selected;backend[at+1]=(byte)(selected>>8);backend[at+2]=(byte)(selected>>16);backend[at+3]=(byte)(selected>>24);return selected;
  }
 }
}
