/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443bc0; label: FUN_00443bc0
 */

float10 FUN_00443bc0(void)

{
  int in_stack_00000014;
  
  if (in_stack_00000014 == 0) {
    return (float10)0;
  }
  if ((*(byte *)(in_stack_00000014 + 10) & 2) != 0) {
    return (float10)1.0;
  }
  return (float10)0.0;
}

