/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440be0; label: FUN_00440be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440be0(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) && ((*(ushort *)(in_stack_00000014 + 0x13a) & 0x30) == 0)) {
    return (float10)1;
  }
  return (float10)0;
}

