/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b1520; label: FUN_006b1520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b1520(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 / *(int *)(param_1 + 8);
  _memmove(*(void **)(param_1 + 0xa0),(void *)((int)*(void **)(param_1 + 0xa0) + iVar1 * 4),
           (*(int *)(param_1 + 0xa8) / *(int *)(param_1 + 8) - iVar1) * 4 + 8);
  *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) - param_2;
  if (-1 < *(int *)(param_1 + 0xac)) {
    *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) - param_2;
  }
  *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) - param_2;
  return;
}

