/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55cd20; label: FUN_0055cd20
 */

void FUN_0055cd20(int param_1)

{
  float fVar1;
  
  *(undefined4 *)(param_1 + 0xff0) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x34);
  fVar1 = *(float *)(*(int *)(param_1 + 0x54) + 0x38);
  *(float *)(param_1 + 0xff4) = fVar1;
  if (*(float *)(param_1 + 0xffc) == 0.0) {
    *(undefined4 *)(param_1 + 0x1004) = 0;
    return;
  }
  *(float *)(param_1 + 0x1004) =
       (fVar1 - *(float *)(param_1 + 0xff0)) /
       (*(float *)(param_1 + 0xffc) + *(float *)(param_1 + 0xffc));
  return;
}

