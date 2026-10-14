// Action table identity, bank byte arrays and deep action-list copying.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptActionPrimitives
 {
  static void Zero(TakeoverReleaseMemory m,uint p,uint size){for(uint i=0;i<size;i++)m.Write8(unchecked(p+i),0);}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  //512f00 customEDI=name, no stack arguments; custom12-byte descriptors before8019c0.
  public static uint FindAction(TakeoverReleaseMemory m,uint name){uint table=m.Read32(0x922228);if(table!=0){uint row=table,budget=0;while(m.Read32(row)!=0){if(++budget>4096)throw new ArgumentException("Bounded action table required.");if(name!=0&&PreparedConditionLoading.Equal(m,name,m.Read32(row)))return row;row+=12;}}uint builtin=0x8019c0,remaining=0;while(m.Read32(builtin)!=0){if(++remaining>4096)throw new ArgumentException("Bounded builtin actions required.");if(name!=0&&PreparedConditionLoading.Equal(m,name,m.Read32(builtin)))return builtin;builtin+=12;}return 0;}
  //512e60 EAX=bottomPointer, ECX=byteSize, EDI=topPointer; zero-size still aligns if admitted.
  public static uint AllocateBytes(TakeoverReleaseMemory m,uint top,uint bottom,uint size){if(top==0||bottom==0)return 0;if(unchecked(m.Read32(top)+size)>=m.Read32(bottom))return 0;uint p=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(p+size));Zero(m,p,size);return p;}
  public static void SetActions(TakeoverReleaseMemory m,uint table){m.Write32(0x922228,table);uint row=table,count=0;while(m.Read32(row)!=0){if(count>=4096)throw new ArgumentException("Bounded custom action rows required.");m.Write16(row+10,(ushort)count++);m.Write8(row+9,1);row+=12;}row=0x8019c0;count=0;while(m.Read32(row)!=0){if(count>=4096)throw new ArgumentException("Bounded builtin action rows required.");m.Write16(row+10,(ushort)count++);m.Write8(row+9,0);row+=12;}}
  public static void SetPredicates(TakeoverReleaseMemory m,uint table){m.Write32(0x922224,table);}
  static uint CopyToken(TakeoverReleaseMemory m,Action<TakeoverReleaseMemory,uint,uint[]> diag,uint top,uint bottom,uint source){if(source==0)return 0;uint size=(uint)PreparedConditionLoading.Text(m,source).Length;if(size==0)return 0;size++;uint target=0;if(unchecked(m.Read32(top)+size)<m.Read32(bottom)){target=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(target+size));Zero(m,target,size);}else if(diag!=null)diag(m,0x512850,new uint[0]);for(uint i=0;i<4096;i++){byte c=m.Read8(source+i);m.Write8(target+i,c);if(c==0)return target;}throw new ArgumentException("Bounded copied action token required.");}
  //513b30 cdecl(sourceList,destinationList,topPointer,bottomPointer). Descriptor10 remains shallow.
  public static void CopyActions(TakeoverReleaseMemory m,Action<TakeoverReleaseMemory,uint,uint[]> diag,uint source,uint destination,uint top,uint bottom)
  {
   uint node=m.Read32(source),budget=0;while(node!=0){if(++budget>4096)throw new ArgumentException("Bounded disjoint action list required.");if(top==0||bottom==0||unchecked(m.Read32(top)+0x14)>=m.Read32(bottom)){if(diag!=null)diag(m,0x512850,new uint[0]);node=m.Read32(node);continue;}uint copy=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(copy+0x14));Zero(m,copy,0x14);if(copy!=0){uint size=unchecked(m.Read32(node+12)*4),array=0;if(unchecked(m.Read32(top)+size)<m.Read32(bottom)){array=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(array+size));Zero(m,array,size);}else if(diag!=null)diag(m,0x512850,new uint[0]);m.Write32(copy+8,array);m.Write32(copy+12,m.Read32(node+12));for(uint i=0;unchecked((int)i)<unchecked((int)m.Read32(copy+12));i++){uint token=m.Read32(unchecked(m.Read32(node+8)+i*4));uint text=CopyToken(m,diag,top,bottom,token);m.Write32(unchecked(m.Read32(copy+8)+i*4),text);}m.Write32(copy+16,m.Read32(node+16));Append(m,destination,copy);}node=m.Read32(node);}
  }
 }
}
