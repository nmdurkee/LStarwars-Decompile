
int * FUN_005e91f0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (DAT_00973868 == 0) {
    FUN_005c9140();
  }
  if (param_1 == 0) {
    return (int *)0x0;
  }
  piVar5 = (int *)(param_1 + param_2);
  if (piVar5 != (int *)0x0) {
    if ((0x414e4933 < *piVar5) && (*piVar5 < 0x414e4936)) {
      if (param_3 == 0) {
        FUN_005ca320(piVar5,piVar5,param_4);
        return piVar5;
      }
      FUN_005ca320(piVar5,param_2,param_4);
      return piVar5;
    }
    if (piVar5[3] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = piVar5[3] + param_2;
    }
    piVar5[3] = iVar2;
    if (piVar5[4] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = piVar5[4] + param_2;
    }
    piVar5[4] = iVar2;
    if (piVar5[5] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = piVar5[5] + param_2;
    }
    iVar4 = (int)*(short *)((int)piVar5 + 6) * (int)(short)piVar5[1];
    iVar6 = 0;
    piVar5[5] = iVar2;
    if (0 < iVar4) {
      do {
        if (*(char *)(iVar6 + piVar5[4]) != '\0') {
          piVar1 = (int *)(piVar5[3] + iVar6 * 4);
          if (*piVar1 == 0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = (int *)(*piVar1 + param_2);
          }
          *piVar1 = (int)piVar3;
          if (*piVar3 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = *piVar3 + param_2;
          }
          *piVar3 = iVar2;
          iVar2 = *(int *)(*piVar1 + 4);
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = iVar2 + param_2;
          }
          *(int *)(*piVar1 + 4) = iVar2;
          iVar2 = *(int *)(*piVar1 + 8);
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = iVar2 + param_2;
          }
          *(int *)(*piVar1 + 8) = iVar2;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar4);
    }
  }
  return piVar5;
}

