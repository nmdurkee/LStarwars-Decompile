/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b0490; label: FUN_006b0490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b0490(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  int local_30;
  int local_24;
  
  iVar7 = *(int *)(param_1 + 0x68);
  iVar2 = *(int *)(*(int *)(param_1 + 0x40) + 0x68);
  iVar10 = *(int *)(*(int *)(param_1 + 0x40) + 4);
  iVar6 = *(int *)(iVar10 + 0x1c);
  FUN_006eafc0(*(double *)(iVar2 + 0x70) + 0.5);
  local_30 = FUN_006e6b90();
  iVar4 = FUN_006a3db0(*(undefined4 *)(iVar7 + 0xc + local_30 * 4));
  iVar4 = iVar4 * 8;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar8 = *(int *)(iVar2 + 0x60);
    local_24 = *(int *)(iVar2 + 100);
  }
  else {
    iVar8 = *(int *)(iVar2 + 0x68) * *(int *)(iVar2 + 0x60);
    local_24 = *(int *)(iVar2 + 0x68) * *(int *)(iVar2 + 100);
  }
  iVar3 = *(int *)(iVar6 + *(int *)(param_1 + 0x1c) * 4);
  iVar5 = FUN_006e6b90();
  if (*(int *)(iVar2 + 0x50) == 0) {
    if (*(int *)(iVar2 + 0x78) == 0) {
      *(int *)(iVar2 + 0x78) = param_1;
      return 0;
    }
    return 0xffffffff;
  }
  iVar11 = *(int *)(iVar2 + 0x5c);
  *(int *)(iVar2 + 0x78) = param_1;
  if (0 < iVar11) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      iVar11 = *(int *)(iVar2 + 0x68) * iVar11;
    }
    dVar1 = *(double *)(iVar6 + 0xd38);
    iVar9 = (*(int *)(iVar2 + 0x54) - iVar11) + iVar4;
    if (iVar5 < iVar9) {
      for (; ((0 < local_30 && (iVar11 < iVar4)) &&
             (iVar5 < (*(int *)(iVar2 + 0x54) - iVar11) + iVar4)); iVar4 = iVar4 * 8) {
        local_30 = local_30 + -1;
        iVar4 = FUN_006a3db0();
      }
    }
    else if ((iVar9 < iVar5) && (local_30 + 1 < 0xf)) {
      do {
        if ((iVar11 <= iVar4) || (iVar5 <= (*(int *)(iVar2 + 0x54) - iVar11) + iVar4)) break;
        local_30 = local_30 + 1;
        iVar4 = FUN_006a3db0();
        iVar4 = iVar4 * 8;
      } while (local_30 < 0xe);
    }
    iVar10 = *(int *)(iVar10 + 8);
    fVar12 = (float10)FUN_006eafc0(((double)local_30 - *(double *)(iVar2 + 0x70)) + 0.5);
    fVar13 = (float10)(iVar3 >> 1);
    fVar14 = (float10)iVar10;
    fVar12 = (fVar12 / fVar13) * fVar14;
    fVar15 = (float10)(15.0 / dVar1);
    if (fVar12 < -fVar15) {
      fVar12 = -fVar15;
    }
    if (fVar15 < fVar12) {
      fVar12 = fVar15;
    }
    fVar12 = fVar13 * (fVar12 / fVar14) + (float10)*(double *)(iVar2 + 0x70);
    *(double *)(iVar2 + 0x70) = (double)fVar12;
    FUN_006eafc0((double)(fVar12 + (float10)0.5));
    local_30 = FUN_006e6b90();
    iVar4 = FUN_006a3db0(*(undefined4 *)(iVar7 + 0xc + local_30 * 4));
    iVar4 = iVar4 * 8;
  }
  if ((0 < *(int *)(iVar2 + 0x60)) && (iVar4 < iVar8)) {
    iVar10 = (*(int *)(iVar2 + 0x58) - iVar8) + iVar4;
    while ((iVar10 < 0 && (local_30 = local_30 + 1, local_30 < 0xf))) {
      iVar4 = FUN_006a3db0();
      iVar4 = iVar4 * 8;
      iVar10 = (*(int *)(iVar2 + 0x58) - iVar8) + iVar4;
    }
  }
  if (((0 < *(int *)(iVar2 + 100)) && (local_24 < iVar4)) &&
     (*(int *)(iVar6 + 0xd2c) < (*(int *)(iVar2 + 0x58) - local_24) + iVar4)) {
    do {
      local_30 = local_30 + -1;
      if (local_30 < 0) goto LAB_006b0839;
      iVar4 = FUN_006a3db0();
      iVar4 = iVar4 * 8;
    } while (*(int *)(iVar6 + 0xd2c) < (*(int *)(iVar2 + 0x58) - local_24) + iVar4);
  }
  if (local_30 < 0) {
LAB_006b0839:
    iVar10 = *(int *)(iVar6 + 0xd2c);
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    iVar10 = (iVar10 - *(int *)(iVar2 + 0x58)) + local_24;
    iVar6 = (int)(iVar10 + (iVar10 >> 0x1f & 7U)) >> 3;
    iVar10 = FUN_006a3db0();
    if (iVar6 < iVar10) {
      FUN_006a3510(*(undefined4 *)(iVar7 + 0xc),iVar6 * 8);
      iVar4 = FUN_006a3db0(*(undefined4 *)(iVar7 + 0xc));
      goto LAB_006b0805;
    }
  }
  else {
    iVar10 = (iVar8 - *(int *)(iVar2 + 0x58)) + 7;
    if (0xe < local_30) {
      local_30 = 0xe;
    }
    *(int *)(iVar2 + 0x7c) = local_30;
    iVar6 = FUN_006a3db0();
    for (iVar6 = ((int)(iVar10 + (iVar10 >> 0x1f & 7U)) >> 3) - iVar6; 0 < iVar6; iVar6 = iVar6 + -1
        ) {
      FUN_006a3570(*(undefined4 *)(iVar7 + 0xc + local_30 * 4),0,8);
    }
    iVar4 = FUN_006a3db0();
LAB_006b0805:
    iVar4 = iVar4 * 8;
  }
  if ((0 < *(int *)(iVar2 + 0x60)) || (0 < *(int *)(iVar2 + 100))) {
    if ((local_24 < 1) || (iVar4 <= local_24)) {
      if ((iVar8 < 1) || (iVar8 <= iVar4)) {
        iVar7 = *(int *)(iVar2 + 0x58);
        if (iVar5 < iVar7) {
          if ((0 < local_24) &&
             (iVar7 = (iVar7 - local_24) + iVar4, *(int *)(iVar2 + 0x58) = iVar7, iVar5 <= iVar7))
          goto LAB_006b08d1;
        }
        else if ((0 < iVar8) &&
                (iVar7 = (iVar7 - iVar8) + iVar4, *(int *)(iVar2 + 0x58) = iVar7, iVar7 <= iVar5))
        goto LAB_006b08d1;
        *(int *)(iVar2 + 0x58) = iVar5;
      }
      else {
        *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + (iVar4 - iVar8);
      }
    }
    else {
      *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + (iVar4 - local_24);
    }
  }
LAB_006b08d1:
  iVar7 = *(int *)(iVar2 + 0x5c);
  if (0 < iVar7) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(int *)(iVar2 + 0x54) = *(int *)(iVar2 + 0x54) + (iVar4 - *(int *)(iVar2 + 0x68) * iVar7);
      return 0;
    }
    *(int *)(iVar2 + 0x54) = *(int *)(iVar2 + 0x54) + (iVar4 - iVar7);
  }
  return 0;
}

