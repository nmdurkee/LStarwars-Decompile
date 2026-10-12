/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56d750; label: FUN_0056d750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056d750(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  return *param_1 + 0x10;
}

