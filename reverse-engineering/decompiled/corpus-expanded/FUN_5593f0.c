/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x5593f0; label: FUN_005593f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005593f0(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x68) & 0x800) != 0) {
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 8;
    FUN_00557b90();
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0xc);
  if ((iVar1 != 0) && (iVar1 != 3)) {
    return;
  }
  FUN_00557960();
  return;
}

