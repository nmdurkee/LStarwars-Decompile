// Original32-slot texture pool ownership and finite integer accounting.
using System;
namespace Recovered.Geometry
{
 public sealed class TextureOwnerCpuState
 {
  public readonly byte[] Pool,Used;
  public uint AccountedBytes;
  public TextureOwnerCpuState(byte[] pool,byte[] used){Pool=pool;Used=used;}
 }
 public static class TextureOwnerCpu
 {
  const uint Base=0x986f00;
  static uint Read(byte[] b,int o){if(b==null||o<0||o>b.Length-4)throw new ArgumentException("Resolved texture owner bytes required.");return(uint)b[o]|(uint)b[o+1]<<8|(uint)b[o+2]<<16|(uint)b[o+3]<<24;}
  static void Write(byte[] b,int o,uint v){Read(b,o);b[o]=(byte)v;b[o+1]=(byte)(v>>8);b[o+2]=(byte)(v>>16);b[o+3]=(byte)(v>>24);}
  static uint Half(byte[] b,int o){return Read(b,o)&0xffff;}
  // Original5f7980 consumes EAX; its embedded jump table has ten entries.
  public static uint NativeFormat(uint value){switch(value){case 1:return 22;case 2:return 21;case 4:return 75;case 5:return 83;case 10:return 114;default:return uint.MaxValue;}}
  // Original5f79e0 consumes EAX; exact original byte/table dispatch.
  public static uint OwnerFormat(uint value){switch(value){case 21:case 22:return 2;case 75:return 4;case 83:return 5;default:return 0;}}
  // Whole5f7b40. Null keeps incoming EAX; non-pool pointers return 0x600.
  public static uint Free(TextureOwnerCpuState s,uint owner,uint incomingEax,Func<uint,uint> release)
  {
   if(owner==0)return incomingEax;uint offset=unchecked(owner-Base);if(offset>=0x600||offset%48!=0)return 0x600;
   if(s==null||s.Pool==null||s.Pool.Length<0x600||s.Used==null||s.Used.Length<32)throw new ArgumentException("Resolved original texture pool/usage globals required.");int at=(int)offset;
   // Reference field is tested once. Second object and accounting scalars are fresh.
   if(Read(s.Pool,at+0x2c)==uint.MaxValue){uint token=Read(s.Pool,at);if(token!=0){if(release==null)throw new ArgumentException("Final object Release required.");release(token);Write(s.Pool,at,0);}token=Read(s.Pool,at+0x28);if(token!=0){if(release==null)throw new ArgumentException("Final object Release required.");release(token);Write(s.Pool,at+0x28,0);}}
   uint width=Half(s.Pool,at+4),height=Half(s.Pool,at+6),levels=Half(s.Pool,at+10);int area=unchecked((int)(0u-width*height*4u));
   // Original FILD signed wrapped area times exact1.0/1.5, FISTP64 trunc.
   // All products fit53 significand bits; double multiplication is exact here.
   long delta=(long)((double)area*(levels==1?1.0:1.5));s.AccountedBytes=unchecked(s.AccountedBytes+(uint)delta);
   Array.Clear(s.Pool,at,48);s.Used[at/48]=0;return owner;
  }
 }
}
