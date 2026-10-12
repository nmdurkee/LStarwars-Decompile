/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440f80; label: FUN_00440f80
 */

float10 FUN_00440f80(int param_1)

{
  int in_stack_00000014;
  
  if (((param_1 != 0) && (in_stack_00000014 != 0)) &&
     (*(int *)(param_1 + 0x1390) == in_stack_00000014)) {
    return (float10)1;
  }
  return (float10)0;
}

