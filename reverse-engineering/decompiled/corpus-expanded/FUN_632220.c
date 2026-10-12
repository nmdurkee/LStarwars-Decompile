/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x632220; label: FUN_00632220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00632220(int param_1,int param_2,int param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (param_3 == 0) {
    param_3 = 1;
  }
  local_8 = 0;
  local_4 = 0x3f800000;
  local_18 = 0;
  local_14 = 0;
  local_10 = param_2;
  local_c = param_3;
  (**(code **)(**(int **)(param_1 + 4) + 0xbc))(*(int **)(param_1 + 4),&local_18);
  return;
}

