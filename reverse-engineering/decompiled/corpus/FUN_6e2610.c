/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2610; label: FUN_006e2610
 */

void FUN_006e2610(void)

{
  uint uVar1;
  int in_ECX;
  bool bVar2;
  undefined4 uVar3;
  
  FUN_006db030(DAT_008264c0);
  FUN_006daff0(DAT_008264b4);
  FUN_006db050(1);
  if (DAT_008264c7 == '\0') {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  FUN_006db030(uVar3);
  if (DAT_02974d1c < 2) {
    if ((DAT_008264c4 != '\0') && (1 < DAT_008264bc)) {
      FUN_006db030(1);
    }
    if ((DAT_008264b8 != '\0') && (1 < DAT_008264b0)) {
      FUN_006daff0(1);
    }
  }
  if (((DAT_02974d1c < 3) && (DAT_008264c4 != '\0')) && (1 < DAT_008264bc)) {
    FUN_006db030(1);
  }
  if (*(int *)(in_ECX + 0x638) != 0) {
    if ((DAT_008264c4 != '\0') && (1 < DAT_008264bc)) {
      FUN_006db030(0);
    }
    if ((DAT_008264b8 != '\0') && (1 < DAT_008264b0)) {
      FUN_006daff0(1);
    }
  }
  *(undefined4 *)(in_ECX + 0x654) = 1;
  *(undefined4 *)(in_ECX + 0x658) = 1;
  if (DAT_008264bc == 2) {
    *(undefined4 *)(in_ECX + 0x654) = 0x21;
    *(undefined4 *)(in_ECX + 0x658) = 0x13;
  }
  if (DAT_008264b0 != 0) {
    *(uint *)(in_ECX + 0x654) = *(uint *)(in_ECX + 0x654) | 4;
  }
  if (DAT_008264b0 == 2) {
    *(uint *)(in_ECX + 0x658) = *(uint *)(in_ECX + 0x658) | 2;
  }
  if (DAT_008264c5 != '\0') {
    *(uint *)(in_ECX + 0x654) = *(uint *)(in_ECX + 0x654) | 0x80;
  }
  bVar2 = *(int *)(in_ECX + 0x638) == 0;
  if (bVar2) {
    *(undefined4 *)(in_ECX + 0x6d4) = 0;
  }
  uVar1 = (uint)bVar2;
  if ((*(byte *)(in_ECX + 0x658) & 2) != 0) {
    *(undefined4 *)(in_ECX + 0x6d4 + uVar1 * 4) = 1;
    uVar1 = uVar1 + 1;
  }
  if ((*(byte *)(in_ECX + 0x658) & 4) != 0) {
    *(undefined4 *)(in_ECX + 0x6d4 + uVar1 * 4) = 2;
    uVar1 = uVar1 + 1;
  }
  if ((*(byte *)(in_ECX + 0x658) & 0x10) != 0) {
    *(undefined4 *)(in_ECX + 0x6d4 + uVar1 * 4) = 3;
    uVar1 = uVar1 + 1;
  }
  *(short *)(in_ECX + 0x66c) = (short)uVar1;
  FUN_006db1c0();
  return;
}

