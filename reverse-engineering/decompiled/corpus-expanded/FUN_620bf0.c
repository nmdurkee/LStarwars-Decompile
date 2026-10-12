/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x620bf0; label: FUN_00620bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00620bf0(float *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_64;
  float local_60;
  float local_5c;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  if (param_1[0x23] == 0.0) {
    fVar1 = 1.0;
  }
  else {
    fVar1 = ABS(param_1[5]) * param_1[0x23] + param_1[0x22];
  }
  FUN_006d5bc0();
  FUN_006d5bb0();
  fVar8 = (float10)FUN_006d5bd0();
  iVar2 = FUN_006d58b0();
  if (((uint)param_1[0x24] & 0x20) != 0) {
    fVar1 = param_1[5] - param_1[0x1b] * (float)fVar8 * fVar1;
    param_1[5] = fVar1;
    if (-param_1[0x1c] < fVar1) {
      fVar1 = -param_1[0x1c];
    }
    param_1[5] = fVar1;
  }
  local_5c = 0.0;
  local_60 = 0.0;
  local_64 = 0.0;
  puVar6 = &DAT_00806680;
  puVar7 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  FUN_005b4cf0(local_40,param_1[3]);
  FUN_005b4f70(local_40,param_1[4]);
  local_5c = -param_1[5];
  FUN_005b3200(&local_64,&local_64,local_40);
  FUN_005b37d0(local_4c,param_1,&local_64);
  iVar5 = FUN_006e6b90();
  fVar1 = param_1[0x24];
  if (((uint)fVar1 & 8) != 0) {
    iVar3 = FUN_006e6b90();
    param_1[3] = (float)((int)param_1[3] + iVar3);
  }
  fVar4 = param_1[3];
  if (0x4000 < (int)fVar4) {
    fVar4 = 2.29589e-41;
  }
  param_1[3] = fVar4;
  if ((int)fVar4 < -0x4000) {
    fVar4 = -NAN;
  }
  param_1[3] = fVar4;
  if (((uint)fVar1 & 0x10) != 0) {
    param_1[4] = (float)((int)param_1[4] + iVar5);
  }
  puVar6 = &DAT_00806680;
  puVar7 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  FUN_005b4cf0(local_40,fVar4);
  FUN_005b4f70(local_40,param_1[4]);
  local_60 = 0.0;
  local_64 = 0.0;
  local_5c = -param_1[5];
  FUN_005b3200(&local_64,&local_64,local_40);
  FUN_005b37d0(local_58,param_1,&local_64);
  FUN_005b37d0(param_1,param_1,local_58);
  FUN_005b3800(param_1,param_1,local_4c);
  local_5c = 0.0;
  local_60 = 0.0;
  local_64 = 0.0;
  if (iVar2 == 1) {
    param_2 = -param_2;
  }
  else if (iVar2 != 2) goto LAB_00620e1a;
  local_5c = param_2 * param_1[5];
LAB_00620e1a:
  FUN_005b3200(&local_64,&local_64,local_40);
  fVar1 = param_1[0x24];
  if (((uint)fVar1 & 1) != 0) {
    *param_1 = *param_1 + local_64;
  }
  if (((uint)fVar1 & 2) != 0) {
    param_1[1] = param_1[1] + local_60;
  }
  if (((uint)fVar1 & 4) != 0) {
    param_1[2] = param_1[2] + local_5c;
  }
  return;
}

