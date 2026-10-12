/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x6241d0; label: FUN_006241d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006241d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    FUN_0061ec10(param_1);
    iVar1 = *param_1;
    while (iVar1 != 0) {
      piVar2 = (int *)*param_1;
      iVar1 = *piVar2;
      (*(code *)piVar2[0x11])(param_1,piVar2);
      *param_1 = iVar1;
    }
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  return;
}

