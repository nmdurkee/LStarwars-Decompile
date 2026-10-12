/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x441300; label: FUN_00441300
 */

float10 FUN_00441300(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) &&
     (((*(uint *)(in_stack_00000014 + 0xa0) & 0x200000) != 0 ||
      (*(int *)(in_stack_00000014 + 0x3c) != 0)))) {
    return (float10)1;
  }
  return (float10)0;
}

