/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a53c0; label: FUN_006a53c0
 */

void FUN_006a53c0(void *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x10) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x10));
    }
    if (*(void **)((int)param_1 + 0x14) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x14));
    }
    if (*(void **)((int)param_1 + 0x18) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x18));
    }
    if (*(int *)((int)param_1 + 8) != 0) {
      iVar1 = 0;
      do {
        iVar2 = 0;
        do {
          _free(*(void **)(*(int *)(iVar1 + *(int *)((int)param_1 + 8)) + iVar2));
          iVar2 = iVar2 + 4;
        } while (iVar2 < 0x20);
        _free(*(void **)(iVar1 + *(int *)((int)param_1 + 8)));
        iVar1 = iVar1 + 4;
      } while (iVar1 < 0x44);
      _free(*(void **)((int)param_1 + 8));
    }
    if (*(int *)((int)param_1 + 0xc) != 0) {
      iVar1 = 0;
      do {
        _free(*(void **)(*(int *)((int)param_1 + 0xc) + iVar1));
        iVar1 = iVar1 + 4;
      } while (iVar1 < 0xc);
      _free(*(void **)((int)param_1 + 0xc));
    }
    _memset(param_1,0,0x34);
  }
  return;
}

