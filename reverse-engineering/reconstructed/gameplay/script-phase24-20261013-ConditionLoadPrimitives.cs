// Script condition loader prerequisites: raw definition tables, bank strings, target tail.
using System;
using System.Text;
namespace Recovered.Gameplay
{
 public abstract class ScriptConditionLoadServices
 {
  public abstract void NextToken(TakeoverReleaseMemory m,uint parser);
  public abstract void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments);
 }
 public static class PreparedConditionLoading
 {
  public static string Text(TakeoverReleaseMemory m,uint p){var s=new StringBuilder();for(uint i=0;i<4096;i++){byte c=m.Read8(unchecked(p+i));if(c==0)return s.ToString();s.Append((char)c);}throw new ArgumentException("Bounded NUL text required.");}
  static byte Fold(byte c){return c>=97&&c<=122||c>=224?unchecked((byte)(c-32)):c;}
  public static bool Equal(TakeoverReleaseMemory m,uint a,uint b){for(uint i=0;i<4096;i++){byte x=m.Read8(unchecked(a+i)),y=m.Read8(unchecked(b+i));if(Fold(x)!=Fold(y))return false;if(x==0)return true;}throw new ArgumentException("Bounded NUL comparison required.");}
  //512ea0 customEDI=name, no stackargs. Custom12-byte descriptor table precedes native builtin801768.
  public static uint FindPredicate(TakeoverReleaseMemory m,uint name){uint table=m.Read32(0x922224);if(table!=0){uint row=table;while(m.Read32(row)!=0){if(Equal(m,name,m.Read32(row)))return row;row+=12;if(row-table>12288)throw new ArgumentException("Bounded descriptor table required.");}}uint entry=0x801768;while(m.Read32(entry)!=0){if(Equal(m,name,m.Read32(entry)))return entry;entry+=12;if(entry-0x801768>12288)throw new ArgumentException("Bounded builtin descriptor table required.");}return 0;}
  //513100 customEDI=topPointer, cdecl(text,bottomPointer). Checks UNALIGNED top+size strictly belowbottom.
  public static uint CopyString(TakeoverReleaseMemory m,uint topPointer,uint text,uint bottomPointer)
  {
   uint destination=0;if(text==0)return 0;uint length=(uint)Text(m,text).Length;if(length==0)return 0;uint size=length+1;if(topPointer!=0&&bottomPointer!=0&&unchecked(m.Read32(topPointer)+size)<m.Read32(bottomPointer)){destination=unchecked(m.Read32(topPointer)+15)&0xfffffff0;m.Write32(topPointer,unchecked(destination+size));for(uint i=0;i<size;i++)m.Write8(unchecked(destination+i),0);}
   // Native callsstrcpy evenwhenallocationfailed. Valid mappedmemory/fault policies belongtocaller.
   for(uint i=0;i<4096;i++){byte c=m.Read8(unchecked(text+i));m.Write8(unchecked(destination+i),c);if(c==0)return destination;}throw new ArgumentException("Bounded copiedtext required.");
  }
  //5132f0 customESI=parser, cdecl(condition). NextToken effects remain explicituntilrawfile transport hydration.
  public static void Finish(TakeoverReleaseMemory m,ScriptConditionLoadServices s,uint parser,uint condition)
  {
   s.NextToken(m,parser);if(Equal(m,m.Read32(parser+0x510),0x75ffc8)){m.Write16(condition+0xe,(ushort)(m.Read16(condition+0xe)&0xfffd));s.NextToken(m,parser);uint bottom=m.Read32(0x922218),text=m.Read32(parser+0x510),top=m.Read32(0x922214);uint copy=CopyString(m,top,text,bottom);m.Write32(condition+0x20,copy);s.NextToken(m,parser);if(Equal(m,m.Read32(parser+0x510),0x75ffb4))m.Write16(condition+0xe,(ushort)(m.Read16(condition+0xe)|2));return;}
   if(Equal(m,m.Read32(parser+0x510),0x75ffb0)){m.Write16(condition+0xe,(ushort)(m.Read16(condition+0xe)|1));return;}if(m.Read32(0x922238)!=0)return;uint mode=m.Read32(0x922248),state=m.Read32(0x922220);uint stateName=state==0?0x755ba8:m.Read32(state+0x18),line=m.Read32(parser+0x50c),script=m.Read32(0x92221c),scriptName=m.Read32(script+8);s.Diagnostic(m,mode==1?0x512860u:0x512850u,new uint[]{scriptName,stateName,line});
  }
 }
}
