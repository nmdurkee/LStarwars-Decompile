/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x6332c0; label: FUN_006332c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006332c0(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x20) != 0) {
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x50))(*(int **)(param_1 + 0x4c));
      return;
    }
    piVar1 = *(int **)(*(int *)(param_1 + 0x48) + -4 + *(int *)(param_1 + 0x1c) * 4);
    (**(code **)(*piVar1 + 0x50))(piVar1,0);
  }
  return;
}

