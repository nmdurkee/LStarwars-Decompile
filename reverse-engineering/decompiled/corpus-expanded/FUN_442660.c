/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442660; label: FUN_00442660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442660(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 0) && (*(int *)(in_stack_00000014 + 4) != 0)) &&
     ((*(byte *)(*(int *)(in_stack_00000014 + 4) + 0x88) & 2) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

