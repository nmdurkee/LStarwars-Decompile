/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x507c00; label: FUN_00507c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00507c00(int *param_1)

{
  param_1[0x16] = param_1[0x17];
  if ((*(byte *)(param_1 + 0x22) & 2) != 0) {
    FUN_005060e0(param_1);
  }
  if (param_1[0x29] != 0) {
    FUN_00502b40();
  }
  if (*param_1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = *param_1;
    return;
  }
  DAT_0092133c = *param_1;
  return;
}

