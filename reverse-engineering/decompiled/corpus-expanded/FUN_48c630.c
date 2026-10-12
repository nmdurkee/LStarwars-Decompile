/* Ghidra pseudocode, not original source.
 * ev_d2059846c6c59f2eb69523c3226546ce784b50eedb8313b68b3d943803e3bded
 * Entry: 0x48c630; label: FUN_0048c630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048c630(int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_20 = DAT_0093b0d0;
  local_2c = DAT_0093b0d0;
  local_24 = DAT_0093b0cc;
  local_1c = DAT_0093b0d4;
  local_30 = DAT_0093b0cc;
  local_28 = DAT_0093b0d4;
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x13c), iVar2 != 0)) {
    if (0 < *(int *)(iVar2 + 0xf4) * 2) {
      iVar6 = 0;
      iVar5 = (*(int *)(iVar2 + 0xf4) * 2 - 1U >> 1) + 1;
      do {
        if ((*(int *)(iVar2 + 0x110) == 0) ||
           ((*(uint *)(*(int *)(iVar2 + 0x110) + 0x74) & 0x4000) == 0)) {
          local_18 = *(float *)(*(int *)(iVar2 + 0xfc) + iVar6);
          iVar4 = *(int *)(iVar2 + 0xfc) + iVar6;
          local_14 = *(float *)(iVar4 + 4);
          local_10 = *(float *)(iVar4 + 8);
          local_c = *(float *)(iVar4 + 0x10);
          local_8 = *(float *)(iVar4 + 0x14);
          fVar1 = *(float *)(iVar4 + 0x18);
        }
        else {
          pfVar3 = (float *)(*(int *)(iVar2 + 0xfc) + iVar6);
          local_18 = *(float *)(*(int *)(iVar2 + 0xfc) + iVar6) - pfVar3[4];
          local_14 = pfVar3[1] - pfVar3[5];
          local_10 = pfVar3[2] - pfVar3[6];
          local_c = pfVar3[4] + *pfVar3;
          local_8 = pfVar3[1] + pfVar3[5];
          fVar1 = pfVar3[2] + pfVar3[6];
        }
        if (local_18 < local_24) {
          local_24 = local_18;
        }
        if (local_30 < local_c) {
          local_30 = local_c;
        }
        if (local_14 < local_20) {
          local_20 = local_14;
        }
        if (local_2c < local_8) {
          local_2c = local_8;
        }
        if (local_10 < local_1c) {
          local_1c = local_10;
        }
        if (local_28 < fVar1) {
          local_28 = fVar1;
        }
        iVar6 = iVar6 + 0x20;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    *(float *)(param_1 + 0x150) = local_30;
    *(float *)(param_1 + 0x154) = local_2c;
    *(float *)(param_1 + 0x144) = local_24;
    *(float *)(param_1 + 0x158) = local_28;
    *(float *)(param_1 + 0x148) = local_20;
    *(float *)(param_1 + 0x14c) = local_1c;
  }
  return;
}

