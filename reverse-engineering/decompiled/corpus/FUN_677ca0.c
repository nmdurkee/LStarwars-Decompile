/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x677ca0; label: FUN_00677ca0
 */

void FUN_00677ca0(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float local_18;
  float local_10;
  float local_c;
  float local_4;
  
  uVar1 = *param_1;
  while (-1 < (int)(uVar1 - 3)) {
    uVar2 = uVar1 + 1;
    uVar6 = 0x10;
    if (uVar2 < 0x10) {
      uVar6 = uVar2;
    }
    local_18 = *(float *)(param_1 + 2);
    local_10 = *(float *)(param_1 + 6);
    iVar5 = 1;
    local_c = local_18;
    local_4 = local_10;
    if (3 < (int)(uVar6 - 1)) {
      iVar4 = (uVar6 - 5 >> 2) + 1;
      pfVar3 = (float *)(param_1 + 0xc);
      iVar5 = iVar4 * 4 + 1;
      do {
        if (pfVar3[-2] < local_18) {
          local_18 = pfVar3[-2];
        }
        if (*pfVar3 < local_10) {
          local_10 = *pfVar3;
        }
        if (local_c < pfVar3[-2]) {
          local_c = pfVar3[-2];
        }
        if (local_4 < *pfVar3) {
          local_4 = *pfVar3;
        }
        if (pfVar3[1] < local_18) {
          local_18 = pfVar3[1];
        }
        if (pfVar3[3] < local_10) {
          local_10 = pfVar3[3];
        }
        if (local_c < pfVar3[1]) {
          local_c = pfVar3[1];
        }
        if (local_4 < pfVar3[3]) {
          local_4 = pfVar3[3];
        }
        if (pfVar3[4] < local_18) {
          local_18 = pfVar3[4];
        }
        if (pfVar3[6] < local_10) {
          local_10 = pfVar3[6];
        }
        if (local_c < pfVar3[4]) {
          local_c = pfVar3[4];
        }
        if (local_4 < pfVar3[6]) {
          local_4 = pfVar3[6];
        }
        if (pfVar3[7] < local_18) {
          local_18 = pfVar3[7];
        }
        if (pfVar3[9] < local_10) {
          local_10 = pfVar3[9];
        }
        if (local_c < pfVar3[7]) {
          local_c = pfVar3[7];
        }
        if (local_4 < pfVar3[9]) {
          local_4 = pfVar3[9];
        }
        pfVar3 = pfVar3 + 0xc;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (iVar5 < (int)uVar6) {
      iVar4 = uVar6 - iVar5;
      pfVar3 = (float *)(param_1 + (iVar5 * 3 + 3) * 2);
      do {
        if (pfVar3[-2] < local_18) {
          local_18 = pfVar3[-2];
        }
        if (*pfVar3 < local_10) {
          local_10 = *pfVar3;
        }
        if (local_c < pfVar3[-2]) {
          local_c = pfVar3[-2];
        }
        if (local_4 < *pfVar3) {
          local_4 = *pfVar3;
        }
        pfVar3 = pfVar3 + 3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *(float *)(param_1 + 4) = local_18;
    *(float *)(param_1 + 10) = local_c;
    *(float *)(param_1 + 0x10) = local_10;
    *(float *)(param_1 + 0x16) = local_4;
    uVar1 = *param_1;
  }
  if (*param_1 != 0xffffffff) {
    param_1[4] = 0;
    param_1[5] = 0x4f00;
  }
  return;
}

