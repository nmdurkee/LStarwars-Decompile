/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56cf30; label: FUN_0056cf30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056cf30(undefined4 param_1,int param_2,int *param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_10;
  int local_c;
  int local_8;
  
  local_10 = 1e+09;
  iVar1 = *(int *)(param_2 + 0x50a0);
  iVar2 = 0;
  local_c = 0;
  local_8 = -1;
  iVar4 = 0;
  if (0 < *(int *)(param_2 + 0x50a4)) {
    do {
      iVar3 = 0;
      iVar4 = iVar1 + 8;
      do {
        fVar5 = (float10)FUN_005b3c50(param_1,iVar4,0);
        if ((float)fVar5 < local_10) {
          local_10 = (float)fVar5;
          local_c = iVar1;
          local_8 = iVar3;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar3 < 2);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x24;
      iVar4 = local_c;
    } while (iVar2 < *(int *)(param_2 + 0x50a4));
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_8;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = local_10;
  }
  return iVar4;
}

