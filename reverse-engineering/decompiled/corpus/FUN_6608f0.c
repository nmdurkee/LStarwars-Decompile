/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x6608f0; label: FUN_006608f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006608f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  float *pfVar6;
  undefined8 uVar5;
  ulonglong uVar7;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  uVar2 = DAT_02962ab4;
  uVar4 = DAT_02962ab8;
  if (DAT_02962a30 != 0) {
    uVar2 = DAT_02962ac8;
    uVar4 = DAT_02962acc;
  }
  pfVar6 = &local_54;
  local_54 = 0.5;
  uVar5 = CONCAT44(uVar2,pfVar6);
  local_50 = 0.0;
  local_4c = 0.0;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar4,pfVar6,uVar5);
  local_48 = DAT_02920abc - local_54;
  local_30 = 0xffffffff;
  local_44 = DAT_02920ac0 - local_50;
  local_c = 0xffffffff;
  local_40 = DAT_02920ac4 - local_4c;
  local_24 = DAT_02920abc;
  local_20 = DAT_02920ac0;
  local_1c = DAT_02920ac4;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_48 = DAT_02920abc;
  local_44 = DAT_02920ac0;
  local_40 = DAT_02920ac4;
  local_30 = 0xff00ff00;
  local_24 = local_54 + DAT_02920abc;
  local_c = 0xff00ff00;
  local_20 = DAT_02920ac0 + local_50;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.0;
  local_50 = 0.5;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_48 = DAT_02920abc - local_54;
  uVar7 = (ulonglong)DAT_02947c68;
  pfVar6 = &local_48;
  local_30 = 0xffffffff;
  local_44 = DAT_02920ac0 - local_50;
  local_c = 0xffffffff;
  local_40 = DAT_02920ac4 - local_4c;
  local_24 = DAT_02920abc;
  local_20 = DAT_02920ac0;
  local_1c = DAT_02920ac4;
  FUN_005dbed0();
  local_48 = DAT_02920abc;
  local_44 = DAT_02920ac0;
  local_40 = DAT_02920ac4;
  local_30 = 0xff00ff00;
  local_c = 0xff00ff00;
  local_24 = local_54 + DAT_02920abc;
  local_20 = DAT_02920ac0 + local_50;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0,pfVar6,uVar7);
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.5;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_30 = 0xffffffff;
  local_48 = DAT_02920abc - local_54;
  local_44 = DAT_02920ac0 - local_50;
  local_40 = DAT_02920ac4 - local_4c;
  local_24 = DAT_02920abc;
  local_20 = DAT_02920ac0;
  local_1c = DAT_02920ac4;
  local_c = 0xffffffff;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_48 = DAT_02920abc;
  local_44 = DAT_02920ac0;
  local_40 = DAT_02920ac4;
  local_30 = 0xff00ff00;
  local_24 = local_54 + DAT_02920abc;
  local_c = 0xff00ff00;
  local_20 = DAT_02920ac0 + local_50;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.55;
  pfVar6 = &local_54;
  local_50 = 0.05;
  uVar5 = CONCAT44(uVar2,pfVar6);
  local_4c = 0.0;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar4,pfVar6,uVar5);
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.6;
  local_50 = -0.05;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_1c = DAT_02920ac4 + local_4c;
  local_c = 0xff00ff00;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.6;
  local_50 = 0.05;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  pfVar6 = &local_54;
  uVar5 = CONCAT44(uVar4,pfVar6);
  FUN_005b3620();
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.55;
  local_50 = -0.05;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2,pfVar6,uVar5);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.0;
  local_50 = 0.65;
  local_4c = -0.025;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_48 = DAT_02920abc + local_54;
  pfVar6 = &local_54;
  uVar5 = CONCAT44(uVar2,pfVar6);
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.0;
  local_50 = 0.6;
  local_4c = 0.0;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar4,pfVar6,uVar5);
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.0;
  local_50 = 0.65;
  local_4c = 0.025;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.0;
  local_30 = 0xff00ff00;
  local_50 = 0.6;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  pfVar6 = &local_54;
  uVar5 = CONCAT44(uVar4,pfVar6);
  FUN_005b3620();
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0,pfVar6,uVar5);
  local_54 = 0.0;
  local_50 = 0.6;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.0;
  local_50 = 0.55;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_24 = DAT_02920abc + local_54;
  uVar7 = (ulonglong)DAT_02947c68;
  pfVar6 = &local_48;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0();
  local_54 = 0.0;
  local_50 = 0.05;
  local_4c = 0.55;
  FUN_005b3690(&local_54,&local_54,uVar2,pfVar6,uVar7);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.0;
  local_50 = 0.05;
  local_4c = 0.6;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.0;
  pfVar6 = &local_54;
  local_50 = 0.05;
  uVar5 = CONCAT44(uVar2,pfVar6);
  local_4c = 0.6;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar4,pfVar6,uVar5);
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.0;
  local_50 = -0.05;
  local_4c = 0.55;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  local_54 = 0.0;
  local_50 = -0.05;
  local_4c = 0.55;
  FUN_005b3690(&local_54,&local_54,uVar2);
  pfVar6 = &local_54;
  uVar5 = CONCAT44(uVar4,pfVar6);
  FUN_005b3620();
  local_48 = DAT_02920abc + local_54;
  local_44 = DAT_02920ac0 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_02920ac4 + local_4c;
  local_54 = 0.0;
  local_50 = -0.05;
  local_4c = 0.6;
  FUN_005b3690(&local_54,&local_54,uVar2,pfVar6,uVar5);
  FUN_005b3620(&local_54,&local_54,uVar4);
  local_24 = DAT_02920abc + local_54;
  local_20 = DAT_02920ac0 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_02920ac4 + local_4c;
  FUN_005dbed0(&local_48,DAT_02947c68,0);
  if (DAT_02962a30 == 0) {
    local_54 = 0.0;
    pfVar6 = &local_54;
    local_50 = 0.375;
    uVar5 = CONCAT44(DAT_02962aa8,pfVar6);
    local_4c = 0.0;
    FUN_005b3690();
    FUN_005b3620(&local_54,&local_54,DAT_02962aac,pfVar6,uVar5);
    FUN_005b35a0(&local_54,&local_54,DAT_02962ab0);
    FUN_005b3690(&local_54,&local_54,uVar2);
    FUN_005b3620(&local_54,&local_54,uVar4);
    local_48 = DAT_02920abc;
    local_44 = DAT_02920ac0;
    local_40 = DAT_02920ac4;
    local_24 = local_54 + DAT_02920abc;
    local_30 = 0xff0000ff;
    local_c = 0xff0000ff;
    local_20 = DAT_02920ac0 + local_50;
    local_1c = DAT_02920ac4 + local_4c;
    FUN_005dbed0(&local_48,DAT_02947c68,0);
    local_54 = 0.0;
    pfVar6 = &local_54;
    local_50 = 0.375;
    uVar5 = CONCAT44(DAT_02962aa8,pfVar6);
    local_4c = 0.125;
    FUN_005b3690();
    FUN_005b3620(&local_54,&local_54,DAT_02962aac,pfVar6,uVar5);
    FUN_005b35a0(&local_54,&local_54,DAT_02962ab0);
    FUN_005b3690(&local_54,&local_54,uVar2);
    FUN_005b3620(&local_54,&local_54,uVar4);
    local_48 = DAT_02920abc + local_54;
    local_44 = DAT_02920ac0 + local_50;
    local_30 = 0xff0000ff;
    local_40 = DAT_02920ac4 + local_4c;
    FUN_005dbed0(&local_48,DAT_02947c68,0);
    if (DAT_02962a44 == 3) {
      local_54 = 0.0;
      pfVar6 = &local_54;
      local_50 = 0.25;
      uVar5 = CONCAT44(DAT_02962ac0,pfVar6);
      local_4c = 0.0;
      FUN_005b3690();
      FUN_005b3620(&local_54,&local_54,DAT_02962ac4,pfVar6,uVar5);
      FUN_005b3690(&local_54,&local_54,uVar2);
      FUN_005b3620(&local_54,&local_54,uVar4);
      local_48 = DAT_02920abc;
      local_44 = DAT_02920ac0;
      local_40 = DAT_02920ac4;
      local_30 = 0xffff0000;
      local_24 = local_54 + DAT_02920abc;
      local_c = 0xffff0000;
      local_20 = DAT_02920ac0 + local_50;
      local_1c = DAT_02920ac4 + local_4c;
      FUN_005dbed0(&local_48,DAT_02947c68,0);
      if (DAT_029231a8 != -1) {
        local_54 = 0.0;
        pfVar6 = &local_54;
        local_50 = (float)(&DAT_02924b94)[DAT_029231a8 * 0x16];
        uVar5 = CONCAT44(DAT_02962ac0,pfVar6);
        local_4c = 0.0;
        FUN_005b3690();
        FUN_005b3620(&local_54,&local_54,DAT_02962ac4,pfVar6,uVar5);
        FUN_005b3690(&local_54,&local_54,uVar2);
        FUN_005b3620(&local_54,&local_54,uVar4);
        FUN_0065bb50(DAT_02920abc + local_54,DAT_02920ac0 + local_50,DAT_02920ac4 + local_4c,
                     0x3e800000,0,0x3e800000,DAT_02962ac0,DAT_02962ac4,0,uVar2,uVar4,0xffff0000,
                     DAT_02947c68);
      }
    }
    if (DAT_02962a44 == 4) {
      local_54 = 0.0;
      pfVar6 = &local_54;
      local_50 = 0.0;
      uVar5 = CONCAT44(DAT_02962ad0,pfVar6);
      local_4c = 0.25;
      FUN_005b35a0();
      FUN_005b3620(&local_54,&local_54,DAT_02962ad4,pfVar6,uVar5);
      local_48 = DAT_02920abc;
      local_44 = DAT_02920ac0;
      local_40 = DAT_02920ac4;
      local_30 = 0xffff0000;
      local_24 = local_54 + DAT_02920abc;
      local_c = 0xffff0000;
      local_20 = DAT_02920ac0 + local_50;
      local_1c = DAT_02920ac4 + local_4c;
      FUN_005dbed0(&local_48,DAT_02947c68,0);
      FUN_0065b830(DAT_02920abc,DAT_02920ac0,DAT_02920ac4,0x3e800000,0x3e800000,0,DAT_02962ad0,
                   DAT_02962ad4,0,0xffff0000,DAT_02947c68);
    }
  }
  else {
    FUN_0065bb50(DAT_02920abc,DAT_02920ac0,DAT_02920ac4,_DAT_00810adc,_DAT_00810adc,_DAT_00810adc,0,
                 0,0,0,0,0xffffffff,DAT_02947c68);
  }
  FUN_005db880(0x1680,0x9b0,4000,0x410,0x80808080,DAT_02947c04);
  FUN_005db880(0x1670,0x8f0,0xfc0,0xc0,0x80000000,DAT_02947c04);
  FUN_005db5b0(0x1670,0x9b0,0x1670,0xdc8,0x80000000,DAT_02947c04);
  FUN_005db5b0(0x2630,0x9b0,0x2630,0xdc8,0x80000000,DAT_02947c04);
  FUN_005db5b0(0x1670,0xdc8,0x2630,0xdc8,0x80000000,DAT_02947c04);
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  if (DAT_02962a48 == 0) {
    if (DAT_0296206c % 200 < 0x65) {
      FUN_005d1060(DAT_009738b8,0xe0e0e0e0);
      uVar5 = 0x76c5d400000010;
    }
    else {
      if (0 < DAT_02962a3c) {
        FUN_005d1060(DAT_009738b8,0x80202080);
        FUN_005f35e0(DAT_009738b8,0x1720,0x988,0x10,"WARNING: %d Orphan(s)",DAT_02962a3c);
        goto LAB_0066192f;
      }
      FUN_005d1060(DAT_009738b8,0xe0e0e0e0);
      uVar5 = 0x76c5d400000010;
    }
LAB_00661927:
    FUN_005f35e0(DAT_009738b8,0x98800001720,uVar5);
  }
  else if (DAT_02962a48 == 1) {
    FUN_005d1060(DAT_009738b8,0x80808080);
    uVar5 = 0x76c5b000000010;
    goto LAB_00661927;
  }
LAB_0066192f:
  FUN_005d1060(DAT_009738b8,0x80000000);
  if (DAT_02962a48 != 0) {
    if (DAT_02962a48 != 1) goto LAB_00661f4c;
    if (DAT_029231a8 != -1) {
      iVar3 = (&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + DAT_029620a4;
      FUN_005f35e0(DAT_009738b8,0x1720,0xa50,0x10,"Highlight: %s",
                   *(undefined4 *)(DAT_0296209c + *(short *)(iVar3 + 0x182) * 4));
      FUN_005f35e0(DAT_009738b8,0x1720,0xaf0,0x10,"XYZ: %0.2f %0.2f %0.2f",
                   (double)*(float *)(iVar3 + 400),(double)*(float *)(iVar3 + 0x194),
                   (double)*(float *)(iVar3 + 0x198));
      FUN_005f35e0(DAT_009738b8,0x1720,0xb90,0x10,"RotZ: %d",
                   (int)(short)(&DAT_02924b64)[DAT_029231a8 * 0x2c]);
      FUN_005f35e0(DAT_009738b8,0x1720,0xc30,0x10,"RotY: %d",
                   (int)(short)(&DAT_02924b66)[DAT_029231a8 * 0x2c]);
      FUN_005f35e0(DAT_009738b8,0x1720,0xcd0,0x10,"EmitRotZ: %d",
                   (int)(short)(&DAT_02924b68)[DAT_029231a8 * 0x2c]);
      FUN_005f35e0(DAT_009738b8,0x1720,0xd70,0x10,"EmitRotY: %d",
                   (int)(short)(&DAT_02924b6a)[DAT_029231a8 * 0x2c]);
      goto LAB_00661f4c;
    }
    goto LAB_00661df0;
  }
  if (DAT_02962a30 == 0) {
    if (((DAT_0292118b == '\x01') || (DAT_0292118b == '\0')) || (DAT_0292118b == '\x05')) {
      FUN_005f35e0();
    }
    if (DAT_00810ad8 == -1) {
      FUN_005f35e0();
    }
    else {
      FUN_005f35e0(DAT_009738b8,0x1720,0xaf0,0x10,"Current Type: %s",
                   *(undefined4 *)(DAT_0296209c + DAT_00810ad8 * 4));
    }
    if (DAT_02962a30 != 0) goto LAB_00661a1d;
    if (DAT_00810aec != -1) {
      uVar5 = CONCAT44(*(undefined4 *)(DAT_0296209c + DAT_00810aec * 4),"Clipboard: %s");
      goto LAB_00661aae;
    }
    FUN_005f35e0();
  }
  else {
LAB_00661a1d:
    if (DAT_02962a38 == 0) {
      FUN_005f35e0();
    }
    else {
      uVar5 = CONCAT44(DAT_02962a38,"Clipboard: %d items");
LAB_00661aae:
      FUN_005f35e0(CONCAT44(0x1720,DAT_009738b8),0x1000000b90,uVar5);
    }
  }
  if (DAT_02962a30 == 0) {
    if (DAT_029231a8 == -1) {
      FUN_005f35e0();
    }
    else {
      iVar3 = *(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4);
      if (*(char *)(iVar3 + 0x2c) == '\0') {
        FUN_0065bb50(DAT_02920abc,DAT_02920ac0,DAT_02920ac4,*(undefined4 *)(iVar3 + 0x58),
                     *(undefined4 *)(iVar3 + 0x5c),*(undefined4 *)(iVar3 + 0x60),DAT_02962aa8,
                     DAT_02962aac,DAT_02962ab0,uVar2,uVar4,0xff0000ff,DAT_02947c68);
        FUN_006604f0(iVar3,(&DAT_02924b60)[DAT_029231a8 * 0x16]);
      }
      FUN_00660680(iVar3,(&DAT_02924b60)[DAT_029231a8 * 0x16]);
      FUN_005d0fb0();
      FUN_005f35e0(DAT_009738b8,0x1720,0xc30,0x10,"Highlight: %s",iVar3);
      FUN_005f35e0(DAT_009738b8,0x1720,0xcd0,0x10,"Particles:");
      iVar1 = (-(uint)(*(char *)(iVar3 + 0x2e) != '\a') & 0x14) + 0xc;
      if (iVar1 * 0x20 < (int)*(short *)(iVar3 + 0x14)) {
        FUN_005d1060(DAT_009738b8,0x80000080);
      }
      FUN_005f35e0(DAT_009738b8,0x1cc0,0xcd0,0x10,"%d (%d)",(int)*(short *)(iVar3 + 0x14),
                   ((*(short *)(iVar3 + 0x14) + -1) / iVar1 + 1) * iVar1);
      FUN_005d1060(DAT_009738b8,0x80000000);
    }
  }
  else {
    if (8 < DAT_02962a34) {
      FUN_005d1060(DAT_009738b8,0x80000080);
    }
    FUN_005f35e0(DAT_009738b8,0x1720,0xc30,0x10,"Enclosed: %d",DAT_02962a34);
    FUN_005d1060(DAT_009738b8,0x80000000);
  }
  if (DAT_02962a30 == 0) {
    if (DAT_02962a44 == 0) {
      FUN_005f35e0();
      FUN_005d08c0();
      FUN_005d0a70();
      return;
    }
    if (DAT_02962a44 != 1) {
      if (DAT_02962a44 == 2) {
        FUN_005f35e0(DAT_009738b8,0x1720,0xd70,0x10,"Dpad Mode: Offset (%0.2f)",
                     (double)_DAT_02962abc);
        FUN_005d08c0();
        FUN_005d0a70();
        return;
      }
      if (DAT_02962a44 == 3) {
        FUN_005f35e0();
        FUN_005d08c0();
        FUN_005d0a70();
        return;
      }
      if (DAT_02962a44 != 4) {
LAB_00661f4c:
        FUN_005d08c0();
        FUN_005d0a70();
        return;
      }
    }
    FUN_005f35e0();
    FUN_005d08c0();
    FUN_005d0a70();
    return;
  }
LAB_00661df0:
  FUN_005f35e0();
  FUN_005d08c0();
  FUN_005d0a70();
  return;
}

