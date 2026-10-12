/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x506460; label: FUN_00506460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00506460(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 0x80;
  FUN_005b4f70(param_1 + 0x18,param_2);
  FUN_00500b90();
  return;
}

