// Raw file body and program loop; parser transport and token-dispatch services remain explicit.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public abstract class ScriptFileBodyServices
 {
  public abstract uint Open(TakeoverReleaseMemory m,uint archive,uint context,uint fileName);
  public abstract void Close(TakeoverReleaseMemory m,uint parser);
  public abstract void PushTable(TakeoverReleaseMemory m,uint parser,uint table);
  public abstract uint NextLine(TakeoverReleaseMemory m,uint parser);
  public abstract void NextToken(TakeoverReleaseMemory m,uint parser);
  public abstract void Dispatch(TakeoverReleaseMemory m,uint parser);
  public virtual void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){}
 }
 public static class PreparedScriptFileBody
 {
  static byte Fold(byte c){return c>=97&&c<=122||c>=224?unchecked((byte)(c-32)):c;}
  static uint CopyName(TakeoverReleaseMemory m,uint top,uint bottom,byte[] name)
  {
   if(name.Length==0)return 0;uint size=(uint)name.Length+1,destination=0;
   if(top!=0&&bottom!=0&&unchecked(m.Read32(top)+size)<m.Read32(bottom)){destination=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(destination+size));for(uint i=0;i<size;i++)m.Write8(destination+i,0);}
   for(uint i=0;i<name.Length;i++)m.Write8(destination+i,name[i]);m.Write8(destination+(uint)name.Length,0);return destination;
  }
  //52bcb0 cdecl(outputPointer,context,fileName,archive,topPointer,bottomPointer), void projection.
  public static void Parse(TakeoverReleaseMemory m,ScriptFileBodyServices s,uint output,uint context,uint fileName,uint archive,uint top,uint bottom)
  {
   uint parser=s.Open(m,archive,context,fileName);if(parser==0){s.Diagnostic(m,m.Read32(0x922248)==1?0x512860u:0x512850u,new uint[]{fileName});return;}
   if(m.Read32(output)==0){uint script=0;if(top!=0&&bottom!=0&&unchecked(m.Read32(top)+0x58)<m.Read32(bottom)){script=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(script+0x58));for(uint i=0;i<0x58;i++)m.Write8(script+i,0);}else s.Diagnostic(m,0x512850,new uint[0]);m.Write32(output,script);
    if(script!=0){for(uint i=0;i<0x58;i++)m.Write8(script+i,0);var name=new List<byte>();for(uint i=0;i<64;i++){byte c=m.Read8(fileName+i);if(c==0)break;if(i==63)throw new ArgumentException("Filename must fit the native 64-byte local.");name.Add(c);}byte[] full=name.ToArray();for(int i=0;i+4<=full.Length;i++){if(Fold(full[i])==(byte)'.'&&Fold(full[i+1])==(byte)'S'&&Fold(full[i+2])==(byte)'C'&&Fold(full[i+3])==(byte)'P'){name.RemoveRange(i,name.Count-i);break;}}uint copy=CopyName(m,top,bottom,name.ToArray());m.Write32(m.Read32(output)+8,copy);}
   }
   Populate(m,s,parser,m.Read32(output),top,bottom);s.Close(m,parser);
  }
  //5137a0 custom EAX=top, ECX=bottom, ESI=parser; cdecl(script). Null script leaves allglobals untouched.
  public static void Populate(TakeoverReleaseMemory m,ScriptFileBodyServices s,uint parser,uint script,uint top,uint bottom)
  {
   if(script==0)return;m.Write32(0x922214,top);m.Write32(0x922218,bottom);m.Write32(0x92221c,script);m.Write32(0x922244,0);s.PushTable(m,parser,0x801720);uint line=s.NextLine(m,parser),budget=0;while(line!=0){if(++budget>65536)throw new ArgumentException("Bounded script line stream required.");s.NextToken(m,parser);m.Write32(0x92222c,unchecked(script+0x40));s.Dispatch(m,parser);line=s.NextLine(m,parser);}m.Write32(0x922214,0);m.Write32(0x922218,0);m.Write32(0x92221c,0);m.Write32(0x92222c,0);
  }
 }
}
