/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f1310; label: FUN_004f1310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1310(int *param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = param_1[1];
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = param_2;
  }
  param_1[1] = (int)param_2;
  if (*param_1 == 0) {
    *param_1 = (int)param_2;
  }
  return;
}

