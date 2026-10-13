using System;
namespace Recovered.Gameplay
{
 public sealed class ActorPoolWorld
 {
  public OriginPathMemory Memory;
  public uint World,Registry,PublishedPool;
  public uint HighestActive;
  //41c7c0 character initializer is still a service; caller ignores its return.
  public Action<uint,uint,uint> Initialize;
 }
 public static class ActorPoolCreation
 {
  public static int Availability(OriginPathMemory m,bool active,uint table,uint index,uint output)
  {
   if(!active){if(output!=0)m.Set32(output,0);return -1;}if(output!=0){int slot=unchecked((sbyte)m.U8(index));m.Set32(output,m.U32(unchecked(table+(uint)(slot*12))));}return unchecked((sbyte)m.U8(index));
  }
  public static uint Allocate(OriginPathMemory m,uint descriptor)
  {
   if(descriptor==0)return 0;uint stride=m.U32(descriptor);if(stride==0)return 0;uint current=m.U32(descriptor+4);
   for(uint j=0;j<64;j++,current=unchecked(current+stride))if((m.U8(current+0x1fc)&1)==0){for(uint k=0;k<stride;k++)m.Set8(current+k,0);m.Set32(current+0x1fc,m.U32(current+0x1fc)|1);m.Set8(current+0x28d,(int)j);return current;}return 0;
  }
  public static void RefreshHighest(ActorPoolWorld w)
  {
   w.HighestActive=0;for(uint j=0;j<64;j++)if((w.Memory.U8(w.PublishedPool+j*0x10d8+0x1fc)&1)!=0)w.HighestActive=j+1;
  }
  public static uint Prepare(ActorPoolWorld w)
  {
   var m=w.Memory;uint actor=Allocate(m,m.U32(w.World+0x298c));if(actor==0)return 0;uint index=m.U8(actor+0x28d);m.Set32(actor+0x1fc,m.U32(actor+0x1fc)|0x1001);m.SetFloat(actor+0xa8,1);m.SetFloat(actor+0xff8,1);m.SetFloat(actor+0x1014,2000000);m.Set8(actor+0x671,255);m.Set8(actor+0x107a,2);ulong mask=index<64?1UL<<(int)index:0;m.Set32(actor+0x1e8,(uint)mask);m.SetFloat(actor+0x224,2000000);m.Set32(actor+0x1ec,(uint)(mask>>32));m.SetFloat(actor+0x220,2000000);m.Set32(actor+0x1048,1);m.SetFloat(actor+0x21c,2000000);m.Set8(actor+0x284,255);m.Set8(actor+0x283,255);m.Set8(actor+0x285,255);RefreshHighest(w);m.Set32(actor,actor);m.Set32(actor+0x398,actor);m.Set32(actor+4,actor+0x2c8);m.Set32(actor+0x2b0,0);m.Set32(actor+0x2b4,0);return actor;
  }
  public static uint Create(ActorPoolWorld w,uint type,uint mode)
  {
   if(type>0x153)return 0;var m=w.Memory;uint types=m.U32(w.Registry+0x1c);if((m.U32(types+type*2)&0xffff)==0xffff)return 0;uint actor=Prepare(w);if(actor==0)return 0;if(w.Initialize==null)throw new InvalidOperationException("Original character initializer required.");w.Initialize(actor,type,mode);return actor;
  }
 }
}
