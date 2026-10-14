// Original resource caller's CPU ownership writes and buffer/mesh production.
using System;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class RendererResourceCall
 {
  public readonly string Kind;
  public readonly uint Receiver,Offset;
  public readonly uint[] Arguments;
  public readonly RawViewportView Output;
  public RendererResourceCall(string kind,uint receiver,uint offset,uint[] args,RawViewportView output){Kind=kind;Receiver=receiver;Offset=offset;Arguments=args;Output=output;}
 }
 public sealed class RendererResourceState
 {
  public readonly DeviceBootstrapState Bootstrap;
  // Original texture owner records986f00,32 records of48 bytes, pointer firstword.
  public readonly byte[] TexturePool;
  public uint CallerStack;
  public RendererResourceState(DeviceBootstrapState bootstrap,byte[] texturePool){Bootstrap=bootstrap;TexturePool=texturePool;}
 }
 public sealed class RendererResourceServices
 {
  public Func<RendererResourceCall,uint> Call;
  // Host lock output token resolves a stable, disjoint writable byte view.
  public Func<uint,RawViewportView> ResolveBuffer;
 }
 public static class RendererResourceProduction
 {
  const uint B=0x29765c8;
  static uint Read(byte[] image,uint at){if(image==null||image.Length<4||at>(uint)(image.Length-4))throw new ArgumentException("Resolved resource bytes required.");int i=(int)at;return(uint)image[i]|(uint)image[i+1]<<8|(uint)image[i+2]<<16|(uint)image[i+3]<<24;}
  static void Write(byte[] image,uint at,uint value){Read(image,at);int i=(int)at;image[i]=(byte)value;image[i+1]=(byte)(value>>8);image[i+2]=(byte)(value>>16);image[i+3]=(byte)(value>>24);}
  static uint Call(RendererResourceServices services,string kind,uint receiver,uint offset,uint[] args,RawViewportView output){if(services==null||services.Call==null)throw new ArgumentException("Explicit resource/device service required.");return services.Call(new RendererResourceCall(kind,receiver,offset,args,output));}
  static uint Device(RendererResourceState s,RendererResourceServices services,uint offset,uint[] args,RawViewportView output){return Call(services,"device",Read(s.Bootstrap.Pipeline.BackendImage,4),offset,args,output);}
  static uint Save(RendererResourceState s,uint result){Write(s.Bootstrap.Cache.CacheImage,0,result);return result;}
  static void Release(RendererResourceState s,RendererResourceServices services,uint offset){byte[] b=s.Bootstrap.Pipeline.BackendImage;uint token=Read(b,offset);if(token!=0){Call(services,"object",token,8,new uint[0],null);Write(b,offset,0);}}
  // Original6e2610 plus actual settings scalar setters; file-open failure policy.
  public static uint Features(RendererResourceState s,RendererResourceServices services)
  {
   byte[] b=s.Bootstrap.Pipeline.BackendImage,p=s.Bootstrap.Settings;int configuration=s.Bootstrap.Pipeline.TargetCache.Configuration;
   Write(p,0x44c,Read(p,0x450));Write(p,0x440,Read(p,0x444));p[0x455]=1;Write(p,0x44c,p[0x457]==0?1u:2u);
   if(configuration<2){if(p[0x454]!=0&&unchecked((int)Read(p,0x44c))>1)Write(p,0x44c,1);if(p[0x448]!=0&&unchecked((int)Read(p,0x440))>1)Write(p,0x440,1);}
   if(configuration<=2&&p[0x454]!=0&&unchecked((int)Read(p,0x44c))>1)Write(p,0x44c,1);
   if(Read(b,0x638)!=0){if(p[0x454]!=0&&unchecked((int)Read(p,0x44c))>1)Write(p,0x44c,0);if(p[0x448]!=0&&unchecked((int)Read(p,0x440))>1)Write(p,0x440,1);}
   uint mask=Read(p,0x44c)==2?0x21u:1u,types=Read(p,0x44c)==2?0x13u:1u;if(Read(p,0x440)!=0)mask|=4;if(Read(p,0x440)==2)types|=2;if(p[0x455]!=0)mask|=0x80;Write(b,0x654,mask);Write(b,0x658,types);uint count=0;if(Read(b,0x638)==0)Write(b,0x6d4+count++*4,0);if((types&2)!=0)Write(b,0x6d4+count++*4,1);if((types&4)!=0)Write(b,0x6d4+count++*4,2);if((types&0x10)!=0)Write(b,0x6d4+count++*4,3);b[0x66c]=(byte)count;b[0x66d]=(byte)(count>>8);
   uint result=Call(services,"settings-open",0,0,new uint[]{0x826074,0x76f4d8},new RawViewportView(p,0));if(result!=0)throw new ArgumentException("Successful settings-file writer is outside this bounded resource policy.");return result;
  }
  // Actual6e4810/6e46f0 CPU wrappers, with raw HRESULT stored after final COM.
  public static uint CreateVertex(RendererResourceState s,RendererResourceServices services,uint size,uint usage,uint fvf,uint pool,uint output)
  {if(s.Bootstrap.Pipeline.TargetCache.Configuration==0)usage|=0x10;return Save(s,Device(s,services,0x68,new uint[]{size,usage,fvf,pool,B+output,0},new RawViewportView(s.Bootstrap.Pipeline.BackendImage,output)));}
  public static uint CreateIndex(RendererResourceState s,RendererResourceServices services,uint size,uint usage,uint format,uint pool,uint output,uint shared)
  {if(s.Bootstrap.Pipeline.TargetCache.Configuration==0)usage|=0x10;return Save(s,Device(s,services,0x6c,new uint[]{size,usage,format,pool,B+output,shared},new RawViewportView(s.Bootstrap.Pipeline.BackendImage,output)));}
  public static uint BufferLock(RendererResourceState s,RendererResourceServices services,uint handle,uint offset,uint length,uint outputToken,RawViewportView output,uint flags)
  {return Save(s,Call(services,"object",handle,0x2c,new uint[]{offset,length,outputToken,flags},output));}
  public static uint BufferUnlock(RendererResourceServices services,uint handle){return Call(services,"object",handle,0x30,new uint[0],null);}
  static RawViewportView Lock(RendererResourceState s,RendererResourceServices services,uint handle,uint length)
  {byte[] pointer=new byte[4];BufferLock(s,services,handle,0,length,unchecked(s.CallerStack-0x94),new RawViewportView(pointer,0),0);if(services.ResolveBuffer==null)throw new ArgumentException("Resolved borrowed lock buffer required.");RawViewportView view=services.ResolveBuffer(Read(pointer,0));if(view==null)throw new ArgumentException("Lock output lifetime must resolve.");return view;}
  static uint Unlock(RendererResourceServices services,uint handle){return BufferUnlock(services,handle);}
  static uint FloatWord(W value){float v=value.Store();NativeFrustum.Finite(v);return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static W U(uint value){return W.FromDouble((double)value);}
  static W Sub(W a,W b){return W.Add(a,W.Multiply(b,W.From(-1)));}
  static void Packet(RawViewportView destination,uint[] words){for(uint i=0;i<words.Length;++i)Write(destination.Image,unchecked(destination.Offset+i*4),words[i]);}
  // Whole original6e2d20 caller. Texture ownership free/allocation graphs stay
  // explicit; real buffer wrappers, feature selection and CPU writes execute here.
  public static uint Apply(RendererResourceState s,RendererResourceServices services)
  {
   if(s==null||s.Bootstrap==null||s.TexturePool==null)throw new ArgumentException("Resolved renderer/global/texture-owner images required.");byte[] b=s.Bootstrap.Pipeline.BackendImage;
   foreach(uint offset in new uint[]{0x6b0,0x6ec,0x690,0x694,0x698,0x688})Release(s,services,offset);
   Device(s,services,0x48,new uint[]{0,0,0,B+0x6b0},new RawViewportView(b,0x6b0));Device(s,services,0xa0,new uint[]{B+0x6ec},new RawViewportView(b,0x6ec));Features(s,services);
   for(uint i=0;i<4;++i){Release(s,services,0x6c4+i*4);Call(services,"texture-free",0,0,new uint[]{Read(b,0x6b4+i*4)},null);Write(b,0x6b4+i*4,0);Write(b,0x6f0+i*4,0);}
   uint count=(uint)(b[0x66c]|b[0x66d]<<8);if(count>4)count=4;b[0x6e4]=(byte)count;b[0x6e5]=(byte)(count>>8);
   for(uint i=0;i<count;++i){uint type=Read(b,0x6d4+i*4);if(type==0||type==1)Write(b,0x6b4+i*4,Call(services,"texture-create",0,0,new uint[]{1,1},null));else if(type==3)Write(b,0x6b4+i*4,Call(services,"texture-format",0,0,new uint[]{1,1,10},null));uint owner=Read(b,0x6b4+i*4);if(owner!=0){uint texture=Read(s.TexturePool,unchecked(owner-0x986f00u));Call(services,"texture",texture,0x48,new uint[]{0,B+0x6c4+i*4},new RawViewportView(b,0x6c4+i*4));}}
   // Static80-byte packet and48-byte packet constructed BEFORE buffer creation.
   uint[] quad={0xbf800000,0x3f800000,0,0,0,0xbf800000,0xbf800000,0,0,0x3f800000,0x3f800000,0x3f800000,0,0x3f800000,0,0x3f800000,0xbf800000,0,0x3f800000,0x3f800000};
   uint[] rectangle={0,0,0,0,0,FloatWord(W.Multiply(U(Read(b,0x13c)),W.From(3))),0,0x40400000,FloatWord(W.Multiply(U(Read(b,0x138)),W.From(3))),0,0x40400000,0};
   CreateVertex(s,services,0x50,8,0,0,0x690);CreateVertex(s,services,0x30,8,0,0,0x688);Packet(Lock(s,services,Read(b,0x690),0x50),quad);Unlock(services,Read(b,0x690));Packet(Lock(s,services,Read(b,0x688),0x30),rectangle);Unlock(services,Read(b,0x688));
   Write(b,0x6a0,16);int[] screen=s.Bootstrap.Pipeline.Viewport.Input.Screen;if(screen[0]==0)throw new ArgumentException("Finite fitting nonzero screen-ratio conversion required.");int rows=W.Multiply(W.Divide(W.FromDouble(screen[1]),W.FromDouble(screen[0])),W.From(16)).TruncateInt32();if(rows<1||rows>128)throw new ArgumentException("Declared finite resolved mesh row domain1..128 required.");Write(b,0x69c,unchecked((uint)rows));Write(b,0x6a4,unchecked((uint)(rows+1)*17u));Write(b,0x6a8,unchecked((uint)rows*32u));
   CreateVertex(s,services,unchecked(Read(b,0x6a4)*20u),8,0,0,0x694);CreateIndex(s,services,unchecked(Read(b,0x6a8)*6u),8,0x65,0,0x698,0);
   RawViewportView vertices=Lock(s,services,Read(b,0x694),unchecked(Read(b,0x6a4)*20u));uint vertexAt=vertices.Offset,rowCount=Read(b,0x69c),columnCount=Read(b,0x6a0);if(rowCount<1||rowCount>128||columnCount<1||columnCount>128)throw new ArgumentException("Stable resolved finite grid dimensions required.");
   for(uint row=0;row<=rowCount;++row){float rf=U(row).Store();for(uint column=0;column<=columnCount;++column){float cf=U(column).Store();W x=W.Divide(W.From(cf),U(columnCount)),y=W.Divide(W.From(rf),U(rowCount));Write(vertices.Image,vertexAt,FloatWord(Sub(W.Multiply(x,W.From(2)),W.From(1))));Write(vertices.Image,vertexAt+4,FloatWord(Sub(W.From(1),W.Multiply(y,W.From(2)))));Write(vertices.Image,vertexAt+8,0);Write(vertices.Image,vertexAt+12,FloatWord(x));Write(vertices.Image,vertexAt+16,FloatWord(y));vertexAt+=20;}}
   Unlock(services,Read(b,0x694));RawViewportView indices=Lock(s,services,Read(b,0x698),unchecked(Read(b,0x6a8)*6u));uint indexAt=indices.Offset;rowCount=Read(b,0x69c);columnCount=Read(b,0x6a0);if(rowCount>128||columnCount>128)throw new ArgumentException("Resolved bounded index-grid dimensions required.");for(uint row=0;row<rowCount;++row)for(uint column=0;column<columnCount;++column){uint a=(columnCount+1)*row+column,c=(columnCount+1)*(row+1)+column;foreach(uint value in new uint[]{a,a+1,c,c,a+1,c+1}){if(indices.Image==null||indexAt>(uint)(indices.Image.Length-2))throw new ArgumentException("Resolved writable index bytes required.");indices.Image[(int)indexAt]=(byte)value;indices.Image[(int)indexAt+1]=(byte)(value>>8);indexAt+=2;}}
   return Unlock(services,Read(b,0x698));
  }
 }
}
