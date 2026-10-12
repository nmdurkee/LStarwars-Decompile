/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d10e0; label: FUN_005d10e0
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

