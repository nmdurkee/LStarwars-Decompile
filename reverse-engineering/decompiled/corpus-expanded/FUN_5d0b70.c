/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0b70; label: FUN_005d0b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0b70(int param_1,short *param_2)

{
  short sVar1;
  
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    sVar1 = *param_2;
    while (sVar1 != 0) {
      sVar1 = FUN_005d0aa0(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x10),*param_2)
      ;
      *param_2 = sVar1;
      if (sVar1 == -1) {
        *param_2 = 0x3f;
      }
      param_2 = param_2 + 1;
      sVar1 = *param_2;
    }
  }
  return;
}

