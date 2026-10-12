/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55ccd0; label: FUN_0055ccd0
 */

void FUN_0055ccd0(int param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *(int *)(param_1 + 0x54);
  *(float *)(param_1 + 0xa4) = *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 0xa8);
  fVar2 = *(float *)(param_1 + 0xffc) * *(float *)(param_1 + 0xa8);
  *(float *)(param_1 + 0xac) = fVar2;
  *(float *)(param_1 + 0xb0) = fVar2 * *(float *)(param_1 + 0x1004);
  *(float *)(param_1 + 0xb4) =
       (*(float *)(iVar1 + 0x38) - *(float *)(iVar1 + 0x34)) * *(float *)(param_1 + 0xff8);
  return;
}

