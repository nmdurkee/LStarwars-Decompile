/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x6551d0; label: FUN_006551d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006551d0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  while ((iVar1 != 0 && (iVar2 = *param_2, *(float *)(iVar2 + 4) < *(float *)(param_1 + 4)))) {
    iVar1 = *(int *)(iVar2 + 0x10);
    param_2 = (int *)(iVar2 + 0x10);
  }
  *(int *)(param_1 + 0x10) = *param_2;
  *param_2 = param_1;
  return;
}

