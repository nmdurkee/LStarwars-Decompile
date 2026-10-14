// Raw registered movement-token callback43C0C0 refinement; byte comparison and alias stores.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptMovementToken
 {
  public static uint Execute(TakeoverReleaseMemory m,uint token,uint output)
  {
   if(PreparedScriptByteLookup.Equal(m,token,0x755d44)){m.Write8(output,0);return 1;}
   if(PreparedScriptByteLookup.Equal(m,token,0x755d3c)){m.Write8(output,1);return 1;}
   if(PreparedScriptByteLookup.Equal(m,token,0x755d34)){m.Write8(output,2);return 1;}
   return 0;
  }
 }
 public sealed class RecoveredScriptMovementTokens:ScriptCircleServices
 {
  readonly ScriptCircleServices remaining;public RecoveredScriptMovementTokens(ScriptCircleServices custom){remaining=custom;}
  public override uint Token(TakeoverReleaseMemory m,uint callback,uint token,uint output){if(callback==0x43c0c0)return PreparedScriptMovementToken.Execute(m,token,output);if(remaining==null)throw new NotSupportedException("Custom movement-token callback required.");return remaining.Token(m,callback,token,output);}
 }
}
