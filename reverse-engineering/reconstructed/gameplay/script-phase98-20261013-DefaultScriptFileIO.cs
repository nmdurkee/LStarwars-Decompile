// Standard provider formatter is now concrete throughout filesystem parser I/O.
namespace Recovered.Gameplay
{
 public static class RecoveredDefaultScriptFileIO
 {
  public static RecoveredGameScriptFileIO Create(ScriptGameOpenServices game,ScriptOpenHostServices open,ScriptHostFileServices host,ScriptCloseServices close,ScriptFileSizeServices size,ScriptRemainingSeekServices seeks,ScriptRemainingReadServices reads,uint nameLocal,uint bomLocal,uint indexLocal,uint assembledPathLocal)
  {return new RecoveredGameScriptFileIO(new RecoveredDefaultGameOpenServices(game,assembledPathLocal),open,host,close,size,seeks,reads,nameLocal,bomLocal,indexLocal);}
 }
}
