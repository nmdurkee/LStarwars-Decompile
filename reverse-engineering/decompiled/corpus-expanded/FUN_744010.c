/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x744010; label: FUN_00744010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00744010(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x4cc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x4cc) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x4d0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x4d0) = 0;
  }
  thunk_FUN_00743930(param_1);
  return;
}

