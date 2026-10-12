/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c4f0; label: FUN_0046c4f0
 */

bool FUN_0046c4f0(void)

{
  int iVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = 0;
  uVar6 = 0;
  if (((DAT_0093d7f0 != 0) && (*(char *)(DAT_0093d7f0 + 0x28b) == '\0')) &&
     (uVar4 = (uint)*(byte *)(DAT_0093d7f0 + 0x107e), uVar4 != 0)) {
    iVar1 = uVar4 - (int)*(char *)(DAT_0093d7f0 + 0x107f);
    uVar6 = uVar4;
  }
  if (((DAT_0093d7f4 != 0) && (*(char *)(DAT_0093d7f4 + 0x28b) == '\0')) &&
     (uVar4 = (uint)*(byte *)(DAT_0093d7f4 + 0x107e), uVar4 != 0)) {
    iVar1 = iVar1 + (uVar4 - (int)*(char *)(DAT_0093d7f4 + 0x107f));
    uVar6 = uVar6 + uVar4;
  }
  if (uVar6 != 0) {
    if ((0 < iVar1) && (0 < DAT_0081020c)) {
      psVar3 = (short *)(DAT_0291f664 + 0x13e);
      iVar5 = DAT_0081020c;
      do {
        if (((*(byte *)(psVar3 + 3) & 1) != 0) && (*psVar3 == 0xcb)) {
          iVar1 = iVar1 + -1;
        }
        psVar3 = psVar3 + 0x110;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar5 = 8;
    if (5 < DAT_008668c8._1_1_) {
      iVar5 = 9;
    }
    uVar2 = iVar1 + (iVar5 - (uint)DAT_008668c8._1_1_);
    uVar4 = uVar6;
    if (((int)uVar2 <= (int)uVar6) && (uVar4 = uVar2, (int)uVar2 < 0)) {
      uVar4 = 0;
    }
    iVar1 = (int)(uVar4 << 0x10) / (int)uVar6;
    iVar5 = FUN_0056e160(0x2c);
    if (iVar5 != 0) {
      if (PTR_DAT_007f3a14[DAT_00856c0c * 4 + 1] == '\x01') {
        iVar5 = FUN_0054fa60();
        return iVar5 < iVar1 / 2;
      }
      if (PTR_DAT_007f3a14[DAT_00856c0c * 4 + 1] == -1) {
        iVar1 = iVar1 * 2;
      }
    }
    iVar5 = FUN_0054fa60();
    return iVar5 < iVar1;
  }
  return false;
}

