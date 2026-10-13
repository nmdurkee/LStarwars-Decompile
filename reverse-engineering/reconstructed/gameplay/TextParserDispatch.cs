using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public static class TextParserDispatch
 {
  static sbyte Fold(byte value){if((byte)(value+0x9f)<26||value>0xdf)value=(byte)(value-0x20);return unchecked((sbyte)value);}
  //0x4f8b10: byte folding includes e0..ff; ordering uses signed chars.
  public static int Compare(SoundSetupImage m,uint first,uint second)
  {
   if(first==0)return -1;if(second==0)return 1;
   while(true){sbyte a=Fold(m.Byte(first++)),b=Fold(m.Byte(second++));if(a>b)return 1;if(a<b)return -1;if(a==0||b==0)return 0;}
  }
  static byte Narrow(ushort c){if((c&0xff00)==0)return(byte)c;switch(c){case 0x2019:return 0x92;case 0x2013:return 0x96;case 0x2018:return 0x91;case 0x2026:return 0x85;case 0x2122:return 0x99;default:return 63;}}
  //0x4f2dc0: small explicit UTF16-to-byte conversion, not a general encoding.
  public static void ToBytes(SoundSetupImage m,uint target,uint source)
  {
   if(target==0||source==0)return;m.Byte(target,0);uint i=0;ushort c;
   while((c=m.Half(source+i*2))!=0){m.Byte(target+i,Narrow(c));i++;}m.Byte(target+i,0);
  }
  static bool Equal(SoundSetupImage m,uint first,byte[] token)
  {
   for(uint i=0;;i++){sbyte a=Fold(m.Byte(first+i)),b=Fold(token[i]);if(a!=b)return false;if(a==0)return true;}
  }
  static bool Table(SoundSetupImage m,uint table,byte[] token,uint parser,Action<SoundSetupImage,uint,uint> invoke)
  {
   for(uint at=table;m.Word(at)!=0;at+=8)if(Equal(m,m.Word(at),token)){invoke(m,m.Word(at+4),parser);return true;}return false;
  }
  //0x4fa020. Token snapshot precedes ordered primary/secondary/fallback dispatch.
  //Names fit the original64-byte local; null wide token is outside native defined domain.
  public static void Dispatch(SoundSetupImage m,uint parser,Action<SoundSetupImage,uint,uint> invoke)
  {
   uint source=m.Word(parser+0x510);bool wide=m.Byte(parser+0x578)!=0;var bytes=new List<byte>();
   if(wide){if(source==0)throw new ArgumentException("Native wide-token local would be uninitialized.");for(uint i=0;m.Half(source+i*2)!=0;i++)bytes.Add(Narrow(m.Half(source+i*2)));}
   else if(source!=0)for(uint i=0;m.Byte(source+i)!=0;i++)bytes.Add(m.Byte(source+i));
   if(bytes.Count>=64)throw new ArgumentException("Native command-token local capacity exceeded.");bytes.Add(0);byte[] token=bytes.ToArray();if(token[0]==0||token[0]==59)return;
   int depth=unchecked((int)m.Word(parser+0x570));if(depth>=0)
   {
    if(Table(m,m.Word(parser+0x530+(uint)depth*4),token,parser,invoke))return;
    uint secondary=m.Word(parser+0x550+(uint)depth*4);if(secondary!=0&&Table(m,secondary,token,parser,invoke))return;
   }
   uint fallback=m.Word(0x91eec4);if(fallback!=0)invoke(m,fallback,parser);
  }
 }
}
