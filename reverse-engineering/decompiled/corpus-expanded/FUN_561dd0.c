/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x561dd0; label: FUN_00561dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00561dd0(int param_1)

{
  int iVar1;
  
  if (((DAT_00804c08 == -1) ||
      (iVar1 = (int)DAT_00804c08,
      *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) == 0)) &&
     ((DAT_00804bfc == -1 ||
      (iVar1 = (int)DAT_00804bfc,
      *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) == 0)))) {
    iVar1 = (int)DAT_00804bf0;
  }
  return iVar1;
}

