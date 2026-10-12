/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x620f40; label: FUN_00620f40
 */

void FUN_00620f40(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  *(undefined4 *)(PTR_DAT_0080f7ec + 0xc) = param_1;
  *(undefined4 *)(puVar1 + 0x10) = param_2;
  return;
}

