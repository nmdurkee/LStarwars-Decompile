/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54e750; label: FUN_0054e750
 */

undefined * FUN_0054e750(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  piVar3 = &DAT_00926cac;
  do {
    if (*piVar3 == param_1) {
      return &DAT_00926c58 + iVar1 * 0xf8;
    }
    piVar3 = piVar3 + 0x3e;
    iVar1 = iVar1 + 1;
  } while ((int)piVar3 < 0x92708c);
  iVar1 = 0;
  piVar3 = &DAT_00926cac;
  do {
    if (*piVar3 == 0) {
      iVar2 = iVar1 * 0xf8;
      (&DAT_00926c76)[iVar2] = (&DAT_00926c76)[iVar2] | 2;
      (&DAT_00926cac)[iVar1 * 0x3e] = param_1;
      (&DAT_00926c75)[iVar2] = param_2;
      return &DAT_00926c58 + iVar2;
    }
    piVar3 = piVar3 + 0x3e;
    iVar1 = iVar1 + 1;
  } while ((int)piVar3 < 0x92708c);
  return (undefined *)0x0;
}

