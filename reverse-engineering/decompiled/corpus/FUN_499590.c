/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x499590; label: FUN_00499590
 */

float10 FUN_00499590(float param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int in_ECX;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24);
  fVar3 = (*(float *)(iVar2 + 0x1c) * param_1) / 3.0;
  fVar1 = *(float *)(*(int *)(in_ECX + 0xca4) + 0x28);
  fVar4 = (*(float *)(iVar2 + 0x18) + *(float *)(iVar2 + 0x14)) * 0.5;
  if ((!NAN(fVar1) && !NAN(fVar4)) && fVar1 < fVar4 != (fVar1 == fVar4)) {
    return (float10)fVar3;
  }
  fVar1 = *(float *)(*(int *)(in_ECX + 0xca4) + 0x28);
  iVar2 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24);
  fVar4 = (*(float *)(iVar2 + 0x1c) + *(float *)(iVar2 + 0x18)) * 0.5;
  if ((!NAN(fVar1) && !NAN(fVar4)) && fVar1 < fVar4 != (fVar1 == fVar4)) {
    return (float10)(fVar3 + fVar3);
  }
  return (float10)(fVar3 * 3.0);
}

