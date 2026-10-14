// Original surface capture caller, with raw frame residue and final services explicit.
using System;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class SurfaceCaptureState
 {
  public readonly byte[] Backend;
  public uint AspectOverride,CallerStack,BufferResidue;
  public SurfaceCaptureState(byte[] backend){Backend=backend;}
 }
 public sealed class SurfaceCaptureFrame
 {
  public readonly byte[] RenderTarget=new byte[4],Offscreen=new byte[4],Buffer=new byte[4];
  public uint Width,Height,Return;
 }
 public sealed class SurfaceCaptureServices
 {
  public Func<RendererResourceCall,uint> Call;
  public Func<uint,RawViewportView> ResolveBytes;
 }
 public static class SurfaceCaptureCpu
 {
  static uint Read(byte[] b,uint o){if(b==null||b.Length<4||o>(uint)(b.Length-4))throw new ArgumentException("Resolved capture image required.");int p=(int)o;return(uint)b[p]|(uint)b[p+1]<<8|(uint)b[p+2]<<16|(uint)b[p+3]<<24;}
  static void Write(byte[] b,uint o,uint v){Read(b,o);int p=(int)o;b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
  static uint Call(SurfaceCaptureServices services,string kind,uint receiver,uint offset,uint[] args,RawViewportView output){if(services==null||services.Call==null)throw new ArgumentException("Explicit capture device/D3DX/allocator services required.");return services.Call(new RendererResourceCall(kind,receiver,offset,args,output));}
  static uint Device(SurfaceCaptureState s,SurfaceCaptureServices services,uint offset,uint[] args,RawViewportView output){return Call(services,"device",Read(s.Backend,4),offset,args,output);}
  static uint Object(SurfaceCaptureServices services,uint token,uint offset){return Call(services,"object",token,offset,new uint[0],null);}
  static bool Good(uint result){return unchecked((int)result)>=0;}
  static void Copy(SurfaceCaptureServices services,uint destination,uint source,uint count)
  {
   if(count==0)return;if(services.ResolveBytes==null)throw new ArgumentException("Stable disjoint borrowed source/destination bytes required.");RawViewportView a=services.ResolveBytes(source),b=services.ResolveBytes(destination);if(a==null||b==null||a.Image==null||b.Image==null||count>(uint)a.Image.Length||a.Offset>(uint)a.Image.Length-count||count>(uint)b.Image.Length||b.Offset>(uint)b.Image.Length-count)throw new ArgumentException("Resolved copy capacity required.");if(System.Object.ReferenceEquals(a.Image,b.Image))throw new ArgumentException("Declared disjoint memcpy buffers required.");Array.Copy(a.Image,(int)a.Offset,b.Image,(int)b.Offset,(int)count);
  }
  // Whole6e28e0. Width/height argument slots become output handle boxes.
  // entrySP-8 is incoming residue for nonzero requested height; height derivation
  // overwrites it with the FISTP64 low word. D3DX stage later initializes it.
  public static SurfaceCaptureFrame Apply(SurfaceCaptureState s,SurfaceCaptureServices services,uint requestedWidth,uint requestedHeight,uint destinationOutToken,RawViewportView destinationOut)
  {
   if(s==null||destinationOut==null)throw new ArgumentException("Resolved caller/backend output image required.");SurfaceCaptureFrame frame=new SurfaceCaptureFrame();Write(frame.Buffer,0,s.BufferResidue);frame.Width=requestedWidth==0?Read(s.Backend,0x138):requestedWidth;frame.Height=requestedHeight;
   if(frame.Height==0){float aspect=s.AspectOverride==1?1.7777778f:s.AspectOverride==2?1.6f:s.AspectOverride==3?BitConverter.ToSingle(BitConverter.GetBytes(Read(s.Backend,0x630)),0):1.3333334f;NativeFrustum.Finite(aspect);if(aspect==0)throw new ArgumentException("Finite nonzero aspect required.");int height=W.Divide(W.FromDouble((double)frame.Width),W.From(aspect)).TruncateInt32();frame.Height=unchecked((uint)height);Write(frame.Buffer,0,frame.Height);}
   uint rtOut=unchecked(s.CallerStack+4),offOut=unchecked(s.CallerStack+8),bufferOut=unchecked(s.CallerStack-8);bool proceed=Good(Device(s,services,0x70,new uint[]{frame.Width,frame.Height,0x15,0,0,0,rtOut,0},new RawViewportView(frame.RenderTarget,0)))&&Read(frame.RenderTarget,0)!=0;
   if(proceed)proceed=Good(Device(s,services,0x90,new uint[]{frame.Width,frame.Height,0x15,2,offOut,0},new RawViewportView(frame.Offscreen,0)))&&Read(frame.Offscreen,0)!=0;
   if(proceed)proceed=Good(Device(s,services,0x88,new uint[]{Read(s.Backend,0x6e8),0,Read(frame.RenderTarget,0),0,2},null));
   if(proceed)proceed=Good(Device(s,services,0x80,new uint[]{Read(frame.RenderTarget,0),Read(frame.Offscreen,0)},null));
   if(proceed){Write(frame.Buffer,0,0);proceed=Good(Call(services,"d3dx-surface-buffer",0,0,new uint[]{bufferOut,0,Read(frame.Offscreen,0),0,0},new RawViewportView(frame.Buffer,0)));}
   if(proceed){uint token=Read(frame.Buffer,0);if(token==0)throw new ArgumentException("Successful D3DX output must resolve a buffer object.");uint size=Object(services,token,0x10);uint destination=Call(services,"allocate",0,0,new uint[]{size,0x776f50,0x989},null);Write(destinationOut.Image,destinationOut.Offset,destination);uint count=Object(services,Read(frame.Buffer,0),0x10);uint source=Object(services,Read(frame.Buffer,0),0xc);Copy(services,Read(destinationOut.Image,destinationOut.Offset),source,count);frame.Return=Object(services,Read(frame.Buffer,0),0x10);}
   uint cleanup=Read(frame.RenderTarget,0);if(cleanup!=0){Object(services,cleanup,8);Write(frame.RenderTarget,0,0);}cleanup=Read(frame.Offscreen,0);if(cleanup!=0){Object(services,cleanup,8);Write(frame.Offscreen,0,0);}cleanup=Read(frame.Buffer,0);if(cleanup!=0)Object(services,cleanup,8);return frame;
  }
 }
}
