/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x65efc0; label: FUN_0065efc0
 */

void FUN_0065efc0(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_c;
  float local_8;
  float local_4;
  
  if (DAT_02921884 == -1) {
    DAT_02920ab4 = 0xffffffff;
    return;
  }
  iVar2 = DAT_02921884 * 0x50 + DAT_02962a14;
  iVar4 = (int)*(short *)(iVar2 + 0x40);
  if (DAT_02920ab4 != -1) {
    FUN_005b37d0(&local_c,iVar2 + 8,(DAT_02962a10 * iVar4 + DAT_02920ab4) * 0x20 + DAT_02962a18);
    FUN_005b3800(&local_c,&DAT_02961ff0,&local_c);
    if (local_4 * local_4 + local_c * local_c + local_8 * local_8 == 0.0) {
      return;
    }
  }
  DAT_02920ab4 = -1;
  iVar3 = 0;
  iVar2 = DAT_02921884 * 0x50 + DAT_02962a14;
  if (0 < *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14)) {
    do {
      FUN_005b37d0(&local_c,iVar2 + 8,(DAT_02962a10 * iVar4 + iVar3) * 0x20 + DAT_02962a18);
      FUN_005b3800(&local_c,&DAT_02961ff0,&local_c);
      fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
      iVar2 = iVar3;
      if ((0.0 <= param_1) && (param_1 <= fVar1)) {
        iVar2 = DAT_02920ab4;
        fVar1 = param_1;
      }
      param_1 = fVar1;
      DAT_02920ab4 = iVar2;
      iVar3 = iVar3 + 1;
      iVar2 = DAT_02962a14 + DAT_02921884 * 0x50;
    } while (iVar3 < *(int *)(iVar2 + 4));
  }
  return;
}

