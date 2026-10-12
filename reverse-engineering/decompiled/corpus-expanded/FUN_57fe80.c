/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57fe80; label: FUN_0057fe80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057fe80(int *param_1)

{
  if (*(short *)(*param_1 + 0x66) != -1) {
    FUN_005478a0((int)*(short *)(*param_1 + 0x66));
    return;
  }
  FUN_00547930(0x28,param_1 + 0x22,0,0);
  return;
}

