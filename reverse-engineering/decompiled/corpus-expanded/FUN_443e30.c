/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443e30; label: FUN_00443e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443e30(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) &&
     ((&DAT_0086e0f5)[(uint)*(byte *)(in_stack_00000014 + 0x7c) * 0xc] == '\x01')) {
    return (float10)1;
  }
  return (float10)0;
}

