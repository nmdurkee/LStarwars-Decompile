/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442e00; label: FUN_00442e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442e00(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) &&
     ((((DAT_0093d810 != 0 && (*(char *)(DAT_0093d810 + 0x7b5) == '(')) &&
       (*(int *)(DAT_0093d810 + 0x798) == in_stack_00000014)) ||
      (((DAT_0093d814 != 0 && (*(char *)(DAT_0093d814 + 0x7b5) == '(')) &&
       (*(int *)(DAT_0093d814 + 0x798) == in_stack_00000014)))))) {
    return (float10)1;
  }
  return (float10)0;
}

