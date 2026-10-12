/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x485b70; label: FUN_00485b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00485b70(int param_1,int param_2,float param_3)

{
  float fVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  float10 extraout_ST0;
  float10 fVar12;
  float10 fVar13;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float local_18;
  int local_10;
  int local_8 [2];
  
  uVar9 = *(uint *)(param_1 + 0xb0);
  bVar2 = false;
  local_8[1] = -1;
  if ((uVar9 & 0x100) == 0) {
    if (*(char *)(param_1 + 0xa6) == '\0') {
      if (*(char *)(param_1 + 0xa7) == '\0') {
        if ((uVar9 & 0x40) != 0) {
          local_8[0] = (int)DAT_008806d8;
          goto LAB_00485ca1;
        }
        if ((*(short *)(param_1 + 0xa0) != -1) &&
           (*(char *)(*(short *)(param_1 + 0xa0) * 0x9c + 0x86 + DAT_00951354) == -1)) {
          local_8[0] = (int)DAT_008806d8;
          goto LAB_00485ca1;
        }
        uVar9 = uVar9 >> 3 & 1;
        if ((((uVar9 != 0) && (sVar10 = *(short *)(param_1 + 0x118), sVar10 != -1)) &&
            ((*(byte *)(DAT_00951354 + 0x7a + sVar10 * 0x9c) & 2) == 0)) &&
           ((&DAT_0086e0f4)[sVar10 * 0xc] == '\0')) {
          local_8[0] = (int)DAT_008806d8;
          bVar2 = true;
          goto LAB_00485ca1;
        }
        if ((*(short *)(param_1 + 0x118) == -1) ||
           (sVar10 = DAT_00880724,
           (*(byte *)(*(short *)(param_1 + 0x118) * 0x9c + 0x7a + DAT_00951354) & 2) == 0)) {
          sVar10 = DAT_008806e4;
        }
        local_8[0] = (int)sVar10;
        if (uVar9 == 0) goto LAB_00485ca1;
      }
      else {
        local_8[0] = (int)DAT_0088081c;
      }
    }
    else {
      local_8[0] = (int)DAT_0088081c;
    }
  }
  else {
    local_8[0] = (int)DAT_0088081c;
  }
  local_8[1] = (int)DAT_008806d8;
LAB_00485ca1:
  fVar1 = _DAT_007fa4f0;
  if (DAT_007f39e4 == 0) {
    fVar1 = -(_DAT_007fa4c0 + _DAT_007fa4c0);
  }
  if (local_8[1] == -1) {
    local_18 = _DAT_007fa4c0;
    if (DAT_007f39e4 != 0) {
      local_18 = _DAT_007fa4e8;
    }
    local_10 = 1;
    if (bVar2) {
      sVar10 = DAT_0088076c;
      if (*(char *)(*(short *)(param_1 + 0x118) * 0x9c + 0x87 + DAT_00951354) != '\x05') {
        sVar10 = DAT_00880770;
      }
      uVar6 = FUN_006e6b90();
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + sVar10 * 4),(float)extraout_ST0,0x3ea66666,
                   0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,0xff,0x3f,0,0x3fd9999a,1,0,0,uVar6)
      ;
    }
  }
  else {
    if (((DAT_007f39e4 == 0) || (*(char *)(param_1 + 0xbb) == '\0')) ||
       ((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x14) != DAT_0087af50)))) {
      local_18 = 0.0;
    }
    else {
      FUN_00576910(0x26c,0,1);
      FUN_00576960(0x26c);
      local_18 = _DAT_007fa4ec;
      FUN_00576840(0xffffffff);
    }
    local_10 = 2;
    local_18 = local_18 - fVar1 * 0.5;
  }
  if ((*(uint *)(param_1 + 0xb0) & 0x100) != 0) {
    local_18 = local_18 + 0.075;
  }
  iVar8 = 0;
  if (local_10 == 0) {
    return;
  }
  do {
    fVar12 = (float10)0;
    fVar13 = (float10)0.7;
    if ((param_2 == 0) || (DAT_0087a604 != iVar8)) {
      uVar9 = (uint)DAT_00921da9;
      uVar11 = (uint)DAT_0080099a;
      uVar7 = (uint)DAT_0080099b;
    }
    else {
      bVar3 = DAT_008009a2;
      bVar4 = DAT_008009a1;
      bVar5 = DAT_00921dae;
      if (DAT_009213e4 != 0) {
        bVar3 = DAT_008009a0;
        bVar4 = DAT_00921dad;
        bVar5 = DAT_0080099f;
      }
      uVar11 = (uint)bVar5;
      uVar9 = (uint)bVar4;
      uVar7 = (uint)bVar3;
      if (fVar12 < (float10)_DAT_00921d70) {
        uVar9 = FUN_006e6b90();
        uVar11 = FUN_006e6b90();
        uVar7 = FUN_006e6b90();
        fVar13 = extraout_ST0_00;
        fVar12 = extraout_ST1;
      }
    }
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + local_8[iVar8] * 4),(float)fVar12,local_18,
                 0x3f800000,(float)fVar13,(float)fVar13,(float)fVar13,0,uVar9,uVar11,uVar7,
                 0x3fd9999a,1,0,0,(int)ROUND(param_3 * 128.0) & 0xff);
    local_18 = local_18 + fVar1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < local_10);
  return;
}

