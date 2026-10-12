/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f990; label: FUN_0056f990
 */

void FUN_0056f990(int param_1)

{
  int in_ECX;
  float *in_EDX;
  
  if (param_1 < 7) {
    if ((param_1 < 6) && (*in_EDX < 10.0)) {
      *in_EDX = 10.0;
    }
    if ((((-1 < in_ECX) && (in_ECX < DAT_00951360)) &&
        ((*(byte *)(in_ECX * 0x9c + 0x7a + DAT_00951354) & 1) != 0)) && (*in_EDX < 100.0)) {
      *in_EDX = 100.0;
    }
  }
  return;
}

