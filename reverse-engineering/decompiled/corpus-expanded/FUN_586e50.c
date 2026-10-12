/* Ghidra pseudocode, not original source.
 * ev_160b6ff83e8d01b08d86e74350d491f9e4ae154e83c7564abce91853a1b29784
 * Entry: 0x586e50; label: FUN_00586e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586e50(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x6c) = (float)fVar1;
  return;
}

