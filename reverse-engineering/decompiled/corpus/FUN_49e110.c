/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49e110; label: FUN_0049e110
 */

int FUN_0049e110(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x50) + 0xc);
  if ((((*(int *)(iVar1 + 0x68) != 0) || (*(int *)(iVar1 + 0x6c) != 0)) ||
      (*(int *)(iVar1 + 0x70) != 0)) && (iVar2 = 0, iVar1 = DAT_0093d504, 0 < DAT_0093d500)) {
    do {
      if ((((iVar1 != unaff_ESI) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
          ((*(char *)(iVar1 + 0x28b) == '\0' &&
           ((*(char *)(iVar1 + 0x7b5) == '\x05' && ((*(byte *)(iVar1 + 0x7bc) & 0xc) == 0)))))) &&
         (*(int *)(iVar1 + 0x790) == unaff_ESI)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return 0;
}

