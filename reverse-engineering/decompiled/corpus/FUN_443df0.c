/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443df0; label: FUN_00443df0
 */

float10 FUN_00443df0(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_0062df80(in_stack_00000014);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

