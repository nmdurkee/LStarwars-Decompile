/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59cb90; label: FUN_0059cb90
 */

undefined ** FUN_0059cb90(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  ppuVar2 = &PTR_s_heading_00805438;
  iVar3 = 0;
  do {
    iVar1 = FUN_004f8b10(*ppuVar2,param_1);
    if (iVar1 == 0) {
      return &PTR_s_heading_00805438 + iVar3 * 6;
    }
    ppuVar2 = ppuVar2 + 6;
    iVar3 = iVar3 + 1;
  } while ((int)ppuVar2 < 0x8054b0);
  return (undefined **)0x0;
}

