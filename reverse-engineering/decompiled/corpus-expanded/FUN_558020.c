/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558020; label: FUN_00558020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00558020(int param_1)

{
  if ((((*(uint *)(param_1 + 0x68) & 0x800) == 0) && ((*(byte *)(param_1 + 0x9c) & 4) == 0)) &&
     (*(int *)(*(int *)(param_1 + 0x34) + 0xc) == 0)) {
    return;
  }
  *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 8;
  FUN_00557b90();
  return;
}

