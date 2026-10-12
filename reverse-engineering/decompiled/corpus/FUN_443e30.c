/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443e30; label: FUN_00443e30
 */

float10 FUN_00443e30(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) &&
     ((&DAT_0086e0f5)[(uint)*(byte *)(in_stack_00000014 + 0x7c) * 0xc] == '\x01')) {
    return (float10)1;
  }
  return (float10)0;
}

