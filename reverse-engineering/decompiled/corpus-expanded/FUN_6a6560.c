/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a6560; label: FUN_006a6560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a6560(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  
  iVar3 = *param_1;
  if (iVar3 < param_5) {
    param_5 = iVar3;
  }
  iVar4 = 0;
  if (3 < param_5) {
    pfVar2 = (float *)(param_2 + 4);
    pfVar5 = (float *)(param_4 + 8);
    do {
      iVar1 = iVar4 * 4;
      iVar4 = iVar4 + 4;
      pfVar5[-2] = *(float *)(&DAT_00816b90 + *(int *)(param_3 + iVar1) * 4) * pfVar2[-1];
      *(float *)((param_4 - param_2) + -0x10 + (int)(pfVar2 + 4)) =
           *(float *)(&DAT_00816b90 + *(int *)((int)pfVar2 + (param_3 - param_2)) * 4) * *pfVar2;
      *pfVar5 = *(float *)(&DAT_00816b90 +
                          *(int *)((param_3 - param_4) + -0x10 + (int)(pfVar5 + 4)) * 4) * pfVar2[1]
      ;
      pfVar5[1] = *(float *)(&DAT_00816b90 + *(int *)(param_3 + -4 + iVar4 * 4) * 4) * pfVar2[2];
      pfVar2 = pfVar2 + 4;
      pfVar5 = pfVar5 + 4;
    } while (iVar4 < param_5 + -3);
  }
  if (iVar4 < param_5) {
    param_5 = param_5 - iVar4;
    iVar1 = iVar4 * 4;
    iVar4 = iVar4 + param_5;
    pfVar2 = (float *)(param_2 + iVar1);
    do {
      param_5 = param_5 + -1;
      *(float *)((int)pfVar2 + (param_4 - param_2)) =
           *(float *)(&DAT_00816b90 + *(int *)((param_3 - param_2) + (int)pfVar2) * 4) * *pfVar2;
      pfVar2 = pfVar2 + 1;
    } while (param_5 != 0);
  }
  if (iVar4 < iVar3) {
    puVar6 = (undefined4 *)(param_4 + iVar4 * 4);
    for (iVar3 = iVar3 - iVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
  }
  return;
}

