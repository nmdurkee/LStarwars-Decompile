/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x5063b0; label: FUN_005063b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005063b0(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 0x80;
  FUN_005b4500(param_1 + 0x18,param_2);
  FUN_00500b90();
  return;
}

