/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64ae50; label: FUN_0064ae50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064ae50(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 fVar3;
  float10 fVar4;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  
  if (param_1 != -1) {
    iVar2 = (&DAT_0291f7b4)[param_1 * 0x1b];
    if (iVar2 != -1) {
      if (((float)(&DAT_02913b48)[iVar2 * 0x5e] == 0.0) &&
         ((float)(&DAT_02913b50)[iVar2 * 0x5e] == 0.0)) {
        iVar1 = FUN_006e6b90();
        param_2 = (float)(extraout_ST0 * (float10)iVar1) + param_2;
        fVar3 = (float10)param_2;
        (&DAT_0291f7cc)[param_1 * 0x1b] = param_2;
        (&DAT_0291f7d0)[param_1 * 0x1b] =
             (float)(fVar3 + (float10)(float)(&DAT_02913b44)[iVar2 * 0x5e]);
        while ((fVar4 = extraout_ST1, fVar3 < extraout_ST1 &&
               ((float10)(float)(&DAT_0291f7d0)[param_1 * 0x1b] < extraout_ST1))) {
          if ((float)(&DAT_0291f7d0)[param_1 * 0x1b] < (float)(&DAT_0291f7cc)[param_1 * 0x1b] ==
              ((float)(&DAT_0291f7d0)[param_1 * 0x1b] == (float)(&DAT_0291f7cc)[param_1 * 0x1b])) {
            (&DAT_0291f7cc)[param_1 * 0x1b] =
                 (float)(&DAT_0291f7d0)[param_1 * 0x1b] + (float)(&DAT_02913b4c)[iVar2 * 0x5e];
          }
          else {
            (&DAT_0291f7d0)[param_1 * 0x1b] =
                 (float)(&DAT_02913b44)[iVar2 * 0x5e] + (float)(&DAT_0291f7cc)[param_1 * 0x1b];
          }
          fVar3 = (float10)(float)(&DAT_0291f7cc)[param_1 * 0x1b];
        }
      }
      else {
        (&DAT_0291f7cc)[param_1 * 0x1b] = _DAT_02920a90;
        fVar4 = (float10)FUN_005b9d90(&DAT_008102e8);
        (&DAT_0291f7d0)[param_1 * 0x1b] =
             (float)((float10)(float)(&DAT_02913b44)[iVar2 * 0x5e] +
                     (float10)(float)(&DAT_0291f7cc)[param_1 * 0x1b] +
                    fVar4 * (float10)(float)(&DAT_02913b48)[iVar2 * 0x5e]);
        fVar4 = (float10)_DAT_02920a90;
      }
      if ((float10)(float)(&DAT_0291f7d0)[param_1 * 0x1b] < fVar4) {
        (&DAT_0291f7c8)[param_1 * 0x1b] =
             (float)(&DAT_0291f7cc)[param_1 * 0x1b] - 1.0 / (float)(&DAT_02913b24)[iVar2 * 0x5e];
        *(float *)(&DAT_0291f7e0 + param_1 * 0x6c) = (float)fVar4;
        return;
      }
      iVar2 = FUN_006e6b90();
      (&DAT_0291f7c8)[param_1 * 0x1b] = (float)(extraout_ST0_00 * (float10)iVar2);
      *(float *)(&DAT_0291f7e0 + param_1 * 0x6c) = (float)extraout_ST1_00;
    }
  }
  return;
}

