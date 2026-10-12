/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68cfd0; label: FUN_0068cfd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068cfd0(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int unaff_ESI;
  int *piVar6;
  float fVar7;
  
  fVar7 = 0.0;
  if (0.0 < *(float *)(unaff_ESI + 0xa4)) {
    fVar3 = *(float *)(unaff_ESI + 0x20) + *(float *)(unaff_ESI + 0x1c);
    fVar7 = 0.0;
    do {
      fVar1 = *(float *)(unaff_ESI + 0xa4) - fVar7;
      fVar4 = fVar3;
      if (fVar1 < fVar3) {
        fVar4 = fVar1;
      }
      fVar1 = *(float *)(unaff_ESI + 0xa4) - (fVar4 + fVar7);
      if (*(float *)(unaff_ESI + 0x24) <= fVar1) {
        fVar1 = *(float *)(unaff_ESI + 0x24);
      }
      fVar7 = fVar1 + fVar4 + fVar7;
    } while (fVar7 < *(float *)(unaff_ESI + 0xa4));
  }
  sVar5 = FUN_006e6b90(fVar7,(int)*(short *)(unaff_ESI + 0x16));
  *(short *)(unaff_ESI + 0x14) = sVar5;
  if (sVar5 < 1) {
    *(undefined2 *)(unaff_ESI + 0x14) = 1;
  }
  *(short *)(unaff_ESI + 0x14) = (*(char *)(unaff_ESI + 0x410) + 1) * *(short *)(unaff_ESI + 0x14);
  piVar6 = &DAT_02924b60;
  do {
    iVar2 = *piVar6;
    if (((iVar2 != -1) && (iVar2 != 99999)) &&
       (*(int *)(DAT_0296209c + *(short *)(iVar2 * 0x330 + 0x182 + DAT_029620a4) * 4) == unaff_ESI))
    {
      FUN_00683e90(iVar2 * 0x330 + DAT_029620a4,(int)*(short *)(unaff_ESI + 0x14));
    }
    piVar6 = piVar6 + 0x16;
  } while ((int)piVar6 < 0x292fb60);
  return;
}

