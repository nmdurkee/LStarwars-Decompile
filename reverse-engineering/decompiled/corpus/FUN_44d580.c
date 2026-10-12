/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44d580; label: FUN_0044d580
 */

undefined4 FUN_0044d580(void)

{
  int *in_stack_00000010;
  int in_stack_00000014;
  
  if (((in_stack_00000010 != (int *)0x0) && (in_stack_00000014 != 0)) && (*in_stack_00000010 != 0))
  {
    DAT_009253a4 = FUN_004f8b10("FALSE",*in_stack_00000010);
    if (DAT_009253a4 == 0) {
      return 1;
    }
  }
  DAT_009253a4 = 1;
  return 1;
}

