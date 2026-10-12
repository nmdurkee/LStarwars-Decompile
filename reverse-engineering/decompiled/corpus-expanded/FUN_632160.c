/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x632160; label: FUN_00632160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00632160(int *param_1)

{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)param_1[1];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      param_1[1] = 0;
    }
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *param_1 = 0;
    }
    _free(param_1);
  }
  return;
}

