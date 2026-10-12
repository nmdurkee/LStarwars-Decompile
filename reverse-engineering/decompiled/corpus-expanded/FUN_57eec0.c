/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57eec0; label: FUN_0057eec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057eec0(void)

{
  int iVar1;
  
  if ((((DAT_00951cb0 != 0) && (*(int *)(DAT_00951cb0 + 4) != 0)) && (DAT_00951b80 != 0)) &&
     (DAT_00951b80 == DAT_00951b94)) {
    FUN_006df320(0);
    return;
  }
  if ((0 < DAT_00951c80) && (iVar1 = 0, 0 < DAT_00951c80)) {
    do {
      FUN_005060e0((&DAT_00951c3c)[iVar1]);
      if (iVar1 == DAT_00951bfc) {
        DAT_00951be0 = 0;
        DAT_00951be8 = 0;
        FUN_0054a2f0(PTR_DAT_008021b4);
        FUN_006df320(0);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00951c80);
  }
  return;
}

