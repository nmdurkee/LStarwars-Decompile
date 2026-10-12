/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca470; label: FUN_005ca470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005ca470(float *param_1)

{
  if ((0x414e4933 < (int)*param_1) && ((int)*param_1 < 0x414e4936)) {
    return (float10)((float)*(ushort *)((int)param_1 + 10) + (float)*(ushort *)((int)param_1 + 0xe))
    ;
  }
  return (float10)*param_1;
}

