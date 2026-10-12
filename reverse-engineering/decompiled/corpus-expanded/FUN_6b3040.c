/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b3040; label: FUN_006b3040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b3040(void *param_1)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    iVar1 = 0;
    if (0 < *(int *)((int)param_1 + 4)) {
      do {
        if (*(int *)(*(int *)((int)param_1 + 0x14) + iVar1 * 4) != 0) {
          _free(*(void **)(*(int *)((int)param_1 + 0x14) + iVar1 * 4));
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)((int)param_1 + 4));
    }
    _free(*(void **)((int)param_1 + 0x14));
    iVar1 = 0;
    if (0 < *(int *)((int)param_1 + 0x18)) {
      do {
        _free(*(void **)(*(int *)((int)param_1 + 0x1c) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)((int)param_1 + 0x18));
    }
    _free(*(void **)((int)param_1 + 0x1c));
    _memset(param_1,0,0x2c);
    _free(param_1);
  }
  return;
}

