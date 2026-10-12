/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bb6b0; label: FUN_006bb6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bb6b0(undefined4 param_1,float param_2,float param_3,float param_4,int param_5,
                 uint param_6,int param_7,int param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float local_c8;
  float local_c4;
  uint local_c0;
  float local_bc;
  float local_b8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  float local_88;
  undefined4 local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_60;
  float local_5c;
  float local_50;
  float local_4c;
  float local_38;
  float local_28;
  float local_18;
  
  param_4 = param_4 / param_3;
  local_c0 = 0;
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  FUN_006ba6a0(0);
  uVar6 = 0;
  DAT_02973a68 = param_1;
  if (0 < param_5) {
    iVar8 = 0x10000;
    local_78 = param_2;
    local_74 = 0x3f800000;
    local_94 = 0x3f800000;
    fVar1 = -param_2;
    local_84 = 0x3f800000;
    local_bc = param_3 * DAT_029899a0;
    local_b8 = DAT_029919a0 * param_3;
    local_18 = fVar1;
    do {
      local_c0 = (uint)CONCAT11((char)(((int)param_6 >> 0x10 & 0xffU) * 0xdc >> 8),
                                (char)((param_6 >> 8 & 0xff) * 0xdc >> 8)) << 8 |
                 (int)((param_6 & 0xff) * 0xdc) >> 8 | param_6 & 0xff000000;
      if ((uVar6 & 1) == 0) {
        local_c0 = param_6;
      }
      fVar4 = (&DAT_029899a0)[iVar8 / param_5 >> 1 & 0x7fff] * param_3;
      fVar5 = (&DAT_029899a0)[iVar8 / param_5 + 0x4000 >> 1 & 0x7fff] * param_3;
      fVar2 = local_bc * param_4;
      fVar3 = local_b8 * param_4;
      local_a0 = fVar4 * param_4;
      local_9c = fVar5 * param_4;
      local_98 = param_2;
      local_90 = fVar4;
      local_8c = fVar5;
      local_88 = fVar1;
      local_80 = fVar2;
      local_7c = fVar3;
      local_70 = local_a0;
      local_6c = local_9c;
      local_60 = fVar2;
      local_5c = fVar3;
      local_38 = fVar1;
      FUN_006bb310(&local_80,&local_a0,&local_90,local_c0);
      local_90 = local_bc;
      local_8c = local_b8;
      local_88 = local_18;
      local_a0 = fVar4;
      local_9c = fVar5;
      local_98 = fVar1;
      local_80 = fVar2;
      local_7c = fVar3;
      local_50 = fVar2;
      local_4c = fVar3;
      local_28 = fVar1;
      FUN_006bb310(&local_80,&local_a0,&local_90,local_c0);
      uVar6 = uVar6 + 1;
      iVar8 = iVar8 + 0x10000;
      local_bc = fVar4;
      local_b8 = fVar5;
    } while ((int)uVar6 < param_5);
  }
  if ((param_7 != 0) || (param_8 != 0)) {
    fVar1 = DAT_029899a0 * param_3;
    iVar8 = (int)(0x10000 / (longlong)param_5);
    fVar2 = DAT_029919a0 * param_3;
    local_a4 = param_5 + -2;
    if (0 < local_a4) {
      iVar7 = 0x20000;
      local_c8 = (&DAT_029899a0)[iVar8 >> 1 & 0x7fff] * param_3;
      local_c4 = (&DAT_029899a0)[iVar8 + 0x4000 >> 1 & 0x7fff] * param_3;
      do {
        fVar3 = (&DAT_029899a0)[iVar7 / param_5 >> 1 & 0x7fff] * param_3;
        fVar4 = (&DAT_029899a0)[iVar7 / param_5 + 0x4000 >> 1 & 0x7fff] * param_3;
        if (param_8 != 0) {
          local_80 = fVar1 * param_4;
          local_7c = fVar2 * param_4;
          local_74 = 0x3f800000;
          local_a0 = fVar3 * param_4;
          local_9c = fVar4 * param_4;
          local_94 = 0x3f800000;
          local_90 = local_c8 * param_4;
          local_8c = local_c4 * param_4;
          local_84 = 0x3f800000;
          local_98 = param_2;
          local_88 = param_2;
          local_78 = param_2;
          local_70 = local_a0;
          local_6c = local_9c;
          local_60 = local_90;
          local_5c = local_8c;
          local_50 = local_80;
          local_4c = local_7c;
          FUN_006bb310(&local_80,&local_a0,&local_90,local_c0);
        }
        if (param_7 != 0) {
          local_98 = -param_2;
          local_74 = 0x3f800000;
          local_a0 = local_c8;
          local_9c = local_c4;
          local_94 = 0x3f800000;
          local_84 = 0x3f800000;
          local_90 = fVar3;
          local_8c = fVar4;
          local_88 = local_98;
          local_80 = fVar1;
          local_7c = fVar2;
          local_78 = local_98;
          local_38 = local_98;
          local_28 = local_98;
          local_18 = local_98;
          FUN_006bb310(&local_80,&local_a0,&local_90,local_c0);
        }
        iVar7 = iVar7 + 0x10000;
        local_a4 = local_a4 + -1;
        local_c8 = fVar3;
        local_c4 = fVar4;
      } while (local_a4 != 0);
    }
  }
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  FUN_006ba6a0(0);
  DAT_02973a68 = 0;
  return;
}

