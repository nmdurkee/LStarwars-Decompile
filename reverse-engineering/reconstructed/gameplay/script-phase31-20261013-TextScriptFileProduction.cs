// Attach complete existing text readers, table stack and ordered command dispatch to the raw program loop.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptFileTransportServices
 {
  public abstract uint Open(TakeoverReleaseMemory m,uint archive,uint context,uint fileName);
  public abstract void Close(TakeoverReleaseMemory m,uint parser);
  public abstract void Command(TakeoverReleaseMemory m,uint callback,uint parser);
  public virtual void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){}
 }
 public sealed class RecoveredTextScriptFileServices:ScriptFileBodyServices
 {
  readonly ScriptFileTransportServices ports;readonly RecoveredTextConditionServices readers;
  public RecoveredTextScriptFileServices(ScriptFileTransportServices leaves,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine,Action<SoundSetupImage,uint> binaryToken){if(leaves==null)throw new ArgumentNullException("leaves");ports=leaves;readers=new RecoveredTextConditionServices(readFile,binaryLine,binaryToken,delegate(TakeoverReleaseMemory m,uint c,uint[] a){ports.Diagnostic(m,c,a);});}
  static SoundSetupImage Image(TakeoverReleaseMemory m){ConditionParserMemory raw=m as ConditionParserMemory;if(raw==null)throw new ArgumentException("Shared parser image required.");return raw.Image;}
  public override uint Open(TakeoverReleaseMemory m,uint archive,uint context,uint name){return ports.Open(m,archive,context,name);}
  public override void Close(TakeoverReleaseMemory m,uint p){ports.Close(m,p);}
  public override void PushTable(TakeoverReleaseMemory m,uint p,uint t){TextParserTokens.PushTable(Image(m),p,t);}
  public override uint NextLine(TakeoverReleaseMemory m,uint p){return readers.NextLine(m,p);}
  public override void NextToken(TakeoverReleaseMemory m,uint p){readers.NextToken(m,p);}
  public override void Dispatch(TakeoverReleaseMemory m,uint p){TextParserDispatch.Dispatch(Image(m),p,delegate(SoundSetupImage image,uint callback,uint parser){ports.Command(m,callback,parser);});}
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){ports.Diagnostic(m,callback,arguments);}
 }
 public static class PreparedTextScriptFile
 {
  public static void Populate(ConditionParserMemory m,RecoveredTextScriptFileServices s,uint parser,uint script,uint top,uint bottom){PreparedScriptFileBody.Populate(m,s,parser,script,top,bottom);}
  public static void Parse(ConditionParserMemory m,RecoveredTextScriptFileServices s,uint output,uint context,uint fileName,uint archive,uint top,uint bottom){PreparedScriptFileBody.Parse(m,s,output,context,fileName,archive,top,bottom);}
 }
}
