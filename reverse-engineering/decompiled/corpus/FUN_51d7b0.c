/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51d7b0; label: FUN_0051d7b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051d7b0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  float fVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint *puVar13;
  undefined4 *puVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 fVar16;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined8 uVar17;
  undefined4 *local_84;
  uint local_80;
  int local_7c;
  float local_78;
  float local_74;
  uint *local_70;
  uint *local_6c;
  float local_68;
  undefined8 local_64;
  float local_5c;
  uint local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float local_48;
  undefined4 auStack_44 [2];
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  float fStack_4;
  
  local_38 = *(undefined4 *)(param_2 + 0x1b4);
  local_10 = *(undefined4 *)(param_2 + 0x1c0);
  local_34 = *(undefined4 *)(param_2 + 0x1b8);
  local_30 = *(undefined4 *)(param_2 + 0x1bc);
  local_48 = *(float *)(param_2 + 0x1c4);
  local_28 = *(undefined4 *)(param_2 + 0x1cc);
  local_24 = *(undefined4 *)(param_2 + 0x1d0);
  local_20 = *(undefined4 *)(param_2 + 0x1d4);
  local_1c = *(undefined4 *)(param_2 + 0x1d8);
  local_18 = *(undefined4 *)(param_2 + 0x1dc);
  local_14 = *(undefined4 *)(param_2 + 0x1e0);
  local_80 = 0;
  local_6c = (uint *)0x0;
  local_2c = FUN_0051d750();
  if (local_2c < 0) {
    iVar6 = *(int *)(param_2 + 0xd0);
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(iVar6 + 0x5c);
    *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(iVar6 + 0x60);
    uVar10 = *(undefined4 *)(iVar6 + 100);
    *(undefined4 *)(param_2 + 0x110) = 0;
    *(undefined4 *)(param_2 + 0x10c) = uVar10;
    return;
  }
  local_7c = *(int *)(param_2 + 0x158);
  puVar13 = *(uint **)(param_2 + 0x1d0);
  puVar9 = *(uint **)(param_2 + 0x15c);
  local_70 = puVar9;
  fVar15 = (float10)FUN_005b3c50((undefined4 *)(param_2 + 0x1b4),param_3 + 0x5c,&local_c);
  local_5c = (float)fVar15;
  fVar15 = (float10)0;
  if ((((*(short *)(param_3 + 0x27e) != -1) &&
       ((*(char *)((uint)(byte)puVar9[4] * 0x5c + 0x2a + *(int *)(local_7c + 0x7c)) == '\0' ||
        (*(char *)((uint)*(byte *)((int)puVar9 + 0x11) * 0x5c + 0x2a + *(int *)(local_7c + 0x7c)) ==
         '\0')))) || (fVar15 == (float10)*(float *)(param_2 + 0x1c4))) ||
     (((_DAT_00801c8c <= local_8 || (local_8 <= _DAT_00801c90)) ||
      (*(float *)(param_2 + 0x1c4) * *(float *)(param_2 + 0x1c4) <= local_5c)))) {
LAB_0051da1b:
    fVar15 = (float10)0;
    if (((local_7c != 0) && (puVar9 != (uint *)0x0)) && (puVar13 != (uint *)0x0)) {
      if (*(int *)(param_2 + 0x15c) != *(int *)(param_2 + 0x1d0)) {
        iVar6 = FUN_0051b1f0(param_1,param_2 + 0x14c,*(undefined4 *)(param_2 + 0x158),
                             *(int *)(param_2 + 0x1d0),param_4,*(int *)(param_2 + 0x15c),
                             *(undefined1 *)(param_2 + 0x13c),*(undefined1 *)(param_3 + 0x28d),0,
                             *(undefined4 *)(param_3 + 0xac),0);
        if (iVar6 != 0) {
          cVar2 = *(char *)(*(int *)(param_2 + 0x1d0) + 0x10);
          if ((cVar2 == *(char *)(*(int *)(param_2 + 0x15c) + 0x10)) ||
             (cVar2 == *(char *)(*(int *)(param_2 + 0x15c) + 0x11))) {
            local_80 = 0;
          }
          else {
            local_80 = 1;
          }
          FUN_0051b890(param_2,param_3 + 0x5c,*(int *)(param_2 + 0x1d0),local_80);
        }
        if (*(int *)(param_2 + 0x15c) != *(int *)(param_2 + 0x1d0)) {
          local_80 = (uint)*(byte *)(param_2 + 0x160);
          local_74 = 3.4028235e+38;
          fVar1 = *(float *)(param_2 + 0x168);
          local_58 = (uint)(byte)puVar13[4];
          if (fVar1 <= 1.0) {
            if (fVar1 < 0.0) {
              fVar1 = 0.0;
            }
          }
          else {
            fVar1 = 1.0;
          }
          local_64._0_4_ = ABS((float)puVar9[6] * fVar1);
          local_68 = *(float *)(param_2 + 0x1dc) * (float)puVar13[6];
          local_64._4_4_ = ABS((float)puVar9[6] * (1.0 - fVar1));
          local_78 = (1.0 - *(float *)(param_2 + 0x1dc)) * (float)puVar13[6];
          if (*(char *)(param_2 + 0x13c) != -1) {
            *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x100000;
          }
          while( true ) {
            local_68 = ABS(local_68);
            local_78 = ABS(local_78);
            fVar15 = (float10)3.4028234663852886e+38;
            if ((*(char *)(param_2 + 0x13c) != -1) &&
               (uVar5 = __allshl(), puVar9 = local_70, fVar15 = extraout_ST0,
               ((ushort)puVar13[5] & uVar5) == 0)) {
              iVar6 = (uint)(byte)puVar13[4] * 0x5c + *(int *)(local_7c + 0x7c);
              if ((~*(ushort *)(iVar6 + 0x5a) & *(ushort *)(iVar6 + 0x58) & uVar5) != 0) {
                local_68 = 3.4028235e+38;
              }
              iVar6 = (uint)*(byte *)((int)puVar13 + 0x11) * 0x5c + *(int *)(local_7c + 0x7c);
              if ((~*(ushort *)(iVar6 + 0x5a) & *(ushort *)(iVar6 + 0x58) & uVar5) != 0) {
                local_78 = 3.4028235e+38;
              }
            }
            if ((puVar9[*(byte *)(param_2 + 0x160)] & 0x40000000) == 0) {
              if (((float10)local_68 == fVar15) ||
                 (uVar12 = (uint)(*(byte *)(param_2 + 0x160) == 0),
                 (float10)*(float *)((int)&local_64 + uVar12 * 4) == fVar15)) {
                fVar16 = (float10)3.4028235e+38;
              }
              else {
                fVar15 = (float10)FUN_0051a890(*(undefined4 *)(param_2 + 0x158),
                                               *(undefined1 *)(uVar12 + 0x10 + (int)puVar9),
                                               (char)puVar13[4],*(undefined1 *)(param_2 + 0x13c),0);
                fVar16 = (float10)(float)fVar15;
                fVar15 = (float10)3.4028234663852886e+38;
                if (fVar15 != fVar16) {
                  fVar16 = (float10)(float)((float10)*(float *)((int)&local_64 +
                                                               (uint)(*(char *)(param_2 + 0x160) ==
                                                                     '\0') * 4) + (float10)local_68
                                           + fVar16);
                }
              }
              if (fVar16 < (float10)local_74) {
                uVar12 = puVar13[4];
                local_74 = (float)fVar16;
                local_80 = (uint)*(byte *)(param_2 + 0x160);
                *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xffefffff;
                local_58 = (uint)(byte)uVar12;
              }
              if (((float10)local_78 == fVar15) ||
                 (uVar12 = (uint)(*(char *)(param_2 + 0x160) == '\0'),
                 (float10)*(float *)((int)&local_64 + uVar12 * 4) == fVar15)) {
                fVar16 = (float10)3.4028235e+38;
              }
              else {
                fVar15 = (float10)FUN_0051a890(*(undefined4 *)(param_2 + 0x158),
                                               *(undefined1 *)(uVar12 + 0x10 + (int)puVar9),
                                               *(undefined1 *)((int)puVar13 + 0x11),
                                               *(undefined1 *)(param_2 + 0x13c),0);
                fVar16 = (float10)(float)fVar15;
                fVar15 = (float10)3.4028234663852886e+38;
                if (fVar15 != fVar16) {
                  fVar16 = (float10)(float)((float10)*(float *)((int)&local_64 +
                                                               (uint)(*(char *)(param_2 + 0x160) ==
                                                                     '\0') * 4) + (float10)local_78
                                           + fVar16);
                }
              }
              if (fVar16 < (float10)local_74) {
                bVar3 = *(byte *)((int)puVar13 + 0x11);
                local_74 = (float)fVar16;
                local_80 = (uint)*(byte *)(param_2 + 0x160);
                *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xffefffff;
                local_58 = (uint)bVar3;
              }
            }
            bVar3 = *(byte *)(param_2 + 0x160);
            if ((puVar9[bVar3 == 0] & 0x40000000) == 0) {
              if (((float10)local_68 == fVar15) ||
                 ((float10)*(float *)((int)&local_64 + (uint)bVar3 * 4) == fVar15)) {
                fVar16 = (float10)3.4028235e+38;
              }
              else {
                fVar15 = (float10)FUN_0051a890(*(undefined4 *)(param_2 + 0x158),
                                               *(undefined1 *)(bVar3 + 0x10 + (int)puVar9),
                                               (char)puVar13[4],*(undefined1 *)(param_2 + 0x13c),0);
                fVar16 = (float10)(float)fVar15;
                fVar15 = (float10)3.4028234663852886e+38;
                if (fVar15 != fVar16) {
                  fVar16 = (float10)(float)((float10)*(float *)((int)&local_64 +
                                                               (uint)*(byte *)(param_2 + 0x160) * 4)
                                            + (float10)local_68 + fVar16);
                }
              }
              if (fVar16 < (float10)local_74) {
                local_74 = (float)fVar16;
                local_58 = (uint)(byte)puVar13[4];
                local_80 = (uint)(*(char *)(param_2 + 0x160) == '\0');
                *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xffefffff;
              }
              if (((float10)local_78 == fVar15) ||
                 ((float10)*(float *)((int)&local_64 + (uint)*(byte *)(param_2 + 0x160) * 4) ==
                  fVar15)) {
                fVar1 = 3.4028235e+38;
              }
              else {
                fVar15 = (float10)FUN_0051a890(*(undefined4 *)(param_2 + 0x158),
                                               *(undefined1 *)
                                                (*(byte *)(param_2 + 0x160) + 0x10 + (int)puVar9),
                                               *(undefined1 *)((int)puVar13 + 0x11),
                                               *(undefined1 *)(param_2 + 0x13c),0);
                fVar1 = (float)fVar15;
                if (fVar1 != 3.4028235e+38) {
                  fVar1 = *(float *)((int)&local_64 + (uint)*(byte *)(param_2 + 0x160) * 4) +
                          local_78 + fVar1;
                }
              }
              if (fVar1 < local_74) {
                local_58 = (uint)*(byte *)((int)puVar13 + 0x11);
                local_80 = (uint)(*(char *)(param_2 + 0x160) == '\0');
                *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xffefffff;
                local_74 = fVar1;
              }
            }
            if ((*(uint *)(param_2 + 0x1e8) & 0x100000) == 0) break;
            if (*(byte *)(param_2 + 0x13c) != 0xff) {
              local_6c = (uint *)((uint)local_6c | 1 << (*(byte *)(param_2 + 0x13c) & 0x1f));
            }
            FUN_0051b7f0(param_2);
            if (((uint)local_6c & 1 << (*(byte *)(param_2 + 0x13c) & 0x1f)) != 0) {
              return;
            }
            local_68 = *(float *)(param_2 + 0x1dc) * (float)puVar13[6];
            local_78 = (1.0 - *(float *)(param_2 + 0x1dc)) * (float)puVar13[6];
          }
          *(uint *)(param_2 + 0x17c) = local_58 * 0x5c + *(int *)(local_7c + 0x7c);
          iVar6 = param_3 + 0x5c;
          FUN_0051b890(param_2,iVar6,puVar9,local_80);
          local_6c = (uint *)0x0;
          puVar7 = (uint *)FUN_0051be90(&local_80);
          if (puVar7 == (uint *)0x0) {
            uVar12 = (puVar13[1] | *puVar13) & 0xdfffffff;
            if (((((puVar13[1] | *puVar13) & 0xd8000000) == 0) &&
                ((uVar12 == 0 || ((*(uint *)(param_2 + 500) & uVar12) != 0)))) &&
               (iVar8 = FUN_0051b1f0(param_1,param_2 + 0x14c,*(undefined4 *)(param_2 + 0x158),
                                     puVar13,param_4,*(undefined4 *)(param_2 + 0x15c),
                                     *(undefined1 *)(param_2 + 0x13c),
                                     *(undefined1 *)(param_3 + 0x28d),0,
                                     *(undefined4 *)(param_3 + 0xac),0), iVar8 != 0)) {
              FUN_0051b890(param_2,iVar6,puVar13,0);
            }
          }
          else {
            do {
              if ((((puVar7 == local_6c) ||
                   (iVar8 = FUN_0051b1f0(param_1,param_2 + 0x14c,*(undefined4 *)(param_2 + 0x158),
                                         puVar7,param_4,*(undefined4 *)(param_2 + 0x15c),
                                         *(undefined1 *)(param_2 + 0x13c),
                                         *(undefined1 *)(param_3 + 0x28d),0,
                                         *(undefined4 *)(param_3 + 0xac),0), iVar8 == 0)) ||
                  (puVar9 == puVar13)) ||
                 ((local_6c = puVar7, FUN_0051b890(param_2,iVar6,puVar7,local_80), puVar9 = puVar7,
                  *(uint **)(param_2 + 0x15c) != puVar7 || (*(byte *)(param_2 + 0x160) != local_80))
                 )) break;
              puVar7 = (uint *)FUN_0051be90(&local_80);
            } while (puVar7 != (uint *)0x0);
          }
        }
      }
      local_84 = (undefined4 *)(param_3 + 0x5c);
      if (DAT_009238fc != (code *)0x0) {
        if (puVar9 != puVar13) {
          *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x20000000;
        }
        iVar6 = (*DAT_009238fc)(param_2,param_3,param_4);
        if (iVar6 != 0) {
          *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x40080000;
          return;
        }
      }
      fVar15 = (float10)0;
      uVar12 = (uint)*(byte *)(param_2 + 0x160);
      puVar9 = *(uint **)(param_2 + 0x15c);
      if ((puVar9[uVar12] & 0xd8000000) != 0) {
        puVar14 = (undefined4 *)
                  ((uint)*(byte *)(uVar12 + 0x10 + (int)puVar9) * 0x5c + 4 +
                  *(int *)(local_7c + 0x7c));
        *(undefined4 *)(param_2 + 0x104) = *puVar14;
        *(undefined4 *)(param_2 + 0x108) = puVar14[1];
        uVar10 = puVar14[2];
        *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x400000;
        *(float *)(param_2 + 0x110) = (float)fVar15;
        *(undefined4 *)(param_2 + 0x10c) = uVar10;
        *(uint *)(param_2 + 0x1f8) = puVar9[uVar12];
        return;
      }
      local_70 = puVar9;
      if ((puVar9 == puVar13) &&
         ((*(char *)(param_2 + 0x13c) == -1 ||
          (uVar5 = __allshl(), fVar15 = extraout_ST0_00, (uVar5 & (ushort)puVar13[5]) != 0)))) {
        if (((*(byte *)(param_2 + 0x166) & 1) == 0) ||
           (fVar15 == (float10)*(float *)(param_2 + 0x1c4))) {
          fVar15 = (float10)*(float *)(param_2 + 0x1c0);
          uVar10 = *(undefined4 *)(param_2 + 0x1bc);
          *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_2 + 0x1b4);
          *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_2 + 0x1b8);
          goto LAB_0051e89c;
        }
        if (local_5c < *(float *)(param_2 + 0x1c4) * *(float *)(param_2 + 0x1c4)) {
          if (local_2c == 0) goto LAB_0051e888;
          if ((*(byte *)(param_2 + 0x1ec) & 4) != 0) {
            *(undefined4 *)(param_2 + 0x1c0) = local_10;
            *(undefined4 *)(param_2 + 0x1b4) = local_38;
            *(float *)(param_2 + 0x1c4) = local_48;
            *(undefined4 *)(param_2 + 0x1cc) = local_28;
            *(undefined4 *)(param_2 + 0x1b8) = local_34;
            *(undefined4 *)(param_2 + 0x1d0) = local_24;
            *(undefined4 *)(param_2 + 0x1bc) = local_30;
            *(undefined4 *)(param_2 + 0x1d4) = local_20;
            *(undefined4 *)(param_2 + 0x1d8) = local_1c;
            *(undefined4 *)(param_2 + 0x1dc) = local_18;
            *(undefined4 *)(param_2 + 0x1e0) = local_14;
            FUN_0051d5e0(param_1,param_2);
            FUN_0051d750();
          }
        }
        fVar15 = (float10)FUN_005c0240(local_5c);
        local_5c = (float)fVar15;
        local_48 = *(float *)(param_2 + 0x1c4) / local_5c;
        FUN_005b3830(&local_c,&local_c,local_48);
        *(float *)(param_2 + 0x104) = *(float *)(param_2 + 0x1b4) - local_c;
        *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_2 + 0x1b8);
        *(float *)(param_2 + 0x10c) = *(float *)(param_2 + 0x1bc) - fStack_4;
        if (*(float *)(param_2 + 0x1c4) <= *(float *)(param_2 + 0x1c0)) {
          *(undefined4 *)(param_2 + 0x110) = *(undefined4 *)(param_2 + 0x1c0);
          return;
        }
        goto LAB_0051e706;
      }
      uVar17 = CONCAT44(local_64._4_4_,(float)local_64);
      bVar3 = (byte)puVar9[4];
      if (bVar3 == (byte)puVar13[4]) {
        iVar6 = (uint)bVar3 * 0x5c + *(int *)(local_7c + 0x7c);
        uVar12 = 0;
LAB_0051e4ba:
        local_80 = uVar12;
        local_64 = CONCAT44(local_64._4_4_,(float)local_64);
        if (iVar6 == 0) goto LAB_0051e509;
        puVar9 = puVar13;
        if (*(char *)(param_2 + 0x13c) != -1) {
          uVar17 = __allshl();
          fVar15 = extraout_ST0_01;
          if ((((uint)(ushort)puVar13[5] & (uint)uVar17) == 0) &&
             (local_64 = uVar17, ((uint)*(ushort *)(iVar6 + 0x5a) & (uint)uVar17) == 0))
          goto LAB_0051e509;
        }
      }
      else {
        if (bVar3 == *(byte *)((int)puVar13 + 0x11)) {
          iVar6 = (uint)bVar3 * 0x5c + *(int *)(local_7c + 0x7c);
LAB_0051e4b5:
          uVar12 = 1;
          goto LAB_0051e4ba;
        }
        bVar3 = *(byte *)((int)puVar9 + 0x11);
        if (bVar3 == (byte)puVar13[4]) {
          iVar6 = (uint)bVar3 * 0x5c + *(int *)(local_7c + 0x7c);
          uVar12 = 0;
          goto LAB_0051e4ba;
        }
        local_64 = uVar17;
        if (bVar3 == *(byte *)((int)puVar13 + 0x11)) {
          iVar6 = (uint)bVar3 * 0x5c + *(int *)(local_7c + 0x7c);
          goto LAB_0051e4b5;
        }
LAB_0051e509:
        puVar9 = (uint *)FUN_0051be90(&local_80);
        fVar15 = (float10)0;
        uVar12 = local_80;
        uVar17 = local_64;
      }
      local_64 = uVar17;
      if (puVar9 == (uint *)0x0) {
LAB_0051e5aa:
        puVar14 = (undefined4 *)(param_2 + 0x104);
        iVar8 = (uint)*(byte *)((*(char *)(param_2 + 0x160) == '\0') + 0x10 +
                               *(int *)(param_2 + 0x15c)) * 0x5c;
        iVar6 = iVar8 + 4 + *(int *)(local_7c + 0x7c);
        *puVar14 = *(undefined4 *)(iVar8 + 4 + *(int *)(local_7c + 0x7c));
        *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(iVar6 + 4);
        uVar10 = *(undefined4 *)(iVar6 + 8);
        *(float *)(param_2 + 0x110) = (float)fVar15;
        *(undefined4 *)(param_2 + 0x10c) = uVar10;
        fVar15 = (float10)FUN_005b3c50(puVar14,local_84,auStack_44);
        if (fVar15 < (float10)1.0) {
          *puVar14 = *local_84;
          *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_3 + 0x60);
          *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_3 + 100);
        }
        *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x400000;
        return;
      }
      uVar4 = puVar9[uVar12];
      if ((uVar4 & 0xdfffffff) != 0) {
        if ((uVar4 & 0xd8000000) != 0) {
          *(undefined4 *)(param_2 + 0x104) = *local_84;
          *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_3 + 0x60);
          uVar10 = *(undefined4 *)(param_3 + 100);
          *(float *)(param_2 + 0x110) = (float)fVar15;
          *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x400000;
          *(undefined4 *)(param_2 + 0x10c) = uVar10;
          *(uint *)(param_2 + 0x1f8) = puVar9[uVar12];
          return;
        }
        if ((*(uint *)(param_2 + 500) & uVar4) == 0) {
          *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x600000;
          *(uint *)(param_2 + 0x1f8) = puVar9[uVar12];
          goto LAB_0051e5aa;
        }
        *(uint *)(param_2 + 0x1ec) = *(uint *)(param_2 + 0x1ec) | 1;
      }
      if (puVar9 == puVar13) {
        uStack_54 = *(undefined4 *)(param_2 + 0x1b4);
        uStack_50 = *(undefined4 *)(param_2 + 0x1b8);
        uStack_4c = *(undefined4 *)(param_2 + 0x1bc);
      }
      else {
        puVar14 = (undefined4 *)
                  ((uint)*(byte *)(uVar12 + 0x10 + (int)puVar9) * 0x5c + 4 +
                  *(int *)(local_7c + 0x7c));
        uStack_54 = *puVar14;
        uStack_50 = puVar14[1];
        uStack_4c = puVar14[2];
        *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x80000;
      }
      iVar6 = FUN_0051b1f0(param_1,&uStack_54,*(undefined4 *)(param_2 + 0x158),local_70,param_4,
                           *(undefined4 *)(param_2 + 0x15c),*(undefined1 *)(param_2 + 0x13c),
                           *(undefined1 *)(param_3 + 0x28d),0,*(undefined4 *)(param_3 + 0xac),0);
      if (iVar6 != 0) {
        *(undefined4 *)(param_2 + 0x104) = uStack_54;
        *(undefined4 *)(param_2 + 0x108) = uStack_50;
        *(undefined4 *)(param_2 + 0x10c) = uStack_4c;
LAB_0051e706:
        *(undefined4 *)(param_2 + 0x110) = 0;
        return;
      }
      iVar6 = FUN_0051c430(param_1,param_2,param_3,local_70,puVar9);
      if (iVar6 == 0) {
        iVar6 = (uint)*(byte *)(uVar12 + 0x10 + (int)puVar9) * 0x5c;
        uStack_54 = *(undefined4 *)(iVar6 + 4 + *(int *)(local_7c + 0x7c));
        iVar6 = iVar6 + 4 + *(int *)(local_7c + 0x7c);
        uStack_50 = *(undefined4 *)(iVar6 + 4);
        uStack_4c = *(undefined4 *)(iVar6 + 8);
        goto LAB_0051e85a;
      }
      if ((*(byte *)(param_2 + 0x1e8) & 0x40) == 0) {
LAB_0051e7a6:
        if ((*(byte *)(param_2 + 0x1e8) & 0x20) == 0) goto LAB_0051e85a;
        puVar14 = (undefined4 *)(param_2 + 0x198);
        FUN_005b3800(auStack_44,puVar14,local_84);
        uVar10 = FUN_005be2d0(auStack_44[0],uStack_3c);
        FUN_005b3800(auStack_44,&uStack_54,local_84);
        uVar11 = FUN_005be2d0(auStack_44[0],uStack_3c);
        iVar6 = FUN_005be5b0(uVar11,uVar10);
        if (iVar6 < 1) goto LAB_0051e85a;
      }
      else {
        puVar14 = (undefined4 *)(param_2 + 0x1a4);
        FUN_005b3800(auStack_44,puVar14,local_84);
        uVar10 = FUN_005be2d0(auStack_44[0],uStack_3c);
        FUN_005b3800(auStack_44,&uStack_54,local_84);
        uVar11 = FUN_005be2d0(auStack_44[0],uStack_3c);
        iVar6 = FUN_005be5b0(uVar11,uVar10);
        if (-1 < iVar6) goto LAB_0051e7a6;
      }
      uStack_54 = *puVar14;
      uStack_50 = puVar14[1];
      uStack_4c = puVar14[2];
      *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x80000;
LAB_0051e85a:
      *(undefined4 *)(param_2 + 0x104) = uStack_54;
      *(undefined4 *)(param_2 + 0x110) = 0;
      *(undefined4 *)(param_2 + 0x108) = uStack_50;
      *(undefined4 *)(param_2 + 0x10c) = uStack_4c;
      return;
    }
    param_3 = *(int *)(param_2 + 0xd0);
  }
  else if (local_2c != 0) {
    if ((*(byte *)(param_2 + 0x1ec) & 4) != 0) {
      *(undefined4 *)(param_2 + 0x1c0) = local_10;
      *(undefined4 *)(param_2 + 0x1b4) = local_38;
      *(float *)(param_2 + 0x1c4) = local_48;
      *(undefined4 *)(param_2 + 0x1cc) = local_28;
      *(undefined4 *)(param_2 + 0x1b8) = local_34;
      *(undefined4 *)(param_2 + 0x1d0) = local_24;
      *(undefined4 *)(param_2 + 0x1bc) = local_30;
      *(undefined4 *)(param_2 + 0x1d4) = local_20;
      *(undefined4 *)(param_2 + 0x1d8) = local_1c;
      *(undefined4 *)(param_2 + 0x1dc) = local_18;
      *(undefined4 *)(param_2 + 0x1e0) = local_14;
      FUN_0051d5e0(param_1,param_2);
      FUN_0051d750();
      local_7c = *(int *)(param_2 + 0x158);
      puVar9 = *(uint **)(param_2 + 0x15c);
      puVar13 = *(uint **)(param_2 + 0x1d0);
      local_70 = puVar9;
    }
    goto LAB_0051da1b;
  }
LAB_0051e888:
  *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_3 + 0x5c);
  *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_3 + 0x60);
  uVar10 = *(undefined4 *)(param_3 + 100);
LAB_0051e89c:
  *(float *)(param_2 + 0x110) = (float)fVar15;
  *(undefined4 *)(param_2 + 0x10c) = uVar10;
  return;
}

