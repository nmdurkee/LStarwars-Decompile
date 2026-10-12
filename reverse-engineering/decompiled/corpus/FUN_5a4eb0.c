/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a4eb0; label: FUN_005a4eb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005a4eb0(int param_1,int param_2,int param_3,int *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_2c;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  iVar7 = param_2;
  pfVar1 = *(float **)(param_2 + 0x58);
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  local_2c = 0;
  if (0 < *(int *)(param_1 + 0x46c0)) {
    param_2 = 0;
    do {
      if (((local_2c != param_3) &&
          (iVar9 = *(int *)(param_1 + 0x46bc) + param_2, (*(uint *)(iVar9 + 200) & 0x2000000) == 0))
         && (iVar8 = FUN_005cfd60(iVar9 + 0x24), iVar8 != 0)) {
        pfVar2 = *(float **)(iVar9 + 0x58);
        fVar3 = pfVar1[1] - pfVar2[1];
        local_18 = *(float *)(iVar9 + 0xb0) - *(float *)(iVar7 + 0xbc);
        local_14 = *(float *)(iVar9 + 0xb4) - *(float *)(iVar7 + 0xc0);
        local_10 = *(float *)(iVar9 + 0xb8) - *(float *)(iVar7 + 0xc4);
        local_24 = *(float *)(iVar9 + 0xbc) - *(float *)(iVar7 + 0xb0);
        local_20 = *(float *)(iVar9 + 0xc0) - *(float *)(iVar7 + 0xb4);
        local_1c = *(float *)(iVar9 + 0xc4) - *(float *)(iVar7 + 0xb8);
        if (0.0 < _DAT_0095dea4) {
          local_18 = _DAT_0095dea4 + local_18;
          local_14 = _DAT_0095dea4 + local_14;
          local_10 = _DAT_0095dea4 + local_10;
          local_24 = local_24 - _DAT_0095dea4;
          local_20 = local_20 - _DAT_0095dea4;
          local_1c = local_1c - _DAT_0095dea4;
        }
        if ((*pfVar1 - *pfVar2 <= _DAT_00805a74 + local_18) ||
           (local_24 - _DAT_00805a74 <= *pfVar1 - *pfVar2)) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
        if ((fVar3 <= local_14) || (bVar6 = true, local_20 <= fVar3)) {
          bVar6 = false;
        }
        if ((pfVar1[2] - pfVar2[2] <= _DAT_00805a74 + local_10) ||
           (local_1c - _DAT_00805a74 <= pfVar1[2] - pfVar2[2])) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        if (param_4 != (int *)0x0) {
          if (!bVar4) goto LAB_005a51be;
          if ((bVar5) && (fVar3 = fVar3 - local_20, 0.0 < fVar3)) {
            iVar8 = *param_4;
            if (iVar8 == 0) {
              *param_4 = iVar9;
            }
            else {
              local_20 = *(float *)(iVar8 + 0xc0) - *(float *)(iVar7 + 0xb4);
              if (0.0 < _DAT_0095dea4) {
                local_20 = local_20 - _DAT_0095dea4;
              }
              if (fVar3 < (pfVar1[1] - *(float *)(*(int *)(iVar8 + 0x58) + 4)) - local_20) {
                *(int *)(iVar9 + 0x1c) = iVar8;
                *param_4 = iVar9;
              }
            }
          }
        }
        if (((bVar4) && (bVar6)) && (bVar5)) {
          return iVar9;
        }
      }
LAB_005a51be:
      param_2 = param_2 + 0xd4;
      local_2c = local_2c + 1;
    } while (local_2c < *(int *)(param_1 + 0x46c0));
  }
  return 0;
}

