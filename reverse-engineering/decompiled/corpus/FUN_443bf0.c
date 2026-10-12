/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443bf0; label: FUN_00443bf0
 */

undefined4 FUN_00443bf0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = FUN_004f8b10(param_2,"player1");
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

