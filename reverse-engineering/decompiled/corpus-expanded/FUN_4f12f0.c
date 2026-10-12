/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f12f0; label: FUN_004f12f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f12f0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

