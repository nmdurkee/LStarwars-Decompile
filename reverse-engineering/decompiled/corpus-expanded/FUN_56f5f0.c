/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f5f0; label: FUN_0056f5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056f5f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_3 + 0x50b8);
  iVar2 = 0;
  if (0 < piVar1[2]) {
    iVar3 = 0;
    do {
      if ((*(byte *)(*piVar1 + iVar3 + 0x15) & 2) != 0) {
        FUN_00559ee0(param_1,param_2,0,*piVar1 + iVar3);
      }
      piVar1 = *(int **)(param_3 + 0x50b8);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x2c;
    } while (iVar2 < piVar1[2]);
  }
  return;
}

