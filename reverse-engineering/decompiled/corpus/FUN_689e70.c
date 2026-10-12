/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x689e70; label: FUN_00689e70
 */

void FUN_00689e70(char param_1)

{
  int iVar1;
  
  if ((&DAT_029211a8)[param_1] != 0) {
    (&DAT_029211a8)[param_1] = 0;
    DAT_029629d8 = 0;
    FUN_00545e10();
    FUN_00545540();
    iVar1 = 0;
    do {
      if ((&DAT_029211a8)[iVar1] != 0) {
        (&DAT_029211a8)[iVar1] = 0;
        FUN_00689c80(iVar1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
  }
  return;
}

