/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x61a210; label: FUN_0061a210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0061a210(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) < *(int *)(param_2 + 4)) {
    return 0xffffffff;
  }
  return (uint)(*(int *)(param_2 + 4) < *(int *)(param_1 + 4));
}

