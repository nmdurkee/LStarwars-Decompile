// Actual five-argument request caller6df1a0 and real CPU bootstrap child.
using System;
namespace Recovered.Geometry
{
 public static class DeviceRequestCaller
 {
  public static uint Apply(DeviceBootstrapState s,uint width,uint height,uint refresh,uint windowMode,uint moveWindow,uint callerStack,Func<DeviceBootstrapCall,uint> services)
  {
   if(s==null)throw new ArgumentException("Resolved original bootstrap globals required.");byte[] b=s.Pipeline.BackendImage;
   DeviceModeRequest.Apply(b,s.Modes,unchecked((int)width),unchecked((int)height),unchecked((int)refresh));
   // Original boolean publication occurs AFTER selection: selection observes65c old.
   if(b.Length<=0x65c)throw new ArgumentException("Resolved original window mode byte required.");b[0x65c]=windowMode==1?((byte)1):((byte)0);
   // Original caller pushes moveWindow then CALL: child entrySP=callerSP-8.
   // This is an explicit pointer diagnostic token, not a managed stack claim.
   s.CallerStack=unchecked(callerStack-8);return DeviceDimensionBootstrap.Apply(s,moveWindow,services);
  }
 }
}
