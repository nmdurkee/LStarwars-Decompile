/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f1120; label: FUN_004f1120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f1120(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (6 < *(int *)(param_1 + 0x570)) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1 + 0x570) + 1;
  *(int *)(param_1 + 0x570) = iVar1;
  *(undefined4 *)(param_1 + 0x530 + iVar1 * 4) = param_2;
  *(undefined4 *)(param_1 + 0x550 + *(int *)(param_1 + 0x570) * 4) = 0;
  return *(undefined4 *)(param_1 + 0x570);
}

