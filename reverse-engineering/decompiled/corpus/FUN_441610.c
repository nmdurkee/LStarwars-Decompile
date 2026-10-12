/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x441610; label: FUN_00441610
 */

float10 FUN_00441610(void)

{
  int *in_stack_00000014;
  
  if (((in_stack_00000014 != (int *)0x0) && (*in_stack_00000014 != 0)) &&
     (*(char *)(*in_stack_00000014 + 0x6d) == '\x02')) {
    return (float10)1;
  }
  return (float10)0;
}

