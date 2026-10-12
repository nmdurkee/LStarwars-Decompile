/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b5e90; label: FUN_005b5e90
 */

void FUN_005b5e90(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float *local_64;
  float *local_60;
  float local_5c;
  int local_58;
  int aiStack_50 [3];
  float afStack_44 [9];
  float local_20 [4];
  float local_10 [4];
  
  afStack_44[1] = (float)*param_2;
  afStack_44[2] = (float)param_2[1];
  local_64 = afStack_44 + 3;
  afStack_44[3] = (float)param_2[2];
  afStack_44[4] = (float)param_2[3];
  local_58 = 4;
  afStack_44[5] = (float)param_2[4];
  afStack_44[6] = (float)param_2[5];
  afStack_44[7] = (float)param_2[6];
  afStack_44[8] = (float)param_2[7];
  local_20[0] = (float)param_2[8];
  local_20[1] = (float)param_2[9];
  local_20[2] = (float)param_2[10];
  local_20[3] = (float)param_2[0xb];
  local_10[0] = (float)param_2[0xc];
  local_10[1] = (float)param_2[0xd];
  local_10[2] = (float)param_2[0xe];
  local_10[3] = (float)param_2[0xf];
  iVar7 = 0;
  local_60 = afStack_44 + 1;
  while( true ) {
    local_5c = 0.0;
    aiStack_50[iVar7] = 0;
    pfVar6 = local_60;
    iVar8 = iVar7;
    if (local_58 < 1) {
      return;
    }
    do {
      param_2 = (undefined4 *)0x0;
      iVar5 = iVar7;
      if (3 < local_58) {
        iVar4 = ((uint)-iVar7 >> 2) + 1;
        iVar5 = iVar7 + iVar4 * 4;
        pfVar3 = pfVar6 + 1;
        do {
          iVar4 = iVar4 + -1;
          param_2 = (undefined4 *)
                    (ABS(pfVar3[2]) +
                    ABS(pfVar3[1]) + ABS(*pfVar3) + ABS(pfVar3[-1]) + (float)param_2);
          pfVar3 = pfVar3 + 4;
        } while (iVar4 != 0);
      }
      if (iVar5 < 4) {
        pfVar3 = afStack_44 + iVar5 + iVar8 * 4 + 1;
        iVar5 = 4 - iVar5;
        do {
          fVar1 = *pfVar3;
          pfVar3 = pfVar3 + 1;
          iVar5 = iVar5 + -1;
          param_2 = (undefined4 *)(ABS(fVar1) + (float)param_2);
        } while (iVar5 != 0);
      }
      if ((ABS(*pfVar6) == 0.0) || ((float)param_2 == 0.0)) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        param_2 = (undefined4 *)(ABS(*pfVar6) / (float)param_2);
      }
      if (local_5c < (float)param_2) {
        local_5c = (float)param_2;
        aiStack_50[iVar7] = iVar8;
      }
      iVar8 = iVar8 + 1;
      pfVar6 = pfVar6 + 4;
    } while (iVar8 < 4);
    if (local_5c == 0.0) break;
    iVar8 = aiStack_50[iVar7];
    if (iVar8 != iVar7) {
      fVar1 = local_64[-2];
      local_64[-2] = afStack_44[iVar8 * 4 + 1];
      afStack_44[iVar8 * 4 + 1] = fVar1;
      fVar1 = local_64[-1];
      local_64[-1] = afStack_44[iVar8 * 4 + 2];
      afStack_44[iVar8 * 4 + 2] = fVar1;
      fVar1 = *local_64;
      *local_64 = afStack_44[iVar8 * 4 + 3];
      afStack_44[iVar8 * 4 + 3] = fVar1;
      fVar1 = local_64[1];
      local_64[1] = afStack_44[iVar8 * 4 + 4];
      afStack_44[iVar8 * 4 + 4] = fVar1;
    }
    fVar1 = *local_60;
    iVar8 = 0;
    pfVar6 = local_64 + -2;
    do {
      if (iVar8 != iVar7) {
        fVar2 = *pfVar6;
        *pfVar6 = -fVar2 / fVar1;
        if (local_58 != 4) {
          afStack_44[iVar8 + 1] = afStack_44[iVar7 + 1] * (-fVar2 / fVar1) + afStack_44[iVar8 + 1];
        }
        if (local_58 != 3) {
          afStack_44[iVar8 + 5] = afStack_44[iVar7 + 5] * *pfVar6 + afStack_44[iVar8 + 5];
        }
        if (local_58 != 2) {
          afStack_44[iVar8 + 9] = afStack_44[iVar7 + 9] * *pfVar6 + afStack_44[iVar8 + 9];
        }
        if (local_58 != 1) {
          afStack_44[iVar8 + 0xd] = afStack_44[iVar7 + 0xd] * *pfVar6 + afStack_44[iVar8 + 0xd];
        }
      }
      iVar8 = iVar8 + 1;
      pfVar6 = pfVar6 + 1;
    } while (iVar8 < 4);
    local_64 = local_64 + 4;
    local_58 = local_58 + -1;
    afStack_44[iVar7 + 1] = afStack_44[iVar7 + 1] / fVar1;
    afStack_44[iVar7 + 5] = afStack_44[iVar7 + 5] / fVar1;
    afStack_44[iVar7 + 9] = afStack_44[iVar7 + 9] / fVar1;
    afStack_44[iVar7 + 0xd] = afStack_44[iVar7 + 0xd] / fVar1;
    *local_60 = 1.0 / fVar1;
    iVar7 = iVar7 + 1;
    local_60 = local_60 + 5;
    if (local_58 < 1) {
      iVar7 = 3;
      do {
        iVar8 = aiStack_50[iVar7];
        if (iVar8 != iVar7) {
          fVar1 = afStack_44[iVar7 + 1];
          afStack_44[iVar7 + 1] = afStack_44[iVar8 + 1];
          afStack_44[iVar8 + 1] = fVar1;
          fVar1 = afStack_44[iVar7 + 5];
          afStack_44[iVar7 + 5] = afStack_44[iVar8 + 5];
          afStack_44[iVar8 + 5] = fVar1;
          fVar1 = afStack_44[iVar7 + 9];
          afStack_44[iVar7 + 9] = afStack_44[iVar8 + 9];
          afStack_44[iVar8 + 9] = fVar1;
          fVar1 = afStack_44[iVar7 + 0xd];
          afStack_44[iVar7 + 0xd] = afStack_44[iVar8 + 0xd];
          afStack_44[iVar8 + 0xd] = fVar1;
        }
        iVar7 = iVar7 + -1;
      } while (-1 < iVar7);
      *param_1 = afStack_44[1];
      param_1[1] = afStack_44[2];
      param_1[2] = afStack_44[3];
      param_1[3] = afStack_44[4];
      param_1[4] = afStack_44[5];
      param_1[5] = afStack_44[6];
      param_1[6] = afStack_44[7];
      param_1[7] = afStack_44[8];
      param_1[8] = local_20[0];
      param_1[9] = local_20[1];
      param_1[10] = local_20[2];
      param_1[0xb] = local_20[3];
      param_1[0xc] = local_10[0];
      param_1[0xd] = local_10[1];
      param_1[0xe] = local_10[2];
      param_1[0xf] = local_10[3];
      return;
    }
  }
  return;
}

