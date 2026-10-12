/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x689f70; label: FUN_00689f70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689f70(void)

{
  int iVar1;
  
  DAT_029629d8 = 0;
  FUN_00545e10();
  FUN_00545540();
  DAT_029211a8 = 0;
  DAT_029211ac = 0;
  _DAT_029211b0 = 0;
  _DAT_029211b4 = 0;
  _DAT_029211b8 = 0;
  _DAT_029211bc = 0;
  _DAT_029211c0 = 0;
  _DAT_029211c4 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_02920acc)[iVar1] != 0) {
      (&DAT_0292fc0c)[iVar1] = 0;
      (&DAT_0292fd10)[iVar1] = 0;
      FUN_00689c80(iVar1);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

