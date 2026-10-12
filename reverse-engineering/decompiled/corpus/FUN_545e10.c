/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545e10; label: FUN_00545e10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545e10(void)

{
  int iVar1;
  int iVar2;
  
  DAT_02983a48 = 0;
  DAT_02983a44 = 0;
  _DAT_02983a40 = 0;
  if (0 < DAT_0092484c) {
    iVar1 = 0;
    iVar2 = DAT_0092484c;
    do {
      *(undefined2 *)(iVar1 + DAT_00924850) = 0;
      iVar1 = iVar1 + 0x4c;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

