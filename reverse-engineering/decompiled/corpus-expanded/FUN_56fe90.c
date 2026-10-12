/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56fe90; label: FUN_0056fe90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056fe90(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  return *param_1 + 8;
}

