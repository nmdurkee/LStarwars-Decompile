/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x642c80; label: FUN_00642c80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00642c80(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float *pfVar11;
  undefined8 uVar10;
  char *pcVar12;
  ulonglong uVar13;
  undefined8 uVar14;
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
  
  uVar2 = DAT_02920a4c;
  uVar3 = DAT_02920a50;
  if (DAT_0292097c != 0) {
    uVar2 = DAT_02920a60;
    uVar3 = DAT_02920a64;
  }
  pfVar11 = &local_54;
  local_54 = 0.5;
  uVar10 = CONCAT44(uVar2,pfVar11);
  local_50 = 0.0;
  local_4c = 0.0;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar3,pfVar11,uVar10);
  local_48 = DAT_0291f714 - local_54;
  local_30 = 0xffffffff;
  local_44 = DAT_0291f718 - local_50;
  local_c = 0xffffffff;
  local_40 = DAT_0291f71c - local_4c;
  local_24 = DAT_0291f714;
  local_20 = DAT_0291f718;
  local_1c = DAT_0291f71c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_48 = DAT_0291f714;
  local_44 = DAT_0291f718;
  local_40 = DAT_0291f71c;
  local_30 = 0xff00ff00;
  local_24 = local_54 + DAT_0291f714;
  local_c = 0xff00ff00;
  local_20 = DAT_0291f718 + local_50;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.0;
  local_50 = 0.5;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_48 = DAT_0291f714 - local_54;
  uVar13 = (ulonglong)DAT_02913a54;
  pfVar11 = &local_48;
  local_30 = 0xffffffff;
  local_44 = DAT_0291f718 - local_50;
  local_c = 0xffffffff;
  local_40 = DAT_0291f71c - local_4c;
  local_24 = DAT_0291f714;
  local_20 = DAT_0291f718;
  local_1c = DAT_0291f71c;
  FUN_005dbed0();
  local_48 = DAT_0291f714;
  local_44 = DAT_0291f718;
  local_40 = DAT_0291f71c;
  local_30 = 0xff00ff00;
  local_c = 0xff00ff00;
  local_24 = local_54 + DAT_0291f714;
  local_20 = DAT_0291f718 + local_50;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0,pfVar11,uVar13);
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.5;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_30 = 0xffffffff;
  local_48 = DAT_0291f714 - local_54;
  local_44 = DAT_0291f718 - local_50;
  local_40 = DAT_0291f71c - local_4c;
  local_24 = DAT_0291f714;
  local_20 = DAT_0291f718;
  local_1c = DAT_0291f71c;
  local_c = 0xffffffff;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_48 = DAT_0291f714;
  local_44 = DAT_0291f718;
  local_40 = DAT_0291f71c;
  local_30 = 0xff00ff00;
  local_24 = local_54 + DAT_0291f714;
  local_c = 0xff00ff00;
  local_20 = DAT_0291f718 + local_50;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.55;
  pfVar11 = &local_54;
  local_50 = 0.05;
  uVar10 = CONCAT44(uVar2,pfVar11);
  local_4c = 0.0;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar3,pfVar11,uVar10);
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.6;
  local_50 = -0.05;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_1c = DAT_0291f71c + local_4c;
  local_c = 0xff00ff00;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.6;
  local_50 = 0.05;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  pfVar11 = &local_54;
  uVar10 = CONCAT44(uVar3,pfVar11);
  FUN_005b3620();
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.55;
  local_50 = -0.05;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2,pfVar11,uVar10);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.0;
  local_50 = 0.65;
  local_4c = -0.025;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_48 = DAT_0291f714 + local_54;
  pfVar11 = &local_54;
  uVar10 = CONCAT44(uVar2,pfVar11);
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.0;
  local_50 = 0.6;
  local_4c = 0.0;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar3,pfVar11,uVar10);
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.0;
  local_50 = 0.65;
  local_4c = 0.025;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.0;
  local_30 = 0xff00ff00;
  local_50 = 0.6;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  pfVar11 = &local_54;
  uVar10 = CONCAT44(uVar3,pfVar11);
  FUN_005b3620();
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0,pfVar11,uVar10);
  local_54 = 0.0;
  local_50 = 0.6;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.0;
  local_50 = 0.55;
  local_4c = 0.0;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_24 = DAT_0291f714 + local_54;
  uVar13 = (ulonglong)DAT_02913a54;
  pfVar11 = &local_48;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0();
  local_54 = 0.0;
  local_50 = 0.05;
  local_4c = 0.55;
  FUN_005b3690(&local_54,&local_54,uVar2,pfVar11,uVar13);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.0;
  local_50 = 0.05;
  local_4c = 0.6;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.0;
  pfVar11 = &local_54;
  local_50 = 0.05;
  uVar10 = CONCAT44(uVar2,pfVar11);
  local_4c = 0.6;
  FUN_005b3690();
  FUN_005b3620(&local_54,&local_54,uVar3,pfVar11,uVar10);
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.0;
  local_50 = -0.05;
  local_4c = 0.55;
  FUN_005b3690(&local_54,&local_54,uVar2);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  local_54 = 0.0;
  local_50 = -0.05;
  local_4c = 0.55;
  FUN_005b3690(&local_54,&local_54,uVar2);
  pfVar11 = &local_54;
  uVar10 = CONCAT44(uVar3,pfVar11);
  FUN_005b3620();
  local_48 = DAT_0291f714 + local_54;
  local_44 = DAT_0291f718 + local_50;
  local_30 = 0xff00ff00;
  local_40 = DAT_0291f71c + local_4c;
  local_54 = 0.0;
  local_50 = -0.05;
  local_4c = 0.6;
  FUN_005b3690(&local_54,&local_54,uVar2,pfVar11,uVar10);
  FUN_005b3620(&local_54,&local_54,uVar3);
  local_24 = DAT_0291f714 + local_54;
  local_20 = DAT_0291f718 + local_50;
  local_c = 0xff00ff00;
  local_1c = DAT_0291f71c + local_4c;
  FUN_005dbed0(&local_48,DAT_02913a54,0);
  if (DAT_0292097c == 0) {
    local_54 = 0.0;
    pfVar11 = &local_54;
    local_50 = 0.375;
    uVar10 = CONCAT44(DAT_02920a40,pfVar11);
    local_4c = 0.0;
    FUN_005b3690();
    FUN_005b3620(&local_54,&local_54,DAT_02920a44,pfVar11,uVar10);
    FUN_005b35a0(&local_54,&local_54,DAT_02920a48);
    FUN_005b3690(&local_54,&local_54,uVar2);
    FUN_005b3620(&local_54,&local_54,uVar3);
    local_48 = DAT_0291f714;
    local_44 = DAT_0291f718;
    local_40 = DAT_0291f71c;
    local_24 = local_54 + DAT_0291f714;
    local_30 = 0xff0000ff;
    local_c = 0xff0000ff;
    local_20 = DAT_0291f718 + local_50;
    local_1c = DAT_0291f71c + local_4c;
    FUN_005dbed0(&local_48,DAT_02913a54,0);
    local_54 = 0.0;
    pfVar11 = &local_54;
    local_50 = 0.375;
    uVar10 = CONCAT44(DAT_02920a40,pfVar11);
    local_4c = 0.125;
    FUN_005b3690();
    FUN_005b3620(&local_54,&local_54,DAT_02920a44,pfVar11,uVar10);
    FUN_005b35a0(&local_54,&local_54,DAT_02920a48);
    FUN_005b3690(&local_54,&local_54,uVar2);
    FUN_005b3620(&local_54,&local_54,uVar3);
    local_48 = DAT_0291f714 + local_54;
    local_44 = DAT_0291f718 + local_50;
    local_30 = 0xff0000ff;
    local_40 = DAT_0291f71c + local_4c;
    FUN_005dbed0(&local_48,DAT_02913a54,0);
    if (DAT_02920998 == 3) {
      local_54 = 0.0;
      pfVar11 = &local_54;
      local_50 = 0.25;
      uVar10 = CONCAT44(DAT_02920a58,pfVar11);
      local_4c = 0.0;
      FUN_005b3690();
      FUN_005b3620(&local_54,&local_54,DAT_02920a5c,pfVar11,uVar10);
      FUN_005b3690(&local_54,&local_54,uVar2);
      FUN_005b3620(&local_54,&local_54,uVar3);
      local_48 = DAT_0291f714;
      local_44 = DAT_0291f718;
      local_40 = DAT_0291f71c;
      local_24 = local_54 + DAT_0291f714;
      local_30 = 0xffff0000;
      local_c = 0xffff0000;
      local_20 = DAT_0291f718 + local_50;
      local_1c = DAT_0291f71c + local_4c;
      FUN_005dbed0(&local_48,DAT_02913a54,0);
      if (DAT_02920888 != -1) {
        local_54 = 0.0;
        pfVar11 = &local_54;
        local_50 = *(float *)(&DAT_0291f804 + DAT_02920888 * 0x6c);
        uVar10 = CONCAT44(DAT_02920a58,pfVar11);
        local_4c = 0.0;
        FUN_005b3690();
        FUN_005b3620(&local_54,&local_54,DAT_02920a5c,pfVar11,uVar10);
        FUN_005b3690(&local_54,&local_54,uVar2);
        FUN_005b3620(&local_54,&local_54,uVar3);
        uVar14 = CONCAT44(DAT_02913a54,0xffff0000);
        uVar10 = CONCAT44(uVar3,uVar2);
        uVar7 = 0x3e800000;
        uVar6 = 0;
        fVar5 = DAT_0291f71c + local_4c;
        fVar4 = DAT_0291f718 + local_50;
        fVar1 = DAT_0291f714 + local_54;
        uVar8 = DAT_02920a58;
        uVar9 = DAT_02920a5c;
        goto LAB_006439e1;
      }
    }
  }
  else {
    uVar14 = CONCAT44(DAT_02913a54,0xffffffff);
    uVar10 = 0;
    fVar4 = DAT_0291f718;
    fVar5 = DAT_0291f71c;
    uVar6 = _DAT_00810198;
    uVar7 = _DAT_00810198;
    uVar8 = 0;
    fVar1 = DAT_0291f714;
    uVar9 = 0;
LAB_006439e1:
    FUN_0065bb50(fVar1,fVar4,fVar5,uVar7,uVar6,uVar7,uVar8,uVar9,uVar10,uVar14);
  }
  FUN_005db880(0x1720,0x9b0,0xf00,0x410,0x80808080,DAT_02913a50);
  FUN_005db880(0x1710,0x8f0,0xf20,0xc0,0x80000000,DAT_02913a50);
  FUN_005db5b0(0x1710,0x9b0,0x1710,0xdc8,0x80000000,DAT_02913a50);
  FUN_005db5b0(0x2630,0x9b0,0x2630,0xdc8,0x80000000,DAT_02913a50);
  FUN_005db5b0(0x1710,0xdc8,0x2630,0xdc8,0x80000000,DAT_02913a50);
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d1060(DAT_009738b8,0x80808080);
  FUN_005f35e0();
  if (DAT_0292099c == 0) {
    if (DAT_02920988 < 1) {
      FUN_005d1060(DAT_009738b8,0x80808080);
      pcVar12 = "Info Box";
LAB_00643b91:
      FUN_005f35e0(DAT_009738b8,0x988000017c0,CONCAT44(pcVar12,0x10));
    }
    else {
      FUN_005d1060(DAT_009738b8,0x80202080);
      FUN_005f35e0(DAT_009738b8,0x17c0,0x988,0x10,"WARNING: %d Orphans",DAT_02920988);
    }
  }
  else if (DAT_0292099c == 1) {
    FUN_005d1060(DAT_009738b8,0x80808080);
    pcVar12 = "Co-ordinates";
    goto LAB_00643b91;
  }
  FUN_005d1060(DAT_009738b8,0x80000000);
  if (DAT_0292099c != 0) {
    if (DAT_0292099c == 1) {
      if (DAT_02920888 == -1) {
        FUN_005f35e0();
        FUN_005d08c0();
        FUN_005d0a70();
        return;
      }
      FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Highlight: %s",DAT_02920970);
      FUN_005f35e0(DAT_009738b8,0x17c0,0xaf0,0x10,"XYZ: %0.2f %0.2f %0.2f",(double)*DAT_0292096c,
                   (double)DAT_0292096c[1],(double)DAT_0292096c[2]);
      FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"RotZ: %d",(int)*(short *)(DAT_0292096c + 0x13));
      FUN_005f35e0(DAT_009738b8,0x17c0,0xc30,0x10,"RotY: %d",
                   (int)*(short *)((int)DAT_0292096c + 0x4e));
      FUN_005f35e0(DAT_009738b8,0x17c0,0xcd0,0x10,"EmitRotZ: %d",(int)*(short *)(DAT_0292096c + 0xb)
                  );
      FUN_005f35e0(DAT_009738b8,0x17c0,0xd70,0x10,"EmitRotY: %d",
                   (int)*(short *)((int)DAT_0292096c + 0x2e));
    }
    FUN_005d08c0();
    FUN_005d0a70();
    return;
  }
  if (DAT_0292097c == 0) {
    if (DAT_00810194 == -1) {
      FUN_005f35e0();
    }
    else {
      FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Current Type: %s",
                   &DAT_02913a58 + DAT_00810194 * 0x178);
    }
    if (((DAT_00810194 == -1) || (DAT_02920974 == '\x01')) || (DAT_02920974 == '\0')) {
      FUN_005f35e0();
    }
    if (DAT_0292097c == 0) {
      if (DAT_02920888 == -1) {
        FUN_005f35e0();
      }
      else {
        FUN_0065bb50(DAT_0291f714,DAT_0291f718,DAT_0291f71c,*(undefined4 *)(DAT_02920970 + 0xd4),
                     *(undefined4 *)(DAT_02920970 + 0xd8),*(undefined4 *)(DAT_02920970 + 0xdc),
                     DAT_02920a40,DAT_02920a44,DAT_02920a48,uVar2,uVar3,0xff0000ff,DAT_02913a54);
        FUN_005d0fb0(DAT_009738b8);
        FUN_005d1060(DAT_009738b8,0x80000000);
        FUN_005f35e0(DAT_009738b8,0x17c0,0xc30,0x10,"Highlight: %s",DAT_02920970);
        if ((DAT_0291f66c == 0) && (DAT_0291f788 == 0)) {
          FUN_005f35e0(DAT_009738b8,0x1860,0xcd0,0x10,"Instances: %d of %d",
                       (int)*(char *)(DAT_02920970 + 0xb0),8);
        }
        else {
          FUN_005d1060(DAT_009738b8,0x80000080);
          FUN_005f35e0(DAT_009738b8,0x1860,0xcd0,0x10,"Instances: %d of %d (Or = %d, Du = %d)",
                       (int)*(char *)(DAT_02920970 + 0xb0),8,DAT_0291f66c,DAT_0291f788);
          FUN_005d1060(DAT_009738b8,0x80000000);
        }
      }
      goto LAB_00643e65;
    }
  }
  if (8 < DAT_02920980) {
    FUN_005d1060(DAT_009738b8,0x80000080);
  }
  FUN_005f35e0(DAT_009738b8,0x17c0,0xc30,0x10,"Enclosed: %d",DAT_02920980);
  FUN_005d1060(DAT_009738b8,0x80000000);
LAB_00643e65:
  FUN_005f35e0(DAT_009738b8,0x17c0,0xd70,0x10,"Types: %d/%d; Emits: %d/%d",DAT_02920a94,0x80,
               DAT_02920a98,0x28);
  FUN_005d08c0();
  FUN_005d0a70();
  return;
}

