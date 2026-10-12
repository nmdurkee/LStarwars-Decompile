/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x63ae40; label: FUN_0063ae40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0063ae40(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  float *in_EDX;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  float local_8;
  
  local_8 = 3.4028235e+38;
  iVar6 = -1;
  if (DAT_02913818 == 0) {
    pcVar5 = (char *)(DAT_0291389c + 0x7e);
    iVar7 = 2;
    do {
      if ((((*(int *)(&DAT_0291350c + (uint)(byte)pcVar5[-0x22] * 4) == 0) && (*pcVar5 == -1)) &&
          ((fVar2 = (*(float *)(pcVar5 + -0x72) - in_EDX[2]) *
                    (*(float *)(pcVar5 + -0x72) - in_EDX[2]) +
                    (*(float *)(pcVar5 + -0x7a) - *in_EDX) * (*(float *)(pcVar5 + -0x7a) - *in_EDX)
                    + (*(float *)(pcVar5 + -0x76) - in_EDX[1]) *
                      (*(float *)(pcVar5 + -0x76) - in_EDX[1]), unaff_EDI != 0 ||
           (fVar2 < *(float *)(pcVar5 + -0x3a) * *(float *)(pcVar5 + -0x3a))))) && (fVar2 < local_8)
         ) {
        iVar6 = iVar7 + -2;
        local_8 = fVar2;
      }
      if (((*(int *)(&DAT_0291350c + (uint)(byte)pcVar5[0x6a] * 4) == 0) && (pcVar5[0x8c] == -1)) &&
         (((fVar2 = (*(float *)(pcVar5 + 0x1a) - in_EDX[2]) *
                    (*(float *)(pcVar5 + 0x1a) - in_EDX[2]) +
                    (*(float *)(pcVar5 + 0x12) - *in_EDX) * (*(float *)(pcVar5 + 0x12) - *in_EDX) +
                    (*(float *)(pcVar5 + 0x16) - in_EDX[1]) *
                    (*(float *)(pcVar5 + 0x16) - in_EDX[1]), unaff_EDI != 0 ||
           (fVar2 < *(float *)(pcVar5 + 0x52) * *(float *)(pcVar5 + 0x52))) && (fVar2 < local_8))))
      {
        iVar6 = iVar7 + -1;
        local_8 = fVar2;
      }
      if ((((*(int *)(&DAT_0291350c + (uint)(byte)pcVar5[0xf6] * 4) == 0) && (pcVar5[0x118] == -1))
          && ((fVar2 = (*(float *)(pcVar5 + 0xa6) - in_EDX[2]) *
                       (*(float *)(pcVar5 + 0xa6) - in_EDX[2]) +
                       (*(float *)(pcVar5 + 0x9e) - *in_EDX) * (*(float *)(pcVar5 + 0x9e) - *in_EDX)
                       + (*(float *)(pcVar5 + 0xa2) - in_EDX[1]) *
                         (*(float *)(pcVar5 + 0xa2) - in_EDX[1]), unaff_EDI != 0 ||
              (fVar2 < *(float *)(pcVar5 + 0xde) * *(float *)(pcVar5 + 0xde))))) &&
         (fVar2 < local_8)) {
        iVar6 = iVar7;
        local_8 = fVar2;
      }
      if (((*(int *)(&DAT_0291350c + (uint)(byte)pcVar5[0x182] * 4) == 0) && (pcVar5[0x1a4] == -1))
         && (((fVar2 = (*(float *)(pcVar5 + 0x132) - in_EDX[2]) *
                       (*(float *)(pcVar5 + 0x132) - in_EDX[2]) +
                       (*(float *)(pcVar5 + 0x12a) - *in_EDX) *
                       (*(float *)(pcVar5 + 0x12a) - *in_EDX) +
                       (*(float *)(pcVar5 + 0x12e) - in_EDX[1]) *
                       (*(float *)(pcVar5 + 0x12e) - in_EDX[1]), unaff_EDI != 0 ||
              (fVar2 < *(float *)(pcVar5 + 0x16a) * *(float *)(pcVar5 + 0x16a))) &&
             (fVar2 < local_8)))) {
        iVar6 = iVar7 + 1;
        local_8 = fVar2;
      }
      iVar4 = iVar7 + 2;
      pcVar5 = pcVar5 + 0x230;
      iVar7 = iVar7 + 4;
    } while (iVar4 < 0x80);
  }
  else {
    iVar7 = (int)*(char *)(DAT_02913818 + 0x79);
    if (iVar7 == -1) {
      return 0;
    }
    do {
      iVar4 = iVar7 * 0x8c;
      fVar2 = *(float *)(iVar4 + 8 + DAT_0291389c) - in_EDX[1];
      fVar3 = *(float *)(iVar4 + 4 + DAT_0291389c) - *in_EDX;
      fVar1 = *(float *)(iVar4 + 0xc + DAT_0291389c) - in_EDX[2];
      fVar2 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
      if (((unaff_EDI != 0) ||
          (fVar1 = *(float *)(iVar4 + DAT_0291389c + 0x44), fVar2 < fVar1 * fVar1)) &&
         (fVar2 < local_8)) {
        iVar6 = iVar7;
        local_8 = fVar2;
      }
      iVar7 = (int)*(char *)(iVar4 + DAT_0291389c + 0x7d);
    } while (iVar7 != -1);
  }
  if (iVar6 == -1) {
    return 0;
  }
  return DAT_0291389c + 4 + iVar6 * 0x8c;
}

