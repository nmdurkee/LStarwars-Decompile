/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c79d0; label: FUN_006c79d0
 */

void FUN_006c79d0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  int *piVar2;
  
  FUN_006c5f80(param_2);
  switch(*(int *)(in_ECX + 0x14)) {
  case -0x7fffffff:
    *(int *)(param_1 + 0x48) = *param_3;
    break;
  case -0x7ffffffe:
    *(int *)(param_1 + 0x4c) = *param_3;
    break;
  case -0x7ffffffd:
    *(uint *)(param_1 + 0x50) = (uint)(*param_3 != 0);
    break;
  case -0x7ffffffc:
    *(int *)(param_1 + 0x54) = *param_3;
    break;
  default:
    piVar2 = (int *)(*(int *)(in_ECX + 0x14) + param_1);
    uVar1 = FUN_006c6010(param_2,param_4);
    if (piVar2 == (int *)0x0) {
      return;
    }
    if ((*(uint *)(in_ECX + 0x1c) & 0x40000000) != 0) {
      piVar2 = (int *)*piVar2;
    }
    FUN_004ef660(param_3,piVar2,uVar1);
    return;
  }
  if (DAT_0081fe04 == 0) {
    return;
  }
  FUN_006c7480();
  return;
}

