/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b5760; label: FUN_006b5760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b5760(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int local_1c;
  int local_14;
  int local_10;
  
  uVar7 = in_ECX - param_2;
  iVar9 = param_1 - in_EAX;
  iVar3 = (int)uVar7 / iVar9;
  if ((int)uVar7 < 0) {
    iVar4 = iVar3 + -1;
  }
  else {
    iVar4 = iVar3 + 1;
  }
  local_1c = param_2;
  local_10 = 0;
  uVar5 = FUN_006e6b90();
  if ((int)uVar5 < 0x400) {
    uVar5 = ((int)uVar5 < 0) - 1 & uVar5;
  }
  else {
    uVar5 = 0x3ff;
  }
  uVar8 = iVar3 * iVar9 >> 0x1f;
  fVar2 = *(float *)(param_4 + in_EAX * 4) + *(float *)(param_5 + 0x458);
  fVar1 = *(float *)(param_3 + in_EAX * 4);
  iVar10 = (param_2 - uVar5) * (param_2 - uVar5);
  local_14 = 1;
  if (fVar1 < fVar2 != (fVar1 == fVar2)) {
    if ((float)param_2 + *(float *)(param_5 + 0x448) < (float)(int)uVar5) {
      return 1;
    }
    if ((float)(int)uVar5 < (float)param_2 - *(float *)(param_5 + 0x44c)) {
      return 1;
    }
  }
  param_2 = in_EAX + 1;
  if (param_2 < param_1) {
    pfVar11 = (float *)(param_3 + param_2 * 4);
    do {
      local_10 = local_10 +
                 (((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)) -
                 ((iVar3 * iVar9 ^ uVar8) - uVar8));
      iVar6 = iVar3;
      if (iVar9 <= local_10) {
        local_10 = local_10 - iVar9;
        iVar6 = iVar4;
      }
      local_1c = local_1c + iVar6;
      uVar5 = FUN_006e6b90();
      if ((int)uVar5 < 0x400) {
        uVar5 = ((int)uVar5 < 0) - 1 & uVar5;
      }
      else {
        uVar5 = 0x3ff;
      }
      local_14 = local_14 + 1;
      iVar10 = iVar10 + (local_1c - uVar5) * (local_1c - uVar5);
      fVar1 = *(float *)((param_4 - param_3) + (int)pfVar11) + *(float *)(param_5 + 0x458);
      if ((*pfVar11 < fVar1 != (*pfVar11 == fVar1)) && (uVar5 != 0)) {
        if ((float)local_1c + *(float *)(param_5 + 0x448) < (float)(int)uVar5) {
          return 1;
        }
        if ((float)(int)uVar5 < (float)local_1c - *(float *)(param_5 + 0x44c)) {
          return 1;
        }
      }
      param_2 = param_2 + 1;
      pfVar11 = pfVar11 + 1;
    } while (param_2 < param_1);
  }
  if (*(float *)(param_5 + 0x450) <
      (*(float *)(param_5 + 0x448) * *(float *)(param_5 + 0x448)) / (float)local_14) {
    return 0;
  }
  if (((*(float *)(param_5 + 0x44c) * *(float *)(param_5 + 0x44c)) / (float)local_14 <=
       *(float *)(param_5 + 0x450)) && (*(float *)(param_5 + 0x450) < (float)(iVar10 / local_14))) {
    return 1;
  }
  return 0;
}

