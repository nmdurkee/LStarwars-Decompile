/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440d30; label: FUN_00440d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440d30(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int *piVar1;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(short *)(*piVar1 + 0x1064) == param_5)) {
    return (float10)1;
  }
  return (float10)0;
}

