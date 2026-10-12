/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631e60; label: FUN_00631e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00631e60(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,0,1,param_3,0,3,param_2);
  return -1 < iVar1;
}

