/* Ghidra pseudocode, not original source.
 * ev_df79f36d452c441765aee3b48fdf5c85f40e43d18ea34c7e23c83a31d911b650
 * Entry: 0x4f4f80; label: FUN_004f4f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f4f80(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  param_1 = (int *)(*param_1 + (int)param_1);
  iVar2 = *param_1;
  if (0 < iVar2) {
    do {
      param_1 = param_1 + 1;
      iVar1 = *(int *)(*param_1 + (int)param_1);
      if (iVar1 != 0) {
        *(int *)(*param_1 + (int)param_1) = iVar1 + param_2;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

