/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44d580; label: FUN_0044d580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

