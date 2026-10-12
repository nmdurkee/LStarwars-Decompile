/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x430f20; label: FUN_00430f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00430f20(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  float10 fVar9;
  
  iVar3 = *param_2;
  fVar1 = (float)param_1[0x1b];
  iVar4 = *param_1;
  fVar2 = (float)param_2[0x1b];
  iVar8 = FUN_004a4350(iVar4,iVar3);
  if (iVar8 != 0) {
    if (((*(uint *)(iVar3 + 0x1e8) & *(uint *)(iVar4 + 0x1f0)) != 0 ||
         (*(uint *)(iVar3 + 0x1ec) & *(uint *)(iVar4 + 500)) != 0) ||
       (iVar8 = 2,
       (*(uint *)(iVar3 + 0x1f0) & *(uint *)(iVar4 + 0x1e8)) != 0 ||
       (*(uint *)(iVar3 + 500) & *(uint *)(iVar4 + 0x1ec)) != 0)) {
      iVar8 = 1;
    }
    param_1[0x7c] = param_1[0x7c] | param_2[0x7a];
    param_1[0x7d] = param_1[0x7d] | param_2[0x7b];
    param_2[0x7c] = param_2[0x7c] | param_1[0x7a];
    param_2[0x7d] = param_2[0x7d] | param_1[0x7b];
    return iVar8;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f8) {
    iVar8 = FUN_0062b0f0();
  }
  else {
    iVar8 = FUN_0062b800(param_1,param_2);
  }
  if ((iVar8 == 2) && (DAT_00951288 == 0)) {
    iVar5 = *(int *)(*(int *)(iVar4 + 0x54) + 0x24);
    uVar6 = *(uint *)(iVar5 + 0x90);
    if (((uVar6 & 0x1000) == 0) || ((float)param_1[0x8b] <= *(float *)(iVar5 + 0x1c) * 0.5)) {
      iVar5 = *(int *)(*(int *)(iVar3 + 0x54) + 0x24);
      uVar7 = *(uint *)(iVar5 + 0x90);
      if (((uVar7 & 0x1000) == 0) || ((float)param_2[0x8b] <= *(float *)(iVar5 + 0x1c) * 0.5)) {
        if ((0.0 <= fVar2) || (((uVar6 & 0x40) == 0 || (*(short *)(iVar4 + 0x1070) != -1)))) {
          if ((fVar1 < 0.0) && (((uVar7 & 0x40) != 0 && (*(short *)(iVar3 + 0x1070) == -1)))) {
            param_2[0x1b] = (int)(fVar1 * 0.5 + (float)param_2[0x1b]);
          }
        }
        else {
          param_1[0x1b] = (int)(fVar2 * 0.5 + (float)param_1[0x1b]);
        }
      }
      else {
        FUN_0049bc30(iVar3,iVar4);
      }
    }
    else {
      FUN_0049bc30(iVar4,iVar3);
    }
  }
  fVar1 = *(float *)(*(int *)(param_1[0x15] + 0x24) + 0x1c) * 1.25;
  if (fVar1 < 1.0) {
    fVar1 = 1.0;
  }
  fVar2 = (float)param_1[0x1a] * (float)param_1[0x1a] + (float)param_1[0x1c] * (float)param_1[0x1c];
  if (fVar1 * fVar1 < fVar2) {
    fVar9 = (float10)FUN_005c0240(fVar2);
    param_1[0x1a] = (int)((float)((float10)fVar1 / fVar9) * (float)param_1[0x1a]);
    param_1[0x1c] = (int)((float)((float10)fVar1 / fVar9) * (float)param_1[0x1c]);
  }
  fVar1 = *(float *)(*(int *)(param_2[0x15] + 0x24) + 0x1c) * 1.25;
  if (fVar1 < 1.0) {
    fVar1 = 1.0;
  }
  fVar2 = (float)param_2[0x1a] * (float)param_2[0x1a] + (float)param_2[0x1c] * (float)param_2[0x1c];
  if (fVar2 <= fVar1 * fVar1) {
    return iVar8;
  }
  fVar9 = (float10)FUN_005c0240(fVar2);
  param_2[0x1a] = (int)((float)((float10)fVar1 / fVar9) * (float)param_2[0x1a]);
  param_2[0x1c] = (int)((float)((float10)fVar1 / fVar9) * (float)param_2[0x1c]);
  return iVar8;
}

