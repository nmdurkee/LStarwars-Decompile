/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x5114a0; label: FUN_005114a0
 */

void FUN_005114a0(void)

{
  int iVar1;
  int iVar2;
  
  FUN_00543de0();
  if (DAT_00924808 != 0) {
    DAT_00921e5c = 1;
  }
  FUN_0050b9a0();
  iVar2 = 0;
  DAT_00921e84 = 0;
  if ((DAT_00924810 != 0) && (iVar1 = 0, 0 < DAT_00801598)) {
    do {
      if ((&DAT_02989540)[iVar1] != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
      DAT_00921e84 = iVar2;
    } while (iVar1 < DAT_00801598);
  }
  return;
}

