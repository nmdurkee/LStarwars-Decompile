/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443280; label: FUN_00443280
 */

float10 FUN_00443280(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) && ((*(byte *)(in_stack_00000014 + 0x1fc) & 0x80) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

