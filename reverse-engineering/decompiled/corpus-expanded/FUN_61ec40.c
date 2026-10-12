/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ec40; label: FUN_0061ec40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061ec40(void)

{
  float fVar1;
  int in_ECX;
  
  if ((((*(float *)(in_ECX + 0x5c) < _DAT_0080f550 != (*(float *)(in_ECX + 0x5c) == _DAT_0080f550))
       && (fVar1 = *(float *)(in_ECX + 0x60) * 0.5,
          fVar1 < _DAT_0080f554 != (fVar1 == _DAT_0080f554))) &&
      (_DAT_0080f550 < *(float *)(in_ECX + 0x58) + *(float *)(in_ECX + 0x5c))) &&
     (_DAT_0080f554 < (*(float *)(in_ECX + 0x60) + *(float *)(in_ECX + 0x58)) * 0.5)) {
    return 1;
  }
  return 0;
}

