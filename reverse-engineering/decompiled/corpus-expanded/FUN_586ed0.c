/* Ghidra pseudocode, not original source.
 * ev_160b6ff83e8d01b08d86e74350d491f9e4ae154e83c7564abce91853a1b29784
 * Entry: 0x586ed0; label: FUN_00586ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00586ed0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  if (0.0 < (float)fVar1) {
    *(float *)(DAT_00954404 + 0x74) = (float)fVar1;
    _DAT_0095440c = _DAT_0095440c | 4;
    return;
  }
  return;
}

