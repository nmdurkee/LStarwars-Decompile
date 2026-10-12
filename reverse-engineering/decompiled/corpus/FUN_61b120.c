/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61b120; label: FUN_0061b120
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

