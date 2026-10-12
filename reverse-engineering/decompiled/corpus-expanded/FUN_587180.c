/* Ghidra pseudocode, not original source.
 * ev_160b6ff83e8d01b08d86e74350d491f9e4ae154e83c7564abce91853a1b29784
 * Entry: 0x587180; label: FUN_00587180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00587180(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x7c) = (float)fVar1;
  return;
}

