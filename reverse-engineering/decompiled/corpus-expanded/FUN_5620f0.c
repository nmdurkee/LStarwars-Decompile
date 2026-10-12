/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x5620f0; label: FUN_005620f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005620f0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)*(char *)(param_1 + 0x7b5);
  if ((((*(uint *)(PTR_PTR_007fb0e4 + iVar1 * 0x10 + 8) & 0x1004) != 0) &&
      (((DAT_00802898 == -1 || (iVar1 != DAT_00802898)) || (*(char *)(param_1 + 0x7b3) != '\0'))))
     && ((DAT_00802840 == -1 || (iVar1 != DAT_00802840)))) {
    return 1;
  }
  return 0;
}

