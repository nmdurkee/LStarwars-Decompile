/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443b90; label: FUN_00443b90
 */

undefined4 FUN_00443b90(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_0059f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2acc),param_2);
    return uVar1;
  }
  return 0;
}

