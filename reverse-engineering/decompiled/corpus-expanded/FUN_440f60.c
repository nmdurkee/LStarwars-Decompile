/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440f60; label: FUN_00440f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440f60(int param_1)

{
  int in_stack_00000014;
  
  if (((param_1 != 0) && (in_stack_00000014 != 0)) &&
     (*(int *)(param_1 + 0x138c) == in_stack_00000014)) {
    return (float10)1;
  }
  return (float10)0;
}

