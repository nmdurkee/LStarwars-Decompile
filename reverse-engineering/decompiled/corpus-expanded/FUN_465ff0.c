/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x465ff0; label: FUN_00465ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00465ff0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x10;
  }
  return 0;
}

