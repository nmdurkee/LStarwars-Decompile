/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515320; label: FUN_00515320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515320(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     (*(float *)(*(int *)(param_3 + 0xe4) + 0x60) <
      *(float *)(*(int *)(param_3 + 0xd0) + 0x60) - 0.1)) {
    return (float10)1;
  }
  return (float10)0;
}

