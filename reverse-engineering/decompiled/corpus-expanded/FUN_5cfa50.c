/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfa50; label: FUN_005cfa50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005cfa50(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      return *(undefined4 *)(*(int *)(param_1 + 8) + 0xb4);
    }
    if (*(int *)(param_1 + 4) != 0) {
      return *(undefined4 *)(*(int *)(param_1 + 4) + 0x44);
    }
  }
  return 0;
}

