// Complete __aulldvrm701F40 prepared nonzero unsigned64 division, original quotient/remainder register ABI.
namespace Recovered.Gameplay
{
 public struct ScriptUnsignedDivisionResult
 {
  public readonly uint Eax,Edx,Ebx,Ecx;
  public ScriptUnsignedDivisionResult(ulong quotient,ulong remainder){Eax=(uint)quotient;Edx=(uint)(quotient>>32);Ebx=(uint)(remainder>>32);Ecx=(uint)remainder;}
 }
 public static class PreparedScriptUnsignedDivision
 {
  // Original four DWORD stack arguments numeratorlow/high,divisorlow/high; RET16, ESI/EDI preserved. Divisor0 is a guest divide fault outside the prepared return domain.
  public static ScriptUnsignedDivisionResult Execute(uint numeratorLow,uint numeratorHigh,uint divisorLow,uint divisorHigh)
  {ulong numerator=numeratorLow|((ulong)numeratorHigh<<32),divisor=divisorLow|((ulong)divisorHigh<<32);return new ScriptUnsignedDivisionResult(numerator/divisor,numerator%divisor);}
 }
}
