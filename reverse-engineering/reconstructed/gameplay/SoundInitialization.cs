using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 //Virtual byte images replace process pointers. No native memory is accessed.
 public sealed class SoundSetupImage
 {
  public readonly SortedDictionary<uint,byte[]> Regions=new SortedDictionary<uint,byte[]>();
  byte[] At(uint address,out int offset){foreach(var r in Regions)if(address>=r.Key&&(ulong)address-r.Key<(ulong)r.Value.Length){offset=(int)(address-r.Key);return r.Value;}throw new ArgumentException("Unmapped sound image address.");}
  public byte Byte(uint address){int o;return At(address,out o)[o];}
  public void Byte(uint address,byte value){int o;At(address,out o)[o]=value;}
  public uint Word(uint address){return (uint)(Byte(address)|Byte(address+1)<<8|Byte(address+2)<<16|Byte(address+3)<<24);}
  public void Word(uint address,uint value){for(int i=0;i<4;i++)Byte(address+(uint)i,(byte)(value>>(i*8)));}
  public void Half(uint address,ushort value){Byte(address,(byte)value);Byte(address+1,(byte)(value>>8));}
  public ushort Half(uint address){return (ushort)(Byte(address)|Byte(address+1)<<8);}
  public void Zero(uint address,uint count){for(uint i=0;i<count;i++)Byte(address+i,0);}
  public void Copy(uint target,uint source,uint count){if(target<source){for(uint i=0;i<count;i++)Byte(target+i,Byte(source+i));}else for(uint i=count;i>0;i--)Byte(target+i-1,Byte(source+i-1));}
  public void CopyString(uint target,uint source){byte b;do{b=Byte(source++);Byte(target++,b);}while(b!=0);}
 }
 public static class SoundInitialization
 {
  static uint Reserve(SoundSetupImage m,uint cursor,uint size){uint p=unchecked(m.Word(cursor)+3)&0xfffffffcu;m.Word(cursor,unchecked(p+size));return p;}
  //0x6521b0. Valid capacities, disjoint globals/arena/cursor and terminated strings.
  //Configuration parsing/bank loading at6520b0 remains an explicit mutable service.
  public static void Initialize(SoundSetupImage m,uint cursor,uint opaque,uint path,Action<SoundSetupImage,uint,uint,uint> loadConfiguration)
  {
   m.Word(0x292fda0,Reserve(m,cursor,0x200));
   m.Word(0x2947d70,Reserve(m,cursor,0xaf00));m.Zero(m.Word(0x2947d70),0xaf00);
   m.Word(0x2947b74,Reserve(m,cursor,0x19000));m.Zero(m.Word(0x2947b74),0x19000);
   m.Word(0x292fda4,Reserve(m,cursor,0x19000));m.Zero(m.Word(0x292fda4),0x19000);
   if(m.Word(0x2962044)==0)
   {
    var state=new SoundHashTableState();uint arena=m.Word(cursor);SoundHashInitialization.Initialize(state,ref arena);
    m.Word(0x2947d80,state.TableOffset);m.Word(cursor,arena);for(uint i=0;i<256;i++)m.Word(state.TableOffset+i*4,state.Table[i]);m.Word(0x2962044,1);
   }
   for(uint i=0;i<0x200;i+=2)m.Half(m.Word(0x292fda0)+i,0xffff);
   m.Word(0x2962014,0);m.Word(0x296201c,0);uint index=0,offset=0,name=0x2948f10;
   while(unchecked((int)index)<unchecked((int)m.Word(0x296202c)))
   {
    uint from=m.Word(0x2962028)+offset,to=m.Word(0x2947d70)+offset;
    for(uint i=0;i<7;i++)m.Word(to+i*4,m.Word(from+i*4));
    m.Word(m.Word(0x2947d70)+offset+12,index);m.CopyString(name,m.Word(m.Word(0x2947d70)+offset));
    m.Word(0x2962014,unchecked(m.Word(0x2962014)+1));m.Word(0x2962018,unchecked(m.Word(0x2962018)+1));m.Word(m.Word(0x2947d70)+offset,name);
    index++;offset+=0x1c;name+=0x40;
   }
   uint terminal=m.Word(0x2947d70)+index*0x1c;m.Word(terminal,0);m.Word(terminal+4,0);m.Word(terminal+8,0);m.Word(terminal+12,0xffffffff);
   m.CopyString(0x810368,path);loadConfiguration(m,path,cursor,opaque);
   m.Zero(0x2947ca8,200);int count=unchecked((int)m.Word(0x296201c));uint sound=m.Word(0x2947b74)+4;
   for(int i=0;i<count;i++,sound+=0x40)
   {
    uint flags=m.Word(sound);if((flags&0x20000)==0)continue;int id=unchecked((int)(flags<<17))>>17;uint target=unchecked(0x2947ca8u+(uint)((id>>4)*2));m.Half(target,(ushort)(m.Half(target)|(1<<(id&15))));
   }
   m.Copy(0x2921760,0x2947ca8,200);
  }
 }
}
