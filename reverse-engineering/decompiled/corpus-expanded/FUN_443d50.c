/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443d50; label: FUN_00443d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443d50(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_00570100(in_stack_00000014);
    return (float10)iVar1;
  }
  return (float10)0;
}

