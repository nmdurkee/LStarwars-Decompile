/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x620e70; label: FUN_00620e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00620e70(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_02912e88 != 0) {
    if (DAT_02912f38 != 0) {
      iVar1 = FUN_006d6c20(0x38);
      if (iVar1 == 0) {
        FUN_00620bf0(PTR_DAT_0080f7ec,param_2);
        goto LAB_00620eb7;
      }
    }
    FUN_00620870(PTR_DAT_0080f7ec);
  }
LAB_00620eb7:
  if (param_1 != 0) {
    if (DAT_02912f38 == 0) {
      FUN_006204f0(PTR_DAT_0080f7ec);
      return;
    }
    FUN_006200d0(PTR_DAT_0080f7ec,param_2,param_1);
  }
  return;
}

