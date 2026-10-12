/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472d90; label: FUN_00472d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00472d90(int param_1,undefined4 param_2,int param_3,float *param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_18;
  int local_10;
  undefined1 local_c [12];
  
  local_18 = 1e+09;
  iVar5 = 0;
  local_10 = 0;
  if ((param_1 == 0) || (piVar2 = *(int **)(param_1 + 0x5074), piVar2 == (int *)0x0)) {
    return 0;
  }
  iVar3 = 0;
  if (0 < *piVar2) {
    do {
      iVar4 = piVar2[3] + iVar5;
      if (param_3 == 0) {
        fVar6 = (float10)FUN_005b3c50(param_2,iVar4 + 0x50,0);
LAB_00472e27:
        if ((float)fVar6 < local_18) {
          local_18 = (float)fVar6;
          local_10 = iVar4;
        }
      }
      else {
        bVar1 = *(byte *)(iVar4 + 99);
        if (((((bVar1 & 8) != 0) && ((bVar1 & 4) != 0)) && ((bVar1 & 3) == 0)) &&
           (*(float *)(iVar4 + 0x68) != 2e+06)) {
          FUN_00472800(iVar4,local_c);
          fVar6 = (float10)FUN_005b3c50(param_2,local_c,0);
          goto LAB_00472e27;
        }
      }
      piVar2 = *(int **)(param_1 + 0x5074);
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0xa0;
    } while (iVar3 < *piVar2);
  }
  if (param_4 != (float *)0x0) {
    *param_4 = local_18;
  }
  return local_10;
}

