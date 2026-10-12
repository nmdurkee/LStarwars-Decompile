/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x660680; label: FUN_00660680
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00660680(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(float *)(param_1 + 0x30c) == 0.0) {
    return;
  }
  local_10 = 0.0;
  local_14 = 0.0;
  local_18 = 0.0;
  iVar1 = param_2 * 0x330 + DAT_029620a4;
  if (_DAT_0296205c <= *(float *)(param_2 * 0x330 + 0x1e0 + DAT_029620a4)) {
    fVar2 = *(float *)(iVar1 + 0x1dc);
  }
  else {
    fVar2 = *(float *)(iVar1 + 0x1e0);
  }
  fVar2 = _DAT_0296205c - fVar2;
  if ((fVar2 <= 0.0) || (*(float *)(param_1 + 0x30c) <= fVar2)) {
    return;
  }
  fVar2 = fVar2 / *(float *)(param_1 + 0x30c);
  iVar3 = 0;
  pfVar4 = (float *)(param_1 + 0x318);
  do {
    if ((pfVar4[-2] < fVar2 != (pfVar4[-2] == fVar2)) && (fVar2 <= *pfVar4)) {
      pfVar4 = (float *)(param_1 + 0x314 + iVar3 * 8);
      local_10 = (*(float *)(param_1 + 0x31c + iVar3 * 8) - *pfVar4) *
                 ((fVar2 - *(float *)(param_1 + 0x310 + iVar3 * 8)) /
                 (*(float *)(param_1 + 0x318 + iVar3 * 8) - *(float *)(param_1 + 0x310 + iVar3 * 8))
                 ) + *pfVar4;
      break;
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 2;
  } while (iVar3 < 7);
  iVar3 = 0;
  pfVar4 = (float *)(param_1 + 0x358);
  do {
    if ((pfVar4[-2] < fVar2 != (pfVar4[-2] == fVar2)) && (fVar2 <= *pfVar4)) {
      pfVar4 = (float *)(param_1 + 0x354 + iVar3 * 8);
      local_14 = (*(float *)(param_1 + 0x35c + iVar3 * 8) - *pfVar4) *
                 ((fVar2 - *(float *)(param_1 + 0x350 + iVar3 * 8)) /
                 (*(float *)(param_1 + 0x358 + iVar3 * 8) - *(float *)(param_1 + 0x350 + iVar3 * 8))
                 ) + *pfVar4;
      break;
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 2;
  } while (iVar3 < 7);
  iVar3 = 0;
  pfVar4 = (float *)(param_1 + 0x398);
  while ((pfVar4[-2] < fVar2 == (pfVar4[-2] == fVar2) || (*pfVar4 < fVar2))) {
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 2;
    if (6 < iVar3) {
LAB_00660857:
      local_c = *(undefined4 *)(iVar1 + 400);
      local_8 = *(undefined4 *)(iVar1 + 0x194);
      local_4 = *(undefined4 *)(iVar1 + 0x198);
      FUN_0065c380(&local_c,*(float *)(param_1 + 0x304) * local_10,
                   *(float *)(param_1 + 0x308) * local_14,*(float *)(param_1 + 0x308) * local_18,
                   0xffff0000,DAT_02947c68);
      return;
    }
  }
  pfVar4 = (float *)(param_1 + 0x394 + iVar3 * 8);
  local_18 = (*(float *)(param_1 + 0x39c + iVar3 * 8) - *pfVar4) *
             ((fVar2 - *(float *)(param_1 + 0x390 + iVar3 * 8)) /
             (*(float *)(param_1 + 0x398 + iVar3 * 8) - *(float *)(param_1 + 0x390 + iVar3 * 8))) +
             *pfVar4;
  goto LAB_00660857;
}

