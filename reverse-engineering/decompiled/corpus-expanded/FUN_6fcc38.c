/* Ghidra pseudocode, not original source.
 * ev_8ae20aee9003ac5b707eda996059b97c5ee653d1eec48e1211714341787544ca
 * Entry: 0x6fcc38; label: FUN_006fcc38
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006fcc38(double param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  float10 fVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  
  uVar1 = (ushort)((ulonglong)param_1 >> 0x30);
  uVar2 = (uVar1 & 0x7fff) + 0xcfd0;
  if (uVar2 < 0x10c6) {
    dVar10 = (param_1 * 10.185916357881302 + 6755399441055744.0) - 6755399441055744.0;
    iVar3 = ((int)ROUND(param_1 * 10.185916357881302) + 0x1c7610U & 0x3f) * 0x20;
    dVar11 = dVar10 * 3.798187816439979e-12;
    dVar5 = param_1 - dVar10 * 0.09817477042088285;
    param_1 = param_1 - dVar10 * 0.09817477042088285;
    dVar15 = param_1 - dVar11;
    dVar6 = dVar5 - dVar11;
    dVar8 = dVar5 - dVar10 * 3.798187816439979e-12;
    dVar7 = dVar6 * dVar6;
    dVar9 = dVar8 * dVar8;
    dVar12 = *(double *)(&DAT_0077e630 + iVar3) + *(double *)(&DAT_0077e648 + iVar3);
    dVar13 = *(double *)(&DAT_0077e648 + iVar3) * dVar15;
    dVar16 = dVar15 * *(double *)(&DAT_0077e630 + iVar3);
    dVar14 = dVar13 + *(double *)(&DAT_0077e638 + iVar3);
    dVar17 = dVar16 + dVar14;
    return (float10)(dVar17 + (dVar10 * 1.2639164054974691e-22 - ((param_1 - dVar15) - dVar11)) *
                              (*(double *)(&DAT_0077e638 + iVar3) * dVar15 - dVar12) +
                              *(double *)(&DAT_0077e640 + iVar3) +
                              (*(double *)(&DAT_0077e638 + iVar3) - dVar14) + dVar13 +
                              (dVar14 - dVar17) + dVar16 +
                              (dVar7 * 0.008333333333333333 + -0.16666666666666666 +
                              (dVar5 * 2.7557319223985893e-06 * dVar6 + -0.0001984126984126984) *
                              dVar7 * dVar7) * dVar12 * dVar15 * dVar7 +
                              (dVar9 * 0.041666666666666664 + -0.5 +
                              (dVar5 * 2.48015873015873e-05 * dVar8 + -0.001388888888888889) *
                              dVar9 * dVar9) * *(double *)(&DAT_0077e638 + iVar3) * dVar9);
  }
  if ((short)uVar2 < 0x10c6) {
    return (float10)(1.0 - (double)((ulonglong)param_1 & 0xffffffffffff |
                                   (ulonglong)(uVar1 & 0x7fff) << 0x30));
  }
  fVar4 = (float10)FUN_006ebcff();
  return fVar4;
}

