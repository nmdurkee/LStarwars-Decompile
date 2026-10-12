/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd120; label: FUN_004cd120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004cd120(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_4;
  
  iVar1 = (int)param_1;
  param_1 = 1e+09;
  iVar3 = *(int *)(iVar1 + 0x5078);
  iVar4 = 0;
  local_4 = 0;
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0x507c)) {
    do {
      if (param_3 == 0) {
        iVar2 = iVar3 + 0x10;
LAB_004cd180:
        fVar5 = (float10)FUN_005b3c50(param_2,iVar2,0);
        if ((float)fVar5 < param_1) {
          param_1 = (float)fVar5;
          local_4 = iVar3;
        }
      }
      else if ((((*(byte *)(iVar3 + 0x3c) & 2) != 0) && ((*(byte *)(iVar3 + 0x3c) & 1) != 0)) &&
              (*(float *)(iVar3 + 0x20) != 2e+06)) {
        iVar2 = iVar3 + 0x1c;
        goto LAB_004cd180;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x70;
      iVar2 = local_4;
    } while (iVar4 < *(int *)(iVar1 + 0x507c));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar2;
}

