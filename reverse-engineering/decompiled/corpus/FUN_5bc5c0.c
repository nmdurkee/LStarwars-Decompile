/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5bc5c0; label: FUN_005bc5c0
 */

float10 FUN_005bc5c0(int param_1,int param_2,int param_3,float param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  
  if (param_2 == 1) {
    if (((float)*(int *)(param_3 + param_1 * 4) <= param_4) &&
       (param_4 < (float)*(int *)(param_3 + 4 + param_1 * 4))) {
      return (float10)1.0;
    }
    return (float10)0.0;
  }
  iVar2 = *(int *)(param_3 + param_1 * 4);
  piVar1 = (int *)(param_3 + (param_1 + param_2) * 4);
  if (piVar1[-1] == iVar2) {
    if (*piVar1 == *(int *)(param_3 + 4 + param_1 * 4)) {
      return (float10)0.0;
    }
    if (piVar1[-1] == iVar2) {
      iVar2 = *piVar1;
      fVar5 = (float10)FUN_005bc5c0(param_1 + 1,param_2 + -1,param_3,param_4);
      return (float10)(float)((((float10)iVar2 - (float10)param_4) /
                              (float10)(iVar2 - *(int *)(param_3 + 4 + param_1 * 4))) * fVar5);
    }
  }
  iVar3 = *piVar1;
  param_2 = param_2 + -1;
  if (iVar3 != *(int *)(param_3 + 4 + param_1 * 4)) {
    fVar5 = (float10)FUN_005bc5c0(param_1 + 1,param_2,param_3,param_4);
    iVar2 = *(int *)(param_3 + 4 + param_1 * 4);
    iVar4 = *(int *)(param_3 + param_1 * 4);
    fVar6 = (float10)FUN_005bc5c0(param_1,param_2,param_3,param_4);
    return (float10)(float)((((float10)param_4 - (float10)iVar4) / (float10)(piVar1[-1] - iVar4)) *
                            fVar6 + (float10)(double)(fVar5 * (((float10)iVar3 - (float10)param_4) /
                                                              (float10)(iVar3 - iVar2))));
  }
  fVar5 = (float10)FUN_005bc5c0(param_1,param_2,param_3,param_4);
  return (float10)(float)((((float10)param_4 - (float10)iVar2) / (float10)(piVar1[-1] - iVar2)) *
                         fVar5);
}

