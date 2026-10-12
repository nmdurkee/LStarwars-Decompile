/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4de2a0; label: FUN_004de2a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de2a0(void)

{
  int iVar1;
  int unaff_ESI;
  float10 fVar2;
  
  if (unaff_ESI != 0) {
    if ((*(byte *)(unaff_ESI + 0x5c) & 2) != 0) {
      if (DAT_0093b2a4 == 0) {
        if ((_DAT_00888fb8 & 1) == 0) {
          *(int *)(unaff_ESI + 0x10) = (int)DAT_007f19d8;
          _DAT_00888fb8 = _DAT_00888fb8 | 1;
          *(uint *)(unaff_ESI + 0x5c) = *(uint *)(unaff_ESI + 0x5c) & 0xffffffe3;
          *(undefined4 *)(unaff_ESI + 0x58) = 0;
          return;
        }
        if ((_DAT_00888fb8 & 2) == 0) {
          *(int *)(unaff_ESI + 0x10) = (int)DAT_007f19d4;
          _DAT_00888fb8 = _DAT_00888fb8 | 2;
          *(uint *)(unaff_ESI + 0x5c) = *(uint *)(unaff_ESI + 0x5c) & 0xffffffe3;
          *(undefined4 *)(unaff_ESI + 0x58) = 0;
          return;
        }
      }
      fVar2 = (float10)FUN_005b9dd0();
      if (fVar2 < (float10)0.5) {
        iVar1 = (int)DAT_007f1890;
        *(uint *)(unaff_ESI + 0x5c) = *(uint *)(unaff_ESI + 0x5c) & 0xffffffe3;
        *(int *)(unaff_ESI + 0x10) = iVar1;
        *(undefined4 *)(unaff_ESI + 0x58) = 0;
        return;
      }
      iVar1 = (int)DAT_007f18dc;
      *(uint *)(unaff_ESI + 0x5c) = *(uint *)(unaff_ESI + 0x5c) & 0xffffffe3;
      *(int *)(unaff_ESI + 0x10) = iVar1;
      *(undefined4 *)(unaff_ESI + 0x58) = 0;
      return;
    }
    iVar1 = (int)DAT_007f19dc;
    *(uint *)(unaff_ESI + 0x5c) = *(uint *)(unaff_ESI + 0x5c) & 0xffffffe3;
    *(int *)(unaff_ESI + 0x10) = iVar1;
    *(undefined4 *)(unaff_ESI + 0x58) = 0;
  }
  return;
}

