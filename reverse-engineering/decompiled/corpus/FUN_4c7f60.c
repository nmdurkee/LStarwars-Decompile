/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c7f60; label: FUN_004c7f60
 */

int FUN_004c7f60(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_4;
  
  iVar2 = (int)param_1;
  param_1 = 1e+09;
  iVar4 = *(int *)(iVar2 + 0x5060);
  iVar5 = 0;
  local_4 = 0;
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x5064)) {
    do {
      if (param_3 == 0) {
        iVar3 = iVar4 + 0x50;
LAB_004c7fce:
        fVar6 = (float10)FUN_005b3c50(param_2,iVar3,0);
        if ((float)fVar6 < param_1) {
          param_1 = (float)fVar6;
          local_4 = iVar4;
        }
      }
      else {
        bVar1 = *(byte *)(iVar4 + 0x6a);
        if (((((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 4) == 0)) &&
           (*(short *)(*(int *)(iVar4 + 0x80) + 0x14) == *(short *)(param_3 + 0x1064))) {
          iVar3 = iVar4 + 0x84;
          goto LAB_004c7fce;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x94;
      iVar3 = local_4;
    } while (iVar5 < *(int *)(iVar2 + 0x5064));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar3;
}

