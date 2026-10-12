
void FUN_00502390(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  byte bVar1;
  char *pcVar2;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [24];
  
  if ((int *)param_1[0x13] == (int *)0x0) {
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *param_3 = *param_1;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
    }
    return;
  }
  iVar4 = *(int *)param_1[0x13];
  if ((0x414e4933 < iVar4) && (iVar4 < 0x414e4936)) {
    FUN_00502260(param_1,param_2,param_3);
    return;
  }
  iVar4 = param_1[0x13];
  pcVar2 = *(char **)(iVar4 + 0x10);
  bVar1 = **(byte **)(iVar4 + 0x14);
  pfVar3 = *(float **)(iVar4 + 0xc);
  FUN_005c9c40(iVar4,param_2,local_18);
  if ((bVar1 & 1) == 0) {
    FUN_005b44e0(param_3);
  }
  else {
    if (pcVar2[3] != '\0') {
      FUN_005c9520(pfVar3 + 3,local_18,(int)pcVar2[3]);
    }
    if (pcVar2[4] != '\0') {
      FUN_005c9520(pfVar3 + 4,local_18,(int)pcVar2[4]);
    }
    if (pcVar2[5] != '\0') {
      FUN_005c9520(pfVar3 + 5,local_18,(int)pcVar2[5]);
    }
    local_24 = FUN_006e6b90();
    local_20 = FUN_006e6b90();
    local_1c = FUN_006e6b90();
    FUN_005b5300(param_3,&local_24);
  }
  if ((bVar1 & 8) != 0) {
    if (pcVar2[6] == '\0') {
      fVar5 = (float10)pfVar3[6];
    }
    else {
      fVar5 = (float10)FUN_005c9520(pfVar3 + 6,local_18,(int)pcVar2[6]);
    }
    local_3c = (float)fVar5;
    if (pcVar2[7] == '\0') {
      fVar5 = (float10)pfVar3[7];
    }
    else {
      fVar5 = (float10)FUN_005c9520(pfVar3 + 7,local_18,(int)pcVar2[7]);
    }
    local_38 = (float)fVar5;
    if (pcVar2[8] == '\0') {
      fVar5 = (float10)pfVar3[8];
    }
    else {
      fVar5 = (float10)FUN_005c9520(pfVar3 + 8,local_18,(int)pcVar2[8]);
    }
    local_34 = (float)fVar5;
    FUN_005b4c30(param_3,&local_3c);
  }
  if (*pcVar2 == '\0') {
    fVar5 = (float10)*pfVar3;
  }
  else {
    fVar5 = (float10)FUN_005c9520(pfVar3,local_18,(int)*pcVar2);
  }
  local_30 = (float)fVar5;
  if (pcVar2[1] == '\0') {
    fVar5 = (float10)pfVar3[1];
  }
  else {
    fVar5 = (float10)FUN_005c9520(pfVar3 + 1,local_18,(int)pcVar2[1]);
  }
  local_2c = (float)fVar5;
  if (pcVar2[2] == '\0') {
    fVar5 = (float10)pfVar3[2];
  }
  else {
    fVar5 = (float10)FUN_005c9520(pfVar3 + 2,local_18,(int)pcVar2[2]);
  }
  local_28 = (float)fVar5;
  FUN_005b4900(param_3,&local_30);
  param_3[2] = -(float)param_3[2];
  param_3[6] = -(float)param_3[6];
  param_3[8] = -(float)param_3[8];
  param_3[9] = -(float)param_3[9];
  param_3[0xb] = -(float)param_3[0xb];
  param_3[0xe] = -(float)param_3[0xe];
  FUN_005b4900(param_3,param_1 + 0xc);
  return;
}

