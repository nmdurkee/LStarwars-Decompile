/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6c70; label: FUN_004f6c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6c70(int param_1,int param_2,undefined4 param_3,int param_4)

{
  if (0x7ff < param_1) {
    FUN_004f0ae0(param_1,param_2,param_3,param_4);
    return;
  }
  param_1 = param_1 + -0x400;
  if (param_4 != 1) {
    if (param_4 != 2) {
      *(int *)(&DAT_02983748 + param_1 * 0x14) = *(int *)(&DAT_02983740 + param_1 * 0x14) + param_2;
      return;
    }
    *(int *)(&DAT_02983748 + param_1 * 0x14) = *(int *)(&DAT_02983744 + param_1 * 0x14) - param_2;
    return;
  }
  *(int *)(&DAT_02983748 + param_1 * 0x14) = *(int *)(&DAT_02983748 + param_1 * 0x14) + param_2;
  return;
}

