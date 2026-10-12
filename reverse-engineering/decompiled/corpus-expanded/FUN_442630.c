/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442630; label: FUN_00442630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442630(void)

{
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    return (float10)*(float *)(in_stack_00000014 + 0x4c);
  }
  return (float10)1;
}

