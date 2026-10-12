/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x5672d0; label: FUN_005672d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005672d0(float *param_1,int param_2,int param_3,byte param_4,int param_5)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  float **ppfVar8;
  short *local_148;
  int local_144;
  float local_140;
  float local_13c;
  float local_138;
  int local_134;
  float local_130;
  float local_12c;
  float local_128;
  int local_124;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  undefined4 local_110 [12];
  float local_e0;
  float local_dc;
  float local_d8;
  float *local_d0 [7];
  undefined4 local_b4;
  int local_ac;
  uint local_a4;
  code *local_84;
  code *local_7c;
  undefined4 local_44;
  undefined1 local_c;
  
  local_130 = *param_1;
  local_12c = param_1[1];
  local_128 = param_1[2];
  iVar5 = *(int *)(param_2 + 0xa4);
  if (param_3 != 0) {
    local_130 = *(float *)(param_2 + 0x7c) + local_130;
    local_12c = *(float *)(param_2 + 0x80) + local_12c;
    local_128 = *(float *)(param_2 + 0x84) + local_128;
  }
  local_134 = iVar5;
  if ((param_4 & 1) != 0) {
    psVar2 = (short *)(iVar5 + 0xa8);
    local_144 = 3;
    do {
      if (*psVar2 != -1) {
        local_114 = 0xffffffff;
        FUN_00690460(&local_114,(int)*psVar2,&local_130,1);
      }
      psVar2 = psVar2 + 1;
      local_144 = local_144 + -1;
    } while (local_144 != 0);
  }
  if ((param_4 & 2) != 0) {
    local_148 = (short *)(iVar5 + 0xa0);
    local_144 = 2;
    do {
      if (*local_148 != -1) {
        FUN_0064b370((int)*local_148,&local_130,1);
      }
      local_148 = local_148 + 1;
      local_144 = local_144 + -1;
    } while (local_144 != 0);
  }
  if ((param_4 & 4) != 0) {
    iVar3 = (int)*(char *)(param_2 + 0x10d) * *(int *)(param_2 + 0xa0);
    local_120 = DAT_00802500;
    local_11c = DAT_00802504;
    local_118 = DAT_00802508;
    FUN_005b35a0(&local_120,&local_120,*(undefined2 *)(param_2 + 0xee));
    FUN_005b3620(&local_120,&local_120,*(undefined2 *)(param_2 + 0xf0));
    if (iVar3 < 1) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_0046c4f0();
    }
    FUN_0046d270(iVar3,uVar4,0,*(uint *)(param_2 + 0x98) >> 8 & 1,param_1,&local_120,0,0xffffffff,
                 0x3fc00000,0x49f42400,0,1,1);
  }
  if ((param_4 & 0x10) != 0) {
    FUN_00549bb0(PTR_DAT_008021b4,0x3f800000,0x3f800000,0x3f800000);
    FUN_0054a910(0x3f800000,0x3dcccccd,0,0);
  }
  if ((((*(uint *)(param_2 + 0x98) & 0x80000000) != 0) && ('\0' < *(char *)(param_2 + 0x110))) ||
     (*(char *)(param_2 + 0x110) < '\x01')) {
    local_124 = 4;
    local_148 = (short *)iVar5;
    do {
      iVar3 = FUN_005cfac0(local_148);
      if ((iVar3 != 0) && (local_144 = 0, *(char *)(iVar5 + 0xfa) != '\0')) {
        do {
          FUN_005b44e0(local_110);
          local_e0 = *param_1;
          local_dc = param_1[1];
          local_d8 = param_1[2];
          local_140 = DAT_00802500;
          local_13c = DAT_00802504;
          local_138 = DAT_00802508;
          FUN_0054fa60();
          FUN_006e6b90();
          sVar1 = FUN_006e6b90();
          FUN_005b35a0(&local_140,&local_140,(int)sVar1 + (uint)*(ushort *)(param_2 + 0xee));
          FUN_0054fa60();
          FUN_006e6b90();
          sVar1 = FUN_006e6b90();
          FUN_005b3620(&local_140,&local_140,(int)sVar1 + (uint)*(ushort *)(param_2 + 0xf0));
          FUN_005b3830(&local_140,&local_140,*(undefined4 *)(iVar5 + 0x98));
          iVar3 = local_134;
          if (param_5 != 0) {
            local_140 = local_140 + *(float *)(param_5 + 0x68) * 0.75;
            local_13c = *(float *)(param_5 + 0x6c) * 0.75 + local_13c;
            local_138 = *(float *)(param_5 + 0x70) * 0.75 + local_138;
          }
          puVar7 = &DAT_00810210;
          ppfVar8 = local_d0;
          for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppfVar8 = (float *)*puVar7;
            puVar7 = puVar7 + 1;
            ppfVar8 = ppfVar8 + 1;
          }
          local_44 = _DAT_00925018;
          local_d0[0] = (float *)local_110;
          local_d0[2] = &local_140;
          local_c = 1;
          local_7c = FUN_00571c80;
          local_84 = FUN_00571c50;
          local_b4 = *(undefined4 *)(local_134 + 0x94);
          local_a4 = local_a4 | 0x80;
          local_ac = (int)local_148;
          FUN_0064d270(local_d0);
          local_144 = local_144 + 1;
          iVar5 = local_134;
        } while (local_144 < (int)(uint)*(byte *)(iVar3 + 0xfa));
      }
      local_148 = (short *)((int)local_148 + 0xc);
      local_124 = local_124 + -1;
    } while (local_124 != 0);
  }
  if (DAT_00950bc4 == (code *)0x0) {
    FUN_00547930(0x33,param_1,0,0);
  }
  else {
    (*DAT_00950bc4)(param_2,param_1);
  }
  if ((param_4 & 8) != 0) {
    uVar6 = (-(uint)((*(uint *)(param_2 + 0x98) & 0x40) != 0) & 0xfb) + 0x27;
    if ((*(uint *)(param_2 + 0x98) & 0x10000000) != 0) {
      uVar6 = uVar6 | 8;
    }
    FUN_0056e5f0(param_1,*(undefined4 *)(param_2 + 0xb0),0x3f000000,0,0xffffffff,uVar6);
  }
  return;
}

