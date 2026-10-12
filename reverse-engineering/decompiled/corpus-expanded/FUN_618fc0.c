/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618fc0; label: FUN_00618fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00618fc0(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 == (int *)*param_1) {
    return 0;
  }
  piVar1 = (int *)param_2[1];
  puVar2 = (undefined4 *)piVar1[1];
  iVar3 = *param_2;
  param_2[1] = (int)puVar2;
  *param_2 = (int)piVar1;
  if (puVar2 == (undefined4 *)0x0) {
    *param_1 = (int)param_2;
  }
  else {
    *puVar2 = param_2;
  }
  if (iVar3 == 0) {
    param_1[1] = *param_2;
  }
  else {
    *(int **)(iVar3 + 4) = piVar1;
  }
  piVar1[1] = (int)param_2;
  *piVar1 = iVar3;
  param_1[3] = *param_1;
  param_1[4] = 0;
  return 1;
}

