/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x580200; label: FUN_00580200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580200(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00951cc0 + 0x14) = (float)fVar1;
  return;
}

