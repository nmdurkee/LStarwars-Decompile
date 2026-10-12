/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4eeb10; label: FUN_004eeb10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004eeb10(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  float fVar11;
  float *pfVar12;
  float fVar13;
  float *pfVar14;
  float local_80;
  int local_7c;
  int local_74;
  float local_58;
  float local_48 [6];
  undefined4 local_30;
  float local_24 [6];
  undefined4 local_c;
  
  if (2 < param_3) {
    local_30 = 0xffffffff;
    local_c = 0xffffffff;
    local_48[1] = param_1[1];
    local_48[0] = *param_1;
    fVar11 = *param_1 + (*param_2 - *param_1) * 0.5;
    fVar13 = (param_2[1] - param_1[1]) * 0.5 + param_1[1];
    local_58 = (param_2[2] - param_1[2]) * 0.5 + param_1[2];
    local_48[2] = param_1[2];
    local_24[0] = fVar11;
    local_24[1] = fVar13;
    local_24[2] = local_58;
    FUN_005dbed0(local_48,DAT_0093b108,0);
    fVar7 = (float)DAT_00800440;
    param_3 = param_3 + -1;
    iVar8 = 0;
    if (0 < param_3) {
      iVar9 = DAT_00800440;
      pfVar10 = param_2;
      local_74 = param_3;
      do {
        local_48[2] = local_58;
        local_7c = 0;
        fVar1 = (pfVar10[3] - *pfVar10) * 0.5 + *pfVar10;
        fVar3 = (pfVar10[4] - pfVar10[1]) * 0.5 + pfVar10[1];
        fVar2 = (pfVar10[5] - pfVar10[2]) * 0.5 + pfVar10[2];
        local_80 = 1.0 - 1.0 / fVar7;
        local_48[0] = fVar11;
        local_48[1] = fVar13;
        if (0 < iVar9) {
          do {
            fVar4 = 1.0 - local_80;
            fVar6 = local_80 * local_80;
            fVar5 = fVar4 * fVar4;
            fVar4 = (local_80 + local_80) * fVar4;
            local_24[0] = fVar5 * fVar1 + *pfVar10 * fVar4 + fVar6 * fVar11;
            local_24[1] = fVar5 * fVar3 + pfVar10[1] * fVar4 + fVar6 * fVar13;
            local_24[2] = fVar5 * fVar2 + local_58 * fVar6 + pfVar10[2] * fVar4;
            FUN_005dbed0(local_48,DAT_0093b108,0);
            pfVar12 = local_24;
            pfVar14 = local_48;
            for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
              *pfVar14 = *pfVar12;
              pfVar12 = pfVar12 + 1;
              pfVar14 = pfVar14 + 1;
            }
            local_7c = local_7c + 1;
            iVar9 = DAT_00800440;
            local_80 = local_80 - 1.0 / fVar7;
          } while (local_7c < DAT_00800440);
        }
        local_74 = local_74 + -1;
        iVar8 = param_3;
        pfVar10 = pfVar10 + 3;
        fVar11 = fVar1;
        fVar13 = fVar3;
        local_58 = fVar2;
      } while (local_74 != 0);
    }
    local_24[0] = param_2[iVar8 * 3];
    local_24[1] = param_2[iVar8 * 3 + 1];
    local_24[2] = param_2[iVar8 * 3 + 2];
    FUN_005dbed0(local_48,DAT_0093b108,0);
  }
  return;
}

