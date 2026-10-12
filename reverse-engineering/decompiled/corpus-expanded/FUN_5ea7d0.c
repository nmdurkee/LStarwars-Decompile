/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea7d0; label: FUN_005ea7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ea7d0(int param_1)

{
  short sVar1;
  
  if (param_1 != 0) {
    sVar1 = *(short *)(*(int *)(param_1 + 0x40) + 0x74);
    FUN_005e50e0(*(int *)(param_1 + 0x40));
    if ((*(byte *)(param_1 + 6) & 1) == 0) {
      FUN_005e5630((int)sVar1);
    }
  }
  return;
}

