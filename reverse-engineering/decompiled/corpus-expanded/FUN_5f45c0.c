/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f45c0; label: FUN_005f45c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f45c0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float local_1c;
  
  local_1c = 0.0;
  if ((param_1 != -1) || (DAT_00973970 != 0)) {
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
      **(undefined4 **)(DAT_009738b8 + 0x48) = 0xe0e0e0e0;
      iVar1 = DAT_009738b8;
      if (DAT_009738b8 != 0) {
        **(undefined4 **)(DAT_009738b8 + 0x2c) = 0x3f59999a;
        if ((DAT_009738c4 & 4) == 0) {
          **(undefined4 **)(iVar1 + 0x30) = 0x3ed9999a;
        }
        else {
          **(undefined4 **)(iVar1 + 0x30) = 0x3f59999a;
        }
      }
    }
    iVar1 = (&DAT_009716a4)[param_1];
    iVar8 = 0;
    if (0 < *(int *)(iVar1 + 4)) {
      do {
        if (*(int *)(*(int *)(iVar1 + 0x24) + iVar8 * 4) != 0) {
          fVar10 = (float10)FUN_005d0d60(DAT_009738b8,
                                         *(undefined4 *)(*(int *)(iVar1 + 0x24) + iVar8 * 4));
          if (local_1c < (float)fVar10) {
            local_1c = (float)fVar10;
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(iVar1 + 4));
    }
    if (0 < DAT_009738cc) {
      DAT_009738cc = DAT_009738cc + -1;
      DAT_009738c4 = *(uint *)(&DAT_0096d870 + DAT_009738cc * 4);
    }
    if (0 < DAT_009738c8) {
      iVar8 = DAT_009738c8 * 4;
      DAT_009738c8 = DAT_009738c8 + -1;
      FUN_005d0940(*(undefined4 *)(&DAT_00963dbc + iVar8));
    }
    iVar8 = 0;
    if (0 < *(int *)(iVar1 + 4)) {
      do {
        uVar2 = *(uint *)(*(int *)(iVar1 + 8 + *(int *)(*(int *)(iVar1 + 0x20) + iVar8 * 4) * 4) +
                         iVar8 * 4);
        if (*(uint *)(*(int *)(iVar1 + 0x14) + iVar8 * 4) < uVar2) {
          *(uint *)(*(int *)(iVar1 + 0x14) + iVar8 * 4) = uVar2;
        }
        if (DAT_0080c0ec == 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0x18) + iVar8 * 4) = 0;
        }
        uVar2 = *(uint *)(*(int *)(iVar1 + 8 + *(int *)(*(int *)(iVar1 + 0x20) + iVar8 * 4) * 4) +
                         iVar8 * 4);
        if (*(uint *)(*(int *)(iVar1 + 0x18) + iVar8 * 4) < uVar2) {
          *(uint *)(*(int *)(iVar1 + 0x18) + iVar8 * 4) = uVar2;
        }
        if (*(int *)(*(int *)(iVar1 + 0x18) + iVar8 * 4) != 0) {
          uVar3 = FUN_006e6b90();
          iVar4 = FUN_006e6b90();
          iVar5 = FUN_006e6b90();
          uVar6 = FUN_006e6b90(iVar5,*(undefined4 *)(*(int *)(iVar1 + 0x1c) + iVar8 * 4),0);
          FUN_005db880(uVar3,iVar4,uVar6);
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
          _DAT_0080b608 = 0x41800000;
          _DAT_0080b60c = 0x41800000;
          _DAT_009738b0 = _DAT_009738ac;
          if (DAT_009738b8 != 0) {
            _DAT_009738b4 = *(undefined4 *)(DAT_009738b8 + 0x1c);
            *(undefined4 *)(DAT_009738b8 + 0x20) = 1;
            **(undefined4 **)(DAT_009738b8 + 0x48) = 0xe0e0e0e0;
            iVar9 = DAT_009738b8;
            if (DAT_009738b8 != 0) {
              **(undefined4 **)(DAT_009738b8 + 0x2c) = 0x3f59999a;
              if ((DAT_009738c4 & 4) == 0) {
                **(undefined4 **)(iVar9 + 0x30) = 0x3ed9999a;
              }
              else {
                **(undefined4 **)(iVar9 + 0x30) = 0x3f59999a;
              }
            }
          }
          iVar9 = DAT_009738b8;
          iVar7 = FUN_006e6b90();
          iVar4 = (iVar5 - iVar7) + iVar4;
          if (*(int *)(*(int *)(iVar1 + 0x24) + iVar8 * 4) != 0) {
            uVar6 = FUN_006e6b90(iVar4,0x10,*(undefined4 *)(*(int *)(iVar1 + 0x24) + iVar8 * 4));
            FUN_005f35e0(iVar9,uVar6);
            iVar9 = DAT_009738b8;
          }
          if (*(int *)(*(int *)(iVar1 + 0x18) + iVar8 * 4) != 0) {
            uVar6 = FUN_006e6b90();
            FUN_005f35e0(iVar9,uVar3,iVar4,0x10,&DAT_00751730,uVar6);
            iVar9 = DAT_009738b8;
          }
          if (*(int *)(*(int *)(iVar1 + 0x14) + iVar8 * 4) != 0) {
            uVar3 = FUN_006e6b90();
            uVar3 = FUN_006e6b90(iVar4,0x20,&DAT_00751730,uVar3);
            FUN_005f35e0(iVar9,uVar3);
          }
          if (0 < DAT_009738cc) {
            DAT_009738cc = DAT_009738cc + -1;
            DAT_009738c4 = *(uint *)(&DAT_0096d870 + DAT_009738cc * 4);
          }
          if (0 < DAT_009738c8) {
            iVar4 = DAT_009738c8 * 4;
            DAT_009738c8 = DAT_009738c8 + -1;
            FUN_005d0940(*(undefined4 *)(&DAT_00963dbc + iVar4));
          }
        }
        if (*(int *)(iVar1 + 0x28) != 0) {
          FUN_005d8370(param_1,iVar8);
        }
        if (DAT_00973978 != 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0x14) + iVar8 * 4) = 0;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(iVar1 + 4));
    }
    DAT_0080c0ec = DAT_0080c0ec + -1;
    DAT_00973978 = 0;
    if (DAT_0080c0ec < 0) {
      DAT_0080c0ec = DAT_0080b9f4;
      return;
    }
  }
  return;
}

