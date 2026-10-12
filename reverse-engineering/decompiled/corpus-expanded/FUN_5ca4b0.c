/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca4b0; label: FUN_005ca4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005ca4b0(float *param_1)

{
  if ((0x414e4933 < (int)*param_1) && ((int)*param_1 < 0x414e4936)) {
    if (*(ushort *)((int)param_1 + 0x16) != 0) {
      return (float10)*(ushort *)((int)param_1 + 0x16);
    }
    return (float10)((uint)*(ushort *)((int)param_1 + 0xe) + (uint)*(ushort *)((int)param_1 + 10));
  }
  return (float10)*param_1;
}

