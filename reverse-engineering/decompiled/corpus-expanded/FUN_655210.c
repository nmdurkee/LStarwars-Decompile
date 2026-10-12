/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x655210; label: FUN_00655210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655210(int param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 != 0) {
    while (iVar1 = *param_2, iVar1 != param_1) {
      param_2 = (int *)(iVar1 + 0x10);
      if (*(int *)(iVar1 + 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        return;
      }
    }
    *param_2 = *(int *)(param_1 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

