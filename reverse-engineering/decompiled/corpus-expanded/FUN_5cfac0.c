/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfac0; label: FUN_005cfac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005cfac0(int param_1)

{
  if ((param_1 != 0) && ((*(int *)(param_1 + 4) != 0 || (*(int *)(param_1 + 8) != 0)))) {
    return 1;
  }
  return 0;
}

