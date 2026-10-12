/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x500e50; label: FUN_00500e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00500e50(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  float *pfVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((int *)param_1[0x14] == (int *)0x0) {
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *param_3 = *param_1;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
    }
    return 0;
  }
  iVar4 = *(int *)param_1[0x14];
  if ((0x414e4933 < iVar4) && (iVar4 < 0x414e4936)) {
    uVar3 = FUN_00500d50(param_1,param_3,param_2);
    return uVar3;
  }
  iVar4 = param_1[0x14];
  pfVar1 = *(float **)(iVar4 + 0xc);
  pcVar2 = *(char **)(iVar4 + 0x10);
  if ((**(byte **)(iVar4 + 0x14) & 1) == 0) {
    FUN_005b44e0(param_3);
  }
  else {
    if (pcVar2[3] != '\0') {
      FUN_005c9520(pfVar1 + 3,param_4,(int)pcVar2[3]);
    }
    if (pcVar2[4] != '\0') {
      FUN_005c9520(pfVar1 + 4,param_4,(int)pcVar2[4]);
    }
    if (pcVar2[5] != '\0') {
      FUN_005c9520(pfVar1 + 5,param_4,(int)pcVar2[5]);
    }
    local_c = FUN_006e6b90();
    local_8 = FUN_006e6b90();
    local_4 = FUN_006e6b90();
    FUN_005b5300(param_3,&local_c);
  }
  if (*pcVar2 == '\0') {
    fVar5 = (float10)*pfVar1;
  }
  else {
    fVar5 = (float10)FUN_005c9520(pfVar1,param_4,(int)*pcVar2);
  }
  local_18 = (float)fVar5;
  if (pcVar2[1] == '\0') {
    fVar5 = (float10)pfVar1[1];
  }
  else {
    fVar5 = (float10)FUN_005c9520(pfVar1 + 1,param_4,(int)pcVar2[1]);
  }
  local_14 = (float)fVar5;
  if (pcVar2[2] == '\0') {
    fVar5 = (float10)pfVar1[2];
  }
  else {
    fVar5 = (float10)FUN_005c9520(pfVar1 + 2,param_4,(int)pcVar2[2]);
  }
  local_10 = (float)fVar5;
  FUN_005b4900(param_3,&local_18);
  param_3[2] = -(float)param_3[2];
  param_3[6] = -(float)param_3[6];
  param_3[8] = -(float)param_3[8];
  param_3[9] = -(float)param_3[9];
  param_3[0xb] = -(float)param_3[0xb];
  param_3[0xe] = -(float)param_3[0xe];
  FUN_005b4900(param_3,param_1 + 0xc);
  return 0;
}

