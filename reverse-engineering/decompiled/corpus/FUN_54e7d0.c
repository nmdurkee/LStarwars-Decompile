/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54e7d0; label: FUN_0054e7d0
 */

undefined * FUN_0054e7d0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00926cac;
  do {
    if (*piVar1 == param_1) {
      (&DAT_00926c76)[iVar2 * 0xf8] = (&DAT_00926c76)[iVar2 * 0xf8] & 0xfd;
      (&DAT_00926cac)[iVar2 * 0x3e] = 0;
      return &DAT_00926c58 + iVar2 * 0xf8;
    }
    piVar1 = piVar1 + 0x3e;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x92708c);
  return (undefined *)0x0;
}

