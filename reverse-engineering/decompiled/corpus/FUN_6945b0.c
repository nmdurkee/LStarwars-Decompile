/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x6945b0; label: FUN_006945b0
 */

void FUN_006945b0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  
  if (0x7ff < *(int *)(in_ECX + 0x14)) {
    FUN_00693b60();
  }
  fVar2 = (float10)FUN_004f9f60(param_1);
  *(float *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x14) * 4) = (float)fVar2;
  piVar1 = (int *)(*(int *)(in_ECX + 0x20) + 0x1c);
  *piVar1 = *piVar1 + 1;
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  return;
}

