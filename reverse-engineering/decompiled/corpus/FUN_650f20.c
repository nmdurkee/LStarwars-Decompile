/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x650f20; label: FUN_00650f20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00650f20(int param_1,float *param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 fVar18;
  float local_14;
  float local_10;
  
  local_14 = 0.0;
  local_10 = 0.0;
  if (param_1 == -1) {
    return;
  }
  iVar13 = param_1 * 0x40 + DAT_02947b74;
  if ((*(uint *)(iVar13 + 4) & 0xc0000) == 0) {
    iVar16 = (int)*(char *)(iVar13 + 0xc);
    if (*(short *)(iVar13 + 0x14) != -1) {
      param_1 = FUN_00650d10((int)*(short *)(iVar13 + 0x14),*(uint *)(iVar13 + 4) >> 0x10 & 1);
    }
    iVar13 = DAT_02947b74;
    iVar9 = param_1 * 0x40;
    uVar14 = *(uint *)(iVar9 + 4 + DAT_02947b74);
    uVar15 = (int)(uVar14 << 0x11) >> 0x11;
    iVar10 = FUN_006e6b90();
    fVar1 = *(float *)(iVar9 + 0x18 + iVar13);
    uVar2 = *(undefined4 *)(iVar9 + 0x2c + iVar13);
    uVar5 = *(undefined4 *)(iVar9 + 0x30 + iVar13);
    uVar3 = *(undefined4 *)(iVar9 + 0x34 + iVar13);
    uVar14 = uVar14 >> 0xf & 1;
    uVar4 = *(undefined4 *)(iVar9 + 0x38 + iVar13);
    if ((extraout_ST0 != (float10)*(float *)(iVar9 + 0x24 + iVar13)) ||
       (extraout_ST0 != (float10)*(float *)(iVar9 + 0x28 + iVar13))) {
      local_14 = _DAT_00810d9c;
      local_10 = _DAT_00810d98;
      _DAT_00810d9c = _DAT_00810d9c * *(float *)(iVar9 + 0x24 + iVar13) * 0.5;
      _DAT_00810d98 = (*(float *)(iVar9 + 0x28 + iVar13) * _DAT_00810d98) / 15.0;
    }
    iVar11 = FUN_00696be0();
    iVar13 = DAT_02947b74;
    if ((param_2 == (float *)0x0) ||
       (fVar6 = param_2[1] - *(float *)(iVar11 + 0x34), fVar8 = *param_2 - *(float *)(iVar11 + 0x30)
       , fVar7 = param_2[2] - *(float *)(iVar11 + 0x38),
       fVar7 * fVar7 + fVar8 * fVar8 + fVar6 * fVar6 <= _DAT_00810d98 * _DAT_00810d98)) {
      if (param_4 != 1.0) {
        iVar10 = FUN_006e6b90();
      }
      if ((*(uint *)(iVar9 + 4 + iVar13) & 0x400000) == 0) {
        FUN_006951c0();
      }
      uVar12 = FUN_006e6b90();
      if (*(float *)(iVar9 + 0x1c + DAT_02947b74) != 0.0) {
        FUN_005b9d90(&DAT_00810364);
        FUN_005b9e10(&DAT_00810364);
        iVar10 = FUN_006e6b90();
        if ((*(uint *)(iVar9 + 4 + DAT_02947b74) & 0x8000) != 0) {
          iVar10 = -iVar10;
        }
      }
      if (*(float *)(iVar9 + 0x20 + DAT_02947b74) != 0.0) {
        FUN_005b9d90(&DAT_00810364);
        uVar12 = FUN_006e6b90();
      }
      if (uVar15 < 0x640) {
        if (param_2 == (float *)0x0) {
          fVar18 = (float10)0;
          fVar17 = (float10)fVar1;
          param_1 = uVar12;
          if (fVar18 <= fVar17) {
            param_1 = FUN_006e6b90();
            fVar17 = extraout_ST0_00;
            fVar18 = extraout_ST1;
          }
          if (fVar17 <= fVar18) {
            uVar12 = FUN_006e6b90();
          }
          if (uVar14 == 0) {
            if (iVar16 == 0) {
              FUN_006980c0(uVar15,param_1,uVar12,iVar10,uVar2,uVar5,uVar3,uVar4);
            }
            else {
              FUN_00698040(uVar15,param_1,uVar12,iVar10,uVar2,uVar5,uVar3,uVar4,iVar16);
            }
          }
          else {
            iVar13 = FUN_00696be0();
            _DAT_02962b3c = *(undefined4 *)(iVar13 + 0x30);
            _DAT_02962b40 = *(undefined4 *)(iVar13 + 0x34);
            _DAT_02962b44 = *(undefined4 *)(iVar13 + 0x38);
            FUN_005b37d0(&DAT_02962b3c,&DAT_02962b3c,iVar13 + 0x20);
            FUN_00698260(&DAT_02962b3c,uVar15,param_1,uVar12,iVar10,uVar2,uVar5,uVar3,uVar4);
          }
        }
        else if (uVar14 == 0) {
          if (iVar16 == 0) {
            FUN_00698210(param_2,uVar15,uVar12,uVar12,iVar10,uVar2,uVar5,uVar3,uVar4);
          }
          else {
            FUN_00698100(param_2,uVar15,uVar12,uVar12,iVar10,uVar2,uVar5,uVar3,uVar4,iVar16);
          }
        }
        else {
          FUN_00698260(param_2,uVar15,uVar12,uVar12,iVar10,uVar2,uVar5,uVar3,uVar4);
        }
      }
      if (*(float *)(iVar9 + 0x24 + DAT_02947b74) != 0.0) {
        _DAT_00810d98 = local_10;
        _DAT_00810d9c = local_14;
        return;
      }
      fVar1 = *(float *)(iVar9 + 0x28 + DAT_02947b74);
    }
    else {
      if (*(float *)(iVar9 + 0x24 + DAT_02947b74) != 0.0) {
        _DAT_00810d98 = local_10;
        _DAT_00810d9c = local_14;
        return;
      }
      fVar1 = *(float *)(iVar9 + 0x28 + DAT_02947b74);
    }
    if (fVar1 != 0.0) {
      _DAT_00810d9c = local_14;
      _DAT_00810d98 = local_10;
      return;
    }
    return;
  }
  return;
}

