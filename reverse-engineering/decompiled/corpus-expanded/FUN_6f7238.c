/* Ghidra pseudocode, not original source.
 * ev_6f25f465777d6c282cbfa6a77d593954d589f2e76f9dc6caa100c42a001a6af1
 * Entry: 0x6f7238; label: FUN_006f7238
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006f7238(double param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dStack_c;
  
  iVar4 = 0;
  dVar8 = param_1;
  while( true ) {
    uVar2 = (uint)(ushort)((ulonglong)dVar8 >> 0x34);
    dVar7 = (double)((ulonglong)dVar8 & 0xfffffffffffff | 0x3ff0000000000000);
    uVar1 = SUB82(dVar7 + 4398046511103.0073,0) & 0x7f0;
    dVar9 = (double)((ulonglong)dVar8 & 0xfffffffe00000 | 0x3ff0000000000000);
    dVar12 = (double)((ulonglong)dVar8 & 0xfffffffe00000 | 0x3ff0000000000000);
    dVar10 = dVar9 * *(double *)(&DAT_00779570 + uVar1) - 1.0;
    dVar7 = (dVar7 - dVar9) * *(double *)(&DAT_00779570 + uVar1);
    dVar9 = ((double)((ulonglong)dVar8 & 0xfffffffffffff | 0x3ff0000000000000) - dVar12) *
            *(double *)(&UNK_00779578 + uVar1);
    dVar8 = dVar7 + dVar10;
    dVar12 = dVar9 + (dVar12 * *(double *)(&UNK_00779578 + uVar1) - 1.0);
    uVar3 = uVar2 - 1;
    if (uVar3 < 0x7fe) {
      iVar4 = (uVar2 - 0x3ff) + iVar4;
      dVar11 = (double)iVar4;
      iVar5 = 0;
      if (uVar1 + iVar4 * 0x400 == 0) {
        iVar5 = 0x10;
      }
      return (float10)(((dVar8 * 0.1428709072311373 + -0.1666800146149218) * dVar8 +
                       0.1999999994995557) * dVar8 * dVar8 * dVar8 * dVar8 * dVar8 +
                       ((dVar12 * -0.24999999959276006 + 0.33333333333333787) * dVar12 +
                       -0.5000000000000031) * dVar12 * dVar12 +
                       *(double *)(&UNK_00779988 + uVar1) + dVar11 * 5.497923018708371e-14 +
                       (double)((ulonglong)dVar9 & *(ulonglong *)(&UNK_007794d8 + iVar5)) +
                      *(double *)(&DAT_00779980 + uVar1) + dVar10 + dVar11 * 0.6931471805598903 +
                      (double)((ulonglong)dVar7 & *(ulonglong *)(&DAT_007794d0 + iVar5)));
    }
    dStack_c = (double)-(ulonglong)(param_1 == 0.0);
    if (SUB82(dStack_c,0) != 0) break;
    if (uVar3 != 0xffffffff) {
      if (uVar3 < 0x7ff) {
        dStack_c = 2.225073858507201e-308;
        if ((double)((ulonglong)param_1 & 0xfffffffffffff | 0x3ff0000000000000) == 1.0) {
          return (float10)INFINITY;
        }
        uVar6 = 1000;
      }
      else if (((uVar2 & 0x7ff) < 0x7ff) ||
              (SUB84(param_1,0) == 0 && ((ulonglong)param_1 & 0xfffff00000000) == 0)) {
        dStack_c = -NAN;
        uVar6 = 3;
      }
      else {
        uVar6 = 1000;
      }
      goto LAB_006f7432;
    }
    dVar8 = param_1 * 4503599627370496.0;
    iVar4 = -0x34;
  }
  dStack_c = -INFINITY;
  uVar6 = 2;
LAB_006f7432:
  ___libm_error_support(&param_1,&param_1,&dStack_c,uVar6);
  return (float10)dStack_c;
}

