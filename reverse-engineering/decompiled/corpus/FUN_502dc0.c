/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502dc0; label: FUN_00502dc0
 */

undefined4 FUN_00502dc0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(*(int *)(param_1 + 0x2c) + param_3 * 2) == 10) {
    return *(undefined4 *)(param_2 + param_3 * 4);
  }
  if (*(float *)(param_2 + param_3 * 4) < 0.0) {
    uVar1 = FUN_006e6b90();
    return uVar1;
  }
  uVar1 = FUN_006e6b90();
  return uVar1;
}

