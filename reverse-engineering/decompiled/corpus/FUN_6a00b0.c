/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a00b0; label: FUN_006a00b0
 */

void FUN_006a00b0(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = 0;
    if (0 < param_1[2]) {
      do {
        if (*(int *)(*param_1 + iVar1 * 4) != 0) {
          _free(*(void **)(*param_1 + iVar1 * 4));
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[2]);
    }
    if ((void *)*param_1 != (void *)0x0) {
      _free((void *)*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      _free((void *)param_1[1]);
    }
    if ((void *)param_1[3] != (void *)0x0) {
      _free((void *)param_1[3]);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}

