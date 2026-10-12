/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b3040; label: FUN_006b3040
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

