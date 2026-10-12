/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x744010; label: FUN_00744010
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

