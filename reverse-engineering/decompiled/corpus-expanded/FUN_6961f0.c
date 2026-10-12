/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x6961f0; label: FUN_006961f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006961f0(undefined4 param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_2 + 0x20) + 0x38);
  *puVar1 = *puVar1 | 1;
  return;
}

