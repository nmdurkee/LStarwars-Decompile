/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631d00; label: FUN_00631d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00631d00(int *param_1)

{
  int *piVar1;
  
  if (DAT_029131cc != 0) {
    piVar1 = *(int **)(DAT_029131cc + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x104))(piVar1,0,0);
    }
    FUN_006e3650();
  }
  if (param_1[2] != 0) {
    FUN_00633350(param_1[2]);
    param_1[2] = 0;
  }
  if (*param_1 != 0) {
    _BinkClose_4(*param_1);
    *param_1 = 0;
  }
  if (param_1[6] != 0) {
    FUN_005fb810();
    FUN_005f7b40();
    return;
  }
  return;
}

