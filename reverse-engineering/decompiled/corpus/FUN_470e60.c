/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x470e60; label: FUN_00470e60
 */

void FUN_00470e60(void)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  float *pfVar5;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = *(int *)(in_EAX + 0x514);
  if (iVar3 != 0) {
    if (((*(int *)(in_EAX + 0x4b0) == 0) || ((*(byte *)(in_EAX + 0x559) & 1) == 0)) ||
       (pfVar5 = (float *)(in_EAX + 0x70), *(int *)(*(int *)(in_EAX + 0x4b0) + 0x14) == 0)) {
      pfVar5 = (float *)(in_EAX + 0x48c);
    }
    local_18 = *pfVar5;
    local_14 = pfVar5[1];
    local_10 = pfVar5[2];
    if (*(short *)(in_EAX + 0x55e) == DAT_007f1984) {
      local_c = *(float *)(iVar3 + 0x748);
      fVar2 = *(float *)(iVar3 + 0x77c) / *(float *)(iVar3 + 0x784);
      local_8 = *(float *)(iVar3 + 0x74c);
      local_4 = *(float *)(iVar3 + 0x750);
      if (1.0 < fVar2) {
        fVar2 = 1.0;
      }
      *(float *)(*(int *)(in_EAX + 0x514) + 0x5c) = local_c + fVar2 * (local_18 - local_c);
      *(float *)(*(int *)(in_EAX + 0x514) + 0x60) = local_8 + fVar2 * (local_14 - local_8);
      *(float *)(*(int *)(in_EAX + 0x514) + 100) = local_4 + fVar2 * (local_10 - local_4);
      iVar3 = *(int *)(in_EAX + 0x514);
      *(float *)(iVar3 + 0x5c) =
           *(float *)(iVar3 + 0x5c) -
           (float)(&DAT_029899a0)[*(ushort *)(iVar3 + 0x27a) >> 1] * *(float *)(iVar3 + 0x1e0) *
           fVar2;
      iVar3 = *(int *)(in_EAX + 0x514);
      *(float *)(iVar3 + 100) =
           *(float *)(iVar3 + 100) -
           (float)(&DAT_029899a0)[(int)(*(ushort *)(iVar3 + 0x27a) + 0x4000) >> 1 & 0x7fff] *
           *(float *)(iVar3 + 0x1e0) * fVar2;
      if ((*(char *)(*(int *)(in_EAX + 0x514) + 0x7b3) == '\0') && (fVar2 == 1.0)) {
        FUN_00681f40("imp_C3PO_magnet",&local_18);
        *(undefined1 *)(*(int *)(in_EAX + 0x514) + 0x7b3) = 1;
      }
    }
    else if (*(short *)(iVar3 + 0x7aa) == 5) {
      *(float *)(iVar3 + 0x5c) =
           local_18 -
           (float)(&DAT_029899a0)[*(ushort *)(iVar3 + 0x27a) >> 1] * *(float *)(iVar3 + 0x1e0);
      *(float *)(*(int *)(in_EAX + 0x514) + 0x60) = local_14;
      iVar3 = *(int *)(in_EAX + 0x514);
      *(float *)(iVar3 + 100) =
           local_10 -
           (float)(&DAT_029899a0)[(int)(*(ushort *)(iVar3 + 0x27a) + 0x4000) >> 1 & 0x7fff] *
           *(float *)(iVar3 + 0x1e0);
    }
    else {
      *(float *)(iVar3 + 0x5c) = local_18;
      *(float *)(iVar3 + 0x60) = local_14;
      *(float *)(iVar3 + 100) = local_10;
    }
    puVar1 = (uint *)(*(int *)(in_EAX + 0x514) + 0xef0);
    *puVar1 = *puVar1 & 0xfdffffff;
    iVar3 = *(int *)(in_EAX + 0x514);
    iVar4 = *(int *)(in_EAX + 0x514);
    *(undefined4 *)(iVar4 + 0x10bc) = *(undefined4 *)(iVar3 + 0x5c);
    *(undefined4 *)(iVar4 + 0x10c0) = *(undefined4 *)(iVar3 + 0x60);
    *(undefined4 *)(iVar4 + 0x10c4) = *(undefined4 *)(iVar3 + 100);
  }
  return;
}

