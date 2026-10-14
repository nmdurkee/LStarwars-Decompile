// Concrete recovered wide readers attach to the complete raw per-file script closure.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedDecodedScriptFiles
 {
  public static uint WideToken(SoundSetupImage m,uint p){return PreparedScriptWideTokens.Next(new ConditionParserMemory(m),p);}
  public static RecoveredTextScriptFileServices Create(ScriptFileTransportServices transport,ScriptExpressionServices symbols,ScriptParserLifecycleServices io,Func<SoundSetupImage,uint,uint,int,int> readFile){return PreparedScriptFileClosure.Create(transport,symbols,io,readFile,delegate(SoundSetupImage m,uint p){return PreparedScriptWideLines.Next(m,p,readFile);},WideToken);}
  public static uint NextLine(SoundSetupImage m,uint p,Func<SoundSetupImage,uint,uint,int,int> readFile){return TextParserLines.Next(m,p,readFile,delegate(SoundSetupImage image,uint parser){return PreparedScriptWideLines.Next(image,parser,readFile);});}
  public static uint NextToken(SoundSetupImage m,uint p){return ScriptTokenResults.Next(m,p,WideToken);}
  public static int Integer(SoundSetupImage m,uint p){return TextParserNumbers.ReadInteger(m,p,delegate(SoundSetupImage image,uint parser){WideToken(image,parser);});}
  public static float Real(SoundSetupImage m,uint p){return TextParserNumbers.ReadReal(m,p,delegate(SoundSetupImage image,uint parser){WideToken(image,parser);});}
 }
}
