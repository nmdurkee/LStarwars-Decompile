/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca450; label: FUN_005ca450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005ca450(int *param_1)

{
  if ((0x414e4933 < *param_1) && (*param_1 < 0x414e4936)) {
    return (uint)*(ushort *)(param_1 + 1);
  }
  return (int)(short)param_1[1];
}

