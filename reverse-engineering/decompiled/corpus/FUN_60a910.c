/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a910; label: FUN_0060a910
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060a910(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94 [2];
  int *local_8c;
  int local_88;
  int local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined1 local_54 [4];
  undefined1 local_50 [76];
  
  local_8c = *(int **)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar1 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  piVar2 = *(int **)(DAT_0080bbc4 + DAT_0080bbc0 * 0x28);
  if (*(char *)((int)piVar1 + 9) == '\0') {
    *(undefined1 *)((int)piVar1 + 9) = 1;
  }
  puVar3 = (undefined4 *)*piVar2;
  if ((puVar3 != (undefined4 *)0x0) && (*(char *)((int)piVar2 + 9) == '\0')) {
    *(undefined1 *)((int)piVar2 + 9) = 1;
  }
  local_88 = *local_8c;
  local_84 = *piVar1;
  FUN_006e2320(in_ECX + 0x128,2,0);
  if (puVar3 == (undefined4 *)0x0) {
    uVar5 = 2;
  }
  else {
    if (DAT_0080ea1f != '\0') {
      local_cc = *(float *)(in_ECX + 0x144);
      FUN_005fb870(DAT_02854c2c,0,0);
      *(undefined4 *)((int)local_cc + 0xa0) = 1;
      DAT_0080ea1f = '\0';
    }
    FUN_005f8bf0(*(undefined4 *)(in_ECX + 0x144));
    local_b0 = 0;
    local_c0 = 0.0;
    local_ac = 0x3f800000;
    local_bc = 0.0;
    local_b8 = (float)DAT_0080e188;
    local_b4 = (float)DAT_0080e18c;
    FUN_006e57b0(&local_c0);
    if ((DAT_0097f9b8 != puVar3[8]) || (DAT_0097f9bc != puVar3[9])) {
      FUN_005fa540(0,puVar3 + 8);
    }
    FUN_006e5630(0,*puVar3);
    FUN_005fa0a0();
    FUN_006e2810(1,0,0);
    FUN_006e23e0();
    FUN_006e5630(0,0);
    FUN_006e2810(0,0,0);
    uVar5 = 5;
  }
  FUN_0060a830(DAT_02854c2c,0,DAT_02854c2c,0,uVar5,1,0,0x3f800000,DAT_00973814);
  piVar2 = local_8c;
  FUN_005f8bf0(local_8c);
  local_b4 = DAT_00973904;
  local_b8 = DAT_00973900;
  if ((piVar2 != DAT_02854bc8) && (piVar2 != DAT_028492f4)) {
    local_b4 = (float)(uint)*(ushort *)(local_88 + 6);
    local_b8 = (float)(uint)*(ushort *)(local_88 + 4);
  }
  local_bc = 0.0;
  local_c0 = 0.0;
  local_b0 = 0;
  local_ac = 0x3f800000;
  FUN_006e57b0(&local_c0);
  FUN_005fa0a0();
  if (DAT_02974d1c < 4) {
    FUN_005b5e90(local_50,&DAT_00986eb8);
    FUN_006e5750(0xc,local_50,4);
    FUN_005bfe80(&DAT_0280d820,local_54,&local_c8,&local_cc,&local_c4);
    local_c0 = local_cc;
    local_bc = local_c4;
    local_b8 = local_c4 - local_cc;
    local_b4 = 1.0 / _DAT_0280d848;
    FUN_006e5750(0x31,&local_c0,1);
    FUN_005b7a70(&DAT_0280d820,&local_a0,&local_9c,&local_98,local_94,&local_cc,&local_c4);
    local_9c = local_9c - local_a0;
    local_94[0] = local_94[0] - local_98;
    FUN_006e5750(0x32,&local_a0,1);
  }
  local_cc = *(float *)(*(int *)(in_ECX + 0x68) + 0x20);
  local_80 = *(float *)(*(int *)(in_ECX + 0x68) + 0x14) * *(float *)(in_ECX + 0x60);
  local_78 = 0;
  local_74 = 0;
  local_7c = local_cc;
  FUN_006e5750(*(undefined4 *)(in_ECX + 0x150),&local_80,1);
  iVar4 = *(int *)(in_ECX + 0x68);
  local_cc = (*(float *)(iVar4 + 0x10) - *(float *)(iVar4 + 8)) * *(float *)(iVar4 + 0x14);
  local_c4 = *(float *)(iVar4 + 4) / 180.0;
  local_c8 = 180.0 / (*(float *)(iVar4 + 0xc) - *(float *)(iVar4 + 4));
  local_70 = *(float *)(iVar4 + 8) * *(float *)(iVar4 + 0x14);
  local_6c = local_cc;
  local_68 = local_c4;
  local_64 = local_c8;
  FUN_006e5750(*(undefined4 *)(in_ECX + 0x154),&local_70,1);
  iVar4 = *(int *)(in_ECX + 0x68);
  if (*(int *)(iVar4 + 0x28) != 0) {
    local_c8 = (*(float *)(iVar4 + 0x3c) - *(float *)(iVar4 + 0x44)) * *(float *)(iVar4 + 0x14);
    local_cc = (*(float *)(iVar4 + 0x38) * 3.1415927) / 180.0;
    local_c4 = 180.0 / ((*(float *)(iVar4 + 0x40) - *(float *)(iVar4 + 0x38)) * 3.1415927);
    local_c0 = *(float *)(iVar4 + 0x14) * *(float *)(iVar4 + 0x44);
    local_bc = local_c8;
    local_b8 = local_cc;
    local_b4 = local_c4;
    FUN_006e5750(*(undefined4 *)(in_ECX + 0x158),&local_c0,1);
    iVar4 = *(int *)(in_ECX + 0x68);
    local_c8 = *(float *)(iVar4 + 0x30);
    local_cc = *(float *)(iVar4 + 0x34);
    local_a0 = *(float *)(iVar4 + 0x2c);
    local_94[0] = 1.0;
    local_9c = local_c8;
    local_98 = local_cc;
    FUN_005b3b30(&local_a0,&local_a0);
    local_94[0] = *(float *)(*(int *)(in_ECX + 0x68) + 0x48);
    FUN_006e5750(*(undefined4 *)(in_ECX + 0x15c),&local_a0,1);
  }
  if ((local_8c == DAT_028492f4) && (DAT_02976c7c != 0)) {
    *(uint *)(local_84 + 0x20) = *(uint *)(local_84 + 0x20) & 0xfc25ffff | 0x240000;
    FUN_006059c0();
  }
  DAT_02854c2c[8] = DAT_02854c2c[8] & 0xfc25ffff | 0x240000;
  DAT_02854c2c[8] = DAT_02854c2c[8] & 0xffffdbff | 0x1b00;
  puVar3 = DAT_02854c2c;
  if (DAT_02854c2c == (undefined4 *)0x0) {
    uVar5 = 0;
  }
  else {
    if ((DAT_0097f9d0 != DAT_02854c2c[8]) || (DAT_0097f9d4 != DAT_02854c2c[9])) {
      FUN_005fa540(3,DAT_02854c2c + 8);
    }
    uVar5 = *puVar3;
  }
  FUN_006e5630(3,uVar5);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  if ((local_8c == DAT_028492f4) && (DAT_02976c7c != 0)) {
    FUN_006e5340(0x1b,0);
    FUN_006e5340(0xf,0);
  }
  else {
    FUN_006e5340(0x1b,1);
    FUN_006e5340(0x13,2);
    FUN_006e5340(0x14,2);
    FUN_006e5340(0xab,1);
    FUN_006e5340(0xf,0);
  }
  FUN_006e2420();
  FUN_006e5630(0,0);
  FUN_006e5630(3,0);
  *piVar1 = local_88;
  piVar1[1] = 0;
  *(undefined1 *)(piVar1 + 2) = 1;
  *(undefined1 *)((int)piVar1 + 9) = 0;
  *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = piVar1;
  return;
}

