/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f1c0; label: FUN_0056f1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056f1c0(float param_1,undefined4 param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar2 = (int)param_1;
  param_1 = 1e+09;
  piVar1 = *(int **)(iVar2 + 0x50b8);
  iVar4 = *piVar1;
  iVar5 = 0;
  iVar3 = 0;
  if (0 < piVar1[2]) {
    do {
      fVar6 = (float10)FUN_005b3c50(param_2,iVar4 + 8,0);
      if ((float)fVar6 < param_1) {
        iVar3 = iVar4;
        param_1 = (float)fVar6;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (iVar5 < *(int *)(*(int *)(iVar2 + 0x50b8) + 8));
  }
  if (param_3 != (float *)0x0) {
    *param_3 = param_1;
  }
  return iVar3;
}

