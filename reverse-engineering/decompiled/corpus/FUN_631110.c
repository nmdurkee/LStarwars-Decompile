/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631110; label: FUN_00631110
 */

/* WARNING: Removing unreachable block (ram,0x0063114c) */

float10 FUN_00631110(void)

{
  float fVar1;
  int iStack_3c;
  undefined1 local_38 [56];
  
  _BinkGetRealtime_12(DAT_02913178);
  fVar1 = (float)(iStack_3c * (int)local_38);
  if (iStack_3c * (int)local_38 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  return (float10)(fVar1 / 0.0);
}

