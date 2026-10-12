/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x696330; label: FUN_00696330
 */

void FUN_00696330(undefined4 param_1)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  
  fVar3 = (float10)FUN_004f9f60(param_1);
  *(float *)(*(int *)(in_ECX + 0x20) + 0x2c) = (float)fVar3;
  iVar2 = *(int *)(in_ECX + 0x20);
  if (0.0 <= *(float *)(iVar2 + 0x2c)) {
    fVar3 = (float10)FUN_004f9f60(param_1);
    *(float *)(*(int *)(in_ECX + 0x20) + 0x30) = (float)fVar3;
    return;
  }
  fVar1 = *(float *)(iVar2 + 0x2c);
  if (fVar1 < -100.0 != (fVar1 == -100.0)) {
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    fVar3 = (float10)FUN_004f9f60(param_1);
    *(float *)(*(int *)(in_ECX + 0x20) + 0x30) = (float)fVar3;
    return;
  }
  if (0.0 <= fVar1) {
    *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x2c) = 0x3f800000;
    fVar3 = (float10)FUN_004f9f60(param_1);
    *(float *)(*(int *)(in_ECX + 0x20) + 0x30) = (float)fVar3;
    return;
  }
  fVar3 = (float10)FUN_005be970(fVar1 / 20.0);
  *(float *)(*(int *)(in_ECX + 0x20) + 0x2c) = (float)fVar3;
  fVar3 = (float10)FUN_004f9f60(param_1);
  *(float *)(*(int *)(in_ECX + 0x20) + 0x30) = (float)fVar3;
  return;
}

