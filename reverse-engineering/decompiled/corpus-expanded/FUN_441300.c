/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x441300; label: FUN_00441300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441300(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) &&
     (((*(uint *)(in_stack_00000014 + 0xa0) & 0x200000) != 0 ||
      (*(int *)(in_stack_00000014 + 0x3c) != 0)))) {
    return (float10)1;
  }
  return (float10)0;
}

