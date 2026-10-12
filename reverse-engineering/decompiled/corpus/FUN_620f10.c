/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x620f10; label: FUN_00620f10
 */

void FUN_00620f10(undefined4 *param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  *(undefined4 *)PTR_DAT_0080f7ec = *param_1;
  *(undefined4 *)(puVar1 + 4) = param_1[1];
  *(undefined4 *)(puVar1 + 8) = param_1[2];
  *(undefined4 *)(puVar1 + 0x20) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  return;
}

