/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f3bf0; label: FUN_004f3bf0
 */

void FUN_004f3bf0(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_2;
  uVar2 = *param_3;
  if (uVar2 <= uVar1) {
    *param_1 = uVar1 - uVar2;
    param_1[1] = param_2[1] - param_3[1];
    return;
  }
  *param_1 = uVar1 - uVar2;
  param_1[1] = (param_2[1] - param_3[1]) + -1;
  return;
}

