/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7650; label: FUN_006b7650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b7650(int param_1,int param_2)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  float *pfVar11;
  double *pdVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint unaff_EDI;
  undefined8 uStack_20;
  int local_8;
  
  local_8 = 0;
  uStack_20._4_4_ = 0x6b766b;
  iVar13 = 0;
  if (3 < (int)unaff_EDI) {
    iVar15 = (unaff_EDI - 4 >> 2) + 1;
    iVar13 = iVar15 * 4;
    pfVar11 = (float *)(param_2 + 8);
    pdVar12 = (double *)(&local_8 + unaff_EDI * -2);
    do {
      pdVar12[-2] = (double)pfVar11[-2];
      iVar15 = iVar15 + -1;
      pdVar12[-1] = (double)pfVar11[-1];
      *pdVar12 = (double)*pfVar11;
      pdVar12[1] = (double)pfVar11[1];
      pfVar11 = pfVar11 + 4;
      pdVar12 = pdVar12 + 4;
    } while (iVar15 != 0);
  }
  while (iVar13 < (int)unaff_EDI) {
    iVar15 = iVar13 * 4;
    iVar13 = iVar13 + 1;
    (&uStack_20)[iVar13 - unaff_EDI] = (double)*(float *)(param_2 + iVar15);
  }
  dVar9 = 0.0;
  while( true ) {
    iVar13 = 0;
    dVar3 = dVar9;
    if (0 < (int)unaff_EDI) {
      dVar10 = (double)*(float *)(param_1 + unaff_EDI * 4);
      do {
        dVar2 = *(double *)(&stack0xffffffe8 + iVar13 * 8 + unaff_EDI * -8);
        iVar15 = unaff_EDI - 1;
        dVar4 = dVar10;
        dVar5 = dVar9;
        if (3 < (int)unaff_EDI) {
          uVar14 = unaff_EDI >> 2;
          iVar1 = iVar15 * 4;
          iVar15 = iVar15 + uVar14 * -4;
          pfVar11 = (float *)(param_1 + -8 + iVar1);
          do {
            uVar14 = uVar14 - 1;
            dVar6 = dVar4 * dVar2 + (double)pfVar11[2];
            dVar7 = dVar6 * dVar2 + (double)pfVar11[1];
            dVar8 = dVar7 * dVar2 + (double)*pfVar11;
            dVar5 = dVar2 * (dVar2 * (dVar2 * (dVar2 * dVar5 + dVar4) + dVar6) + dVar7) + dVar8;
            dVar4 = dVar8 * dVar2 + (double)pfVar11[-1];
            pfVar11 = pfVar11 + -4;
          } while (uVar14 != 0);
        }
        while (-1 < iVar15) {
          iVar15 = iVar15 + -1;
          dVar5 = dVar2 * dVar5 + dVar4;
          dVar4 = dVar4 * dVar2 + (double)*(float *)(param_1 + 4 + iVar15 * 4);
        }
        iVar13 = iVar13 + 1;
        dVar4 = dVar4 / dVar5;
        (&uStack_20)[iVar13 - unaff_EDI] = (double)(&uStack_20)[iVar13 - unaff_EDI] - dVar4;
        dVar3 = dVar4 * dVar4 + dVar3;
      } while (iVar13 < (int)unaff_EDI);
    }
    if (0x28 < local_8) break;
    local_8 = local_8 + 1;
    if (dVar3 <= 1e-20) {
      iVar13 = 0;
      if (3 < (int)unaff_EDI) {
        iVar15 = (unaff_EDI - 4 >> 2) + 1;
        iVar13 = iVar15 * 4;
        pdVar12 = (double *)(&local_8 + unaff_EDI * -2);
        pfVar11 = (float *)(param_2 + 8);
        do {
          pfVar11[-2] = (float)pdVar12[-2];
          iVar15 = iVar15 + -1;
          pfVar11[-1] = (float)pdVar12[-1];
          *pfVar11 = (float)*pdVar12;
          pfVar11[1] = (float)pdVar12[1];
          pdVar12 = pdVar12 + 4;
          pfVar11 = pfVar11 + 4;
        } while (iVar15 != 0);
      }
      for (; iVar13 < (int)unaff_EDI; iVar13 = iVar13 + 1) {
        *(float *)(param_2 + iVar13 * 4) =
             (float)*(double *)(&stack0xffffffe8 + iVar13 * 8 + unaff_EDI * -8);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

