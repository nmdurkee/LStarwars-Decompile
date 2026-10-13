using System;
namespace Recovered.Gameplay
{
 public sealed class ActorBaseResetWorld
 {
  public OriginPathMemory Memory;
  public uint World,TypeTable;
  public bool AlternateMode,SpecialMode,DefaultPlayerMask;
  public uint MaskCallback,DefaultMaskLow,DefaultMaskHigh,DurationBits;
  public Func<uint,uint,uint[],uint> Service;
 }
 public static class ActorBaseReset
 {
  static uint Port(ActorBaseResetWorld w,uint address,uint actor,params uint[]args){if(w.Service==null)throw new InvalidOperationException("Original reset child service required.");return w.Service(address,actor,args);}
  static void Word(OriginPathMemory m,uint p,uint v){m.Set8(p,(int)(v&255));m.Set8(p+1,(int)((v>>8)&255));}
  public static uint TypePredicate(OriginPathMemory m,uint table,int type)
  {
   uint flags=m.U32(unchecked(table+(uint)(type*0x4c)+4));return(flags&0x1000010)==0x1000010?0u:(flags&0x40088)!=0?1u:0;
  }
  public static void PathReset(ActorBaseResetWorld w,uint actor)
  {
   var m=w.Memory;m.Set32(actor+0xef0,m.U32(actor+0xef0)&0xffdfffff);m.Set32(actor+0x1090,0);m.Set32(actor+0x4b0,m.U32(actor+0x4b0)&0xfffffd9f);
   foreach(uint at in new uint[]{0x458,0x45c,0x44c})m.Set32(actor+at,0);m.Set8(actor+0x1086,0);m.Set8(actor+0x1087,0);m.Set32(actor+0x108c,0);m.Set8(actor+0x1088,0);Word(m,actor+0x3ee,0xffff);Word(m,actor+0x3f0,0xffff);
   foreach(uint at in new uint[]{0xefc,0xf00,0xf04,0x4c0,0xf08,0x420,0x424,0x428,0x42c,0x430,0x434})m.Set32(actor+at,0);m.Set8(actor+0x405,0);Word(m,actor+0x3ec,0xffff);m.Set8(actor+0x404,255);Port(w,0x52f800,actor,m.U32(w.World+0x2ae8),actor,actor+0x2c8,255,1);
  }
  public static void Reset(ActorBaseResetWorld w,uint actor)
  {
   var m=w.Memory;Port(w,w.AlternateMode?0x481740u:w.SpecialMode?0x4cbe50u:0x407b60u,actor,actor);int type=unchecked((short)m.U32(actor+0x1064));uint predicate=TypePredicate(m,w.TypeTable,type);m.Set32(actor+0x4b0,m.U32(actor+0x4b0)&0xfffeffff);uint ef=m.U32(actor+0xef0);m.Set32(actor+0xef0,ef^(((predicate<<23)^ef)&0x800000));m.Set32(actor+0x3f8,0);m.Set32(actor+0x3fc,0);
   if(w.DefaultPlayerMask&&(m.U32(actor+0x1f8)&0x400)==0){m.Set32(actor+0x3f8,w.DefaultMaskLow);m.Set32(actor+0x3fc,w.DefaultMaskHigh);}
   else if(w.MaskCallback!=0){uint suit=m.U32(actor+0xcbc);uint name=suit!=0?m.U32(suit+4):m.U32(m.U32(actor+0x54)+0xc);byte index=(byte)Port(w,w.MaskCallback,actor,name);if(index!=255){if(index>=64){m.Set32(actor+0x3f8,w.DefaultMaskLow);m.Set32(actor+0x3fc,w.DefaultMaskHigh);}else{ulong mask=1UL<<index;m.Set32(actor+0x3f8,(uint)mask);m.Set32(actor+0x3fc,(uint)(mask>>32));}}}
   m.Set32(actor+0xeec,m.U32(actor+0xeec)|2);uint ec=m.U32(actor+0xeec);m.Set32(actor+0xed4,0x4e6e6b28);m.Set32(actor+0xed8,0x4e6e6b28);uint metadata=m.U32(actor+0x54);m.Set8(actor+0x378,0);ec=(m.U8(metadata+4)&0x80)!=0?ec|4:ec&0xfffffffb;m.Set32(actor+0xef0,m.U32(actor+0xef0)&0xc7ffe6c0);m.Set32(actor+0x1028,0x4e6e6b28);m.Set32(actor+0xef4,m.U32(actor+0xef4)&0x31f7e95c);m.Set32(actor+0x102c,0x4e6e6b28);m.Set32(actor+0xef8,m.U32(actor+0xef8)&0xfffffffc);uint savedEf0=m.U32(actor+0xef0);uint c=(ec&0x25fffc27)|8;bool created=(m.U32(actor+0x1f8)&0x400)!=0;m.Set32(actor+0xeec,ec);uint f4=m.U32(actor+0xef4);m.Set32(actor+0xf14,0);m.Set32(actor+0xeec,c);f4=created?f4&0xfffbffff:f4|0x40000;m.Set32(actor+0xef4,f4);m.Set32(actor+0x104c,0);m.Set32(actor+0x4b0,m.U32(actor+0x4b0)&0xefffffff);uint duration=w.DurationBits;m.Set32(actor+0x4b8,duration);uint f0=m.U32(actor+0x4b0);f0=m.F32(actor+0x4b8)>0?(f0&0xf7ffffff)|0x4000000:f0&0xf3ffffff;m.Set32(actor+0xef4,m.U32(actor+0xef4)&0xfe5fffff);c&=0xfff3ffff;m.SetFloat(actor+0xec8,1);m.Set32(actor+0x4b0,f0);m.Set32(actor+0xeec,c);c=(m.U32(metadata+4)&0x8000000)!=0?c|0x100000:c&0xffefffff;m.Set8(actor+0x7c5,m.U8(actor+0x7c5)&253);m.Set32(actor+0xec4,0);m.Set32(actor+0x4b0,m.U32(actor+0x4b0)&0xffffafff);m.Set32(actor+0x3a8,0x4e6e6b28);m.Set32(actor+0x3b8,0x4e6e6b28);m.Set32(actor+0x454,0);m.Set32(actor+0xeec,c);m.Set32(actor+0xeec,m.U32(actor+0xeec)&0xfadff7fe);m.Set32(actor+0xecc,0);m.Set32(actor+0xef0,savedEf0&0xfeffffff);
   foreach(uint at in new uint[]{0xec0,0x39c,0x3a4,0x3ac,0x3b4,0x2a8,0x2ac,0xeb0,0xeb4,0x10a4,0x10a8,0xeb8,0xebc})m.Set32(actor+at,0);for(uint j=0;j<0x68;j++)m.Set8(actor+0xf3c+j,0);metadata=m.U32(actor+0x54);m.Set8(actor+0x107d,0);foreach(uint at in new uint[]{0xfd8,0x3bc,0x298,0x2a0,0x2a4})m.Set32(actor+at,0);bool special=(m.U32(metadata+4)&0x4000)!=0&&(m.U8(actor+0x280)==255||m.U32(actor+0xcd0)!=0);m.Set32(actor+0x1fc,special?m.U32(actor+0x1fc)|2:m.U32(actor+0x1fc)&0xfffffffd);uint data=m.U32(metadata+0x24);m.Set32(actor+0xef0,(m.U32(data+0x90)&0x2000)!=0?m.U32(actor+0xef0)|0x80000000:m.U32(actor+0xef0)&0x7fffffff);m.Set32(actor+0x1fc,m.U32(actor+0x1fc)&0xffe7f7ff);m.Set32(actor+0xef4,m.U32(actor+0xef4)&0xfffffffb);m.SetFloat(actor+0x1034,1);m.Set32(actor+0xef0,m.U32(actor+0xef0)&0xfbbfffff);m.Set32(actor+0xef8,m.U32(actor+0xef8)&0xfffffff3);m.Set32(actor+0x1038,0);m.Set32(actor+0x10b4,0);m.Set8(actor+0x1083,0);m.Set32(actor+0x10cc,0);PathReset(w,actor);
  }
 }
}
