/* Ghidra pseudocode, not original source.
 * ev_160b6ff83e8d01b08d86e74350d491f9e4ae154e83c7564abce91853a1b29784
 * Entry: 0x586eb0; label: FUN_00586eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586eb0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0xb8) = (float)fVar1;
  return;
}

