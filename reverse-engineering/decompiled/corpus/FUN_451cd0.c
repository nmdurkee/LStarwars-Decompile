/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x451cd0; label: FUN_00451cd0
 */

undefined4 FUN_00451cd0(void)

{
  int iVar1;
  int iVar2;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  if ((in_stack_00000018 != 0) && (*(int *)(PTR_DAT_00802c54 + 0x298c) != 0)) {
    *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0x210) =
         *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0x210) | 1;
    iVar2 = 0;
    if (in_stack_00000014 < 1) {
      return 1;
    }
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar2 * 4),"false");
      if (iVar1 == 0) {
        *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0x210) =
             *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0x210) & 0xfffffffe;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < in_stack_00000014);
    return 1;
  }
  return 1;
}

