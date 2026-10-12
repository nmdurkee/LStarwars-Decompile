/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56b730; label: FUN_0056b730
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056b730(undefined4 param_1,short *param_2)

{
  float fVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  int unaff_ESI;
  float *unaff_EDI;
  float10 fVar6;
  
  if ((*(char *)(unaff_ESI + 0x1078) != '\0') &&
     ((((cVar2 = *(char *)(unaff_ESI + 0x6c0), cVar2 < '\0' || ('\x1f' < cVar2)) ||
       ((*(uint *)(&DAT_008034cc + cVar2 * 0xc) & 0x581) == 0)) &&
      ((*(float *)(unaff_ESI + 0x84) - 0.05 < *(float *)(unaff_ESI + 0x6ac) &&
       (ABS(*(float *)(unaff_ESI + 0x6b8)) <= DAT_029959a0)))))) {
    uVar4 = FUN_005be2d0(*(undefined4 *)(unaff_ESI + 0x6b4),*(undefined4 *)(unaff_ESI + 0x6bc));
    *param_2 = (short)uVar4;
    uVar5 = FUN_00550040(param_1,uVar4);
    if (0x3fff < (int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f))) {
      sVar3 = *param_2;
      fVar1 = *(float *)(unaff_ESI + 0x1dc) + _DAT_008030e8;
      *unaff_EDI = *(float *)(unaff_ESI + 0x5c) +
                   fVar1 * (float)(&DAT_029899a0)[(ushort)(sVar3 + 0x8000U) >> 1];
      unaff_EDI[1] = *(float *)(unaff_ESI + 0x194);
      unaff_EDI[2] = fVar1 * (float)(&DAT_029899a0)
                                    [(int)((ushort)(sVar3 + 0x8000U) + 0x4000) >> 1 & 0x7fff] +
                     *(float *)(unaff_ESI + 100);
      fVar6 = (float10)FUN_005506f0(0);
      fVar1 = (float)fVar6;
      if ((((fVar1 != 2e+06) && (DAT_02992ef4 <= DAT_0292fdbc)) &&
          ((unaff_EDI[1] - fVar1 <= 0.025 && (-0.1 <= unaff_EDI[1] - fVar1)))) &&
         ((*(float *)(unaff_ESI + 0x224) == 2e+06 || (fVar1 <= *(float *)(unaff_ESI + 0x224))))) {
        unaff_EDI[1] = fVar1;
        return 1;
      }
    }
  }
  return 0;
}

