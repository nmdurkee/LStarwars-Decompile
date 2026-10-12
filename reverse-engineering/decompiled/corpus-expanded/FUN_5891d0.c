/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x5891d0; label: FUN_005891d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005891d0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x48) = ABS((float)fVar1);
  return;
}

