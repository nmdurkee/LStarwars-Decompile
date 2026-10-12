/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6332c0; label: FUN_006332c0
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

