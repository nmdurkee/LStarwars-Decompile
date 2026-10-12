/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442e00; label: FUN_00442e00
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

