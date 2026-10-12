/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442750; label: FUN_00442750
 */

float10 FUN_00442750(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 0) && (*(int *)(PTR_DAT_00802c54 + 0x2988) != 0)) &&
     (*(char *)(DAT_0093d810 + 0x671) * 0x13c + **(int **)(PTR_DAT_00802c54 + 0x2988) ==
      in_stack_00000014)) {
    return (float10)1;
  }
  return (float10)0;
}

