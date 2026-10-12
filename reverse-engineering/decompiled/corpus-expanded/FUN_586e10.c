/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x586e10; label: FUN_00586e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586e10(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 100) = (float)fVar1;
  return;
}

