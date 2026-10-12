/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5def70; label: FUN_005def70
 */

void FUN_005def70(int *param_1)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50 [19];
  
  local_e4 = *(float *)(*param_1 + 0x110);
  iVar1 = param_1[2];
  if (param_1[1] == 0) {
    if (iVar1 == 0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = *(undefined4 **)(iVar1 + 0xc4);
      if ((puVar5 == (undefined4 *)0xffffffff) || (puVar5 == (undefined4 *)0x0)) {
        puVar5 = (undefined4 *)(iVar1 + 0x40);
      }
    }
  }
  else {
    puVar6 = *(undefined4 **)(param_1[1] + 0x40);
    puVar5 = (undefined4 *)puVar6[0x12];
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = puVar6;
    }
  }
  puVar6 = local_50;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  local_d0 = *(undefined4 *)(iVar1 + 0x80);
  local_cc = *(undefined4 *)(iVar1 + 0x84);
  local_c8 = *(undefined4 *)(iVar1 + 0x88);
  local_c0 = *(undefined4 *)(iVar1 + 0x90);
  local_bc = *(undefined4 *)(iVar1 + 0x94);
  local_b8 = *(undefined4 *)(iVar1 + 0x98);
  local_b0 = *(undefined4 *)(iVar1 + 0x80);
  local_ac = *(undefined4 *)(iVar1 + 0x84);
  local_a8 = *(undefined4 *)(iVar1 + 0x98);
  local_a0 = *(undefined4 *)(iVar1 + 0x90);
  local_9c = *(undefined4 *)(iVar1 + 0x94);
  local_98 = *(undefined4 *)(iVar1 + 0x88);
  local_90 = *(undefined4 *)(iVar1 + 0x80);
  local_8c = *(undefined4 *)(iVar1 + 0x94);
  local_88 = *(undefined4 *)(iVar1 + 0x88);
  local_80 = *(undefined4 *)(iVar1 + 0x80);
  local_7c = *(undefined4 *)(iVar1 + 0x94);
  local_78 = *(undefined4 *)(iVar1 + 0x98);
  local_70 = *(undefined4 *)(iVar1 + 0x90);
  local_6c = *(undefined4 *)(iVar1 + 0x84);
  local_68 = *(undefined4 *)(iVar1 + 0x88);
  local_60 = *(undefined4 *)(iVar1 + 0x90);
  local_5c = *(undefined4 *)(iVar1 + 0x84);
  local_58 = *(undefined4 *)(iVar1 + 0x98);
  FUN_005b30a0(&local_d0,&local_d0,local_50);
  FUN_005b30a0(&local_c0,&local_c0,local_50);
  FUN_005b30a0(&local_b0,&local_b0,local_50);
  FUN_005b30a0(&local_a0,&local_a0,local_50);
  FUN_005b30a0(&local_90,&local_90,local_50);
  FUN_005b30a0(&local_80,&local_80,local_50);
  FUN_005b30a0(&local_70,&local_70,local_50);
  FUN_005b30a0(&local_60,&local_60,local_50);
  FUN_005b3aa0(&local_110,&local_d0,&local_c0);
  FUN_005b3aa0(&local_110,&local_110,&local_b0);
  FUN_005b3aa0(&local_110,&local_110,&local_a0);
  FUN_005b3aa0(&local_110,&local_110,&local_90);
  FUN_005b3aa0(&local_110,&local_110,&local_80);
  FUN_005b3aa0(&local_110,&local_110,&local_70);
  FUN_005b3aa0(&local_110,&local_110,&local_60);
  FUN_005b3a40(&local_120,&local_d0,&local_c0);
  FUN_005b3a40(&local_120,&local_120,&local_b0);
  FUN_005b3a40(&local_120,&local_120,&local_a0);
  FUN_005b3a40(&local_120,&local_120,&local_90);
  FUN_005b3a40(&local_120,&local_120,&local_80);
  FUN_005b3a40(&local_120,&local_120,&local_70);
  FUN_005b3a40(&local_120,&local_120,&local_60);
  fVar2 = local_e4;
  if ((*(uint *)((int)local_e4 + 0x74) & 0x4000) == 0) {
    pfVar3 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + *(int *)((int)local_e4 + 0x44));
    *pfVar3 = local_110;
    pfVar3[1] = local_10c;
    pfVar3[2] = local_108;
    pfVar3[3] = local_104;
    pfVar3 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + 0x10 + *(int *)((int)local_e4 + 0x44));
    *pfVar3 = local_120;
    pfVar3[1] = local_11c;
    pfVar3[2] = local_118;
    pfVar3[3] = local_114;
  }
  else {
    local_e0 = (local_110 + local_120) * 0.5;
    local_dc = (local_10c + local_11c) * 0.5;
    local_d8 = (local_108 + local_118) * 0.5;
    local_100 = (local_120 - local_110) * 0.5;
    local_fc = (local_11c - local_10c) * 0.5;
    local_f8 = (local_118 - local_108) * 0.5;
    local_e4 = local_fc + local_100 + local_f8;
    fVar7 = (float10)FUN_005c0240(local_e4);
    local_d4 = (float)fVar7;
    pfVar3 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + *(int *)((int)fVar2 + 0x44));
    *pfVar3 = local_e0;
    pfVar3[1] = local_dc;
    pfVar3[2] = local_d8;
    pfVar3[3] = local_d4;
    pfVar3 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + 0x10 + *(int *)((int)fVar2 + 0x44));
    *pfVar3 = local_100;
    pfVar3[1] = local_fc;
    pfVar3[2] = local_f8;
    pfVar3[3] = local_f4;
  }
  thunk_FUN_005f7490(param_1,local_50);
  return;
}

