/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x695170; label: FUN_00695170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00695170(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (in_ECX == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *(undefined4 *)(in_ECX + 0x1dc);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(in_ECX + 0x1e0);
      return;
    }
  }
  return;
}

