/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a7c00; label: FUN_004a7c00
 */

void FUN_004a7c00(void)

{
  undefined2 uVar1;
  int unaff_ESI;
  
  *(undefined2 *)(unaff_ESI + 0x42) = 5;
  if (((*(char *)(unaff_ESI + 0x7b5) != '+') &&
      ((((*(char *)(unaff_ESI + 0x281) != '\0' || (0.0 < *(float *)(unaff_ESI + 0xd24))) ||
        (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x14) == 0)) ||
       (((*(float *)(unaff_ESI + 0xdac) < 0.2 && (*(float *)(unaff_ESI + 0xda0) != 2e+06)) &&
        ((*(float *)(unaff_ESI + 0xda0) < 0.25 && (*(float *)(unaff_ESI + 0x6c) < 0.0)))))))) &&
     (((*(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x28) <= 0.0 ||
       (*(char *)(unaff_ESI + 0x281) != '\0')) ||
      (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x14) == 0)))) {
    uVar1 = FUN_00415050();
    *(undefined2 *)(unaff_ESI + 0x42) = uVar1;
    return;
  }
  return;
}

