/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443a00; label: FUN_00443a00
 */

undefined4 FUN_00443a00(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iStack0000000c;
  
  if (param_2 != 0) {
    iStack0000000c = param_2;
    param_1 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8);
    uVar1 = FUN_0055a020();
    return uVar1;
  }
  return 0;
}

