// Native state producer: state/name bank, BASE prepend, nested state dispatch and table pop.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptStates
 {
  public static int PopTable(SoundSetupImage m,uint parser){int depth=unchecked((int)m.Word(parser+0x570));if(depth>=0)m.Word(parser+0x570,unchecked((uint)--depth));return depth;}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  static void Prepend(TakeoverReleaseMemory m,uint list,uint node){uint head=m.Read32(list);m.Write32(node,head);m.Write32(node+4,0);if(head!=0)m.Write32(head+4,node);else m.Write32(list+4,node);m.Write32(list,node);}
  //513540 cdecl(parser). Failed allocation leaves state0 and reference destination1c; no cleanup branch.
  public static void State(ConditionParserMemory m,ScriptFileBodyServices s,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   if(m.Read32(0x92221c)==0)return;if(ScriptTokenResults.Next(m.Image,parser,binary)==0)return;uint bottom=m.Read32(0x922218),top=m.Read32(0x922214),state=0;
   if(top!=0&&bottom!=0&&unchecked(m.Read32(top)+0x24)<m.Read32(bottom)){state=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(state+0x24));for(uint i=0;i<0x24;i++)m.Write8(state+i,0);}else s.Diagnostic(m,0x512850,new uint[0]);m.Write32(0x922220,state);m.Write32(0x92222c,unchecked(state+0x1c));if(state==0)return;
   for(uint i=0;i<0x24;i++)m.Write8(state+i,0);uint name=PreparedConditionLoading.CopyString(m,top,m.Read32(parser+0x510),bottom);m.Write32(m.Read32(0x922220)+0x18,name);uint current=m.Read32(0x922220),list=unchecked(m.Read32(0x92221c)+0x10);if(name!=0&&TextParserDispatch.Compare(m.Image,name,0x753270)==0)Prepend(m,list,current);else Append(m,list,current);
   TextParserTokens.PushTable(m.Image,parser,0x8016f4);uint line=s.NextLine(m,parser),budget=0;while(line!=0){if(++budget>65536)throw new ArgumentException("Bounded state line stream required.");s.NextToken(m,parser);uint live=m.Read32(0x922220);m.Write32(0x922230,unchecked(live+8));m.Write32(0x922234,unchecked(live+0x10));s.Dispatch(m,parser);line=s.NextLine(m,parser);}PopTable(m.Image,parser);m.Write32(0x92222c,0);m.Write32(0x922220,0);m.Write32(0x922230,0);m.Write32(0x922234,0);
  }
 }
 public sealed class RecoveredScriptStateCommands:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly Func<SoundSetupImage,uint,uint> binary;ScriptFileBodyServices body;
  public RecoveredScriptStateCommands(ScriptFileTransportServices ports,Func<SoundSetupImage,uint,uint> binaryToken){if(ports==null)throw new ArgumentNullException("ports");remaining=ports;binary=binaryToken;}
  public void Bind(ScriptFileBodyServices parser){if(parser==null)throw new ArgumentNullException("parser");body=parser;}
  public override uint Open(TakeoverReleaseMemory m,uint a,uint b,uint c){return remaining.Open(m,a,b,c);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint callback,uint parser){if(callback==0x5133f0){ConditionParserMemory end=m as ConditionParserMemory;if(end==null)throw new ArgumentException("Shared parser image required.");PreparedScriptStates.PopTable(end.Image,parser);return;}if(callback!=0x513540){remaining.Command(m,callback,parser);return;}if(body==null)throw new InvalidOperationException("State parser services not bound.");ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");PreparedScriptStates.State(image,body,parser,binary);}
 }
}
