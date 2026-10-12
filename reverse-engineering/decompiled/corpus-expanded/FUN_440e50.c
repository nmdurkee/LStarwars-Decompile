/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440e50; label: FUN_00440e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440e50(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((*(byte *)(*(int *)(param_3 + 0xd0) + 0x1f8) & 5) == 0)) {
    return (float10)1;
  }
  return (float10)0;
}

