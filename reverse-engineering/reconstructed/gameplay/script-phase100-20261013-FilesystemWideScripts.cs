// Existing wide word/line/token producers now consume the complete recovered filesystem transport.
namespace Recovered.Gameplay
{
 public static class RecoveredFilesystemWideScripts
 {
  public static uint NextLine(SoundSetupImage image,uint parser,RecoveredGameScriptFileIO files){return PreparedDecodedScriptFiles.NextLine(image,parser,files.Read);}
  public static uint NextToken(SoundSetupImage image,uint parser){return PreparedDecodedScriptFiles.NextToken(image,parser);}
  public static RecoveredTextScriptFileServices Create(ScriptFileTransportServices transport,ScriptExpressionServices symbols,ScriptParserLifecycleServices life,RecoveredGameScriptFileIO files){return PreparedDecodedScriptFiles.Create(transport,symbols,life,files.Read);}
 }
}
