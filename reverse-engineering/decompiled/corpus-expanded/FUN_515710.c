/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515710; label: FUN_00515710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515710(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    return (float10)*(byte *)(param_2 + 0xb5);
  }
  return (float10)-1.0;
}

