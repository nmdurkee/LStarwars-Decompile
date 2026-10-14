// Condition macro and reference-block producers, preserving inline operand extraction and rollback.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptMacroReferences
 {
  static byte Fold(byte c){return c>=97&&c<=122||c>=224?unchecked((byte)(c-32)):c;}
  static uint Find(TakeoverReleaseMemory m,uint text,uint key){string a=PreparedConditionLoading.Text(m,text),b=PreparedConditionLoading.Text(m,key);for(int i=0;i+b.Length<=a.Length;i++){bool equal=true;for(int j=0;j<b.Length;j++)if(Fold((byte)a[i+j])!=Fold((byte)b[j])){equal=false;break;}if(equal)return unchecked(text+(uint)i);}return 0;}
  static void Zero(TakeoverReleaseMemory m,uint p,uint count){for(uint i=0;i<count;i++)m.Write8(p+i,0);}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  static uint Operand(ConditionParserMemory m,ScriptConditionMaterializationServices s,uint source,uint top,uint bottom){uint size=(uint)PreparedConditionLoading.Text(m,source).Length;if(size==0)return 0;size++;uint p=0;if(top!=0&&bottom!=0&&unchecked(m.Read32(top)+size)<m.Read32(bottom)){p=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(p+size));Zero(m,p,size);}else s.Diagnostic(m,0x512850,new uint[0]);for(uint i=0;i<4096;i++){byte c=m.Read8(source+i);m.Write8(p+i,c);if(c==0)return p;}throw new ArgumentException("Bounded reference operand required.");}
  public static void ConditionMacro(ConditionParserMemory m,ScriptConditionMaterializationServices s,ScriptExpressionServices symbols,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   if(ScriptTokenResults.Next(m.Image,parser,binary)==0)return;uint top=m.Read32(0x922214);if(top==0){s.Diagnostic(m,0x512850,new uint[0]);return;}uint bottom=m.Read32(0x922218);if(bottom==0||unchecked(m.Read32(top)+0x14)>=m.Read32(bottom)){s.Diagnostic(m,0x512850,new uint[0]);return;}uint macro=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(macro+0x14));Zero(m,macro,0x14);if(macro==0)return;Zero(m,macro,0x14);uint name=PreparedConditionLoading.CopyString(m,top,m.Read32(parser+0x510),bottom);m.Write32(macro+8,name);Append(m,unchecked(m.Read32(0x92221c)+0x48),macro);m.Write32(0x922230,macro+0xc);m.Write32(0x922238,1);PreparedConditionMaterialization.Load(m,s,symbols,parser);m.Write32(0x922230,0);m.Write32(0x922238,0);
  }
  public static void Reference(ConditionParserMemory m,ScriptConditionMaterializationServices s,ScriptExpressionServices symbols,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   if(m.Read32(0x92222c)==0)return;uint top=m.Read32(0x922214),bottom=m.Read32(0x922218),original=m.Read32(top);if(bottom==0||unchecked(original+0x24)>=m.Read32(bottom)){s.Diagnostic(m,0x512850,new uint[0]);return;}uint node=unchecked(original+15)&0xfffffff0;m.Write32(top,unchecked(node+0x24));Zero(m,node,0x24);if(node==0)return;Zero(m,node,0x24);uint budget=0;bool stop=false;
   while(!stop&&s.NextLine(m,parser)!=0){uint tokenBudget=0;while(ScriptTokenResults.Next(m.Image,parser,binary)!=0){if(++budget>65536||++tokenBudget>4096)throw new ArgumentException("Bounded reference block required.");uint text=m.Read32(parser+0x510);if(TextParserDispatch.Compare(m.Image,text,0x75ff74)==0){stop=true;break;}uint found=Find(m,text,0x75fff0);if(found!=0){uint b=m.Read32(0x922218),t=m.Read32(0x922214);uint value=Operand(m,s,unchecked(found+7),t,b);m.Write32(node+8,value);continue;}found=Find(m,m.Read32(parser+0x510),0x76042c);if(found!=0){uint b=m.Read32(0x922218),t=m.Read32(0x922214);uint value=Operand(m,s,unchecked(found+0xc),t,b);m.Write32(node+0x10,value);continue;}if(TextParserDispatch.Compare(m.Image,m.Read32(parser+0x510),0x75ff90)==0){m.Write32(0x922230,node+0x1c);m.Write32(0x922238,1);PreparedConditionMaterialization.Load(m,s,symbols,parser);m.Write32(0x922230,0);m.Write32(0x922238,0);continue;}if(Find(m,m.Read32(parser+0x510),0x75ffe8)!=0){if(Find(m,m.Read32(parser+0x510),0x75ffe0)!=0)m.Write32(node+0x18,m.Read32(node+0x18)|1);else if(Find(m,m.Read32(parser+0x510),0x755d8c)!=0)m.Write32(node+0x18,m.Read32(node+0x18)|2);}}}
   if(m.Read32(node+8)!=0){uint flags=m.Read32(node+0x18);if((flags&3)==0)m.Write32(node+0x18,flags|3);Append(m,m.Read32(0x92222c),node);return;}s.Diagnostic(m,0x512860,new uint[0]);m.Write32(m.Read32(0x922214),original);
  }
 }
 public sealed class RecoveredScriptMacroReferenceCommands:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly ScriptExpressionServices symbols;readonly RecoveredTextConditionServices readers;readonly Func<SoundSetupImage,uint,uint> binary;
  public RecoveredScriptMacroReferenceCommands(ScriptFileTransportServices ports,ScriptExpressionServices expressionSymbols,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine,Func<SoundSetupImage,uint,uint> binaryToken){if(ports==null||expressionSymbols==null)throw new ArgumentNullException("ports/expressionSymbols");remaining=ports;symbols=expressionSymbols;binary=binaryToken;readers=new RecoveredTextConditionServices(readFile,binaryLine,binaryToken==null?null:(Action<SoundSetupImage,uint>)delegate(SoundSetupImage m,uint p){binaryToken(m,p);},Diagnostic);}
  public override uint Open(TakeoverReleaseMemory m,uint a,uint b,uint c){return remaining.Open(m,a,b,c);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint callback,uint parser){if(callback!=0x52bdf0&&callback!=0x52c000){remaining.Command(m,callback,parser);return;}ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");if(callback==0x52bdf0)PreparedScriptMacroReferences.ConditionMacro(image,readers,symbols,parser,binary);else PreparedScriptMacroReferences.Reference(image,readers,symbols,parser,binary);}
 }
}
