/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50d910; label: FUN_0050d910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050d910(char *param_1,float param_2,float param_3,undefined4 param_4,float param_5,
                 float param_6,undefined4 param_7,uint param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,float param_12,int param_13,uint param_14,
                 int param_15,undefined4 param_16)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  float fVar12;
  int iVar13;
  char *pcVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_1838;
  float local_1834;
  float local_1830;
  float local_182c;
  float local_1828;
  float local_1824;
  float local_1820;
  uint local_181c;
  double local_1818;
  float local_1810;
  float local_180c;
  undefined4 local_1808;
  char local_1804 [512];
  undefined1 local_1604 [1024];
  undefined1 local_1204 [512];
  char local_1004 [4096];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1838;
  local_181c = param_14;
  iVar11 = 0;
  local_1820 = -NAN;
  if ((((DAT_00921ea0 == 0) && (DAT_00921e8c == 0)) || (param_1 == (char *)0x0)) ||
     ((*param_1 == '\0' || (DAT_00921d24 != 0)))) goto LAB_0050e35f;
  param_5 = _DAT_008015ac * param_5;
  param_6 = _DAT_008015b0 * param_6;
  local_180c = _DAT_008015ac;
  local_1808 = _DAT_008015b0;
  _DAT_008015ac = 1.0;
  _DAT_008015b0 = 1.0;
  param_2 = _DAT_008015f0 * param_2;
  param_12 = _DAT_008015f0 * param_12;
  FUN_0050c3e0(param_1,local_1804);
  iVar6 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar6 = DAT_00921e8c;
  }
  FUN_0050c050(local_1804,local_1604,iVar6);
  iVar6 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar6 = DAT_00921e8c;
  }
  FUN_005d0fb0(iVar6);
  iVar6 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar6 = DAT_00921e8c;
  }
  local_1818._0_4_ = _DAT_008015b4 * param_5;
  FUN_005d0fe0(iVar6,local_1818._0_4_,_DAT_008015b8 * param_6);
  iVar6 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar6 = DAT_00921e8c;
  }
  fVar15 = (float10)FUN_005d0c50(iVar6,local_1604);
  local_1830 = (float)fVar15;
  iVar6 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar6 = DAT_00921e8c;
  }
  fVar15 = (float10)FUN_005d0e80(iVar6);
  local_1810 = (float)fVar15;
  iVar6 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar6 = DAT_00921e8c;
  }
  FUN_005d0eb0(iVar6);
  if (param_12 < 0.0 != (param_12 == 0.0)) {
    param_12 = _DAT_008015bc;
  }
  fVar10 = 0.0;
  iVar6 = 0;
  while (local_1804[0] != '\0') {
    iVar7 = iVar6;
    if ((local_1804[0] == '\\') && (iVar7 = iVar6 + 1, local_1804[iVar6 + 1] == 'n')) {
      fVar10 = (float)((int)fVar10 + 1);
    }
    bVar1 = local_1804[iVar7 + 1];
    while ((iVar6 = iVar7 + 1, 0x7f < bVar1 && (bVar1 < 0xc0))) {
      bVar1 = local_1804[iVar7 + 2];
      iVar7 = iVar6;
    }
    local_1804[0] = local_1804[iVar7 + 1];
  }
  local_182c = fVar10;
  local_1834 = (float)FUN_006e6b90();
  local_1818._0_4_ = (float)((int)local_1834 + 1);
  if (extraout_ST1 * (float10)0.8999999761581421 < extraout_ST0 / (float10)(int)local_1818._0_4_) {
    local_1834 = local_1818._0_4_;
  }
  bVar3 = false;
  if (param_13 < 9) {
    if (0 < param_13) goto LAB_0050db91;
  }
  else {
    param_13 = 8;
LAB_0050db91:
    if (param_13 < (int)local_1834 + 1) {
      local_1834 = (float)(param_13 + -1);
      bVar3 = true;
    }
  }
  fVar12 = local_1834;
  uVar8 = FUN_004f2010(local_1804);
  local_1818 = (double)CONCAT44(local_1818._4_4_,uVar8);
  local_1824 = (float)FUN_004f1ff0(local_1804);
  local_1828 = 0.0;
  if ((int)fVar10 < 1) {
    if ((int)fVar12 < 1) {
      local_1828 = local_1830;
    }
    else if (((param_8 & 10) == 0) || (bVar3)) {
      local_1838 = 0.0;
      if (-1 < (int)fVar12) {
        do {
          fVar12 = local_1834;
          fVar10 = local_1838;
          if (local_1838 == 0.0) {
            iVar11 = 0;
          }
          else {
            uVar8 = FUN_004f2050(local_1804,
                                 ((int)local_1818._0_4_ / ((int)local_1834 + 1)) * (int)local_1838);
            iVar11 = FUN_0050d3c0(local_1804,uVar8);
          }
          fVar9 = local_1824;
          if (fVar10 != fVar12) {
            uVar8 = FUN_004f2050(local_1804,
                                 ((int)local_1818._0_4_ / ((int)fVar12 + 1)) * ((int)fVar10 + 1));
            fVar9 = (float)FUN_0050d3c0(local_1804,uVar8);
          }
          cVar2 = local_1804[(int)fVar9];
          if (((cVar2 != '-') && (cVar2 != '.')) && (cVar2 != ',')) {
            fVar9 = (float)((int)fVar9 + -1);
          }
          cVar2 = local_1804[(int)fVar9];
          while (cVar2 == ' ') {
            cVar2 = local_1804[(int)fVar9 + -1];
            fVar9 = (float)((int)fVar9 + -1);
          }
          for (; ((cVar2 = local_1804[iVar11], cVar2 == ' ' || (cVar2 == '-')) ||
                 ((cVar2 == '.' || (cVar2 == ',')))); iVar11 = iVar11 + 1) {
          }
          iVar6 = ((int)fVar9 - iVar11) + 1;
          if (0x1ff < iVar6) {
            iVar6 = 0x1ff;
          }
          iVar7 = (int)local_1838 * 0x200;
          FUN_004ef660(local_1004 + iVar7,local_1804 + iVar11,iVar6);
          local_1004[iVar7 + iVar6] = '\0';
          FUN_0050c100(local_1004 + iVar7,local_1604);
          iVar11 = DAT_00921ea0;
          if (DAT_00921ea0 == 0) {
            iVar11 = DAT_00921e8c;
          }
          fVar15 = (float10)FUN_005d0c50(iVar11,local_1604);
          local_1830 = (float)fVar15;
          if (local_1828 < local_1830) {
            local_1820 = local_1838;
            local_1828 = local_1830;
          }
          local_1838 = (float)((int)local_1838 + 1);
          fVar12 = local_1834;
        } while ((int)local_1838 <= (int)local_1834);
      }
    }
    else {
      local_1838 = 0.0;
      local_182c = 0.0;
      if (-1 < (int)fVar12) {
        do {
          fVar10 = local_1824;
          if (local_1838 == 0.0) {
            fVar12 = 0.0;
          }
          else {
            fVar12 = (float)((int)local_182c + 1);
          }
          cVar2 = local_1804[(int)fVar12];
          while (cVar2 == ' ') {
            cVar2 = local_1804[(int)fVar12 + 1];
            fVar12 = (float)((int)fVar12 + 1);
          }
          if (local_1838 == local_1834) {
            local_182c = (float)((int)local_1824 + -1);
          }
          else {
            local_1818 = (double)param_12;
            fVar9 = fVar12;
            if (0.0 < param_12) {
              do {
                cVar2 = local_1804[(int)fVar9 + 1];
                local_182c = fVar9;
                while (fVar4 = (float)((int)local_182c + 1), cVar2 == ' ') {
                  cVar2 = local_1804[(int)local_182c + 2];
                  local_182c = fVar4;
                }
                if (fVar4 == fVar10) break;
                local_182c = fVar9;
                fVar9 = (float)FUN_0050d240(local_1804,fVar4);
                cVar2 = local_1804[(int)fVar9];
                if (((cVar2 != '-') && (cVar2 != '.')) && (cVar2 != ',')) {
                  fVar9 = (float)((int)fVar9 + -1);
                }
                cVar2 = local_1804[(int)fVar9];
                while (cVar2 == ' ') {
                  cVar2 = local_1804[(int)fVar9 + -1];
                  fVar9 = (float)((int)fVar9 + -1);
                }
                iVar11 = ((int)fVar9 - (int)fVar12) + 1;
                if (0x1ff < iVar11) {
                  iVar11 = 0x1ff;
                }
                FUN_004ef660(local_1204,local_1804 + (int)fVar12,iVar11);
                local_1204[iVar11] = 0;
                iVar11 = DAT_00921ea0;
                if (DAT_00921ea0 == 0) {
                  iVar11 = DAT_00921e8c;
                }
                FUN_0050c050(local_1204,local_1604,iVar11);
                iVar11 = DAT_00921ea0;
                if (DAT_00921ea0 == 0) {
                  iVar11 = DAT_00921e8c;
                }
                fVar15 = (float10)FUN_005d0c50(iVar11,local_1604);
              } while (fVar15 < (float10)local_1818);
            }
          }
          iVar11 = ((int)local_182c - (int)fVar12) + 1;
          if (0x1ff < iVar11) {
            iVar11 = 0x1ff;
          }
          iVar6 = (int)local_1838 * 0x200;
          FUN_004ef660(local_1004 + iVar6,local_1804 + (int)fVar12,iVar11);
          local_1004[iVar6 + iVar11] = '\0';
          FUN_0050c100(local_1004 + iVar6,local_1604);
          iVar11 = DAT_00921ea0;
          if (DAT_00921ea0 == 0) {
            iVar11 = DAT_00921e8c;
          }
          fVar15 = (float10)FUN_005d0c50(iVar11,local_1604);
          local_1830 = (float)fVar15;
          if (local_1828 < local_1830) {
            local_1820 = local_1838;
            local_1828 = local_1830;
          }
          local_1838 = (float)((int)local_1838 + 1);
          fVar12 = local_1834;
        } while ((int)local_1838 <= (int)local_1834);
      }
    }
  }
  else {
    local_1838 = 0.0;
    do {
      if (local_1838 == 0.0) {
        iVar6 = 0;
      }
      else {
        iVar6 = iVar11 + 3;
      }
      cVar2 = local_1804[iVar6];
      while (iVar11 = iVar6, cVar2 == ' ') {
        cVar2 = local_1804[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      for (; (iVar11 < (int)local_1824 &&
             ((local_1804[iVar11] != '\\' || (local_1804[iVar11 + 1] != 'n')))); iVar11 = iVar11 + 1
          ) {
      }
      iVar11 = iVar11 + -1;
      iVar7 = (iVar11 - iVar6) + 1;
      if (0x1ff < iVar7) {
        iVar7 = 0x1ff;
      }
      iVar13 = (int)local_1838 * 0x200;
      FUN_004ef660(local_1004 + iVar13,local_1804 + iVar6,iVar7);
      local_1004[iVar13 + iVar7] = '\0';
      iVar6 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar6 = DAT_00921e8c;
      }
      FUN_0050c050(local_1004 + iVar13,local_1604,iVar6);
      iVar6 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar6 = DAT_00921e8c;
      }
      fVar15 = (float10)FUN_005d0c50(iVar6,local_1604);
      local_1830 = (float)fVar15;
      if (local_1828 < local_1830) {
        local_1820 = local_1838;
        local_1828 = local_1830;
      }
      local_1838 = (float)((int)local_1838 + 1);
    } while ((int)local_1838 <= (int)local_182c);
    local_1834 = local_182c;
    fVar12 = local_182c;
  }
  uVar5 = local_181c;
  if (local_1004[(int)fVar12 * 0x200] == '\0') {
    fVar12 = (float)((int)fVar12 + -1);
    local_1834 = fVar12;
  }
  DAT_009213ec = local_1828;
  local_1824 = param_5;
  if (param_12 < local_1828) {
    DAT_009213ec = param_12;
    local_1824 = param_5 * (param_12 / local_1828);
  }
  if (local_181c != 0) {
    iVar11 = DAT_00921ea0;
    if (DAT_00921ea0 == 0) {
      iVar11 = DAT_00921e8c;
    }
    FUN_005d0fe0(iVar11,local_1824,param_6);
    if ((int)local_1820 < 0) {
      fVar15 = (float10)local_1828;
    }
    else {
      FUN_0050c100(local_1004 + (int)local_1820 * 0x200,local_1604);
      iVar11 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar11 = DAT_00921e8c;
      }
      fVar15 = (float10)FUN_005d0c50(iVar11,local_1604);
    }
    local_1830 = (float)fVar15;
    local_181c = (int)fVar12 + 1;
    *(float *)(uVar5 + 4) = param_2;
    *(float *)(uVar5 + 8) = param_3;
    *(float *)(uVar5 + 0x10) = local_1830;
    *(float *)(uVar5 + 0x14) = local_1810 * (float)(int)local_181c * -1.0;
  }
  DAT_00921ebc = 0;
  if (param_15 == 0) {
    if ((int)fVar12 < 1) {
      FUN_0050c780(local_1804,param_2,param_3,param_4,local_1824,param_6,param_7,param_8,param_9,
                   param_10,param_11,param_16);
    }
    else {
      local_1838 = 0.0;
      if (-1 < (int)local_1834) {
        local_181c = param_8 & 1;
        pcVar14 = local_1004;
        do {
          fVar10 = local_1838;
          if (local_181c == 0) {
            fVar12 = (float)(int)local_1834;
            if ((param_8 & 4) == 0) {
              fVar12 = fVar12 * 0.5;
            }
            local_1820 = local_1810 * (float)(int)local_1838 + (param_3 - fVar12 * local_1810);
          }
          else {
            local_1820 = local_1810 * (float)(int)local_1838 + param_3;
          }
          if (local_1838 != 0.0) {
            DAT_00921ebc = 1;
          }
          FUN_0050c780(pcVar14,param_2,local_1820,param_4,local_1824,param_6,param_7,param_8,param_9
                       ,param_10,param_11,param_16);
          local_1838 = (float)((int)fVar10 + 1);
          pcVar14 = pcVar14 + 0x200;
        } while ((int)local_1838 <= (int)local_1834);
      }
    }
  }
  _DAT_008015ac = local_180c;
  DAT_00921ebc = 0;
  _DAT_008015b0 = local_1808;
LAB_0050e35f:
  __security_check_cookie(local_4 ^ (uint)&local_1838);
  return;
}

