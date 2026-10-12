/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x4988b0; label: FUN_004988b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004988b0(int param_1,int param_2)

{
  float *pfVar1;
  ushort uVar2;
  float fVar3;
  float10 fVar4;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  local_14 = DAT_0093b0d0;
  local_18 = DAT_0093b0cc;
  local_10 = DAT_0093b0d4;
  if (*(int *)(param_1 + 0xcbc) != 0) {
    uVar2 = *(ushort *)(*(int *)(param_1 + 0xcbc) + 0xc);
    if ((uVar2 & 0x10) == 0) {
      fVar3 = _DAT_00950c50;
      if ((uVar2 & 0x40) == 0) goto LAB_004988fd;
    }
    else {
      fVar3 = 0.0076;
    }
    local_14 = fVar3;
  }
LAB_004988fd:
  if ((((*(char *)(param_1 + 0x7b5) == 'D') && (*(short *)(param_1 + 0x7aa) != 6)) &&
      (*(short *)(param_1 + 0x7aa) != 5)) ||
     ((*(char *)(param_1 + 0x7b5) == 'C' && (*(char *)(param_1 + 0x7b6) == '\x05')))) {
    local_10 = *(float *)(param_1 + 0x768);
    local_14 = *(float *)(param_1 + 0x764);
    local_18 = *(float *)(param_1 + 0x760);
  }
  if (param_2 == 0) {
    pfVar1 = (float *)(param_1 + 0xe94);
    if (((local_18 != *(float *)(param_1 + 0xe94)) || (local_14 != *(float *)(param_1 + 0xe98))) ||
       (local_10 != *(float *)(param_1 + 0xe9c))) {
      fVar4 = (float10)FUN_005becc0(&local_18,pfVar1,local_c);
      fVar3 = _DAT_00925018 * 0.4;
      if ((float)fVar4 < fVar3 != ((float)fVar4 == fVar3)) {
        *pfVar1 = local_18;
        *(float *)(param_1 + 0xe98) = local_14;
        *(float *)(param_1 + 0xe9c) = local_10;
        return;
      }
      FUN_005b3b30(local_c,local_c);
      FUN_005b3830(local_c,local_c,fVar3);
      FUN_005b37d0(pfVar1,pfVar1,local_c);
    }
    return;
  }
  *(float *)(param_1 + 0xe94) = local_18;
  *(float *)(param_1 + 0xe98) = local_14;
  *(float *)(param_1 + 0xe9c) = local_10;
  return;
}

