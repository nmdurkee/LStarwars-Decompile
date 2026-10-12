/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x7122b2; label: FUN_007122b2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x007127a3) */
/* WARNING: Removing unreachable block (ram,0x007127ad) */
/* WARNING: Removing unreachable block (ram,0x007127b2) */

void FUN_007122b2(int param_1,uint param_2,ushort param_3,int param_4,byte param_5,short *param_6)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  bool bVar4;
  errno_t eVar5;
  short *psVar6;
  uint uVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  char cVar15;
  uint uVar16;
  int iVar17;
  short *psVar18;
  short *psVar19;
  int iVar20;
  uint uVar21;
  ushort uVar22;
  ushort uVar23;
  char *pcVar24;
  undefined *local_6c;
  ushort *local_60;
  ushort *local_5c;
  ushort *local_58;
  int local_54;
  short local_50;
  ushort *local_4c;
  uint local_48;
  int local_44;
  ushort local_40;
  undefined4 uStack_3e;
  ushort uStack_3a;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 local_24;
  undefined4 uStack_20;
  ushort uStack_1c;
  undefined1 local_1a;
  byte bStack_19;
  byte local_14;
  undefined1 uStack_13;
  undefined4 uStack_12;
  undefined4 uStack_e;
  ushort uStack_a;
  uint local_8;
  
  uVar7 = CONCAT22(local_24._2_2_,(ushort)local_24);
  iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  local_14 = (byte)param_1;
  uStack_13 = (undefined1)((uint)param_1 >> 8);
  uStack_12._0_2_ = (ushort)((uint)param_1 >> 0x10);
  uStack_12._2_2_ = (ushort)param_2;
  uStack_e._0_2_ = (ushort)(param_2 >> 0x10);
  uStack_e._2_2_ = param_3;
  uVar14 = CONCAT22(param_3,(ushort)uStack_e);
  uVar10 = CONCAT22(param_3,(ushort)uStack_e);
  uVar8 = param_3 & 0x8000;
  uVar13 = param_3 & 0x7fff;
  local_34 = 0xcccccccc;
  local_30 = 0xcccccccc;
  local_2c._0_1_ = 0xcc;
  local_2c._1_1_ = 0xcc;
  uStack_2a = 0xfb;
  uStack_29 = 0x3f;
  if (uVar8 == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar13 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *param_6 = 0;
    *(byte *)(param_6 + 1) = ((uVar8 != 0x8000) - 1U & 0xd) + 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
    goto LAB_00712b30;
  }
  if ((short)uVar13 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
      if ((uVar8 == 0) || (param_2 != 0xc0000000)) {
        if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_007123e1;
        pcVar24 = "1#INF";
      }
      else {
        if (param_1 != 0) {
LAB_007123e1:
          pcVar24 = "1#QNAN";
          goto LAB_007123e6;
        }
        pcVar24 = "1#IND";
      }
      eVar5 = _strcpy_s((char *)(param_6 + 2),0x16,pcVar24);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      *(undefined1 *)((int)param_6 + 3) = 5;
    }
    else {
      pcVar24 = "1#SNAN";
LAB_007123e6:
      eVar5 = _strcpy_s((char *)(param_6 + 2),0x16,pcVar24);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      *(undefined1 *)((int)param_6 + 3) = 6;
    }
    iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
    uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
    uVar7 = CONCAT22(local_24._2_2_,(ushort)local_24);
    goto LAB_00712b30;
  }
  local_50 = (short)(((uVar13 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar13 * 0x4d10
                    >> 0x10);
  uVar16 = (uint)local_50;
  local_1a = (undefined1)uVar13;
  bStack_19 = (byte)(uVar13 >> 8);
  local_24._2_2_ = (ushort)param_1;
  local_24._0_2_ = 0;
  uVar7 = param_1 << 0x10;
  local_6c = &DAT_0082aad8;
  uStack_1c = (ushort)uStack_e;
  uStack_20 = uStack_12;
  if (uVar16 != 0) {
    uVar13 = -uVar16;
    uVar14 = uVar10;
    uVar7 = param_1 << 0x10;
    if ((int)-uVar16 < 0) {
      local_6c = &DAT_0082ac38;
      uVar13 = uVar16;
    }
joined_r0x00712474:
    if (uVar13 != 0) {
      local_6c = local_6c + 0x54;
      uVar10 = uVar13 & 7;
      uVar13 = (int)uVar13 >> 3;
      if (uVar10 != 0) {
        puVar11 = (ushort *)(local_6c + uVar10 * 0xc);
        if (0x7fff < *puVar11) {
          local_40 = (ushort)*(undefined4 *)puVar11;
          uStack_3e._0_2_ = (undefined2)((uint)*(undefined4 *)puVar11 >> 0x10);
          puVar2 = puVar11 + 4;
          uStack_3e._2_2_ = (undefined2)*(undefined4 *)(puVar11 + 2);
          uStack_3a = (ushort)((uint)*(undefined4 *)(puVar11 + 2) >> 0x10);
          puVar11 = &local_40;
          local_38 = *(int *)puVar2;
          iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e) + -1;
          uStack_3e._0_2_ = (undefined2)iVar1;
          uStack_3e._2_2_ = (undefined2)((uint)iVar1 >> 0x10);
        }
        uVar12 = CONCAT11(bStack_19,local_1a) & 0x7fff;
        uVar22 = puVar11[5] & 0x7fff;
        local_4c = (ushort *)0x0;
        local_14 = 0;
        uStack_13 = 0;
        uStack_12._0_2_ = 0;
        uStack_12._2_2_ = 0;
        uStack_12 = 0;
        uStack_e._0_2_ = 0;
        uStack_e._2_2_ = 0;
        uVar16 = 0;
        uStack_a = 0;
        uVar9 = (puVar11[5] ^ CONCAT11(bStack_19,local_1a)) & 0x8000;
        uVar23 = uVar22 + uVar12;
        uVar10 = 0;
        uVar14 = 0;
        if (((uVar12 < 0x7fff) && (uVar10 = 0, uVar14 = 0, uVar22 < 0x7fff)) &&
           (uVar10 = uStack_12, uVar14 = uVar16, uVar23 < 0xbffe)) {
          if (uVar23 < 0x3fc0) {
            uStack_1c = 0;
            local_1a = 0;
            bStack_19 = 0;
            uStack_20._0_2_ = 0;
            uStack_20._2_2_ = 0;
            local_24._0_2_ = 0;
            local_24._2_2_ = 0;
            uStack_20 = 0;
            uVar7 = 0;
            goto joined_r0x00712474;
          }
          if (((uVar12 == 0) &&
              (uVar23 = uVar23 + 1,
              (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) & 0x7fffffff) == 0)) &&
             ((uStack_20 == 0 && (uVar7 == 0)))) {
            local_1a = 0;
            bStack_19 = 0;
            goto joined_r0x00712474;
          }
          if ((((uVar22 == 0) && (uVar23 = uVar23 + 1, (*(uint *)(puVar11 + 4) & 0x7fffffff) == 0))
              && (*(int *)(puVar11 + 2) == 0)) && (*(int *)puVar11 == 0)) {
            uStack_1c = 0;
            local_1a = 0;
            bStack_19 = 0;
            uStack_20._0_2_ = 0;
            uStack_20._2_2_ = 0;
            local_24._0_2_ = 0;
            local_24._2_2_ = 0;
            uStack_20 = 0;
            uVar7 = 0;
            goto joined_r0x00712474;
          }
          psVar6 = (short *)((int)&uStack_12 + 2);
          local_60 = (ushort *)0x0;
          local_44 = 5;
          do {
            local_54 = local_44;
            if (0 < local_44) {
              local_5c = (ushort *)((int)&local_24 + (int)local_60 * 2);
              local_58 = puVar11 + 4;
              do {
                bVar4 = false;
                uVar14 = *(uint *)(psVar6 + -2) + (uint)*local_5c * (uint)*local_58;
                if ((uVar14 < *(uint *)(psVar6 + -2)) ||
                   (uVar14 < (uint)*local_5c * (uint)*local_58)) {
                  bVar4 = true;
                }
                *(uint *)(psVar6 + -2) = uVar14;
                if (bVar4) {
                  *psVar6 = *psVar6 + 1;
                }
                local_5c = local_5c + 1;
                local_58 = local_58 + -1;
                local_54 = local_54 + -1;
              } while (0 < local_54);
            }
            psVar6 = psVar6 + 1;
            local_60 = (ushort *)((int)local_60 + 1);
            local_44 = local_44 + -1;
          } while (0 < local_44);
          uVar23 = uVar23 + 0xc002;
          if ((short)uVar23 < 1) {
LAB_0071262b:
            uVar23 = uVar23 - 1;
            if ((short)uVar23 < 0) {
              local_48 = (uint)(ushort)-uVar23;
              uVar23 = 0;
              do {
                if ((local_14 & 1) != 0) {
                  local_4c = (ushort *)((int)local_4c + 1);
                }
                iVar20 = CONCAT22(uStack_a,uStack_e._2_2_);
                uVar14 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
                iVar17 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
                uStack_e._2_2_ = (ushort)(CONCAT22(uStack_a,uStack_e._2_2_) >> 1);
                uStack_a = uStack_a >> 1;
                uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uint)(iVar20 << 0x1f) >> 0x10);
                uVar7 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) >> 1;
                uStack_12._0_2_ = (ushort)uStack_12 >> 1 | (ushort)((uint)(iVar17 << 0x1f) >> 0x10);
                local_48 = local_48 - 1;
                uStack_12._2_2_ = (ushort)(uVar14 >> 1);
                local_14 = (byte)uVar7;
                uStack_13 = (undefined1)(uVar7 >> 8);
              } while (local_48 != 0);
              if (local_4c != (ushort *)0x0) {
                local_14 = local_14 | 1;
              }
            }
          }
          else {
            do {
              uVar12 = (ushort)uStack_12;
              if ((uStack_a & 0x8000) != 0) break;
              iVar17 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) << 1;
              local_14 = (byte)iVar17;
              uStack_13 = (undefined1)((uint)iVar17 >> 8);
              uStack_12._0_2_ = (ushort)((uint)iVar17 >> 0x10);
              iVar17 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
              uStack_12._2_2_ = (ushort)iVar17 | uVar12 >> 0xf;
              iVar20 = CONCAT22(uStack_a,uStack_e._2_2_) * 2;
              uStack_e._2_2_ = (ushort)iVar20 | (ushort)uStack_e >> 0xf;
              uVar23 = uVar23 - 1;
              uStack_e._0_2_ = (ushort)((uint)iVar17 >> 0x10);
              uStack_a = (ushort)((uint)iVar20 >> 0x10);
            } while (0 < (short)uVar23);
            if ((short)uVar23 < 1) goto LAB_0071262b;
          }
          if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
             (uVar14 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e),
             uVar10 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12),
             (CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
            if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
              uStack_12._0_2_ = 0;
              uStack_12._2_2_ = 0;
              uVar10 = 0;
              if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
                uStack_e._0_2_ = 0;
                uStack_e._2_2_ = 0;
                if (uStack_a == 0xffff) {
                  uStack_a = 0x8000;
                  uVar23 = uVar23 + 1;
                  uVar14 = 0;
                  uVar10 = 0;
                }
                else {
                  uStack_a = uStack_a + 1;
                  uVar14 = 0;
                  uVar10 = 0;
                }
              }
              else {
                uVar14 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
                uStack_e._0_2_ = (ushort)uVar14;
                uStack_e._2_2_ = (ushort)(uVar14 >> 0x10);
              }
            }
            else {
              uVar10 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
              uStack_12._0_2_ = (ushort)uVar10;
              uStack_12._2_2_ = (ushort)(uVar10 >> 0x10);
              uVar14 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
            }
          }
          if (uVar23 < 0x7fff) {
            local_24 = uVar10;
            bStack_19 = (byte)(uVar23 >> 8) | (byte)(uVar9 >> 8);
            uStack_20 = uVar14;
            uStack_1c = uStack_a;
            local_1a = (undefined1)uVar23;
            uStack_12 = uVar10;
            uVar7 = uVar10;
            goto joined_r0x00712474;
          }
        }
        uStack_20._0_2_ = 0;
        uStack_20._2_2_ = 0;
        uStack_20 = 0;
        iVar17 = (-(uint)(uVar9 != 0) & 0x80000000) + 0x7fff8000;
        local_24._0_2_ = 0;
        local_24._2_2_ = 0;
        uVar7 = 0;
        uStack_1c = (ushort)iVar17;
        local_1a = (undefined1)((uint)iVar17 >> 0x10);
        bStack_19 = (byte)((uint)iVar17 >> 0x18);
        uStack_12 = uVar10;
      }
      goto joined_r0x00712474;
    }
  }
  uVar13 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c));
  uVar10 = uVar14;
  if (0x3ffe < (ushort)(uVar13 >> 0x10)) {
    local_50 = local_50 + 1;
    uVar14 = uVar13 >> 0x10 & 0x7fff;
    iVar17 = uVar14 + 0x3ffb;
    local_5c = (ushort *)0x0;
    local_14 = 0;
    uStack_13 = 0;
    uStack_12._0_2_ = 0;
    uStack_12._2_2_ = 0;
    uStack_12 = 0;
    uStack_e._0_2_ = 0;
    uStack_e._2_2_ = 0;
    uVar10 = 0;
    uStack_a = 0;
    if (((ushort)uVar14 < 0x7fff) && ((ushort)iVar17 < 0xbffe)) {
      if (0x3fbf < (ushort)iVar17) {
        if (((((ushort)uVar14 == 0) &&
             (iVar17 = uVar14 + 0x3ffc,
             (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) & 0x7fffffff) == 0)) &&
            (uStack_20 == 0)) && (uVar7 == 0)) {
          local_1a = 0;
          bStack_19 = 0;
          goto LAB_0071296f;
        }
        local_58 = (ushort *)0x0;
        psVar6 = (short *)((int)&uStack_12 + 2);
        local_44 = 5;
        do {
          local_54 = local_44;
          if (0 < local_44) {
            local_60 = &local_2c;
            local_4c = (ushort *)((int)&local_24 + (int)local_58 * 2);
            do {
              bVar4 = false;
              uVar14 = *(uint *)(psVar6 + -2) + (uint)*local_60 * (uint)*local_4c;
              if ((uVar14 < *(uint *)(psVar6 + -2)) || (uVar14 < (uint)*local_60 * (uint)*local_4c))
              {
                bVar4 = true;
              }
              *(uint *)(psVar6 + -2) = uVar14;
              if (bVar4) {
                *psVar6 = *psVar6 + 1;
              }
              local_4c = local_4c + 1;
              local_60 = local_60 + -1;
              local_54 = local_54 + -1;
            } while (0 < local_54);
          }
          psVar6 = psVar6 + 1;
          local_58 = (ushort *)((int)local_58 + 1);
          local_44 = local_44 + -1;
        } while (0 < local_44);
        iVar17 = iVar17 + 0xc002;
        if ((short)iVar17 < 1) {
LAB_0071287d:
          uVar23 = (ushort)(iVar17 + 0xffff);
          if ((short)uVar23 < 0) {
            uVar14 = -(iVar17 + 0xffff);
            uVar7 = uVar14 & 0xffff;
            uVar23 = uVar23 + (short)uVar14;
            do {
              if ((local_14 & 1) != 0) {
                local_5c = (ushort *)((int)local_5c + 1);
              }
              iVar20 = CONCAT22(uStack_a,uStack_e._2_2_);
              uVar14 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
              iVar17 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
              uStack_e._2_2_ = (ushort)(CONCAT22(uStack_a,uStack_e._2_2_) >> 1);
              uStack_a = uStack_a >> 1;
              uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uint)(iVar20 << 0x1f) >> 0x10);
              uVar10 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) >> 1;
              uStack_12._0_2_ = (ushort)uStack_12 >> 1 | (ushort)((uint)(iVar17 << 0x1f) >> 0x10);
              uVar7 = uVar7 - 1;
              uStack_12._2_2_ = (ushort)(uVar14 >> 1);
              local_14 = (byte)uVar10;
              uStack_13 = (undefined1)(uVar10 >> 8);
            } while (uVar7 != 0);
            if (local_5c != (ushort *)0x0) {
              local_14 = local_14 | 1;
            }
          }
        }
        else {
          do {
            uVar23 = (ushort)uStack_12;
            if ((uStack_a & 0x8000) != 0) break;
            iVar20 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) << 1;
            local_14 = (byte)iVar20;
            uStack_13 = (undefined1)((uint)iVar20 >> 8);
            uStack_12._0_2_ = (ushort)((uint)iVar20 >> 0x10);
            iVar20 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
            uStack_12._2_2_ = (ushort)iVar20 | uVar23 >> 0xf;
            iVar3 = CONCAT22(uStack_a,uStack_e._2_2_) * 2;
            uStack_e._2_2_ = (ushort)iVar3 | (ushort)uStack_e >> 0xf;
            iVar17 = iVar17 + 0xffff;
            uStack_e._0_2_ = (ushort)((uint)iVar20 >> 0x10);
            uStack_a = (ushort)((uint)iVar3 >> 0x10);
          } while (0 < (short)iVar17);
          uVar23 = (ushort)iVar17;
          if ((short)uVar23 < 1) goto LAB_0071287d;
        }
        uStack_20 = 0;
        if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
           (uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e),
           uStack_12 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12),
           (CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
          if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
            uStack_12 = uStack_20;
            if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
              uVar10 = uStack_20;
              if (uStack_a == 0xffff) {
                uStack_a = 0x8000;
                uVar23 = uVar23 + 1;
              }
              else {
                uStack_a = uStack_a + 1;
              }
            }
            else {
              uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
            }
          }
          else {
            uStack_12 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
            uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
          }
        }
        if (uVar23 < 0x7fff) {
          bStack_19 = (byte)(uVar23 >> 8) | bStack_19 & 0x80;
          uStack_1c = uStack_a;
          local_1a = (undefined1)uVar23;
          uStack_20 = uVar10;
          uVar7 = uStack_12;
        }
        else {
          iVar17 = (-(uint)((bStack_19 & 0x80) != 0) & 0x80000000) + 0x7fff8000;
          uStack_1c = (ushort)iVar17;
          local_1a = (undefined1)((uint)iVar17 >> 0x10);
          bStack_19 = (byte)((uint)iVar17 >> 0x18);
          uVar7 = uStack_20;
        }
        goto LAB_0071296f;
      }
      uStack_1c = 0;
      local_1a = 0;
      bStack_19 = 0;
    }
    else {
      iVar17 = (-(uint)((bStack_19 & 0x80) != 0) & 0x80000000) + 0x7fff8000;
      uStack_1c = (ushort)iVar17;
      local_1a = (undefined1)((uint)iVar17 >> 0x10);
      bStack_19 = (byte)((uint)iVar17 >> 0x18);
    }
    uStack_12 = 0;
    uVar10 = 0;
    uStack_20 = 0;
    uVar7 = 0;
  }
LAB_0071296f:
  *param_6 = local_50;
  if (((param_5 & 1) == 0) || (param_4 = param_4 + local_50, 0 < param_4)) {
    if (0x15 < param_4) {
      param_4 = 0x15;
    }
    iVar20 = (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) >> 0x10) - 0x3ffe;
    local_1a = 0;
    bStack_19 = 0;
    iVar17 = 8;
    uVar14 = uVar7;
    do {
      uVar7 = uVar14 << 1;
      uVar13 = uStack_20 * 2;
      iVar3 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) * 2;
      uStack_1c = (ushort)iVar3 | (ushort)(uStack_20 >> 0x1f);
      iVar17 = iVar17 + -1;
      uStack_20._0_2_ = (ushort)(uVar13 | uVar14 >> 0x1f);
      uStack_20._2_2_ = (ushort)(uVar13 >> 0x10);
      local_1a = (undefined1)((uint)iVar3 >> 0x10);
      bStack_19 = (byte)((uint)iVar3 >> 0x18);
      uVar14 = uVar7;
    } while (iVar17 != 0);
    if ((iVar20 < 0) && (uVar14 = -iVar20 & 0xff, uVar14 != 0)) {
      do {
        iVar20 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c));
        uVar16 = CONCAT22(uStack_20._2_2_,(ushort)uStack_20);
        iVar17 = CONCAT22(uStack_20._2_2_,(ushort)uStack_20);
        uVar13 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) >> 1;
        uStack_1c = (ushort)uVar13;
        local_1a = (undefined1)(uVar13 >> 0x10);
        bStack_19 = bStack_19 >> 1;
        uStack_20._2_2_ = uStack_20._2_2_ >> 1 | (ushort)((uint)(iVar20 << 0x1f) >> 0x10);
        local_24._2_2_ = (ushort)(uVar7 >> 0x11) | (ushort)((uint)(iVar17 << 0x1f) >> 0x10);
        uVar14 = uVar14 - 1;
        uStack_20._0_2_ = (ushort)(uVar16 >> 1);
        local_24._0_2_ = (ushort)(uVar7 >> 1);
        uVar7 = CONCAT22(local_24._2_2_,(ushort)local_24);
      } while (0 < (int)uVar14);
    }
    psVar6 = param_6 + 2;
    psVar18 = psVar6;
    uVar23 = uStack_20._2_2_;
    for (param_4 = param_4 + 1; 0 < param_4; param_4 = param_4 + -1) {
      local_24._2_2_ = (ushort)(uVar7 >> 0x10);
      local_24._0_2_ = (ushort)uVar7;
      iVar1 = CONCAT22((ushort)uStack_20,local_24._2_2_);
      local_38 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c));
      uVar13 = (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) * 2 | (uint)(uVar23 >> 0xf)) * 2 |
               (CONCAT22(uVar23,(ushort)uStack_20) & 0x7fffffff) >> 0x1e;
      uVar16 = (CONCAT22(uVar23,(ushort)uStack_20) * 2 | (uint)(local_24._2_2_ >> 0xf)) * 2 |
               (uVar7 & 0x7fffffff) >> 0x1e;
      uVar14 = uVar7 * 5;
      if ((uVar14 < uVar7 * 4) || (uVar21 = uVar16, uVar14 < uVar7)) {
        uVar21 = uVar16 + 1;
        bVar4 = false;
        if ((uVar21 < uVar16) || (uVar21 == 0)) {
          bVar4 = true;
        }
        if (bVar4) {
          uVar13 = uVar13 + 1;
        }
      }
      uVar16 = CONCAT22(uVar23,(ushort)uStack_20) + uVar21;
      if ((uVar16 < uVar21) || (uVar16 < CONCAT22(uVar23,(ushort)uStack_20))) {
        uVar13 = uVar13 + 1;
      }
      iVar17 = (uVar13 + local_38) * 2;
      uStack_1c = (ushort)iVar17 | (ushort)(uVar16 >> 0x1f);
      uVar7 = uVar7 * 10;
      local_1a = (undefined1)((uint)iVar17 >> 0x10);
      uStack_20._0_2_ = (ushort)(uVar16 * 2) | (ushort)(uVar14 >> 0x1f);
      *(char *)psVar18 = (char)((uint)iVar17 >> 0x18) + '0';
      psVar18 = (short *)((int)psVar18 + 1);
      uStack_20._2_2_ = (ushort)(uVar16 * 2 >> 0x10);
      bStack_19 = 0;
      local_40 = (ushort)local_24;
      uStack_3a = uVar23;
      uVar23 = uStack_20._2_2_;
    }
    uStack_20 = CONCAT22(uVar23,(ushort)uStack_20);
    psVar19 = psVar18 + -1;
    if (*(char *)((int)psVar18 + -1) < '5') {
      for (; (psVar6 <= psVar19 && ((char)*psVar19 == '0')); psVar19 = (short *)((int)psVar19 + -1))
      {
      }
      if (psVar19 < psVar6) {
        *param_6 = 0;
        *(undefined1 *)((int)param_6 + 3) = 1;
        *(byte *)(param_6 + 1) = ((uVar8 != 0x8000) - 1U & 0xd) + 0x20;
        *(char *)psVar6 = '0';
        *(undefined1 *)((int)param_6 + 5) = 0;
        goto LAB_00712b30;
      }
    }
    else {
      for (; (psVar6 <= psVar19 && ((char)*psVar19 == '9')); psVar19 = (short *)((int)psVar19 + -1))
      {
        *(char *)psVar19 = '0';
      }
      if (psVar19 < psVar6) {
        psVar19 = (short *)((int)psVar19 + 1);
        *param_6 = *param_6 + 1;
      }
      *(char *)psVar19 = (char)*psVar19 + '\x01';
    }
    cVar15 = ((char)psVar19 - (char)param_6) + -3;
    *(char *)((int)param_6 + 3) = cVar15;
    *(undefined1 *)(cVar15 + 4 + (int)param_6) = 0;
  }
  else {
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(byte *)(param_6 + 1) = ((uVar8 != 0x8000) - 1U & 0xd) + 0x20;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
  }
LAB_00712b30:
  local_24 = uVar7;
  uStack_e = uVar10;
  uStack_3e = iVar1;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

