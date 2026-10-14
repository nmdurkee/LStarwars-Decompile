// Original CPU texture factories and record initializer; final device/object COM explicit.
using System;
namespace Recovered.Geometry
{
 public sealed class TextureAllocationState
 {
  public readonly RendererResourceState Resource;
  public readonly TextureOwnerCpuState Ownership;
  // Bounded original x87 control37f; success return exposes the modified word.
  public ushort FloatingControlWord=0x37f;
  public TextureAllocationState(RendererResourceState resource,TextureOwnerCpuState ownership){if(resource==null||ownership==null||!Object.ReferenceEquals(resource.TexturePool,ownership.Pool))throw new ArgumentException("Shared original texture pool image required.");Resource=resource;Ownership=ownership;}
 }
 public static class TextureAllocationCpu
 {
  const uint PoolBase=0x986f00;
  static uint Read(byte[] b,int o){if(b==null||o<0||o>b.Length-4)throw new ArgumentException("Resolved backend/texture record bytes required.");return(uint)b[o]|(uint)b[o+1]<<8|(uint)b[o+2]<<16|(uint)b[o+3]<<24;}
  static void Write(byte[] b,int o,uint v){Read(b,o);b[o]=(byte)v;b[o+1]=(byte)(v>>8);b[o+2]=(byte)(v>>16);b[o+3]=(byte)(v>>24);}
  static uint Half(byte[] b,int o){return Read(b,o)&0xffff;}
  static void PutHalf(byte[] b,int o,uint v){Read(b,o);b[o]=(byte)v;b[o+1]=(byte)(v>>8);}
  static int Record(TextureAllocationState s,uint owner){uint at=unchecked(owner-PoolBase);if(s==null||s.Ownership.Pool==null||s.Ownership.Pool.Length<0x600||at>=0x600||at%48!=0)throw new ArgumentException("Resolved48-byte pool record required.");return(int)at;}
  static uint Call(TextureAllocationState s,RendererResourceServices services,string kind,uint receiver,uint offset,uint[] args,RawViewportView output){if(services==null||services.Call==null)throw new ArgumentException("Final texture/device COM required.");return services.Call(new RendererResourceCall(kind,receiver,offset,args,output));}
  static uint Device(TextureAllocationState s,RendererResourceServices services,uint offset,uint[] args,RawViewportView output){uint result=Call(s,services,"device",Read(s.Resource.Bootstrap.Pipeline.BackendImage,4),offset,args,output);Write(s.Resource.Bootstrap.Cache.CacheImage,0,result);return result;}
  // Original6e2130 reads the five immutable data words828230 indexed by638.
  public static uint Multisample(TextureAllocationState s){uint index=Read(s.Resource.Bootstrap.Pipeline.BackendImage,0x638);if(index>=5)throw new ArgumentException("Resolved original multisample table index0..4 required.");return new uint[]{0,2,4,8,16}[(int)index];}
  // Original6e47d0 adds the final shared-handle0; caller supplies seven raw args.
  public static uint Texture(TextureAllocationState s,RendererResourceServices services,uint width,uint height,uint levels,uint usage,uint format,uint pool,uint outputToken,RawViewportView output){return Device(s,services,0x5c,new uint[]{width,height,levels,usage,format,pool,outputToken,0},output);}
  // Original6e46b0 forwards all eight raw depth arguments.
  public static uint Depth(TextureAllocationState s,RendererResourceServices services,uint width,uint height,uint format,uint sample,uint quality,uint discard,uint outputToken,RawViewportView output,uint shared){return Device(s,services,0x74,new uint[]{width,height,format,sample,quality,discard,outputToken,shared},output);}
  // Whole5f81f0 CPU body, including both depth and texture branches.
  public static uint Initialize(TextureAllocationState s,RendererResourceServices services,uint owner,uint width,uint height,uint levels,uint renderTarget,uint pool,uint format)
  {
   int at=Record(s,owner);byte[] p=s.Ownership.Pool,b=s.Resource.Bootstrap.Pipeline.BackendImage;PutHalf(p,at+4,width);PutHalf(p,at+6,height);PutHalf(p,at+10,levels);PutHalf(p,at+12,levels);Write(p,at+0x1c,pool);PutHalf(p,at+8,0);Write(p,at+0x10,1);Write(p,at+0x14,format);Write(p,at+0x18,renderTarget);Write(p,at+0x2c,uint.MaxValue);Write(p,at+0x28,0);Write(p,at+0x24,0);Write(p,at+0x20,0x12449d0);
   if(format==4){Write(p,at+0x1c,0);PutHalf(p,at+10,1);uint index=Read(b,0x638);if(index>=5)throw new ArgumentException("Resolved multisample quality table required.");uint quality=Read(b,0x640+(int)index*4),sample=Multisample(s);Depth(s,services,Half(p,at+4),Half(p,at+6),TextureOwnerCpu.NativeFormat(4),sample,quality,0,owner+0x28,new RawViewportView(p,(uint)at+0x28),0);s.Ownership.AccountedBytes=unchecked(s.Ownership.AccountedBytes+Half(p,at+4)*Half(p,at+6)*4);return Half(p,at+4);}
   uint usage=0;if(Read(p,at+0x18)==1)usage=(format==5||format==6||format==7)?2u:1u;uint nativeFormat=TextureOwnerCpu.NativeFormat(format);Texture(s,services,Half(p,at+4),Half(p,at+6),Half(p,at+10),usage,nativeFormat,Read(p,at+0x1c),owner,new RawViewportView(p,(uint)at));uint token=Read(p,at);
   if(token==0)return token;uint count=Call(s,services,"texture",token,0x34,new uint[0],null);PutHalf(p,at+10,count);int area=unchecked((int)(Half(p,at+4)*Half(p,at+6)*4));long amount=(long)((double)area*((count&0xffff)==1?1.0:1.5));s.Ownership.AccountedBytes=unchecked(s.Ownership.AccountedBytes+(uint)amount);if(s.FloatingControlWord!=0x37f)throw new ArgumentException("Original finite64-significand arithmetic control37f required.");return(uint)(s.FloatingControlWord|0xc00);
  }
  static uint Create(TextureAllocationState s,RendererResourceServices services,uint divisor,uint levels,uint format)
  {
   if(divisor==0)throw new ArgumentException("Nonzero unsigned dimension divisor required.");byte[] b=s.Resource.Bootstrap.Pipeline.BackendImage;uint height=Read(b,0x13c)/divisor,width=Read(b,0x138)/divisor;byte[] used=s.Ownership.Used;if(used==null||used.Length<32)throw new ArgumentException("Resolved original usage bytes required.");int slot=0;while(slot<32&&used[slot]!=0)++slot;if(slot==32)throw new ArgumentException("Original exhausted-pool invalid-pointer branch is outside the resolved normal policy.");used[slot]=1;uint owner=PoolBase+(uint)slot*48;Initialize(s,services,owner,width,height,levels,1,0,format);int at=slot*48;Write(s.Ownership.Pool,at+0x20,(Read(s.Ownership.Pool,at+0x20)&0xffffdbff)|0x1b00);return owner;
  }
  public static uint CreateDefault(TextureAllocationState s,RendererResourceServices services,uint divisor,uint levels){uint format=TextureOwnerCpu.OwnerFormat(Read(s.Resource.Bootstrap.Pipeline.BackendImage,0x140));return Create(s,services,divisor,levels,format);}
  public static uint CreateFormat(TextureAllocationState s,RendererResourceServices services,uint divisor,uint levels,uint format){return Create(s,services,divisor,levels,format);}
 }
}
