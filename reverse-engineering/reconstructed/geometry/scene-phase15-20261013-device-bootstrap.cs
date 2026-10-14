// Original bootstrap caller; actual recovered CPU children and explicit host/resource edges.
using System;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class DeviceBootstrapCall
 {
  public readonly string Kind;
  public readonly uint Receiver,Offset;
  public readonly uint[] Arguments;
  public readonly RawViewportView Output;
  public readonly ViewportComCall Viewport;
  public DeviceBootstrapCall(string kind,uint receiver,uint offset,uint[] arguments,RawViewportView output,ViewportComCall viewport){Kind=kind;Receiver=receiver;Offset=offset;Arguments=arguments;Output=output;Viewport=viewport;}
 }
 public sealed class DeviceBootstrapState
 {
  public readonly RenderTargetPipelineRuntime Pipeline;
  public readonly BackendServiceGlobals Cache;
  public readonly BackendVendorGlobals Vendor;
  public readonly byte[] Modes,Settings;
  public readonly uint[] MultisampleTypes,Desktop;
  public uint Window,CriticalIndex,ResetEnabled,AspectMode;
  public bool LossCallback;
  // Explicit original frame token for local query output pointer diagnostics.
  public uint CallerStack;
  public DeviceBootstrapState(RenderTargetPipelineRuntime pipeline,BackendServiceGlobals cache,BackendVendorGlobals vendor,byte[] modes,byte[] settings,uint[] types,uint[] desktop){Pipeline=pipeline;Cache=cache;Vendor=vendor;Modes=modes;Settings=settings;MultisampleTypes=types;Desktop=desktop;}
 }
 public static class DeviceDimensionBootstrap
 {
  const uint BackendAddress=0x29765c8;
  static uint Read(byte[] b,uint at){if(b==null||b.Length<4||at>(uint)(b.Length-4))throw new ArgumentException("Resolved bootstrap byte image required.");int i=(int)at;return(uint)b[i]|(uint)b[i+1]<<8|(uint)b[i+2]<<16|(uint)b[i+3]<<24;}
  static void Write(byte[] b,uint at,uint value){Read(b,at);int i=(int)at;b[i]=(byte)value;b[i+1]=(byte)(value>>8);b[i+2]=(byte)(value>>16);b[i+3]=(byte)(value>>24);}
  static void CopyShort(byte[] b,int destination,int source){b[destination]=b[source];b[destination+1]=b[source+1];}
  static uint ModeWord(DeviceBootstrapState s,uint word){uint offset=unchecked(Read(s.Pipeline.BackendImage,0x660)*16u+word*4u);return Read(s.Modes,offset);}
  static uint Host(Func<DeviceBootstrapCall,uint> service,string kind,uint receiver,uint offset,uint[] args,RawViewportView output){if(service==null)throw new ArgumentException("Explicit bootstrap service required.");return service(new DeviceBootstrapCall(kind,receiver,offset,args,output,null));}
  static uint Com(DeviceBootstrapState s,Func<DeviceBootstrapCall,uint> service,bool d3d,uint offset,uint[] args,RawViewportView output){return Host(service,d3d?"d3d":"device",Read(s.Pipeline.BackendImage,d3d?0u:4u),offset,args,output);}
  static void Screen(DeviceBootstrapState s){int width=unchecked((int)Read(s.Pipeline.BackendImage,0x138)),height=unchecked((int)Read(s.Pipeline.BackendImage,0x13c));s.Pipeline.Viewport.Input.Screen[0]=width;s.Pipeline.Viewport.Origin[0]=width/2;s.Pipeline.Viewport.Input.Screen[1]=height;s.Pipeline.Viewport.Origin[1]=height/2;}
  static uint Create(DeviceBootstrapState s,Func<DeviceBootstrapCall,uint> service){byte[] b=s.Pipeline.BackendImage;uint result=Com(s,service,true,0x40,new uint[]{Read(b,0x1a0),Read(b,0x5f0),Read(b,0x154),Read(b,0x5f4),BackendAddress+0x138,BackendAddress+4},new RawViewportView(b,0x138));Write(s.Cache.CacheImage,0,result);return result;}
  static void Resource(DeviceBootstrapState s,Func<DeviceBootstrapCall,uint> service,string kind,uint mode){Host(service,kind,BackendAddress,0,new uint[]{mode},null);}
  // Original0x6e3940, thiscall receiver, one raw move-window argument, ret4.
  // Large resource release/rebuild graphs remain explicit lifecycle services;
  // their intervening CPU writes are NOT represented as final COM equivalence.
  public static uint Apply(DeviceBootstrapState s,uint moveWindow,Func<DeviceBootstrapCall,uint> service)
  {
   if(s==null||s.Pipeline==null||s.Cache==null||s.Vendor==null||!Object.ReferenceEquals(s.Pipeline.BackendImage,s.Cache.BackendImage)||s.MultisampleTypes==null||s.MultisampleTypes.Length!=5||s.Desktop==null||s.Desktop.Length!=2)throw new ArgumentException("One fixed backend and resolved bootstrap globals required.");
   byte[] b=s.Pipeline.BackendImage;Func<BackendComCall,uint> forward=delegate(BackendComCall call){return Host(service,"device",call.Device,call.VtableOffset,call.Arguments,null);};
   BackendCpuServices.Critical(s.CriticalIndex,true,delegate(bool enter,uint token){return Host(service,"enter",token,0,new uint[0],null);});
   Write(b,0x670,Read(b,0x620));b[0x66e]=(byte)(Read(b,0x158)==1?1:0);CopyShort(b,0x67c,0x6e4);Write(b,0x678,Read(b,0x638));b[0x674]=b[0x634];Write(b,0x680,Read(s.Settings,0x424));
   Com(s,service,true,0x38,new uint[]{0,1,BackendAddress+8},new RawViewportView(b,8));
   Write(b,0x154,s.Window);Write(b,0x158,b[0x65c]);Write(b,0x15c,1);Write(b,0x164,2);Write(b,0x150,1);Write(b,0x160,0x4b);if(b[0x664]!=0&&(b[0x1c]&1)==0)b[0x664]=0;b[0x634]=b[0x664];Write(b,0x144,2);Write(b,0x16c,1);
   if(Read(b,0x158)!=0&&moveWindow!=0){uint x=Read(s.Settings,0x414),y=Read(s.Settings,0x418),width=Read(s.Settings,0x40c),height=Read(s.Settings,0x410);if(unchecked((int)x)<0)x=unchecked(s.Desktop[0]-width)>>1;if(unchecked((int)y)<0)y=unchecked(s.Desktop[1]-height)>>1;Host(service,"window",s.Window,0,new uint[]{x,y,width,height,1},null);}
   uint format=Com(s,service,true,0x24,new uint[]{0,1,ModeWord(s,3),0x15,Read(b,0x158)},null);Write(b,0x140,unchecked((int)format)<0?ModeWord(s,3):0x15);Write(b,0x138,ModeWord(s,0));Write(b,0x13c,ModeWord(s,1));Write(b,0x168,ModeWord(s,2));if(Read(b,0x158)!=0)Write(b,0x168,0);
   byte processing=b[0x5f8];uint flags=processing==0?0x10u:0u;if(b[0x5fa]!=0)flags|=4;if(processing==0){if(Read(b,0xcc)>=0xfffe0101)flags|=0x40;else if((Read(b,0x24)&0x10000)!=0)flags|=0x80;else flags|=0x20;}else flags|=0x20;Write(b,0x5f4,flags);Write(b,0x5f0,1);Write(b,0x1a0,0);
   Com(s,service,true,0x14,new uint[]{0,0,BackendAddress+0x1a4},new RawViewportView(b,0x1a4));s.Vendor.Vendor=Read(b,0x5cc);s.Vendor.Device=Read(b,0x5d0);BackendCpuServices.Vendor(s.Cache,s.Vendor);
   if(b[0x63c]==0){for(uint i=0;i<5;++i){byte[] first=new byte[4],second=new byte[4];uint sample=s.MultisampleTypes[i];uint a=Com(s,service,true,0x2c,new uint[]{Read(b,0x1a0),Read(b,0x5f0),Read(b,0x140),Read(b,0x158),sample,s.CallerStack+4},new RawViewportView(first,0));bool ok=unchecked((int)a)>=0;if(ok){uint q=Com(s,service,true,0x2c,new uint[]{Read(b,0x1a0),Read(b,0x5f0),Read(b,0x160),Read(b,0x158),s.MultisampleTypes[i],unchecked(s.CallerStack-4)},new RawViewportView(second,0));ok=unchecked((int)q)>=0;}uint quality=Math.Max(Read(first,0),Read(second,0));Write(b,0x640+i*4,ok&&quality!=0?quality-1:0xffffffff);}Write(b,0x640,0);Write(b,0x658,0);b[0x63c]=1;}
   uint requested=Read(b,0x668),current=Read(b,0x638);if(b[0x63c]!=0&&Read(b,unchecked(0x640+requested*4))!=0xffffffff)Write(b,0x638,requested);else if(b[0x63c]==0||Read(b,unchecked(0x640+current*4))==0xffffffff)Write(b,0x638,0);
   current=Read(b,0x638);if(current>=5)throw new ArgumentException("Selected multisample index must resolve.");Write(b,0x148,s.MultisampleTypes[current]);uint maximum=Read(b,0x640+current*4);Write(b,0x14c,unchecked((int)maximum)<0?0:maximum);bool initialize=true;
   if(Read(b,4)==0){uint result=Create(s,service);for(int retry=0;unchecked((int)result)<0&&retry<15;++retry){Host(service,"sleep",0,0,new uint[]{500},null);result=Create(s,service);}if(Read(b,4)==0){Write(b,0x138,640);Write(b,0x13c,480);Write(b,0x168,60);result=Create(s,service);if(Read(b,4)==0){uint message=result==0x8876017c?0x776f80u:result==0x88760868?0x776fb0u:result==0x8876086a?0x776fdcu:0x777010u;Host(service,"error",0x2976078,0,message==0x777010?new uint[]{message,result}:new uint[]{message},null);}}Screen(s);}
   else if(s.ResetEnabled!=0){uint status=BackendCpuServices.Status(s.Cache,forward);if(unchecked((int)status)<0){if(status==0x88760869){BackendCpuServices.EndScene(s.Cache,forward);Resource(s,service,"release",0);uint result=Com(s,service,false,0x40,new uint[]{BackendAddress+0x138},new RawViewportView(b,0x138));if(unchecked((int)result)>=0){Resource(s,service,"rebuild",0);initialize=false;}}else if(status==0x88760868){if(s.LossCallback)Host(service,"loss",0,0,new uint[]{BackendAddress+0x138},new RawViewportView(b,0x138));}else Host(service,"message",s.Window,0,new uint[]{0x10,0,0},null);}else{BackendCpuServices.EndScene(s.Cache,forward);Resource(s,service,"release",1);Com(s,service,false,0x40,new uint[]{BackendAddress+0x138},new RawViewportView(b,0x138));Screen(s);Resource(s,service,"rebuild",1);initialize=false;}}
   Write(b,0x638,0);uint target=Read(b,0x148);for(uint i=0;i<5;++i)if(s.MultisampleTypes[i]==target){Write(b,0x638,i);break;}
   uint widthWord=Read(b,0x138),heightWord=Read(b,0x13c);uint aspect=DisplayModeCpuSelection.ClassifyRaw(widthWord,heightWord).Mode;Write(b,0x62c,aspect);float ratio=W.Divide(W.FromDouble((double)widthWord),W.FromDouble((double)heightWord)).Store();Write(b,0x630,BitConverter.ToUInt32(BitConverter.GetBytes(ratio),0));uint overrideMode=Read(s.Settings,0x424);s.AspectMode=overrideMode==3?aspect:overrideMode;
   uint refresh=Read(b,0x158)!=0?ModeWord(s,2):Read(b,0x168);Write(b,0x620,DisplayModeCpuSelection.Select(b,s.Modes,unchecked((int)Read(b,0x138)),unchecked((int)Read(b,0x13c)),unchecked((int)refresh)));
   Com(s,service,false,0x1c,new uint[]{BackendAddress+8},new RawViewportView(b,8));if(initialize)Resource(s,service,"resources",0);
   var resets=new RenderTargetResetServices{Target=delegate(uint device,uint slot,uint handle){return Host(service,"device",device,0x94,new uint[]{slot,handle},null);},Depth=delegate(uint device,uint handle){return Host(service,"device",device,0x9c,new uint[]{handle},null);},Viewport=delegate(ViewportComCall call){return service(new DeviceBootstrapCall("device",call.Device,0xbc,call.Arguments,null,call));}};RenderTargetResetProduction.ClearAdditional(s.Pipeline,resets);BackendCpuServices.Clear(s.Cache,new uint[]{0,0,1,0,0x3f800000,0},forward);Write(b,0x5fc,Com(s,service,false,0x44,new uint[]{0,0,0,0},null));
   for(uint stage=0;stage<8;++stage){BackendCpuServices.Sampler(s.Cache,stage,5,2,forward);BackendCpuServices.Sampler(s.Cache,stage,6,2,forward);BackendCpuServices.Sampler(s.Cache,stage,7,2,forward);}if(s.Pipeline.TargetCache.Configuration==0)BackendCpuServices.Shader(s.Cache,0,forward);BackendCpuServices.RenderState(s.Cache,161,Read(b,0x638)!=0?1u:0u,forward);
   for(uint i=0;i<4;++i)Write(b,0x6f0+i*4,0);Write(s.Settings,0x404,unchecked((uint)s.Pipeline.Viewport.Input.Screen[0]));Write(s.Settings,0x408,unchecked((uint)s.Pipeline.Viewport.Input.Screen[1]));if(Read(b,0x158)==0)Write(s.Settings,0x41c,Read(b,0x168));Write(s.Settings,0x420,Read(b,0x638));if(Host(service,"settings-open",0,0,new uint[]{0x826074,0x76f4d8},new RawViewportView(s.Settings,0))!=0)throw new ArgumentException("This bounded bootstrap retains file-open failure policy only; successful settings writer remains external.");
   Write(b,0x188,0);Write(b,0x18c,0);Write(b,0x190,unchecked((uint)s.Pipeline.Viewport.Input.Screen[0]));Write(b,0x194,unchecked((uint)s.Pipeline.Viewport.Input.Screen[1]));Write(b,0x198,0);Write(b,0x19c,0x3f800000);b[0x65c]=(byte)(Read(b,0x158)==1?1:0);Write(b,0x660,Read(b,0x620));b[0x664]=b[0x634];Write(b,0x668,Read(b,0x638));CopyShort(b,0x66c,0x6e4);
   return BackendCpuServices.Critical(s.CriticalIndex,false,delegate(bool enter,uint token){return Host(service,"exit",token,0,new uint[0],null);});
  }
 }
}
