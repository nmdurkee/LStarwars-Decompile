/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x507c00; label: FUN_00507c00
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

