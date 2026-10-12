/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c7aa0; label: FUN_006c7aa0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c7aa0(int param_1,undefined4 param_2,float *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  int *piVar2;
  
  FUN_006c5f80(param_2);
  switch(*(int *)(in_ECX + 0x14)) {
  case -0x7fffffff:
    FUN_004f1f40(param_3,*(int *)(param_1 + 0x40) + 0xc,param_4);
    return;
  case -0x7ffffffe:
    *param_3 = _DAT_0081f9b4 * _DAT_0081fa04;
    return;
  case -0x7ffffffd:
    *param_3 = *(float *)(param_1 + 0x10);
    param_3[1] = *(float *)(param_1 + 0x14);
    param_3[2] = *(float *)(param_1 + 0x18);
    param_3[3] = *(float *)(param_1 + 0x1c);
    return;
  case -0x7ffffffc:
    *param_3 = *(float *)(param_1 + 0x20);
    param_3[1] = *(float *)(param_1 + 0x24);
    param_3[2] = *(float *)(param_1 + 0x28);
    param_3[3] = *(float *)(param_1 + 0x2c);
    return;
  case -0x7ffffffb:
    *param_3 = *(float *)(param_1 + 0x30);
    param_3[1] = *(float *)(param_1 + 0x34);
    param_3[2] = *(float *)(param_1 + 0x38);
    param_3[3] = *(float *)(param_1 + 0x3c);
    return;
  }
  piVar2 = (int *)(*(int *)(in_ECX + 0x14) + param_1);
  uVar1 = FUN_006c6010(param_2,param_4);
  if (piVar2 != (int *)0x0) {
    if ((*(uint *)(in_ECX + 0x1c) & 0x40000000) != 0) {
      piVar2 = (int *)*piVar2;
    }
    FUN_004ef660(param_3,piVar2,uVar1);
  }
  return;
}

