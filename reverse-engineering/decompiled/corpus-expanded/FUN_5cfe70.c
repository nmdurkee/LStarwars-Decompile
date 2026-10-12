/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfe70; label: FUN_005cfe70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005cfe70(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    return *(uint *)(*(int *)(param_1[1] + 0x40) + 0x44) >> 1 & 1;
  }
  return 1;
}

