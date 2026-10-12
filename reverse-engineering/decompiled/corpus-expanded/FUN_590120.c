/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x590120; label: FUN_00590120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00590120(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x34;
  }
  return 0;
}

