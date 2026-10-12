/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57ed70; label: FUN_0057ed70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057ed70(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00951c7c < 1) {
    DAT_00951c7c = 0;
    return;
  }
  do {
    FUN_0057eb00((&DAT_00951c0c)[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < DAT_00951c7c);
  DAT_00951c7c = 0;
  return;
}

