/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x665320; label: FUN_00665320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00665320(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  undefined1 local_120 [16];
  float local_110 [68];
  
  if ((((DAT_02962b10 != 0) && (iVar5 = FUN_0061a8c0(DAT_02962b10,local_120,8), iVar5 - 2U < 7)) &&
      (DAT_029231a8 != -1)) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    iVar9 = 0;
    fVar2 = *(float *)(iVar1 + 0x148) / 10000.0;
    fVar3 = *(float *)(iVar1 + 0x14c) / 10000.0;
    if (3 < iVar5) {
      fVar4 = fVar3 - fVar2;
      iVar8 = (iVar5 - 4U >> 2) + 1;
      iVar9 = iVar8 * 4;
      pfVar6 = local_110;
      pfVar7 = (float *)(iVar1 + 0x2b4);
      do {
        pfVar7[-1] = pfVar6[-4];
        iVar8 = iVar8 + -1;
        *pfVar7 = *pfVar6 * fVar4 + fVar2;
        pfVar7[1] = pfVar6[5];
        pfVar7[2] = pfVar6[9] * fVar4 + fVar2;
        pfVar7[3] = pfVar6[0xe];
        pfVar7[4] = pfVar6[0x12] * fVar4 + fVar2;
        pfVar7[5] = pfVar6[0x17];
        pfVar7[6] = pfVar6[0x1b] * fVar4 + fVar2;
        pfVar6 = pfVar6 + 0x24;
        pfVar7 = pfVar7 + 8;
      } while (iVar8 != 0);
    }
    if (iVar9 < iVar5) {
      iVar5 = iVar5 - iVar9;
      pfVar6 = local_110 + iVar9 * 9;
      pfVar7 = (float *)(iVar1 + 0x2b4 + iVar9 * 8);
      do {
        pfVar7[-1] = pfVar6[-4];
        iVar5 = iVar5 + -1;
        *pfVar7 = *pfVar6 * (fVar3 - fVar2) + fVar2;
        pfVar6 = pfVar6 + 9;
        pfVar7 = pfVar7 + 2;
      } while (iVar5 != 0);
    }
  }
  return;
}

