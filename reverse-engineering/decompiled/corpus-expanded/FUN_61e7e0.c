/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61e7e0; label: FUN_0061e7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061e7e0(void)

{
  float fVar1;
  float *in_ECX;
  
  fVar1 = *(float *)((int)in_ECX[5] + 0x54) + *in_ECX + 1.0;
  if ((((fVar1 < _DAT_0080f550 != (fVar1 == _DAT_0080f550)) &&
       (in_ECX[1] < _DAT_0080f554 != (in_ECX[1] == _DAT_0080f554))) &&
      (_DAT_0080f550 < *(float *)((int)in_ECX[5] + 0x5c))) &&
     (_DAT_0080f554 < in_ECX[3] + in_ECX[1])) {
    return 1;
  }
  return 0;
}

