/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x60f850; label: FUN_0060f850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f850(float param_1,float param_2,float param_3,float param_4,int param_5)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  float10 fVar12;
  float10 fVar13;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  double local_8c;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_a4;
  uVar10 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar11 = 0;
  puVar5 = (uint *)(in_ECX + 0x48);
  local_9c = 7.00649e-45;
  do {
    if (uVar10 <= puVar5[-2]) {
      uVar10 = puVar5[-2];
    }
    if (uVar8 <= puVar5[-1]) {
      uVar8 = puVar5[-1];
    }
    if (uVar9 <= *puVar5) {
      uVar9 = *puVar5;
    }
    if (uVar11 <= puVar5[1]) {
      uVar11 = puVar5[1];
    }
    if (uVar10 <= puVar5[2]) {
      uVar10 = puVar5[2];
    }
    if (uVar8 <= puVar5[3]) {
      uVar8 = puVar5[3];
    }
    if (uVar9 <= puVar5[4]) {
      uVar9 = puVar5[4];
    }
    if (uVar11 <= puVar5[5]) {
      uVar11 = puVar5[5];
    }
    if (uVar10 <= puVar5[6]) {
      uVar10 = puVar5[6];
    }
    if (uVar8 <= puVar5[7]) {
      uVar8 = puVar5[7];
    }
    if (uVar9 <= puVar5[8]) {
      uVar9 = puVar5[8];
    }
    if (uVar11 <= puVar5[9]) {
      uVar11 = puVar5[9];
    }
    if (uVar10 <= puVar5[10]) {
      uVar10 = puVar5[10];
    }
    if (uVar8 <= puVar5[0xb]) {
      uVar8 = puVar5[0xb];
    }
    if (uVar9 <= puVar5[0xc]) {
      uVar9 = puVar5[0xc];
    }
    if (uVar11 <= puVar5[0xd]) {
      uVar11 = puVar5[0xd];
    }
    if (uVar10 <= puVar5[0xe]) {
      uVar10 = puVar5[0xe];
    }
    if (uVar8 <= puVar5[0xf]) {
      uVar8 = puVar5[0xf];
    }
    if (uVar9 <= puVar5[0x10]) {
      uVar9 = puVar5[0x10];
    }
    if (uVar11 <= puVar5[0x11]) {
      uVar11 = puVar5[0x11];
    }
    if (uVar10 <= puVar5[0x12]) {
      uVar10 = puVar5[0x12];
    }
    if (uVar8 <= puVar5[0x13]) {
      uVar8 = puVar5[0x13];
    }
    if (uVar9 <= puVar5[0x14]) {
      uVar9 = puVar5[0x14];
    }
    if (uVar11 <= puVar5[0x15]) {
      uVar11 = puVar5[0x15];
    }
    puVar5 = puVar5 + 0x18;
    local_9c = (float)((int)local_9c + -1);
  } while (local_9c != 0.0);
  local_a4 = param_3 * 0.5;
  local_90 = local_a4 / 30.0;
  uVar6 = uVar10;
  if (uVar10 <= uVar8) {
    uVar6 = uVar8;
  }
  fVar3 = (float)(int)uVar6;
  if ((int)uVar6 < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  local_9c = 4352.0;
  if (4352.0 < fVar3) {
    if (uVar10 <= uVar8) {
      uVar10 = uVar8;
    }
    local_9c = (float)(int)uVar10;
    if ((int)uVar10 < 0) {
      local_9c = local_9c + 4.2949673e+09;
    }
  }
  local_94 = param_4 / local_9c;
  if (uVar9 <= uVar11) {
    uVar9 = uVar11;
  }
  local_98 = (float)(int)uVar9;
  if ((int)uVar9 < 0) {
    local_98 = local_98 + 4.2949673e+09;
  }
  local_98 = param_4 / local_98;
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(1);
  FUN_00607d70(0xf,5,0);
  FUN_0060f3d0();
  fVar12 = (float10)param_1;
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = param_1;
  pfVar1[1] = param_2;
  *(undefined4 *)(*DAT_02854d10 + 8) = 0;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  fVar13 = (float10)FUN_0060f3d0();
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = (float)fVar12;
  local_8c = (double)(extraout_ST1 - (float10)param_4);
  local_9c = (float)(extraout_ST1 - (float10)param_4);
  fVar12 = (float10)local_9c;
  pfVar1[1] = local_9c;
  *(float *)(*DAT_02854d10 + 8) = (float)fVar13;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  fVar13 = (float10)FUN_0060f3d0();
  pfVar1 = (float *)*DAT_02854d10;
  local_9c = (float)((float10)local_a4 + extraout_ST1_00);
  *pfVar1 = local_9c;
  pfVar1[1] = (float)fVar12;
  *(float *)(*DAT_02854d10 + 8) = (float)fVar13;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009a0();
  FUN_00607d70(0xf,5,0);
  FUN_0060f3d0();
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = param_1;
  local_a4 = local_94 * 4352.0 + (float)local_8c;
  pfVar1[1] = local_a4;
  *(undefined4 *)(*DAT_02854d10 + 8) = 0;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  fVar12 = (float10)FUN_0060f3d0();
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = local_9c;
  pfVar1[1] = (float)extraout_ST1_01;
  *(float *)(*DAT_02854d10 + 8) = (float)fVar12;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009a0();
  FUN_00607d70(0xf,5,0);
  iVar7 = *(int *)(in_ECX + 0x18);
  local_a4 = 0.0;
  do {
    iVar7 = iVar7 + 1;
    if (0x1d < iVar7) {
      iVar7 = 0;
    }
    if (param_5 == 0) {
      iVar2 = *(int *)((iVar7 + 4) * 0x10 + in_ECX);
      local_a0 = (float)iVar2;
      if (iVar2 < 0) {
        local_a0 = local_a0 + 4.2949673e+09;
      }
      local_a0 = local_a0 * local_94;
LAB_0060fc20:
      local_a0 = local_a0 + (float)local_8c;
    }
    else if (param_5 == 1) {
      iVar2 = *(int *)(iVar7 * 0x10 + 0x48 + in_ECX);
      local_a0 = (float)iVar2;
      if (iVar2 < 0) {
        local_a0 = local_a0 + 4.2949673e+09;
      }
      local_a0 = local_a0 * local_98;
      goto LAB_0060fc20;
    }
    if (DAT_02854c31 == '\0') {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0x80004000;
    }
    else {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0x80008000;
    }
    pfVar1 = (float *)*DAT_02854d10;
    *pfVar1 = (float)(int)local_a4 * local_90 + param_1;
    local_a4 = (float)((int)local_a4 + 1);
    pfVar1[1] = local_a0;
    *(undefined4 *)(*DAT_02854d10 + 8) = 0;
    *DAT_02854d10 = *DAT_02854d10 + 0x18;
    DAT_02854d14 = DAT_02854d14 + 1;
  } while ((int)local_a4 < 0x1e);
  FUN_006009a0();
  FUN_00607d70(0xf,5,0);
  fVar3 = local_98;
  iVar7 = *(int *)(in_ECX + 0x18);
  local_a4 = 0.0;
  do {
    iVar7 = iVar7 + 1;
    if (0x1d < iVar7) {
      iVar7 = 0;
    }
    if (param_5 == 0) {
      local_98 = *(float *)(iVar7 * 0x10 + 0x44 + in_ECX);
      local_a0 = (float)(int)local_98;
      if ((int)local_98 < 0) {
        local_a0 = local_a0 + 4.2949673e+09;
      }
      local_a0 = local_a0 * local_94;
LAB_0060fd31:
      local_a0 = local_a0 + (float)local_8c;
    }
    else if (param_5 == 1) {
      local_98 = *(float *)(iVar7 * 0x10 + 0x4c + in_ECX);
      local_a0 = (float)(int)local_98;
      if ((int)local_98 < 0) {
        local_a0 = local_a0 + 4.2949673e+09;
      }
      local_a0 = local_a0 * fVar3;
      goto LAB_0060fd31;
    }
    if (DAT_02854c31 == '\0') {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0x80404000;
    }
    else {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0x80808000;
    }
    pfVar1 = (float *)*DAT_02854d10;
    *pfVar1 = (float)(int)local_a4 * local_90 + param_1;
    local_a4 = (float)((int)local_a4 + 1);
    pfVar1[1] = local_a0;
    *(undefined4 *)(*DAT_02854d10 + 8) = 0;
    *DAT_02854d10 = *DAT_02854d10 + 0x18;
    DAT_02854d14 = DAT_02854d14 + 1;
    if (0x1d < (int)local_a4) {
      FUN_006009a0();
      iVar7 = DAT_02854d1c * 4;
      DAT_02854d1c = DAT_02854d1c + -1;
      FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar7));
      FUN_005d0a40(3);
      FUN_005d0880(2);
      uVar4 = DAT_009738b8;
      fVar12 = (float10)FUN_005d0e80(DAT_009738b8);
      local_94 = (float)fVar12;
      local_a4 = local_9c;
      FUN_005d1060(uVar4,0x80808080);
      FUN_005d0fe0(uVar4,0x3f400000,0x3f400000);
      local_a0 = local_94 + param_2;
      FUN_005eabb0(uVar4,local_a4,local_a0,0);
      FUN_005f3510(uVar4,*(undefined4 *)(in_ECX + 4));
      local_a0 = local_94 + local_a0;
      FUN_005eabb0(uVar4,local_a4,local_a0,0);
      FUN_004f2740(local_84,"bps %d : %d",
                   *(undefined4 *)((*(int *)(in_ECX + 0x18) + 4) * 0x10 + in_ECX),
                   *(undefined4 *)(*(int *)(in_ECX + 0x18) * 0x10 + 0x44 + in_ECX));
      FUN_005f3510(uVar4,local_84);
      local_a0 = local_94 + local_a0;
      FUN_005eabb0(uVar4,local_a4,local_a0,0);
      iVar7 = *(int *)(in_ECX + 0x18) * 0x10;
      FUN_004f2740(local_84,"pps %d : %d",*(undefined4 *)(iVar7 + 0x48 + in_ECX),
                   *(undefined4 *)(iVar7 + 0x4c + in_ECX));
      FUN_005f3510(uVar4,local_84);
      local_a0 = local_94 + local_a0;
      FUN_005eabb0(uVar4,local_a4,local_a0,0);
      FUN_004f2740(local_84,"max bps %d : %d",*(undefined4 *)(in_ECX + 0x20),
                   *(undefined4 *)(in_ECX + 0x24));
      FUN_005f3510(uVar4,local_84);
      local_98 = local_94 + local_a0;
      FUN_005eabb0(uVar4,local_a4,local_98,0);
      FUN_004f2740(local_84,"max pps %d : %d",*(undefined4 *)(in_ECX + 0x28),
                   *(undefined4 *)(in_ECX + 0x2c));
      FUN_005f3510(uVar4,local_84);
      FUN_005d08c0();
      FUN_005d0a70();
      __security_check_cookie(local_4 ^ (uint)&local_a4);
      return;
    }
  } while( true );
}

