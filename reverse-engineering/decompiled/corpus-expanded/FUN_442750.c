/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442750; label: FUN_00442750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

