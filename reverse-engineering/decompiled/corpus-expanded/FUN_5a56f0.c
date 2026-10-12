/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a56f0; label: FUN_005a56f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a56f0(int param_1,int param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  
  pfVar7 = param_3;
  iVar9 = 0;
  if ((param_3 != (float *)0x0) && (param_4 != (float *)0x0)) {
    *param_4 = -10000.0;
    param_4[1] = -10000.0;
    param_4[2] = -10000.0;
    param_4[3] = -10000.0;
    if (0 < *(int *)(param_1 + 0x46c0)) {
      param_3 = (float *)0x0;
      do {
        iVar8 = *(int *)(param_1 + 0x46bc) + (int)param_3;
        if (iVar8 != param_2) {
          pfVar1 = *(float **)(iVar8 + 0x58);
          fVar2 = *pfVar1 - ABS(*(float *)(iVar8 + 0xb0));
          fVar3 = pfVar1[2] - ABS(*(float *)(iVar8 + 0xb8));
          fVar4 = ABS(*(float *)(iVar8 + 0xbc)) + *pfVar1;
          fVar5 = ABS(*(float *)(iVar8 + 0xc0)) + pfVar1[1];
          fVar6 = ABS(*(float *)(iVar8 + 0xc4)) + pfVar1[2];
          if ((((fVar2 < *pfVar7) && (*pfVar7 < fVar4)) && (fVar3 < pfVar7[2])) &&
             (pfVar7[2] < fVar6)) {
            *param_4 = fVar5;
          }
          if (((fVar2 < pfVar7[3]) && (pfVar7[3] < fVar4)) &&
             ((fVar3 < pfVar7[5] && (pfVar7[5] < fVar6)))) {
            param_4[1] = fVar5;
          }
          if (((fVar2 < pfVar7[6]) && (pfVar7[6] < fVar4)) &&
             ((fVar3 < pfVar7[8] && (pfVar7[8] < fVar6)))) {
            param_4[2] = fVar5;
          }
          if ((((fVar2 < pfVar7[9]) && (pfVar7[9] < fVar4)) && (fVar3 < pfVar7[0xb])) &&
             (pfVar7[0xb] < fVar6)) {
            param_4[3] = fVar5;
          }
        }
        param_3 = (float *)((int)param_3 + 0xd4);
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(int *)(param_1 + 0x46c0));
    }
    return 1;
  }
  return 0;
}

