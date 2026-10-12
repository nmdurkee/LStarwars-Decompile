/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x5750f0; label: FUN_005750f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005750f0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00951398 + 0x100) = (float)fVar1;
  return;
}

