// Bind recovered original CPU renderer producers into camera service ordering.
using System;
namespace Recovered.Geometry
{
 public static class CameraCpuRendererServices
 {
  // Source dimensions 0x80e694/8 and origin0x80202c/30 are independent of
  // camera-derived SourceSize at0x80e69c/a0. Runtime bindings stay explicit.
  // Only matrix/device services are forwarded; both CPU callbacks are owned
  // by recovered finite light and render-cache producers using one counter.
  public static CameraPlaneServices Bind(CameraPlaneServices matrixAndDevice,CameraRenderCache cameraCache,RenderCacheInputs cacheInputs,LightRenderCache lightCache,LightNumericGlobals lightGlobals)
  {
   if(matrixAndDevice==null||matrixAndDevice.Multiply==null||cameraCache==null||cacheInputs==null||lightCache==null||lightGlobals==null)throw new ArgumentException("Resolved renderer state and explicit matrix service required.");return new CameraPlaneServices{Multiply=matrixAndDevice.Multiply,DeviceTransform=matrixAndDevice.DeviceTransform,UpdateLight=LightNumericProduction.CameraCallback(cameraCache,lightCache,lightGlobals),UpdateRenderCache=CameraRenderCacheProduction.CameraCallback(cameraCache,cacheInputs)};
  }
 }
}
