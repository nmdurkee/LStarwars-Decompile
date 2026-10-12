/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443b60; label: FUN_00443b60
 */

float10 FUN_00443b60(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_0055a320(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014);
    return (float10)iVar1;
  }
  return (float10)0;
}

