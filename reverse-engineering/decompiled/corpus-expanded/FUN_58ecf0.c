/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ecf0; label: FUN_0058ecf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058ecf0(int param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x6d) == '\x02')) {
    return 1;
  }
  return 0;
}

