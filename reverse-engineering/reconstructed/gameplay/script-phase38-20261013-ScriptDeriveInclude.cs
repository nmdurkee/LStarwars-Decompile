// DERIVEFROMSCRIPT statement and INCLUDE orchestration; filesystem lifecycle services explicit.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptIncludeServices
 {
  public abstract void Suspend(TakeoverReleaseMemory m,uint parser);
  public abstract void Parse(TakeoverReleaseMemory m,uint output,uint context,uint fileName,uint archive,uint top,uint bottom);
  public abstract void Resume(TakeoverReleaseMemory m,uint parser);
 }
 public static class PreparedScriptDeriveInclude
 {
  static byte Fold(byte c){return c>=97&&c<=122||c>=224?unchecked((byte)(c-32)):c;}
  static uint Find(TakeoverReleaseMemory m,uint text,uint key){string a=PreparedConditionLoading.Text(m,text),b=PreparedConditionLoading.Text(m,key);for(int i=0;i+b.Length<=a.Length;i++){bool equal=true;for(int j=0;j<b.Length;j++)if(Fold((byte)a[i+j])!=Fold((byte)b[j])){equal=false;break;}if(equal)return unchecked(text+(uint)i);}return 0;}
  static uint Name(ConditionParserMemory m,ScriptConditionMaterializationServices s,uint text,uint top,uint bottom){uint size=(uint)PreparedConditionLoading.Text(m,text).Length;if(size==0)return 0;size++;uint p=0;if(top!=0&&bottom!=0&&unchecked(m.Read32(top)+size)<m.Read32(bottom)){p=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(p+size));for(uint i=0;i<size;i++)m.Write8(p+i,0);}else s.Diagnostic(m,0x512850,new uint[0]);for(uint i=0;i<4096;i++){byte c=m.Read8(text+i);m.Write8(p+i,c);if(c==0)return p;}throw new ArgumentException("Bounded parent script operand required.");}
  public static void Derive(ConditionParserMemory m,ScriptConditionMaterializationServices s,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   uint script=m.Read32(0x92221c);if(script==0||m.Read32(script+0xc)!=0)return;m.Write32(script+0x3c,m.Read32(script+0x3c)&0xfffffffbu);uint budget=0;bool stop=false;while(!stop&&s.NextLine(m,parser)!=0){while(ScriptTokenResults.Next(m.Image,parser,binary)!=0){if(++budget>65536)throw new ArgumentException("Bounded derivation block required.");uint text=m.Read32(parser+0x510);if(TextParserDispatch.Compare(m.Image,text,0x75ff74)==0){stop=true;break;}uint found=Find(m,text,0x75fff0);if(found!=0){uint bottom=m.Read32(0x922218),top=m.Read32(0x922214);uint parent=Name(m,s,unchecked(found+7),top,bottom);m.Write32(m.Read32(0x92221c)+0xc,parent);continue;}if(Find(m,m.Read32(parser+0x510),0x75ffe8)!=0){script=m.Read32(0x92221c);uint flags=m.Read32(script+0x3c);if(Find(m,m.Read32(parser+0x510),0x75ffe0)!=0)m.Write32(script+0x3c,flags&0xfffffffbu);else if(Find(m,m.Read32(parser+0x510),0x755d8c)!=0)m.Write32(m.Read32(0x92221c)+0x3c,m.Read32(m.Read32(0x92221c)+0x3c)|4);}}}script=m.Read32(0x92221c);if(m.Read32(script+0xc)!=0)m.Write32(script+0x3c,m.Read32(script+0x3c)|2);
  }
  public static void Include(ConditionParserMemory m,ScriptIncludeServices s,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   uint bottom=m.Read32(0x922218),script=m.Read32(0x92221c),top=m.Read32(0x922214);ScriptTokenResults.Next(m.Image,parser,binary);s.Suspend(m,parser);uint b=m.Read32(0x922218),t=m.Read32(0x922214),archive=m.Read32(0x92223c),name=m.Read32(parser+0x510),context=m.Read32(0x922240);s.Parse(m,0x92221c,context,name,archive,t,b);s.Resume(m,parser);m.Write32(0x922214,top);m.Write32(0x92221c,script);m.Write32(0x922218,bottom);
  }
 }
 public sealed class RecoveredScriptDeriveIncludeCommands:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly ScriptIncludeServices include;readonly RecoveredTextConditionServices readers;readonly Func<SoundSetupImage,uint,uint> binary;
  public RecoveredScriptDeriveIncludeCommands(ScriptFileTransportServices ports,ScriptIncludeServices includes,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine,Func<SoundSetupImage,uint,uint> binaryToken){if(ports==null||includes==null)throw new ArgumentNullException("ports/includes");remaining=ports;include=includes;binary=binaryToken;readers=new RecoveredTextConditionServices(readFile,binaryLine,binaryToken==null?null:(Action<SoundSetupImage,uint>)delegate(SoundSetupImage m,uint p){binaryToken(m,p);},Diagnostic);}
  public override uint Open(TakeoverReleaseMemory m,uint a,uint b,uint c){return remaining.Open(m,a,b,c);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint callback,uint parser){if(callback!=0x513820&&callback!=0x52bf80){remaining.Command(m,callback,parser);return;}ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");if(callback==0x513820)PreparedScriptDeriveInclude.Derive(image,readers,parser,binary);else PreparedScriptDeriveInclude.Include(image,include,parser,binary);}
 }
}
