/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x512f00; label: FUN_00512f00
 */

undefined ** FUN_00512f00(void)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined **ppuVar4;
  
  if (DAT_00922228 != (undefined **)0x0) {
    puVar2 = *DAT_00922228;
    ppuVar4 = DAT_00922228;
    while (puVar2 != (undefined *)0x0) {
      iVar3 = FUN_004f8b10();
      if (iVar3 == 0) {
        return ppuVar4;
      }
      ppuVar1 = ppuVar4 + 3;
      ppuVar4 = ppuVar4 + 3;
      puVar2 = *ppuVar1;
    }
  }
  ppuVar4 = &PTR_DAT_008019c0;
  puVar2 = PTR_DAT_008019c0;
  while( true ) {
    if (puVar2 == (undefined *)0x0) {
      return (undefined **)0x0;
    }
    iVar3 = FUN_004f8b10();
    if (iVar3 == 0) break;
    ppuVar4 = ppuVar4 + 3;
    puVar2 = *ppuVar4;
  }
  return ppuVar4;
}

