/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43adb0; label: FUN_0043adb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0043adb0(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_0055bc80(param_1,0);
  if (((iVar2 == 0) && (sVar1 = *(short *)(param_1 + 0x1064), sVar1 != DAT_007f1968)) &&
     (sVar1 != DAT_007f187c)) {
    return sVar1 == DAT_007f1878;
  }
  return true;
}

