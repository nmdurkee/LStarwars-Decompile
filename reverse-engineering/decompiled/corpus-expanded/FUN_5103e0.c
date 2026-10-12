/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x5103e0; label: FUN_005103e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005103e0(int param_1,float param_2)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  int local_14;
  int local_10;
  int local_8;
  
  if (0 < DAT_00921d88) {
    DAT_00921d88 = DAT_00921d88 + -1;
  }
  if (0 < DAT_00921d84) {
    DAT_00921d84 = DAT_00921d84 + -1;
  }
  if (DAT_00801598 < 4) {
    local_10 = DAT_00801598 + -1;
    local_14 = 0;
  }
  else {
    iVar5 = (int)*(short *)(param_1 + 8);
    if (DAT_00921d80 != iVar5) {
      if (iVar5 < DAT_00921d80) {
        DAT_00921d88 = 10;
        DAT_00921d80 = iVar5;
      }
      else {
        DAT_00921d84 = 10;
        DAT_00921d80 = iVar5;
      }
    }
    local_14 = iVar5 + -1;
    if (DAT_00921d84 != 0) {
      local_14 = iVar5 + -2;
    }
    local_10 = iVar5 + 1;
    if (DAT_00921d88 != 0) {
      local_10 = iVar5 + 2;
    }
  }
  if (DAT_00801598 < 7) {
    local_8 = DAT_00801598;
  }
  else {
    local_8 = DAT_00921e84;
  }
  iVar5 = local_14;
  if (DAT_00801598 < 4) {
    fVar1 = (float)(DAT_00801598 + -1) * -0.25;
  }
  else {
    fVar1 = ((float)DAT_00921d84 * 0.5) / 10.0 +
            ((0.0 - (float)(*(short *)(param_1 + 8) - local_14) * 0.5) -
            ((float)DAT_00921d88 * 0.5) / 10.0);
  }
  for (; iVar5 <= local_10; iVar5 = iVar5 + 1) {
    fVar10 = (float10)param_2;
    if ((((*(short *)(param_1 + 10) == *(short *)(param_1 + 0xe)) &&
         (*(short *)(param_1 + 8) == iVar5)) && (DAT_00921d84 == 0)) && (DAT_00921d88 == 0)) {
      uVar6 = 1;
    }
    else {
      uVar6 = 0;
    }
    fVar11 = (float10)fVar1;
    if ((-1 < iVar5) && (iVar5 <= *(short *)(param_1 + 0x10))) {
      if (iVar5 < local_8) {
        (*(code *)PTR_FUN_00800964)(fVar1,param_2,uVar6,iVar5);
      }
      else {
        if ((*(short *)(param_1 + 8) == local_8) && (*(short *)(param_1 + 10) == 0)) {
          bVar2 = DAT_008009a2;
          bVar3 = DAT_008009a1;
          bVar4 = DAT_00921dae;
          if (DAT_009213e4 != 0) {
            bVar2 = DAT_008009a0;
            bVar3 = DAT_00921dad;
            bVar4 = DAT_0080099f;
          }
          uVar9 = (uint)bVar4;
          uVar8 = (uint)bVar3;
          uVar7 = (uint)bVar2;
          if (0.0 < _DAT_00921d70) {
            uVar8 = FUN_006e6b90();
            uVar9 = FUN_006e6b90();
            uVar7 = FUN_006e6b90();
            fVar11 = extraout_ST0;
            fVar10 = extraout_ST1;
          }
        }
        else {
          uVar8 = (uint)DAT_00921da9;
          uVar9 = (uint)DAT_0080099a;
          uVar7 = (uint)DAT_0080099b;
        }
        FUN_0050f4c0(PTR_s_New_Save_00800a3c,(float)fVar11,(float)fVar10,0x3f800000,
                     _DAT_0080098c * 0.85,_DAT_0080098c * 0.85,_DAT_0080098c,0,uVar8,uVar9,uVar7,
                     DAT_00921d60);
      }
    }
    fVar1 = fVar1 + 0.5;
  }
  fVar10 = (float10)param_2;
  if (*(short *)(param_1 + 10) == 0) {
    bVar2 = DAT_008009a1;
    bVar3 = DAT_008009a2;
    bVar4 = DAT_00921dae;
    if (DAT_009213e4 != 0) {
      bVar2 = DAT_00921dad;
      bVar3 = DAT_008009a0;
      bVar4 = DAT_0080099f;
    }
    uVar9 = (uint)bVar4;
    uVar7 = (uint)bVar3;
    uVar8 = (uint)bVar2;
    if (0.0 < _DAT_00921d70) {
      uVar8 = FUN_006e6b90();
      uVar9 = FUN_006e6b90();
      uVar7 = FUN_006e6b90();
      fVar10 = extraout_ST0_00;
    }
  }
  else {
    uVar8 = (uint)DAT_00921da9;
    uVar9 = (uint)DAT_0080099a;
    uVar7 = (uint)DAT_0080099b;
  }
  fVar1 = _DAT_0080098c + _DAT_0080098c;
  if ((DAT_00921d84 == 0) && (DAT_00921d88 == 0)) {
    if (0 < local_14) {
      FUN_0050f4c0(&DAT_007533c8,0xbf4ccccd,(float)fVar10,0x3f800000,fVar1,fVar1,fVar1,0,uVar8,uVar9
                   ,uVar7,DAT_00921d60);
    }
    if (local_10 < *(short *)(param_1 + 0x10)) {
      FUN_0050f4c0(&DAT_007533c4,0x3f4ccccd,param_2,0x3f800000,fVar1,fVar1,fVar1,0,uVar8,uVar9,uVar7
                   ,DAT_00921d60);
      return;
    }
  }
  return;
}

