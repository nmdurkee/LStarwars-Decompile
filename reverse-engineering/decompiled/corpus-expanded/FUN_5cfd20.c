/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfd20; label: FUN_005cfd20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005cfd20(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      return *(uint *)(param_1[1] + 0x48) & 0x200;
    }
    if (param_1[2] != 0) {
      return *(uint *)(param_1[2] + 0xb8) & 0x200;
    }
  }
  return 0;
}

