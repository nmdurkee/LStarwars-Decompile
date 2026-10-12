/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x545a80; label: FUN_00545a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545a80(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  short *psVar10;
  int local_8;
  
  psVar10 = DAT_00924840;
  _DAT_02983a4c = _DAT_02983a4c + 0x1f5;
  _DAT_02983a54 = _DAT_02983a54 + 0x85;
  _DAT_02983a58 = _DAT_02983a58 + 0x179;
  if (DAT_00802028 == 0) {
    return;
  }
  FUN_0066cbc0();
  local_8 = 0;
  if (0 < DAT_00924838) {
    do {
      if (*psVar10 != 0) {
        if (*(float *)(psVar10 + 0x1c) <=
            (*(float *)(psVar10 + 0x12) - DAT_00973720) *
            (*(float *)(psVar10 + 0x12) - DAT_00973720) +
            (*(float *)(psVar10 + 0xe) - DAT_00973718) * (*(float *)(psVar10 + 0xe) - DAT_00973718)
            + (*(float *)(psVar10 + 0x10) - DAT_0097371c) *
              (*(float *)(psVar10 + 0x10) - DAT_0097371c)) {
          *(undefined1 *)((int)psVar10 + 0x29) = 0;
        }
        else {
          *(undefined1 *)((int)psVar10 + 0x29) = 1;
          if (psVar10[1] != 0) {
            FUN_0066cbb0(*(undefined4 *)(psVar10 + 6));
            iVar9 = *(int *)(psVar10 + 10);
            psVar8 = *(short **)(psVar10 + 0xc);
            iVar7 = 0;
            if (0 < psVar10[0x15]) {
              do {
                iVar6 = 0;
                do {
                  if ((*(int *)(param_1 + iVar6 * 4) != 0) &&
                     (pfVar1 = *(float **)(param_1 + iVar6 * 4),
                     fVar2 = *(float *)(iVar9 + 0x34) - pfVar1[1],
                     fVar4 = *(float *)(iVar9 + 0x30) - *pfVar1,
                     fVar3 = *(float *)(iVar9 + 0x38) - pfVar1[2],
                     fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2 < 4.0)) {
                    if (*psVar8 == -1) {
                      sVar5 = FUN_0067bf50(iVar9,(int)psVar10[8]);
                      *psVar8 = sVar5;
                      FUN_0067c7b0((int)sVar5,1);
                    }
                    goto LAB_00545bb1;
                  }
                  iVar6 = iVar6 + 1;
                } while (iVar6 < 8);
                if (*psVar8 != -1) {
                  FUN_0067c930((int)*psVar8);
                  *psVar8 = -1;
                }
LAB_00545bb1:
                iVar7 = iVar7 + 1;
                iVar9 = iVar9 + 0x40;
                psVar8 = psVar8 + 1;
              } while (iVar7 < psVar10[0x15]);
            }
          }
        }
      }
      local_8 = local_8 + 1;
      psVar10 = psVar10 + 0x20;
    } while (local_8 < DAT_00924838);
  }
  FUN_0066cbb0();
  return;
}

