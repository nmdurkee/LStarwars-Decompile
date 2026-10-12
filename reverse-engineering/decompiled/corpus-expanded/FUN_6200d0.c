/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x6200d0; label: FUN_006200d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006200d0(float *param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float local_64;
  float local_60;
  float local_5c;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  pfVar4 = param_1;
  fVar2 = param_2 / 0.016666668;
  fVar3 = 1.0;
  if (param_1[0x21] == 0.0) {
    param_1 = (float *)0x3f800000;
  }
  else {
    param_1 = (float *)(param_1[0x21] * ABS(param_1[5]) + param_1[0x20]);
  }
  if (pfVar4[0x23] != 0.0) {
    fVar3 = ABS(pfVar4[5]) * pfVar4[0x23] + pfVar4[0x22];
  }
  fVar1 = pfVar4[3];
  local_5c = 0.0;
  local_60 = 0.0;
  local_64 = 0.0;
  puVar8 = &DAT_00806680;
  puVar9 = local_40;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  FUN_005b4cf0(local_40,fVar1);
  FUN_005b4f70(local_40,pfVar4[4]);
  local_5c = -pfVar4[5];
  FUN_005b3200(&local_64,&local_64,local_40);
  FUN_005b37d0(local_4c,pfVar4,&local_64);
  FUN_006dec10(*(undefined1 *)(param_3 + 0x90),0x20);
  iVar7 = FUN_006e6b90();
  FUN_006dec10(*(undefined1 *)(param_3 + 0x91),0x20);
  iVar5 = FUN_006e6b90();
  fVar1 = pfVar4[0x24];
  if (((uint)fVar1 & 0x40) != 0) {
    iVar5 = -iVar5;
  }
  if (((uint)fVar1 & 8) != 0) {
    pfVar4[3] = (float)((int)pfVar4[3] + iVar5);
    fVar6 = pfVar4[3];
    if (0x4000 < (int)fVar6) {
      fVar6 = 2.29589e-41;
    }
    pfVar4[3] = fVar6;
    if ((int)fVar6 < -0x4000) {
      fVar6 = -NAN;
    }
    pfVar4[3] = fVar6;
  }
  if (((uint)fVar1 & 0x10) != 0) {
    pfVar4[4] = (float)((int)pfVar4[4] + iVar7);
  }
  puVar8 = &DAT_00806680;
  puVar9 = local_40;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  FUN_005b4cf0(local_40,pfVar4[3]);
  FUN_005b4f70(local_40,pfVar4[4]);
  local_60 = 0.0;
  local_64 = 0.0;
  local_5c = -pfVar4[5];
  FUN_005b3200(&local_64,&local_64,local_40);
  FUN_005b37d0(local_58,pfVar4,&local_64);
  FUN_005b37d0(pfVar4,pfVar4,local_58);
  FUN_005b3800(pfVar4,pfVar4,local_4c);
  local_5c = 0.0;
  local_60 = 0.0;
  local_64 = 0.0;
  iVar7 = FUN_006dec10(*(undefined1 *)(param_3 + 0x92),0x20);
  local_64 = 0.0 - (float)iVar7 * param_2 * pfVar4[5] * 0.01;
  iVar7 = FUN_006dec10(*(undefined1 *)(param_3 + 0x93),0x20);
  local_5c = (float)iVar7 * param_2 * pfVar4[5] * 0.01 + local_5c;
  local_60 = (local_60 +
             fVar2 * (float)param_1 * (float)*(byte *)(param_3 + 0x9c) * pfVar4[0x17] * 0.5) -
             fVar2 * (float)*(byte *)(param_3 + 0x9e) * pfVar4[0x17] * (float)param_1 * 0.5;
  if (((uint)pfVar4[0x24] & 0x20) != 0) {
    fVar1 = pfVar4[5] + fVar2 * fVar3 * (float)*(byte *)(param_3 + 0x9d) * pfVar4[0x1b];
    pfVar4[5] = fVar1;
    fVar1 = fVar1 - (float)*(byte *)(param_3 + 0x9f) * pfVar4[0x1b] * fVar3 * fVar2;
    pfVar4[5] = fVar1;
    if (fVar1 <= -pfVar4[0x1c]) {
      pfVar4[5] = fVar1;
    }
    else {
      pfVar4[5] = -pfVar4[0x1c];
    }
  }
  FUN_005b3200(&local_64,&local_64,local_40);
  fVar2 = pfVar4[0x24];
  if (((uint)fVar2 & 1) != 0) {
    *pfVar4 = *pfVar4 + local_64;
  }
  if (((uint)fVar2 & 2) != 0) {
    pfVar4[1] = local_60 + pfVar4[1];
  }
  if (((uint)fVar2 & 4) != 0) {
    pfVar4[2] = pfVar4[2] + local_5c;
  }
  return;
}

