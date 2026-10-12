/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a5bb0; label: FUN_004a5bb0
 */

void FUN_004a5bb0(float param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = (int)param_1;
  fVar3 = (float10)FUN_005bec80((int)param_1 + 0x80);
  fVar1 = (float)fVar3;
  if (2.5 <= fVar1) {
    param_1 = 1.0;
  }
  else if ((NAN(fVar1) || 0.1 < fVar1 == (fVar1 == 0.1)) ||
          (param_1 = (fVar1 - 0.1) / 2.4, param_1 <= 0.0)) {
    return;
  }
  FUN_00651470("BBounce",iVar2 + 0x30,param_1);
  return;
}

