/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x597d00; label: FUN_00597d00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597d00(float param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = (int)param_1;
  fVar2 = (float10)FUN_005bec80((int)param_1 + 0x80);
  param_1 = (float)fVar2;
  if (_DAT_008051dc < param_1 == (_DAT_008051dc == param_1)) {
    param_1 = param_1 / _DAT_008051dc;
    if (param_1 <= 0.0) {
      return;
    }
  }
  else {
    param_1 = 1.0;
  }
  iVar1 = FUN_0054fa60(iVar1 + 0x30);
  FUN_00549de0(0,param_1 * 0.3,(iVar1 < 0x8000) - 1U & 2);
  return;
}

