// Actual decimal helper→ctype fast-path/locale dispatch composition.
namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptDecimalCtypeServices:ScriptDecimalFormattingServices
 {
  readonly ScriptLocaleUpdateServices locale;readonly ScriptCtypeServices ctype;public RecoveredScriptDecimalCtypeServices(ScriptLocaleUpdateServices l,ScriptCtypeServices c){locale=l;ctype=c;}
  public override uint Thread(TakeoverReleaseMemory m){return locale.Thread(m);}public override uint Locale(TakeoverReleaseMemory m){return locale.Locale(m);}public override uint Multibyte(TakeoverReleaseMemory m){return locale.Multibyte(m);}public override uint Lower(TakeoverReleaseMemory m,uint character){return PreparedScriptCtype.Lower(m,ctype,character);}public override uint Digit(TakeoverReleaseMemory m,uint character){return PreparedScriptCtype.Digit(m,ctype,character);}
 }
}
