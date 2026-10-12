/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d10e0; label: FUN_005d10e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d10e0(undefined4 param_1,int param_2,float param_3,float param_4,undefined4 param_5)

{
  if (DAT_009738c0 != 4) {
    param_3 = _DAT_0080b600 * param_3 + _DAT_009738ac;
    param_4 = (_DAT_0080b604 * param_4 + _DAT_009738b0) -
              **(float **)(param_2 + 0x30) * *(float *)(param_2 + 0x18);
  }
  *(float *)(*(int *)(param_2 + 0x48) + 4) = param_3;
  *(float *)(*(int *)(param_2 + 0x48) + 8) = param_4;
  *(undefined4 *)(*(int *)(param_2 + 0x48) + 0xc) = param_5;
  return;
}

