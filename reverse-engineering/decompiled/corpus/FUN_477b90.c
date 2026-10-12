/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x477b90; label: FUN_00477b90
 */

undefined4 FUN_00477b90(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined *puVar4;
  uint in_EAX;
  undefined **ppuVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  iVar6 = (int)*(short *)(in_EAX * 0x9c + 0x8a + DAT_00951354);
  if ((iVar6 == -1) || (*(int *)(param_1 + 0x2ae0) == 0)) {
    return 0;
  }
  pfVar7 = (float *)(in_EAX * 0x7c + *(int *)(param_1 + 0x2ae0));
  ppuVar5 = &PTR_s_negotiations_007f9368;
  puVar4 = PTR_s_negotiations_007f9368;
  while (puVar4 != (undefined *)0x0) {
    if ((ppuVar5[8] != (undefined *)0x0) && ((byte)ppuVar5[8][0x7c] == in_EAX)) goto LAB_00477bfd;
    ppuVar5 = ppuVar5 + 0xf;
    puVar4 = *ppuVar5;
  }
  ppuVar5 = (undefined **)0x0;
LAB_00477bfd:
  iVar6 = iVar6 * 0x4c;
  fVar1 = *(float *)(DAT_0093b274 + 0x34 + iVar6);
  fVar2 = *(float *)(DAT_0093b274 + 0x38 + iVar6);
  fVar3 = *(float *)(DAT_0093b274 + 0x30 + iVar6);
  fVar8 = (float10)fVar3;
  pfVar7[0x19] = fVar3;
  fVar9 = (float10)fVar2;
  fVar10 = (float10)fVar1;
  fVar1 = (float)((fVar9 - fVar10) / (fVar8 + fVar8));
  pfVar7[0x1a] = fVar1;
  fVar8 = (float10)(pfVar7[0x1b] + *pfVar7);
  pfVar7[0x10] = pfVar7[0x1b] + *pfVar7;
  fVar11 = (float10)(pfVar7[0x1c] + pfVar7[2]);
  pfVar7[0x12] = pfVar7[0x1c] + pfVar7[2];
  fVar12 = (float10)0.5;
  fVar2 = (float)((float10)pfVar7[1] + (fVar9 + fVar10) * fVar12);
  fVar9 = (float10)fVar2;
  pfVar7[0x11] = fVar2;
  iVar6 = FUN_006e6b90();
  fVar2 = (float)(((float10)1 -
                  ((float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] + (float10)1) * fVar8) *
                  (float10)0.3330000042915344 + extraout_ST1);
  pfVar7[0x11] = fVar2;
  fVar2 = (float)((float10)fVar2 +
                 (float10)(float)(&DAT_029899a0)[(int)pfVar7[0xb] >> 1 & 0x7fff] *
                 (float10)0.02500000037252903 * extraout_ST0);
  pfVar7[0x11] = fVar2;
  if (ppuVar5 == (undefined **)0x0) {
    puVar4 = (undefined *)0x0;
  }
  else {
    puVar4 = ppuVar5[5];
  }
  pfVar7[0x11] = fVar2 + (float)puVar4;
  pfVar7[0x13] = (float)(fVar9 - fVar11);
  pfVar7[0x16] = (float)(fVar9 + fVar11);
  fVar8 = (float10)fVar1 * fVar11;
  pfVar7[0x14] = (float)((float10)pfVar7[0x11] - fVar8);
  pfVar7[0x17] = (float)(fVar8 + (float10)pfVar7[0x11]);
  pfVar7[0x15] = (float)(fVar12 - fVar11);
  pfVar7[0x18] = (float)(fVar12 + fVar11);
  return 1;
}

