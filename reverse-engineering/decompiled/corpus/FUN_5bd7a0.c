/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bd7a0; label: FUN_005bd7a0
 */

undefined4 FUN_005bd7a0(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST0_00;
  float10 fVar9;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float local_10;
  float local_c;
  int local_8;
  
  FUN_005bcf50(param_1,100);
  local_8 = 0;
  if (0 < param_3) {
    iVar5 = FUN_006e6b90();
    iVar4 = DAT_0095e5dc;
    iVar3 = DAT_0095e5d8;
    do {
      fVar2 = (float)local_8 * (1.0 / (float)(param_3 + -1));
      iVar6 = FUN_006e6b90();
      if (iVar3 <= iVar6) {
        iVar6 = iVar3 + -1;
      }
      if (iVar4 == 0) {
        local_c = 0.0;
      }
      else {
        local_c = *(float *)(iVar4 + iVar6 * 0xc);
      }
      if (iVar3 <= iVar5) {
        iVar5 = iVar3 + -1;
      }
      if (iVar4 == 0) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = *(float *)(iVar4 + iVar5 * 0xc);
      }
      fVar7 = (float10)fVar2;
      fVar8 = (float10)fVar1;
      fVar9 = extraout_ST0;
      if (fVar8 < fVar7 != (fVar8 == fVar7)) {
        do {
          local_c = (float)fVar8;
          fVar7 = (float10)(float)fVar9;
          iVar5 = FUN_006e6b90();
          if (iVar3 <= iVar5) {
            iVar5 = iVar3 + -1;
          }
          if (iVar4 == 0) {
            fVar1 = 0.0;
          }
          else {
            fVar1 = *(float *)(iVar4 + iVar5 * 0xc);
          }
          fVar8 = (float10)fVar1;
          fVar9 = extraout_ST0_00;
        } while (fVar8 < fVar7 != (fVar8 == fVar7));
      }
      fVar9 = (float10)local_c;
      if (fVar8 == fVar9) {
        local_10 = 0.0;
      }
      else {
        local_10 = (float)(((float10)fVar2 - fVar9) / (fVar8 - fVar9));
      }
      iVar5 = FUN_006e6b90();
      if (iVar3 <= iVar5) {
        iVar5 = iVar3 + -1;
      }
      if (iVar4 == 0) {
        local_c = (float)extraout_ST0_01;
      }
      else {
        local_c = *(float *)(iVar4 + 4 + iVar5 * 0xc);
      }
      iVar5 = FUN_006e6b90();
      iVar6 = iVar5;
      if (iVar3 <= iVar5) {
        iVar6 = iVar3 + -1;
      }
      fVar9 = extraout_ST1;
      if (iVar4 != 0) {
        fVar9 = (float10)*(float *)(iVar4 + 4 + iVar6 * 0xc);
      }
      local_c = local_c + local_10 * ((float)fVar9 - local_c);
      *(float *)(param_2 + local_8 * 4) = local_c;
      if (1.0 < local_c) {
        *(undefined4 *)(param_2 + local_8 * 4) = 0x3f800000;
      }
      local_8 = local_8 + 1;
      *(float *)(param_2 + -4 + local_8 * 4) =
           *(float *)(param_1 + 0x50) * *(float *)(param_2 + -4 + local_8 * 4);
    } while (local_8 < param_3);
  }
  return 0;
}

