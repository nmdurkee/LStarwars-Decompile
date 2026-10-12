/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61e850; label: FUN_0061e850
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061e850(void)

{
  float fVar1;
  int in_ECX;
  
  if ((((*(float *)(in_ECX + 0x5c) < _DAT_0080f550 != (*(float *)(in_ECX + 0x5c) == _DAT_0080f550))
       && (fVar1 = *(float *)(in_ECX + 0x60) * 0.5,
          fVar1 < _DAT_0080f554 != (fVar1 == _DAT_0080f554))) &&
      (_DAT_0080f550 < *(float *)(in_ECX + 0x5c) + *(float *)(in_ECX + 0x58))) &&
     (_DAT_0080f554 < (*(float *)(in_ECX + 0x60) + *(float *)(in_ECX + 0x58)) * 0.5)) {
    return 1;
  }
  return 0;
}

