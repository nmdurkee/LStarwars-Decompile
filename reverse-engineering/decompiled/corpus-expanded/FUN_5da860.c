/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da860; label: FUN_005da860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005da860(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 != 0) && (param_1 != (int *)0x0)) {
    if ((*(int *)(param_2 + 0x110) != 0) && (param_3 < *(int *)(*(int *)(param_2 + 0x110) + 0x6c)))
    {
      param_1[1] = 0;
      *param_1 = param_2;
      param_1[2] = param_3 * 0xd0 + *(int *)(*(int *)(param_2 + 0x110) + 0x70);
      return;
    }
    if (param_3 < *(int *)(param_2 + 0x24)) {
      *param_1 = param_2;
      iVar1 = *(int *)(param_2 + 0x28);
      param_1[2] = 0;
      param_1[1] = param_3 * 0x4c + iVar1;
      return;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

