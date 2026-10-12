/* Ghidra pseudocode, not original source.
 * ev_aa81935a86a90d95efe1cd13896fafaf1f7525855a34f109f6da8479aa997be3
 * Entry: 0x5876e0; label: FUN_005876e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005876e0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x18) = (float)fVar1;
  return;
}

