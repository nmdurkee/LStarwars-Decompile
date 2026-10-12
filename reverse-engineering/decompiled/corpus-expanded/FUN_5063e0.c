/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x5063e0; label: FUN_005063e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005063e0(int param_1,undefined4 param_2)

{
  if (-1 < (char)*(uint *)(param_1 + 0x88)) {
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 0x80;
    FUN_005b44e0(param_1 + 0x18);
  }
  FUN_005b4900(param_1 + 0x18,param_2);
  FUN_00500b90();
  return;
}

