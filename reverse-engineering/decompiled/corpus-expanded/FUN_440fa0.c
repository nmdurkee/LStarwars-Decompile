/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440fa0; label: FUN_00440fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440fa0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if ((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) {
    if (DAT_0093d810 == DAT_0093d7f0) {
      if (*piVar1 == DAT_0093d7f4) {
        return (float10)1;
      }
    }
    else if ((DAT_0093d810 == DAT_0093d7f4) && (*piVar1 == DAT_0093d7f0)) {
      return (float10)1;
    }
  }
  return (float10)0;
}

