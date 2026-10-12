/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x6604f0; label: FUN_006604f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006604f0(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(char *)(param_1 + 0x2f0) != '\0') && (iVar5 = 0, '\0' < *(char *)(param_1 + 0x2f0))) {
    param_2 = param_2 * 0x330;
    iVar3 = DAT_029620a4;
    do {
      fVar1 = _DAT_0296205c - *(float *)(param_2 + 0x200 + iVar3);
      if ((0.0 <= fVar1) && (fVar1 <= *(float *)(param_1 + 0xa4))) {
        pfVar4 = (float *)(param_1 + 0x2b8);
        local_c = *(float *)(param_2 + 0x1e8 + iVar3) + *(float *)(param_2 + 500 + iVar3) * fVar1;
        local_8 = *(float *)(param_2 + 0x1ec + iVar3) +
                  fVar1 * fVar1 * *(float *)(param_1 + 0xa0) +
                  *(float *)(param_2 + 0x1f8 + iVar3) * fVar1;
        iVar2 = 0;
        local_4 = *(float *)(param_2 + 0x1f0 + iVar3) + *(float *)(param_2 + 0x1fc + iVar3) * fVar1;
        fVar1 = fVar1 / *(float *)(param_1 + 0xa4);
        do {
          if ((pfVar4[-2] < fVar1 != (pfVar4[-2] == fVar1)) && (fVar1 <= *pfVar4)) break;
          iVar2 = iVar2 + 1;
          pfVar4 = pfVar4 + 2;
        } while (iVar2 < 7);
        pfVar4 = (float *)(param_1 + 0x2b4 + iVar2 * 8);
        FUN_0065c520(&local_c,(*(float *)(param_1 + 700 + iVar2 * 8) - *pfVar4) *
                              ((fVar1 - *(float *)(param_1 + 0x2b0 + iVar2 * 8)) /
                              (*(float *)(param_1 + 0x2b8 + iVar2 * 8) -
                              *(float *)(param_1 + 0x2b0 + iVar2 * 8))) + *pfVar4,0xffff0000,
                     DAT_02947c68);
        iVar3 = DAT_029620a4;
      }
      iVar5 = iVar5 + 1;
      param_2 = param_2 + 0x1c;
    } while (iVar5 < *(char *)(param_1 + 0x2f0));
  }
  return;
}

