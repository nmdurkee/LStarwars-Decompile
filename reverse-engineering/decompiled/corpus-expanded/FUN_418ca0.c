/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x418ca0; label: FUN_00418ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00418ca0(float param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float fStack_8;
  
  iVar3 = (int)param_1;
  iVar4 = *(int *)((int)param_1 + 0x50);
  iVar5 = *(int *)((int)param_1 + 0xca4);
  *(undefined2 *)((int)param_1 + 0x40) = *(undefined2 *)((int)param_1 + 0x3e);
  *(undefined2 *)((int)param_1 + 0x7f0) = *(undefined2 *)((int)param_1 + 0x7ee);
  if ((*(uint *)((int)param_1 + 0x1f8) & 0x40000) == 0) {
    (**(code **)(*(int *)((int)param_1 + 0x54) + 0x1c))(param_1);
  }
  sVar2 = *(short *)((int)param_1 + 0x3ee);
  if ((sVar2 != -1) &&
     (((sVar2 == 0xe9 && (*(char *)((int)param_1 + 0x7b5) != '\x1c')) ||
      (*(short *)((int)param_1 + 0x42) == sVar2)))) {
    *(undefined2 *)((int)param_1 + 0x42) = *(undefined2 *)((int)param_1 + 0x3f0);
  }
  if (((iVar4 == 0) ||
      ((*(char *)((int)param_1 + 0x28b) != '\0' && (*(float *)((int)param_1 + 0x100c) == 0.0)))) ||
     (*(char *)((int)param_1 + 0x28b) == '\x01')) {
    return;
  }
  fStack_8 = 1.0;
  if ((*(uint *)((int)param_1 + 0xef0) & 0x4000) != 0) {
    fStack_8 = -1.0;
  }
  if (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + 4) == 0) {
    if ((*(uint *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x90) & 0x100000) == 0) {
      fVar1 = *(float *)(iVar5 + 0x28);
    }
    else {
      fVar1 = *(float *)((int)param_1 + 0xf30) * *(float *)((int)param_1 + 0x68) +
              *(float *)((int)param_1 + 0xf38) * *(float *)((int)param_1 + 0x70);
      if (fVar1 < 0.0) {
        param_1 = 0.0;
        fVar1 = param_1;
      }
    }
  }
  else {
    fVar1 = *(float *)(iVar5 + 0x34);
    if (((0.0 < fVar1) && (*(short *)((int)param_1 + 0x1064) == DAT_007f1a50)) &&
       (iVar5 = FUN_0056e160(8), iVar5 == 0)) {
      fVar1 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x18);
    }
  }
  param_1 = fVar1;
  if ((*(char *)(iVar3 + 0x7b5) == '-') && (*(int *)(iVar3 + 0x798) != 0)) {
    fVar7 = (float10)FUN_0058fe80(iVar3);
  }
  else {
    fVar7 = (float10)1;
  }
  pfVar6 = (float *)(iVar3 + 8);
  FUN_0062e9b0(iVar4,pfVar6,_DAT_00925018 * 30.0 * (float)fVar7,param_1 * fStack_8,
               (float)fVar7 * _DAT_00925018,
               *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x20));
  if ((*(byte *)(iVar3 + 0x38) & 4) != 0) {
    if (*(char *)(iVar3 + 0x39) == '\0') {
      if (*(short *)(iVar3 + 0x3e) != 0x5f) goto LAB_00418f85;
    }
    else {
      if (*(short *)(iVar3 + 0x3c) != 0x5f) goto LAB_00418f85;
      pfVar6 = (float *)(iVar3 + 0x1c);
    }
    if (pfVar6 != (float *)0x0) {
      FUN_0062e040((int)*(short *)(iVar3 + 0x1064),0x5f,0,0,0);
      iVar4 = FUN_006e6b90();
      fVar7 = (float10)FUN_005b7d30((float)extraout_ST0,0x40400000);
      if ((float10)0.15 < fVar7) {
        iVar4 = iVar4 + 1;
      }
      iVar5 = FUN_0054fa60();
      iVar5 = iVar5 / ((int)(0xffff / (longlong)iVar4) + 1);
      fVar1 = *(float *)(*(int *)(*(int *)(*(int *)(iVar3 + 0x50) + 8) + 0x17c) + 0x18) * 0.3 *
              (float)iVar5 + 1.0;
      fVar7 = (float10)FUN_005ca470(*(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x50) + 0xc) + 0x17c))
      ;
      if ((float10)fVar1 < fVar7) {
        *pfVar6 = fVar1;
      }
      *(uint *)(iVar3 + 0xe20) =
           *(uint *)(iVar3 + 0xe20) ^ (iVar5 << 0xe ^ *(uint *)(iVar3 + 0xe20)) & 0x4000;
    }
  }
LAB_00418f85:
  FUN_0058dd90(iVar3);
  FUN_0058bc60(iVar3);
  return;
}

