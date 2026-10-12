/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f10a0; label: FUN_004f10a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f10a0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  *(int *)(param_1 + 0x524) = iVar1;
  *(undefined4 *)(param_1 + 0x520) = *(undefined4 *)(param_2 + 4);
  if ((iVar1 < *(int *)(param_1 + 0x528)) || (*(int *)(param_1 + 0x52c) < iVar1)) {
    *(int *)(param_1 + 0x52c) = iVar1 + -1;
  }
  return;
}

