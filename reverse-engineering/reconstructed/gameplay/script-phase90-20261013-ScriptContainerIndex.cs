// Byte path normalization, flat container cache/name index and registered provider prefix routing.
using System;
using System.Text;
namespace Recovered.Gameplay
{
 public static class PreparedScriptContainerIndex
 {
  static uint Length(TakeoverReleaseMemory m,uint p){uint z=0;while(m.Read8(p+z)!=0){if(z++>=4096)throw new ArgumentException("Prepared bounded byte string required.");}return z;}
  //4efdf0 cdecl(context,path); separator snapshot and optional ASCII uppercase.
  public static void Normalize(TakeoverReleaseMemory m,uint context,uint path)
  {byte separator=context==0?(byte)92:m.Read8(context+16);bool preserve=m.Read32(0x91ee84)!=0;uint count=0;for(uint p=path;m.Read8(p)!=0;p=unchecked(p+1)){if(count++>=4096)throw new ArgumentException("Prepared bounded path required.");byte c=m.Read8(p);if(c==47||c==92)m.Write8(p,separator);else if(!preserve&&c>=97&&c<=122)m.Write8(p,(byte)(c-32));}}
  //4f76f0 cdecl(container,path), hash-only hit precedence then byte-exact packed names.
  public static uint Flat(TakeoverReleaseMemory m,uint container,uint path)
  {
   uint hash=0x811c9dc5;for(uint p=path;m.Read8(p)!=0;p=unchecked(p+1))hash=unchecked((hash^(uint)(int)(sbyte)m.Read8(p))*0x199933);
   int count=unchecked((int)m.Read32(container+4));if(count>0){uint hashes=m.Read32(container+0x1c);for(int i=0;i<count;i++)if(m.Read32(hashes+(uint)i*4)==hash)return (uint)i;}
   int additional=unchecked((int)m.Read32(container+0x20));if(additional==0)return 0xffffffff;uint name=m.Read32(container+0x28);if(additional<0)return 0xffffffff;
   for(int i=0;i<additional;i++)
   {
    uint offset=0;bool equal=true;while(true){byte a=m.Read8(name+offset),b=m.Read8(path+offset);if(a!=b){equal=false;break;}offset++;if(a==0)break;}
    uint length=Length(m,name);if(equal){uint index=unchecked(name+length+1);if((index&1)!=0)index++;return unchecked((uint)(int)(short)(m.Read8(index)|(m.Read8(index+1)<<8)));}
    name=unchecked(name+length+3);if((name&1)!=0)name++;
   }
   return 0xffffffff;
  }
  static string Ascii(TakeoverReleaseMemory m,uint p){StringBuilder s=new StringBuilder();for(uint i=0;i<4096;i++){byte c=m.Read8(p+i);if(c==0)return s.ToString();if(c>127)throw new ArgumentException("Prepared ASCII provider names required.");s.Append((char)c);}throw new ArgumentException("Prepared bounded provider name required.");}
  //4f98c0 cdecl(path). Registered ASCII projection4f8b80 reused without duplicate address credit.
  public static uint Provider(TakeoverReleaseMemory m,uint path)
  {
   uint colon=0;while(colon<8&&m.Read8(path+colon)!=58)colon++;if(colon==8)return 0;int count=unchecked((int)m.Read32(0x297e064));for(int i=0;i<count;i++){uint name=unchecked(0x2980414+(uint)i*0x234);if(RandomSplineSelection.Compare(Ascii(m,path),Ascii(m,name),unchecked((int)m.Read32(name+16)))==0)return unchecked(0x29803e0+(uint)i*0x234);}return 0;
  }
 }
}
