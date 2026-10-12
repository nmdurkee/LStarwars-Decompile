/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61b120; label: FUN_0061b120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061b120(void)

{
  float *in_ECX;
  
  if ((((*in_ECX < _DAT_0080f550 != (*in_ECX == _DAT_0080f550)) &&
       (in_ECX[1] < _DAT_0080f554 != (in_ECX[1] == _DAT_0080f554))) &&
      (_DAT_0080f550 < in_ECX[2] + *in_ECX)) && (_DAT_0080f554 < in_ECX[3] * 0.75 + in_ECX[1])) {
    return 1;
  }
  return 0;
}

