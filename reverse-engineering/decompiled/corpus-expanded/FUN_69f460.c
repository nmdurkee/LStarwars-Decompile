/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69f460; label: FUN_0069f460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069f460(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      _free((void *)*param_1);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    _free(param_1);
  }
  return 0;
}

