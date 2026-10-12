/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x6961b0; label: FUN_006961b0
 */

void FUN_006961b0(undefined4 param_1,int param_2)

{
  int *piVar1;
  float10 fVar2;
  
  if (0x7ff < *(int *)(param_2 + 0x14)) {
    FUN_00693b60();
  }
  fVar2 = (float10)FUN_004f9f60(param_1);
  *(float *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x14) * 4) = (float)fVar2;
  piVar1 = (int *)(*(int *)(param_2 + 0x20) + 0x1c);
  *piVar1 = *piVar1 + 1;
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
  return;
}

