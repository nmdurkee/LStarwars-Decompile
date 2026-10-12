/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a51f0; label: FUN_005a51f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a51f0(int param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float fVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  float local_30;
  float local_28;
  float local_24;
  float local_1c;
  
  if ((*(uint *)(param_2 + 200) & 0x400) == 0) {
    pfVar5 = *(float **)(param_2 + 0x58);
    fVar6 = *(float *)(param_2 + 0xb0);
    fVar1 = *pfVar5;
    fVar7 = *(float *)(param_2 + 0xb8);
    fVar8 = *(float *)(param_2 + 0xbc);
    fVar9 = *(float *)(param_2 + 0xc4);
    fVar2 = pfVar5[2];
    fVar3 = *pfVar5;
    iVar13 = 0;
    fVar4 = pfVar5[2];
    if (0 < *(int *)(param_1 + 0x46c0)) {
      param_2 = 0;
      fVar11 = _DAT_00805a74;
      do {
        if (iVar13 != param_3) {
          pfVar14 = (float *)(*(int *)(param_1 + 0x46bc) + param_2);
          if (((((uint)pfVar14[0x32] & 0x4000000) == 0) && (((uint)pfVar14[0x32] & 0x40000) != 0))
             && (pfVar10 = (float *)pfVar14[0x16], pfVar5[1] < pfVar10[1])) {
            local_30 = (fVar1 + fVar6) - pfVar14[0x2f];
            local_28 = (fVar2 + fVar7) - pfVar14[0x31];
            local_24 = (fVar3 + fVar8) - pfVar14[0x2c];
            local_1c = (fVar4 + fVar9) - pfVar14[0x2e];
            if (0.0 < fVar11) {
              local_30 = fVar11 + local_30;
              local_28 = local_28 + fVar11;
              local_24 = local_24 - fVar11;
              local_1c = local_1c - fVar11;
            }
            if (((local_30 < *pfVar10 != (local_30 == *pfVar10)) && (*pfVar10 <= local_24)) &&
               ((local_28 < pfVar10[2] != (local_28 == pfVar10[2]) && (pfVar10[2] <= local_1c)))) {
              pfVar14[0x29] = *pfVar10;
              pfVar14[0x2a] = pfVar10[1];
              pfVar14[0x2b] = pfVar10[2];
              *pfVar10 = *pfVar10 + *param_4;
              pfVar10[1] = pfVar10[1] - param_4[1];
              *pfVar14 = *pfVar14 - param_4[1];
              pfVar10[2] = param_4[2] + pfVar10[2];
              pfVar14[0x32] = (float)((uint)pfVar14[0x32] | 4);
              iVar12 = FUN_005a4eb0(param_1,pfVar14,iVar13,pfVar14 + 7);
              if (iVar12 != 0) {
                pfVar14[0x32] = (float)((uint)pfVar14[0x32] | 0x400);
              }
              FUN_005ea660(pfVar14 + 9);
              fVar11 = _DAT_00805a74;
            }
          }
        }
        param_2 = param_2 + 0xd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(param_1 + 0x46c0));
    }
  }
  return;
}

