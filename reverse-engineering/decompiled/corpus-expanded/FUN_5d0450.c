/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0450; label: FUN_005d0450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d0450(int param_1,int param_2)

{
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 4) != *(int *)(param_2 + 4))) &&
     ((*(int *)(param_1 + 8) == 0 || (*(int *)(param_1 + 8) != *(int *)(param_2 + 8))))) {
    return 0;
  }
  return 1;
}

