/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a7d00; label: FUN_004a7d00
 */

void FUN_004a7d00(void)

{
  int unaff_ESI;
  
  if ((*(char *)(unaff_ESI + 0x7b5) == -1) && (*(char *)(unaff_ESI + 0xe32) == '\0')) {
    if (*(char *)(unaff_ESI + 0x281) == '\0') {
      return;
    }
    if (((*(char *)(unaff_ESI + 0x282) == '\0') &&
        ((0.2 <= *(float *)(unaff_ESI + 0xdac) || ((*(uint *)(unaff_ESI + 0xe24) & 0x400) != 0))))
       && (((*(uint *)(unaff_ESI + 0xe24) & 0x400) != 0 ||
           ((*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) == 0.0 ||
            (((*(byte *)(unaff_ESI + 0x1fc) & 0x80) == 0 &&
             (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x164) != 0)))))))) {
      FUN_005621a0();
    }
  }
  if (*(char *)(unaff_ESI + 0x281) != '\0') {
    *(uint *)(unaff_ESI + 0xe24) = *(uint *)(unaff_ESI + 0xe24) & 0xfffffbff;
  }
  return;
}

