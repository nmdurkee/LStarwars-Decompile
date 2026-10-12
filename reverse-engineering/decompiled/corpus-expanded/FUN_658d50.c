/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x658d50; label: FUN_00658d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00658d50(float param_1,float *param_2,float param_3,float param_4,byte param_5)

{
  short sVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  
  iVar4 = DAT_029620a4 + (int)param_1 * 0x330;
  sVar1 = *(short *)(iVar4 + 0x182);
  if (((((sVar1 != 0) && (sVar1 != -1)) && (iVar2 = *(int *)(DAT_0296209c + sVar1 * 4), iVar2 != 0))
      && (((*(byte *)(iVar2 + 0x2f2) & param_5) != 0 && (*(char *)(iVar2 + 0x2f0) != '\0')))) &&
     (iVar5 = 0, '\0' < *(char *)(iVar2 + 0x2f0))) {
    pfVar6 = (float *)(iVar4 + 500);
    do {
      fVar3 = _DAT_0296205c - pfVar6[3];
      if ((0.0 <= fVar3) && (fVar3 <= *(float *)(iVar2 + 0xa4))) {
        iVar4 = 0;
        pfVar7 = (float *)(iVar2 + 0x2b8);
        _DAT_02947b48 = pfVar6[-3] + *pfVar6 * fVar3;
        _DAT_02947b4c = pfVar6[-2] + fVar3 * fVar3 * *(float *)(iVar2 + 0xa0) + pfVar6[1] * fVar3;
        _DAT_02947b50 = pfVar6[-1] + pfVar6[2] * fVar3;
        fVar3 = fVar3 / *(float *)(iVar2 + 0xa4);
        do {
          if ((pfVar7[-2] < fVar3 != (pfVar7[-2] == fVar3)) && (fVar3 <= *pfVar7)) {
            pfVar7 = (float *)(iVar2 + 0x2b4 + iVar4 * 8);
            fVar3 = (*(float *)(iVar2 + 700 + iVar4 * 8) - *pfVar7) *
                    ((fVar3 - *(float *)(iVar2 + 0x2b0 + iVar4 * 8)) /
                    (*(float *)(iVar2 + 0x2b8 + iVar4 * 8) - *(float *)(iVar2 + 0x2b0 + iVar4 * 8)))
                    + *pfVar7;
            if (fVar3 < 0.0 == (fVar3 == 0.0)) {
              param_1 = param_2[1] - _DAT_02947b4c;
              if (param_4 != 1.0) {
                param_1 = ((fVar3 + param_3) / (param_3 * param_4 + fVar3)) * param_1;
              }
              if ((param_2[2] - _DAT_02947b50) * (param_2[2] - _DAT_02947b50) +
                  (*param_2 - _DAT_02947b48) * (*param_2 - _DAT_02947b48) + param_1 * param_1 <
                  (param_3 + fVar3) * (param_3 + fVar3)) {
                return 1;
              }
            }
            break;
          }
          iVar4 = iVar4 + 1;
          pfVar7 = pfVar7 + 2;
        } while (iVar4 < 7);
      }
      iVar5 = iVar5 + 1;
      pfVar6 = pfVar6 + 7;
    } while (iVar5 < *(char *)(iVar2 + 0x2f0));
  }
  return 0;
}

