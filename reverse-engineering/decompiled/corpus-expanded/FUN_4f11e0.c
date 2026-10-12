/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f11e0; label: FUN_004f11e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f11e0(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x570)) {
    *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + -1;
  }
  return;
}

