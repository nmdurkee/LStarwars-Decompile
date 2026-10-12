/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x4424b0; label: FUN_004424b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004424b0(void)

{
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    return (float10)*(float *)(in_stack_00000014 + 0x28);
  }
  return (float10)0;
}

