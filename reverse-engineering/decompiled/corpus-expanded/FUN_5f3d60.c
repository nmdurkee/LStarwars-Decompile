/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f3d60; label: FUN_005f3d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f3d60(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int extraout_EDX;
  int iVar12;
  int iVar13;
  bool bVar14;
  int local_24;
  uint local_18;
  float local_14;
  
  local_14 = 0.0;
  iVar2 = (&DAT_009716a4)[param_1];
  if (param_1 == -1) {
    if (DAT_00973974 != 0) {
      iVar3 = *(int *)(iVar2 + 8 + *(int *)(*(int *)(iVar2 + 0x20) + 4) * 4);
      fVar4 = (float)*(int *)(iVar3 + 4);
      if (*(int *)(iVar3 + 4) < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      local_14 = (fVar4 * _DAT_0297dbe0) / 1e+06;
    }
    if ((DAT_00973970 == 0) && (local_14 <= 1.0)) {
      return;
    }
  }
  FUN_005d4290(1);
  if ((-1 < param_1) || ((param_1 == -1 && (extraout_EDX != 0)))) {
    local_18 = 0;
    if (0 < *(int *)(iVar2 + 4)) {
      do {
        puVar1 = (uint *)(*(int *)(iVar2 + 0x14) + local_18 * 4);
        uVar11 = *(uint *)(*(int *)(iVar2 + 8 + *(int *)(*(int *)(iVar2 + 0x20) + local_18 * 4) * 4)
                          + local_18 * 4);
        if (*puVar1 < uVar11) {
          *puVar1 = uVar11;
        }
        if (DAT_0080c0e8 == 0) {
          *(undefined4 *)(*(int *)(iVar2 + 0x18) + local_18 * 4) = 0;
        }
        uVar11 = *(uint *)(*(int *)(iVar2 + 8 + *(int *)(*(int *)(iVar2 + 0x20) + local_18 * 4) * 4)
                          + local_18 * 4);
        if (*(uint *)(*(int *)(iVar2 + 0x18) + local_18 * 4) < uVar11) {
          *(uint *)(*(int *)(iVar2 + 0x18) + local_18 * 4) = uVar11;
        }
        if (*(int *)(*(int *)(iVar2 + 0x18) + local_18 * 4) != 0) {
          iVar3 = local_18 + 1;
          uVar5 = FUN_006e6b90(*(undefined4 *)(*(int *)(iVar2 + 0x1c) + local_18 * 4),0);
          uVar5 = FUN_006e6b90(uVar5);
          uVar5 = FUN_006e6b90(uVar5);
          uVar5 = FUN_006e6b90(uVar5);
          FUN_005db880(uVar5);
          if (DAT_009738cc < 0x10) {
            *(uint *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
            DAT_009738cc = DAT_009738cc + 1;
          }
          DAT_009738c4 = 2;
          if (DAT_009738c8 < 0x10) {
            *(undefined4 *)(&DAT_00963dc0 + DAT_009738c8 * 4) = DAT_009738c0;
            DAT_009738c8 = DAT_009738c8 + 1;
          }
          _DAT_0080b600 = 0x3d800000;
          _DAT_0080b604 = 0x3d800000;
          DAT_009738c0 = 1;
          _DAT_009738ac = 0;
          _DAT_009738b0 = 0;
          _DAT_0080b608 = 0x41800000;
          _DAT_0080b60c = 0x41800000;
          if (DAT_009738b8 != 0) {
            _DAT_009738b4 = *(undefined4 *)(DAT_009738b8 + 0x1c);
            *(undefined4 *)(DAT_009738b8 + 0x20) = 1;
            iVar13 = DAT_009738b8;
            **(undefined4 **)(DAT_009738b8 + 0x2c) = 0x3f800000;
            if ((DAT_009738c4 & 4) == 0) {
              **(undefined4 **)(iVar13 + 0x30) = 0x3f000000;
            }
            else {
              **(undefined4 **)(iVar13 + 0x30) = 0x3f800000;
            }
            **(undefined4 **)(DAT_009738b8 + 0x48) = 0xe0e0e0e0;
          }
          iVar13 = DAT_009738b8;
          iVar6 = FUN_006e6b90();
          iVar7 = FUN_006e6b90();
          if (*(int *)(*(int *)(iVar2 + 0x18) + local_18 * 4) != 0) {
            local_24 = FUN_006e6b90();
            if (9999 < local_24) {
              local_24 = 9999;
            }
            iVar8 = FUN_006e6b90();
            iVar8 = iVar8 * 0x10;
            if (local_24 < 1000) {
              iVar9 = FUN_006e6b90();
              iVar8 = iVar8 + iVar9 * 4;
            }
            else if (iVar13 == 0) {
              iVar9 = FUN_006e6b90();
              iVar8 = iVar9 * 5 + iVar8;
            }
            else {
              iVar9 = FUN_006e6b90();
              iVar8 = iVar9 * 5 + iVar8;
            }
            iVar9 = FUN_006e6b90();
            iVar12 = (iVar7 + iVar6 * iVar3 * -3) * 0x10;
            FUN_005f35e0(iVar13,iVar12,iVar8 - iVar9,0x40,&DAT_0075c058,local_24 % 10);
            iVar6 = DAT_009738b8;
            iVar10 = FUN_006e6b90();
            iVar10 = (iVar8 - iVar9) - iVar10;
            iVar13 = (local_24 / 10) / 10;
            FUN_005f35e0(iVar6,iVar12,iVar10,0x40,&DAT_0075c058,(local_24 / 10) % 10);
            iVar7 = DAT_009738b8;
            iVar6 = FUN_006e6b90();
            iVar10 = iVar10 - iVar6;
            iVar6 = iVar13 / 10;
            FUN_005f35e0(iVar7,iVar12,iVar10,0x40,&DAT_0075c058,iVar13 % 10);
            iVar13 = DAT_009738b8;
            if (iVar6 != 0) {
              iVar6 = FUN_006e6b90(0x40,&DAT_0075c058,iVar6 % 10);
              FUN_005f35e0(iVar13,iVar12,iVar10 - iVar6);
              iVar13 = DAT_009738b8;
            }
          }
          if (*(int *)(*(int *)(iVar2 + 0x14) + local_18 * 4) != 0) {
            iVar6 = FUN_006e6b90();
            iVar7 = FUN_006e6b90();
            iVar8 = FUN_006e6b90();
            iVar10 = DAT_0080e698 * 0x10;
            iVar9 = FUN_006e6b90();
            iVar9 = iVar10 + iVar8 * -2 + iVar9;
            uVar11 = local_18 & 0x80000001;
            bVar14 = uVar11 == 0;
            if ((int)uVar11 < 0) {
              bVar14 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
            }
            if (!bVar14) {
              iVar9 = iVar9 + -0x140;
            }
            uVar5 = FUN_006e6b90();
            FUN_005f35e0(iVar13,(iVar7 + iVar6 * iVar3 * -3) * 0x10,iVar9,0x40,&DAT_0075c058,uVar5);
            iVar13 = DAT_009738b8;
          }
          iVar6 = *(int *)(iVar2 + 0x24);
          if (*(int *)(iVar6 + local_18 * 4) != 0) {
            iVar8 = FUN_006e6b90();
            iVar9 = FUN_006e6b90();
            iVar12 = DAT_0080e698 * 0x10;
            iVar10 = FUN_006e6b90();
            iVar7 = FUN_006e6b90();
            uVar11 = local_18 & 0x80000001;
            bVar14 = uVar11 == 0;
            iVar7 = (iVar12 - iVar10) + -0x140 + iVar7;
            if ((int)uVar11 < 0) {
              bVar14 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
            }
            if (!bVar14) {
              iVar7 = iVar7 + -0x140;
            }
            FUN_005f35e0(iVar13,(iVar9 + iVar8 * iVar3 * -3) * 0x10,iVar7,0x40,
                         *(undefined4 *)(iVar6 + local_18 * 4));
          }
          if (0 < DAT_009738cc) {
            DAT_009738c4 = *(uint *)(&DAT_0096d86c + DAT_009738cc * 4);
            DAT_009738cc = DAT_009738cc + -1;
          }
          if (0 < DAT_009738c8) {
            DAT_009738c8 = DAT_009738c8 + -1;
            FUN_005d0940(*(undefined4 *)(&DAT_00963dc0 + DAT_009738c8 * 4));
          }
        }
        if (*(int *)(iVar2 + 0x28) != 0) {
          FUN_005d8370(param_1,local_18);
        }
        if (DAT_00973978 != 0) {
          *(undefined4 *)(*(int *)(iVar2 + 0x14) + local_18 * 4) = 0;
        }
        local_18 = local_18 + 1;
      } while ((int)local_18 < *(int *)(iVar2 + 4));
    }
    DAT_0080c0e8 = DAT_0080c0e8 + -1;
    DAT_00973978 = 0;
    if (DAT_0080c0e8 < 0) {
      DAT_0080c0e8 = DAT_0080b9f4;
    }
  }
  if (1.0 < local_14) {
    FUN_005db880(0,0,0x3c0,0xe00,0x80000064,DAT_0097397c);
    FUN_005db880(0x2440,0,0x3c0,0xe00,0x80000064,DAT_0097397c);
  }
  FUN_005f3950();
  return;
}

