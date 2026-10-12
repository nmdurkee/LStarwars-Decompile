/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x711b2c; label: FUN_00711b2c
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00711b2c(undefined2 *param_1,int *param_2,char *param_3,int param_4,int param_5,int param_6
                 ,int param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  ushort uVar9;
  char cVar10;
  ushort uVar11;
  undefined4 *puVar12;
  uint uVar13;
  ushort *puVar14;
  int iVar15;
  ushort uVar16;
  int iVar17;
  uint uVar18;
  ushort uVar19;
  char *pcVar20;
  undefined4 uVar21;
  undefined *puVar22;
  short *psVar23;
  uint uVar24;
  undefined4 uVar25;
  ushort uVar26;
  char *pcVar27;
  int local_6c;
  int local_68;
  ushort *local_64;
  ushort *local_60;
  int local_5c;
  char *local_58;
  int local_54;
  uint local_50;
  ushort local_4c;
  undefined4 uStack_4a;
  undefined2 uStack_46;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  ushort uStack_38;
  ushort local_36;
  byte local_30;
  undefined1 uStack_2f;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  ushort uStack_26;
  char local_24 [23];
  char local_d;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  iVar17 = 0;
  pcVar27 = local_24;
  uVar9 = 0;
  local_6c = 1;
  local_50 = 0;
  bVar6 = false;
  bVar8 = false;
  bVar7 = false;
  local_68 = 0;
  local_54 = 0;
  if (param_8 != (int *)0x0) {
    local_58 = param_3;
    for (; (((cVar10 = *param_3, cVar10 == ' ' || (cVar10 == '\t')) || (cVar10 == '\n')) ||
           (cVar10 == '\r')); param_3 = param_3 + 1) {
    }
LAB_00711bb1:
    cVar10 = *param_3;
    pcVar20 = param_3 + 1;
    switch(iVar17) {
    case 0:
      if ((byte)(cVar10 - 0x31U) < 9) {
LAB_00711bce:
        iVar17 = 3;
        goto LAB_00711bd0;
      }
      if (cVar10 == *(char *)**(undefined4 **)(*param_8 + 0xbc)) {
LAB_00711be5:
        iVar17 = 5;
        param_3 = pcVar20;
      }
      else if (cVar10 == '+') {
        uVar9 = 0;
        iVar17 = 2;
        param_3 = pcVar20;
      }
      else {
        if (cVar10 != '-') {
          if (cVar10 == '0') goto LAB_00711bff;
          goto LAB_00711d8a;
        }
        iVar17 = 2;
        uVar9 = 0x8000;
        param_3 = pcVar20;
      }
      goto LAB_00711bb1;
    case 1:
      bVar6 = true;
      if ((byte)(cVar10 - 0x31U) < 9) goto LAB_00711bce;
      if (cVar10 == *(char *)**(undefined4 **)(*param_8 + 0xbc)) goto LAB_00711c36;
      if ((cVar10 == '+') || (cVar10 == '-')) goto LAB_00711c66;
      if (cVar10 == '0') goto LAB_00711bff;
      goto LAB_00711c46;
    case 2:
      if ((byte)(cVar10 - 0x31U) < 9) goto LAB_00711bce;
      if (cVar10 == *(char *)**(undefined4 **)(*param_8 + 0xbc)) goto LAB_00711be5;
      param_3 = local_58;
      if (cVar10 != '0') goto LAB_00711db5;
LAB_00711bff:
      iVar17 = 1;
      param_3 = pcVar20;
      goto LAB_00711bb1;
    case 3:
      while (('/' < cVar10 && (cVar10 < ':'))) {
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar27 = cVar10 + -0x30;
          pcVar27 = pcVar27 + 1;
        }
        else {
          local_54 = local_54 + 1;
        }
        cVar10 = *pcVar20;
        pcVar20 = pcVar20 + 1;
      }
      if (cVar10 != *(char *)**(undefined4 **)(*param_8 + 0xbc)) goto LAB_00711cd9;
LAB_00711c36:
      bVar6 = true;
      iVar17 = 4;
      param_3 = pcVar20;
      goto LAB_00711bb1;
    case 4:
      bVar8 = true;
      if (local_50 == 0) {
        while (cVar10 == '0') {
          local_54 = local_54 + -1;
          cVar10 = *pcVar20;
          pcVar20 = pcVar20 + 1;
        }
      }
      while (('/' < cVar10 && (cVar10 < ':'))) {
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar27 = cVar10 + -0x30;
          pcVar27 = pcVar27 + 1;
          local_54 = local_54 + -1;
        }
        cVar10 = *pcVar20;
        pcVar20 = pcVar20 + 1;
      }
LAB_00711cd9:
      if ((cVar10 == '+') || (cVar10 == '-')) {
LAB_00711c66:
        bVar6 = true;
        iVar17 = 0xb;
        param_3 = pcVar20 + -1;
      }
      else {
LAB_00711c46:
        bVar6 = true;
        if ((cVar10 < 'D') || (('E' < cVar10 && ((cVar10 < 'd' || ('e' < cVar10))))))
        goto LAB_00711d8a;
        iVar17 = 6;
        param_3 = pcVar20;
      }
      goto LAB_00711bb1;
    case 5:
      bVar8 = true;
      param_3 = local_58;
      if ((byte)(cVar10 - 0x30U) < 10) {
        iVar17 = 4;
        goto LAB_00711bd0;
      }
      goto LAB_00711db5;
    case 6:
      local_58 = param_3 + -1;
      if (8 < (byte)(cVar10 - 0x31U)) {
        if (cVar10 == '+') goto LAB_00711d71;
        if (cVar10 == '-') goto LAB_00711d65;
LAB_00711d58:
        param_3 = local_58;
        if (cVar10 != '0') goto LAB_00711db5;
        iVar17 = 8;
        param_3 = pcVar20;
        goto LAB_00711bb1;
      }
      break;
    case 7:
      if (8 < (byte)(cVar10 - 0x31U)) goto LAB_00711d58;
      break;
    case 8:
      bVar7 = true;
      while (cVar10 == '0') {
        cVar10 = *pcVar20;
        pcVar20 = pcVar20 + 1;
      }
      if (8 < (byte)(cVar10 - 0x31U)) goto LAB_00711d8a;
      break;
    case 9:
      bVar7 = true;
      local_68 = 0;
      goto LAB_00711e17;
    default:
      goto switchD_00711bbd_caseD_a;
    case 0xb:
      if (param_7 != 0) {
        local_58 = param_3;
        if (cVar10 == '+') {
LAB_00711d71:
          iVar17 = 7;
          param_3 = pcVar20;
        }
        else {
          if (cVar10 != '-') goto LAB_00711db5;
LAB_00711d65:
          local_6c = -1;
          iVar17 = 7;
          param_3 = pcVar20;
        }
        goto LAB_00711bb1;
      }
      iVar17 = 10;
      pcVar20 = param_3;
switchD_00711bbd_caseD_a:
      param_3 = pcVar20;
      if (iVar17 != 10) goto LAB_00711bb1;
      goto LAB_00711db5;
    }
    iVar17 = 9;
LAB_00711bd0:
    param_3 = pcVar20 + -1;
    goto LAB_00711bb1;
  }
  puVar12 = (undefined4 *)FUN_006ead5f();
  *puVar12 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  iVar15 = CONCAT22(local_40._2_2_,(undefined2)local_40);
  goto LAB_007121ad;
LAB_00711e17:
  if ((cVar10 < '0') || ('9' < cVar10)) goto LAB_00711e32;
  local_68 = local_68 * 10 + -0x30 + (int)cVar10;
  if (local_68 < 0x1451) {
    cVar10 = *pcVar20;
    pcVar20 = pcVar20 + 1;
    goto LAB_00711e17;
  }
  local_68 = 0x1451;
LAB_00711e32:
  while (('/' < cVar10 && (cVar10 < ':'))) {
    cVar10 = *pcVar20;
    pcVar20 = pcVar20 + 1;
  }
LAB_00711d8a:
  param_3 = pcVar20 + -1;
LAB_00711db5:
  *param_2 = (int)param_3;
  if (bVar6) {
    if (0x18 < local_50) {
      if ('\x04' < local_d) {
        local_d = local_d + '\x01';
      }
      pcVar27 = pcVar27 + -1;
      local_54 = local_54 + 1;
      local_50 = 0x18;
    }
    if (local_50 == 0) goto LAB_0071218f;
    while (pcVar27 = pcVar27 + -1, *pcVar27 == '\0') {
      local_50 = local_50 - 1;
      local_54 = local_54 + 1;
    }
    ___mtold12(local_24,local_50,&local_40);
    iVar5 = CONCAT22(local_3c._2_2_,(undefined2)local_3c);
    iVar15 = CONCAT22(local_40._2_2_,(undefined2)local_40);
    iVar2 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a);
    iVar1 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e);
    iVar17 = CONCAT22(uStack_4a._2_2_,(undefined2)uStack_4a);
    if (local_6c < 0) {
      local_68 = -local_68;
    }
    local_58 = (char *)(local_68 + local_54);
    if (!bVar7) {
      local_58 = (char *)((int)local_58 + param_5);
    }
    if (!bVar8) {
      local_58 = (char *)((int)local_58 - param_6);
    }
    if ((int)local_58 < 0x1451) {
      if ((int)local_58 < -0x1450) goto LAB_0071218f;
      puVar22 = &DAT_0082aad8;
      if (local_58 != (char *)0x0) {
        if ((int)local_58 < 0) {
          local_58 = (char *)-(int)local_58;
          puVar22 = &DAT_0082ac38;
        }
        if (param_4 == 0) {
          local_40._0_2_ = 0;
        }
        iVar17 = uStack_4a;
        iVar1 = uStack_2e;
        iVar2 = uStack_2a;
        iVar15 = CONCAT22(local_40._2_2_,(undefined2)local_40);
        iVar5 = local_3c;
joined_r0x00711ebd:
        if (local_58 != (char *)0x0) {
          uVar24 = (int)local_58 >> 3;
          puVar22 = puVar22 + 0x54;
          uVar13 = (uint)local_58 & 7;
          local_58 = (char *)uVar24;
          if (uVar13 != 0) {
            puVar14 = (ushort *)(puVar22 + uVar13 * 0xc);
            if (0x7fff < *puVar14) {
              local_4c = (ushort)*(undefined4 *)puVar14;
              uStack_4a._0_2_ = (undefined2)((uint)*(undefined4 *)puVar14 >> 0x10);
              uStack_4a._2_2_ = (undefined2)*(undefined4 *)(puVar14 + 2);
              uStack_46 = (undefined2)((uint)*(undefined4 *)(puVar14 + 2) >> 0x10);
              local_44 = *(undefined4 *)(puVar14 + 4);
              iVar17 = CONCAT22(uStack_4a._2_2_,(undefined2)uStack_4a) + -1;
              uStack_4a._0_2_ = (undefined2)iVar17;
              uStack_4a._2_2_ = (undefined2)((uint)iVar17 >> 0x10);
              puVar14 = &local_4c;
            }
            local_54 = 0;
            local_30 = 0;
            uStack_2f = 0;
            uStack_2e._0_2_ = 0;
            uStack_2e._2_2_ = 0;
            iVar3 = 0;
            uStack_2a._0_2_ = 0;
            uStack_2a._2_2_ = 0;
            iVar4 = 0;
            uStack_26 = 0;
            uVar16 = local_36 & 0x7fff;
            uVar19 = puVar14[5] & 0x7fff;
            uVar11 = (puVar14[5] ^ local_36) & 0x8000;
            uVar26 = uVar19 + uVar16;
            iVar1 = 0;
            iVar2 = 0;
            if (((uVar16 < 0x7fff) && (iVar1 = 0, iVar2 = 0, uVar19 < 0x7fff)) &&
               (iVar1 = iVar3, iVar2 = iVar4, uVar26 < 0xbffe)) {
              if (0x3fbf < uVar26) {
                if (((uVar16 == 0) &&
                    (uVar26 = uVar26 + 1, (CONCAT22(local_36,uStack_38) & 0x7fffffff) == 0)) &&
                   ((iVar5 == 0 && (iVar15 == 0)))) {
                  local_36 = 0;
                }
                else if (((uVar19 == 0) &&
                         (uVar26 = uVar26 + 1, (*(uint *)(puVar14 + 4) & 0x7fffffff) == 0)) &&
                        ((*(int *)(puVar14 + 2) == 0 && (*(int *)puVar14 == 0)))) {
                  uStack_38 = 0;
                  local_36 = 0;
                  local_3c._0_2_ = 0;
                  local_3c._2_2_ = 0;
                  local_40._0_2_ = 0;
                  local_40._2_2_ = 0;
                  iVar15 = 0;
                  iVar5 = 0;
                }
                else {
                  local_6c = 0;
                  psVar23 = (short *)((int)&uStack_2e + 2);
                  local_5c = 5;
                  do {
                    local_68 = local_5c;
                    if (0 < local_5c) {
                      local_60 = (ushort *)((int)&local_40 + local_6c * 2);
                      local_64 = puVar14 + 4;
                      do {
                        bVar6 = false;
                        uVar24 = *(uint *)(psVar23 + -2) + (uint)*local_64 * (uint)*local_60;
                        if ((uVar24 < *(uint *)(psVar23 + -2)) ||
                           (uVar24 < (uint)*local_64 * (uint)*local_60)) {
                          bVar6 = true;
                        }
                        *(uint *)(psVar23 + -2) = uVar24;
                        if (bVar6) {
                          *psVar23 = *psVar23 + 1;
                        }
                        local_60 = local_60 + 1;
                        local_64 = local_64 + -1;
                        local_68 = local_68 + -1;
                      } while (0 < local_68);
                    }
                    psVar23 = psVar23 + 1;
                    local_6c = local_6c + 1;
                    local_5c = local_5c + -1;
                  } while (0 < local_5c);
                  uVar26 = uVar26 + 0xc002;
                  if ((short)uVar26 < 1) {
LAB_00712073:
                    uVar26 = uVar26 - 1;
                    if ((short)uVar26 < 0) {
                      uVar24 = (uint)(ushort)-uVar26;
                      uVar26 = 0;
                      do {
                        if ((local_30 & 1) != 0) {
                          local_54 = local_54 + 1;
                        }
                        iVar1 = CONCAT22(uStack_26,uStack_2a._2_2_);
                        uVar13 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_);
                        iVar2 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_);
                        uStack_2a._2_2_ = (ushort)(CONCAT22(uStack_26,uStack_2a._2_2_) >> 1);
                        uStack_26 = uStack_26 >> 1;
                        uStack_2a._0_2_ =
                             (ushort)uStack_2a >> 1 | (ushort)((uint)(iVar1 << 0x1f) >> 0x10);
                        uVar18 = CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30)) >> 1;
                        uStack_2e._0_2_ =
                             (ushort)uStack_2e >> 1 | (ushort)((uint)(iVar2 << 0x1f) >> 0x10);
                        uVar24 = uVar24 - 1;
                        uStack_2e._2_2_ = (ushort)(uVar13 >> 1);
                        local_30 = (byte)uVar18;
                        uStack_2f = (undefined1)(uVar18 >> 8);
                      } while (uVar24 != 0);
                      if (local_54 != 0) {
                        local_30 = local_30 | 1;
                      }
                    }
                  }
                  else {
                    do {
                      uVar16 = (ushort)uStack_2e;
                      if ((uStack_26 & 0x8000) != 0) break;
                      iVar2 = CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30)) << 1;
                      local_30 = (byte)iVar2;
                      uStack_2f = (undefined1)((uint)iVar2 >> 8);
                      uStack_2e._0_2_ = (ushort)((uint)iVar2 >> 0x10);
                      iVar2 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_) * 2;
                      uStack_2e._2_2_ = (ushort)iVar2 | uVar16 >> 0xf;
                      iVar1 = CONCAT22(uStack_26,uStack_2a._2_2_) * 2;
                      uStack_2a._2_2_ = (ushort)iVar1 | (ushort)uStack_2a >> 0xf;
                      uVar26 = uVar26 - 1;
                      uStack_2a._0_2_ = (ushort)((uint)iVar2 >> 0x10);
                      uStack_26 = (ushort)((uint)iVar1 >> 0x10);
                    } while (0 < (short)uVar26);
                    if ((short)uVar26 < 1) goto LAB_00712073;
                  }
                  if ((0x8000 < CONCAT11(uStack_2f,local_30)) ||
                     (iVar2 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a),
                     iVar1 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e),
                     (CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30)) & 0x1ffff) == 0x18000
                     )) {
                    if (CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e) == -1) {
                      uStack_2e._0_2_ = 0;
                      uStack_2e._2_2_ = 0;
                      iVar1 = 0;
                      if (CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a) == -1) {
                        uStack_2a._0_2_ = 0;
                        uStack_2a._2_2_ = 0;
                        if (uStack_26 == 0xffff) {
                          uStack_26 = 0x8000;
                          uVar26 = uVar26 + 1;
                          iVar2 = 0;
                          iVar1 = 0;
                        }
                        else {
                          uStack_26 = uStack_26 + 1;
                          iVar2 = 0;
                          iVar1 = 0;
                        }
                      }
                      else {
                        iVar2 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a) + 1;
                        uStack_2a._0_2_ = (ushort)iVar2;
                        uStack_2a._2_2_ = (ushort)((uint)iVar2 >> 0x10);
                      }
                    }
                    else {
                      iVar1 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e) + 1;
                      uStack_2e._0_2_ = (ushort)iVar1;
                      uStack_2e._2_2_ = (ushort)((uint)iVar1 >> 0x10);
                      iVar2 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a);
                    }
                  }
                  if (0x7ffe < uVar26) goto LAB_00712132;
                  local_40 = iVar1;
                  local_3c = iVar2;
                  uStack_38 = uStack_26;
                  local_36 = uVar26 | uVar11;
                  iVar15 = iVar1;
                  iVar5 = iVar2;
                }
                goto joined_r0x00711ebd;
              }
              iVar15 = 0;
              local_3c._0_2_ = 0;
              local_3c._2_2_ = 0;
              local_40._0_2_ = 0;
              local_40._2_2_ = 0;
            }
            else {
LAB_00712132:
              local_3c._0_2_ = 0;
              local_3c._2_2_ = 0;
              iVar15 = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
              local_40._0_2_ = 0;
              local_40._2_2_ = 0;
            }
            uStack_38 = (ushort)iVar15;
            local_36 = (ushort)((uint)iVar15 >> 0x10);
            iVar15 = 0;
            iVar5 = 0;
          }
          goto joined_r0x00711ebd;
        }
      }
      local_3c._2_2_ = (undefined2)((uint)iVar5 >> 0x10);
      local_3c._0_2_ = (undefined2)iVar5;
      local_40._2_2_ = (undefined2)((uint)iVar15 >> 0x10);
      local_40._0_2_ = (undefined2)iVar15;
      uVar25 = CONCAT22((undefined2)local_3c,local_40._2_2_);
      uVar21 = CONCAT22(uStack_38,local_3c._2_2_);
      uVar26 = local_36;
      uStack_4a = iVar17;
      uStack_2e = iVar1;
      uStack_2a = iVar2;
      local_3c = iVar5;
    }
    else {
      uVar25 = 0;
      uVar26 = 0x7fff;
      uVar21 = 0x80000000;
      local_40._0_2_ = 0;
    }
  }
  else {
LAB_0071218f:
    iVar15 = CONCAT22(local_40._2_2_,(undefined2)local_40);
    local_40._0_2_ = 0;
    uVar26 = 0;
    uVar21 = 0;
    uVar25 = 0;
  }
  *param_1 = (undefined2)local_40;
  param_1[5] = uVar26 | uVar9;
  *(undefined4 *)(param_1 + 1) = uVar25;
  *(undefined4 *)(param_1 + 3) = uVar21;
LAB_007121ad:
  local_40 = iVar15;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

