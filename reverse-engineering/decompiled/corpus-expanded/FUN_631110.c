/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x631110; label: FUN_00631110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

