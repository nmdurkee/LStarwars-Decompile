/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x5156f0; label: FUN_005156f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005156f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && ((*(uint *)(param_3 + 0x1e8) & 0x400000) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

