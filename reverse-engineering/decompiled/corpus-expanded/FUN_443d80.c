/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443d80; label: FUN_00443d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443d80(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && ((*(uint *)(**(int **)(param_3 + 0xd0) + 0xef4) & 0x200) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

