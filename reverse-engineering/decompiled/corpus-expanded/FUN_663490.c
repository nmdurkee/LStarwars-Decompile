/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x663490; label: FUN_00663490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663490(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  undefined1 local_120 [16];
  float local_110 [68];
  
  if ((((DAT_02962aec != 0) && (DAT_02962af0 != 0)) && (DAT_02962ae8 != 0)) && (DAT_02962ae4 != 0))
  {
    iVar5 = FUN_0061a8c0(DAT_02962ae4,local_120,8);
    fVar1 = *(float *)(DAT_02962aec + 0x54);
    fVar2 = *(float *)(DAT_02962af0 + 0x54);
    if (((iVar5 - 2U < 7) && (DAT_029231a8 != -1)) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1))
    {
      iVar3 = *(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4);
      iVar9 = 0;
      if (3 < iVar5) {
        fVar4 = fVar2 - fVar1;
        iVar8 = (iVar5 - 4U >> 2) + 1;
        iVar9 = iVar8 * 4;
        pfVar6 = local_110;
        pfVar7 = (float *)(iVar3 + 0x154);
        do {
          pfVar7[-1] = pfVar6[-4];
          iVar8 = iVar8 + -1;
          *pfVar7 = *pfVar6 * fVar4 + fVar1;
          pfVar7[1] = pfVar6[5];
          pfVar7[2] = pfVar6[9] * fVar4 + fVar1;
          pfVar7[3] = pfVar6[0xe];
          pfVar7[4] = pfVar6[0x12] * fVar4 + fVar1;
          pfVar7[5] = pfVar6[0x17];
          pfVar7[6] = pfVar6[0x1b] * fVar4 + fVar1;
          pfVar6 = pfVar6 + 0x24;
          pfVar7 = pfVar7 + 8;
        } while (iVar8 != 0);
      }
      if (iVar9 < iVar5) {
        iVar5 = iVar5 - iVar9;
        pfVar6 = local_110 + iVar9 * 9;
        pfVar7 = (float *)(iVar3 + 0x154 + iVar9 * 8);
        do {
          pfVar7[-1] = pfVar6[-4];
          iVar5 = iVar5 + -1;
          *pfVar7 = *pfVar6 * (fVar2 - fVar1) + fVar1;
          pfVar6 = pfVar6 + 9;
          pfVar7 = pfVar7 + 2;
        } while (iVar5 != 0);
      }
      *(float *)(iVar3 + 0x148) = fVar1;
      *(float *)(iVar3 + 0x14c) = fVar2;
      FUN_00600260(iVar3);
    }
    iVar5 = FUN_0061a8c0(DAT_02962ae8,local_120,8);
    if (((iVar5 - 2U < 7) && (DAT_029231a8 != -1)) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1))
    {
      iVar3 = *(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4);
      iVar9 = 0;
      if (3 < iVar5) {
        iVar8 = (iVar5 - 4U >> 2) + 1;
        fVar4 = fVar2 - fVar1;
        iVar9 = iVar8 * 4;
        pfVar6 = local_110;
        pfVar7 = (float *)(iVar3 + 0x194);
        do {
          pfVar7[-1] = pfVar6[-4];
          iVar8 = iVar8 + -1;
          *pfVar7 = *pfVar6 * fVar4 + fVar1;
          pfVar7[1] = pfVar6[5];
          pfVar7[2] = pfVar6[9] * fVar4 + fVar1;
          pfVar7[3] = pfVar6[0xe];
          pfVar7[4] = pfVar6[0x12] * fVar4 + fVar1;
          pfVar7[5] = pfVar6[0x17];
          pfVar7[6] = pfVar6[0x1b] * fVar4 + fVar1;
          pfVar6 = pfVar6 + 0x24;
          pfVar7 = pfVar7 + 8;
        } while (iVar8 != 0);
      }
      if (iVar9 < iVar5) {
        iVar5 = iVar5 - iVar9;
        pfVar6 = local_110 + iVar9 * 9;
        pfVar7 = (float *)(iVar3 + 0x194 + iVar9 * 8);
        do {
          pfVar7[-1] = pfVar6[-4];
          iVar5 = iVar5 + -1;
          *pfVar7 = *pfVar6 * (fVar2 - fVar1) + fVar1;
          pfVar6 = pfVar6 + 9;
          pfVar7 = pfVar7 + 2;
        } while (iVar5 != 0);
      }
      *(float *)(iVar3 + 0x148) = fVar1;
      *(float *)(iVar3 + 0x14c) = fVar2;
      FUN_00600260(iVar3);
    }
  }
  return;
}

