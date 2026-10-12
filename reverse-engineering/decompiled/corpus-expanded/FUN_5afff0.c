/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afff0; label: FUN_005afff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005afff0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_3 + 0x5104);
  iVar3 = 0;
  if (0 < piVar1[1]) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004f1ff0(*piVar1 + iVar4);
      if (iVar2 != 0) {
        FUN_00559ee0(param_1,param_2,0,**(int **)(param_3 + 0x5104) + iVar4);
      }
      piVar1 = *(int **)(param_3 + 0x5104);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x3c;
    } while (iVar3 < piVar1[1]);
  }
  return;
}

