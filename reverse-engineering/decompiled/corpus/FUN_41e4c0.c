/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41e4c0; label: FUN_0041e4c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041e4c0(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  float10 fVar13;
  float local_4fc;
  float local_4f0;
  float local_4ec;
  float local_4e8;
  float local_4e4;
  float local_4e0;
  float local_4dc;
  undefined4 local_4d8 [12];
  float local_4a8;
  float local_4a4;
  float local_4a0;
  undefined4 local_498;
  float local_494;
  undefined4 local_490;
  undefined4 local_48c;
  uint local_488;
  undefined4 local_480 [16];
  undefined1 local_440 [64];
  undefined1 local_400 [1024];
  
  if (DAT_007f2398 != 0) {
    iVar7 = *(int *)(param_1 + 0xcd0);
    if (((iVar7 == 0) || (*(char *)(param_1 + 0x7b5) == ';')) ||
       ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x98) & 0x40) != 0)) {
      if (((*(byte *)(param_1 + 0xe24) & 1) != 0) && (iVar7 = *(int *)(param_1 + 0x790), iVar7 != 0)
         ) {
        iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf8);
        if ((iVar5 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar5 * 4) == 0)) {
          local_488 = (uint)*(ushort *)(param_1 + 0x27a);
          local_48c = 0xffffc000;
          FUN_005c0820(local_4d8,&local_48c);
          local_4a8 = *(float *)(param_1 + 0x5c) +
                      (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x27a) >> 1] *
                      *(float *)(param_1 + 0x1dc) * 1.75;
          local_4a4 = (*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c)) * 0.6 +
                      *(float *)(param_1 + 0x17c);
          local_4a0 = (float)(&DAT_029899a0)
                             [(int)(*(ushort *)(param_1 + 0x27a) + 0x4000) >> 1 & 0x7fff] *
                      *(float *)(param_1 + 0x1dc) * 1.75 + *(float *)(param_1 + 100);
        }
        else {
          puVar11 = (undefined4 *)(iVar5 * 0x40 + 0x804 + param_1);
          puVar12 = local_4d8;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
        }
        FUN_0041cb50(*(undefined4 *)(iVar7 + 0x50),iVar7 + 8,local_4d8,0,0,0,0,
                     *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0xa4));
      }
    }
    else {
      *(undefined1 *)(iVar7 + 0x107c) = *(undefined1 *)(param_1 + 0x107c);
      *(undefined1 *)(iVar7 + 0x107b) = *(undefined1 *)(param_1 + 0x107b);
      *(undefined4 *)(iVar7 + 0x1014) = *(undefined4 *)(param_1 + 0x1014);
      iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x113);
      if ((iVar5 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar5 * 4) == 0)) {
        local_4ec = *(float *)(param_1 + 0x1e0);
        local_4f0 = 0.0;
        FUN_005b3200(&local_4f0,&local_4f0,(undefined4 *)(param_1 + 0xb8));
        FUN_005b37d0(&local_4f0,&local_4f0,param_1 + 0x80);
        puVar11 = (undefined4 *)(param_1 + 0xb8);
        puVar12 = local_4d8;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        local_4a8 = local_4f0;
        local_4a4 = local_4ec;
        local_4a0 = local_4e8;
      }
      else {
        puVar11 = (undefined4 *)(iVar5 * 0x40 + 0x804 + param_1);
        puVar12 = local_4d8;
        for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      if ((((*(char *)(iVar7 + 0x107b) == '\0') || (*(float *)(iVar7 + 0x1014) == 2e+06)) ||
          ((float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcd) <=
           *(float *)(param_1 + 0x101c))) ||
         (iVar5 = FUN_00550490(local_4d8,*(char *)(iVar7 + 0x107b),*(undefined4 *)(iVar7 + 0x1014),
                               *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_480)
         , iVar5 == 0)) {
        puVar11 = (undefined4 *)0x0;
      }
      else {
        puVar11 = local_480;
      }
      uVar6 = FUN_0041a5b0(*(undefined4 *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0xa4),iVar7);
      iVar5 = FUN_0041cb50(*(undefined4 *)(iVar7 + 0x50),iVar7 + 8,local_4d8,0,puVar11,local_400,0,
                           uVar6);
      if (iVar5 != 0) {
        if (*(byte *)(iVar7 + 0x1082) != 0) {
          FUN_00552e90(PTR_DAT_00802c54,iVar7,*(byte *)(iVar7 + 0x1082) + 0xf9,0,
                       (int)*(char *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x111),0xffffffff,
                       local_400,*(undefined1 *)(iVar7 + 0x107c),uVar6,0,0,0x3f800000,0x3f800000);
        }
        iVar5 = FUN_0056e160(2);
        if (iVar5 != 0) {
          FUN_00552e90(PTR_DAT_00802c54,iVar7,0xe7,0,
                       (int)*(char *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x10e),0xffffffff,
                       local_400,*(undefined1 *)(iVar7 + 0x107c),uVar6,0,0,0x3f800000,0x3f800000);
        }
        FUN_0041e2c0(iVar7,local_400);
        if ((*(short *)(iVar7 + 0x1064) == DAT_007f18e4) ||
           (*(short *)(iVar7 + 0x1064) == DAT_007f18e8)) {
          FUN_00592d00(DAT_00856980,iVar7,local_400);
        }
      }
    }
    iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    if ((*(byte *)(iVar7 + 0x94) & 1) == 0) {
      if ((*(byte *)(*(int *)(param_1 + 0x54) + 0x40) & 1) == 0) {
        if ((*(short *)(param_1 + 0x1064) == DAT_007f192c) &&
           (((*(char *)(param_1 + 0x7b5) != '\n' || ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0)) ||
            ((*(char *)(param_1 + 0xe3f) != -1 ||
             ((*(float *)(param_1 + 0x77c) < 0.5 && (DAT_00925068 % 6 < 3)))))))) {
          DAT_0093b0f8 = 0xc000;
          FUN_00552e90(PTR_DAT_00802c54,param_1,0xf0,0,
                       (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xfc),0xffffffff,
                       param_1 + 0x804,0,*(undefined4 *)(param_1 + 0x1048),0,0,0x3f800000,0x3f800000
                      );
        }
      }
      else {
        iVar7 = (int)*(char *)(iVar7 + 0x110);
        if (((iVar7 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar7 * 4) == 0)) ||
           (*(char *)(param_1 + 0x288) == '\0')) {
          puVar11 = (undefined4 *)(param_1 + 0xb8);
        }
        else {
          puVar11 = (undefined4 *)(iVar7 * 0x40 + 0x804 + param_1);
        }
        cVar3 = *(char *)(param_1 + 0x107c);
        puVar12 = local_4d8;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        puVar11 = (undefined4 *)(param_1 + 0x138);
        puVar12 = local_480;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        FUN_0055b570(PTR_DAT_00802c54,(int)*(short *)(param_1 + 0x1064),local_4d8,
                     -(uint)(cVar3 != '\0') & (uint)local_480);
      }
    }
    else if ((DAT_00951154 != 0) && (DAT_00951288 != 0)) {
      FUN_00599ce0((int)*(short *)(param_1 + 0x1064),param_1 + 0xb8,
                   *(undefined1 *)(param_1 + 0x107b),*(undefined4 *)(param_1 + 0x1014),
                   *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0));
    }
    if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\x01') &&
       (iVar7 = FUN_0062f150(param_1 + 8,0x60,1,1), iVar7 != 0)) {
      FUN_00552e90(PTR_DAT_00802c54,param_1,9,0,
                   (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf8),0xffffffff,
                   param_1 + 0x804,*(undefined1 *)(param_1 + 0x107c),
                   *(undefined4 *)(param_1 + 0x1048),0,0,0x3f800000,0x3f800000);
    }
    else if (*(float *)(param_1 + 0xd3c) <= 0.0) {
      fVar13 = (float10)FUN_00419130();
      FUN_0041dad0(param_1,*(undefined1 *)(param_1 + 0x107c),(float)fVar13);
    }
    else {
      FUN_0041dad0(param_1,*(undefined1 *)(param_1 + 0x107c),*(undefined4 *)(param_1 + 0xd3c));
      if (0.0 < *(float *)(param_1 + 0xd54)) {
        DAT_0093b0fc = 1;
        FUN_00552e90(PTR_DAT_00802c54,param_1,0x35,0,
                     (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xfc),0xffffffff,
                     param_1 + 0x804,*(undefined1 *)(param_1 + 0x107c),
                     *(undefined4 *)(param_1 + 0x1048),0,0,0x3f800000,0x3f800000);
      }
    }
    if ((0.0 < *(float *)(param_1 + 0xd30)) || (0.0 < *(float *)(param_1 + 0xd34))) {
      thunk_FUN_005d05b0();
      FUN_004191d0(*(undefined1 *)(param_1 + 0x107c));
      FUN_00596920(0);
    }
    if (0.0 < *(float *)(param_1 + 0xd38)) {
      FUN_00419550(param_1,*(undefined1 *)(param_1 + 0x107c));
    }
    if (*(char *)(param_1 + 0x7b5) == '\"') {
      if (((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
          (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364)) ||
         ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b174 ||
          (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b11c)))) {
        local_498 = *(undefined4 *)(param_1 + 0x80);
        local_494 = (*(float *)(param_1 + 0xff4) - *(float *)(param_1 + 0xff0)) * 0.5 *
                    *(float *)(param_1 + 0xa8) +
                    *(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8) +
                    *(float *)(param_1 + 0x60);
        local_490 = *(undefined4 *)(param_1 + 0x88);
        if (*(float *)(param_1 + 0x1dc) <= *(float *)(param_1 + 0x1e0)) {
          fVar1 = *(float *)(param_1 + 0x1e0);
        }
        else {
          fVar1 = *(float *)(param_1 + 0x1dc);
        }
        if (0.2 <= *(float *)(param_1 + 0x778)) {
          if (0.2 <= *(float *)(param_1 + 0x77c)) {
            fVar2 = 1.0;
          }
          else {
            fVar2 = *(float *)(param_1 + 0x77c) / 0.2;
          }
        }
        else {
          fVar2 = *(float *)(param_1 + 0x778) / 0.2;
        }
        FUN_004a4ce0(&local_498,fVar1 * 1.75,0xdf,fVar2,param_1);
      }
    }
    else if ((((0.0 < *(float *)(param_1 + 0xd80)) && (0.0 < *(float *)(param_1 + 0xd8c))) &&
             (*(char *)(*(short *)(param_1 + 0xe1e) * 0x10 + 0xe +
                       *(int *)(PTR_DAT_00802c54 + 0x2ac0)) != '\0')) &&
            ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x400) == 0)) {
      FUN_004a4ce0(param_1 + 0xc68,*(undefined4 *)(param_1 + 0xd8c),(int)*(short *)(param_1 + 0xe1e)
                   ,*(float *)(param_1 + 0xd80) / _DAT_007fc074,param_1);
    }
    iVar7 = FUN_0056e160(2);
    if (iVar7 != 0) {
      FUN_00552e90(PTR_DAT_00802c54,param_1,0xe7,0,
                   (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x10e),0xffffffff,
                   param_1 + 0x804,*(undefined1 *)(param_1 + 0x107c),
                   *(undefined4 *)(param_1 + 0x1048),0,0,0x3f800000,0x3f800000);
    }
    bVar4 = *(byte *)(param_1 + 0x1082);
    if (bVar4 != 0) {
      if (((*(short *)(param_1 + 0x1064) == DAT_007f18ec) ||
          (*(short *)(param_1 + 0x1064) == DAT_007f18f0)) && ((bVar4 != 5 && (bVar4 != 6)))) {
        iVar7 = 9;
      }
      else {
        iVar7 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x111);
      }
      FUN_00552e90(PTR_DAT_00802c54,param_1,bVar4 + 0xf9,0,iVar7,0xffffffff,param_1 + 0x804,
                   *(undefined1 *)(param_1 + 0x107c),*(undefined4 *)(param_1 + 0x1048),0,0,
                   0x3f800000,0x3f800000);
    }
    if (((*(char *)(param_1 + 0x288) != '\0') &&
        (*(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf2) != 0)) &&
       (0.0 < *(float *)(param_1 + 0xdcc))) {
      FUN_00419340(param_1,*(undefined1 *)(param_1 + 0x107c));
    }
    if (*(char *)(param_1 + 0x7b5) == '-') {
      FUN_0058ef70(param_1,*(undefined1 *)(param_1 + 0x107c));
    }
    if (((*(char *)(param_1 + 0x7b5) == 'H') &&
        (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) != 0))
       && (*(char *)(param_1 + 0x7b3) == '\0')) {
      FUN_00419760(param_1,0xec,*(undefined1 *)(param_1 + 0x107c));
    }
    else if (((*(char *)(param_1 + 0x7b5) == 'I') &&
             (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4)
              != 0)) && (*(char *)(param_1 + 0x7b3) != '\0')) {
      FUN_00419a00(param_1,0xec,*(undefined1 *)(param_1 + 0x107c));
    }
    if ((*(uint *)(param_1 + 0xe20) & 0x400000) != 0) {
      DAT_0093b0f8 = 0x4000;
      uVar6 = FUN_00404f10((int)*(short *)(param_1 + 0x1064),0,
                           (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x112),
                           0xffffffff,param_1 + 0x804,*(undefined1 *)(param_1 + 0x107c),
                           *(undefined4 *)(param_1 + 0x1048),0,0,0x3f800000,0x3f800000);
      FUN_00552e90(PTR_DAT_00802c54,param_1,uVar6);
    }
    if (*(char *)(param_1 + 0x7b5) == 'F') {
      FUN_0054dcb0(param_1);
    }
    if (((*(uint *)(param_1 + 0xe20) & 0x800000) != 0) || (*(char *)(param_1 + 0x7b5) == 'X')) {
      FUN_00597dd0(param_1);
    }
    FUN_0041e2c0(param_1,param_1 + 0x804);
    if (*(char *)(param_1 + 0x7b5) == ']') {
      FUN_00419d10(*(undefined1 *)(param_1 + 0x107c));
    }
    if ((*(char **)(param_1 + 0xcc4) != (char *)0x0) && (**(char **)(param_1 + 0xcc4) != '\0')) {
      FUN_004d3f20(param_1);
    }
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\0') {
      FUN_00592d00(DAT_00856980,param_1,0);
    }
    if ((((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x1000000) != 0) &&
        (0.0 < *(float *)(param_1 + 0xd80))) && (0.0 < *(float *)(param_1 + 0xd8c))) {
      FUN_004d5210(param_1 + 0xc68,
                   (*(float *)(param_1 + 0xd80) * 0.20000005 + 1.4) * *(float *)(param_1 + 0xd8c),
                   *(float *)(param_1 + 0xd80) * 0.6 + 0.4);
    }
    iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    if (*(char *)(iVar7 + 0x116) == '\x01') {
      iVar7 = (int)*(char *)(iVar7 + 0x110);
      if (((iVar7 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar7 * 4) != 0)) &&
         (pfVar8 = (float *)FUN_0062f150(param_1 + 8,0x6b,1,1), pfVar8 != (float *)0x0)) {
        fVar1 = *pfVar8;
        if (((NAN(fVar1) || 70.0 < fVar1 == (fVar1 == 70.0)) ||
            (*pfVar8 < 210.0 == (*pfVar8 == 210.0))) &&
           ((fVar1 = *pfVar8, NAN(fVar1) || 310.0 < fVar1 == (fVar1 == 310.0) ||
            (*pfVar8 < 433.0 == (*pfVar8 == 433.0))))) {
          iVar5 = -1;
          local_4fc = 1.0;
          iVar7 = 10;
          puVar10 = &DAT_0087ab50;
          do {
            iVar9 = FUN_005cfac0(puVar10);
            if (iVar9 != 0) {
              uVar6 = FUN_005cf9e0(puVar10,0);
              fVar13 = (float10)FUN_005b3c50(param_1 + 0x80,uVar6);
              if ((float)fVar13 < local_4fc) {
                iVar5 = iVar7;
                local_4fc = (float)fVar13;
              }
            }
            puVar10 = puVar10 + 0xc;
            iVar7 = iVar7 + 1;
          } while ((int)puVar10 < 0x87abb0);
          if (iVar5 != -1) {
            uVar6 = FUN_005d0330(&DAT_0087aad8 + iVar5 * 3);
            FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xa0,uVar6);
            return;
          }
        }
        else {
          puVar11 = (undefined4 *)(iVar7 * 0x40 + 0x804 + param_1);
          puVar12 = local_4d8;
          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          FUN_005b5240(local_4d8,0xffffc000);
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xa0,local_4d8);
          if ((*(char *)(param_1 + 0x107c) != '\0') &&
             (iVar7 = FUN_00550490(local_4d8,*(undefined1 *)(param_1 + 0x107b),
                                   *(undefined4 *)(param_1 + 0x1014),
                                   *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                   local_440), iVar7 != 0)) {
            FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xa0,local_440);
            return;
          }
        }
      }
    }
    else if ((*(short *)(param_1 + 0x1064) == DAT_007f1820) &&
            (pfVar8 = (float *)FUN_0062f150(param_1 + 8,1,0,0), pfVar8 != (float *)0x0)) {
      fVar13 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),1,0);
      fVar1 = (float)fVar13;
      if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
        fVar13 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),1,1);
        fVar2 = (float)fVar13;
        if (((fVar1 < fVar2 != (fVar1 == fVar2)) && (fVar1 < *pfVar8)) && (*pfVar8 < fVar2)) {
          fVar1 = (*pfVar8 - fVar1) / (fVar2 - fVar1);
          if (0.1 <= fVar1) {
            if (0.9 <= fVar1) {
              local_4e4 = 1.0 - (fVar1 - 0.9) / 0.1;
            }
            else {
              local_4e4 = 1.0;
            }
          }
          else {
            local_4e4 = fVar1 / 0.1;
          }
          local_4e0 = local_4e4;
          local_4dc = local_4e4;
          FUN_005b45a0(local_4d8,&local_4e4);
          FUN_005b4cf0(local_4d8,(int)ROUND(fVar1 * -65536.0) & 0xffff);
          FUN_005b4f70(local_4d8,*(undefined2 *)(param_1 + 0x27a));
          FUN_005b4900(local_4d8,param_1 + 0x834);
          iVar7 = FUN_006e6b90();
          local_4a4 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] * 0.2 + local_4a4;
          FUN_00552e90(PTR_DAT_00802c54,param_1,0xf9,0,0,0xffffffff,local_4d8,
                       *(undefined1 *)(param_1 + 0x107c),*(undefined4 *)(param_1 + 0x1048),0,0,
                       0x3f800000,0x3f800000);
          return;
        }
      }
    }
  }
  return;
}

