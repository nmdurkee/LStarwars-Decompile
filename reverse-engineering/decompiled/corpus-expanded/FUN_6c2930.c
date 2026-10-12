/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2930; label: FUN_006c2930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2930(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  undefined4 uVar10;
  float *pfVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  int local_470;
  int iStack_468;
  int *piStack_464;
  int iStack_460;
  int iStack_458;
  int aiStack_410 [259];
  
  iVar9 = 0;
  local_470 = 0;
  DAT_02973b04 = 0;
  iVar13 = DAT_02973b04;
  if (0 < DAT_02973b00) {
    while ((iVar13 = DAT_02973b04, DAT_02973b04 < DAT_02973b00 &&
           (iVar9 = (**(code **)(*(int *)(&DAT_02973b0c)[DAT_02973b04 * 2] + 0x14))(0),
           iVar13 = DAT_02973b04, iVar9 == 0))) {
      DAT_02973b04 = DAT_02973b04 + 1;
    }
  }
  while ((iVar14 = iVar9, iVar14 != 0 && (local_470 < 0x100))) {
    aiStack_410[local_470] = iVar14;
    local_470 = local_470 + 1;
    iVar9 = 0;
    if (iVar14 == 0) {
      iVar13 = 0;
      DAT_02973b04 = 0;
    }
    if (iVar13 < DAT_02973b00) {
      while ((iVar13 < DAT_02973b00 &&
             (iVar9 = (**(code **)(*(int *)(&DAT_02973b0c)[iVar13 * 2] + 0x14))(iVar14),
             iVar13 = DAT_02973b04, iVar9 == 0))) {
        iVar13 = DAT_02973b04 + 1;
        iVar14 = 0;
        DAT_02973b04 = iVar13;
      }
    }
  }
  if (0 < local_470) {
    piStack_464 = aiStack_410;
    iStack_460 = 1;
    iStack_458 = local_470;
    do {
      piVar1 = (int *)*piStack_464;
      if (piVar1 != (int *)0x0) {
        uVar10 = (**(code **)(*piVar1 + 0xc))();
        pfVar11 = (float *)(**(code **)(*piVar1 + 0x28))();
        fVar2 = *pfVar11;
        fVar3 = pfVar11[1];
        fVar4 = pfVar11[2];
        iVar13 = 0;
        iStack_468 = 0;
        if (0 < DAT_02973b00) {
          do {
            iStack_468 = iVar13;
            if (*(int *)((&DAT_02973b0c)[iVar13 * 2] + 8) == (int)(short)piVar1[1]) break;
            iVar13 = iVar13 + 1;
            iStack_468 = iVar13;
          } while (iVar13 < DAT_02973b00);
        }
        fVar8 = fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3;
        fVar15 = (float10)FUN_005c0240(fVar8);
        iVar13 = iStack_460;
        if ((float10)0.10000000149011612 < fVar15) {
          for (; iVar13 < local_470; iVar13 = iVar13 + 1) {
            piVar1 = (int *)aiStack_410[iVar13];
            if (piVar1 != (int *)0x0) {
              uVar12 = (**(code **)(*piVar1 + 0xc))();
              pfVar11 = (float *)(**(code **)(*piVar1 + 0x28))();
              fVar5 = *pfVar11;
              fVar6 = pfVar11[1];
              fVar7 = pfVar11[2];
              iVar9 = 0;
              if (0 < DAT_02973b00) {
                do {
                  if (*(int *)((&DAT_02973b0c)[iVar9 * 2] + 8) == (int)(short)piVar1[1]) break;
                  iVar9 = iVar9 + 1;
                } while (iVar9 < DAT_02973b00);
              }
              fVar15 = (float10)FUN_005c0240(fVar8);
              if (((((float10)0.10000000149011612 < fVar15) &&
                   (fVar15 = (float10)FUN_005c0240((fVar4 - fVar7) * (fVar4 - fVar7) +
                                                   (fVar2 - fVar5) * (fVar2 - fVar5) +
                                                   (fVar3 - fVar6) * (fVar3 - fVar6)),
                   fVar15 < (float10)0.10000000149011612)) && (iStack_468 == iVar9)) &&
                 ((iVar14 = FUN_004f20a0(uVar10,uVar12), iVar14 != 0 ||
                  (iVar14 = FUN_004f20a0(uVar12,uVar10), iVar14 != 0)))) {
                (**(code **)(*(int *)(&DAT_02973b0c)[iVar9 * 2] + 0x1c))(piVar1,0);
                aiStack_410[iVar13] = 0;
              }
            }
          }
        }
      }
      piStack_464 = piStack_464 + 1;
      iStack_460 = iStack_460 + 1;
      iStack_458 = iStack_458 + -1;
    } while (iStack_458 != 0);
  }
  return;
}

