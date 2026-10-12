/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f5f0; label: FUN_0056f5f0
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

