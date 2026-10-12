/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440c70; label: FUN_00440c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440c70(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if ((in_stack_00000014 != -1) && (DAT_0093d810 != 0)) {
    iVar1 = FUN_0055bc80(DAT_0093d810,in_stack_00000014);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

