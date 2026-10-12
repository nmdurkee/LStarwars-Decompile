/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f13c0; label: FUN_004f13c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f13c0(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    param_3[1] = param_2;
    *param_3 = *param_2;
    piVar1 = (int *)*param_2;
    if ((int *)*param_2 == (int *)0x0) {
      piVar1 = param_1;
    }
    piVar1[1] = (int)param_3;
    *param_2 = param_3;
    return;
  }
  *param_3 = 0;
  param_3[1] = param_1[1];
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = param_3;
  }
  param_1[1] = (int)param_3;
  if (*param_1 == 0) {
    *param_1 = (int)param_3;
  }
  return;
}

