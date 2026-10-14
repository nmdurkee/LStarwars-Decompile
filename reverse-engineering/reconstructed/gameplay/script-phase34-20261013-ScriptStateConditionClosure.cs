// Replace state CONDITIONS callback with recovered raw condition production on the shared parser image.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptConditionCommands:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly ScriptExpressionServices symbols;readonly RecoveredTextConditionServices readers;
  public RecoveredScriptConditionCommands(ScriptFileTransportServices ports,ScriptExpressionServices expressionSymbols,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine,Action<SoundSetupImage,uint> binaryToken){if(ports==null||expressionSymbols==null)throw new ArgumentNullException("ports/expressionSymbols");remaining=ports;symbols=expressionSymbols;readers=new RecoveredTextConditionServices(readFile,binaryLine,binaryToken,Diagnostic);}
  public override uint Open(TakeoverReleaseMemory m,uint a,uint b,uint c){return remaining.Open(m,a,b,c);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint callback,uint parser){if(callback!=0x52b3f0){remaining.Command(m,callback,parser);return;}ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");PreparedTextConditionMaterialization.Load(image,readers,symbols,parser);}
 }
}
