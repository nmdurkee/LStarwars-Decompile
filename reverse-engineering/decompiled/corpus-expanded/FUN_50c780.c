/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50c780; label: FUN_0050c780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050c780(char *param_1,float param_2,float param_3,undefined4 param_4,float param_5,
                 float param_6,undefined4 param_7,byte param_8,byte param_9,byte param_10,
                 byte param_11,byte param_12)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined4 uVar15;
  float local_141c;
  float local_1418;
  float local_1414;
  float local_1410;
  double local_140c;
  byte local_1404 [512];
  byte local_1204 [512];
  byte local_1004 [512];
  byte local_e04 [512];
  undefined1 local_c04 [1024];
  undefined1 local_804 [1024];
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_141c;
  _DAT_00921d00 = 0.0;
  DAT_00921438 = 0.0;
  if ((((DAT_00921ea0 != 0) || (DAT_00921e8c != 0)) && (param_1 != (char *)0x0)) &&
     ((*param_1 != '\0' && (DAT_00921d24 == 0)))) {
    param_5 = _DAT_008015ac * param_5;
    param_6 = _DAT_008015b0 * param_6;
    if ((param_2 < -2.0) || (2.0 < param_2)) {
      __security_check_cookie(local_4 ^ (uint)&local_141c);
      return;
    }
    if ((-2.0 <= param_3) && (param_3 <= 2.0)) {
      if (DAT_00921ec0 == 0) {
        uVar15 = 2;
      }
      else {
        uVar15 = 3;
      }
      FUN_005d0880(uVar15);
      FUN_0050c3e0(param_1,local_1404);
      if (DAT_00921ebc == 0) {
        iVar3 = DAT_00921ea0;
        if (DAT_00921ea0 == 0) {
          iVar3 = DAT_00921e8c;
        }
        FUN_005d0fb0(iVar3);
      }
      FUN_0050c100(local_1404,local_c04);
      iVar3 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar3 = DAT_00921e8c;
      }
      local_141c = _DAT_008015b4 * param_5;
      FUN_005d0fe0(iVar3,local_141c,_DAT_008015b8 * param_6);
      iVar3 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar3 = DAT_00921e8c;
      }
      fVar11 = (float10)FUN_005d0c50(iVar3,local_c04);
      _DAT_00921d00 = (float)fVar11;
      local_1418 = _DAT_00921d00;
      iVar3 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar3 = DAT_00921e8c;
      }
      fVar11 = (float10)FUN_005d0e80(iVar3);
      DAT_00921438 = (float)fVar11;
      local_141c = DAT_00921438;
      iVar3 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar3 = DAT_00921e8c;
      }
      local_140c = (double)(DAT_00921438 * 0.5);
      fVar11 = (float10)FUN_005d0eb0(iVar3);
      local_141c = (float)(fVar11 + (float10)param_3);
      param_3 = local_141c - (float)local_140c;
      local_1414 = param_5;
      if (param_6 != param_5) {
        iVar3 = 0;
        local_141c = 0.0;
        iVar6 = 0;
        iVar8 = 0;
        bVar2 = local_1404[0];
        local_1414 = param_5;
        if ((DAT_00921ec8 != 1) && (local_1414 = param_6, DAT_00921ec8 != 2)) {
          local_1414 = (param_6 + param_5) * 0.5;
        }
        while (bVar2 != 0) {
          if (((bVar2 == 0xd4) && (0xb0 < local_1404[iVar3 + 1])) && (local_1404[iVar3 + 1] < 0xc0))
          {
            local_e04[iVar6] = 0xd4;
            bVar2 = local_1404[iVar3 + 1];
            iVar4 = iVar3;
            while( true ) {
              iVar3 = iVar4 + 1;
              iVar6 = iVar6 + 1;
              if ((bVar2 < 0x80) || (0xbf < bVar2)) break;
              local_e04[iVar6] = bVar2;
              bVar2 = local_1404[iVar4 + 2];
              iVar4 = iVar3;
            }
          }
          else {
            local_1004[iVar8] = bVar2;
            bVar2 = local_1404[iVar3 + 1];
            iVar9 = iVar8;
            iVar4 = iVar3;
            while( true ) {
              iVar3 = iVar4 + 1;
              iVar8 = iVar9 + 1;
              if ((bVar2 < 0x80) || (0xbf < bVar2)) break;
              local_1004[iVar9 + 1] = bVar2;
              bVar2 = local_1404[iVar4 + 2];
              iVar9 = iVar8;
              iVar4 = iVar3;
            }
          }
          bVar2 = local_1404[iVar3];
        }
        local_e04[iVar6] = 0;
        local_1004[iVar8] = 0;
        if (iVar6 != 0) {
          FUN_0050c100(local_e04,local_804);
          iVar3 = DAT_00921ea0;
          if (DAT_00921ea0 == 0) {
            iVar3 = DAT_00921e8c;
          }
          local_141c = local_1414 * _DAT_008015b4;
          FUN_005d0fe0(iVar3,local_141c,local_1414 * _DAT_008015b8);
          iVar3 = DAT_00921ea0;
          if (DAT_00921ea0 == 0) {
            iVar3 = DAT_00921e8c;
          }
          fVar11 = (float10)FUN_005d0c50(iVar3,local_804);
          local_141c = (float)fVar11;
        }
        if (iVar8 != 0) {
          FUN_0050c100(local_1004,local_404);
          iVar3 = DAT_00921ea0;
          if (DAT_00921ea0 == 0) {
            iVar3 = DAT_00921e8c;
          }
          local_1410 = _DAT_008015b4 * param_5;
          FUN_005d0fe0(iVar3,local_1410,_DAT_008015b8 * param_6);
          iVar3 = DAT_00921ea0;
          if (DAT_00921ea0 == 0) {
            iVar3 = DAT_00921e8c;
          }
          fVar11 = (float10)FUN_005d0c50(iVar3,local_404);
          local_1410 = (float)fVar11;
          if (local_1410 != 0.0) {
            local_1410 = (local_1418 - local_141c) / local_1410;
            param_5 = local_1410 * param_5;
            goto LAB_0050cc1b;
          }
        }
        local_1414 = param_5;
        if (DAT_00921ec8 == 2) {
          local_1410 = param_6 * local_1418;
          local_1418 = local_1410 / param_5;
          local_1414 = param_6;
        }
      }
LAB_0050cc1b:
      if ((param_8 & 4) == 0) {
        if ((param_8 & 1) != 0) {
          param_3 = param_3 + (float)local_140c;
        }
      }
      else {
        param_3 = param_3 - (float)local_140c;
      }
      if ((param_8 & 2) == 0) {
        if ((param_8 & 8) == 0) {
          local_1418 = local_1418 * 0.5;
        }
        param_2 = param_2 - local_1418;
      }
      iVar3 = 0;
      iVar8 = 0;
      local_1418 = 0.0;
      if (DAT_00921ebc == 0) {
        if (DAT_008015ec == 0) {
          DAT_008015e8 = CONCAT31(CONCAT21(CONCAT11(param_12,param_11),param_10),param_9);
        }
        else {
          DAT_008015e8 = ((param_11 & 0xfffffffe) << 8 | param_10 & 0xfffffffe |
                         (uint)param_12 << 0x11) << 7 | (uint)(param_9 >> 1);
        }
      }
      uVar7 = DAT_008015e8;
      fVar1 = param_2;
      if (local_1404[0] != 0) {
        do {
          if (local_1404[iVar3] == 0x7e) {
            if (local_1404[iVar3 + 1] == 0x7e) {
              if (DAT_008015ec == 0) {
                uVar10 = (uint)param_9;
                uVar5 = (uint)CONCAT21(CONCAT11(param_12,param_11),param_10) << 8;
              }
              else {
                uVar10 = ((param_11 & 0xfffffffe) << 8 | param_10 & 0xfffffffe |
                         (uint)param_12 << 0x11) << 7;
                uVar5 = (uint)(param_9 >> 1);
              }
LAB_0050ce2d:
              uVar10 = uVar10 | uVar5;
            }
            else {
              uVar5 = (uint)local_1404[iVar3 + 1];
              if (((param_9 != 0) || (param_10 != 0)) || (param_11 != 0)) {
                if (DAT_008015ec == 0) {
                  uVar10 = (uint)(byte)(&DAT_00801594)[uVar5] * 2 & 0xff |
                           ((byte)(&DAT_008015ac)[uVar5] & 0x7f) << 0x11 |
                           (*(byte *)((int)&DAT_008015a0 + uVar5) & 0x7f) << 9;
                  uVar5 = (uint)param_12 << 0x18;
                }
                else {
                  uVar10 = (uint)(byte)(&DAT_00801594)[uVar5];
                  uVar5 = (uint)CONCAT21(CONCAT11(param_12,(&DAT_008015ac)[uVar5]),
                                         *(undefined1 *)((int)&DAT_008015a0 + uVar5)) << 8;
                }
                goto LAB_0050ce2d;
              }
              uVar10 = (uint)param_12 << 0x18;
            }
            iVar3 = iVar3 + 2;
            uVar5 = uVar10;
            if ((0 < iVar8) && (uVar10 != uVar7)) {
              local_1204[iVar8] = 0;
              fVar12 = local_1414;
              fVar13 = local_1414;
              fVar14 = local_1418;
              if (local_1418 == 0.0) {
                fVar12 = param_5;
                fVar13 = param_6;
                fVar14 = (float)0;
              }
              fVar11 = (float10)FUN_0050c650(local_1204,fVar1,param_3,param_4,fVar12,fVar13,uVar7,
                                             fVar14);
              iVar8 = 0;
              fVar1 = (float)(fVar11 + (float10)param_2);
              param_2 = fVar1;
            }
          }
          else {
            uVar10 = uVar7;
            if (((local_1404[iVar3] == 0xd4) && (0xb0 < local_1404[iVar3 + 1])) &&
               (local_1404[iVar3 + 1] < 0xc0)) {
              if ((0 < iVar8) && (local_1418 == 0.0)) {
                local_1204[iVar8] = 0;
                fVar11 = (float10)FUN_0050c650(local_1204,fVar1,param_3,param_4,param_5,param_6,
                                               uVar7,0);
                fVar1 = (float)(fVar11 + (float10)param_2);
                iVar8 = 0;
                uVar10 = DAT_008015e8;
                param_2 = fVar1;
              }
              local_1204[iVar8] = local_1404[iVar3];
              bVar2 = local_1404[iVar3 + 1];
              local_1418 = 1.4013e-45;
              iVar6 = iVar3;
              while( true ) {
                iVar3 = iVar6 + 1;
                iVar8 = iVar8 + 1;
                uVar5 = DAT_008015e8;
                if ((bVar2 < 0x80) || (0xbf < bVar2)) break;
                local_1204[iVar8] = bVar2;
                bVar2 = local_1404[iVar6 + 2];
                iVar6 = iVar3;
              }
            }
            else {
              if ((0 < iVar8) && (local_1418 != 0.0)) {
                local_1204[iVar8] = 0;
                fVar11 = (float10)FUN_0050c650(local_1204,fVar1,param_3,param_4,local_1414,
                                               local_1414,uVar7,local_1418);
                fVar1 = (float)(fVar11 + (float10)param_2);
                iVar8 = 0;
                uVar10 = DAT_008015e8;
                param_2 = fVar1;
              }
              local_1204[iVar8] = local_1404[iVar3];
              bVar2 = local_1404[iVar3 + 1];
              local_1418 = 0.0;
              iVar4 = iVar8;
              iVar6 = iVar3;
              while( true ) {
                iVar3 = iVar6 + 1;
                iVar8 = iVar4 + 1;
                uVar5 = DAT_008015e8;
                if ((bVar2 < 0x80) || (0xbf < bVar2)) break;
                local_1204[iVar4 + 1] = bVar2;
                bVar2 = local_1404[iVar6 + 2];
                iVar4 = iVar8;
                iVar6 = iVar3;
              }
            }
          }
          DAT_008015e8 = uVar5;
        } while ((iVar8 < 0x1fd) && (uVar7 = uVar10, local_1404[iVar3] != 0));
        if (0 < iVar8) {
          local_1204[iVar8] = 0;
          if (local_1418 != 0.0) {
            FUN_0050c650(local_1204,fVar1,param_3,param_4,local_1414,local_1414,uVar10,local_1418);
            FUN_005d08c0();
            __security_check_cookie(local_4 ^ (uint)&local_141c);
            return;
          }
          FUN_0050c650(local_1204,fVar1,param_3,param_4,param_5,param_6,uVar10,0);
          FUN_005d08c0();
          __security_check_cookie(local_4 ^ (uint)&local_141c);
          return;
        }
      }
      FUN_005d08c0();
      __security_check_cookie(local_4 ^ (uint)&local_141c);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_141c);
  return;
}

