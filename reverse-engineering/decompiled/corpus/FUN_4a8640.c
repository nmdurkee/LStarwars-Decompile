/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a8640; label: FUN_004a8640
 */

void FUN_004a8640(int param_1)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  
  if (((*(byte *)(*(int *)(unaff_ESI + 0x54) + 4) & 0x10) != 0) &&
     ((*(uint *)(unaff_ESI + 0xe24) & 0x200) == 0)) {
    iVar2 = FUN_0056e160(0x20);
    if (((iVar2 != 0) &&
        (((((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0 && (*(char *)(unaff_ESI + 0x28b) == '\0')) &&
          (cVar1 = *(char *)(unaff_ESI + 0x7b5), cVar1 != '\v')) &&
         ((cVar1 != '\x16' && (cVar1 != '+')))))) && (param_1 != 0)) {
      FUN_004381e0();
      iVar2 = FUN_00426de0(unaff_ESI + 0x80,0);
      if (((iVar2 != 0) && (DAT_0093b324 != 0)) &&
         ((*(char *)(unaff_ESI + 0x280) == '\0' || (*(char *)(unaff_ESI + 0x280) == '\x01')))) {
        *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | 0x10000;
        *(int *)(iVar2 + 8) = unaff_ESI;
      }
      FUN_00437390();
      if (0.0 < *(float *)(unaff_ESI + 0xc64)) {
        FUN_00561b20(*(undefined4 *)(DAT_00926c20 + DAT_00881040 * 4),
                     *(undefined4 *)(unaff_ESI + 0xc5c),*(undefined4 *)(unaff_ESI + 0xc60),
                     0x3e800000,0x3f800000,1,0);
      }
    }
  }
  return;
}

