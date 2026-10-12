/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x441050; label: FUN_00441050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441050(void)

{
  int iVar1;
  undefined4 in_stack_00000014;
  
  iVar1 = FUN_004678f0(DAT_0093d810,in_stack_00000014);
  if (iVar1 != 0) {
    return (float10)1;
  }
  return (float10)0;
}

